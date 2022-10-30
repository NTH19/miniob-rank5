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


#line 139 "yacc_sql.tab.c"

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
  YYSYMBOL_insert = 93,                    /* insert  */
  YYSYMBOL_record_list = 94,               /* record_list  */
  YYSYMBOL_record = 95,                    /* record  */
  YYSYMBOL_value_list = 96,                /* value_list  */
  YYSYMBOL_value = 97,                     /* value  */
  YYSYMBOL_delete = 98,                    /* delete  */
  YYSYMBOL_update = 99,                    /* update  */
  YYSYMBOL_update_attr_list = 100,         /* update_attr_list  */
  YYSYMBOL_update_attr = 101,              /* update_attr  */
  YYSYMBOL_update_select_attr = 102,       /* update_select_attr  */
  YYSYMBOL_update_agg = 103,               /* update_agg  */
  YYSYMBOL_select = 104,                   /* select  */
  YYSYMBOL_sub_where = 105,                /* sub_where  */
  YYSYMBOL_sub_condition_list = 106,       /* sub_condition_list  */
  YYSYMBOL_sub_condition = 107,            /* sub_condition  */
  YYSYMBOL_sub_query = 108,                /* sub_query  */
  YYSYMBOL_join_list = 109,                /* join_list  */
  YYSYMBOL_join_cons = 110,                /* join_cons  */
  YYSYMBOL_agg_fun_list_head = 111,        /* agg_fun_list_head  */
  YYSYMBOL_agg_fun_list = 112,             /* agg_fun_list  */
  YYSYMBOL_select_attr = 113,              /* select_attr  */
  YYSYMBOL_attr_list = 114,                /* attr_list  */
  YYSYMBOL_rel_list = 115,                 /* rel_list  */
  YYSYMBOL_where = 116,                    /* where  */
  YYSYMBOL_condition_list = 117,           /* condition_list  */
  YYSYMBOL_condition = 118,                /* condition  */
  YYSYMBOL_in_cells = 119,                 /* in_cells  */
  YYSYMBOL_exist_con = 120,                /* exist_con  */
  YYSYMBOL_in_not_com = 121,               /* in_not_com  */
  YYSYMBOL_sub_com = 122,                  /* sub_com  */
  YYSYMBOL_reverseComp = 123,              /* reverseComp  */
  YYSYMBOL_comOp = 124,                    /* comOp  */
  YYSYMBOL_load_data = 125                 /* load_data  */
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
#define YYLAST   524

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  183
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  472

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
       0,   163,   163,   165,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   190,   195,   200,   206,   212,   218,   224,   230,
     236,   244,   251,   256,   263,   265,   269,   276,   283,   292,
     294,   298,   309,   320,   331,   342,   353,   366,   369,   370,
     371,   372,   373,   376,   385,   401,   402,   407,   408,   413,
     414,   419,   422,   425,   429,   433,   439,   449,   457,   459,
     463,   469,   477,   488,   493,   498,   503,   511,   516,   521,
     526,   531,   536,   541,   546,   551,   556,   561,   571,   584,
     594,   606,   608,   611,   613,   617,   629,   639,   659,   681,
     702,   712,   726,   747,   765,   783,   801,   819,   837,   855,
     878,   880,   885,   890,   895,   900,   906,   912,   918,   925,
     927,   932,   937,   943,   949,   955,   965,   971,   977,   982,
     988,   990,   996,  1002,  1010,  1012,  1016,  1018,  1021,  1023,
    1027,  1039,  1049,  1069,  1091,  1112,  1122,  1133,  1141,  1147,
    1154,  1162,  1172,  1175,  1176,  1179,  1180,  1183,  1184,  1185,
    1186,  1187,  1188,  1191,  1192,  1193,  1194,  1195,  1196,  1199,
    1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,
    1210,  1211,  1212,  1216
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
  "number", "type", "ID_get", "insert", "record_list", "record",
  "value_list", "value", "delete", "update", "update_attr_list",
  "update_attr", "update_select_attr", "update_agg", "select", "sub_where",
  "sub_condition_list", "sub_condition", "sub_query", "join_list",
  "join_cons", "agg_fun_list_head", "agg_fun_list", "select_attr",
  "attr_list", "rel_list", "where", "condition_list", "condition",
  "in_cells", "exist_con", "in_not_com", "sub_com", "reverseComp", "comOp",
  "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-305)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-163)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -305,   106,  -305,    12,   116,    11,   -48,   142,    16,    -6,
      32,     9,    78,    86,    97,    98,   138,    63,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,    77,    83,   146,
      96,   136,   147,   193,   200,   207,   212,     8,   214,   196,
     204,   240,   249,   217,  -305,   203,   221,   252,  -305,  -305,
    -305,  -305,  -305,   230,   278,   253,   231,   294,   295,   -26,
     234,   235,   237,   238,   239,    37,  -305,  -305,   241,   245,
    -305,  -305,   246,   264,   266,   248,   247,   250,   251,   275,
    -305,  -305,   301,   302,   303,   304,   305,   306,    20,   214,
     214,   266,    -2,   321,   309,    21,   323,   279,   310,   293,
    -305,   312,   242,   315,   267,   317,   317,   317,   317,   317,
     317,    64,  -305,  -305,  -305,   330,   271,   296,   266,  -305,
      93,   319,   329,  -305,   285,  -305,  -305,  -305,  -305,   118,
    -305,   140,   307,   325,  -305,    28,   248,   266,   336,   250,
     326,  -305,  -305,  -305,  -305,  -305,    66,   280,   328,   114,
    -305,  -305,  -305,  -305,  -305,  -305,   214,   214,  -305,   331,
     281,   345,   332,   309,   348,     1,   335,  -305,   288,   338,
     339,   340,   341,   342,   343,  -305,   344,  -305,   233,   308,
     346,   347,   141,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
     236,   148,    21,  -305,   329,   352,  -305,   310,   361,   311,
     312,   363,   313,   314,  -305,  -305,   349,   280,   353,   354,
     355,   356,   358,  -305,  -305,  -305,   337,  -305,    93,   351,
     319,  -305,   362,   364,   365,   366,   367,    58,   232,   140,
    -305,   368,  -305,  -305,     5,   329,  -305,  -305,  -305,   350,
    -305,   307,   360,    29,  -305,  -305,   383,  -305,  -305,  -305,
     370,  -305,   280,   371,   349,    94,   324,   327,   333,   334,
      21,   332,  -305,  -305,   134,   357,   359,   369,   372,   373,
     374,  -305,  -305,  -305,  -305,  -305,  -305,   375,   155,   332,
     376,   377,   378,   379,  -305,  -305,   380,   381,   384,   385,
     386,   382,  -305,   387,   388,  -305,   173,   349,   400,   389,
     390,   391,   392,   393,   394,   395,   398,   307,  -305,   396,
     397,   401,   407,   408,   410,   409,   331,  -305,   411,  -305,
    -305,  -305,  -305,  -305,  -305,   183,   399,   402,   403,   404,
     185,   405,   406,   413,  -305,  -305,  -305,   412,   317,   317,
     317,   317,   317,   317,   414,   266,  -305,   415,   416,   417,
     418,   419,   420,   421,   422,   423,    10,   431,    19,    23,
      30,    95,  -305,  -305,   266,   266,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,   424,   425,   432,   426,   433,   434,
     435,   436,   331,   162,  -305,  -305,  -305,   427,  -305,  -305,
     428,  -305,   429,  -305,   430,  -305,   437,   438,   439,   445,
    -305,   440,   422,   441,   443,   452,   458,   422,   129,   140,
     457,   442,   446,   448,   449,   456,  -305,  -305,    21,   444,
    -305,   447,   450,   451,   453,  -305,   454,   182,   195,   162,
    -305,  -305,  -305,  -305,  -305,  -305,   398,   422,   422,   422,
     422,   422,   140,  -305,  -305,   463,  -305,   457,  -305,  -305,
    -305,  -305,  -305,  -305,   202,   455,  -305,   464,  -305,  -305,
     459,  -305
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
       0,     0,     0,     0,     0,     0,     0,   130,   130,     0,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,    23,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   126,     0,     0,
      31,    29,     0,     0,   136,     0,     0,     0,     0,     0,
      28,    37,     0,     0,     0,     0,     0,     0,   130,   130,
     130,   136,   134,     0,    57,     0,     0,     0,    68,     0,
      53,    39,     0,     0,     0,   119,   119,   119,   119,   119,
     119,     0,   131,   128,   129,     0,     0,     0,   136,    30,
       0,    55,     0,   154,     0,    65,    61,    62,    63,     0,
      64,     0,   138,     0,    66,     0,     0,   136,     0,     0,
       0,    48,    51,    52,    49,    50,    44,     0,     0,     0,
     114,   113,   115,   116,   118,   117,   130,   130,    89,   134,
       0,     0,    59,    57,     0,     0,     0,   153,     0,   169,
     170,   171,   172,   173,   174,   179,   176,   175,     0,   182,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   176,
       0,     0,     0,   137,     0,     0,    70,    68,     0,     0,
      39,     0,     0,     0,    46,    36,    34,     0,     0,     0,
       0,     0,     0,   132,   133,   135,     0,    88,     0,     0,
      55,    54,     0,     0,     0,     0,     0,     0,     0,     0,
     178,   177,   180,   181,     0,     0,   142,   140,   177,   143,
     141,   138,     0,     0,    69,    67,     0,    40,    38,    47,
       0,    45,     0,     0,    34,     0,     0,     0,     0,     0,
       0,    59,    58,    56,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,   166,   167,   168,     0,     0,    59,
       0,     0,     0,     0,   139,   148,     0,     0,     0,     0,
       0,    74,    73,     0,     0,   183,    41,    34,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   138,    60,     0,
       0,     0,     0,     0,     0,     0,   134,   149,     0,   144,
     152,   151,   150,   147,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    35,    32,     0,   119,   119,
     119,   119,   119,   119,     0,   136,   112,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,    75,    76,   136,   136,    42,    33,   121,   120,
     122,   123,   125,   124,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,   103,   146,    78,     0,    77,    80,
       0,    82,     0,    86,     0,    84,     0,     0,     0,     0,
      90,     0,    91,     0,     0,     0,     0,    91,     0,     0,
      93,     0,     0,     0,     0,     0,    71,    72,     0,     0,
     104,     0,     0,     0,     0,   102,     0,     0,     0,     0,
      92,    79,    81,    83,    87,    85,   110,    91,    91,    91,
      91,    91,     0,    97,    95,    98,    96,    93,   111,   105,
     106,   107,   109,   108,     0,     0,    94,     0,    99,   100,
       0,   101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -251,  -205,  -305,  -305,   180,   255,
    -305,  -305,  -305,  -305,   161,   243,  -243,  -130,  -305,  -305,
     198,   272,  -305,  -305,  -305,  -304,   -44,   -20,  -141,   -25,
      -8,  -305,  -113,  -305,   -39,  -161,   -99,  -240,   -95,  -305,
    -305,  -305,  -305,  -305,  -140,  -305
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   263,   216,    30,    31,   150,   111,
     260,   156,   112,    32,   174,   131,   229,   141,    33,    34,
     147,   108,   303,   304,    35,   394,   440,   420,   176,   355,
     316,    49,   160,    50,    76,   128,   106,   203,   317,   291,
     143,   190,   191,   287,   192,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     172,   201,   125,   161,   162,   163,   164,   165,   225,    77,
     142,   294,   264,   309,   175,   206,   126,    51,    37,    54,
      38,   232,   233,   234,   235,   236,    74,   396,   318,   171,
      55,    42,    43,    44,    45,    46,   399,   132,    74,    92,
     401,   127,    93,    75,   205,   397,   330,   403,   208,   296,
     297,   298,   299,   300,   400,   121,   345,   307,   402,   122,
     123,   124,   247,   252,   135,   404,   237,   136,   137,   138,
      56,   250,   140,    39,    57,   133,    47,   356,   134,    48,
     135,    58,   212,   136,   137,   138,   139,   135,   140,    59,
     136,   137,   138,   279,   301,   140,   280,   302,   271,   288,
      60,    61,    99,   290,   292,   100,     2,   251,   430,    63,
       3,     4,   405,   435,   289,     5,     6,     7,     8,     9,
      10,    11,    40,   213,    41,    12,   214,   223,   224,   166,
     406,    13,   167,    14,   218,   219,   220,   221,   222,    15,
      16,    62,    64,   459,   460,   461,   462,   463,    65,    52,
      53,    17,   135,   178,    66,   136,   137,   138,   329,   310,
     140,    67,   311,    69,   436,   364,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   193,   194,   195,
     196,   197,   198,   185,   199,   187,   200,   189,   193,   194,
     195,   196,   197,   198,   185,   199,   187,   200,   189,   319,
     135,    68,   320,   136,   137,   138,   246,   135,   140,    70,
     136,   137,   138,   249,   135,   140,    71,   136,   137,   138,
     328,   135,   140,    72,   136,   137,   138,   418,    73,   140,
     343,   417,    74,   344,    78,   378,   379,   380,   381,   382,
     383,   135,    79,    80,   136,   137,   138,   453,   366,   140,
     372,   367,    81,   373,   135,    82,   385,   136,   137,   138,
     455,   135,   140,   419,   136,   137,   138,   467,    83,   140,
     151,   152,   153,   154,   155,   407,   408,    86,   437,   438,
     281,   282,   283,   284,   285,   286,    84,   240,   241,   242,
     240,   248,   242,    85,    87,    88,    89,    90,    91,    94,
      95,   104,    96,    97,    98,   105,   101,   454,   456,   419,
     102,   103,   464,   107,   109,   110,   113,   114,   115,   116,
     117,   118,   119,   120,   129,   130,   144,   145,   146,   148,
     149,   157,   158,   168,   468,   159,   169,   173,   175,   177,
     170,   204,   209,   211,   217,   215,   226,   202,   227,   126,
     228,   231,   238,   239,  -157,  -158,  -159,  -160,  -161,  -162,
    -155,   253,   244,   245,   255,   243,   258,   262,   272,   265,
     266,   267,   268,   261,   269,   259,   256,   295,   274,   270,
     275,   276,   277,   278,  -156,   293,   305,   306,   308,   312,
     257,   273,   313,   331,   332,   333,   335,   336,   314,   315,
     337,   338,   339,   346,   210,   254,   347,   348,   349,   350,
     351,   352,   353,   466,   358,   377,   230,   340,   207,   457,
     446,   458,   321,     0,   322,   341,   342,     0,   410,     0,
       0,   357,     0,     0,   323,     0,   359,   324,   325,   326,
     327,   354,   360,   361,   334,   362,   365,   363,   398,   411,
     413,   414,   415,   416,   387,   426,   427,     0,   384,   441,
       0,   393,     0,   442,   368,   443,   444,   369,   370,   371,
     374,   375,   376,   445,     0,     0,     0,     0,   429,   431,
     386,   432,   388,   389,   390,   391,   392,   428,   395,   409,
     433,   412,   421,   422,   423,   424,   434,   439,   465,   470,
       0,     0,   425,     0,     0,     0,     0,     0,     0,   447,
       0,     0,   448,     0,     0,   449,   450,     0,   451,   452,
     469,     0,     0,     0,   471
};

