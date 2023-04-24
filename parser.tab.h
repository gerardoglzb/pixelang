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
     IF = 267,
     ELSE = 268,
     PRINT = 269,
     FOR = 270,
     DO = 271,
     WHILE = 272,
     TO = 273,
     FUNCTION = 274,
     RETURN = 275,
     VOID = 276,
     ADDITION = 277,
     SUBSTRACTION = 278,
     MULTI = 279,
     DIV = 280,
     LESS_THAN = 281,
     MORE_THAN = 282,
     NOT_EQUAL = 283,
     EQUAL = 284,
     EQUAL_TO = 285,
     AND = 286,
     OR = 287,
     LEFT_PAR = 288,
     RIGHT_PAR = 289,
     LEFT_CURLY = 290,
     RIGHT_CURLY = 291,
     LEFT_BRACK = 292,
     RIGHT_BRACK = 293,
     COLON = 294,
     SEMICOLON = 295,
     COMMA = 296
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
#define IF 267
#define ELSE 268
#define PRINT 269
#define FOR 270
#define DO 271
#define WHILE 272
#define TO 273
#define FUNCTION 274
#define RETURN 275
#define VOID 276
#define ADDITION 277
#define SUBSTRACTION 278
#define MULTI 279
#define DIV 280
#define LESS_THAN 281
#define MORE_THAN 282
#define NOT_EQUAL 283
#define EQUAL 284
#define EQUAL_TO 285
#define AND 286
#define OR 287
#define LEFT_PAR 288
#define RIGHT_PAR 289
#define LEFT_CURLY 290
#define RIGHT_CURLY 291
#define LEFT_BRACK 292
#define RIGHT_BRACK 293
#define COLON 294
#define SEMICOLON 295
#define COMMA 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "parser.y"
{
    char *sval;
    int ival;
    float fval;
}
/* Line 1529 of yacc.c.  */
#line 137 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

