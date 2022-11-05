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
  YYSYMBOL_DT = 26,                        /* DT  */
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
  YYSYMBOL_BY = 42,                        /* BY  */
  YYSYMBOL_DT1 = 43,                       /* DT1  */
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
  YYSYMBOL_NUMBER = 65,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 66,                     /* FLOAT  */
  YYSYMBOL_DATEE = 67,                     /* DATEE  */
  YYSYMBOL_ID = 68,                        /* ID  */
  YYSYMBOL_PATH = 69,                      /* PATH  */
  YYSYMBOL_SSS = 70,                       /* SSS  */
  YYSYMBOL_STAR = 71,                      /* STAR  */
  YYSYMBOL_STRING_V = 72,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 73,                  /* $accept  */
  YYSYMBOL_commands = 74,                  /* commands  */
  YYSYMBOL_command = 75,                   /* command  */
  YYSYMBOL_exit = 76,                      /* exit  */
  YYSYMBOL_help = 77,                      /* help  */
  YYSYMBOL_sync = 78,                      /* sync  */
  YYSYMBOL_begin = 79,                     /* begin  */
  YYSYMBOL_commit = 80,                    /* commit  */
  YYSYMBOL_rollback = 81,                  /* rollback  */
  YYSYMBOL_drop_table = 82,                /* drop_table  */
  YYSYMBOL_show_tables = 83,               /* show_tables  */
  YYSYMBOL_show_indexes = 84,              /* show_indexes  */
  YYSYMBOL_desc_table = 85,                /* desc_table  */
  YYSYMBOL_create_index = 86,              /* create_index  */
  YYSYMBOL_index_attr_list = 87,           /* index_attr_list  */
  YYSYMBOL_index_attr = 88,                /* index_attr  */
  YYSYMBOL_drop_index = 89,                /* drop_index  */
  YYSYMBOL_create_table = 90,              /* create_table  */
  YYSYMBOL_attr_def_list = 91,             /* attr_def_list  */
  YYSYMBOL_attr_def = 92,                  /* attr_def  */
  YYSYMBOL_number = 93,                    /* number  */
  YYSYMBOL_type = 94,                      /* type  */
  YYSYMBOL_ID_get = 95,                    /* ID_get  */
  YYSYMBOL_dummy = 96,                     /* dummy  */
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
  YYSYMBOL_by_attrs = 109,                 /* by_attrs  */
  YYSYMBOL_sub_query = 110,                /* sub_query  */
  YYSYMBOL_join_list = 111,                /* join_list  */
  YYSYMBOL_join_cons = 112,                /* join_cons  */
  YYSYMBOL_agg_fun_list_head = 113,        /* agg_fun_list_head  */
  YYSYMBOL_agg_fun_list = 114,             /* agg_fun_list  */
  YYSYMBOL_select_attr = 115,              /* select_attr  */
  YYSYMBOL_attr_list = 116,                /* attr_list  */
  YYSYMBOL_rel_list = 117,                 /* rel_list  */
  YYSYMBOL_where = 118,                    /* where  */
  YYSYMBOL_condition_list = 119,           /* condition_list  */
  YYSYMBOL_condition = 120,                /* condition  */
  YYSYMBOL_in_cells = 121,                 /* in_cells  */
  YYSYMBOL_reverseComp = 122,              /* reverseComp  */
  YYSYMBOL_comOp = 123,                    /* comOp  */
  YYSYMBOL_load_data = 124                 /* load_data  */
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
#define YYLAST   568

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  188
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  531

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   327


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
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   162,   162,   164,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   189,   194,   199,   205,   211,   217,   223,   229,
     235,   243,   250,   255,   262,   264,   268,   275,   282,   291,
     293,   297,   308,   319,   330,   341,   352,   365,   368,   369,
     370,   371,   372,   375,   382,   388,   398,   399,   404,   405,
     410,   411,   416,   419,   422,   426,   430,   436,   446,   454,
     456,   460,   466,   474,   485,   490,   495,   500,   508,   513,
     518,   523,   528,   533,   538,   543,   548,   553,   558,   566,
     577,   589,   602,   612,   622,   635,   641,   649,   658,   679,
     699,   719,   739,   758,   777,   796,   820,   822,   827,   832,
     837,   842,   848,   854,   860,   867,   869,   874,   879,   885,
     891,   897,   907,   913,   919,   924,   930,   932,   938,   944,
     950,   953,   955,   959,   961,   964,   966,   970,   982,   992,
    1012,  1034,  1055,  1065,  1076,  1082,  1088,  1095,  1103,  1111,
    1119,  1126,  1133,  1140,  1147,  1155,  1163,  1171,  1179,  1187,
    1195,  1203,  1211,  1219,  1227,  1235,  1243,  1250,  1254,  1255,
    1256,  1257,  1258,  1259,  1262,  1263,  1264,  1265,  1266,  1267,
    1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,  1279
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
  "COUNT_T", "MAX_T", "MIN_T", "AVG_T", "SUM_T", "TRX_COMMIT", "DT",
  "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T", "TEXT_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET",
  "BY", "DT1", "GROUP", "ON", "INNER_T", "JOIN_T", "LOAD", "DATA",
  "INFILE", "EQ", "LT", "GT", "LE", "GE", "NE", "EXIST_T", "IN_T", "LIKE",
  "NOT", "IS", "NULLL", "NULLABLE", "UNIQUE", "NUMBER", "FLOAT", "DATEE",
  "ID", "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands",
  "command", "exit", "help", "sync", "begin", "commit", "rollback",
  "drop_table", "show_tables", "show_indexes", "desc_table",
  "create_index", "index_attr_list", "index_attr", "drop_index",
  "create_table", "attr_def_list", "attr_def", "number", "type", "ID_get",
  "dummy", "insert", "record_list", "record", "value_list", "value",
  "delete", "update", "update_attr_list", "update_attr",
  "update_select_attr", "update_agg", "select", "by_attrs", "sub_query",
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

