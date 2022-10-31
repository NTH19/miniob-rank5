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
  context->value_length = 0;
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
  YYSYMBOL_DABIAO = 26,                    /* DABIAO  */
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
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_SET = 41,                       /* SET  */
  YYSYMBOL_ON = 42,                        /* ON  */
  YYSYMBOL_INNER_T = 43,                   /* INNER_T  */
  YYSYMBOL_JOIN_T = 44,                    /* JOIN_T  */
  YYSYMBOL_LOAD = 45,                      /* LOAD  */
  YYSYMBOL_DATA = 46,                      /* DATA  */
  YYSYMBOL_INFILE = 47,                    /* INFILE  */
  YYSYMBOL_EQ = 48,                        /* EQ  */
  YYSYMBOL_LT = 49,                        /* LT  */
  YYSYMBOL_GT = 50,                        /* GT  */
  YYSYMBOL_LE = 51,                        /* LE  */
  YYSYMBOL_GE = 52,                        /* GE  */
  YYSYMBOL_NE = 53,                        /* NE  */
  YYSYMBOL_EXIST_T = 54,                   /* EXIST_T  */
  YYSYMBOL_IN_T = 55,                      /* IN_T  */
  YYSYMBOL_LIKE = 56,                      /* LIKE  */
  YYSYMBOL_NOT = 57,                       /* NOT  */
  YYSYMBOL_IS = 58,                        /* IS  */
  YYSYMBOL_NULLL = 59,                     /* NULLL  */
  YYSYMBOL_NULLABLE = 60,                  /* NULLABLE  */
  YYSYMBOL_UNIQUE = 61,                    /* UNIQUE  */
  YYSYMBOL_NUMBER = 62,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 63,                     /* FLOAT  */
  YYSYMBOL_DATEE = 64,                     /* DATEE  */
  YYSYMBOL_ID = 65,                        /* ID  */
  YYSYMBOL_PATH = 66,                      /* PATH  */
  YYSYMBOL_SSS = 67,                       /* SSS  */
  YYSYMBOL_STAR = 68,                      /* STAR  */
  YYSYMBOL_STRING_V = 69,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_commands = 71,                  /* commands  */
  YYSYMBOL_command = 72,                   /* command  */
  YYSYMBOL_exit = 73,                      /* exit  */
  YYSYMBOL_help = 74,                      /* help  */
  YYSYMBOL_sync = 75,                      /* sync  */
  YYSYMBOL_begin = 76,                     /* begin  */
  YYSYMBOL_commit = 77,                    /* commit  */
  YYSYMBOL_rollback = 78,                  /* rollback  */
  YYSYMBOL_drop_table = 79,                /* drop_table  */
  YYSYMBOL_show_tables = 80,               /* show_tables  */
  YYSYMBOL_show_indexes = 81,              /* show_indexes  */
  YYSYMBOL_desc_table = 82,                /* desc_table  */
  YYSYMBOL_create_index = 83,              /* create_index  */
  YYSYMBOL_index_attr_list = 84,           /* index_attr_list  */
  YYSYMBOL_index_attr = 85,                /* index_attr  */
  YYSYMBOL_drop_index = 86,                /* drop_index  */
  YYSYMBOL_create_table = 87,              /* create_table  */
  YYSYMBOL_attr_def_list = 88,             /* attr_def_list  */
  YYSYMBOL_attr_def = 89,                  /* attr_def  */
  YYSYMBOL_number = 90,                    /* number  */
  YYSYMBOL_type = 91,                      /* type  */
  YYSYMBOL_ID_get = 92,                    /* ID_get  */
  YYSYMBOL_dummy = 93,                     /* dummy  */
  YYSYMBOL_insert = 94,                    /* insert  */
  YYSYMBOL_record_list = 95,               /* record_list  */
  YYSYMBOL_record = 96,                    /* record  */
  YYSYMBOL_value_list = 97,                /* value_list  */
  YYSYMBOL_value = 98,                     /* value  */
  YYSYMBOL_delete = 99,                    /* delete  */
  YYSYMBOL_update = 100,                   /* update  */
  YYSYMBOL_update_attr_list = 101,         /* update_attr_list  */
  YYSYMBOL_update_attr = 102,              /* update_attr  */
  YYSYMBOL_update_select_attr = 103,       /* update_select_attr  */
  YYSYMBOL_update_agg = 104,               /* update_agg  */
  YYSYMBOL_select = 105,                   /* select  */
  YYSYMBOL_sub_query = 106,                /* sub_query  */
  YYSYMBOL_join_list = 107,                /* join_list  */
  YYSYMBOL_join_cons = 108,                /* join_cons  */
  YYSYMBOL_agg_fun_list_head = 109,        /* agg_fun_list_head  */
  YYSYMBOL_agg_fun_list = 110,             /* agg_fun_list  */
  YYSYMBOL_select_attr = 111,              /* select_attr  */
  YYSYMBOL_attr_list = 112,                /* attr_list  */
  YYSYMBOL_rel_list = 113,                 /* rel_list  */
  YYSYMBOL_where = 114,                    /* where  */
  YYSYMBOL_condition_list = 115,           /* condition_list  */
  YYSYMBOL_condition = 116,                /* condition  */
  YYSYMBOL_in_cells = 117,                 /* in_cells  */
  YYSYMBOL_reverseComp = 118,              /* reverseComp  */
  YYSYMBOL_comOp = 119,                    /* comOp  */
  YYSYMBOL_load_data = 120                 /* load_data  */
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
#define YYLAST   617

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  515

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


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
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   159,   159,   161,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   186,   191,   196,   202,   208,   214,   220,   226,
     232,   240,   247,   252,   259,   261,   265,   272,   279,   288,
     290,   294,   305,   316,   327,   338,   349,   362,   365,   366,
     367,   368,   369,   372,   379,   385,   395,   396,   401,   402,
     407,   408,   413,   416,   419,   423,   427,   433,   443,   451,
     453,   457,   463,   471,   482,   487,   492,   497,   505,   510,
     515,   520,   525,   530,   535,   540,   545,   550,   555,   565,
     578,   588,   601,   622,   642,   662,   682,   701,   720,   739,
     763,   765,   770,   775,   780,   785,   791,   797,   803,   810,
     812,   817,   822,   828,   834,   840,   850,   856,   862,   867,
     873,   875,   881,   887,   895,   897,   901,   903,   906,   908,
     912,   924,   934,   954,   976,   997,  1007,  1018,  1024,  1030,
    1037,  1045,  1053,  1061,  1068,  1075,  1082,  1089,  1097,  1105,
    1113,  1121,  1129,  1137,  1145,  1153,  1161,  1169,  1177,  1185,
    1192,  1196,  1197,  1198,  1199,  1200,  1201,  1204,  1205,  1206,
    1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,
    1217,  1221
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
  "COUNT_T", "MAX_T", "MIN_T", "AVG_T", "SUM_T", "TRX_COMMIT", "DABIAO",
  "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T", "TEXT_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET",
  "ON", "INNER_T", "JOIN_T", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT",
  "LE", "GE", "NE", "EXIST_T", "IN_T", "LIKE", "NOT", "IS", "NULLL",
  "NULLABLE", "UNIQUE", "NUMBER", "FLOAT", "DATEE", "ID", "PATH", "SSS",
  "STAR", "STRING_V", "$accept", "commands", "command", "exit", "help",
  "sync", "begin", "commit", "rollback", "drop_table", "show_tables",
  "show_indexes", "desc_table", "create_index", "index_attr_list",
  "index_attr", "drop_index", "create_table", "attr_def_list", "attr_def",
  "number", "type", "ID_get", "dummy", "insert", "record_list", "record",
  "value_list", "value", "delete", "update", "update_attr_list",
  "update_attr", "update_select_attr", "update_agg", "select", "sub_query",
  "join_list", "join_cons", "agg_fun_list_head", "agg_fun_list",
  "select_attr", "attr_list", "rel_list", "where", "condition_list",
  "condition", "in_cells", "reverseComp", "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-451)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -451,   118,  -451,    22,    15,    17,    23,    26,    87,   -11,
      61,    40,   107,   108,   112,   116,   121,    88,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,    75,    77,   140,
      93,    95,   134,   163,   227,   235,   239,     1,   240,   237,
     238,   275,   277,   243,  -451,   218,   219,   241,  -451,  -451,
    -451,  -451,  -451,   244,   269,   245,   221,   285,   287,   -33,
     228,   229,   230,   231,   232,    -3,  -451,  -451,   233,   234,
    -451,  -451,   236,   255,   261,   242,   246,   247,   249,   260,
    -451,  -451,   286,   288,   289,   291,   292,   293,    13,   240,
     240,   261,     0,   301,   295,    30,   312,   268,   299,   282,
    -451,   303,   171,   306,   258,   307,   307,   307,   307,   307,
     307,    70,  -451,  -451,  -451,   321,   262,   284,   261,  -451,
     190,   308,   320,   314,   278,  -451,  -451,  -451,  -451,   156,
    -451,   167,   294,  -451,    50,   242,   261,   325,   247,   316,
    -451,  -451,  -451,  -451,  -451,    84,   270,   323,   217,  -451,
    -451,  -451,  -451,  -451,  -451,   240,   240,  -451,   318,   272,
     337,   324,   295,   338,   133,   326,   320,   328,   280,   330,
     331,   332,   333,   334,   335,  -451,   336,  -451,   206,   296,
     102,  -451,  -451,  -451,  -451,  -451,  -451,  -451,   209,   111,
      30,  -451,   345,  -451,   299,   352,   297,   303,   353,   298,
     300,  -451,  -451,   339,   270,   342,   347,   348,   349,   350,
    -451,  -451,  -451,   319,  -451,   190,   351,   308,  -451,   354,
     355,   356,   357,   358,   101,   144,   359,   320,   178,   320,
     320,   320,   320,   320,   320,     5,  -451,   361,  -451,  -451,
    -451,  -451,  -451,   340,  -451,   294,    33,  -451,  -451,   364,
    -451,  -451,  -451,   362,  -451,   270,   363,   339,    81,   304,
     313,   317,   322,    30,   324,  -451,  -451,    94,   327,   329,
     344,   346,   360,   365,  -451,  -451,  -451,  -451,  -451,   367,
     366,  -451,   368,   370,   372,   374,   375,   377,   379,   380,
     212,   183,   381,   382,   383,   384,   385,   386,   324,   393,
     395,     5,   369,  -451,   397,   398,   399,   400,   401,   387,
    -451,   343,   388,  -451,   120,   339,   394,   402,   403,   404,
     406,   407,   410,   411,   389,   294,  -451,   405,   412,   408,
     409,   413,   414,   415,   318,   320,  -451,  -451,   320,   320,
     320,   320,   320,   320,   320,   417,   416,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,   418,   419,  -451,
     103,   373,   376,   390,   391,   191,   392,   396,   378,  -451,
    -451,  -451,   436,   307,   307,   307,   307,   307,   307,   420,
     261,  -451,   421,   422,   423,   424,   425,   426,   427,  -451,
     428,   429,   430,   433,   435,   437,   441,   442,     5,   431,
    -451,  -451,     7,   445,     9,    69,    85,    86,  -451,  -451,
     261,   261,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
     432,   439,   446,   434,   448,   449,   450,   451,   318,   261,
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,   452,   453,
    -451,  -451,   438,  -451,  -451,   440,  -451,   443,  -451,   444,
    -451,   447,   454,   455,   456,  -451,   457,  -451,   462,   463,
     464,   466,  -451,  -451,  -451,  -451,   458,   459,   460,   461,
     465,  -451,  -451,    30,   467,   261,   468,   469,   470,   471,
     261,  -451,  -451,  -451,  -451,  -451,   389,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -451,   261,   261,   261,   261,   261,
    -451,  -451,  -451,  -451,  -451
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
       0,     0,     0,     0,     0,     0,     0,   120,   120,     0,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,    23,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,   116,     0,     0,
      31,    29,     0,     0,   126,     0,     0,     0,     0,     0,
      28,    37,     0,     0,     0,     0,     0,     0,   120,   120,
     120,   126,   124,     0,    58,     0,     0,     0,    69,     0,
      53,    39,     0,     0,     0,   109,   109,   109,   109,   109,
     109,     0,   121,   118,   119,     0,     0,     0,   126,    30,
       0,    56,     0,     0,     0,    66,    62,    63,    64,     0,
      65,     0,   128,    67,     0,     0,   126,     0,     0,     0,
      48,    51,    52,    49,    50,    44,     0,     0,     0,   104,
     103,   105,   106,   108,   107,   120,   120,    90,   124,     0,
       0,    60,    58,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   177,   174,   173,     0,   180,
       0,   167,   168,   169,   170,   171,   172,   174,     0,     0,
       0,   127,     0,    71,    69,     0,     0,    39,     0,     0,
       0,    46,    36,    34,     0,     0,     0,     0,     0,     0,
     122,   123,   125,     0,    89,     0,     0,    56,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   176,   175,   178,   179,
     132,   130,   175,   133,   131,   128,     0,    70,    68,     0,
      40,    38,    47,     0,    45,     0,     0,    34,     0,     0,
       0,     0,     0,     0,    60,    59,    57,     0,     0,     0,
       0,     0,     0,     0,   161,   162,   163,   164,   165,   166,
       0,   137,     0,   167,   168,   169,   170,   171,   172,   174,
       0,     0,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,   129,     0,     0,     0,     0,     0,    75,
      74,     0,     0,   181,    41,    34,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   128,    61,     0,     0,     0,
       0,     0,     0,     0,   124,     0,   139,   138,     0,     0,
       0,     0,     0,     0,     0,   175,     0,   134,   147,   148,
     149,   150,   151,   152,   160,   143,   140,     0,     0,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
      35,    32,     0,   109,   109,   109,   109,   109,   109,     0,
     126,   102,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   141,     0,     0,     0,     0,     0,     0,    76,    77,
     126,   126,    42,    33,   111,   110,   112,   113,   115,   114,
       0,     0,     0,     0,     0,     0,     0,     0,   124,   126,
     159,   153,   154,   155,   156,   157,   158,   144,     0,     0,
     136,    79,     0,    78,    81,     0,    83,     0,    87,     0,
      85,     0,     0,     0,     0,    91,     0,    54,     0,     0,
       0,     0,    54,    93,   146,   142,     0,     0,     0,     0,
       0,    72,    73,     0,     0,   126,     0,     0,     0,     0,
     126,    80,    82,    84,    88,    86,   100,    54,    94,    54,
      54,    54,    54,    92,   101,   126,   126,   126,   126,   126,
      95,    96,    97,    99,    98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,  -451,
    -451,  -451,  -451,  -451,  -251,  -194,  -451,  -451,   211,   371,
    -451,  -451,  -451,  -450,  -451,   252,   302,  -245,  -129,  -451,
    -451,   276,   472,  -451,  -451,  -451,  -164,   -23,    -2,  -451,
    -114,  -451,   -40,  -161,  -101,  -244,   -92,  -302,  -451,  -131,
    -451
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   266,   213,    30,    31,   149,   111,
     263,   155,   112,   439,    32,   173,   131,   226,   141,    33,
      34,   146,   108,   321,   322,    35,   175,   390,   334,    49,
     159,    50,    76,   128,   106,   201,   335,   310,   290,   190,
      36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     125,   171,   160,   161,   162,   163,   164,   222,    77,   368,
     199,   313,   236,   142,   174,   203,   327,   485,   126,    74,
     267,    40,   490,    41,   451,    55,   454,   170,    37,   336,
      38,    74,    92,    52,    53,    93,    75,    42,    43,    44,
      45,    46,   452,   127,   455,   205,   132,   505,   121,   506,
     507,   508,   509,   314,   315,   316,   317,   318,   122,   123,
     124,   251,    99,   364,   135,   100,   202,   136,   137,   138,
     254,   325,   140,   292,   380,   302,   303,   304,   305,   306,
     307,   309,    47,    39,   133,    48,   456,   134,    51,   135,
      54,   391,   136,   137,   138,   139,   274,   140,   319,    56,
     209,   320,   458,   460,   457,    57,   449,   301,   255,   135,
      58,    59,   136,   137,   138,    60,   308,   140,     2,    61,
     459,   461,     3,     4,    62,   220,   221,     5,     6,     7,
       8,     9,    10,    11,    63,   165,   282,    12,   166,   283,
      64,   210,    65,    13,   211,    14,   328,   367,    66,   329,
      69,    15,    16,   229,   230,   231,   232,   233,    67,   337,
      68,   135,   338,    17,   136,   137,   138,   250,   412,   140,
     135,   413,   357,   136,   137,   138,   253,   378,   140,    70,
     379,   400,   308,   399,   401,   402,   403,   404,   405,   406,
     407,   178,   284,   285,   286,   287,   288,   289,   234,   150,
     151,   152,   153,   154,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   191,   192,   193,   194,   195,
     196,   185,   197,   187,   198,   189,   293,   294,   295,   296,
     297,   298,   185,   299,   187,   300,   189,   215,   216,   217,
     218,   219,   135,    71,   448,   136,   137,   138,   356,   135,
     140,    72,   136,   137,   138,    73,   418,   140,    74,   419,
     246,   247,   248,   246,   252,   248,   246,   355,   248,   424,
     425,   426,   427,   428,   429,    78,    79,   472,    80,   308,
      81,    82,    85,    83,    84,    87,    89,    88,    90,   431,
      91,    86,   104,    94,    95,    96,    97,    98,   101,   102,
     105,   103,   114,   115,   129,   116,   117,   107,   118,   119,
     120,   130,   110,   109,   113,   143,   144,   145,   147,   462,
     463,   148,   156,   157,   167,   158,   172,   168,   169,   174,
     176,   206,   177,   208,   200,   212,   126,   223,   473,   214,
     224,   228,   225,   235,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   249,   256,   258,   261,   265,   268,   264,
     262,   273,   259,   269,   270,   271,   272,   323,   275,   330,
     277,   278,   279,   280,   281,   312,   291,   311,   331,   324,
     326,   376,   332,   345,   498,   347,   348,   333,   349,   503,
     350,   351,   339,   352,   340,   353,   354,   381,   358,   359,
     360,   361,   362,   363,   510,   511,   512,   513,   514,   341,
     365,   342,   366,   370,   371,   372,   373,   374,   260,   382,
     383,   384,   375,   385,   386,   343,   377,   387,   388,   393,
     344,   346,   389,   408,   369,   410,   411,   422,   414,   423,
     392,   415,   465,   394,   395,   440,   441,   442,   396,   397,
     443,   409,   444,   398,   445,   416,   417,   420,   446,   447,
     433,   421,   453,   466,   430,   468,   469,   470,   471,   474,
     475,   481,   482,   504,   227,   491,   492,   493,   494,   276,
     257,   496,   495,     0,     0,     0,   432,     0,   434,   435,
     436,   437,   438,     0,     0,   484,   450,   464,   483,   467,
     486,   487,   488,   476,   489,   477,     0,     0,   478,   479,
       0,     0,   480,     0,     0,     0,     0,     0,     0,   207,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   497,   499,   500,   501,   502,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   204
};

