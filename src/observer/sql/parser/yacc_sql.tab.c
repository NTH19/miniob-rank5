/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "./src/observer/sql/parser/yacc_sql.y"


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


#line 136 "./src/observer/sql/parser/yacc_sql.tab.c"

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
  YYSYMBOL_ADD = 66,                       /* ADD  */
  YYSYMBOL_SUB = 67,                       /* SUB  */
  YYSYMBOL_DIV = 68,                       /* DIV  */
  YYSYMBOL_NUMBER = 69,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 70,                     /* FLOAT  */
  YYSYMBOL_DATEE = 71,                     /* DATEE  */
  YYSYMBOL_ID = 72,                        /* ID  */
  YYSYMBOL_PATH = 73,                      /* PATH  */
  YYSYMBOL_SSS = 74,                       /* SSS  */
  YYSYMBOL_STAR = 75,                      /* STAR  */
  YYSYMBOL_STRING_V = 76,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 77,                  /* $accept  */
  YYSYMBOL_commands = 78,                  /* commands  */
  YYSYMBOL_command = 79,                   /* command  */
  YYSYMBOL_exit = 80,                      /* exit  */
  YYSYMBOL_help = 81,                      /* help  */
  YYSYMBOL_sync = 82,                      /* sync  */
  YYSYMBOL_begin = 83,                     /* begin  */
  YYSYMBOL_commit = 84,                    /* commit  */
  YYSYMBOL_rollback = 85,                  /* rollback  */
  YYSYMBOL_drop_table = 86,                /* drop_table  */
  YYSYMBOL_show_tables = 87,               /* show_tables  */
  YYSYMBOL_show_indexes = 88,              /* show_indexes  */
  YYSYMBOL_desc_table = 89,                /* desc_table  */
  YYSYMBOL_create_index = 90,              /* create_index  */
  YYSYMBOL_index_attr_list = 91,           /* index_attr_list  */
  YYSYMBOL_index_attr = 92,                /* index_attr  */
  YYSYMBOL_drop_index = 93,                /* drop_index  */
  YYSYMBOL_create_table = 94,              /* create_table  */
  YYSYMBOL_attr_def_list = 95,             /* attr_def_list  */
  YYSYMBOL_attr_def = 96,                  /* attr_def  */
  YYSYMBOL_number = 97,                    /* number  */
  YYSYMBOL_type = 98,                      /* type  */
  YYSYMBOL_ID_get = 99,                    /* ID_get  */
  YYSYMBOL_dummy = 100,                    /* dummy  */
  YYSYMBOL_insert = 101,                   /* insert  */
  YYSYMBOL_record_list = 102,              /* record_list  */
  YYSYMBOL_record = 103,                   /* record  */
  YYSYMBOL_value_list = 104,               /* value_list  */
  YYSYMBOL_insert_value = 105,             /* insert_value  */
  YYSYMBOL_value = 106,                    /* value  */
  YYSYMBOL_delete = 107,                   /* delete  */
  YYSYMBOL_update = 108,                   /* update  */
  YYSYMBOL_update_attr_list = 109,         /* update_attr_list  */
  YYSYMBOL_update_attr = 110,              /* update_attr  */
  YYSYMBOL_update_select_attr = 111,       /* update_select_attr  */
  YYSYMBOL_update_agg = 112,               /* update_agg  */
  YYSYMBOL_select = 113,                   /* select  */
  YYSYMBOL_order_by = 114,                 /* order_by  */
  YYSYMBOL_order_item = 115,               /* order_item  */
  YYSYMBOL_order = 116,                    /* order  */
  YYSYMBOL_order_item_list = 117,          /* order_item_list  */
  YYSYMBOL_sub_query = 118,                /* sub_query  */
  YYSYMBOL_join_list = 119,                /* join_list  */
  YYSYMBOL_join_cons = 120,                /* join_cons  */
  YYSYMBOL_expr = 121,                     /* expr  */
  YYSYMBOL_expr_list = 122,                /* expr_list  */
  YYSYMBOL_select_attr = 123,              /* select_attr  */
  YYSYMBOL_attr_list = 124,                /* attr_list  */
  YYSYMBOL_rel_list = 125,                 /* rel_list  */
  YYSYMBOL_where = 126,                    /* where  */
  YYSYMBOL_condition_list = 127,           /* condition_list  */
  YYSYMBOL_condition = 128,                /* condition  */
  YYSYMBOL_in_cells = 129,                 /* in_cells  */
  YYSYMBOL_reverseComp = 130,              /* reverseComp  */
  YYSYMBOL_comOp = 131,                    /* comOp  */
  YYSYMBOL_load_data = 132                 /* load_data  */
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYLAST   871

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  273
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  783

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   331


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
      75,    76
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
     585,   598,   611,   622,   632,   643,   645,   649,   654,   662,
     665,   668,   673,   675,   681,   702,   722,   742,   762,   781,
     800,   819,   841,   864,   883,   903,   922,   942,   961,   980,
    1002,  1025,  1045,  1065,  1085,  1105,  1125,  1145,  1169,  1191,
    1213,  1233,  1253,  1273,  1293,  1313,  1333,  1352,  1371,  1390,
    1409,  1429,  1449,  1472,  1495,  1519,  1543,  1563,  1583,  1604,
    1625,  1645,  1665,  1686,  1707,  1727,  1747,  1767,  1787,  1810,
    1833,  1857,  1881,  1902,  1923,  1944,  1965,  1986,  2007,  2028,
    2049,  2070,  2091,  2112,  2133,  2157,  2183,  2185,  2190,  2195,
    2198,  2201,  2204,  2207,  2210,  2216,  2219,  2224,  2229,  2234,
    2241,  2247,  2253,  2259,  2264,  2269,  2274,  2279,  2284,  2290,
    2298,  2306,  2314,  2322,  2330,  2338,  2345,  2352,  2360,  2368,
    2376,  2384,  2390,  2396,  2402,  2408,  2414,  2421,  2429,  2437,
    2445,  2453,  2460,  2468,  2476,  2484,  2494,  2495,  2500,  2506,
    2511,  2513,  2519,  2525,  2531,  2538,  2544,  2551,  2559,  2561,
    2564,  2568,  2573,  2575,  2578,  2580,  2584,  2590,  2596,  2602,
    2609,  2617,  2624,  2630,  2636,  2643,  2650,  2654,  2655,  2656,
    2657,  2658,  2659,  2662,  2663,  2664,  2665,  2666,  2667,  2668,
    2669,  2670,  2671,  2675
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
  "NULLL", "NULLABLE", "UNIQUE", "ORDER", "BY", "ADD", "SUB", "DIV",
  "NUMBER", "FLOAT", "DATEE", "ID", "PATH", "SSS", "STAR", "STRING_V",
  "$accept", "commands", "command", "exit", "help", "sync", "begin",
  "commit", "rollback", "drop_table", "show_tables", "show_indexes",
  "desc_table", "create_index", "index_attr_list", "index_attr",
  "drop_index", "create_table", "attr_def_list", "attr_def", "number",
  "type", "ID_get", "dummy", "insert", "record_list", "record",
  "value_list", "insert_value", "value", "delete", "update",
  "update_attr_list", "update_attr", "update_select_attr", "update_agg",
  "select", "order_by", "order_item", "order", "order_item_list",
  "sub_query", "join_list", "join_cons", "expr", "expr_list",
  "select_attr", "attr_list", "rel_list", "where", "condition_list",
  "condition", "in_cells", "reverseComp", "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331
};
#endif

