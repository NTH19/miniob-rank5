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
  Condition conditions[MAX_NUM];
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
  context->value_length = 0;
  context->ssql->sstr.insertion.value_num = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)


#line 132 "./src/observer/sql/parser/yacc_sql.tab.c"

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
  YYSYMBOL_SHOW = 11,                      /* SHOW  */
  YYSYMBOL_SYNC = 12,                      /* SYNC  */
  YYSYMBOL_INSERT = 13,                    /* INSERT  */
  YYSYMBOL_DELETE = 14,                    /* DELETE  */
  YYSYMBOL_UPDATE = 15,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 16,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 17,                    /* RBRACE  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 19,                 /* TRX_BEGIN  */
  YYSYMBOL_COUNT_T = 20,                   /* COUNT_T  */
  YYSYMBOL_MAX_T = 21,                     /* MAX_T  */
  YYSYMBOL_MIN_T = 22,                     /* MIN_T  */
  YYSYMBOL_AVG_T = 23,                     /* AVG_T  */
  YYSYMBOL_SUM_T = 24,                     /* SUM_T  */
  YYSYMBOL_TRX_COMMIT = 25,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 26,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 27,                     /* INT_T  */
  YYSYMBOL_STRING_T = 28,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 29,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 30,                    /* DATE_T  */
  YYSYMBOL_TEXT_T = 31,                    /* TEXT_T  */
  YYSYMBOL_HELP = 32,                      /* HELP  */
  YYSYMBOL_EXIT = 33,                      /* EXIT  */
  YYSYMBOL_DOT = 34,                       /* DOT  */
  YYSYMBOL_INTO = 35,                      /* INTO  */
  YYSYMBOL_VALUES = 36,                    /* VALUES  */
  YYSYMBOL_FROM = 37,                      /* FROM  */
  YYSYMBOL_WHERE = 38,                     /* WHERE  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_SET = 40,                       /* SET  */
  YYSYMBOL_ON = 41,                        /* ON  */
  YYSYMBOL_INNER_T = 42,                   /* INNER_T  */
  YYSYMBOL_JOIN_T = 43,                    /* JOIN_T  */
  YYSYMBOL_LOAD = 44,                      /* LOAD  */
  YYSYMBOL_DATA = 45,                      /* DATA  */
  YYSYMBOL_INFILE = 46,                    /* INFILE  */
  YYSYMBOL_EQ = 47,                        /* EQ  */
  YYSYMBOL_LT = 48,                        /* LT  */
  YYSYMBOL_GT = 49,                        /* GT  */
  YYSYMBOL_LE = 50,                        /* LE  */
  YYSYMBOL_GE = 51,                        /* GE  */
  YYSYMBOL_NE = 52,                        /* NE  */
  YYSYMBOL_LIKE = 53,                      /* LIKE  */
  YYSYMBOL_NOT = 54,                       /* NOT  */
  YYSYMBOL_UNIQUE = 55,                    /* UNIQUE  */
  YYSYMBOL_NUMBER = 56,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 57,                     /* FLOAT  */
  YYSYMBOL_DATEE = 58,                     /* DATEE  */
  YYSYMBOL_ID = 59,                        /* ID  */
  YYSYMBOL_PATH = 60,                      /* PATH  */
  YYSYMBOL_SSS = 61,                       /* SSS  */
  YYSYMBOL_STAR = 62,                      /* STAR  */
  YYSYMBOL_STRING_V = 63,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_commands = 65,                  /* commands  */
  YYSYMBOL_command = 66,                   /* command  */
  YYSYMBOL_exit = 67,                      /* exit  */
  YYSYMBOL_help = 68,                      /* help  */
  YYSYMBOL_sync = 69,                      /* sync  */
  YYSYMBOL_begin = 70,                     /* begin  */
  YYSYMBOL_commit = 71,                    /* commit  */
  YYSYMBOL_rollback = 72,                  /* rollback  */
  YYSYMBOL_drop_table = 73,                /* drop_table  */
  YYSYMBOL_show_tables = 74,               /* show_tables  */
  YYSYMBOL_show_indexes = 75,              /* show_indexes  */
  YYSYMBOL_desc_table = 76,                /* desc_table  */
  YYSYMBOL_create_index = 77,              /* create_index  */
  YYSYMBOL_index_attr_list = 78,           /* index_attr_list  */
  YYSYMBOL_index_attr = 79,                /* index_attr  */
  YYSYMBOL_drop_index = 80,                /* drop_index  */
  YYSYMBOL_create_table = 81,              /* create_table  */
  YYSYMBOL_attr_def_list = 82,             /* attr_def_list  */
  YYSYMBOL_attr_def = 83,                  /* attr_def  */
  YYSYMBOL_number = 84,                    /* number  */
  YYSYMBOL_type = 85,                      /* type  */
  YYSYMBOL_ID_get = 86,                    /* ID_get  */
  YYSYMBOL_insert = 87,                    /* insert  */
  YYSYMBOL_record_list = 88,               /* record_list  */
  YYSYMBOL_record = 89,                    /* record  */
  YYSYMBOL_value_list = 90,                /* value_list  */
  YYSYMBOL_value = 91,                     /* value  */
  YYSYMBOL_delete = 92,                    /* delete  */
  YYSYMBOL_update = 93,                    /* update  */
  YYSYMBOL_update_attr_list = 94,          /* update_attr_list  */
  YYSYMBOL_update_attr = 95,               /* update_attr  */
  YYSYMBOL_update_select_attr = 96,        /* update_select_attr  */
  YYSYMBOL_update_agg = 97,                /* update_agg  */
  YYSYMBOL_select = 98,                    /* select  */
  YYSYMBOL_join_list = 99,                 /* join_list  */
  YYSYMBOL_join_cons = 100,                /* join_cons  */
  YYSYMBOL_agg_fun_list_head = 101,        /* agg_fun_list_head  */
  YYSYMBOL_agg_fun_list = 102,             /* agg_fun_list  */
  YYSYMBOL_select_attr = 103,              /* select_attr  */
  YYSYMBOL_attr_list = 104,                /* attr_list  */
  YYSYMBOL_rel_list = 105,                 /* rel_list  */
  YYSYMBOL_where = 106,                    /* where  */
  YYSYMBOL_condition_list = 107,           /* condition_list  */
  YYSYMBOL_condition = 108,                /* condition  */
  YYSYMBOL_comOp = 109,                    /* comOp  */
  YYSYMBOL_load_data = 110                 /* load_data  */
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
#define YYLAST   331

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  334

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   150,   150,   152,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   177,   182,   187,   193,   199,   205,   211,   217,
     223,   231,   238,   243,   250,   252,   256,   263,   270,   279,
     281,   285,   296,   309,   312,   313,   314,   315,   316,   319,
     328,   344,   345,   350,   351,   356,   357,   362,   365,   368,
     372,   379,   389,   397,   399,   403,   409,   417,   428,   433,
     438,   443,   451,   456,   461,   466,   471,   476,   481,   486,
     491,   496,   501,   509,   524,   532,   545,   547,   552,   556,
     561,   566,   572,   578,   584,   591,   593,   598,   603,   609,
     615,   621,   631,   637,   643,   648,   654,   656,   662,   668,
     676,   678,   682,   684,   688,   690,   695,   707,   727,   747,
     769,   790,   800,   814,   815,   816,   817,   818,   819,   820,
     821,   825
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
  "DROP", "TABLE", "TABLES", "INDEX", "SELECT", "DESC", "SHOW", "SYNC",
  "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "COUNT_T", "MAX_T", "MIN_T", "AVG_T", "SUM_T", "TRX_COMMIT",
  "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T", "TEXT_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET",
  "ON", "INNER_T", "JOIN_T", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT",
  "LE", "GE", "NE", "LIKE", "NOT", "UNIQUE", "NUMBER", "FLOAT", "DATEE",
  "ID", "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands",
  "command", "exit", "help", "sync", "begin", "commit", "rollback",
  "drop_table", "show_tables", "show_indexes", "desc_table",
  "create_index", "index_attr_list", "index_attr", "drop_index",
  "create_table", "attr_def_list", "attr_def", "number", "type", "ID_get",
  "insert", "record_list", "record", "value_list", "value", "delete",
  "update", "update_attr_list", "update_attr", "update_select_attr",
  "update_agg", "select", "join_list", "join_cons", "agg_fun_list_head",
  "agg_fun_list", "select_attr", "attr_list", "rel_list", "where",
  "condition_list", "condition", "comOp", "load_data", YY_NULLPTR
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
     315,   316,   317,   318
};
#endif