static const yytype_int16 yycheck[] =
{
     130,   141,   101,   116,   117,   118,   119,   120,   169,    48,
     105,   251,   217,   264,     9,   145,    18,    65,     6,     3,
       8,    20,    21,    22,    23,    24,    18,    17,   271,   128,
      36,    20,    21,    22,    23,    24,    17,    16,    18,    65,
      17,    43,    68,    35,    16,    35,   289,    17,   147,    20,
      21,    22,    23,    24,    35,    35,   307,   262,    35,    98,
      99,   100,   192,   204,    59,    35,    65,    62,    63,    64,
      38,   201,    67,    61,    65,    54,    65,   317,    57,    68,
      59,     3,    16,    62,    63,    64,    65,    59,    67,     3,
      62,    63,    64,    35,    65,    67,    38,    68,   228,   239,
       3,     3,    65,   244,   245,    68,     0,   202,   412,    46,
       4,     5,    17,   417,   244,     9,    10,    11,    12,    13,
      14,    15,     6,    57,     8,    19,    60,   166,   167,    65,
      35,    25,    68,    27,    20,    21,    22,    23,    24,    33,
      34,     3,    65,   447,   448,   449,   450,   451,    65,     7,
       8,    45,    59,    35,     8,    62,    63,    64,   288,    65,
      67,    65,    68,    16,    35,   326,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    65,
      59,    65,    68,    62,    63,    64,    65,    59,    67,    16,
      62,    63,    64,    65,    59,    67,    16,    62,    63,    64,
      65,    59,    67,    16,    62,    63,    64,    65,    16,    67,
      57,   392,    18,    60,    38,   348,   349,   350,   351,   352,
     353,    59,    38,     3,    62,    63,    64,    65,    65,    67,
      65,    68,     3,    68,    59,    38,   355,    62,    63,    64,
      65,    59,    67,   393,    62,    63,    64,    65,    65,    67,
      28,    29,    30,    31,    32,   374,   375,    47,   418,   419,
      48,    49,    50,    51,    52,    53,    65,    54,    55,    56,
      54,    55,    56,    41,    16,    42,    65,     3,     3,    65,
      65,    37,    65,    65,    65,    39,    65,   437,   438,   439,
      65,    65,   452,    65,    67,    65,    65,    42,    17,    17,
      17,    17,    17,    17,     3,    16,     3,    48,    18,    36,
      18,    16,    65,     3,   464,    18,    65,    18,     9,    54,
      44,    16,     6,    17,    16,    65,    65,    40,     3,    18,
      18,     3,    17,    65,    16,    16,    16,    16,    16,    16,
      16,     9,    16,    16,     3,    57,     3,    18,    17,    16,
      16,    16,    16,    59,    16,    62,    65,    17,    16,    42,
      16,    16,    16,    16,    16,    35,     3,    17,    17,    65,
     210,   230,    65,    17,    17,    17,    16,    16,    65,    65,
      16,    16,    16,     3,   149,   207,    17,    17,    17,    17,
      17,    17,    17,   457,    17,     3,   173,    35,   146,   439,
     428,   446,    65,    -1,    65,    38,    38,    -1,     3,    -1,
      -1,    35,    -1,    -1,    65,    -1,    35,    65,    65,    65,
      65,    43,    35,    35,    65,    35,    35,    38,    17,    17,
      17,    17,    17,    17,    38,    17,    17,    -1,    44,    17,
      -1,    39,    -1,    17,    65,    17,    17,    65,    65,    65,
      65,    65,    59,    17,    -1,    -1,    -1,    -1,    38,    38,
      65,    38,    65,    65,    65,    65,    65,    42,    65,    65,
      38,    65,    65,    65,    65,    65,    38,    40,    35,    35,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    65,    -1,    -1,    65,    65,    -1,    65,    65,
      65,    -1,    -1,    -1,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    71,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    25,    27,    33,    34,    45,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      86,    87,    93,    98,    99,   104,   125,     6,     8,    61,
       6,     8,    20,    21,    22,    23,    24,    65,    68,   111,
     113,    65,     7,     8,     3,    36,    38,    65,     3,     3,
       3,     3,     3,    46,    65,    65,     8,    65,    65,    16,
      16,    16,    16,    16,    18,    35,   114,   114,    38,    38,
       3,     3,    38,    65,    65,    41,    47,    16,    42,    65,
       3,     3,    65,    68,    65,    65,    65,    65,    65,    65,
      68,    65,    65,    65,    37,    39,   116,    65,   101,    67,
      65,    89,    92,    65,    42,    17,    17,    17,    17,    17,
      17,    35,   114,   114,   114,   116,    18,    43,   115,     3,
      16,    95,    16,    54,    57,    59,    62,    63,    64,    65,
      67,    97,   118,   120,     3,    48,    18,   100,    36,    18,
      88,    28,    29,    30,    31,    32,    91,    16,    65,    18,
     112,   112,   112,   112,   112,   112,    65,    68,     3,    65,
      44,   116,    97,    18,    94,     9,   108,    54,    35,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
     121,   122,   124,    48,    49,    50,    51,    52,    53,    55,
      57,   124,    40,   117,    16,    16,    97,   101,   116,     6,
      89,    17,    16,    57,    60,    65,    85,    16,    20,    21,
      22,    23,    24,   114,   114,   115,    65,     3,    18,    96,
      95,     3,    20,    21,    22,    23,    24,    65,    17,    65,
      54,    55,    56,    57,    16,    16,    65,    97,    55,    65,
      97,   118,   108,     9,   100,     3,    65,    88,     3,    62,
      90,    59,    18,    84,    85,    16,    16,    16,    16,    16,
      42,    97,    17,    94,    16,    16,    16,    16,    16,    35,
      38,    48,    49,    50,    51,    52,    53,   123,   124,    97,
     108,   119,   108,    35,   117,    17,    20,    21,    22,    23,
      24,    65,    68,   102,   103,     3,    17,    85,    17,    84,
      65,    68,    65,    65,    65,    65,   110,   118,    96,    65,
      68,    65,    65,    65,    65,    65,    65,    65,    65,    97,
      96,    17,    17,    17,    65,    16,    16,    16,    16,    16,
      35,    38,    38,    57,    60,    84,     3,    17,    17,    17,
      17,    17,    17,    17,    43,   109,   117,    35,    17,    35,
      35,    35,    35,    38,   115,    35,    65,    68,    65,    65,
      65,    65,    65,    68,    65,    65,    59,     3,   112,   112,
     112,   112,   112,   112,    44,   116,    65,    38,    65,    65,
      65,    65,    65,    39,   105,    65,    17,    35,    17,    17,
      35,    17,    35,    17,    35,    17,    35,   116,   116,    65,
       3,    17,    65,    17,    17,    17,    17,   115,    65,    97,
     107,    65,    65,    65,    65,    65,    17,    17,    42,    38,
     105,    38,    38,    38,    38,   105,    35,   124,   124,    40,
     106,    17,    17,    17,    17,    17,   110,    65,    65,    65,
      65,    65,    65,    65,    97,    65,    97,   107,   109,   105,
     105,   105,   105,   105,   124,    35,   106,    65,    97,    65,
      35,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    83,    84,    84,    85,    86,    87,    88,
      88,    89,    89,    89,    89,    89,    89,    90,    91,    91,
      91,    91,    91,    92,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    97,    97,    98,    99,   100,   100,
     101,   101,   101,   102,   102,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   104,   104,
     104,   105,   105,   106,   106,   107,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     109,   109,   110,   111,   111,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   113,   113,
     114,   114,   114,   114,   115,   115,   116,   116,   117,   117,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   120,   120,   121,   121,   122,   122,   122,
     122,   122,   122,   123,   123,   123,   123,   123,   123,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   125
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
       4,     6,     4,     6,     4,     6,     4,     6,     7,     6,
      12,     0,     3,     0,     3,     3,     3,     3,     3,     5,
       5,     7,     8,     6,     8,    10,    10,    10,    10,    10,
       0,     6,     2,     5,     5,     5,     5,     5,     5,     0,
       6,     6,     6,     6,     6,     6,     2,     2,     4,     4,
       0,     3,     5,     5,     0,     3,     0,     3,     0,     3,
       3,     3,     3,     3,     5,     5,     7,     5,     4,     5,
       5,     5,     2,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     2,     1,     8
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
#line 190 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1582 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 195 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1590 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 200 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1598 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 206 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1606 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 212 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1614 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 218 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1622 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 224 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1631 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 230 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1639 "yacc_sql.tab.c"
    break;

  case 30: /* show_indexes: SHOW INDEX FROM ID SEMICOLON  */
#line 236 "yacc_sql.y"
                                {
      CONTEXT->ssql->flag = SCF_SHOW_INDEXES;
	  show_indexes_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string));
    }
