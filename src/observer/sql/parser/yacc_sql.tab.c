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
#define YYLAST   642

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  219
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  572

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
     599,   610,   620,   630,   632,   636,   641,   649,   652,   655,
     660,   662,   664,   666,   669,   671,   675,   687,   697,   717,
     739,   760,   770,   784,   805,   823,   841,   859,   877,   895,
     913,   934,   956,   975,   994,  1013,  1032,  1051,  1070,  1094,
    1096,  1101,  1106,  1111,  1116,  1122,  1128,  1134,  1140,  1146,
    1152,  1159,  1166,  1173,  1181,  1183,  1188,  1193,  1199,  1205,
    1211,  1217,  1223,  1229,  1235,  1241,  1247,  1257,  1263,  1269,
    1274,  1279,  1285,  1292,  1294,  1300,  1306,  1312,  1319,  1327,
    1329,  1332,  1337,  1339,  1342,  1344,  1348,  1360,  1370,  1390,
    1412,  1433,  1443,  1454,  1462,  1468,  1475,  1483,  1493,  1496,
    1497,  1500,  1501,  1504,  1505,  1506,  1507,  1508,  1509,  1512,
    1513,  1514,  1515,  1516,  1517,  1520,  1521,  1522,  1523,  1524,
    1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,  1537
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

