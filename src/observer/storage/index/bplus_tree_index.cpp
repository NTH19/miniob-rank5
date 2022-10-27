/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Meiyi & wangyunlai.wyl on 2021/5/19.
//

#include "storage/index/bplus_tree_index.h"
#include "common/log/log.h"
#include "storage/common/table.h"

BplusTreeIndex::~BplusTreeIndex() noexcept
{
  close();
}

RC BplusTreeIndex::create(const char *file_name, const IndexMeta &index_meta, const std::vector<const FieldMeta *> &field_meta)
{
  if (inited_) {
    LOG_WARN("Failed to create index due to the index has been created before. file_name:%s, index:%s, field:%s",
        file_name,
        index_meta.name(),
        index_meta.desc_field().c_str());
    return RC::RECORD_OPENNED;
  }

  Index::init(index_meta, field_meta);

  RC rc = index_handler_.create(file_name, field_meta);
  if (RC::SUCCESS != rc) {
    LOG_WARN("Failed to create index_handler, file_name:%s, index:%s, field:%s, rc:%s",
        file_name,
        index_meta.name(),
        index_meta.desc_field().c_str(),
        strrc(rc));
    return rc;
  }

  inited_ = true;
  LOG_INFO(
      "Successfully create index, file_name:%s, index:%s, field:%s", file_name, index_meta.name(), index_meta.desc_field().c_str());
  return RC::SUCCESS;
}

RC BplusTreeIndex::drop()
{
  if(inited_==false){
    LOG_WARN("Failed to drop index inited_ first  index:%s, field:%s",
        index_meta_.name(),
        index_meta_.desc_field().c_str());
    return RC::FILE_CLOSE;
  }
  index_handler_.drop();
  inited_ = false;
  return RC::SUCCESS;
}
RC BplusTreeIndex::open(const char *file_name, const IndexMeta &index_meta, const std::vector<const FieldMeta *> &field_meta)
{
  if (inited_) {
    LOG_WARN("Failed to open index due to the index has been initedd before. file_name:%s, index:%s, field:%s",
        file_name,
        index_meta.name(),
        index_meta.desc_field().c_str());
    return RC::RECORD_OPENNED;
  }

  Index::init(index_meta, field_meta);

  RC rc = index_handler_.open(file_name);
  if (RC::SUCCESS != rc) {
    LOG_WARN("Failed to open index_handler, file_name:%s, index:%s, field:%s, rc:%s",
        file_name,
        index_meta.name(),
        index_meta.desc_field().c_str(),
        strrc(rc));
    return rc;
  }

  inited_ = true;
  LOG_INFO(
      "Successfully open index, file_name:%s, index:%s, field:%s", file_name, index_meta.name(), index_meta.desc_field().c_str());
  return RC::SUCCESS;
}

RC BplusTreeIndex::close()
{
  if (inited_) {
    LOG_INFO("Begin to close index, index:%s, field:%s",
        index_meta_.name(), index_meta_.desc_field().c_str());
    index_handler_.close();
    inited_ = false;
  }
  LOG_INFO("Successfully close index.");
  return RC::SUCCESS;
}

/* return value should be delete after use */
char *BplusTreeIndex::make_userkey(const char *record) const {
  char *user_key = new char[index_handler_.attr_length()];
  int offset = 0;
  for(const FieldMeta &field : field_meta_) {
    memcpy(user_key + offset, record + field.offset(), field.len());
    offset += field.len();
  }
  return user_key;
}

RC BplusTreeIndex::insert_entry(const char *record, const RID *rid)
{
  char *user_key = make_userkey(record);
  if(index_meta_.unique() && !index_handler_.is_empty()) {
    std::list<RID> rids;
    RC rc = index_handler_.get_entry(user_key, index_handler_.attr_length(), rids);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get index entry: %s", strrc(rc));
      delete[] user_key;
      return rc;
    }

    if(!rids.empty()) {
      int offset = 0;
      bool has_null = false;
      for(const FieldMeta &field : field_meta_) {
        if(memcmp(user_key + offset, __NULL_DATA__, 4) == 0) {
          has_null = true;
          break;
        }
        offset += field.len();
      }
      if (!has_null) {
        delete[] user_key;
        return RC::RECORD_DUPLICATE_KEY;
      }
    }
  }

  RC rc = index_handler_.insert_entry(user_key, rid);
  delete[] user_key;
  return rc;
}

RC BplusTreeIndex::delete_entry(const char *record, const RID *rid)
{
  char *user_key = make_userkey(record);
  RC rc = index_handler_.delete_entry(user_key, rid);
  delete[] user_key;
  return rc;
}
RC BplusTreeIndex::update_entry(const char *record, const RID *rid, const char *new_data) {
  RC rc = delete_entry(record, rid);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to update entry when deleting old entry.");
    return rc;    
  }
  rc = insert_entry(new_data, rid);
  if (rc != RC::SUCCESS) {
    RC rc2 = insert_entry(record, rid);
    if (rc2 != RC::SUCCESS) {
      LOG_ERROR("Failed to reinsert old entry");
    }
  }
  return rc;
}
IndexScanner *BplusTreeIndex::create_scanner(const char *left_key, int left_len, bool left_inclusive,
					     const char *right_key, int right_len, bool right_inclusive)
{
  BplusTreeIndexScanner *index_scanner = new BplusTreeIndexScanner(index_handler_);
  RC rc = index_scanner->open(left_key, left_len, left_inclusive, right_key, right_len, right_inclusive);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open index scanner. rc=%d:%s", rc, strrc(rc));
    delete index_scanner;
    return nullptr;
  }
  return index_scanner;
}

RC BplusTreeIndex::sync()
{
  return index_handler_.sync();
}

////////////////////////////////////////////////////////////////////////////////
BplusTreeIndexScanner::BplusTreeIndexScanner(BplusTreeHandler &tree_handler) : tree_scanner_(tree_handler)
{}

BplusTreeIndexScanner::~BplusTreeIndexScanner() noexcept
{
  tree_scanner_.close();
}

RC BplusTreeIndexScanner::open(const char *left_key, int left_len, bool left_inclusive,
                               const char *right_key, int right_len, bool right_inclusive)
{
  return tree_scanner_.open(left_key, left_len, left_inclusive, right_key, right_len, right_inclusive);
}

RC BplusTreeIndexScanner::next_entry(RID *rid)
{
  return tree_scanner_.next_entry(rid);
}

RC BplusTreeIndexScanner::destroy()
{
  delete this;
  return RC::SUCCESS;
}
