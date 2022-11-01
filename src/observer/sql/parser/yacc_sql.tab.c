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
  YYSYMBOL_dummy = 97,                     /* dummy  */
  YYSYMBOL_insert = 98,                    /* insert  */
  YYSYMBOL_record_list = 99,               /* record_list  */
  YYSYMBOL_record = 100,                   /* record  */
  YYSYMBOL_value_list = 101,               /* value_list  */
  YYSYMBOL_value = 102,                    /* value  */
  YYSYMBOL_delete = 103,                   /* delete  */
  YYSYMBOL_update = 104,                   /* update  */
  YYSYMBOL_update_attr_list = 105,         /* update_attr_list  */
  YYSYMBOL_update_attr = 106,              /* update_attr  */
  YYSYMBOL_update_select_attr = 107,       /* update_select_attr  */
  YYSYMBOL_update_agg = 108,               /* update_agg  */
  YYSYMBOL_select = 109,                   /* select  */
  YYSYMBOL_order_by = 110,                 /* order_by  */
  YYSYMBOL_order_item = 111,               /* order_item  */
  YYSYMBOL_order = 112,                    /* order  */
  YYSYMBOL_order_item_list = 113,          /* order_item_list  */
  YYSYMBOL_sub_query = 114,                /* sub_query  */
  YYSYMBOL_join_list = 115,                /* join_list  */
  YYSYMBOL_join_cons = 116,                /* join_cons  */
  YYSYMBOL_agg_fun_list_head = 117,        /* agg_fun_list_head  */
  YYSYMBOL_agg_fun_list = 118,             /* agg_fun_list  */
  YYSYMBOL_select_attr = 119,              /* select_attr  */
  YYSYMBOL_attr_list = 120,                /* attr_list  */
  YYSYMBOL_rel_list = 121,                 /* rel_list  */
  YYSYMBOL_where = 122,                    /* where  */
  YYSYMBOL_condition_list = 123,           /* condition_list  */
  YYSYMBOL_condition = 124,                /* condition  */
  YYSYMBOL_in_cells = 125,                 /* in_cells  */
  YYSYMBOL_reverseComp = 126,              /* reverseComp  */
  YYSYMBOL_comOp = 127,                    /* comOp  */
  YYSYMBOL_load_data = 128                 /* load_data  */
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
#define YYLAST   720

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  241
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  684

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
       0,   165,   165,   167,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   192,   197,   202,   208,   214,   220,   226,   232,
     238,   246,   253,   258,   265,   267,   271,   278,   285,   294,
     296,   300,   311,   322,   333,   344,   355,   368,   371,   372,
     373,   374,   375,   378,   385,   391,   401,   402,   407,   408,
     413,   414,   419,   422,   425,   429,   433,   439,   449,   457,
     459,   463,   469,   477,   488,   493,   498,   503,   511,   516,
     521,   526,   531,   536,   541,   546,   551,   556,   561,   570,
     583,   596,   606,   617,   628,   638,   649,   660,   662,   666,
     671,   679,   682,   685,   690,   692,   695,   716,   736,   756,
     776,   795,   814,   833,   855,   878,   897,   917,   936,   956,
     975,   994,  1016,  1039,  1059,  1079,  1099,  1119,  1139,  1159,
    1184,  1186,  1191,  1196,  1201,  1206,  1212,  1218,  1224,  1230,
    1236,  1242,  1249,  1256,  1263,  1270,  1276,  1282,  1289,  1296,
    1303,  1311,  1313,  1318,  1323,  1329,  1335,  1341,  1347,  1353,
    1359,  1365,  1371,  1377,  1383,  1389,  1395,  1401,  1407,  1413,
    1423,  1429,  1435,  1440,  1445,  1451,  1458,  1460,  1466,  1472,
    1478,  1485,  1493,  1495,  1498,  1502,  1507,  1509,  1512,  1514,
    1518,  1530,  1540,  1560,  1582,  1603,  1613,  1624,  1630,  1636,
    1643,  1651,  1659,  1667,  1674,  1681,  1688,  1695,  1703,  1711,
    1719,  1727,  1735,  1743,  1751,  1759,  1767,  1775,  1783,  1791,
    1798,  1802,  1803,  1804,  1805,  1806,  1807,  1810,  1811,  1812,
    1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,
    1823,  1827
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
  "dummy", "insert", "record_list", "record", "value_list", "value",
  "delete", "update", "update_attr_list", "update_attr",
  "update_select_attr", "update_agg", "select", "order_by", "order_item",
  "order", "order_item_list", "sub_query", "join_list", "join_cons",
  "agg_fun_list_head", "agg_fun_list", "select_attr", "attr_list",
  "rel_list", "where", "condition_list", "condition", "in_cells",
  "reverseComp", "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-423)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -423,   261,  -423,     3,   138,    -2,   -63,    90,     9,     1,
      10,   -26,    56,    85,  -423,   101,   107,   174,   102,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,   116,   172,
     255,   198,   215,   251,   268,   274,   277,   284,   195,   259,
     264,   267,   304,   306,   271,  -423,   249,   285,   313,  -423,
    -423,  -423,  -423,  -423,   308,   336,   331,   301,   386,   388,
     -40,   323,   329,   330,   332,   333,   -39,   335,  -423,  -423,
     338,   341,  -423,  -423,   342,   367,   376,   348,   354,   357,
     358,   389,  -423,  -423,   414,   416,   417,   418,   419,   420,
     206,     5,   259,   259,   115,     6,   436,   423,    47,   438,
     392,   424,   407,  -423,   426,   283,   430,   379,     7,    21,
      88,    92,    98,   113,   -30,   380,  -423,   381,  -423,  -423,
    -423,   382,   376,   450,   390,   394,   409,   442,   376,  -423,
     347,   445,   448,   449,   411,  -423,  -423,  -423,  -423,   269,
    -423,   280,   427,  -423,    69,   348,   376,   459,   357,   452,
    -423,  -423,  -423,  -423,  -423,   114,   399,   454,   321,   403,
     455,  -423,   404,   455,  -423,   408,   455,  -423,   412,   455,
    -423,   413,   455,  -423,   415,   455,  -423,    31,   259,   259,
     259,   376,   473,  -423,   122,   442,   421,   376,   422,   461,
     423,   475,   235,   465,   448,   468,   425,   470,   471,   472,
     474,   476,   478,  -423,   479,  -423,   316,   433,   231,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,   326,   310,    47,  -423,
     488,  -423,   424,   495,   432,   426,   496,   437,   441,  -423,
    -423,   485,   399,   489,   492,   493,   494,   497,   455,  -423,
     455,  -423,   455,  -423,   455,  -423,   455,  -423,   455,  -423,
     443,  -423,  -423,  -423,  -423,   502,  -423,   444,   442,  -423,
     376,   477,   512,   451,   514,   347,   501,   445,  -423,   503,
     505,   506,   507,   509,   147,   369,   510,   448,   309,   448,
     448,   448,   448,   448,   448,    28,  -423,   513,  -423,  -423,
    -423,  -423,  -423,   491,  -423,   427,    33,  -423,  -423,   526,
    -423,  -423,  -423,   515,  -423,   399,   516,   485,   149,   466,
     469,   481,   482,  -423,  -423,  -423,  -423,  -423,  -423,   259,
    -423,   442,  -423,   534,    47,  -423,   483,  -423,   461,  -423,
    -423,   150,   486,   499,   508,   511,   517,   518,  -423,  -423,
    -423,  -423,  -423,   523,   519,  -423,   525,   524,   527,   530,
     531,   537,   540,   541,   373,   319,   542,   543,   545,   546,
     548,   552,   461,   554,   556,    28,   520,  -423,   558,   559,
     561,   562,   564,   547,  -423,   551,   553,  -423,   210,   485,
     579,   566,   567,   573,   575,   576,   577,   578,  -423,  -423,
    -423,   555,   427,   199,   580,  -423,   565,   584,   568,   569,
     570,   571,   572,   123,   448,  -423,  -423,   448,   448,   448,
     448,   448,   448,   448,   581,   574,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,   585,   590,  -423,   214,
     528,   544,   549,   550,   221,   557,   560,   563,  -423,  -423,
    -423,   606,   139,   146,   155,   159,   160,   170,   582,   376,
    -423,  -423,  -423,   583,  -423,   483,  -423,   586,   588,   587,
     589,   591,   592,   593,   594,   442,  -423,   596,   597,   598,
     599,   602,   603,   604,   605,    28,   595,  -423,  -423,   157,
     607,   177,   209,   244,   246,  -423,  -423,   376,   376,  -423,
    -423,   600,   455,  -423,   601,   455,  -423,   608,   455,  -423,
     609,   455,  -423,   610,   455,  -423,   611,   455,  -423,   612,
     627,   222,   580,   613,   614,   615,   616,   617,   618,   175,
     442,  -423,   376,  -423,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,   619,   620,  -423,  -423,   621,  -423,  -423,   622,  -423,
     623,  -423,   624,  -423,   625,   626,   628,   455,  -423,   455,
    -423,   455,  -423,   455,  -423,   455,  -423,   455,  -423,   629,
    -423,  -423,  -423,   632,    -6,   633,   635,   636,   637,   630,
     442,  -423,  -423,   376,  -423,  -423,  -423,   631,   639,   641,
     647,   648,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,
      47,   634,   638,  -423,   376,   640,   642,   643,   644,   442,
    -423,   376,   376,  -423,  -423,  -423,  -423,  -423,  -423,   555,
       0,  -423,   376,  -423,     4,    12,    51,   121,  -423,   376,
    -423,  -423,  -423,   645,  -423,   376,   376,  -423,   646,  -423,
     376,   649,  -423,   376,   650,  -423,   376,   651,  -423,   376,
     376,  -423,  -423,   376,  -423,  -423,  -423,   376,  -423,  -423,
     376,  -423,  -423,   376,  -423,  -423,   376,  -423,  -423,   376,
    -423,   376,  -423,   376,  -423,   376,  -423,   376,  -423,  -423,
    -423,  -423,  -423,  -423
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     3,
      21,    20,    15,    16,    17,    18,     9,    10,    11,    12,
      13,    14,     8,     5,     7,     6,     4,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,   176,
       0,     0,     0,     0,     0,    24,     0,     0,     0,    25,
      26,    27,    23,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   171,   170,
       0,     0,    31,    29,     0,     0,   186,     0,     0,     0,
       0,     0,    28,    37,     0,     0,     0,     0,     0,     0,
     176,   176,   176,   176,   186,   182,     0,    58,     0,     0,
       0,    69,     0,    53,    39,     0,     0,     0,   151,   151,
     151,   151,   151,   151,     0,     0,   177,     0,   172,   173,
     174,     0,   186,     0,     0,     0,     0,   182,   186,    30,
       0,    56,     0,     0,     0,    66,    62,    63,    64,     0,
      65,     0,   188,    67,     0,     0,   186,     0,     0,     0,
      48,    51,    52,    49,    50,    44,     0,     0,     0,     0,
     151,   134,     0,   151,   133,     0,   151,   135,     0,   151,
     136,     0,   151,   138,     0,   151,   137,   176,   176,   176,
     176,   186,     0,    91,   182,   182,     0,   186,    97,    60,
      58,     0,     0,     0,     0,     0,     0,   227,   228,   229,
     230,   231,   232,   237,   234,   233,     0,   240,     0,   227,
     228,   229,   230,   231,   232,   234,     0,     0,     0,   187,
       0,    71,    69,     0,     0,    39,     0,     0,     0,    46,
      36,    34,     0,     0,     0,     0,     0,     0,   151,   146,
     151,   145,   151,   147,   151,   148,   151,   150,   151,   149,
       0,   178,   179,   180,   175,     0,    96,     0,   182,   183,
     186,     0,     0,     0,     0,     0,     0,    56,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,   235,   238,   239,
     192,   190,   235,   193,   191,   188,     0,    70,    68,     0,
      40,    38,    47,     0,    45,     0,     0,    34,     0,     0,
       0,     0,     0,   140,   139,   141,   142,   144,   143,   176,
      94,   182,   185,     0,     0,    95,     0,    90,    60,    59,
      57,     0,     0,     0,     0,     0,     0,     0,   221,   222,
     223,   224,   225,   226,     0,   197,     0,   227,   228,   229,
     230,   231,   232,   234,     0,     0,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,   189,     0,     0,
       0,     0,     0,    75,    74,     0,     0,   241,    41,    34,
       0,     0,     0,     0,     0,     0,     0,     0,   181,   184,
      93,   130,   188,   101,   104,    61,     0,     0,     0,     0,
       0,     0,     0,   182,     0,   199,   198,     0,     0,     0,
       0,     0,     0,     0,   235,     0,   194,   207,   208,   209,
     210,   211,   212,   220,   203,   200,     0,     0,   195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    35,
      32,     0,   151,   151,   151,   151,   151,   151,     0,   186,
     132,   103,   102,     0,    99,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,   182,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   201,     0,
       0,     0,     0,     0,     0,    76,    77,   186,   186,    42,
      33,     0,   151,   153,     0,   151,   152,     0,   151,   154,
       0,   151,   155,     0,   151,   157,     0,   151,   156,     0,
       0,   101,   104,     0,     0,     0,     0,     0,     0,   182,
     182,    54,   186,   219,   213,   214,   215,   216,   217,   218,
     204,     0,     0,   196,    79,     0,    78,    81,     0,    83,
       0,    87,     0,    85,     0,     0,     0,   151,   165,   151,
     164,   151,   166,   151,   167,   151,   169,   151,   168,     0,
      92,   100,   105,     0,    54,     0,     0,     0,     0,     0,
     182,    54,    54,   186,   107,   206,   202,     0,     0,     0,
       0,     0,    72,    73,   159,   158,   160,   161,   163,   162,
       0,     0,     0,    54,   186,     0,     0,     0,     0,   182,
      54,   186,   186,   123,    80,    82,    84,    88,    86,   130,
      54,    54,   186,   108,    54,    54,    54,    54,    54,   186,
     106,   115,   131,     0,    54,   186,   186,   124,     0,    54,
     186,     0,    54,   186,     0,    54,   186,     0,    54,   186,
     186,   122,    54,   186,   109,   116,    54,   186,   110,    54,
     186,   111,    54,   186,   113,    54,   186,   112,   114,   186,
     125,   186,   126,   186,   127,   186,   129,   186,   128,   117,
     118,   119,   121,   120
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  -423,  -310,  -237,  -423,  -423,   377,   484,
    -423,  -423,  -423,  -422,  -423,   355,   439,  -328,  -127,  -423,
    -423,   435,   490,  -423,  -423,  -423,  -423,   176,   119,   125,
    -168,    24,    48,  -423,  -105,  -423,   -18,  -134,  -104,  -301,
    -100,  -373,  -423,  -150,  -423
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   316,   241,    31,    32,   159,   114,
     313,   165,   115,   532,    33,   201,   141,   276,   151,    34,
      35,   156,   111,   385,   386,    36,   274,   404,   464,   466,
     203,   459,   401,    50,   171,    51,    78,   138,   109,   229,
     402,   374,   354,   218,    37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     133,   227,   437,   197,   377,   317,    52,   391,   152,    38,
     405,    39,    55,   199,   174,   177,   180,   183,   186,    43,
      44,    45,    46,    47,    75,   134,   168,   231,   192,    94,
     101,    79,    95,   102,   198,   602,   286,   202,    56,   187,
     168,   633,   188,    58,   433,   638,   127,   135,   169,    57,
      75,   136,   233,   641,   378,   379,   380,   381,   382,    59,
     269,   270,   172,   603,   142,   249,    40,    48,   251,   634,
      49,   253,   260,   639,   255,   137,   170,   257,   389,   449,
     259,   642,   126,   128,   129,   130,   230,   265,    60,   145,
     173,   301,   644,   272,   146,   147,   148,    53,    54,   150,
     304,   460,   383,   143,    61,   384,   144,   168,   145,   583,
      62,   168,   542,   146,   147,   148,   149,   168,   150,   356,
     645,   366,   367,   368,   369,   370,   371,   373,   305,   175,
     145,   237,   168,   178,   332,   146,   147,   148,   365,   181,
     150,   134,   134,   323,    41,   324,    42,   325,   338,   326,
      64,   327,   604,   328,   184,   108,   131,   176,   168,   611,
     612,   179,   647,   267,   474,   168,   333,   182,   372,   261,
     262,   263,   264,   238,   168,   544,   239,    63,   168,   168,
     501,   622,   185,   346,   132,    65,   347,   504,   629,   168,
     648,   268,   475,   545,   134,   547,   507,   399,   635,   636,
     510,   513,   640,   643,   646,   649,   650,   436,   502,   461,
     462,   516,   653,   548,    75,   505,   579,   657,   392,   406,
     660,   393,   407,   663,   508,    75,   666,   549,   511,   514,
     669,    76,   461,   462,   671,   463,    77,   673,   426,   517,
     675,    66,   124,   677,   580,   550,   477,   125,   372,   478,
     479,   480,   481,   482,   483,   484,   279,   280,   281,   282,
     283,     2,   551,    67,   553,     3,     4,    68,    70,   447,
       5,     6,   448,     7,     8,     9,    10,    11,    75,   476,
     552,    12,   554,   489,    69,    71,   490,    13,    14,    15,
     495,    72,   145,   496,    73,    16,    17,   146,   147,   148,
     300,    74,   150,    80,   284,   206,    81,    82,    18,    83,
      84,   398,   160,   161,   162,   163,   164,   541,    85,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     219,   220,   221,   222,   223,   224,   213,   225,   215,   226,
     217,   531,   243,   244,   245,   246,   247,   503,   506,   509,
     512,   515,   518,    89,    86,   520,    87,    88,   372,   357,
     358,   359,   360,   361,   362,   213,   363,   215,   364,   217,
      91,   145,   296,   297,   298,    90,   146,   147,   148,   303,
     145,   150,   296,   302,   298,   146,   147,   148,   425,    92,
     150,    93,    96,   555,   556,   581,   582,   558,    97,    98,
     560,    99,   100,   562,   103,   107,   564,   104,   145,   566,
     105,   106,   568,   146,   147,   148,   108,   110,   150,   348,
     349,   350,   351,   352,   353,   112,   113,   116,   584,   296,
     424,   298,   118,   117,   119,   120,   121,   122,   123,   139,
     140,   153,   154,   155,   157,   158,   610,   166,   167,   189,
     190,   191,   594,   193,   595,   196,   596,   202,   597,   194,
     598,   134,   599,   195,   200,   234,   204,   205,   240,   228,
     236,   242,   248,   250,   168,   628,   266,   252,   278,   613,
     275,   254,   256,   285,   258,   287,   273,   289,   290,   291,
     271,   292,   299,   293,   288,   294,   295,   306,   308,   311,
     623,   309,   314,   312,   315,   330,   318,   630,   631,   319,
     320,   321,   329,   331,   322,   335,   336,   337,   637,   339,
     341,   334,   342,   343,   344,   651,   345,   376,   355,   387,
     375,   654,   655,   388,   390,   394,   658,   400,   395,   661,
     414,   417,   664,   416,   418,   667,   668,   419,   420,   670,
     396,   397,   403,   672,   421,   408,   674,   422,   423,   676,
     427,   428,   678,   429,   430,   679,   431,   680,   409,   681,
     432,   682,   434,   683,   435,   439,   440,   410,   441,   442,
     411,   443,   450,   444,   451,   452,   412,   413,   415,   438,
     445,   453,   446,   454,   455,   456,   457,   491,   485,   465,
     458,   467,   468,   487,   469,   470,   471,   472,   488,   500,
     486,   473,   310,   492,   533,   534,   535,   536,   493,   494,
     537,   538,   539,   540,   499,   546,   497,   524,   519,   498,
     570,   573,   340,   575,   576,   577,   578,   585,   586,   277,
     571,   522,   235,   632,   592,   232,   593,   572,   619,   614,
       0,     0,   521,     0,     0,   523,   525,   615,   526,   616,
     527,   528,   529,   530,   543,   617,   618,   307,     0,   557,
     559,   601,   605,   600,   606,   607,   608,   561,   563,   565,
     567,   569,     0,   574,     0,     0,     0,     0,     0,     0,
     587,   588,   589,   590,   591,     0,     0,     0,     0,   609,
       0,     0,     0,   620,     0,     0,     0,   621,     0,   624,
       0,   625,   626,   627,   652,   656,     0,     0,   659,   662,
     665
};