#define YYPACT_NINF (-456)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-199)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -456,   162,  -456,     8,   255,    28,   -52,   112,    22,    -5,
       1,   -23,    52,    81,    96,   104,   157,    67,  -456,  -456,
    -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,
    -456,  -456,  -456,  -456,  -456,  -456,  -456,    80,    84,   160,
     101,   124,   238,   256,   258,   287,   294,    18,   296,   278,
     284,   303,   324,   300,  -456,   282,   309,   334,  -456,  -456,
    -456,  -456,  -456,   305,   362,   336,   315,   382,   383,   -31,
     318,   320,   321,   322,   323,   -27,   325,  -456,  -456,   326,
     327,  -456,  -456,   328,   355,   358,   330,   329,   332,   333,
     359,  -456,  -456,   386,   387,   388,   389,   390,   391,    82,
       7,   296,   296,   140,    24,   407,   394,    79,   409,   363,
     395,   378,  -456,   397,   338,   401,   350,    16,    41,    95,
      98,   113,   114,    44,   352,  -456,   353,  -456,  -456,  -456,
     354,   417,   356,   357,   381,   358,  -456,   279,   405,   419,
    -456,   373,  -456,  -456,  -456,  -456,   148,  -456,   190,   392,
     413,  -456,    27,   330,   358,   425,   332,   414,  -456,  -456,
    -456,  -456,  -456,    30,   364,   418,   351,   367,  -456,   368,
    -456,   369,  -456,   370,  -456,   371,  -456,   372,  -456,   132,
     296,   296,   296,   439,  -456,   138,   424,   375,   384,   426,
     394,   443,    -1,   429,  -456,   380,   433,   434,   435,   436,
     437,   438,  -456,   440,  -456,   209,   399,   442,   444,   191,
    -456,  -456,  -456,  -456,  -456,  -456,  -456,   239,   203,    79,
    -456,   419,   447,  -456,   395,   457,   393,   397,   460,   398,
     404,  -456,  -456,   448,   364,   449,   451,   452,   453,   454,
     455,   455,   455,   455,   455,   455,   403,  -456,  -456,  -456,
    -456,  -456,   406,  -456,   358,   432,   408,   474,   279,   461,
     405,  -456,   463,   464,   465,   466,   467,   176,   311,   190,
    -456,   468,  -456,  -456,    19,   419,  -456,  -456,  -456,   450,
    -456,   392,   469,    87,  -456,  -456,   475,  -456,  -456,  -456,
     470,  -456,   364,   471,   448,   182,   421,   422,   423,   427,
    -456,  -456,  -456,  -456,  -456,  -456,   296,   424,   490,    79,
     428,  -456,   426,  -456,  -456,   184,   430,   431,   441,   445,
     446,   456,  -456,  -456,  -456,  -456,  -456,  -456,   458,   223,
     426,   476,   477,   480,   459,  -456,  -456,   484,   485,   486,
     487,   488,   472,  -456,   473,   478,  -456,   155,   448,   503,
     489,   491,   493,   495,   498,   500,   501,  -456,  -456,  -456,
     479,   392,    20,   502,  -456,   494,   504,   496,   497,   499,
     505,   481,   142,  -456,   506,  -456,  -456,  -456,  -456,  -456,
    -456,   216,   462,   482,   483,   492,   244,   507,   508,   509,
    -456,  -456,  -456,   520,   144,   145,   146,   150,   170,   175,
     510,   358,  -456,  -456,  -456,   511,  -456,   428,  -456,   512,
     514,   513,   515,   516,   517,   518,   519,   522,   521,     0,
     525,   116,   200,   201,   202,  -456,  -456,   358,   358,  -456,
    -456,   523,  -456,   524,  -456,   526,  -456,   527,  -456,   528,
    -456,   529,  -456,   530,   531,   212,   502,   532,   533,   536,
     537,   539,   540,   194,   424,   232,  -456,  -456,  -456,   534,
    -456,  -456,   535,  -456,   538,  -456,   541,  -456,   542,   545,
     546,   455,   455,   455,   455,   455,   455,   547,  -456,  -456,
    -456,   544,   246,   550,   555,   561,   562,   543,   522,   522,
     174,   190,   563,   548,   549,   551,   553,   554,  -456,  -456,
    -456,  -456,  -456,  -456,  -456,  -456,    79,   552,   556,  -456,
     557,   558,   559,   560,   424,  -456,  -456,   564,   241,   253,
     232,  -456,  -456,  -456,  -456,  -456,  -456,   479,   285,   522,
     289,   301,   308,   312,   522,   190,  -456,  -456,   570,  -456,
     563,  -456,   565,  -456,  -456,   566,  -456,   567,  -456,   568,
    -456,   569,  -456,  -456,   267,   571,  -456,   522,   522,   522,
     522,   522,   572,  -456,  -456,  -456,  -456,  -456,  -456,  -456,
     573,  -456
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
       0,     0,     0,     0,     0,     0,     0,   163,   163,     0,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,    23,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,   157,     0,
       0,    31,    29,     0,     0,   172,     0,     0,     0,     0,
       0,    28,    37,     0,     0,     0,     0,     0,     0,   163,
     163,   163,   163,   172,   169,     0,    57,     0,     0,     0,
      68,     0,    53,    39,     0,     0,     0,   144,   144,   144,
     144,   144,   144,     0,     0,   164,     0,   159,   160,   161,
       0,     0,     0,     0,     0,   172,    30,     0,    55,     0,
     190,     0,    65,    61,    62,    63,     0,    64,     0,   174,
       0,    66,     0,     0,   172,     0,     0,     0,    48,    51,
      52,    49,    50,    44,     0,     0,     0,     0,   133,     0,
     132,     0,   134,     0,   135,     0,   137,     0,   136,   163,
     163,   163,   163,     0,    89,   169,   169,     0,    93,    59,
      57,     0,     0,     0,   189,     0,   205,   206,   207,   208,
     209,   210,   215,   212,   211,     0,   218,     0,     0,     0,
     205,   206,   207,   208,   209,   210,   212,     0,     0,     0,
     173,     0,     0,    70,    68,     0,     0,    39,     0,     0,
       0,    46,    36,    34,     0,     0,     0,     0,     0,     0,
     144,   144,   144,   144,   144,   144,     0,   165,   166,   167,
     162,    92,     0,   170,   172,     0,     0,     0,     0,     0,
      55,    54,     0,     0,     0,     0,     0,     0,     0,     0,
     214,   213,   216,   217,     0,     0,   178,   176,   213,   179,
     177,   174,     0,     0,    69,    67,     0,    40,    38,    47,
       0,    45,     0,     0,    34,     0,     0,     0,     0,     0,
     139,   138,   140,   141,   143,   142,   163,   169,     0,     0,
       0,    88,    59,    58,    56,     0,     0,     0,     0,     0,
       0,     0,   199,   200,   201,   202,   203,   204,     0,     0,
      59,     0,     0,     0,     0,   175,   184,     0,     0,     0,
       0,     0,    74,    73,     0,     0,   219,    41,    34,     0,
       0,     0,     0,     0,     0,     0,     0,   168,   171,    91,
     129,   174,    97,   100,    60,     0,     0,     0,     0,     0,
       0,     0,   169,   185,     0,   180,   188,   187,   186,   183,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    35,    32,     0,   144,   144,   144,   144,   144,   144,
       0,   172,   131,    99,    98,     0,    95,     0,    94,     0,
       0,     0,     0,     0,     0,     0,     0,   102,     0,     0,
       0,     0,     0,     0,     0,    75,    76,   172,   172,    42,
      33,     0,   146,     0,   145,     0,   147,     0,   148,     0,
     150,     0,   149,     0,     0,    97,   100,     0,     0,     0,
       0,     0,     0,   169,   169,     0,   114,   182,    78,     0,
      77,    80,     0,    82,     0,    86,     0,    84,     0,     0,
       0,   144,   144,   144,   144,   144,   144,     0,    90,    96,
     101,     0,   102,     0,     0,     0,     0,     0,   102,   102,
       0,     0,   104,     0,     0,     0,     0,     0,    71,    72,
     152,   151,   153,   154,   156,   155,     0,     0,     0,   115,
       0,     0,     0,     0,   169,   113,   122,     0,     0,     0,
       0,   103,    79,    81,    83,    87,    85,   129,   102,   102,
     102,   102,   102,   102,   102,     0,   108,   106,   109,   107,
     104,   130,     0,   116,   123,     0,   117,     0,   118,     0,
     120,     0,   119,   121,     0,     0,   105,   102,   102,   102,
     102,   102,     0,   110,   111,   124,   125,   126,   128,   127,
       0,   112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,
    -456,  -456,  -456,  -456,  -265,  -222,  -456,  -456,   299,   412,
    -456,  -456,  -456,  -456,   269,   346,   -91,  -137,  -456,  -456,
     313,   385,  -456,  -456,  -456,  -456,   133,    94,    99,  -455,
       4,    26,  -208,    21,    43,  -456,  -116,  -456,   -38,  -177,
     -96,  -270,   -88,  -456,  -456,  -456,  -456,  -456,  -147,  -456
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   293,   233,    30,    31,   157,   113,
     290,   163,   114,    32,   191,   138,   259,   148,    33,    34,
     154,   110,   344,   345,    35,   257,   363,   406,   408,   456,
     521,   492,   193,   401,   360,    49,   168,    50,    77,   135,
     108,   220,   361,   332,   150,   207,   208,   328,   209,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     189,   218,   170,   172,   174,   176,   178,   131,   253,   254,
      78,   335,   294,   282,    37,   223,    38,    51,   458,   149,
     262,   263,   264,   265,   266,    54,    74,   509,   192,   350,
     403,   404,    55,   515,   516,   166,   459,    74,    93,   188,
      56,    94,   100,   132,   222,   101,    57,   229,   126,    42,
      43,    44,    45,    46,    75,    58,   405,   167,   225,    76,
     166,   125,   127,   128,   129,   133,   331,   333,   267,   134,
     348,    39,   277,   543,   544,   546,   548,   550,   552,   553,
     142,   280,   169,   391,    59,   143,   144,   145,   142,   230,
     147,   402,   231,   143,   144,   145,   139,    47,   147,    60,
      48,    74,   565,   566,   567,   568,   569,    61,   337,   338,
     339,   340,   341,   179,   166,    63,   180,   166,   123,    52,
      53,   312,   329,   124,   300,   301,   302,   303,   304,   305,
     358,   281,   166,   166,   461,   140,   171,   330,   141,   173,
     142,   247,   248,   249,   250,   143,   144,   145,   146,    64,
     147,    74,   462,    65,   175,   177,   342,   132,   308,   343,
      62,   132,     2,   166,   166,   166,     3,     4,    66,   166,
      67,     5,     6,   246,     7,     8,     9,    10,    11,   252,
     107,   130,    12,   416,   195,   431,   433,   435,    13,   166,
      14,   437,   375,    68,   166,   417,    15,    16,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    17,
     517,   439,   320,   132,   389,   321,   441,   390,   463,   465,
     467,   364,   403,   404,   210,   211,   212,   213,   214,   215,
     202,   216,   204,   217,   206,   487,   464,   466,   468,   376,
     210,   211,   212,   213,   214,   215,   202,   216,   204,   217,
     206,   351,   142,   365,   352,    69,   366,   143,   144,   145,
     276,    40,   147,    41,   142,   270,   271,   272,   357,   143,
     144,   145,   279,    70,   147,    71,   488,   489,   432,   434,
     436,   438,   440,   442,   142,   419,   455,   508,   420,   143,
     144,   145,   374,   142,   147,   270,   278,   272,   143,   144,
     145,   490,   142,   147,    72,   444,    81,   143,   144,   145,
     536,    73,   147,   425,   142,    74,   426,    79,   491,   143,
     144,   145,   538,    80,   147,   455,   542,    82,   142,   455,
     545,   469,   470,   143,   144,   145,   562,   534,   147,    83,
     142,   455,   547,   518,   519,   143,   144,   145,   455,   549,
     147,    84,   455,   551,    87,   500,   501,   502,   503,   504,
     505,   322,   323,   324,   325,   326,   327,   158,   159,   160,
     161,   162,   235,   236,   237,   238,   239,    86,    85,    88,
      89,   537,   539,   491,    90,    91,    92,    95,   554,    96,
      97,    98,    99,   106,   102,   103,   104,   105,   107,   109,
     111,   112,   115,   116,   117,   118,   119,   120,   121,   122,
     136,   137,   151,   152,   153,   155,   156,   563,   164,   165,
     184,   181,   182,   183,   190,   185,   186,   187,   192,   194,
     221,   226,   228,   232,   219,   234,   240,   241,   242,   243,
     244,   245,   251,   132,   255,   258,   261,   268,   256,   269,
    -193,  -194,  -195,  -196,  -197,  -198,   283,  -191,   273,   274,
     285,   275,   286,   288,   289,   291,   295,   292,   296,   297,
     298,   299,   306,   310,   166,   307,   309,   311,   346,   313,
     315,   316,   317,   318,   319,  -192,   334,   336,   347,   349,
     353,   354,   355,   359,   377,   378,   356,   362,   379,   367,
     368,   381,   382,   383,   384,   385,   392,   393,   386,   394,
     369,   395,   387,   396,   370,   371,   397,   388,   398,   399,
     415,   407,   410,   430,   400,   372,   287,   373,   380,   314,
     409,   421,   411,   412,   478,   413,   260,   284,   224,   479,
     446,   414,   418,   460,   556,   480,   540,     0,   541,   527,
     481,   422,   423,   448,   483,   484,   443,   485,   486,     0,
       0,   424,   455,   498,   499,     0,   522,   523,   227,   524,
     429,   525,   526,     0,     0,     0,   427,   428,     0,     0,
     445,   447,   449,   507,   450,   451,   452,   453,   454,   510,
     457,   506,   471,   472,   511,   473,   474,   475,   476,   477,
     512,   513,   482,   493,   494,   520,   555,   495,   570,     0,
     496,   497,   514,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,     0,     0,   529,   530,   531,   532,   533,
       0,     0,     0,   535,   557,   558,   559,   560,   561,     0,
     564,     0,   571
};

