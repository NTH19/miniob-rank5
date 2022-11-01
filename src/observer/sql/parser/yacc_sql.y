
%{

#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ParserContext {
  Query * ssql;
  size_t select_length;
  size_t condition_length;
  size_t from_length;
  size_t record_length;
  size_t single_record_length[MAX_DATA];
  size_t value_length;
  Value values[MAX_NUM*MAX_DATA];
  size_t sub_con_start[MAX_NUM];
  Condition conditions[MAX_NUM];
  size_t depth;
  DescribeFun des[MAX_NUM];
  CompOp comp;
	char id[MAX_NUM];
	int order; 
} ParserContext;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = (ParserContext *)(yyget_extra(scanner));
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  context->condition_length = 0;
  context->from_length = 0;
  context->select_length = 0;
  context->ssql->sstr.selection.is_da=0;
  context->value_length = 0;
  context->ssql->sstr.selection.sub_query_num=0;
  context->ssql->sstr.insertion.value_num = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)

%}

%define api.pure full
%lex-param { yyscan_t scanner }
%parse-param { void *scanner }

//标识tokens
%token  SEMICOLON
        CREATE
        DROP
        TABLE
        TABLES
        INDEX
        SELECT
        DESC
		ASC
        SHOW
        SYNC
        INSERT
        DELETE
        UPDATE
        LBRACE
        RBRACE
        COMMA
        TRX_BEGIN
		COUNT_T
		MAX_T
		MIN_T
		AVG_T
		SUM_T
        TRX_COMMIT
		DABIAO
        TRX_ROLLBACK
        INT_T
        STRING_T
        FLOAT_T
		DATE_T
		TEXT_T
        HELP
        EXIT
        DOT //QUOTE
        INTO
        VALUES
        FROM
        WHERE
		AS
        AND
        SET

        ON
		INNER_T
		JOIN_T
        LOAD
        DATA
        INFILE
        EQ
        LT
        GT
        LE
        GE
        NE
		EXIST_T
		IN_T
		LIKE
		NOT
		IS
		NULLL
		NULLABLE
		UNIQUE
		ORDER
        BY

%union {
  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  char *dates;
  int number;
  float floats;
	char *position;
}

%token <number> NUMBER
%token <floats> FLOAT 
%token <dates> DATEE  
%token <string> ID
%token <string> PATH
%token <string> SSS
%token <string> STAR
%token <string> STRING_V
//非终结符

%type <number> type;
%type <condition1> condition;
%type <value1> value;
%type <number> number;

%%

commands:		//commands or sqls. parser starts here.
    /* empty */
    | commands command
    ;

command:
	  select  
	| insert
	| update
	| delete
	| create_table
	| drop_table
	| show_tables
	| show_indexes
	| desc_table
	| create_index	
	| drop_index
	| sync
	| begin
	| commit
	| rollback
	| load_data
	| help
	| exit
    ;

exit:			
    EXIT SEMICOLON {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    };

help:
    HELP SEMICOLON {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    };

sync:
    SYNC SEMICOLON {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
    ;

begin:
    TRX_BEGIN SEMICOLON {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
    ;

commit:
    TRX_COMMIT SEMICOLON {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
    ;

rollback:
    TRX_ROLLBACK SEMICOLON {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
    ;

drop_table:		/*drop table 语句的语法解析树*/
    DROP TABLE ID SEMICOLON {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, $3);
    };

show_tables:
    SHOW TABLES SEMICOLON {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
    ;

show_indexes:
    SHOW INDEX FROM ID SEMICOLON{
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, $4);
    }
    ;


desc_table:
    DESC ID SEMICOLON {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, $2);
    }
    ;

create_index:		/*create index 语句的语法解析树*/
    CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON 
		{
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, $3, $5, 0);
		}
	| CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON 
		{
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, $4, $6, 1);
		}
    ;

index_attr_list:
	/* empty */
	| COMMA index_attr index_attr_list { } 
	;

index_attr:
	ID 
		{
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, $1);
		}
	;
	
