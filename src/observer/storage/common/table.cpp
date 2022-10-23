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
// Created by Meiyi & Wangyunlai on 2021/5/13.
//

#include <limits.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <string>

#include "common/defs.h"
#include "storage/common/table.h"
#include "storage/common/table_meta.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/default/disk_buffer_pool.h"
#include "storage/record/record_manager.h"
#include "storage/common/condition_filter.h"
#include "storage/common/meta_util.h"
#include "storage/index/index.h"
#include "storage/index/bplus_tree_index.h"
#include "storage/trx/trx.h"
#include "storage/clog/clog.h"
#include "util/util.h"

Table::~Table()
{
  if (record_handler_ != nullptr) {
    delete record_handler_;
    record_handler_ = nullptr;
  }

  if (data_buffer_pool_ != nullptr) {
    data_buffer_pool_->close_file();
    data_buffer_pool_ = nullptr;
  }

  for (std::vector<Index *>::iterator it = indexes_.begin(); it != indexes_.end(); ++it) {
    Index *index = *it;
    delete index;
  }
  indexes_.clear();

  LOG_INFO("Table has been closed: %s", name());
}

RC Table::create(
    const char *path, const char *name, const char *base_dir, int attribute_count, const AttrInfo attributes[], CLogManager *clog_manager)
{

  if (common::is_blank(name)) {
    LOG_WARN("Name cannot be empty");
    return RC::INVALID_ARGUMENT;
  }
  LOG_INFO("Begin to create table %s:%s", base_dir, name);

  if (attribute_count <= 0 || nullptr == attributes) {
    LOG_WARN("Invalid arguments. table_name=%s, attribute_count=%d, attributes=%p", name, attribute_count, attributes);
    return RC::INVALID_ARGUMENT;
  }

  RC rc = RC::SUCCESS;

  // 使用 table_name.table记录一个表的元数据
  // 判断表文件是否已经存在
  int fd = ::open(path, O_WRONLY | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
  if (fd < 0) {
    if (EEXIST == errno) {
      LOG_ERROR("Failed to create table file, it has been created. %s, EEXIST, %s", path, strerror(errno));
      return RC::SCHEMA_TABLE_EXIST;
    }
    LOG_ERROR("Create table file failed. filename=%s, errmsg=%d:%s", path, errno, strerror(errno));
    return RC::IOERR;
  }

  close(fd);

  // 创建文件
  if ((rc = table_meta_.init(name, attribute_count, attributes)) != RC::SUCCESS) {
    LOG_ERROR("Failed to init table meta. name:%s, ret:%d", name, rc);
    return rc;  // delete table file
  }

  std::fstream fs;
  fs.open(path, std::ios_base::out | std::ios_base::binary);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open file for write. file name=%s, errmsg=%s", path, strerror(errno));
    return RC::IOERR;
  }

  // 记录元数据到文件中
  table_meta_.serialize(fs);
  fs.close();

  std::string data_file = table_data_file(base_dir, name);
  BufferPoolManager &bpm = BufferPoolManager::instance();
  rc = bpm.create_file(data_file.c_str());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to create disk buffer pool of data file. file name=%s", data_file.c_str());
    return rc;
  }

  rc = init_record_handler(base_dir);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to create table %s due to init record handler failed.", data_file.c_str());
    // don't need to remove the data_file
    return rc;
  }

  base_dir_ = base_dir;
  clog_manager_ = clog_manager;
  LOG_INFO("Successfully create table %s:%s", base_dir, name);
  return rc;
}