static const yytype_int16 yycheck[] =
{
     137,   148,   118,   119,   120,   121,   122,   103,   185,   186,
      48,   281,   234,   221,     6,   152,     8,    69,    18,   107,
      21,    22,    23,    24,    25,     3,    19,   482,     9,   294,
      10,    11,    37,   488,   489,    19,    36,    19,    69,   135,
      39,    72,    69,    19,    17,    72,    69,    17,    41,    21,
      22,    23,    24,    25,    36,     3,    36,    41,   154,    41,
      19,    99,   100,   101,   102,    41,   274,   275,    69,    45,
     292,    63,   209,   528,   529,   530,   531,   532,   533,   534,
      61,   218,    41,   348,     3,    66,    67,    68,    61,    59,
      71,   361,    62,    66,    67,    68,    17,    69,    71,     3,
      72,    19,   557,   558,   559,   560,   561,     3,    21,    22,
      23,    24,    25,    69,    19,    48,    72,    19,    36,     7,
       8,   258,   269,    41,   240,   241,   242,   243,   244,   245,
     307,   219,    19,    19,    18,    56,    41,   274,    59,    41,
      61,   179,   180,   181,   182,    66,    67,    68,    69,    69,
      71,    19,    36,    69,    41,    41,    69,    19,   254,    72,
       3,    19,     0,    19,    19,    19,     4,     5,     8,    19,
      69,     9,    10,    41,    12,    13,    14,    15,    16,    41,
      40,    41,    20,    41,    36,    41,    41,    41,    26,    19,
      28,    41,   329,    69,    19,   372,    34,    35,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    47,
      36,    41,    36,    19,    59,    39,    41,    62,    18,    18,
      18,   312,    10,    11,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    41,    36,    36,    36,   330,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    69,    61,    69,    72,    17,    72,    66,    67,    68,
      69,     6,    71,     8,    61,    56,    57,    58,   306,    66,
      67,    68,    69,    17,    71,    17,   453,   454,   394,   395,
     396,   397,   398,   399,    61,    69,    40,    41,    72,    66,
      67,    68,    69,    61,    71,    56,    57,    58,    66,    67,
      68,    69,    61,    71,    17,   401,     3,    66,    67,    68,
      69,    17,    71,    69,    61,    19,    72,    39,   455,    66,
      67,    68,    69,    39,    71,    40,    41,     3,    61,    40,
      41,   427,   428,    66,    67,    68,    69,   514,    71,    39,
      61,    40,    41,   490,   491,    66,    67,    68,    40,    41,
      71,    69,    40,    41,    49,   471,   472,   473,   474,   475,
     476,    50,    51,    52,    53,    54,    55,    29,    30,    31,
      32,    33,    21,    22,    23,    24,    25,    43,    69,    17,
      44,   518,   519,   520,    69,     3,     3,    69,   535,    69,
      69,    69,    69,    38,    69,    69,    69,    69,    40,    69,
      71,    69,    69,    44,    18,    18,    18,    18,    18,    18,
       3,    17,     3,    50,    19,    37,    19,   554,    17,    69,
       3,    69,    69,    69,    19,    69,    69,    46,     9,    56,
      17,     6,    18,    69,    42,    17,    69,    69,    69,    69,
      69,    69,     3,    19,    69,    19,     3,    18,    64,    69,
      17,    17,    17,    17,    17,    17,     9,    17,    59,    17,
       3,    17,    69,     3,    66,    61,    17,    19,    17,    17,
      17,    17,    69,    65,    19,    69,    44,     3,     3,    18,
      17,    17,    17,    17,    17,    17,    36,    18,    18,    18,
      69,    69,    69,     3,    18,    18,    69,    69,    18,    69,
      69,    17,    17,    17,    17,    17,     3,    18,    36,    18,
      69,    18,    39,    18,    69,    69,    18,    39,    18,    18,
      39,    19,    18,     3,    45,    69,   227,    69,    69,   260,
      36,    69,    36,    36,     3,    36,   190,   224,   153,   445,
     407,    36,    36,    18,   540,   446,   520,    -1,   527,   506,
      18,    69,    69,    39,    18,    18,    46,    18,    18,    -1,
      -1,    69,    40,    18,    18,    -1,    18,    18,   156,    18,
      61,    18,    18,    -1,    -1,    -1,    69,    69,    -1,    -1,
      69,    69,    69,    39,    69,    69,    69,    69,    69,    39,
      69,    44,    69,    69,    39,    69,    69,    69,    69,    69,
      39,    39,    69,    69,    69,    42,    36,    69,    36,    -1,
      69,    69,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    69,    69,    69,    69,    69,
      -1,    -1,    -1,    69,    69,    69,    69,    69,    69,    -1,
      69,    -1,    69
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
      41,   124,    19,    41,    45,   123,     3,    17,    99,    17,
      56,    59,    61,    66,    67,    68,    69,    71,   101,   126,
     128,     3,    50,    19,   104,    37,    19,    92,    29,    30,
      31,    32,    33,    95,    17,    69,    19,    41,   120,    41,
     120,    41,   120,    41,   120,    41,   120,    41,   120,    69,
      72,    69,    69,    69,     3,    69,    69,    46,   124,   101,
      19,    98,     9,   116,    56,    36,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,   129,   130,   132,
      50,    51,    52,    53,    54,    55,    57,    59,   132,    42,
     125,    17,    17,   101,   105,   124,     6,    93,    18,    17,
      59,    62,    69,    89,    17,    21,    22,    23,    24,    25,
      69,    69,    69,    69,    69,    69,    41,   122,   122,   122,
     122,     3,    41,   123,   123,    69,    64,   109,    19,   100,
      99,     3,    21,    22,    23,    24,    25,    69,    18,    69,
      56,    57,    58,    59,    17,    17,    69,   101,    57,    69,
     101,   126,   116,     9,   104,     3,    69,    92,     3,    66,
      94,    61,    19,    88,    89,    17,    17,    17,    17,    17,
     120,   120,   120,   120,   120,   120,    69,    69,   124,    44,
      65,     3,   101,    18,    98,    17,    17,    17,    17,    17,
      36,    39,    50,    51,    52,    53,    54,    55,   131,   132,
     101,   116,   127,   116,    36,   125,    18,    21,    22,    23,
      24,    25,    69,    72,   106,   107,     3,    18,    89,    18,
      88,    69,    72,    69,    69,    69,    69,   122,   123,     3,
     118,   126,    69,   110,   100,    69,    72,    69,    69,    69,
      69,    69,    69,    69,    69,   101,   100,    18,    18,    18,
      69,    17,    17,    17,    17,    17,    36,    39,    39,    59,
      62,    88,     3,    18,    18,    18,    18,    18,    18,    18,
      45,   117,   125,    10,    11,    36,   111,    19,   112,    36,
      18,    36,    36,    36,    36,    39,    41,   123,    36,    69,
      72,    69,    69,    69,    69,    69,    72,    69,    69,    61,
       3,    41,   120,    41,   120,    41,   120,    41,   120,    41,
     120,    41,   120,    46,   124,    69,   110,    69,    39,    69,
      69,    69,    69,    69,    69,    40,   113,    69,    18,    36,
      18,    18,    36,    18,    36,    18,    36,    18,    36,   124,
     124,    69,    69,    69,    69,    69,    69,    69,     3,   111,
     112,    18,    69,    18,    18,    18,    18,    41,   123,   123,
      69,   101,   115,    69,    69,    69,    69,    69,    18,    18,
     120,   120,   120,   120,   120,   120,    44,    39,    41,   113,
      39,    39,    39,    39,    69,   113,   113,    36,   132,   132,
      42,   114,    18,    18,    18,    18,    18,   118,    69,    69,
      69,    69,    69,    69,   123,    69,    69,   101,    69,   101,
     115,   117,    41,   113,   113,    41,   113,    41,   113,    41,
     113,    41,   113,   113,   132,    36,   114,    69,    69,    69,
      69,    69,    69,   101,    69,   113,   113,   113,   113,   113,
      36,    69
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
     108,   108,   108,   109,   109,   110,   110,   111,   111,   111,
     112,   112,   113,   113,   114,   114,   115,   115,   115,   115,
     115,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   117,
     117,   118,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   121,   121,   122,   122,   122,   122,   122,   122,   123,
     123,   123,   124,   124,   125,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   128,
     128,   129,   129,   130,   130,   130,   130,   130,   130,   131,
     131,   131,   131,   131,   131,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   133
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
      12,     9,     7,     0,     4,     2,     4,     0,     1,     1,
       0,     3,     0,     3,     0,     3,     3,     3,     3,     3,
       5,     5,     7,     8,     6,     8,    10,    10,    10,    10,
      10,    10,     8,    10,    12,    12,    12,    12,    12,     0,
       6,     2,     5,     5,     5,     5,     5,     5,     7,     7,
       7,     7,     7,     7,     0,     6,     6,     6,     6,     6,
       6,     8,     8,     8,     8,     8,     8,     2,     2,     4,
       4,     4,     6,     0,     3,     5,     5,     5,     7,     0,
       3,     5,     0,     3,     0,     3,     3,     3,     3,     3,
       5,     5,     7,     5,     4,     5,     5,     5,     2,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     2,     1,     8
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
#line 1655 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 200 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1663 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 205 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1671 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 211 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1679 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 217 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1687 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 223 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1695 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 229 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1704 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 235 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1712 "yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 241 "yacc_sql.y"
                                {
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
    }
#line 1721 "yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 249 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1730 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 257 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
		}