#define YYPACT_NINF (-465)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -465,   121,  -465,    11,   144,    34,   -46,    27,    43,    -8,
      58,    -9,   105,   113,  -465,   135,   142,   148,  -465,    69,
    -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,    89,
      97,   164,   119,   127,   165,   221,   227,   232,   234,   106,
     240,   233,   235,   260,   269,   242,  -465,   217,   224,   256,
    -465,  -465,  -465,  -465,  -465,   248,   283,   255,   236,   298,
     299,   -48,   238,   239,   241,   243,    17,   -35,  -465,  -465,
     244,   245,  -465,  -465,   246,   266,   271,   247,   249,   250,
     252,   263,  -465,  -465,   288,   300,   304,   305,   306,   307,
     109,  -465,   240,   240,   271,    25,   313,   309,    33,   325,
     278,   312,   295,  -465,   314,   190,   317,   268,   316,   316,
     316,   316,   316,   316,    52,  -465,  -465,  -465,   332,   270,
     290,   271,  -465,   101,   321,   331,   326,   284,  -465,  -465,
    -465,  -465,   145,  -465,   156,   303,  -465,     2,   247,   271,
     338,   250,   328,  -465,  -465,  -465,  -465,  -465,    93,   280,
     330,   267,  -465,  -465,  -465,  -465,  -465,  -465,   240,   240,
    -465,   333,   281,    22,   334,   309,   347,   155,   336,   331,
     339,   286,   340,   341,   342,   343,   344,   345,  -465,   346,
    -465,   188,   308,   174,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,   225,   187,    33,  -465,   354,  -465,   312,   361,   297,
     314,   363,   302,   310,  -465,  -465,   351,   280,   355,   357,
     358,   359,   360,  -465,  -465,  -465,   335,  -465,   337,   101,
     353,   321,  -465,   362,   365,   366,   367,   368,    54,   214,
     369,   331,   173,   331,   331,   331,   331,   331,   331,    21,
    -465,   371,  -465,  -465,  -465,  -465,  -465,   350,  -465,   303,
      91,  -465,  -465,   374,  -465,  -465,  -465,   372,  -465,   280,
     373,   351,    71,   320,   323,   324,   329,    33,   348,   334,
    -465,  -465,    90,   356,   364,   370,   375,   376,   377,  -465,
    -465,  -465,  -465,  -465,   378,   379,  -465,   381,   380,   383,
     385,   386,   387,   388,   389,   237,   194,   390,   391,   392,
     393,   394,   395,   334,   396,   397,    21,   382,  -465,   399,
     406,   407,   409,   410,   398,  -465,   401,   402,  -465,   110,
     351,   403,   411,   412,   413,   414,   417,   418,   419,   400,
     303,   125,   424,  -465,   416,   420,   421,   422,   423,   425,
     404,   333,   331,  -465,  -465,   331,   331,   331,   331,   331,
     331,   331,   432,   426,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,  -465,  -465,  -465,   435,   436,  -465,   115,   405,   408,
     415,   427,   167,   428,   429,   430,  -465,  -465,  -465,   438,
     316,   316,   316,   316,   316,   316,   431,   271,  -465,   433,
     434,  -465,   437,   439,   440,   441,   442,   443,   444,  -465,
     445,   446,   447,   448,   449,   450,   451,   452,    21,   453,
    -465,  -465,     7,   454,     9,    12,    87,   102,  -465,  -465,
     271,   271,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
     455,   456,  -465,   457,   462,   458,   463,   464,   465,   467,
     333,   271,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
     468,   469,  -465,  -465,   459,  -465,  -465,   460,  -465,   461,
    -465,   466,  -465,   470,   471,   472,   473,  -465,   474,   475,
    -465,   476,   477,   478,   479,  -465,  -465,  -465,  -465,   481,
     482,   483,   486,   487,  -465,  -465,    33,   484,   480,   271,
     485,   488,   489,   490,   271,  -465,  -465,  -465,  -465,  -465,
     400,   491,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,   271,   271,   271,   271,   271,  -465,  -465,  -465,  -465,
    -465
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,    89,     0,
       3,    21,    20,    15,    16,    17,    18,     9,    10,    11,
      12,    13,    14,     8,     5,     7,     6,     4,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
     126,     0,     0,     0,     0,     0,    24,     0,     0,     0,
      25,    26,    27,    23,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   122,
       0,     0,    31,    29,     0,     0,   133,     0,     0,     0,
       0,     0,    28,    37,     0,     0,     0,     0,     0,     0,
     126,   130,   126,   126,   133,   131,     0,    58,     0,     0,
       0,    69,     0,    53,    39,     0,     0,     0,   115,   115,
     115,   115,   115,   115,     0,   127,   124,   125,     0,     0,
       0,   133,    30,     0,    56,     0,     0,     0,    66,    62,
      63,    64,     0,    65,     0,   135,    67,     0,     0,   133,
       0,     0,     0,    48,    51,    52,    49,    50,    44,     0,
       0,     0,   110,   109,   111,   112,   114,   113,   126,   126,
      92,   131,     0,     0,    60,    58,     0,     0,     0,     0,
       0,     0,   174,   175,   176,   177,   178,   179,   184,   181,
     180,     0,   187,     0,   174,   175,   176,   177,   178,   179,
     181,     0,     0,     0,   134,     0,    71,    69,     0,     0,
      39,     0,     0,     0,    46,    36,    34,     0,     0,     0,
       0,     0,     0,   128,   129,   132,     0,    91,     0,     0,
       0,    56,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,   182,   185,   186,   139,   137,   182,   140,   138,   135,
       0,    70,    68,     0,    40,    38,    47,     0,    45,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    60,
      59,    57,     0,     0,     0,     0,     0,     0,     0,   168,
     169,   170,   171,   172,   173,     0,   144,     0,   174,   175,
     176,   177,   178,   179,   181,     0,     0,     0,     0,     0,
       0,     0,     0,    60,     0,     0,     0,     0,   136,     0,
       0,     0,     0,     0,    75,    74,     0,     0,   188,    41,
      34,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     135,    95,     0,    61,     0,     0,     0,     0,     0,     0,
       0,   131,     0,   146,   145,     0,     0,     0,     0,     0,
       0,     0,   182,     0,   141,   154,   155,   156,   157,   158,
     159,   167,   150,   147,     0,     0,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    35,    32,     0,
     115,   115,   115,   115,   115,   115,     0,   133,   108,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     152,   148,     0,     0,     0,     0,     0,     0,    76,    77,
     133,   133,    42,    33,   117,   116,   118,   119,   121,   120,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
     131,   133,   166,   160,   161,   162,   163,   164,   165,   151,
       0,     0,   143,    79,     0,    78,    81,     0,    83,     0,
      87,     0,    85,     0,     0,     0,     0,    94,     0,     0,
      54,     0,     0,     0,     0,    54,    99,   153,   149,     0,
       0,     0,     0,     0,    72,    73,     0,     0,     0,   133,
       0,     0,     0,     0,   133,    80,    82,    84,    88,    86,
     106,     0,    54,   100,    54,    54,    54,    54,    98,   107,
      97,   133,   133,   133,   133,   133,   101,   102,   103,   105,
     104
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,  -465,  -465,  -465,  -257,  -185,  -465,  -465,   183,   319,
    -465,  -465,  -465,  -464,  -465,   218,   279,  -248,  -132,  -465,
    -465,   265,   384,  -465,  -465,  -465,  -465,  -167,   -55,   -22,
     492,  -116,  -465,   -40,  -169,  -104,  -246,   -97,  -308,  -465,
    -135,  -465
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   270,   216,    32,    33,   152,   114,
     267,   158,   115,   451,    34,   176,   134,   230,   144,    35,
      36,   149,   111,   326,   327,    37,   342,   178,   397,   339,
      51,   162,    52,    78,   131,   109,   204,   340,   315,   295,
     193,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     128,   174,   225,   163,   164,   165,   166,   167,   375,   202,
      79,   145,   240,   318,   332,   206,   499,    39,   205,    40,
      94,   504,    53,    95,   463,   227,   466,   173,    57,   468,
     177,   343,   271,   102,    54,    55,   103,    44,    45,    46,
      47,    48,   464,   129,   467,   208,    56,   469,   521,   135,
     522,   523,   524,   525,    44,    45,    46,    47,    48,    59,
     125,   255,   126,   127,   138,   371,   228,   139,   140,   141,
     258,   130,   143,   387,   297,    41,   307,   308,   309,   310,
     311,   312,   314,   138,   330,   100,   139,   140,   141,   287,
     136,   143,   288,   137,   398,   138,    58,   279,   139,   140,
     141,   142,    49,   143,   470,    50,   259,   306,    60,   212,
     461,   319,   320,   321,   322,   323,    61,   313,    65,   472,
     168,     2,   471,   169,    76,     3,     4,    76,   223,   224,
       5,     6,     7,     8,     9,    10,    11,   473,    62,   333,
      12,    77,   334,   399,   124,    63,    13,    14,    15,   374,
      42,    64,    43,   213,    16,    17,   214,    66,   344,   324,
     400,   345,   325,   138,    18,    67,   139,   140,   141,    19,
     385,   143,    68,   386,   364,   233,   234,   235,   236,   237,
     181,    71,   409,   422,   313,   410,   423,    69,   411,   412,
     413,   414,   415,   416,   417,    70,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   194,   195,   196,
     197,   198,   199,   188,   200,   190,   201,   192,   153,   154,
     155,   156,   157,   238,   298,   299,   300,   301,   302,   303,
     188,   304,   190,   305,   192,   428,   138,    72,   429,   139,
     140,   141,   254,    73,   143,   250,   251,   252,    74,   138,
      75,   460,   139,   140,   141,   257,   138,   143,    76,   139,
     140,   141,   363,    82,   143,   289,   290,   291,   292,   293,
     294,    80,    83,    81,   434,   435,   436,   437,   438,   439,
      84,   485,   250,   256,   252,    85,   313,   218,   219,   220,
     221,   222,    86,   441,   250,   362,   252,    87,    88,    89,
      90,    92,    93,   107,    91,   118,    96,    97,   117,    98,
     108,    99,   104,   105,   106,   110,   132,   119,   113,   112,
     116,   120,   121,   122,   123,   133,   474,   475,   146,   147,
     148,   150,   151,   159,   161,   170,   160,   172,   171,   175,
     177,   180,   179,   203,   209,   211,   217,   486,   215,   226,
     232,   129,   229,   239,   242,   241,   243,   244,   245,   246,
     247,   248,   249,   260,   262,   263,   265,   266,   253,   269,
     280,   272,   268,   273,   274,   275,   276,   328,   282,   278,
     277,   283,   284,   285,   286,   317,   296,   316,   335,   329,
     331,   336,   337,   264,   352,   513,   355,   338,   354,   356,
     518,   357,   358,   359,   360,   361,   388,   365,   366,   367,
     368,   369,   370,   372,   373,   377,   341,   526,   527,   528,
     529,   530,   378,   379,   346,   380,   381,   401,   389,   390,
     391,   392,   347,   382,   393,   394,   395,   403,   348,   383,
     384,   433,   408,   349,   350,   351,   396,   353,   418,   281,
     376,   402,   420,   421,   231,   519,   404,   405,   406,   477,
     407,   419,   452,   453,   454,   455,   456,   457,   458,   459,
     210,   465,   261,   424,   510,   478,   425,   445,   440,   479,
     481,   482,   483,   426,   484,   487,   488,     0,   494,   495,
       0,     0,   432,     0,     0,   427,   430,   431,   505,   506,
     507,   442,   443,   508,   509,   444,     0,     0,   446,   447,
     448,   449,   450,   498,   500,   501,   502,   503,   496,   511,
       0,   462,     0,   476,     0,     0,   480,   489,   490,   491,
       0,     0,   207,     0,   492,     0,     0,     0,   493,     0,
       0,     0,   497,     0,     0,     0,     0,     0,   512,     0,
       0,     0,     0,   514,     0,     0,   515,   516,   517,   520,
       0,     0,     0,     0,     0,     0,     0,     0,   101
};