drop_index:			/*drop index 语句的语法解析树*/
    DROP INDEX ID  SEMICOLON 
		{
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, $3);
		}
    ;
create_table:		/*create table 语句的语法解析树*/
    CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON 
		{
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, $3);
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
    ;
attr_def_list:
    /* empty */
    | COMMA attr_def attr_def_list {    }
    ;
    
attr_def:
    ID_get type LBRACE number RBRACE 
		{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, $2, $4, 0);		
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
	| ID_get type LBRACE number RBRACE NOT NULLL
	{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, $2, $4, 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
	| ID_get type LBRACE number RBRACE NULLABLE
		{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, $2, $4, 1);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
    | ID_get type
		{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, $2, 4, 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
    | ID_get type NOT NULLL
		{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, $2, 4, 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
    | ID_get type NULLABLE
		{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, $2, 4, 1);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
    ;
number:
		NUMBER {$$ = $1;}
		;
type:
	INT_T { $$=INTS; }
	   | DATE_T { $$=DATES; }
	   | TEXT_T { $$=TEXTS; }
       | STRING_T { $$=CHARS; }
       | FLOAT_T { $$=FLOATS; }
       ;
ID_get:
	ID 
	{
		char *temp=$1; 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
	;

dummy:{
		CONTEXT->depth++;
		CONTEXT->sub_con_start[CONTEXT->depth]=CONTEXT->condition_length;
	}
	;
insert:				/*insert   语句的语法解析树*/
    INSERT INTO ID VALUES record record_list SEMICOLON 
	{
		CONTEXT->ssql->flag=SCF_INSERT;//"insert";
		CONTEXT->ssql->sstr.insertion.relation_name = $3;
		CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
		inserts_init(&CONTEXT->ssql->sstr.insertion, $3, CONTEXT->values, CONTEXT->value_length,CONTEXT->single_record_length,CONTEXT->record_length);

      	CONTEXT->value_length=0;
	  	CONTEXT->record_length=0;
    }
record_list:
	| COMMA record record_list	{

		}
	;

record:
	| LBRACE value value_list RBRACE
		{
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		};
value_list:
    | COMMA value value_list  { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
    ;
value:
    NUMBER{	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
    |FLOAT{
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
	|DATEE {
			$1 = substr($1,1,strlen($1)-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
    |SSS {
			$1 = substr($1,1,strlen($1)-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
	|NULLL {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		}
    ;
    
delete:		/*  delete 语句的语法解析树*/
    DELETE FROM ID where SEMICOLON 
		{
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, $3);
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
    ;
update:			/*  update 语句的语法解析树*/
    UPDATE ID SET update_attr update_attr_list where SEMICOLON
		{
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, $2, CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
    ;

update_attr_list:
	/* empty */
	| COMMA update_attr update_attr_list
	;

update_attr:
	ID EQ value
		{
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, $1);
			CONTEXT->value_length = 0;
		}
	| ID EQ LBRACE SELECT update_select_attr FROM ID where RBRACE
		{
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, $7);
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, $1);
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
	| ID EQ LBRACE SELECT update_agg FROM ID where RBRACE
		{
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, $7);
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, $1);
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
	;

update_select_attr:
    STAR {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
    | ID {
			RelAttr attr;
			relation_attr_init(&attr, NULL, $1);
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
  	| ID DOT ID {
			RelAttr attr;
			relation_attr_init(&attr, $1, $3);
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
	| ID DOT STAR {
			RelAttr attr;
			relation_attr_init(&attr, $1, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
    ;

update_agg:
	 COUNT_T LBRACE STAR RBRACE {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
	| COUNT_T LBRACE ID RBRACE {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, $3);
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
	| COUNT_T LBRACE ID DOT ID RBRACE {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, $3, $5);
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
	| MAX_T LBRACE ID RBRACE {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, $3);
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
	| MAX_T LBRACE ID DOT ID RBRACE {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, $3, $5);
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
	| MIN_T LBRACE ID RBRACE {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, $3);
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
	| MIN_T LBRACE ID DOT ID RBRACE {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, $3, $5);
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
	| SUM_T LBRACE ID RBRACE {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, $3);
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
	| SUM_T LBRACE ID DOT ID RBRACE {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, $3, $5);
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
	| AVG_T LBRACE ID RBRACE {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, $3);
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
	| AVG_T LBRACE ID DOT ID RBRACE {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, $3, $5);
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
	;


select:
	DABIAO{

		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		
  		CONTEXT->condition_length = 0;
  		CONTEXT->from_length = 0;
  		CONTEXT->select_length = 0;
  		CONTEXT->value_length = 0;
  		CONTEXT->ssql->sstr.selection.is_da=1;
  		CONTEXT->ssql->sstr.selection.sub_query_num=0;
	}
	/*  select 语句的语法解析树*/
    |SELECT select_attr FROM ID rel_list where order_by SEMICOLON{
			selects_append_relation(&CONTEXT->ssql->sstr.selection, $4);

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;//"select";

			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
	| SELECT agg_fun_list_head FROM ID where SEMICOLON{
		selects_append_relation(&CONTEXT->ssql->sstr.selection, $4);
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;

		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	|SELECT select_attr FROM ID INNER_T JOIN_T ID ON join_cons join_list where SEMICOLON{
			selects_append_relation(&CONTEXT->ssql->sstr.selection, $7);
			selects_append_relation(&CONTEXT->ssql->sstr.selection, $4);
			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->ssql->flag=SCF_SELECT;//"select";

			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
	| SELECT select_attr FROM ID AS ID rel_list where SEMICOLON{
		selects_append_relation(&CONTEXT->ssql->sstr.selection, $4);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $4,$6);
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		
	}
	| SELECT agg_fun_list_head FROM ID AS ID  where SEMICOLON {
	selects_append_relation(&CONTEXT->ssql->sstr.selection, $4);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $4,$6);
	selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;
		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	| SELECT select_attr FROM ID  ID rel_list where SEMICOLON{
		selects_append_relation(&CONTEXT->ssql->sstr.selection, $4);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $4,$5);
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		
	}
	| SELECT agg_fun_list_head FROM ID  ID  where SEMICOLON {
	selects_append_relation(&CONTEXT->ssql->sstr.selection, $4);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $4,$5);
	selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;
		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	;
order_by:

	| ORDER BY order_item order_item_list
	;

order_item: 
	ID order {
		RelAttr attr;
		relation_attr_init(&attr, NULL, $1);
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, CONTEXT->order);
	}
	| ID DOT ID order {
		RelAttr attr;
		relation_attr_init(&attr, $1, $3);
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, CONTEXT->order);
	}
	;

order:
	/* empty */ {
		CONTEXT->order = 0;
	}
	| ASC {
		CONTEXT->order = 0;
	}
	| DESC {
		CONTEXT->order = 1;
	}
	;

order_item_list:
	/* empty */
	| COMMA order_item order_item_list
	;
sub_query:
	SELECT ID DOT ID FROM ID rel_list dummy where {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $6);
		RelAttr attr;
		relation_attr_init(&attr, $2, $4);
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	}
	|SELECT ID FROM ID rel_list dummy where {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $4);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		RelAttr attr;
		relation_attr_init(&attr, NULL, $2);
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	}
	|SELECT COUNT_T LBRACE STAR RBRACE FROM ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $7);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	}
	|SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, $4, $6);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	}
	|SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, $4, $6);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	}
	|SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, $4, $6);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	  }
	|SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, $4, $6);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	  }
	|SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, $4, $6);
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	  }
	| SELECT ID DOT ID FROM ID AS ID  rel_list dummy where {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $6);
		RelAttr attr;
		relation_attr_init(&attr, $2, $4);
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $6,$8);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	|SELECT ID FROM ID AS ID rel_list dummy where {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $4);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		RelAttr attr;
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $4,$6);
		relation_attr_init(&attr, NULL, $2);
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	|SELECT COUNT_T LBRACE STAR RBRACE FROM ID AS ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $7);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $7,$9);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	|SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $9,$11);
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, $4, $6);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	|SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, $4, $6);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $9,$11);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	|SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, $4, $6);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $9,$11);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
	|SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, $4, $6);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $9,$11);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
	|SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, $4, $6);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $9,$11);
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
	  | SELECT ID DOT ID FROM ID  ID  rel_list dummy where {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $6);
		RelAttr attr;
		relation_attr_init(&attr, $2, $4);
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

	selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $6,$7);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	|SELECT ID FROM ID  ID rel_list dummy where {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $4);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		RelAttr attr;
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $4,$5);
		relation_attr_init(&attr, NULL, $2);
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	|SELECT COUNT_T LBRACE STAR RBRACE FROM ID  ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $7);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $7,$8);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	|SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID  ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $9,$10);
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, $4, $6);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
	
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	|SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID  ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, $4, $6);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $9,$10);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
	|SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, $4, $6);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $9,$10);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
	|SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, $4, $6);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $9,$10);
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
	
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
	|SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where{
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], $9);
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, $4, $6);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $9,$10);
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
	;
	;