#line 1648 "yacc_sql.tab.c"
    break;

  case 31: /* desc_table: DESC ID SEMICOLON  */
#line 244 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1657 "yacc_sql.tab.c"
    break;

  case 32: /* create_index: CREATE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 252 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 0);
		}
#line 1666 "yacc_sql.tab.c"
    break;

  case 33: /* create_index: CREATE UNIQUE INDEX ID ON ID LBRACE index_attr index_attr_list RBRACE SEMICOLON  */
#line 257 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-7].string), (yyvsp[-5].string), 1);
		}
#line 1675 "yacc_sql.tab.c"
    break;

  case 35: /* index_attr_list: COMMA index_attr index_attr_list  */
#line 265 "yacc_sql.y"
                                           { }
#line 1681 "yacc_sql.tab.c"
    break;

  case 36: /* index_attr: ID  */
#line 270 "yacc_sql.y"
                {
			create_index_append_attribute(&CONTEXT->ssql->sstr.create_index, (yyvsp[0].string));
		}
#line 1689 "yacc_sql.tab.c"
    break;

  case 37: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 277 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1698 "yacc_sql.tab.c"
    break;

  case 38: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 284 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1710 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 294 "yacc_sql.y"
                                   {    }
#line 1716 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 299 "yacc_sql.y"
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
#line 1731 "yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type LBRACE number RBRACE NOT NULLL  */
#line 310 "yacc_sql.y"
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
#line 1746 "yacc_sql.tab.c"
    break;

  case 43: /* attr_def: ID_get type LBRACE number RBRACE NULLABLE  */