RC Table::drop(
    const char *path, const char *name, const char *base_dir)
{
  BufferPoolManager &bpm = BufferPoolManager::instance();
  LOG_INFO("Begin to drop table %s:%s", base_dir, name);

  RC rc = RC::SUCCESS;
  
  bpm.drop_file(path);

  std::string data_file = table_data_file(base_dir, name);
  
  //we don't care the error
  bpm.drop_file(data_file.c_str());
  for(int i=0;i<indexes_.size();++i){
    indexes_[i]->drop();
    delete indexes_[i];
  }
  LOG_INFO("Successfully drop table %s:%s", base_dir, name);
  return rc;
}
RC Table::open(const char *meta_file, const char *base_dir, CLogManager *clog_manager)
{
  // 加载元数据文件
  std::fstream fs;
  std::string meta_file_path = std::string(base_dir) + common::FILE_PATH_SPLIT_STR + meta_file;
  fs.open(meta_file_path, std::ios_base::in | std::ios_base::binary);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open meta file for read. file name=%s, errmsg=%s", meta_file_path.c_str(), strerror(errno));
    return RC::IOERR;
  }
  if (table_meta_.deserialize(fs) < 0) {
    LOG_ERROR("Failed to deserialize table meta. file name=%s", meta_file_path.c_str());
    fs.close();
    return RC::GENERIC_ERROR;
  }
  fs.close();

  // 加载数据文件
  RC rc = init_record_handler(base_dir);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to open table %s due to init record handler failed.", base_dir);
    // don't need to remove the data_file
    return rc;
  }

  base_dir_ = base_dir;

  const int index_num = table_meta_.index_num();
  for (int i = 0; i < index_num; i++) {
    const IndexMeta *index_meta = table_meta_.index(i);
    const std::vector<std::string> &field_names = index_meta->fields();
    std::vector<const FieldMeta *> field_meta;
    for(const std::string &filed_name : field_names) {
      const FieldMeta *field = table_meta_.field(filed_name.c_str());
      if (field == nullptr) {
        LOG_ERROR("Found invalid index meta info which has a non-exists field. table=%s, index=%s, field=%s",
            name(),
            index_meta->name(),
            index_meta->desc_field().c_str());
        // skip cleanup
        //  do all cleanup action in destructive Table function
        return RC::GENERIC_ERROR;
      }
      field_meta.push_back(field);
    }

    BplusTreeIndex *index = new BplusTreeIndex();
    std::string index_file = table_index_file(base_dir, name(), index_meta->name());
    rc = index->open(index_file.c_str(), *index_meta, field_meta);
    if (rc != RC::SUCCESS) {
      delete index;
      LOG_ERROR("Failed to open index. table=%s, index=%s, file=%s, rc=%d:%s",
          name(),
          index_meta->name(),
          index_file.c_str(),
          rc,
          strrc(rc));
      // skip cleanup
      //  do all cleanup action in destructive Table function.
      return rc;
    }
    indexes_.push_back(index);
  }

  if (clog_manager_ == nullptr) {
    clog_manager_ = clog_manager;
  }
  return rc;
}

RC Table::commit_insert(Trx *trx, const RID &rid)
{
  Record record;
  RC rc = record_handler_->get_record(&rid, &record);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to get record %s: %s", this->name(), rid.to_string().c_str());
    return rc;
  }

  return trx->commit_insert(this, record);
}
RC Table::commit_update(Trx *trx, const RID &rid) {
  Record record;
  RC rc = record_handler_->get_record(&rid, &record);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return trx->commit_update(this, record);
}
RC Table::rollback_insert(Trx *trx, const RID &rid)
{

  Record record;
  RC rc = record_handler_->get_record(&rid, &record);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to get record %s: %s", this->name(), rid.to_string().c_str());
    return rc;
  }

  // remove all indexes
  rc = delete_entry_of_indexes(record.data(), rid, false);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to delete indexes of record(rid=%d.%d) while rollback insert, rc=%d:%s",
        rid.page_num,
        rid.slot_num,
        rc,
        strrc(rc));
    return rc;
  }

  rc = record_handler_->delete_record(&rid);
  return rc;
}
RC Insert_Date_Checker(Value values){
  if(values.type==DATES && values.data==nullptr){
    return RC::INVALID_ARGUMENT;
  }
  return RC::SUCCESS;
}

RC Table::show_index(std::vector<std::string>& ret){
  ret.push_back("TABLE | NON_UNIQUE | KEY_NAME | SEQ_IN_INDEX | COLUMN_NAME");
  std::string head(this->name());
  for(size_t i = 0; i < indexes_.size(); ++ i){
    auto index_meta = indexes_[i]->index_meta();
    const std::vector<std::string> &field_name = index_meta.fields();
    for (size_t idx = 0; idx < field_name.size(); ++ idx) {
      std::string s = head + " | 1 | " + std::string(index_meta.name()) + 
                      " | " + std::to_string(idx + 1) + " | " + field_name[idx];
      ret.emplace_back(s);
    }
  }
  return RC::SUCCESS;
}

RC Table::rollback_update(Trx *trx, const RID &rid) {

  Record record;
  RC rc = record_handler_->get_record(&rid, &record);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  // remove all indexes
  rc = delete_entry_of_indexes(record.data(), rid, false);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to delete indexes of record(rid=%d.%d) while rollback insert, rc=%d:%s",
              rid.page_num, rid.slot_num, rc, strrc(rc));
  } else {
    rc = record_handler_->delete_record(&rid);
  }
  return rc;
}

