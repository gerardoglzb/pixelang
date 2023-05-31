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
     IMAGE = 268,
     IF = 269,
     ELSE = 270,
     PRINT = 271,
     FOR = 272,
     DO = 273,
     WHILE = 274,
     TO = 275,
     FUNCTION = 276,
     RETURN = 277,
     VOID = 278,
     ADDITION = 279,
     SUBSTRACTION = 280,
     MULTI = 281,
     DIV = 282,
     MOD = 283,
     LESS_THAN = 284,
     MORE_THAN = 285,
     NOT_EQUAL = 286,
     GREATEREQ = 287,
     LESSEQ = 288,
     EQUAL = 289,
     EQUAL_TO = 290,
     AND = 291,
     OR = 292,
     NOT = 293,
     LEFT_PAR = 294,
     RIGHT_PAR = 295,
     LEFT_CURLY = 296,
     RIGHT_CURLY = 297,
     LEFT_BRACK = 298,
     RIGHT_BRACK = 299,
     COLON = 300,
     SEMICOLON = 301,
     COMMA = 302,
     ARROW = 303,
     OPEN = 304,
     GRAYSCALE = 305,
     SAVE = 306
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
#define IMAGE 268
#define IF 269
#define ELSE 270
#define PRINT 271
#define FOR 272
#define DO 273
#define WHILE 274
#define TO 275
#define FUNCTION 276
#define RETURN 277
#define VOID 278
#define ADDITION 279
#define SUBSTRACTION 280
#define MULTI 281
#define DIV 282
#define MOD 283
#define LESS_THAN 284
#define MORE_THAN 285
#define NOT_EQUAL 286
#define GREATEREQ 287
#define LESSEQ 288
#define EQUAL 289
#define EQUAL_TO 290
#define AND 291
#define OR 292
#define NOT 293
#define LEFT_PAR 294
#define RIGHT_PAR 295
#define LEFT_CURLY 296
#define RIGHT_CURLY 297
#define LEFT_BRACK 298
#define RIGHT_BRACK 299
#define COLON 300
#define SEMICOLON 301
#define COMMA 302
#define ARROW 303
#define OPEN 304
#define GRAYSCALE 305
#define SAVE 306




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
    struct ParamNode *paramNode;
    int chType;
    int ivar;
    int iparam;
    int iarray;
    int imgFunc;
}
/* Line 1529 of yacc.c.  */
#line 167 "./bin/parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

