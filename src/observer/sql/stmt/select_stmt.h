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
// Created by Wangyunlai on 2022/6/5.
//

#pragma once

#include <vector>
#include<map>

#include "rc.h"
#include "sql/stmt/stmt.h"
#include "sql/expr/expression.h"
#include "storage/common/field.h"
# include<map>

class FieldMeta;
class FilterStmt;
class Db;
class Table;

struct Group_by{
  std::map<int,Group_by*>zhu;
  std::vector<std::pair<int,int>>ret;
  std::vector<int>char_len;
  std::string ans;
};

class SelectStmt : public Stmt
{
public:

  SelectStmt() = default;
  ~SelectStmt() override;

  StmtType type() const override { return StmtType::SELECT; }
public:
  static RC create(Db *db, const Selects &select_sql, Stmt *&stmt,bool outatble = false,std::map<std::string, std::queue<std::string>>* alias_name_set=nullptr);

public:
  const std::vector<Table *> &tables() const { return tables_; }
  const std::vector<Field> &query_fields() const { return query_fields_; }
  FilterStmt *filter_stmt() const { return filter_stmt_; }
  const std::vector<std::pair<DescribeFun,Field>> & funs()const {return funs_;}
  int need_reverse;

  int is_da=0;
  int group_num=0;
  Group_by* head=nullptr;

  std::map<std::string,std::queue<std::string>> aliasset_;
  std::vector<std::pair<Field,int>>   order_fields;
  std::vector<AstExpression *> ast_exprs_;

  std::vector<std::pair<DescribeFun,Field>> funs_;

private:
  std::vector<Field> query_fields_;
  std::vector<Table *> tables_;
  FilterStmt *filter_stmt_ = nullptr;

};