static const yytype_int16 yycheck[] =
{
     101,   130,   116,   117,   118,   119,   120,   168,    48,   311,
     141,   255,   176,   105,     9,   144,   267,   467,    18,    18,
     214,     6,   472,     8,    17,    36,    17,   128,     6,   274,
       8,    18,    65,     7,     8,    68,    35,    20,    21,    22,
      23,    24,    35,    43,    35,   146,    16,   497,    35,   499,
     500,   501,   502,    20,    21,    22,    23,    24,    98,    99,
     100,   190,    65,   308,    59,    68,    16,    62,    63,    64,
     199,   265,    67,   237,   325,   239,   240,   241,   242,   243,
     244,   245,    65,    61,    54,    68,    17,    57,    65,    59,
       3,   335,    62,    63,    64,    65,   225,    67,    65,    38,
      16,    68,    17,    17,    35,    65,   408,   238,   200,    59,
       3,     3,    62,    63,    64,     3,   245,    67,     0,     3,
      35,    35,     4,     5,     3,   165,   166,     9,    10,    11,
      12,    13,    14,    15,    46,    65,    35,    19,    68,    38,
      65,    57,    65,    25,    60,    27,    65,   311,     8,    68,
      16,    33,    34,    20,    21,    22,    23,    24,    65,    65,
      65,    59,    68,    45,    62,    63,    64,    65,    65,    67,
      59,    68,   301,    62,    63,    64,    65,    57,    67,    16,
      60,   345,   311,   344,   348,   349,   350,   351,   352,   353,
     354,    35,    48,    49,    50,    51,    52,    53,    65,    28,
      29,    30,    31,    32,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    20,    21,    22,
      23,    24,    59,    16,   408,    62,    63,    64,    65,    59,
      67,    16,    62,    63,    64,    16,    65,    67,    18,    68,
      54,    55,    56,    54,    55,    56,    54,    55,    56,   383,
     384,   385,   386,   387,   388,    38,    38,   438,     3,   408,
       3,    38,    41,    65,    65,    16,    65,    42,     3,   390,
       3,    47,    37,    65,    65,    65,    65,    65,    65,    65,
      39,    65,    42,    17,     3,    17,    17,    65,    17,    17,
      17,    16,    65,    67,    65,     3,    48,    18,    36,   420,
     421,    18,    16,    65,     3,    18,    18,    65,    44,     9,
      16,     6,    54,    17,    40,    65,    18,    65,   439,    16,
       3,     3,    18,    17,    16,    65,    16,    16,    16,    16,
      16,    16,    16,    57,     9,     3,     3,    18,    16,    59,
      62,    42,    65,    16,    16,    16,    16,     3,    17,    65,
      16,    16,    16,    16,    16,    35,    17,    16,    65,    17,
      17,    38,    65,    16,   485,    17,    16,    65,    16,   490,
      16,    16,    65,    16,    65,    16,    16,     3,    17,    17,
      17,    17,    17,    17,   505,   506,   507,   508,   509,    65,
      17,    65,    17,    16,    16,    16,    16,    16,   207,    17,
      17,    17,    35,    17,    17,    65,    38,    17,    17,    17,
      65,    65,    43,    16,    65,    17,    17,    59,    65,     3,
      35,    65,     3,    35,    35,    17,    17,    17,    35,    35,
      17,    35,    17,    38,    17,    65,    65,    65,    17,    17,
      38,    65,    17,    17,    44,    17,    17,    17,    17,    17,
      17,    17,    17,   496,   172,    17,    17,    17,    17,   227,
     204,   483,    17,    -1,    -1,    -1,    65,    -1,    65,    65,
      65,    65,    65,    -1,    -1,    38,    65,    65,    42,    65,
      38,    38,    38,    65,    38,    65,    -1,    -1,    65,    65,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    65,    65,    65,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    71,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    25,    27,    33,    34,    45,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      86,    87,    94,    99,   100,   105,   120,     6,     8,    61,
       6,     8,    20,    21,    22,    23,    24,    65,    68,   109,
     111,    65,     7,     8,     3,    36,    38,    65,     3,     3,
       3,     3,     3,    46,    65,    65,     8,    65,    65,    16,
      16,    16,    16,    16,    18,    35,   112,   112,    38,    38,
       3,     3,    38,    65,    65,    41,    47,    16,    42,    65,
       3,     3,    65,    68,    65,    65,    65,    65,    65,    65,
      68,    65,    65,    65,    37,    39,   114,    65,   102,    67,
      65,    89,    92,    65,    42,    17,    17,    17,    17,    17,
      17,    35,   112,   112,   112,   114,    18,    43,   113,     3,
      16,    96,    16,    54,    57,    59,    62,    63,    64,    65,
      67,    98,   116,     3,    48,    18,   101,    36,    18,    88,
      28,    29,    30,    31,    32,    91,    16,    65,    18,   110,
     110,   110,   110,   110,   110,    65,    68,     3,    65,    44,
     114,    98,    18,    95,     9,   106,    16,    54,    35,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
     119,    48,    49,    50,    51,    52,    53,    55,    57,   119,
      40,   115,    16,    98,   102,   114,     6,    89,    17,    16,
      57,    60,    65,    85,    16,    20,    21,    22,    23,    24,
     112,   112,   113,    65,     3,    18,    97,    96,     3,    20,
      21,    22,    23,    24,    65,    17,   106,    16,    65,    16,
      16,    16,    16,    16,    16,    16,    54,    55,    56,    57,
      65,    98,    55,    65,    98,   116,     9,   101,     3,    65,
      88,     3,    62,    90,    59,    18,    84,    85,    16,    16,
      16,    16,    16,    42,    98,    17,    95,    16,    16,    16,
      16,    16,    35,    38,    48,    49,    50,    51,    52,    53,
     118,    17,   106,    48,    49,    50,    51,    52,    53,    55,
      57,   119,   106,   106,   106,   106,   106,   106,    98,   106,
     117,    16,    35,   115,    20,    21,    22,    23,    24,    65,
      68,   103,   104,     3,    17,    85,    17,    84,    65,    68,
      65,    65,    65,    65,   108,   116,    97,    65,    68,    65,
      65,    65,    65,    65,    65,    16,    65,    17,    16,    16,
      16,    16,    16,    16,    16,    55,    65,    98,    17,    17,
      17,    17,    17,    17,    97,    17,    17,   106,   117,    65,
      16,    16,    16,    16,    16,    35,    38,    38,    57,    60,
      84,     3,    17,    17,    17,    17,    17,    17,    17,    43,
     107,   115,    35,    17,    35,    35,    35,    35,    38,   113,
     106,   106,   106,   106,   106,   106,   106,   106,    16,    35,
      17,    17,    65,    68,    65,    65,    65,    65,    65,    68,
      65,    65,    59,     3,   110,   110,   110,   110,   110,   110,
      44,   114,    65,    38,    65,    65,    65,    65,    65,    93,
      17,    17,    17,    17,    17,    17,    17,    17,   106,   117,
      65,    17,    35,    17,    17,    35,    17,    35,    17,    35,
      17,    35,   114,   114,    65,     3,    17,    65,    17,    17,
      17,    17,   113,   114,    17,    17,    65,    65,    65,    65,
      65,    17,    17,    42,    38,    93,    38,    38,    38,    38,
      93,    17,    17,    17,    17,    17,   108,    65,   114,    65,
      65,    65,    65,   114,   107,    93,    93,    93,    93,    93,
     114,   114,   114,   114,   114
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    83,    84,    84,    85,    86,    87,    88,
      88,    89,    89,    89,    89,    89,    89,    90,    91,    91,
      91,    91,    91,    92,    93,    94,    95,    95,    96,    96,
      97,    97,    98,    98,    98,    98,    98,    99,   100,   101,
     101,   102,   102,   102,   103,   103,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   105,
     105,   105,   106,   106,   106,   106,   106,   106,   106,   106,
     107,   107,   108,   109,   109,   109,   109,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   111,   111,   111,   111,
     112,   112,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     117,   118,   118,   118,   118,   118,   118,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   120
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
       0,     3,     1,     1,     1,     1,     1,     5,     7,     0,
       3,     3,     9,     9,     1,     1,     3,     3,     4,     4,
       6,     4,     6,     4,     6,     4,     6,     4,     6,     7,
       6,    12,     9,     7,     9,    11,    11,    11,    11,    11,
       0,     6,     2,     5,     5,     5,     5,     5,     5,     0,
       6,     6,     6,     6,     6,     6,     2,     2,     4,     4,
       0,     3,     5,     5,     0,     3,     0,     3,     0,     3,
       3,     3,     3,     3,     5,     5,     7,     4,     5,     5,
       5,     6,     8,     5,     7,     6,     8,     5,     5,     5,
       5,     5,     5,     7,     7,     7,     7,     7,     7,     7,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     2,     2,
       1,     8
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
#line 186 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1601 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 191 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1609 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 196 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1617 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 202 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1625 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 208 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1633 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 214 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1641 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 220 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1650 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 226 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1658 "yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 232 "yacc_sql.y"
                                {
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
    }
#line 1667 "yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 240 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1676 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 248 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
		}