static const yytype_int16 yycheck[] =
{
     104,   133,   171,   119,   120,   121,   122,   123,   316,   144,
      50,   108,   179,   259,   271,   147,   480,     6,    16,     8,
      68,   485,    68,    71,    17,     3,    17,   131,    36,    17,
       9,   279,   217,    68,     7,     8,    71,    20,    21,    22,
      23,    24,    35,    18,    35,   149,     3,    35,   512,    16,
     514,   515,   516,   517,    20,    21,    22,    23,    24,    68,
     100,   193,   102,   103,    62,   313,    44,    65,    66,    67,
     202,    46,    70,   330,   241,    64,   243,   244,   245,   246,
     247,   248,   249,    62,   269,    68,    65,    66,    67,    35,
      57,    70,    38,    60,   340,    62,    38,   229,    65,    66,
      67,    68,    68,    70,    17,    71,   203,   242,     3,    16,
     418,    20,    21,    22,    23,    24,     3,   249,    49,    17,
      68,     0,    35,    71,    18,     4,     5,    18,   168,   169,
       9,    10,    11,    12,    13,    14,    15,    35,     3,    68,
      19,    35,    71,    18,    35,     3,    25,    26,    27,   316,
       6,     3,     8,    60,    33,    34,    63,    68,    68,    68,
      35,    71,    71,    62,    43,    68,    65,    66,    67,    48,
      60,    70,     8,    63,   306,    20,    21,    22,    23,    24,
      35,    16,   351,    68,   316,   352,    71,    68,   355,   356,
     357,   358,   359,   360,   361,    68,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    28,    29,
      30,    31,    32,    68,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    68,    62,    16,    71,    65,
      66,    67,    68,    16,    70,    57,    58,    59,    16,    62,
      16,   418,    65,    66,    67,    68,    62,    70,    18,    65,
      66,    67,    68,     3,    70,    51,    52,    53,    54,    55,
      56,    38,     3,    38,   390,   391,   392,   393,   394,   395,
      38,   450,    57,    58,    59,    68,   418,    20,    21,    22,
      23,    24,    68,   397,    57,    58,    59,    41,    50,    16,
      45,     3,     3,    37,    68,    17,    68,    68,    45,    68,
      39,    68,    68,    68,    68,    68,     3,    17,    68,    70,
      68,    17,    17,    17,    17,    16,   430,   431,     3,    51,
      18,    36,    18,    16,    18,     3,    68,    47,    68,    18,
       9,    57,    16,    40,     6,    17,    16,   451,    68,    68,
       3,    18,    18,    17,    68,    16,    16,    16,    16,    16,
      16,    16,    16,     9,     3,    68,     3,    65,    60,    18,
      17,    16,    62,    16,    16,    16,    16,     3,    16,    42,
      45,    16,    16,    16,    16,    35,    17,    16,    68,    17,
      17,    68,    68,   210,    16,   499,    16,    68,    17,    16,
     504,    16,    16,    16,    16,    16,     3,    17,    17,    17,
      17,    17,    17,    17,    17,    16,    68,   521,   522,   523,
     524,   525,    16,    16,    68,    16,    16,     3,    17,    17,
      17,    17,    68,    35,    17,    17,    17,    17,    68,    38,
      38,     3,    38,    68,    68,    68,    46,    68,    16,   231,
      68,    35,    17,    17,   175,   510,    35,    35,    35,     3,
      35,    35,    17,    17,    17,    17,    17,    17,    17,    17,
     151,    17,   207,    68,   496,    18,    68,    38,    47,    17,
      17,    17,    17,    68,    17,    17,    17,    -1,    17,    17,
      -1,    -1,    62,    -1,    -1,    68,    68,    68,    17,    17,
      17,    68,    68,    17,    17,    68,    -1,    -1,    68,    68,
      68,    68,    68,    38,    38,    38,    38,    38,    45,    35,
      -1,    68,    -1,    68,    -1,    -1,    68,    68,    68,    68,
      -1,    -1,   148,    -1,    68,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    68,    68,    68,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    74,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    25,    26,    27,    33,    34,    43,    48,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    89,    90,    97,   102,   103,   108,   124,     6,
       8,    64,     6,     8,    20,    21,    22,    23,    24,    68,
      71,   113,   115,    68,     7,     8,     3,    36,    38,    68,
       3,     3,     3,     3,     3,    49,    68,    68,     8,    68,
      68,    16,    16,    16,    16,    16,    18,    35,   116,   116,
      38,    38,     3,     3,    38,    68,    68,    41,    50,    16,
      45,    68,     3,     3,    68,    71,    68,    68,    68,    68,
      68,   113,    68,    71,    68,    68,    68,    37,    39,   118,
      68,   105,    70,    68,    92,    95,    68,    45,    17,    17,
      17,    17,    17,    17,    35,   116,   116,   116,   118,    18,
      46,   117,     3,    16,    99,    16,    57,    60,    62,    65,
      66,    67,    68,    70,   101,   120,     3,    51,    18,   104,
      36,    18,    91,    28,    29,    30,    31,    32,    94,    16,
      68,    18,   114,   114,   114,   114,   114,   114,    68,    71,
       3,    68,    47,   118,   101,    18,    98,     9,   110,    16,
      57,    35,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   123,    51,    52,    53,    54,    55,    56,
      58,    60,   123,    40,   119,    16,   101,   105,   118,     6,
      92,    17,    16,    60,    63,    68,    88,    16,    20,    21,
      22,    23,    24,   116,   116,   117,    68,     3,    44,    18,
     100,    99,     3,    20,    21,    22,    23,    24,    68,    17,
     110,    16,    68,    16,    16,    16,    16,    16,    16,    16,
      57,    58,    59,    60,    68,   101,    58,    68,   101,   120,
       9,   104,     3,    68,    91,     3,    65,    93,    62,    18,
      87,    88,    16,    16,    16,    16,    16,    45,    42,   101,
      17,    98,    16,    16,    16,    16,    16,    35,    38,    51,
      52,    53,    54,    55,    56,   122,    17,   110,    51,    52,
      53,    54,    55,    56,    58,    60,   123,   110,   110,   110,
     110,   110,   110,   101,   110,   121,    16,    35,   119,    20,
      21,    22,    23,    24,    68,    71,   106,   107,     3,    17,
      88,    17,    87,    68,    71,    68,    68,    68,    68,   112,
     120,    68,   109,   100,    68,    71,    68,    68,    68,    68,
      68,    68,    16,    68,    17,    16,    16,    16,    16,    16,
      16,    16,    58,    68,   101,    17,    17,    17,    17,    17,
      17,   100,    17,    17,   110,   121,    68,    16,    16,    16,
      16,    16,    35,    38,    38,    60,    63,    87,     3,    17,
      17,    17,    17,    17,    17,    17,    46,   111,   119,    18,
      35,     3,    35,    17,    35,    35,    35,    35,    38,   117,
     110,   110,   110,   110,   110,   110,   110,   110,    16,    35,
      17,    17,    68,    71,    68,    68,    68,    68,    68,    71,
      68,    68,    62,     3,   114,   114,   114,   114,   114,   114,
      47,   118,    68,    68,    68,    38,    68,    68,    68,    68,
      68,    96,    17,    17,    17,    17,    17,    17,    17,    17,
     110,   121,    68,    17,    35,    17,    17,    35,    17,    35,
      17,    35,    17,    35,   118,   118,    68,     3,    18,    17,
      68,    17,    17,    17,    17,   117,   118,    17,    17,    68,
      68,    68,    68,    68,    17,    17,    45,    68,    38,    96,
      38,    38,    38,    38,    96,    17,    17,    17,    17,    17,
     112,    35,    68,   118,    68,    68,    68,    68,   118,   111,
      68,    96,    96,    96,    96,    96,   118,   118,   118,   118,
     118
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    73,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    86,    87,    87,    88,    89,    90,    91,
      91,    92,    92,    92,    92,    92,    92,    93,    94,    94,
      94,    94,    94,    95,    96,    97,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   101,   101,   102,   103,   104,
     104,   105,   105,   105,   106,   106,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   108,
     108,   108,   108,   108,   108,   109,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   111,   111,   112,   113,
     113,   113,   113,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   115,   115,   115,   115,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   122,   122,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   124
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
       6,     4,     6,     4,     6,     4,     6,     4,     6,     1,
       1,     7,     6,    10,    12,     1,     3,     7,     9,     7,
       9,    11,    11,    11,    11,    11,     0,     6,     2,     5,
       5,     5,     5,     5,     5,     0,     6,     6,     6,     6,
       6,     6,     2,     2,     4,     4,     0,     3,     5,     5,
       2,     0,     3,     0,     3,     0,     3,     3,     3,     3,
       3,     5,     5,     7,     4,     5,     5,     5,     6,     8,
       5,     7,     6,     8,     5,     5,     5,     5,     5,     5,
       7,     7,     7,     7,     7,     7,     7,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     2,     1,     8
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
#line 189 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1602 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 194 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1610 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 199 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1618 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 205 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1626 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 211 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1634 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 217 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1642 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 223 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1651 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 229 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1659 "yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 235 "yacc_sql.y"
                                {
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
    }
#line 1668 "yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 243 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1677 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 251 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
		}
