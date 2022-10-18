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

#pragma once

#include "rc.h"
#include "sql/stmt/stmt.h"

class Table;
class FilterStmt;
class UpdateStmt : public Stmt
{
public:

  UpdateStmt() = default;
  UpdateStmt(Table *table, const Value* values, int value_amount,FilterStmt * filter_stmt,const char * attr, const char * data,const Updates& up);
~UpdateStmt() override;

public:
  static RC create(Db *db, const Updates &update_sql, Stmt *&stmt);

public:
  size_t condition_num;           // Length of conditions in Where clause
  Condition conditions[MAX_NUM];

  Table *table() const {return table_;}
  const Value* values() const { return values_; }
  int value_amount() const { return value_amount_; }
  const char* attribute(){return attribute_name_;}
  const char * data(){return new_data_;}
FilterStmt *filter_stmt() const { return filter_stmt_; }
StmtType type() const override { return StmtType::UPDATE; }
public:
  Table *table_ = nullptr;
  const Value* values_ ;
  int value_amount_ = 0;
  FilterStmt *filter_stmt_ = nullptr;
  const char* attribute_name_;
  const char* new_data_;
};