static const yytype_int16 yycheck[] =
{
     104,   151,   375,   137,   305,   242,    69,   317,   108,     6,
     338,     8,     3,   140,   119,   120,   121,   122,   123,    21,
      22,    23,    24,    25,    19,    19,    19,   154,   132,    69,
      69,    49,    72,    72,   138,    41,   204,     9,    37,    69,
      19,    41,    72,    69,   372,    41,    41,    41,    41,    39,
      19,    45,   156,    41,    21,    22,    23,    24,    25,     3,
     194,   195,    41,    69,    17,   170,    63,    69,   173,    69,
      72,   176,    41,    69,   179,    69,    69,   182,   315,   389,
     185,    69,   100,   101,   102,   103,    17,   191,     3,    61,
      69,   218,    41,   197,    66,    67,    68,     7,     8,    71,
     227,   402,    69,    56,     3,    72,    59,    19,    61,   531,
       3,    19,   485,    66,    67,    68,    69,    19,    71,   287,
      69,   289,   290,   291,   292,   293,   294,   295,   228,    41,
      61,    17,    19,    41,   268,    66,    67,    68,   288,    41,
      71,    19,    19,   248,     6,   250,     8,   252,   275,   254,
      48,   256,   574,   258,    41,    40,    41,    69,    19,   581,
     582,    69,    41,    41,    41,    19,   270,    69,   295,   187,
     188,   189,   190,    59,    19,    18,    62,     3,    19,    19,
      41,   603,    69,    36,    69,    69,    39,    41,   610,    19,
      69,    69,    69,    36,    19,    18,    41,   331,   620,   621,
      41,    41,   624,   625,   626,   627,   628,   375,    69,    10,
      11,    41,   634,    36,    19,    69,    41,   639,    69,    69,
     642,    72,    72,   645,    69,    19,   648,    18,    69,    69,
     652,    36,    10,    11,   656,    36,    41,   659,   365,    69,
     662,    69,    36,   665,    69,    36,   414,    41,   375,   417,
     418,   419,   420,   421,   422,   423,    21,    22,    23,    24,
      25,     0,    18,     8,    18,     4,     5,    69,    17,    59,
       9,    10,    62,    12,    13,    14,    15,    16,    19,   413,
      36,    20,    36,    69,    69,    17,    72,    26,    27,    28,
      69,    17,    61,    72,    17,    34,    35,    66,    67,    68,
      69,    17,    71,    39,    69,    36,    39,     3,    47,     3,
      39,   329,    29,    30,    31,    32,    33,   485,    69,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,   475,    21,    22,    23,    24,    25,   452,   453,   454,
     455,   456,   457,    17,    69,   459,    43,    49,   485,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      69,    61,    56,    57,    58,    44,    66,    67,    68,    69,
      61,    71,    56,    57,    58,    66,    67,    68,    69,     3,
      71,     3,    69,   497,   498,   529,   530,   502,    69,    69,
     505,    69,    69,   508,    69,    38,   511,    69,    61,   514,
      69,    69,   517,    66,    67,    68,    40,    69,    71,    50,
      51,    52,    53,    54,    55,    71,    69,    69,   532,    56,
      57,    58,    18,    44,    18,    18,    18,    18,    18,     3,
      17,     3,    50,    19,    37,    19,   580,    17,    69,    69,
      69,    69,   557,     3,   559,    46,   561,     9,   563,    69,
     565,    19,   567,    69,    19,     6,    17,    56,    69,    42,
      18,    17,    69,    69,    19,   609,     3,    69,     3,   583,
      19,    69,    69,    18,    69,    17,    64,    17,    17,    17,
      69,    17,    59,    17,    69,    17,    17,     9,     3,     3,
     604,    69,    61,    66,    19,     3,    17,   611,   612,    17,
      17,    17,    69,    69,    17,     3,    65,     3,   622,    18,
      17,    44,    17,    17,    17,   629,    17,    36,    18,     3,
      17,   635,   636,    18,    18,    69,   640,     3,    69,   643,
      17,    17,   646,    18,    17,   649,   650,    17,    17,   653,
      69,    69,    69,   657,    17,    69,   660,    17,    17,   663,
      18,    18,   666,    18,    18,   669,    18,   671,    69,   673,
      18,   675,    18,   677,    18,    17,    17,    69,    17,    17,
      69,    17,     3,    36,    18,    18,    69,    69,    69,    69,
      39,    18,    39,    18,    18,    18,    18,    69,    17,    19,
      45,    36,    18,    18,    36,    36,    36,    36,    18,     3,
      36,    39,   235,    69,    18,    18,    18,    18,    69,    69,
      18,    18,    18,    18,    61,    18,    69,    39,    46,    69,
       3,    18,   277,    18,    18,    18,    18,    18,    18,   200,
     521,   465,   158,   619,    18,   155,    18,   522,   600,    18,
      -1,    -1,    69,    -1,    -1,    69,    69,    18,    69,    18,
      69,    69,    69,    69,    69,    18,    18,   232,    -1,    69,
      69,    39,    39,    44,    39,    39,    39,    69,    69,    69,
      69,    69,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    69,    69,    69,    69,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    69,    -1,    69,
      -1,    69,    69,    69,    69,    69,    -1,    -1,    69,    69,
      69
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,     0,     4,     5,     9,    10,    12,    13,    14,
      15,    16,    20,    26,    27,    28,    34,    35,    47,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    90,    91,    98,   103,   104,   109,   128,     6,     8,
      63,     6,     8,    21,    22,    23,    24,    25,    69,    72,
     117,   119,    69,     7,     8,     3,    37,    39,    69,     3,
       3,     3,     3,     3,    48,    69,    69,     8,    69,    69,
      17,    17,    17,    17,    17,    19,    36,    41,   120,   120,
      39,    39,     3,     3,    39,    69,    69,    43,    49,    17,
      44,    69,     3,     3,    69,    72,    69,    69,    69,    69,
      69,    69,    72,    69,    69,    69,    69,    38,    40,   122,
      69,   106,    71,    69,    93,    96,    69,    44,    18,    18,
      18,    18,    18,    18,    36,    41,   120,    41,   120,   120,
     120,    41,    69,   122,    19,    41,    45,    69,   121,     3,
      17,   100,    17,    56,    59,    61,    66,    67,    68,    69,
      71,   102,   124,     3,    50,    19,   105,    37,    19,    92,
      29,    30,    31,    32,    33,    95,    17,    69,    19,    41,
      69,   118,    41,    69,   118,    41,    69,   118,    41,    69,
     118,    41,    69,   118,    41,    69,   118,    69,    72,    69,
      69,    69,   122,     3,    69,    69,    46,   121,   122,   102,
      19,    99,     9,   114,    17,    56,    36,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,   127,    50,
      51,    52,    53,    54,    55,    57,    59,   127,    42,   123,
      17,   102,   106,   122,     6,    93,    18,    17,    59,    62,
      69,    89,    17,    21,    22,    23,    24,    25,    69,   118,
      69,   118,    69,   118,    69,   118,    69,   118,    69,   118,
      41,   120,   120,   120,   120,   122,     3,    41,    69,   121,
     121,    69,   122,    64,   110,    19,   101,   100,     3,    21,
      22,    23,    24,    25,    69,    18,   114,    17,    69,    17,
      17,    17,    17,    17,    17,    17,    56,    57,    58,    59,
      69,   102,    57,    69,   102,   124,     9,   105,     3,    69,
      92,     3,    66,    94,    61,    19,    88,    89,    17,    17,
      17,    17,    17,   118,   118,   118,   118,   118,   118,    69,
       3,    69,   121,   122,    44,     3,    65,     3,   102,    18,
      99,    17,    17,    17,    17,    17,    36,    39,    50,    51,
      52,    53,    54,    55,   126,    18,   114,    50,    51,    52,
      53,    54,    55,    57,    59,   127,   114,   114,   114,   114,
     114,   114,   102,   114,   125,    17,    36,   123,    21,    22,
      23,    24,    25,    69,    72,   107,   108,     3,    18,    89,
      18,    88,    69,    72,    69,    69,    69,    69,   120,   121,
       3,   116,   124,    69,   111,   101,    69,    72,    69,    69,
      69,    69,    69,    69,    17,    69,    18,    17,    17,    17,
      17,    17,    17,    17,    57,    69,   102,    18,    18,    18,
      18,    18,    18,   101,    18,    18,   114,   125,    69,    17,
      17,    17,    17,    17,    36,    39,    39,    59,    62,    88,
       3,    18,    18,    18,    18,    18,    18,    18,    45,   115,
     123,    10,    11,    36,   112,    19,   113,    36,    18,    36,
      36,    36,    36,    39,    41,    69,   121,   114,   114,   114,
     114,   114,   114,   114,   114,    17,    36,    18,    18,    69,
      72,    69,    69,    69,    69,    69,    72,    69,    69,    61,
       3,    41,    69,   118,    41,    69,   118,    41,    69,   118,
      41,    69,   118,    41,    69,   118,    41,    69,   118,    46,
     122,    69,   111,    69,    39,    69,    69,    69,    69,    69,
      69,   121,    97,    18,    18,    18,    18,    18,    18,    18,
      18,   114,   125,    69,    18,    36,    18,    18,    36,    18,
      36,    18,    36,    18,    36,   122,   122,    69,   118,    69,
     118,    69,   118,    69,   118,    69,   118,    69,   118,    69,
       3,   112,   113,    18,    69,    18,    18,    18,    18,    41,
      69,   121,   121,    97,   122,    18,    18,    69,    69,    69,
      69,    69,    18,    18,   118,   118,   118,   118,   118,   118,
      44,    39,    41,    69,    97,    39,    39,    39,    39,    69,
     121,    97,    97,   122,    18,    18,    18,    18,    18,   116,
      69,    69,    97,   122,    69,    69,    69,    69,   121,    97,
     122,   122,   115,    41,    69,    97,    97,   122,    41,    69,
      97,    41,    69,    97,    41,    69,    97,    41,    69,    97,
      97,   122,    69,    97,   122,   122,    69,    97,   122,    69,
      97,   122,    69,    97,   122,    69,    97,   122,   122,    97,
     122,    97,   122,    97,   122,    97,   122,    97,   122,   122,
     122,   122,   122,   122
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    87,    88,    88,    89,    90,    91,    92,
      92,    93,    93,    93,    93,    93,    93,    94,    95,    95,
      95,    95,    95,    96,    97,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   102,   102,   102,   103,   104,   105,
     105,   106,   106,   106,   107,   107,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   109,   110,   110,   111,
     111,   112,   112,   112,   113,   113,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   116,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     119,   119,   119,   119,   119,   119,   120,   120,   120,   120,
     120,   120,   121,   121,   121,   121,   122,   122,   123,   123,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     125,   126,   126,   126,   126,   126,   126,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   128
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
       8,     6,    12,     9,     8,     8,     7,     0,     4,     2,
       4,     0,     1,     1,     0,     3,     9,     7,     9,    11,
      11,    11,    11,    11,    11,     9,    11,    13,    13,    13,
      13,    13,    10,     8,    10,    12,    12,    12,    12,    12,
       0,     6,     2,     5,     5,     5,     5,     5,     5,     7,
       7,     7,     7,     7,     7,     6,     6,     6,     6,     6,
       6,     0,     6,     6,     6,     6,     6,     6,     8,     8,
       8,     8,     8,     8,     7,     7,     7,     7,     7,     7,
       2,     2,     4,     4,     4,     6,     0,     3,     5,     5,
       5,     7,     0,     3,     5,     4,     0,     3,     0,     3,
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
#line 192 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1703 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 197 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1711 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 202 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1719 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 208 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1727 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 214 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1735 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 220 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1743 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 226 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1752 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 232 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1760 "yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 238 "yacc_sql.y"
                                {
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
    }
#line 1769 "yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 246 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1778 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 254 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
		}
