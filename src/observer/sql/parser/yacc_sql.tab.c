/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


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
  size_t sub_cons_num;
  size_t record_length;
  size_t single_record_length[MAX_DATA];
  size_t value_length;
  CompOp tempOp;
  size_t sub_use_comp;
  Value values[MAX_NUM*MAX_DATA];
  Condition conditions[MAX_NUM];
  Condition sub_cons[MAX_NUM];
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
  context->sub_cons_num=0;
  context->from_length = 0;
  context->select_length = 0;
  context->value_length = 0;
  context->tempOp=COMP_IS_NOT;
  context->ssql->sstr.selection.dabiao=0;
  context->ssql->sstr.selection.sub_query_num=0;
  context->ssql->sstr.insertion.value_num = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)


#line 140 "yacc_sql.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_TABLES = 7,                     /* TABLES  */
  YYSYMBOL_INDEX = 8,                      /* INDEX  */
  YYSYMBOL_SELECT = 9,                     /* SELECT  */
  YYSYMBOL_DESC = 10,                      /* DESC  */
  YYSYMBOL_ASC = 11,                       /* ASC  */
  YYSYMBOL_SHOW = 12,                      /* SHOW  */
  YYSYMBOL_SYNC = 13,                      /* SYNC  */
  YYSYMBOL_INSERT = 14,                    /* INSERT  */
  YYSYMBOL_DELETE = 15,                    /* DELETE  */
  YYSYMBOL_UPDATE = 16,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 18,                    /* RBRACE  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 20,                 /* TRX_BEGIN  */
  YYSYMBOL_COUNT_T = 21,                   /* COUNT_T  */
  YYSYMBOL_MAX_T = 22,                     /* MAX_T  */
  YYSYMBOL_MIN_T = 23,                     /* MIN_T  */
  YYSYMBOL_AVG_T = 24,                     /* AVG_T  */
  YYSYMBOL_SUM_T = 25,                     /* SUM_T  */
  YYSYMBOL_TRX_COMMIT = 26,                /* TRX_COMMIT  */
  YYSYMBOL_DABIAO = 27,                    /* DABIAO  */
  YYSYMBOL_TRX_ROLLBACK = 28,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 29,                     /* INT_T  */
  YYSYMBOL_STRING_T = 30,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 31,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 32,                    /* DATE_T  */
  YYSYMBOL_TEXT_T = 33,                    /* TEXT_T  */
  YYSYMBOL_HELP = 34,                      /* HELP  */
  YYSYMBOL_EXIT = 35,                      /* EXIT  */
  YYSYMBOL_DOT = 36,                       /* DOT  */
  YYSYMBOL_INTO = 37,                      /* INTO  */
  YYSYMBOL_VALUES = 38,                    /* VALUES  */
  YYSYMBOL_FROM = 39,                      /* FROM  */
  YYSYMBOL_WHERE = 40,                     /* WHERE  */
  YYSYMBOL_AS = 41,                        /* AS  */
  YYSYMBOL_AND = 42,                       /* AND  */
  YYSYMBOL_SET = 43,                       /* SET  */
  YYSYMBOL_ON = 44,                        /* ON  */
  YYSYMBOL_INNER_T = 45,                   /* INNER_T  */
  YYSYMBOL_JOIN_T = 46,                    /* JOIN_T  */
  YYSYMBOL_LOAD = 47,                      /* LOAD  */
  YYSYMBOL_DATA = 48,                      /* DATA  */
  YYSYMBOL_INFILE = 49,                    /* INFILE  */
  YYSYMBOL_EQ = 50,                        /* EQ  */
  YYSYMBOL_LT = 51,                        /* LT  */
  YYSYMBOL_GT = 52,                        /* GT  */
  YYSYMBOL_LE = 53,                        /* LE  */
  YYSYMBOL_GE = 54,                        /* GE  */
  YYSYMBOL_NE = 55,                        /* NE  */
  YYSYMBOL_EXIST_T = 56,                   /* EXIST_T  */
  YYSYMBOL_IN_T = 57,                      /* IN_T  */
  YYSYMBOL_LIKE = 58,                      /* LIKE  */
  YYSYMBOL_NOT = 59,                       /* NOT  */
  YYSYMBOL_IS = 60,                        /* IS  */
  YYSYMBOL_NULLL = 61,                     /* NULLL  */
  YYSYMBOL_NULLABLE = 62,                  /* NULLABLE  */
  YYSYMBOL_UNIQUE = 63,                    /* UNIQUE  */
  YYSYMBOL_ORDER = 64,                     /* ORDER  */
  YYSYMBOL_BY = 65,                        /* BY  */
  YYSYMBOL_NUMBER = 66,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 67,                     /* FLOAT  */
  YYSYMBOL_DATEE = 68,                     /* DATEE  */
  YYSYMBOL_ID = 69,                        /* ID  */
  YYSYMBOL_PATH = 70,                      /* PATH  */
  YYSYMBOL_SSS = 71,                       /* SSS  */
  YYSYMBOL_STAR = 72,                      /* STAR  */
  YYSYMBOL_STRING_V = 73,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 74,                  /* $accept  */
  YYSYMBOL_commands = 75,                  /* commands  */
  YYSYMBOL_command = 76,                   /* command  */
  YYSYMBOL_exit = 77,                      /* exit  */
  YYSYMBOL_help = 78,                      /* help  */
  YYSYMBOL_sync = 79,                      /* sync  */
  YYSYMBOL_begin = 80,                     /* begin  */
  YYSYMBOL_commit = 81,                    /* commit  */
  YYSYMBOL_rollback = 82,                  /* rollback  */
  YYSYMBOL_drop_table = 83,                /* drop_table  */
  YYSYMBOL_show_tables = 84,               /* show_tables  */
  YYSYMBOL_show_indexes = 85,              /* show_indexes  */
  YYSYMBOL_desc_table = 86,                /* desc_table  */
  YYSYMBOL_create_index = 87,              /* create_index  */
  YYSYMBOL_index_attr_list = 88,           /* index_attr_list  */
  YYSYMBOL_index_attr = 89,                /* index_attr  */
  YYSYMBOL_drop_index = 90,                /* drop_index  */
  YYSYMBOL_create_table = 91,              /* create_table  */
  YYSYMBOL_attr_def_list = 92,             /* attr_def_list  */
  YYSYMBOL_attr_def = 93,                  /* attr_def  */
  YYSYMBOL_number = 94,                    /* number  */
  YYSYMBOL_type = 95,                      /* type  */
  YYSYMBOL_ID_get = 96,                    /* ID_get  */
  YYSYMBOL_insert = 97,                    /* insert  */
  YYSYMBOL_record_list = 98,               /* record_list  */
  YYSYMBOL_record = 99,                    /* record  */
  YYSYMBOL_value_list = 100,               /* value_list  */
  YYSYMBOL_value = 101,                    /* value  */
  YYSYMBOL_delete = 102,                   /* delete  */
  YYSYMBOL_update = 103,                   /* update  */
  YYSYMBOL_update_attr_list = 104,         /* update_attr_list  */
  YYSYMBOL_update_attr = 105,              /* update_attr  */
  YYSYMBOL_update_select_attr = 106,       /* update_select_attr  */
  YYSYMBOL_update_agg = 107,               /* update_agg  */
  YYSYMBOL_select = 108,                   /* select  */
  YYSYMBOL_order_by = 109,                 /* order_by  */
  YYSYMBOL_order_item = 110,               /* order_item  */
  YYSYMBOL_order = 111,                    /* order  */
  YYSYMBOL_order_item_list = 112,          /* order_item_list  */
  YYSYMBOL_sub_where = 113,                /* sub_where  */
  YYSYMBOL_sub_condition_list = 114,       /* sub_condition_list  */
  YYSYMBOL_sub_condition = 115,            /* sub_condition  */
  YYSYMBOL_sub_query = 116,                /* sub_query  */
  YYSYMBOL_join_list = 117,                /* join_list  */
  YYSYMBOL_join_cons = 118,                /* join_cons  */
  YYSYMBOL_agg_fun_list_head = 119,        /* agg_fun_list_head  */
  YYSYMBOL_agg_fun_list = 120,             /* agg_fun_list  */
  YYSYMBOL_select_attr = 121,              /* select_attr  */
  YYSYMBOL_attr_list = 122,                /* attr_list  */
  YYSYMBOL_rel_list = 123,                 /* rel_list  */
  YYSYMBOL_where = 124,                    /* where  */
  YYSYMBOL_condition_list = 125,           /* condition_list  */
  YYSYMBOL_condition = 126,                /* condition  */
  YYSYMBOL_in_cells = 127,                 /* in_cells  */
  YYSYMBOL_exist_con = 128,                /* exist_con  */
  YYSYMBOL_in_not_com = 129,               /* in_not_com  */
  YYSYMBOL_sub_com = 130,                  /* sub_com  */
  YYSYMBOL_reverseComp = 131,              /* reverseComp  */
  YYSYMBOL_comOp = 132,                    /* comOp  */
  YYSYMBOL_load_data = 133                 /* load_data  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   694

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  242
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  624

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   328


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   168,   168,   170,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   195,   200,   205,   211,   217,   223,   229,   235,
     241,   249,   256,   261,   268,   270,   274,   281,   288,   297,
     299,   303,   314,   325,   336,   347,   358,   371,   374,   375,
     376,   377,   378,   381,   390,   406,   407,   412,   413,   418,
     419,   424,   427,   430,   434,   438,   444,   454,   462,   464,
     468,   474,   482,   493,   498,   503,   508,   516,   521,   526,
     531,   536,   541,   546,   551,   556,   561,   566,   574,   589,
     599,   610,   621,   631,   642,   653,   655,   659,   664,   672,
     675,   678,   683,   685,   687,   689,   692,   694,   698,   710,
     720,   740,   762,   783,   793,   807,   828,   846,   864,   882,
     900,   918,   936,   957,   979,   998,  1017,  1036,  1055,  1074,
    1093,  1115,  1137,  1156,  1175,  1194,  1213,  1232,  1251,  1275,
    1277,  1282,  1287,  1292,  1297,  1303,  1309,  1315,  1321,  1327,
    1333,  1340,  1347,  1354,  1361,  1367,  1373,  1380,  1387,  1394,
    1402,  1404,  1409,  1414,  1420,  1426,  1432,  1438,  1444,  1450,
    1456,  1462,  1468,  1474,  1480,  1486,  1492,  1498,  1504,  1514,
    1520,  1526,  1531,  1536,  1542,  1549,  1551,  1557,  1563,  1569,
    1576,  1584,  1586,  1589,  1593,  1598,  1600,  1603,  1605,  1609,
    1621,  1631,  1651,  1673,  1694,  1704,  1715,  1723,  1729,  1736,
    1744,  1754,  1757,  1758,  1761,  1762,  1765,  1766,  1767,  1768,
    1769,  1770,  1773,  1774,  1775,  1776,  1777,  1778,  1781,  1782,
    1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,
    1793,  1794,  1798
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "INDEX", "SELECT", "DESC", "ASC", "SHOW",
  "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA",
  "TRX_BEGIN", "COUNT_T", "MAX_T", "MIN_T", "AVG_T", "SUM_T", "TRX_COMMIT",
  "DABIAO", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "TEXT_T", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AS",
  "AND", "SET", "ON", "INNER_T", "JOIN_T", "LOAD", "DATA", "INFILE", "EQ",
  "LT", "GT", "LE", "GE", "NE", "EXIST_T", "IN_T", "LIKE", "NOT", "IS",
  "NULLL", "NULLABLE", "UNIQUE", "ORDER", "BY", "NUMBER", "FLOAT", "DATEE",
  "ID", "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands",
  "command", "exit", "help", "sync", "begin", "commit", "rollback",
  "drop_table", "show_tables", "show_indexes", "desc_table",
  "create_index", "index_attr_list", "index_attr", "drop_index",
  "create_table", "attr_def_list", "attr_def", "number", "type", "ID_get",
  "insert", "record_list", "record", "value_list", "value", "delete",
  "update", "update_attr_list", "update_attr", "update_select_attr",
  "update_agg", "select", "order_by", "order_item", "order",
  "order_item_list", "sub_where", "sub_condition_list", "sub_condition",
  "sub_query", "join_list", "join_cons", "agg_fun_list_head",
  "agg_fun_list", "select_attr", "attr_list", "rel_list", "where",
  "condition_list", "condition", "in_cells", "exist_con", "in_not_com",
  "sub_com", "reverseComp", "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-392)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-222)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -392,   257,  -392,     3,   234,     4,   -59,   299,    32,     2,
      40,    60,    93,   110,   138,   149,   157,   114,  -392,  -392,
    -392,  -392,  -392,  -392,  -392,  -392,  -392,  -392,  -392,  -392,
    -392,  -392,  -392,  -392,  -392,  -392,  -392,   100,   116,   171,
     122,   126,   182,   189,   193,   197,   201,   109,   204,   219,
     229,   251,   277,   308,  -392,   213,   279,   306,  -392,  -392,
    -392,  -392,  -392,   307,   338,   314,   290,   358,   359,   -29,
     295,   298,   305,   309,   318,   -28,   319,  -392,  -392,   320,
     327,  -392,  -392,   328,   330,   337,   329,   332,   336,   340,
     355,  -392,  -392,   383,   393,   398,   400,   404,   407,   224,
      -5,   204,   204,   -18,   102,   423,   410,    -9,   432,   386,
     418,   408,  -392,   425,   440,   429,   384,     5,    13,    14,
      73,    89,   127,    37,   385,  -392,   391,  -392,  -392,  -392,
     405,   337,   452,   406,   409,   430,   458,   337,  -392,   390,
     460,   450,  -392,   424,  -392,  -392,  -392,  -392,   243,  -392,
     285,   439,   465,  -392,    44,   329,   337,   477,   336,   466,
    -392,  -392,  -392,  -392,  -392,    36,   416,   469,   265,   419,
     468,  -392,   420,   468,  -392,   421,   468,  -392,   422,   468,
    -392,   426,   468,  -392,   427,   468,  -392,    -3,   204,   204,
     204,   337,   489,  -392,   147,   458,   428,   337,   434,   474,
     410,   491,   207,   481,  -392,   431,   484,   485,   486,   487,
     488,   490,  -392,   492,  -392,   191,   447,   493,   494,   304,
    -392,  -392,  -392,  -392,  -392,  -392,  -392,   256,   315,    -9,
    -392,   450,   499,  -392,   418,   509,   444,   425,   511,   449,
     455,  -392,  -392,   498,   416,   501,   502,   503,   504,   505,
     468,  -392,   468,  -392,   468,  -392,   468,  -392,   468,  -392,
     468,  -392,   454,  -392,  -392,  -392,  -392,   521,  -392,   456,
     458,  -392,   337,   482,   524,   463,   526,   390,   512,   460,
    -392,   514,   515,   516,   517,   518,   154,   413,   285,  -392,
     519,  -392,  -392,    33,   450,  -392,  -392,  -392,   506,  -392,
     439,   520,    95,  -392,  -392,   534,  -392,  -392,  -392,   522,
    -392,   416,   523,   498,   169,   470,   475,   476,   478,  -392,
    -392,  -392,  -392,  -392,  -392,   204,  -392,   458,  -392,   540,
      -9,  -392,   479,  -392,   474,  -392,  -392,   187,   480,   483,
     495,   496,   497,   500,  -392,  -392,  -392,  -392,  -392,  -392,
     507,   324,   474,   528,   532,   533,   508,  -392,  -392,   536,
     537,   538,   539,   541,   525,  -392,   529,   531,  -392,   216,
     498,   554,   542,   544,   545,   549,   553,   555,   556,  -392,
    -392,  -392,   527,   439,   112,   559,  -392,   543,   557,   546,
     547,   548,   550,   551,   151,  -392,   552,  -392,  -392,  -392,
    -392,  -392,  -392,   212,   530,   535,   558,   560,   236,   561,
     562,   563,  -392,  -392,  -392,   577,   167,   168,   170,   181,
     183,   184,   513,   337,  -392,  -392,  -392,   564,  -392,   479,
    -392,   565,   566,   567,   568,   569,   570,   571,   572,   458,
     573,   574,    -6,   575,    27,   108,   208,   215,  -392,  -392,
     337,   337,  -392,  -392,   576,   468,  -392,   578,   468,  -392,
     579,   468,  -392,   580,   468,  -392,   581,   468,  -392,   582,
     468,  -392,   583,   584,   311,   559,   585,   586,   588,   589,
     590,   591,   186,   458,   573,   346,  -392,  -392,  -392,   587,
    -392,  -392,   592,  -392,   593,  -392,   594,  -392,   595,   596,
     597,   468,  -392,   468,  -392,   468,  -392,   468,  -392,   468,
    -392,   468,  -392,   598,  -392,  -392,  -392,   605,     8,   607,
     614,   615,   618,   599,   458,   573,   573,  -392,   274,   285,
     616,   600,   601,   602,   603,   604,  -392,  -392,  -392,  -392,
    -392,  -392,  -392,  -392,    -9,   606,   608,   573,  -392,   609,
     610,   611,   612,   458,   573,  -392,  -392,   613,   363,   372,
     346,  -392,  -392,  -392,  -392,  -392,  -392,   527,    62,   573,
    -392,    92,    96,   194,   205,   573,  -392,   285,  -392,  -392,
     623,  -392,   616,  -392,   617,   573,  -392,  -392,   619,   573,
    -392,   620,   573,  -392,   621,   573,  -392,   622,   573,  -392,
    -392,   381,   624,  -392,   573,  -392,   573,  -392,   573,  -392,
     573,  -392,   573,  -392,   629,  -392,  -392,  -392,  -392,  -392,
    -392,  -392,   625,  -392
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    21,
      20,    15,    16,    17,    18,     9,    10,    11,    12,    13,
      14,     8,     5,     7,     6,     4,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,   185,     0,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,    23,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   179,     0,
       0,    31,    29,     0,     0,   195,     0,     0,     0,     0,
       0,    28,    37,     0,     0,     0,     0,     0,     0,   185,
     185,   185,   185,   195,   191,     0,    57,     0,     0,     0,
      68,     0,    53,    39,     0,     0,     0,   160,   160,   160,
     160,   160,   160,     0,     0,   186,     0,   181,   182,   183,
       0,   195,     0,     0,     0,     0,   191,   195,    30,     0,
      55,     0,   213,     0,    65,    61,    62,    63,     0,    64,
       0,   197,     0,    66,     0,     0,   195,     0,     0,     0,
      48,    51,    52,    49,    50,    44,     0,     0,     0,     0,
     160,   143,     0,   160,   142,     0,   160,   144,     0,   160,
     145,     0,   160,   147,     0,   160,   146,   185,   185,   185,
     185,   195,     0,    89,   191,   191,     0,   195,    95,    59,
      57,     0,     0,     0,   212,     0,   228,   229,   230,   231,
     232,   233,   238,   235,   234,     0,   241,     0,     0,     0,
     228,   229,   230,   231,   232,   233,   235,     0,     0,     0,
     196,     0,     0,    70,    68,     0,     0,    39,     0,     0,
       0,    46,    36,    34,     0,     0,     0,     0,     0,     0,
     160,   155,   160,   154,   160,   156,   160,   157,   160,   159,
     160,   158,     0,   187,   188,   189,   184,     0,    94,     0,
     191,   192,   195,     0,     0,     0,     0,     0,     0,    55,
      54,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     236,   239,   240,     0,     0,   201,   199,   236,   202,   200,
     197,     0,     0,    69,    67,     0,    40,    38,    47,     0,
      45,     0,     0,    34,     0,     0,     0,     0,     0,   149,
     148,   150,   151,   153,   152,   185,    92,   191,   194,     0,
       0,    93,     0,    88,    59,    58,    56,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,   226,   227,
       0,     0,    59,     0,     0,     0,     0,   198,   207,     0,
       0,     0,     0,     0,    74,    73,     0,     0,   242,    41,
      34,     0,     0,     0,     0,     0,     0,     0,     0,   190,
     193,    91,   139,   197,    99,   102,    60,     0,     0,     0,
       0,     0,     0,     0,   191,   208,     0,   203,   211,   210,
     209,   206,   204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    35,    32,     0,   160,   160,   160,   160,
     160,   160,     0,   195,   141,   101,   100,     0,    97,     0,
      96,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     104,     0,     0,     0,     0,     0,     0,     0,    75,    76,
     195,   195,    42,    33,     0,   160,   162,     0,   160,   161,
       0,   160,   163,     0,   160,   164,     0,   160,   166,     0,
     160,   165,     0,     0,    99,   102,     0,     0,     0,     0,
       0,     0,   191,   191,   104,     0,   116,   205,    78,     0,
      77,    80,     0,    82,     0,    86,     0,    84,     0,     0,
       0,   160,   174,   160,   173,   160,   175,   160,   176,   160,
     178,   160,   177,     0,    90,    98,   103,     0,   104,     0,
       0,     0,     0,     0,   191,   104,   104,   132,     0,     0,
     106,     0,     0,     0,     0,     0,    71,    72,   168,   167,
     169,   170,   172,   171,     0,     0,     0,   104,   117,     0,
       0,     0,     0,   191,   104,   115,   124,     0,     0,     0,
       0,   105,    79,    81,    83,    87,    85,   139,   104,   104,
     133,   104,   104,   104,   104,   104,   131,     0,   110,   108,
     111,   109,   106,   140,     0,   104,   118,   125,     0,   104,
     119,     0,   104,   120,     0,   104,   122,     0,   104,   121,
     123,     0,     0,   107,   104,   134,   104,   135,   104,   136,
     104,   138,   104,   137,     0,   112,   113,   126,   127,   128,
     130,   129,     0,   114
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -392,  -392,  -392,  -392,  -392,  -392,  -392,  -392,  -392,  -392,
    -392,  -392,  -392,  -392,  -300,  -240,  -392,  -392,   344,   433,
    -392,  -392,  -392,  -392,   310,   392,  -227,  -139,  -392,  -392,
     351,   441,  -392,  -392,  -392,  -392,   165,   121,   123,  -391,
      15,    41,  -226,    35,    56,  -392,  -101,  -392,   -14,  -130,
    -100,  -293,  -105,  -392,  -392,  -392,  -392,  -392,  -149,  -392
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   312,   243,    30,    31,   159,   113,
     309,   165,   114,    32,   201,   140,   278,   150,    33,    34,
     156,   110,   366,   367,    35,   276,   385,   428,   430,   486,
     561,   530,   203,   423,   382,    49,   171,    50,    77,   137,
     108,   230,   383,   354,   152,   217,   218,   350,   219,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     199,   228,   151,   132,   313,   301,   197,   357,   141,    37,
      51,    38,   488,   372,    74,   233,    74,   174,   177,   180,
     183,   186,   107,   130,   168,    42,    43,    44,    45,    46,
     489,   192,   168,   168,    78,    54,   126,   198,   262,    55,
      93,   100,   202,    94,   101,   491,   169,   142,   485,   546,
     143,   131,   144,   239,   172,   175,   235,   145,   146,   147,
     148,   232,   149,   492,   271,   272,    39,   353,   355,   251,
     413,   370,   253,    47,   170,   255,    48,   547,   257,    56,
     296,   259,   173,   176,   261,   125,   127,   128,   129,   299,
     424,   267,   168,   527,   144,   240,    58,   274,   241,   145,
     146,   147,   485,   584,   149,   144,   187,   386,   168,   188,
     145,   146,   147,    59,   178,   149,   359,   360,   361,   362,
     363,   133,   425,   426,   300,   398,   493,   548,    74,    57,
     181,   585,   485,   588,   555,   556,   485,   591,   334,   351,
     328,    60,   179,   134,   494,    75,   168,   135,   427,   319,
      76,   320,    61,   321,   352,   322,   570,   323,   182,   324,
      62,   589,    63,   576,   364,   592,   133,   365,   184,    64,
     133,   136,   329,   263,   264,   265,   266,   586,   587,    66,
     590,   593,   596,   599,   600,    65,   168,   168,   269,   168,
     342,    67,   438,   343,   605,    68,   185,   380,   607,    69,
     168,   609,   168,   168,   611,   133,    70,   613,   454,   457,
      71,   460,   397,   617,    72,   618,   270,   619,    73,   620,
     439,   621,   463,    74,   466,   469,   495,   523,   281,   282,
     283,   284,   285,   497,   485,   594,   455,   458,   373,   461,
      40,   374,    41,    74,   496,   485,   597,   289,   290,   291,
     464,   498,   467,   470,    81,   524,   387,     2,    79,   388,
     123,     3,     4,   595,   440,   124,     5,     6,    80,     7,
       8,     9,    10,    11,   598,   411,   286,    12,   412,   205,
      82,   442,    84,    13,   443,    14,   245,   246,   247,   248,
     249,    15,    16,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    17,   448,    52,    53,   449,   484,
     557,   379,   289,   297,   291,   456,   459,   462,   465,   468,
     471,   425,   426,   473,   220,   221,   222,   223,   224,   225,
     212,   226,   214,   227,   216,   220,   221,   222,   223,   224,
     225,   212,   226,   214,   227,   216,   529,    83,    85,    86,
     499,   500,   525,   526,   502,    88,    87,   504,    89,    90,
     506,    91,    92,   508,    95,   144,   510,    96,   106,   512,
     145,   146,   147,   295,    97,   149,   144,   107,    98,   558,
     559,   145,   146,   147,   298,   144,   149,    99,   102,   103,
     145,   146,   147,   396,   554,   149,   104,   105,   109,   116,
     538,   117,   539,   111,   540,   112,   541,   144,   542,   115,
     543,   118,   145,   146,   147,   528,   119,   149,   120,   579,
     581,   529,   121,   575,   144,   122,   138,   139,   601,   145,
     146,   147,   578,   144,   149,   153,   154,   155,   145,   146,
     147,   580,   144,   149,   158,   157,   166,   145,   146,   147,
     614,   144,   149,   167,   189,   193,   145,   146,   147,   202,
     190,   149,   615,   344,   345,   346,   347,   348,   349,   160,
     161,   162,   163,   164,   191,   194,   196,   133,   195,   200,
     204,   229,   231,   236,   238,   242,   244,   168,   250,   252,
     254,   256,   268,   277,   280,   258,   260,   273,   275,   287,
     288,  -216,  -217,  -218,  -219,  -220,   292,  -221,   302,  -214,
     293,   294,   304,   305,   307,   308,   310,   311,   314,   315,
     316,   317,   318,   325,   326,   327,   330,   331,   332,   333,
     335,   337,   338,   339,   340,   341,  -215,   368,   358,   375,
     369,   371,   356,   381,   376,   377,   399,   378,   384,   389,
     400,   401,   390,   403,   404,   405,   406,   414,   407,   472,
     415,   408,   416,   417,   391,   392,   393,   418,   409,   394,
     410,   419,   422,   420,   421,   432,   395,   402,   429,   431,
     453,   306,   433,   434,   435,   303,   436,   514,   441,   336,
     437,   237,   279,   490,   475,   515,   234,   603,   516,   444,
     567,   582,   583,   517,   445,   477,   519,   520,   521,   522,
       0,     0,     0,   485,   536,   537,     0,     0,   562,   563,
     564,   565,   566,     0,   452,     0,     0,   446,     0,   447,
     450,   451,     0,   474,   476,     0,   478,   479,   480,   481,
     482,   483,   544,   487,   545,   501,   549,   503,   505,   507,
     509,   511,   513,   550,   551,   518,   531,   552,   560,   602,
       0,   532,   533,   534,   535,   622,     0,     0,   553,     0,
       0,     0,     0,     0,     0,   568,     0,   569,   571,   572,
     573,   574,   577,     0,     0,     0,   604,     0,   606,   608,
     610,   612,     0,   616,   623
};

static const yytype_int16 yycheck[] =
{
     139,   150,   107,   103,   244,   231,   136,   300,    17,     6,
      69,     8,    18,   313,    19,   154,    19,   118,   119,   120,
     121,   122,    40,    41,    19,    21,    22,    23,    24,    25,
      36,   131,    19,    19,    48,     3,    41,   137,    41,    37,
      69,    69,     9,    72,    72,    18,    41,    56,    40,    41,
      59,    69,    61,    17,    41,    41,   156,    66,    67,    68,
      69,    17,    71,    36,   194,   195,    63,   293,   294,   170,
     370,   311,   173,    69,    69,   176,    72,    69,   179,    39,
     219,   182,    69,    69,   185,    99,   100,   101,   102,   228,
     383,   191,    19,   484,    61,    59,     3,   197,    62,    66,
      67,    68,    40,    41,    71,    61,    69,   334,    19,    72,
      66,    67,    68,     3,    41,    71,    21,    22,    23,    24,
      25,    19,    10,    11,   229,   352,    18,   518,    19,    69,
      41,    69,    40,    41,   525,   526,    40,    41,   277,   288,
     270,     3,    69,    41,    36,    36,    19,    45,    36,   250,
      41,   252,     3,   254,   293,   256,   547,   258,    69,   260,
       3,    69,    48,   554,    69,    69,    19,    72,    41,    69,
      19,    69,   272,   187,   188,   189,   190,   568,   569,     8,
     571,   572,   573,   574,   575,    69,    19,    19,    41,    19,
      36,    69,    41,    39,   585,    69,    69,   327,   589,    17,
      19,   592,    19,    19,   595,    19,    17,   598,    41,    41,
      17,    41,   351,   604,    17,   606,    69,   608,    17,   610,
      69,   612,    41,    19,    41,    41,    18,    41,    21,    22,
      23,    24,    25,    18,    40,    41,    69,    69,    69,    69,
       6,    72,     8,    19,    36,    40,    41,    56,    57,    58,
      69,    36,    69,    69,     3,    69,    69,     0,    39,    72,
      36,     4,     5,    69,   394,    41,     9,    10,    39,    12,
      13,    14,    15,    16,    69,    59,    69,    20,    62,    36,
       3,    69,    69,    26,    72,    28,    21,    22,    23,    24,
      25,    34,    35,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    47,    69,     7,     8,    72,   439,
      36,   325,    56,    57,    58,   416,   417,   418,   419,   420,
     421,    10,    11,   423,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,   485,    39,    69,    43,
     450,   451,   482,   483,   455,    17,    49,   458,    44,    69,
     461,     3,     3,   464,    69,    61,   467,    69,    38,   470,
      66,    67,    68,    69,    69,    71,    61,    40,    69,   528,
     529,    66,    67,    68,    69,    61,    71,    69,    69,    69,
      66,    67,    68,    69,   524,    71,    69,    69,    69,    44,
     501,    18,   503,    71,   505,    69,   507,    61,   509,    69,
     511,    18,    66,    67,    68,    69,    18,    71,    18,   558,
     559,   560,    18,   553,    61,    18,     3,    17,   577,    66,
      67,    68,    69,    61,    71,     3,    50,    19,    66,    67,
      68,    69,    61,    71,    19,    37,    17,    66,    67,    68,
      69,    61,    71,    69,    69,     3,    66,    67,    68,     9,
      69,    71,   601,    50,    51,    52,    53,    54,    55,    29,
      30,    31,    32,    33,    69,    69,    46,    19,    69,    19,
      56,    42,    17,     6,    18,    69,    17,    19,    69,    69,
      69,    69,     3,    19,     3,    69,    69,    69,    64,    18,
      69,    17,    17,    17,    17,    17,    59,    17,     9,    17,
      17,    17,     3,    69,     3,    66,    61,    19,    17,    17,
      17,    17,    17,    69,     3,    69,    44,     3,    65,     3,
      18,    17,    17,    17,    17,    17,    17,     3,    18,    69,
      18,    18,    36,     3,    69,    69,    18,    69,    69,    69,
      18,    18,    69,    17,    17,    17,    17,     3,    17,    46,
      18,    36,    18,    18,    69,    69,    69,    18,    39,    69,
      39,    18,    45,    18,    18,    18,    69,    69,    19,    36,
       3,   237,    36,    36,    36,   234,    36,     3,    36,   279,
      39,   158,   200,    18,   429,   474,   155,   582,   475,    69,
     544,   560,   567,    18,    69,    39,    18,    18,    18,    18,
      -1,    -1,    -1,    40,    18,    18,    -1,    -1,    18,    18,
      18,    18,    18,    -1,    61,    -1,    -1,    69,    -1,    69,
      69,    69,    -1,    69,    69,    -1,    69,    69,    69,    69,
      69,    69,    44,    69,    39,    69,    39,    69,    69,    69,
      69,    69,    69,    39,    39,    69,    69,    39,    42,    36,
      -1,    69,    69,    69,    69,    36,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    69,    69,    69,
      69,    69,    69,    -1,    -1,    -1,    69,    -1,    69,    69,
      69,    69,    -1,    69,    69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,     0,     4,     5,     9,    10,    12,    13,    14,
      15,    16,    20,    26,    28,    34,    35,    47,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      90,    91,    97,   102,   103,   108,   133,     6,     8,    63,
       6,     8,    21,    22,    23,    24,    25,    69,    72,   119,
     121,    69,     7,     8,     3,    37,    39,    69,     3,     3,
       3,     3,     3,    48,    69,    69,     8,    69,    69,    17,
      17,    17,    17,    17,    19,    36,    41,   122,   122,    39,
      39,     3,     3,    39,    69,    69,    43,    49,    17,    44,
      69,     3,     3,    69,    72,    69,    69,    69,    69,    69,
      69,    72,    69,    69,    69,    69,    38,    40,   124,    69,
     105,    71,    69,    93,    96,    69,    44,    18,    18,    18,
      18,    18,    18,    36,    41,   122,    41,   122,   122,   122,
      41,    69,   124,    19,    41,    45,    69,   123,     3,    17,
      99,    17,    56,    59,    61,    66,    67,    68,    69,    71,
     101,   126,   128,     3,    50,    19,   104,    37,    19,    92,
      29,    30,    31,    32,    33,    95,    17,    69,    19,    41,
      69,   120,    41,    69,   120,    41,    69,   120,    41,    69,
     120,    41,    69,   120,    41,    69,   120,    69,    72,    69,
      69,    69,   124,     3,    69,    69,    46,   123,   124,   101,
      19,    98,     9,   116,    56,    36,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,   129,   130,   132,
      50,    51,    52,    53,    54,    55,    57,    59,   132,    42,
     125,    17,    17,   101,   105,   124,     6,    93,    18,    17,
      59,    62,    69,    89,    17,    21,    22,    23,    24,    25,
      69,   120,    69,   120,    69,   120,    69,   120,    69,   120,
      69,   120,    41,   122,   122,   122,   122,   124,     3,    41,
      69,   123,   123,    69,   124,    64,   109,    19,   100,    99,
       3,    21,    22,    23,    24,    25,    69,    18,    69,    56,
      57,    58,    59,    17,    17,    69,   101,    57,    69,   101,
     126,   116,     9,   104,     3,    69,    92,     3,    66,    94,
      61,    19,    88,    89,    17,    17,    17,    17,    17,   120,
     120,   120,   120,   120,   120,    69,     3,    69,   123,   124,
      44,     3,    65,     3,   101,    18,    98,    17,    17,    17,
      17,    17,    36,    39,    50,    51,    52,    53,    54,    55,
     131,   132,   101,   116,   127,   116,    36,   125,    18,    21,
      22,    23,    24,    25,    69,    72,   106,   107,     3,    18,
      89,    18,    88,    69,    72,    69,    69,    69,    69,   122,
     123,     3,   118,   126,    69,   110,   100,    69,    72,    69,
      69,    69,    69,    69,    69,    69,    69,   101,   100,    18,
      18,    18,    69,    17,    17,    17,    17,    17,    36,    39,
      39,    59,    62,    88,     3,    18,    18,    18,    18,    18,
      18,    18,    45,   117,   125,    10,    11,    36,   111,    19,
     112,    36,    18,    36,    36,    36,    36,    39,    41,    69,
     123,    36,    69,    72,    69,    69,    69,    69,    69,    72,
      69,    69,    61,     3,    41,    69,   120,    41,    69,   120,
      41,    69,   120,    41,    69,   120,    41,    69,   120,    41,
      69,   120,    46,   124,    69,   110,    69,    39,    69,    69,
      69,    69,    69,    69,   123,    40,   113,    69,    18,    36,
      18,    18,    36,    18,    36,    18,    36,    18,    36,   124,
     124,    69,   120,    69,   120,    69,   120,    69,   120,    69,
     120,    69,   120,    69,     3,   111,   112,    18,    69,    18,
      18,    18,    18,    41,    69,   123,   123,   113,    69,   101,
     115,    69,    69,    69,    69,    69,    18,    18,   120,   120,
     120,   120,   120,   120,    44,    39,    41,    69,   113,    39,
      39,    39,    39,    69,   123,   113,   113,    36,   132,   132,
      42,   114,    18,    18,    18,    18,    18,   118,    69,    69,
     113,    69,    69,    69,    69,   123,   113,    69,    69,   101,
      69,   101,   115,   117,    41,    69,   113,   113,    41,    69,
     113,    41,    69,   113,    41,    69,   113,    41,    69,   113,
     113,   132,    36,   114,    69,   113,    69,   113,    69,   113,
      69,   113,    69,   113,    69,   101,    69,   113,   113,   113,
     113,   113,    36,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    87,    88,    88,    89,    90,    91,    92,
      92,    93,    93,    93,    93,    93,    93,    94,    95,    95,
      95,    95,    95,    96,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   101,   101,   101,   102,   103,   104,   104,
     105,   105,   105,   106,   106,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   109,   109,   110,   110,   111,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     115,   115,   115,   115,   115,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   117,
     117,   118,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   121,   121,   121,   121,   122,   122,   122,   122,   122,
     122,   123,   123,   123,   123,   124,   124,   125,   125,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   127,   128,   128,   129,   129,   130,   130,   130,   130,
     130,   130,   131,   131,   131,   131,   131,   131,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   133
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       5,     3,    10,    11,     0,     3,     1,     4,     8,     0,
       3,     5,     7,     6,     2,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     7,     0,     3,     0,     4,     0,
       3,     1,     1,     1,     1,     1,     5,     7,     0,     3,
       3,     9,     9,     1,     1,     3,     3,     4,     4,     6,
       4,     6,     4,     6,     4,     6,     4,     6,     8,     6,
      12,     9,     8,     8,     7,     0,     4,     2,     4,     0,
       1,     1,     0,     3,     0,     3,     0,     3,     3,     3,
       3,     3,     5,     5,     7,     8,     6,     8,    10,    10,
      10,    10,    10,    10,     8,    10,    12,    12,    12,    12,
      12,     9,     7,     9,    11,    11,    11,    11,    11,     0,
       6,     2,     5,     5,     5,     5,     5,     5,     7,     7,
       7,     7,     7,     7,     6,     6,     6,     6,     6,     6,
       0,     6,     6,     6,     6,     6,     6,     8,     8,     8,
       8,     8,     8,     7,     7,     7,     7,     7,     7,     2,
       2,     4,     4,     4,     6,     0,     3,     5,     5,     5,
       7,     0,     3,     5,     4,     0,     3,     0,     3,     3,
       3,     3,     3,     5,     5,     7,     5,     4,     5,     5,
       5,     2,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       2,     1,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, void *scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *scanner)
{
  YY_USE (yyvaluep);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 22: /* exit: EXIT SEMICOLON  */