RC Table::insert_record(Trx *trx, Record *record)
{
  RC rc = RC::SUCCESS;

  if (trx != nullptr) {
    trx->init_trx_info(this, *record);
  }
  rc = record_handler_->insert_record(record->data(), table_meta_.record_size(), &record->rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Insert record failed. table name=%s, rc=%d:%s", table_meta_.name(), rc, strrc(rc));
    return rc;
  }

  if (trx != nullptr) {
    rc = trx->insert_record(this, record);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to log operation(insertion) to trx");

      RC rc2 = record_handler_->delete_record(&record->rid());
      if (rc2 != RC::SUCCESS) {
        LOG_ERROR("Failed to rollback record data when insert index entries failed. table name=%s, rc=%d:%s",
            name(),
            rc2,
            strrc(rc2));
      }
      return rc;
    }
  }

  rc = insert_entry_of_indexes(record->data(), record->rid());
  if (rc != RC::SUCCESS) {
    RC rc2 = delete_entry_of_indexes(record->data(), record->rid(), true);
    if (rc2 != RC::SUCCESS) {
      LOG_ERROR("Failed to rollback index data when insert index entries failed. table name=%s, rc=%d:%s",
          name(),
          rc2,
          strrc(rc2));
    }
    rc2 = record_handler_->delete_record(&record->rid());
    if (rc2 != RC::SUCCESS) {
      LOG_PANIC("Failed to rollback record data when insert index entries failed. table name=%s, rc=%d:%s",
          name(),
          rc2,
          strrc(rc2));
    }
    return rc;
  }

  if (trx != nullptr) {
    // append clog record
    CLogRecord *clog_record = nullptr;
    rc = clog_manager_->clog_gen_record(CLogType::REDO_INSERT, trx->get_current_id(), clog_record, name(), table_meta_.record_size(), record);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to create a clog record. rc=%d:%s", rc, strrc(rc));
      return rc;
    }
    rc = clog_manager_->clog_append_record(clog_record);
    if (rc != RC::SUCCESS) {
      return rc;
    }
  }
  return rc;
}

RC Table::recover_insert_record(Record *record)
{
  RC rc = RC::SUCCESS;

  rc = record_handler_->recover_insert_record(record->data(), table_meta_.record_size(), &record->rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Insert record failed. table name=%s, rc=%d:%s", table_meta_.name(), rc, strrc(rc));
    return rc;
  }

  return rc;
}

RC Table::insert_record(Trx *trx, int value_num, const Value *values)
{
  if (value_num <= 0 || nullptr == values) {
    LOG_ERROR("Invalid argument. table name: %s, value num=%d, values=%p", name(), value_num, values);
    return RC::INVALID_ARGUMENT;
  }
  RC rc = RC::SUCCESS;
  for(int i=0;i<value_num;++i){
    rc = Insert_Date_Checker(values[i]);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Invalid argument. value num=%d, values=%p", value_num, values);
      return RC::INVALID_ARGUMENT;
    }
  }
  char *record_data;
  rc = make_record(value_num, values, record_data);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to create a record. rc=%d:%s", rc, strrc(rc));
    return rc;
  }

  Record record;
  record.set_data(record_data);
  rc = insert_record(trx, &record);
  delete[] record_data;
  return rc;
}

RC Table::insert_records(Trx *trx, int record_num,int value_num, const Value values[MAX_DATA][MAX_NUM]){
  if (value_num <= 0 || nullptr == values ) {
    LOG_ERROR("Invalid argument. value num=%d, values=%p", value_num, values);
    return RC::INVALID_ARGUMENT;
  }
  RC rc;
  value_num=value_num/record_num;
  const int normal_field_start_index = table_meta_.sys_field_num();
  for(size_t jk=0;jk<record_num;jk++){//check filed
    const Value * valuesc=values[jk];
  for (int i = 0; i < value_num; i++) {
    const FieldMeta *field = table_meta_.field(i + normal_field_start_index);
    const Value &value = valuesc[i];
    if (record_num == 1) {
      if (field->type() != value.type && value.type == UNDEFINED) {
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    } else {
      if (field->type() != value.type || value.type == UNDEFINED) {
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    }
  }
}
  for(int i = 0;i < record_num;i++){
    char *record_data;
    rc = make_record(value_num, values[i], record_data);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to create a record. rc=%d:%s", rc, strrc(rc));
      return rc;
    }
    Record record;
    record.set_data(record_data);
    rc = insert_record(trx, &record);
    delete[] record_data;
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to insert a record. rc=%d:%s", rc, strrc(rc));
      return rc;
    }
  }
  return RC::SUCCESS;
}

const char *Table::name() const
{
  return table_meta_.name();
}

const TableMeta &Table::table_meta() const
{
  return table_meta_;
}

RC Table::cast_to_char(const FieldMeta &field, const Value &src_value, char *record) 
{
  switch (src_value.type)
  {
  case CHARS: {
    size_t copy_len = std::min(static_cast<size_t>(field.len()), 
                              strlen(static_cast<const char *>(src_value.data)) + 1);
    memcpy(record + field.offset(), src_value.data, copy_len);
    break;
  }
  case INTS: {
    std::string num = std::to_string(*static_cast<int *>(src_value.data));
    size_t copy_len = std::min(static_cast<size_t>(field.len()), num.size() + 1);
    memcpy(record + field.offset(), num.c_str(), copy_len);
    break;
  }
  case FLOATS: {
    std::string num = double2string(*static_cast<float *>(src_value.data));
    size_t copy_len = std::min(static_cast<size_t>(field.len()), num.size() + 1);
    memcpy(record + field.offset(), num.c_str(), copy_len);
    LOG_INFO("cast float value=%f to %s", *static_cast<float *>(src_value.data), num.c_str());
    break;
  }
  case DATES:
  default:
    LOG_WARN("cannot cast type=%d to char", src_value.type);
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }
  return RC::SUCCESS;
}