#line 1739 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 262 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
		}
#line 1748 "yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA index_attr index_attr_list  */
#line 270 "yacc_sql.y"
                                           { }
#line 1754 "yacc_sql.tab.c"
    break;

  case 36: /* index_attr: ID  */
#line 275 "yacc_sql.y"
                {
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
		}
#line 1762 "yacc_sql.tab.c"
    break;

  case 37: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 282 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1771 "yacc_sql.tab.c"
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
#line 1783 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 299 "yacc_sql.y"
                                   {    }
#line 1789 "yacc_sql.tab.c"
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
#line 1804 "yacc_sql.tab.c"
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
#line 1819 "yacc_sql.tab.c"
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
#line 1834 "yacc_sql.tab.c"
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
#line 1849 "yacc_sql.tab.c"
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
#line 1864 "yacc_sql.tab.c"
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
#line 1879 "yacc_sql.tab.c"
    break;

  case 47: /* number: NUMBER  */
#line 371 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1885 "yacc_sql.tab.c"
    break;

  case 48: /* type: INT_T  */
#line 374 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1891 "yacc_sql.tab.c"
    break;

  case 49: /* type: DATE_T  */
#line 375 "yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 1897 "yacc_sql.tab.c"
    break;

  case 50: /* type: TEXT_T  */
