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
  context->ssql->sstr.selection.flag_=0;
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


#line 135 "yacc_sql.tab.c"

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
  YYSYMBOL_TRX_ROLLBACK = 27,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 28,                     /* INT_T  */
  YYSYMBOL_STRING_T = 29,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 30,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 31,                    /* DATE_T  */
  YYSYMBOL_TEXT_T = 32,                    /* TEXT_T  */
  YYSYMBOL_HELP = 33,                      /* HELP  */
  YYSYMBOL_EXIT = 34,                      /* EXIT  */
  YYSYMBOL_DOT = 35,                       /* DOT  */
  YYSYMBOL_INTO = 36,                      /* INTO  */
  YYSYMBOL_VALUES = 37,                    /* VALUES  */
  YYSYMBOL_FROM = 38,                      /* FROM  */
  YYSYMBOL_WHERE = 39,                     /* WHERE  */
  YYSYMBOL_AS = 40,                        /* AS  */
  YYSYMBOL_AND = 41,                       /* AND  */
  YYSYMBOL_SET = 42,                       /* SET  */
  YYSYMBOL_OR = 43,                        /* OR  */
  YYSYMBOL_GROUP = 44,                     /* GROUP  */
  YYSYMBOL_ON = 45,                        /* ON  */
  YYSYMBOL_INNER_T = 46,                   /* INNER_T  */
  YYSYMBOL_JOIN_T = 47,                    /* JOIN_T  */
  YYSYMBOL_LOAD = 48,                      /* LOAD  */
  YYSYMBOL_DATA = 49,                      /* DATA  */
  YYSYMBOL_INFILE = 50,                    /* INFILE  */
  YYSYMBOL_EQ = 51,                        /* EQ  */
  YYSYMBOL_LT = 52,                        /* LT  */
  YYSYMBOL_GT = 53,                        /* GT  */
  YYSYMBOL_LE = 54,                        /* LE  */
  YYSYMBOL_GE = 55,                        /* GE  */
  YYSYMBOL_NE = 56,                        /* NE  */
  YYSYMBOL_EXIST_T = 57,                   /* EXIST_T  */
  YYSYMBOL_IN_T = 58,                      /* IN_T  */
  YYSYMBOL_LIKE = 59,                      /* LIKE  */
  YYSYMBOL_NOT = 60,                       /* NOT  */
  YYSYMBOL_IS = 61,                        /* IS  */
  YYSYMBOL_NULLL = 62,                     /* NULLL  */
  YYSYMBOL_NULLABLE = 63,                  /* NULLABLE  */
  YYSYMBOL_UNIQUE = 64,                    /* UNIQUE  */
  YYSYMBOL_HAVING = 65,                    /* HAVING  */
  YYSYMBOL_ORDER = 66,                     /* ORDER  */
  YYSYMBOL_BY = 67,                        /* BY  */
  YYSYMBOL_ADD = 68,                       /* ADD  */
  YYSYMBOL_SUB = 69,                       /* SUB  */
  YYSYMBOL_DIV = 70,                       /* DIV  */
  YYSYMBOL_NUMBER = 71,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 72,                     /* FLOAT  */
  YYSYMBOL_DATEE = 73,                     /* DATEE  */
  YYSYMBOL_ID = 74,                        /* ID  */
  YYSYMBOL_PATH = 75,                      /* PATH  */
  YYSYMBOL_SSS = 76,                       /* SSS  */
  YYSYMBOL_STAR = 77,                      /* STAR  */
  YYSYMBOL_STRING_V = 78,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 79,                  /* $accept  */
  YYSYMBOL_commands = 80,                  /* commands  */
  YYSYMBOL_command = 81,                   /* command  */
  YYSYMBOL_exit = 82,                      /* exit  */
  YYSYMBOL_help = 83,                      /* help  */
  YYSYMBOL_sync = 84,                      /* sync  */
  YYSYMBOL_begin = 85,                     /* begin  */
  YYSYMBOL_commit = 86,                    /* commit  */
  YYSYMBOL_rollback = 87,                  /* rollback  */
  YYSYMBOL_drop_table = 88,                /* drop_table  */
  YYSYMBOL_show_tables = 89,               /* show_tables  */
  YYSYMBOL_show_indexes = 90,              /* show_indexes  */
  YYSYMBOL_desc_table = 91,                /* desc_table  */
  YYSYMBOL_create_index = 92,              /* create_index  */
  YYSYMBOL_index_attr_list = 93,           /* index_attr_list  */
  YYSYMBOL_index_attr = 94,                /* index_attr  */
  YYSYMBOL_drop_index = 95,                /* drop_index  */
  YYSYMBOL_create_table = 96,              /* create_table  */
  YYSYMBOL_attr_def_list = 97,             /* attr_def_list  */
  YYSYMBOL_attr_def = 98,                  /* attr_def  */
  YYSYMBOL_number = 99,                    /* number  */
  YYSYMBOL_type = 100,                     /* type  */
  YYSYMBOL_ID_get = 101,                   /* ID_get  */
  YYSYMBOL_dummy = 102,                    /* dummy  */
  YYSYMBOL_insert = 103,                   /* insert  */
  YYSYMBOL_record_list = 104,              /* record_list  */
  YYSYMBOL_record = 105,                   /* record  */
  YYSYMBOL_value_list = 106,               /* value_list  */
  YYSYMBOL_insert_value = 107,             /* insert_value  */
  YYSYMBOL_value = 108,                    /* value  */
  YYSYMBOL_delete = 109,                   /* delete  */
  YYSYMBOL_update = 110,                   /* update  */
  YYSYMBOL_update_attr_list = 111,         /* update_attr_list  */
  YYSYMBOL_update_attr = 112,              /* update_attr  */
  YYSYMBOL_update_select_attr = 113,       /* update_select_attr  */
  YYSYMBOL_update_agg = 114,               /* update_agg  */
  YYSYMBOL_having = 115,                   /* having  */
  YYSYMBOL_order_by_list = 116,            /* order_by_list  */
  YYSYMBOL_order_by_attr_list = 117,       /* order_by_attr_list  */
  YYSYMBOL_order_by_attr = 118,            /* order_by_attr  */
  YYSYMBOL_select = 119,                   /* select  */
  YYSYMBOL_by_attrs = 120,                 /* by_attrs  */
  YYSYMBOL_sub_query = 121,                /* sub_query  */
  YYSYMBOL_join_list = 122,                /* join_list  */
  YYSYMBOL_join_cons = 123,                /* join_cons  */
  YYSYMBOL_expr = 124,                     /* expr  */
  YYSYMBOL_expr_list = 125,                /* expr_list  */
  YYSYMBOL_select_attr = 126,              /* select_attr  */
  YYSYMBOL_attr_list = 127,                /* attr_list  */
  YYSYMBOL_rel_list = 128,                 /* rel_list  */
  YYSYMBOL_where = 129,                    /* where  */
  YYSYMBOL_condition_list = 130,           /* condition_list  */
  YYSYMBOL_condition = 131,                /* condition  */
  YYSYMBOL_in_cells = 132,                 /* in_cells  */
  YYSYMBOL_reverseComp = 133,              /* reverseComp  */
  YYSYMBOL_comOp = 134,                    /* comOp  */
  YYSYMBOL_load_data = 135                 /* load_data  */
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
#define YYLAST   903

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  280
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  804

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   333


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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   174,   174,   176,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   201,   206,   211,   217,   223,   229,   235,   241,
     247,   255,   262,   267,   274,   276,   280,   287,   294,   303,
     305,   309,   320,   331,   342,   353,   364,   377,   380,   381,
     382,   383,   384,   387,   394,   400,   410,   411,   416,   417,
     422,   423,   429,   434,   437,   440,   444,   448,   454,   464,
     472,   474,   478,   484,   492,   503,   508,   513,   518,   526,
     531,   536,   541,   546,   551,   556,   561,   566,   571,   576,
     583,   584,   591,   592,   594,   595,   598,   603,   608,   613,
     618,   623,   632,   646,   657,   668,   678,   690,   696,   704,
     715,   734,   753,   772,   791,   809,   827,   845,   866,   887,
     905,   924,   942,   961,   979,   997,  1018,  1040,  1059,  1078,
    1097,  1116,  1135,  1154,  1176,  1197,  1218,  1237,  1256,  1275,
    1294,  1313,  1332,  1350,  1368,  1386,  1404,  1423,  1442,  1463,
    1484,  1506,  1528,  1546,  1564,  1583,  1602,  1620,  1638,  1657,
    1676,  1694,  1712,  1730,  1748,  1769,  1790,  1812,  1834,  1853,
    1872,  1891,  1910,  1929,  1948,  1967,  1986,  2005,  2024,  2043,
    2062,  2084,  2108,  2110,  2115,  2120,  2123,  2126,  2129,  2132,
    2135,  2141,  2144,  2149,  2154,  2159,  2166,  2172,  2178,  2184,
    2189,  2194,  2199,  2204,  2209,  2215,  2223,  2231,  2239,  2247,
    2255,  2263,  2270,  2277,  2285,  2293,  2301,  2309,  2315,  2321,
    2327,  2333,  2339,  2346,  2354,  2362,  2370,  2378,  2385,  2393,
    2401,  2409,  2419,  2420,  2425,  2431,  2436,  2438,  2444,  2450,
    2458,  2465,  2471,  2478,  2487,  2489,  2492,  2496,  2501,  2503,
    2506,  2508,  2511,  2516,  2522,  2528,  2534,  2541,  2549,  2556,
    2562,  2568,  2575,  2582,  2586,  2587,  2588,  2589,  2590,  2591,
    2594,  2595,  2596,  2597,  2598,  2599,  2600,  2601,  2602,  2603,
    2607
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
  "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T", "TEXT_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AS", "AND",
  "SET", "OR", "GROUP", "ON", "INNER_T", "JOIN_T", "LOAD", "DATA",
  "INFILE", "EQ", "LT", "GT", "LE", "GE", "NE", "EXIST_T", "IN_T", "LIKE",
  "NOT", "IS", "NULLL", "NULLABLE", "UNIQUE", "HAVING", "ORDER", "BY",
  "ADD", "SUB", "DIV", "NUMBER", "FLOAT", "DATEE", "ID", "PATH", "SSS",
  "STAR", "STRING_V", "$accept", "commands", "command", "exit", "help",
  "sync", "begin", "commit", "rollback", "drop_table", "show_tables",
  "show_indexes", "desc_table", "create_index", "index_attr_list",
  "index_attr", "drop_index", "create_table", "attr_def_list", "attr_def",
  "number", "type", "ID_get", "dummy", "insert", "record_list", "record",
  "value_list", "insert_value", "value", "delete", "update",
  "update_attr_list", "update_attr", "update_select_attr", "update_agg",
  "having", "order_by_list", "order_by_attr_list", "order_by_attr",
  "select", "by_attrs", "sub_query", "join_list", "join_cons", "expr",
  "expr_list", "select_attr", "attr_list", "rel_list", "where",
  "condition_list", "condition", "in_cells", "reverseComp", "comOp",
  "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-310)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -310,   428,  -310,    31,    15,   115,   -63,   281,    12,   -11,
      71,    43,   119,   128,   150,   171,   187,   136,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -310,  -310,  -310,   175,   184,   255,
     229,   235,   208,   312,   332,   336,   352,   354,  -310,   208,
    -310,  -310,  -310,    94,  -310,   375,  -310,    29,   345,   394,
     397,   366,  -310,   353,   355,   389,  -310,  -310,  -310,  -310,
    -310,   356,   417,   390,   362,   442,   444,   -15,   -31,   376,
     378,   379,   382,   166,    81,   384,  -310,   385,  -310,   208,
     208,   208,   208,   208,  -310,   391,  -310,  -310,   393,   426,
     429,   398,   401,   399,   400,   433,  -310,  -310,  -310,    -1,
     461,     1,   243,   337,   339,   -30,  -310,  -310,    93,    29,
     166,   166,  -310,  -310,   -13,   478,   465,   139,   480,   435,
     468,   448,  -310,   470,   380,   473,   421,   -22,   423,    10,
     140,   424,   153,   425,   163,   427,   182,   430,   432,  -310,
     102,   437,   375,  -310,  -310,   438,   440,   455,   472,   429,
    -310,   208,   484,     7,   490,   452,   590,   198,  -310,   223,
     398,   429,   509,   399,   498,  -310,  -310,  -310,  -310,  -310,
     106,   445,   504,   449,  -310,   506,   454,  -310,   456,  -310,
     508,   457,  -310,   511,   459,  -310,   517,   462,  -310,   519,
    -310,    28,   375,   375,  -310,   107,   472,   464,   429,   -24,
     503,   321,   465,   537,   195,   523,   534,   528,  -310,  -310,
    -310,  -310,  -310,  -310,   529,  -310,   344,   488,   250,   139,
     139,  -310,    42,  -310,   468,   546,   476,   470,   549,   483,
     494,  -310,  -310,   538,   445,  -310,   186,  -310,  -310,   202,
    -310,   219,  -310,   260,  -310,   261,   485,   375,  -310,  -310,
    -310,   486,   472,  -310,   429,   516,   560,   500,   501,   562,
     208,   551,   484,  -310,   556,   558,   564,   566,   567,   160,
     363,   559,   534,    48,   568,  -310,  -310,     7,   321,   198,
     198,   120,  -310,  -310,   576,  -310,  -310,  -310,   569,  -310,
     445,   571,   538,   518,  -310,   520,  -310,   522,  -310,   524,
    -310,   525,  -310,   375,  -310,   472,  -310,   588,   139,  -310,
     527,   531,  -310,   503,  -310,  -310,   161,   532,   533,   539,
     541,   544,   547,   550,   555,  -310,  -310,  -310,  -310,  -310,
     586,   552,  -310,   593,   503,   605,   609,    48,   611,  -310,
    -310,   613,   615,   616,   619,   622,   612,  -310,   602,   617,
    -310,   205,   538,   650,   636,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,   610,   198,    37,   597,    90,   645,  -310,
     630,   648,   633,   634,   635,   637,    20,   108,   639,   600,
     534,  -310,  -310,  -310,  -310,  -310,   653,   657,  -310,   310,
     604,   606,   608,   614,   318,   620,   623,   625,  -310,  -310,
    -310,   681,   638,   429,  -310,   624,   627,   208,   687,  -310,
    -310,   629,   531,  -310,   632,   183,   640,   641,   643,   644,
     647,   649,   655,   651,   472,  -310,   654,   130,   673,  -310,
    -310,   340,   678,   342,   350,   358,   364,  -310,  -310,   429,
     429,  -310,  -310,   656,   696,  -310,   685,   826,  -310,   412,
     645,   689,   658,   659,   670,   691,   692,   693,   694,   131,
     686,   661,   472,  -310,   429,   132,   663,   472,  -310,  -310,
    -310,   664,  -310,  -310,   666,  -310,   668,  -310,   669,  -310,
     671,   701,   709,   702,  -310,   672,   690,   208,  -310,  -310,
    -310,   212,   264,   713,   679,   213,   224,   268,   273,   680,
     472,  -310,   683,   133,  -310,   429,  -310,   684,   472,  -310,
     472,  -310,   429,   734,   737,   742,   744,   745,  -310,  -310,
     139,   730,   321,   697,   699,   728,   703,  -310,   429,   704,
     267,   706,   708,   729,   710,   711,   732,   715,   717,   749,
     718,   720,   758,   472,  -310,   429,   135,   723,   472,  -310,
     429,  -310,   472,  -310,   429,  -310,   429,  -310,  -310,  -310,
    -310,  -310,  -310,   610,   725,   270,   762,   727,  -310,   429,
    -310,   274,   731,  -310,   429,   276,   764,   736,   277,   765,
     738,   278,   766,   739,   280,   768,   740,  -310,   429,  -310,
     741,   472,  -310,   472,  -310,   429,  -310,  -310,   429,  -310,
     429,  -310,  -310,  -310,   743,  -310,   429,   747,   285,   429,
    -310,   748,  -310,   429,  -310,   429,  -310,   750,  -310,   429,
     751,   287,   753,  -310,   429,   755,   288,   756,  -310,   429,
     757,   290,   759,  -310,   429,   761,   291,   429,  -310,   472,
    -310,   429,  -310,   429,  -310,   429,  -310,  -310,  -310,   429,
    -310,   292,   763,  -310,   429,  -310,  -310,   429,  -310,   429,
    -310,  -310,   429,  -310,   293,   767,  -310,   429,  -310,   429,
    -310,   296,   769,  -310,   429,  -310,   429,  -310,   299,   771,
    -310,   429,  -310,   429,  -310,   306,   772,  -310,   429,  -310,
    -310,   429,  -310,   429,  -310,  -310,   429,  -310,   773,  -310,
     429,  -310,   429,  -310,   429,  -310,  -310,   429,  -310,   774,
    -310,   429,  -310,   429,  -310,   429,  -310,   775,  -310,   429,
    -310,   429,  -310,   429,  -310,   776,  -310,   429,  -310,   429,
    -310,   429,  -310,   778,  -310,   429,  -310,   429,  -310,   429,
    -310,  -310,  -310,  -310,   429,  -310,   429,  -310,  -310,  -310,
    -310,   429,  -310,   429,  -310,  -310,  -310,   429,  -310,   429,
    -310,  -310,  -310,   429,  -310,   429,  -310,  -310,  -310,   429,
    -310,   429,  -310,  -310,   429,  -310,  -310,   429,  -310,  -310,
     429,  -310,  -310,   429,  -310,  -310,   429,  -310,  -310,  -310,
    -310,  -310,  -310,  -310
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    21,
      20,    15,    16,    17,    18,     9,    10,    11,    12,    13,
      14,     8,     5,     7,     6,     4,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
      63,    64,    65,   192,    66,   236,   191,   232,     0,     0,
       0,     0,    24,     0,     0,     0,    25,    26,    27,    23,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,     0,     0,   197,     0,   234,     0,
       0,     0,     0,     0,   235,     0,    31,    29,     0,     0,
     248,     0,     0,     0,     0,     0,    28,    37,   190,     0,
       0,     0,     0,     0,     0,   193,   194,   195,   236,   232,
     185,   187,   189,   188,   244,     0,    58,     0,     0,     0,
      70,     0,    53,    39,     0,     0,     0,   200,     0,   199,
     201,     0,   202,     0,   204,     0,   203,     0,     0,   198,
       0,     0,   236,   237,   233,     0,     0,     0,   244,   248,
      30,     0,    56,     0,     0,     0,     0,   250,    68,     0,
       0,   248,     0,     0,     0,    48,    51,    52,    49,    50,
      44,     0,     0,     0,   212,     0,     0,   211,     0,   213,
       0,     0,   214,     0,     0,   216,     0,     0,   215,     0,
     196,   236,   236,   236,   242,   244,   244,     0,   248,    92,
      60,    62,    58,     0,     0,     0,     0,     0,   270,   271,
     272,   273,   274,   275,     0,   276,     0,   279,     0,     0,
       0,   249,     0,    72,    70,     0,     0,    39,     0,     0,
       0,    46,    36,    34,     0,   206,   217,   205,   207,   218,
     208,   219,   210,   221,   209,   220,     0,   236,   238,   239,
     240,     0,   244,   245,   248,     0,     0,     0,     0,     0,
       0,     0,    56,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,   278,     0,   253,   250,
     250,     0,    71,    69,     0,    40,    38,    47,     0,    45,
       0,     0,    34,     0,   227,     0,   228,     0,   229,     0,
     231,     0,   230,   236,   243,   244,   247,     0,     0,   106,
       0,     0,   102,    60,    59,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,   265,   266,   267,   268,
     269,     0,   254,     0,    60,     0,     0,     0,     0,   251,
     252,     0,     0,     0,     0,     0,    76,    75,     0,     0,
     280,    41,    34,     0,     0,   222,   223,   224,   226,   225,
     241,   246,   105,   182,   250,   107,    90,    96,    94,    61,
       0,     0,     0,     0,     0,     0,     0,   244,     0,     0,
       0,   256,   255,   263,   259,   257,     0,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    35,
      32,     0,     0,   248,   184,     0,     0,     0,     0,   100,
      98,     0,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,    54,     0,   244,     0,   260,
     258,     0,     0,     0,     0,     0,     0,    77,    78,   248,
     248,    42,    33,     0,     0,   108,     0,     0,   103,    97,
      94,     0,     0,     0,     0,     0,     0,     0,     0,   244,
       0,     0,   244,    54,   248,   244,     0,   244,    54,   262,
      80,     0,    79,    82,     0,    84,     0,    88,     0,    86,
       0,     0,     0,     0,   104,     0,     0,     0,   101,    99,
      95,     0,    54,     0,     0,     0,     0,     0,     0,     0,
     244,    54,     0,   244,    54,   248,   111,     0,   244,    54,
     244,    54,   248,     0,     0,     0,     0,     0,    73,    74,
       0,     0,    91,     0,     0,     0,     0,    54,   248,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,    54,   248,   244,     0,   244,    54,
     248,   127,   244,    54,   248,    54,   248,   137,    81,    83,
      85,    89,    87,   182,     0,    54,     0,     0,    54,   248,
     112,    54,     0,    54,   248,    54,     0,     0,    54,     0,
       0,    54,     0,     0,    54,     0,     0,    54,   248,   110,
       0,   244,    54,   244,    54,   248,   119,    54,   248,   136,
     248,   169,   183,   109,     0,    54,   248,     0,    54,   248,
     128,     0,    54,   248,    54,   248,   139,     0,    54,   248,
       0,    54,     0,    54,   248,     0,    54,     0,    54,   248,
       0,    54,     0,    54,   248,     0,    54,   248,   126,   244,
      54,   248,    54,   248,   135,   248,   168,   153,    54,   248,
     113,    54,     0,    54,   248,   120,    54,   248,   138,   248,
     171,    54,   248,   114,    54,     0,    54,   248,    54,   248,
     115,    54,     0,    54,   248,    54,   248,   117,    54,     0,
      54,   248,    54,   248,   116,    54,     0,    54,   248,   118,
      54,   248,   134,   248,   167,   152,   248,   129,     0,    54,
     248,    54,   248,   141,   248,   170,   155,   248,   130,     0,
      54,   248,    54,   248,   143,   248,   131,     0,    54,   248,
      54,   248,   145,   248,   133,     0,    54,   248,    54,   248,
     149,   248,   132,     0,    54,   248,    54,   248,   147,   248,
     166,   151,   121,    54,   248,   140,   248,   173,   154,   122,
      54,   248,   142,   248,   175,   123,    54,   248,   144,   248,
     177,   125,    54,   248,   148,   248,   181,   124,    54,   248,
     146,   248,   179,   150,   248,   172,   157,   248,   174,   159,
     248,   176,   161,   248,   180,   165,   248,   178,   163,   156,
     158,   160,   164,   162
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,  -310,
    -310,  -310,  -310,  -310,  -280,  -204,  -310,  -310,   574,   595,
    -310,  -310,  -310,    98,  -310,   536,   563,  -309,  -167,  -270,
    -310,  -310,   582,   662,  -310,  -310,  -310,  -310,   359,   416,
    -310,  -310,  -212,   266,   323,    -4,   721,  -310,  -111,  -132,
    -159,  -281,  -122,   507,  -310,   402,  -310
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   301,   243,    30,    31,   174,   133,
     298,   180,   134,   474,    32,   213,   162,   271,   210,    56,
      33,    34,   171,   130,   358,   359,   418,   269,   423,   378,
      35,   376,   215,   413,   373,   166,    94,    58,    88,   159,
     128,   231,   374,   346,   341,   228,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     209,    57,   233,   108,   281,   167,   155,   153,   349,   350,
     148,    59,   235,   344,   379,    62,   214,   137,   183,   140,
     267,    40,   364,    41,    42,    63,   208,   156,    43,    44,
      45,    46,    47,   157,   138,   393,   141,    37,    77,    38,
     302,   204,   268,   109,   149,    83,   110,    87,    89,   266,
     186,   291,   184,    90,    91,    92,   415,   214,   430,    42,
     431,   158,    93,    43,    44,    45,    46,    47,   256,    48,
     343,   345,   416,   263,   264,   348,    49,   344,    50,    51,
      52,    53,   409,    54,   187,   119,   120,   121,   122,   123,
     258,   259,   260,   414,   432,    39,   362,    90,    91,    92,
     419,   420,   257,   323,    48,   317,    93,   289,   290,    64,
      48,    49,    87,    50,    51,    52,    53,    65,    54,    50,
      51,    52,    66,   239,    54,   421,   155,   155,   150,    84,
     316,    67,    42,   151,    85,   396,    43,    44,    45,    46,
      47,   351,   352,   353,   354,   355,   314,   261,   433,   155,
     155,   155,   155,    68,   155,   115,   163,   211,   116,    77,
      43,    44,    45,    46,    47,   211,   240,   152,    86,   241,
     476,   509,   517,   557,    69,   600,   201,    48,   438,   202,
     188,   262,   434,   371,    49,    71,    50,    51,    52,    53,
      70,    54,    55,   191,   356,   331,   164,   357,   332,   165,
     333,    48,   370,   194,   477,   510,   518,   558,    49,   601,
      50,    51,    52,    53,   189,    54,   274,   275,   276,   277,
     278,   462,   197,   463,   288,    42,   303,   192,    77,    43,
      44,    45,    46,    47,   334,   380,    92,   195,   381,   229,
     232,   230,   305,    93,    43,    44,    45,    46,    47,    72,
     533,   541,   534,   542,   454,   435,   198,   464,    73,   307,
     304,   142,   544,    74,   545,   407,   211,   287,   408,   279,
      48,    43,    44,    45,    46,    47,   306,    49,   143,    50,
      51,    52,    53,    77,    54,    48,   535,   543,    60,    61,
     491,   492,    49,   308,    50,    51,    52,    53,   546,    54,
     309,   311,   473,    75,   536,   478,   547,   582,   548,    76,
     614,   550,    48,   551,   621,   516,   627,   632,   637,    49,
     642,    50,    51,    52,    53,   662,    54,   675,   682,    78,
     689,   696,   708,   719,   310,   312,   727,   511,   537,   735,
     514,   583,   549,   519,   615,   521,   743,   552,   622,    79,
     628,   633,   638,    80,   643,   144,   561,   146,   480,   663,
     483,   676,   683,   567,   690,   697,   709,   720,   485,    81,
     728,    82,   145,   736,   147,   481,   487,   484,   554,   580,
     744,   559,   489,    95,   441,   486,   563,   442,   565,    90,
      91,    92,   447,   488,    87,   448,   599,    96,    93,   490,
      97,   606,   284,   285,    98,   609,   102,   611,   175,   176,
     177,   178,   179,   457,   335,   336,   337,   338,   339,   340,
     620,   597,   498,   499,   602,   626,   604,    99,     2,   100,
     607,   101,     3,     4,   103,   104,   105,     5,     6,   648,
       7,     8,     9,    10,    11,   106,   654,   107,    12,   656,
     111,   657,   112,   113,    13,    14,   114,   660,   117,   118,
     665,    15,    16,   126,   668,   124,   670,   125,   127,   650,
     673,   652,   129,   132,   135,   680,    17,   131,   136,   139,
     687,   160,   161,   168,   172,   694,   169,   170,   699,   173,
     181,   155,   702,   532,   704,   182,   705,   185,   190,   193,
     707,   196,   207,   212,   199,   713,   200,   216,   715,   217,
     716,   203,   205,   718,   206,   236,   238,   700,   724,   242,
     726,   244,   270,   245,   246,   732,   249,   734,   247,   251,
     248,   250,   740,   252,   742,   253,   254,   255,   265,   748,
     273,   280,   750,   214,   751,   282,   283,   752,   286,   293,
     294,   755,   296,   757,   297,   758,   299,   300,   759,   313,
     315,   318,   762,   319,   764,   322,   765,   320,   321,   324,
     768,   515,   770,   326,   771,   327,   522,   342,   774,   360,
     776,   328,   777,   329,   330,   347,   780,   361,   782,   363,
     783,   372,   365,   389,   366,   785,   367,   786,   368,   369,
     538,   375,   788,   390,   789,   377,   382,   383,   791,   555,
     792,   392,   560,   384,   794,   385,   795,   564,   386,   566,
     797,   387,   798,   394,   388,   799,   391,   395,   800,   398,
     399,   801,   400,   401,   802,   579,   402,   803,   584,   403,
     405,   218,   219,   220,   221,   222,   223,   404,   224,   225,
     226,   227,   598,   410,   411,   406,   412,   605,    90,    91,
      92,   608,   417,   610,   422,   424,   425,    93,   426,   427,
     428,   439,   429,   616,   437,   440,   619,   436,   443,   623,
     444,   625,   445,   629,   452,   453,   634,   451,   446,   639,
     458,   479,   644,   471,   449,   647,   482,   450,   455,   494,
     651,   456,   653,   459,   495,   655,   461,   501,   504,   505,
     506,   507,   508,   659,   465,   466,   664,   467,   468,   528,
     667,   469,   669,   470,   512,   472,   672,   529,   475,   677,
     493,   679,   502,   503,   684,   513,   686,   520,   523,   691,
     524,   693,   525,   526,   698,   527,   531,   530,   701,   285,
     703,   539,   568,   540,   553,   569,   706,   556,   562,   710,
     570,   712,   571,   572,   714,   574,   577,   587,   237,   717,
     590,   575,   721,   576,   723,   272,   725,   578,   581,   729,
     585,   731,   586,   733,   588,   589,   737,   593,   739,   591,
     741,   592,   594,   745,   595,   747,   596,   603,   749,   613,
     617,   618,   630,   635,   640,   624,   645,   754,   325,   756,
     631,   295,   636,   641,   646,   649,   292,   658,   761,   500,
     763,   661,   666,     0,   671,   674,   767,   678,   769,   681,
     685,   688,   234,   692,   773,   695,   775,   711,   460,   612,
     154,   722,   779,   730,   781,   738,   746,   753,   760,   766,
     772,   784,   778,   573,   397,     0,     0,     0,   787,   497,
       0,     0,     0,     0,   790,     0,     0,     0,     0,     0,
     793,     0,     0,     0,     0,     0,   796,   218,   219,   220,
     221,   222,   223,     0,     0,   225,   496,   227,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,     0,     0,    93
};