#line 1685 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 253 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
		}
#line 1694 "yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA index_attr index_attr_list  */
#line 261 "yacc_sql.y"
                                           { }
#line 1700 "yacc_sql.tab.c"
    break;

  case 36: /* index_attr: ID  */
#line 266 "yacc_sql.y"
                {
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
		}
#line 1708 "yacc_sql.tab.c"
    break;

  case 37: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 273 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1717 "yacc_sql.tab.c"
    break;

  case 38: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 280 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1729 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 290 "yacc_sql.y"
                                   {    }
#line 1735 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 295 "yacc_sql.y"
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
#line 1750 "yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type LBRACE number RBRACE NOT NULLL  */
#line 306 "yacc_sql.y"
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
#line 1765 "yacc_sql.tab.c"
    break;

  case 43: /* attr_def: ID_get type LBRACE number RBRACE NULLABLE  */
#line 317 "yacc_sql.y"
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
#line 1780 "yacc_sql.tab.c"
    break;

  case 44: /* attr_def: ID_get type  */
#line 328 "yacc_sql.y"
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
#line 1795 "yacc_sql.tab.c"
    break;

  case 45: /* attr_def: ID_get type NOT NULLL  */
#line 339 "yacc_sql.y"
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
#line 1810 "yacc_sql.tab.c"
    break;

  case 46: /* attr_def: ID_get type NULLABLE  */
