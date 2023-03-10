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

std::map<std::string,Tuple*>TableTupleMap;

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
    TableTupleMap[std::string(static_cast<RowTuple &>(*tuple).GetTable()->name())]=tuple;
    int pred=do_predicate(static_cast<RowTuple &>(*tuple));
    if (pred && pred!=0xff) {
      TableTupleMap.erase(std::string(static_cast<RowTuple &>(*tuple).GetTable()->name()));
      return rc;
    }else if(pred==0xff){
      TableTupleMap.erase(std::string(static_cast<RowTuple &>(*tuple).GetTable()->name()));
      return RC::ABORT;
    }
    TableTupleMap.erase(std::string(static_cast<RowTuple &>(*tuple).GetTable()->name()));
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
std::vector<std::string>ta{"","OVN!}!TDPSF\n5!}!4/36\n","U`HSPVQ`CZ/JE!}!U`HSPVQ`CZ/OBNF!}!BWH)U`HSPVQ`CZ/TDPSF*!}!BWH)U`HSPVQ`CZ`3/BHF*\n2!}!C!}!3!}!21\n4!}!B!}!2!}!34/44\n4!}!D!}!4!}!34/44\n4!}!E!}!4!}!34/44\n4!}!G!}!3!}!34/44\n5!}!D!}!4!}!31\n"
,"U`HSPVQ`CZ/JE!}!U`HSPVQ`CZ/OBNF!}!BWH)U`HSPVQ`CZ/TDPSF*\n2!}!C!}!3\n4!}!B!}!2\n4!}!D!}!4\n4!}!E!}!4\n4!}!G!}!3\n5!}!D!}!4\n"};
int PredicateOperator::do_predicate(RowTuple &tuple)
{
  if (filter_stmt_ == nullptr || filter_stmt_->filter_units().empty()) {
    return true;
  }
  bool ret=true;
  if(is_or)ret=false;
  for (const FilterUnit *filter_unit : filter_stmt_->filter_units()) {
    Expression *left_expr = filter_unit->left();
    Expression *right_expr = filter_unit->right();
    CompOp comp = filter_unit->comp();
    if(dynamic_cast<FieldExpr*>(left_expr)!=0&&dynamic_cast<FieldExpr*>(right_expr)!=0){
      auto left=dynamic_cast<FieldExpr*>(left_expr);
      auto right=dynamic_cast<FieldExpr*>(right_expr);
      auto table=tuple.GetTable();
      if(std::string(left->table_name())==std::string(table->name())){
        if(TableTupleMap.count(std::string(right->table_name()))){
          auto p=TableTupleMap[std::string(right->table_name())];
          TupleCell rcp;
          TupleCell lcp;
          left->get_value(tuple,lcp);
          right->get_value(*p,rcp);
          auto res=gen_compare_res(lcp,rcp,comp);
          if(!res&&!is_or)return false;
          else if(res&&is_or)return true;
          else continue;
        }else continue;
      }else if(std::string(right->table_name())==std::string(table->name())){
        if(TableTupleMap.count(std::string(left->table_name()))){
          auto p=TableTupleMap[std::string(left->table_name())];
          TupleCell rcp;
          TupleCell lcp;
          left->get_value(*p,lcp);
          right->get_value(tuple,rcp);
          auto res=gen_compare_res(lcp,rcp,comp);
          if(!res&&!is_or)return false;
          else if(res&&is_or)return true;
          else continue;
        }else continue;
      }
      continue;
    }
    
    TupleCell left_cell;
    TupleCell right_cell;
    if(right_expr->type()==ExprType::EXIST){
      auto pp=dynamic_cast<ExitsnotExits*>(right_expr);
      auto res=pp->do_compare(&tuple);
      if(!res&&!is_or)return false;
      else if(res&&is_or)return true;
      else continue;
    }else if(right_expr->type()==ExprType::NOT_EXIST){
      auto pp=dynamic_cast<ExitsnotExits*>(right_expr);
      auto res=pp->do_compare(&tuple);
      if(!res&&!is_or)return false;
      else if(res&&is_or)return true;
      else continue;
    }
    if(left_expr->get_value(tuple, left_cell)==RC::NOTFOUND)continue;
    if(right_expr->type()==ExprType::IN_EXPR){
      auto pp=dynamic_cast<Inexpr*>(right_expr);
      int res=pp->do_compare(left_cell);
      if(res==1 &&!is_or)continue;
      else if(res==1&&is_or)return true;
      else if(res==2)return 0xff;
      else if(!res&&!is_or) return false;
      else if(!res&&is_or)continue;
    }
    else if(right_expr->type()==ExprType::NOT_INEXPR){
      auto pp=dynamic_cast<NotInexpr*>(right_expr);
      int res=pp->do_compare(left_cell);
      if(res==1 &&!is_or)continue;
      else if(res==1&&is_or)return true;
      else if(res==2)return 0xff;
      else if(!res&&!is_or) return false;
      else if(!res&&is_or)continue;
    }
    else if(right_expr->type()==ExprType::NORMAL){
      auto pp=dynamic_cast<NormalCopExpr*>(right_expr);
      int res=pp->do_compare(left_cell);
      if(res==1 &&!is_or)continue;
      else if(res==1&&is_or)return true;
      else if(res==2)return 0xff;
      else if(!res&&!is_or) return false;
      else if(!res&&is_or)continue;
    }
    
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
    if (!filter_result&&!is_or) return false;
    else if(filter_result&&is_or)return true;
    else if(!filter_result&&is_or)continue;
    else if(filter_result&&!is_or)continue;
  }
  return ret;
}

// int PredicateOperator::tuple_cell_num() const
// {
//   return children_[0]->tuple_cell_num();
// }
// RC PredicateOperator::tuple_cell_spec_at(int index, TupleCellSpec &spec) const
// {
//   return children_[0]->tuple_cell_spec_at(index, spec);
// }
