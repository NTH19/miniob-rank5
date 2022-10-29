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

#include "rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/db.h"
#include "storage/common/table.h"

FilterStmt::~FilterStmt()
{
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const Condition *conditions, int condition_num, FilterStmt *&stmt,
    std::map<std::string, std::string> alias_name_map)
{
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  tmp_stmt->alias_name_map = alias_name_map;
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;
    rc = create_filter_unit(db, default_table, tables, conditions[i], filter_unit, alias_name_map);
    if (rc != RC::SUCCESS) {
      delete tmp_stmt;
      LOG_WARN("failed to create filter unit. condition index=%d", i);
      return rc;
    }
    tmp_stmt->filter_units_.push_back(filter_unit);
  }

  stmt = tmp_stmt;
  return rc;
}

RC get_table_and_field(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const RelAttr &attr, Table *&table, const FieldMeta *&field, std::map<std::string, std::string> alias_name_map)
{
  char *real_relation;
  char *real_attr;
  if (alias_name_map.size())
  {
    if (attr.relation_name == nullptr && alias_name_map.count(std::string(attr.attribute_name)) > 0 && alias_name_map[std::string(attr.attribute_name)].find(".") != std::string::npos) {
    int idx = alias_name_map[std::string(attr.attribute_name)].find(".");
    real_relation = strdup(alias_name_map[std::string(attr.attribute_name)].substr(0, idx).c_str());
    real_attr = strdup(alias_name_map[std::string(attr.attribute_name)].substr(idx + 1).c_str());

  } else {
    if (alias_name_map.count(std::string(attr.relation_name)) > 0)
      real_relation = strdup(alias_name_map[std::string(attr.relation_name)].c_str());
    else
      real_relation = attr.relation_name;
    if (alias_name_map.count(std::string(attr.attribute_name)) > 0)
      real_attr = strdup(alias_name_map[std::string(attr.attribute_name)].c_str());
    else
      real_attr = attr.attribute_name;
  }

  }else{
    real_attr=attr.attribute_name;
    real_relation=attr.relation_name;
  }
  

  
  if (common::is_blank(real_relation)) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(std::string(real_relation));
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(real_relation);
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", real_relation);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(real_attr);
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), real_attr);
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const Condition &condition, FilterUnit *&filter_unit, std::map<std::string, std::string> alias_name_map)
{
  RC rc = RC::SUCCESS;

  CompOp comp = condition.comp;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  Expression *left = nullptr;
  Expression *right = nullptr;
  AttrType left_type, right_type;
  if (condition.left_is_attr) {
    Table *table = nullptr;
    const FieldMeta *field = nullptr;
    rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field, alias_name_map);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      return rc;
    }
    left = new FieldExpr(table, field);
    left_type = field->type();
  } else {
    left = new ValueExpr(condition.left_value);
    left_type = condition.left_value.type;
  }

  if (condition.right_is_attr) {
    Table *table = nullptr;
    const FieldMeta *field = nullptr;
    rc = get_table_and_field(db, default_table, tables, condition.right_attr, table, field, alias_name_map);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      delete left;
      return rc;
    }
    right = new FieldExpr(table, field);
    right_type = field->type();
  } else {
    right = new ValueExpr(condition.right_value);
    right_type = condition.right_value.type;
  }

  if ((comp == LIKE_TO || comp == NOT_LIKE) && left_type != CHARS && right_type != CHARS) {
    delete left;
    delete right;
    return RC::UNIMPLENMENT;
  }

  filter_unit = new FilterUnit;
  filter_unit->set_comp(comp);
  filter_unit->set_left(left);
  filter_unit->set_right(right);

  // 检查两个类型是否能够比较
  return rc;
}