RC Table::cast_to_int(const FieldMeta &field, const Value &src_value, char *record) 
{
  switch (src_value.type)
  {
  case CHARS: {
    int num = atoi(static_cast<const char *>(src_value.data));
    memcpy(record + field.offset(), &num, field.len());
    break;
  }
  case INTS: {
    memcpy(record + field.offset(), src_value.data, field.len());
    break;
  }
  case FLOATS: {
    float val = *static_cast<float *>(src_value.data);
    int num = static_cast<int>(round(val));
    memcpy(record + field.offset(), &num, field.len());
    break;
  }
  case DATES:
  default:
    LOG_WARN("cannot cast type=%d to int", src_value.type);
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }
  return RC::SUCCESS;
}

RC Table::cast_to_float(const FieldMeta &field, const Value &src_value, char *record) 
{
  switch (src_value.type)
  {
  case CHARS: {
    float num = atof(static_cast<const char *>(src_value.data));
    memcpy(record + field.offset(), &num, field.len());
    break;
  }
  case INTS: {
    float num = static_cast<float>(*static_cast<int *>(src_value.data));
    memcpy(record + field.offset(), &num, field.len());
    break;
  }
  case FLOATS: {
    memcpy(record + field.offset(), src_value.data, field.len());
    break;
  }
  case DATES:
  default:
    LOG_WARN("cannot cast type=%d to float", src_value.type);
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }
  return RC::SUCCESS;
}

//   CHARS,
//   INTS,
//   FLOATS,
//   DATES

RC Table::make_record(int value_num, const Value *values, char *&record_out)
{
  // 检查字段类型是否一致
  if (value_num + table_meta_.sys_field_num() != table_meta_.field_num()) {
    LOG_WARN("Input values don't match the table's schema, table name:%s", table_meta_.name());
    return RC::SCHEMA_FIELD_MISSING;
  }

  const int normal_field_start_index = table_meta_.sys_field_num();

  // 复制所有字段的值
  int record_size = table_meta_.record_size();
  char *record = new char[record_size];
  RC rc = RC::SUCCESS;

  for (int i = 0; i < value_num; i++) {
    const FieldMeta *field = table_meta_.field(i + normal_field_start_index);
    const Value &value = values[i];
    switch (field->type())
    {
    case CHARS:
      rc = cast_to_char(*field, value, record);
      break;
    case INTS:
      rc = cast_to_int(*field, value, record);
      break;
    case FLOATS:
      rc = cast_to_float(*field, value, record);
      break;
    case DATES:
      memcpy(record + field->offset(), value.data, field->len());
      break;
    default:
      rc = RC::SCHEMA_FIELD_TYPE_MISMATCH;
      break;
    }
  }

  if (rc != RC::SUCCESS) {
    delete[] record;
    return rc;
  }

  record_out = record;
  return RC::SUCCESS;
}

RC Table::init_record_handler(const char *base_dir)
{
  std::string data_file = table_data_file(base_dir, table_meta_.name());

  RC rc = BufferPoolManager::instance().open_file(data_file.c_str(), data_buffer_pool_);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to open disk buffer pool for file:%s. rc=%d:%s", data_file.c_str(), rc, strrc(rc));
    return rc;
  }

  record_handler_ = new RecordFileHandler();
  rc = record_handler_->init(data_buffer_pool_);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to init record handler. rc=%d:%s", rc, strrc(rc));
    data_buffer_pool_->close_file();
    data_buffer_pool_ = nullptr;
    delete record_handler_;
    record_handler_ = nullptr;
    return rc;
  }

  return rc;
}

RC Table::get_record_scanner(RecordFileScanner &scanner)
{
  RC rc = scanner.open_scan(*data_buffer_pool_, nullptr);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("failed to open scanner. rc=%d:%s", rc, strrc(rc));
  }
  return rc;
}

/**
 * 为了不把Record暴露出去，封装一下
 */
class RecordReaderScanAdapter {
public:
  explicit RecordReaderScanAdapter(void (*record_reader)(const char *data, void *context), void *context)
      : record_reader_(record_reader), context_(context)
  {}

  void consume(const Record *record)
  {
    record_reader_(record->data(), context_);
  }

private:
  void (*record_reader_)(const char *, void *);
  void *context_;
};