#line 1787 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 259 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
		}
#line 1796 "yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA index_attr index_attr_list  */
#line 267 "yacc_sql.y"
                                           { }
#line 1802 "yacc_sql.tab.c"
    break;

  case 36: /* index_attr: ID  */
#line 272 "yacc_sql.y"
                {
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
		}
#line 1810 "yacc_sql.tab.c"
    break;

  case 37: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 279 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1819 "yacc_sql.tab.c"
    break;

  case 38: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 286 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1831 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 296 "yacc_sql.y"
                                   {    }
#line 1837 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 301 "yacc_sql.y"
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
#line 1852 "yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type LBRACE number RBRACE NOT NULLL  */
#line 312 "yacc_sql.y"
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
#line 1867 "yacc_sql.tab.c"
    break;

  case 43: /* attr_def: ID_get type LBRACE number RBRACE NULLABLE  */
#line 323 "yacc_sql.y"
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
#line 1882 "yacc_sql.tab.c"
    break;

  case 44: /* attr_def: ID_get type  */
#line 334 "yacc_sql.y"
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
#line 1897 "yacc_sql.tab.c"
    break;

  case 45: /* attr_def: ID_get type NOT NULLL  */
#line 345 "yacc_sql.y"
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
#line 1912 "yacc_sql.tab.c"
    break;

  case 46: /* attr_def: ID_get type NULLABLE  */
