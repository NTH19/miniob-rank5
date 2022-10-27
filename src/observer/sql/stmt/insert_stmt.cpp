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

#include "sql/stmt/insert_stmt.h"
#include "common/log/log.h"
#include "storage/common/db.h"
#include "storage/common/table.h"

// InsertStmt::InsertStmt(Table *table, const Value *values, int value_amount)
//   : table_ (table), values_(values), value_amount_(value_amount)
// {}
InsertStmt::InsertStmt(Table *table, int value_amount,int record_num,const Inserts &inserts)
  : table_ (table),  value_amount_(value_amount),record_num_(record_num)
{
     memcpy(values_,inserts.values,sizeof(Value)*50*20);
}
RC InsertStmt::create(Db *db, const Inserts &inserts, Stmt *&stmt)
{
  const char *table_name = inserts.relation_name;
  if (nullptr == db || nullptr == table_name || inserts.value_num <= 0) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, value_num=%d", 
             db, table_name, inserts.value_num);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  const int value_num = inserts.value_num / inserts.record_num;
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num() - table_meta.sys_field_num();
  if (field_num != value_num) {
    LOG_WARN("schema mismatch. value num=%d, field num in schema=%d", value_num, field_num);
    return RC::SCHEMA_FIELD_MISSING;
  }
  // check the fields number
  const int sys_field_num = table_meta.sys_field_num();
  for (size_t j = 0; j < inserts.record_num; j++) {
    const Value *rvalues = inserts.values[j];
    for (int i = 0; i < value_num; i++) {
      const FieldMeta *field_meta = table_meta.field(i + sys_field_num);
      const AttrType field_type = field_meta->type();
      const AttrType value_type = rvalues[i].type;
      if (rvalues[i]._is_null && !field_meta->nullable()) { 
        LOG_WARN("cannot insert null to non-null field. table=%s, field=%s", table_name, field_meta->name());
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
      if (inserts.record_num > 1 && field_type != value_type && !(TEXTS == field_type && CHARS == value_type) && 
          !(rvalues[i]._is_null && field_meta->nullable())) { 
        LOG_WARN("field type mismatch. table=%s, field=%s, field type=%d, value_type=%d", 
                table_name, field_meta->name(), field_type, value_type);
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    }
  }
  // everything alright
  stmt = new InsertStmt(table,value_num,inserts.record_num, inserts);
  return RC::SUCCESS;
}
