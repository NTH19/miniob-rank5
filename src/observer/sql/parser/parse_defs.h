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

#ifndef __OBSERVER_SQL_PARSER_PARSE_DEFS_H__
#define __OBSERVER_SQL_PARSER_PARSE_DEFS_H__
#include <stddef.h>

#define MAX_NUM 20
#define MAX_REL_NAME 20
#define MAX_ATTR_NAME 20
#define MAX_ERROR_MESSAGE 20
#define MAX_DATA 50

//属性结构体
typedef struct {
  char *relation_name;   // relation name (may be NULL) 表名
  char *attribute_name;  // attribute name              属性名
} RelAttr;

typedef enum _CompOp{
  EQUAL_TO,     //"="     0
  LESS_EQUAL,   //"<="    1
  NOT_EQUAL,    //"<>"    2
  LESS_THAN,    //"<"     3
  GREAT_EQUAL,  //">="    4
  GREAT_THAN,   //">"     5
  LIKE_TO,      //"like"
  NOT_LIKE,     //"not like"   
  COMP_IS_NOT,
  COMP_IS,       
  NO_OP,
  IN,
  NOT_IN,
  EXIST,
  NOT_EXIST
} CompOp;

//属性值类型
typedef enum
{
  UNDEFINED,
  CHARS,
  INTS,
  FLOATS,
  DATES,
  TEXTS
} AttrType;
typedef enum
{
  SUM,
  COUNT,
  COUNT_STAR,
  MAX,
  MIN,
  AVG
} DescribeFun;
//属性值
typedef struct _Value {
  AttrType type;  // type of value
  void *data;     // value
  int _is_null;
} Value;

typedef struct _OrderBy {
  RelAttr attribute;  // order by this attribute
  int     order;      // 0:asc, 1:desc
} OrderBy;

struct _Selects;

typedef struct {
  DescribeFun des;
  RelAttr attr;
   char * alias_name;
} AggFun;

typedef enum _AstExprType {
  VALUE_EXPR,
  ATTR_EXPR,
  AGG_EXPR,
  ADD_OP,
  SUB_OP,
  MUL_OP,
  DIV_OP,
} AstExprType;

typedef struct _AstExpr {
  AstExprType type;
  union {
    Value value;
    RelAttr attr;
    AggFun agg;
  };
  // 左右括号的数量
  int left_brackets;
  int right_brackets;
  int need_append;
  struct _AstExpr *left;
  struct _AstExpr *right;
} AstExpr;

enum Con_type{
  ATTR,
  VALUE,
  CELLS,
  NONE,
  SEL,
  AST_EXPR
};

typedef struct _Condition {
  enum Con_type left_type;    // TRUE if left-hand side is an attribute
                       // 1时，操作符左边是属性名，0时，是属性值
  Value left_value;    // left-hand side value if left_is_attr = FALSE
  RelAttr left_attr;   // left-hand side attribute
  CompOp comp;         // comparison operator
  enum Con_type right_type;   // TRUE if right-hand side is an attribute
                       // 1时，操作符右边是属性名，0时，是属性值
  RelAttr right_attr;  // right-hand side attribute if right_is_attr = TRUE 右边的属性
  Value right_value;   // right-hand side value if right_is_attr = FALSE
  int value_num;
  struct _Selects *sel[2];
  Value  values[MAX_NUM];

  AstExpr *left_expr;
  AstExpr *right_expr;
} Condition;

struct _Selects{
  size_t attr_num;                // Length of attrs in Select clause
  RelAttr attributes[MAX_NUM];    // attrs in Select clause
  // normal column attrs are in attributes.
  // complex expressions are in attr_expr.
  size_t expr_num;                
  AstExpr attr_expr[MAX_NUM];
  size_t relation_num;            // Length of relations in Fro clause
  size_t aggfun_num;
  char *relations[MAX_NUM];       // relations in From clause
  size_t condition_num;           // Length of conditions in Where clause
  Condition conditions[MAX_NUM];  // conditions in Where clause
  AggFun aggFun[MAX_NUM];
  struct _Selects *sub_query[MAX_NUM];
  int sub_query_num;
  int need_Revere;
  int need_reverse_join;
  char * real_name[MAX_NUM];
  char * alias_name[MAX_NUM];
  size_t alias_num;
  size_t    order_num;
  OrderBy   order_by[MAX_NUM];
  size_t ha_num;
  Condition hav_con[MAX_NUM];
  int is_da;
  int group_num;
  RelAttr gruop_use[MAX_NUM];
} ;
typedef struct _Selects Selects;


