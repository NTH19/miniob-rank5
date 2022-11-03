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
  YYSYMBOL_value = 105,                    /* value  */
  YYSYMBOL_delete = 106,                   /* delete  */
  YYSYMBOL_update = 107,                   /* update  */
  YYSYMBOL_update_attr_list = 108,         /* update_attr_list  */
  YYSYMBOL_update_attr = 109,              /* update_attr  */
  YYSYMBOL_update_select_attr = 110,       /* update_select_attr  */
  YYSYMBOL_update_agg = 111,               /* update_agg  */
  YYSYMBOL_select = 112,                   /* select  */
  YYSYMBOL_order_by = 113,                 /* order_by  */
  YYSYMBOL_order_item = 114,               /* order_item  */
  YYSYMBOL_order = 115,                    /* order  */
  YYSYMBOL_order_item_list = 116,          /* order_item_list  */
  YYSYMBOL_sub_query = 117,                /* sub_query  */
  YYSYMBOL_join_list = 118,                /* join_list  */
  YYSYMBOL_join_cons = 119,                /* join_cons  */
  YYSYMBOL_expr = 120,                     /* expr  */
  YYSYMBOL_expr_list = 121,                /* expr_list  */
  YYSYMBOL_select_attr = 122,              /* select_attr  */
  YYSYMBOL_attr_list = 123,                /* attr_list  */
  YYSYMBOL_rel_list = 124,                 /* rel_list  */
  YYSYMBOL_where = 125,                    /* where  */
  YYSYMBOL_condition_list = 126,           /* condition_list  */
  YYSYMBOL_condition = 127,                /* condition  */
  YYSYMBOL_in_cells = 128,                 /* in_cells  */
  YYSYMBOL_reverseComp = 129,              /* reverseComp  */
  YYSYMBOL_comOp = 130,                    /* comOp  */
  YYSYMBOL_load_data = 131                 /* load_data  */
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
#define YYLAST   828

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  272
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  782

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
     422,   423,   428,   431,   434,   438,   442,   448,   458,   466,
     468,   472,   478,   486,   497,   502,   507,   512,   520,   525,
     530,   535,   540,   545,   550,   555,   560,   565,   570,   579,
     592,   605,   616,   626,   637,   639,   643,   648,   656,   659,
     662,   667,   669,   675,   696,   716,   736,   756,   775,   794,
     813,   835,   858,   877,   897,   916,   936,   955,   974,   996,
    1019,  1039,  1059,  1079,  1099,  1119,  1139,  1163,  1185,  1207,
    1227,  1247,  1267,  1287,  1307,  1327,  1346,  1365,  1384,  1403,
    1423,  1443,  1466,  1489,  1513,  1537,  1557,  1577,  1598,  1619,
    1639,  1659,  1680,  1701,  1721,  1741,  1761,  1781,  1804,  1827,
    1851,  1875,  1896,  1917,  1938,  1959,  1980,  2001,  2022,  2043,
    2064,  2085,  2106,  2127,  2151,  2177,  2179,  2184,  2189,  2192,
    2195,  2198,  2201,  2204,  2207,  2210,  2215,  2220,  2225,  2232,
    2238,  2244,  2250,  2255,  2260,  2265,  2270,  2275,  2281,  2289,
    2297,  2305,  2313,  2321,  2329,  2336,  2343,  2351,  2359,  2367,
    2375,  2381,  2387,  2393,  2399,  2405,  2412,  2420,  2428,  2436,
    2444,  2451,  2459,  2467,  2475,  2485,  2486,  2491,  2497,  2502,
    2504,  2510,  2516,  2522,  2529,  2535,  2542,  2550,  2552,  2555,
    2559,  2564,  2566,  2569,  2571,  2575,  2581,  2587,  2593,  2600,
    2608,  2615,  2621,  2627,  2634,  2641,  2645,  2646,  2647,  2648,
    2649,  2650,  2653,  2654,  2655,  2656,  2657,  2658,  2659,  2660,
    2661,  2662,  2666
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
  "value_list", "value", "delete", "update", "update_attr_list",
  "update_attr", "update_select_attr", "update_agg", "select", "order_by",
  "order_item", "order", "order_item_list", "sub_query", "join_list",
  "join_cons", "expr", "expr_list", "select_attr", "attr_list", "rel_list",
  "where", "condition_list", "condition", "in_cells", "reverseComp",
  "comOp", "load_data", YY_NULLPTR
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

