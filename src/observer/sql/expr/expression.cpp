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
  std::map<std::string, std::queue<std::string>> alias_set;
  alias_set.swap(select_stmt->aliasset_);
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
RC FieldExpr::get_value(const Tuple &tuple, TupleCell &cell) const
{
  return tuple.find_cell(field_, cell);
}

RC ValueExpr::get_value(const Tuple &tuple, TupleCell &cell) const
{
  cell = tuple_cell_;
  return RC::SUCCESS;
}
int Inexpr::do_compare(TupleCell left)
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
int Inexpr::do_expr(TupleCell left)
{
  std::vector<TupleCell> tupe;
  if(get_valuse_from_signle_field_select(tupe, ptr)==RC::ABORT)return 2;
  for (int i = 0; i < tupe.size(); ++i) {
    if (gen_compare_res(left, tupe[i], EQUAL_TO)) {
      return true;
    }
  }
  return false;
}
int NotInexpr::do_expr(TupleCell left)
{
  std::vector<TupleCell> tupe;
  if(get_valuse_from_signle_field_select(tupe, ptr)==RC::ABORT)return 2;
  for (int i = 0; i < tupe.size(); ++i) {
    if (!gen_compare_res(left, tupe[i], NOT_EQUAL)) {
      return false;
    }
  }
  return true;
}
int NotInexpr::do_compare(TupleCell left)
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
int NormalCopExpr::do_compare(TupleCell left){
  std::vector<TupleCell> tupe;
  if(get_valuse_from_signle_field_select(tupe, ptr)==RC::ABORT)return 2;
  if (tupe.size() != 1)return 2;
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

TupleCell null_cell() {
  TupleCell cell;
  char *data = new char[4];
  memcpy(data, __NULL_DATA__, 4);
  cell.set_data(data);
  cell.set_type(CHARS);
  cell.set_length(4);
  return cell;
}

float cell2float(TupleCell &cell) {
  if (cell.attr_type() == INTS) {
    return *(int *)cell.data();
  } else if(cell.attr_type() == FLOATS) {
    return *(float *)cell.data();
  } else {
    return 0;
  }
}

TupleCell cell_from_float(float val) {
  TupleCell cell;
  float *value = new float(val);
  cell.set_data((char *)value);
  cell.set_type(FLOATS);
  return cell;
}

TupleCell calculate(const AstExpression *ast_expr, const Tuple &tuple) {
  TupleCell cell;
  if(ast_expr == nullptr) {
    return cell_from_float(0);
  }
  switch (ast_expr->expr_type)
  {
  case AstExprType::VALUE_EXPR: {
    auto &value = ast_expr->value;
    cell.set_data((char *)value.data);
    cell.set_type(value.type);
    if (value.data != nullptr && value.type == CHARS) {
      cell.set_length(strlen((const char *)value.data));
    }
  } break;
  case AstExprType::ATTR_EXPR: {
    RC rc = tuple.find_cell(ast_expr->field, cell);
    if (rc != RC::SUCCESS) {
      LOG_PANIC("failed to get attr");
    }
  } break;
  case AstExprType::AGG_EXPR:
    // TODO: ???
    break;
  default: {
    TupleCell left_cell = calculate(ast_expr->left, tuple);
    TupleCell right_cell = calculate(ast_expr->right, tuple);
    if (left_cell.check_null() || right_cell.check_null()) {
      return null_cell();
    }
    float l_val = cell2float(left_cell);
    float r_val = cell2float(right_cell);
    switch (ast_expr->expr_type)
    {
    case AstExprType::ADD_OP:
      cell = cell_from_float(l_val + r_val);
      break;
    case AstExprType::SUB_OP:
      cell = cell_from_float(l_val - r_val);
      break;
    case AstExprType::MUL_OP:
      cell = cell_from_float(l_val * r_val);
      break;
    case AstExprType::DIV_OP:
      if (r_val == 0) {
        return null_cell();
      }
      cell = cell_from_float(l_val / r_val);
      break;
    }
  } break;
  }
  return cell;
}

RC AstExpression::get_value(const Tuple &tuple, TupleCell &cell) const {
  cell = calculate(this, tuple);
  LOG_INFO("ast expr[%s] call result: %f", this->alias.c_str(), cell2float(cell));
  return RC::SUCCESS;
}