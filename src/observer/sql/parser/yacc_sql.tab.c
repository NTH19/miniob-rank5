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


#line 136 "yacc_sql.tab.c"

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
  YYSYMBOL_DT2 = 14,                       /* DT2  */
  YYSYMBOL_INSERT = 15,                    /* INSERT  */
  YYSYMBOL_DELETE = 16,                    /* DELETE  */
  YYSYMBOL_UPDATE = 17,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 18,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 19,                    /* RBRACE  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 21,                 /* TRX_BEGIN  */
  YYSYMBOL_COUNT_T = 22,                   /* COUNT_T  */
  YYSYMBOL_MAX_T = 23,                     /* MAX_T  */
  YYSYMBOL_MIN_T = 24,                     /* MIN_T  */
  YYSYMBOL_AVG_T = 25,                     /* AVG_T  */
  YYSYMBOL_SUM_T = 26,                     /* SUM_T  */
  YYSYMBOL_TRX_COMMIT = 27,                /* TRX_COMMIT  */
  YYSYMBOL_DT = 28,                        /* DT  */
  YYSYMBOL_TRX_ROLLBACK = 29,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 30,                     /* INT_T  */
  YYSYMBOL_STRING_T = 31,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 32,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 33,                    /* DATE_T  */
  YYSYMBOL_TEXT_T = 34,                    /* TEXT_T  */
  YYSYMBOL_HELP = 35,                      /* HELP  */
  YYSYMBOL_EXIT = 36,                      /* EXIT  */
  YYSYMBOL_DOT = 37,                       /* DOT  */
  YYSYMBOL_INTO = 38,                      /* INTO  */
  YYSYMBOL_VALUES = 39,                    /* VALUES  */
  YYSYMBOL_FROM = 40,                      /* FROM  */
  YYSYMBOL_WHERE = 41,                     /* WHERE  */
  YYSYMBOL_AS = 42,                        /* AS  */
  YYSYMBOL_AND = 43,                       /* AND  */
  YYSYMBOL_SET = 44,                       /* SET  */
  YYSYMBOL_DT1 = 45,                       /* DT1  */
  YYSYMBOL_GROUP = 46,                     /* GROUP  */
  YYSYMBOL_ON = 47,                        /* ON  */
  YYSYMBOL_INNER_T = 48,                   /* INNER_T  */
  YYSYMBOL_JOIN_T = 49,                    /* JOIN_T  */
  YYSYMBOL_LOAD = 50,                      /* LOAD  */
  YYSYMBOL_DATA = 51,                      /* DATA  */
  YYSYMBOL_INFILE = 52,                    /* INFILE  */
  YYSYMBOL_EQ = 53,                        /* EQ  */
  YYSYMBOL_LT = 54,                        /* LT  */
  YYSYMBOL_GT = 55,                        /* GT  */
  YYSYMBOL_LE = 56,                        /* LE  */
  YYSYMBOL_GE = 57,                        /* GE  */
  YYSYMBOL_NE = 58,                        /* NE  */
  YYSYMBOL_EXIST_T = 59,                   /* EXIST_T  */
  YYSYMBOL_IN_T = 60,                      /* IN_T  */
  YYSYMBOL_LIKE = 61,                      /* LIKE  */
  YYSYMBOL_NOT = 62,                       /* NOT  */
  YYSYMBOL_IS = 63,                        /* IS  */
  YYSYMBOL_NULLL = 64,                     /* NULLL  */
  YYSYMBOL_NULLABLE = 65,                  /* NULLABLE  */
  YYSYMBOL_UNIQUE = 66,                    /* UNIQUE  */
  YYSYMBOL_ORDER = 67,                     /* ORDER  */
  YYSYMBOL_BY = 68,                        /* BY  */
  YYSYMBOL_ADD = 69,                       /* ADD  */
  YYSYMBOL_SUB = 70,                       /* SUB  */
  YYSYMBOL_DIV = 71,                       /* DIV  */
  YYSYMBOL_NUMBER = 72,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 73,                     /* FLOAT  */
  YYSYMBOL_DATEE = 74,                     /* DATEE  */
  YYSYMBOL_ID = 75,                        /* ID  */
  YYSYMBOL_PATH = 76,                      /* PATH  */
  YYSYMBOL_SSS = 77,                       /* SSS  */
  YYSYMBOL_STAR = 78,                      /* STAR  */
  YYSYMBOL_STRING_V = 79,                  /* STRING_V  */
  YYSYMBOL_YYACCEPT = 80,                  /* $accept  */
  YYSYMBOL_commands = 81,                  /* commands  */
  YYSYMBOL_command = 82,                   /* command  */
  YYSYMBOL_exit = 83,                      /* exit  */
  YYSYMBOL_help = 84,                      /* help  */
  YYSYMBOL_sync = 85,                      /* sync  */
  YYSYMBOL_begin = 86,                     /* begin  */
  YYSYMBOL_commit = 87,                    /* commit  */
  YYSYMBOL_rollback = 88,                  /* rollback  */
  YYSYMBOL_drop_table = 89,                /* drop_table  */
  YYSYMBOL_show_tables = 90,               /* show_tables  */
  YYSYMBOL_show_indexes = 91,              /* show_indexes  */
  YYSYMBOL_desc_table = 92,                /* desc_table  */
  YYSYMBOL_create_index = 93,              /* create_index  */
  YYSYMBOL_index_attr_list = 94,           /* index_attr_list  */
  YYSYMBOL_index_attr = 95,                /* index_attr  */
  YYSYMBOL_drop_index = 96,                /* drop_index  */
  YYSYMBOL_create_table = 97,              /* create_table  */
  YYSYMBOL_attr_def_list = 98,             /* attr_def_list  */
  YYSYMBOL_attr_def = 99,                  /* attr_def  */
  YYSYMBOL_number = 100,                   /* number  */
  YYSYMBOL_type = 101,                     /* type  */
  YYSYMBOL_ID_get = 102,                   /* ID_get  */
  YYSYMBOL_dummy = 103,                    /* dummy  */
  YYSYMBOL_insert = 104,                   /* insert  */
  YYSYMBOL_record_list = 105,              /* record_list  */
  YYSYMBOL_record = 106,                   /* record  */
  YYSYMBOL_value_list = 107,               /* value_list  */
  YYSYMBOL_insert_value = 108,             /* insert_value  */
  YYSYMBOL_value = 109,                    /* value  */
  YYSYMBOL_delete = 110,                   /* delete  */
  YYSYMBOL_update = 111,                   /* update  */
  YYSYMBOL_update_attr_list = 112,         /* update_attr_list  */
  YYSYMBOL_update_attr = 113,              /* update_attr  */
  YYSYMBOL_update_select_attr = 114,       /* update_select_attr  */
  YYSYMBOL_update_agg = 115,               /* update_agg  */
  YYSYMBOL_select = 116,                   /* select  */
  YYSYMBOL_by_attrs = 117,                 /* by_attrs  */
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
#define YYLAST   861

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  270
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  783

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   334


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
      75,    76,    77,    78,    79
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   176,   176,   178,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   203,   208,   213,   219,   225,   231,   237,   243,
     249,   257,   264,   269,   276,   278,   282,   289,   296,   305,
     307,   311,   322,   333,   344,   355,   366,   379,   382,   383,
     384,   385,   386,   389,   396,   402,   412,   413,   418,   419,
     424,   425,   431,   436,   439,   442,   446,   450,   456,   466,
     474,   476,   480,   486,   494,   505,   510,   515,   520,   528,
     533,   538,   543,   548,   553,   558,   563,   568,   573,   578,
     587,   598,   609,   621,   635,   646,   657,   667,   679,   685,
     693,   704,   723,   742,   761,   780,   798,   816,   834,   855,
     876,   894,   913,   931,   950,   968,   986,  1007,  1029,  1048,
    1067,  1086,  1105,  1124,  1143,  1165,  1186,  1207,  1226,  1245,
    1264,  1283,  1302,  1321,  1339,  1357,  1375,  1393,  1412,  1431,
    1452,  1473,  1495,  1517,  1535,  1553,  1572,  1591,  1609,  1627,
    1646,  1665,  1683,  1701,  1719,  1737,  1758,  1779,  1801,  1823,
    1842,  1861,  1880,  1899,  1918,  1937,  1956,  1975,  1994,  2013,
    2032,  2051,  2073,  2097,  2099,  2104,  2109,  2112,  2115,  2118,
    2121,  2124,  2130,  2133,  2138,  2143,  2148,  2155,  2161,  2167,
    2173,  2178,  2183,  2188,  2193,  2198,  2204,  2212,  2220,  2228,
    2236,  2244,  2252,  2259,  2266,  2274,  2282,  2290,  2298,  2304,
    2310,  2316,  2322,  2328,  2335,  2343,  2351,  2359,  2367,  2374,
    2382,  2390,  2398,  2408,  2409,  2414,  2420,  2425,  2427,  2433,
    2439,  2447,  2454,  2460,  2467,  2476,  2478,  2481,  2485,  2490,
    2492,  2495,  2497,  2501,  2507,  2513,  2519,  2526,  2534,  2541,
    2547,  2553,  2560,  2567,  2571,  2572,  2573,  2574,  2575,  2576,
    2579,  2580,  2581,  2582,  2583,  2584,  2585,  2586,  2587,  2588,
    2592
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
  "SYNC", "DT2", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA",
  "TRX_BEGIN", "COUNT_T", "MAX_T", "MIN_T", "AVG_T", "SUM_T", "TRX_COMMIT",
  "DT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T", "TEXT_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AS", "AND",
  "SET", "DT1", "GROUP", "ON", "INNER_T", "JOIN_T", "LOAD", "DATA",
  "INFILE", "EQ", "LT", "GT", "LE", "GE", "NE", "EXIST_T", "IN_T", "LIKE",
  "NOT", "IS", "NULLL", "NULLABLE", "UNIQUE", "ORDER", "BY", "ADD", "SUB",
  "DIV", "NUMBER", "FLOAT", "DATEE", "ID", "PATH", "SSS", "STAR",
  "STRING_V", "$accept", "commands", "command", "exit", "help", "sync",
  "begin", "commit", "rollback", "drop_table", "show_tables",
  "show_indexes", "desc_table", "create_index", "index_attr_list",
  "index_attr", "drop_index", "create_table", "attr_def_list", "attr_def",
  "number", "type", "ID_get", "dummy", "insert", "record_list", "record",
  "value_list", "insert_value", "value", "delete", "update",
  "update_attr_list", "update_attr", "update_select_attr", "update_agg",
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