#line 356 "yacc_sql.y"
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
#line 1927 "yacc_sql.tab.c"
    break;

  case 47: /* number: NUMBER  */
#line 368 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1933 "yacc_sql.tab.c"
    break;

  case 48: /* type: INT_T  */
#line 371 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1939 "yacc_sql.tab.c"
    break;

  case 49: /* type: DATE_T  */
#line 372 "yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 1945 "yacc_sql.tab.c"
    break;

  case 50: /* type: TEXT_T  */
#line 373 "yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 1951 "yacc_sql.tab.c"
    break;

  case 51: /* type: STRING_T  */
#line 374 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1957 "yacc_sql.tab.c"
    break;

  case 52: /* type: FLOAT_T  */
#line 375 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1963 "yacc_sql.tab.c"
    break;

  case 53: /* ID_get: ID  */
#line 379 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1972 "yacc_sql.tab.c"
    break;

  case 54: /* dummy: %empty  */
#line 385 "yacc_sql.y"
      {
		CONTEXT->depth++;
		CONTEXT->sub_con_start[CONTEXT->depth]=CONTEXT->condition_length;
	}
#line 1981 "yacc_sql.tab.c"
    break;

  case 55: /* insert: INSERT INTO ID VALUES record record_list SEMICOLON  */
#line 392 "yacc_sql.y"
        {
		CONTEXT->ssql->flag=SCF_INSERT;//"insert";
		CONTEXT->ssql->sstr.insertion.relation_name = (yyvsp[-4].string);
		CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
		inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-4].string), CONTEXT->values, CONTEXT->value_length,CONTEXT->single_record_length,CONTEXT->record_length);

      	CONTEXT->value_length=0;
	  	CONTEXT->record_length=0;
    }