#line 1686 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 256 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
		}
#line 1695 "yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA index_attr index_attr_list  */
#line 264 "yacc_sql.y"
                                           { }
#line 1701 "yacc_sql.tab.c"
    break;

  case 36: /* index_attr: ID  */
#line 269 "yacc_sql.y"
                {
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
		}
#line 1709 "yacc_sql.tab.c"
    break;

  case 37: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 276 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1718 "yacc_sql.tab.c"
    break;

  case 38: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 283 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1730 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 293 "yacc_sql.y"
                                   {    }
#line 1736 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 298 "yacc_sql.y"
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
#line 1751 "yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type LBRACE number RBRACE NOT NULLL  */
#line 309 "yacc_sql.y"
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
#line 1766 "yacc_sql.tab.c"
    break;

  case 43: /* attr_def: ID_get type LBRACE number RBRACE NULLABLE  */
#line 320 "yacc_sql.y"
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
#line 1781 "yacc_sql.tab.c"
    break;

  case 44: /* attr_def: ID_get type  */
#line 331 "yacc_sql.y"
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
#line 1796 "yacc_sql.tab.c"
    break;

  case 45: /* attr_def: ID_get type NOT NULLL  */
#line 342 "yacc_sql.y"
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
#line 1811 "yacc_sql.tab.c"
    break;

  case 46: /* attr_def: ID_get type NULLABLE  */
