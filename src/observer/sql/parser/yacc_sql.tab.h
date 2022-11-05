/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_OBSERVER_SQL_PARSER_YACC_SQL_TAB_H_INCLUDED
# define YY_YY_SRC_OBSERVER_SQL_PARSER_YACC_SQL_TAB_H_INCLUDED
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
    INSERT = 269,                  /* INSERT  */
    DELETE = 270,                  /* DELETE  */
    UPDATE = 271,                  /* UPDATE  */
    LBRACE = 272,                  /* LBRACE  */
    RBRACE = 273,                  /* RBRACE  */
    COMMA = 274,                   /* COMMA  */
    TRX_BEGIN = 275,               /* TRX_BEGIN  */
    COUNT_T = 276,                 /* COUNT_T  */
    MAX_T = 277,                   /* MAX_T  */
    MIN_T = 278,                   /* MIN_T  */
    AVG_T = 279,                   /* AVG_T  */
    SUM_T = 280,                   /* SUM_T  */
    TRX_COMMIT = 281,              /* TRX_COMMIT  */
    DABIAO = 282,                  /* DABIAO  */
    TRX_ROLLBACK = 283,            /* TRX_ROLLBACK  */
    INT_T = 284,                   /* INT_T  */
    STRING_T = 285,                /* STRING_T  */
    FLOAT_T = 286,                 /* FLOAT_T  */
    DATE_T = 287,                  /* DATE_T  */
    TEXT_T = 288,                  /* TEXT_T  */
    HELP = 289,                    /* HELP  */
    EXIT = 290,                    /* EXIT  */
    DOT = 291,                     /* DOT  */
    INTO = 292,                    /* INTO  */
    VALUES = 293,                  /* VALUES  */
    FROM = 294,                    /* FROM  */
    WHERE = 295,                   /* WHERE  */
    AS = 296,                      /* AS  */
    AND = 297,                     /* AND  */
    SET = 298,                     /* SET  */
    ON = 299,                      /* ON  */
    INNER_T = 300,                 /* INNER_T  */
    JOIN_T = 301,                  /* JOIN_T  */
    LOAD = 302,                    /* LOAD  */
    DATA = 303,                    /* DATA  */
    INFILE = 304,                  /* INFILE  */
    EQ = 305,                      /* EQ  */
    LT = 306,                      /* LT  */
    GT = 307,                      /* GT  */
    LE = 308,                      /* LE  */
    GE = 309,                      /* GE  */
    NE = 310,                      /* NE  */
    EXIST_T = 311,                 /* EXIST_T  */
    IN_T = 312,                    /* IN_T  */
    LIKE = 313,                    /* LIKE  */
    NOT = 314,                     /* NOT  */
    IS = 315,                      /* IS  */
    NULLL = 316,                   /* NULLL  */
    NULLABLE = 317,                /* NULLABLE  */
    UNIQUE = 318,                  /* UNIQUE  */
    ORDER = 319,                   /* ORDER  */
    BY = 320,                      /* BY  */
    ADD = 321,                     /* ADD  */
    SUB = 322,                     /* SUB  */
    DIV = 323,                     /* DIV  */
    NUMBER = 324,                  /* NUMBER  */
    FLOAT = 325,                   /* FLOAT  */
    DATEE = 326,                   /* DATEE  */
    ID = 327,                      /* ID  */
    PATH = 328,                    /* PATH  */
    SSS = 329,                     /* SSS  */
    STAR = 330,                    /* STAR  */
    STRING_V = 331                 /* STRING_V  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 140 "./src/observer/sql/parser/yacc_sql.y"

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

#line 153 "./src/observer/sql/parser/yacc_sql.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_SRC_OBSERVER_SQL_PARSER_YACC_SQL_TAB_H_INCLUDED  */
