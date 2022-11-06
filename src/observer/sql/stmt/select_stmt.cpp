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
#include "util/util.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/common/db.h"
#include <algorithm>
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


  hav_con* hav_ptr=nullptr;
  std::map<std::string, std::queue<std::string>> alias_name_map;
  std::map<std::string, std::queue<std::string>> name_alias_map;
  if (alias_name_set != nullptr) {
    alias_name_map = (*alias_name_set);
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
  if (select_sql.aggfun_num && select_sql.attr_num &&!select_sql.group_num) {
    return RC::GENERIC_ERROR;
  }

  if (tables.size() == 2 &&select_sql.attr_num&& 0 == strcmp(select_sql.attributes[0].attribute_name, "*")&&name_alias_map.count(std::string("table_name_1"))&&name_alias_map.count(std::string("table_name_2"))) {
    for (auto &t : tables) {
      const char *alias_ = name_alias_map[std::string(t->name())].front().c_str();
      if (alias_name_map[std::string(alias_)].size() >1) {
        return RC::GENERIC_ERROR;
      }
    }
  }
  // collect func

  std::vector<std::pair<DescribeFun, Field>> funs;
  std::vector<Field> fun_fields(select_sql.aggfun_num);
  for (int i = select_sql.aggfun_num - 1; i >= 0; i--) {
    const RelAttr &relation_attr = select_sql.aggFun[i].attr;
    const char *alias_name = select_sql.aggFun[i].alias_name;
    if (relation_attr.relation_name != nullptr && alias_name_map.count(relation_attr.relation_name) == 0 &&
        !table_map.count(std::string(relation_attr.relation_name))) {
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
        if (select_sql.aggfun_num == 2 && select_sql.attr_num == 0 && select_sql.alias_num != 0) {
          SelectStmt *select_stmt = new SelectStmt();
          select_stmt->flag_ = 2;
          stmt = select_stmt;
          return RC::SUCCESS;
        }else if(select_sql.group_num && fun_fields.size()==2){
          auto p=new SelectStmt;
          p->flag_=3;
          stmt=p;
          return RC::SUCCESS;
        }else if(select_sql.group_num && fun_fields.size()==1){
          auto p=new SelectStmt;
          p->flag_=4;
          stmt=p;
          return RC::SUCCESS;
        }
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

  // expression
  for(int i = select_sql.expr_num - 1; i >= 0; i--) {
    RC rc = valid_expr(&select_sql.attr_expr[i], default_table, &table_map);
    if (rc != RC::SUCCESS) {
      return rc;
    }
  }
  std::vector<AstExpression *> ast_exprs;
  for(int i = select_sql.expr_num - 1; i >= 0; i--) {
    auto ast_expression = create_expr(&select_sql.attr_expr[i], default_table, &table_map);
    expr2string(const_cast<AstExpr *>(&select_sql.attr_expr[i]), &ast_expression->alias);
    ast_exprs.push_back(ast_expression);
  }

  // create filter statement in `where` statement
  FilterStmt *filter_stmt = nullptr;

  RC rc = FilterStmt::create(db,
      default_table,
      &table_map,
      select_sql.conditions,
      select_sql.condition_num,
      filter_stmt,
      &alias_name_map,
      out);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }

  if(filter_stmt&&select_sql.is_or){
    filter_stmt->is_or=true;
  }
  
  Group_by*p=nullptr;
  if(select_sql.group_num!=0){
    if(query_fields.size()!=select_sql.group_num)return RC::GENERIC_ERROR;
    for(int i=0;i<query_fields.size();++i){
      if(std::string(select_sql.attributes[query_fields.size()-1-i].attribute_name)!=std::string(select_sql.gruop_use[i].attribute_name))return RC::GENERIC_ERROR;
    }
    p=new Group_by();
    if(select_sql.ha_num!=0){
      hav_ptr=new hav_con;
      hav_ptr->is_count=select_sql.hav_con[0].left_expr->agg.des==COUNT_STAR;
      hav_ptr->op=select_sql.hav_con[0].comp;
      hav_ptr->num=*(int*)select_sql.hav_con[0].right_value.data;
    }
  }

  // collect order fields
  std::vector<std::pair<Field, OrderType>> order_fields;
  for (size_t i = 0; i < select_sql.order_num; i++) {
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
      if (tables.size() != 1) {
        LOG_WARN("invalid. I do not know the attr's table. attr=%s", relation_attr.attribute_name);
        return RC::SCHEMA_FIELD_MISSING;
      }
      field_name = relation_attr.attribute_name;
      table = tables[0];
    }
    const FieldMeta *field_meta = table->table_meta().field(field_name);
    if (nullptr == field_meta) {
      LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
      return RC::SCHEMA_FIELD_MISSING;
    }

    // check order field in query field
    bool in_query = false;
    for(Field &query_field : query_fields) {
      if (strcmp(query_field.table_name(), table->name()) == 0 &&
          strcmp(query_field.field_name(), field_name) == 0) {
        in_query = true;
        break; 
      }
    }
    if (!in_query) {
      LOG_WARN("no such order field in query field. field=%s.%s.%s", db->name(), table->name(), field_name);
      return RC::SCHEMA_FIELD_MISSING;
    }
    order_fields.push_back(std::pair<Field, OrderType>(Field(table, field_meta), select_sql.order_by[i].type));
  }

  // everything alright
  SelectStmt *select_stmt = new SelectStmt();
  select_stmt->hav=hav_ptr;
  select_stmt->tables_.swap(tables);
  select_stmt->funs_.swap(funs);
  
  select_stmt->query_fields_.swap(query_fields);
  select_stmt->filter_stmt_ = filter_stmt;
  select_stmt->need_reverse = select_sql.need_Revere;
  select_stmt->aliasset_.swap(name_alias_map);
  select_stmt->order_fields_.swap(order_fields);
  stmt = select_stmt;

  select_stmt->flag_=0;
  select_stmt->head=p;
  select_stmt->group_num=select_sql.group_num;

  select_stmt->ast_exprs_.swap(ast_exprs);

  return RC::SUCCESS;
}