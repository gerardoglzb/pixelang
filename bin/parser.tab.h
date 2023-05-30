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
     CTE_BOOL = 260,
     CTE_STRING = 261,
     ID = 262,
     PROGRAM = 263,
     VAR = 264,
     INT = 265,
     FLOAT = 266,
     BOOL = 267,
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
     MOD = 282,
     LESS_THAN = 283,
     MORE_THAN = 284,
     NOT_EQUAL = 285,
     GREATEREQ = 286,
     LESSEQ = 287,
     EQUAL = 288,
     EQUAL_TO = 289,
     AND = 290,
     OR = 291,
     NOT = 292,
     LEFT_PAR = 293,
     RIGHT_PAR = 294,
     LEFT_CURLY = 295,
     RIGHT_CURLY = 296,
     LEFT_BRACK = 297,
     RIGHT_BRACK = 298,
     COLON = 299,
     SEMICOLON = 300,
     COMMA = 301
   };
#endif
/* Tokens.  */
#define CTE_INT 258
#define CTE_FLOAT 259
#define CTE_BOOL 260
#define CTE_STRING 261
#define ID 262
#define PROGRAM 263
#define VAR 264
#define INT 265
#define FLOAT 266
#define BOOL 267
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
#define MOD 282
#define LESS_THAN 283
#define MORE_THAN 284
#define NOT_EQUAL 285
#define GREATEREQ 286
#define LESSEQ 287
#define EQUAL 288
#define EQUAL_TO 289
#define AND 290
#define OR 291
#define NOT 292
#define LEFT_PAR 293
#define RIGHT_PAR 294
#define LEFT_CURLY 295
#define RIGHT_CURLY 296
#define LEFT_BRACK 297
#define RIGHT_BRACK 298
#define COLON 299
#define SEMICOLON 300
#define COMMA 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 17 "./src/parser.y"
{
    char *sval;
    char *strval;
    int ival;
    float fval;
    bool bval;
    struct IDNode *nodeID;
    struct ArrayNode *arrNode;
    int chType;
    int ivar;
    int iparam;
    int iarray;
}
/* Line 1529 of yacc.c.  */
#line 155 "./bin/parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