#define YYPACT_NINF (-456)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -456,   692,  -456,    11,   201,   307,   -61,   342,    40,    -2,
      15,   -22,    57,    93,  -456,   111,   117,   140,    85,  -456,
    -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,
    -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,    86,   115,
     188,   120,   156,   607,   216,   232,   260,   265,   281,  -456,
     607,  -456,  -456,  -456,     4,  -456,   277,  -456,    14,   287,
     330,   352,   349,  -456,   327,   332,   375,  -456,  -456,  -456,
    -456,  -456,   366,   405,   379,   354,   422,   427,   -11,   -38,
     359,   360,   361,   363,   -44,    26,   364,  -456,   367,  -456,
     607,   607,   607,   607,   607,  -456,   368,  -456,  -456,   370,
     400,   408,   373,   376,   377,   381,   407,  -456,  -456,  -456,
     124,   436,   144,   194,   221,   224,   -20,  -456,  -456,     6,
      14,   -44,   -44,  -456,  -456,    78,   452,   439,   595,   455,
     409,   441,   424,  -456,   444,   616,   447,   394,    32,   395,
      36,    76,   396,   126,   398,   131,   403,   147,   404,   406,
    -456,   110,   411,   277,  -456,  -456,   412,   414,   426,   460,
     408,  -456,   340,   461,   241,   457,   425,   678,   446,  -456,
     166,   373,   408,   483,   377,   474,  -456,  -456,  -456,  -456,
    -456,    -1,   421,   477,   428,  -456,   478,   429,  -456,   431,
    -456,   480,   433,  -456,   481,   434,  -456,   489,   438,  -456,
     490,  -456,    81,   277,   277,  -456,    91,   460,   440,   408,
     449,   495,   439,   512,   249,   499,   509,   503,  -456,  -456,
    -456,  -456,  -456,  -456,   505,  -456,   338,   464,   619,   595,
    -456,   516,  -456,   441,   523,   459,   444,   524,   465,   468,
    -456,  -456,   514,   421,  -456,   154,  -456,  -456,   176,  -456,
     184,  -456,   227,  -456,   237,   466,   277,  -456,  -456,  -456,
     470,   460,  -456,   408,   492,   534,   475,   541,   340,   527,
     461,  -456,   529,   531,   533,   535,   536,    -9,   697,   538,
     509,    66,   537,  -456,  -456,   241,   353,   446,   282,  -456,
    -456,   555,  -456,  -456,  -456,   542,  -456,   421,   543,   514,
     494,  -456,   496,  -456,   497,  -456,   498,  -456,   501,  -456,
     277,  -456,   460,  -456,   559,   595,  -456,   504,  -456,   495,
    -456,  -456,   209,   506,   508,   510,   511,   517,   518,   520,
     525,  -456,  -456,  -456,  -456,  -456,   554,   522,  -456,   557,
     495,   566,   568,    66,   570,  -456,   560,   578,   579,   581,
     583,   565,  -456,   564,   567,  -456,   179,   514,   601,   589,
    -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,   576,   446,
       3,   590,  -456,   574,   597,   577,   586,   587,   591,   -19,
     105,   594,   553,   509,  -456,  -456,  -456,  -456,  -456,   608,
     617,  -456,   222,   562,   580,   585,   588,   271,   598,   599,
     592,  -456,  -456,  -456,   634,   593,   408,  -456,  -456,  -456,
     600,  -456,   504,  -456,   603,   -13,   610,   611,   612,   613,
     615,   622,   620,   623,   460,  -456,   626,   130,   632,  -456,
    -456,   257,   637,   317,   369,   371,   372,  -456,  -456,   408,
     408,  -456,  -456,   627,   635,   402,   590,   640,   628,   631,
     624,   643,   655,   691,   693,   133,   671,   641,   460,  -456,
     408,   138,   642,   460,  -456,  -456,  -456,   644,  -456,  -456,
     645,  -456,   649,  -456,   650,  -456,   651,   706,   707,   690,
    -456,  -456,  -456,    72,   246,   676,   668,   175,   183,   213,
     251,   669,   460,  -456,   670,   149,  -456,   408,  -456,   682,
     460,  -456,   460,  -456,   408,   725,   737,   738,   739,   740,
    -456,  -456,   595,   687,   688,   722,   694,  -456,   408,   695,
     273,   696,   698,   723,   699,   700,   724,   701,   702,   726,
     703,   704,   730,   460,  -456,   408,   159,   705,   460,  -456,
     408,  -456,   460,  -456,   408,  -456,   408,  -456,  -456,  -456,
    -456,  -456,  -456,   576,   275,   741,   709,  -456,   408,  -456,
     276,   710,  -456,   408,   279,   744,   712,   293,   746,   714,
     295,   748,   716,   297,   750,   718,  -456,   408,  -456,   719,
     460,  -456,   460,  -456,   408,  -456,  -456,   408,  -456,   408,
    -456,  -456,   720,  -456,   408,   721,   298,   408,  -456,   727,
    -456,   408,  -456,   408,  -456,   728,  -456,   408,   729,   299,
     731,  -456,   408,   732,   300,   733,  -456,   408,   734,   301,
     735,  -456,   408,   736,   311,   408,  -456,   460,  -456,   408,
    -456,   408,  -456,   408,  -456,  -456,  -456,   408,  -456,   319,
     742,  -456,   408,  -456,  -456,   408,  -456,   408,  -456,  -456,
     408,  -456,   320,   743,  -456,   408,  -456,   408,  -456,   321,
     745,  -456,   408,  -456,   408,  -456,   322,   747,  -456,   408,
    -456,   408,  -456,   344,   749,  -456,   408,  -456,  -456,   408,
    -456,   408,  -456,  -456,   408,  -456,   751,  -456,   408,  -456,
     408,  -456,   408,  -456,  -456,   408,  -456,   752,  -456,   408,
    -456,   408,  -456,   408,  -456,   753,  -456,   408,  -456,   408,
    -456,   408,  -456,   754,  -456,   408,  -456,   408,  -456,   408,
    -456,   755,  -456,   408,  -456,   408,  -456,   408,  -456,  -456,
    -456,  -456,   408,  -456,   408,  -456,  -456,  -456,  -456,   408,
    -456,   408,  -456,  -456,  -456,   408,  -456,   408,  -456,  -456,
    -456,   408,  -456,   408,  -456,  -456,  -456,   408,  -456,   408,
    -456,  -456,   408,  -456,  -456,   408,  -456,  -456,   408,  -456,
    -456,   408,  -456,  -456,   408,  -456,  -456,  -456,  -456,  -456,
    -456,  -456
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     3,
      21,    20,    15,    16,    17,    18,     9,    10,    11,    12,
      13,    14,     8,     5,     7,     6,     4,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
       0,    62,    63,    64,   185,    65,   229,   184,   225,     0,
       0,     0,     0,    24,     0,     0,     0,    25,    26,    27,
      23,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   179,     0,     0,   190,     0,   227,
       0,     0,     0,     0,     0,   228,     0,    31,    29,     0,
       0,   241,     0,     0,     0,     0,     0,    28,    37,   183,
       0,     0,     0,     0,     0,     0,   186,   187,   188,   229,
     225,   178,   180,   182,   181,   237,     0,    58,     0,     0,
       0,    69,     0,    53,    39,     0,     0,     0,   193,     0,
     192,   194,     0,   195,     0,   197,     0,   196,     0,     0,
     191,     0,     0,   229,   230,   226,     0,     0,     0,   237,
     241,    30,     0,    56,     0,     0,     0,     0,   243,    67,
       0,     0,   241,     0,     0,     0,    48,    51,    52,    49,
      50,    44,     0,     0,     0,   205,     0,     0,   204,     0,
     206,     0,     0,   207,     0,     0,   209,     0,     0,   208,
       0,   189,   229,   229,   229,   235,   237,   237,     0,   241,
      94,    60,    58,     0,     0,     0,     0,     0,   262,   263,
     264,   265,   266,   267,     0,   268,     0,   271,     0,     0,
     242,     0,    71,    69,     0,     0,    39,     0,     0,     0,
      46,    36,    34,     0,   199,   210,   198,   200,   211,   201,
     212,   203,   214,   202,   213,     0,   229,   231,   232,   233,
       0,   237,   238,   241,     0,     0,     0,     0,     0,     0,
      56,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,   270,     0,   245,   243,     0,    70,
      68,     0,    40,    38,    47,     0,    45,     0,     0,    34,
       0,   220,     0,   221,     0,   222,     0,   224,     0,   223,
     229,   236,   237,   240,     0,     0,    93,     0,    90,    60,
      59,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,   257,   258,   259,   260,   261,     0,   246,     0,
      60,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,    75,    74,     0,     0,   272,    41,    34,     0,     0,
     215,   216,   217,   219,   218,   234,   239,    92,   175,   243,
      98,   101,    61,     0,     0,     0,     0,     0,     0,     0,
     237,     0,     0,     0,   248,   247,   255,   251,   249,     0,
       0,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    35,    32,     0,     0,   241,   177,   100,    99,
       0,    96,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,    54,     0,   237,     0,   252,
     250,     0,     0,     0,     0,     0,     0,    76,    77,   241,
     241,    42,    33,     0,     0,    98,   101,     0,     0,     0,
       0,     0,     0,     0,     0,   237,     0,     0,   237,    54,
     241,   237,     0,   237,    54,   254,    79,     0,    78,    81,
       0,    83,     0,    87,     0,    85,     0,     0,     0,     0,
      91,    97,   102,     0,    54,     0,     0,     0,     0,     0,
       0,     0,   237,    54,     0,   237,    54,   241,   104,     0,
     237,    54,   237,    54,   241,     0,     0,     0,     0,     0,
      72,    73,     0,     0,     0,     0,     0,    54,   241,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,    54,   241,   237,     0,   237,    54,
     241,   120,   237,    54,   241,    54,   241,   130,    80,    82,
      84,    88,    86,   175,    54,     0,     0,    54,   241,   105,
      54,     0,    54,   241,    54,     0,     0,    54,     0,     0,
      54,     0,     0,    54,     0,     0,    54,   241,   103,     0,
     237,    54,   237,    54,   241,   112,    54,   241,   129,   241,
     162,   176,     0,    54,   241,     0,    54,   241,   121,     0,
      54,   241,    54,   241,   132,     0,    54,   241,     0,    54,
       0,    54,   241,     0,    54,     0,    54,   241,     0,    54,
       0,    54,   241,     0,    54,   241,   119,   237,    54,   241,
      54,   241,   128,   241,   161,   146,    54,   241,   106,    54,
       0,    54,   241,   113,    54,   241,   131,   241,   164,    54,
     241,   107,    54,     0,    54,   241,    54,   241,   108,    54,
       0,    54,   241,    54,   241,   110,    54,     0,    54,   241,
      54,   241,   109,    54,     0,    54,   241,   111,    54,   241,
     127,   241,   160,   145,   241,   122,     0,    54,   241,    54,
     241,   134,   241,   163,   148,   241,   123,     0,    54,   241,
      54,   241,   136,   241,   124,     0,    54,   241,    54,   241,
     138,   241,   126,     0,    54,   241,    54,   241,   142,   241,
     125,     0,    54,   241,    54,   241,   140,   241,   159,   144,
     114,    54,   241,   133,   241,   166,   147,   115,    54,   241,
     135,   241,   168,   116,    54,   241,   137,   241,   170,   118,
      54,   241,   141,   241,   174,   117,    54,   241,   139,   241,
     172,   143,   241,   165,   150,   241,   167,   152,   241,   169,
     154,   241,   173,   158,   241,   171,   156,   149,   151,   153,
     157,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,  -456,
    -456,  -456,  -456,  -456,  -291,  -228,  -456,  -456,   528,   604,
    -456,  -456,  -456,  -455,  -456,   526,   582,  -185,  -152,  -456,
    -456,   546,   638,  -456,  -456,  -456,  -456,   383,   357,   351,
    -213,   245,   304,     1,   708,  -456,  -117,  -136,  -160,  -286,
    -123,   467,  -456,  -456,  -456
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   298,   242,    31,    32,   175,   134,
     295,   181,   135,   460,    33,   213,   163,   269,    57,    34,
      35,   172,   131,   353,   354,    36,   267,   371,   411,   413,
     215,   406,   368,   167,    95,    59,    89,   160,   129,   230,
     369,   342,   337,   228,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     210,   345,   154,   279,   497,   168,    58,   109,   359,   504,
     211,    60,   234,   408,   409,   299,   238,    38,   232,    39,
     420,   149,   421,   209,    93,    88,   448,   327,   449,   518,
     328,    94,   329,    90,   110,    64,   205,   111,   535,   410,
      85,   540,   151,    63,    78,    86,   544,   152,   546,   265,
      66,    84,   150,   422,    65,    91,    92,    93,   239,   450,
      67,   240,   558,   330,    94,   563,   402,   339,   341,   357,
     262,   263,   344,   184,    40,   214,    87,   187,   153,   577,
      91,    92,    93,   407,   584,   257,   258,   259,   587,    94,
     589,   120,   121,   122,   123,   124,    68,   156,   116,   594,
      88,   117,   597,   314,   185,   601,   287,   603,   188,   607,
     156,   513,   612,   514,    69,   617,   319,   189,   622,   157,
      70,   625,   255,   158,   156,   313,   629,    49,   631,   340,
     389,   633,   260,    72,   372,    51,    52,    53,   637,   311,
      55,   642,   138,    71,   515,   645,   423,   647,   190,   156,
     159,   650,   156,   256,   655,   386,   657,   156,    73,   662,
     139,   664,   141,   261,   669,    78,   671,   192,   156,   676,
     428,   462,   195,   679,   491,   681,   366,   424,   156,   499,
     142,   684,   202,   231,   688,   203,   690,    74,   198,   692,
     537,   340,    76,   365,   695,   300,    75,   699,   193,   701,
     579,   703,   463,   196,   707,   492,   709,    41,   711,    42,
     500,   715,   143,   717,   521,   719,   522,   302,   723,   199,
     725,   538,   524,   727,   525,   304,   301,    49,    77,   286,
     144,   580,   732,    79,   734,    51,    52,    53,   400,   145,
      55,   401,   147,   739,   425,   741,   444,   523,   303,    80,
     214,   745,   527,   747,   528,   526,   305,   146,    43,   751,
     148,   753,    44,    45,    46,    47,    48,   757,   306,   759,
     272,   273,   274,   275,   276,   466,   762,    81,   308,   477,
     478,   373,    82,   765,   374,   529,    78,   516,   459,   768,
     530,   464,   531,   467,   431,   771,    88,   432,    83,   307,
     498,   774,    49,   346,   347,   348,   349,   350,    50,   309,
      51,    52,    53,    54,   561,    55,   592,   599,   517,   493,
     605,   277,   496,   532,    43,   501,    96,   503,    44,    45,
      46,    47,    48,    97,   610,   469,   615,   541,   620,   640,
     653,   660,   667,   437,   547,   562,   438,   593,   600,    61,
      62,   606,   674,   470,   351,    98,   534,   352,   559,   539,
     686,   697,   705,   713,   543,   611,   545,   616,    49,   621,
     641,   654,   661,   668,    50,   578,    51,    52,    53,    54,
     585,    55,    56,   675,   588,   721,   590,   471,    99,   473,
     475,   687,   698,   706,   714,   282,   283,   576,   598,   100,
     581,    49,   583,   604,   101,   472,   586,   474,   476,    51,
      52,    53,   408,   409,    55,   103,   722,   626,   102,    91,
      92,    93,   104,   105,   632,   107,   106,   634,    94,   635,
     108,   112,   113,   114,   638,   115,   118,   643,   127,   119,
     125,   646,   126,   648,   628,   130,   630,   651,   128,   133,
     132,   137,   658,   136,   140,   161,   162,   665,   169,   170,
     171,   173,   672,   174,   182,   677,   183,   186,   191,   680,
     194,   682,   208,   683,   216,   197,   200,   685,   201,   156,
     212,   217,   691,   204,   206,   693,   207,   694,   229,   235,
     696,   678,   237,   241,   243,   702,   245,   704,   248,   250,
     244,   246,   710,   247,   712,   249,   251,   252,   254,   718,
     253,   720,   264,   266,   268,   271,   726,   278,   214,   728,
     280,   729,   281,   284,   730,   288,   290,   293,   733,   296,
     735,   291,   736,   297,   294,   737,   315,   316,   310,   740,
     317,   742,   312,   743,   318,   320,   322,   746,   323,   748,
     324,   749,   325,   326,   343,   752,   338,   754,   355,   755,
     356,   358,   367,   758,   382,   760,   360,   761,   361,   362,
     363,   383,   763,   364,   764,   385,   370,   392,   375,   766,
     376,   767,   377,   378,   387,   769,   388,   770,   391,   379,
     380,   772,   381,   773,   384,   393,   394,   775,   395,   776,
     396,   397,   777,   398,   403,   778,   399,   404,   779,   412,
     414,   780,   164,   416,   781,   415,    44,    45,    46,    47,
      48,   405,   417,   418,    43,   427,   429,   419,    44,    45,
      46,    47,    48,   426,   433,   430,   285,   442,   480,   443,
      44,    45,    46,    47,    48,   176,   177,   178,   179,   180,
     465,   165,   434,   441,   166,   468,    49,   435,   483,   457,
     436,   487,    50,   486,    51,    52,    53,    54,    49,    55,
     439,   440,   445,   488,    50,   447,    51,    52,    53,    54,
      49,    55,   451,   452,   453,   454,    50,   455,    51,    52,
      53,    54,     2,    55,   456,   458,     3,     4,   461,   479,
     484,     5,     6,   485,     7,     8,     9,    10,    11,   489,
     494,   490,    12,   495,   502,   519,   505,   506,    13,    14,
      15,   507,   508,   509,   510,   511,    16,    17,   218,   219,
     220,   221,   222,   223,   512,   224,   225,   226,   227,    18,
     520,   533,   536,   548,    91,    92,    93,   331,   332,   333,
     334,   335,   336,    94,   542,   549,   550,   551,   552,   554,
     555,   556,   566,   569,   292,   572,   557,   560,   564,   575,
     565,   567,   568,   570,   571,   573,   574,   582,   236,   289,
     595,   596,   602,   608,   609,   613,   614,   618,   619,   623,
     624,   627,   636,   639,   270,   446,   321,   482,   591,   644,
     649,   652,   481,   656,   659,   663,   666,   670,   673,   233,
     390,     0,     0,     0,   689,   700,   553,   708,     0,   716,
       0,   724,     0,   731,   738,   744,   750,   756,   155
};