#line 376 "yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 1903 "yacc_sql.tab.c"
    break;

  case 51: /* type: STRING_T  */
#line 377 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1909 "yacc_sql.tab.c"
    break;

  case 52: /* type: FLOAT_T  */
#line 378 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1915 "yacc_sql.tab.c"
    break;

  case 53: /* ID_get: ID  */
#line 382 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1924 "yacc_sql.tab.c"
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
#line 1944 "yacc_sql.tab.c"
    break;

  case 56: /* record_list: COMMA record record_list  */
#line 407 "yacc_sql.y"
                                        {

		}
#line 1952 "yacc_sql.tab.c"
    break;

  case 58: /* record: LBRACE value value_list RBRACE  */
#line 414 "yacc_sql.y"
                {
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		}
#line 1961 "yacc_sql.tab.c"
    break;

  case 60: /* value_list: COMMA value value_list  */
#line 419 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1969 "yacc_sql.tab.c"
    break;

  case 61: /* value: NUMBER  */
#line 424 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1977 "yacc_sql.tab.c"
    break;

  case 62: /* value: FLOAT  */
#line 427 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1985 "yacc_sql.tab.c"
    break;

  case 63: /* value: DATEE  */
#line 430 "yacc_sql.y"
               {
			(yyvsp[0].dates) = substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].dates));
		}
#line 1994 "yacc_sql.tab.c"
    break;

  case 64: /* value: SSS  */
#line 434 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2003 "yacc_sql.tab.c"
    break;

  case 65: /* value: NULLL  */
#line 438 "yacc_sql.y"
               {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		}
#line 2011 "yacc_sql.tab.c"
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
#line 2023 "yacc_sql.tab.c"
    break;

  case 67: /* update: UPDATE ID SET update_attr update_attr_list where SEMICOLON  */
#line 455 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2033 "yacc_sql.tab.c"
    break;

  case 70: /* update_attr: ID EQ value  */
#line 469 "yacc_sql.y"
                {
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			CONTEXT->value_length = 0;
		}
#line 2043 "yacc_sql.tab.c"
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
#line 2055 "yacc_sql.tab.c"
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
#line 2067 "yacc_sql.tab.c"
    break;

  case 73: /* update_select_attr: STAR  */
#line 493 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2077 "yacc_sql.tab.c"
    break;

  case 74: /* update_select_attr: ID  */
#line 498 "yacc_sql.y"
         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2087 "yacc_sql.tab.c"
    break;

  case 75: /* update_select_attr: ID DOT ID  */
#line 503 "yacc_sql.y"
                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2097 "yacc_sql.tab.c"
    break;

  case 76: /* update_select_attr: ID DOT STAR  */
#line 508 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2107 "yacc_sql.tab.c"
    break;

  case 77: /* update_agg: COUNT_T LBRACE STAR RBRACE  */
#line 516 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
#line 2117 "yacc_sql.tab.c"
    break;

  case 78: /* update_agg: COUNT_T LBRACE ID RBRACE  */
#line 521 "yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2127 "yacc_sql.tab.c"
    break;

  case 79: /* update_agg: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 526 "yacc_sql.y"
                                          {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2137 "yacc_sql.tab.c"
    break;

  case 80: /* update_agg: MAX_T LBRACE ID RBRACE  */
#line 531 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2147 "yacc_sql.tab.c"
    break;

  case 81: /* update_agg: MAX_T LBRACE ID DOT ID RBRACE  */
#line 536 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2157 "yacc_sql.tab.c"
    break;

  case 82: /* update_agg: MIN_T LBRACE ID RBRACE  */
#line 541 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2167 "yacc_sql.tab.c"
    break;

  case 83: /* update_agg: MIN_T LBRACE ID DOT ID RBRACE  */
#line 546 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2177 "yacc_sql.tab.c"
    break;

  case 84: /* update_agg: SUM_T LBRACE ID RBRACE  */
#line 551 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2187 "yacc_sql.tab.c"
    break;

  case 85: /* update_agg: SUM_T LBRACE ID DOT ID RBRACE  */
#line 556 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2197 "yacc_sql.tab.c"
    break;

  case 86: /* update_agg: AVG_T LBRACE ID RBRACE  */
#line 561 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2207 "yacc_sql.tab.c"
    break;

  case 87: /* update_agg: AVG_T LBRACE ID DOT ID RBRACE  */
#line 566 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2217 "yacc_sql.tab.c"
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
#line 2237 "yacc_sql.tab.c"
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
#line 2252 "yacc_sql.tab.c"
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
#line 2268 "yacc_sql.tab.c"
    break;

  case 91: /* select: SELECT select_attr FROM ID AS ID rel_list where SEMICOLON  */
#line 610 "yacc_sql.y"
                                                                   {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string));
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string));
	}
#line 2283 "yacc_sql.tab.c"
    break;

  case 92: /* select: SELECT agg_fun_list_head FROM ID AS ID SEMICOLON  */