#define YYPACT_NINF (-303)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -303,   327,  -303,     3,   131,   119,   -65,    95,    42,   -22,
      17,    11,   108,   164,  -303,   171,   176,   214,   187,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,    87,   147,
     241,   185,   234,   181,   226,   297,   299,   339,   391,  -303,
     181,  -303,  -303,  -303,    12,  -303,   303,  -303,    81,   387,
     424,   426,   392,  -303,   360,   361,   393,  -303,  -303,  -303,
    -303,  -303,   385,   420,   395,   368,   438,   440,    47,   -56,
     377,   379,   380,   382,   -24,   -32,   383,  -303,   384,  -303,
     181,   181,   181,   181,   181,  -303,   388,  -303,  -303,   389,
     408,   410,   396,   397,   401,   403,   413,  -303,  -303,  -303,
      80,   441,   137,   142,   350,   352,   -31,  -303,  -303,   -14,
      81,   -24,   -24,  -303,  -303,     9,   459,   447,   140,   462,
     417,   450,   439,  -303,   458,   390,   463,   407,    55,   409,
     111,   146,   412,   186,   415,   191,   418,   203,   421,   422,
    -303,    97,   423,   303,  -303,  -303,   425,   427,   436,   466,
     410,  -303,   181,   470,     8,   483,   445,   570,   460,  -303,
     199,   396,   410,   498,   401,   488,  -303,  -303,  -303,  -303,
    -303,    35,   435,   491,   442,  -303,   493,   443,  -303,   444,
    -303,   495,   446,  -303,   501,   449,  -303,   505,   452,  -303,
     508,  -303,   104,   303,   303,  -303,   109,   466,   455,   410,
     464,   511,   349,   447,   529,    13,   516,   526,   520,  -303,
    -303,  -303,  -303,  -303,  -303,   521,  -303,   326,   480,   216,
     140,  -303,    38,  -303,   450,   538,   471,   458,   542,   477,
     486,  -303,  -303,   530,   435,  -303,   223,  -303,  -303,   237,
    -303,   238,  -303,   253,  -303,   258,   479,   303,  -303,  -303,
    -303,   481,   466,  -303,   410,   510,   552,   492,   556,   181,
     543,   470,  -303,   545,   546,   548,   550,   553,   -15,   589,
     551,   526,    64,   554,  -303,  -303,     8,   349,   460,    96,
    -303,  -303,   569,  -303,  -303,  -303,   558,  -303,   435,   559,
     530,   506,  -303,   509,  -303,   512,  -303,   513,  -303,   515,
    -303,   303,  -303,   466,  -303,   580,   140,  -303,   517,  -303,
     511,  -303,  -303,   120,   518,   519,   523,   524,   525,   532,
     533,   562,  -303,  -303,  -303,  -303,  -303,   576,   535,  -303,
     584,   511,   592,   595,    64,   596,  -303,   600,   602,   609,
     614,   616,   598,  -303,   607,   608,  -303,   197,   530,   645,
     632,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,   606,
     460,   369,   633,  -303,   617,   637,   620,   621,   623,   625,
     174,   110,   624,   590,   526,  -303,  -303,  -303,  -303,  -303,
     646,   647,  -303,   225,   594,   599,   601,   604,   236,   611,
     612,   613,  -303,  -303,  -303,   664,   622,   410,  -303,  -303,
    -303,   615,  -303,   517,  -303,   618,   190,   627,   628,   630,
     631,   634,   635,   639,   638,   466,  -303,   640,   112,   652,
    -303,  -303,   354,   662,   355,   374,   375,   378,  -303,  -303,
     410,   410,  -303,  -303,   641,   678,   402,   633,   668,   642,
     644,   650,   674,   675,   676,   677,   113,   658,   648,   466,
    -303,   410,   156,   651,   466,  -303,  -303,  -303,   653,  -303,
    -303,   655,  -303,   656,  -303,   660,  -303,   661,   686,   687,
     665,  -303,  -303,  -303,   195,   261,   679,   663,   233,   243,
     252,   257,   666,   466,  -303,   669,   189,  -303,   410,  -303,
     670,   466,  -303,   466,  -303,   410,   701,   704,   712,   719,
     722,  -303,  -303,   140,   672,   680,   707,   681,  -303,   410,
     683,   262,   685,   688,   708,   689,   690,   709,   691,   693,
     710,   694,   696,   711,   466,  -303,   410,   235,   698,   466,
    -303,   410,  -303,   466,  -303,   410,  -303,   410,  -303,  -303,
    -303,  -303,  -303,  -303,   606,   263,   733,   703,  -303,   410,
    -303,   272,   705,  -303,   410,   276,   734,   714,   277,   740,
     715,   278,   741,   717,   280,   743,   720,  -303,   410,  -303,
     723,   466,  -303,   466,  -303,   410,  -303,  -303,   410,  -303,
     410,  -303,  -303,   724,  -303,   410,   725,   305,   410,  -303,
     726,  -303,   410,  -303,   410,  -303,   727,  -303,   410,   728,
     310,   729,  -303,   410,   731,   317,   735,  -303,   410,   736,
     322,   737,  -303,   410,   738,   323,   410,  -303,   466,  -303,
     410,  -303,   410,  -303,   410,  -303,  -303,  -303,   410,  -303,
     325,   739,  -303,   410,  -303,  -303,   410,  -303,   410,  -303,
    -303,   410,  -303,   328,   742,  -303,   410,  -303,   410,  -303,
     330,   744,  -303,   410,  -303,   410,  -303,   334,   745,  -303,
     410,  -303,   410,  -303,   337,   746,  -303,   410,  -303,  -303,
     410,  -303,   410,  -303,  -303,   410,  -303,   747,  -303,   410,
    -303,   410,  -303,   410,  -303,  -303,   410,  -303,   748,  -303,
     410,  -303,   410,  -303,   410,  -303,   750,  -303,   410,  -303,
     410,  -303,   410,  -303,   752,  -303,   410,  -303,   410,  -303,
     410,  -303,   753,  -303,   410,  -303,   410,  -303,   410,  -303,
    -303,  -303,  -303,   410,  -303,   410,  -303,  -303,  -303,  -303,
     410,  -303,   410,  -303,  -303,  -303,   410,  -303,   410,  -303,
    -303,  -303,   410,  -303,   410,  -303,  -303,  -303,   410,  -303,
     410,  -303,  -303,   410,  -303,  -303,   410,  -303,  -303,   410,
    -303,  -303,   410,  -303,  -303,   410,  -303,  -303,  -303,  -303,
    -303,  -303,  -303
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     3,
      21,    20,    15,    16,    17,    18,     9,    10,    11,    12,
      13,    14,     8,     5,     7,     6,     4,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,    63,    64,    65,   186,    66,   230,   185,   226,     0,
       0,     0,     0,    24,     0,     0,     0,    25,    26,    27,
      23,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   180,     0,     0,   191,     0,   228,
       0,     0,     0,     0,     0,   229,     0,    31,    29,     0,
       0,   242,     0,     0,     0,     0,     0,    28,    37,   184,
       0,     0,     0,     0,     0,     0,   187,   188,   189,   230,
     226,   179,   181,   183,   182,   238,     0,    58,     0,     0,
       0,    70,     0,    53,    39,     0,     0,     0,   194,     0,
     193,   195,     0,   196,     0,   198,     0,   197,     0,     0,
     192,     0,     0,   230,   231,   227,     0,     0,     0,   238,
     242,    30,     0,    56,     0,     0,     0,     0,   244,    68,
       0,     0,   242,     0,     0,     0,    48,    51,    52,    49,
      50,    44,     0,     0,     0,   206,     0,     0,   205,     0,
     207,     0,     0,   208,     0,     0,   210,     0,     0,   209,
       0,   190,   230,   230,   230,   236,   238,   238,     0,   242,
      95,    60,    62,    58,     0,     0,     0,     0,     0,   263,
     264,   265,   266,   267,   268,     0,   269,     0,   272,     0,
       0,   243,     0,    72,    70,     0,     0,    39,     0,     0,
       0,    46,    36,    34,     0,   200,   211,   199,   201,   212,
     202,   213,   204,   215,   203,   214,     0,   230,   232,   233,
     234,     0,   238,   239,   242,     0,     0,     0,     0,     0,
       0,    56,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,   271,     0,   246,   244,     0,
      71,    69,     0,    40,    38,    47,     0,    45,     0,     0,
      34,     0,   221,     0,   222,     0,   223,     0,   225,     0,
     224,   230,   237,   238,   241,     0,     0,    94,     0,    91,
      60,    59,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   257,   258,   259,   260,   261,   262,     0,   247,
       0,    60,     0,     0,     0,     0,   245,     0,     0,     0,
       0,     0,    76,    75,     0,     0,   273,    41,    34,     0,
       0,   216,   217,   218,   220,   219,   235,   240,    93,   176,
     244,    99,   102,    61,     0,     0,     0,     0,     0,     0,
       0,   238,     0,     0,     0,   249,   248,   256,   252,   250,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    35,    32,     0,     0,   242,   178,   101,
     100,     0,    97,     0,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,    54,     0,   238,     0,
     253,   251,     0,     0,     0,     0,     0,     0,    77,    78,
     242,   242,    42,    33,     0,     0,    99,   102,     0,     0,
       0,     0,     0,     0,     0,     0,   238,     0,     0,   238,
      54,   242,   238,     0,   238,    54,   255,    80,     0,    79,
      82,     0,    84,     0,    88,     0,    86,     0,     0,     0,
       0,    92,    98,   103,     0,    54,     0,     0,     0,     0,
       0,     0,     0,   238,    54,     0,   238,    54,   242,   105,
       0,   238,    54,   238,    54,   242,     0,     0,     0,     0,
       0,    73,    74,     0,     0,     0,     0,     0,    54,   242,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,    54,   242,   238,     0,   238,
      54,   242,   121,   238,    54,   242,    54,   242,   131,    81,
      83,    85,    89,    87,   176,    54,     0,     0,    54,   242,
     106,    54,     0,    54,   242,    54,     0,     0,    54,     0,
       0,    54,     0,     0,    54,     0,     0,    54,   242,   104,
       0,   238,    54,   238,    54,   242,   113,    54,   242,   130,
     242,   163,   177,     0,    54,   242,     0,    54,   242,   122,
       0,    54,   242,    54,   242,   133,     0,    54,   242,     0,
      54,     0,    54,   242,     0,    54,     0,    54,   242,     0,
      54,     0,    54,   242,     0,    54,   242,   120,   238,    54,
     242,    54,   242,   129,   242,   162,   147,    54,   242,   107,
      54,     0,    54,   242,   114,    54,   242,   132,   242,   165,
      54,   242,   108,    54,     0,    54,   242,    54,   242,   109,
      54,     0,    54,   242,    54,   242,   111,    54,     0,    54,
     242,    54,   242,   110,    54,     0,    54,   242,   112,    54,
     242,   128,   242,   161,   146,   242,   123,     0,    54,   242,
      54,   242,   135,   242,   164,   149,   242,   124,     0,    54,
     242,    54,   242,   137,   242,   125,     0,    54,   242,    54,
     242,   139,   242,   127,     0,    54,   242,    54,   242,   143,
     242,   126,     0,    54,   242,    54,   242,   141,   242,   160,
     145,   115,    54,   242,   134,   242,   167,   148,   116,    54,
     242,   136,   242,   169,   117,    54,   242,   138,   242,   171,
     119,    54,   242,   142,   242,   175,   118,    54,   242,   140,
     242,   173,   144,   242,   166,   151,   242,   168,   153,   242,
     170,   155,   242,   174,   159,   242,   172,   157,   150,   152,
     154,   158,   156
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -294,  -224,  -303,  -303,   547,   654,
    -303,  -303,  -303,   114,  -303,   487,   578,  -302,  -168,  -268,
    -303,  -303,   560,   659,  -303,  -303,  -303,  -303,   399,   359,
     386,  -214,   273,   293,    -4,   706,  -303,  -111,  -136,  -160,
    -275,  -124,   490,  -303,  -303,  -303
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   299,   243,    31,    32,   175,   134,
     296,   181,   135,   461,    33,   214,   163,   270,   211,    57,
      34,    35,   172,   131,   354,   355,    36,   268,   372,   412,
     414,   216,   407,   369,    78,    95,    59,    89,   160,   129,
     231,   370,   343,   338,   229,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     210,    58,   233,   280,   168,    88,   360,    60,   154,    38,
     149,    39,   235,   346,   341,    64,   110,   215,   373,   111,
     300,   328,   151,   209,   329,    43,   330,   152,   156,    44,
      45,    46,    47,    48,   273,   274,   275,   276,   277,   387,
     116,   150,   205,   117,    93,    63,    84,   289,    85,   266,
     157,    94,   239,    86,   158,    43,    65,   331,   153,    44,
      45,    46,    47,    48,   403,   109,    40,   340,   342,    49,
     263,   264,   345,   215,   358,    50,   341,    51,    52,    53,
      54,   159,    55,    66,    87,   278,   120,   121,   122,   123,
     124,   258,   259,   260,   240,   408,   184,   241,   138,    49,
      90,   320,    61,    62,   315,    50,   288,    51,    52,    53,
      54,    67,    55,    91,    92,    93,   139,   347,   348,   349,
     350,   351,    94,    88,   167,    49,   314,   185,   156,   156,
     390,   156,   156,    51,    52,    53,    43,    41,    55,    42,
      44,    45,    46,    47,    48,   256,   312,    91,    92,    93,
     261,   424,   187,   463,   492,   141,    94,   164,   212,    73,
     143,    44,    45,    46,    47,    48,   212,    68,   352,   202,
     429,   353,   203,   142,    69,   156,   257,   367,   144,    70,
      49,   262,   425,   188,   464,   493,    50,   189,    51,    52,
      53,    54,   374,    55,    56,   375,   165,   500,    43,   166,
     366,    49,    44,    45,    46,    47,    48,    50,   156,    51,
      52,    53,    54,   421,    55,   422,   232,    71,   190,    74,
      44,    45,    46,    47,    48,   287,   167,   192,   501,   449,
     538,   450,   195,   286,   514,    72,   515,    44,    45,    46,
      47,    48,    49,    79,   198,   426,   423,   445,    50,    75,
      51,    52,    53,    54,   156,    55,   401,    76,   193,   402,
      49,   539,   451,   196,   301,   212,    50,   516,    51,    52,
      53,    54,   522,    55,   523,   199,   580,    49,   303,   305,
     478,   479,   525,    50,   526,    51,    52,    53,    54,   460,
      55,   528,   465,   529,   307,   302,   531,   432,   532,   309,
     433,   499,   517,   562,   593,   524,    77,   581,   438,   304,
     306,   439,   167,   600,    80,   527,    81,   606,   611,   616,
     494,   621,    88,   497,   530,   308,   502,     2,   504,   533,
     310,     3,     4,   518,   563,   594,     5,     6,   542,     7,
       8,     9,    10,    11,   601,   548,   641,    12,   607,   612,
     617,   654,   622,    13,    14,    15,    82,   535,   661,   560,
     540,    16,    17,   668,   675,   544,   687,   546,   145,   698,
     147,   706,   467,   470,    18,   714,   579,   642,   722,   409,
     410,   586,   655,   283,   284,   589,   146,   591,   148,   662,
     468,   471,   472,   474,   669,   676,   476,   688,   577,   599,
     699,   582,   707,   584,   605,   411,   715,   587,    83,   723,
     473,   475,   409,   410,   477,    91,    92,    93,   627,   176,
     177,   178,   179,   180,    94,   633,    96,    97,   635,    98,
     636,    99,   100,   101,   103,   639,   102,   104,   644,   105,
     106,   107,   647,   108,   649,   629,   127,   631,   652,   112,
     128,   113,   114,   659,   115,   118,   119,   137,   666,   140,
     125,   126,   161,   673,   162,   169,   678,   170,   130,   171,
     681,   132,   683,   133,   684,   136,   173,   174,   686,   183,
     182,   186,   208,   692,   191,   156,   694,   194,   695,   213,
     197,   697,   679,   200,   201,   204,   703,   206,   705,   207,
     217,   218,   230,   711,   236,   713,   238,   242,   244,   167,
     719,   246,   721,   249,   245,   247,   248,   727,   250,   251,
     729,   252,   730,   253,   254,   731,   255,   265,   267,   734,
     269,   736,   272,   737,   279,   215,   738,   281,   282,   285,
     741,   291,   743,   292,   744,   294,   295,   297,   747,   298,
     749,   311,   750,   313,   316,   317,   753,   318,   755,   319,
     756,   321,   323,   324,   759,   325,   761,   326,   762,   339,
     327,   344,   356,   764,   498,   765,   357,   359,   361,   505,
     767,   362,   768,   368,   363,   364,   770,   365,   771,   371,
     376,   377,   773,   384,   774,   378,   379,   380,   776,   519,
     777,   383,   386,   778,   381,   382,   779,   385,   536,   780,
     388,   541,   781,   389,   392,   782,   545,   393,   547,   394,
     219,   220,   221,   222,   223,   224,   395,   225,   226,   227,
     228,   396,   559,   397,   398,   564,    91,    92,    93,   332,
     333,   334,   335,   336,   337,    94,   399,   400,   404,   578,
     405,   406,   413,   415,   585,   416,   417,   418,   588,   419,
     590,   420,   428,   427,   430,   431,   434,   443,   444,   595,
     466,   435,   598,   436,   442,   602,   437,   604,   458,   608,
     469,   481,   613,   440,   441,   618,   484,   446,   623,   487,
     448,   626,   488,   489,   490,   491,   630,   495,   632,   452,
     453,   634,   454,   455,   511,   512,   456,   457,   638,   513,
     459,   643,   462,   480,   485,   646,   486,   648,   520,   549,
     496,   651,   550,   503,   656,   506,   658,   507,   508,   663,
     551,   665,   509,   510,   670,   521,   672,   552,   534,   677,
     553,   537,   543,   680,   555,   682,   557,   567,   570,   573,
     576,   685,   556,   558,   689,   561,   691,   565,   322,   693,
     566,   568,   569,   571,   696,   572,   574,   700,   575,   702,
     583,   704,   596,   609,   708,   597,   710,   603,   712,   614,
     619,   716,   624,   718,   293,   720,   610,   615,   724,   620,
     726,   271,   625,   728,   290,   628,   637,   640,   645,   650,
     653,   657,   733,   660,   735,   482,   554,   664,   667,   671,
     674,   690,   447,   740,   701,   742,   709,   717,   725,   732,
     739,   746,   745,   748,   751,   757,   155,   592,   237,   752,
     234,   754,     0,   483,   391,     0,     0,   758,     0,   760,
       0,     0,     0,     0,     0,     0,   763,     0,     0,     0,
       0,     0,     0,   766,     0,     0,     0,     0,     0,   769,
       0,     0,     0,     0,     0,   772,     0,     0,     0,     0,
       0,   775
};