static const yytype_int16 yycheck[] =
{
     160,   287,   119,   216,   459,   128,     5,    18,   299,   464,
     162,    72,   172,    10,    11,   243,    17,     6,   170,     8,
      39,    41,    41,   159,    68,    19,    39,    36,    41,   484,
      39,    75,    41,    19,    72,    37,   153,    75,   493,    36,
      36,   496,    36,     3,    43,    41,   501,    41,   503,   209,
      72,    50,    72,    72,    39,    66,    67,    68,    59,    72,
       3,    62,   517,    72,    75,   520,   357,   280,   281,   297,
     206,   207,   285,    41,    63,     9,    72,    41,    72,   534,
      66,    67,    68,   369,   539,   202,   203,   204,   543,    75,
     545,    90,    91,    92,    93,    94,     3,    19,    72,   554,
      19,    75,   557,   263,    72,   560,   229,   562,    72,   564,
      19,    39,   567,    41,     3,   570,   268,    41,   573,    41,
       3,   576,    41,    45,    19,   261,   581,    61,   583,   281,
     343,   586,    41,    48,   319,    69,    70,    71,   593,   256,
      74,   596,    18,     3,    72,   600,    41,   602,    72,    19,
      72,   606,    19,    72,   609,   340,   611,    19,    72,   614,
      36,   616,    18,    72,   619,   164,   621,    41,    19,   624,
     383,    41,    41,   628,    41,   630,   312,    72,    19,    41,
      36,   636,    72,    17,   639,    75,   641,    72,    41,   644,
      41,   343,    72,   310,   649,    41,     8,   652,    72,   654,
      41,   656,    72,    72,   659,    72,   661,     6,   663,     8,
      72,   666,    18,   668,    39,   670,    41,    41,   673,    72,
     675,    72,    39,   678,    41,    41,    72,    61,    72,   228,
      36,    72,   687,    17,   689,    69,    70,    71,    59,    18,
      74,    62,    18,   698,   380,   700,   406,    72,    72,    17,
       9,   706,    39,   708,    41,    72,    72,    36,    17,   714,
      36,   716,    21,    22,    23,    24,    25,   722,    41,   724,
      21,    22,    23,    24,    25,    18,   731,    17,    41,   439,
     440,    72,    17,   738,    75,    72,   285,    41,   424,   744,
      39,   427,    41,    36,    72,   750,    19,    75,    17,    72,
     460,   756,    61,    21,    22,    23,    24,    25,    67,    72,
      69,    70,    71,    72,    41,    74,    41,    41,    72,   455,
      41,    72,   458,    72,    17,   461,    39,   463,    21,    22,
      23,    24,    25,     3,    41,    18,    41,   497,    41,    41,
      41,    41,    41,    72,   504,    72,    75,    72,    72,     7,
       8,    72,    41,    36,    72,     3,   492,    75,   518,   495,
      41,    41,    41,    41,   500,    72,   502,    72,    61,    72,
      72,    72,    72,    72,    67,   535,    69,    70,    71,    72,
     540,    74,    75,    72,   544,    41,   546,    18,    39,    18,
      18,    72,    72,    72,    72,    57,    58,   533,   558,    72,
     536,    61,   538,   563,    72,    36,   542,    36,    36,    69,
      70,    71,    10,    11,    74,    49,    72,   577,    43,    66,
      67,    68,    17,    44,   584,     3,    72,   587,    75,   589,
       3,    72,    72,    72,   594,    72,    72,   597,    38,    72,
      72,   601,    72,   603,   580,    72,   582,   607,    40,    72,
      74,    44,   612,    72,    18,     3,    17,   617,     3,    50,
      19,    37,   622,    19,    17,   625,    72,    72,    72,   629,
      72,   631,    46,   633,    17,    72,    72,   637,    72,    19,
      19,    56,   642,    72,    72,   645,    72,   647,    42,     6,
     650,   627,    18,    72,    17,   655,    18,   657,    18,    18,
      72,    72,   662,    72,   664,    72,    72,    18,    18,   669,
      72,   671,    72,    64,    19,     3,   676,    18,     9,   679,
      17,   681,    17,    59,   684,     9,     3,     3,   688,    61,
     690,    72,   692,    19,    69,   695,    44,     3,    72,   699,
      65,   701,    72,   703,     3,    18,    17,   707,    17,   709,
      17,   711,    17,    17,    17,   715,    18,   717,     3,   719,
      18,    18,     3,   723,    39,   725,    72,   727,    72,    72,
      72,    17,   732,    72,   734,    18,    72,    17,    72,   739,
      72,   741,    72,    72,    18,   745,    18,   747,    18,    72,
      72,   751,    72,   753,    72,    17,    17,   757,    17,   759,
      17,    36,   762,    39,     3,   765,    39,    18,   768,    19,
      36,   771,    17,    36,   774,    18,    21,    22,    23,    24,
      25,    45,    36,    36,    17,    72,    18,    36,    21,    22,
      23,    24,    25,    39,    72,    18,    17,     3,     3,    46,
      21,    22,    23,    24,    25,    29,    30,    31,    32,    33,
      18,    56,    72,    61,    59,    18,    61,    72,    18,    39,
      72,    18,    67,    39,    69,    70,    71,    72,    61,    74,
      72,    72,    72,    18,    67,    72,    69,    70,    71,    72,
      61,    74,    72,    72,    72,    72,    67,    72,    69,    70,
      71,    72,     0,    74,    72,    72,     4,     5,    72,    72,
      72,     9,    10,    72,    12,    13,    14,    15,    16,    18,
      39,    18,    20,    72,    72,    39,    72,    72,    26,    27,
      28,    72,    72,    72,    18,    18,    34,    35,    50,    51,
      52,    53,    54,    55,    44,    57,    58,    59,    60,    47,
      72,    72,    72,    18,    66,    67,    68,    50,    51,    52,
      53,    54,    55,    75,    72,    18,    18,    18,    18,    72,
      72,    39,    39,    39,   236,    39,    72,    72,    72,    39,
      72,    72,    72,    72,    72,    72,    72,    72,   174,   233,
      39,    72,    72,    39,    72,    39,    72,    39,    72,    39,
      72,    72,    72,    72,   212,   412,   270,   446,   553,    72,
      72,    72,   445,    72,    72,    72,    72,    72,    72,   171,
     343,    -1,    -1,    -1,    72,    72,   512,    72,    -1,    72,
      -1,    72,    -1,    72,    72,    72,    72,    72,   120
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    78,     0,     4,     5,     9,    10,    12,    13,    14,
      15,    16,    20,    26,    27,    28,    34,    35,    47,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    93,    94,   101,   106,   107,   112,   131,     6,     8,
      63,     6,     8,    17,    21,    22,    23,    24,    25,    61,
      67,    69,    70,    71,    72,    74,    75,   105,   120,   122,
      72,     7,     8,     3,    37,    39,    72,     3,     3,     3,
       3,     3,    48,    72,    72,     8,    72,    72,   120,    17,
      17,    17,    17,    17,   120,    36,    41,    72,    19,   123,
      19,    66,    67,    68,    75,   121,    39,     3,     3,    39,
      72,    72,    43,    49,    17,    44,    72,     3,     3,    18,
      72,    75,    72,    72,    72,    72,    72,    75,    72,    72,
     120,   120,   120,   120,   120,    72,    72,    38,    40,   125,
      72,   109,    74,    72,    96,    99,    72,    44,    18,    36,
      18,    18,    36,    18,    36,    18,    36,    18,    36,    41,
      72,    36,    41,    72,   123,   121,    19,    41,    45,    72,
     124,     3,    17,   103,    17,    56,    59,   120,   127,     3,
      50,    19,   108,    37,    19,    95,    29,    30,    31,    32,
      33,    98,    17,    72,    41,    72,    72,    41,    72,    41,
      72,    72,    41,    72,    72,    41,    72,    72,    41,    72,
      72,    72,    72,    75,    72,   123,    72,    72,    46,   124,
     125,   105,    19,   102,     9,   117,    17,    56,    50,    51,
      52,    53,    54,    55,    57,    58,    59,    60,   130,    42,
     126,    17,   105,   109,   125,     6,    96,    18,    17,    59,
      62,    72,    92,    17,    72,    18,    72,    72,    18,    72,
      18,    72,    18,    72,    18,    41,    72,   123,   123,   123,
      41,    72,   124,   124,    72,   125,    64,   113,    19,   104,
     103,     3,    21,    22,    23,    24,    25,    72,    18,   117,
      17,    17,    57,    58,    59,    17,   120,   127,     9,   108,
       3,    72,    95,     3,    69,    97,    61,    19,    91,    92,
      41,    72,    41,    72,    41,    72,    41,    72,    41,    72,
      72,   123,    72,   124,   125,    44,     3,    65,     3,   105,
      18,   102,    17,    17,    17,    17,    17,    36,    39,    41,
      72,    50,    51,    52,    53,    54,    55,   129,    18,   117,
     105,   117,   128,    17,   117,   126,    21,    22,    23,    24,
      25,    72,    75,   110,   111,     3,    18,    92,    18,    91,
      72,    72,    72,    72,    72,   123,   124,     3,   119,   127,
      72,   114,   104,    72,    75,    72,    72,    72,    72,    72,
      72,    72,    39,    17,    72,    18,   104,    18,    18,   117,
     128,    18,    17,    17,    17,    17,    17,    36,    39,    39,
      59,    62,    91,     3,    18,    45,   118,   126,    10,    11,
      36,   115,    19,   116,    36,    18,    36,    36,    36,    36,
      39,    41,    72,    41,    72,   124,    39,    72,   117,    18,
      18,    72,    75,    72,    72,    72,    72,    72,    75,    72,
      72,    61,     3,    46,   125,    72,   114,    72,    39,    41,
      72,    72,    72,    72,    72,    72,    72,    39,    72,   124,
     100,    72,    41,    72,   124,    18,    18,    36,    18,    18,
      36,    18,    36,    18,    36,    18,    36,   125,   125,    72,
       3,   115,   116,    18,    72,    72,    39,    18,    18,    18,
      18,    41,    72,   124,    39,    72,   124,   100,   125,    41,
      72,   124,    72,   124,   100,    72,    72,    72,    72,    72,
      18,    18,    44,    39,    41,    72,    41,    72,   100,    39,
      72,    39,    41,    72,    39,    41,    72,    39,    41,    72,
      39,    41,    72,    72,   124,   100,    72,    41,    72,   124,
     100,   125,    72,   124,   100,   124,   100,   125,    18,    18,
      18,    18,    18,   119,    72,    72,    39,    72,   100,   125,
      72,    41,    72,   100,    72,    72,    39,    72,    72,    39,
      72,    72,    39,    72,    72,    39,   124,   100,   125,    41,
      72,   124,    72,   124,   100,   125,   124,   100,   125,   100,
     125,   118,    41,    72,   100,    39,    72,   100,   125,    41,
      72,   100,    72,   100,   125,    41,    72,   100,    39,    72,
      41,    72,   100,    39,    72,    41,    72,   100,    39,    72,
      41,    72,   100,    39,    72,   100,   125,    72,   124,   100,
     124,   100,   125,   100,   125,   125,    72,   100,   125,    72,
      41,    72,   100,   125,    72,   100,   125,   100,   125,    72,
     100,   125,    72,    41,    72,   100,    72,   100,   125,    72,
      41,    72,   100,    72,   100,   125,    72,    41,    72,   100,
      72,   100,   125,    72,    41,    72,   100,   125,   124,   100,
     125,   100,   125,   125,   100,   125,    41,    72,   100,    72,
     100,   125,   100,   125,   125,   100,   125,    41,    72,   100,
      72,   100,   125,   100,   125,    41,    72,   100,    72,   100,
     125,   100,   125,    41,    72,   100,    72,   100,   125,   100,
     125,    41,    72,   100,    72,   100,   125,   100,   125,   125,
     125,    72,   100,   125,   100,   125,   125,   125,    72,   100,
     125,   100,   125,   125,    72,   100,   125,   100,   125,   125,
      72,   100,   125,   100,   125,   125,    72,   100,   125,   100,
     125,   125,   100,   125,   125,   100,   125,   125,   100,   125,
     125,   100,   125,   125,   100,   125,   125,   125,   125,   125,
     125,   125
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
     104,   104,   105,   105,   105,   105,   105,   106,   107,   108,
     108,   109,   109,   109,   110,   110,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   113,   113,   114,   114,   115,   115,
     115,   116,   116,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   118,   118,   119,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   124,
     124,   125,   125,   126,   126,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   128,   129,   129,   129,   129,
     129,   129,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   131
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
       0,     3,     1,     1,     1,     1,     1,     5,     7,     0,
       3,     3,     9,     9,     1,     1,     3,     3,     4,     4,
       6,     4,     6,     4,     6,     4,     6,     4,     6,     1,
       8,    12,     9,     8,     0,     4,     2,     4,     0,     1,
       1,     0,     3,     9,     7,     9,    11,    11,    11,    11,
      11,    11,     9,    11,    13,    13,    13,    13,    13,    10,
       8,    10,    12,    12,    12,    12,    12,    11,    10,     9,
       8,    11,    10,    13,    12,    13,    12,    13,    12,    13,
      12,    13,    12,    13,    12,    11,    10,    13,    12,    15,
      14,    15,    14,    15,    14,    15,    14,    15,    14,    12,
      11,    10,     9,    12,    11,    14,    13,    14,    13,    14,
      13,    14,    13,    14,    13,     0,     6,     2,     3,     2,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     5,
       2,     4,     4,     4,     4,     4,     4,     4,     6,     6,
       6,     6,     6,     6,     5,     5,     5,     5,     5,     5,
       6,     6,     6,     6,     6,     8,     8,     8,     8,     8,
       7,     7,     7,     7,     7,     0,     3,     2,     2,     0,
       3,     5,     5,     5,     7,     4,     6,     0,     3,     5,
       4,     0,     3,     0,     3,     3,     4,     5,     5,     5,
       6,     5,     6,     5,     7,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     8
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
#line 1768 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 206 "./src/observer/sql/parser/yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1776 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 211 "./src/observer/sql/parser/yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1784 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 217 "./src/observer/sql/parser/yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1792 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 223 "./src/observer/sql/parser/yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1800 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 229 "./src/observer/sql/parser/yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1808 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 235 "./src/observer/sql/parser/yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1817 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 241 "./src/observer/sql/parser/yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1825 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 247 "./src/observer/sql/parser/yacc_sql.y"
                                {
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
    }
#line 1834 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 255 "./src/observer/sql/parser/yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1843 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 263 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
		}