#line 620 "yacc_sql.y"
                                                           {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
		CONTEXT->ssql->flag=SCF_SELECT;
		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2297 "yacc_sql.tab.c"
    break;

  case 95: /* order_item: ID order  */
#line 636 "yacc_sql.y"
                 {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, CONTEXT->order);
	}
#line 2307 "yacc_sql.tab.c"
    break;

  case 96: /* order_item: ID DOT ID order  */
#line 641 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, CONTEXT->order);
	}
#line 2317 "yacc_sql.tab.c"
    break;

  case 97: /* order: %empty  */
#line 649 "yacc_sql.y"
                    {
		CONTEXT->order = 0;
	}
#line 2325 "yacc_sql.tab.c"
    break;

  case 98: /* order: ASC  */
#line 652 "yacc_sql.y"
              {
		CONTEXT->order = 0;
	}
#line 2333 "yacc_sql.tab.c"
    break;

  case 99: /* order: DESC  */
#line 655 "yacc_sql.y"
               {
		CONTEXT->order = 1;
	}
#line 2341 "yacc_sql.tab.c"
    break;

  case 103: /* sub_where: WHERE sub_condition sub_condition_list  */
#line 666 "yacc_sql.y"
                                             {	
			}
#line 2348 "yacc_sql.tab.c"
    break;

  case 105: /* sub_condition_list: AND sub_condition sub_condition_list  */
#line 671 "yacc_sql.y"
                                           {
			}
#line 2355 "yacc_sql.tab.c"
    break;

  case 106: /* sub_condition: ID comOp value  */
#line 676 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;

		}
#line 2371 "yacc_sql.tab.c"
    break;

  case 107: /* sub_condition: value comOp value  */
#line 688 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;

		}
#line 2385 "yacc_sql.tab.c"
    break;

  case 108: /* sub_condition: ID comOp ID  */
#line 698 "yacc_sql.y"
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
#line 2409 "yacc_sql.tab.c"
    break;

  case 109: /* sub_condition: value comOp ID  */
#line 718 "yacc_sql.y"
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
#line 2435 "yacc_sql.tab.c"
    break;

  case 110: /* sub_condition: ID DOT ID comOp value  */
#line 740 "yacc_sql.y"
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
#line 2460 "yacc_sql.tab.c"
    break;

  case 111: /* sub_condition: value comOp ID DOT ID  */
#line 761 "yacc_sql.y"
                {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;
									
    }
#line 2474 "yacc_sql.tab.c"
    break;

  case 112: /* sub_condition: ID DOT ID comOp ID DOT ID  */
#line 771 "yacc_sql.y"
        {
			
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;
    }
#line 2489 "yacc_sql.tab.c"
    break;

  case 113: /* sub_query: SELECT ID DOT ID FROM ID rel_list sub_where  */
#line 784 "yacc_sql.y"
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
#line 2515 "yacc_sql.tab.c"
    break;

  case 114: /* sub_query: SELECT ID FROM ID rel_list sub_where  */
#line 805 "yacc_sql.y"
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
#line 2538 "yacc_sql.tab.c"
    break;

  case 115: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID sub_where  */
#line 823 "yacc_sql.y"
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
#line 2561 "yacc_sql.tab.c"
    break;

  case 116: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 841 "yacc_sql.y"
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
#line 2584 "yacc_sql.tab.c"
    break;

  case 117: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 859 "yacc_sql.y"
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
#line 2607 "yacc_sql.tab.c"
    break;

  case 118: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 877 "yacc_sql.y"
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
#line 2630 "yacc_sql.tab.c"
    break;

  case 119: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 895 "yacc_sql.y"
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
#line 2653 "yacc_sql.tab.c"
    break;

  case 120: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 913 "yacc_sql.y"
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
#line 2679 "yacc_sql.tab.c"
    break;

  case 121: /* sub_query: SELECT ID DOT ID FROM ID AS ID rel_list sub_where  */
#line 934 "yacc_sql.y"
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
#line 2706 "yacc_sql.tab.c"
    break;

  case 122: /* sub_query: SELECT ID FROM ID AS ID rel_list sub_where  */
#line 956 "yacc_sql.y"
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
#line 2730 "yacc_sql.tab.c"
    break;

  case 123: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID AS ID sub_where  */
#line 975 "yacc_sql.y"
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
#line 2754 "yacc_sql.tab.c"
    break;

  case 124: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID AS ID sub_where  */
#line 994 "yacc_sql.y"
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
#line 2778 "yacc_sql.tab.c"
    break;

  case 125: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID AS ID sub_where  */
#line 1013 "yacc_sql.y"
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
#line 2802 "yacc_sql.tab.c"
    break;

  case 126: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID AS ID sub_where  */
#line 1032 "yacc_sql.y"
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
#line 2826 "yacc_sql.tab.c"
    break;

  case 127: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID AS ID sub_where  */
#line 1051 "yacc_sql.y"
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
#line 2850 "yacc_sql.tab.c"
    break;

  case 128: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID AS ID sub_where  */
#line 1070 "yacc_sql.y"
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
#line 2877 "yacc_sql.tab.c"
    break;

  case 130: /* join_list: INNER_T JOIN_T ID ON join_cons join_list  */
#line 1096 "yacc_sql.y"
                                               {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
	}
#line 2885 "yacc_sql.tab.c"
    break;

  case 131: /* join_cons: condition condition_list  */
#line 1101 "yacc_sql.y"
                                  {	
	}
#line 2892 "yacc_sql.tab.c"
    break;

  case 132: /* agg_fun_list_head: COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 1106 "yacc_sql.y"
                                                {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2902 "yacc_sql.tab.c"
    break;

  case 133: /* agg_fun_list_head: COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 1111 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2912 "yacc_sql.tab.c"
    break;

  case 134: /* agg_fun_list_head: MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 1116 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2923 "yacc_sql.tab.c"
    break;

  case 135: /* agg_fun_list_head: MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 1122 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2934 "yacc_sql.tab.c"
    break;

  case 136: /* agg_fun_list_head: SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 1128 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2945 "yacc_sql.tab.c"
    break;

  case 137: /* agg_fun_list_head: AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 1134 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2956 "yacc_sql.tab.c"
    break;

  case 138: /* agg_fun_list_head: COUNT_T LBRACE STAR RBRACE AS ID agg_fun_list  */