#line 350 "yacc_sql.y"
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
#line 1825 "yacc_sql.tab.c"
    break;

  case 47: /* number: NUMBER  */
#line 362 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1831 "yacc_sql.tab.c"
    break;

  case 48: /* type: INT_T  */
#line 365 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1837 "yacc_sql.tab.c"
    break;

  case 49: /* type: DATE_T  */
#line 366 "yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 1843 "yacc_sql.tab.c"
    break;

  case 50: /* type: TEXT_T  */
#line 367 "yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 1849 "yacc_sql.tab.c"
    break;

  case 51: /* type: STRING_T  */
#line 368 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1855 "yacc_sql.tab.c"
    break;

  case 52: /* type: FLOAT_T  */
#line 369 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1861 "yacc_sql.tab.c"
    break;

  case 53: /* ID_get: ID  */
#line 373 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1870 "yacc_sql.tab.c"
    break;

  case 54: /* dummy: %empty  */
#line 379 "yacc_sql.y"
      {
		CONTEXT->depth++;
		CONTEXT->sub_con_start[CONTEXT->depth]=CONTEXT->condition_length;
	}
#line 1879 "yacc_sql.tab.c"
    break;

  case 55: /* insert: INSERT INTO ID VALUES record record_list SEMICOLON  */
#line 386 "yacc_sql.y"
        {
		CONTEXT->ssql->flag=SCF_INSERT;//"insert";
		CONTEXT->ssql->sstr.insertion.relation_name = (yyvsp[-4].string);
		CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
		inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-4].string), CONTEXT->values, CONTEXT->value_length,CONTEXT->single_record_length,CONTEXT->record_length);

      	CONTEXT->value_length=0;
	  	CONTEXT->record_length=0;
    }