#define YYPACT_NINF (-209)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -209,    56,  -209,     7,    51,    63,   -39,    27,    22,    23,
      26,    15,    61,    73,    75,    77,   108,   100,  -209,  -209,
    -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,  -209,  -209,  -209,  -209,    71,    92,   105,
     101,   103,   147,   161,   162,   163,   164,    13,   165,    35,
     144,   179,   181,   148,  -209,   127,   128,   149,  -209,  -209,
    -209,  -209,  -209,   142,   174,   150,   133,   190,   191,   -35,
     136,   137,   138,   139,   140,    50,  -209,  -209,   141,   143,
    -209,  -209,   145,   167,   168,   146,   151,   154,   155,   160,
    -209,  -209,   192,   193,   194,   198,   199,   200,    14,   165,
     165,   204,    -1,   205,   202,    60,   216,   173,   203,   187,
    -209,   206,    68,   207,   166,   208,   208,   208,   208,   208,
     208,    64,  -209,  -209,  -209,  -209,   169,   184,   168,  -209,
     -28,   211,  -209,  -209,  -209,    86,  -209,    54,   195,  -209,
     -12,   146,   168,   224,   154,   214,  -209,  -209,  -209,  -209,
    -209,   217,   176,   220,   152,  -209,  -209,  -209,  -209,  -209,
    -209,   165,   165,   219,   180,   229,   222,   202,   235,   182,
    -209,  -209,  -209,  -209,  -209,  -209,  -209,   189,    85,    91,
      60,  -209,   234,  -209,   203,   241,   186,   206,   243,   196,
    -209,   230,   176,   231,   233,   237,   238,   239,  -209,  -209,
    -209,   209,  -209,   -28,   240,   211,  -209,    54,  -209,  -209,
    -209,   225,  -209,   195,    70,  -209,  -209,   248,  -209,  -209,
    -209,   244,   176,   245,   230,    65,   197,   201,   210,   212,
      60,   222,  -209,  -209,    98,   213,  -209,   242,   247,   249,
     250,   251,   236,  -209,   227,   246,  -209,  -209,   230,   265,
     256,   257,   258,   259,   260,   261,   262,   252,   195,  -209,
     253,  -209,  -209,    69,   221,   223,   226,   232,    99,   254,
     255,  -209,  -209,   278,   208,   208,   208,   208,   208,   208,
     263,   168,  -209,   264,     2,   267,     4,     5,     6,     9,
    -209,  -209,   168,   168,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,   266,   283,  -209,  -209,   268,  -209,  -209,   269,  -209,
     270,  -209,   271,  -209,   272,   273,   275,   274,  -209,   276,
     279,   280,   281,   282,  -209,  -209,    60,  -209,  -209,  -209,
    -209,  -209,   252,  -209
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
       0,     0,     0,     0,     0,     0,     0,   106,   106,     0,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,    23,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   102,     0,     0,
      31,    29,     0,     0,   112,     0,     0,     0,     0,     0,
      28,    37,     0,     0,     0,     0,     0,     0,   106,   106,
     106,     0,   110,     0,    53,     0,     0,     0,    63,     0,
      49,    39,     0,     0,     0,    95,    95,    95,    95,    95,
      95,     0,   107,   104,   105,    84,     0,     0,   112,    30,
       0,    51,    57,    58,    59,     0,    60,     0,   114,    61,
       0,     0,   112,     0,     0,     0,    44,    47,    48,    45,
      46,    42,     0,     0,     0,    90,    89,    91,    92,    94,
      93,   106,   106,   110,     0,     0,    55,    53,     0,     0,
     123,   124,   125,   126,   127,   128,   129,     0,     0,     0,
       0,   113,     0,    65,    63,     0,     0,    39,     0,     0,
      36,    34,     0,     0,     0,     0,     0,     0,   108,   109,
     111,     0,    83,     0,     0,    51,    50,     0,   130,   118,
     116,   119,   117,   114,     0,    64,    62,     0,    40,    38,
      43,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,    55,    54,    52,     0,     0,   115,     0,     0,     0,
       0,     0,    69,    68,     0,     0,   131,    41,    34,     0,
       0,     0,     0,     0,     0,     0,     0,    86,   114,    56,
       0,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    32,     0,    95,    95,    95,    95,    95,    95,
       0,   112,    88,     0,     0,     0,     0,     0,     0,     0,
      70,    71,   112,   112,    33,    97,    96,    98,    99,   101,
     100,     0,     0,   122,    73,     0,    72,    75,     0,    77,
       0,    81,     0,    79,     0,     0,     0,     0,    85,     0,
       0,     0,     0,     0,    66,    67,     0,    74,    76,    78,
      82,    80,    86,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,  -209,  -209,  -206,  -185,  -209,  -209,   102,   156,
    -209,  -209,  -209,  -209,    83,   134,    72,  -124,  -209,  -209,
     111,   170,  -209,  -209,  -209,   -30,   -22,  -209,  -108,  -209,
     -47,   153,  -128,  -208,  -103,  -134,  -209
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   223,   191,    30,    31,   145,   111,
     221,   151,   112,    32,   168,   131,   204,   137,    33,    34,
     142,   108,   244,   245,    35,   281,   257,    49,   155,    50,
      76,   128,   106,   181,   258,   178,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     165,    77,   138,   179,   182,   236,   166,   224,   156,   157,
     158,   159,   160,    37,   185,    38,   183,   126,   250,   304,
      51,   307,   309,   311,    92,    54,   313,    93,   132,   133,
     134,    74,    74,   136,    52,    53,   305,   248,   308,   310,
     312,   127,   271,   314,   132,   133,   134,    75,   121,   136,
     282,   122,   123,   124,   210,   212,     2,    40,    55,    41,
       3,     4,    39,    56,    58,     5,     6,     7,     8,     9,
      10,    11,    78,   234,    57,    12,    59,   213,    60,   231,
      61,    13,    14,    42,    43,    44,    45,    46,    15,    16,
     237,   238,   239,   240,   241,   146,   147,   148,   149,   150,
      17,   170,   171,   172,   173,   174,   175,   176,   177,    99,
     261,    62,   100,    66,   198,   199,   132,   133,   134,   135,
     169,   136,    47,   161,   251,    48,   162,   252,   284,   242,
      64,   285,   243,   170,   171,   172,   173,   174,   175,   176,
     177,   132,   133,   134,   209,    63,   136,   132,   133,   134,
     211,    65,   136,   302,   132,   133,   134,   260,   290,   136,
      67,   291,    68,    69,   315,   316,   295,   296,   297,   298,
     299,   300,   193,   194,   195,   196,   197,    70,    71,    72,
      73,    79,    80,    74,    81,    82,    83,    84,    86,    85,
      87,    88,    89,    90,    91,    94,    95,    96,    97,    98,
     101,   114,   102,   104,   103,   107,   105,   125,   129,   115,
     116,   117,   109,   110,   113,   118,   119,   120,   130,   139,
     140,   141,   143,   152,   144,   153,   154,   164,   163,   167,
     186,   188,   202,   189,   180,   190,   192,   126,   206,   201,
     203,   207,   208,   214,   216,   217,   219,   225,   222,   226,
     230,   246,   220,   227,   228,   229,   253,   232,   263,   235,
     254,   247,   249,   264,   269,   265,   266,   267,   272,   255,
     268,   256,   262,   273,   274,   275,   276,   277,   278,   279,
     286,   294,   287,   270,   306,   288,   318,   283,   233,   218,
     324,   289,   325,   327,   280,   215,   328,   329,   330,   331,
     187,   205,   333,   259,   332,     0,   301,     0,     0,     0,
       0,   184,     0,   292,   293,   326,   200,     0,     0,     0,
       0,     0,     0,   303,     0,   317,     0,   319,   320,   321,
     322,   323
};