#line 321 "yacc_sql.y"
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
#line 1761 "yacc_sql.tab.c"
    break;

  case 44: /* attr_def: ID_get type  */
#line 332 "yacc_sql.y"
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
#line 1776 "yacc_sql.tab.c"
    break;

  case 45: /* attr_def: ID_get type NOT NULLL  */
#line 343 "yacc_sql.y"
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
#line 1791 "yacc_sql.tab.c"
    break;

  case 46: /* attr_def: ID_get type NULLABLE  */
#line 354 "yacc_sql.y"
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
#line 1806 "yacc_sql.tab.c"
    break;

  case 47: /* number: NUMBER  */
#line 366 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1812 "yacc_sql.tab.c"
    break;

  case 48: /* type: INT_T  */
#line 369 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1818 "yacc_sql.tab.c"
    break;

  case 49: /* type: DATE_T  */
#line 370 "yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 1824 "yacc_sql.tab.c"
    break;

  case 50: /* type: TEXT_T  */
#line 371 "yacc_sql.y"
                    { (yyval.number)=TEXTS; }
#line 1830 "yacc_sql.tab.c"
    break;

  case 51: /* type: STRING_T  */
#line 372 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1836 "yacc_sql.tab.c"
    break;

  case 52: /* type: FLOAT_T  */