static RC scan_record_reader_adapter(Record *record, void *context)
{
  RecordReaderScanAdapter &adapter = *(RecordReaderScanAdapter *)context;
  adapter.consume(record);
  return RC::SUCCESS;
}

RC Table::scan_record(Trx *trx, ConditionFilter *filter,
		      int limit, void *context,
		      void (*record_reader)(const char *data, void *context))
{
  RecordReaderScanAdapter adapter(record_reader, context);
  return scan_record(trx, filter, limit, (void *)&adapter, scan_record_reader_adapter);
}

RC Table::scan_record(Trx *trx, ConditionFilter *filter, int limit, void *context,
                      RC (*record_reader)(Record *record, void *context))
{
  if (nullptr == record_reader) {
    return RC::INVALID_ARGUMENT;
  }

  if (0 == limit) {
    return RC::SUCCESS;
  }

  if (limit < 0) {
    limit = INT_MAX;
  }

  IndexScanner *index_scanner = find_index_for_scan(filter);
  if (index_scanner != nullptr) {
    return scan_record_by_index(trx, index_scanner, filter, limit, context, record_reader);
  }

  RC rc = RC::SUCCESS;
  RecordFileScanner scanner;
  rc = scanner.open_scan(*data_buffer_pool_, filter);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("failed to open scanner. rc=%d:%s", rc, strrc(rc));
    return rc;
  }

  int record_count = 0;
  Record record;
  while (scanner.has_next()) {
    rc = scanner.next(record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to fetch next record. rc=%d:%s", rc, strrc(rc));
      return rc;
    }
    if (trx == nullptr || trx->is_visible(this, &record)) {
      rc = record_reader(&record, context);
      if (rc != RC::SUCCESS) {
        break;
      }
      record_count++;
    }
  }

  scanner.close_scan();
  return rc;
}

RC Table::scan_record_by_index(Trx *trx, IndexScanner *scanner, ConditionFilter *filter,
                               int limit, void *context,
                               RC (*record_reader)(Record *, void *))
{
  RC rc = RC::SUCCESS;
  RID rid;
  Record record;
  int record_count = 0;
  while (record_count < limit) {
    rc = scanner->next_entry(&rid);
    if (rc != RC::SUCCESS) {
      if (RC::RECORD_EOF == rc) {
        rc = RC::SUCCESS;
        break;
      }
      LOG_ERROR("Failed to scan table by index. rc=%d:%s", rc, strrc(rc));
      break;
    }

    rc = record_handler_->get_record(&rid, &record);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to fetch record of rid=%d:%d, rc=%d:%s", rid.page_num, rid.slot_num, rc, strrc(rc));
      break;
    }

    if ((trx == nullptr || trx->is_visible(this, &record)) && (filter == nullptr || filter->filter(record))) {
      rc = record_reader(&record, context);
      if (rc != RC::SUCCESS) {
        LOG_TRACE("Record reader break the table scanning. rc=%d:%s", rc, strrc(rc));
        break;
      }
    }

    record_count++;
  }

  scanner->destroy();
  return rc;
}

class IndexInserter {
public:
  explicit IndexInserter(Index *index) : index_(index)
  {}

  RC insert_index(const Record *record)
  {
    return index_->insert_entry(record->data(), &record->rid());
  }

private:
  Index *index_;
};

static RC insert_index_record_reader_adapter(Record *record, void *context)
{
  IndexInserter &inserter = *(IndexInserter *)context;
  return inserter.insert_index(record);
}

