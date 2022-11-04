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
// Created by wangyunlai on 2022/9/28
//

#include <string.h>
#include "util/util.h"

std::string double2string(double v)
{
  char buf[256];
  snprintf(buf, sizeof(buf), "%.2f", v);
  size_t len = strlen(buf);
  while (buf[len - 1] == '0') {
    len--;
      
  }
  if (buf[len - 1] == '.') {
    len--;
  }

  return std::string(buf, len);
}

std::string charptr2string(char *s, int length) {
  std::string ss(s, length);
  return std::string(s, strlen(ss.c_str()));
}

RC valid_expr(const AstExpr *expr, Table *default_table, std::unordered_map<std::string, Table *> *tables) {
  if (expr == nullptr) {
    return RC::SUCCESS;
  }
  if (expr->type == AstExprType::ATTR_EXPR || expr->type == AstExprType::AGG_EXPR) {
    auto &attr = expr->type == AstExprType::ATTR_EXPR ? 
                  expr->attr : expr->agg.attr;
    Table *table = default_table;
    if(attr.relation_name != nullptr) {
      auto it = tables->find(attr.relation_name);
      if(it == tables->end()) {
        return RC::SCHEMA_TABLE_NOT_EXIST;
      }
      table = it->second;
    } else if(tables->size() != 1) {
      LOG_WARN("invalid. I do not know the attr's table. attr=%s", attr.attribute_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    const FieldMeta *field_meta = table->table_meta().field(attr.attribute_name);
    if (nullptr == field_meta) {
      LOG_WARN("no such field. field=%s.%s", table->name(), attr.attribute_name);
      return RC::SCHEMA_FIELD_MISSING;
    } 
  } else if (expr->type != AstExprType::VALUE_EXPR) {
    RC left_valid = valid_expr(expr->left, default_table, tables);
    if( left_valid != RC::SUCCESS) {
      return left_valid;
    }
    RC right_valid = valid_expr(expr->right, default_table, tables);
    if(right_valid != RC::SUCCESS) {
      return right_valid;
    }
  }
  return RC::SUCCESS;
}

AstExpression *create_expr(const AstExpr *expr, Table *default_table, std::unordered_map<std::string, Table *> *tables) {
  if (expr == nullptr) {
    return nullptr;
  }
  AstExpression *ret_expr = new AstExpression();
  ret_expr->expr_type = expr->type;
  ret_expr->left_brackets = expr->left_brackets;
  ret_expr->right_brackets = expr->right_brackets;
  if (expr->type == AstExprType::ATTR_EXPR || expr->type == AstExprType::AGG_EXPR) {
    auto &attr = expr->type == AstExprType::ATTR_EXPR ? 
                  expr->attr : expr->agg.attr;
    Table *table = default_table;
    if(attr.relation_name != nullptr) {
      auto it = tables->find(attr.relation_name);
      table = it->second;
    }
    const FieldMeta *field_meta = table->table_meta().field(attr.attribute_name);
    ret_expr->field = Field(table, field_meta);
    if (expr->type == AstExprType::AGG_EXPR) {
      ret_expr->agg = expr->agg.des;
    }
  } else if (expr->type == AstExprType::VALUE_EXPR) {
    ret_expr->value = expr->value;
  } else {
    ret_expr->left = create_expr(expr->left, default_table, tables);
    ret_expr->right = create_expr(expr->right, default_table, tables);
  }
  return ret_expr;
}

void value2string(Value &value, std::string *str) {
  switch (value.type)
  {
  case CHARS:
    str->append((char *)value.data);
    break;
  case INTS:
    str->append(std::to_string(*(int *)value.data));
    break;
  case FLOATS:
    str->append(double2string(*(float *)value.data));
    break;
  default:
    break;
  }
}

void attr2string(RelAttr &attr, std::string *str) {
  if (attr.relation_name != nullptr) {
    str->append(attr.relation_name);
    str->append(".");
  }
  str->append(attr.attribute_name);
}

void agg2string(AggFun &agg, std::string *str) {
  auto &attr = agg.attr;
  std::string attr_str;
  attr2string(attr, &attr_str);
  switch (agg.des) {
    case MAX:
      str->append("MAX(" + attr_str + ")");
      break;
    case MIN:
      str->append("MIN(" + attr_str + ")");
      break;
    case AVG:
      str->append("AVG(" + attr_str + ")");
      break;
    case SUM:
      str->append("SUM(" + attr_str + ")");
      break;
    case COUNT:
      str->append("COUNT(" + attr_str + ")");
      break;
    case COUNT_STAR:
      str->append("COUNT(*)");
      break;
  }
}

void expr2string(AstExpr *expr, std::string *str) {
  if(expr == nullptr) {
    return ;
  }
  for(int i = 0; i < expr->left_brackets; i ++) {
    str->push_back('(');
  }
  switch (expr->type)
  {
  case AstExprType::VALUE_EXPR:
    value2string(expr->value, str);
    break;
  case AstExprType::ATTR_EXPR:
    attr2string(expr->attr, str);
    break;
  case AstExprType::AGG_EXPR:
    agg2string(expr->agg, str);
    break;
  default:
    expr2string(expr->left, str);
    switch (expr->type)
    {
    case AstExprType::ADD_OP:
      str->push_back('+');
      break;
    case AstExprType::SUB_OP:
      str->push_back('-');
      break;
    case AstExprType::MUL_OP:
      str->push_back('*');
      break;
    case AstExprType::DIV_OP:
      str->push_back('/');
      break;
    default:
      LOG_PANIC("unknown expr type");
      break;
    }
    expr2string(expr->right, str);
    break;
  }
  for(int i = 0; i < expr->right_brackets; i ++) {
    str->push_back(')');
  }
}