#line 353 "yacc_sql.y"
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
#line 1826 "yacc_sql.tab.c"
    break;

  case 47: /* number: NUMBER  */
#line 365 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1832 "yacc_sql.tab.c"
    break;

  case 48: /* type: INT_T  */
#line 368 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1838 "yacc_sql.tab.c"
    break;

  case 49: /* type: DATE_T  */
#line 369 "yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 1844 "yacc_sql.tab.c"
    break;

  case 50: /* type: TEXT_T  */
#line 370 "yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 1850 "yacc_sql.tab.c"
    break;

  case 51: /* type: STRING_T  */
#line 371 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1856 "yacc_sql.tab.c"
    break;

  case 52: /* type: FLOAT_T  */
#line 372 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1862 "yacc_sql.tab.c"
    break;

  case 53: /* ID_get: ID  */
#line 376 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1871 "yacc_sql.tab.c"
    break;

  case 54: /* dummy: %empty  */
#line 382 "yacc_sql.y"
      {
		CONTEXT->depth++;
		CONTEXT->sub_con_start[CONTEXT->depth]=CONTEXT->condition_length;
	}
#line 1880 "yacc_sql.tab.c"
    break;

  case 55: /* insert: INSERT INTO ID VALUES record record_list SEMICOLON  */
#line 389 "yacc_sql.y"
        {
		CONTEXT->ssql->flag=SCF_INSERT;//"insert";
		CONTEXT->ssql->sstr.insertion.relation_name = (yyvsp[-4].string);
		CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
		inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-4].string), CONTEXT->values, CONTEXT->value_length,CONTEXT->single_record_length,CONTEXT->record_length);

      	CONTEXT->value_length=0;
	  	CONTEXT->record_length=0;
    }
#line 1894 "yacc_sql.tab.c"
    break;

  case 57: /* record_list: COMMA record record_list  */
#line 399 "yacc_sql.y"
                                        {

		}
#line 1902 "yacc_sql.tab.c"
    break;

  case 59: /* record: LBRACE value value_list RBRACE  */
#line 406 "yacc_sql.y"
                {
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		}
#line 1911 "yacc_sql.tab.c"
    break;

  case 61: /* value_list: COMMA value value_list  */
#line 411 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1919 "yacc_sql.tab.c"
    break;

  case 62: /* value: NUMBER  */
#line 416 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1927 "yacc_sql.tab.c"
    break;

  case 63: /* value: FLOAT  */
#line 419 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1935 "yacc_sql.tab.c"
    break;

  case 64: /* value: DATEE  */
#line 422 "yacc_sql.y"
               {
			(yyvsp[0].dates) = substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].dates));
		}
#line 1944 "yacc_sql.tab.c"
    break;

  case 65: /* value: SSS  */
#line 426 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1953 "yacc_sql.tab.c"
    break;

  case 66: /* value: NULLL  */
#line 430 "yacc_sql.y"
               {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		}
#line 1961 "yacc_sql.tab.c"
    break;

  case 67: /* delete: DELETE FROM ID where SEMICOLON  */
#line 437 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1973 "yacc_sql.tab.c"
    break;

  case 68: /* update: UPDATE ID SET update_attr update_attr_list where SEMICOLON  */
#line 447 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1983 "yacc_sql.tab.c"
    break;

  case 71: /* update_attr: ID EQ value  */