#line 1893 "yacc_sql.tab.c"
    break;

  case 57: /* record_list: COMMA record record_list  */
#line 396 "yacc_sql.y"
                                        {

		}
#line 1901 "yacc_sql.tab.c"
    break;

  case 59: /* record: LBRACE value value_list RBRACE  */
#line 403 "yacc_sql.y"
                {
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		}
#line 1910 "yacc_sql.tab.c"
    break;

  case 61: /* value_list: COMMA value value_list  */
#line 408 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1918 "yacc_sql.tab.c"
    break;

  case 62: /* value: NUMBER  */
#line 413 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1926 "yacc_sql.tab.c"
    break;

  case 63: /* value: FLOAT  */
#line 416 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1934 "yacc_sql.tab.c"
    break;

  case 64: /* value: DATEE  */
#line 419 "yacc_sql.y"
               {
			(yyvsp[0].dates) = substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].dates));
		}
#line 1943 "yacc_sql.tab.c"
    break;

  case 65: /* value: SSS  */
#line 423 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1952 "yacc_sql.tab.c"
    break;

  case 66: /* value: NULLL  */
#line 427 "yacc_sql.y"
               {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		}
#line 1960 "yacc_sql.tab.c"
    break;

  case 67: /* delete: DELETE FROM ID where SEMICOLON  */