static const yytype_int16 yycheck[] =
{
     159,     5,   169,    18,   216,   127,    19,   118,   289,   290,
      40,    74,   171,   283,   323,     3,     9,    18,    40,    18,
      44,     6,   302,     8,    17,    36,   158,    40,    21,    22,
      23,    24,    25,    46,    35,   344,    35,     6,    42,     8,
     244,   152,    66,    74,    74,    49,    77,    19,    19,   208,
      40,     9,    74,    68,    69,    70,    19,     9,    38,    17,
      40,    74,    77,    21,    22,    23,    24,    25,    40,    62,
     282,   283,    35,   205,   206,   287,    69,   347,    71,    72,
      73,    74,   362,    76,    74,    89,    90,    91,    92,    93,
     201,   202,   203,   374,    74,    64,   300,    68,    69,    70,
      10,    11,    74,   270,    62,   264,    77,   229,   230,    38,
      62,    69,    19,    71,    72,    73,    74,    74,    76,    71,
      72,    73,     3,    17,    76,    35,    19,    19,    35,    35,
     262,     3,    17,    40,    40,   347,    21,    22,    23,    24,
      25,    21,    22,    23,    24,    25,   257,    40,    40,    19,
      19,    19,    19,     3,    19,    74,    17,   161,    77,   163,
      21,    22,    23,    24,    25,   169,    60,    74,    74,    63,
      40,    40,    40,    40,     3,    40,    74,    62,   390,    77,
      40,    74,    74,   315,    69,    49,    71,    72,    73,    74,
       3,    76,    77,    40,    74,    35,    57,    77,    38,    60,
      40,    62,   313,    40,    74,    74,    74,    74,    69,    74,
      71,    72,    73,    74,    74,    76,    21,    22,    23,    24,
      25,    38,    40,    40,   228,    17,    40,    74,   232,    21,
      22,    23,    24,    25,    74,    74,    70,    74,    77,    41,
      17,    43,    40,    77,    21,    22,    23,    24,    25,    74,
      38,    38,    40,    40,   413,   387,    74,    74,    74,    40,
      74,    18,    38,     8,    40,    60,   270,    17,    63,    74,
      62,    21,    22,    23,    24,    25,    74,    69,    35,    71,
      72,    73,    74,   287,    76,    62,    74,    74,     7,     8,
     449,   450,    69,    74,    71,    72,    73,    74,    74,    76,
      40,    40,   434,    74,    40,   437,    38,    40,    40,    74,
      40,    38,    62,    40,    40,   474,    40,    40,    40,    69,
      40,    71,    72,    73,    74,    40,    76,    40,    40,    17,
      40,    40,    40,    40,    74,    74,    40,   469,    74,    40,
     472,    74,    74,   475,    74,   477,    40,    74,    74,    17,
      74,    74,    74,    17,    74,    18,   515,    18,    18,    74,
      18,    74,    74,   522,    74,    74,    74,    74,    18,    17,
      74,    17,    35,    74,    35,    35,    18,    35,   510,   538,
      74,   513,    18,    38,    74,    35,   518,    77,   520,    68,
      69,    70,    74,    35,    19,    77,   555,     3,    77,    35,
       3,   560,    58,    59,    38,   564,    50,   566,    28,    29,
      30,    31,    32,   417,    51,    52,    53,    54,    55,    56,
     579,   553,    10,    11,   556,   584,   558,    74,     0,    74,
     562,    42,     4,     5,    17,    45,    74,     9,    10,   598,
      12,    13,    14,    15,    16,     3,   605,     3,    20,   608,
      74,   610,    74,    74,    26,    27,    74,   616,    74,    74,
     619,    33,    34,    37,   623,    74,   625,    74,    39,   601,
     629,   603,    74,    74,    74,   634,    48,    76,    45,    18,
     639,     3,    17,     3,    36,   644,    51,    19,   647,    19,
      17,    19,   651,   497,   653,    74,   655,    74,    74,    74,
     659,    74,    47,    19,    74,   664,    74,    17,   667,    57,
     669,    74,    74,   672,    74,     6,    18,   649,   677,    74,
     679,    17,    19,    74,    18,   684,    18,   686,    74,    18,
      74,    74,   691,    74,   693,    18,    74,    18,    74,   698,
       3,    18,   701,     9,   703,    17,    17,   706,    60,     3,
      74,   710,     3,   712,    71,   714,    62,    19,   717,    74,
      74,    45,   721,     3,   723,     3,   725,    67,    67,    18,
     729,   473,   731,    17,   733,    17,   478,    18,   737,     3,
     739,    17,   741,    17,    17,    17,   745,    18,   747,    18,
     749,     3,    74,    38,    74,   754,    74,   756,    74,    74,
     502,    74,   761,    17,   763,    74,    74,    74,   767,   511,
     769,    18,   514,    74,   773,    74,   775,   519,    74,   521,
     779,    74,   781,    18,    74,   784,    74,    18,   787,    18,
      17,   790,    17,    17,   793,   537,    17,   796,   540,    17,
      38,    51,    52,    53,    54,    55,    56,    35,    58,    59,
      60,    61,   554,     3,    18,    38,    46,   559,    68,    69,
      70,   563,    65,   565,    19,    35,    18,    77,    35,    35,
      35,    18,    35,   575,    74,    18,   578,    38,    74,   581,
      74,   583,    74,   585,     3,    47,   588,    62,    74,   591,
       3,    18,   594,    38,    74,   597,    18,    74,    74,     3,
     602,    74,   604,    74,    19,   607,    74,    18,    38,    18,
      18,    18,    18,   615,    74,    74,   618,    74,    74,    18,
     622,    74,   624,    74,    38,    74,   628,    18,    74,   631,
      74,   633,    74,    74,   636,    74,   638,    74,    74,   641,
      74,   643,    74,    74,   646,    74,    74,    45,   650,    59,
     652,    38,    18,    74,    74,    18,   658,    74,    74,   661,
      18,   663,    18,    18,   666,    35,    38,    38,   173,   671,
      38,    74,   674,    74,   676,   212,   678,    74,    74,   681,
      74,   683,    74,   685,    74,    74,   688,    38,   690,    74,
     692,    74,    74,   695,    74,   697,    38,    74,   700,    74,
      38,    74,    38,    38,    38,    74,    38,   709,   272,   711,
      74,   237,    74,    74,    74,    74,   234,    74,   720,   460,
     722,    74,    74,    -1,    74,    74,   728,    74,   730,    74,
      74,    74,   170,    74,   736,    74,   738,    74,   422,   573,
     119,    74,   744,    74,   746,    74,    74,    74,    74,    74,
      74,   753,    74,   530,   347,    -1,    -1,    -1,   760,   457,
      -1,    -1,    -1,    -1,   766,    -1,    -1,    -1,    -1,    -1,
     772,    -1,    -1,    -1,    -1,    -1,   778,    51,    52,    53,
      54,    55,    56,    -1,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    77
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    80,     0,     4,     5,     9,    10,    12,    13,    14,
      15,    16,    20,    26,    27,    33,    34,    48,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      95,    96,   103,   109,   110,   119,   135,     6,     8,    64,
       6,     8,    17,    21,    22,    23,    24,    25,    62,    69,
      71,    72,    73,    74,    76,    77,   108,   124,   126,    74,
       7,     8,     3,    36,    38,    74,     3,     3,     3,     3,
       3,    49,    74,    74,     8,    74,    74,   124,    17,    17,
      17,    17,    17,   124,    35,    40,    74,    19,   127,    19,
      68,    69,    70,    77,   125,    38,     3,     3,    38,    74,
      74,    42,    50,    17,    45,    74,     3,     3,    18,    74,
      77,    74,    74,    74,    74,    74,    77,    74,    74,   124,
     124,   124,   124,   124,    74,    74,    37,    39,   129,    74,
     112,    76,    74,    98,   101,    74,    45,    18,    35,    18,
      18,    35,    18,    35,    18,    35,    18,    35,    40,    74,
      35,    40,    74,   127,   125,    19,    40,    46,    74,   128,
       3,    17,   105,    17,    57,    60,   124,   131,     3,    51,
      19,   111,    36,    19,    97,    28,    29,    30,    31,    32,
     100,    17,    74,    40,    74,    74,    40,    74,    40,    74,
      74,    40,    74,    74,    40,    74,    74,    40,    74,    74,
      74,    74,    77,    74,   127,    74,    74,    47,   128,   129,
     107,   124,    19,   104,     9,   121,    17,    57,    51,    52,
      53,    54,    55,    56,    58,    59,    60,    61,   134,    41,
      43,   130,    17,   107,   112,   129,     6,    98,    18,    17,
      60,    63,    74,    94,    17,    74,    18,    74,    74,    18,
      74,    18,    74,    18,    74,    18,    40,    74,   127,   127,
     127,    40,    74,   128,   128,    74,   129,    44,    66,   116,
      19,   106,   105,     3,    21,    22,    23,    24,    25,    74,
      18,   121,    17,    17,    58,    59,    60,    17,   124,   131,
     131,     9,   111,     3,    74,    97,     3,    71,    99,    62,
      19,    93,    94,    40,    74,    40,    74,    40,    74,    40,
      74,    40,    74,    74,   127,    74,   128,   129,    45,     3,
      67,    67,     3,   107,    18,   104,    17,    17,    17,    17,
      17,    35,    38,    40,    74,    51,    52,    53,    54,    55,
      56,   133,    18,   121,   108,   121,   132,    17,   121,   130,
     130,    21,    22,    23,    24,    25,    74,    77,   113,   114,
       3,    18,    94,    18,    93,    74,    74,    74,    74,    74,
     127,   128,     3,   123,   131,    74,   120,    74,   118,   106,
      74,    77,    74,    74,    74,    74,    74,    74,    74,    38,
      17,    74,    18,   106,    18,    18,   121,   132,    18,    17,
      17,    17,    17,    17,    35,    38,    38,    60,    63,    93,
       3,    18,    46,   122,   130,    19,    35,    65,   115,    10,
      11,    35,    19,   117,    35,    18,    35,    35,    35,    35,
      38,    40,    74,    40,    74,   128,    38,    74,   121,    18,
      18,    74,    77,    74,    74,    74,    74,    74,    77,    74,
      74,    62,     3,    47,   129,    74,    74,   124,     3,    74,
     118,    74,    38,    40,    74,    74,    74,    74,    74,    74,
      74,    38,    74,   128,   102,    74,    40,    74,   128,    18,
      18,    35,    18,    18,    35,    18,    35,    18,    35,    18,
      35,   129,   129,    74,     3,    19,    60,   134,    10,    11,
     117,    18,    74,    74,    38,    18,    18,    18,    18,    40,
      74,   128,    38,    74,   128,   102,   129,    40,    74,   128,
      74,   128,   102,    74,    74,    74,    74,    74,    18,    18,
      45,    74,   124,    38,    40,    74,    40,    74,   102,    38,
      74,    38,    40,    74,    38,    40,    74,    38,    40,    74,
      38,    40,    74,    74,   128,   102,    74,    40,    74,   128,
     102,   129,    74,   128,   102,   128,   102,   129,    18,    18,
      18,    18,    18,   123,    35,    74,    74,    38,    74,   102,
     129,    74,    40,    74,   102,    74,    74,    38,    74,    74,
      38,    74,    74,    38,    74,    74,    38,   128,   102,   129,
      40,    74,   128,    74,   128,   102,   129,   128,   102,   129,
     102,   129,   122,    74,    40,    74,   102,    38,    74,   102,
     129,    40,    74,   102,    74,   102,   129,    40,    74,   102,
      38,    74,    40,    74,   102,    38,    74,    40,    74,   102,
      38,    74,    40,    74,   102,    38,    74,   102,   129,    74,
     128,   102,   128,   102,   129,   102,   129,   129,    74,   102,
     129,    74,    40,    74,   102,   129,    74,   102,   129,   102,
     129,    74,   102,   129,    74,    40,    74,   102,    74,   102,
     129,    74,    40,    74,   102,    74,   102,   129,    74,    40,
      74,   102,    74,   102,   129,    74,    40,    74,   102,   129,
     128,   102,   129,   102,   129,   129,   102,   129,    40,    74,
     102,    74,   102,   129,   102,   129,   129,   102,   129,    40,
      74,   102,    74,   102,   129,   102,   129,    40,    74,   102,
      74,   102,   129,   102,   129,    40,    74,   102,    74,   102,
     129,   102,   129,    40,    74,   102,    74,   102,   129,   102,
     129,   129,   129,    74,   102,   129,   102,   129,   129,   129,
      74,   102,   129,   102,   129,   129,    74,   102,   129,   102,
     129,   129,    74,   102,   129,   102,   129,   129,    74,   102,
     129,   102,   129,   129,   102,   129,   129,   102,   129,   129,
     102,   129,   129,   102,   129,   129,   102,   129,   129,   129,
     129,   129,   129,   129
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    92,    93,    93,    94,    95,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    99,   100,   100,
     100,   100,   100,   101,   102,   103,   104,   104,   105,   105,
     106,   106,   107,   108,   108,   108,   108,   108,   109,   110,
     111,   111,   112,   112,   112,   113,   113,   113,   113,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   118,   118,
     118,   118,   119,   119,   119,   119,   119,   120,   120,   120,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   122,   122,   123,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   126,   126,   127,   127,   127,   127,
     127,   127,   127,   127,   128,   128,   128,   128,   129,   129,
     130,   130,   130,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   132,   133,   133,   133,   133,   133,   133,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     135
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       5,     3,    10,    11,     0,     3,     1,     4,     8,     0,
       3,     5,     7,     6,     2,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     0,     7,     0,     3,     0,     4,
       0,     3,     1,     1,     1,     1,     1,     1,     5,     7,
       0,     3,     3,     9,     9,     1,     1,     3,     3,     4,
       4,     6,     4,     6,     4,     6,     4,     6,     4,     6,
       0,     4,     0,     4,     0,     3,     1,     3,     2,     4,
       2,     4,     8,    11,    12,     9,     8,     1,     3,     7,
       9,     7,     9,    11,    11,    11,    11,    11,    11,     9,
      11,    13,    13,    13,    13,    13,    10,     8,    10,    12,
      12,    12,    12,    12,    11,    10,     9,     8,    11,    10,
      13,    12,    13,    12,    13,    12,    13,    12,    13,    12,
      13,    12,    11,    10,    13,    12,    15,    14,    15,    14,
      15,    14,    15,    14,    15,    14,    12,    11,    10,     9,
      12,    11,    14,    13,    14,    13,    14,    13,    14,    13,
      14,    13,     0,     6,     2,     3,     2,     3,     3,     3,
       3,     1,     1,     3,     3,     3,     5,     2,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     6,     6,
       6,     5,     5,     5,     5,     5,     5,     6,     6,     6,
       6,     6,     8,     8,     8,     8,     8,     7,     7,     7,
       7,     7,     0,     3,     2,     2,     0,     3,     5,     5,
       5,     7,     4,     6,     0,     3,     5,     4,     0,     3,
       0,     3,     3,     3,     4,     5,     5,     5,     6,     5,
       6,     5,     7,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       8
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
#line 201 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1795 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 206 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1803 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 211 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1811 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 217 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1819 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 223 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1827 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 229 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1835 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 235 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1844 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 241 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1852 "yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 247 "yacc_sql.y"
                                {
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
    }
#line 1861 "yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 255 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1870 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 263 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
		}