#line 195 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1689 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 200 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1697 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 205 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1705 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 211 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1713 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 217 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1721 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 223 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1729 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 229 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1738 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 235 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1746 "yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 241 "yacc_sql.y"
                                {
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
    }
#line 1755 "yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 249 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1764 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 257 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
		}
#line 1773 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 262 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
		}
#line 1782 "yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA index_attr index_attr_list  */
#line 270 "yacc_sql.y"
                                           { }
#line 1788 "yacc_sql.tab.c"
    break;

  case 36: /* index_attr: ID  */
#line 275 "yacc_sql.y"
                {
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
		}
#line 1796 "yacc_sql.tab.c"
    break;

  case 37: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 282 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1805 "yacc_sql.tab.c"
    break;

  case 38: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 289 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1817 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 299 "yacc_sql.y"
                                   {    }
#line 1823 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 304 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-3].number), (yyvsp[-1].number), 0);		
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1838 "yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type LBRACE number RBRACE NOT NULLL  */
#line 315 "yacc_sql.y"
        {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-5].number), (yyvsp[-3].number), 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1853 "yacc_sql.tab.c"
    break;

  case 43: /* attr_def: ID_get type LBRACE number RBRACE NULLABLE  */
#line 326 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-4].number), (yyvsp[-2].number), 1);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1868 "yacc_sql.tab.c"
    break;

  case 44: /* attr_def: ID_get type  */
