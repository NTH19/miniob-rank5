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
#define YYLAST   902

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  270
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  789

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
       0,   175,   175,   177,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   202,   207,   212,   218,   224,   230,   236,   242,
     248,   256,   263,   268,   275,   277,   281,   288,   295,   304,
     306,   310,   321,   332,   343,   354,   365,   378,   381,   382,
     383,   384,   385,   388,   395,   401,   411,   412,   417,   418,
     423,   424,   430,   435,   438,   441,   445,   449,   455,   465,
     473,   475,   479,   485,   493,   504,   509,   514,   519,   527,
     532,   537,   542,   547,   552,   557,   562,   567,   572,   577,
     584,   585,   594,   608,   619,   630,   640,   652,   658,   666,
     677,   696,   715,   734,   753,   771,   789,   807,   828,   849,
     867,   886,   904,   923,   941,   959,   980,  1002,  1021,  1040,
    1059,  1078,  1097,  1116,  1138,  1159,  1180,  1199,  1218,  1237,
    1256,  1275,  1294,  1312,  1330,  1348,  1366,  1385,  1404,  1425,
    1446,  1468,  1490,  1508,  1526,  1545,  1564,  1582,  1600,  1619,
    1638,  1656,  1674,  1692,  1710,  1731,  1752,  1774,  1796,  1815,
    1834,  1853,  1872,  1891,  1910,  1929,  1948,  1967,  1986,  2005,
    2024,  2046,  2070,  2072,  2077,  2082,  2085,  2088,  2091,  2094,
    2097,  2103,  2106,  2111,  2116,  2121,  2128,  2134,  2140,  2146,
    2151,  2156,  2161,  2166,  2171,  2177,  2185,  2193,  2201,  2209,
    2217,  2225,  2232,  2239,  2247,  2255,  2263,  2271,  2277,  2283,
    2289,  2295,  2301,  2308,  2316,  2324,  2332,  2340,  2347,  2355,
    2363,  2371,  2381,  2382,  2387,  2393,  2398,  2400,  2406,  2412,
    2420,  2427,  2433,  2440,  2449,  2451,  2454,  2458,  2463,  2465,
    2468,  2470,  2473,  2478,  2484,  2490,  2496,  2503,  2511,  2518,
    2524,  2530,  2537,  2544,  2548,  2549,  2550,  2551,  2552,  2553,
    2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,  2564,  2565,
    2569
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
  "having", "select", "by_attrs", "sub_query", "join_list", "join_cons",
  "expr", "expr_list", "select_attr", "attr_list", "rel_list", "where",
  "condition_list", "condition", "in_cells", "reverseComp", "comOp",
  "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-312)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -312,   413,  -312,    44,   147,   102,   -53,   103,    45,    22,
      66,    60,   145,   197,   221,   230,   256,   186,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,   204,   210,   278,
     234,   252,   182,   313,   335,   362,   368,   384,  -312,   182,
    -312,  -312,  -312,     5,  -312,   389,  -312,    32,   373,   409,
     412,   378,  -312,   345,   346,   388,  -312,  -312,  -312,  -312,
    -312,   371,   415,   390,   363,   435,   441,   -13,   -41,   374,
     376,   380,   382,   -36,   -39,   383,  -312,   385,  -312,   182,
     182,   182,   182,   182,  -312,   392,  -312,  -312,   393,   416,
     419,   394,   386,   395,   397,   407,  -312,  -312,  -312,    -7,
     445,     9,    19,   104,   349,   158,  -312,  -312,   121,    32,
     -36,   -36,  -312,  -312,   144,   461,   455,   120,   471,   424,
     457,   442,  -312,   464,   344,   463,   410,   172,   414,   187,
     190,   417,   201,   418,   223,   420,   236,   422,   423,  -312,
     171,   425,   389,  -312,  -312,   426,   427,   439,   468,   419,
    -312,   182,   483,     1,   487,   449,   805,   116,  -312,   198,
     394,   419,   501,   395,   490,  -312,  -312,  -312,  -312,  -312,
      -1,   437,   492,   440,  -312,   495,   444,  -312,   446,  -312,
     497,   447,  -312,   498,   448,  -312,   505,   451,  -312,   508,
    -312,   127,   389,   389,  -312,   143,   468,   454,   419,     3,
     511,   170,   455,   528,   277,   515,   525,   518,  -312,  -312,
    -312,  -312,  -312,  -312,   520,  -312,   348,   479,   271,   120,
     120,  -312,    59,  -312,   457,   538,   470,   464,   539,   474,
     484,  -312,  -312,   529,   437,  -312,   237,  -312,  -312,   245,
    -312,   247,  -312,   249,  -312,   250,   476,   389,  -312,  -312,
    -312,   478,   468,  -312,   419,   509,   553,  -312,   493,   182,
     543,   483,  -312,   545,   547,   549,   551,   552,   176,   572,
     554,   525,    23,   557,  -312,  -312,     1,   170,   116,   116,
      91,  -312,  -312,   567,  -312,  -312,  -312,   558,  -312,   437,
     559,   529,   504,  -312,   507,  -312,   510,  -312,   512,  -312,
     516,  -312,   389,  -312,   468,  -312,   580,   120,  -312,   523,
     511,  -312,  -312,   232,   526,   530,   532,   534,   535,   537,
     541,   556,  -312,  -312,  -312,  -312,  -312,   568,   544,  -312,
     574,   511,   584,   585,    23,   594,  -312,  -312,   603,   604,
     612,   613,   615,   598,  -312,   596,   597,  -312,   253,   529,
     634,   620,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
     593,   116,   162,   576,  -312,   608,   626,   610,   611,   614,
     616,   -21,   168,   609,   579,   525,  -312,  -312,  -312,  -312,
    -312,   630,   632,  -312,   240,   582,   583,   587,   589,   326,
     590,   592,   605,  -312,  -312,  -312,   651,   622,   419,  -312,
     599,   601,   182,   656,   602,    -9,   606,   617,   619,   623,
     624,   628,   639,   629,   468,  -312,   633,   169,   652,  -312,
    -312,   359,   654,   360,   364,   369,   379,  -312,  -312,   419,
     419,  -312,  -312,   635,   675,  -312,   663,   825,  -312,   665,
     637,   638,   647,   668,   669,   670,   671,   191,   658,   640,
     468,  -312,   419,   194,   642,   468,  -312,  -312,  -312,   643,
    -312,  -312,   645,  -312,   648,  -312,   650,  -312,   657,   672,
     676,   655,  -312,   659,   662,   182,    80,   264,   666,   660,
      98,   111,   112,   188,   667,   468,  -312,   673,   217,  -312,
     419,  -312,   678,   468,  -312,   468,  -312,   419,   688,   707,
     708,   710,   712,  -312,  -312,   120,   697,   170,   680,   682,
     698,   683,  -312,   419,   685,   265,   687,   689,   699,   690,
     692,   701,   694,   696,   704,   702,   705,   706,   468,  -312,
     419,   233,   709,   468,  -312,   419,  -312,   468,  -312,   419,
    -312,   419,  -312,  -312,  -312,  -312,  -312,  -312,   593,   711,
     282,   733,   713,  -312,   419,  -312,   285,   715,  -312,   419,
     287,   735,   716,   288,   737,   717,   289,   740,   718,   291,
     742,   719,  -312,   419,  -312,   720,   468,  -312,   468,  -312,
     419,  -312,  -312,   419,  -312,   419,  -312,  -312,  -312,   721,
    -312,   419,   722,   292,   419,  -312,   724,  -312,   419,  -312,
     419,  -312,   726,  -312,   419,   727,   294,   728,  -312,   419,
     729,   295,   730,  -312,   419,   732,   296,   734,  -312,   419,
     736,   297,   419,  -312,   468,  -312,   419,  -312,   419,  -312,
     419,  -312,  -312,  -312,   419,  -312,   306,   738,  -312,   419,
    -312,  -312,   419,  -312,   419,  -312,  -312,   419,  -312,   309,
     743,  -312,   419,  -312,   419,  -312,   314,   744,  -312,   419,
    -312,   419,  -312,   315,   745,  -312,   419,  -312,   419,  -312,
     317,   746,  -312,   419,  -312,  -312,   419,  -312,   419,  -312,
    -312,   419,  -312,   748,  -312,   419,  -312,   419,  -312,   419,
    -312,  -312,   419,  -312,   750,  -312,   419,  -312,   419,  -312,
     419,  -312,   751,  -312,   419,  -312,   419,  -312,   419,  -312,
     752,  -312,   419,  -312,   419,  -312,   419,  -312,   753,  -312,
     419,  -312,   419,  -312,   419,  -312,  -312,  -312,  -312,   419,
    -312,   419,  -312,  -312,  -312,  -312,   419,  -312,   419,  -312,
    -312,  -312,   419,  -312,   419,  -312,  -312,  -312,   419,  -312,
     419,  -312,  -312,  -312,   419,  -312,   419,  -312,  -312,   419,
    -312,  -312,   419,  -312,  -312,   419,  -312,  -312,   419,  -312,
    -312,   419,  -312,  -312,  -312,  -312,  -312,  -312,  -312
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
      63,    64,    65,   182,    66,   226,   181,   222,     0,     0,
       0,     0,    24,     0,     0,     0,    25,    26,    27,    23,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   176,     0,     0,   187,     0,   224,     0,
       0,     0,     0,     0,   225,     0,    31,    29,     0,     0,
     238,     0,     0,     0,     0,     0,    28,    37,   180,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   226,   222,
     175,   177,   179,   178,   234,     0,    58,     0,     0,     0,
      70,     0,    53,    39,     0,     0,     0,   190,     0,   189,
     191,     0,   192,     0,   194,     0,   193,     0,     0,   188,
       0,     0,   226,   227,   223,     0,     0,     0,   234,   238,
      30,     0,    56,     0,     0,     0,     0,   240,    68,     0,
       0,   238,     0,     0,     0,    48,    51,    52,    49,    50,
      44,     0,     0,     0,   202,     0,     0,   201,     0,   203,
       0,     0,   204,     0,     0,   206,     0,     0,   205,     0,
     186,   226,   226,   226,   232,   234,   234,     0,   238,     0,
      60,    62,    58,     0,     0,     0,     0,     0,   260,   261,
     262,   263,   264,   265,     0,   266,     0,   269,     0,     0,
       0,   239,     0,    72,    70,     0,     0,    39,     0,     0,
       0,    46,    36,    34,     0,   196,   207,   195,   197,   208,
     198,   209,   200,   211,   199,   210,     0,   226,   228,   229,
     230,     0,   234,   235,   238,     0,     0,    92,     0,     0,
       0,    56,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,   268,     0,   243,   240,   240,
       0,    71,    69,     0,    40,    38,    47,     0,    45,     0,
       0,    34,     0,   217,     0,   218,     0,   219,     0,   221,
       0,   220,   226,   233,   234,   237,     0,     0,    96,     0,
      60,    59,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   256,   257,   258,   259,     0,   244,
       0,    60,     0,     0,     0,     0,   241,   242,     0,     0,
       0,     0,     0,    76,    75,     0,     0,   270,    41,    34,
       0,     0,   212,   213,   214,   216,   215,   231,   236,    95,
     172,   240,    97,    90,    61,     0,     0,     0,     0,     0,
       0,     0,   234,     0,     0,     0,   246,   245,   253,   249,
     247,     0,     0,   251,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,    35,    32,     0,     0,   238,   174,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,    54,     0,   234,     0,   250,
     248,     0,     0,     0,     0,     0,     0,    77,    78,   238,
     238,    42,    33,     0,     0,    98,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,   234,     0,     0,
     234,    54,   238,   234,     0,   234,    54,   252,    80,     0,
      79,    82,     0,    84,     0,    88,     0,    86,     0,     0,
       0,     0,    94,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,   234,    54,     0,   234,    54,
     238,   101,     0,   234,    54,   234,    54,   238,     0,     0,
       0,     0,     0,    73,    74,     0,     0,    91,     0,     0,
       0,     0,    54,   238,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,    54,
     238,   234,     0,   234,    54,   238,   117,   234,    54,   238,
      54,   238,   127,    81,    83,    85,    89,    87,   172,     0,
      54,     0,     0,    54,   238,   102,    54,     0,    54,   238,
      54,     0,     0,    54,     0,     0,    54,     0,     0,    54,
       0,     0,    54,   238,   100,     0,   234,    54,   234,    54,
     238,   109,    54,   238,   126,   238,   159,   173,    99,     0,
      54,   238,     0,    54,   238,   118,     0,    54,   238,    54,
     238,   129,     0,    54,   238,     0,    54,     0,    54,   238,
       0,    54,     0,    54,   238,     0,    54,     0,    54,   238,
       0,    54,   238,   116,   234,    54,   238,    54,   238,   125,
     238,   158,   143,    54,   238,   103,    54,     0,    54,   238,
     110,    54,   238,   128,   238,   161,    54,   238,   104,    54,
       0,    54,   238,    54,   238,   105,    54,     0,    54,   238,
      54,   238,   107,    54,     0,    54,   238,    54,   238,   106,
      54,     0,    54,   238,   108,    54,   238,   124,   238,   157,
     142,   238,   119,     0,    54,   238,    54,   238,   131,   238,
     160,   145,   238,   120,     0,    54,   238,    54,   238,   133,
     238,   121,     0,    54,   238,    54,   238,   135,   238,   123,
       0,    54,   238,    54,   238,   139,   238,   122,     0,    54,
     238,    54,   238,   137,   238,   156,   141,   111,    54,   238,
     130,   238,   163,   144,   112,    54,   238,   132,   238,   165,
     113,    54,   238,   134,   238,   167,   115,    54,   238,   138,
     238,   171,   114,    54,   238,   136,   238,   169,   140,   238,
     162,   147,   238,   164,   149,   238,   166,   151,   238,   170,
     155,   238,   168,   153,   146,   148,   150,   154,   152
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -281,  -201,  -312,  -312,   513,   573,
    -312,  -312,  -312,    92,  -312,   540,   533,  -311,  -166,  -275,
    -312,  -312,   548,   644,  -312,  -312,  -312,  -312,  -312,  -215,
     226,   266,    -3,   714,  -312,  -110,  -145,  -159,  -274,  -123,
     405,  -312,   381,  -312
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   300,   243,    30,    31,   174,   133,
     297,   180,   134,   462,    32,   213,   162,   270,   210,    56,
      33,    34,   171,   130,   355,   356,   413,    35,   373,   215,
     408,   370,   166,    94,    58,    88,   159,   128,   231,   371,
     343,   338,   228,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     209,   280,    57,   233,   167,   108,   267,   341,   153,   374,
     214,   137,   235,   208,   346,   347,   239,   420,    42,   421,
     361,    59,    43,    44,    45,    46,    47,   140,   138,   450,
     388,   451,   214,   109,    92,   115,   110,   142,   116,    77,
      84,    93,   204,   301,   141,    85,    83,   268,    62,   266,
      37,    89,    38,   422,   143,    90,    91,    92,    63,   240,
     263,   264,   241,    48,    93,   452,   340,   342,   290,   341,
      49,   345,    50,    51,    52,    53,    42,    54,   404,    86,
      43,    44,    45,    46,    47,    48,   119,   120,   121,   122,
     123,   258,   259,   260,    50,    51,    52,   409,   359,    54,
      90,    91,    92,   320,    64,   316,   288,   289,    39,    93,
      60,    61,   348,   349,   350,   351,   352,   315,   518,    42,
     519,    48,   144,    43,    44,    45,    46,    47,    49,   391,
      50,    51,    52,    53,    65,    54,   526,   163,   527,   145,
      87,    43,    44,    45,    46,    47,    87,   313,    66,   529,
     532,   530,   533,    40,   520,    41,   150,   229,   211,   230,
      77,   151,   155,   155,    48,   353,   211,   256,   354,   368,
     428,    49,   528,    50,    51,    52,    53,   164,    54,    55,
     165,   410,    48,   261,   156,   531,   534,   155,   155,    49,
     157,    50,    51,    52,    53,   152,    54,   411,   148,    42,
      67,   257,   367,    43,    44,    45,    46,    47,   423,   464,
     155,   328,   183,   155,   329,   232,   330,   262,   158,    43,
      44,    45,    46,    47,    68,   287,   535,   186,   536,    77,
     188,   494,   149,    69,   502,    71,   155,   425,    90,    91,
      92,   191,   424,   465,    48,   201,   184,    93,   202,   444,
     331,    49,   155,    50,    51,    52,    53,   542,    54,    70,
      48,   187,   537,   194,   189,   495,   211,    49,   503,    50,
      51,    52,    53,   585,    54,   192,   197,   302,    72,   461,
     479,   480,   466,    77,    73,   304,    74,   306,   286,   308,
     310,   543,    43,    44,    45,    46,    47,   195,   273,   274,
     275,   276,   277,   501,   521,   567,   375,   586,    75,   376,
     198,   303,   496,   402,   431,   499,   403,   432,   504,   305,
     506,   307,   599,   309,   311,   606,    76,   612,   617,   622,
      78,   627,   647,    48,   660,   667,   674,   681,   522,   568,
      49,   546,    50,    51,    52,    53,   693,    54,   552,   704,
     539,   278,    79,   544,   712,   720,   600,   728,   548,   607,
     550,   613,   618,   623,   565,   628,   648,   146,   661,   668,
     675,   682,   175,   176,   177,   178,   179,   468,   471,    80,
     694,   584,   473,   705,   147,    81,   591,   475,   713,   721,
     594,   729,   596,   582,   469,   472,   587,   477,   589,   474,
     437,    82,   592,   438,   476,   605,   283,   284,    87,   447,
     611,    95,    96,     2,   478,    97,    98,     3,     4,    99,
     100,   102,     5,     6,   633,     7,     8,     9,    10,    11,
     101,   639,   103,    12,   641,   104,   642,   105,   106,    13,
      14,   635,   645,   637,   107,   650,    15,    16,   111,   653,
     112,   655,   136,   126,   113,   658,   114,   117,   127,   118,
     665,    17,   131,   139,   160,   672,   124,   125,   129,   132,
     679,   135,   161,   684,   168,   169,   170,   687,   172,   689,
     181,   690,   517,   173,   182,   692,   207,   155,   185,   685,
     698,   190,   193,   700,   196,   701,   199,   200,   703,   203,
     205,   206,   212,   709,   216,   711,   217,   236,   238,   244,
     717,   242,   719,   246,   245,   249,   251,   725,   247,   727,
     248,   250,   252,   253,   733,   254,   255,   735,   265,   736,
     269,   272,   737,   279,   214,   281,   740,   282,   742,   285,
     743,   292,   295,   744,   293,   296,   298,   747,   299,   749,
     312,   750,   314,   500,   317,   753,   318,   755,   507,   756,
     319,   321,   323,   759,   324,   761,   325,   762,   326,   327,
     357,   765,   339,   767,   344,   768,   358,   360,   362,   523,
     770,   363,   771,   369,   364,   385,   365,   773,   540,   774,
     366,   545,   387,   776,   384,   777,   549,   372,   551,   779,
     377,   780,   389,   390,   378,   782,   379,   783,   380,   381,
     784,   382,   393,   785,   564,   383,   786,   569,   386,   787,
     394,   395,   788,   332,   333,   334,   335,   336,   337,   396,
     397,   583,   398,   399,   400,   401,   590,   405,   406,   407,
     593,   412,   595,   414,   415,   416,   417,   426,   429,   418,
     430,   419,   601,   427,   442,   604,   433,   434,   608,   448,
     610,   435,   614,   436,   439,   619,   440,   441,   624,   443,
     467,   629,   470,   445,   632,   446,   449,   459,   482,   636,
     453,   638,   483,   486,   640,   489,   490,   491,   492,   493,
     513,   454,   644,   455,   514,   649,   497,   456,   457,   652,
     515,   654,   458,   460,   524,   657,   553,   463,   662,   481,
     664,   487,   488,   669,   498,   671,   505,   508,   676,   509,
     678,   284,   510,   683,   511,   554,   555,   686,   556,   688,
     557,   512,   559,   516,   525,   691,   562,   572,   695,   575,
     697,   538,   578,   699,   581,   271,   237,   541,   702,   392,
     294,   706,   547,   708,   560,   710,   561,   563,   714,   566,
     716,   570,   718,   571,   573,   722,   574,   724,   576,   726,
     577,   602,   730,   615,   732,   620,   579,   734,   625,   580,
     630,   558,   291,   588,   597,   598,   739,   603,   741,   609,
     616,   621,   626,   631,   634,   643,   646,   746,   651,   748,
     656,   659,   663,   666,   670,   752,   673,   754,   677,     0,
     680,   322,   696,   758,   234,   760,     0,   707,   715,   723,
     731,   764,   738,   766,   745,   751,   757,   763,   485,     0,
     769,     0,     0,   154,     0,     0,     0,   772,     0,     0,
       0,     0,     0,   775,     0,     0,     0,     0,     0,   778,
       0,     0,     0,     0,     0,   781,   218,   219,   220,   221,
     222,   223,     0,   224,   225,   226,   227,     0,     0,     0,
       0,     0,     0,    90,    91,    92,   218,   219,   220,   221,
     222,   223,    93,     0,   225,   484,   227,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     0,     0,     0,     0,
       0,     0,    93
};