static const yytype_int16 yycheck[] =
{
     128,    48,   105,   137,    16,   213,   130,   192,   116,   117,
     118,   119,   120,     6,   142,     8,   140,    18,   224,    17,
      59,    17,    17,    17,    59,     3,    17,    62,    56,    57,
      58,    18,    18,    61,     7,     8,    34,   222,    34,    34,
      34,    42,   248,    34,    56,    57,    58,    34,    34,    61,
     258,    98,    99,   100,   178,   179,     0,     6,    35,     8,
       4,     5,    55,    37,     3,     9,    10,    11,    12,    13,
      14,    15,    37,   207,    59,    19,     3,   180,     3,   203,
       3,    25,    26,    20,    21,    22,    23,    24,    32,    33,
      20,    21,    22,    23,    24,    27,    28,    29,    30,    31,
      44,    47,    48,    49,    50,    51,    52,    53,    54,    59,
     234,     3,    62,     8,   161,   162,    56,    57,    58,    59,
      34,    61,    59,    59,    59,    62,    62,    62,    59,    59,
      59,    62,    62,    47,    48,    49,    50,    51,    52,    53,
      54,    56,    57,    58,    59,    45,    61,    56,    57,    58,
      59,    59,    61,   281,    56,    57,    58,    59,    59,    61,
      59,    62,    59,    16,   292,   293,   274,   275,   276,   277,
     278,   279,    20,    21,    22,    23,    24,    16,    16,    16,
      16,    37,     3,    18,     3,    37,    59,    59,    46,    40,
      16,    41,    59,     3,     3,    59,    59,    59,    59,    59,
      59,    41,    59,    36,    59,    59,    38,     3,     3,    17,
      17,    17,    61,    59,    59,    17,    17,    17,    16,     3,
      47,    18,    35,    16,    18,    59,    18,    43,    59,    18,
       6,    17,     3,    16,    39,    59,    16,    18,     3,    59,
      18,    59,    53,     9,     3,    59,     3,    16,    18,    16,
      41,     3,    56,    16,    16,    16,    59,    17,    16,    34,
      59,    17,    17,    16,    37,    16,    16,    16,     3,    59,
      34,    59,    59,    17,    17,    17,    17,    17,    17,    17,
      59,     3,    59,    37,    17,    59,     3,    34,   205,   187,
      17,    59,    17,    17,    42,   184,    17,    17,    17,    17,
     144,   167,   332,   231,   326,    -1,    43,    -1,    -1,    -1,
      -1,   141,    -1,    59,    59,    41,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    59,    -1,    59,    59,    59,
      59,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    65,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    25,    26,    32,    33,    44,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      80,    81,    87,    92,    93,    98,   110,     6,     8,    55,
       6,     8,    20,    21,    22,    23,    24,    59,    62,   101,
     103,    59,     7,     8,     3,    35,    37,    59,     3,     3,
       3,     3,     3,    45,    59,    59,     8,    59,    59,    16,
      16,    16,    16,    16,    18,    34,   104,   104,    37,    37,
       3,     3,    37,    59,    59,    40,    46,    16,    41,    59,
       3,     3,    59,    62,    59,    59,    59,    59,    59,    59,
      62,    59,    59,    59,    36,    38,   106,    59,    95,    61,
      59,    83,    86,    59,    41,    17,    17,    17,    17,    17,
      17,    34,   104,   104,   104,     3,    18,    42,   105,     3,
      16,    89,    56,    57,    58,    59,    61,    91,   108,     3,
      47,    18,    94,    35,    18,    82,    27,    28,    29,    30,
      31,    85,    16,    59,    18,   102,   102,   102,   102,   102,
     102,    59,    62,    59,    43,   106,    91,    18,    88,    34,
      47,    48,    49,    50,    51,    52,    53,    54,   109,   109,
      39,   107,    16,    91,    95,   106,     6,    83,    17,    16,
      59,    79,    16,    20,    21,    22,    23,    24,   104,   104,
     105,    59,     3,    18,    90,    89,     3,    59,    53,    59,
      91,    59,    91,   108,     9,    94,     3,    59,    82,     3,
      56,    84,    18,    78,    79,    16,    16,    16,    16,    16,
      41,    91,    17,    88,   109,    34,   107,    20,    21,    22,
      23,    24,    59,    62,    96,    97,     3,    17,    79,    17,
      78,    59,    62,    59,    59,    59,    59,   100,   108,    90,
      59,    91,    59,    16,    16,    16,    16,    16,    34,    37,
      37,    78,     3,    17,    17,    17,    17,    17,    17,    17,
      42,    99,   107,    34,    59,    62,    59,    59,    59,    59,
      59,    62,    59,    59,     3,   102,   102,   102,   102,   102,
     102,    43,   106,    59,    17,    34,    17,    17,    34,    17,
      34,    17,    34,    17,    34,   106,   106,    59,     3,    59,
      59,    59,    59,    59,    17,    17,    41,    17,    17,    17,
      17,    17,   100,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    77,    78,    78,    79,    80,    81,    82,
      82,    83,    83,    84,    85,    85,    85,    85,    85,    86,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    91,
      91,    92,    93,    94,    94,    95,    95,    95,    96,    96,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    98,    99,    99,   100,   101,
     101,   101,   101,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   103,   103,   103,   103,   104,   104,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     109,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       5,     3,    10,    11,     0,     3,     1,     4,     8,     0,
       3,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       7,     0,     3,     0,     4,     0,     3,     1,     1,     1,
       1,     5,     7,     0,     3,     3,     9,     9,     1,     1,
       3,     3,     4,     4,     6,     4,     6,     4,     6,     4,
       6,     4,     6,     7,     5,    12,     0,     6,     2,     5,
       5,     5,     5,     5,     5,     0,     6,     6,     6,     6,
       6,     6,     2,     2,     4,     4,     0,     3,     5,     5,
       0,     3,     0,     3,     0,     3,     3,     3,     3,     3,
       5,     5,     7,     1,     1,     1,     1,     1,     1,     1,
       2,     8
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
#line 177 "./src/observer/sql/parser/yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1460 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 182 "./src/observer/sql/parser/yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1468 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 187 "./src/observer/sql/parser/yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1476 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 193 "./src/observer/sql/parser/yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1484 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 199 "./src/observer/sql/parser/yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1492 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 205 "./src/observer/sql/parser/yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1500 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 211 "./src/observer/sql/parser/yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1509 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 217 "./src/observer/sql/parser/yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1517 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 223 "./src/observer/sql/parser/yacc_sql.y"
                                {
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
    }
#line 1526 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 231 "./src/observer/sql/parser/yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1535 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 239 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
		}