#line 337 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[0].number), 4, 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1883 "yacc_sql.tab.c"
    break;

  case 45: /* attr_def: ID_get type NOT NULLL  */
#line 348 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-2].number), 4, 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1898 "yacc_sql.tab.c"
    break;

  case 46: /* attr_def: ID_get type NULLABLE  */
#line 359 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 4, 1);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1913 "yacc_sql.tab.c"
    break;

  case 47: /* number: NUMBER  */
#line 371 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1919 "yacc_sql.tab.c"
    break;

  case 48: /* type: INT_T  */
#line 374 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1925 "yacc_sql.tab.c"
    break;

  case 49: /* type: DATE_T  */
#line 375 "yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 1931 "yacc_sql.tab.c"
    break;

  case 50: /* type: TEXT_T  */
#line 376 "yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 1937 "yacc_sql.tab.c"
    break;

  case 51: /* type: STRING_T  */
#line 377 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1943 "yacc_sql.tab.c"
    break;

  case 52: /* type: FLOAT_T  */
#line 378 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1949 "yacc_sql.tab.c"
    break;

  case 53: /* ID_get: ID  */
#line 382 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1958 "yacc_sql.tab.c"
    break;

  case 54: /* insert: INSERT INTO ID VALUES record record_list SEMICOLON  */