#line 1995 "yacc_sql.tab.c"
    break;

  case 57: /* record_list: COMMA record record_list  */
#line 402 "yacc_sql.y"
                                        {

		}
#line 2003 "yacc_sql.tab.c"
    break;

  case 59: /* record: LBRACE value value_list RBRACE  */
#line 409 "yacc_sql.y"
                {
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		}
#line 2012 "yacc_sql.tab.c"
    break;

  case 61: /* value_list: COMMA value value_list  */
#line 414 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 2020 "yacc_sql.tab.c"
    break;

  case 62: /* value: NUMBER  */
#line 419 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 2028 "yacc_sql.tab.c"
    break;

  case 63: /* value: FLOAT  */
#line 422 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 2036 "yacc_sql.tab.c"
    break;

  case 64: /* value: DATEE  */
#line 425 "yacc_sql.y"
               {
			(yyvsp[0].dates) = substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].dates));
		}
#line 2045 "yacc_sql.tab.c"
    break;

  case 65: /* value: SSS  */
#line 429 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 2054 "yacc_sql.tab.c"
    break;

  case 66: /* value: NULLL  */
#line 433 "yacc_sql.y"
               {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		}
#line 2062 "yacc_sql.tab.c"
    break;

  case 67: /* delete: DELETE FROM ID where SEMICOLON  */
#line 440 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 2074 "yacc_sql.tab.c"
    break;

  case 68: /* update: UPDATE ID SET update_attr update_attr_list where SEMICOLON  */
#line 450 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2084 "yacc_sql.tab.c"
    break;

  case 71: /* update_attr: ID EQ value  */
#line 464 "yacc_sql.y"
                {
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			CONTEXT->value_length = 0;
		}
#line 2094 "yacc_sql.tab.c"
    break;

  case 72: /* update_attr: ID EQ LBRACE SELECT update_select_attr FROM ID where RBRACE  */
#line 470 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2106 "yacc_sql.tab.c"
    break;

  case 73: /* update_attr: ID EQ LBRACE SELECT update_agg FROM ID where RBRACE  */
#line 478 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 2118 "yacc_sql.tab.c"
    break;

  case 74: /* update_select_attr: STAR  */
#line 488 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2128 "yacc_sql.tab.c"
    break;

  case 75: /* update_select_attr: ID  */
#line 493 "yacc_sql.y"
         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2138 "yacc_sql.tab.c"
    break;

  case 76: /* update_select_attr: ID DOT ID  */
#line 498 "yacc_sql.y"
                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2148 "yacc_sql.tab.c"
    break;

  case 77: /* update_select_attr: ID DOT STAR  */
#line 503 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2158 "yacc_sql.tab.c"
    break;

  case 78: /* update_agg: COUNT_T LBRACE STAR RBRACE  */
#line 511 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
#line 2168 "yacc_sql.tab.c"
    break;

  case 79: /* update_agg: COUNT_T LBRACE ID RBRACE  */
#line 516 "yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2178 "yacc_sql.tab.c"
    break;

  case 80: /* update_agg: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 521 "yacc_sql.y"
                                          {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2188 "yacc_sql.tab.c"
    break;

  case 81: /* update_agg: MAX_T LBRACE ID RBRACE  */
#line 526 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2198 "yacc_sql.tab.c"
    break;

  case 82: /* update_agg: MAX_T LBRACE ID DOT ID RBRACE  */
#line 531 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2208 "yacc_sql.tab.c"
    break;

  case 83: /* update_agg: MIN_T LBRACE ID RBRACE  */
#line 536 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2218 "yacc_sql.tab.c"
    break;

  case 84: /* update_agg: MIN_T LBRACE ID DOT ID RBRACE  */
#line 541 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2228 "yacc_sql.tab.c"
    break;

  case 85: /* update_agg: SUM_T LBRACE ID RBRACE  */
#line 546 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2238 "yacc_sql.tab.c"
    break;

  case 86: /* update_agg: SUM_T LBRACE ID DOT ID RBRACE  */
#line 551 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2248 "yacc_sql.tab.c"
    break;

  case 87: /* update_agg: AVG_T LBRACE ID RBRACE  */
#line 556 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2258 "yacc_sql.tab.c"
    break;

  case 88: /* update_agg: AVG_T LBRACE ID DOT ID RBRACE  */
#line 561 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2268 "yacc_sql.tab.c"
    break;

  case 89: /* select: DABIAO  */
#line 570 "yacc_sql.y"
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
#line 2285 "yacc_sql.tab.c"
    break;

  case 90: /* select: SELECT select_attr FROM ID rel_list where order_by SEMICOLON  */
