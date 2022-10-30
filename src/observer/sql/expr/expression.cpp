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
#include "../stmt/filter_stmt.h"
#include "../stmt/select_stmt.h"
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
RC FieldExpr::get_value(const Tuple &tuple, TupleCell &cell) const
{
  return tuple.find_cell(field_, cell);
}

RC ValueExpr::get_value(const Tuple &tuple, TupleCell & cell) const
{
  cell = tuple_cell_;
  return RC::SUCCESS;
}
bool Inexpr::do_compare(TupleCell left){
    for(int i=0;i<tuplecells.size();++i){
      if(gen_compare_res(left,tuplecells[i],EQUAL_TO)){
        return true;
      }
    }
    return false;
}
bool NotInexpr::do_compare(TupleCell left){
    for(int i=0;i<tuplecells.size();++i){
      if(!gen_compare_res(left,tuplecells[i],NOT_EQUAL)){
        return false;
      }
    }
    return true;
  }
bool ExitsnotExits::do_compare(Tuple *left){
    RC rc = RC::SUCCESS;
  FieldExpr  *leftEx = dynamic_cast<FieldExpr *>(ptr->filter_stmt()->filter_units()[0]->left());
  FieldExpr  *right = dynamic_cast<FieldExpr *>(ptr->filter_stmt()->filter_units()[0]->right());
  auto com = ptr->filter_stmt()->filter_units()[0]->comp();
  
    Operator *scan_oper2 = new TableScanOperator(ptr->tables()[0]);
    PredicateOperator pred_oper2(nullptr);
    pred_oper2.add_child(scan_oper2);
    pred_oper2.open();
    TupleCell leftcell;
    leftEx->get_value(*left,leftcell);
    bool canAdd;
    if(ExprType::EXIST==ee)canAdd=false;
    else canAdd=true;
    while ((rc = pred_oper2.next()) == RC::SUCCESS) {
      // get current record
      // write to response
      Tuple *tuple2 = pred_oper2.current_tuple();
      TupleCell rightcell;
      right->get_value(*tuple2,rightcell);
      //Exist 0xff
      if(ExprType::EXIST==ee){
        if(gen_compare_res(leftcell,rightcell,com)){
          canAdd=true;
          break;
        }
      }else{
        if(gen_compare_res(leftcell,rightcell,com)){
          canAdd=false;
          break;
        }
      }
    }
    pred_oper2.close();
    delete scan_oper2;
    return canAdd;
  }