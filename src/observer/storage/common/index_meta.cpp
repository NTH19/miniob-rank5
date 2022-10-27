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
// Created by Meiyi & Wangyunlai.wyl on 2021/5/18.
//

#include "storage/common/index_meta.h"
#include "storage/common/field_meta.h"
#include "storage/common/table_meta.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "rc.h"
#include "json/json.h"

const static Json::StaticString INDEX_NAME("name");
const static Json::StaticString INDEX_UNIQUE("unique");
const static Json::StaticString INDEX_FIELDS("fileds");

RC IndexMeta::init(const char *name, const std::vector<const FieldMeta *> &fields, bool unique)
{
  if (common::is_blank(name)) {
    LOG_ERROR("Failed to init index, name is empty.");
    return RC::INVALID_ARGUMENT;
  }

  unique_ = unique;
  name_ = name;
  fields_.clear();
  for (const FieldMeta* field: fields) {
    fields_.emplace_back(field->name());
  }
  return RC::SUCCESS;
}

bool IndexMeta::unique() const {
  return unique_;
}

void IndexMeta::to_json(Json::Value &json_value) const
{
  json_value[INDEX_NAME] = name_;
  json_value[INDEX_UNIQUE] = Json::Value(unique_);
  Json::Value fileds;
  for(const std::string &field : fields_) {
    fileds.append(Json::Value(field));
  }
  json_value[INDEX_FIELDS] = fileds;
}

RC IndexMeta::from_json(const TableMeta &table, const Json::Value &json_value, IndexMeta &index)
{
  const Json::Value &name_value = json_value[INDEX_NAME];
  const Json::Value &field_value = json_value[INDEX_FIELDS];
  const Json::Value &unique_value = json_value[INDEX_UNIQUE];

  if (!name_value.isString()) {
    LOG_ERROR("Index name is not a string. json value=%s", name_value.toStyledString().c_str());
    return RC::GENERIC_ERROR;
  }

  if (!field_value.isArray()) {
    LOG_ERROR("Field name of index [%s] is not an array", name_value.asCString());
    return RC::GENERIC_ERROR;
  }

  if(!unique_value.isBool()) {
    LOG_ERROR("unique of index [%s] is not a bool", name_value.asCString());
    return RC::GENERIC_ERROR;
  }

  int num = field_value.size();
  std::vector<const FieldMeta *> fields(num);

  for(int i = 0; i < num; i ++) {
    const Json::Value &value = field_value[i];
    if (!value.isString()) {
      return RC::GENERIC_ERROR;
    }
    const FieldMeta *field = table.field(value.asCString());
    if (nullptr == field) {
      LOG_ERROR("Deserialize index [%s]: no such field: %s", name_value.asCString(), value.asCString());
      return RC::SCHEMA_FIELD_MISSING;
    }
    fields[i] = field;
  }

  return index.init(name_value.asCString(), fields, unique_value.asBool());
}

const char *IndexMeta::name() const
{
  return name_.c_str();
}

const std::vector<std::string> &IndexMeta::fields() const
{
  return fields_;
}

void IndexMeta::desc(std::ostream &os) const
{
  os << "index name=" << name_ << ", field=" << desc_field();
}

std::string IndexMeta::desc_field() const {
  std::string s("[");
  for(size_t i = 0; i < fields_.size(); i ++) {
    if (i != 0) {
      s.append(", ");
    }
    s.append(fields_[i]);
  }
  s.append("]");
  return s;
}