#line 1879 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 268 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
		}
#line 1888 "yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA index_attr index_attr_list  */
#line 276 "yacc_sql.y"
                                           { }
#line 1894 "yacc_sql.tab.c"
    break;

  case 36: /* index_attr: ID  */
#line 281 "yacc_sql.y"
                {
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
		}
#line 1902 "yacc_sql.tab.c"
    break;

  case 37: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 288 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1911 "yacc_sql.tab.c"
    break;

  case 38: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 295 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1923 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 305 "yacc_sql.y"
                                   {    }
#line 1929 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 310 "yacc_sql.y"
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
#line 1944 "yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type LBRACE number RBRACE NOT NULLL  */
#line 321 "yacc_sql.y"
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
#line 1959 "yacc_sql.tab.c"
    break;

  case 43: /* attr_def: ID_get type LBRACE number RBRACE NULLABLE  */
#line 332 "yacc_sql.y"
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
#line 1974 "yacc_sql.tab.c"
    break;

  case 44: /* attr_def: ID_get type  */
#line 343 "yacc_sql.y"
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
#line 1989 "yacc_sql.tab.c"
    break;

  case 45: /* attr_def: ID_get type NOT NULLL  */
#line 354 "yacc_sql.y"
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
#line 2004 "yacc_sql.tab.c"
    break;

  case 46: /* attr_def: ID_get type NULLABLE  */
