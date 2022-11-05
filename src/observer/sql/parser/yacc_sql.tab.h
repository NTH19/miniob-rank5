/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_SQL_TAB_H_INCLUDED
# define YY_YY_YACC_SQL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    CREATE = 259,                  /* CREATE  */
    DROP = 260,                    /* DROP  */
    TABLE = 261,                   /* TABLE  */
    TABLES = 262,                  /* TABLES  */
    INDEX = 263,                   /* INDEX  */
    SELECT = 264,                  /* SELECT  */
    DESC = 265,                    /* DESC  */
    ASC = 266,                     /* ASC  */
    SHOW = 267,                    /* SHOW  */
    SYNC = 268,                    /* SYNC  */
    DT2 = 269,                     /* DT2  */
    INSERT = 270,                  /* INSERT  */
    DELETE = 271,                  /* DELETE  */
    UPDATE = 272,                  /* UPDATE  */
    LBRACE = 273,                  /* LBRACE  */
    RBRACE = 274,                  /* RBRACE  */
    COMMA = 275,                   /* COMMA  */
    TRX_BEGIN = 276,               /* TRX_BEGIN  */
    COUNT_T = 277,                 /* COUNT_T  */
    MAX_T = 278,                   /* MAX_T  */
    MIN_T = 279,                   /* MIN_T  */
    AVG_T = 280,                   /* AVG_T  */
    SUM_T = 281,                   /* SUM_T  */
    TRX_COMMIT = 282,              /* TRX_COMMIT  */
    DT = 283,                      /* DT  */
    TRX_ROLLBACK = 284,            /* TRX_ROLLBACK  */
    INT_T = 285,                   /* INT_T  */
    STRING_T = 286,                /* STRING_T  */
    FLOAT_T = 287,                 /* FLOAT_T  */
    DATE_T = 288,                  /* DATE_T  */
    TEXT_T = 289,                  /* TEXT_T  */
    HELP = 290,                    /* HELP  */
    EXIT = 291,                    /* EXIT  */
    DOT = 292,                     /* DOT  */
    INTO = 293,                    /* INTO  */
    VALUES = 294,                  /* VALUES  */
    FROM = 295,                    /* FROM  */
    WHERE = 296,                   /* WHERE  */
    AS = 297,                      /* AS  */
    AND = 298,                     /* AND  */
    SET = 299,                     /* SET  */
    DT1 = 300,                     /* DT1  */
    GROUP = 301,                   /* GROUP  */
    ON = 302,                      /* ON  */
    INNER_T = 303,                 /* INNER_T  */
    JOIN_T = 304,                  /* JOIN_T  */
    LOAD = 305,                    /* LOAD  */
    DATA = 306,                    /* DATA  */
    INFILE = 307,                  /* INFILE  */
    EQ = 308,                      /* EQ  */
    LT = 309,                      /* LT  */
    GT = 310,                      /* GT  */
    LE = 311,                      /* LE  */
    GE = 312,                      /* GE  */
    NE = 313,                      /* NE  */
    EXIST_T = 314,                 /* EXIST_T  */
    IN_T = 315,                    /* IN_T  */
    LIKE = 316,                    /* LIKE  */
    NOT = 317,                     /* NOT  */
    IS = 318,                      /* IS  */
    NULLL = 319,                   /* NULLL  */
    NULLABLE = 320,                /* NULLABLE  */
    UNIQUE = 321,                  /* UNIQUE  */
    HAVING = 322,                  /* HAVING  */
    ORDER = 323,                   /* ORDER  */
    BY = 324,                      /* BY  */
    ADD = 325,                     /* ADD  */
    SUB = 326,                     /* SUB  */
    DIV = 327,                     /* DIV  */
    NUMBER = 328,                  /* NUMBER  */
    FLOAT = 329,                   /* FLOAT  */
    DATEE = 330,                   /* DATEE  */
    ID = 331,                      /* ID  */
    PATH = 332,                    /* PATH  */
    SSS = 333,                     /* SSS  */
    STAR = 334,                    /* STAR  */
    STRING_V = 335                 /* STRING_V  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 143 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  char *dates;
  int number;
  float floats;
  char *position;
  struct _AstExpr *expr1;
  enum _CompOp compOp1;

#line 157 "yacc_sql.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (void *scanner);


#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */
