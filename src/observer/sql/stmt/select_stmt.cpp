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
// Created by Wangyunlai on 2022/6/6.
//

#include "sql/stmt/select_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/common/db.h"
#include "storage/common/table.h"
#include "queue"

SelectStmt::~SelectStmt()
{
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  }
}

static void wildcard_fields(Table *table, std::vector<Field> &field_metas)
{
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    field_metas.push_back(Field(table, table_meta.field(i)));
  }
}

RC SelectStmt::create(Db *db, const Selects &select_sql, Stmt *&stmt, bool out,
    std::map<std::string, std::queue<std::string>> *alias_name_set)
{
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }
  std::map<std::string, std::queue<std::string>> alias_name_map;
  std::map<std::string, std::queue<std::string>> name_alias_map;
  if (alias_name_set != nullptr) {
    alias_name_map.swap(*alias_name_set);
    std::map<std::string, std::queue<std::string>>::iterator iter;
    for (iter = (*alias_name_set).begin(); iter != (*alias_name_set).end(); iter++) {
      while (!iter->second.empty()) {
        name_alias_map[iter->second.front()].push(iter->first);
        iter->second.pop();
      }
    }
  } else {
    for (auto it = 0; it < select_sql.alias_num; it++)
    // todo some deal
    {
      name_alias_map[std::string(select_sql.real_name[it])].push(std::string(select_sql.alias_name[it]));
      alias_name_map[std::string(select_sql.alias_name[it])].push(std::string(select_sql.real_name[it]));
    }
  }
  // collect tables in `from` statement
  std::vector<Table *> tables;
  std::unordered_map<std::string, Table *> table_map;
  for (size_t i = 0; i < select_sql.relation_num; i++) {
    const char *table_name = select_sql.relations[i];
    if (nullptr == table_name) {
      LOG_WARN("invalid argument. relation name is null. index=%d", i);
      return RC::INVALID_ARGUMENT;
    }

    Table *table = db->find_table(table_name);
    if (nullptr == table) {
      LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    tables.push_back(table);
    table_map.insert(std::pair<std::string, Table *>(table_name, table));
  }
  if (select_sql.aggfun_num && select_sql.attr_num) {
    return RC::GENERIC_ERROR;
  }
  // collect func
  std::vector<std::pair<DescribeFun, Field>> funs;
  std::vector<Field> fun_fields(select_sql.aggfun_num);
  for (int i = select_sql.aggfun_num - 1; i >= 0; i--) {
    const RelAttr &relation_attr = select_sql.aggFun[i].attr;
    const char *alias_name = select_sql.aggFun[i].alias_name;
    if (relation_attr.relation_name != nullptr && !table_map.count(std::string(relation_attr.relation_name))) {
      LOG_WARN("invalid table name in aggregate: %s", relation_attr.relation_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }
    if (0 == strcmp(relation_attr.attribute_name, "*")) {
      const FieldMeta *field_meta = tables[0]->table_meta().field(1);
      if (nullptr == field_meta) {
        return RC::SCHEMA_FIELD_MISSING;
      }
      fun_fields[i] = Field(tables[0], field_meta);
      fun_fields[i].aliasname = alias_name;
    } else {
      if (tables.size() != 1) {
        LOG_WARN("invalid. I do not know the attr's table. attr=%s", relation_attr.attribute_name);
        return RC::SCHEMA_FIELD_MISSING;
      }

      Table *table = tables[0];
      const FieldMeta *field_meta = table->table_meta().field(relation_attr.attribute_name);
      if (nullptr == field_meta) {
        LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), relation_attr.attribute_name);
        return RC::SCHEMA_FIELD_MISSING;
      }

      fun_fields[i] = Field(table, field_meta);
      fun_fields[i].aliasname = alias_name;
    }
    funs.push_back(std::pair<DescribeFun, Field>(select_sql.aggFun[i].des, fun_fields[i]));
  }

  // collect query fields in `select` statement
  std::vector<Field> query_fields;
  int i = select_sql.attr_num - 1;
  for (int i = select_sql.attr_num - 1; i >= 0; i--) {
    const RelAttr &relation_attr = select_sql.attributes[i];
    if (common::is_blank(relation_attr.relation_name) && 0 == strcmp(relation_attr.attribute_name, "*")) {
      for (Table *table : tables) {
        wildcard_fields(table, query_fields);
      }

    } else if (!common::is_blank(relation_attr.relation_name)) {  // TODO
      const char *table_name = relation_attr.relation_name;
      const char *field_name = relation_attr.attribute_name;
      if (alias_name_map.count(std::string(table_name))) {

        table_name = alias_name_map[std::string(table_name)].back().c_str();  // alias->table
      }
      if (alias_name_map.count(std::string(field_name))) {
        field_name = alias_name_map[std::string(field_name)].front().c_str();
      }
      if (0 == strcmp(table_name, "*")) {
        if (0 != strcmp(field_name, "*")) {
          LOG_WARN("invalid field name while table is *. attr=%s", field_name);
          return RC::SCHEMA_FIELD_MISSING;
        }
        for (Table *table : tables) {
          wildcard_fields(table, query_fields);
        }
      } else {
        auto iter = table_map.find(table_name);
        if (iter == table_map.end()) {
          LOG_WARN("no such table in from list: %s", table_name);
          return RC::SCHEMA_FIELD_MISSING;
        }

        Table *table = iter->second;
        if (0 == strcmp(field_name, "*")) {
          wildcard_fields(table, query_fields);
        } else {
          const FieldMeta *field_meta = table->table_meta().field(field_name);
          if (nullptr == field_meta) {
            LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
            return RC::SCHEMA_FIELD_MISSING;
          }

          query_fields.push_back(Field(table, field_meta));
        }
      }
    } else {
      if (tables.size() != 1) {
        LOG_WARN("invalid. I do not know the attr's table. attr=%s", relation_attr.attribute_name);
        return RC::SCHEMA_FIELD_MISSING;
      }

      Table *table = tables[0];
      const FieldMeta *field_meta = table->table_meta().field(relation_attr.attribute_name);
      if (nullptr == field_meta) {
        LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), relation_attr.attribute_name);
        return RC::SCHEMA_FIELD_MISSING;
      }

      query_fields.push_back(Field(table, field_meta));
    }
  }

  LOG_INFO("got %d tables in from stmt and %d fields in query stmt", tables.size(), query_fields.size());

  Table *default_table = nullptr;
  if (tables.size() == 1) {
    default_table = tables[0];
  }

  // create filter statement in `where` statement
  FilterStmt *filter_stmt = nullptr;

  RC rc = FilterStmt::create(db, default_table, &table_map,select_sql.conditions,select_sql.condition_num,filter_stmt,&alias_name_map,out);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }
  // collect orderfields
  std::vector<std::pair<Field, int>> order_fields;
  for (int i = 0; i < select_sql.order_num; i++) {
    Table *table;
    const char *field_name;
    const RelAttr &relation_attr = select_sql.order_by[i].attribute;
    if (!common::is_blank(relation_attr.relation_name)) {
      const char *table_name = relation_attr.relation_name;
      field_name = relation_attr.attribute_name;
      auto iter = table_map.find(table_name);
      if (iter == table_map.end()) {
        LOG_WARN("no such table in from list: %s", table_name);
        return RC::SCHEMA_FIELD_MISSING;
      }
      table = iter->second;
    } else {  // single table
      field_name = relation_attr.attribute_name;
      table = tables[0];
    }
    const FieldMeta *field_meta = table->table_meta().field(field_name);
    if (nullptr == field_meta) {
      LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
      return RC::SCHEMA_FIELD_MISSING;
    }
    order_fields.push_back(std::pair<Field, int>(Field(table, field_meta), select_sql.order_by[i].order));
    // order_bys.push_back(select_sql.order_by[i]);
  }

  // everything alright
  SelectStmt *select_stmt = new SelectStmt();
  select_stmt->tables_.swap(tables);
  select_stmt->funs_.swap(funs);
  select_stmt->query_fields_.swap(query_fields);
  select_stmt->filter_stmt_ = filter_stmt;
  select_stmt->need_reverse = select_sql.need_Revere;
  select_stmt->aliasset_.swap(name_alias_map);
  select_stmt->order_fields.swap(order_fields);
  stmt = select_stmt;
  select_stmt->is_da=select_sql.is_da;
  return RC::SUCCESS;
}