join_list:
	 /* empty */
    | INNER_T JOIN_T ID ON join_cons join_list {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, $3);
	}
    ;
join_cons:
	 condition condition_list {	
	}
    ;

agg_fun_list_head:
	 COUNT_T LBRACE STAR RBRACE agg_fun_list{
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
	|COUNT_T LBRACE ID RBRACE agg_fun_list{
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,$3);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
	| MAX_T LBRACE ID RBRACE agg_fun_list{
		AggFun aggre;
		Init_AggFun(&aggre, MAX, $3);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| MIN_T LBRACE ID RBRACE agg_fun_list{
		AggFun aggre;
		Init_AggFun(&aggre, MIN, $3);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| SUM_T LBRACE ID RBRACE agg_fun_list{
		AggFun aggre;
		Init_AggFun(&aggre, SUM, $3);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| AVG_T LBRACE ID RBRACE agg_fun_list{
		AggFun aggre;
		Init_AggFun(&aggre, AVG, $3);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| COUNT_T LBRACE STAR RBRACE AS ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",$6);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
	|COUNT_T LBRACE ID RBRACE AS ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,$3,$6);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
	| MAX_T LBRACE ID RBRACE AS ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, $3,$6);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
	| MIN_T LBRACE ID RBRACE AS ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, $3,$6);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
	| SUM_T LBRACE ID RBRACE AS ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, $3,$6);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
	
		CONTEXT->select_length++;
	  }
	| AVG_T LBRACE ID RBRACE AS ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, $3,$6);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		
		CONTEXT->select_length++;
	  }
	| COUNT_T LBRACE STAR RBRACE  ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",$5);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
	|COUNT_T LBRACE ID RBRACE  ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,$3,$5);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
	| MAX_T LBRACE ID RBRACE  ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, $3,$5);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
	| MIN_T LBRACE ID RBRACE  ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, $3,$5);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
	| SUM_T LBRACE ID RBRACE  ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, $3,$5);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
	
		CONTEXT->select_length++;
	  }
	| AVG_T LBRACE ID RBRACE  ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, $3,$5);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		
		CONTEXT->select_length++;
	  }
	;