#line 461 "yacc_sql.y"
                {
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			CONTEXT->value_length = 0;
		}
#line 1993 "yacc_sql.tab.c"
    break;

  case 72: /* update_attr: ID EQ LBRACE SELECT update_select_attr FROM ID where RBRACE  */
#line 467 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2005 "yacc_sql.tab.c"
    break;

  case 73: /* update_attr: ID EQ LBRACE SELECT update_agg FROM ID where RBRACE  */
#line 475 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2017 "yacc_sql.tab.c"
    break;

  case 74: /* update_select_attr: STAR  */
#line 485 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2027 "yacc_sql.tab.c"
    break;

  case 75: /* update_select_attr: ID  */
#line 490 "yacc_sql.y"
         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2037 "yacc_sql.tab.c"
    break;

  case 76: /* update_select_attr: ID DOT ID  */
#line 495 "yacc_sql.y"
                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2047 "yacc_sql.tab.c"
    break;

  case 77: /* update_select_attr: ID DOT STAR  */
#line 500 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2057 "yacc_sql.tab.c"
    break;

  case 78: /* update_agg: COUNT_T LBRACE STAR RBRACE  */
#line 508 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
#line 2067 "yacc_sql.tab.c"
    break;

  case 79: /* update_agg: COUNT_T LBRACE ID RBRACE  */
#line 513 "yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2077 "yacc_sql.tab.c"
    break;

  case 80: /* update_agg: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 518 "yacc_sql.y"
                                          {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2087 "yacc_sql.tab.c"
    break;

  case 81: /* update_agg: MAX_T LBRACE ID RBRACE  */
#line 523 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2097 "yacc_sql.tab.c"
    break;

  case 82: /* update_agg: MAX_T LBRACE ID DOT ID RBRACE  */
#line 528 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2107 "yacc_sql.tab.c"
    break;

  case 83: /* update_agg: MIN_T LBRACE ID RBRACE  */
#line 533 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2117 "yacc_sql.tab.c"
    break;

  case 84: /* update_agg: MIN_T LBRACE ID DOT ID RBRACE  */
#line 538 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2127 "yacc_sql.tab.c"
    break;

  case 85: /* update_agg: SUM_T LBRACE ID RBRACE  */
#line 543 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2137 "yacc_sql.tab.c"
    break;

  case 86: /* update_agg: SUM_T LBRACE ID DOT ID RBRACE  */
#line 548 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2147 "yacc_sql.tab.c"
    break;

  case 87: /* update_agg: AVG_T LBRACE ID RBRACE  */
#line 553 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2157 "yacc_sql.tab.c"
    break;

  case 88: /* update_agg: AVG_T LBRACE ID DOT ID RBRACE  */
#line 558 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2167 "yacc_sql.tab.c"
    break;

  case 89: /* select: DT1  */
#line 566 "yacc_sql.y"
           {
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		
  		CONTEXT->condition_length = 0;
  		CONTEXT->from_length = 0;
  		CONTEXT->select_length = 0;
  		CONTEXT->value_length = 0;
  		CONTEXT->ssql->sstr.selection.is_da=2;
  		CONTEXT->ssql->sstr.selection.sub_query_num=0;
	}
#line 2183 "yacc_sql.tab.c"
    break;

  case 90: /* select: DT  */
#line 577 "yacc_sql.y"
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
#line 2199 "yacc_sql.tab.c"
    break;

  case 91: /* select: SELECT select_attr FROM ID rel_list where SEMICOLON  */
#line 589 "yacc_sql.y"
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
#line 2217 "yacc_sql.tab.c"
    break;

  case 92: /* select: SELECT agg_fun_list_head FROM ID where SEMICOLON  */
#line 602 "yacc_sql.y"
                                                          {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;

		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2232 "yacc_sql.tab.c"
    break;

  case 93: /* select: SELECT select_attr FROM ID rel_list where GROUP BY by_attrs SEMICOLON  */
#line 612 "yacc_sql.y"
                                                                                {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-6].string));
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;

		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2247 "yacc_sql.tab.c"
    break;

  case 94: /* select: SELECT select_attr FROM ID INNER_T JOIN_T ID ON join_cons join_list where SEMICOLON  */
#line 622 "yacc_sql.y"
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
#line 2263 "yacc_sql.tab.c"
    break;

  case 95: /* by_attrs: ID  */
#line 635 "yacc_sql.y"
           {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->ssql->sstr.selection.gruop_use[0]=attr;
		CONTEXT->ssql->sstr.selection.group_num=1;
	}
#line 2274 "yacc_sql.tab.c"
    break;

  case 96: /* by_attrs: ID COMMA ID  */
#line 641 "yacc_sql.y"
                    {
		RelAttr attr1,attr2;
		relation_attr_init(&attr1, NULL, (yyvsp[-2].string));
		relation_attr_init(&attr2, NULL, (yyvsp[0].string));
		CONTEXT->ssql->sstr.selection.gruop_use[0]=attr1;
		CONTEXT->ssql->sstr.selection.gruop_use[1]=attr2;
		CONTEXT->ssql->sstr.selection.group_num=2;
	}
#line 2287 "yacc_sql.tab.c"
    break;

  case 97: /* by_attrs: ID DOT ID COMMA ID DOT ID  */
#line 649 "yacc_sql.y"
                                   {
		RelAttr attr1,attr2;
		relation_attr_init(&attr1,(yyvsp[-6].string),(yyvsp[-4].string));
		relation_attr_init(&attr2,(yyvsp[-2].string),(yyvsp[0].string));
		CONTEXT->ssql->sstr.selection.gruop_use[0]=attr1;
		CONTEXT->ssql->sstr.selection.gruop_use[1]=attr2;
		CONTEXT->ssql->sstr.selection.group_num=2;
	}
#line 2300 "yacc_sql.tab.c"
    break;

  case 98: /* sub_query: SELECT ID DOT ID FROM ID rel_list dummy where  */
#line 658 "yacc_sql.y"
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
#line 2326 "yacc_sql.tab.c"
    break;

  case 99: /* sub_query: SELECT ID FROM ID rel_list dummy where  */
#line 679 "yacc_sql.y"
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
#line 2351 "yacc_sql.tab.c"
    break;

  case 100: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID dummy where  */
