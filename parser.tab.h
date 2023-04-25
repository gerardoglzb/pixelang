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
     VAR = 263,
     INT = 264,
     FLOAT = 265,
     IF = 266,
     ELSE = 267,
     PRINT = 268,
     FOR = 269,
     DO = 270,
     WHILE = 271,
     TO = 272,
     FUNCTION = 273,
     RETURN = 274,
     VOID = 275,
     ADDITION = 276,
     SUBSTRACTION = 277,
     MULTI = 278,
     DIV = 279,
     LESS_THAN = 280,
     MORE_THAN = 281,
     NOT_EQUAL = 282,
     EQUAL = 283,
     EQUAL_TO = 284,
     AND = 285,
     OR = 286,
     LEFT_PAR = 287,
     RIGHT_PAR = 288,
     LEFT_CURLY = 289,
     RIGHT_CURLY = 290,
     LEFT_BRACK = 291,
     RIGHT_BRACK = 292,
     COLON = 293,
     SEMICOLON = 294,
     COMMA = 295
   };
#endif
/* Tokens.  */
#define CTE_INT 258
#define CTE_FLOAT 259
#define CTE_STRING 260
#define ID 261
#define PROGRAM 262
#define VAR 263
#define INT 264
#define FLOAT 265
#define IF 266
#define ELSE 267
#define PRINT 268
#define FOR 269
#define DO 270
#define WHILE 271
#define TO 272
#define FUNCTION 273
#define RETURN 274
#define VOID 275
#define ADDITION 276
#define SUBSTRACTION 277
#define MULTI 278
#define DIV 279
#define LESS_THAN 280
#define MORE_THAN 281
#define NOT_EQUAL 282
#define EQUAL 283
#define EQUAL_TO 284
#define AND 285
#define OR 286
#define LEFT_PAR 287
#define RIGHT_PAR 288
#define LEFT_CURLY 289
#define RIGHT_CURLY 290
#define LEFT_BRACK 291
#define RIGHT_BRACK 292
#define COLON 293
#define SEMICOLON 294
#define COMMA 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "parser.y"
{
    char *sval;
    int ival;
    float fval;
    struct IDNode *nodeID;
    char chType;
}
/* Line 1529 of yacc.c.  */
#line 137 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