agg_fun_list:
	
  	|COMMA COUNT_T LBRACE STAR RBRACE agg_fun_list{
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
	|COMMA COUNT_T LBRACE ID RBRACE agg_fun_list{
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,$4);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
	|COMMA MAX_T LBRACE ID RBRACE agg_fun_list{
		AggFun aggre;
		Init_AggFun(&aggre, MAX, $4);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	|COMMA MIN_T LBRACE ID RBRACE agg_fun_list{
		AggFun aggre;
		Init_AggFun(&aggre,MIN, $4);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| COMMA SUM_T LBRACE ID RBRACE agg_fun_list{
		AggFun aggre;
		Init_AggFun(&aggre,SUM, $4);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| COMMA AVG_T LBRACE ID RBRACE agg_fun_list{
		AggFun aggre;
		Init_AggFun(&aggre,AVG, $4);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| COMMA COUNT_T LBRACE STAR RBRACE AS ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",$7);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
	|COMMA COUNT_T LBRACE ID RBRACE AS ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,$4,$7);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
	| COMMA MAX_T LBRACE ID RBRACE AS ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, $4,$7);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| COMMA MIN_T LBRACE ID RBRACE AS ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, $4,$7);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| COMMA SUM_T LBRACE ID RBRACE AS ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, $4,$7);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| COMMA AVG_T LBRACE ID RBRACE AS ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, $4,$7);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| COMMA COUNT_T LBRACE STAR RBRACE  ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",$6);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
	|COMMA COUNT_T LBRACE ID RBRACE  ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,$4,$6);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
	| COMMA MAX_T LBRACE ID RBRACE  ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, $4,$6);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| COMMA MIN_T LBRACE ID RBRACE  ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, $4,$6);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| COMMA SUM_T LBRACE ID RBRACE  ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, $4,$6);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	| COMMA AVG_T LBRACE ID RBRACE  ID agg_fun_list{
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, $4,$6);
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
	;