#line 1544 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 244 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
		}
#line 1553 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA index_attr index_attr_list  */
#line 252 "./src/observer/sql/parser/yacc_sql.y"
                                           { }
#line 1559 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 36: /* index_attr: ID  */
#line 257 "./src/observer/sql/parser/yacc_sql.y"
                {
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
		}
#line 1567 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 37: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 264 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1576 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 38: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 271 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1588 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 281 "./src/observer/sql/parser/yacc_sql.y"
                                   {    }
#line 1594 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 286 "./src/observer/sql/parser/yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-3].number), (yyvsp[-1].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1609 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type  */
#line 297 "./src/observer/sql/parser/yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[0].number), 4);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1624 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 43: /* number: NUMBER  */
#line 309 "./src/observer/sql/parser/yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1630 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 44: /* type: INT_T  */
#line 312 "./src/observer/sql/parser/yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1636 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 45: /* type: DATE_T  */
#line 313 "./src/observer/sql/parser/yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 1642 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 46: /* type: TEXT_T  */
#line 314 "./src/observer/sql/parser/yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 1648 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 47: /* type: STRING_T  */
#line 315 "./src/observer/sql/parser/yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1654 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 48: /* type: FLOAT_T  */
#line 316 "./src/observer/sql/parser/yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1660 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 49: /* ID_get: ID  */
#line 320 "./src/observer/sql/parser/yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1669 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 50: /* insert: INSERT INTO ID VALUES record record_list SEMICOLON  */
#line 329 "./src/observer/sql/parser/yacc_sql.y"
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
#line 1689 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 52: /* record_list: COMMA record record_list  */
#line 345 "./src/observer/sql/parser/yacc_sql.y"
                                        {

		}