#line 365 "yacc_sql.y"
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
#line 2019 "yacc_sql.tab.c"
    break;

  case 47: /* number: NUMBER  */
#line 377 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 2025 "yacc_sql.tab.c"
    break;

  case 48: /* type: INT_T  */
#line 380 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 2031 "yacc_sql.tab.c"
    break;

  case 49: /* type: DATE_T  */
#line 381 "yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 2037 "yacc_sql.tab.c"
    break;

  case 50: /* type: TEXT_T  */
#line 382 "yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 2043 "yacc_sql.tab.c"
    break;

  case 51: /* type: STRING_T  */
#line 383 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 2049 "yacc_sql.tab.c"
    break;

  case 52: /* type: FLOAT_T  */
#line 384 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 2055 "yacc_sql.tab.c"
    break;

  case 53: /* ID_get: ID  */
#line 388 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 2064 "yacc_sql.tab.c"
    break;

  case 54: /* dummy: %empty  */
#line 394 "yacc_sql.y"
      {
		CONTEXT->depth++;
		CONTEXT->sub_con_start[CONTEXT->depth]=CONTEXT->condition_length;
	}
#line 2073 "yacc_sql.tab.c"
    break;

  case 55: /* insert: INSERT INTO ID VALUES record record_list SEMICOLON  */