static const yytype_int16 yycheck[] =
{
     159,   216,     5,   169,   127,    18,     3,   282,   118,   320,
       9,    18,   171,   158,   288,   289,    17,    38,    17,    40,
     301,    74,    21,    22,    23,    24,    25,    18,    35,    38,
     341,    40,     9,    74,    70,    74,    77,    18,    77,    42,
      35,    77,   152,   244,    35,    40,    49,    44,     3,   208,
       6,    19,     8,    74,    35,    68,    69,    70,    36,    60,
     205,   206,    63,    62,    77,    74,   281,   282,     9,   344,
      69,   286,    71,    72,    73,    74,    17,    76,   359,    74,
      21,    22,    23,    24,    25,    62,    89,    90,    91,    92,
      93,   201,   202,   203,    71,    72,    73,   371,   299,    76,
      68,    69,    70,   269,    38,   264,   229,   230,    64,    77,
       7,     8,    21,    22,    23,    24,    25,   262,    38,    17,
      40,    62,    18,    21,    22,    23,    24,    25,    69,   344,
      71,    72,    73,    74,    74,    76,    38,    17,    40,    35,
      19,    21,    22,    23,    24,    25,    19,   257,     3,    38,
      38,    40,    40,     6,    74,     8,    35,    41,   161,    43,
     163,    40,    19,    19,    62,    74,   169,    40,    77,   314,
     385,    69,    74,    71,    72,    73,    74,    57,    76,    77,
      60,    19,    62,    40,    40,    74,    74,    19,    19,    69,
      46,    71,    72,    73,    74,    74,    76,    35,    40,    17,
       3,    74,   312,    21,    22,    23,    24,    25,    40,    40,
      19,    35,    40,    19,    38,    17,    40,    74,    74,    21,
      22,    23,    24,    25,     3,   228,    38,    40,    40,   232,
      40,    40,    74,     3,    40,    49,    19,   382,    68,    69,
      70,    40,    74,    74,    62,    74,    74,    77,    77,   408,
      74,    69,    19,    71,    72,    73,    74,    40,    76,     3,
      62,    74,    74,    40,    74,    74,   269,    69,    74,    71,
      72,    73,    74,    40,    76,    74,    40,    40,    74,   424,
     439,   440,   427,   286,    74,    40,     8,    40,    17,    40,
      40,    74,    21,    22,    23,    24,    25,    74,    21,    22,
      23,    24,    25,   462,    40,    40,    74,    74,    74,    77,
      74,    74,   457,    60,    74,   460,    63,    77,   463,    74,
     465,    74,    40,    74,    74,    40,    74,    40,    40,    40,
      17,    40,    40,    62,    40,    40,    40,    40,    74,    74,
      69,   500,    71,    72,    73,    74,    40,    76,   507,    40,
     495,    74,    17,   498,    40,    40,    74,    40,   503,    74,
     505,    74,    74,    74,   523,    74,    74,    18,    74,    74,
      74,    74,    28,    29,    30,    31,    32,    18,    18,    17,
      74,   540,    18,    74,    35,    17,   545,    18,    74,    74,
     549,    74,   551,   538,    35,    35,   541,    18,   543,    35,
      74,    17,   547,    77,    35,   564,    58,    59,    19,   412,
     569,    38,     3,     0,    35,     3,    38,     4,     5,    74,
      74,    50,     9,    10,   583,    12,    13,    14,    15,    16,
      42,   590,    17,    20,   593,    45,   595,    74,     3,    26,
      27,   586,   601,   588,     3,   604,    33,    34,    74,   608,
      74,   610,    45,    37,    74,   614,    74,    74,    39,    74,
     619,    48,    76,    18,     3,   624,    74,    74,    74,    74,
     629,    74,    17,   632,     3,    51,    19,   636,    36,   638,
      17,   640,   485,    19,    74,   644,    47,    19,    74,   634,
     649,    74,    74,   652,    74,   654,    74,    74,   657,    74,
      74,    74,    19,   662,    17,   664,    57,     6,    18,    17,
     669,    74,   671,    18,    74,    18,    18,   676,    74,   678,
      74,    74,    74,    18,   683,    74,    18,   686,    74,   688,
      19,     3,   691,    18,     9,    17,   695,    17,   697,    60,
     699,     3,     3,   702,    74,    71,    62,   706,    19,   708,
      74,   710,    74,   461,    45,   714,     3,   716,   466,   718,
      67,    18,    17,   722,    17,   724,    17,   726,    17,    17,
       3,   730,    18,   732,    17,   734,    18,    18,    74,   487,
     739,    74,   741,     3,    74,    17,    74,   746,   496,   748,
      74,   499,    18,   752,    38,   754,   504,    74,   506,   758,
      74,   760,    18,    18,    74,   764,    74,   766,    74,    74,
     769,    74,    18,   772,   522,    74,   775,   525,    74,   778,
      17,    17,   781,    51,    52,    53,    54,    55,    56,    17,
      17,   539,    17,    35,    38,    38,   544,     3,    18,    46,
     548,    65,   550,    35,    18,    35,    35,    38,    18,    35,
      18,    35,   560,    74,     3,   563,    74,    74,   566,     3,
     568,    74,   570,    74,    74,   573,    74,    62,   576,    47,
      18,   579,    18,    74,   582,    74,    74,    38,     3,   587,
      74,   589,    19,    18,   592,    38,    18,    18,    18,    18,
      18,    74,   600,    74,    18,   603,    38,    74,    74,   607,
      45,   609,    74,    74,    38,   613,    18,    74,   616,    74,
     618,    74,    74,   621,    74,   623,    74,    74,   626,    74,
     628,    59,    74,   631,    74,    18,    18,   635,    18,   637,
      18,    74,    35,    74,    74,   643,    38,    38,   646,    38,
     648,    74,    38,   651,    38,   212,   173,    74,   656,   344,
     237,   659,    74,   661,    74,   663,    74,    74,   666,    74,
     668,    74,   670,    74,    74,   673,    74,   675,    74,   677,
      74,    38,   680,    38,   682,    38,    74,   685,    38,    74,
      38,   515,   234,    74,   558,    74,   694,    74,   696,    74,
      74,    74,    74,    74,    74,    74,    74,   705,    74,   707,
      74,    74,    74,    74,    74,   713,    74,   715,    74,    -1,
      74,   271,    74,   721,   170,   723,    -1,    74,    74,    74,
      74,   729,    74,   731,    74,    74,    74,    74,   447,    -1,
     738,    -1,    -1,   119,    -1,    -1,    -1,   745,    -1,    -1,
      -1,    -1,    -1,   751,    -1,    -1,    -1,    -1,    -1,   757,
      -1,    -1,    -1,    -1,    -1,   763,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    51,    52,    53,    54,
      55,    56,    77,    -1,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    77
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    80,     0,     4,     5,     9,    10,    12,    13,    14,
      15,    16,    20,    26,    27,    33,    34,    48,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      95,    96,   103,   109,   110,   116,   132,     6,     8,    64,
       6,     8,    17,    21,    22,    23,    24,    25,    62,    69,
      71,    72,    73,    74,    76,    77,   108,   121,   123,    74,
       7,     8,     3,    36,    38,    74,     3,     3,     3,     3,
       3,    49,    74,    74,     8,    74,    74,   121,    17,    17,
      17,    17,    17,   121,    35,    40,    74,    19,   124,    19,
      68,    69,    70,    77,   122,    38,     3,     3,    38,    74,
      74,    42,    50,    17,    45,    74,     3,     3,    18,    74,
      77,    74,    74,    74,    74,    74,    77,    74,    74,   121,
     121,   121,   121,   121,    74,    74,    37,    39,   126,    74,
     112,    76,    74,    98,   101,    74,    45,    18,    35,    18,
      18,    35,    18,    35,    18,    35,    18,    35,    40,    74,
      35,    40,    74,   124,   122,    19,    40,    46,    74,   125,
       3,    17,   105,    17,    57,    60,   121,   128,     3,    51,
      19,   111,    36,    19,    97,    28,    29,    30,    31,    32,
     100,    17,    74,    40,    74,    74,    40,    74,    40,    74,
      74,    40,    74,    74,    40,    74,    74,    40,    74,    74,
      74,    74,    77,    74,   124,    74,    74,    47,   125,   126,
     107,   121,    19,   104,     9,   118,    17,    57,    51,    52,
      53,    54,    55,    56,    58,    59,    60,    61,   131,    41,
      43,   127,    17,   107,   112,   126,     6,    98,    18,    17,
      60,    63,    74,    94,    17,    74,    18,    74,    74,    18,
      74,    18,    74,    18,    74,    18,    40,    74,   124,   124,
     124,    40,    74,   125,   125,    74,   126,     3,    44,    19,
     106,   105,     3,    21,    22,    23,    24,    25,    74,    18,
     118,    17,    17,    58,    59,    60,    17,   121,   128,   128,
       9,   111,     3,    74,    97,     3,    71,    99,    62,    19,
      93,    94,    40,    74,    40,    74,    40,    74,    40,    74,
      40,    74,    74,   124,    74,   125,   126,    45,     3,    67,
     107,    18,   104,    17,    17,    17,    17,    17,    35,    38,
      40,    74,    51,    52,    53,    54,    55,    56,   130,    18,
     118,   108,   118,   129,    17,   118,   127,   127,    21,    22,
      23,    24,    25,    74,    77,   113,   114,     3,    18,    94,
      18,    93,    74,    74,    74,    74,    74,   124,   125,     3,
     120,   128,    74,   117,   106,    74,    77,    74,    74,    74,
      74,    74,    74,    74,    38,    17,    74,    18,   106,    18,
      18,   118,   129,    18,    17,    17,    17,    17,    17,    35,
      38,    38,    60,    63,    93,     3,    18,    46,   119,   127,
      19,    35,    65,   115,    35,    18,    35,    35,    35,    35,
      38,    40,    74,    40,    74,   125,    38,    74,   118,    18,
      18,    74,    77,    74,    74,    74,    74,    74,    77,    74,
      74,    62,     3,    47,   126,    74,    74,   121,     3,    74,
      38,    40,    74,    74,    74,    74,    74,    74,    74,    38,
      74,   125,   102,    74,    40,    74,   125,    18,    18,    35,
      18,    18,    35,    18,    35,    18,    35,    18,    35,   126,
     126,    74,     3,    19,    60,   131,    18,    74,    74,    38,
      18,    18,    18,    18,    40,    74,   125,    38,    74,   125,
     102,   126,    40,    74,   125,    74,   125,   102,    74,    74,
      74,    74,    74,    18,    18,    45,    74,   121,    38,    40,
      74,    40,    74,   102,    38,    74,    38,    40,    74,    38,
      40,    74,    38,    40,    74,    38,    40,    74,    74,   125,
     102,    74,    40,    74,   125,   102,   126,    74,   125,   102,
     125,   102,   126,    18,    18,    18,    18,    18,   120,    35,
      74,    74,    38,    74,   102,   126,    74,    40,    74,   102,
      74,    74,    38,    74,    74,    38,    74,    74,    38,    74,
      74,    38,   125,   102,   126,    40,    74,   125,    74,   125,
     102,   126,   125,   102,   126,   102,   126,   119,    74,    40,
      74,   102,    38,    74,   102,   126,    40,    74,   102,    74,
     102,   126,    40,    74,   102,    38,    74,    40,    74,   102,
      38,    74,    40,    74,   102,    38,    74,    40,    74,   102,
      38,    74,   102,   126,    74,   125,   102,   125,   102,   126,
     102,   126,   126,    74,   102,   126,    74,    40,    74,   102,
     126,    74,   102,   126,   102,   126,    74,   102,   126,    74,
      40,    74,   102,    74,   102,   126,    74,    40,    74,   102,
      74,   102,   126,    74,    40,    74,   102,    74,   102,   126,
      74,    40,    74,   102,   126,   125,   102,   126,   102,   126,
     126,   102,   126,    40,    74,   102,    74,   102,   126,   102,
     126,   126,   102,   126,    40,    74,   102,    74,   102,   126,
     102,   126,    40,    74,   102,    74,   102,   126,   102,   126,
      40,    74,   102,    74,   102,   126,   102,   126,    40,    74,
     102,    74,   102,   126,   102,   126,   126,   126,    74,   102,
     126,   102,   126,   126,   126,    74,   102,   126,   102,   126,
     126,    74,   102,   126,   102,   126,   126,    74,   102,   126,
     102,   126,   126,    74,   102,   126,   102,   126,   126,   102,
     126,   126,   102,   126,   126,   102,   126,   126,   102,   126,
     126,   102,   126,   126,   126,   126,   126,   126,   126
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
     115,   115,   116,   116,   116,   116,   116,   117,   117,   117,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   119,   120,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   122,   122,   123,   123,   124,   124,   124,   124,
     124,   124,   124,   124,   125,   125,   125,   125,   126,   126,
     127,   127,   127,   128,   128,   128,   128,   128,   128,   128,
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
       0,     4,     7,    11,    12,     9,     8,     1,     3,     7,
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
#line 202 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1783 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 207 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1791 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 212 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1799 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 218 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1807 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 224 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1815 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 230 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1823 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 236 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1832 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 242 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1840 "yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 248 "yacc_sql.y"
                                {
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
    }
#line 1849 "yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 256 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1858 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 264 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
		}