#line 1697 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 54: /* record: LBRACE value value_list RBRACE  */
#line 352 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		}
#line 1706 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 56: /* value_list: COMMA value value_list  */
#line 357 "./src/observer/sql/parser/yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1714 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 57: /* value: NUMBER  */
#line 362 "./src/observer/sql/parser/yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1722 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 58: /* value: FLOAT  */
#line 365 "./src/observer/sql/parser/yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1730 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 59: /* value: DATEE  */
#line 368 "./src/observer/sql/parser/yacc_sql.y"
               {
			(yyvsp[0].dates) = substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].dates));
		}
#line 1739 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 60: /* value: SSS  */
#line 372 "./src/observer/sql/parser/yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1748 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 61: /* delete: DELETE FROM ID where SEMICOLON  */
#line 380 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1760 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 62: /* update: UPDATE ID SET update_attr update_attr_list where SEMICOLON  */
#line 390 "./src/observer/sql/parser/yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1770 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 65: /* update_attr: ID EQ value  */
#line 404 "./src/observer/sql/parser/yacc_sql.y"
                {
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			CONTEXT->value_length = 0;
		}
#line 1780 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 66: /* update_attr: ID EQ LBRACE SELECT update_select_attr FROM ID where RBRACE  */
#line 410 "./src/observer/sql/parser/yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 1792 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 67: /* update_attr: ID EQ LBRACE SELECT update_agg FROM ID where RBRACE  */
#line 418 "./src/observer/sql/parser/yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 1804 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 68: /* update_select_attr: STAR  */
#line 428 "./src/observer/sql/parser/yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 1814 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 69: /* update_select_attr: ID  */
#line 433 "./src/observer/sql/parser/yacc_sql.y"
         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 1824 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 70: /* update_select_attr: ID DOT ID  */