#line 401 "yacc_sql.y"
        {
		CONTEXT->ssql->flag=SCF_INSERT;//"insert";
		CONTEXT->ssql->sstr.insertion.relation_name = (yyvsp[-4].string);
		CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
		inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-4].string), CONTEXT->values, CONTEXT->value_length,CONTEXT->single_record_length,CONTEXT->record_length);

      	CONTEXT->value_length=0;
	  	CONTEXT->record_length=0;
    }
#line 2087 "yacc_sql.tab.c"
    break;

  case 57: /* record_list: COMMA record record_list  */
#line 411 "yacc_sql.y"
                                        {

		}
#line 2095 "yacc_sql.tab.c"
    break;

  case 59: /* record: LBRACE insert_value value_list RBRACE  */
#line 418 "yacc_sql.y"
                {
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		}
#line 2104 "yacc_sql.tab.c"
    break;

  case 61: /* value_list: COMMA insert_value value_list  */
#line 423 "yacc_sql.y"
                                     { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 2112 "yacc_sql.tab.c"
    break;

  case 62: /* insert_value: expr  */
#line 429 "yacc_sql.y"
             {
		value_init_astexpr((yyvsp[0].expr1), &CONTEXT->values[CONTEXT->value_length - 1]);
	}
#line 2120 "yacc_sql.tab.c"
    break;

  case 63: /* value: NUMBER  */
#line 434 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2128 "yacc_sql.tab.c"
    break;

  case 64: /* value: FLOAT  */
#line 437 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2136 "yacc_sql.tab.c"
    break;

  case 65: /* value: DATEE  */
#line 440 "yacc_sql.y"
               {
			(yyvsp[0].dates) = substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].dates));
		}
#line 2145 "yacc_sql.tab.c"
    break;

  case 66: /* value: SSS  */
#line 444 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2154 "yacc_sql.tab.c"
    break;

  case 67: /* value: NULLL  */
#line 448 "yacc_sql.y"
               {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		}
#line 2162 "yacc_sql.tab.c"
    break;

  case 68: /* delete: DELETE FROM ID where SEMICOLON  */
#line 455 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2174 "yacc_sql.tab.c"
    break;

  case 69: /* update: UPDATE ID SET update_attr update_attr_list where SEMICOLON  */
#line 465 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2184 "yacc_sql.tab.c"
    break;

  case 72: /* update_attr: ID EQ insert_value  */
#line 479 "yacc_sql.y"
                {
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			CONTEXT->value_length = 0;
		}
#line 2194 "yacc_sql.tab.c"
    break;

  case 73: /* update_attr: ID EQ LBRACE SELECT update_select_attr FROM ID where RBRACE  */
#line 485 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2206 "yacc_sql.tab.c"
    break;

  case 74: /* update_attr: ID EQ LBRACE SELECT update_agg FROM ID where RBRACE  */
#line 493 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2218 "yacc_sql.tab.c"
    break;

  case 75: /* update_select_attr: STAR  */
#line 503 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2228 "yacc_sql.tab.c"
    break;

  case 76: /* update_select_attr: ID  */
#line 508 "yacc_sql.y"
         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2238 "yacc_sql.tab.c"
    break;

  case 77: /* update_select_attr: ID DOT ID  */
#line 513 "yacc_sql.y"
                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2248 "yacc_sql.tab.c"
    break;

  case 78: /* update_select_attr: ID DOT STAR  */
#line 518 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2258 "yacc_sql.tab.c"
    break;

  case 79: /* update_agg: COUNT_T LBRACE STAR RBRACE  */
#line 526 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
#line 2268 "yacc_sql.tab.c"
    break;

  case 80: /* update_agg: COUNT_T LBRACE ID RBRACE  */
#line 531 "yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2278 "yacc_sql.tab.c"
    break;

  case 81: /* update_agg: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 536 "yacc_sql.y"
                                          {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2288 "yacc_sql.tab.c"
    break;

  case 82: /* update_agg: MAX_T LBRACE ID RBRACE  */
#line 541 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2298 "yacc_sql.tab.c"
    break;

  case 83: /* update_agg: MAX_T LBRACE ID DOT ID RBRACE  */
#line 546 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2308 "yacc_sql.tab.c"
    break;

  case 84: /* update_agg: MIN_T LBRACE ID RBRACE  */
#line 551 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2318 "yacc_sql.tab.c"
    break;

  case 85: /* update_agg: MIN_T LBRACE ID DOT ID RBRACE  */
#line 556 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2328 "yacc_sql.tab.c"
    break;

  case 86: /* update_agg: SUM_T LBRACE ID RBRACE  */
#line 561 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2338 "yacc_sql.tab.c"
    break;

  case 87: /* update_agg: SUM_T LBRACE ID DOT ID RBRACE  */
#line 566 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2348 "yacc_sql.tab.c"
    break;

  case 88: /* update_agg: AVG_T LBRACE ID RBRACE  */
#line 571 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2358 "yacc_sql.tab.c"
    break;

  case 89: /* update_agg: AVG_T LBRACE ID DOT ID RBRACE  */
#line 576 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2368 "yacc_sql.tab.c"
    break;

  case 91: /* having: HAVING expr comOp expr  */
#line 585 "yacc_sql.y"
        {
		Condition condition;
		condition_init_from_expr(&condition, CONTEXT->comp, (yyvsp[-2].expr1), (yyvsp[0].expr1));
		selects_setup_having_condition(&CONTEXT->ssql->sstr.selection,&condition);
	}
#line 2378 "yacc_sql.tab.c"
    break;

  case 93: /* order_by_list: ORDER BY order_by_attr order_by_attr_list  */
#line 592 "yacc_sql.y"
                                                    {}
#line 2384 "yacc_sql.tab.c"
    break;

  case 95: /* order_by_attr_list: COMMA order_by_attr order_by_attr_list  */
#line 595 "yacc_sql.y"
                                                 {}
#line 2390 "yacc_sql.tab.c"
    break;

  case 96: /* order_by_attr: ID  */
#line 598 "yacc_sql.y"
           {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, ASC_T);
	}
#line 2400 "yacc_sql.tab.c"
    break;

  case 97: /* order_by_attr: ID DOT ID  */
#line 603 "yacc_sql.y"
                    {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, ASC_T);
	}
#line 2410 "yacc_sql.tab.c"
    break;

  case 98: /* order_by_attr: ID ASC  */
#line 608 "yacc_sql.y"
                 {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, ASC_T);
	}
#line 2420 "yacc_sql.tab.c"
    break;

  case 99: /* order_by_attr: ID DOT ID ASC  */
#line 613 "yacc_sql.y"
                        {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, ASC_T);
	}
#line 2430 "yacc_sql.tab.c"
    break;

  case 100: /* order_by_attr: ID DESC  */
#line 618 "yacc_sql.y"
                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, DESC_T);
	}
#line 2440 "yacc_sql.tab.c"
    break;

  case 101: /* order_by_attr: ID DOT ID DESC  */
#line 623 "yacc_sql.y"
                         {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, DESC_T);
	}