select_attr:
    STAR attr_list {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			CONTEXT->ssql->sstr.selection.need_Revere=1;
		}
    | ID attr_list {
			RelAttr attr;
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			relation_attr_init(&attr, NULL, $1);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
  	| ID DOT ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $1, $3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
	| ID DOT STAR attr_list{
		RelAttr attr;
		relation_attr_init(&attr, $1, "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
	| ID AS ID attr_list{
		RelAttr attr;
		relation_attr_init(&attr, NULL, $1);
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $1,$3);
	}
	| ID DOT ID AS ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $1, $3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, $1,$3,$5);
		}
    ;
attr_list:
    /* empty */
    | COMMA ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, NULL, $2);
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
    | COMMA ID DOT ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $2, $4);
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
	| COMMA ID DOT STAR attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $2, "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
	| COMMA ID AS ID attr_list{
		RelAttr attr;
		relation_attr_init(&attr, NULL, $2);
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $2,$4);
	}
	| COMMA ID DOT ID AS ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $2, $4);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, $2,$4,$6);
		}
  	;

rel_list:
    /* empty */
    | COMMA ID rel_list {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, $2);
		  }
	| COMMA ID AS ID rel_list{
		selects_append_relation(&CONTEXT->ssql->sstr.selection, $2);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $2,$4);
	}
	| COMMA ID ID rel_list{
		selects_append_relation(&CONTEXT->ssql->sstr.selection, $2);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, $2,$3);
	}
    ;
where:
    /* empty */ 
    | WHERE condition condition_list {
	}
    ;
condition_list:
    /* empty */
    | AND condition condition_list {
			}
    ;