#line 438 "./src/observer/sql/parser/yacc_sql.y"
                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 1834 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 71: /* update_select_attr: ID DOT STAR  */
#line 443 "./src/observer/sql/parser/yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 1844 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 72: /* update_agg: COUNT_T LBRACE STAR RBRACE  */
#line 451 "./src/observer/sql/parser/yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
#line 1854 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 73: /* update_agg: COUNT_T LBRACE ID RBRACE  */
#line 456 "./src/observer/sql/parser/yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 1864 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 74: /* update_agg: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 461 "./src/observer/sql/parser/yacc_sql.y"
                                          {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 1874 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 75: /* update_agg: MAX_T LBRACE ID RBRACE  */
#line 466 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 1884 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 76: /* update_agg: MAX_T LBRACE ID DOT ID RBRACE  */
#line 471 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 1894 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 77: /* update_agg: MIN_T LBRACE ID RBRACE  */
#line 476 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 1904 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 78: /* update_agg: MIN_T LBRACE ID DOT ID RBRACE  */
#line 481 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 1914 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 79: /* update_agg: SUM_T LBRACE ID RBRACE  */
#line 486 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 1924 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 80: /* update_agg: SUM_T LBRACE ID DOT ID RBRACE  */
#line 491 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 1934 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 81: /* update_agg: AVG_T LBRACE ID RBRACE  */
#line 496 "./src/observer/sql/parser/yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 1944 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 82: /* update_agg: AVG_T LBRACE ID DOT ID RBRACE  */
#line 501 "./src/observer/sql/parser/yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 1954 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 83: /* select: SELECT select_attr FROM ID rel_list where SEMICOLON  */
#line 509 "./src/observer/sql/parser/yacc_sql.y"
                                                       {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;

			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 1974 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 84: /* select: SELECT agg_fun_list_head FROM ID SEMICOLON  */
#line 524 "./src/observer/sql/parser/yacc_sql.y"
                                                    {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		CONTEXT->ssql->flag=SCF_SELECT;
		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 1987 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 85: /* select: SELECT select_attr FROM ID INNER_T JOIN_T ID ON join_cons join_list where SEMICOLON  */
#line 532 "./src/observer/sql/parser/yacc_sql.y"
                                                                                            {
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string));
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-8].string));
			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2004 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 87: /* join_list: INNER_T JOIN_T ID ON join_cons join_list  */
