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
#include "../expr/tuple_cell.h"
#include "../operator/predicate_operator.h"
#include "../operator/project_operator.h"
#include "../executor/execute_stage.h"
#include "../operator/table_scan_operator.h"
#include "select_stmt.h"

FilterStmt::~FilterStmt()
{
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
   const Condition *conditions, int condition_num, FilterStmt *&stmt,
    std::map<std::string, std::queue<std::string>> *alias_name_map,bool out)

{
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  tmp_stmt->alias_name_map =alias_name_map;
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;
    rc = create_filter_unit(db, default_table, tables, conditions[i], filter_unit,tmp_stmt->alias_name_map,out);
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
    const RelAttr &attr, Table *&table, const FieldMeta *&field,bool out =false,std::map<std::string, std::queue<std::string>> *alias_name_map= nullptr)

{
  char *real_relation;
  char *real_attr;
  if (alias_name_map!=nullptr && alias_name_map->size())
  {
    if (attr.relation_name == nullptr && alias_name_map->count(std::string(attr.attribute_name)) > 0 && (*alias_name_map)[std::string(attr.attribute_name)].front().find(".") != std::string::npos) {
    int idx = (*alias_name_map)[std::string(attr.attribute_name)].front().find(".");
    real_relation = strdup((*alias_name_map)[std::string(attr.attribute_name)].front().substr(0, idx).c_str());
    real_attr = strdup((*alias_name_map)[std::string(attr.attribute_name)].front().substr(idx + 1).c_str());

  } else {
    if (attr.relation_name && alias_name_map->count(std::string(attr.relation_name)) > 0)
      real_relation = strdup((*alias_name_map)[std::string(attr.relation_name)].front().c_str());
    else
      real_relation = attr.relation_name;
    if (alias_name_map->count(std::string(attr.attribute_name)) > 0)
      real_attr = strdup((*alias_name_map)[std::string(attr.attribute_name)].front().c_str());
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
    }else if(out)table = db->find_table(attr.relation_name);
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

RC get_valuse_from_signle_field_select(std::vector<TupleCell> &values, SelectStmt *select_stmt)
{
  if (select_stmt->funs().size() != 0) {
    std::vector<std::pair<int, int>> ret;
    std::vector<int> char_len;
    std::stringstream ss;
    if (gen_ret_of_aggfun(select_stmt, ret, char_len, ss) != RC::SUCCESS)
      return RC::GENERIC_ERROR;
    std::vector<Value> val;
    agg_result(ret, select_stmt->funs(), char_len, val);
    auto right = new Value;
    values.push_back(TupleCell());
    values[0].set_data((char *)val[0].data);
    values[0].set_type(val[0].type);
    return RC::SUCCESS;
  }
  Operator *scan_oper = new TableScanOperator(select_stmt->tables()[0]);
  std::map<std::string,std::queue<std::string>> alias_set;
  alias_set.swap(select_stmt->aliasset_);

  RC rc = RC::SUCCESS;
  PredicateOperator pred_oper(select_stmt->filter_stmt());
  pred_oper.add_child(scan_oper);
  ProjectOperator project_oper;
  project_oper.add_child(&pred_oper);
  if (select_stmt->query_fields().size() != 1)
    return RC::GENERIC_ERROR;
  for (const Field &field : select_stmt->query_fields()) {
    project_oper.add_projection(field.table(), field.meta(),false,alias_set);
  }
  rc = project_oper.open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open operator");
    return rc;
  }
  int i = 0;
  while ((rc = project_oper.next()) == RC::SUCCESS) {
    // get current record
    // write to response
    Tuple *tuple = project_oper.current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get current record. rc=%s", strrc(rc));
      break;
    }
    TupleCell temp;
    values.push_back(TupleCell());
    tuple->cell_at(0, temp);
    TupleCell::deepcopyTupleCell(temp, values[i++]);
  }
  if (rc != RC::RECORD_EOF) {
    LOG_WARN("something wrong while iterate operator. rc=%s", strrc(rc));
    project_oper.close();
  } else {
    rc = project_oper.close();
  }
  delete scan_oper;
  return rc;
}
// has sel =true
RC gen_filter_unit_from_query(FilterUnit *&filter_unit, const Condition &condition, Db *db)
{
  if (!condition.left_is_attr &&condition.comp != EXIST && condition.comp != NOT_EXIST)
    return RC::GENERIC_ERROR;
  if (condition.comp == IN || condition.comp == NOT_IN) {
    if (condition.value_num) {
      std::vector<TupleCell> tupe;
      tupe.resize(condition.value_num);
      Expression *ee = nullptr;
      for(int i=0;i<condition.value_num;++i){
        auto p=new int;
        if(condition.values[i].data==nullptr)memcpy(p,__NULL_DATA__,4);
        else memcpy(p,condition.values[i].data,4);
        tupe[i].set_data((char*)p);
        tupe[i].set_type(condition.values[i].type);
      }
      if (condition.comp == IN) {
        auto ex = new Inexpr();
        filter_unit->set_comp(IN);
        ex->tuplecells.swap(tupe);
        ee = ex;
      } else {
        auto ex = new NotInexpr();
        ex->tuplecells.swap(tupe);
        filter_unit->set_comp(NOT_IN);
        ee = ex;
      }
      filter_unit->set_right(ee);
      return RC::SUCCESS;
    }


    Stmt *stmt;
    std::vector<TupleCell> tupe;
    if (SelectStmt::create(db, *condition.sel, stmt) != RC::SUCCESS)
      return RC::GENERIC_ERROR;
    auto p = dynamic_cast<SelectStmt *>(stmt);

    get_valuse_from_signle_field_select(tupe, p);
    filter_unit = new FilterUnit;
    Expression *ee = nullptr;
    if (condition.comp == IN) {
      auto ex = new Inexpr();
      filter_unit->set_comp(IN);
      ex->tuplecells.swap(tupe);
      ee = ex;
    } else {
      auto ex = new NotInexpr();
      ex->tuplecells.swap(tupe);
      filter_unit->set_comp(NOT_IN);
      ee = ex;
    }
    filter_unit->set_right(ee);

  } else if (condition.comp == EXIST || condition.comp == NOT_EXIST) {
    Stmt *stmt;
    if (SelectStmt::create(db, *condition.sel, stmt,true) != RC::SUCCESS)
      return RC::GENERIC_ERROR;
    auto p = dynamic_cast<SelectStmt *>(stmt);
    auto ex = new ExitsnotExits();
    ex->ptr = p;
    filter_unit->set_right(ex);
    if (condition.comp == EXIST) {
      ex->ee = ExprType::EXIST;
      filter_unit->set_comp(EXIST);
    } else {
      ex->ee = ExprType::NOT_EXIST;
      filter_unit->set_comp(NOT_EXIST);
    }
  } else {
    Stmt *stmt;
    std::vector<TupleCell> tupe;
    if (SelectStmt::create(db, *condition.sel, stmt) != RC::SUCCESS)
      return RC::GENERIC_ERROR;
    auto p = dynamic_cast<SelectStmt *>(stmt);

    get_valuse_from_signle_field_select(tupe, p);
    if (tupe.size() != 1)
      return RC::GENERIC_ERROR;
    filter_unit->set_comp(condition.comp);
    auto val = new Value();
    val->data = (void *)tupe[0].data();
    val->type = tupe[0].attr_type();
    auto right = new ValueExpr(*val);
    filter_unit->set_right(right);
    filter_unit->set_comp(condition.comp);
  }
  return RC::SUCCESS;
}
RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const Condition &condition, FilterUnit *&filter_unit, std::map<std::string, std::queue<std::string>> *alias_name_map,bool out)

{
  RC rc = RC::SUCCESS;

  CompOp comp = condition.comp;
  if (comp < EQUAL_TO || comp > NOT_EXIST) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }
  if (condition.has_sel || condition.value_num) {
    filter_unit = new FilterUnit();
    if (gen_filter_unit_from_query(filter_unit, condition, db) != RC::SUCCESS)
      return RC::GENERIC_ERROR;
    Expression *left = nullptr;
    AttrType left_type;
    if (condition.left_is_attr) {
      Table *table = nullptr;
      const FieldMeta *field = nullptr;

      rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field,out,alias_name_map);
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
    filter_unit->set_left(left);
    return RC::SUCCESS;
  }
  Expression *left = nullptr;
  Expression *right = nullptr;
  AttrType left_type, right_type;
  if (condition.left_is_attr) {
    Table *table = nullptr;
    const FieldMeta *field = nullptr;
    rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field,out, alias_name_map);

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
    rc = get_table_and_field(db, default_table, tables, condition.right_attr, table, field,out, alias_name_map);

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