#line 699 "yacc_sql.y"
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
#line 2376 "yacc_sql.tab.c"
    break;

  case 101: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 719 "yacc_sql.y"
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
#line 2401 "yacc_sql.tab.c"
    break;

  case 102: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
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
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-7].string), (yyvsp[-5].string));
		selects_append_aggfun(CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num],&aggre);

		CONTEXT->ssql->sstr.selection.sub_query_num++;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
		CONTEXT->depth--;
	}
#line 2425 "yacc_sql.tab.c"
    break;

  case 103: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 758 "yacc_sql.y"
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
#line 2449 "yacc_sql.tab.c"
    break;

  case 104: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 777 "yacc_sql.y"
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
#line 2473 "yacc_sql.tab.c"
    break;

  case 105: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 796 "yacc_sql.y"
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
#line 2500 "yacc_sql.tab.c"
    break;

  case 107: /* join_list: INNER_T JOIN_T ID ON join_cons join_list  */
#line 822 "yacc_sql.y"
                                               {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
	}
#line 2508 "yacc_sql.tab.c"
    break;

  case 108: /* join_cons: condition condition_list  */
#line 827 "yacc_sql.y"
                                  {	
	}
#line 2515 "yacc_sql.tab.c"
    break;

  case 109: /* agg_fun_list_head: COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 832 "yacc_sql.y"
                                                {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2525 "yacc_sql.tab.c"
    break;

  case 110: /* agg_fun_list_head: COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 837 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2535 "yacc_sql.tab.c"
    break;

  case 111: /* agg_fun_list_head: MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 842 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2546 "yacc_sql.tab.c"
    break;

  case 112: /* agg_fun_list_head: MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 848 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2557 "yacc_sql.tab.c"
    break;

  case 113: /* agg_fun_list_head: SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 854 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2568 "yacc_sql.tab.c"
    break;

  case 114: /* agg_fun_list_head: AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 860 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2579 "yacc_sql.tab.c"
    break;

  case 116: /* agg_fun_list: COMMA COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 869 "yacc_sql.y"
                                                      {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2589 "yacc_sql.tab.c"
    break;

  case 117: /* agg_fun_list: COMMA COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 874 "yacc_sql.y"
                                                    {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2599 "yacc_sql.tab.c"
    break;

  case 118: /* agg_fun_list: COMMA MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 879 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2610 "yacc_sql.tab.c"
    break;

  case 119: /* agg_fun_list: COMMA MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 885 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre,MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2621 "yacc_sql.tab.c"
    break;

  case 120: /* agg_fun_list: COMMA SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 891 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2632 "yacc_sql.tab.c"
    break;

  case 121: /* agg_fun_list: COMMA AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 897 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2643 "yacc_sql.tab.c"
    break;

  case 122: /* select_attr: STAR attr_list  */
#line 907 "yacc_sql.y"
                   {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			CONTEXT->ssql->sstr.selection.need_Revere=1;
		}
#line 2654 "yacc_sql.tab.c"
    break;

  case 123: /* select_attr: ID attr_list  */