#line 391 "yacc_sql.y"
                {
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			 CONTEXT->ssql->sstr.insertion.relation_name = (yyvsp[-4].string);
			 CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
			inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-4].string), CONTEXT->values, CONTEXT->value_length,CONTEXT->single_record_length,CONTEXT->record_length);

      //临时变量清零
      CONTEXT->value_length=0;
	  CONTEXT->record_length=0;
    }
#line 1978 "yacc_sql.tab.c"
    break;

  case 56: /* record_list: COMMA record record_list  */
#line 407 "yacc_sql.y"
                                        {

		}
#line 1986 "yacc_sql.tab.c"
    break;

  case 58: /* record: LBRACE value value_list RBRACE  */
#line 414 "yacc_sql.y"
                {
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		}
#line 1995 "yacc_sql.tab.c"
    break;

  case 60: /* value_list: COMMA value value_list  */
#line 419 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 2003 "yacc_sql.tab.c"
    break;

  case 61: /* value: NUMBER  */
#line 424 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2011 "yacc_sql.tab.c"
    break;

  case 62: /* value: FLOAT  */
#line 427 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2019 "yacc_sql.tab.c"
    break;

  case 63: /* value: DATEE  */
#line 430 "yacc_sql.y"
               {
			(yyvsp[0].dates) = substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].dates));
		}
