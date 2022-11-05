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

#pragma once

#include <string>
#include <unordered_map>
#include "sql/parser/parse_defs.h"
#include "sql/stmt/stmt.h"
#include "sql/expr/expression.h"
#include "common/log/log.h"
#include "storage/common/db.h"
#include "storage/common/table.h"

std::string double2string(double v);

std::string charptr2string(char *s, int length);

RC valid_expr(const AstExpr *expr, Table *default_table, std::unordered_map<std::string, Table *> *tables);
AstExpression *create_expr(const AstExpr *expr, Table *default_table, std::unordered_map<std::string, Table *> *tables);
void expr2string(AstExpr *expr, std::string *str);