// struct of insert
typedef struct {
  char *relation_name;    // Relation to insert into
  size_t value_num;       // Length of values
  Value values[MAX_DATA][MAX_NUM];  // values to insert
  size_t record_num;
  size_t record_length[MAX_DATA];
} Inserts;

// struct of delete
typedef struct {
  char *relation_name;            // Relation to delete from
  size_t condition_num;           // Length of conditions in Where clause
  Condition conditions[MAX_NUM];  // conditions in Where clause
} Deletes;

typedef struct {
  char *attribute_name; // Attribute to update
  Value value;          // update value
  Selects select;       // update select
} UpdateAttr;

// struct of update
typedef struct {
  char *relation_name;            // Relation to update
  UpdateAttr update_attrs[10];
  size_t attr_num;
  size_t condition_num;           // Length of conditions in Where clause
  Condition conditions[MAX_NUM];  // conditions in Where clause
} Updates;

typedef struct {
  char *name;     // Attribute name
  AttrType type;  // Type of attribute
  size_t length;  // Length of attribute
  int _nullable;
} AttrInfo;

// struct of craete_table
typedef struct {
  char *relation_name;           // Relation name
  size_t attribute_count;        // Length of attribute
  AttrInfo attributes[MAX_NUM];  // attributes
} CreateTable;

// struct of drop_table
typedef struct {
  char *relation_name;  // Relation name
} DropTable;

typedef struct {
  const char *relation_name;  // Index name
} ShowIndex;


// struct of create_index
typedef struct {
  int   unique;
  char *index_name;      // Index name
  char *relation_name;   // Relation name
  char *attribute_name[MAX_NUM];  // Attribute name
  size_t attribute_count;         // Attribute count
} CreateIndex;

// struct of  drop_index
typedef struct {
  const char *index_name;  // Index name
} DropIndex;

typedef struct {
  const char *relation_name;
} DescTable;

typedef struct {
  const char *relation_name;
  const char *file_name;
} LoadData;

union Queries {
  Selects selection;
  Inserts insertion;
  Deletes deletion;
  Updates update;
  CreateTable create_table;
  DropTable drop_table;
  CreateIndex create_index;
  DropIndex drop_index;
  DescTable desc_table;
  LoadData load_data;
  ShowIndex show_index;
  char *errors;
};

// 修改yacc中相关数字编码为宏定义
enum SqlCommandFlag {
  SCF_ERROR = 0,
  SCF_SELECT,
  SCF_INSERT,
  SCF_UPDATE,
  SCF_DELETE,
  SCF_CREATE_TABLE,
  SCF_DROP_TABLE,
  SCF_CREATE_INDEX,
  SCF_DROP_INDEX,
  SCF_SYNC,
  SCF_SHOW_TABLES,
  SCF_DESC_TABLE,
  SCF_BEGIN,
  SCF_COMMIT,
  SCF_CLOG_SYNC,
  SCF_ROLLBACK,
  SCF_LOAD_DATA,
  SCF_HELP,
  SCF_EXIT,
  SCF_SHOW_INDEXES,
  SCF_SELECT_WITH_FUN
};
// struct of flag and sql_struct
typedef struct Query {
  enum SqlCommandFlag flag;
  union Queries sstr;
} Query;

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

void relation_attr_init(RelAttr *relation_attr, const char *relation_name, const char *attribute_name);
void relation_attr_destroy(RelAttr *relation_attr);

// 因为value无法解析负数，所以从expr中获取负数value
void value_init_astexpr(AstExpr *expr, Value *value);
void value_init_integer(Value *value, int v);
void value_init_float(Value *value, float v);
void value_init_string(Value *value, const char *v);
 int value_init_date(Value *value, const char *v);
 void value_init_null(Value *value);