#line 547 "./src/observer/sql/parser/yacc_sql.y"
                                               {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
	}
#line 2012 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 88: /* join_cons: condition condition_list  */
#line 552 "./src/observer/sql/parser/yacc_sql.y"
                                  {	
	}
#line 2019 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 89: /* agg_fun_list_head: COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 556 "./src/observer/sql/parser/yacc_sql.y"
                                                {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2029 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 90: /* agg_fun_list_head: COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 561 "./src/observer/sql/parser/yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2039 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 91: /* agg_fun_list_head: MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 566 "./src/observer/sql/parser/yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2050 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 92: /* agg_fun_list_head: MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 572 "./src/observer/sql/parser/yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2061 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 93: /* agg_fun_list_head: SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 578 "./src/observer/sql/parser/yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2072 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 94: /* agg_fun_list_head: AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 584 "./src/observer/sql/parser/yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2083 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 96: /* agg_fun_list: COMMA COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 593 "./src/observer/sql/parser/yacc_sql.y"
                                                      {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2093 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 97: /* agg_fun_list: COMMA COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 598 "./src/observer/sql/parser/yacc_sql.y"
                                                    {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2103 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 98: /* agg_fun_list: COMMA MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 603 "./src/observer/sql/parser/yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2114 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 99: /* agg_fun_list: COMMA MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 609 "./src/observer/sql/parser/yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre,MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2125 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 100: /* agg_fun_list: COMMA SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 615 "./src/observer/sql/parser/yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2136 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 101: /* agg_fun_list: COMMA AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 621 "./src/observer/sql/parser/yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2147 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 102: /* select_attr: STAR attr_list  */
#line 631 "./src/observer/sql/parser/yacc_sql.y"
                   {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			CONTEXT->ssql->sstr.selection.need_Revere=1;
		}
#line 2158 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 103: /* select_attr: ID attr_list  */
#line 637 "./src/observer/sql/parser/yacc_sql.y"
                   {
			RelAttr attr;
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2169 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 104: /* select_attr: ID DOT ID attr_list  */
#line 643 "./src/observer/sql/parser/yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2179 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 105: /* select_attr: ID DOT STAR attr_list  */
#line 648 "./src/observer/sql/parser/yacc_sql.y"
                               {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2189 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 107: /* attr_list: COMMA ID attr_list  */
#line 656 "./src/observer/sql/parser/yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 2200 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 108: /* attr_list: COMMA ID DOT ID attr_list  */
#line 662 "./src/observer/sql/parser/yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 2211 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 109: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 668 "./src/observer/sql/parser/yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 2222 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 111: /* rel_list: COMMA ID rel_list  */
#line 678 "./src/observer/sql/parser/yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2230 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 113: /* where: WHERE condition condition_list  */
#line 684 "./src/observer/sql/parser/yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2238 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 115: /* condition_list: AND condition condition_list  */
#line 690 "./src/observer/sql/parser/yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2246 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 116: /* condition: ID comOp value  */
#line 696 "./src/observer/sql/parser/yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 2262 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 117: /* condition: value comOp value  */
#line 708 "./src/observer/sql/parser/yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
#line 2286 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 118: /* condition: ID comOp ID  */
#line 728 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2310 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 119: /* condition: value comOp ID  */
#line 748 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2336 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 120: /* condition: ID DOT ID comOp value  */
#line 770 "./src/observer/sql/parser/yacc_sql.y"
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
#line 2361 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 121: /* condition: value comOp ID DOT ID  */
#line 791 "./src/observer/sql/parser/yacc_sql.y"
                {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 2375 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 122: /* condition: ID DOT ID comOp ID DOT ID  */
#line 801 "./src/observer/sql/parser/yacc_sql.y"
        {
			
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2390 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 123: /* comOp: EQ  */
#line 814 "./src/observer/sql/parser/yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2396 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 124: /* comOp: LT  */
#line 815 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2402 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 125: /* comOp: GT  */
#line 816 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2408 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 126: /* comOp: LE  */
#line 817 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2414 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 127: /* comOp: GE  */
#line 818 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2420 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 128: /* comOp: NE  */
#line 819 "./src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2426 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 129: /* comOp: LIKE  */
#line 820 "./src/observer/sql/parser/yacc_sql.y"
               { CONTEXT->comp = LIKE_TO; }
#line 2432 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 130: /* comOp: NOT LIKE  */
#line 821 "./src/observer/sql/parser/yacc_sql.y"
                   { CONTEXT->comp = NOT_LIKE; }
#line 2438 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 131: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 826 "./src/observer/sql/parser/yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2447 "./src/observer/sql/parser/yacc_sql.tab.c"
    break;


#line 2451 "./src/observer/sql/parser/yacc_sql.tab.c"

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

#line 831 "./src/observer/sql/parser/yacc_sql.y"

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