#line 1852 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 268 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
		}
#line 1861 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA index_attr index_attr_list  */
#line 276 "./src/observer/sql/parser/yacc_sql.y"
                                           { }
#line 1867 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 36: /* index_attr: ID  */
#line 281 "./src/observer/sql/parser/yacc_sql.y"
                {
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
		}
#line 1875 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 37: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 288 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1884 "./src/observer/sql/parser/yacc_sql.tab.c"
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
#line 1896 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 305 "./src/observer/sql/parser/yacc_sql.y"
                                   {    }
#line 1902 "./src/observer/sql/parser/yacc_sql.tab.c"
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
#line 1917 "./src/observer/sql/parser/yacc_sql.tab.c"
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
#line 1932 "./src/observer/sql/parser/yacc_sql.tab.c"
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
#line 1947 "./src/observer/sql/parser/yacc_sql.tab.c"
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
#line 1962 "./src/observer/sql/parser/yacc_sql.tab.c"
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
#line 1977 "./src/observer/sql/parser/yacc_sql.tab.c"
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
#line 1992 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 47: /* number: NUMBER  */
#line 377 "./src/observer/sql/parser/yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1998 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 48: /* type: INT_T  */
#line 380 "./src/observer/sql/parser/yacc_sql.y"
              { (yyval.number)=INTS; }