#line 2450 "yacc_sql.tab.c"
    break;

  case 102: /* select: SELECT select_attr FROM ID rel_list where order_by_list SEMICOLON  */
#line 632 "yacc_sql.y"
                                                                     {
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string));

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;//"select";

			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
	}
#line 2468 "yacc_sql.tab.c"
    break;

  case 103: /* select: SELECT select_attr FROM ID rel_list where GROUP BY by_attrs having SEMICOLON  */
#line 646 "yacc_sql.y"
                                                                                       {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-7].string));
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;

		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2483 "yacc_sql.tab.c"
    break;

  case 104: /* select: SELECT select_attr FROM ID INNER_T JOIN_T ID ON join_cons join_list where SEMICOLON  */
#line 657 "yacc_sql.y"
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
#line 2499 "yacc_sql.tab.c"
    break;

  case 105: /* select: SELECT select_attr FROM ID AS ID rel_list where SEMICOLON  */
#line 668 "yacc_sql.y"
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
#line 2514 "yacc_sql.tab.c"
    break;

  case 106: /* select: SELECT select_attr FROM ID ID rel_list where SEMICOLON  */
#line 678 "yacc_sql.y"
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
#line 2529 "yacc_sql.tab.c"
    break;

  case 107: /* by_attrs: ID  */
#line 690 "yacc_sql.y"
           {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->ssql->sstr.selection.gruop_use[0]=attr;
		CONTEXT->ssql->sstr.selection.group_num=1;
	}
#line 2540 "yacc_sql.tab.c"
    break;

  case 108: /* by_attrs: ID COMMA ID  */
#line 696 "yacc_sql.y"
                    {
		RelAttr attr1,attr2;
		relation_attr_init(&attr1, NULL, (yyvsp[-2].string));
		relation_attr_init(&attr2, NULL, (yyvsp[0].string));
		CONTEXT->ssql->sstr.selection.gruop_use[0]=attr1;
		CONTEXT->ssql->sstr.selection.gruop_use[1]=attr2;
		CONTEXT->ssql->sstr.selection.group_num=2;
	}
#line 2553 "yacc_sql.tab.c"
    break;

  case 109: /* by_attrs: ID DOT ID COMMA ID DOT ID  */
#line 704 "yacc_sql.y"
                                   {
		RelAttr attr1,attr2;
		relation_attr_init(&attr1,(yyvsp[-6].string),(yyvsp[-4].string));
		relation_attr_init(&attr2,(yyvsp[-2].string),(yyvsp[0].string));
		CONTEXT->ssql->sstr.selection.gruop_use[0]=attr1;
		CONTEXT->ssql->sstr.selection.gruop_use[1]=attr2;
		CONTEXT->ssql->sstr.selection.group_num=2;
	}
#line 2566 "yacc_sql.tab.c"
    break;

  case 110: /* sub_query: SELECT ID DOT ID FROM ID rel_list dummy where  */
#line 715 "yacc_sql.y"
                                                      {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-7].string), (yyvsp[-5].string));
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
#line 2590 "yacc_sql.tab.c"
    break;

  case 111: /* sub_query: SELECT ID FROM ID rel_list dummy where  */
#line 734 "yacc_sql.y"
                                                {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-5].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	}
#line 2614 "yacc_sql.tab.c"
    break;

  case 112: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID dummy where  */
#line 753 "yacc_sql.y"
                                                              {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
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
#line 2638 "yacc_sql.tab.c"
    break;

  case 113: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 772 "yacc_sql.y"
                                                                   {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-7].string), (yyvsp[-5].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	}
#line 2662 "yacc_sql.tab.c"
    break;

  case 114: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 791 "yacc_sql.y"
                                                                 {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-7].string), (yyvsp[-5].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	}
#line 2685 "yacc_sql.tab.c"
    break;

  case 115: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 809 "yacc_sql.y"
                                                                 {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-7].string), (yyvsp[-5].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	  }
#line 2708 "yacc_sql.tab.c"
    break;

  case 116: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 827 "yacc_sql.y"
                                                                 {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-7].string), (yyvsp[-5].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	  }
#line 2731 "yacc_sql.tab.c"
    break;

  case 117: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 845 "yacc_sql.y"
                                                                 {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);


		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-7].string), (yyvsp[-5].string));
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	  }
#line 2757 "yacc_sql.tab.c"
    break;

  case 118: /* sub_query: SELECT ID DOT ID FROM ID AS ID rel_list dummy where  */
#line 866 "yacc_sql.y"
                                                               {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-5].string));
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2783 "yacc_sql.tab.c"
    break;

  case 119: /* sub_query: SELECT ID FROM ID AS ID rel_list dummy where  */
#line 887 "yacc_sql.y"
                                                      {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-5].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		RelAttr attr;
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string));
		relation_attr_init(&attr, NULL, (yyvsp[-7].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2806 "yacc_sql.tab.c"
    break;

  case 120: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID AS ID dummy where  */
#line 905 "yacc_sql.y"
                                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2830 "yacc_sql.tab.c"
    break;

  case 121: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 924 "yacc_sql.y"
                                                                         {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2853 "yacc_sql.tab.c"
    break;

  case 122: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 942 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2877 "yacc_sql.tab.c"
    break;

  case 123: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 961 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 2900 "yacc_sql.tab.c"
    break;

  case 124: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 979 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 2923 "yacc_sql.tab.c"
    break;

  case 125: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 997 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);


		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 2949 "yacc_sql.tab.c"
    break;

  case 126: /* sub_query: SELECT ID DOT ID FROM ID ID rel_list dummy where  */
#line 1018 "yacc_sql.y"
                                                               {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);


		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

	selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-3].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2976 "yacc_sql.tab.c"
    break;

  case 127: /* sub_query: SELECT ID FROM ID ID rel_list dummy where  */
#line 1040 "yacc_sql.y"
                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		RelAttr attr;
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-3].string));
		relation_attr_init(&attr, NULL, (yyvsp[-6].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3000 "yacc_sql.tab.c"
    break;

  case 128: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID ID dummy where  */
#line 1059 "yacc_sql.y"
                                                                  {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3024 "yacc_sql.tab.c"
    break;

  case 129: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1078 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
	
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3048 "yacc_sql.tab.c"
    break;

  case 130: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1097 "yacc_sql.y"
                                                                     {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3072 "yacc_sql.tab.c"
    break;

  case 131: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1116 "yacc_sql.y"
                                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 3096 "yacc_sql.tab.c"
    break;

  case 132: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1135 "yacc_sql.y"
                                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
	
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 3120 "yacc_sql.tab.c"
    break;

  case 133: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1154 "yacc_sql.y"
                                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 3146 "yacc_sql.tab.c"
    break;

  case 134: /* sub_query: SELECT ID DOT ID AS ID FROM ID rel_list dummy where  */
#line 1176 "yacc_sql.y"
                                                         {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-9].string),(yyvsp[-7].string),(yyvsp[-5].string));

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-9].string), (yyvsp[-7].string));
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
#line 3172 "yacc_sql.tab.c"
    break;

  case 135: /* sub_query: SELECT ID DOT ID ID FROM ID rel_list dummy where  */
#line 1197 "yacc_sql.y"
                                                           {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-8].string),(yyvsp[-6].string),(yyvsp[-5].string));

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-8].string), (yyvsp[-6].string));
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
#line 3198 "yacc_sql.tab.c"
    break;

  case 136: /* sub_query: SELECT ID AS ID FROM ID rel_list dummy where  */
#line 1218 "yacc_sql.y"
                                                      {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
      selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-7].string),(yyvsp[-5].string));
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-7].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	}
#line 3222 "yacc_sql.tab.c"
    break;

  case 137: /* sub_query: SELECT ID ID FROM ID rel_list dummy where  */
#line 1237 "yacc_sql.y"
                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
      selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-6].string),(yyvsp[-5].string));
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-6].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	}
#line 3246 "yacc_sql.tab.c"
    break;

  case 138: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID dummy where  */
#line 1256 "yacc_sql.y"
                                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
        selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-4].string));
		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	}
#line 3270 "yacc_sql.tab.c"
    break;

  case 139: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID dummy where  */
#line 1275 "yacc_sql.y"
                                                                  {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
        selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-4].string));
		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	}
#line 3294 "yacc_sql.tab.c"
    break;

  case 140: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1294 "yacc_sql.y"
                                                                         {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-4].string));
		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	}
#line 3318 "yacc_sql.tab.c"
    break;

  case 141: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1313 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-4].string));
		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	}
#line 3342 "yacc_sql.tab.c"
    break;

  case 142: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1332 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-4].string));
		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	}
#line 3365 "yacc_sql.tab.c"
    break;

  case 143: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1350 "yacc_sql.y"
                                                                     {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-4].string));
		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	}
#line 3388 "yacc_sql.tab.c"
    break;

  case 144: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1368 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-4].string));
		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	  }
#line 3411 "yacc_sql.tab.c"
    break;

  case 145: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1386 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-4].string));
		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	  }
#line 3434 "yacc_sql.tab.c"
    break;

  case 146: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1404 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-4].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	  }
#line 3458 "yacc_sql.tab.c"
    break;

  case 147: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1423 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-8].string), (yyvsp[-6].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-4].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	  }
#line 3482 "yacc_sql.tab.c"
    break;

  case 148: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1442 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-9].string), (yyvsp[-7].string));
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-4].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	  }
#line 3508 "yacc_sql.tab.c"
    break;

  case 149: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1463 "yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-2].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];

		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-8].string), (yyvsp[-6].string));
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-4].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->depth--;
		CONTEXT->value_length = 0;
	  }
#line 3534 "yacc_sql.tab.c"
    break;

  case 150: /* sub_query: SELECT ID DOT ID AS ID FROM ID AS ID rel_list dummy where  */
#line 1484 "yacc_sql.y"
                                                                     {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-5].string));
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-11].string), (yyvsp[-9].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string));
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-11].string),(yyvsp[-9].string),(yyvsp[-7].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3561 "yacc_sql.tab.c"
    break;

  case 151: /* sub_query: SELECT ID DOT ID ID FROM ID AS ID rel_list dummy where  */
#line 1506 "yacc_sql.y"
                                                                  {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-7].string));
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-10].string), (yyvsp[-8].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string));
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-10].string),(yyvsp[-8].string),(yyvsp[-7].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3588 "yacc_sql.tab.c"
    break;

  case 152: /* sub_query: SELECT ID AS ID FROM ID AS ID rel_list dummy where  */
#line 1528 "yacc_sql.y"
                                                            {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-5].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		RelAttr attr;
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string));
		relation_attr_init(&attr, NULL, (yyvsp[-9].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-9].string),(yyvsp[-7].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3611 "yacc_sql.tab.c"
    break;

  case 153: /* sub_query: SELECT ID ID FROM ID AS ID rel_list dummy where  */
#line 1546 "yacc_sql.y"
                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-5].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		RelAttr attr;
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string));
		relation_attr_init(&attr, NULL, (yyvsp[-8].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-8].string),(yyvsp[-7].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3634 "yacc_sql.tab.c"
    break;

  case 154: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID AS ID dummy where  */
#line 1564 "yacc_sql.y"
                                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-6].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3658 "yacc_sql.tab.c"
    break;

  case 155: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID AS ID dummy where  */