#line 1867 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 269 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
		}
#line 1876 "yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA index_attr index_attr_list  */
#line 277 "yacc_sql.y"
                                           { }
#line 1882 "yacc_sql.tab.c"
    break;

  case 36: /* index_attr: ID  */
#line 282 "yacc_sql.y"
                {
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
		}
#line 1890 "yacc_sql.tab.c"
    break;

  case 37: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 289 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1899 "yacc_sql.tab.c"
    break;

  case 38: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 296 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1911 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 306 "yacc_sql.y"
                                   {    }
#line 1917 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 311 "yacc_sql.y"
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
#line 1932 "yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type LBRACE number RBRACE NOT NULLL  */
#line 322 "yacc_sql.y"
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
#line 1947 "yacc_sql.tab.c"
    break;

  case 43: /* attr_def: ID_get type LBRACE number RBRACE NULLABLE  */
#line 333 "yacc_sql.y"
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
#line 1962 "yacc_sql.tab.c"
    break;

  case 44: /* attr_def: ID_get type  */
#line 344 "yacc_sql.y"
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
#line 1977 "yacc_sql.tab.c"
    break;

  case 45: /* attr_def: ID_get type NOT NULLL  */
#line 355 "yacc_sql.y"
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
#line 1992 "yacc_sql.tab.c"
    break;

  case 46: /* attr_def: ID_get type NULLABLE  */
#line 366 "yacc_sql.y"
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
#line 2007 "yacc_sql.tab.c"
    break;

  case 47: /* number: NUMBER  */
#line 378 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 2013 "yacc_sql.tab.c"
    break;

  case 48: /* type: INT_T  */
#line 381 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 2019 "yacc_sql.tab.c"
    break;

  case 49: /* type: DATE_T  */
#line 382 "yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 2025 "yacc_sql.tab.c"
    break;

  case 50: /* type: TEXT_T  */
#line 383 "yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 2031 "yacc_sql.tab.c"
    break;

  case 51: /* type: STRING_T  */
#line 384 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 2037 "yacc_sql.tab.c"
    break;

  case 52: /* type: FLOAT_T  */
#line 385 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 2043 "yacc_sql.tab.c"
    break;

  case 53: /* ID_get: ID  */
#line 389 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 2052 "yacc_sql.tab.c"
    break;

  case 54: /* dummy: %empty  */
#line 395 "yacc_sql.y"
      {
		CONTEXT->depth++;
		CONTEXT->sub_con_start[CONTEXT->depth]=CONTEXT->condition_length;
	}
#line 2061 "yacc_sql.tab.c"
    break;

  case 55: /* insert: INSERT INTO ID VALUES record record_list SEMICOLON  */