#line 2004 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 49: /* type: DATE_T  */
#line 381 "./src/observer/sql/parser/yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 2010 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 50: /* type: TEXT_T  */
#line 382 "./src/observer/sql/parser/yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 2016 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 51: /* type: STRING_T  */
#line 383 "./src/observer/sql/parser/yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 2022 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 52: /* type: FLOAT_T  */
#line 384 "./src/observer/sql/parser/yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 2028 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 53: /* ID_get: ID  */
#line 388 "./src/observer/sql/parser/yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 2037 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 54: /* dummy: %empty  */
#line 394 "./src/observer/sql/parser/yacc_sql.y"
      {
		CONTEXT->depth++;
		CONTEXT->sub_con_start[CONTEXT->depth]=CONTEXT->condition_length;
	}
#line 2046 "./src/observer/sql/parser/yacc_sql.tab.c"
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
#line 2060 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 57: /* record_list: COMMA record record_list  */
#line 411 "./src/observer/sql/parser/yacc_sql.y"
                                        {

		}
#line 2068 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 59: /* record: LBRACE value value_list RBRACE  */
#line 418 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		}
#line 2077 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 61: /* value_list: COMMA value value_list  */
#line 423 "./src/observer/sql/parser/yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 2085 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 62: /* value: NUMBER  */
#line 428 "./src/observer/sql/parser/yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2093 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 63: /* value: FLOAT  */
#line 431 "./src/observer/sql/parser/yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2101 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 64: /* value: DATEE  */
#line 434 "./src/observer/sql/parser/yacc_sql.y"
               {
			(yyvsp[0].dates) = substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].dates));
		}
