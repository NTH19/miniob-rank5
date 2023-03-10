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
// Created by Meiyi 
//

#include <mutex>
#include "sql/parser/parse.h"
#include "rc.h"
#include "common/log/log.h"

RC parse(char *st, Query *sqln);

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

void relation_attr_init(RelAttr *relation_attr, const char *relation_name, const char *attribute_name)
{
  if (relation_name != nullptr) {
    relation_attr->relation_name = strdup(relation_name);
  } else {
    relation_attr->relation_name = nullptr;
  }
  relation_attr->attribute_name = strdup(attribute_name);
}

void relation_attr_destroy(RelAttr *relation_attr)
{
  free(relation_attr->relation_name);
  free(relation_attr->attribute_name);
  relation_attr->relation_name = nullptr;
  relation_attr->attribute_name = nullptr;
}

void value_init_astexpr(AstExpr *expr, Value *value) {
  if (expr->type == VALUE_EXPR) {
    *value = expr->value;
  } else if (expr->type == SUB_OP && expr->right->type == VALUE_EXPR) {
    *value = expr->right->value;
    if(value->type == INTS) {
      int val = *(int *)value->data;
      *(int *)value->data = -val;
    } else if (value->type == FLOATS) {
      float val = *(float *)value->data;
      *(float *)value->data = -val;
    } else {
      LOG_PANIC("invalid expr 1");
    }
  } else {
    LOG_PANIC("invalid expr 2");
  }
}

void value_init_null(Value *value) {
  value->data = nullptr;
  value->type = UNDEFINED;
  value->_is_null = 1;
}
void value_init_integer(Value *value, int v)
{
  value->type = INTS;
  value->data = malloc(sizeof(v));
  value->_is_null = 0;
  memcpy(value->data, &v, sizeof(v));
}
void value_init_float(Value *value, float v)
{
  value->type = FLOATS;
  value->data = malloc(sizeof(v));
  value->_is_null = 0;
  memcpy(value->data, &v, sizeof(v));
}

void value_init_string(Value *value, const char *v)
{
  value->type = CHARS;
  value->data = strdup(v);
  value->_is_null=0;
}

int value_init_date(Value* value, const char* v) {
    value->type = DATES;
    int y,m,d;
    sscanf(v, "%d-%d-%d", &y, &m, &d);//not check return value eq 3, lex guarantee
    bool b = check_date(y,m,d);
    if(!b) return -1;
    int dv = y*10000+m*100+d;
    value->data = malloc(sizeof(dv));//TODO:check malloc failure
    value->_is_null = 0;
    memcpy(value->data, &dv, sizeof(dv));
    return 0;
}
int check_date(int y, int m, int d)
{
    static int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = (y%400==0 || (y%100 && y%4==0));
    return y > 0
        && (m > 0)&&(m <= 12)
        && (d > 0)&&(d <= ((m==2 && leap)?1:0) + mon[m]);
}
void value_destroy(Value *value)
{
  value->type = UNDEFINED;
  free(value->data);
  value->data = nullptr;
  value->_is_null = 0;
}
void condition_init_with_two_query(Condition *condition,CompOp comp,Selects *l,Selects *r){
  condition->comp=comp;
  condition->value_num=0;
  condition->left_type=SEL;
  condition->right_type=SEL;
  condition->sel[0]=l;
  condition->sel[1]=r;
  condition->left_expr = nullptr;
  condition->right_expr = nullptr;
}
void condition_init_with_query(Condition *condition, CompOp comp, RelAttr *left_attr,Selects *p){
  condition->comp=comp;
  condition->value_num=0;
  if(left_attr==NULL){
    condition->left_type=NONE;
  }else{
  condition->left_type=ATTR;
  condition->left_attr = *left_attr;
  }
  condition->right_type=SEL;
  condition->sel[1]=p;
  condition->sel[0]=nullptr;
  condition->left_expr = nullptr;
  condition->right_expr = nullptr;
}
void condition_init(Condition *condition, CompOp comp, int left_is_attr, RelAttr *left_attr, Value *left_value,
    int right_is_attr, RelAttr *right_attr, Value *right_value)
{
  condition->comp = comp;
  condition->value_num=0;
  if (left_is_attr) {
    condition->left_attr = *left_attr;
    condition->left_type=ATTR;
  } else {
    condition->left_value = *left_value;
    condition->left_type=VALUE;
  }

  if (right_is_attr) {
    condition->right_attr = *right_attr;
    condition->right_type=ATTR;
  } else {
    condition->right_value = *right_value;
    condition->right_type=VALUE;
  }
  condition->sel[0]=nullptr;
  condition->sel[1]=nullptr;
  condition->left_expr = nullptr;
  condition->right_expr = nullptr;
}

