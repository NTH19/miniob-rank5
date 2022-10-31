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
// Created by Wangyunlai on 2022/07/05.
//

#include "sql/expr/tuple.h"
#include "../operator/predicate_operator.h"
#include "../operator/table_scan_operator.h"
#include "../operator/project_operator.h"
#include "../stmt/filter_stmt.h"
#include "../stmt/select_stmt.h"
#include "../executor/execute_stage.h"
inline bool gen_compare_res(TupleCell &left_cell, TupleCell &right_cell, CompOp cmp)
{
  bool canAdd = false;

  bool filter_result = false;

  bool left_null = left_cell.check_null();
  bool right_null = right_cell.check_null();
  if (left_null || right_null) {
    switch (cmp) {
      case EQUAL_TO:
      case LESS_EQUAL:
      case NOT_EQUAL:
      case LESS_THAN:
      case GREAT_EQUAL:
      case GREAT_THAN:
      case LIKE_TO:
      case NOT_LIKE:
        filter_result = false;
        break;
      case COMP_IS_NOT: {
        if (!left_null && right_null) {  // value is not null
          filter_result = true;
        } else if (left_null && !right_null) {  // null is not value
          filter_result = true;
        } else {  // null is null
          filter_result = false;
        }
        break;
      }
      case COMP_IS: {
        if (!left_null && right_null) {  // value is null
          filter_result = false;
        } else if (left_null && !right_null) {  // null is value
          filter_result = false;
        } else {  // null is null
          filter_result = true;
        }
        break;
      }
      default: {
        // LOG_WARN("invalid compare type: %d", comp);
      } break;
    }
  } else {
    const int compare = left_cell.compare(right_cell);
    switch (cmp) {
      case EQUAL_TO: {
        filter_result = (0 == compare);
      } break;
      case LESS_EQUAL: {
        filter_result = (compare <= 0);
      } break;
      case NOT_EQUAL: {
        filter_result = (compare != 0);
      } break;
      case LESS_THAN: {
        filter_result = (compare < 0);
      } break;
      case GREAT_EQUAL: {
        filter_result = (compare >= 0);
      } break;
      case GREAT_THAN: {
        filter_result = (compare > 0);
      } break;
      case LIKE_TO: {
        filter_result = left_cell.like(right_cell);
      } break;
      case NOT_LIKE: {
        filter_result = !left_cell.like(right_cell);
      } break;
      case COMP_IS_NOT: {
        filter_result = false;
      } break;
      case COMP_IS: {
        filter_result = false;
      } break;
      default:
        break;
    }
  }
  return filter_result;
}
inline RC get_valuse_from_signle_field_select(std::vector<TupleCell> &values, SelectStmt *select_stmt)
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

  RC rc = RC::SUCCESS;
  PredicateOperator pred_oper(select_stmt->filter_stmt());
  pred_oper.add_child(scan_oper);
  ProjectOperator project_oper;
  project_oper.add_child(&pred_oper);
  if (select_stmt->query_fields().size() != 1)
    return RC::GENERIC_ERROR;
  for (const Field &field : select_stmt->query_fields()) {
    project_oper.add_projection(field.table(), field.meta());
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
RC FieldExpr::get_value(const Tuple &tuple, TupleCell &cell) const
{
  return tuple.find_cell(field_, cell);
}

RC ValueExpr::get_value(const Tuple &tuple, TupleCell &cell) const
{
  cell = tuple_cell_;
  return RC::SUCCESS;
}
bool Inexpr::do_compare(TupleCell left)
{
  if (ptr != nullptr)
    return do_expr(left);
  for (int i = 0; i < tuplecells.size(); ++i) {
    if (gen_compare_res(left, tuplecells[i], EQUAL_TO)) {
      return true;
    }
  }
  return false;
}
bool Inexpr::do_expr(TupleCell left)
{
  std::vector<TupleCell> tupe;
  get_valuse_from_signle_field_select(tupe, ptr);
  for (int i = 0; i < tupe.size(); ++i) {
    if (gen_compare_res(left, tupe[i], EQUAL_TO)) {
      return true;
    }
  }
  return false;
}
bool NotInexpr::do_expr(TupleCell left)
{
  std::vector<TupleCell> tupe;
  get_valuse_from_signle_field_select(tupe, ptr);
  for (int i = 0; i < tupe.size(); ++i) {
    if (!gen_compare_res(left, tupe[i], NOT_EQUAL)) {
      return false;
    }
  }
  return true;
}
bool NotInexpr::do_compare(TupleCell left)
{
  if (ptr != nullptr)
    return do_expr(left);
  for (int i = 0; i < tuplecells.size(); ++i) {
    if (!gen_compare_res(left, tuplecells[i], NOT_EQUAL)) {
      return false;
    }
  }
  return true;
}
bool NormalCopExpr::do_compare(TupleCell left){
  std::vector<TupleCell> tupe;
  get_valuse_from_signle_field_select(tupe, ptr);
  if (tupe.size() != 1)return false;
  return gen_compare_res(left,tupe[0],cmp);
}
bool ExitsnotExits::do_compare(Tuple *left)
{
  RC rc = RC::SUCCESS;
  FieldExpr *leftEx = dynamic_cast<FieldExpr *>(ptr->filter_stmt()->filter_units()[0]->left());
  FieldExpr *right = dynamic_cast<FieldExpr *>(ptr->filter_stmt()->filter_units()[0]->right());
  auto com = ptr->filter_stmt()->filter_units()[0]->comp();

  Operator *scan_oper2 = new TableScanOperator(ptr->tables()[0]);
  PredicateOperator pred_oper2(nullptr);
  pred_oper2.add_child(scan_oper2);
  pred_oper2.open();
  TupleCell leftcell;
  leftEx->get_value(*left, leftcell);
  bool canAdd;
  if (ExprType::EXIST == ee)
    canAdd = false;
  else
    canAdd = true;
  while ((rc = pred_oper2.next()) == RC::SUCCESS) {
    // get current record
    // write to response
    Tuple *tuple2 = pred_oper2.current_tuple();
    TupleCell rightcell;
    right->get_value(*tuple2, rightcell);
    // Exist 0xff
    if (ExprType::EXIST == ee) {
      if (gen_compare_res(leftcell, rightcell, com)) {
        canAdd = true;
        break;
      }
    } else {
      if (gen_compare_res(leftcell, rightcell, com)) {
        canAdd = false;
        break;
      }
    }
  }
  pred_oper2.close();
  delete scan_oper2;
  return canAdd;
}