static const yytype_int16 yycheck[] =
{
     160,     5,   170,   217,   128,    19,   300,    72,   119,     6,
      41,     8,   172,   288,   282,    37,    72,     9,   320,    75,
     244,    36,    36,   159,    39,    17,    41,    41,    19,    21,
      22,    23,    24,    25,    21,    22,    23,    24,    25,   341,
      72,    72,   153,    75,    68,     3,    50,     9,    36,   209,
      41,    75,    17,    41,    45,    17,    39,    72,    72,    21,
      22,    23,    24,    25,   358,    18,    63,   281,   282,    61,
     206,   207,   286,     9,   298,    67,   344,    69,    70,    71,
      72,    72,    74,    72,    72,    72,    90,    91,    92,    93,
      94,   202,   203,   204,    59,   370,    41,    62,    18,    61,
      19,   269,     7,     8,   264,    67,   230,    69,    70,    71,
      72,     3,    74,    66,    67,    68,    36,    21,    22,    23,
      24,    25,    75,    19,   128,    61,   262,    72,    19,    19,
     344,    19,    19,    69,    70,    71,    17,     6,    74,     8,
      21,    22,    23,    24,    25,    41,   257,    66,    67,    68,
      41,    41,    41,    41,    41,    18,    75,    17,   162,    72,
      18,    21,    22,    23,    24,    25,   170,     3,    72,    72,
     384,    75,    75,    36,     3,    19,    72,   313,    36,     3,
      61,    72,    72,    72,    72,    72,    67,    41,    69,    70,
      71,    72,    72,    74,    75,    75,    56,    41,    17,    59,
     311,    61,    21,    22,    23,    24,    25,    67,    19,    69,
      70,    71,    72,    39,    74,    41,    17,     3,    72,    72,
      21,    22,    23,    24,    25,   229,   230,    41,    72,    39,
      41,    41,    41,    17,    39,    48,    41,    21,    22,    23,
      24,    25,    61,    17,    41,   381,    72,   407,    67,     8,
      69,    70,    71,    72,    19,    74,    59,    72,    72,    62,
      61,    72,    72,    72,    41,   269,    67,    72,    69,    70,
      71,    72,    39,    74,    41,    72,    41,    61,    41,    41,
     440,   441,    39,    67,    41,    69,    70,    71,    72,   425,
      74,    39,   428,    41,    41,    72,    39,    72,    41,    41,
      75,   461,    41,    41,    41,    72,    72,    72,    72,    72,
      72,    75,   316,    41,    17,    72,    17,    41,    41,    41,
     456,    41,    19,   459,    72,    72,   462,     0,   464,    72,
      72,     4,     5,    72,    72,    72,     9,    10,   498,    12,
      13,    14,    15,    16,    72,   505,    41,    20,    72,    72,
      72,    41,    72,    26,    27,    28,    17,   493,    41,   519,
     496,    34,    35,    41,    41,   501,    41,   503,    18,    41,
      18,    41,    18,    18,    47,    41,   536,    72,    41,    10,
      11,   541,    72,    57,    58,   545,    36,   547,    36,    72,
      36,    36,    18,    18,    72,    72,    18,    72,   534,   559,
      72,   537,    72,   539,   564,    36,    72,   543,    17,    72,
      36,    36,    10,    11,    36,    66,    67,    68,   578,    29,
      30,    31,    32,    33,    75,   585,    39,     3,   588,     3,
     590,    39,    72,    72,    49,   595,    43,    17,   598,    44,
      72,     3,   602,     3,   604,   581,    38,   583,   608,    72,
      40,    72,    72,   613,    72,    72,    72,    44,   618,    18,
      72,    72,     3,   623,    17,     3,   626,    50,    72,    19,
     630,    74,   632,    72,   634,    72,    37,    19,   638,    72,
      17,    72,    46,   643,    72,    19,   646,    72,   648,    19,
      72,   651,   628,    72,    72,    72,   656,    72,   658,    72,
      17,    56,    42,   663,     6,   665,    18,    72,    17,   513,
     670,    18,   672,    18,    72,    72,    72,   677,    72,    18,
     680,    72,   682,    18,    72,   685,    18,    72,    64,   689,
      19,   691,     3,   693,    18,     9,   696,    17,    17,    59,
     700,     3,   702,    72,   704,     3,    69,    61,   708,    19,
     710,    72,   712,    72,    44,     3,   716,    65,   718,     3,
     720,    18,    17,    17,   724,    17,   726,    17,   728,    18,
      17,    17,     3,   733,   460,   735,    18,    18,    72,   465,
     740,    72,   742,     3,    72,    72,   746,    72,   748,    72,
      72,    72,   752,    17,   754,    72,    72,    72,   758,   485,
     760,    39,    18,   763,    72,    72,   766,    72,   494,   769,
      18,   497,   772,    18,    18,   775,   502,    17,   504,    17,
      50,    51,    52,    53,    54,    55,    17,    57,    58,    59,
      60,    17,   518,    17,    36,   521,    66,    67,    68,    50,
      51,    52,    53,    54,    55,    75,    39,    39,     3,   535,
      18,    45,    19,    36,   540,    18,    36,    36,   544,    36,
     546,    36,    72,    39,    18,    18,    72,     3,    46,   555,
      18,    72,   558,    72,    61,   561,    72,   563,    39,   565,
      18,     3,   568,    72,    72,   571,    18,    72,   574,    39,
      72,   577,    18,    18,    18,    18,   582,    39,   584,    72,
      72,   587,    72,    72,    18,    18,    72,    72,   594,    44,
      72,   597,    72,    72,    72,   601,    72,   603,    39,    18,
      72,   607,    18,    72,   610,    72,   612,    72,    72,   615,
      18,   617,    72,    72,   620,    72,   622,    18,    72,   625,
      18,    72,    72,   629,    72,   631,    39,    39,    39,    39,
      39,   637,    72,    72,   640,    72,   642,    72,   271,   645,
      72,    72,    72,    72,   650,    72,    72,   653,    72,   655,
      72,   657,    39,    39,   660,    72,   662,    72,   664,    39,
      39,   667,    39,   669,   237,   671,    72,    72,   674,    72,
     676,   213,    72,   679,   234,    72,    72,    72,    72,    72,
      72,    72,   688,    72,   690,   446,   513,    72,    72,    72,
      72,    72,   413,   699,    72,   701,    72,    72,    72,    72,
      72,   707,    72,   709,    72,    72,   120,   554,   174,   715,
     171,   717,    -1,   447,   344,    -1,    -1,   723,    -1,   725,
      -1,    -1,    -1,    -1,    -1,    -1,   732,    -1,    -1,    -1,
      -1,    -1,    -1,   739,    -1,    -1,    -1,    -1,    -1,   745,
      -1,    -1,    -1,    -1,    -1,   751,    -1,    -1,    -1,    -1,
      -1,   757
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    78,     0,     4,     5,     9,    10,    12,    13,    14,
      15,    16,    20,    26,    27,    28,    34,    35,    47,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    93,    94,   101,   107,   108,   113,   132,     6,     8,
      63,     6,     8,    17,    21,    22,    23,    24,    25,    61,
      67,    69,    70,    71,    72,    74,    75,   106,   121,   123,
      72,     7,     8,     3,    37,    39,    72,     3,     3,     3,
       3,     3,    48,    72,    72,     8,    72,    72,   121,    17,
      17,    17,    17,    17,   121,    36,    41,    72,    19,   124,
      19,    66,    67,    68,    75,   122,    39,     3,     3,    39,
      72,    72,    43,    49,    17,    44,    72,     3,     3,    18,
      72,    75,    72,    72,    72,    72,    72,    75,    72,    72,
     121,   121,   121,   121,   121,    72,    72,    38,    40,   126,
      72,   110,    74,    72,    96,    99,    72,    44,    18,    36,
      18,    18,    36,    18,    36,    18,    36,    18,    36,    41,
      72,    36,    41,    72,   124,   122,    19,    41,    45,    72,
     125,     3,    17,   103,    17,    56,    59,   121,   128,     3,
      50,    19,   109,    37,    19,    95,    29,    30,    31,    32,
      33,    98,    17,    72,    41,    72,    72,    41,    72,    41,
      72,    72,    41,    72,    72,    41,    72,    72,    41,    72,
      72,    72,    72,    75,    72,   124,    72,    72,    46,   125,
     126,   105,   121,    19,   102,     9,   118,    17,    56,    50,
      51,    52,    53,    54,    55,    57,    58,    59,    60,   131,
      42,   127,    17,   105,   110,   126,     6,    96,    18,    17,
      59,    62,    72,    92,    17,    72,    18,    72,    72,    18,
      72,    18,    72,    18,    72,    18,    41,    72,   124,   124,
     124,    41,    72,   125,   125,    72,   126,    64,   114,    19,
     104,   103,     3,    21,    22,    23,    24,    25,    72,    18,
     118,    17,    17,    57,    58,    59,    17,   121,   128,     9,
     109,     3,    72,    95,     3,    69,    97,    61,    19,    91,
      92,    41,    72,    41,    72,    41,    72,    41,    72,    41,
      72,    72,   124,    72,   125,   126,    44,     3,    65,     3,
     105,    18,   102,    17,    17,    17,    17,    17,    36,    39,
      41,    72,    50,    51,    52,    53,    54,    55,   130,    18,
     118,   106,   118,   129,    17,   118,   127,    21,    22,    23,
      24,    25,    72,    75,   111,   112,     3,    18,    92,    18,
      91,    72,    72,    72,    72,    72,   124,   125,     3,   120,
     128,    72,   115,   104,    72,    75,    72,    72,    72,    72,
      72,    72,    72,    39,    17,    72,    18,   104,    18,    18,
     118,   129,    18,    17,    17,    17,    17,    17,    36,    39,
      39,    59,    62,    91,     3,    18,    45,   119,   127,    10,
      11,    36,   116,    19,   117,    36,    18,    36,    36,    36,
      36,    39,    41,    72,    41,    72,   125,    39,    72,   118,
      18,    18,    72,    75,    72,    72,    72,    72,    72,    75,
      72,    72,    61,     3,    46,   126,    72,   115,    72,    39,
      41,    72,    72,    72,    72,    72,    72,    72,    39,    72,
     125,   100,    72,    41,    72,   125,    18,    18,    36,    18,
      18,    36,    18,    36,    18,    36,    18,    36,   126,   126,
      72,     3,   116,   117,    18,    72,    72,    39,    18,    18,
      18,    18,    41,    72,   125,    39,    72,   125,   100,   126,
      41,    72,   125,    72,   125,   100,    72,    72,    72,    72,
      72,    18,    18,    44,    39,    41,    72,    41,    72,   100,
      39,    72,    39,    41,    72,    39,    41,    72,    39,    41,
      72,    39,    41,    72,    72,   125,   100,    72,    41,    72,
     125,   100,   126,    72,   125,   100,   125,   100,   126,    18,
      18,    18,    18,    18,   120,    72,    72,    39,    72,   100,
     126,    72,    41,    72,   100,    72,    72,    39,    72,    72,
      39,    72,    72,    39,    72,    72,    39,   125,   100,   126,
      41,    72,   125,    72,   125,   100,   126,   125,   100,   126,
     100,   126,   119,    41,    72,   100,    39,    72,   100,   126,
      41,    72,   100,    72,   100,   126,    41,    72,   100,    39,
      72,    41,    72,   100,    39,    72,    41,    72,   100,    39,
      72,    41,    72,   100,    39,    72,   100,   126,    72,   125,
     100,   125,   100,   126,   100,   126,   126,    72,   100,   126,
      72,    41,    72,   100,   126,    72,   100,   126,   100,   126,
      72,   100,   126,    72,    41,    72,   100,    72,   100,   126,
      72,    41,    72,   100,    72,   100,   126,    72,    41,    72,
     100,    72,   100,   126,    72,    41,    72,   100,   126,   125,
     100,   126,   100,   126,   126,   100,   126,    41,    72,   100,
      72,   100,   126,   100,   126,   126,   100,   126,    41,    72,
     100,    72,   100,   126,   100,   126,    41,    72,   100,    72,
     100,   126,   100,   126,    41,    72,   100,    72,   100,   126,
     100,   126,    41,    72,   100,    72,   100,   126,   100,   126,
     126,   126,    72,   100,   126,   100,   126,   126,   126,    72,
     100,   126,   100,   126,   126,    72,   100,   126,   100,   126,
     126,    72,   100,   126,   100,   126,   126,    72,   100,   126,
     100,   126,   126,   100,   126,   126,   100,   126,   126,   100,
     126,   126,   100,   126,   126,   100,   126,   126,   126,   126,
     126,   126,   126
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    78,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    90,    91,    91,    92,    93,    94,    95,
      95,    96,    96,    96,    96,    96,    96,    97,    98,    98,
      98,    98,    98,    99,   100,   101,   102,   102,   103,   103,
     104,   104,   105,   106,   106,   106,   106,   106,   107,   108,
     109,   109,   110,   110,   110,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     113,   113,   113,   113,   113,   114,   114,   115,   115,   116,
     116,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   119,   119,   120,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   122,   122,   123,   123,
     124,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   126,   126,   127,   127,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   129,   130,   130,   130,
     130,   130,   130,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   132
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
       1,     8,    12,     9,     8,     0,     4,     2,     4,     0,
       1,     1,     0,     3,     9,     7,     9,    11,    11,    11,
      11,    11,    11,     9,    11,    13,    13,    13,    13,    13,
      10,     8,    10,    12,    12,    12,    12,    12,    11,    10,
       9,     8,    11,    10,    13,    12,    13,    12,    13,    12,
      13,    12,    13,    12,    13,    12,    11,    10,    13,    12,
      15,    14,    15,    14,    15,    14,    15,    14,    15,    14,
      12,    11,    10,     9,    12,    11,    14,    13,    14,    13,
      14,    13,    14,    13,    14,    13,     0,     6,     2,     3,
       2,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       5,     2,     4,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     6,     6,     6,     5,     5,     5,     5,     5,
       5,     6,     6,     6,     6,     6,     8,     8,     8,     8,
       8,     7,     7,     7,     7,     7,     0,     3,     2,     2,
       0,     3,     5,     5,     5,     7,     4,     6,     0,     3,
       5,     4,     0,     3,     0,     3,     3,     4,     5,     5,
       5,     6,     5,     6,     5,     7,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
#line 201 "./src/observer/sql/parser/yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1779 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 206 "./src/observer/sql/parser/yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1787 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 211 "./src/observer/sql/parser/yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1795 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 217 "./src/observer/sql/parser/yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1803 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 223 "./src/observer/sql/parser/yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1811 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 229 "./src/observer/sql/parser/yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1819 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 235 "./src/observer/sql/parser/yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1828 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 241 "./src/observer/sql/parser/yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1836 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 247 "./src/observer/sql/parser/yacc_sql.y"
                                {
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
    }
#line 1845 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 255 "./src/observer/sql/parser/yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1854 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 263 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
		}