#line 402 "yacc_sql.y"
        {
		CONTEXT->ssql->flag=SCF_INSERT;//"insert";
		CONTEXT->ssql->sstr.insertion.relation_name = (yyvsp[-4].string);
		CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
		inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-4].string), CONTEXT->values, CONTEXT->value_length,CONTEXT->single_record_length,CONTEXT->record_length);

      	CONTEXT->value_length=0;
	  	CONTEXT->record_length=0;
    }
#line 2075 "yacc_sql.tab.c"
    break;

  case 57: /* record_list: COMMA record record_list  */
#line 412 "yacc_sql.y"
                                        {

		}
#line 2083 "yacc_sql.tab.c"
    break;

  case 59: /* record: LBRACE insert_value value_list RBRACE  */
#line 419 "yacc_sql.y"
                {
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		}
#line 2092 "yacc_sql.tab.c"
    break;

  case 61: /* value_list: COMMA insert_value value_list  */
#line 424 "yacc_sql.y"
                                     { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 2100 "yacc_sql.tab.c"
    break;

  case 62: /* insert_value: expr  */
#line 430 "yacc_sql.y"
             {
		value_init_astexpr((yyvsp[0].expr1), &CONTEXT->values[CONTEXT->value_length - 1]);
	}
#line 2108 "yacc_sql.tab.c"
    break;

  case 63: /* value: NUMBER  */
#line 435 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2116 "yacc_sql.tab.c"
    break;

  case 64: /* value: FLOAT  */
#line 438 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2124 "yacc_sql.tab.c"
    break;

  case 65: /* value: DATEE  */
#line 441 "yacc_sql.y"
               {
			(yyvsp[0].dates) = substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].dates));
		}
#line 2133 "yacc_sql.tab.c"
    break;

  case 66: /* value: SSS  */
#line 445 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2142 "yacc_sql.tab.c"
    break;

  case 67: /* value: NULLL  */
#line 449 "yacc_sql.y"
               {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		}
#line 2150 "yacc_sql.tab.c"
    break;

  case 68: /* delete: DELETE FROM ID where SEMICOLON  */
#line 456 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2162 "yacc_sql.tab.c"
    break;

  case 69: /* update: UPDATE ID SET update_attr update_attr_list where SEMICOLON  */
#line 466 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2172 "yacc_sql.tab.c"
    break;

  case 72: /* update_attr: ID EQ insert_value  */
#line 480 "yacc_sql.y"
                {
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			CONTEXT->value_length = 0;
		}
#line 2182 "yacc_sql.tab.c"
    break;

  case 73: /* update_attr: ID EQ LBRACE SELECT update_select_attr FROM ID where RBRACE  */
#line 486 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2194 "yacc_sql.tab.c"
    break;

  case 74: /* update_attr: ID EQ LBRACE SELECT update_agg FROM ID where RBRACE  */
#line 494 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2206 "yacc_sql.tab.c"
    break;

  case 75: /* update_select_attr: STAR  */
#line 504 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2216 "yacc_sql.tab.c"
    break;

  case 76: /* update_select_attr: ID  */
#line 509 "yacc_sql.y"
         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2226 "yacc_sql.tab.c"
    break;

  case 77: /* update_select_attr: ID DOT ID  */
#line 514 "yacc_sql.y"
                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2236 "yacc_sql.tab.c"
    break;

  case 78: /* update_select_attr: ID DOT STAR  */
#line 519 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2246 "yacc_sql.tab.c"
    break;

  case 79: /* update_agg: COUNT_T LBRACE STAR RBRACE  */
#line 527 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
#line 2256 "yacc_sql.tab.c"
    break;

  case 80: /* update_agg: COUNT_T LBRACE ID RBRACE  */
#line 532 "yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2266 "yacc_sql.tab.c"
    break;

  case 81: /* update_agg: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 537 "yacc_sql.y"
                                          {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2276 "yacc_sql.tab.c"
    break;

  case 82: /* update_agg: MAX_T LBRACE ID RBRACE  */
#line 542 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2286 "yacc_sql.tab.c"
    break;

  case 83: /* update_agg: MAX_T LBRACE ID DOT ID RBRACE  */
#line 547 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2296 "yacc_sql.tab.c"
    break;

  case 84: /* update_agg: MIN_T LBRACE ID RBRACE  */
#line 552 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2306 "yacc_sql.tab.c"
    break;

  case 85: /* update_agg: MIN_T LBRACE ID DOT ID RBRACE  */
#line 557 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2316 "yacc_sql.tab.c"
    break;

  case 86: /* update_agg: SUM_T LBRACE ID RBRACE  */
#line 562 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2326 "yacc_sql.tab.c"
    break;

  case 87: /* update_agg: SUM_T LBRACE ID DOT ID RBRACE  */
#line 567 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2336 "yacc_sql.tab.c"
    break;

  case 88: /* update_agg: AVG_T LBRACE ID RBRACE  */
#line 572 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2346 "yacc_sql.tab.c"
    break;

  case 89: /* update_agg: AVG_T LBRACE ID DOT ID RBRACE  */
#line 577 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2356 "yacc_sql.tab.c"
    break;

  case 91: /* having: HAVING expr comOp expr  */
#line 586 "yacc_sql.y"
        {
		Condition condition;
		condition_init_from_expr(&condition, CONTEXT->comp, (yyvsp[-2].expr1), (yyvsp[0].expr1));
		selects_setup_having_condition(&CONTEXT->ssql->sstr.selection,&condition);
	}
#line 2366 "yacc_sql.tab.c"
    break;

  case 92: /* select: SELECT select_attr FROM ID rel_list where SEMICOLON  */
#line 594 "yacc_sql.y"
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
#line 2384 "yacc_sql.tab.c"
    break;

  case 93: /* select: SELECT select_attr FROM ID rel_list where GROUP BY by_attrs having SEMICOLON  */
#line 608 "yacc_sql.y"
                                                                                       {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-7].string));
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;

		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2399 "yacc_sql.tab.c"
    break;

  case 94: /* select: SELECT select_attr FROM ID INNER_T JOIN_T ID ON join_cons join_list where SEMICOLON  */
#line 619 "yacc_sql.y"
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
#line 2415 "yacc_sql.tab.c"
    break;

  case 95: /* select: SELECT select_attr FROM ID AS ID rel_list where SEMICOLON  */
#line 630 "yacc_sql.y"
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
#line 2430 "yacc_sql.tab.c"
    break;

  case 96: /* select: SELECT select_attr FROM ID ID rel_list where SEMICOLON  */
#line 640 "yacc_sql.y"
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
#line 2445 "yacc_sql.tab.c"
    break;

  case 97: /* by_attrs: ID  */
#line 652 "yacc_sql.y"
           {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->ssql->sstr.selection.gruop_use[0]=attr;
		CONTEXT->ssql->sstr.selection.group_num=1;
	}
#line 2456 "yacc_sql.tab.c"
    break;

  case 98: /* by_attrs: ID COMMA ID  */
#line 658 "yacc_sql.y"
                    {
		RelAttr attr1,attr2;
		relation_attr_init(&attr1, NULL, (yyvsp[-2].string));
		relation_attr_init(&attr2, NULL, (yyvsp[0].string));
		CONTEXT->ssql->sstr.selection.gruop_use[0]=attr1;
		CONTEXT->ssql->sstr.selection.gruop_use[1]=attr2;
		CONTEXT->ssql->sstr.selection.group_num=2;
	}
#line 2469 "yacc_sql.tab.c"
    break;

  case 99: /* by_attrs: ID DOT ID COMMA ID DOT ID  */
#line 666 "yacc_sql.y"
                                   {
		RelAttr attr1,attr2;
		relation_attr_init(&attr1,(yyvsp[-6].string),(yyvsp[-4].string));
		relation_attr_init(&attr2,(yyvsp[-2].string),(yyvsp[0].string));
		CONTEXT->ssql->sstr.selection.gruop_use[0]=attr1;
		CONTEXT->ssql->sstr.selection.gruop_use[1]=attr2;
		CONTEXT->ssql->sstr.selection.group_num=2;
	}
#line 2482 "yacc_sql.tab.c"
    break;

  case 100: /* sub_query: SELECT ID DOT ID FROM ID rel_list dummy where  */
#line 677 "yacc_sql.y"
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
#line 2506 "yacc_sql.tab.c"
    break;

  case 101: /* sub_query: SELECT ID FROM ID rel_list dummy where  */
#line 696 "yacc_sql.y"
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
#line 2530 "yacc_sql.tab.c"
    break;

  case 102: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID dummy where  */