#line 373 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1842 "yacc_sql.tab.c"
    break;

  case 53: /* ID_get: ID  */
#line 377 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1851 "yacc_sql.tab.c"
    break;

  case 54: /* insert: INSERT INTO ID VALUES record record_list SEMICOLON  */
#line 386 "yacc_sql.y"
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
#line 1871 "yacc_sql.tab.c"
    break;

  case 56: /* record_list: COMMA record record_list  */
#line 402 "yacc_sql.y"
                                        {

		}
#line 1879 "yacc_sql.tab.c"
    break;

  case 58: /* record: LBRACE value value_list RBRACE  */
#line 409 "yacc_sql.y"
                {
			CONTEXT->single_record_length[CONTEXT->record_length] = CONTEXT->value_length;
			CONTEXT->record_length++;
		}
#line 1888 "yacc_sql.tab.c"
    break;

  case 60: /* value_list: COMMA value value_list  */
#line 414 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1896 "yacc_sql.tab.c"
    break;

  case 61: /* value: NUMBER  */
#line 419 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1904 "yacc_sql.tab.c"
    break;

  case 62: /* value: FLOAT  */
#line 422 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1912 "yacc_sql.tab.c"
    break;

  case 63: /* value: DATEE  */
#line 425 "yacc_sql.y"
               {
			(yyvsp[0].dates) = substr((yyvsp[0].dates),1,strlen((yyvsp[0].dates))-2);
  		value_init_date(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].dates));
		}
#line 1921 "yacc_sql.tab.c"
    break;

  case 64: /* value: SSS  */
#line 429 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1930 "yacc_sql.tab.c"
    break;

  case 65: /* value: NULLL  */
#line 433 "yacc_sql.y"
               {
		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		}
#line 1938 "yacc_sql.tab.c"
    break;

  case 66: /* delete: DELETE FROM ID where SEMICOLON  */
#line 440 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1950 "yacc_sql.tab.c"
    break;

  case 67: /* update: UPDATE ID SET update_attr update_attr_list where SEMICOLON  */
#line 450 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-5].string), CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1960 "yacc_sql.tab.c"
    break;

  case 70: /* update_attr: ID EQ value  */
#line 464 "yacc_sql.y"
                {
			updates_append_value(&CONTEXT->ssql->sstr.update, &CONTEXT->values[CONTEXT->value_length - 1]);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			CONTEXT->value_length = 0;
		}
#line 1970 "yacc_sql.tab.c"
    break;

  case 71: /* update_attr: ID EQ LBRACE SELECT update_select_attr FROM ID where RBRACE  */
#line 470 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 1982 "yacc_sql.tab.c"
    break;

  case 72: /* update_attr: ID EQ LBRACE SELECT update_agg FROM ID where RBRACE  */
#line 478 "yacc_sql.y"
                {
			updates_selects_append_relation(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string));
			updates_selects_append_conditions(&CONTEXT->ssql->sstr.update, CONTEXT->conditions, CONTEXT->condition_length);
			updates_append_attr(&CONTEXT->ssql->sstr.update, (yyvsp[-8].string));
			CONTEXT->condition_length = 0;
			CONTEXT->value_length = 0;
		}
#line 1994 "yacc_sql.tab.c"
    break;

  case 73: /* update_select_attr: STAR  */
#line 488 "yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2004 "yacc_sql.tab.c"
    break;

  case 74: /* update_select_attr: ID  */
#line 493 "yacc_sql.y"
         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2014 "yacc_sql.tab.c"
    break;

  case 75: /* update_select_attr: ID DOT ID  */
#line 498 "yacc_sql.y"
                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2024 "yacc_sql.tab.c"
    break;

  case 76: /* update_select_attr: ID DOT STAR  */
#line 503 "yacc_sql.y"
                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-2].string), "*");
			updates_selects_append_attribute(&CONTEXT->ssql->sstr.update, &attr);
		}
#line 2034 "yacc_sql.tab.c"
    break;

  case 77: /* update_agg: COUNT_T LBRACE STAR RBRACE  */
#line 511 "yacc_sql.y"
                                    {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT_STAR, "*");
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update,  &aggre);
	}