RC Table::create_index(Trx *trx, const char *index_name, const char * const attribute_name[], size_t attribute_count)
{
  if (common::is_blank(index_name) || attribute_count == 0) {
    LOG_INFO("Invalid input arguments, table name is %s, index_name is blank or attribute_name is blank", name());
    return RC::INVALID_ARGUMENT;
  }

  for(size_t i = 0; i < attribute_count; ++ i) {
    if(common::is_blank(attribute_name[i])) {
      return RC::INVALID_ARGUMENT;
    }
  }

  if (table_meta_.index(index_name) != nullptr 
      || table_meta_.find_index_by_field(attribute_name, attribute_count)) {
    LOG_INFO("Invalid input arguments, table name is %s, index %s exist or attribute %s exist index",
             name(), index_name, attribute_name[0]);
    return RC::SCHEMA_INDEX_EXIST;
  }

  std::vector<const FieldMeta *> field_meta(attribute_count);

  for(size_t i = 0; i < attribute_count; i ++) {
    const FieldMeta *field = table_meta_.field(attribute_name[i]);
    if (nullptr == field) {
      LOG_INFO("Invalid input arguments, there is no field of %s in table:%s.", attribute_name[i], name());
      return RC::SCHEMA_FIELD_MISSING;
    }
    field_meta[i] = field;
  }

  IndexMeta new_index_meta;
  RC rc = new_index_meta.init(index_name, field_meta);
  if (rc != RC::SUCCESS) {
    LOG_INFO("Failed to init IndexMeta in table:%s, index_name:%s, field_name:%s",
             name(), index_name, attribute_name);
    return rc;
  }

  // 创建索引相关数据
  BplusTreeIndex *index = new BplusTreeIndex();
  std::string index_file = table_index_file(base_dir_.c_str(), name(), index_name);
  rc = index->create(index_file.c_str(), new_index_meta, field_meta);
  if (rc != RC::SUCCESS) {
    delete index;
    LOG_ERROR("Failed to create bplus tree index. file name=%s, rc=%d:%s", index_file.c_str(), rc, strrc(rc));
    return rc;
  }

  // 遍历当前的所有数据，插入这个索引
  IndexInserter index_inserter(index);
  rc = scan_record(trx, nullptr, -1, &index_inserter, insert_index_record_reader_adapter);
  if (rc != RC::SUCCESS) {
    // rollback
    delete index;
    LOG_ERROR("Failed to insert index to all records. table=%s, rc=%d:%s", name(), rc, strrc(rc));
    return rc;
  }
  indexes_.push_back(index);

  TableMeta new_table_meta(table_meta_);
  rc = new_table_meta.add_index(new_index_meta);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to add index (%s) on table (%s). error=%d:%s", index_name, name(), rc, strrc(rc));
    return rc;
  }
  // 创建元数据临时文件
  std::string tmp_file = table_meta_file(base_dir_.c_str(), name()) + ".tmp";
  std::fstream fs;
  fs.open(tmp_file, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open file for write. file name=%s, errmsg=%s", tmp_file.c_str(), strerror(errno));
    return RC::IOERR;  // 创建索引中途出错，要做还原操作
  }
  if (new_table_meta.serialize(fs) < 0) {
    LOG_ERROR("Failed to dump new table meta to file: %s. sys err=%d:%s", tmp_file.c_str(), errno, strerror(errno));
    return RC::IOERR;
  }
  fs.close();

  // 覆盖原始元数据文件
  std::string meta_file = table_meta_file(base_dir_.c_str(), name());
  int ret = rename(tmp_file.c_str(), meta_file.c_str());
  if (ret != 0) {
    LOG_ERROR("Failed to rename tmp meta file (%s) to normal meta file (%s) while creating index (%s) on table (%s). "
              "system error=%d:%s",
        tmp_file.c_str(),
        meta_file.c_str(),
        index_name,
        name(),
        errno,
        strerror(errno));
    return RC::IOERR;
  }

  table_meta_.swap(new_table_meta);

  LOG_INFO("Successfully added a new index (%s) on the table (%s)", index_name, name());

  return rc;
}

class RecordUpdater {
public:
  RecordUpdater(Table &table, Trx *trx, const char *attribute_name, const Value value) : 
    table_(table), trx_(trx), attribute_name_(attribute_name), value_(value) {
  }
  RC init() {
    // init updating attribute feild meta
    field_meta_ = table_.table_meta().field(attribute_name_);
    if (field_meta_ == nullptr) {
      return RC::SCHEMA_FIELD_NOT_EXIST;
    }
    if (field_meta_->type() != value_.type) {
      // When the types are inconsistent, attempt to conversion
      if (field_meta_->type() == FLOATS && value_.type == INTS) {
        int int_value;
        float float_value;
        memcpy(&int_value, value_.data, sizeof(int));
        float_value = int_value;
        memcpy(value_.data, &float_value, sizeof(float));
        value_.type = FLOATS;
        return RC::SUCCESS;
      }
      return RC::MISMATCH;
    }
    attr_data_size_ = field_meta_->len();
    return RC::SUCCESS;
  }
  RC add_record(Record* record) {
    records_.push_back(*record);
    return RC::SUCCESS;
  }
  RC do_update() {
    RC rc = RC::SUCCESS;
    int record_size = table_.table_meta().record_size();
    char *new_record_data = new char[record_size];
    int record_data_size = 0;
    
    int i = 0;
    for (Record &record : records_) {
      // create new record->data
      int record_data_size = attr_data_size_;
      if (field_meta_->type() == CHARS) {
        record_data_size = strlen((char *)value_.data) + 1;
        if (record_data_size > attr_data_size_) {
          record_data_size = attr_data_size_;
        }
      }
      memcpy(new_record_data, record.data(), record_size);
      memcpy(new_record_data + field_meta_->offset(), value_.data, record_data_size);
      rc = table_.update_record(trx_, &record, new_record_data);
      
    }
    delete[] new_record_data;
    return RC::SUCCESS;
  }

  int updated_count() const {
    return updated_count_;
  }

private:
  Table & table_;
  Trx *trx_;
  const char *attribute_name_;
  Value value_;
  const FieldMeta *field_meta_;
  int updated_count_ = 0;
  int attr_data_size_ = 0;
  std::vector<Record> records_;
};