#line 1140 "yacc_sql.y"
                                                       {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 2967 "yacc_sql.tab.c"
    break;

  case 139: /* agg_fun_list_head: COUNT_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1146 "yacc_sql.y"
                                                    {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 2978 "yacc_sql.tab.c"
    break;

  case 140: /* agg_fun_list_head: MAX_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1152 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
#line 2990 "yacc_sql.tab.c"
    break;

  case 141: /* agg_fun_list_head: MIN_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1159 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
#line 3002 "yacc_sql.tab.c"
    break;

  case 142: /* agg_fun_list_head: SUM_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1166 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
	
		CONTEXT->select_length++;
	  }
#line 3014 "yacc_sql.tab.c"
    break;

  case 143: /* agg_fun_list_head: AVG_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1173 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		
		CONTEXT->select_length++;
	  }
#line 3026 "yacc_sql.tab.c"
    break;

  case 145: /* agg_fun_list: COMMA COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 1183 "yacc_sql.y"
                                                      {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 3036 "yacc_sql.tab.c"
    break;

  case 146: /* agg_fun_list: COMMA COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 1188 "yacc_sql.y"
                                                    {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 3046 "yacc_sql.tab.c"
    break;

  case 147: /* agg_fun_list: COMMA MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 1193 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3057 "yacc_sql.tab.c"
    break;

  case 148: /* agg_fun_list: COMMA MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 1199 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre,MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3068 "yacc_sql.tab.c"
    break;

  case 149: /* agg_fun_list: COMMA SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 1205 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3079 "yacc_sql.tab.c"
    break;

  case 150: /* agg_fun_list: COMMA AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 1211 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3090 "yacc_sql.tab.c"
    break;

  case 151: /* agg_fun_list: COMMA COUNT_T LBRACE STAR RBRACE AS ID agg_fun_list  */
#line 1217 "yacc_sql.y"
                                                             {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3101 "yacc_sql.tab.c"
    break;

  case 152: /* agg_fun_list: COMMA COUNT_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1223 "yacc_sql.y"
                                                          {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3112 "yacc_sql.tab.c"
    break;

  case 153: /* agg_fun_list: COMMA MAX_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1229 "yacc_sql.y"
                                                         {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3123 "yacc_sql.tab.c"
    break;

  case 154: /* agg_fun_list: COMMA MIN_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1235 "yacc_sql.y"
                                                         {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3134 "yacc_sql.tab.c"
    break;

  case 155: /* agg_fun_list: COMMA SUM_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1241 "yacc_sql.y"
                                                         {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3145 "yacc_sql.tab.c"
    break;

  case 156: /* agg_fun_list: COMMA AVG_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1247 "yacc_sql.y"
                                                         {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3156 "yacc_sql.tab.c"
    break;

  case 157: /* select_attr: STAR attr_list  */
#line 1257 "yacc_sql.y"
                   {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			CONTEXT->ssql->sstr.selection.need_Revere=1;
		}
#line 3167 "yacc_sql.tab.c"
    break;

  case 158: /* select_attr: ID attr_list  */
#line 1263 "yacc_sql.y"
                   {
			RelAttr attr;
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 3178 "yacc_sql.tab.c"
    break;

  case 159: /* select_attr: ID DOT ID attr_list  */
#line 1269 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 3188 "yacc_sql.tab.c"
    break;

  case 160: /* select_attr: ID DOT STAR attr_list  */
#line 1274 "yacc_sql.y"
                               {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 3198 "yacc_sql.tab.c"
    break;

  case 161: /* select_attr: ID AS ID attr_list  */
#line 1279 "yacc_sql.y"
                            {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-3].string));
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 3209 "yacc_sql.tab.c"
    break;

  case 162: /* select_attr: ID DOT ID AS ID attr_list  */
#line 1285 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string),(yyvsp[-1].string));
		}
#line 3220 "yacc_sql.tab.c"
    break;

  case 164: /* attr_list: COMMA ID attr_list  */
#line 1294 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 3231 "yacc_sql.tab.c"
    break;

  case 165: /* attr_list: COMMA ID DOT ID attr_list  */
#line 1300 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 3242 "yacc_sql.tab.c"
    break;

  case 166: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 1306 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 3253 "yacc_sql.tab.c"
    break;

  case 167: /* attr_list: COMMA ID AS ID attr_list  */
#line 1312 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-3].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 3265 "yacc_sql.tab.c"
    break;

  case 168: /* attr_list: COMMA ID DOT ID AS ID attr_list  */
#line 1319 "yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string),(yyvsp[-1].string));
		}
#line 3276 "yacc_sql.tab.c"
    break;

  case 170: /* rel_list: COMMA ID rel_list  */
#line 1329 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 3284 "yacc_sql.tab.c"
    break;

  case 171: /* rel_list: COMMA ID AS ID rel_list  */