#line 434 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1972 "yacc_sql.tab.c"
    break;

  case 68: /* update: UPDATE ID SET update_attr update_attr_list where SEMICOLON  */
#line 444 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1982 "yacc_sql.tab.c"
    break;

  case 71: /* update_attr: ID EQ value  */
#line 458 "yacc_sql.y"
                {
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			CONTEXT->value_length = 0;
		}
#line 1992 "yacc_sql.tab.c"
    break;

  case 72: /* update_attr: ID EQ LBRACE SELECT update_select_attr FROM ID where RBRACE  */
#line 464 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2004 "yacc_sql.tab.c"
    break;

  case 73: /* update_attr: ID EQ LBRACE SELECT update_agg FROM ID where RBRACE  */
#line 472 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2016 "yacc_sql.tab.c"
    break;

  case 74: /* update_select_attr: STAR  */
#line 482 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2026 "yacc_sql.tab.c"
    break;

  case 75: /* update_select_attr: ID  */
#line 487 "yacc_sql.y"
         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2036 "yacc_sql.tab.c"
    break;

  case 76: /* update_select_attr: ID DOT ID  */
#line 492 "yacc_sql.y"
                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2046 "yacc_sql.tab.c"
    break;

  case 77: /* update_select_attr: ID DOT STAR  */
#line 497 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2056 "yacc_sql.tab.c"
    break;

  case 78: /* update_agg: COUNT_T LBRACE STAR RBRACE  */
#line 505 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
#line 2066 "yacc_sql.tab.c"
    break;

  case 79: /* update_agg: COUNT_T LBRACE ID RBRACE  */
#line 510 "yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2076 "yacc_sql.tab.c"
    break;

  case 80: /* update_agg: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 515 "yacc_sql.y"
                                          {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2086 "yacc_sql.tab.c"
    break;

  case 81: /* update_agg: MAX_T LBRACE ID RBRACE  */
#line 520 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2096 "yacc_sql.tab.c"
    break;

  case 82: /* update_agg: MAX_T LBRACE ID DOT ID RBRACE  */
#line 525 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2106 "yacc_sql.tab.c"
    break;

  case 83: /* update_agg: MIN_T LBRACE ID RBRACE  */
#line 530 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2116 "yacc_sql.tab.c"
    break;

  case 84: /* update_agg: MIN_T LBRACE ID DOT ID RBRACE  */
#line 535 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2126 "yacc_sql.tab.c"
    break;

  case 85: /* update_agg: SUM_T LBRACE ID RBRACE  */
#line 540 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2136 "yacc_sql.tab.c"
    break;

  case 86: /* update_agg: SUM_T LBRACE ID DOT ID RBRACE  */
#line 545 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2146 "yacc_sql.tab.c"
    break;

  case 87: /* update_agg: AVG_T LBRACE ID RBRACE  */
#line 550 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2156 "yacc_sql.tab.c"
    break;

  case 88: /* update_agg: AVG_T LBRACE ID DOT ID RBRACE  */
#line 555 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2166 "yacc_sql.tab.c"
    break;

  case 89: /* select: SELECT select_attr FROM ID rel_list where SEMICOLON  */
#line 565 "yacc_sql.y"
                                                       {
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;//"select";

			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
		}
#line 2184 "yacc_sql.tab.c"
    break;

  case 90: /* select: SELECT agg_fun_list_head FROM ID where SEMICOLON  */