#line 1863 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 268 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
		}
#line 1872 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA index_attr index_attr_list  */
#line 276 "./src/observer/sql/parser/yacc_sql.y"
                                           { }
#line 1878 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 36: /* index_attr: ID  */
#line 281 "./src/observer/sql/parser/yacc_sql.y"
                {
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
		}
#line 1886 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 37: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 288 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1895 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 38: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 295 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1907 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 305 "./src/observer/sql/parser/yacc_sql.y"
                                   {    }
#line 1913 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 310 "./src/observer/sql/parser/yacc_sql.y"
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
#line 1928 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type LBRACE number RBRACE NOT NULLL  */
#line 321 "./src/observer/sql/parser/yacc_sql.y"
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
#line 1943 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 43: /* attr_def: ID_get type LBRACE number RBRACE NULLABLE  */
#line 332 "./src/observer/sql/parser/yacc_sql.y"
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
#line 1958 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 44: /* attr_def: ID_get type  */
#line 343 "./src/observer/sql/parser/yacc_sql.y"
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
#line 1973 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 45: /* attr_def: ID_get type NOT NULLL  */
#line 354 "./src/observer/sql/parser/yacc_sql.y"
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
#line 1988 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 46: /* attr_def: ID_get type NULLABLE  */
#line 365 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2003 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 47: /* number: NUMBER  */
#line 377 "./src/observer/sql/parser/yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 2009 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 48: /* type: INT_T  */
#line 380 "./src/observer/sql/parser/yacc_sql.y"
              { (yyval.number)=INTS; }