#line 1332 "yacc_sql.y"
                                 {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 3293 "yacc_sql.tab.c"
    break;

  case 173: /* where: WHERE condition condition_list  */
#line 1339 "yacc_sql.y"
                                     {	
			}
#line 3300 "yacc_sql.tab.c"
    break;

  case 175: /* condition_list: AND condition condition_list  */
#line 1344 "yacc_sql.y"
                                   {
			}
#line 3307 "yacc_sql.tab.c"
    break;

  case 176: /* condition: ID comOp value  */
#line 1349 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 3323 "yacc_sql.tab.c"
    break;

  case 177: /* condition: value comOp value  */
#line 1361 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 3337 "yacc_sql.tab.c"
    break;

  case 178: /* condition: ID comOp ID  */
#line 1371 "yacc_sql.y"
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
#line 3361 "yacc_sql.tab.c"
    break;

  case 179: /* condition: value comOp ID  */
#line 1391 "yacc_sql.y"
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
#line 3387 "yacc_sql.tab.c"
    break;

  case 180: /* condition: ID DOT ID comOp value  */
#line 1413 "yacc_sql.y"
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
#line 3412 "yacc_sql.tab.c"
    break;

  case 181: /* condition: value comOp ID DOT ID  */
#line 1434 "yacc_sql.y"
                {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 3426 "yacc_sql.tab.c"
    break;

  case 182: /* condition: ID DOT ID comOp ID DOT ID  */
#line 1444 "yacc_sql.y"
        {
			
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3441 "yacc_sql.tab.c"
    break;

  case 183: /* condition: ID sub_com LBRACE sub_query RBRACE  */
#line 1455 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->tempOp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3453 "yacc_sql.tab.c"
    break;

  case 184: /* condition: exist_con LBRACE sub_query RBRACE  */
#line 1463 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->tempOp, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3463 "yacc_sql.tab.c"
    break;

  case 185: /* condition: LBRACE sub_query RBRACE reverseComp ID  */
#line 1468 "yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->comp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3475 "yacc_sql.tab.c"
    break;

  case 186: /* condition: ID in_not_com LBRACE in_cells RBRACE  */
#line 1475 "yacc_sql.y"
                                             {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,CONTEXT->tempOp);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3488 "yacc_sql.tab.c"
    break;

  case 187: /* condition: ID in_not_com LBRACE sub_query RBRACE  */
#line 1483 "yacc_sql.y"
                                              {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->tempOp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3500 "yacc_sql.tab.c"
    break;

  case 188: /* in_cells: value value_list  */
#line 1493 "yacc_sql.y"
                          {
	}
#line 3507 "yacc_sql.tab.c"
    break;

  case 189: /* exist_con: NOT EXIST_T  */
#line 1496 "yacc_sql.y"
                    {CONTEXT->tempOp= NOT_EXIST;}
#line 3513 "yacc_sql.tab.c"
    break;

  case 190: /* exist_con: EXIST_T  */
#line 1497 "yacc_sql.y"
                 {CONTEXT->tempOp = EXIST;}
#line 3519 "yacc_sql.tab.c"
    break;

  case 191: /* in_not_com: IN_T  */
#line 1500 "yacc_sql.y"
             {CONTEXT->tempOp = IN;}
#line 3525 "yacc_sql.tab.c"
    break;

  case 192: /* in_not_com: NOT IN_T  */
#line 1501 "yacc_sql.y"
                   {CONTEXT->tempOp = NOT_IN;}
#line 3531 "yacc_sql.tab.c"
    break;

  case 193: /* sub_com: EQ  */
#line 1504 "yacc_sql.y"
           { CONTEXT->tempOp = EQUAL_TO;}
#line 3537 "yacc_sql.tab.c"
    break;

  case 194: /* sub_com: LT  */
#line 1505 "yacc_sql.y"
         { CONTEXT->tempOp = LESS_THAN; }
#line 3543 "yacc_sql.tab.c"
    break;

  case 195: /* sub_com: GT  */
#line 1506 "yacc_sql.y"
         { CONTEXT->tempOp = GREAT_THAN; }
#line 3549 "yacc_sql.tab.c"
    break;

  case 196: /* sub_com: LE  */
#line 1507 "yacc_sql.y"
         { CONTEXT->tempOp = LESS_EQUAL; }
#line 3555 "yacc_sql.tab.c"
    break;

  case 197: /* sub_com: GE  */
#line 1508 "yacc_sql.y"
         { CONTEXT->tempOp = GREAT_EQUAL; }
#line 3561 "yacc_sql.tab.c"
    break;

  case 198: /* sub_com: NE  */
#line 1509 "yacc_sql.y"
         { CONTEXT->tempOp = NOT_EQUAL; }
#line 3567 "yacc_sql.tab.c"
    break;

  case 199: /* reverseComp: EQ  */
#line 1512 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 3573 "yacc_sql.tab.c"
    break;

  case 200: /* reverseComp: LT  */
#line 1513 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3579 "yacc_sql.tab.c"
    break;

  case 201: /* reverseComp: GT  */
#line 1514 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3585 "yacc_sql.tab.c"
    break;

  case 202: /* reverseComp: LE  */
#line 1515 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3591 "yacc_sql.tab.c"
    break;

  case 203: /* reverseComp: GE  */
#line 1516 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3597 "yacc_sql.tab.c"
    break;

  case 204: /* reverseComp: NE  */
#line 1517 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3603 "yacc_sql.tab.c"
    break;

  case 205: /* comOp: EQ  */
#line 1520 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO;}
#line 3609 "yacc_sql.tab.c"
    break;

  case 206: /* comOp: LT  */
#line 1521 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3615 "yacc_sql.tab.c"
    break;

  case 207: /* comOp: GT  */
#line 1522 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3621 "yacc_sql.tab.c"
    break;

  case 208: /* comOp: LE  */
#line 1523 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3627 "yacc_sql.tab.c"
    break;

  case 209: /* comOp: GE  */
#line 1524 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3633 "yacc_sql.tab.c"
    break;

  case 210: /* comOp: NE  */
#line 1525 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3639 "yacc_sql.tab.c"
    break;

  case 211: /* comOp: LIKE  */
#line 1526 "yacc_sql.y"
               { CONTEXT->comp = LIKE_TO; }
#line 3645 "yacc_sql.tab.c"
    break;

  case 212: /* comOp: IN_T  */
#line 1527 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 3651 "yacc_sql.tab.c"
    break;

  case 213: /* comOp: NOT IN_T  */
#line 1528 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 3657 "yacc_sql.tab.c"
    break;

  case 214: /* comOp: NOT EXIST_T  */
#line 1529 "yacc_sql.y"
                     {CONTEXT->comp = NOT_EXIST;}
#line 3663 "yacc_sql.tab.c"
    break;

  case 215: /* comOp: EXIST_T  */
#line 1530 "yacc_sql.y"
                 {CONTEXT->comp = EXIST;}
#line 3669 "yacc_sql.tab.c"
    break;

  case 216: /* comOp: NOT LIKE  */
#line 1531 "yacc_sql.y"
                   { CONTEXT->comp = NOT_LIKE; }
#line 3675 "yacc_sql.tab.c"
    break;

  case 217: /* comOp: IS NOT  */
#line 1532 "yacc_sql.y"
                 { CONTEXT->comp = COMP_IS_NOT; }
#line 3681 "yacc_sql.tab.c"
    break;

  case 218: /* comOp: IS  */
#line 1533 "yacc_sql.y"
             { CONTEXT->comp = COMP_IS; }
#line 3687 "yacc_sql.tab.c"
    break;

  case 219: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1538 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3696 "yacc_sql.tab.c"
    break;


#line 3700 "yacc_sql.tab.c"

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

#line 1543 "yacc_sql.y"

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