#line 1583 "yacc_sql.y"
                                                                        {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-6].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3682 "yacc_sql.tab.c"
    break;

  case 156: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1602 "yacc_sql.y"
                                                                                {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-11].string), (yyvsp[-9].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-6].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3705 "yacc_sql.tab.c"
    break;

  case 157: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1620 "yacc_sql.y"
                                                                            {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-10].string), (yyvsp[-8].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-6].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3728 "yacc_sql.tab.c"
    break;

  case 158: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1638 "yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-11].string), (yyvsp[-9].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-6].string));

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3752 "yacc_sql.tab.c"
    break;

  case 159: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1657 "yacc_sql.y"
                                                                           {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-10].string), (yyvsp[-8].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-6].string));

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3776 "yacc_sql.tab.c"
    break;

  case 160: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1676 "yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-11].string), (yyvsp[-9].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-6].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 3799 "yacc_sql.tab.c"
    break;

  case 161: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1694 "yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-10].string), (yyvsp[-8].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-6].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 3822 "yacc_sql.tab.c"
    break;

  case 162: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1712 "yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-11].string), (yyvsp[-9].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-6].string));
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 3845 "yacc_sql.tab.c"
    break;

  case 163: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1730 "yacc_sql.y"
                                                                           {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-10].string), (yyvsp[-8].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-6].string));
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 3868 "yacc_sql.tab.c"
    break;

  case 164: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1748 "yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-11].string), (yyvsp[-9].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-6].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 3894 "yacc_sql.tab.c"
    break;

  case 165: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1769 "yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-10].string), (yyvsp[-8].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string));
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-6].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 3920 "yacc_sql.tab.c"
    break;

  case 166: /* sub_query: SELECT ID DOT ID AS ID FROM ID ID rel_list dummy where  */
#line 1790 "yacc_sql.y"
                                                                     {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-10].string), (yyvsp[-8].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-3].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-10].string),(yyvsp[-8].string),(yyvsp[-6].string));

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3947 "yacc_sql.tab.c"
    break;

  case 167: /* sub_query: SELECT ID DOT ID ID FROM ID ID rel_list dummy where  */
#line 1812 "yacc_sql.y"
                                                                 {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);

		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-3].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-9].string),(yyvsp[-7].string),(yyvsp[-6].string));

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3974 "yacc_sql.tab.c"
    break;

  case 168: /* sub_query: SELECT ID AS ID FROM ID ID rel_list dummy where  */
#line 1834 "yacc_sql.y"
                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		RelAttr attr;
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-3].string));
		relation_attr_init(&attr, NULL, (yyvsp[-8].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-8].string),(yyvsp[-6].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 3998 "yacc_sql.tab.c"
    break;

  case 169: /* sub_query: SELECT ID ID FROM ID ID rel_list dummy where  */
#line 1853 "yacc_sql.y"
                                                        {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-4].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		RelAttr attr;
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-3].string));
		relation_attr_init(&attr, NULL, (yyvsp[-7].string));
		selects_append_attribute(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-7].string),(yyvsp[-6].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 4022 "yacc_sql.tab.c"
    break;

  case 170: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID ID dummy where  */
#line 1872 "yacc_sql.y"
                                                                        {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-5].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 4046 "yacc_sql.tab.c"
    break;

  case 171: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID ID dummy where  */
#line 1891 "yacc_sql.y"
                                                                      {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-5].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 4070 "yacc_sql.tab.c"
    break;

  case 172: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 1910 "yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-10].string), (yyvsp[-8].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-5].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
	
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 4094 "yacc_sql.tab.c"
    break;

  case 173: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 1929 "yacc_sql.y"
                                                                           {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-5].string));

		CONTEXT->ssql->sstr.selection.sub_query_num++;
	
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 4118 "yacc_sql.tab.c"
    break;

  case 174: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 1948 "yacc_sql.y"
                                                                           {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-10].string), (yyvsp[-8].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-5].string));

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 4142 "yacc_sql.tab.c"
    break;

  case 175: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 1967 "yacc_sql.y"
                                                                         {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-5].string));

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 4166 "yacc_sql.tab.c"
    break;

  case 176: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 1986 "yacc_sql.y"
                                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-10].string), (yyvsp[-8].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-5].string));
		
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 4190 "yacc_sql.tab.c"
    break;

  case 177: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2005 "yacc_sql.y"
                                                                         {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-5].string));
		
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 4214 "yacc_sql.tab.c"
    break;

  case 178: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2024 "yacc_sql.y"
                                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-10].string), (yyvsp[-8].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-5].string));
	
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 4238 "yacc_sql.tab.c"
    break;

  case 179: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2043 "yacc_sql.y"
                                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);
		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-5].string));
	
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 4262 "yacc_sql.tab.c"
    break;

  case 180: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2062 "yacc_sql.y"
                                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-10].string), (yyvsp[-8].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-5].string));

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 4289 "yacc_sql.tab.c"
    break;

  case 181: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2084 "yacc_sql.y"
                                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		selects_init(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]);

		selects_append_relation(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num], (yyvsp[-3].string));
		selects_append_conditions_start(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]
		, CONTEXT->conditions, CONTEXT->sub_con_start[CONTEXT->depth],CONTEXT->condition_length);
		CONTEXT->condition_length=CONTEXT->sub_con_start[CONTEXT->depth];
		
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-9].string), (yyvsp[-7].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-2].string));
		
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		selects_append_alias3(&CONTEXT->ssql->sstr.selection, &aggre,(yyvsp[-5].string));

		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	  }
#line 4316 "yacc_sql.tab.c"
    break;

  case 183: /* join_list: INNER_T JOIN_T ID ON join_cons join_list  */
#line 2110 "yacc_sql.y"
                                               {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
	}
#line 4324 "yacc_sql.tab.c"
    break;

  case 184: /* join_cons: condition condition_list  */
#line 2115 "yacc_sql.y"
                                  {	
	}
#line 4331 "yacc_sql.tab.c"
    break;

  case 185: /* expr: expr ADD expr  */