RC Table::update_record(Trx *trx, Record *record, const char *new_data) {
  RC rc = RC::SUCCESS;
  rc = update_entry_of_indexes(record->data(), &record->rid(), new_data);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to update indexes of record (rid=%d.%d). rc=%d:%s",record->rid().page_num, record->rid().slot_num, rc, strrc(rc));
    return rc;
  }

  record->data_= const_cast<char *> (new_data);
  rc = record_handler_->update_record(record);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to update record (rid=%d.%d). rc=%d:%s",
                record->rid().page_num, record->rid().slot_num, rc, strrc(rc));
    return rc;
  }

  if (trx != nullptr) {
    rc = trx->update_record(this, record);
    // TODO: CLog
  }

  return rc;
}

RC Table::update_entry_of_indexes(const char *record, const RID *rid, const char *new_data) {
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->update_entry(record, rid, new_data);
    if (rc != RC::SUCCESS) {
      LOG_WARN("Failed to update_entry");
      break;
    }
  }
  return rc;
}

static RC record_reader_update_adapter(Record *record, void *context) {
  RecordUpdater &record_updater = *(RecordUpdater *)context;
  return record_updater.add_record(record);
}

RC Table::update_record(Trx *trx, const char *attribute_name, const Value *value, int condition_num,
    const Condition conditions[], int *updated_count)
{
  RC rc = RC::SUCCESS;
  CompositeConditionFilter filter;
  filter.init(*this, conditions, condition_num);

  RecordUpdater updater(*this, trx, attribute_name, *value);
  rc = updater.init();
  if (rc != RC::SUCCESS) {
    return rc;
  }
  // Scan qualified records and save them in vector<Record>
  rc = scan_record(trx, &filter, -1, &updater, record_reader_update_adapter);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  rc = updater.do_update();
  if (updated_count != nullptr) {
    *updated_count = updater.updated_count();
  }
  return rc;
}

class RecordDeleter {
public:
  RecordDeleter(Table &table, Trx *trx) : table_(table), trx_(trx)
  {}

  RC delete_record(Record *record)
  {
    RC rc = RC::SUCCESS;
    rc = table_.delete_record(trx_, record);
    if (rc == RC::SUCCESS) {
      deleted_count_++;
    }
    return rc;
  }

  int deleted_count() const
  {
    return deleted_count_;
  }

private:
  Table &table_;
  Trx *trx_;
  int deleted_count_ = 0;
};

static RC record_reader_delete_adapter(Record *record, void *context)
{
  RecordDeleter &record_deleter = *(RecordDeleter *)context;
  return record_deleter.delete_record(record);
}

RC Table::delete_record(Trx *trx, ConditionFilter *filter, int *deleted_count)
{
  RecordDeleter deleter(*this, trx);
  RC rc = scan_record(trx, filter, -1, &deleter, record_reader_delete_adapter);
  if (deleted_count != nullptr) {
    *deleted_count = deleter.deleted_count();
  }
  return rc;
}

RC Table::delete_record(Trx *trx, Record *record)
{
  RC rc = RC::SUCCESS;
  
  rc = delete_entry_of_indexes(record->data(), record->rid(), false);  // 重复代码 refer to commit_delete
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to delete indexes of record (rid=%d.%d). rc=%d:%s",
                record->rid().page_num, record->rid().slot_num, rc, strrc(rc));
    return rc;
  } 
  
  rc = record_handler_->delete_record(&record->rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to delete record (rid=%d.%d). rc=%d:%s",
                record->rid().page_num, record->rid().slot_num, rc, strrc(rc));
    return rc;
  }

  if (trx != nullptr) {
    rc = trx->delete_record(this, record);
    
    CLogRecord *clog_record = nullptr;
    rc = clog_manager_->clog_gen_record(CLogType::REDO_DELETE, trx->get_current_id(), clog_record, name(), 0, record);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to create a clog record. rc=%d:%s", rc, strrc(rc));
      return rc;
    }
    rc = clog_manager_->clog_append_record(clog_record);
    if (rc != RC::SUCCESS) {
      return rc;
    }
  }
  return rc;
}

RC Table::recover_delete_record(Record *record)
{
  RC rc = RC::SUCCESS;
  rc = record_handler_->delete_record(&record->rid());
  
  return rc;
}

RC Table::commit_delete(Trx *trx, const RID &rid)
{
  RC rc = RC::SUCCESS;
  Record record;
  rc = record_handler_->get_record(&rid, &record);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  rc = delete_entry_of_indexes(record.data(), record.rid(), false);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to delete indexes of record(rid=%d.%d). rc=%d:%s",
        rid.page_num, rid.slot_num, rc, strrc(rc));  // panic?
  }

  rc = record_handler_->delete_record(&rid);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return rc;
}