#line 2015 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 49: /* type: DATE_T  */
#line 381 "./src/observer/sql/parser/yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 2021 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 50: /* type: TEXT_T  */
#line 382 "./src/observer/sql/parser/yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 2027 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 51: /* type: STRING_T  */
#line 383 "./src/observer/sql/parser/yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 2033 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 52: /* type: FLOAT_T  */
#line 384 "./src/observer/sql/parser/yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 2039 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 53: /* ID_get: ID  */
#line 388 "./src/observer/sql/parser/yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 2048 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 54: /* dummy: %empty  */
#line 394 "./src/observer/sql/parser/yacc_sql.y"
      {
		CONTEXT->depth++;
		CONTEXT->sub_con_start[CONTEXT->depth]=CONTEXT->condition_length;
	}
#line 2057 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 55: /* insert: INSERT INTO ID VALUES record record_list SEMICOLON  */
#line 401 "./src/observer/sql/parser/yacc_sql.y"
        {
		CONTEXT->ssql->flag=SCF_INSERT;//"insert";
		CONTEXT->ssql->sstr.insertion.relation_name = (yyvsp[-4].string);
		CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
		inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-4].string), CONTEXT->values, CONTEXT->value_length,CONTEXT->single_record_length,CONTEXT->record_length);

      	CONTEXT->value_length=0;
	  	CONTEXT->record_length=0;
    }
#line 2071 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 57: /* record_list: COMMA record record_list  */
#line 411 "./src/observer/sql/parser/yacc_sql.y"
                                        {

		}
#line 2079 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 59: /* record: LBRACE insert_value value_list RBRACE  */
#line 418 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		}
#line 2088 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 61: /* value_list: COMMA insert_value value_list  */
#line 423 "./src/observer/sql/parser/yacc_sql.y"
                                     { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 2096 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 62: /* insert_value: expr  */
#line 429 "./src/observer/sql/parser/yacc_sql.y"
             {
		value_init_astexpr((yyvsp[0].expr1), &CONTEXT->values[CONTEXT->value_length - 1]);
	}
#line 2104 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 63: /* value: NUMBER  */
#line 434 "./src/observer/sql/parser/yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2112 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 64: /* value: FLOAT  */
#line 437 "./src/observer/sql/parser/yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2120 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 65: /* value: DATEE  */
#line 440 "./src/observer/sql/parser/yacc_sql.y"
               {
			(yyvsp[0].dates) = substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].dates));
		}