#line 2044 "yacc_sql.tab.c"
    break;

  case 78: /* update_agg: COUNT_T LBRACE ID RBRACE  */
#line 516 "yacc_sql.y"
                                   {
		AggFun aggre;
		Init_AggFun(&aggre, COUNT, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2054 "yacc_sql.tab.c"
    break;

  case 79: /* update_agg: COUNT_T LBRACE ID DOT ID RBRACE  */
#line 521 "yacc_sql.y"
                                          {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, COUNT, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2064 "yacc_sql.tab.c"
    break;

  case 80: /* update_agg: MAX_T LBRACE ID RBRACE  */
#line 526 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2074 "yacc_sql.tab.c"
    break;

  case 81: /* update_agg: MAX_T LBRACE ID DOT ID RBRACE  */
#line 531 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MAX, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2084 "yacc_sql.tab.c"
    break;

  case 82: /* update_agg: MIN_T LBRACE ID RBRACE  */
#line 536 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2094 "yacc_sql.tab.c"
    break;

  case 83: /* update_agg: MIN_T LBRACE ID DOT ID RBRACE  */
#line 541 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, MIN, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2104 "yacc_sql.tab.c"
    break;

  case 84: /* update_agg: SUM_T LBRACE ID RBRACE  */
#line 546 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2114 "yacc_sql.tab.c"
    break;

  case 85: /* update_agg: SUM_T LBRACE ID DOT ID RBRACE  */
#line 551 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, SUM, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2124 "yacc_sql.tab.c"
    break;

  case 86: /* update_agg: AVG_T LBRACE ID RBRACE  */
#line 556 "yacc_sql.y"
                                 {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2134 "yacc_sql.tab.c"
    break;

  case 87: /* update_agg: AVG_T LBRACE ID DOT ID RBRACE  */
#line 561 "yacc_sql.y"
                                        {
		AggFun aggre;
		Init_AggFun_Rel(&aggre, AVG, (yyvsp[-3].string), (yyvsp[-1].string));
		updates_selects_append_aggfun(&CONTEXT->ssql->sstr.update, &aggre);
	}
#line 2144 "yacc_sql.tab.c"
    break;

  case 88: /* select: SELECT select_attr FROM ID rel_list where SEMICOLON  */
#line 571 "yacc_sql.y"
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
#line 2162 "yacc_sql.tab.c"
    break;

  case 89: /* select: SELECT agg_fun_list_head FROM ID where SEMICOLON  */
#line 584 "yacc_sql.y"
                                                          {
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		CONTEXT->ssql->flag=SCF_SELECT;

		CONTEXT->condition_length=0;
		CONTEXT->from_length=0;
		CONTEXT->select_length=0;
		CONTEXT->value_length = 0;
	}
#line 2177 "yacc_sql.tab.c"
    break;

  case 90: /* select: SELECT select_attr FROM ID INNER_T JOIN_T ID ON join_cons join_list where SEMICOLON  */
#line 594 "yacc_sql.y"
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
#line 2193 "yacc_sql.tab.c"
    break;

  case 92: /* sub_where: WHERE sub_condition sub_condition_list  */
#line 608 "yacc_sql.y"
                                             {	
			}
#line 2200 "yacc_sql.tab.c"
    break;

  case 94: /* sub_condition_list: AND sub_condition sub_condition_list  */
#line 613 "yacc_sql.y"
                                           {
			}
#line 2207 "yacc_sql.tab.c"
    break;

  case 95: /* sub_condition: ID comOp value  */
#line 618 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;

		}
#line 2223 "yacc_sql.tab.c"
    break;

  case 96: /* sub_condition: value comOp value  */
#line 630 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;

		}
#line 2237 "yacc_sql.tab.c"
    break;

  case 97: /* sub_condition: ID comOp ID  */
#line 640 "yacc_sql.y"
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
#line 2261 "yacc_sql.tab.c"
    break;

  case 98: /* sub_condition: value comOp ID  */
#line 660 "yacc_sql.y"
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
#line 2287 "yacc_sql.tab.c"
    break;

  case 99: /* sub_condition: ID DOT ID comOp value  */
#line 682 "yacc_sql.y"
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
#line 2312 "yacc_sql.tab.c"
    break;

  case 100: /* sub_condition: value comOp ID DOT ID  */
#line 703 "yacc_sql.y"
                {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;
									
    }
#line 2326 "yacc_sql.tab.c"
    break;

  case 101: /* sub_condition: ID DOT ID comOp ID DOT ID  */
#line 713 "yacc_sql.y"
        {
			
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->sub_cons[CONTEXT->sub_cons_num++] = condition;
    }
#line 2341 "yacc_sql.tab.c"
    break;

  case 102: /* sub_query: SELECT ID DOT ID FROM ID rel_list sub_where  */
#line 726 "yacc_sql.y"
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
#line 2367 "yacc_sql.tab.c"
    break;

  case 103: /* sub_query: SELECT ID FROM ID rel_list sub_where  */
#line 747 "yacc_sql.y"
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
#line 2390 "yacc_sql.tab.c"
    break;

  case 104: /* sub_query: SELECT COUNT_T LBRACE STAR RBRACE FROM ID sub_where  */
#line 765 "yacc_sql.y"
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
#line 2413 "yacc_sql.tab.c"
    break;

  case 105: /* sub_query: SELECT COUNT_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 783 "yacc_sql.y"
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
#line 2436 "yacc_sql.tab.c"
    break;

  case 106: /* sub_query: SELECT MAX_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 801 "yacc_sql.y"
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
#line 2459 "yacc_sql.tab.c"
    break;

  case 107: /* sub_query: SELECT MIN_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 819 "yacc_sql.y"
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
#line 2482 "yacc_sql.tab.c"
    break;

  case 108: /* sub_query: SELECT SUM_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 837 "yacc_sql.y"
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
#line 2505 "yacc_sql.tab.c"
    break;

  case 109: /* sub_query: SELECT AVG_T LBRACE ID DOT ID RBRACE FROM ID sub_where  */
#line 855 "yacc_sql.y"
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
#line 2531 "yacc_sql.tab.c"
    break;

  case 111: /* join_list: INNER_T JOIN_T ID ON join_cons join_list  */
#line 880 "yacc_sql.y"
                                               {	
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string));
	}
