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
// Created by WangYunlai on 2022/07/01.
//

#include "common/log/log.h"
#include "sql/operator/project_operator.h"
#include "storage/record/record.h"
#include "storage/common/table.h"
#include "queue"
RC ProjectOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("project operator must has 1 child");
    return RC::INTERNAL;
  }

  Operator *child = children_[0];
  RC rc = child->open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  return RC::SUCCESS;
}

RC ProjectOperator::next()
{
  return children_[0]->next();
}

RC ProjectOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}
Tuple *ProjectOperator::for_mu_tables()
{
  return &tuple_;
}
Tuple *ProjectOperator::current_tuple()
{
  tuple_.set_tuple(children_[0]->current_tuple());
  return &tuple_;
}
Tuple *ProjectOperator::process_one_tuple(Tuple *t)
{
  tuple_.set_tuple(t);
  return &tuple_;
}
void ProjectOperator::add_projection(
    const Table *table, const FieldMeta *field_meta, bool add_table, std::map<std::string,std::queue<std::string>>& alias_set)
{
  // 对单表来说，展示的(alias) 字段总是字段名称，
  // 对多表查询来说，展示的alias 需要带表名字
  TupleCellSpec *spec = new TupleCellSpec(new FieldExpr(table, field_meta));

  int i = alias_set.count(std::string(field_meta->name()));
  int j = alias_set.count(std::string(table->name()));
  const char *field_name = nullptr;
    const char *table_name = nullptr;
    if (j > 0)
        table_name = alias_set[std::string(table->name())].front().c_str();
      else
        table_name = table->name();
    std::string alias1 = (std::string(table_name)).append(".").append(std::string(field_meta->name()));
    std::string alias2 = (std::string(table->name())).append(".").append(std::string(field_meta->name()));
  if (!add_table) {
    if (alias_set.count(alias1) > 0)
      spec->set_alias(alias_set[alias1].front().c_str());
    else if (alias_set.count(alias2) > 0) spec->set_alias(alias_set[alias2].front().c_str());
    else {
    if (i > 0)
      spec->set_alias(alias_set[std::string(field_meta->name())].front().c_str());
    else
      spec->set_alias(field_meta->name());
      }
  } else {// multi tables

    if (alias_set.count(alias1) > 0)
      spec->set_alias(alias_set[alias1].front().c_str());
    else if (alias_set.count(alias2) > 0) spec->set_alias(alias_set[alias2].front().c_str());
    else {
      if (i > 0)
        field_name = alias_set[std::string(field_meta->name())].front().c_str();
      else
        field_name = field_meta->name();
      
      spec->set_alias((new std::string(table_name))->append(".").append(field_name).c_str());
    }
  }
  tuple_.add_cell_spec(spec);
}



void ProjectOperator::add_expr_projection(AstExpression *ast_expr) {
  TupleCellSpec *spec = new TupleCellSpec(ast_expr);
  spec->set_alias(ast_expr->alias.c_str());
  tuple_.add_cell_spec(spec);
}

RC ProjectOperator::tuple_cell_spec_at(int index, const TupleCellSpec *&spec) const
{
  return tuple_.cell_spec_at(index, spec);
}