#line 583 "yacc_sql.y"
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
#line 2303 "yacc_sql.tab.c"
    break;

  case 91: /* select: SELECT agg_fun_list_head FROM ID where SEMICOLON  */
#line 596 "yacc_sql.y"
                                                          {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;

		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2318 "yacc_sql.tab.c"
    break;

  case 92: /* select: SELECT select_attr FROM ID INNER_T JOIN_T ID ON join_cons join_list where SEMICOLON  */
#line 606 "yacc_sql.y"
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
#line 2334 "yacc_sql.tab.c"
    break;

  case 93: /* select: SELECT select_attr FROM ID AS ID rel_list where SEMICOLON  */
#line 617 "yacc_sql.y"
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
#line 2350 "yacc_sql.tab.c"
    break;

  case 94: /* select: SELECT agg_fun_list_head FROM ID AS ID where SEMICOLON  */
#line 628 "yacc_sql.y"
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
#line 2365 "yacc_sql.tab.c"
    break;

  case 95: /* select: SELECT select_attr FROM ID ID rel_list where SEMICOLON  */
#line 638 "yacc_sql.y"
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
#line 2381 "yacc_sql.tab.c"
    break;

  case 96: /* select: SELECT agg_fun_list_head FROM ID ID where SEMICOLON  */
#line 649 "yacc_sql.y"
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
#line 2396 "yacc_sql.tab.c"
    break;

  case 99: /* order_item: ID order  */
#line 666 "yacc_sql.y"
                 {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, CONTEXT->order);
	}
#line 2406 "yacc_sql.tab.c"
    break;

  case 100: /* order_item: ID DOT ID order  */
#line 671 "yacc_sql.y"
                          {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		selects_append_order(&CONTEXT->ssql->sstr.selection, &attr, CONTEXT->order);
	}
#line 2416 "yacc_sql.tab.c"
    break;

  case 101: /* order: %empty  */
#line 679 "yacc_sql.y"
                    {
		CONTEXT->order = 0;
	}
#line 2424 "yacc_sql.tab.c"
    break;

  case 102: /* order: ASC  */
#line 682 "yacc_sql.y"
              {
		CONTEXT->order = 0;
	}
#line 2432 "yacc_sql.tab.c"
    break;

  case 103: /* order: DESC  */
#line 685 "yacc_sql.y"
               {
		CONTEXT->order = 1;
	}
#line 2440 "yacc_sql.tab.c"
    break;

  case 106: /* sub_query: SELECT ID DOT ID FROM ID rel_list dummy where  */
#line 695 "yacc_sql.y"
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
#line 2466 "yacc_sql.tab.c"
    break;

  case 107: /* sub_query: SELECT ID FROM ID rel_list dummy where  */
#line 716 "yacc_sql.y"
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
#line 2491 "yacc_sql.tab.c"
    break;

  case 108: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID dummy where  */
#line 736 "yacc_sql.y"
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
#line 2516 "yacc_sql.tab.c"
    break;

  case 109: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 756 "yacc_sql.y"
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
#line 2541 "yacc_sql.tab.c"
    break;

  case 110: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 776 "yacc_sql.y"
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
#line 2565 "yacc_sql.tab.c"
    break;

  case 111: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 795 "yacc_sql.y"
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
#line 2589 "yacc_sql.tab.c"
    break;

  case 112: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 814 "yacc_sql.y"
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
#line 2613 "yacc_sql.tab.c"
    break;

  case 113: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID dummy where  */
#line 833 "yacc_sql.y"
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
#line 2640 "yacc_sql.tab.c"
    break;

  case 114: /* sub_query: SELECT ID DOT ID FROM ID AS ID rel_list dummy where  */
#line 855 "yacc_sql.y"
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
#line 2668 "yacc_sql.tab.c"
    break;

  case 115: /* sub_query: SELECT ID FROM ID AS ID rel_list dummy where  */
#line 878 "yacc_sql.y"
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
#line 2692 "yacc_sql.tab.c"
    break;

  case 116: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID AS ID dummy where  */
#line 897 "yacc_sql.y"
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
#line 2717 "yacc_sql.tab.c"
    break;

  case 117: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 917 "yacc_sql.y"
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
#line 2741 "yacc_sql.tab.c"
    break;

  case 118: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 936 "yacc_sql.y"
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
#line 2766 "yacc_sql.tab.c"
    break;

  case 119: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 956 "yacc_sql.y"
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
#line 2790 "yacc_sql.tab.c"
    break;

  case 120: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 975 "yacc_sql.y"
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
#line 2814 "yacc_sql.tab.c"
    break;

  case 121: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID AS ID dummy where  */
#line 994 "yacc_sql.y"
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
#line 2841 "yacc_sql.tab.c"
    break;

  case 122: /* sub_query: SELECT ID DOT ID FROM ID ID rel_list dummy where  */
#line 1016 "yacc_sql.y"
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
#line 2869 "yacc_sql.tab.c"
    break;

  case 123: /* sub_query: SELECT ID FROM ID ID rel_list dummy where  */
#line 1039 "yacc_sql.y"
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
#line 2894 "yacc_sql.tab.c"
    break;

  case 124: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID ID dummy where  */
#line 1059 "yacc_sql.y"
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
#line 2919 "yacc_sql.tab.c"
    break;

  case 125: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1079 "yacc_sql.y"
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
#line 2944 "yacc_sql.tab.c"
    break;

  case 126: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1099 "yacc_sql.y"
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
#line 2969 "yacc_sql.tab.c"
    break;

  case 127: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1119 "yacc_sql.y"
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
#line 2994 "yacc_sql.tab.c"
    break;

  case 128: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1139 "yacc_sql.y"
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
#line 3019 "yacc_sql.tab.c"
    break;

  case 129: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID ID dummy where  */
#line 1159 "yacc_sql.y"
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
#line 3047 "yacc_sql.tab.c"
    break;

  case 131: /* join_list: INNER_T JOIN_T ID ON join_cons join_list  */
#line 1186 "yacc_sql.y"
                                               {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
	}
#line 3055 "yacc_sql.tab.c"
    break;

  case 132: /* join_cons: condition condition_list  */
#line 1191 "yacc_sql.y"
                                  {	
	}
#line 3062 "yacc_sql.tab.c"
    break;

  case 133: /* agg_fun_list_head: COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 1196 "yacc_sql.y"
                                                {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 3072 "yacc_sql.tab.c"
    break;

  case 134: /* agg_fun_list_head: COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 1201 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 3082 "yacc_sql.tab.c"
    break;

  case 135: /* agg_fun_list_head: MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 1206 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3093 "yacc_sql.tab.c"
    break;

  case 136: /* agg_fun_list_head: MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 1212 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3104 "yacc_sql.tab.c"
    break;

  case 137: /* agg_fun_list_head: SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 1218 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3115 "yacc_sql.tab.c"
    break;

  case 138: /* agg_fun_list_head: AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 1224 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3126 "yacc_sql.tab.c"
    break;

  case 139: /* agg_fun_list_head: COUNT_T LBRACE STAR RBRACE AS ID agg_fun_list  */