#line 2539 "yacc_sql.tab.c"
    break;

  case 112: /* join_cons: condition condition_list  */
#line 885 "yacc_sql.y"
                                  {	
	}
#line 2546 "yacc_sql.tab.c"
    break;

  case 113: /* agg_fun_list_head: COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 890 "yacc_sql.y"
                                                {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2556 "yacc_sql.tab.c"
    break;

  case 114: /* agg_fun_list_head: COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 895 "yacc_sql.y"
                                              {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2566 "yacc_sql.tab.c"
    break;

  case 115: /* agg_fun_list_head: MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 900 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2577 "yacc_sql.tab.c"
    break;

  case 116: /* agg_fun_list_head: MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 906 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2588 "yacc_sql.tab.c"
    break;

  case 117: /* agg_fun_list_head: SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 912 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2599 "yacc_sql.tab.c"
    break;

  case 118: /* agg_fun_list_head: AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 918 "yacc_sql.y"
                                             {
		AggFun aggre;
		Init_AggFun(&aggre, AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2610 "yacc_sql.tab.c"
    break;

  case 120: /* agg_fun_list: COMMA COUNT_T LBRACE STAR RBRACE agg_fun_list  */
#line 927 "yacc_sql.y"
                                                      {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT_STAR,"*");
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2620 "yacc_sql.tab.c"
    break;

  case 121: /* agg_fun_list: COMMA COUNT_T LBRACE ID RBRACE agg_fun_list  */
#line 932 "yacc_sql.y"
                                                    {
		AggFun aggre;
		Init_AggFun(&aggre,COUNT,(yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection,&aggre);
	}
#line 2630 "yacc_sql.tab.c"
    break;

  case 122: /* agg_fun_list: COMMA MAX_T LBRACE ID RBRACE agg_fun_list  */
#line 937 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre, MAX, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2641 "yacc_sql.tab.c"
    break;

  case 123: /* agg_fun_list: COMMA MIN_T LBRACE ID RBRACE agg_fun_list  */
#line 943 "yacc_sql.y"
                                                  {
		AggFun aggre;
		Init_AggFun(&aggre,MIN, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2652 "yacc_sql.tab.c"
    break;

  case 124: /* agg_fun_list: COMMA SUM_T LBRACE ID RBRACE agg_fun_list  */
#line 949 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,SUM, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2663 "yacc_sql.tab.c"
    break;

  case 125: /* agg_fun_list: COMMA AVG_T LBRACE ID RBRACE agg_fun_list  */
#line 955 "yacc_sql.y"
                                                   {
		AggFun aggre;
		Init_AggFun(&aggre,AVG, (yyvsp[-2].string));
		selects_append_aggfun(&CONTEXT->ssql->sstr.selection, &aggre);
		CONTEXT->select_length++;
	  }
#line 2674 "yacc_sql.tab.c"
    break;

  case 126: /* select_attr: STAR attr_list  */
#line 965 "yacc_sql.y"
                   {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			CONTEXT->ssql->sstr.selection.need_Revere=1;
		}
#line 2685 "yacc_sql.tab.c"
    break;

  case 127: /* select_attr: ID attr_list  */
#line 971 "yacc_sql.y"
                   {
			RelAttr attr;
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2696 "yacc_sql.tab.c"
    break;

  case 128: /* select_attr: ID DOT ID attr_list  */
#line 977 "yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 2706 "yacc_sql.tab.c"
    break;

  case 129: /* select_attr: ID DOT STAR attr_list  */
#line 982 "yacc_sql.y"
                               {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), "*");
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2716 "yacc_sql.tab.c"
    break;

  case 131: /* attr_list: COMMA ID attr_list  */
#line 990 "yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
      }
#line 2727 "yacc_sql.tab.c"
    break;

  case 132: /* attr_list: COMMA ID DOT ID attr_list  */
#line 996 "yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 2738 "yacc_sql.tab.c"
    break;

  case 133: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 1002 "yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			CONTEXT->ssql->sstr.selection.need_Revere=0;
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
  	  }
#line 2749 "yacc_sql.tab.c"
    break;

  case 135: /* rel_list: COMMA ID rel_list  */
#line 1012 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2757 "yacc_sql.tab.c"
    break;

  case 137: /* where: WHERE condition condition_list  */
#line 1018 "yacc_sql.y"
                                     {	
			}
#line 2764 "yacc_sql.tab.c"
    break;

  case 139: /* condition_list: AND condition condition_list  */
#line 1023 "yacc_sql.y"
                                   {
			}
#line 2771 "yacc_sql.tab.c"
    break;

  case 140: /* condition: ID comOp value  */
#line 1028 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 2787 "yacc_sql.tab.c"
    break;

  case 141: /* condition: value comOp value  */
#line 1040 "yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

		}
#line 2801 "yacc_sql.tab.c"
    break;

  case 142: /* condition: ID comOp ID  */
#line 1050 "yacc_sql.y"
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
#line 2825 "yacc_sql.tab.c"
    break;

  case 143: /* condition: value comOp ID  */
#line 1070 "yacc_sql.y"
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
#line 2851 "yacc_sql.tab.c"
    break;

  case 144: /* condition: ID DOT ID comOp value  */
#line 1092 "yacc_sql.y"
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
#line 2876 "yacc_sql.tab.c"
    break;

  case 145: /* condition: value comOp ID DOT ID  */