#line 2110 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 65: /* value: SSS  */
#line 438 "./src/observer/sql/parser/yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2119 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 66: /* value: NULLL  */
#line 442 "./src/observer/sql/parser/yacc_sql.y"
               {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		}
#line 2127 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 67: /* delete: DELETE FROM ID where SEMICOLON  */
#line 449 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2139 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 68: /* update: UPDATE ID SET update_attr update_attr_list where SEMICOLON  */
#line 459 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2149 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 71: /* update_attr: ID EQ value  */
#line 473 "./src/observer/sql/parser/yacc_sql.y"
                {
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			CONTEXT->value_length = 0;
		}
#line 2159 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 72: /* update_attr: ID EQ LBRACE SELECT update_select_attr FROM ID where RBRACE  */
#line 479 "./src/observer/sql/parser/yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2171 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 73: /* update_attr: ID EQ LBRACE SELECT update_agg FROM ID where RBRACE  */
#line 487 "./src/observer/sql/parser/yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2183 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 74: /* update_select_attr: STAR  */
#line 497 "./src/observer/sql/parser/yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2193 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 75: /* update_select_attr: ID  */
#line 502 "./src/observer/sql/parser/yacc_sql.y"
         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2203 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 76: /* update_select_attr: ID DOT ID  */
#line 507 "./src/observer/sql/parser/yacc_sql.y"
                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2213 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 77: /* update_select_attr: ID DOT STAR  */
#line 512 "./src/observer/sql/parser/yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2223 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 78: /* update_agg: COUNT_T LBRACE STAR RBRACE  */
#line 520 "./src/observer/sql/parser/yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
#line 2233 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 79: /* update_agg: COUNT_T LBRACE ID RBRACE  */
#line 525 "./src/observer/sql/parser/yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2243 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 80: /* update_agg: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 530 "./src/observer/sql/parser/yacc_sql.y"
                                          {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2253 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 81: /* update_agg: MAX_T LBRACE ID RBRACE  */
#line 535 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2263 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 82: /* update_agg: MAX_T LBRACE ID DOT ID RBRACE  */
#line 540 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2273 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 83: /* update_agg: MIN_T LBRACE ID RBRACE  */
#line 545 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2283 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 84: /* update_agg: MIN_T LBRACE ID DOT ID RBRACE  */
#line 550 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2293 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 85: /* update_agg: SUM_T LBRACE ID RBRACE  */
#line 555 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2303 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 86: /* update_agg: SUM_T LBRACE ID DOT ID RBRACE  */
#line 560 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2313 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 87: /* update_agg: AVG_T LBRACE ID RBRACE  */
#line 565 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2323 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 88: /* update_agg: AVG_T LBRACE ID DOT ID RBRACE  */
#line 570 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2333 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 89: /* select: DABIAO  */
#line 579 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2350 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 90: /* select: SELECT select_attr FROM ID rel_list where order_by SEMICOLON  */
#line 592 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2368 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 91: /* select: SELECT select_attr FROM ID INNER_T JOIN_T ID ON join_cons join_list where SEMICOLON  */
#line 605 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2384 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 92: /* select: SELECT select_attr FROM ID AS ID rel_list where SEMICOLON  */
#line 616 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2399 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 93: /* select: SELECT select_attr FROM ID ID rel_list where SEMICOLON  */
#line 626 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2414 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 96: /* order_item: ID order  */
#line 643 "./src/observer/sql/parser/yacc_sql.y"
                 {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, CONTEXT->order);
	}
#line 2424 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 97: /* order_item: ID DOT ID order  */
#line 648 "./src/observer/sql/parser/yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, CONTEXT->order);
	}
#line 2434 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 98: /* order: %empty  */
#line 656 "./src/observer/sql/parser/yacc_sql.y"
                    {
		CONTEXT->order = 0;
	}
#line 2442 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 99: /* order: ASC  */
#line 659 "./src/observer/sql/parser/yacc_sql.y"
              {
		CONTEXT->order = 0;
	}
#line 2450 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 100: /* order: DESC  */
#line 662 "./src/observer/sql/parser/yacc_sql.y"
               {
		CONTEXT->order = 1;
	}
#line 2458 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 103: /* sub_query: SELECT ID DOT ID FROM ID rel_list dummy where  */
#line 675 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2484 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 104: /* sub_query: SELECT ID FROM ID rel_list dummy where  */
#line 696 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2509 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 105: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID dummy where  */
#line 716 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2534 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 106: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 736 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2559 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 107: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 756 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2583 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 108: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 775 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2607 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 109: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 794 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2631 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 110: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 813 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2658 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 111: /* sub_query: SELECT ID DOT ID FROM ID AS ID rel_list dummy where  */
#line 835 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2686 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 112: /* sub_query: SELECT ID FROM ID AS ID rel_list dummy where  */
#line 858 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2710 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 113: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID AS ID dummy where  */
#line 877 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2735 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 114: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 897 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2759 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 115: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 916 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2784 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 116: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 936 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2808 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 117: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 955 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2832 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 118: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 974 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2859 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 119: /* sub_query: SELECT ID DOT ID FROM ID ID rel_list dummy where  */
#line 996 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2887 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 120: /* sub_query: SELECT ID FROM ID ID rel_list dummy where  */
#line 1019 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2912 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 121: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID ID dummy where  */
#line 1039 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2937 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 122: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1059 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2962 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 123: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1079 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2987 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 124: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1099 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3012 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 125: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1119 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3037 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 126: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1139 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3065 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 127: /* sub_query: SELECT ID DOT ID AS ID FROM ID rel_list dummy where  */
#line 1163 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3092 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 128: /* sub_query: SELECT ID DOT ID ID FROM ID rel_list dummy where  */
#line 1185 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3119 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 129: /* sub_query: SELECT ID AS ID FROM ID rel_list dummy where  */
#line 1207 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3144 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 130: /* sub_query: SELECT ID ID FROM ID rel_list dummy where  */
#line 1227 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3169 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 131: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID dummy where  */
#line 1247 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3194 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 132: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID dummy where  */
#line 1267 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3219 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 133: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1287 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3244 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 134: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1307 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3269 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 135: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1327 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3293 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 136: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1346 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3317 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 137: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1365 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3341 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 138: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1384 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3365 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 139: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1403 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3390 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 140: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1423 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3415 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 141: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1443 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3443 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 142: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1466 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3471 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 143: /* sub_query: SELECT ID DOT ID AS ID FROM ID AS ID rel_list dummy where  */
#line 1489 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3500 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 144: /* sub_query: SELECT ID DOT ID ID FROM ID AS ID rel_list dummy where  */
#line 1513 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3529 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 145: /* sub_query: SELECT ID AS ID FROM ID AS ID rel_list dummy where  */
#line 1537 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3554 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 146: /* sub_query: SELECT ID ID FROM ID AS ID rel_list dummy where  */
#line 1557 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3579 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 147: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID AS ID dummy where  */
#line 1577 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3605 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 148: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID AS ID dummy where  */
#line 1598 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3631 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 149: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1619 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3656 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 150: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1639 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3681 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 151: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1659 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3707 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 152: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1680 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3733 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 153: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1701 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3758 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 154: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1721 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3783 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 155: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1741 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3808 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 156: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1761 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3833 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 157: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1781 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3861 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 158: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1804 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3889 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 159: /* sub_query: SELECT ID DOT ID AS ID FROM ID ID rel_list dummy where  */
#line 1827 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3918 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 160: /* sub_query: SELECT ID DOT ID ID FROM ID ID rel_list dummy where  */
#line 1851 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3947 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 161: /* sub_query: SELECT ID AS ID FROM ID ID rel_list dummy where  */
#line 1875 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3973 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 162: /* sub_query: SELECT ID ID FROM ID ID rel_list dummy where  */
#line 1896 "./src/observer/sql/parser/yacc_sql.y"
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
#line 3999 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 163: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID ID dummy where  */
#line 1917 "./src/observer/sql/parser/yacc_sql.y"
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
#line 4025 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 164: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID ID dummy where  */
#line 1938 "./src/observer/sql/parser/yacc_sql.y"
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
#line 4051 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 165: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 1959 "./src/observer/sql/parser/yacc_sql.y"
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
#line 4077 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 166: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 1980 "./src/observer/sql/parser/yacc_sql.y"
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
#line 4103 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 167: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2001 "./src/observer/sql/parser/yacc_sql.y"
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
#line 4129 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 168: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2022 "./src/observer/sql/parser/yacc_sql.y"
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
#line 4155 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 169: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2043 "./src/observer/sql/parser/yacc_sql.y"
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
#line 4181 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 170: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2064 "./src/observer/sql/parser/yacc_sql.y"
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
#line 4207 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 171: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2085 "./src/observer/sql/parser/yacc_sql.y"
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
#line 4233 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 172: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2106 "./src/observer/sql/parser/yacc_sql.y"
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
#line 4259 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 173: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2127 "./src/observer/sql/parser/yacc_sql.y"
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
#line 4288 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 174: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2151 "./src/observer/sql/parser/yacc_sql.y"
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
#line 4317 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 176: /* join_list: INNER_T JOIN_T ID ON join_cons join_list  */
#line 2179 "./src/observer/sql/parser/yacc_sql.y"
                                               {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
	}