#line 2120 "yacc_sql.y"
                      {
		(yyval.expr1) = create_astexpr(ADD_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4339 "yacc_sql.tab.c"
    break;

  case 186: /* expr: SUB expr  */
#line 2123 "yacc_sql.y"
                   {
		(yyval.expr1) = create_astexpr(SUB_OP, NULL, (yyvsp[0].expr1));
	}
#line 4347 "yacc_sql.tab.c"
    break;

  case 187: /* expr: expr SUB expr  */
#line 2126 "yacc_sql.y"
                        {
		(yyval.expr1) = create_astexpr(SUB_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4355 "yacc_sql.tab.c"
    break;

  case 188: /* expr: expr STAR expr  */
#line 2129 "yacc_sql.y"
                         {
		(yyval.expr1) = create_astexpr(MUL_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4363 "yacc_sql.tab.c"
    break;

  case 189: /* expr: expr DIV expr  */
#line 2132 "yacc_sql.y"
                        {
		(yyval.expr1) = create_astexpr(DIV_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4371 "yacc_sql.tab.c"
    break;

  case 190: /* expr: LBRACE expr RBRACE  */
#line 2135 "yacc_sql.y"
                             {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-1].expr1);
		astExpr->left_brackets ++;
		astExpr->right_brackets ++;
		(yyval.expr1) = (yyvsp[-1].expr1);
	}
#line 4382 "yacc_sql.tab.c"
    break;

  case 191: /* expr: value  */
#line 2141 "yacc_sql.y"
                {
		(yyval.expr1) = create_value_expr(&CONTEXT->values[CONTEXT->value_length - 1]);
	}
#line 4390 "yacc_sql.tab.c"
    break;

  case 192: /* expr: ID  */
#line 2144 "yacc_sql.y"
             {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4400 "yacc_sql.tab.c"
    break;

  case 193: /* expr: ID DOT ID  */
#line 2149 "yacc_sql.y"
                    {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4410 "yacc_sql.tab.c"
    break;

  case 194: /* expr: ID DOT STAR  */
#line 2154 "yacc_sql.y"
                      {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), "*");
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4420 "yacc_sql.tab.c"
    break;

  case 195: /* expr: ID AS ID  */
#line 2159 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[0].string));

		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4432 "yacc_sql.tab.c"
    break;

  case 196: /* expr: ID DOT ID AS ID  */
#line 2166 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4443 "yacc_sql.tab.c"
    break;

  case 197: /* expr: ID ID  */
#line 2172 "yacc_sql.y"
                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4454 "yacc_sql.tab.c"
    break;

  case 198: /* expr: ID DOT ID ID  */
#line 2178 "yacc_sql.y"
                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4465 "yacc_sql.tab.c"
    break;

  case 199: /* expr: COUNT_T LBRACE STAR RBRACE  */
#line 2184 "yacc_sql.y"
                                     {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4475 "yacc_sql.tab.c"
    break;

  case 200: /* expr: COUNT_T LBRACE ID RBRACE  */
#line 2189 "yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4485 "yacc_sql.tab.c"
    break;

  case 201: /* expr: MAX_T LBRACE ID RBRACE  */
#line 2194 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4495 "yacc_sql.tab.c"
    break;

  case 202: /* expr: MIN_T LBRACE ID RBRACE  */
#line 2199 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4505 "yacc_sql.tab.c"
    break;

  case 203: /* expr: SUM_T LBRACE ID RBRACE  */
#line 2204 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4515 "yacc_sql.tab.c"
    break;

  case 204: /* expr: AVG_T LBRACE ID RBRACE  */
#line 2209 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4525 "yacc_sql.tab.c"
    break;

  case 205: /* expr: COUNT_T LBRACE STAR RBRACE AS ID  */
#line 2215 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4538 "yacc_sql.tab.c"
    break;

  case 206: /* expr: COUNT_T LBRACE ID RBRACE AS ID  */
#line 2223 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4551 "yacc_sql.tab.c"
    break;

  case 207: /* expr: MAX_T LBRACE ID RBRACE AS ID  */
#line 2231 "yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4564 "yacc_sql.tab.c"
    break;

  case 208: /* expr: MIN_T LBRACE ID RBRACE AS ID  */
#line 2239 "yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4577 "yacc_sql.tab.c"
    break;

  case 209: /* expr: SUM_T LBRACE ID RBRACE AS ID  */
#line 2247 "yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4590 "yacc_sql.tab.c"
    break;

  case 210: /* expr: AVG_T LBRACE ID RBRACE AS ID  */
#line 2255 "yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4603 "yacc_sql.tab.c"
    break;

  case 211: /* expr: COUNT_T LBRACE STAR RBRACE ID  */
#line 2263 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4615 "yacc_sql.tab.c"
    break;

  case 212: /* expr: COUNT_T LBRACE ID RBRACE ID  */
#line 2270 "yacc_sql.y"
                                     {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-2].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4627 "yacc_sql.tab.c"
    break;

  case 213: /* expr: MAX_T LBRACE ID RBRACE ID  */
#line 2277 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-2].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4640 "yacc_sql.tab.c"
    break;

  case 214: /* expr: MIN_T LBRACE ID RBRACE ID  */
#line 2285 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4653 "yacc_sql.tab.c"
    break;

  case 215: /* expr: SUM_T LBRACE ID RBRACE ID  */
#line 2293 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	  }
#line 4666 "yacc_sql.tab.c"
    break;

  case 216: /* expr: AVG_T LBRACE ID RBRACE ID  */
#line 2301 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	  }
#line 4679 "yacc_sql.tab.c"
    break;

  case 217: /* expr: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 2309 "yacc_sql.y"
                                         {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4690 "yacc_sql.tab.c"
    break;

  case 218: /* expr: MAX_T LBRACE ID DOT ID RBRACE  */
#line 2315 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MAX_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4701 "yacc_sql.tab.c"
    break;

  case 219: /* expr: MIN_T LBRACE ID DOT ID RBRACE  */
#line 2321 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MIN_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4712 "yacc_sql.tab.c"
    break;

  case 220: /* expr: SUM_T LBRACE ID DOT ID RBRACE  */
#line 2327 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,SUM_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4723 "yacc_sql.tab.c"
    break;

  case 221: /* expr: AVG_T LBRACE ID DOT ID RBRACE  */
#line 2333 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,AVG_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4734 "yacc_sql.tab.c"
    break;

  case 222: /* expr: COUNT_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2339 "yacc_sql.y"
                                               {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4746 "yacc_sql.tab.c"
    break;

  case 223: /* expr: MAX_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2346 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MAX_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4759 "yacc_sql.tab.c"
    break;

  case 224: /* expr: MIN_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2354 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MIN_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4772 "yacc_sql.tab.c"
    break;

  case 225: /* expr: SUM_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2362 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,SUM_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4785 "yacc_sql.tab.c"
    break;

  case 226: /* expr: AVG_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2370 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,AVG_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4798 "yacc_sql.tab.c"
    break;

  case 227: /* expr: COUNT_T LBRACE ID DOT ID RBRACE ID  */
#line 2378 "yacc_sql.y"
                                            {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4810 "yacc_sql.tab.c"
    break;

  case 228: /* expr: MAX_T LBRACE ID DOT ID RBRACE ID  */
#line 2385 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4823 "yacc_sql.tab.c"
    break;

  case 229: /* expr: MIN_T LBRACE ID DOT ID RBRACE ID  */
#line 2393 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4836 "yacc_sql.tab.c"
    break;

  case 230: /* expr: SUM_T LBRACE ID DOT ID RBRACE ID  */
#line 2401 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4849 "yacc_sql.tab.c"
    break;

  case 231: /* expr: AVG_T LBRACE ID DOT ID RBRACE ID  */
#line 2409 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4862 "yacc_sql.tab.c"
    break;

  case 233: /* expr_list: COMMA expr expr_list  */
#line 2420 "yacc_sql.y"
                               {
		selects_append_expr(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1));
	}
#line 4870 "yacc_sql.tab.c"
    break;

  case 234: /* select_attr: STAR attr_list  */
#line 2425 "yacc_sql.y"
                   {  
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		CONTEXT->ssql->sstr.selection.need_Revere=1;
	}
#line 4881 "yacc_sql.tab.c"
    break;

  case 235: /* select_attr: expr expr_list  */
#line 2431 "yacc_sql.y"
                         {
		selects_append_expr(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1));
	}
#line 4889 "yacc_sql.tab.c"
    break;

  case 237: /* attr_list: COMMA ID attr_list  */
#line 2438 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 4900 "yacc_sql.tab.c"
    break;

  case 238: /* attr_list: COMMA ID DOT ID attr_list  */
#line 2444 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 4911 "yacc_sql.tab.c"
    break;

  case 239: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 2450 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 4922 "yacc_sql.tab.c"
    break;

  case 240: /* attr_list: COMMA ID AS ID attr_list  */
#line 2458 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-3].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 4934 "yacc_sql.tab.c"
    break;

  case 241: /* attr_list: COMMA ID DOT ID AS ID attr_list  */
#line 2465 "yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string),(yyvsp[-1].string));
		}
#line 4945 "yacc_sql.tab.c"
    break;

  case 242: /* attr_list: COMMA ID ID attr_list  */
#line 2471 "yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
	}
#line 4957 "yacc_sql.tab.c"
    break;

  case 243: /* attr_list: COMMA ID DOT ID ID attr_list  */
#line 2478 "yacc_sql.y"
                                        {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string),(yyvsp[-1].string));
		}
#line 4968 "yacc_sql.tab.c"
    break;

  case 245: /* rel_list: COMMA ID rel_list  */
#line 2489 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 4976 "yacc_sql.tab.c"
    break;

  case 246: /* rel_list: COMMA ID AS ID rel_list  */
#line 2492 "yacc_sql.y"
                                 {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 4985 "yacc_sql.tab.c"
    break;

  case 247: /* rel_list: COMMA ID ID rel_list  */
#line 2496 "yacc_sql.y"
                              {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
	}
#line 4994 "yacc_sql.tab.c"
    break;

  case 249: /* where: WHERE condition condition_list  */
#line 2503 "yacc_sql.y"
                                     {
	}
#line 5001 "yacc_sql.tab.c"
    break;

  case 251: /* condition_list: AND condition condition_list  */
#line 2508 "yacc_sql.y"
                                   {
		CONTEXT->ssql->sstr.selection.is_or=0;
	}
#line 5009 "yacc_sql.tab.c"
    break;

  case 252: /* condition_list: OR condition condition_list  */
#line 2511 "yacc_sql.y"
                                    {
		CONTEXT->ssql->sstr.selection.is_or=1;
	}
#line 5017 "yacc_sql.tab.c"
    break;

  case 253: /* condition: expr comOp expr  */
#line 2517 "yacc_sql.y"
        {
		Condition condition;
		condition_init_from_expr(&condition, CONTEXT->comp, (yyvsp[-2].expr1), (yyvsp[0].expr1));
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5027 "yacc_sql.tab.c"
    break;

  case 254: /* condition: EXIST_T LBRACE sub_query RBRACE  */
#line 2523 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 5037 "yacc_sql.tab.c"
    break;

  case 255: /* condition: NOT EXIST_T LBRACE sub_query RBRACE  */
#line 2529 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, NOT_EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 5047 "yacc_sql.tab.c"
    break;

  case 256: /* condition: LBRACE sub_query RBRACE reverseComp ID  */
#line 2534 "yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->comp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5059 "yacc_sql.tab.c"
    break;

  case 257: /* condition: expr IN_T LBRACE in_cells RBRACE  */
#line 2541 "yacc_sql.y"
                                          {
		/*TODO: 当前认为expr一定是单个attr */
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_cells_for_in(&condition,&astExpr->attr,CONTEXT->values,CONTEXT->value_length,IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5072 "yacc_sql.tab.c"
    break;

  case 258: /* condition: expr NOT IN_T LBRACE in_cells RBRACE  */
#line 2549 "yacc_sql.y"
                                              {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-5].expr1);
		Condition condition;
		condition_init_cells_for_in(&condition,&astExpr->attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5084 "yacc_sql.tab.c"
    break;

  case 259: /* condition: expr IN_T LBRACE sub_query RBRACE  */
#line 2556 "yacc_sql.y"
                                          {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_with_query(&condition, IN, &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5095 "yacc_sql.tab.c"
    break;

  case 260: /* condition: expr NOT IN_T LBRACE sub_query RBRACE  */
#line 2562 "yacc_sql.y"
                                              {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-5].expr1);
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5106 "yacc_sql.tab.c"
    break;

  case 261: /* condition: expr comOp LBRACE sub_query RBRACE  */
#line 2569 "yacc_sql.y"
        {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_with_query(&condition, (yyvsp[-3].compOp1), &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 5117 "yacc_sql.tab.c"
    break;

  case 262: /* condition: LBRACE sub_query RBRACE NE LBRACE sub_query RBRACE  */
#line 2575 "yacc_sql.y"
                                                            {
		Condition condition;
		condition_init_with_two_query(&condition, NOT_EQUAL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1],CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-2]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5127 "yacc_sql.tab.c"
    break;

  case 263: /* in_cells: value value_list  */
#line 2582 "yacc_sql.y"
                          {
	}
#line 5134 "yacc_sql.tab.c"
    break;

  case 264: /* reverseComp: EQ  */
#line 2586 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 5140 "yacc_sql.tab.c"
    break;

  case 265: /* reverseComp: LT  */
#line 2587 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 5146 "yacc_sql.tab.c"
    break;

  case 266: /* reverseComp: GT  */
#line 2588 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 5152 "yacc_sql.tab.c"
    break;

  case 267: /* reverseComp: LE  */
#line 2589 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 5158 "yacc_sql.tab.c"
    break;

  case 268: /* reverseComp: GE  */
#line 2590 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 5164 "yacc_sql.tab.c"
    break;

  case 269: /* reverseComp: NE  */
#line 2591 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 5170 "yacc_sql.tab.c"
    break;

  case 270: /* comOp: EQ  */
#line 2594 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; (yyval.compOp1) = EQUAL_TO; }
#line 5176 "yacc_sql.tab.c"
    break;

  case 271: /* comOp: LT  */
#line 2595 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; (yyval.compOp1) = LESS_THAN; }
#line 5182 "yacc_sql.tab.c"
    break;

  case 272: /* comOp: GT  */
#line 2596 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; (yyval.compOp1) = GREAT_THAN; }
#line 5188 "yacc_sql.tab.c"
    break;

  case 273: /* comOp: LE  */
#line 2597 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; (yyval.compOp1) = LESS_EQUAL; }
#line 5194 "yacc_sql.tab.c"
    break;

  case 274: /* comOp: GE  */
#line 2598 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; (yyval.compOp1) = GREAT_EQUAL; }
#line 5200 "yacc_sql.tab.c"
    break;

  case 275: /* comOp: NE  */
#line 2599 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; (yyval.compOp1) = NOT_EQUAL; }
#line 5206 "yacc_sql.tab.c"
    break;

  case 276: /* comOp: LIKE  */
#line 2600 "yacc_sql.y"
               { CONTEXT->comp = LIKE_TO; (yyval.compOp1) = LIKE_TO; }
#line 5212 "yacc_sql.tab.c"
    break;

  case 277: /* comOp: NOT LIKE  */
#line 2601 "yacc_sql.y"
                   { CONTEXT->comp = NOT_LIKE; (yyval.compOp1) = NOT_LIKE; }
#line 5218 "yacc_sql.tab.c"
    break;

  case 278: /* comOp: IS NOT  */
#line 2602 "yacc_sql.y"
                 { CONTEXT->comp = COMP_IS_NOT; (yyval.compOp1) = COMP_IS_NOT; }
#line 5224 "yacc_sql.tab.c"
    break;

  case 279: /* comOp: IS  */
#line 2603 "yacc_sql.y"
             { CONTEXT->comp = COMP_IS; (yyval.compOp1) = COMP_IS; }
#line 5230 "yacc_sql.tab.c"
    break;

  case 280: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 2608 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 5239 "yacc_sql.tab.c"
    break;


#line 5243 "yacc_sql.tab.c"

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

#line 2613 "yacc_sql.y"

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
