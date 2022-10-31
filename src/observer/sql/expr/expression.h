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

#pragma once
//#include "tuple.h"
#include <string.h>
#include "storage/common/field.h"
#include "sql/expr/tuple_cell.h"
class Tuple;

enum class ExprType {
  NONE,
  FIELD,
  VALUE,
  IN_EXPR,
  NOT_INEXPR,
  EXIST,
  NORMAL,
  NOT_EXIST
};
class SelectStmt;
class Expression
{
public: 
  Expression() = default;
  virtual ~Expression() = default;
  
  virtual RC get_value(const Tuple &tuple, TupleCell &cell) const = 0;
  virtual ExprType type() const = 0;
};
class Inexpr:public Expression{
public:

  virtual ~Inexpr() = default;
  ExprType type() const override
  {
    return ExprType::IN_EXPR;
  }
  bool do_compare(TupleCell left);
  bool do_expr(TupleCell left);
  RC get_value(const Tuple &tuple, TupleCell &cell) const override{return RC::SUCCESS;};
  std::vector<TupleCell> tuplecells;
  SelectStmt* ptr=nullptr;
};
class FieldExpr : public Expression
{
public:
  FieldExpr() = default;
  FieldExpr(const Table *table, const FieldMeta *field) : field_(table, field)
  {}

  virtual ~FieldExpr() = default;

  ExprType type() const override
  {
    return ExprType::FIELD;
  }

  Field &field()
  {
    return field_;
  }

  const Field &field() const
  {
    return field_;
  }

  const char *table_name() const
  {
    return field_.table_name();
  }

  const char *field_name() const
  {
    return field_.field_name();
  }

  RC get_value(const Tuple &tuple, TupleCell &cell) const override;
private:
  Field field_;
};

class ValueExpr : public Expression
{
public:
  ValueExpr() = default;
  ValueExpr(const Value &value) : tuple_cell_(value.type, (char *)value.data)
  {
    if (value.data != nullptr && value.type == CHARS) {
      tuple_cell_.set_length(strlen((const char *)value.data));
    }
  }

  virtual ~ValueExpr() = default;

  RC get_value(const Tuple &tuple, TupleCell & cell) const override;
  ExprType type() const override
  {
    return ExprType::VALUE;
  }

  void get_tuple_cell(TupleCell &cell) const {
    cell = tuple_cell_;
  }

private:
  TupleCell tuple_cell_;
};

class NotInexpr:public Expression{
public:

  virtual ~NotInexpr() = default;
  ExprType type() const override
  {
    return ExprType::NOT_INEXPR;
  }
  bool do_expr(TupleCell left);
  bool do_compare(TupleCell left);
  RC get_value(const Tuple &tuple, TupleCell &cell) const override{return RC::SUCCESS;};
  std::vector<TupleCell> tuplecells;
  SelectStmt* ptr=nullptr;
};

class ExitsnotExits:public Expression{
public:

  virtual ~ExitsnotExits() = default;
  ExprType type() const override
  {
    return ee;
  }
  bool do_compare(Tuple *left);
  RC get_value(const Tuple &tuple, TupleCell &cell) const override{return RC::SUCCESS;};
  SelectStmt* ptr;
  ExprType ee;
};

class NormalCopExpr:public Expression{
public:

  virtual ~NormalCopExpr() = default;
  ExprType type() const override
  {
    return ExprType::NORMAL;
  }
  bool do_compare(TupleCell left);
  RC get_value(const Tuple &tuple, TupleCell &cell) const override{return RC::SUCCESS;};
  SelectStmt* ptr=nullptr;
  CompOp cmp;
};