condition:
    ID comOp value 
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, $1);

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
		|value comOp value 
		{
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
		|ID comOp ID 
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, $1);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, $3);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;

		}
    |value comOp ID
		{
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, $3);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp=CONTEXT->comp;
			
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;
		
		}
    |ID DOT ID comOp value
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, $1, $3);
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp=CONTEXT->comp;
			// $$->right_is_attr = 0;   //属性值
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=NULL;
			// $$->right_value =*$5;			
							
    }
    |value comOp ID DOT ID
		{
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
		RelAttr right_attr;
		relation_attr_init(&right_attr, $3, $5);
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
    |ID DOT ID comOp ID DOT ID
	{
			
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);
		RelAttr right_attr;
		relation_attr_init(&right_attr, $5, $7);
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|EXIST_T LBRACE sub_query RBRACE
	{
		Condition condition;
		condition_init_with_query(&condition, EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|NOT EXIST_T LBRACE sub_query RBRACE
	{
		Condition condition;
		condition_init_with_query(&condition, NOT_EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|LBRACE sub_query RBRACE reverseComp ID{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $5);
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->comp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
	|ID IN_T LBRACE in_cells RBRACE{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
	|ID NOT IN_T LBRACE in_cells RBRACE{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
	|ID DOT ID NOT IN_T LBRACE in_cells RBRACE{
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
	|ID IN_T LBRACE sub_query RBRACE{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);
		Condition condition;
		condition_init_with_query(&condition, IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
	|ID DOT ID IN_T LBRACE sub_query RBRACE{
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);
		Condition condition;
		condition_init_with_query(&condition, IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
	|ID NOT IN_T LBRACE sub_query RBRACE{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
	|ID DOT ID NOT IN_T LBRACE sub_query RBRACE{
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
	|ID  EQ LBRACE sub_query RBRACE
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);
		Condition condition;
		condition_init_with_query(&condition, EQUAL_TO, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|ID  LT LBRACE sub_query RBRACE
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);
		Condition condition;
		condition_init_with_query(&condition, LESS_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|ID  GT LBRACE sub_query RBRACE
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);
		Condition condition;
		condition_init_with_query(&condition, GREAT_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|ID  LE LBRACE sub_query RBRACE
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);
		Condition condition;
		condition_init_with_query(&condition,LESS_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|ID  GE LBRACE sub_query RBRACE
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);
		Condition condition;
		condition_init_with_query(&condition, GREAT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|ID  NE LBRACE sub_query RBRACE
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);
		Condition condition;
		condition_init_with_query(&condition, NOT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|ID DOT ID EQ LBRACE sub_query RBRACE
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);
		Condition condition;
		condition_init_with_query(&condition, EQUAL_TO, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|ID  DOT ID LT LBRACE sub_query RBRACE
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);
		Condition condition;
		condition_init_with_query(&condition, LESS_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|ID  DOT ID GT LBRACE sub_query RBRACE
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);
		Condition condition;
		condition_init_with_query(&condition, GREAT_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|ID  DOT ID LE LBRACE sub_query RBRACE
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);
		Condition condition;
		condition_init_with_query(&condition,LESS_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|ID  DOT ID GE LBRACE sub_query RBRACE
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);
		Condition condition;
		condition_init_with_query(&condition, GREAT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|ID  DOT ID NE LBRACE sub_query RBRACE
	{
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);
		Condition condition;
		condition_init_with_query(&condition, NOT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
	|LBRACE sub_query RBRACE NE LBRACE sub_query RBRACE {
		Condition condition;
		condition_init_with_two_query(&condition, NOT_EQUAL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1],CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-2]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
    ;
in_cells:
	 value value_list {
	};

reverseComp:
	  EQ { CONTEXT->comp = EQUAL_TO; }
    | LT { CONTEXT->comp = GREAT_THAN; }
    | GT { CONTEXT->comp = LESS_THAN; }
    | LE { CONTEXT->comp = GREAT_EQUAL; }
    | GE { CONTEXT->comp = LESS_EQUAL; }
    | NE { CONTEXT->comp = NOT_EQUAL; }
    ;
comOp:
  	  EQ { CONTEXT->comp = EQUAL_TO;}
    | LT { CONTEXT->comp = LESS_THAN; }
    | GT { CONTEXT->comp = GREAT_THAN; }
    | LE { CONTEXT->comp = LESS_EQUAL; }
    | GE { CONTEXT->comp = GREAT_EQUAL; }
    | NE { CONTEXT->comp = NOT_EQUAL; }
	| LIKE { CONTEXT->comp = LIKE_TO; }
	| IN_T {CONTEXT->comp = IN;}
	| NOT IN_T {CONTEXT->comp = NOT_IN;}
	| NOT EXIST_T{CONTEXT->comp = NOT_EXIST;}
	| EXIST_T{CONTEXT->comp = EXIST;}
	| NOT LIKE { CONTEXT->comp = NOT_LIKE; }
	| IS NOT { CONTEXT->comp = COMP_IS_NOT; }
	| IS { CONTEXT->comp = COMP_IS; }
    ;

load_data:
		LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON
		{
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, $7, $4);
		}
		;
%%
//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context;
	memset(&context, 0, sizeof(context));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