#define YYPACT_NINF (-302)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -302,   746,  -302,    11,   137,   111,   -53,   363,    30,  -302,
       0,    60,    44,   152,   204,  -302,   230,   297,   319,  -302,
     184,  -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,
    -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,
     180,   182,   320,   255,   275,   186,   340,   342,   348,   379,
     387,  -302,   186,  -302,  -302,  -302,   -32,  -302,   390,  -302,
     160,   367,   410,   411,   376,  -302,   343,   344,   373,  -302,
    -302,  -302,  -302,  -302,   368,   403,   377,   351,   420,   425,
     148,    63,   354,   355,   356,   357,   -36,   159,   359,  -302,
     362,  -302,   186,   186,   186,   186,   186,  -302,   364,  -302,
    -302,   366,   396,   397,   369,   370,   374,   375,   401,  -302,
    -302,  -302,    -3,   433,    83,   120,   140,   142,   -28,  -302,
    -302,    -5,   160,   -36,   -36,  -302,  -302,   205,   450,   436,
     128,   452,   404,   438,   421,  -302,   440,   360,   444,   388,
      41,   391,    53,   164,   392,   223,   394,   227,   398,   236,
     399,   400,  -302,   301,   402,   390,  -302,  -302,   405,   407,
     416,   451,   397,  -302,   186,   458,    37,   461,   424,   783,
     442,  -302,   198,   369,   397,   481,   374,   469,  -302,  -302,
    -302,  -302,  -302,   100,   415,   474,   418,  -302,   476,   422,
    -302,   423,  -302,   480,   427,  -302,   485,   430,  -302,   488,
     434,  -302,   492,  -302,   -11,   390,   390,  -302,    38,   451,
     437,   397,    36,   493,   304,   436,   497,    28,   495,   507,
     499,  -302,  -302,  -302,  -302,  -302,  -302,   501,  -302,   -16,
     459,   218,   128,  -302,    99,  -302,   438,   519,   449,   440,
     522,   454,   464,  -302,  -302,   510,   415,  -302,   237,  -302,
    -302,   243,  -302,   252,  -302,   254,  -302,   259,   457,   390,
    -302,  -302,  -302,   460,   451,  -302,   397,   486,   534,  -302,
     471,   186,   524,   458,  -302,   526,   527,   529,   531,   533,
     -19,   331,   536,   507,     2,   535,  -302,  -302,    37,   304,
     442,     3,  -302,  -302,   549,  -302,  -302,  -302,   538,  -302,
     415,   540,   510,   490,  -302,   500,  -302,   506,  -302,   508,
    -302,   512,  -302,   390,  -302,   451,  -302,   558,   128,  -302,
     513,   493,  -302,  -302,   324,   514,   516,   518,   520,   525,
     528,   530,   523,  -302,  -302,  -302,  -302,  -302,   550,   537,
    -302,   548,   493,   551,   555,     2,   557,  -302,   564,   567,
     581,   584,   588,   571,  -302,   569,   574,  -302,   341,   510,
     612,   598,  -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,
     570,   442,    20,   616,  -302,   586,   602,   587,   589,   590,
     591,    56,    73,   585,   554,   507,  -302,  -302,  -302,  -302,
    -302,   611,   614,  -302,   333,   556,   559,   561,   562,   334,
     566,   568,   575,  -302,  -302,  -302,   641,   597,   397,  -302,
     572,   577,  -302,   578,    57,   580,   582,   583,   592,   593,
     594,   609,   595,   451,  -302,   596,   122,   631,  -302,  -302,
     176,   637,   177,   325,   330,   332,  -302,  -302,   397,   397,
    -302,  -302,   599,   657,  -302,   642,   644,   601,   603,   625,
     647,   654,   658,   661,   124,   643,   607,   451,  -302,   397,
     173,   617,   451,  -302,  -302,  -302,   619,  -302,  -302,   621,
    -302,   622,  -302,   624,  -302,   626,   665,   667,   640,  -302,
     627,   107,   261,   649,   629,   116,   209,   224,   241,   630,
     451,  -302,   633,   212,  -302,   397,  -302,   635,   451,  -302,
     451,  -302,   397,   672,   687,   692,   693,   694,  -302,  -302,
     128,   677,   646,   650,   676,   651,  -302,   397,   652,   262,
     655,   659,   679,   662,   664,   682,   666,   668,   684,   669,
     673,   689,   451,  -302,   397,   232,   678,   451,  -302,   397,
    -302,   451,  -302,   397,  -302,   397,  -302,  -302,  -302,  -302,
    -302,  -302,   570,   690,   263,   696,   695,  -302,   397,  -302,
     264,   697,  -302,   397,   266,   724,   701,   267,   729,   703,
     268,   731,   705,   271,   743,   709,  -302,   397,  -302,   711,
     451,  -302,   451,  -302,   397,  -302,  -302,   397,  -302,   397,
    -302,  -302,  -302,   713,  -302,   397,   714,   273,   397,  -302,
     715,  -302,   397,  -302,   397,  -302,   717,  -302,   397,   719,
     277,   722,  -302,   397,   723,   279,   725,  -302,   397,   727,
     282,   730,  -302,   397,   732,   284,   397,  -302,   451,  -302,
     397,  -302,   397,  -302,   397,  -302,  -302,  -302,   397,  -302,
     289,   733,  -302,   397,  -302,  -302,   397,  -302,   397,  -302,
    -302,   397,  -302,   290,   734,  -302,   397,  -302,   397,  -302,
     293,   736,  -302,   397,  -302,   397,  -302,   303,   737,  -302,
     397,  -302,   397,  -302,   305,   738,  -302,   397,  -302,  -302,
     397,  -302,   397,  -302,  -302,   397,  -302,   739,  -302,   397,
    -302,   397,  -302,   397,  -302,  -302,   397,  -302,   740,  -302,
     397,  -302,   397,  -302,   397,  -302,   741,  -302,   397,  -302,
     397,  -302,   397,  -302,   744,  -302,   397,  -302,   397,  -302,
     397,  -302,   745,  -302,   397,  -302,   397,  -302,   397,  -302,
    -302,  -302,  -302,   397,  -302,   397,  -302,  -302,  -302,  -302,
     397,  -302,   397,  -302,  -302,  -302,   397,  -302,   397,  -302,
    -302,  -302,   397,  -302,   397,  -302,  -302,  -302,   397,  -302,
     397,  -302,  -302,   397,  -302,  -302,   397,  -302,  -302,   397,
    -302,  -302,   397,  -302,  -302,   397,  -302,  -302,  -302,  -302,
    -302,  -302,  -302
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,    91,
       0,     0,     0,     0,     0,    92,     0,     0,     0,    90,
       0,     3,    21,    20,    15,    16,    17,    18,     9,    10,
      11,    12,    13,    14,     8,     5,     7,     6,     4,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,    63,    64,    65,   183,    66,   227,   182,
     223,     0,     0,     0,     0,    24,     0,     0,     0,    25,
      26,    27,    23,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,     0,     0,   188,
       0,   225,     0,     0,     0,     0,     0,   226,     0,    31,
      29,     0,     0,   239,     0,     0,     0,     0,     0,    28,
      37,   181,     0,     0,     0,     0,     0,     0,   184,   185,
     186,   227,   223,   176,   178,   180,   179,   235,     0,    58,
       0,     0,     0,    70,     0,    53,    39,     0,     0,     0,
     191,     0,   190,   192,     0,   193,     0,   195,     0,   194,
       0,     0,   189,     0,     0,   227,   228,   224,     0,     0,
       0,   235,   239,    30,     0,    56,     0,     0,     0,     0,
     241,    68,     0,     0,   239,     0,     0,     0,    48,    51,
      52,    49,    50,    44,     0,     0,     0,   203,     0,     0,
     202,     0,   204,     0,     0,   205,     0,     0,   207,     0,
       0,   206,     0,   187,   227,   227,   227,   233,   235,   235,
       0,   239,     0,    60,    62,    58,     0,     0,     0,     0,
       0,   260,   261,   262,   263,   264,   265,     0,   266,     0,
     269,     0,     0,   240,     0,    72,    70,     0,     0,    39,
       0,     0,     0,    46,    36,    34,     0,   197,   208,   196,
     198,   209,   199,   210,   201,   212,   200,   211,     0,   227,
     229,   230,   231,     0,   235,   236,   239,     0,     0,    93,
       0,     0,     0,    56,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,   268,     0,   243,
     241,     0,    71,    69,     0,    40,    38,    47,     0,    45,
       0,     0,    34,     0,   218,     0,   219,     0,   220,     0,
     222,     0,   221,   227,   234,   235,   238,     0,     0,    97,
       0,    60,    59,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,   257,   258,   259,     0,
     244,     0,    60,     0,     0,     0,     0,   242,     0,     0,
       0,     0,     0,    76,    75,     0,     0,   270,    41,    34,
       0,     0,   213,   214,   215,   217,   216,   232,   237,    96,
     173,   241,    98,     0,    61,     0,     0,     0,     0,     0,
       0,     0,   235,     0,     0,     0,   246,   245,   253,   249,
     247,     0,     0,   251,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,    35,    32,     0,     0,   239,   175,
       0,     0,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   235,    54,     0,   235,     0,   250,   248,
       0,     0,     0,     0,     0,     0,    77,    78,   239,   239,
      42,    33,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,     0,     0,   235,    54,   239,
     235,     0,   235,    54,   252,    80,     0,    79,    82,     0,
      84,     0,    88,     0,    86,     0,     0,     0,     0,    95,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
     235,    54,     0,   235,    54,   239,   102,     0,   235,    54,
     235,    54,   239,     0,     0,     0,     0,     0,    73,    74,
       0,     0,     0,     0,     0,     0,    54,   239,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,    54,   239,   235,     0,   235,    54,   239,
     118,   235,    54,   239,    54,   239,   128,    81,    83,    85,
      89,    87,   173,     0,    54,     0,     0,    54,   239,   103,
      54,     0,    54,   239,    54,     0,     0,    54,     0,     0,
      54,     0,     0,    54,     0,     0,    54,   239,   101,     0,
     235,    54,   235,    54,   239,   110,    54,   239,   127,   239,
     160,   174,   100,     0,    54,   239,     0,    54,   239,   119,
       0,    54,   239,    54,   239,   130,     0,    54,   239,     0,
      54,     0,    54,   239,     0,    54,     0,    54,   239,     0,
      54,     0,    54,   239,     0,    54,   239,   117,   235,    54,
     239,    54,   239,   126,   239,   159,   144,    54,   239,   104,
      54,     0,    54,   239,   111,    54,   239,   129,   239,   162,
      54,   239,   105,    54,     0,    54,   239,    54,   239,   106,
      54,     0,    54,   239,    54,   239,   108,    54,     0,    54,
     239,    54,   239,   107,    54,     0,    54,   239,   109,    54,
     239,   125,   239,   158,   143,   239,   120,     0,    54,   239,
      54,   239,   132,   239,   161,   146,   239,   121,     0,    54,
     239,    54,   239,   134,   239,   122,     0,    54,   239,    54,
     239,   136,   239,   124,     0,    54,   239,    54,   239,   140,
     239,   123,     0,    54,   239,    54,   239,   138,   239,   157,
     142,   112,    54,   239,   131,   239,   164,   145,   113,    54,
     239,   133,   239,   166,   114,    54,   239,   135,   239,   168,
     116,    54,   239,   139,   239,   172,   115,    54,   239,   137,
     239,   170,   141,   239,   163,   148,   239,   165,   150,   239,
     167,   152,   239,   171,   156,   239,   169,   154,   147,   149,
     151,   155,   153
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,  -302,
    -302,  -302,  -302,  -302,  -294,  -216,  -302,  -302,   478,   623,
    -302,  -302,  -302,    78,  -302,   545,   517,  -301,  -165,  -278,
    -302,  -302,   606,   648,  -302,  -302,  -302,  -302,  -215,   270,
     294,    -4,   702,  -302,  -119,  -137,  -162,  -277,  -127,   482,
    -302,  -302,  -302
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   301,   245,    33,    34,   177,   136,
     298,   183,   137,   459,    35,   216,   165,   272,   213,    59,
      36,    37,   174,   133,   355,   356,    38,   373,   218,   408,
     370,    80,    97,    61,    91,   162,   131,   233,   371,   344,
     339,   231,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     212,    60,   156,   170,   282,    87,   342,   235,   361,    90,
      88,   217,   237,   347,   151,    90,   140,    40,   329,    41,
     374,   330,    62,   331,   211,   348,   349,   350,   351,   352,
     302,   258,   153,    65,   141,    95,   207,   154,    66,   269,
     410,   388,    96,    89,   285,   286,   217,   152,    86,   268,
     275,   276,   277,   278,   279,    45,   332,   411,   158,    46,
      47,    48,    49,    50,   259,   404,    51,   342,   341,   343,
     155,   265,   266,   346,    53,    54,    55,    42,   353,    57,
     263,   354,   270,   186,   359,   260,   261,   262,   122,   123,
     124,   125,   126,   158,   409,   189,   419,   447,   420,   448,
      67,    51,   143,   280,   317,   290,   321,    52,   291,    53,
      54,    55,    56,   264,    57,   422,   187,    45,   241,    68,
     144,    46,    47,    48,    49,    50,   169,   316,   190,    45,
     391,   421,   449,    46,    47,    48,    49,    50,   112,   145,
     314,   113,   158,    43,   158,    44,   166,   512,   423,   513,
      46,    47,    48,    49,    50,    69,   520,   146,   521,   147,
     214,   149,   242,    51,   461,   243,   489,   111,   214,    52,
     427,    53,    54,    55,    56,    51,    57,   148,   368,   150,
      92,    52,   514,    53,    54,    55,    56,   167,    57,    58,
     168,   522,    51,   158,   367,   465,   468,   462,    52,   490,
      53,    54,    55,    56,    45,    57,   191,    70,    46,    47,
      48,    49,    50,   466,   469,   497,   234,    93,    94,    95,
      46,    47,    48,    49,    50,   158,    96,   289,   169,    93,
      94,    95,   158,    71,   118,    74,   288,   119,    96,   192,
      46,    47,    48,    49,    50,   424,   443,   159,   498,   523,
      51,   524,   158,   160,   536,    75,    52,    76,    53,    54,
      55,    56,    51,    57,   526,   194,   527,   214,    52,   197,
      53,    54,    55,    56,   579,    57,   476,   477,   200,   303,
     161,   529,    51,   530,   525,   305,   458,   537,    52,   463,
      53,    54,    55,    56,   307,    57,   309,   496,   195,   528,
      72,   311,   198,   515,   561,   593,   600,   580,   606,   611,
     616,   201,   304,   621,   169,   641,   531,   491,   306,   654,
     494,   661,    73,   499,   668,   501,   675,   308,    77,   310,
      78,   687,   698,   540,   312,   706,   516,   562,   594,   601,
     546,   607,   612,   617,   470,   714,   622,   722,   642,   472,
      79,   474,   655,   533,   662,   559,   538,   669,    81,   676,
      82,   542,   471,   544,   688,   699,    83,   473,   707,   475,
      63,    64,   578,    93,    94,    95,   204,   585,   715,   205,
     723,   588,    96,   590,   333,   334,   335,   336,   337,   338,
     178,   179,   180,   181,   182,   576,   599,    84,   581,   375,
     583,   605,   376,   402,   586,    85,   403,    98,   430,   436,
      90,   431,   437,    99,   100,   627,   101,   104,   102,   103,
     105,   106,   633,   109,   107,   635,   108,   636,   110,   114,
     115,   116,   117,   639,   120,   129,   644,   121,   130,   127,
     647,   128,   649,   629,   132,   631,   652,   134,   139,   135,
     138,   659,   142,   163,   164,   171,   666,   172,   173,   175,
     176,   673,   184,   185,   678,   210,   188,   193,   681,   196,
     683,   158,   684,   199,   202,   203,   686,   206,   215,   219,
     208,   692,   209,   220,   694,   232,   695,   238,   240,   697,
     244,   679,   246,   247,   703,   248,   705,   249,   250,   251,
     274,   711,   252,   713,   253,   254,   169,   255,   719,   256,
     721,   257,   267,   271,   281,   727,   217,   283,   729,   284,
     730,   287,   293,   731,   294,   296,   297,   734,   299,   736,
     300,   737,   313,   318,   738,   315,   495,   319,   741,   320,
     743,   502,   744,   322,   324,   325,   747,   326,   749,   327,
     750,   328,   357,   345,   753,   340,   755,   358,   756,   360,
     517,   369,   759,   384,   761,   362,   762,   387,   385,   534,
     389,   764,   539,   765,   390,   363,   393,   543,   767,   545,
     768,   364,   394,   365,   770,   395,   771,   366,   372,   377,
     773,   378,   774,   379,   558,   380,   776,   563,   777,   396,
     381,   778,   397,   382,   779,   383,   398,   780,   399,   400,
     781,   577,   386,   782,   401,   405,   584,   406,   407,   412,
     587,   414,   589,   413,   415,   425,   416,   417,   418,   426,
     428,   432,   595,   429,   433,   598,   434,   435,   602,   440,
     604,   438,   608,   439,   441,   613,   442,   444,   618,   456,
     464,   623,   445,   446,   626,   450,   467,   451,   452,   630,
     479,   632,   480,   481,   634,   484,   485,   453,   454,   455,
     457,   460,   638,   486,   478,   643,   482,   487,   483,   646,
     488,   648,   493,   492,   508,   651,   509,   510,   656,   518,
     658,   547,   500,   663,   503,   665,   504,   505,   670,   506,
     672,   507,   511,   677,   519,   532,   548,   680,   535,   682,
     541,   549,   550,   551,   553,   685,   556,   295,   689,   566,
     691,   554,   569,   693,   572,   555,   557,   560,   696,   575,
     564,   700,   273,   702,   565,   704,   596,   567,   708,   568,
     710,   570,   712,   571,   573,   716,     2,   718,   574,   720,
       3,     4,   724,   582,   726,     5,     6,   728,     7,     8,
       9,    10,    11,    12,   609,   592,   733,    13,   735,   614,
     597,   619,   603,    14,    15,    16,   610,   740,   615,   742,
     620,    17,    18,   624,   625,   746,   628,   748,   637,   640,
     645,    19,   650,   752,   653,   754,    20,   657,   660,   239,
     664,   758,   667,   760,   552,   671,     0,   674,   690,   701,
     763,   709,   717,   725,   732,   739,   745,   766,   323,   751,
     757,   236,   591,   769,   157,     0,     0,   392,     0,   772,
       0,     0,     0,     0,     0,   775,   221,   222,   223,   224,
     225,   226,   292,   227,   228,   229,   230,     0,     0,     0,
       0,     0,    93,    94,    95,     0,     0,     0,     0,     0,
       0,    96
};

static const yytype_int16 yycheck[] =
{
     162,     5,   121,   130,   219,    37,   284,   172,   302,    20,
      42,     9,   174,   290,    42,    20,    19,     6,    37,     8,
     321,    40,    75,    42,   161,    22,    23,    24,    25,    26,
     246,    42,    37,     3,    37,    71,   155,    42,    38,     3,
      20,   342,    78,    75,    60,    61,     9,    75,    52,   211,
      22,    23,    24,    25,    26,    18,    75,    37,    20,    22,
      23,    24,    25,    26,    75,   359,    64,   345,   283,   284,
      75,   208,   209,   288,    72,    73,    74,    66,    75,    77,
      42,    78,    46,    42,   300,   204,   205,   206,    92,    93,
      94,    95,    96,    20,   371,    42,    40,    40,    42,    42,
      40,    64,    19,    75,   266,   232,   271,    70,     9,    72,
      73,    74,    75,    75,    77,    42,    75,    18,    18,    75,
      37,    22,    23,    24,    25,    26,   130,   264,    75,    18,
     345,    75,    75,    22,    23,    24,    25,    26,    75,    19,
     259,    78,    20,     6,    20,     8,    18,    40,    75,    42,
      22,    23,    24,    25,    26,     3,    40,    37,    42,    19,
     164,    19,    62,    64,    42,    65,    42,    19,   172,    70,
     385,    72,    73,    74,    75,    64,    77,    37,   315,    37,
      20,    70,    75,    72,    73,    74,    75,    59,    77,    78,
      62,    75,    64,    20,   313,    19,    19,    75,    70,    75,
      72,    73,    74,    75,    18,    77,    42,     3,    22,    23,
      24,    25,    26,    37,    37,    42,    18,    69,    70,    71,
      22,    23,    24,    25,    26,    20,    78,   231,   232,    69,
      70,    71,    20,     3,    75,    51,    18,    78,    78,    75,
      22,    23,    24,    25,    26,   382,   408,    42,    75,    40,
      64,    42,    20,    48,    42,    75,    70,    75,    72,    73,
      74,    75,    64,    77,    40,    42,    42,   271,    70,    42,
      72,    73,    74,    75,    42,    77,   438,   439,    42,    42,
      75,    40,    64,    42,    75,    42,   423,    75,    70,   426,
      72,    73,    74,    75,    42,    77,    42,   459,    75,    75,
       3,    42,    75,    42,    42,    42,    42,    75,    42,    42,
      42,    75,    75,    42,   318,    42,    75,   454,    75,    42,
     457,    42,     3,   460,    42,   462,    42,    75,     8,    75,
      75,    42,    42,   495,    75,    42,    75,    75,    75,    75,
     502,    75,    75,    75,    19,    42,    75,    42,    75,    19,
      75,    19,    75,   490,    75,   517,   493,    75,    18,    75,
      18,   498,    37,   500,    75,    75,    18,    37,    75,    37,
       7,     8,   534,    69,    70,    71,    75,   539,    75,    78,
      75,   543,    78,   545,    53,    54,    55,    56,    57,    58,
      30,    31,    32,    33,    34,   532,   558,    18,   535,    75,
     537,   563,    78,    62,   541,    18,    65,    40,    75,    75,
      20,    78,    78,     3,     3,   577,    40,    44,    75,    75,
      52,    18,   584,     3,    47,   587,    75,   589,     3,    75,
      75,    75,    75,   595,    75,    39,   598,    75,    41,    75,
     602,    75,   604,   580,    75,   582,   608,    77,    47,    75,
      75,   613,    19,     3,    18,     3,   618,    53,    20,    38,
      20,   623,    18,    75,   626,    49,    75,    75,   630,    75,
     632,    20,   634,    75,    75,    75,   638,    75,    20,    18,
      75,   643,    75,    59,   646,    43,   648,     6,    19,   651,
      75,   628,    18,    75,   656,    19,   658,    75,    75,    19,
       3,   663,    75,   665,    19,    75,   510,    19,   670,    75,
     672,    19,    75,    20,    19,   677,     9,    18,   680,    18,
     682,    62,     3,   685,    75,     3,    72,   689,    64,   691,
      20,   693,    75,    47,   696,    75,   458,     3,   700,    68,
     702,   463,   704,    19,    18,    18,   708,    18,   710,    18,
     712,    18,     3,    18,   716,    19,   718,    19,   720,    19,
     482,     3,   724,    40,   726,    75,   728,    19,    18,   491,
      19,   733,   494,   735,    19,    75,    19,   499,   740,   501,
     742,    75,    18,    75,   746,    18,   748,    75,    75,    75,
     752,    75,   754,    75,   516,    75,   758,   519,   760,    18,
      75,   763,    18,    75,   766,    75,    18,   769,    37,    40,
     772,   533,    75,   775,    40,     3,   538,    19,    48,     3,
     542,    19,   544,    37,    37,    40,    37,    37,    37,    75,
      19,    75,   554,    19,    75,   557,    75,    75,   560,    64,
     562,    75,   564,    75,     3,   567,    49,    75,   570,    40,
      19,   573,    75,    75,   576,    75,    19,    75,    75,   581,
       3,   583,    20,    19,   586,    40,    19,    75,    75,    75,
      75,    75,   594,    19,    75,   597,    75,    19,    75,   601,
      19,   603,    75,    40,    19,   607,    19,    47,   610,    40,
     612,    19,    75,   615,    75,   617,    75,    75,   620,    75,
     622,    75,    75,   625,    75,    75,    19,   629,    75,   631,
      75,    19,    19,    19,    37,   637,    40,   239,   640,    40,
     642,    75,    40,   645,    40,    75,    75,    75,   650,    40,
      75,   653,   215,   655,    75,   657,    40,    75,   660,    75,
     662,    75,   664,    75,    75,   667,     0,   669,    75,   671,
       4,     5,   674,    75,   676,     9,    10,   679,    12,    13,
      14,    15,    16,    17,    40,    75,   688,    21,   690,    40,
      75,    40,    75,    27,    28,    29,    75,   699,    75,   701,
      75,    35,    36,    40,    75,   707,    75,   709,    75,    75,
      75,    45,    75,   715,    75,   717,    50,    75,    75,   176,
      75,   723,    75,   725,   510,    75,    -1,    75,    75,    75,
     732,    75,    75,    75,    75,    75,    75,   739,   273,    75,
      75,   173,   552,   745,   122,    -1,    -1,   345,    -1,   751,
      -1,    -1,    -1,    -1,    -1,   757,    53,    54,    55,    56,
      57,    58,   236,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    81,     0,     4,     5,     9,    10,    12,    13,    14,
      15,    16,    17,    21,    27,    28,    29,    35,    36,    45,
      50,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    96,    97,   104,   110,   111,   116,   132,
       6,     8,    66,     6,     8,    18,    22,    23,    24,    25,
      26,    64,    70,    72,    73,    74,    75,    77,    78,   109,
     121,   123,    75,     7,     8,     3,    38,    40,    75,     3,
       3,     3,     3,     3,    51,    75,    75,     8,    75,    75,
     121,    18,    18,    18,    18,    18,   121,    37,    42,    75,
      20,   124,    20,    69,    70,    71,    78,   122,    40,     3,
       3,    40,    75,    75,    44,    52,    18,    47,    75,     3,
       3,    19,    75,    78,    75,    75,    75,    75,    75,    78,
      75,    75,   121,   121,   121,   121,   121,    75,    75,    39,
      41,   126,    75,   113,    77,    75,    99,   102,    75,    47,
      19,    37,    19,    19,    37,    19,    37,    19,    37,    19,
      37,    42,    75,    37,    42,    75,   124,   122,    20,    42,
      48,    75,   125,     3,    18,   106,    18,    59,    62,   121,
     128,     3,    53,    20,   112,    38,    20,    98,    30,    31,
      32,    33,    34,   101,    18,    75,    42,    75,    75,    42,
      75,    42,    75,    75,    42,    75,    75,    42,    75,    75,
      42,    75,    75,    75,    75,    78,    75,   124,    75,    75,
      49,   125,   126,   108,   121,    20,   105,     9,   118,    18,
      59,    53,    54,    55,    56,    57,    58,    60,    61,    62,
      63,   131,    43,   127,    18,   108,   113,   126,     6,    99,
      19,    18,    62,    65,    75,    95,    18,    75,    19,    75,
      75,    19,    75,    19,    75,    19,    75,    19,    42,    75,
     124,   124,   124,    42,    75,   125,   125,    75,   126,     3,
      46,    20,   107,   106,     3,    22,    23,    24,    25,    26,
      75,    19,   118,    18,    18,    60,    61,    62,    18,   121,
     128,     9,   112,     3,    75,    98,     3,    72,   100,    64,
      20,    94,    95,    42,    75,    42,    75,    42,    75,    42,
      75,    42,    75,    75,   124,    75,   125,   126,    47,     3,
      68,   108,    19,   105,    18,    18,    18,    18,    18,    37,
      40,    42,    75,    53,    54,    55,    56,    57,    58,   130,
      19,   118,   109,   118,   129,    18,   118,   127,    22,    23,
      24,    25,    26,    75,    78,   114,   115,     3,    19,    95,
      19,    94,    75,    75,    75,    75,    75,   124,   125,     3,
     120,   128,    75,   117,   107,    75,    78,    75,    75,    75,
      75,    75,    75,    75,    40,    18,    75,    19,   107,    19,
      19,   118,   129,    19,    18,    18,    18,    18,    18,    37,
      40,    40,    62,    65,    94,     3,    19,    48,   119,   127,
      20,    37,     3,    37,    19,    37,    37,    37,    37,    40,
      42,    75,    42,    75,   125,    40,    75,   118,    19,    19,
      75,    78,    75,    75,    75,    75,    75,    78,    75,    75,
      64,     3,    49,   126,    75,    75,    75,    40,    42,    75,
      75,    75,    75,    75,    75,    75,    40,    75,   125,   103,
      75,    42,    75,   125,    19,    19,    37,    19,    19,    37,
      19,    37,    19,    37,    19,    37,   126,   126,    75,     3,
      20,    19,    75,    75,    40,    19,    19,    19,    19,    42,
      75,   125,    40,    75,   125,   103,   126,    42,    75,   125,
      75,   125,   103,    75,    75,    75,    75,    75,    19,    19,
      47,    75,    40,    42,    75,    42,    75,   103,    40,    75,
      40,    42,    75,    40,    42,    75,    40,    42,    75,    40,
      42,    75,    75,   125,   103,    75,    42,    75,   125,   103,
     126,    75,   125,   103,   125,   103,   126,    19,    19,    19,
      19,    19,   120,    37,    75,    75,    40,    75,   103,   126,
      75,    42,    75,   103,    75,    75,    40,    75,    75,    40,
      75,    75,    40,    75,    75,    40,   125,   103,   126,    42,
      75,   125,    75,   125,   103,   126,   125,   103,   126,   103,
     126,   119,    75,    42,    75,   103,    40,    75,   103,   126,
      42,    75,   103,    75,   103,   126,    42,    75,   103,    40,
      75,    42,    75,   103,    40,    75,    42,    75,   103,    40,
      75,    42,    75,   103,    40,    75,   103,   126,    75,   125,
     103,   125,   103,   126,   103,   126,   126,    75,   103,   126,
      75,    42,    75,   103,   126,    75,   103,   126,   103,   126,
      75,   103,   126,    75,    42,    75,   103,    75,   103,   126,
      75,    42,    75,   103,    75,   103,   126,    75,    42,    75,
     103,    75,   103,   126,    75,    42,    75,   103,   126,   125,
     103,   126,   103,   126,   126,   103,   126,    42,    75,   103,
      75,   103,   126,   103,   126,   126,   103,   126,    42,    75,
     103,    75,   103,   126,   103,   126,    42,    75,   103,    75,
     103,   126,   103,   126,    42,    75,   103,    75,   103,   126,
     103,   126,    42,    75,   103,    75,   103,   126,   103,   126,
     126,   126,    75,   103,   126,   103,   126,   126,   126,    75,
     103,   126,   103,   126,   126,    75,   103,   126,   103,   126,
     126,    75,   103,   126,   103,   126,   126,    75,   103,   126,
     103,   126,   126,   103,   126,   126,   103,   126,   126,   103,
     126,   126,   103,   126,   126,   103,   126,   126,   126,   126,
     126,   126,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    93,    94,    94,    95,    96,    97,    98,
      98,    99,    99,    99,    99,    99,    99,   100,   101,   101,
     101,   101,   101,   102,   103,   104,   105,   105,   106,   106,
     107,   107,   108,   109,   109,   109,   109,   109,   110,   111,
     112,   112,   113,   113,   113,   114,   114,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   122,   122,   123,   123,   124,   124,   124,
     124,   124,   124,   124,   124,   125,   125,   125,   125,   126,
     126,   127,   127,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   129,   130,   130,   130,   130,   130,   130,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     132
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
       1,     1,     1,     7,    10,    12,     9,     8,     1,     3,
       7,     9,     7,     9,    11,    11,    11,    11,    11,    11,
       9,    11,    13,    13,    13,    13,    13,    10,     8,    10,
      12,    12,    12,    12,    12,    11,    10,     9,     8,    11,
      10,    13,    12,    13,    12,    13,    12,    13,    12,    13,
      12,    13,    12,    11,    10,    13,    12,    15,    14,    15,
      14,    15,    14,    15,    14,    15,    14,    12,    11,    10,
       9,    12,    11,    14,    13,    14,    13,    14,    13,    14,
      13,    14,    13,     0,     6,     2,     3,     2,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     5,     2,     4,
       4,     4,     4,     4,     4,     4,     6,     6,     6,     6,
       6,     6,     5,     5,     5,     5,     5,     5,     6,     6,
       6,     6,     6,     8,     8,     8,     8,     8,     7,     7,
       7,     7,     7,     0,     3,     2,     2,     0,     3,     5,
       5,     5,     7,     4,     6,     0,     3,     5,     4,     0,
       3,     0,     3,     3,     4,     5,     5,     5,     6,     5,
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
#line 203 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1775 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 208 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1783 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 213 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1791 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 219 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1799 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 225 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1807 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 231 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1815 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 237 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1824 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 243 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1832 "yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 249 "yacc_sql.y"
                                {
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
    }
#line 1841 "yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 257 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1850 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 265 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
		}
#line 1859 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 270 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
		}
#line 1868 "yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA index_attr index_attr_list  */
#line 278 "yacc_sql.y"
                                           { }
#line 1874 "yacc_sql.tab.c"
    break;

  case 36: /* index_attr: ID  */
#line 283 "yacc_sql.y"
                {
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
		}
#line 1882 "yacc_sql.tab.c"
    break;

  case 37: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 290 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1891 "yacc_sql.tab.c"
    break;

  case 38: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 297 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1903 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 307 "yacc_sql.y"
                                   {    }
#line 1909 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 312 "yacc_sql.y"
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
#line 1924 "yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type LBRACE number RBRACE NOT NULLL  */
#line 323 "yacc_sql.y"
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
#line 1939 "yacc_sql.tab.c"
    break;

  case 43: /* attr_def: ID_get type LBRACE number RBRACE NULLABLE  */
#line 334 "yacc_sql.y"
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
#line 1954 "yacc_sql.tab.c"
    break;

  case 44: /* attr_def: ID_get type  */
#line 345 "yacc_sql.y"
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
#line 1969 "yacc_sql.tab.c"
    break;

  case 45: /* attr_def: ID_get type NOT NULLL  */
#line 356 "yacc_sql.y"
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
#line 1984 "yacc_sql.tab.c"
    break;

  case 46: /* attr_def: ID_get type NULLABLE  */
#line 367 "yacc_sql.y"
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
#line 1999 "yacc_sql.tab.c"
    break;

  case 47: /* number: NUMBER  */
#line 379 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 2005 "yacc_sql.tab.c"
    break;

  case 48: /* type: INT_T  */
#line 382 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 2011 "yacc_sql.tab.c"
    break;

  case 49: /* type: DATE_T  */
#line 383 "yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 2017 "yacc_sql.tab.c"
    break;

  case 50: /* type: TEXT_T  */
#line 384 "yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 2023 "yacc_sql.tab.c"
    break;

  case 51: /* type: STRING_T  */
#line 385 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 2029 "yacc_sql.tab.c"
    break;

  case 52: /* type: FLOAT_T  */
#line 386 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 2035 "yacc_sql.tab.c"
    break;

  case 53: /* ID_get: ID  */
#line 390 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 2044 "yacc_sql.tab.c"
    break;

  case 54: /* dummy: %empty  */
#line 396 "yacc_sql.y"
      {
		CONTEXT->depth++;
		CONTEXT->sub_con_start[CONTEXT->depth]=CONTEXT->condition_length;
	}
#line 2053 "yacc_sql.tab.c"
    break;

  case 55: /* insert: INSERT INTO ID VALUES record record_list SEMICOLON  */
#line 403 "yacc_sql.y"
        {
		CONTEXT->ssql->flag=SCF_INSERT;//"insert";
		CONTEXT->ssql->sstr.insertion.relation_name = (yyvsp[-4].string);
		CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
		inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-4].string), CONTEXT->values, CONTEXT->value_length,CONTEXT->single_record_length,CONTEXT->record_length);

      	CONTEXT->value_length=0;
	  	CONTEXT->record_length=0;
    }
#line 2067 "yacc_sql.tab.c"
    break;

  case 57: /* record_list: COMMA record record_list  */
#line 413 "yacc_sql.y"
                                        {

		}
#line 2075 "yacc_sql.tab.c"
    break;

  case 59: /* record: LBRACE insert_value value_list RBRACE  */
#line 420 "yacc_sql.y"
                {
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		}
#line 2084 "yacc_sql.tab.c"
    break;

  case 61: /* value_list: COMMA insert_value value_list  */
#line 425 "yacc_sql.y"
                                     { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 2092 "yacc_sql.tab.c"
    break;

  case 62: /* insert_value: expr  */
#line 431 "yacc_sql.y"
             {
		value_init_astexpr((yyvsp[0].expr1), &CONTEXT->values[CONTEXT->value_length - 1]);
	}
#line 2100 "yacc_sql.tab.c"
    break;

  case 63: /* value: NUMBER  */
#line 436 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2108 "yacc_sql.tab.c"
    break;

  case 64: /* value: FLOAT  */
#line 439 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2116 "yacc_sql.tab.c"
    break;

  case 65: /* value: DATEE  */
#line 442 "yacc_sql.y"
               {
			(yyvsp[0].dates) = substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].dates));
		}
#line 2125 "yacc_sql.tab.c"
    break;

  case 66: /* value: SSS  */
#line 446 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2134 "yacc_sql.tab.c"
    break;

  case 67: /* value: NULLL  */
#line 450 "yacc_sql.y"
               {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		}
#line 2142 "yacc_sql.tab.c"
    break;

  case 68: /* delete: DELETE FROM ID where SEMICOLON  */
#line 457 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2154 "yacc_sql.tab.c"
    break;

  case 69: /* update: UPDATE ID SET update_attr update_attr_list where SEMICOLON  */
#line 467 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2164 "yacc_sql.tab.c"
    break;

  case 72: /* update_attr: ID EQ insert_value  */
#line 481 "yacc_sql.y"
                {
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			CONTEXT->value_length = 0;
		}
#line 2174 "yacc_sql.tab.c"
    break;

  case 73: /* update_attr: ID EQ LBRACE SELECT update_select_attr FROM ID where RBRACE  */
#line 487 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2186 "yacc_sql.tab.c"
    break;

  case 74: /* update_attr: ID EQ LBRACE SELECT update_agg FROM ID where RBRACE  */
#line 495 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2198 "yacc_sql.tab.c"
    break;

  case 75: /* update_select_attr: STAR  */
#line 505 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2208 "yacc_sql.tab.c"
    break;

  case 76: /* update_select_attr: ID  */
#line 510 "yacc_sql.y"
         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2218 "yacc_sql.tab.c"
    break;

  case 77: /* update_select_attr: ID DOT ID  */
#line 515 "yacc_sql.y"
                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2228 "yacc_sql.tab.c"
    break;

  case 78: /* update_select_attr: ID DOT STAR  */
#line 520 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2238 "yacc_sql.tab.c"
    break;

  case 79: /* update_agg: COUNT_T LBRACE STAR RBRACE  */
#line 528 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
#line 2248 "yacc_sql.tab.c"
    break;

  case 80: /* update_agg: COUNT_T LBRACE ID RBRACE  */
#line 533 "yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2258 "yacc_sql.tab.c"
    break;

  case 81: /* update_agg: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 538 "yacc_sql.y"
                                          {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2268 "yacc_sql.tab.c"
    break;

  case 82: /* update_agg: MAX_T LBRACE ID RBRACE  */
#line 543 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2278 "yacc_sql.tab.c"
    break;

  case 83: /* update_agg: MAX_T LBRACE ID DOT ID RBRACE  */
#line 548 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2288 "yacc_sql.tab.c"
    break;

  case 84: /* update_agg: MIN_T LBRACE ID RBRACE  */
#line 553 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2298 "yacc_sql.tab.c"
    break;

  case 85: /* update_agg: MIN_T LBRACE ID DOT ID RBRACE  */
#line 558 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2308 "yacc_sql.tab.c"
    break;

  case 86: /* update_agg: SUM_T LBRACE ID RBRACE  */
#line 563 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2318 "yacc_sql.tab.c"
    break;

  case 87: /* update_agg: SUM_T LBRACE ID DOT ID RBRACE  */
#line 568 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2328 "yacc_sql.tab.c"
    break;

  case 88: /* update_agg: AVG_T LBRACE ID RBRACE  */
#line 573 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2338 "yacc_sql.tab.c"
    break;

  case 89: /* update_agg: AVG_T LBRACE ID DOT ID RBRACE  */
#line 578 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2348 "yacc_sql.tab.c"
    break;

  case 90: /* select: DT1  */
#line 587 "yacc_sql.y"
           {
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		
  		CONTEXT->condition_length = 0;
  		CONTEXT->from_length = 0;
  		CONTEXT->select_length = 0;
  		CONTEXT->value_length = 0;
  		CONTEXT->ssql->sstr.selection.is_da=3;
  		CONTEXT->ssql->sstr.selection.sub_query_num=0;
	}
#line 2364 "yacc_sql.tab.c"
    break;

  case 91: /* select: DT2  */
#line 598 "yacc_sql.y"
            {
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		
  		CONTEXT->condition_length = 0;
  		CONTEXT->from_length = 0;
  		CONTEXT->select_length = 0;
  		CONTEXT->value_length = 0;
  		CONTEXT->ssql->sstr.selection.is_da=4;
  		CONTEXT->ssql->sstr.selection.sub_query_num=0;
	}
#line 2380 "yacc_sql.tab.c"
    break;

  case 92: /* select: DT  */
#line 609 "yacc_sql.y"
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
#line 2396 "yacc_sql.tab.c"
    break;

  case 93: /* select: SELECT select_attr FROM ID rel_list where SEMICOLON  */
#line 621 "yacc_sql.y"
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
#line 2414 "yacc_sql.tab.c"
    break;

  case 94: /* select: SELECT select_attr FROM ID rel_list where GROUP BY by_attrs SEMICOLON  */
#line 635 "yacc_sql.y"
                                                                                {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-6].string));
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;

		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2429 "yacc_sql.tab.c"
    break;

  case 95: /* select: SELECT select_attr FROM ID INNER_T JOIN_T ID ON join_cons join_list where SEMICOLON  */
#line 646 "yacc_sql.y"
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
#line 2445 "yacc_sql.tab.c"
    break;

  case 96: /* select: SELECT select_attr FROM ID AS ID rel_list where SEMICOLON  */
#line 657 "yacc_sql.y"
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
#line 2460 "yacc_sql.tab.c"
    break;

  case 97: /* select: SELECT select_attr FROM ID ID rel_list where SEMICOLON  */
#line 667 "yacc_sql.y"
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
#line 2475 "yacc_sql.tab.c"
    break;

  case 98: /* by_attrs: ID  */
#line 679 "yacc_sql.y"
           {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->ssql->sstr.selection.gruop_use[0]=attr;
		CONTEXT->ssql->sstr.selection.group_num=1;
	}
#line 2486 "yacc_sql.tab.c"
    break;

  case 99: /* by_attrs: ID COMMA ID  */
#line 685 "yacc_sql.y"
                    {
		RelAttr attr1,attr2;
		relation_attr_init(&attr1, NULL, (yyvsp[-2].string));
		relation_attr_init(&attr2, NULL, (yyvsp[0].string));
		CONTEXT->ssql->sstr.selection.gruop_use[0]=attr1;
		CONTEXT->ssql->sstr.selection.gruop_use[1]=attr2;
		CONTEXT->ssql->sstr.selection.group_num=2;
	}
#line 2499 "yacc_sql.tab.c"
    break;

  case 100: /* by_attrs: ID DOT ID COMMA ID DOT ID  */
#line 693 "yacc_sql.y"
                                   {
		RelAttr attr1,attr2;
		relation_attr_init(&attr1,(yyvsp[-6].string),(yyvsp[-4].string));
		relation_attr_init(&attr2,(yyvsp[-2].string),(yyvsp[0].string));
		CONTEXT->ssql->sstr.selection.gruop_use[0]=attr1;
		CONTEXT->ssql->sstr.selection.gruop_use[1]=attr2;
		CONTEXT->ssql->sstr.selection.group_num=2;
	}
#line 2512 "yacc_sql.tab.c"
    break;

  case 101: /* sub_query: SELECT ID DOT ID FROM ID rel_list dummy where  */
#line 704 "yacc_sql.y"
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
#line 2536 "yacc_sql.tab.c"
    break;

  case 102: /* sub_query: SELECT ID FROM ID rel_list dummy where  */
#line 723 "yacc_sql.y"
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
#line 2560 "yacc_sql.tab.c"
    break;

  case 103: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID dummy where  */
#line 742 "yacc_sql.y"
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
#line 2584 "yacc_sql.tab.c"
    break;

  case 104: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 761 "yacc_sql.y"
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
#line 2608 "yacc_sql.tab.c"
    break;

  case 105: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 780 "yacc_sql.y"
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
#line 2631 "yacc_sql.tab.c"
    break;

  case 106: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 798 "yacc_sql.y"
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
#line 2654 "yacc_sql.tab.c"
    break;

  case 107: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 816 "yacc_sql.y"
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
#line 2677 "yacc_sql.tab.c"
    break;

  case 108: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 834 "yacc_sql.y"
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
#line 2703 "yacc_sql.tab.c"
    break;

  case 109: /* sub_query: SELECT ID DOT ID FROM ID AS ID rel_list dummy where  */
#line 855 "yacc_sql.y"
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
#line 2729 "yacc_sql.tab.c"
    break;

  case 110: /* sub_query: SELECT ID FROM ID AS ID rel_list dummy where  */
#line 876 "yacc_sql.y"
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
#line 2752 "yacc_sql.tab.c"
    break;

  case 111: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID AS ID dummy where  */
#line 894 "yacc_sql.y"
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
#line 2776 "yacc_sql.tab.c"
    break;

  case 112: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 913 "yacc_sql.y"
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
#line 2799 "yacc_sql.tab.c"
    break;

  case 113: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 931 "yacc_sql.y"
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
#line 2823 "yacc_sql.tab.c"
    break;

  case 114: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 950 "yacc_sql.y"
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
#line 2846 "yacc_sql.tab.c"
    break;

  case 115: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 968 "yacc_sql.y"
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
#line 2869 "yacc_sql.tab.c"
    break;

  case 116: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 986 "yacc_sql.y"
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
#line 2895 "yacc_sql.tab.c"
    break;

  case 117: /* sub_query: SELECT ID DOT ID FROM ID ID rel_list dummy where  */
#line 1007 "yacc_sql.y"
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
#line 2922 "yacc_sql.tab.c"
    break;

  case 118: /* sub_query: SELECT ID FROM ID ID rel_list dummy where  */
#line 1029 "yacc_sql.y"
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
#line 2946 "yacc_sql.tab.c"
    break;

  case 119: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID ID dummy where  */
#line 1048 "yacc_sql.y"
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
#line 2970 "yacc_sql.tab.c"
    break;

  case 120: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1067 "yacc_sql.y"
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
#line 2994 "yacc_sql.tab.c"
    break;

  case 121: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1086 "yacc_sql.y"
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
#line 3018 "yacc_sql.tab.c"
    break;

  case 122: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1105 "yacc_sql.y"
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
#line 3042 "yacc_sql.tab.c"
    break;

  case 123: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1124 "yacc_sql.y"
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
#line 3066 "yacc_sql.tab.c"
    break;

  case 124: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1143 "yacc_sql.y"
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
#line 3092 "yacc_sql.tab.c"
    break;

  case 125: /* sub_query: SELECT ID DOT ID AS ID FROM ID rel_list dummy where  */
#line 1165 "yacc_sql.y"
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
#line 3118 "yacc_sql.tab.c"
    break;

  case 126: /* sub_query: SELECT ID DOT ID ID FROM ID rel_list dummy where  */
#line 1186 "yacc_sql.y"
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
#line 3144 "yacc_sql.tab.c"
    break;

  case 127: /* sub_query: SELECT ID AS ID FROM ID rel_list dummy where  */
#line 1207 "yacc_sql.y"
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
#line 3168 "yacc_sql.tab.c"
    break;

  case 128: /* sub_query: SELECT ID ID FROM ID rel_list dummy where  */
#line 1226 "yacc_sql.y"
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
#line 3192 "yacc_sql.tab.c"
    break;

  case 129: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID dummy where  */
#line 1245 "yacc_sql.y"
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
#line 3216 "yacc_sql.tab.c"
    break;

  case 130: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID dummy where  */
#line 1264 "yacc_sql.y"
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
#line 3240 "yacc_sql.tab.c"
    break;

  case 131: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1283 "yacc_sql.y"
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
#line 3264 "yacc_sql.tab.c"
    break;

  case 132: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1302 "yacc_sql.y"
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
#line 3288 "yacc_sql.tab.c"
    break;

  case 133: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1321 "yacc_sql.y"
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
#line 3311 "yacc_sql.tab.c"
    break;

  case 134: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1339 "yacc_sql.y"
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
#line 3334 "yacc_sql.tab.c"
    break;

  case 135: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1357 "yacc_sql.y"
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
#line 3357 "yacc_sql.tab.c"
    break;

  case 136: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1375 "yacc_sql.y"
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
#line 3380 "yacc_sql.tab.c"
    break;

  case 137: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1393 "yacc_sql.y"
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
#line 3404 "yacc_sql.tab.c"
    break;

  case 138: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1412 "yacc_sql.y"
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
#line 3428 "yacc_sql.tab.c"
    break;

  case 139: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1431 "yacc_sql.y"
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
#line 3454 "yacc_sql.tab.c"
    break;

  case 140: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1452 "yacc_sql.y"
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
#line 3480 "yacc_sql.tab.c"
    break;

  case 141: /* sub_query: SELECT ID DOT ID AS ID FROM ID AS ID rel_list dummy where  */
#line 1473 "yacc_sql.y"
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
#line 3507 "yacc_sql.tab.c"
    break;

  case 142: /* sub_query: SELECT ID DOT ID ID FROM ID AS ID rel_list dummy where  */
#line 1495 "yacc_sql.y"
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
#line 3534 "yacc_sql.tab.c"
    break;

  case 143: /* sub_query: SELECT ID AS ID FROM ID AS ID rel_list dummy where  */
#line 1517 "yacc_sql.y"
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
#line 3557 "yacc_sql.tab.c"
    break;

  case 144: /* sub_query: SELECT ID ID FROM ID AS ID rel_list dummy where  */
#line 1535 "yacc_sql.y"
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
#line 3580 "yacc_sql.tab.c"
    break;

  case 145: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID AS ID dummy where  */
#line 1553 "yacc_sql.y"
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
#line 3604 "yacc_sql.tab.c"
    break;

  case 146: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID AS ID dummy where  */
#line 1572 "yacc_sql.y"
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
#line 3628 "yacc_sql.tab.c"
    break;

  case 147: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1591 "yacc_sql.y"
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
#line 3651 "yacc_sql.tab.c"
    break;

  case 148: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1609 "yacc_sql.y"
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
#line 3674 "yacc_sql.tab.c"
    break;

  case 149: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1627 "yacc_sql.y"
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
#line 3698 "yacc_sql.tab.c"
    break;

  case 150: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1646 "yacc_sql.y"
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
#line 3722 "yacc_sql.tab.c"
    break;

  case 151: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1665 "yacc_sql.y"
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
#line 3745 "yacc_sql.tab.c"
    break;

  case 152: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1683 "yacc_sql.y"
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
#line 3768 "yacc_sql.tab.c"
    break;

  case 153: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1701 "yacc_sql.y"
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
#line 3791 "yacc_sql.tab.c"
    break;

  case 154: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1719 "yacc_sql.y"
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
#line 3814 "yacc_sql.tab.c"
    break;

  case 155: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1737 "yacc_sql.y"
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
#line 3840 "yacc_sql.tab.c"
    break;

  case 156: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1758 "yacc_sql.y"
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
#line 3866 "yacc_sql.tab.c"
    break;

  case 157: /* sub_query: SELECT ID DOT ID AS ID FROM ID ID rel_list dummy where  */
#line 1779 "yacc_sql.y"
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
#line 3893 "yacc_sql.tab.c"
    break;

  case 158: /* sub_query: SELECT ID DOT ID ID FROM ID ID rel_list dummy where  */
#line 1801 "yacc_sql.y"
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
#line 3920 "yacc_sql.tab.c"
    break;

  case 159: /* sub_query: SELECT ID AS ID FROM ID ID rel_list dummy where  */
#line 1823 "yacc_sql.y"
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
#line 3944 "yacc_sql.tab.c"
    break;

  case 160: /* sub_query: SELECT ID ID FROM ID ID rel_list dummy where  */
#line 1842 "yacc_sql.y"
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
#line 3968 "yacc_sql.tab.c"
    break;

  case 161: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID ID dummy where  */
#line 1861 "yacc_sql.y"
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
#line 3992 "yacc_sql.tab.c"
    break;

  case 162: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID ID dummy where  */
#line 1880 "yacc_sql.y"
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
#line 4016 "yacc_sql.tab.c"
    break;

  case 163: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 1899 "yacc_sql.y"
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
#line 4040 "yacc_sql.tab.c"
    break;

  case 164: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 1918 "yacc_sql.y"
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
#line 4064 "yacc_sql.tab.c"
    break;

  case 165: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 1937 "yacc_sql.y"
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
#line 4088 "yacc_sql.tab.c"
    break;

  case 166: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 1956 "yacc_sql.y"
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
#line 4112 "yacc_sql.tab.c"
    break;

  case 167: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 1975 "yacc_sql.y"
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
#line 4136 "yacc_sql.tab.c"
    break;

  case 168: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 1994 "yacc_sql.y"
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
#line 4160 "yacc_sql.tab.c"
    break;

  case 169: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2013 "yacc_sql.y"
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
#line 4184 "yacc_sql.tab.c"
    break;

  case 170: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2032 "yacc_sql.y"
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
#line 4208 "yacc_sql.tab.c"
    break;

  case 171: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2051 "yacc_sql.y"
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
#line 4235 "yacc_sql.tab.c"
    break;

  case 172: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2073 "yacc_sql.y"
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
#line 4262 "yacc_sql.tab.c"
    break;

  case 174: /* join_list: INNER_T JOIN_T ID ON join_cons join_list  */
#line 2099 "yacc_sql.y"
                                               {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
	}
#line 4270 "yacc_sql.tab.c"
    break;

  case 175: /* join_cons: condition condition_list  */
#line 2104 "yacc_sql.y"
                                  {	
	}
#line 4277 "yacc_sql.tab.c"
    break;

  case 176: /* expr: expr ADD expr  */
#line 2109 "yacc_sql.y"
                      {
		(yyval.expr1) = create_astexpr(ADD_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4285 "yacc_sql.tab.c"
    break;

  case 177: /* expr: SUB expr  */
#line 2112 "yacc_sql.y"
                   {
		(yyval.expr1) = create_astexpr(SUB_OP, NULL, (yyvsp[0].expr1));
	}
#line 4293 "yacc_sql.tab.c"
    break;

  case 178: /* expr: expr SUB expr  */
#line 2115 "yacc_sql.y"
                        {
		(yyval.expr1) = create_astexpr(SUB_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4301 "yacc_sql.tab.c"
    break;

  case 179: /* expr: expr STAR expr  */
#line 2118 "yacc_sql.y"
                         {
		(yyval.expr1) = create_astexpr(MUL_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4309 "yacc_sql.tab.c"
    break;

  case 180: /* expr: expr DIV expr  */
#line 2121 "yacc_sql.y"
                        {
		(yyval.expr1) = create_astexpr(DIV_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4317 "yacc_sql.tab.c"
    break;

  case 181: /* expr: LBRACE expr RBRACE  */
#line 2124 "yacc_sql.y"
                             {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-1].expr1);
		astExpr->left_brackets ++;
		astExpr->right_brackets ++;
		(yyval.expr1) = (yyvsp[-1].expr1);
	}
#line 4328 "yacc_sql.tab.c"
    break;

  case 182: /* expr: value  */
#line 2130 "yacc_sql.y"
                {
		(yyval.expr1) = create_value_expr(&CONTEXT->values[CONTEXT->value_length - 1]);
	}
#line 4336 "yacc_sql.tab.c"
    break;

  case 183: /* expr: ID  */
#line 2133 "yacc_sql.y"
             {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4346 "yacc_sql.tab.c"
    break;

  case 184: /* expr: ID DOT ID  */
#line 2138 "yacc_sql.y"
                    {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4356 "yacc_sql.tab.c"
    break;

  case 185: /* expr: ID DOT STAR  */
#line 2143 "yacc_sql.y"
                      {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), "*");
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4366 "yacc_sql.tab.c"
    break;

  case 186: /* expr: ID AS ID  */
#line 2148 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[0].string));

		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4378 "yacc_sql.tab.c"
    break;

  case 187: /* expr: ID DOT ID AS ID  */
#line 2155 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4389 "yacc_sql.tab.c"
    break;

  case 188: /* expr: ID ID  */
#line 2161 "yacc_sql.y"
                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4400 "yacc_sql.tab.c"
    break;

  case 189: /* expr: ID DOT ID ID  */
#line 2167 "yacc_sql.y"
                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4411 "yacc_sql.tab.c"
    break;

  case 190: /* expr: COUNT_T LBRACE STAR RBRACE  */
#line 2173 "yacc_sql.y"
                                     {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4421 "yacc_sql.tab.c"
    break;

  case 191: /* expr: COUNT_T LBRACE ID RBRACE  */
#line 2178 "yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4431 "yacc_sql.tab.c"
    break;

  case 192: /* expr: MAX_T LBRACE ID RBRACE  */
#line 2183 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4441 "yacc_sql.tab.c"
    break;

  case 193: /* expr: MIN_T LBRACE ID RBRACE  */
#line 2188 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4451 "yacc_sql.tab.c"
    break;

  case 194: /* expr: SUM_T LBRACE ID RBRACE  */
#line 2193 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4461 "yacc_sql.tab.c"
    break;

  case 195: /* expr: AVG_T LBRACE ID RBRACE  */
#line 2198 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4471 "yacc_sql.tab.c"
    break;

  case 196: /* expr: COUNT_T LBRACE STAR RBRACE AS ID  */
#line 2204 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4484 "yacc_sql.tab.c"
    break;

  case 197: /* expr: COUNT_T LBRACE ID RBRACE AS ID  */
#line 2212 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4497 "yacc_sql.tab.c"
    break;

  case 198: /* expr: MAX_T LBRACE ID RBRACE AS ID  */
#line 2220 "yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4510 "yacc_sql.tab.c"
    break;

  case 199: /* expr: MIN_T LBRACE ID RBRACE AS ID  */
#line 2228 "yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4523 "yacc_sql.tab.c"
    break;

  case 200: /* expr: SUM_T LBRACE ID RBRACE AS ID  */
#line 2236 "yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4536 "yacc_sql.tab.c"
    break;

  case 201: /* expr: AVG_T LBRACE ID RBRACE AS ID  */
#line 2244 "yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4549 "yacc_sql.tab.c"
    break;

  case 202: /* expr: COUNT_T LBRACE STAR RBRACE ID  */
#line 2252 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4561 "yacc_sql.tab.c"
    break;

  case 203: /* expr: COUNT_T LBRACE ID RBRACE ID  */
#line 2259 "yacc_sql.y"
                                     {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-2].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4573 "yacc_sql.tab.c"
    break;

  case 204: /* expr: MAX_T LBRACE ID RBRACE ID  */
#line 2266 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-2].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4586 "yacc_sql.tab.c"
    break;

  case 205: /* expr: MIN_T LBRACE ID RBRACE ID  */
#line 2274 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4599 "yacc_sql.tab.c"
    break;

  case 206: /* expr: SUM_T LBRACE ID RBRACE ID  */
#line 2282 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	  }
#line 4612 "yacc_sql.tab.c"
    break;

  case 207: /* expr: AVG_T LBRACE ID RBRACE ID  */
#line 2290 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	  }
#line 4625 "yacc_sql.tab.c"
    break;

  case 208: /* expr: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 2298 "yacc_sql.y"
                                         {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4636 "yacc_sql.tab.c"
    break;

  case 209: /* expr: MAX_T LBRACE ID DOT ID RBRACE  */
#line 2304 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MAX_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4647 "yacc_sql.tab.c"
    break;

  case 210: /* expr: MIN_T LBRACE ID DOT ID RBRACE  */
#line 2310 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MIN_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4658 "yacc_sql.tab.c"
    break;

  case 211: /* expr: SUM_T LBRACE ID DOT ID RBRACE  */
#line 2316 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,SUM_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4669 "yacc_sql.tab.c"
    break;

  case 212: /* expr: AVG_T LBRACE ID DOT ID RBRACE  */
#line 2322 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,AVG_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4680 "yacc_sql.tab.c"
    break;

  case 213: /* expr: COUNT_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2328 "yacc_sql.y"
                                               {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4692 "yacc_sql.tab.c"
    break;

  case 214: /* expr: MAX_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2335 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MAX_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4705 "yacc_sql.tab.c"
    break;

  case 215: /* expr: MIN_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2343 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MIN_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4718 "yacc_sql.tab.c"
    break;

  case 216: /* expr: SUM_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2351 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,SUM_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4731 "yacc_sql.tab.c"
    break;

  case 217: /* expr: AVG_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2359 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,AVG_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4744 "yacc_sql.tab.c"
    break;

  case 218: /* expr: COUNT_T LBRACE ID DOT ID RBRACE ID  */
#line 2367 "yacc_sql.y"
                                            {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4756 "yacc_sql.tab.c"
    break;

  case 219: /* expr: MAX_T LBRACE ID DOT ID RBRACE ID  */
#line 2374 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4769 "yacc_sql.tab.c"
    break;

  case 220: /* expr: MIN_T LBRACE ID DOT ID RBRACE ID  */
#line 2382 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4782 "yacc_sql.tab.c"
    break;

  case 221: /* expr: SUM_T LBRACE ID DOT ID RBRACE ID  */
#line 2390 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4795 "yacc_sql.tab.c"
    break;

  case 222: /* expr: AVG_T LBRACE ID DOT ID RBRACE ID  */
#line 2398 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4808 "yacc_sql.tab.c"
    break;

  case 224: /* expr_list: COMMA expr expr_list  */
#line 2409 "yacc_sql.y"
                               {
		selects_append_expr(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1));
	}
#line 4816 "yacc_sql.tab.c"
    break;

  case 225: /* select_attr: STAR attr_list  */
#line 2414 "yacc_sql.y"
                   {  
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		CONTEXT->ssql->sstr.selection.need_Revere=1;
	}
#line 4827 "yacc_sql.tab.c"
    break;

  case 226: /* select_attr: expr expr_list  */
#line 2420 "yacc_sql.y"
                         {
		selects_append_expr(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1));
	}
#line 4835 "yacc_sql.tab.c"
    break;

  case 228: /* attr_list: COMMA ID attr_list  */
#line 2427 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 4846 "yacc_sql.tab.c"
    break;

  case 229: /* attr_list: COMMA ID DOT ID attr_list  */
#line 2433 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 4857 "yacc_sql.tab.c"
    break;

  case 230: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 2439 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 4868 "yacc_sql.tab.c"
    break;

  case 231: /* attr_list: COMMA ID AS ID attr_list  */
#line 2447 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-3].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 4880 "yacc_sql.tab.c"
    break;

  case 232: /* attr_list: COMMA ID DOT ID AS ID attr_list  */
#line 2454 "yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string),(yyvsp[-1].string));
		}
#line 4891 "yacc_sql.tab.c"
    break;

  case 233: /* attr_list: COMMA ID ID attr_list  */
#line 2460 "yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
	}
#line 4903 "yacc_sql.tab.c"
    break;

  case 234: /* attr_list: COMMA ID DOT ID ID attr_list  */
#line 2467 "yacc_sql.y"
                                        {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string),(yyvsp[-1].string));
		}
#line 4914 "yacc_sql.tab.c"
    break;

  case 236: /* rel_list: COMMA ID rel_list  */
#line 2478 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 4922 "yacc_sql.tab.c"
    break;

  case 237: /* rel_list: COMMA ID AS ID rel_list  */
#line 2481 "yacc_sql.y"
                                 {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 4931 "yacc_sql.tab.c"
    break;

  case 238: /* rel_list: COMMA ID ID rel_list  */
#line 2485 "yacc_sql.y"
                              {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
	}
#line 4940 "yacc_sql.tab.c"
    break;

  case 240: /* where: WHERE condition condition_list  */
#line 2492 "yacc_sql.y"
                                     {
	}
#line 4947 "yacc_sql.tab.c"
    break;

  case 242: /* condition_list: AND condition condition_list  */
#line 2497 "yacc_sql.y"
                                   {
			}
#line 4954 "yacc_sql.tab.c"
    break;

  case 243: /* condition: expr comOp expr  */
#line 2502 "yacc_sql.y"
        {
		Condition condition;
		condition_init_from_expr(&condition, CONTEXT->comp, (yyvsp[-2].expr1), (yyvsp[0].expr1));
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 4964 "yacc_sql.tab.c"
    break;

  case 244: /* condition: EXIST_T LBRACE sub_query RBRACE  */
#line 2508 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 4974 "yacc_sql.tab.c"
    break;

  case 245: /* condition: NOT EXIST_T LBRACE sub_query RBRACE  */
#line 2514 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, NOT_EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 4984 "yacc_sql.tab.c"
    break;

  case 246: /* condition: LBRACE sub_query RBRACE reverseComp ID  */
#line 2519 "yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->comp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 4996 "yacc_sql.tab.c"
    break;

  case 247: /* condition: expr IN_T LBRACE in_cells RBRACE  */
#line 2526 "yacc_sql.y"
                                          {
		/*TODO: 当前认为expr一定是单个attr */
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_cells_for_in(&condition,&astExpr->attr,CONTEXT->values,CONTEXT->value_length,IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5009 "yacc_sql.tab.c"
    break;

  case 248: /* condition: expr NOT IN_T LBRACE in_cells RBRACE  */
#line 2534 "yacc_sql.y"
                                              {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-5].expr1);
		Condition condition;
		condition_init_cells_for_in(&condition,&astExpr->attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5021 "yacc_sql.tab.c"
    break;

  case 249: /* condition: expr IN_T LBRACE sub_query RBRACE  */
#line 2541 "yacc_sql.y"
                                          {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_with_query(&condition, IN, &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5032 "yacc_sql.tab.c"
    break;

  case 250: /* condition: expr NOT IN_T LBRACE sub_query RBRACE  */
#line 2547 "yacc_sql.y"
                                              {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-5].expr1);
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5043 "yacc_sql.tab.c"
    break;

  case 251: /* condition: expr comOp LBRACE sub_query RBRACE  */
#line 2554 "yacc_sql.y"
        {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_with_query(&condition, (yyvsp[-3].compOp1), &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 5054 "yacc_sql.tab.c"
    break;

  case 252: /* condition: LBRACE sub_query RBRACE NE LBRACE sub_query RBRACE  */
#line 2560 "yacc_sql.y"
                                                            {
		Condition condition;
		condition_init_with_two_query(&condition, NOT_EQUAL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1],CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-2]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5064 "yacc_sql.tab.c"
    break;

  case 253: /* in_cells: value value_list  */
#line 2567 "yacc_sql.y"
                          {
	}
#line 5071 "yacc_sql.tab.c"
    break;

  case 254: /* reverseComp: EQ  */
#line 2571 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 5077 "yacc_sql.tab.c"
    break;

  case 255: /* reverseComp: LT  */
#line 2572 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 5083 "yacc_sql.tab.c"
    break;

  case 256: /* reverseComp: GT  */
#line 2573 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 5089 "yacc_sql.tab.c"
    break;

  case 257: /* reverseComp: LE  */
#line 2574 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 5095 "yacc_sql.tab.c"
    break;

  case 258: /* reverseComp: GE  */
#line 2575 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 5101 "yacc_sql.tab.c"
    break;

  case 259: /* reverseComp: NE  */
#line 2576 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 5107 "yacc_sql.tab.c"
    break;

  case 260: /* comOp: EQ  */
#line 2579 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; (yyval.compOp1) = EQUAL_TO; }
#line 5113 "yacc_sql.tab.c"
    break;

  case 261: /* comOp: LT  */
#line 2580 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; (yyval.compOp1) = LESS_THAN; }
#line 5119 "yacc_sql.tab.c"
    break;

  case 262: /* comOp: GT  */
#line 2581 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; (yyval.compOp1) = GREAT_THAN; }
#line 5125 "yacc_sql.tab.c"
    break;

  case 263: /* comOp: LE  */
#line 2582 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; (yyval.compOp1) = LESS_EQUAL; }
#line 5131 "yacc_sql.tab.c"
    break;

  case 264: /* comOp: GE  */
#line 2583 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; (yyval.compOp1) = GREAT_EQUAL; }
#line 5137 "yacc_sql.tab.c"
    break;

  case 265: /* comOp: NE  */
#line 2584 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; (yyval.compOp1) = NOT_EQUAL; }
#line 5143 "yacc_sql.tab.c"
    break;

  case 266: /* comOp: LIKE  */
#line 2585 "yacc_sql.y"
               { CONTEXT->comp = LIKE_TO; (yyval.compOp1) = LIKE_TO; }
#line 5149 "yacc_sql.tab.c"
    break;

  case 267: /* comOp: NOT LIKE  */
#line 2586 "yacc_sql.y"
                   { CONTEXT->comp = NOT_LIKE; (yyval.compOp1) = NOT_LIKE; }
#line 5155 "yacc_sql.tab.c"
    break;

  case 268: /* comOp: IS NOT  */
#line 2587 "yacc_sql.y"
                 { CONTEXT->comp = COMP_IS_NOT; (yyval.compOp1) = COMP_IS_NOT; }
#line 5161 "yacc_sql.tab.c"
    break;

  case 269: /* comOp: IS  */
#line 2588 "yacc_sql.y"
             { CONTEXT->comp = COMP_IS; (yyval.compOp1) = COMP_IS; }
#line 5167 "yacc_sql.tab.c"
    break;

  case 270: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 2593 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 5176 "yacc_sql.tab.c"
    break;


#line 5180 "yacc_sql.tab.c"

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

#line 2598 "yacc_sql.y"

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