#line 2028 "yacc_sql.tab.c"
    break;

  case 64: /* value: SSS  */
#line 434 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2037 "yacc_sql.tab.c"
    break;

  case 65: /* value: NULLL  */
#line 438 "yacc_sql.y"
               {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		}
#line 2045 "yacc_sql.tab.c"
    break;

  case 66: /* delete: DELETE FROM ID where SEMICOLON  */
#line 445 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2057 "yacc_sql.tab.c"
    break;

  case 67: /* update: UPDATE ID SET update_attr update_attr_list where SEMICOLON  */
#line 455 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2067 "yacc_sql.tab.c"
    break;

  case 70: /* update_attr: ID EQ value  */
#line 469 "yacc_sql.y"
                {
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			CONTEXT->value_length = 0;
		}
#line 2077 "yacc_sql.tab.c"
    break;

  case 71: /* update_attr: ID EQ LBRACE SELECT update_select_attr FROM ID where RBRACE  */
#line 475 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2089 "yacc_sql.tab.c"
    break;

  case 72: /* update_attr: ID EQ LBRACE SELECT update_agg FROM ID where RBRACE  */
#line 483 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2101 "yacc_sql.tab.c"
    break;

  case 73: /* update_select_attr: STAR  */
#line 493 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2111 "yacc_sql.tab.c"
    break;

  case 74: /* update_select_attr: ID  */