#line 4325 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 177: /* join_cons: condition condition_list  */
#line 2184 "./src/observer/sql/parser/yacc_sql.y"
                                  {	
	}
#line 4332 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 178: /* expr: expr ADD expr  */
#line 2189 "./src/observer/sql/parser/yacc_sql.y"
                      {
		(yyval.expr1) = create_astexpr(ADD_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4340 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 179: /* expr: SUB expr  */
#line 2192 "./src/observer/sql/parser/yacc_sql.y"
                   {
		(yyval.expr1) = create_astexpr(SUB_OP, NULL, (yyvsp[0].expr1));
	}
#line 4348 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 180: /* expr: expr SUB expr  */
#line 2195 "./src/observer/sql/parser/yacc_sql.y"
                        {
		(yyval.expr1) = create_astexpr(SUB_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4356 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 181: /* expr: expr STAR expr  */
#line 2198 "./src/observer/sql/parser/yacc_sql.y"
                         {
		(yyval.expr1) = create_astexpr(MUL_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4364 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 182: /* expr: expr DIV expr  */
#line 2201 "./src/observer/sql/parser/yacc_sql.y"
                        {
		(yyval.expr1) = create_astexpr(DIV_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4372 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 183: /* expr: LBRACE expr RBRACE  */
#line 2204 "./src/observer/sql/parser/yacc_sql.y"
                             {
		(yyval.expr1) = (yyvsp[-1].expr1);
	}
#line 4380 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 184: /* expr: value  */
#line 2207 "./src/observer/sql/parser/yacc_sql.y"
                {
		(yyval.expr1) = create_value_expr(&CONTEXT->values[CONTEXT->value_length - 1]);
	}
#line 4388 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 185: /* expr: ID  */
#line 2210 "./src/observer/sql/parser/yacc_sql.y"
             {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4398 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 186: /* expr: ID DOT ID  */
#line 2215 "./src/observer/sql/parser/yacc_sql.y"
                    {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4408 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 187: /* expr: ID DOT STAR  */
#line 2220 "./src/observer/sql/parser/yacc_sql.y"
                      {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), "*");
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4418 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 188: /* expr: ID AS ID  */
#line 2225 "./src/observer/sql/parser/yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[0].string));

		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4430 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 189: /* expr: ID DOT ID AS ID  */
#line 2232 "./src/observer/sql/parser/yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4441 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 190: /* expr: ID ID  */
#line 2238 "./src/observer/sql/parser/yacc_sql.y"
                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4452 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 191: /* expr: ID DOT ID ID  */
#line 2244 "./src/observer/sql/parser/yacc_sql.y"
                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4463 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 192: /* expr: COUNT_T LBRACE STAR RBRACE  */
#line 2250 "./src/observer/sql/parser/yacc_sql.y"
                                     {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4473 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 193: /* expr: COUNT_T LBRACE ID RBRACE  */
#line 2255 "./src/observer/sql/parser/yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4483 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 194: /* expr: MAX_T LBRACE ID RBRACE  */
#line 2260 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4493 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 195: /* expr: MIN_T LBRACE ID RBRACE  */
#line 2265 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4503 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 196: /* expr: SUM_T LBRACE ID RBRACE  */
#line 2270 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4513 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 197: /* expr: AVG_T LBRACE ID RBRACE  */
#line 2275 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4523 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 198: /* expr: COUNT_T LBRACE STAR RBRACE AS ID  */
#line 2281 "./src/observer/sql/parser/yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4536 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 199: /* expr: COUNT_T LBRACE ID RBRACE AS ID  */
#line 2289 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4549 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 200: /* expr: MAX_T LBRACE ID RBRACE AS ID  */
#line 2297 "./src/observer/sql/parser/yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4562 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 201: /* expr: MIN_T LBRACE ID RBRACE AS ID  */
#line 2305 "./src/observer/sql/parser/yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4575 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 202: /* expr: SUM_T LBRACE ID RBRACE AS ID  */
#line 2313 "./src/observer/sql/parser/yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4588 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 203: /* expr: AVG_T LBRACE ID RBRACE AS ID  */
#line 2321 "./src/observer/sql/parser/yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4601 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 204: /* expr: COUNT_T LBRACE STAR RBRACE ID  */
#line 2329 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4613 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 205: /* expr: COUNT_T LBRACE ID RBRACE ID  */
#line 2336 "./src/observer/sql/parser/yacc_sql.y"
                                     {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-2].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4625 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 206: /* expr: MAX_T LBRACE ID RBRACE ID  */
#line 2343 "./src/observer/sql/parser/yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-2].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4638 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 207: /* expr: MIN_T LBRACE ID RBRACE ID  */
#line 2351 "./src/observer/sql/parser/yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4651 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 208: /* expr: SUM_T LBRACE ID RBRACE ID  */
#line 2359 "./src/observer/sql/parser/yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	  }
#line 4664 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 209: /* expr: AVG_T LBRACE ID RBRACE ID  */
#line 2367 "./src/observer/sql/parser/yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	  }
#line 4677 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 210: /* expr: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 2375 "./src/observer/sql/parser/yacc_sql.y"
                                         {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4688 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 211: /* expr: MAX_T LBRACE ID DOT ID RBRACE  */
#line 2381 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MAX_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4699 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 212: /* expr: MIN_T LBRACE ID DOT ID RBRACE  */
#line 2387 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MIN_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4710 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 213: /* expr: SUM_T LBRACE ID DOT ID RBRACE  */
#line 2393 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,SUM_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4721 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 214: /* expr: AVG_T LBRACE ID DOT ID RBRACE  */
#line 2399 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,AVG_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4732 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 215: /* expr: COUNT_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2405 "./src/observer/sql/parser/yacc_sql.y"
                                               {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4744 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 216: /* expr: MAX_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2412 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MAX_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4757 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 217: /* expr: MIN_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2420 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MIN_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4770 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 218: /* expr: SUM_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2428 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,SUM_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4783 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 219: /* expr: AVG_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2436 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,AVG_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4796 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 220: /* expr: COUNT_T LBRACE ID DOT ID RBRACE ID  */
#line 2444 "./src/observer/sql/parser/yacc_sql.y"
                                            {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4808 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 221: /* expr: MAX_T LBRACE ID DOT ID RBRACE ID  */
#line 2451 "./src/observer/sql/parser/yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4821 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 222: /* expr: MIN_T LBRACE ID DOT ID RBRACE ID  */
#line 2459 "./src/observer/sql/parser/yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4834 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 223: /* expr: SUM_T LBRACE ID DOT ID RBRACE ID  */
#line 2467 "./src/observer/sql/parser/yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4847 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 224: /* expr: AVG_T LBRACE ID DOT ID RBRACE ID  */
#line 2475 "./src/observer/sql/parser/yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4860 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 226: /* expr_list: COMMA expr expr_list  */
#line 2486 "./src/observer/sql/parser/yacc_sql.y"
                               {
		selects_append_expr(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1));
	}
#line 4868 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 227: /* select_attr: STAR attr_list  */
#line 2491 "./src/observer/sql/parser/yacc_sql.y"
                   {  
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		CONTEXT->ssql->sstr.selection.need_Revere=1;
	}
#line 4879 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 228: /* select_attr: expr expr_list  */
#line 2497 "./src/observer/sql/parser/yacc_sql.y"
                         {
		selects_append_expr(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1));
	}
#line 4887 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 230: /* attr_list: COMMA ID attr_list  */
#line 2504 "./src/observer/sql/parser/yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 4898 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 231: /* attr_list: COMMA ID DOT ID attr_list  */
#line 2510 "./src/observer/sql/parser/yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 4909 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 232: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 2516 "./src/observer/sql/parser/yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 4920 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 233: /* attr_list: COMMA ID AS ID attr_list  */
#line 2522 "./src/observer/sql/parser/yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-3].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 4932 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 234: /* attr_list: COMMA ID DOT ID AS ID attr_list  */
#line 2529 "./src/observer/sql/parser/yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string),(yyvsp[-1].string));
		}
#line 4943 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 235: /* attr_list: COMMA ID ID attr_list  */
#line 2535 "./src/observer/sql/parser/yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
	}
#line 4955 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 236: /* attr_list: COMMA ID DOT ID ID attr_list  */
#line 2542 "./src/observer/sql/parser/yacc_sql.y"
                                        {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string),(yyvsp[-1].string));
		}
#line 4966 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 238: /* rel_list: COMMA ID rel_list  */
#line 2552 "./src/observer/sql/parser/yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 4974 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 239: /* rel_list: COMMA ID AS ID rel_list  */
#line 2555 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 4983 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 240: /* rel_list: COMMA ID ID rel_list  */
#line 2559 "./src/observer/sql/parser/yacc_sql.y"
                              {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
	}
#line 4992 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 242: /* where: WHERE condition condition_list  */
#line 2566 "./src/observer/sql/parser/yacc_sql.y"
                                     {
	}
#line 4999 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 244: /* condition_list: AND condition condition_list  */
#line 2571 "./src/observer/sql/parser/yacc_sql.y"
                                   {
			}
#line 5006 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 245: /* condition: expr comOp expr  */
#line 2576 "./src/observer/sql/parser/yacc_sql.y"
        {
		Condition condition;
		condition_init_from_expr(&condition, CONTEXT->comp, (yyvsp[-2].expr1), (yyvsp[0].expr1));
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5016 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 246: /* condition: EXIST_T LBRACE sub_query RBRACE  */
#line 2582 "./src/observer/sql/parser/yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 5026 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 247: /* condition: NOT EXIST_T LBRACE sub_query RBRACE  */
#line 2588 "./src/observer/sql/parser/yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, NOT_EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 5036 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 248: /* condition: LBRACE sub_query RBRACE reverseComp ID  */
#line 2593 "./src/observer/sql/parser/yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->comp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5048 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 249: /* condition: expr IN_T LBRACE in_cells RBRACE  */
#line 2600 "./src/observer/sql/parser/yacc_sql.y"
                                          {
		/*TODO: 当前认为expr一定是单个attr */
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_cells_for_in(&condition,&astExpr->attr,CONTEXT->values,CONTEXT->value_length,IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5061 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 250: /* condition: expr NOT IN_T LBRACE in_cells RBRACE  */
#line 2608 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-5].expr1);
		Condition condition;
		condition_init_cells_for_in(&condition,&astExpr->attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5073 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 251: /* condition: expr IN_T LBRACE sub_query RBRACE  */
#line 2615 "./src/observer/sql/parser/yacc_sql.y"
                                          {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_with_query(&condition, IN, &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5084 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 252: /* condition: expr NOT IN_T LBRACE sub_query RBRACE  */
#line 2621 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-5].expr1);
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5095 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 253: /* condition: expr comOp LBRACE sub_query RBRACE  */
#line 2628 "./src/observer/sql/parser/yacc_sql.y"
        {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_with_query(&condition, (yyvsp[-3].compOp1), &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 5106 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 254: /* condition: LBRACE sub_query RBRACE NE LBRACE sub_query RBRACE  */
#line 2634 "./src/observer/sql/parser/yacc_sql.y"
                                                            {
		Condition condition;
		condition_init_with_two_query(&condition, NOT_EQUAL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1],CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-2]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5116 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 255: /* in_cells: value value_list  */
#line 2641 "./src/observer/sql/parser/yacc_sql.y"
                          {
	}
#line 5123 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 256: /* reverseComp: EQ  */
#line 2645 "./src/observer/sql/parser/yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 5129 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 257: /* reverseComp: LT  */
#line 2646 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 5135 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 258: /* reverseComp: GT  */
#line 2647 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 5141 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 259: /* reverseComp: LE  */
#line 2648 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 5147 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 260: /* reverseComp: GE  */
#line 2649 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 5153 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 261: /* reverseComp: NE  */
#line 2650 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 5159 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 262: /* comOp: EQ  */
#line 2653 "./src/observer/sql/parser/yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; (yyval.compOp1) = EQUAL_TO; }
#line 5165 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 263: /* comOp: LT  */
#line 2654 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; (yyval.compOp1) = LESS_THAN; }
#line 5171 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 264: /* comOp: GT  */
#line 2655 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; (yyval.compOp1) = GREAT_THAN; }
#line 5177 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 265: /* comOp: LE  */
#line 2656 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; (yyval.compOp1) = LESS_EQUAL; }
#line 5183 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 266: /* comOp: GE  */
#line 2657 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; (yyval.compOp1) = GREAT_EQUAL; }
#line 5189 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 267: /* comOp: NE  */
#line 2658 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; (yyval.compOp1) = NOT_EQUAL; }
#line 5195 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 268: /* comOp: LIKE  */
#line 2659 "./src/observer/sql/parser/yacc_sql.y"
               { CONTEXT->comp = LIKE_TO; (yyval.compOp1) = LIKE_TO; }
#line 5201 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 269: /* comOp: NOT LIKE  */
#line 2660 "./src/observer/sql/parser/yacc_sql.y"
                   { CONTEXT->comp = NOT_LIKE; (yyval.compOp1) = NOT_LIKE; }
#line 5207 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 270: /* comOp: IS NOT  */
#line 2661 "./src/observer/sql/parser/yacc_sql.y"
                 { CONTEXT->comp = COMP_IS_NOT; (yyval.compOp1) = COMP_IS_NOT; }
#line 5213 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 271: /* comOp: IS  */
#line 2662 "./src/observer/sql/parser/yacc_sql.y"
             { CONTEXT->comp = COMP_IS; (yyval.compOp1) = COMP_IS; }
#line 5219 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 272: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 2667 "./src/observer/sql/parser/yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 5228 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;


#line 5232 "./src/observer/sql/parser/yacc_sql.tab.c"

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

#line 2672 "./src/observer/sql/parser/yacc_sql.y"

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