#line 913 "yacc_sql.y"
                   {
			RelAttr attr;
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2665 "yacc_sql.tab.c"
    break;

  case 124: /* select_attr: ID DOT ID attr_list  */
#line 919 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2675 "yacc_sql.tab.c"
    break;

  case 125: /* select_attr: ID DOT STAR attr_list  */
#line 924 "yacc_sql.y"
                               {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2685 "yacc_sql.tab.c"
    break;

  case 127: /* attr_list: COMMA ID attr_list  */
#line 932 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 2696 "yacc_sql.tab.c"
    break;

  case 128: /* attr_list: COMMA ID DOT ID attr_list  */
#line 938 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 2707 "yacc_sql.tab.c"
    break;

  case 129: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 944 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 2718 "yacc_sql.tab.c"
    break;

  case 130: /* attr_list: COMMA agg_fun_list_head  */
#line 950 "yacc_sql.y"
                                 {}
#line 2724 "yacc_sql.tab.c"
    break;

  case 132: /* rel_list: COMMA ID rel_list  */
#line 955 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2732 "yacc_sql.tab.c"
    break;

  case 134: /* where: WHERE condition condition_list  */
#line 961 "yacc_sql.y"
                                     {
	}
#line 2739 "yacc_sql.tab.c"
    break;

  case 136: /* condition_list: AND condition condition_list  */
#line 966 "yacc_sql.y"
                                   {
			}
#line 2746 "yacc_sql.tab.c"
    break;

  case 137: /* condition: ID comOp value  */
#line 971 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 2762 "yacc_sql.tab.c"
    break;

  case 138: /* condition: value comOp value  */
#line 983 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 2776 "yacc_sql.tab.c"
    break;

  case 139: /* condition: ID comOp ID  */
#line 993 "yacc_sql.y"
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
#line 2800 "yacc_sql.tab.c"
    break;

  case 140: /* condition: value comOp ID  */
#line 1013 "yacc_sql.y"
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
#line 2826 "yacc_sql.tab.c"
    break;

  case 141: /* condition: ID DOT ID comOp value  */
#line 1035 "yacc_sql.y"
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
#line 2851 "yacc_sql.tab.c"
    break;

  case 142: /* condition: value comOp ID DOT ID  */
#line 1056 "yacc_sql.y"
                {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 2865 "yacc_sql.tab.c"
    break;

  case 143: /* condition: ID DOT ID comOp ID DOT ID  */
#line 1066 "yacc_sql.y"
        {
			
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2880 "yacc_sql.tab.c"
    break;

  case 144: /* condition: EXIST_T LBRACE sub_query RBRACE  */
#line 1077 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2890 "yacc_sql.tab.c"
    break;

  case 145: /* condition: NOT EXIST_T LBRACE sub_query RBRACE  */
#line 1083 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, NOT_EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2900 "yacc_sql.tab.c"
    break;

  case 146: /* condition: LBRACE sub_query RBRACE reverseComp ID  */
#line 1088 "yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->comp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2912 "yacc_sql.tab.c"
    break;

  case 147: /* condition: ID IN_T LBRACE in_cells RBRACE  */
#line 1095 "yacc_sql.y"
                                       {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2925 "yacc_sql.tab.c"
    break;

  case 148: /* condition: ID NOT IN_T LBRACE in_cells RBRACE  */
#line 1103 "yacc_sql.y"
                                           {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2938 "yacc_sql.tab.c"
    break;

  case 149: /* condition: ID DOT ID NOT IN_T LBRACE in_cells RBRACE  */
#line 1111 "yacc_sql.y"
                                                  {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-7].string), (yyvsp[-5].string));
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2951 "yacc_sql.tab.c"
    break;

  case 150: /* condition: ID IN_T LBRACE sub_query RBRACE  */
#line 1119 "yacc_sql.y"
                                        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2963 "yacc_sql.tab.c"
    break;

  case 151: /* condition: ID DOT ID IN_T LBRACE sub_query RBRACE  */
#line 1126 "yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2975 "yacc_sql.tab.c"
    break;

  case 152: /* condition: ID NOT IN_T LBRACE sub_query RBRACE  */
#line 1133 "yacc_sql.y"
                                            {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2987 "yacc_sql.tab.c"
    break;

  case 153: /* condition: ID DOT ID NOT IN_T LBRACE sub_query RBRACE  */
#line 1140 "yacc_sql.y"
                                                   {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-7].string), (yyvsp[-5].string));
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2999 "yacc_sql.tab.c"
    break;

  case 154: /* condition: ID EQ LBRACE sub_query RBRACE  */
#line 1148 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, EQUAL_TO, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3011 "yacc_sql.tab.c"
    break;

  case 155: /* condition: ID LT LBRACE sub_query RBRACE  */
#line 1156 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, LESS_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3023 "yacc_sql.tab.c"
    break;

  case 156: /* condition: ID GT LBRACE sub_query RBRACE  */
#line 1164 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, GREAT_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3035 "yacc_sql.tab.c"
    break;

  case 157: /* condition: ID LE LBRACE sub_query RBRACE  */
#line 1172 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition,LESS_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3047 "yacc_sql.tab.c"
    break;

  case 158: /* condition: ID GE LBRACE sub_query RBRACE  */
#line 1180 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, GREAT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3059 "yacc_sql.tab.c"
    break;

  case 159: /* condition: ID NE LBRACE sub_query RBRACE  */
#line 1188 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, NOT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3071 "yacc_sql.tab.c"
    break;

  case 160: /* condition: ID DOT ID EQ LBRACE sub_query RBRACE  */
#line 1196 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, EQUAL_TO, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3083 "yacc_sql.tab.c"
    break;

  case 161: /* condition: ID DOT ID LT LBRACE sub_query RBRACE  */
#line 1204 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, LESS_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3095 "yacc_sql.tab.c"
    break;

  case 162: /* condition: ID DOT ID GT LBRACE sub_query RBRACE  */
#line 1212 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, GREAT_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3107 "yacc_sql.tab.c"
    break;

  case 163: /* condition: ID DOT ID LE LBRACE sub_query RBRACE  */
#line 1220 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition,LESS_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3119 "yacc_sql.tab.c"
    break;

  case 164: /* condition: ID DOT ID GE LBRACE sub_query RBRACE  */
#line 1228 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, GREAT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3131 "yacc_sql.tab.c"
    break;

  case 165: /* condition: ID DOT ID NE LBRACE sub_query RBRACE  */
#line 1236 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, NOT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3143 "yacc_sql.tab.c"
    break;

  case 166: /* condition: LBRACE sub_query RBRACE NE LBRACE sub_query RBRACE  */
#line 1243 "yacc_sql.y"
                                                            {
		Condition condition;
		condition_init_with_two_query(&condition, NOT_EQUAL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1],CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-2]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3153 "yacc_sql.tab.c"
    break;

  case 167: /* in_cells: value value_list  */
#line 1250 "yacc_sql.y"
                          {
	}
#line 3160 "yacc_sql.tab.c"
    break;

  case 168: /* reverseComp: EQ  */
#line 1254 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 3166 "yacc_sql.tab.c"
    break;

  case 169: /* reverseComp: LT  */
#line 1255 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3172 "yacc_sql.tab.c"
    break;

  case 170: /* reverseComp: GT  */
#line 1256 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3178 "yacc_sql.tab.c"
    break;

  case 171: /* reverseComp: LE  */
#line 1257 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3184 "yacc_sql.tab.c"
    break;

  case 172: /* reverseComp: GE  */
#line 1258 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3190 "yacc_sql.tab.c"
    break;

  case 173: /* reverseComp: NE  */
#line 1259 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3196 "yacc_sql.tab.c"
    break;

  case 174: /* comOp: EQ  */
#line 1262 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO;}
#line 3202 "yacc_sql.tab.c"
    break;

  case 175: /* comOp: LT  */
#line 1263 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3208 "yacc_sql.tab.c"
    break;

  case 176: /* comOp: GT  */
#line 1264 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3214 "yacc_sql.tab.c"
    break;

  case 177: /* comOp: LE  */
#line 1265 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3220 "yacc_sql.tab.c"
    break;

  case 178: /* comOp: GE  */
#line 1266 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3226 "yacc_sql.tab.c"
    break;

  case 179: /* comOp: NE  */
#line 1267 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3232 "yacc_sql.tab.c"
    break;

  case 180: /* comOp: LIKE  */
#line 1268 "yacc_sql.y"
               { CONTEXT->comp = LIKE_TO; }
#line 3238 "yacc_sql.tab.c"
    break;

  case 181: /* comOp: IN_T  */
#line 1269 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 3244 "yacc_sql.tab.c"
    break;

  case 182: /* comOp: NOT IN_T  */
#line 1270 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 3250 "yacc_sql.tab.c"
    break;

  case 183: /* comOp: NOT EXIST_T  */
#line 1271 "yacc_sql.y"
                     {CONTEXT->comp = NOT_EXIST;}
#line 3256 "yacc_sql.tab.c"
    break;

  case 184: /* comOp: EXIST_T  */
#line 1272 "yacc_sql.y"
                 {CONTEXT->comp = EXIST;}
#line 3262 "yacc_sql.tab.c"
    break;

  case 185: /* comOp: NOT LIKE  */
#line 1273 "yacc_sql.y"
                   { CONTEXT->comp = NOT_LIKE; }
#line 3268 "yacc_sql.tab.c"
    break;

  case 186: /* comOp: IS NOT  */
#line 1274 "yacc_sql.y"
                 { CONTEXT->comp = COMP_IS_NOT; }
#line 3274 "yacc_sql.tab.c"
    break;

  case 187: /* comOp: IS  */
#line 1275 "yacc_sql.y"
             { CONTEXT->comp = COMP_IS; }
#line 3280 "yacc_sql.tab.c"
    break;

  case 188: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1280 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3289 "yacc_sql.tab.c"
    break;


#line 3293 "yacc_sql.tab.c"

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

#line 1285 "yacc_sql.y"

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
