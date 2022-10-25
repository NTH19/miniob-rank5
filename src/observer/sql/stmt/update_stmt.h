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
#include "sql/stmt/select_stmt.h"
#include "storage/common/field_meta.h"

class Table;
class FilterStmt;

class UpdateAttrInfo {
public:
  UpdateAttrInfo() = default;
  UpdateAttrInfo(const FieldMeta *field, const Value *value, SelectStmt *select_stmt) :
    field_(field), value_(value), select_stmt_(select_stmt)
    {}
  const FieldMeta *field_ = nullptr;
  const Value *value_ = nullptr;      // raw value from update sentence
  SelectStmt *select_stmt_ = nullptr;
  std::vector<Value> selected_values; // selected_values
};

class UpdateStmt : public Stmt
{
public:

  UpdateStmt() = default;
  ~UpdateStmt() override;

public:
  static RC create(Db *db, const Updates &update_sql, Stmt *&stmt);

public:
  Table *table() const {return table_;}
  int attr_num() const { return update_attrs_.size(); }
  std::vector<UpdateAttrInfo> &attrs(){ return update_attrs_; };
  FilterStmt *filter_stmt() const { return filter_stmt_; }
  StmtType type() const override { return StmtType::UPDATE; }

private:
  Table *table_ = nullptr;
  FilterStmt *filter_stmt_ = nullptr;
  std::vector<UpdateAttrInfo> update_attrs_;
};