#line 1113 "yacc_sql.y"
                {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
#line 2890 "yacc_sql.tab.c"
    break;

  case 146: /* condition: ID DOT ID comOp ID DOT ID  */
#line 1123 "yacc_sql.y"
        {
			
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2905 "yacc_sql.tab.c"
    break;

  case 147: /* condition: ID sub_com LBRACE sub_query RBRACE  */
#line 1134 "yacc_sql.y"
        {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->tempOp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2917 "yacc_sql.tab.c"
    break;

  case 148: /* condition: exist_con LBRACE sub_query RBRACE  */
#line 1142 "yacc_sql.y"
        {
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->tempOp, NULL,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
#line 2927 "yacc_sql.tab.c"
    break;

  case 149: /* condition: LBRACE sub_query RBRACE reverseComp ID  */
#line 1147 "yacc_sql.y"
                                               {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[0].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->comp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2939 "yacc_sql.tab.c"
    break;

  case 150: /* condition: ID in_not_com LBRACE in_cells RBRACE  */
#line 1154 "yacc_sql.y"
                                             {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_cells_for_in(&condition,&left_attr,CONTEXT->values,CONTEXT->value_length,CONTEXT->tempOp);
		CONTEXT->value_length=0;
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2952 "yacc_sql.tab.c"
    break;

  case 151: /* condition: ID in_not_com LBRACE sub_query RBRACE  */
#line 1162 "yacc_sql.y"
                                              {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-4].string));
		Condition condition;
		condition_init_with_query(&condition, CONTEXT->tempOp, &left_attr,CONTEXT->ssql->sstr.selection.sub_query[CONTEXT->ssql->sstr.selection.sub_query_num-1]);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2964 "yacc_sql.tab.c"
    break;

  case 152: /* in_cells: value value_list  */
#line 1172 "yacc_sql.y"
                          {
	}
#line 2971 "yacc_sql.tab.c"
    break;

  case 153: /* exist_con: NOT EXIST_T  */
#line 1175 "yacc_sql.y"
                    {CONTEXT->tempOp= NOT_EXIST;}
#line 2977 "yacc_sql.tab.c"
    break;

  case 154: /* exist_con: EXIST_T  */
#line 1176 "yacc_sql.y"
                 {CONTEXT->tempOp = EXIST;}
#line 2983 "yacc_sql.tab.c"
    break;

  case 155: /* in_not_com: IN_T  */
#line 1179 "yacc_sql.y"
             {CONTEXT->tempOp = IN;}
#line 2989 "yacc_sql.tab.c"
    break;

  case 156: /* in_not_com: NOT IN_T  */
#line 1180 "yacc_sql.y"
                   {CONTEXT->tempOp = NOT_IN;}
#line 2995 "yacc_sql.tab.c"
    break;

  case 157: /* sub_com: EQ  */
#line 1183 "yacc_sql.y"
           { CONTEXT->tempOp = EQUAL_TO;}
#line 3001 "yacc_sql.tab.c"
    break;

  case 158: /* sub_com: LT  */
#line 1184 "yacc_sql.y"
         { CONTEXT->tempOp = LESS_THAN; }
#line 3007 "yacc_sql.tab.c"
    break;

  case 159: /* sub_com: GT  */
#line 1185 "yacc_sql.y"
         { CONTEXT->tempOp = GREAT_THAN; }
#line 3013 "yacc_sql.tab.c"
    break;

  case 160: /* sub_com: LE  */
#line 1186 "yacc_sql.y"
         { CONTEXT->tempOp = LESS_EQUAL; }
#line 3019 "yacc_sql.tab.c"
    break;

  case 161: /* sub_com: GE  */
#line 1187 "yacc_sql.y"
         { CONTEXT->tempOp = GREAT_EQUAL; }
#line 3025 "yacc_sql.tab.c"
    break;

  case 162: /* sub_com: NE  */
#line 1188 "yacc_sql.y"
         { CONTEXT->tempOp = NOT_EQUAL; }
#line 3031 "yacc_sql.tab.c"
    break;

  case 163: /* reverseComp: EQ  */
#line 1191 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 3037 "yacc_sql.tab.c"
    break;

  case 164: /* reverseComp: LT  */
#line 1192 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3043 "yacc_sql.tab.c"
    break;

  case 165: /* reverseComp: GT  */
#line 1193 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3049 "yacc_sql.tab.c"
    break;

  case 166: /* reverseComp: LE  */
#line 1194 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3055 "yacc_sql.tab.c"
    break;

  case 167: /* reverseComp: GE  */
#line 1195 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3061 "yacc_sql.tab.c"
    break;

  case 168: /* reverseComp: NE  */
#line 1196 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3067 "yacc_sql.tab.c"
    break;

  case 169: /* comOp: EQ  */
#line 1199 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO;}
#line 3073 "yacc_sql.tab.c"
    break;

  case 170: /* comOp: LT  */
#line 1200 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 3079 "yacc_sql.tab.c"
    break;

  case 171: /* comOp: GT  */
#line 1201 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 3085 "yacc_sql.tab.c"
    break;

  case 172: /* comOp: LE  */
#line 1202 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 3091 "yacc_sql.tab.c"
    break;

  case 173: /* comOp: GE  */
#line 1203 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 3097 "yacc_sql.tab.c"
    break;

  case 174: /* comOp: NE  */
#line 1204 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 3103 "yacc_sql.tab.c"
    break;

  case 175: /* comOp: LIKE  */
#line 1205 "yacc_sql.y"
               { CONTEXT->comp = LIKE_TO; }
#line 3109 "yacc_sql.tab.c"
    break;

  case 176: /* comOp: IN_T  */
#line 1206 "yacc_sql.y"
               {CONTEXT->comp = IN;}
#line 3115 "yacc_sql.tab.c"
    break;

  case 177: /* comOp: NOT IN_T  */
#line 1207 "yacc_sql.y"
                   {CONTEXT->comp = NOT_IN;}
#line 3121 "yacc_sql.tab.c"
    break;

  case 178: /* comOp: NOT EXIST_T  */
#line 1208 "yacc_sql.y"
                     {CONTEXT->comp = NOT_EXIST;}
#line 3127 "yacc_sql.tab.c"
    break;

  case 179: /* comOp: EXIST_T  */
#line 1209 "yacc_sql.y"
                 {CONTEXT->comp = EXIST;}
#line 3133 "yacc_sql.tab.c"
    break;

  case 180: /* comOp: NOT LIKE  */
#line 1210 "yacc_sql.y"
                   { CONTEXT->comp = NOT_LIKE; }
#line 3139 "yacc_sql.tab.c"
    break;

  case 181: /* comOp: IS NOT  */
#line 1211 "yacc_sql.y"
                 { CONTEXT->comp = COMP_IS_NOT; }
#line 3145 "yacc_sql.tab.c"
    break;

  case 182: /* comOp: IS  */
#line 1212 "yacc_sql.y"
             { CONTEXT->comp = COMP_IS; }
#line 3151 "yacc_sql.tab.c"
    break;

  case 183: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 1217 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3160 "yacc_sql.tab.c"
    break;


#line 3164 "yacc_sql.tab.c"

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

#line 1222 "yacc_sql.y"

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