void condition_init_from_expr(Condition *condition, CompOp comp, AstExpr *left, AstExpr *right) {
  condition->comp = comp;
  condition->value_num = 0;
  condition->left_expr = nullptr;
  condition->right_expr = nullptr;
  condition->sel[0]=nullptr;
  condition->sel[1]=nullptr;
  if (left->type == AstExprType::VALUE_EXPR) {
    condition->left_value = left->value;
    condition->left_type = VALUE;
  } else if (left->type == AstExprType::ATTR_EXPR) {
    condition->left_attr = left->attr;
    condition->left_type = ATTR;
  } else {
    condition->left_expr = left;
    condition->left_type = AST_EXPR;
  }

  if (right->type == AstExprType::VALUE_EXPR) {
    condition->right_value = right->value;
    condition->right_type = VALUE;
  } else if (right->type == AstExprType::ATTR_EXPR) {
    condition->right_attr = right->attr;
    condition->right_type = ATTR;
  } else {
    condition->right_expr = right;
    condition->right_type = AST_EXPR;
  }
}

void condition_destroy(Condition *condition)
{
  // if (condition->left_is_attr) {
  //   relation_attr_destroy(&condition->left_attr);
  // } else {
  //   value_destroy(&condition->left_value);
  // }
  // if (condition->right_is_attr) {
  //   relation_attr_destroy(&condition->right_attr);
  // } else {
  //   value_destroy(&condition->right_value);
  // }
}


void attr_info_init(AttrInfo *attr_info, const char *name, AttrType type, size_t length, int nullable)
{
  attr_info->name = strdup(name);
  attr_info->type = type;
  attr_info->length = length;
  attr_info->_nullable = nullable;
}
void attr_info_destroy(AttrInfo *attr_info)
{
  free(attr_info->name);
  attr_info->name = nullptr;
  attr_info->_nullable = 0;
}

void selects_init(Selects *selects) {
  selects->attr_num = 0;
  selects->aggfun_num = 0;
  selects->relation_num = 0;
  selects->expr_num = 0;
  selects->sub_query_num = 0;
  selects->alias_num = 0;
  selects->condition_num = 0;
  selects->order_num = 0;
}

void selects_append_order(Selects *selects, RelAttr *rel_attr, OrderType type) {
  selects->order_by[selects->order_num].attribute = *rel_attr;
  selects->order_by[selects->order_num].type = type;
  selects->order_num++;
}

void selects_append_attribute(Selects *selects, RelAttr *rel_attr)
{
  selects->attributes[selects->attr_num++] = *rel_attr;
}

void selects_reverse_append_attribute(Selects *selects, RelAttr *rel_attr) {
  for(size_t i = selects->attr_num; i > 0; i -- ) {
    selects->attributes[i] = selects->attributes[i - 1];
  }
  selects->attributes[0] = *rel_attr;
  selects->attr_num++;
}

void condition_init_cells_for_in(Condition *c, RelAttr *left_attr,Value values[], size_t value_num,CompOp cmp)
{
  c->left_type = ATTR;
  c->left_attr = *left_attr;
  c->value_num=value_num;
  c->right_type=CELLS;
  c->comp=cmp;
  c->left_expr = nullptr;
  c->right_expr = nullptr;
  for(int i=0;i<value_num;++i){
    c->values[i]=values[i];
  }
  c->sel[0]=nullptr;
  c->sel[1]=nullptr;
}

void selects_append_relation(Selects *selects, const char *relation_name)
{
  selects->relations[selects->relation_num++] = strdup(relation_name);
}
void selects_append_aggfun(Selects *selects, AggFun * a)
{
  selects->aggFun[selects->aggfun_num++]=*a;
}

void selects_reverse_append_aggfun(Selects *selects, AggFun * a) {
  for(size_t i = selects->aggfun_num; i > 0; i --) {
    selects->aggFun[i] = selects->aggFun[i - 1];
  }
  selects->aggFun[0] = *a;
  selects->aggfun_num++;
}

void selects_append_alias2(Selects *selects, const char *relation_name,const char * attr_name,const char* alias)
{
  selects->real_name[selects->alias_num]=strdup((new std::string(relation_name))->append(".").append(attr_name).c_str());
  selects->alias_name[selects->alias_num]=strdup(alias);
  selects->alias_num++;
}
void selects_append_alias3(Selects *selects, AggFun * a,const char* alias)
{
  char* i=(char*)&(a->des);
  if (a->attr.relation_name) selects->real_name[selects->alias_num]=strdup((new std::string(a->attr.relation_name))->append(".").append(a->attr.attribute_name).c_str());
  else selects->real_name[selects->alias_num]=strdup((new std::string(i))->append(".").append(a->attr.attribute_name).c_str());
  selects->alias_name[selects->alias_num]=strdup(alias);
  selects->alias_num++;
  a->alias_name= strdup(alias);
}
void selects_append_alias(Selects *selects, const char * name,const char* alias)
{
  selects->real_name[selects->alias_num]=strdup(name);
  selects->alias_name[selects->alias_num]=strdup(alias);
  selects->alias_num++;
}
void Init_AggFun(AggFun * a, DescribeFun des, const char* arr_name){
  a->attr.attribute_name = strdup(arr_name);
  a->des = des;
  a->attr.relation_name=nullptr;
  a->alias_name=nullptr;
}
void Init_AggFun1(AggFun * a, DescribeFun des, const char* arr_name,const char * alias_name){
  a->attr.attribute_name = strdup(arr_name);
  a->des = des;
  a->attr.relation_name=nullptr;
  a->alias_name=strdup(alias_name);

}
void Init_AggFun_Rel(AggFun *a, DescribeFun des, const char* rel_name, const char* arr_name) {
  a->attr.relation_name = strdup(rel_name);
  a->attr.attribute_name = strdup(arr_name);
  a->des = des;
  a->alias_name=nullptr;
}

void selects_append_conditions(Selects *selects, Condition conditions[], size_t condition_num)
{
  assert(condition_num <= sizeof(selects->conditions) / sizeof(selects->conditions[0]));
  for (size_t i = 0; i < condition_num; i++) {
    selects->conditions[i] = conditions[i];
  }
  selects->condition_num = condition_num;
}
void selects_setup_having_condition(Selects *selects, Condition conditions[])
{
  selects->hav_con[0]=conditions[0];
  selects->ha_num=1;
}
void selects_append_conditions_start(Selects *selects, Condition conditions[], size_t start,size_t end)
{
  assert(end-start <= sizeof(selects->conditions) / sizeof(selects->conditions[0]));
  for (size_t i = start; i < end; i++) {
    selects->conditions[i - start] = conditions[i];
  }
  selects->condition_num = end-start;
}

void selects_append_expr(Selects *selects, AstExpr *expr) {
  switch (expr->type)
  {
  case AstExprType::ATTR_EXPR:
    if (expr->need_append) {
      selects_append_attribute(selects, &expr->attr);
    }
    break; 
  case AstExprType::AGG_EXPR:
    if (expr->need_append) {
      selects_append_aggfun(selects, &expr->agg);
    }
    break;
  default:
    selects->attr_expr[selects->expr_num++] = *expr;
    break;
  }
  // TODO: free(expr);
}

void selects_destroy(Selects *selects)
{
  for (size_t i = 0; i < selects->attr_num; i++) {
    relation_attr_destroy(&selects->attributes[i]);
  }
  selects->attr_num = 0;

  for (size_t i = 0; i < selects->relation_num; i++) {
    free(selects->relations[i]);
    selects->relations[i] = NULL;
  }
  selects->relation_num = 0;

  for (size_t i = 0; i < selects->condition_num; i++) {
    condition_destroy(&selects->conditions[i]);
  }
  selects->condition_num = 0;

  for(size_t i = 0; i < selects->aggfun_num; i++) {
    relation_attr_destroy(&selects->aggFun[i].attr);
  }
  selects->aggfun_num = 0;
  for(size_t i = 0; i < selects->alias_num; i++) {
    free(selects->alias_name[i]);
    free(selects->real_name[i]);
    selects->alias_name[i]=NULL;
    selects->real_name[i]=NULL;
  }
  selects->alias_num = 0;
  for (size_t i = 0; i < selects->order_num; i++) {
    relation_attr_destroy(&selects->attributes[i]);
  }
  selects->order_num = 0;
}

void inserts_init(Inserts *inserts, const char *relation_name, Value values[], size_t value_num,size_t single_record_length[], size_t record_num)
{
  assert(value_num <= sizeof(inserts->values) / sizeof(inserts->values[0][0]));

  inserts->relation_name = strdup(relation_name);
  size_t cou=single_record_length[0];
  for (size_t i = 0,j=0,co=0; i < value_num,j<record_num; i++,co++) {
    if (i>=cou){
      j++;
      cou=single_record_length[j];
      co=0;
    }
    inserts->values[j][co] = values[i];
  }
  for(size_t i = 0;i < record_num;i++){
    inserts->record_length[i] = single_record_length[i];
  }
  inserts->record_num = record_num;
  inserts->value_num = value_num;
}
void inserts_destroy(Inserts *inserts)
{
  free(inserts->relation_name);
  inserts->relation_name = nullptr;

  for(size_t j = 0;j < inserts->record_num; j++){
    for (size_t i = 0; i < inserts->value_num; i++) {
      value_destroy(&inserts->values[j][i]);
    }
  }
  
  inserts->record_num = 0;
  inserts->value_num = 0;
}

void deletes_init_relation(Deletes *deletes, const char *relation_name)
{
  deletes->relation_name = strdup(relation_name);
}

void deletes_set_conditions(Deletes *deletes, Condition conditions[], size_t condition_num)
{
  assert(condition_num <= sizeof(deletes->conditions) / sizeof(deletes->conditions[0]));
  for (size_t i = 0; i < condition_num; i++) {
    deletes->conditions[i] = conditions[i];
  }
  deletes->condition_num = condition_num;
}
void deletes_destroy(Deletes *deletes)
{
  for (size_t i = 0; i < deletes->condition_num; i++) {
    condition_destroy(&deletes->conditions[i]);
  }
  deletes->condition_num = 0;
  free(deletes->relation_name);
  deletes->relation_name = nullptr;
}

void updates_selects_append_attribute(Updates *updates, RelAttr *rel_attr) {
  selects_append_attribute(&updates->update_attrs[updates->attr_num].select, rel_attr);
}

void updates_selects_append_aggfun(Updates *updates, AggFun * a) {
  selects_append_aggfun(&updates->update_attrs[updates->attr_num].select, a);
}

void updates_selects_append_conditions(Updates *updates, Condition conditions[], size_t condition_num) {
  selects_append_conditions(&updates->update_attrs[updates->attr_num].select, conditions, condition_num);
}

void updates_selects_append_relation(Updates *updates, const char *relation_name) {
  selects_append_relation(&updates->update_attrs[updates->attr_num].select, relation_name);
}

void updates_append_value(Updates *updates, Value *value) {
  updates->update_attrs[updates->attr_num].value = *value;
}

void updates_append_attr(Updates *updates, const char *attr_name) {
  updates->update_attrs[updates->attr_num].attribute_name = strdup(attr_name);
  updates->attr_num ++;
}

void updates_init(Updates *updates, const char *relation_name, Condition conditions[], size_t condition_num)
{
  updates->relation_name = strdup(relation_name);

  assert(condition_num <= sizeof(updates->conditions) / sizeof(updates->conditions[0]));
  for (size_t i = 0; i < condition_num; i++) {
    updates->conditions[i] = conditions[i];
  }
  updates->condition_num = condition_num;
}

void updates_destroy(Updates *updates)
{
  free(updates->relation_name);
  updates->relation_name = nullptr;
  
  for (size_t i = 0; i < updates->attr_num; i++) {
    free(updates->update_attrs[i].attribute_name);
    updates->update_attrs[i].attribute_name = nullptr;
    value_destroy(&updates->update_attrs[i].value);
    selects_destroy(&updates->update_attrs[i].select);
  }
  updates->attr_num = 0;

  for (size_t i = 0; i < updates->condition_num; i++) {
    condition_destroy(&updates->conditions[i]);
  }
  updates->condition_num = 0;
}

void create_table_append_attribute(CreateTable *create_table, AttrInfo *attr_info)
{
  create_table->attributes[create_table->attribute_count++] = *attr_info;
}

void show_indexes_init(ShowIndex *s, const char *relation_name)
{
  s->relation_name = strdup(relation_name);
}

void create_table_init_name(CreateTable *create_table, const char *relation_name)
{
  create_table->relation_name = strdup(relation_name);
}

void create_table_destroy(CreateTable *create_table)
{
  for (size_t i = 0; i < create_table->attribute_count; i++) {
    attr_info_destroy(&create_table->attributes[i]);
  }
  create_table->attribute_count = 0;
  free(create_table->relation_name);
  create_table->relation_name = nullptr;
}

void drop_table_init(DropTable *drop_table, const char *relation_name)
{
  drop_table->relation_name = strdup(relation_name);
}

void drop_table_destroy(DropTable *drop_table)
{
  free(drop_table->relation_name);
  drop_table->relation_name = nullptr;
}

void create_index_init(CreateIndex *create_index, const char *index_name, 
                        const char *relation_name, int unique)
{
  create_index->unique = unique;
  create_index->index_name = strdup(index_name);
  create_index->relation_name = strdup(relation_name);
}

void create_index_append_attribute(CreateIndex *create_index, const char *attr_name)
{
  create_index->attribute_name[create_index->attribute_count++] = strdup(attr_name);
}

void create_index_destroy(CreateIndex *create_index)
{
  free(create_index->index_name);
  free(create_index->relation_name);
  for(size_t i = 0; i < create_index->attribute_count; ++ i) {
    free(create_index->attribute_name[i]);
  }

  create_index->index_name = nullptr;
  create_index->relation_name = nullptr;
  create_index->attribute_count = 0;
}

void drop_index_init(DropIndex *drop_index, const char *index_name)
{
  drop_index->index_name = strdup(index_name);
}

void drop_index_destroy(DropIndex *drop_index)
{
  free((char *)drop_index->index_name);
  drop_index->index_name = nullptr;
}

void desc_table_init(DescTable *desc_table, const char *relation_name)
{
  desc_table->relation_name = strdup(relation_name);
}

void desc_table_destroy(DescTable *desc_table)
{
  free((char *)desc_table->relation_name);
  desc_table->relation_name = nullptr;
}

void load_data_init(LoadData *load_data, const char *relation_name, const char *file_name)
{
  load_data->relation_name = strdup(relation_name);

  if (file_name[0] == '\'' || file_name[0] == '\"') {
    file_name++;
  }
  char *dup_file_name = strdup(file_name);
  int len = strlen(dup_file_name);
  if (dup_file_name[len - 1] == '\'' || dup_file_name[len - 1] == '\"') {
    dup_file_name[len - 1] = 0;
  }
  load_data->file_name = dup_file_name;
}