void value_destroy(Value *value);
 int  check_date(int y, int m, int d);
void condition_init(Condition *condition, CompOp comp, int left_is_attr, RelAttr *left_attr, Value *left_value,
    int right_is_attr, RelAttr *right_attr, Value *right_value);

void condition_init_from_expr(Condition *condition, CompOp comp, AstExpr *left, AstExpr *right);

void condition_destroy(Condition *condition);

void attr_info_init(AttrInfo *attr_info, const char *name, AttrType type, size_t length, int nullable);
void attr_info_destroy(AttrInfo *attr_info);

void Init_AggFun(AggFun * a, DescribeFun des, const char* arr_name);
void Init_AggFun1(AggFun * a, DescribeFun des, const char* arr_name,const char * alias_name);
void Init_AggFun_Rel(AggFun *a, DescribeFun des, const char* rel_name, const char* arr_name);

void selects_init(Selects *selects);
void selects_append_aggfun(Selects *selects, AggFun * a);
void selects_reverse_append_aggfun(Selects *selects, AggFun * a);
void selects_append_order(Selects *selects, RelAttr *rel_attr, int order);
void selects_append_alias(Selects *selects, const char *name,const char *alias_name);
void selects_append_alias2(Selects *selects, const char *name,const char *rname,const char *alias_name);
void selects_append_alias3(Selects *selects, AggFun * a,const char* alias);

void selects_append_attribute(Selects *selects, RelAttr *rel_attr);
void selects_reverse_append_attribute(Selects *selects, RelAttr *rel_attr);
void selects_append_relation(Selects *selects, const char *relation_name);
void selects_append_conditions(Selects *selects, Condition conditions[], size_t condition_num);
void selects_append_expr(Selects *selects, AstExpr *expr);
void selects_destroy(Selects *selects);

void inserts_init(Inserts *inserts, const char *relation_name, Value values[], size_t value_num,size_t single_record_length[], size_t record_num);
void inserts_destroy(Inserts *inserts);

void deletes_init_relation(Deletes *deletes, const char *relation_name);
void deletes_set_conditions(Deletes *deletes, Condition conditions[], size_t condition_num);
void deletes_destroy(Deletes *deletes);

void updates_selects_append_attribute(Updates *updates, RelAttr *rel_attr);
void updates_selects_append_aggfun(Updates *updates, AggFun * a);
void updates_selects_append_conditions(Updates *updates, Condition conditions[], size_t condition_num);
void updates_selects_append_relation(Updates *updates, const char *relation_name);
void updates_append_value(Updates *updates, Value *value);
void updates_append_attr(Updates *updates, const char *attr_name);
void updates_init(Updates *updates, const char *relation_name, Condition conditions[], size_t condition_num);
void updates_destroy(Updates *updates);

void create_table_append_attribute(CreateTable *create_table, AttrInfo *attr_info);
void create_table_init_name(CreateTable *create_table, const char *relation_name);
void create_table_destroy(CreateTable *create_table);

void drop_table_init(DropTable *drop_table, const char *relation_name);
void drop_table_destroy(DropTable *drop_table);

void create_index_init(CreateIndex *create_index, const char *index_name, const char *relation_name, int unique);
void create_index_append_attribute(CreateIndex *create_index, const char *attr_name);
void create_index_destroy(CreateIndex *create_index);

void drop_index_init(DropIndex *drop_index, const char *index_name);
void drop_index_destroy(DropIndex *drop_index);

void desc_table_init(DescTable *desc_table, const char *relation_name);
void desc_table_destroy(DescTable *desc_table);

void load_data_init(LoadData *load_data, const char *relation_name, const char *file_name);
void load_data_destroy(LoadData *load_data);

AstExpr *create_value_expr(Value *value);
AstExpr *create_attr_expr(RelAttr *attr, int need_append);
AstExpr *create_agg_expr(AggFun *agg, int need_append);
AstExpr *create_astexpr(AstExprType type, AstExpr *left, AstExpr *right);

void query_init(Query *query);
Query *query_create();  // create and init
void query_reset(Query *query);
void query_destroy(Query *query);  // reset and delete

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // __OBSERVER_SQL_PARSER_PARSE_DEFS_H__
