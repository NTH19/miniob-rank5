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
// Created by WangYunlai on 2022/6/27.
//

#include "common/log/log.h"
#include "sql/operator/predicate_operator.h"
#include "storage/record/record.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/field.h"

RC PredicateOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("predicate operator must has one child");
    return RC::INTERNAL;
  }

  return children_[0]->open();
}

RC PredicateOperator::next()
{
  RC rc = RC::SUCCESS;
  Operator *oper = children_[0];
  
  while (RC::SUCCESS == (rc = oper->next())) {
    Tuple *tuple = oper->current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get tuple from operator");
      break;
    }

    if (do_predicate(static_cast<RowTuple &>(*tuple))) {
      return rc;
    }
  }
  return rc;
}

RC PredicateOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}

Tuple * PredicateOperator::current_tuple()
{
  return children_[0]->current_tuple();
}



bool PredicateOperator::do_predicate(RowTuple &tuple)
{
  if (filter_stmt_ == nullptr || filter_stmt_->filter_units().empty()) {
    return true;
  }

  for (const FilterUnit *filter_unit : filter_stmt_->filter_units()) {
    Expression *left_expr = filter_unit->left();
    Expression *right_expr = filter_unit->right();
    if(dynamic_cast<FieldExpr*>(left_expr)!=0&&dynamic_cast<FieldExpr*>(right_expr)!=0)continue;
    CompOp comp = filter_unit->comp();
    TupleCell left_cell;
    TupleCell right_cell;

    if(left_expr->get_value(tuple, left_cell)==RC::NOTFOUND)continue;
    if(right_expr->get_value(tuple, right_cell)==RC::NOTFOUND)continue;

    bool filter_result = false;
    bool left_null = left_cell.check_null();
    bool right_null = right_cell.check_null();

    if (left_null || right_null) {
      switch (comp) {
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
        case COMP_IS_NOT:{
          if(!left_null && right_null) { // value is not null
            filter_result = true;
          } else if (left_null && !right_null) { // null is not value
            filter_result = true;
          } else {                               // null is null
            filter_result = false;
          }
          break;
        }
        case COMP_IS: {
          if(!left_null && right_null) { // value is null
            filter_result = false;
          } else if (left_null && !right_null) { // null is value
            filter_result = false;
          } else {                              // null is null
            filter_result = true;
          }
          break;
        }
        default: {
          LOG_WARN("invalid compare type: %d", comp);
        } break;
      }
    }
    else {
      const int compare = (comp >= LIKE_TO ? 0 : left_cell.compare(right_cell));
      switch (comp) {
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
        case COMP_IS_NOT:{
          filter_result = false;
        }break;
        case COMP_IS: {
          filter_result = false;
        }break;
        default: {
          LOG_WARN("invalid compare type: %d", comp);
        } break;
      }
    }
    if (!filter_result) {
      return false;
    }
  }
  return true;
}

// int PredicateOperator::tuple_cell_num() const
// {
//   return children_[0]->tuple_cell_num();
// }
// RC PredicateOperator::tuple_cell_spec_at(int index, TupleCellSpec &spec) const
// {
//   return children_[0]->tuple_cell_spec_at(index, spec);
// }