#line 715 "yacc_sql.y"
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
#line 2554 "yacc_sql.tab.c"
    break;

  case 103: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 734 "yacc_sql.y"
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
#line 2578 "yacc_sql.tab.c"
    break;

  case 104: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 753 "yacc_sql.y"
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
#line 2601 "yacc_sql.tab.c"
    break;

  case 105: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 771 "yacc_sql.y"
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
#line 2624 "yacc_sql.tab.c"
    break;

  case 106: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 789 "yacc_sql.y"
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
#line 2647 "yacc_sql.tab.c"
    break;

  case 107: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 807 "yacc_sql.y"
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
#line 2673 "yacc_sql.tab.c"
    break;

  case 108: /* sub_query: SELECT ID DOT ID FROM ID AS ID rel_list dummy where  */
#line 828 "yacc_sql.y"
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
#line 2699 "yacc_sql.tab.c"
    break;

  case 109: /* sub_query: SELECT ID FROM ID AS ID rel_list dummy where  */
#line 849 "yacc_sql.y"
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
#line 2722 "yacc_sql.tab.c"
    break;

  case 110: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID AS ID dummy where  */
#line 867 "yacc_sql.y"
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
#line 2746 "yacc_sql.tab.c"
    break;

  case 111: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 886 "yacc_sql.y"
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
#line 2769 "yacc_sql.tab.c"
    break;

  case 112: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 904 "yacc_sql.y"
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
#line 2793 "yacc_sql.tab.c"
    break;

  case 113: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 923 "yacc_sql.y"
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
#line 2816 "yacc_sql.tab.c"
    break;

  case 114: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 941 "yacc_sql.y"
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
#line 2839 "yacc_sql.tab.c"
    break;

  case 115: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 959 "yacc_sql.y"
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
#line 2865 "yacc_sql.tab.c"
    break;

  case 116: /* sub_query: SELECT ID DOT ID FROM ID ID rel_list dummy where  */
#line 980 "yacc_sql.y"
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
#line 2892 "yacc_sql.tab.c"
    break;

  case 117: /* sub_query: SELECT ID FROM ID ID rel_list dummy where  */
#line 1002 "yacc_sql.y"
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
#line 2916 "yacc_sql.tab.c"
    break;

  case 118: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID ID dummy where  */
#line 1021 "yacc_sql.y"
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
#line 2940 "yacc_sql.tab.c"
    break;

  case 119: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1040 "yacc_sql.y"
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
#line 2964 "yacc_sql.tab.c"
    break;

  case 120: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1059 "yacc_sql.y"
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
#line 2988 "yacc_sql.tab.c"
    break;

  case 121: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1078 "yacc_sql.y"
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
#line 3012 "yacc_sql.tab.c"
    break;

  case 122: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1097 "yacc_sql.y"
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
#line 3036 "yacc_sql.tab.c"
    break;

  case 123: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1116 "yacc_sql.y"
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
#line 3062 "yacc_sql.tab.c"
    break;

  case 124: /* sub_query: SELECT ID DOT ID AS ID FROM ID rel_list dummy where  */
#line 1138 "yacc_sql.y"
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
#line 3088 "yacc_sql.tab.c"
    break;

  case 125: /* sub_query: SELECT ID DOT ID ID FROM ID rel_list dummy where  */
#line 1159 "yacc_sql.y"
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
#line 3114 "yacc_sql.tab.c"
    break;

  case 126: /* sub_query: SELECT ID AS ID FROM ID rel_list dummy where  */
#line 1180 "yacc_sql.y"
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
#line 3138 "yacc_sql.tab.c"
    break;

  case 127: /* sub_query: SELECT ID ID FROM ID rel_list dummy where  */
#line 1199 "yacc_sql.y"
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
#line 3162 "yacc_sql.tab.c"
    break;

  case 128: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID dummy where  */
#line 1218 "yacc_sql.y"
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
#line 3186 "yacc_sql.tab.c"
    break;

  case 129: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID dummy where  */
#line 1237 "yacc_sql.y"
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
#line 3210 "yacc_sql.tab.c"
    break;

  case 130: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1256 "yacc_sql.y"
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
#line 3234 "yacc_sql.tab.c"
    break;

  case 131: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1275 "yacc_sql.y"
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
#line 3258 "yacc_sql.tab.c"
    break;

  case 132: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1294 "yacc_sql.y"
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
#line 3281 "yacc_sql.tab.c"
    break;

  case 133: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1312 "yacc_sql.y"
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
#line 3304 "yacc_sql.tab.c"
    break;

  case 134: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1330 "yacc_sql.y"
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
#line 3327 "yacc_sql.tab.c"
    break;

  case 135: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1348 "yacc_sql.y"
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
#line 3350 "yacc_sql.tab.c"
    break;

  case 136: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1366 "yacc_sql.y"
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
#line 3374 "yacc_sql.tab.c"
    break;

  case 137: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1385 "yacc_sql.y"
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
#line 3398 "yacc_sql.tab.c"
    break;

  case 138: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID dummy where  */
#line 1404 "yacc_sql.y"
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
#line 3424 "yacc_sql.tab.c"
    break;

  case 139: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID dummy where  */
#line 1425 "yacc_sql.y"
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
#line 3450 "yacc_sql.tab.c"
    break;

  case 140: /* sub_query: SELECT ID DOT ID AS ID FROM ID AS ID rel_list dummy where  */
#line 1446 "yacc_sql.y"
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
#line 3477 "yacc_sql.tab.c"
    break;

  case 141: /* sub_query: SELECT ID DOT ID ID FROM ID AS ID rel_list dummy where  */
#line 1468 "yacc_sql.y"
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
#line 3504 "yacc_sql.tab.c"
    break;

  case 142: /* sub_query: SELECT ID AS ID FROM ID AS ID rel_list dummy where  */
#line 1490 "yacc_sql.y"
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
#line 3527 "yacc_sql.tab.c"
    break;

  case 143: /* sub_query: SELECT ID ID FROM ID AS ID rel_list dummy where  */
#line 1508 "yacc_sql.y"
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
#line 3550 "yacc_sql.tab.c"
    break;

  case 144: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID AS ID dummy where  */
#line 1526 "yacc_sql.y"
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
#line 3574 "yacc_sql.tab.c"
    break;

  case 145: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID AS ID dummy where  */
#line 1545 "yacc_sql.y"
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
#line 3598 "yacc_sql.tab.c"
    break;

  case 146: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1564 "yacc_sql.y"
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
#line 3621 "yacc_sql.tab.c"
    break;

  case 147: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1582 "yacc_sql.y"
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
#line 3644 "yacc_sql.tab.c"
    break;

  case 148: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1600 "yacc_sql.y"
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
#line 3668 "yacc_sql.tab.c"
    break;

  case 149: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1619 "yacc_sql.y"
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
#line 3692 "yacc_sql.tab.c"
    break;

  case 150: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1638 "yacc_sql.y"
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
#line 3715 "yacc_sql.tab.c"
    break;

  case 151: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1656 "yacc_sql.y"
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
#line 3738 "yacc_sql.tab.c"
    break;

  case 152: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1674 "yacc_sql.y"
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
#line 3761 "yacc_sql.tab.c"
    break;

  case 153: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1692 "yacc_sql.y"
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
#line 3784 "yacc_sql.tab.c"
    break;

  case 154: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID AS ID dummy where  */
#line 1710 "yacc_sql.y"
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
#line 3810 "yacc_sql.tab.c"
    break;

  case 155: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID AS ID dummy where  */
#line 1731 "yacc_sql.y"
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
#line 3836 "yacc_sql.tab.c"
    break;

  case 156: /* sub_query: SELECT ID DOT ID AS ID FROM ID ID rel_list dummy where  */
#line 1752 "yacc_sql.y"
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
#line 3863 "yacc_sql.tab.c"
    break;

  case 157: /* sub_query: SELECT ID DOT ID ID FROM ID ID rel_list dummy where  */
#line 1774 "yacc_sql.y"
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
#line 3890 "yacc_sql.tab.c"
    break;

  case 158: /* sub_query: SELECT ID AS ID FROM ID ID rel_list dummy where  */
#line 1796 "yacc_sql.y"
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
#line 3914 "yacc_sql.tab.c"
    break;

  case 159: /* sub_query: SELECT ID ID FROM ID ID rel_list dummy where  */
#line 1815 "yacc_sql.y"
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
#line 3938 "yacc_sql.tab.c"
    break;

  case 160: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE AS ID FROM ID ID dummy where  */
#line 1834 "yacc_sql.y"
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
#line 3962 "yacc_sql.tab.c"
    break;

  case 161: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE ID FROM ID ID dummy where  */
#line 1853 "yacc_sql.y"
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
#line 3986 "yacc_sql.tab.c"
    break;

  case 162: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 1872 "yacc_sql.y"
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
#line 4010 "yacc_sql.tab.c"
    break;

  case 163: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 1891 "yacc_sql.y"
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
#line 4034 "yacc_sql.tab.c"
    break;

  case 164: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 1910 "yacc_sql.y"
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
#line 4058 "yacc_sql.tab.c"
    break;

  case 165: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 1929 "yacc_sql.y"
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
#line 4082 "yacc_sql.tab.c"
    break;

  case 166: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 1948 "yacc_sql.y"
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
#line 4106 "yacc_sql.tab.c"
    break;

  case 167: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 1967 "yacc_sql.y"
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
#line 4130 "yacc_sql.tab.c"
    break;

  case 168: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 1986 "yacc_sql.y"
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
#line 4154 "yacc_sql.tab.c"
    break;

  case 169: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2005 "yacc_sql.y"
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
#line 4178 "yacc_sql.tab.c"
    break;

  case 170: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE AS ID FROM ID ID dummy where  */