#line 498 "yacc_sql.y"
         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2121 "yacc_sql.tab.c"
    break;

  case 75: /* update_select_attr: ID DOT ID  */
#line 503 "yacc_sql.y"
                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2131 "yacc_sql.tab.c"
    break;

  case 76: /* update_select_attr: ID DOT STAR  */
#line 508 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2141 "yacc_sql.tab.c"
    break;

  case 77: /* update_agg: COUNT_T LBRACE STAR RBRACE  */
#line 516 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
#line 2151 "yacc_sql.tab.c"
    break;

  case 78: /* update_agg: COUNT_T LBRACE ID RBRACE  */
#line 521 "yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2161 "yacc_sql.tab.c"
    break;

  case 79: /* update_agg: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 526 "yacc_sql.y"
                                          {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2171 "yacc_sql.tab.c"
    break;

  case 80: /* update_agg: MAX_T LBRACE ID RBRACE  */
#line 531 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2181 "yacc_sql.tab.c"
    break;

  case 81: /* update_agg: MAX_T LBRACE ID DOT ID RBRACE  */
#line 536 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2191 "yacc_sql.tab.c"
    break;

  case 82: /* update_agg: MIN_T LBRACE ID RBRACE  */
#line 541 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2201 "yacc_sql.tab.c"
    break;

  case 83: /* update_agg: MIN_T LBRACE ID DOT ID RBRACE  */
#line 546 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2211 "yacc_sql.tab.c"
    break;

  case 84: /* update_agg: SUM_T LBRACE ID RBRACE  */
#line 551 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2221 "yacc_sql.tab.c"
    break;

  case 85: /* update_agg: SUM_T LBRACE ID DOT ID RBRACE  */
#line 556 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2231 "yacc_sql.tab.c"
    break;

  case 86: /* update_agg: AVG_T LBRACE ID RBRACE  */
#line 561 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2241 "yacc_sql.tab.c"
    break;

  case 87: /* update_agg: AVG_T LBRACE ID DOT ID RBRACE  */
#line 566 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2251 "yacc_sql.tab.c"
    break;

  case 88: /* select: SELECT select_attr FROM ID rel_list where order_by SEMICOLON  */
#line 574 "yacc_sql.y"
                                                                {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;

			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string));

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;//"select";

			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2271 "yacc_sql.tab.c"
    break;

  case 89: /* select: SELECT agg_fun_list_head FROM ID where SEMICOLON  */
#line 589 "yacc_sql.y"
                                                          {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;

		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2286 "yacc_sql.tab.c"
    break;

  case 90: /* select: SELECT select_attr FROM ID INNER_T JOIN_T ID ON join_cons join_list where SEMICOLON  */
#line 599 "yacc_sql.y"
                                                                                            {
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string));
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-8].string));
			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->ssql->flag=SCF_SELECT;//"select";

			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2302 "yacc_sql.tab.c"
    break;

  case 91: /* select: SELECT select_attr FROM ID AS ID rel_list where SEMICOLON  */
#line 610 "yacc_sql.y"
                                                                   {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string));
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		
	}
#line 2318 "yacc_sql.tab.c"
    break;

  case 92: /* select: SELECT agg_fun_list_head FROM ID AS ID where SEMICOLON  */
#line 621 "yacc_sql.y"
                                                                  {
	selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
	selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;
		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2333 "yacc_sql.tab.c"
    break;

  case 93: /* select: SELECT select_attr FROM ID ID rel_list where SEMICOLON  */
#line 631 "yacc_sql.y"
                                                                 {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-3].string));
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		
	}
#line 2349 "yacc_sql.tab.c"
    break;

  case 94: /* select: SELECT agg_fun_list_head FROM ID ID where SEMICOLON  */
#line 642 "yacc_sql.y"
                                                                {
	selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
	selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;
		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2364 "yacc_sql.tab.c"
    break;

  case 97: /* order_item: ID order  */
#line 659 "yacc_sql.y"
                 {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, CONTEXT->order);
	}
#line 2374 "yacc_sql.tab.c"
    break;

  case 98: /* order_item: ID DOT ID order  */
#line 664 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, CONTEXT->order);
	}
#line 2384 "yacc_sql.tab.c"
    break;

  case 99: /* order: %empty  */
#line 672 "yacc_sql.y"
                    {
		CONTEXT->order = 0;
	}
#line 2392 "yacc_sql.tab.c"
    break;

  case 100: /* order: ASC  */
#line 675 "yacc_sql.y"
              {
		CONTEXT->order = 0;
	}
#line 2400 "yacc_sql.tab.c"
    break;

  case 101: /* order: DESC  */
#line 678 "yacc_sql.y"
               {
		CONTEXT->order = 1;
	}
#line 2408 "yacc_sql.tab.c"
    break;

  case 105: /* sub_where: WHERE sub_condition sub_condition_list  */
#line 689 "yacc_sql.y"
                                             {	
			}
#line 2415 "yacc_sql.tab.c"
    break;

  case 107: /* sub_condition_list: AND sub_condition sub_condition_list  */
#line 694 "yacc_sql.y"
                                           {
			}
#line 2422 "yacc_sql.tab.c"
    break;

  case 108: /* sub_condition: ID comOp value  */
#line 699 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;

		}
#line 2438 "yacc_sql.tab.c"
    break;

  case 109: /* sub_condition: value comOp value  */
#line 711 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;

		}
#line 2452 "yacc_sql.tab.c"
    break;

  case 110: /* sub_condition: ID comOp ID  */
#line 721 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;

		}
#line 2476 "yacc_sql.tab.c"
    break;

  case 111: /* sub_condition: value comOp ID  */
#line 741 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;

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
#line 2502 "yacc_sql.tab.c"
    break;

  case 112: /* sub_condition: ID DOT ID comOp value  */
#line 763 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;

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
#line 2527 "yacc_sql.tab.c"
    break;

  case 113: /* sub_condition: value comOp ID DOT ID  */
#line 784 "yacc_sql.y"
                {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;
									
    }
#line 2541 "yacc_sql.tab.c"
    break;

  case 114: /* sub_condition: ID DOT ID comOp ID DOT ID  */
#line 794 "yacc_sql.y"
        {
			
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;
    }
#line 2556 "yacc_sql.tab.c"
    break;

  case 115: /* sub_query: SELECT ID DOT ID FROM ID rel_list sub_where  */
#line 807 "yacc_sql.y"
                                                    {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-6].string), (yyvsp[-4].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2582 "yacc_sql.tab.c"
    break;

  case 116: /* sub_query: SELECT ID FROM ID rel_list sub_where  */
#line 828 "yacc_sql.y"
                                              {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-4].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2605 "yacc_sql.tab.c"
    break;

  case 117: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID sub_where  */
#line 846 "yacc_sql.y"
                                                            {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-1].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2628 "yacc_sql.tab.c"
    break;

  case 118: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 864 "yacc_sql.y"
                                                                 {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-1].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-6].string), (yyvsp[-4].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2651 "yacc_sql.tab.c"
    break;

  case 119: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 882 "yacc_sql.y"
                                                               {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-1].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-6].string), (yyvsp[-4].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2674 "yacc_sql.tab.c"
    break;

  case 120: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 900 "yacc_sql.y"
                                                               {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-1].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-6].string), (yyvsp[-4].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 2697 "yacc_sql.tab.c"
    break;

  case 121: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 918 "yacc_sql.y"
                                                               {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-1].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-6].string), (yyvsp[-4].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 2720 "yacc_sql.tab.c"
    break;

  case 122: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 936 "yacc_sql.y"
                                                               {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-1].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-6].string), (yyvsp[-4].string));
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 2746 "yacc_sql.tab.c"
    break;

  case 123: /* sub_query: SELECT ID DOT ID FROM ID AS ID rel_list sub_where  */
