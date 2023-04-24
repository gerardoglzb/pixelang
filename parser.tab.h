/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CTE_INT = 258,
     CTE_FLOAT = 259,
     CTE_STRING = 260,
     ID = 261,
     PROGRAM = 262,
     MAIN = 263,
     VAR = 264,
     INT = 265,
     FLOAT = 266,
     CHAR = 267,
     IF = 268,
     ELSE = 269,
     PRINT = 270,
     FOR = 271,
     DO = 272,
     WHILE = 273,
     TO = 274,
     FUNCTION = 275,
     RETURN = 276,
     VOID = 277,
     ADDITION = 278,
     SUBSTRACTION = 279,
     MULTI = 280,
     DIV = 281,
     LESS_THAN = 282,
     MORE_THAN = 283,
     NOT_EQUAL = 284,
     EQUAL = 285,
     EQUAL_TO = 286,
     AND = 287,
     OR = 288,
     LEFT_PAR = 289,
     RIGHT_PAR = 290,
     LEFT_CURLY = 291,
     RIGHT_CURLY = 292,
     LEFT_BRACK = 293,
     RIGHT_BRACK = 294,
     COLON = 295,
     SEMICOLON = 296,
     COMMA = 297
   };
#endif
/* Tokens.  */
#define CTE_INT 258
#define CTE_FLOAT 259
#define CTE_STRING 260
#define ID 261
#define PROGRAM 262
#define MAIN 263
#define VAR 264
#define INT 265
#define FLOAT 266
#define CHAR 267
#define IF 268
#define ELSE 269
#define PRINT 270
#define FOR 271
#define DO 272
#define WHILE 273
#define TO 274
#define FUNCTION 275
#define RETURN 276
#define VOID 277
#define ADDITION 278
#define SUBSTRACTION 279
#define MULTI 280
#define DIV 281
#define LESS_THAN 282
#define MORE_THAN 283
#define NOT_EQUAL 284
#define EQUAL 285
#define EQUAL_TO 286
#define AND 287
#define OR 288
#define LEFT_PAR 289
#define RIGHT_PAR 290
#define LEFT_CURLY 291
#define RIGHT_CURLY 292
#define LEFT_BRACK 293
#define RIGHT_BRACK 294
#define COLON 295
#define SEMICOLON 296
#define COMMA 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "parser.y"
{
    char *sval;
    int ival;
    float fval;
}
/* Line 1529 of yacc.c.  */
#line 139 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