RC Table::rollback_delete(Trx *trx, const RID &rid)
{
  RC rc = RC::SUCCESS;
  Record record;
  rc = record_handler_->get_record(&rid, &record);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return trx->rollback_delete(this, record);  // update record in place
}

RC Table::insert_entry_of_indexes(const char *record, const RID &rid)
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->insert_entry(record, &rid);
    if (rc != RC::SUCCESS) {
      break;
    }
  }
  return rc;
}

RC Table::delete_entry_of_indexes(const char *record, const RID &rid, bool error_on_not_exists)
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->delete_entry(record, &rid);
    if (rc != RC::SUCCESS) {
      if (rc != RC::RECORD_INVALID_KEY || !error_on_not_exists) {
        break;
      }
    }
  }
  return rc;
}

Index *Table::find_index(const char *index_name) const
{
  for (Index *index : indexes_) {
    if (0 == strcmp(index->index_meta().name(), index_name)) {
      return index;
    }
  }
  return nullptr;
}
Index *Table::find_index_by_field(const char *field_name) const
{
  const TableMeta &table_meta = this->table_meta();
  const char * fields[1] = { field_name };
  const IndexMeta *index_meta = table_meta.find_index_by_field(fields, 1);
  if (index_meta != nullptr) {
    return this->find_index(index_meta->name());
  }
  return nullptr;
}

IndexScanner *Table::find_index_for_scan(const DefaultConditionFilter &filter)
{
  const ConDesc *field_cond_desc = nullptr;
  const ConDesc *value_cond_desc = nullptr;
  if (filter.left().is_attr && !filter.right().is_attr) {
    field_cond_desc = &filter.left();
    value_cond_desc = &filter.right();
  } else if (filter.right().is_attr && !filter.left().is_attr) {
    field_cond_desc = &filter.right();
    value_cond_desc = &filter.left();
  }
  if (field_cond_desc == nullptr || value_cond_desc == nullptr) {
    return nullptr;
  }

  const FieldMeta *field_meta = table_meta_.find_field_by_offset(field_cond_desc->attr_offset);
  if (nullptr == field_meta) {
    LOG_PANIC("Cannot find field by offset %d. table=%s", field_cond_desc->attr_offset, name());
    return nullptr;
  }

  Index *index = find_index_by_field(field_meta->name());
  if (nullptr == index) {
    return nullptr;
  }

  const char *left_key = nullptr;
  const char *right_key = nullptr;
  int left_len = 4;
  int right_len = 4;
  bool left_inclusive = false;
  bool right_inclusive = false;
  switch (filter.comp_op()) {
  case EQUAL_TO: {
    left_key = (const char *)value_cond_desc->value;
    right_key = (const char *)value_cond_desc->value;
    left_inclusive = true;
    right_inclusive = true;
  }
    break;
  case LESS_EQUAL: {
    right_key = (const char *)value_cond_desc->value;
    right_inclusive = true;
  }
    break;
  case GREAT_EQUAL: {
    left_key = (const char *)value_cond_desc->value;
    left_inclusive = true;
  }
    break;
  case LESS_THAN: {
    right_key = (const char *)value_cond_desc->value;
    right_inclusive = false;
  }
    break;
  case GREAT_THAN: {
    left_key = (const char *)value_cond_desc->value;
    left_inclusive = false;
  }
    break;
  default: {
    return nullptr;
  }
  }

  if (filter.attr_type() == CHARS) {
    left_len = left_key != nullptr ? strlen(left_key) : 0;
    right_len = right_key != nullptr ? strlen(right_key) : 0;
  }
  return index->create_scanner(left_key, left_len, left_inclusive, right_key, right_len, right_inclusive);
}

IndexScanner *Table::find_index_for_scan(const ConditionFilter *filter)
{
  if (nullptr == filter) {
    return nullptr;
  }

  // remove dynamic_cast
  const DefaultConditionFilter *default_condition_filter = dynamic_cast<const DefaultConditionFilter *>(filter);
  if (default_condition_filter != nullptr) {
    return find_index_for_scan(*default_condition_filter);
  }

  const CompositeConditionFilter *composite_condition_filter = dynamic_cast<const CompositeConditionFilter *>(filter);
  if (composite_condition_filter != nullptr) {
    int filter_num = composite_condition_filter->filter_num();
    for (int i = 0; i < filter_num; i++) {
      IndexScanner *scanner = find_index_for_scan(&composite_condition_filter->filter(i));
      if (scanner != nullptr) {
        return scanner;  // 可以找到一个最优的，比如比较符号是=
      }
    }
  }
  return nullptr;
}

RC Table::sync()
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->sync();
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to flush index's pages. table=%s, index=%s, rc=%d:%s",
          name(), index->index_meta().name(), rc, strrc(rc));
      return rc;
    }
  }
  LOG_INFO("Sync table over. table=%s", name());
  return rc;
}