#line 957 "yacc_sql.y"
                                                             {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2773 "yacc_sql.tab.c"
    break;

  case 124: /* sub_query: SELECT ID FROM ID AS ID rel_list sub_where  */
#line 979 "yacc_sql.y"
                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		RelAttr attr;
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		relation_attr_init(&attr, NULL, (yyvsp[-6].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2797 "yacc_sql.tab.c"
    break;

  case 125: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID AS ID sub_where  */
#line 998 "yacc_sql.y"
                                                                  {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2821 "yacc_sql.tab.c"
    break;

  case 126: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID AS ID sub_where  */
#line 1017 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2845 "yacc_sql.tab.c"
    break;

  case 127: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID AS ID sub_where  */
#line 1036 "yacc_sql.y"
                                                                     {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2869 "yacc_sql.tab.c"
    break;

  case 128: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID AS ID sub_where  */
#line 1055 "yacc_sql.y"
                                                                     {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 2893 "yacc_sql.tab.c"
    break;

  case 129: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID AS ID sub_where  */
#line 1074 "yacc_sql.y"
                                                                     {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 2917 "yacc_sql.tab.c"
    break;

  case 130: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID AS ID sub_where  */
#line 1093 "yacc_sql.y"
                                                                     {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 2944 "yacc_sql.tab.c"
    break;

  case 131: /* sub_query: SELECT ID DOT ID FROM ID ID rel_list sub_where  */
#line 1115 "yacc_sql.y"
                                                             {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-7].string), (yyvsp[-5].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2971 "yacc_sql.tab.c"
    break;

  case 132: /* sub_query: SELECT ID FROM ID ID rel_list sub_where  */
#line 1137 "yacc_sql.y"
                                                  {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		RelAttr attr;
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		relation_attr_init(&attr, NULL, (yyvsp[-5].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2995 "yacc_sql.tab.c"
    break;

  case 133: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID ID sub_where  */
#line 1156 "yacc_sql.y"
                                                                {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3019 "yacc_sql.tab.c"
    break;

  case 134: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID ID sub_where  */
#line 1175 "yacc_sql.y"
                                                                     {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-7].string), (yyvsp[-5].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3043 "yacc_sql.tab.c"
    break;

  case 135: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID ID sub_where  */
#line 1194 "yacc_sql.y"
                                                                   {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-7].string), (yyvsp[-5].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3067 "yacc_sql.tab.c"
    break;

  case 136: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID ID sub_where  */
#line 1213 "yacc_sql.y"
                                                                  {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-7].string), (yyvsp[-5].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 3091 "yacc_sql.tab.c"
    break;

  case 137: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID ID sub_where  */
#line 1232 "yacc_sql.y"
                                                                  {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-7].string), (yyvsp[-5].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 3115 "yacc_sql.tab.c"
    break;

  case 138: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID ID sub_where  */
#line 1251 "yacc_sql.y"
                                                                  {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->sub_cons, CONTEXT->sub_cons_num);
		
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-7].string), (yyvsp[-5].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->sub_cons_num=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 3142 "yacc_sql.tab.c"
    break;

  case 140: /* join_list: INNER_T JOIN_T ID ON join_cons join_list  */
#line 1277 "yacc_sql.y"
                                               {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
	}
#line 3150 "yacc_sql.tab.c"
    break;

  case 141: /* join_cons: condition condition_list  */
#line 1282 "yacc_sql.y"
                                  {	
	}
#line 3157 "yacc_sql.tab.c"
    break;

  case 142: /* agg_fun_list_head: COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 1287 "yacc_sql.y"
                                                {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 3167 "yacc_sql.tab.c"
    break;

  case 143: /* agg_fun_list_head: COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 1292 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 3177 "yacc_sql.tab.c"
    break;

  case 144: /* agg_fun_list_head: MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 1297 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3188 "yacc_sql.tab.c"
    break;

  case 145: /* agg_fun_list_head: MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 1303 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3199 "yacc_sql.tab.c"
    break;

  case 146: /* agg_fun_list_head: SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 1309 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3210 "yacc_sql.tab.c"
    break;

  case 147: /* agg_fun_list_head: AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 1315 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3221 "yacc_sql.tab.c"
    break;

  case 148: /* agg_fun_list_head: COUNT_T LBRACE STAR RBRACE AS ID agg_fun_list  */
#line 1321 "yacc_sql.y"
                                                       {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3232 "yacc_sql.tab.c"
    break;

  case 149: /* agg_fun_list_head: COUNT_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1327 "yacc_sql.y"
                                                    {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3243 "yacc_sql.tab.c"
    break;

  case 150: /* agg_fun_list_head: MAX_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1333 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
#line 3255 "yacc_sql.tab.c"
    break;

  case 151: /* agg_fun_list_head: MIN_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1340 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
#line 3267 "yacc_sql.tab.c"
    break;

  case 152: /* agg_fun_list_head: SUM_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1347 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
	
		CONTEXT->select_length++;
	  }
#line 3279 "yacc_sql.tab.c"
    break;

  case 153: /* agg_fun_list_head: AVG_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1354 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		
		CONTEXT->select_length++;
	  }
#line 3291 "yacc_sql.tab.c"
    break;

  case 154: /* agg_fun_list_head: COUNT_T LBRACE STAR RBRACE ID agg_fun_list  */
#line 1361 "yacc_sql.y"
                                                     {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3302 "yacc_sql.tab.c"
    break;

  case 155: /* agg_fun_list_head: COUNT_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1367 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3313 "yacc_sql.tab.c"
    break;

  case 156: /* agg_fun_list_head: MAX_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1373 "yacc_sql.y"
                                                 {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
#line 3325 "yacc_sql.tab.c"
    break;

  case 157: /* agg_fun_list_head: MIN_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1380 "yacc_sql.y"
                                                 {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
#line 3337 "yacc_sql.tab.c"
    break;

  case 158: /* agg_fun_list_head: SUM_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1387 "yacc_sql.y"
                                                 {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
	
		CONTEXT->select_length++;
	  }
#line 3349 "yacc_sql.tab.c"
    break;

  case 159: /* agg_fun_list_head: AVG_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1394 "yacc_sql.y"
                                                 {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		
		CONTEXT->select_length++;
	  }
#line 3361 "yacc_sql.tab.c"
    break;

  case 161: /* agg_fun_list: COMMA COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 1404 "yacc_sql.y"
                                                      {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 3371 "yacc_sql.tab.c"
    break;

  case 162: /* agg_fun_list: COMMA COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 1409 "yacc_sql.y"
                                                    {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 3381 "yacc_sql.tab.c"
    break;

  case 163: /* agg_fun_list: COMMA MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 1414 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3392 "yacc_sql.tab.c"
    break;

  case 164: /* agg_fun_list: COMMA MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 1420 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre,MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3403 "yacc_sql.tab.c"
    break;

  case 165: /* agg_fun_list: COMMA SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 1426 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3414 "yacc_sql.tab.c"
    break;

  case 166: /* agg_fun_list: COMMA AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 1432 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3425 "yacc_sql.tab.c"
    break;

  case 167: /* agg_fun_list: COMMA COUNT_T LBRACE STAR RBRACE AS ID agg_fun_list  */
#line 1438 "yacc_sql.y"
                                                             {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3436 "yacc_sql.tab.c"
    break;

  case 168: /* agg_fun_list: COMMA COUNT_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1444 "yacc_sql.y"
                                                          {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3447 "yacc_sql.tab.c"
    break;

  case 169: /* agg_fun_list: COMMA MAX_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1450 "yacc_sql.y"
                                                         {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3458 "yacc_sql.tab.c"
    break;

  case 170: /* agg_fun_list: COMMA MIN_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1456 "yacc_sql.y"
                                                         {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3469 "yacc_sql.tab.c"
    break;

  case 171: /* agg_fun_list: COMMA SUM_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1462 "yacc_sql.y"
                                                         {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3480 "yacc_sql.tab.c"
    break;

  case 172: /* agg_fun_list: COMMA AVG_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1468 "yacc_sql.y"
                                                         {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3491 "yacc_sql.tab.c"
    break;

  case 173: /* agg_fun_list: COMMA COUNT_T LBRACE STAR RBRACE ID agg_fun_list  */
#line 1474 "yacc_sql.y"
                                                           {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3502 "yacc_sql.tab.c"
    break;

  case 174: /* agg_fun_list: COMMA COUNT_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1480 "yacc_sql.y"
                                                        {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3513 "yacc_sql.tab.c"
    break;

  case 175: /* agg_fun_list: COMMA MAX_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1486 "yacc_sql.y"
                                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3524 "yacc_sql.tab.c"
    break;

  case 176: /* agg_fun_list: COMMA MIN_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1492 "yacc_sql.y"
                                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3535 "yacc_sql.tab.c"
    break;

  case 177: /* agg_fun_list: COMMA SUM_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1498 "yacc_sql.y"
                                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3546 "yacc_sql.tab.c"
    break;

  case 178: /* agg_fun_list: COMMA AVG_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1504 "yacc_sql.y"
                                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3557 "yacc_sql.tab.c"
    break;

  case 179: /* select_attr: STAR attr_list  */
#line 1514 "yacc_sql.y"
                   {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			CONTEXT->ssql->sstr.selection.need_Revere=1;
		}
#line 3568 "yacc_sql.tab.c"
    break;

  case 180: /* select_attr: ID attr_list  */
#line 1520 "yacc_sql.y"
                   {
			RelAttr attr;
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 3579 "yacc_sql.tab.c"
    break;

  case 181: /* select_attr: ID DOT ID attr_list  */
#line 1526 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 3589 "yacc_sql.tab.c"
    break;

  case 182: /* select_attr: ID DOT STAR attr_list  */
#line 1531 "yacc_sql.y"
                               {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 3599 "yacc_sql.tab.c"
    break;

  case 183: /* select_attr: ID AS ID attr_list  */
#line 1536 "yacc_sql.y"
                            {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-3].string));
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 3610 "yacc_sql.tab.c"
    break;

  case 184: /* select_attr: ID DOT ID AS ID attr_list  */
#line 1542 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string),(yyvsp[-1].string));
		}
#line 3621 "yacc_sql.tab.c"
    break;

  case 186: /* attr_list: COMMA ID attr_list  */
#line 1551 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 3632 "yacc_sql.tab.c"
    break;

  case 187: /* attr_list: COMMA ID DOT ID attr_list  */
#line 1557 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 3643 "yacc_sql.tab.c"
    break;

  case 188: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 1563 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 3654 "yacc_sql.tab.c"
    break;

  case 189: /* attr_list: COMMA ID AS ID attr_list  */
#line 1569 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-3].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 3666 "yacc_sql.tab.c"
    break;

  case 190: /* attr_list: COMMA ID DOT ID AS ID attr_list  */
#line 1576 "yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string),(yyvsp[-1].string));
		}
#line 3677 "yacc_sql.tab.c"
    break;

  case 192: /* rel_list: COMMA ID rel_list  */
#line 1586 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 3685 "yacc_sql.tab.c"
    break;

  case 193: /* rel_list: COMMA ID AS ID rel_list  */
#line 1589 "yacc_sql.y"
                                 {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 3694 "yacc_sql.tab.c"
    break;

  case 194: /* rel_list: COMMA ID ID rel_list  */
#line 1593 "yacc_sql.y"
                              {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
	}
#line 3703 "yacc_sql.tab.c"
    break;

  case 196: /* where: WHERE condition condition_list  */
#line 1600 "yacc_sql.y"
                                     {	
			}
#line 3710 "yacc_sql.tab.c"
    break;

  case 198: /* condition_list: AND condition condition_list  */
#line 1605 "yacc_sql.y"
                                   {
			}
#line 3717 "yacc_sql.tab.c"
    break;

  case 199: /* condition: ID comOp value  */
#line 1610 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 3733 "yacc_sql.tab.c"
    break;

  case 200: /* condition: value comOp value  */
#line 1622 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 3747 "yacc_sql.tab.c"
    break;

  case 201: /* condition: ID comOp ID  */
#line 1632 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

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
#line 3771 "yacc_sql.tab.c"
    break;

  case 202: /* condition: value comOp ID  */
#line 1652 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

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
#line 3797 "yacc_sql.tab.c"
    break;

  case 203: /* condition: ID DOT ID comOp value  */
#line 1674 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
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
#line 3822 "yacc_sql.tab.c"
    break;

  case 204: /* condition: value comOp ID DOT ID  */
#line 1695 "yacc_sql.y"
                {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 3836 "yacc_sql.tab.c"
    break;

  case 205: /* condition: ID DOT ID comOp ID DOT ID  */
#line 1705 "yacc_sql.y"
        {
			
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3851 "yacc_sql.tab.c"
    break;

  case 206: /* condition: ID sub_com LBRACE sub_query RBRACE  */
#line 1716 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->tempOp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3863 "yacc_sql.tab.c"
    break;

  case 207: /* condition: exist_con LBRACE sub_query RBRACE  */
#line 1724 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->tempOp, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3873 "yacc_sql.tab.c"
    break;

  case 208: /* condition: LBRACE sub_query RBRACE reverseComp ID  */
#line 1729 "yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->comp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3885 "yacc_sql.tab.c"
    break;

  case 209: /* condition: ID in_not_com LBRACE in_cells RBRACE  */
#line 1736 "yacc_sql.y"
                                             {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,CONTEXT->tempOp);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3898 "yacc_sql.tab.c"
    break;

  case 210: /* condition: ID in_not_com LBRACE sub_query RBRACE  */
#line 1744 "yacc_sql.y"
                                              {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->tempOp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3910 "yacc_sql.tab.c"
    break;

  case 211: /* in_cells: value value_list  */
#line 1754 "yacc_sql.y"
                          {
	}
#line 3917 "yacc_sql.tab.c"
    break;

  case 212: /* exist_con: NOT EXIST_T  */
#line 1757 "yacc_sql.y"
                    {CONTEXT->tempOp= NOT_EXIST;}
#line 3923 "yacc_sql.tab.c"
    break;

  case 213: /* exist_con: EXIST_T  */
#line 1758 "yacc_sql.y"
                 {CONTEXT->tempOp = EXIST;}
#line 3929 "yacc_sql.tab.c"
    break;

  case 214: /* in_not_com: IN_T  */
#line 1761 "yacc_sql.y"
             {CONTEXT->tempOp = IN;}
#line 3935 "yacc_sql.tab.c"
    break;

  case 215: /* in_not_com: NOT IN_T  */
#line 1762 "yacc_sql.y"
                   {CONTEXT->tempOp = NOT_IN;}
#line 3941 "yacc_sql.tab.c"
    break;

  case 216: /* sub_com: EQ  */
#line 1765 "yacc_sql.y"
           { CONTEXT->tempOp = EQUAL_TO;}
#line 3947 "yacc_sql.tab.c"
    break;

  case 217: /* sub_com: LT  */
#line 1766 "yacc_sql.y"
         { CONTEXT->tempOp = LESS_THAN; }
#line 3953 "yacc_sql.tab.c"
    break;

  case 218: /* sub_com: GT  */
#line 1767 "yacc_sql.y"
         { CONTEXT->tempOp = GREAT_THAN; }
#line 3959 "yacc_sql.tab.c"
    break;

  case 219: /* sub_com: LE  */
#line 1768 "yacc_sql.y"
         { CONTEXT->tempOp = LESS_EQUAL; }
#line 3965 "yacc_sql.tab.c"
    break;

  case 220: /* sub_com: GE  */
#line 1769 "yacc_sql.y"
         { CONTEXT->tempOp = GREAT_EQUAL; }
#line 3971 "yacc_sql.tab.c"
    break;

  case 221: /* sub_com: NE  */
#line 1770 "yacc_sql.y"
         { CONTEXT->tempOp = NOT_EQUAL; }
#line 3977 "yacc_sql.tab.c"
    break;

  case 222: /* reverseComp: EQ  */
#line 1773 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 3983 "yacc_sql.tab.c"
    break;

  case 223: /* reverseComp: LT  */
#line 1774 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3989 "yacc_sql.tab.c"
    break;

  case 224: /* reverseComp: GT  */
#line 1775 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3995 "yacc_sql.tab.c"
    break;

  case 225: /* reverseComp: LE  */
#line 1776 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 4001 "yacc_sql.tab.c"
    break;

  case 226: /* reverseComp: GE  */
#line 1777 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 4007 "yacc_sql.tab.c"
    break;

  case 227: /* reverseComp: NE  */
#line 1778 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 4013 "yacc_sql.tab.c"
    break;

  case 228: /* comOp: EQ  */
#line 1781 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO;}
#line 4019 "yacc_sql.tab.c"
    break;

  case 229: /* comOp: LT  */
#line 1782 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 4025 "yacc_sql.tab.c"
    break;

  case 230: /* comOp: GT  */
#line 1783 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 4031 "yacc_sql.tab.c"
    break;

  case 231: /* comOp: LE  */
#line 1784 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 4037 "yacc_sql.tab.c"
    break;

  case 232: /* comOp: GE  */
#line 1785 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 4043 "yacc_sql.tab.c"
    break;

  case 233: /* comOp: NE  */
#line 1786 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 4049 "yacc_sql.tab.c"
    break;

  case 234: /* comOp: LIKE  */
#line 1787 "yacc_sql.y"
               { CONTEXT->comp = LIKE_TO; }
#line 4055 "yacc_sql.tab.c"
    break;

  case 235: /* comOp: IN_T  */
#line 1788 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 4061 "yacc_sql.tab.c"
    break;

  case 236: /* comOp: NOT IN_T  */
#line 1789 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 4067 "yacc_sql.tab.c"
    break;

  case 237: /* comOp: NOT EXIST_T  */
#line 1790 "yacc_sql.y"
                     {CONTEXT->comp = NOT_EXIST;}
#line 4073 "yacc_sql.tab.c"
    break;

  case 238: /* comOp: EXIST_T  */
#line 1791 "yacc_sql.y"
                 {CONTEXT->comp = EXIST;}
#line 4079 "yacc_sql.tab.c"
    break;

  case 239: /* comOp: NOT LIKE  */
#line 1792 "yacc_sql.y"
                   { CONTEXT->comp = NOT_LIKE; }
#line 4085 "yacc_sql.tab.c"
    break;

  case 240: /* comOp: IS NOT  */
#line 1793 "yacc_sql.y"
                 { CONTEXT->comp = COMP_IS_NOT; }
#line 4091 "yacc_sql.tab.c"
    break;

  case 241: /* comOp: IS  */
#line 1794 "yacc_sql.y"
             { CONTEXT->comp = COMP_IS; }
#line 4097 "yacc_sql.tab.c"
    break;

  case 242: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1799 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 4106 "yacc_sql.tab.c"
    break;


#line 4110 "yacc_sql.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (scanner, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1804 "yacc_sql.y"

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