void load_data_destroy(LoadData *load_data)
{
  free((char *)load_data->relation_name);
  free((char *)load_data->file_name);
  load_data->relation_name = nullptr;
  load_data->file_name = nullptr;
}

AstExpr *create_value_expr(Value *value) {
  AstExpr *expr = (AstExpr *)malloc(sizeof(AstExpr));
  expr->type = AstExprType::VALUE_EXPR;
  expr->value = *value;
  expr->left_brackets = 0;
  expr->right_brackets = 0;
  expr->left = nullptr;
  expr->right = nullptr;
  return expr;
}

AstExpr *create_attr_expr(RelAttr *attr, int need_append) {
  AstExpr *expr = (AstExpr *)malloc(sizeof(AstExpr));
  expr->type = AstExprType::ATTR_EXPR;
  expr->left_brackets = 0;
  expr->right_brackets = 0;
  expr->attr = *attr;
  expr->need_append = need_append;
  expr->left = nullptr;
  expr->right = nullptr;
  return expr;
}

AstExpr *create_agg_expr(AggFun *agg, int need_append) {
  AstExpr *expr = (AstExpr *)malloc(sizeof(AstExpr));
  expr->type = AstExprType::AGG_EXPR;
  expr->agg = *agg;
  expr->left_brackets = 0;
  expr->right_brackets = 0;
  expr->need_append = need_append;
  expr->left = nullptr;
  expr->right = nullptr;
  return expr;
}

AstExpr *create_astexpr(AstExprType type, AstExpr *left, AstExpr *right) {
  AstExpr *expr = (AstExpr *)malloc(sizeof(AstExpr));
  expr->type = type;
  expr->left_brackets = 0;
  expr->right_brackets = 0;
  expr->left = left;
  expr->right = right;
  return expr;
}

void query_init(Query *query)
{
  query->flag = SCF_ERROR;
  memset(&query->sstr, 0, sizeof(query->sstr));
}

Query *query_create()
{
  Query *query = (Query *)malloc(sizeof(Query));
  if (nullptr == query) {
    LOG_ERROR("Failed to alloc memroy for query. size=%ld", sizeof(Query));
    return nullptr;
  }

  query_init(query);
  return query;
}

void query_reset(Query *query)
{
  switch (query->flag) {
    case SCF_SELECT: {
      selects_destroy(&query->sstr.selection);
    } break;
    case SCF_INSERT: {
      inserts_destroy(&query->sstr.insertion);
    } break;
    case SCF_DELETE: {
      deletes_destroy(&query->sstr.deletion);
    } break;
    case SCF_UPDATE: {
      updates_destroy(&query->sstr.update);
    } break;
    case SCF_CREATE_TABLE: {
      create_table_destroy(&query->sstr.create_table);
    } break;
    case SCF_DROP_TABLE: {
      drop_table_destroy(&query->sstr.drop_table);
    } break;
    case SCF_CREATE_INDEX: {
      create_index_destroy(&query->sstr.create_index);
    } break;
    case SCF_DROP_INDEX: {
      drop_index_destroy(&query->sstr.drop_index);
    } break;
    case SCF_SYNC: {

    } break;
    case SCF_SHOW_TABLES:
      break;

    case SCF_DESC_TABLE: {
      desc_table_destroy(&query->sstr.desc_table);
    } break;

    case SCF_LOAD_DATA: {
      load_data_destroy(&query->sstr.load_data);
    } break;
    case SCF_CLOG_SYNC:
    case SCF_BEGIN:
    case SCF_COMMIT:
    case SCF_ROLLBACK:
    case SCF_HELP:
    case SCF_EXIT:
    case SCF_ERROR:
      break;
  }
}

void query_destroy(Query *query)
{
  query_reset(query);
  free(query);
}
#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

////////////////////////////////////////////////////////////////////////////////

extern "C" int sql_parse(const char *st, Query *sqls);

RC parse(const char *st, Query *sqln)
{
  sql_parse(st, sqln);

  if (sqln->flag == SCF_ERROR)
    return SQL_SYNTAX;
  else
    return SUCCESS;
}