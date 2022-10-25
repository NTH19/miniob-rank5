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
// Created by Wangyunlai on 2022/5/22.
//

#include "sql/stmt/update_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "common/log/log.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/db.h"
#include "storage/common/table.h"

UpdateStmt::~UpdateStmt(){
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  } 
  for(auto &attr : update_attrs_) {
    delete attr.select_stmt_;
  }
  update_attrs_.clear();
}

RC UpdateStmt::create(Db *db, const Updates &update, Stmt *&stmt)
{
  stmt = nullptr;
  const char *table_name = update.relation_name;
  if (nullptr == db || nullptr == table_name) {
    LOG_WARN("invalid argument. db=%p, table_name=%p", 
             db, table_name);
    return RC::INVALID_ARGUMENT;
  }
  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::vector<UpdateAttrInfo> update_attrs;
  for (size_t i = 0; i < update.attr_num; i ++) {
    const UpdateAttr &attr = update.update_attrs[i];
    const FieldMeta *field = table->table_meta().field(attr.attribute_name);
    if (nullptr == field) {
      LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), attr.attribute_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }
    if(attr.value.type != UNDEFINED) {
      if (field->type() != attr.value.type && !(field->type() == TEXTS && attr.value.type == CHARS)) {
        LOG_WARN("field type not match. field=%s.%s.%s", db->name(), table->name(), attr.attribute_name);
        for(auto &attr : update_attrs) {
          delete attr.select_stmt_;
        }
        return RC::SCHEMA_TABLE_NOT_EXIST;
      }
      update_attrs.emplace_back(field, &attr.value, nullptr);
    } else {
      Stmt *select_stmt = nullptr;
      RC rc = SelectStmt::create(db, attr.select, select_stmt);
      if (rc != RC::SUCCESS) {
        for(auto &attr : update_attrs) {
          delete attr.select_stmt_;
        }
        return rc;
      }
      update_attrs.emplace_back(field, nullptr, dynamic_cast<SelectStmt *>(select_stmt));
    }
    
  }

  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(std::string(table_name), table));

  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db, table, &table_map,
			     update.conditions,update.condition_num, filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }
  UpdateStmt *update_stmt = new UpdateStmt();
  update_stmt->table_ = table;
  update_stmt->filter_stmt_ = filter_stmt;
  update_stmt->update_attrs_.swap(update_attrs);
  stmt = update_stmt;
  return rc;
}