#line 2024 "yacc_sql.y"
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
#line 4205 "yacc_sql.tab.c"
    break;

  case 171: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE ID FROM ID ID dummy where  */
#line 2046 "yacc_sql.y"
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
#line 4232 "yacc_sql.tab.c"
    break;

  case 173: /* join_list: INNER_T JOIN_T ID ON join_cons join_list  */
#line 2072 "yacc_sql.y"
                                               {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
	}
#line 4240 "yacc_sql.tab.c"
    break;

  case 174: /* join_cons: condition condition_list  */
#line 2077 "yacc_sql.y"
                                  {	
	}
#line 4247 "yacc_sql.tab.c"
    break;

  case 175: /* expr: expr ADD expr  */
#line 2082 "yacc_sql.y"
                      {
		(yyval.expr1) = create_astexpr(ADD_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4255 "yacc_sql.tab.c"
    break;

  case 176: /* expr: SUB expr  */
#line 2085 "yacc_sql.y"
                   {
		(yyval.expr1) = create_astexpr(SUB_OP, NULL, (yyvsp[0].expr1));
	}
#line 4263 "yacc_sql.tab.c"
    break;

  case 177: /* expr: expr SUB expr  */
#line 2088 "yacc_sql.y"
                        {
		(yyval.expr1) = create_astexpr(SUB_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4271 "yacc_sql.tab.c"
    break;

  case 178: /* expr: expr STAR expr  */
#line 2091 "yacc_sql.y"
                         {
		(yyval.expr1) = create_astexpr(MUL_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4279 "yacc_sql.tab.c"
    break;

  case 179: /* expr: expr DIV expr  */
#line 2094 "yacc_sql.y"
                        {
		(yyval.expr1) = create_astexpr(DIV_OP, (yyvsp[-2].expr1), (yyvsp[0].expr1));
	}
#line 4287 "yacc_sql.tab.c"
    break;

  case 180: /* expr: LBRACE expr RBRACE  */
#line 2097 "yacc_sql.y"
                             {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-1].expr1);
		astExpr->left_brackets ++;
		astExpr->right_brackets ++;
		(yyval.expr1) = (yyvsp[-1].expr1);
	}
#line 4298 "yacc_sql.tab.c"
    break;

  case 181: /* expr: value  */
#line 2103 "yacc_sql.y"
                {
		(yyval.expr1) = create_value_expr(&CONTEXT->values[CONTEXT->value_length - 1]);
	}
#line 4306 "yacc_sql.tab.c"
    break;

  case 182: /* expr: ID  */
#line 2106 "yacc_sql.y"
             {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4316 "yacc_sql.tab.c"
    break;

  case 183: /* expr: ID DOT ID  */
#line 2111 "yacc_sql.y"
                    {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4326 "yacc_sql.tab.c"
    break;

  case 184: /* expr: ID DOT STAR  */
#line 2116 "yacc_sql.y"
                      {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), "*");
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4336 "yacc_sql.tab.c"
    break;

  case 185: /* expr: ID AS ID  */
#line 2121 "yacc_sql.y"
                   {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[0].string));

		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4348 "yacc_sql.tab.c"
    break;

  case 186: /* expr: ID DOT ID AS ID  */
#line 2128 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4359 "yacc_sql.tab.c"
    break;

  case 187: /* expr: ID ID  */
#line 2134 "yacc_sql.y"
                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4370 "yacc_sql.tab.c"
    break;

  case 188: /* expr: ID DOT ID ID  */
#line 2140 "yacc_sql.y"
                       {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string),(yyvsp[0].string));
		(yyval.expr1) = create_attr_expr(&attr, 1);
	}
#line 4381 "yacc_sql.tab.c"
    break;

  case 189: /* expr: COUNT_T LBRACE STAR RBRACE  */
#line 2146 "yacc_sql.y"
                                     {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4391 "yacc_sql.tab.c"
    break;

  case 190: /* expr: COUNT_T LBRACE ID RBRACE  */
#line 2151 "yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4401 "yacc_sql.tab.c"
    break;

  case 191: /* expr: MAX_T LBRACE ID RBRACE  */
#line 2156 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4411 "yacc_sql.tab.c"
    break;

  case 192: /* expr: MIN_T LBRACE ID RBRACE  */
#line 2161 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4421 "yacc_sql.tab.c"
    break;

  case 193: /* expr: SUM_T LBRACE ID RBRACE  */
#line 2166 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4431 "yacc_sql.tab.c"
    break;

  case 194: /* expr: AVG_T LBRACE ID RBRACE  */
#line 2171 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4441 "yacc_sql.tab.c"
    break;

  case 195: /* expr: COUNT_T LBRACE STAR RBRACE AS ID  */
#line 2177 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4454 "yacc_sql.tab.c"
    break;

  case 196: /* expr: COUNT_T LBRACE ID RBRACE AS ID  */
#line 2185 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4467 "yacc_sql.tab.c"
    break;

  case 197: /* expr: MAX_T LBRACE ID RBRACE AS ID  */
#line 2193 "yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4480 "yacc_sql.tab.c"
    break;

  case 198: /* expr: MIN_T LBRACE ID RBRACE AS ID  */
#line 2201 "yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4493 "yacc_sql.tab.c"
    break;

  case 199: /* expr: SUM_T LBRACE ID RBRACE AS ID  */
#line 2209 "yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4506 "yacc_sql.tab.c"
    break;

  case 200: /* expr: AVG_T LBRACE ID RBRACE AS ID  */
#line 2217 "yacc_sql.y"
                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-3].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4519 "yacc_sql.tab.c"
    break;

  case 201: /* expr: COUNT_T LBRACE STAR RBRACE ID  */
#line 2225 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4531 "yacc_sql.tab.c"
    break;

  case 202: /* expr: COUNT_T LBRACE ID RBRACE ID  */
#line 2232 "yacc_sql.y"
                                     {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-2].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4543 "yacc_sql.tab.c"
    break;

  case 203: /* expr: MAX_T LBRACE ID RBRACE ID  */
#line 2239 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-2].string),(yyvsp[0].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4556 "yacc_sql.tab.c"
    break;

  case 204: /* expr: MIN_T LBRACE ID RBRACE ID  */
#line 2247 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4569 "yacc_sql.tab.c"
    break;

  case 205: /* expr: SUM_T LBRACE ID RBRACE ID  */
#line 2255 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	  }
#line 4582 "yacc_sql.tab.c"
    break;

  case 206: /* expr: AVG_T LBRACE ID RBRACE ID  */
#line 2263 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	  }
#line 4595 "yacc_sql.tab.c"
    break;

  case 207: /* expr: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 2271 "yacc_sql.y"
                                         {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4606 "yacc_sql.tab.c"
    break;

  case 208: /* expr: MAX_T LBRACE ID DOT ID RBRACE  */
#line 2277 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MAX_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4617 "yacc_sql.tab.c"
    break;

  case 209: /* expr: MIN_T LBRACE ID DOT ID RBRACE  */
#line 2283 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MIN_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4628 "yacc_sql.tab.c"
    break;

  case 210: /* expr: SUM_T LBRACE ID DOT ID RBRACE  */
#line 2289 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,SUM_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4639 "yacc_sql.tab.c"
    break;

  case 211: /* expr: AVG_T LBRACE ID DOT ID RBRACE  */
#line 2295 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,AVG_T,(yyvsp[-3].string),(yyvsp[-1].string));

		(yyval.expr1) = create_agg_expr(&aggre, 1);
	}
#line 4650 "yacc_sql.tab.c"
    break;

  case 212: /* expr: COUNT_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2301 "yacc_sql.y"
                                               {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4662 "yacc_sql.tab.c"
    break;

  case 213: /* expr: MAX_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2308 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MAX_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4675 "yacc_sql.tab.c"
    break;

  case 214: /* expr: MIN_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2316 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,MIN_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4688 "yacc_sql.tab.c"
    break;

  case 215: /* expr: SUM_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2324 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,SUM_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4701 "yacc_sql.tab.c"
    break;

  case 216: /* expr: AVG_T LBRACE ID DOT ID RBRACE AS ID  */
#line 2332 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,AVG_T,(yyvsp[-5].string),(yyvsp[-3].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4714 "yacc_sql.tab.c"
    break;

  case 217: /* expr: COUNT_T LBRACE ID DOT ID RBRACE ID  */
#line 2340 "yacc_sql.y"
                                            {
		AggFun aggre;
		Init_AggFun_Rel(&aggre,COUNT,(yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4726 "yacc_sql.tab.c"
    break;

  case 218: /* expr: MAX_T LBRACE ID DOT ID RBRACE ID  */
#line 2347 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4739 "yacc_sql.tab.c"
    break;

  case 219: /* expr: MIN_T LBRACE ID DOT ID RBRACE ID  */
#line 2355 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));

		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4752 "yacc_sql.tab.c"
    break;

  case 220: /* expr: SUM_T LBRACE ID DOT ID RBRACE ID  */
#line 2363 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
	
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4765 "yacc_sql.tab.c"
    break;

  case 221: /* expr: AVG_T LBRACE ID DOT ID RBRACE ID  */
#line 2371 "yacc_sql.y"
                                           {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-4].string),(yyvsp[-2].string));
		selects_reverse_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		selects_append_alias3(&CONTEXT->ssql->sstr.selection,&aggre,(yyvsp[0].string));
		
		(yyval.expr1) = create_agg_expr(&aggre, 0);
	}
#line 4778 "yacc_sql.tab.c"
    break;

  case 223: /* expr_list: COMMA expr expr_list  */
#line 2382 "yacc_sql.y"
                               {
		selects_append_expr(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1));
	}
#line 4786 "yacc_sql.tab.c"
    break;

  case 224: /* select_attr: STAR attr_list  */
#line 2387 "yacc_sql.y"
                   {  
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		CONTEXT->ssql->sstr.selection.need_Revere=1;
	}
#line 4797 "yacc_sql.tab.c"
    break;

  case 225: /* select_attr: expr expr_list  */
#line 2393 "yacc_sql.y"
                         {
		selects_append_expr(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].expr1));
	}
#line 4805 "yacc_sql.tab.c"
    break;

  case 227: /* attr_list: COMMA ID attr_list  */
#line 2400 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 4816 "yacc_sql.tab.c"
    break;

  case 228: /* attr_list: COMMA ID DOT ID attr_list  */
#line 2406 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 4827 "yacc_sql.tab.c"
    break;

  case 229: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 2412 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 4838 "yacc_sql.tab.c"
    break;

  case 230: /* attr_list: COMMA ID AS ID attr_list  */
#line 2420 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-3].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 4850 "yacc_sql.tab.c"
    break;

  case 231: /* attr_list: COMMA ID DOT ID AS ID attr_list  */
#line 2427 "yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string),(yyvsp[-1].string));
		}
#line 4861 "yacc_sql.tab.c"
    break;

  case 232: /* attr_list: COMMA ID ID attr_list  */
#line 2433 "yacc_sql.y"
                                {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-2].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
	}
#line 4873 "yacc_sql.tab.c"
    break;

  case 233: /* attr_list: COMMA ID DOT ID ID attr_list  */
#line 2440 "yacc_sql.y"
                                        {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string),(yyvsp[-2].string),(yyvsp[-1].string));
		}
#line 4884 "yacc_sql.tab.c"
    break;

  case 235: /* rel_list: COMMA ID rel_list  */
#line 2451 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 4892 "yacc_sql.tab.c"
    break;

  case 236: /* rel_list: COMMA ID AS ID rel_list  */
#line 2454 "yacc_sql.y"
                                 {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 4901 "yacc_sql.tab.c"
    break;

  case 237: /* rel_list: COMMA ID ID rel_list  */
#line 2458 "yacc_sql.y"
                              {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
	}
#line 4910 "yacc_sql.tab.c"
    break;

  case 239: /* where: WHERE condition condition_list  */
#line 2465 "yacc_sql.y"
                                     {
	}
#line 4917 "yacc_sql.tab.c"
    break;

  case 241: /* condition_list: AND condition condition_list  */
#line 2470 "yacc_sql.y"
                                   {
		CONTEXT->ssql->sstr.selection.is_or=0;
	}
#line 4925 "yacc_sql.tab.c"
    break;

  case 242: /* condition_list: OR condition condition_list  */
#line 2473 "yacc_sql.y"
                                    {
		CONTEXT->ssql->sstr.selection.is_or=1;
	}
#line 4933 "yacc_sql.tab.c"
    break;

  case 243: /* condition: expr comOp expr  */
#line 2479 "yacc_sql.y"
        {
		Condition condition;
		condition_init_from_expr(&condition, CONTEXT->comp, (yyvsp[-2].expr1), (yyvsp[0].expr1));
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 4943 "yacc_sql.tab.c"
    break;

  case 244: /* condition: EXIST_T LBRACE sub_query RBRACE  */
#line 2485 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 4953 "yacc_sql.tab.c"
    break;

  case 245: /* condition: NOT EXIST_T LBRACE sub_query RBRACE  */
#line 2491 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, NOT_EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 4963 "yacc_sql.tab.c"
    break;

  case 246: /* condition: LBRACE sub_query RBRACE reverseComp ID  */
#line 2496 "yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->comp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 4975 "yacc_sql.tab.c"
    break;

  case 247: /* condition: expr IN_T LBRACE in_cells RBRACE  */
#line 2503 "yacc_sql.y"
                                          {
		/*TODO: 当前认为expr一定是单个attr */
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_cells_for_in(&condition,&astExpr->attr,CONTEXT->values,CONTEXT->value_length,IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 4988 "yacc_sql.tab.c"
    break;

  case 248: /* condition: expr NOT IN_T LBRACE in_cells RBRACE  */
#line 2511 "yacc_sql.y"
                                              {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-5].expr1);
		Condition condition;
		condition_init_cells_for_in(&condition,&astExpr->attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5000 "yacc_sql.tab.c"
    break;

  case 249: /* condition: expr IN_T LBRACE sub_query RBRACE  */
#line 2518 "yacc_sql.y"
                                          {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_with_query(&condition, IN, &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5011 "yacc_sql.tab.c"
    break;

  case 250: /* condition: expr NOT IN_T LBRACE sub_query RBRACE  */
#line 2524 "yacc_sql.y"
                                              {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-5].expr1);
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5022 "yacc_sql.tab.c"
    break;

  case 251: /* condition: expr comOp LBRACE sub_query RBRACE  */
#line 2531 "yacc_sql.y"
        {
		AstExpr *astExpr = (AstExpr *)(yyvsp[-4].expr1);
		Condition condition;
		condition_init_with_query(&condition, (yyvsp[-3].compOp1), &astExpr->attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 5033 "yacc_sql.tab.c"
    break;

  case 252: /* condition: LBRACE sub_query RBRACE NE LBRACE sub_query RBRACE  */
#line 2537 "yacc_sql.y"
                                                            {
		Condition condition;
		condition_init_with_two_query(&condition, NOT_EQUAL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1],CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-2]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 5043 "yacc_sql.tab.c"
    break;

  case 253: /* in_cells: value value_list  */
#line 2544 "yacc_sql.y"
                          {
	}
#line 5050 "yacc_sql.tab.c"
    break;

  case 254: /* reverseComp: EQ  */
#line 2548 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 5056 "yacc_sql.tab.c"
    break;

  case 255: /* reverseComp: LT  */
#line 2549 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 5062 "yacc_sql.tab.c"
    break;

  case 256: /* reverseComp: GT  */
#line 2550 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 5068 "yacc_sql.tab.c"
    break;

  case 257: /* reverseComp: LE  */
#line 2551 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 5074 "yacc_sql.tab.c"
    break;

  case 258: /* reverseComp: GE  */
#line 2552 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 5080 "yacc_sql.tab.c"
    break;

  case 259: /* reverseComp: NE  */
#line 2553 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 5086 "yacc_sql.tab.c"
    break;

  case 260: /* comOp: EQ  */
#line 2556 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; (yyval.compOp1) = EQUAL_TO; }
#line 5092 "yacc_sql.tab.c"
    break;

  case 261: /* comOp: LT  */
#line 2557 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; (yyval.compOp1) = LESS_THAN; }
#line 5098 "yacc_sql.tab.c"
    break;

  case 262: /* comOp: GT  */
#line 2558 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; (yyval.compOp1) = GREAT_THAN; }
#line 5104 "yacc_sql.tab.c"
    break;

  case 263: /* comOp: LE  */
#line 2559 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; (yyval.compOp1) = LESS_EQUAL; }
#line 5110 "yacc_sql.tab.c"
    break;

  case 264: /* comOp: GE  */
#line 2560 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; (yyval.compOp1) = GREAT_EQUAL; }
#line 5116 "yacc_sql.tab.c"
    break;

  case 265: /* comOp: NE  */
#line 2561 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; (yyval.compOp1) = NOT_EQUAL; }
#line 5122 "yacc_sql.tab.c"
    break;

  case 266: /* comOp: LIKE  */
#line 2562 "yacc_sql.y"
               { CONTEXT->comp = LIKE_TO; (yyval.compOp1) = LIKE_TO; }
#line 5128 "yacc_sql.tab.c"
    break;

  case 267: /* comOp: NOT LIKE  */
#line 2563 "yacc_sql.y"
                   { CONTEXT->comp = NOT_LIKE; (yyval.compOp1) = NOT_LIKE; }
#line 5134 "yacc_sql.tab.c"
    break;

  case 268: /* comOp: IS NOT  */
#line 2564 "yacc_sql.y"
                 { CONTEXT->comp = COMP_IS_NOT; (yyval.compOp1) = COMP_IS_NOT; }
#line 5140 "yacc_sql.tab.c"
    break;

  case 269: /* comOp: IS  */
#line 2565 "yacc_sql.y"
             { CONTEXT->comp = COMP_IS; (yyval.compOp1) = COMP_IS; }
#line 5146 "yacc_sql.tab.c"
    break;

  case 270: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 2570 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 5155 "yacc_sql.tab.c"
    break;


#line 5159 "yacc_sql.tab.c"

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

#line 2575 "yacc_sql.y"

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