#line 1230 "yacc_sql.y"
                                                       {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3137 "yacc_sql.tab.c"
    break;

  case 140: /* agg_fun_list_head: COUNT_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1236 "yacc_sql.y"
                                                    {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3148 "yacc_sql.tab.c"
    break;

  case 141: /* agg_fun_list_head: MAX_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1242 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
#line 3160 "yacc_sql.tab.c"
    break;

  case 142: /* agg_fun_list_head: MIN_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1249 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
#line 3172 "yacc_sql.tab.c"
    break;

  case 143: /* agg_fun_list_head: SUM_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1256 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
	
		CONTEXT->select_length++;
	  }
#line 3184 "yacc_sql.tab.c"
    break;

  case 144: /* agg_fun_list_head: AVG_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1263 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		
		CONTEXT->select_length++;
	  }
#line 3196 "yacc_sql.tab.c"
    break;

  case 145: /* agg_fun_list_head: COUNT_T LBRACE STAR RBRACE ID agg_fun_list  */
#line 1270 "yacc_sql.y"
                                                     {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3207 "yacc_sql.tab.c"
    break;

  case 146: /* agg_fun_list_head: COUNT_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1276 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3218 "yacc_sql.tab.c"
    break;

  case 147: /* agg_fun_list_head: MAX_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1282 "yacc_sql.y"
                                                 {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
#line 3230 "yacc_sql.tab.c"
    break;

  case 148: /* agg_fun_list_head: MIN_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1289 "yacc_sql.y"
                                                 {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);

		CONTEXT->select_length++;
	  }
#line 3242 "yacc_sql.tab.c"
    break;

  case 149: /* agg_fun_list_head: SUM_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1296 "yacc_sql.y"
                                                 {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
	
		CONTEXT->select_length++;
	  }
#line 3254 "yacc_sql.tab.c"
    break;

  case 150: /* agg_fun_list_head: AVG_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1303 "yacc_sql.y"
                                                 {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		
		CONTEXT->select_length++;
	  }
#line 3266 "yacc_sql.tab.c"
    break;

  case 152: /* agg_fun_list: COMMA COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 1313 "yacc_sql.y"
                                                      {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 3276 "yacc_sql.tab.c"
    break;

  case 153: /* agg_fun_list: COMMA COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 1318 "yacc_sql.y"
                                                    {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 3286 "yacc_sql.tab.c"
    break;

  case 154: /* agg_fun_list: COMMA MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 1323 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3297 "yacc_sql.tab.c"
    break;

  case 155: /* agg_fun_list: COMMA MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 1329 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre,MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3308 "yacc_sql.tab.c"
    break;

  case 156: /* agg_fun_list: COMMA SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 1335 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3319 "yacc_sql.tab.c"
    break;

  case 157: /* agg_fun_list: COMMA AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 1341 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3330 "yacc_sql.tab.c"
    break;

  case 158: /* agg_fun_list: COMMA COUNT_T LBRACE STAR RBRACE AS ID agg_fun_list  */
#line 1347 "yacc_sql.y"
                                                             {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3341 "yacc_sql.tab.c"
    break;

  case 159: /* agg_fun_list: COMMA COUNT_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1353 "yacc_sql.y"
                                                          {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3352 "yacc_sql.tab.c"
    break;

  case 160: /* agg_fun_list: COMMA MAX_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1359 "yacc_sql.y"
                                                         {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3363 "yacc_sql.tab.c"
    break;

  case 161: /* agg_fun_list: COMMA MIN_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1365 "yacc_sql.y"
                                                         {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3374 "yacc_sql.tab.c"
    break;

  case 162: /* agg_fun_list: COMMA SUM_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1371 "yacc_sql.y"
                                                         {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3385 "yacc_sql.tab.c"
    break;

  case 163: /* agg_fun_list: COMMA AVG_T LBRACE ID RBRACE AS ID agg_fun_list  */
#line 1377 "yacc_sql.y"
                                                         {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-4].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3396 "yacc_sql.tab.c"
    break;

  case 164: /* agg_fun_list: COMMA COUNT_T LBRACE STAR RBRACE ID agg_fun_list  */
#line 1383 "yacc_sql.y"
                                                           {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT_STAR,"*",(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3407 "yacc_sql.tab.c"
    break;

  case 165: /* agg_fun_list: COMMA COUNT_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1389 "yacc_sql.y"
                                                        {
		AggFun aggre;
		Init_AggFun1(&aggre,COUNT,(yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);

	}
#line 3418 "yacc_sql.tab.c"
    break;

  case 166: /* agg_fun_list: COMMA MAX_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1395 "yacc_sql.y"
                                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MAX, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3429 "yacc_sql.tab.c"
    break;

  case 167: /* agg_fun_list: COMMA MIN_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1401 "yacc_sql.y"
                                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, MIN, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3440 "yacc_sql.tab.c"
    break;

  case 168: /* agg_fun_list: COMMA SUM_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1407 "yacc_sql.y"
                                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, SUM, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3451 "yacc_sql.tab.c"
    break;

  case 169: /* agg_fun_list: COMMA AVG_T LBRACE ID RBRACE ID agg_fun_list  */
#line 1413 "yacc_sql.y"
                                                       {
		AggFun aggre;
		Init_AggFun1(&aggre, AVG, (yyvsp[-3].string),(yyvsp[-1].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 3462 "yacc_sql.tab.c"
    break;

  case 170: /* select_attr: STAR attr_list  */
#line 1423 "yacc_sql.y"
                   {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			CONTEXT->ssql->sstr.selection.need_Revere=1;
		}
#line 3473 "yacc_sql.tab.c"
    break;

  case 171: /* select_attr: ID attr_list  */
#line 1429 "yacc_sql.y"
                   {
			RelAttr attr;
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 3484 "yacc_sql.tab.c"
    break;

  case 172: /* select_attr: ID DOT ID attr_list  */
#line 1435 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 3494 "yacc_sql.tab.c"
    break;

  case 173: /* select_attr: ID DOT STAR attr_list  */
#line 1440 "yacc_sql.y"
                               {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 3504 "yacc_sql.tab.c"
    break;

  case 174: /* select_attr: ID AS ID attr_list  */
#line 1445 "yacc_sql.y"
                            {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-3].string));
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 3515 "yacc_sql.tab.c"
    break;

  case 175: /* select_attr: ID DOT ID AS ID attr_list  */
#line 1451 "yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string),(yyvsp[-1].string));
		}
#line 3526 "yacc_sql.tab.c"
    break;

  case 177: /* attr_list: COMMA ID attr_list  */
#line 1460 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 3537 "yacc_sql.tab.c"
    break;

  case 178: /* attr_list: COMMA ID DOT ID attr_list  */
#line 1466 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 3548 "yacc_sql.tab.c"
    break;

  case 179: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 1472 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 3559 "yacc_sql.tab.c"
    break;

  case 180: /* attr_list: COMMA ID AS ID attr_list  */
#line 1478 "yacc_sql.y"
                                  {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-3].string));
		CONTEXT->ssql->sstr.selection.need_Revere=0;
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 3571 "yacc_sql.tab.c"
    break;

  case 181: /* attr_list: COMMA ID DOT ID AS ID attr_list  */
#line 1485 "yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-5].string), (yyvsp[-3].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			selects_append_alias2(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string),(yyvsp[-3].string),(yyvsp[-1].string));
		}
#line 3582 "yacc_sql.tab.c"
    break;

  case 183: /* rel_list: COMMA ID rel_list  */
#line 1495 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 3590 "yacc_sql.tab.c"
    break;

  case 184: /* rel_list: COMMA ID AS ID rel_list  */
#line 1498 "yacc_sql.y"
                                 {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string),(yyvsp[-1].string));
	}
#line 3599 "yacc_sql.tab.c"
    break;

  case 185: /* rel_list: COMMA ID ID rel_list  */
#line 1502 "yacc_sql.y"
                              {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_alias(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string),(yyvsp[-1].string));
	}
#line 3608 "yacc_sql.tab.c"
    break;

  case 187: /* where: WHERE condition condition_list  */
#line 1509 "yacc_sql.y"
                                     {
	}
#line 3615 "yacc_sql.tab.c"
    break;

  case 189: /* condition_list: AND condition condition_list  */
#line 1514 "yacc_sql.y"
                                   {
			}
#line 3622 "yacc_sql.tab.c"
    break;

  case 190: /* condition: ID comOp value  */
#line 1519 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 3638 "yacc_sql.tab.c"
    break;

  case 191: /* condition: value comOp value  */
#line 1531 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 3652 "yacc_sql.tab.c"
    break;

  case 192: /* condition: ID comOp ID  */
#line 1541 "yacc_sql.y"
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
#line 3676 "yacc_sql.tab.c"
    break;

  case 193: /* condition: value comOp ID  */
#line 1561 "yacc_sql.y"
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
#line 3702 "yacc_sql.tab.c"
    break;

  case 194: /* condition: ID DOT ID comOp value  */
#line 1583 "yacc_sql.y"
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
#line 3727 "yacc_sql.tab.c"
    break;

  case 195: /* condition: value comOp ID DOT ID  */
#line 1604 "yacc_sql.y"
                {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 3741 "yacc_sql.tab.c"
    break;

  case 196: /* condition: ID DOT ID comOp ID DOT ID  */
#line 1614 "yacc_sql.y"
        {
			
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3756 "yacc_sql.tab.c"
    break;

  case 197: /* condition: EXIST_T LBRACE sub_query RBRACE  */
#line 1625 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3766 "yacc_sql.tab.c"
    break;

  case 198: /* condition: NOT EXIST_T LBRACE sub_query RBRACE  */
#line 1631 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, NOT_EXIST, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3776 "yacc_sql.tab.c"
    break;

  case 199: /* condition: LBRACE sub_query RBRACE reverseComp ID  */
#line 1636 "yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->comp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3788 "yacc_sql.tab.c"
    break;

  case 200: /* condition: ID IN_T LBRACE in_cells RBRACE  */
#line 1643 "yacc_sql.y"
                                       {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3801 "yacc_sql.tab.c"
    break;

  case 201: /* condition: ID NOT IN_T LBRACE in_cells RBRACE  */
#line 1651 "yacc_sql.y"
                                           {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3814 "yacc_sql.tab.c"
    break;

  case 202: /* condition: ID DOT ID NOT IN_T LBRACE in_cells RBRACE  */
#line 1659 "yacc_sql.y"
                                                  {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-7].string), (yyvsp[-5].string));
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,NOT_IN);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3827 "yacc_sql.tab.c"
    break;

  case 203: /* condition: ID IN_T LBRACE sub_query RBRACE  */
#line 1667 "yacc_sql.y"
                                        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3839 "yacc_sql.tab.c"
    break;

  case 204: /* condition: ID DOT ID IN_T LBRACE sub_query RBRACE  */
#line 1674 "yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3851 "yacc_sql.tab.c"
    break;

  case 205: /* condition: ID NOT IN_T LBRACE sub_query RBRACE  */
#line 1681 "yacc_sql.y"
                                            {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-5].string));
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3863 "yacc_sql.tab.c"
    break;

  case 206: /* condition: ID DOT ID NOT IN_T LBRACE sub_query RBRACE  */