#line 2129 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 66: /* value: SSS  */
#line 444 "./src/observer/sql/parser/yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2138 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 67: /* value: NULLL  */
#line 448 "./src/observer/sql/parser/yacc_sql.y"
               {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		}
#line 2146 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 68: /* delete: DELETE FROM ID where SEMICOLON  */
#line 455 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2158 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 69: /* update: UPDATE ID SET update_attr update_attr_list where SEMICOLON  */
#line 465 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2168 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 72: /* update_attr: ID EQ insert_value  */
#line 479 "./src/observer/sql/parser/yacc_sql.y"
                {
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			CONTEXT->value_length = 0;
		}
#line 2178 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 73: /* update_attr: ID EQ LBRACE SELECT update_select_attr FROM ID where RBRACE  */
#line 485 "./src/observer/sql/parser/yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2190 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 74: /* update_attr: ID EQ LBRACE SELECT update_agg FROM ID where RBRACE  */
#line 493 "./src/observer/sql/parser/yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2202 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 75: /* update_select_attr: STAR  */
#line 503 "./src/observer/sql/parser/yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2212 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 76: /* update_select_attr: ID  */
#line 508 "./src/observer/sql/parser/yacc_sql.y"
         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2222 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 77: /* update_select_attr: ID DOT ID  */
#line 513 "./src/observer/sql/parser/yacc_sql.y"
                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2232 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 78: /* update_select_attr: ID DOT STAR  */
#line 518 "./src/observer/sql/parser/yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2242 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 79: /* update_agg: COUNT_T LBRACE STAR RBRACE  */
#line 526 "./src/observer/sql/parser/yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
#line 2252 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 80: /* update_agg: COUNT_T LBRACE ID RBRACE  */
#line 531 "./src/observer/sql/parser/yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2262 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 81: /* update_agg: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 536 "./src/observer/sql/parser/yacc_sql.y"
                                          {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2272 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 82: /* update_agg: MAX_T LBRACE ID RBRACE  */
#line 541 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2282 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 83: /* update_agg: MAX_T LBRACE ID DOT ID RBRACE  */
#line 546 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2292 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 84: /* update_agg: MIN_T LBRACE ID RBRACE  */
#line 551 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2302 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 85: /* update_agg: MIN_T LBRACE ID DOT ID RBRACE  */
#line 556 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2312 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 86: /* update_agg: SUM_T LBRACE ID RBRACE  */
#line 561 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2322 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 87: /* update_agg: SUM_T LBRACE ID DOT ID RBRACE  */
#line 566 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2332 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 88: /* update_agg: AVG_T LBRACE ID RBRACE  */
#line 571 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2342 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 89: /* update_agg: AVG_T LBRACE ID DOT ID RBRACE  */
#line 576 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2352 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 90: /* select: DABIAO  */
#line 585 "./src/observer/sql/parser/yacc_sql.y"
              {

		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		
  		CONTEXT->condition_length = 0;
  		CONTEXT->from_length = 0;
  		CONTEXT->select_length = 0;
  		CONTEXT->value_length = 0;
  		CONTEXT->ssql->sstr.selection.is_da=1;
  		CONTEXT->ssql->sstr.selection.sub_query_num=0;
	}
#line 2369 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 91: /* select: SELECT select_attr FROM ID rel_list where order_by SEMICOLON  */
#line 598 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2387 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 92: /* select: SELECT select_attr FROM ID INNER_T JOIN_T ID ON join_cons join_list where SEMICOLON  */
#line 611 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2403 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 93: /* select: SELECT select_attr FROM ID AS ID rel_list where SEMICOLON  */
#line 622 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2418 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 94: /* select: SELECT select_attr FROM ID ID rel_list where SEMICOLON  */
#line 632 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2433 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 97: /* order_item: ID order  */
#line 649 "./src/observer/sql/parser/yacc_sql.y"
                 {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, CONTEXT->order);
	}
#line 2443 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 98: /* order_item: ID DOT ID order  */
#line 654 "./src/observer/sql/parser/yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, CONTEXT->order);
	}
#line 2453 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 99: /* order: %empty  */
#line 662 "./src/observer/sql/parser/yacc_sql.y"
                    {
		CONTEXT->order = 0;
	}
#line 2461 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 100: /* order: ASC  */
#line 665 "./src/observer/sql/parser/yacc_sql.y"
              {
		CONTEXT->order = 0;
	}
#line 2469 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 101: /* order: DESC  */
#line 668 "./src/observer/sql/parser/yacc_sql.y"
               {
		CONTEXT->order = 1;
	}