#line 578 "yacc_sql.y"
                                                          {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;

		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2199 "yacc_sql.tab.c"
    break;

  case 91: /* select: SELECT select_attr FROM ID INNER_T JOIN_T ID ON join_cons join_list where SEMICOLON  */
#line 588 "yacc_sql.y"
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
#line 2215 "yacc_sql.tab.c"
    break;

  case 92: /* sub_query: SELECT ID DOT ID FROM ID rel_list dummy where  */
#line 601 "yacc_sql.y"
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
#line 2241 "yacc_sql.tab.c"
    break;

  case 93: /* sub_query: SELECT ID FROM ID rel_list dummy where  */
#line 622 "yacc_sql.y"
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
#line 2266 "yacc_sql.tab.c"
    break;

  case 94: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID dummy where  */
#line 642 "yacc_sql.y"
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
#line 2291 "yacc_sql.tab.c"
    break;

  case 95: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 662 "yacc_sql.y"
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
#line 2316 "yacc_sql.tab.c"
    break;

  case 96: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 682 "yacc_sql.y"
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
#line 2340 "yacc_sql.tab.c"
    break;

  case 97: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 701 "yacc_sql.y"
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
#line 2364 "yacc_sql.tab.c"
    break;

  case 98: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 720 "yacc_sql.y"
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
#line 2388 "yacc_sql.tab.c"
    break;

  case 99: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 739 "yacc_sql.y"
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
#line 2415 "yacc_sql.tab.c"
    break;

  case 101: /* join_list: INNER_T JOIN_T ID ON join_cons join_list  */
#line 765 "yacc_sql.y"
                                               {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
	}
#line 2423 "yacc_sql.tab.c"
    break;

  case 102: /* join_cons: condition condition_list  */
#line 770 "yacc_sql.y"
                                  {	
	}
#line 2430 "yacc_sql.tab.c"
    break;

  case 103: /* agg_fun_list_head: COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 775 "yacc_sql.y"
                                                {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2440 "yacc_sql.tab.c"
    break;

  case 104: /* agg_fun_list_head: COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 780 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2450 "yacc_sql.tab.c"
    break;

  case 105: /* agg_fun_list_head: MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 785 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2461 "yacc_sql.tab.c"
    break;

  case 106: /* agg_fun_list_head: MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 791 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2472 "yacc_sql.tab.c"
    break;

  case 107: /* agg_fun_list_head: SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 797 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2483 "yacc_sql.tab.c"
    break;

  case 108: /* agg_fun_list_head: AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 803 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2494 "yacc_sql.tab.c"
    break;

  case 110: /* agg_fun_list: COMMA COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 812 "yacc_sql.y"
                                                      {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2504 "yacc_sql.tab.c"
    break;

  case 111: /* agg_fun_list: COMMA COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 817 "yacc_sql.y"
                                                    {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2514 "yacc_sql.tab.c"
    break;

  case 112: /* agg_fun_list: COMMA MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 822 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2525 "yacc_sql.tab.c"
    break;

  case 113: /* agg_fun_list: COMMA MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 828 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre,MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2536 "yacc_sql.tab.c"
    break;

  case 114: /* agg_fun_list: COMMA SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 834 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2547 "yacc_sql.tab.c"
    break;

  case 115: /* agg_fun_list: COMMA AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 840 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2558 "yacc_sql.tab.c"
    break;

  case 116: /* select_attr: STAR attr_list  */
#line 850 "yacc_sql.y"
                   {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			CONTEXT->ssql->sstr.selection.need_Revere=1;
		}
#line 2569 "yacc_sql.tab.c"
    break;

  case 117: /* select_attr: ID attr_list  */
#line 856 "yacc_sql.y"
                   {
			RelAttr attr;
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2580 "yacc_sql.tab.c"
    break;

  case 118: /* select_attr: ID DOT ID attr_list  */
#line 862 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2590 "yacc_sql.tab.c"
    break;

  case 119: /* select_attr: ID DOT STAR attr_list  */
#line 867 "yacc_sql.y"
                               {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2600 "yacc_sql.tab.c"
    break;

  case 121: /* attr_list: COMMA ID attr_list  */
#line 875 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 2611 "yacc_sql.tab.c"
    break;

  case 122: /* attr_list: COMMA ID DOT ID attr_list  */
#line 881 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 2622 "yacc_sql.tab.c"
    break;

  case 123: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 887 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 2633 "yacc_sql.tab.c"
    break;

  case 125: /* rel_list: COMMA ID rel_list  */
#line 897 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2641 "yacc_sql.tab.c"
    break;

  case 127: /* where: WHERE condition condition_list  */
#line 903 "yacc_sql.y"
                                     {
	}
#line 2648 "yacc_sql.tab.c"
    break;

  case 129: /* condition_list: AND condition condition_list  */
#line 908 "yacc_sql.y"
                                   {
			}
#line 2655 "yacc_sql.tab.c"
    break;

  case 130: /* condition: ID comOp value  */
#line 913 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 2671 "yacc_sql.tab.c"
    break;

  case 131: /* condition: value comOp value  */
#line 925 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 2685 "yacc_sql.tab.c"
    break;

  case 132: /* condition: ID comOp ID  */
#line 935 "yacc_sql.y"
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
#line 2709 "yacc_sql.tab.c"
    break;

  case 133: /* condition: value comOp ID  */
#line 955 "yacc_sql.y"
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
#line 2735 "yacc_sql.tab.c"
    break;

  case 134: /* condition: ID DOT ID comOp value  */
#line 977 "yacc_sql.y"
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
#line 2760 "yacc_sql.tab.c"
    break;

  case 135: /* condition: value comOp ID DOT ID  */
#line 998 "yacc_sql.y"
                {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 2774 "yacc_sql.tab.c"
    break;

  case 136: /* condition: ID DOT ID comOp ID DOT ID  */
#line 1008 "yacc_sql.y"
        {
			
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2789 "yacc_sql.tab.c"
    break;

  case 137: /* condition: EXIST_T LBRACE sub_query RBRACE  */
#line 1019 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2799 "yacc_sql.tab.c"
    break;

  case 138: /* condition: NOT EXIST_T LBRACE sub_query RBRACE  */
#line 1025 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, NOT_EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2809 "yacc_sql.tab.c"
    break;

  case 139: /* condition: LBRACE sub_query RBRACE reverseComp ID  */
#line 1030 "yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->comp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2821 "yacc_sql.tab.c"
    break;

  case 140: /* condition: ID IN_T LBRACE in_cells RBRACE  */
#line 1037 "yacc_sql.y"
                                       {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2834 "yacc_sql.tab.c"
    break;

  case 141: /* condition: ID NOT IN_T LBRACE in_cells RBRACE  */
#line 1045 "yacc_sql.y"
                                           {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2847 "yacc_sql.tab.c"
    break;

  case 142: /* condition: ID DOT ID NOT IN_T LBRACE in_cells RBRACE  */
#line 1053 "yacc_sql.y"
                                                  {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-7].string), (yyvsp[-5].string));
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2860 "yacc_sql.tab.c"
    break;

  case 143: /* condition: ID IN_T LBRACE sub_query RBRACE  */
#line 1061 "yacc_sql.y"
                                        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2872 "yacc_sql.tab.c"
    break;

  case 144: /* condition: ID DOT ID IN_T LBRACE sub_query RBRACE  */
#line 1068 "yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2884 "yacc_sql.tab.c"
    break;

  case 145: /* condition: ID NOT IN_T LBRACE sub_query RBRACE  */
#line 1075 "yacc_sql.y"
                                            {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2896 "yacc_sql.tab.c"
    break;

  case 146: /* condition: ID DOT ID NOT IN_T LBRACE sub_query RBRACE  */
#line 1082 "yacc_sql.y"
                                                   {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-7].string), (yyvsp[-5].string));
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2908 "yacc_sql.tab.c"
    break;

  case 147: /* condition: ID EQ LBRACE sub_query RBRACE  */
#line 1090 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, EQUAL_TO, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2920 "yacc_sql.tab.c"
    break;

  case 148: /* condition: ID LT LBRACE sub_query RBRACE  */
#line 1098 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, LESS_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2932 "yacc_sql.tab.c"
    break;

  case 149: /* condition: ID GT LBRACE sub_query RBRACE  */
#line 1106 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, GREAT_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2944 "yacc_sql.tab.c"
    break;

  case 150: /* condition: ID LE LBRACE sub_query RBRACE  */
#line 1114 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition,LESS_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2956 "yacc_sql.tab.c"
    break;

  case 151: /* condition: ID GE LBRACE sub_query RBRACE  */
#line 1122 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, GREAT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2968 "yacc_sql.tab.c"
    break;

  case 152: /* condition: ID NE LBRACE sub_query RBRACE  */
#line 1130 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, NOT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2980 "yacc_sql.tab.c"
    break;

  case 153: /* condition: ID DOT ID EQ LBRACE sub_query RBRACE  */
#line 1138 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, EQUAL_TO, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2992 "yacc_sql.tab.c"
    break;

  case 154: /* condition: ID DOT ID LT LBRACE sub_query RBRACE  */
#line 1146 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, LESS_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3004 "yacc_sql.tab.c"
    break;

  case 155: /* condition: ID DOT ID GT LBRACE sub_query RBRACE  */
#line 1154 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, GREAT_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3016 "yacc_sql.tab.c"
    break;

  case 156: /* condition: ID DOT ID LE LBRACE sub_query RBRACE  */
#line 1162 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition,LESS_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3028 "yacc_sql.tab.c"
    break;

  case 157: /* condition: ID DOT ID GE LBRACE sub_query RBRACE  */
#line 1170 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, GREAT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3040 "yacc_sql.tab.c"
    break;

  case 158: /* condition: ID DOT ID NE LBRACE sub_query RBRACE  */
#line 1178 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, NOT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3052 "yacc_sql.tab.c"
    break;

  case 159: /* condition: LBRACE sub_query RBRACE NE LBRACE sub_query RBRACE  */
#line 1185 "yacc_sql.y"
                                                            {
		Condition condition;
		condition_init_with_two_query(&condition, NOT_EQUAL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1],CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-2]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3062 "yacc_sql.tab.c"
    break;

  case 160: /* in_cells: value value_list  */
#line 1192 "yacc_sql.y"
                          {
	}
#line 3069 "yacc_sql.tab.c"
    break;

  case 161: /* reverseComp: EQ  */
#line 1196 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 3075 "yacc_sql.tab.c"
    break;

  case 162: /* reverseComp: LT  */
#line 1197 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3081 "yacc_sql.tab.c"
    break;

  case 163: /* reverseComp: GT  */
#line 1198 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3087 "yacc_sql.tab.c"
    break;

  case 164: /* reverseComp: LE  */
#line 1199 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3093 "yacc_sql.tab.c"
    break;

  case 165: /* reverseComp: GE  */
#line 1200 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3099 "yacc_sql.tab.c"
    break;

  case 166: /* reverseComp: NE  */
#line 1201 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3105 "yacc_sql.tab.c"
    break;

  case 167: /* comOp: EQ  */
#line 1204 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO;}
#line 3111 "yacc_sql.tab.c"
    break;

  case 168: /* comOp: LT  */
#line 1205 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3117 "yacc_sql.tab.c"
    break;

  case 169: /* comOp: GT  */
#line 1206 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3123 "yacc_sql.tab.c"
    break;

  case 170: /* comOp: LE  */
#line 1207 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3129 "yacc_sql.tab.c"
    break;

  case 171: /* comOp: GE  */
#line 1208 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3135 "yacc_sql.tab.c"
    break;

  case 172: /* comOp: NE  */
#line 1209 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3141 "yacc_sql.tab.c"
    break;

  case 173: /* comOp: LIKE  */
#line 1210 "yacc_sql.y"
               { CONTEXT->comp = LIKE_TO; }
#line 3147 "yacc_sql.tab.c"
    break;

  case 174: /* comOp: IN_T  */
#line 1211 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 3153 "yacc_sql.tab.c"
    break;

  case 175: /* comOp: NOT IN_T  */
#line 1212 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 3159 "yacc_sql.tab.c"
    break;

  case 176: /* comOp: NOT EXIST_T  */
#line 1213 "yacc_sql.y"
                     {CONTEXT->comp = NOT_EXIST;}
#line 3165 "yacc_sql.tab.c"
    break;

  case 177: /* comOp: EXIST_T  */
#line 1214 "yacc_sql.y"
                 {CONTEXT->comp = EXIST;}
#line 3171 "yacc_sql.tab.c"
    break;

  case 178: /* comOp: NOT LIKE  */
#line 1215 "yacc_sql.y"
                   { CONTEXT->comp = NOT_LIKE; }
#line 3177 "yacc_sql.tab.c"
    break;

  case 179: /* comOp: IS NOT  */
#line 1216 "yacc_sql.y"
                 { CONTEXT->comp = COMP_IS_NOT; }
#line 3183 "yacc_sql.tab.c"
    break;

  case 180: /* comOp: IS  */
#line 1217 "yacc_sql.y"
             { CONTEXT->comp = COMP_IS; }
#line 3189 "yacc_sql.tab.c"
    break;

  case 181: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1222 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3198 "yacc_sql.tab.c"
    break;


#line 3202 "yacc_sql.tab.c"

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

#line 1227 "yacc_sql.y"

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