#line 1688 "yacc_sql.y"
                                                   {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-7].string), (yyvsp[-5].string));
		Condition condition;
		condition_init_with_query(&condition, NOT_IN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 3875 "yacc_sql.tab.c"
    break;

  case 207: /* condition: ID EQ LBRACE sub_query RBRACE  */
#line 1696 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, EQUAL_TO, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3887 "yacc_sql.tab.c"
    break;

  case 208: /* condition: ID LT LBRACE sub_query RBRACE  */
#line 1704 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, LESS_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3899 "yacc_sql.tab.c"
    break;

  case 209: /* condition: ID GT LBRACE sub_query RBRACE  */
#line 1712 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, GREAT_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3911 "yacc_sql.tab.c"
    break;

  case 210: /* condition: ID LE LBRACE sub_query RBRACE  */
#line 1720 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition,LESS_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3923 "yacc_sql.tab.c"
    break;

  case 211: /* condition: ID GE LBRACE sub_query RBRACE  */
#line 1728 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, GREAT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3935 "yacc_sql.tab.c"
    break;

  case 212: /* condition: ID NE LBRACE sub_query RBRACE  */
#line 1736 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, NOT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3947 "yacc_sql.tab.c"
    break;

  case 213: /* condition: ID DOT ID EQ LBRACE sub_query RBRACE  */
#line 1744 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, EQUAL_TO, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3959 "yacc_sql.tab.c"
    break;

  case 214: /* condition: ID DOT ID LT LBRACE sub_query RBRACE  */
#line 1752 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, LESS_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3971 "yacc_sql.tab.c"
    break;

  case 215: /* condition: ID DOT ID GT LBRACE sub_query RBRACE  */
#line 1760 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, GREAT_THAN, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3983 "yacc_sql.tab.c"
    break;

  case 216: /* condition: ID DOT ID LE LBRACE sub_query RBRACE  */
#line 1768 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition,LESS_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 3995 "yacc_sql.tab.c"
    break;

  case 217: /* condition: ID DOT ID GE LBRACE sub_query RBRACE  */
#line 1776 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, GREAT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 4007 "yacc_sql.tab.c"
    break;

  case 218: /* condition: ID DOT ID NE LBRACE sub_query RBRACE  */
#line 1784 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, NOT_EQUAL, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 4019 "yacc_sql.tab.c"
    break;

  case 219: /* condition: LBRACE sub_query RBRACE NE LBRACE sub_query RBRACE  */
#line 1791 "yacc_sql.y"
                                                            {
		Condition condition;
		condition_init_with_two_query(&condition, NOT_EQUAL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1],CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-2]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 4029 "yacc_sql.tab.c"
    break;

  case 220: /* in_cells: value value_list  */
#line 1798 "yacc_sql.y"
                          {
	}
#line 4036 "yacc_sql.tab.c"
    break;

  case 221: /* reverseComp: EQ  */
#line 1802 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 4042 "yacc_sql.tab.c"
    break;

  case 222: /* reverseComp: LT  */
#line 1803 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 4048 "yacc_sql.tab.c"
    break;

  case 223: /* reverseComp: GT  */
#line 1804 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 4054 "yacc_sql.tab.c"
    break;

  case 224: /* reverseComp: LE  */
#line 1805 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 4060 "yacc_sql.tab.c"
    break;

  case 225: /* reverseComp: GE  */
#line 1806 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 4066 "yacc_sql.tab.c"
    break;

  case 226: /* reverseComp: NE  */
#line 1807 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 4072 "yacc_sql.tab.c"
    break;

  case 227: /* comOp: EQ  */
#line 1810 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO;}
#line 4078 "yacc_sql.tab.c"
    break;

  case 228: /* comOp: LT  */
#line 1811 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 4084 "yacc_sql.tab.c"
    break;

  case 229: /* comOp: GT  */
#line 1812 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 4090 "yacc_sql.tab.c"
    break;

  case 230: /* comOp: LE  */
#line 1813 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 4096 "yacc_sql.tab.c"
    break;

  case 231: /* comOp: GE  */
#line 1814 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 4102 "yacc_sql.tab.c"
    break;

  case 232: /* comOp: NE  */
#line 1815 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 4108 "yacc_sql.tab.c"
    break;

  case 233: /* comOp: LIKE  */
#line 1816 "yacc_sql.y"
               { CONTEXT->comp = LIKE_TO; }
#line 4114 "yacc_sql.tab.c"
    break;

  case 234: /* comOp: IN_T  */
#line 1817 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 4120 "yacc_sql.tab.c"
    break;

  case 235: /* comOp: NOT IN_T  */
#line 1818 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 4126 "yacc_sql.tab.c"
    break;

  case 236: /* comOp: NOT EXIST_T  */
#line 1819 "yacc_sql.y"
                     {CONTEXT->comp = NOT_EXIST;}
#line 4132 "yacc_sql.tab.c"
    break;

  case 237: /* comOp: EXIST_T  */
#line 1820 "yacc_sql.y"
                 {CONTEXT->comp = EXIST;}
#line 4138 "yacc_sql.tab.c"
    break;

  case 238: /* comOp: NOT LIKE  */
#line 1821 "yacc_sql.y"
                   { CONTEXT->comp = NOT_LIKE; }
#line 4144 "yacc_sql.tab.c"
    break;

  case 239: /* comOp: IS NOT  */
#line 1822 "yacc_sql.y"
                 { CONTEXT->comp = COMP_IS_NOT; }
#line 4150 "yacc_sql.tab.c"
    break;

  case 240: /* comOp: IS  */
#line 1823 "yacc_sql.y"
             { CONTEXT->comp = COMP_IS; }
#line 4156 "yacc_sql.tab.c"
    break;

  case 241: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1828 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 4165 "yacc_sql.tab.c"
    break;


#line 4169 "yacc_sql.tab.c"

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

#line 1833 "yacc_sql.y"

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