#line 2477 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 104: /* sub_query: SELECT ID DOT ID FROM ID rel_list dummy where  */
#line 681 "./src/observer/sql/parser/yacc_sql.y"
                                                      {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 2503 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 105: /* sub_query: SELECT ID FROM ID rel_list dummy where  */
#line 702 "./src/observer/sql/parser/yacc_sql.y"
                                                {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2528 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 106: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID dummy where  */
#line 722 "./src/observer/sql/parser/yacc_sql.y"
                                                              {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2553 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 107: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 742 "./src/observer/sql/parser/yacc_sql.y"
                                                                   {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2578 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 108: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 762 "./src/observer/sql/parser/yacc_sql.y"
                                                                 {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2602 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 109: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 781 "./src/observer/sql/parser/yacc_sql.y"
                                                                 {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2626 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 110: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 800 "./src/observer/sql/parser/yacc_sql.y"
                                                                 {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2650 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 111: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 819 "./src/observer/sql/parser/yacc_sql.y"
                                                                 {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 2677 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 112: /* sub_query: SELECT ID DOT ID FROM ID AS ID rel_list dummy where  */
#line 841 "./src/observer/sql/parser/yacc_sql.y"
                                                               {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 2705 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 113: /* sub_query: SELECT ID FROM ID AS ID rel_list dummy where  */
#line 864 "./src/observer/sql/parser/yacc_sql.y"
                                                      {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2729 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 114: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID AS ID dummy where  */
#line 883 "./src/observer/sql/parser/yacc_sql.y"
                                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2754 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 115: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 903 "./src/observer/sql/parser/yacc_sql.y"
                                                                         {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2778 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 116: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 922 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2803 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 117: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 942 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2827 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 118: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 961 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2851 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 119: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 980 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 2878 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 120: /* sub_query: SELECT ID DOT ID FROM ID ID rel_list dummy where  */
#line 1002 "./src/observer/sql/parser/yacc_sql.y"
                                                               {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 2906 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 121: /* sub_query: SELECT ID FROM ID ID rel_list dummy where  */
#line 1025 "./src/observer/sql/parser/yacc_sql.y"
                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2931 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 122: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID ID dummy where  */
#line 1045 "./src/observer/sql/parser/yacc_sql.y"
                                                                  {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2956 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 123: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1065 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 2981 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 124: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1085 "./src/observer/sql/parser/yacc_sql.y"
                                                                     {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3006 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 125: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1105 "./src/observer/sql/parser/yacc_sql.y"
                                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3031 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 126: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1125 "./src/observer/sql/parser/yacc_sql.y"
                                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3056 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 127: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1145 "./src/observer/sql/parser/yacc_sql.y"
                                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 3084 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 128: /* sub_query: SELECT ID DOT ID AS ID FROM ID rel_list dummy where  */
#line 1169 "./src/observer/sql/parser/yacc_sql.y"
                                                         {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3111 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 129: /* sub_query: SELECT ID DOT ID ID FROM ID rel_list dummy where  */
#line 1191 "./src/observer/sql/parser/yacc_sql.y"
                                                           {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3138 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 130: /* sub_query: SELECT ID AS ID FROM ID rel_list dummy where  */
#line 1213 "./src/observer/sql/parser/yacc_sql.y"
                                                      {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3163 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 131: /* sub_query: SELECT ID ID FROM ID rel_list dummy where  */
#line 1233 "./src/observer/sql/parser/yacc_sql.y"
                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3188 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 132: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID dummy where  */
#line 1253 "./src/observer/sql/parser/yacc_sql.y"
                                                                    {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3213 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 133: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID dummy where  */
#line 1273 "./src/observer/sql/parser/yacc_sql.y"
                                                                  {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3238 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 134: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1293 "./src/observer/sql/parser/yacc_sql.y"
                                                                         {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3263 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 135: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1313 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3288 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 136: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1333 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3312 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 137: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1352 "./src/observer/sql/parser/yacc_sql.y"
                                                                     {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3336 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 138: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1371 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3360 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 139: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1390 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3384 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 140: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1409 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3409 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 141: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1429 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3434 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 142: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1449 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 3462 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 143: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1472 "./src/observer/sql/parser/yacc_sql.y"
                                                                       {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 3490 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 144: /* sub_query: SELECT ID DOT ID AS ID FROM ID AS ID rel_list dummy where  */
#line 1495 "./src/observer/sql/parser/yacc_sql.y"
                                                                     {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 3519 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 145: /* sub_query: SELECT ID DOT ID ID FROM ID AS ID rel_list dummy where  */
#line 1519 "./src/observer/sql/parser/yacc_sql.y"
                                                                  {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 3548 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 146: /* sub_query: SELECT ID AS ID FROM ID AS ID rel_list dummy where  */
#line 1543 "./src/observer/sql/parser/yacc_sql.y"
                                                            {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3573 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 147: /* sub_query: SELECT ID ID FROM ID AS ID rel_list dummy where  */
#line 1563 "./src/observer/sql/parser/yacc_sql.y"
                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3598 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 148: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID AS ID dummy where  */
#line 1583 "./src/observer/sql/parser/yacc_sql.y"
                                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3624 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 149: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID AS ID dummy where  */
#line 1604 "./src/observer/sql/parser/yacc_sql.y"
                                                                        {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3650 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 150: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1625 "./src/observer/sql/parser/yacc_sql.y"
                                                                                {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3675 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 151: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1645 "./src/observer/sql/parser/yacc_sql.y"
                                                                            {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3700 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 152: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1665 "./src/observer/sql/parser/yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3726 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 153: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1686 "./src/observer/sql/parser/yacc_sql.y"
                                                                           {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3752 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 154: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1707 "./src/observer/sql/parser/yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3777 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 155: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1727 "./src/observer/sql/parser/yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3802 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 156: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1747 "./src/observer/sql/parser/yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3827 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 157: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1767 "./src/observer/sql/parser/yacc_sql.y"
                                                                           {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3852 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 158: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1787 "./src/observer/sql/parser/yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 3880 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 159: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1810 "./src/observer/sql/parser/yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 3908 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 160: /* sub_query: SELECT ID DOT ID AS ID FROM ID ID rel_list dummy where  */
#line 1833 "./src/observer/sql/parser/yacc_sql.y"
                                                                     {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 3937 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 161: /* sub_query: SELECT ID DOT ID ID FROM ID ID rel_list dummy where  */
#line 1857 "./src/observer/sql/parser/yacc_sql.y"
                                                                 {

		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 3966 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 162: /* sub_query: SELECT ID AS ID FROM ID ID rel_list dummy where  */
#line 1881 "./src/observer/sql/parser/yacc_sql.y"
                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 3992 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 163: /* sub_query: SELECT ID ID FROM ID ID rel_list dummy where  */
#line 1902 "./src/observer/sql/parser/yacc_sql.y"
                                                        {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 4018 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 164: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID ID dummy where  */
#line 1923 "./src/observer/sql/parser/yacc_sql.y"
                                                                        {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 4044 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 165: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID ID dummy where  */
#line 1944 "./src/observer/sql/parser/yacc_sql.y"
                                                                      {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 4070 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 166: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 1965 "./src/observer/sql/parser/yacc_sql.y"
                                                                             {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 4096 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 167: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 1986 "./src/observer/sql/parser/yacc_sql.y"
                                                                           {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 4122 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 168: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2007 "./src/observer/sql/parser/yacc_sql.y"
                                                                           {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 4148 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 169: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2028 "./src/observer/sql/parser/yacc_sql.y"
                                                                         {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 4174 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 170: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2049 "./src/observer/sql/parser/yacc_sql.y"
                                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 4200 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 171: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2070 "./src/observer/sql/parser/yacc_sql.y"
                                                                         {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 4226 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 172: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2091 "./src/observer/sql/parser/yacc_sql.y"
                                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 4252 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 173: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2112 "./src/observer/sql/parser/yacc_sql.y"
                                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;
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
#line 4278 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 174: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2133 "./src/observer/sql/parser/yacc_sql.y"
                                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 4307 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 175: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2157 "./src/observer/sql/parser/yacc_sql.y"
                                                                          {
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]=malloc(sizeof(Selects));
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->relation_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->aggfun_num=0;
		CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num]->attr_num=0;

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
#line 4336 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 177: /* join_list: INNER_T JOIN_T ID ON join_cons join_list  */
#line 2185 "./src/observer/sql/parser/yacc_sql.y"
                                               {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
	}
#line 4344 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 178: /* join_cons: condition condition_list  */
#line 2190 "./src/observer/sql/parser/yacc_sql.y"
                                  {	
	}
#line 4351 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 179: /* expr: expr ADD expr  */
#line 2195 "./src/observer/sql/parser/yacc_sql.y"
                      {
		(yyval.expr1) = create_astexpr(ADD_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4359 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 180: /* expr: SUB expr  */
#line 2198 "./src/observer/sql/parser/yacc_sql.y"
                   {
		(yyval.expr1) = create_astexpr(SUB_OP, NULL, (yyvsp[0].expr1));
	}
#line 4367 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 181: /* expr: expr SUB expr  */
#line 2201 "./src/observer/sql/parser/yacc_sql.y"
                        {
		(yyval.expr1) = create_astexpr(SUB_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4375 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 182: /* expr: expr STAR expr  */
#line 2204 "./src/observer/sql/parser/yacc_sql.y"
                         {
		(yyval.expr1) = create_astexpr(MUL_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4383 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 183: /* expr: expr DIV expr  */
#line 2207 "./src/observer/sql/parser/yacc_sql.y"
                        {
		(yyval.expr1) = create_astexpr(DIV_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4391 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 184: /* expr: LBRACE expr RBRACE  */
#line 2210 "./src/observer/sql/parser/yacc_sql.y"
                             {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-1].expr1);
		astExpr->left_brackets ++;
		astExpr->right_brackets ++;
		(yyval.expr1) = (yyvsp[-1].expr1);
	}
#line 4402 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 185: /* expr: value  */
#line 2216 "./src/observer/sql/parser/yacc_sql.y"
                {
		(yyval.expr1) = create_value_expr(&CONTEXT->values[CONTEXT->value_length - 1]);
	}
#line 4410 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 186: /* expr: ID  */
#line 2219 "./src/observer/sql/parser/yacc_sql.y"
             {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4420 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 187: /* expr: ID DOT ID  */
#line 2224 "./src/observer/sql/parser/yacc_sql.y"
                    {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4430 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 188: /* expr: ID DOT STAR  */
#line 2229 "./src/observer/sql/parser/yacc_sql.y"
                      {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), "*");
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4440 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 189: /* expr: ID AS ID  */
#line 2234 "./src/observer/sql/parser/yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[0].string));

		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4452 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 190: /* expr: ID DOT ID AS ID  */
#line 2241 "./src/observer/sql/parser/yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4463 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 191: /* expr: ID ID  */
#line 2247 "./src/observer/sql/parser/yacc_sql.y"
                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4474 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 192: /* expr: ID DOT ID ID  */
#line 2253 "./src/observer/sql/parser/yacc_sql.y"
                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4485 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 193: /* expr: COUNT_T LBRACE STAR RBRACE  */
#line 2259 "./src/observer/sql/parser/yacc_sql.y"
                                     {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4495 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 194: /* expr: COUNT_T LBRACE ID RBRACE  */
#line 2264 "./src/observer/sql/parser/yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4505 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 195: /* expr: MAX_T LBRACE ID RBRACE  */
#line 2269 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4515 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 196: /* expr: MIN_T LBRACE ID RBRACE  */
#line 2274 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4525 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 197: /* expr: SUM_T LBRACE ID RBRACE  */
#line 2279 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4535 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 198: /* expr: AVG_T LBRACE ID RBRACE  */
#line 2284 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4545 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 199: /* expr: COUNT_T LBRACE STAR RBRACE AS ID  */
#line 2290 "./src/observer/sql/parser/yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4558 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 200: /* expr: COUNT_T LBRACE ID RBRACE AS ID  */
#line 2298 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4571 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 201: /* expr: MAX_T LBRACE ID RBRACE AS ID  */
#line 2306 "./src/observer/sql/parser/yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4584 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 202: /* expr: MIN_T LBRACE ID RBRACE AS ID  */
#line 2314 "./src/observer/sql/parser/yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4597 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 203: /* expr: SUM_T LBRACE ID RBRACE AS ID  */
#line 2322 "./src/observer/sql/parser/yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4610 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 204: /* expr: AVG_T LBRACE ID RBRACE AS ID  */
#line 2330 "./src/observer/sql/parser/yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4623 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 205: /* expr: COUNT_T LBRACE STAR RBRACE ID  */
#line 2338 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4635 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 206: /* expr: COUNT_T LBRACE ID RBRACE ID  */
#line 2345 "./src/observer/sql/parser/yacc_sql.y"
                                     {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-2].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4647 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 207: /* expr: MAX_T LBRACE ID RBRACE ID  */
#line 2352 "./src/observer/sql/parser/yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-2].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4660 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 208: /* expr: MIN_T LBRACE ID RBRACE ID  */
#line 2360 "./src/observer/sql/parser/yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4673 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 209: /* expr: SUM_T LBRACE ID RBRACE ID  */
#line 2368 "./src/observer/sql/parser/yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	  }
#line 4686 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 210: /* expr: AVG_T LBRACE ID RBRACE ID  */
#line 2376 "./src/observer/sql/parser/yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	  }
#line 4699 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 211: /* expr: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 2384 "./src/observer/sql/parser/yacc_sql.y"
                                         {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4710 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 212: /* expr: MAX_T LBRACE ID DOT ID RBRACE  */
#line 2390 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MAX_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4721 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 213: /* expr: MIN_T LBRACE ID DOT ID RBRACE  */
#line 2396 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MIN_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4732 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 214: /* expr: SUM_T LBRACE ID DOT ID RBRACE  */
#line 2402 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,SUM_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4743 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 215: /* expr: AVG_T LBRACE ID DOT ID RBRACE  */
#line 2408 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,AVG_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4754 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 216: /* expr: COUNT_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2414 "./src/observer/sql/parser/yacc_sql.y"
                                               {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4766 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 217: /* expr: MAX_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2421 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MAX_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4779 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 218: /* expr: MIN_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2429 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MIN_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4792 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 219: /* expr: SUM_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2437 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,SUM_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4805 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 220: /* expr: AVG_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2445 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,AVG_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4818 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 221: /* expr: COUNT_T LBRACE ID DOT ID RBRACE ID  */
#line 2453 "./src/observer/sql/parser/yacc_sql.y"
                                            {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4830 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 222: /* expr: MAX_T LBRACE ID DOT ID RBRACE ID  */
#line 2460 "./src/observer/sql/parser/yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4843 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 223: /* expr: MIN_T LBRACE ID DOT ID RBRACE ID  */
#line 2468 "./src/observer/sql/parser/yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4856 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 224: /* expr: SUM_T LBRACE ID DOT ID RBRACE ID  */
#line 2476 "./src/observer/sql/parser/yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4869 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 225: /* expr: AVG_T LBRACE ID DOT ID RBRACE ID  */
#line 2484 "./src/observer/sql/parser/yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4882 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 227: /* expr_list: COMMA expr expr_list  */
#line 2495 "./src/observer/sql/parser/yacc_sql.y"
                               {
		selects_append_expr(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1));
	}
#line 4890 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 228: /* select_attr: STAR attr_list  */
#line 2500 "./src/observer/sql/parser/yacc_sql.y"
                   {  
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		CONTEXT->ssql->sstr.selection.need_Revere=1;
	}
#line 4901 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 229: /* select_attr: expr expr_list  */
#line 2506 "./src/observer/sql/parser/yacc_sql.y"
                         {
		selects_append_expr(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1));
	}
#line 4909 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 231: /* attr_list: COMMA ID attr_list  */
#line 2513 "./src/observer/sql/parser/yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 4920 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 232: /* attr_list: COMMA ID DOT ID attr_list  */
#line 2519 "./src/observer/sql/parser/yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 4931 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 233: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 2525 "./src/observer/sql/parser/yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 4942 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 234: /* attr_list: COMMA ID AS ID attr_list  */
#line 2531 "./src/observer/sql/parser/yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-3].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 4954 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 235: /* attr_list: COMMA ID DOT ID AS ID attr_list  */
#line 2538 "./src/observer/sql/parser/yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string),(yyvsp[-1].string));
		}
#line 4965 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 236: /* attr_list: COMMA ID ID attr_list  */
#line 2544 "./src/observer/sql/parser/yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
	}
#line 4977 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 237: /* attr_list: COMMA ID DOT ID ID attr_list  */
#line 2551 "./src/observer/sql/parser/yacc_sql.y"
                                        {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string),(yyvsp[-1].string));
		}
#line 4988 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 239: /* rel_list: COMMA ID rel_list  */
#line 2561 "./src/observer/sql/parser/yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 4996 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 240: /* rel_list: COMMA ID AS ID rel_list  */
#line 2564 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 5005 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 241: /* rel_list: COMMA ID ID rel_list  */
#line 2568 "./src/observer/sql/parser/yacc_sql.y"
                              {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
	}
#line 5014 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 243: /* where: WHERE condition condition_list  */
#line 2575 "./src/observer/sql/parser/yacc_sql.y"
                                     {
	}
#line 5021 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 245: /* condition_list: AND condition condition_list  */
#line 2580 "./src/observer/sql/parser/yacc_sql.y"
                                   {
			}
#line 5028 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 246: /* condition: expr comOp expr  */
#line 2585 "./src/observer/sql/parser/yacc_sql.y"
        {
		Condition condition;
		condition_init_from_expr(&condition, CONTEXT->comp, (yyvsp[-2].expr1), (yyvsp[0].expr1));
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5038 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 247: /* condition: EXIST_T LBRACE sub_query RBRACE  */
#line 2591 "./src/observer/sql/parser/yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 5048 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 248: /* condition: NOT EXIST_T LBRACE sub_query RBRACE  */
#line 2597 "./src/observer/sql/parser/yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, NOT_EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 5058 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 249: /* condition: LBRACE sub_query RBRACE reverseComp ID  */
#line 2602 "./src/observer/sql/parser/yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->comp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5070 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 250: /* condition: expr IN_T LBRACE in_cells RBRACE  */
#line 2609 "./src/observer/sql/parser/yacc_sql.y"
                                          {
		/*TODO: 当前认为expr一定是单个attr */
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_cells_for_in(&condition,&astExpr->attr,CONTEXT->values,CONTEXT->value_length,IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5083 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 251: /* condition: expr NOT IN_T LBRACE in_cells RBRACE  */
#line 2617 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-5].expr1);
		Condition condition;
		condition_init_cells_for_in(&condition,&astExpr->attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5095 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 252: /* condition: expr IN_T LBRACE sub_query RBRACE  */
#line 2624 "./src/observer/sql/parser/yacc_sql.y"
                                          {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_with_query(&condition, IN, &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5106 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 253: /* condition: expr NOT IN_T LBRACE sub_query RBRACE  */
#line 2630 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-5].expr1);
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5117 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 254: /* condition: expr comOp LBRACE sub_query RBRACE  */
#line 2637 "./src/observer/sql/parser/yacc_sql.y"
        {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_with_query(&condition, (yyvsp[-3].compOp1), &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 5128 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 255: /* condition: LBRACE sub_query RBRACE NE LBRACE sub_query RBRACE  */
#line 2643 "./src/observer/sql/parser/yacc_sql.y"
                                                            {
		Condition condition;
		condition_init_with_two_query(&condition, NOT_EQUAL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1],CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-2]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5138 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 256: /* in_cells: value value_list  */
#line 2650 "./src/observer/sql/parser/yacc_sql.y"
                          {
	}
#line 5145 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 257: /* reverseComp: EQ  */
#line 2654 "./src/observer/sql/parser/yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 5151 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 258: /* reverseComp: LT  */
#line 2655 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 5157 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 259: /* reverseComp: GT  */
#line 2656 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 5163 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 260: /* reverseComp: LE  */
#line 2657 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 5169 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 261: /* reverseComp: GE  */
#line 2658 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 5175 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 262: /* reverseComp: NE  */
#line 2659 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 5181 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 263: /* comOp: EQ  */
#line 2662 "./src/observer/sql/parser/yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; (yyval.compOp1) = EQUAL_TO; }
#line 5187 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 264: /* comOp: LT  */
#line 2663 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; (yyval.compOp1) = LESS_THAN; }
#line 5193 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 265: /* comOp: GT  */
#line 2664 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; (yyval.compOp1) = GREAT_THAN; }
#line 5199 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 266: /* comOp: LE  */
#line 2665 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; (yyval.compOp1) = LESS_EQUAL; }
#line 5205 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 267: /* comOp: GE  */
#line 2666 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; (yyval.compOp1) = GREAT_EQUAL; }
#line 5211 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 268: /* comOp: NE  */
#line 2667 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; (yyval.compOp1) = NOT_EQUAL; }
#line 5217 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 269: /* comOp: LIKE  */
#line 2668 "./src/observer/sql/parser/yacc_sql.y"
               { CONTEXT->comp = LIKE_TO; (yyval.compOp1) = LIKE_TO; }
#line 5223 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 270: /* comOp: NOT LIKE  */
#line 2669 "./src/observer/sql/parser/yacc_sql.y"
                   { CONTEXT->comp = NOT_LIKE; (yyval.compOp1) = NOT_LIKE; }
#line 5229 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 271: /* comOp: IS NOT  */
#line 2670 "./src/observer/sql/parser/yacc_sql.y"
                 { CONTEXT->comp = COMP_IS_NOT; (yyval.compOp1) = COMP_IS_NOT; }
#line 5235 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 272: /* comOp: IS  */
#line 2671 "./src/observer/sql/parser/yacc_sql.y"
             { CONTEXT->comp = COMP_IS; (yyval.compOp1) = COMP_IS; }
#line 5241 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 273: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 2676 "./src/observer/sql/parser/yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 5250 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;


#line 5254 "./src/observer/sql/parser/yacc_sql.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 2681 "./src/observer/sql/parser/yacc_sql.y"

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
