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
     INPUT = 272,
     FINPUT = 273,
     SINPUT = 274,
     FOR = 275,
     DO = 276,
     WHILE = 277,
     TO = 278,
     FUNCTION = 279,
     RETURN = 280,
     VOID = 281,
     ADDITION = 282,
     SUBSTRACTION = 283,
     MULTI = 284,
     DIV = 285,
     MOD = 286,
     LESS_THAN = 287,
     MORE_THAN = 288,
     NOT_EQUAL = 289,
     GREATEREQ = 290,
     LESSEQ = 291,
     EQUAL = 292,
     EQUAL_TO = 293,
     AND = 294,
     OR = 295,
     NOT = 296,
     LEFT_PAR = 297,
     RIGHT_PAR = 298,
     LEFT_CURLY = 299,
     RIGHT_CURLY = 300,
     LEFT_BRACK = 301,
     RIGHT_BRACK = 302,
     COLON = 303,
     SEMICOLON = 304,
     COMMA = 305,
     ARROW = 306,
     OPEN = 307,
     GRAYSCALE = 308,
     SAVE = 309,
     BANDW = 310,
     CHANGE_COLOR = 311,
     HFLIP = 312,
     VFLIP = 313,
     CROP = 314
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
#define INPUT 272
#define FINPUT 273
#define SINPUT 274
#define FOR 275
#define DO 276
#define WHILE 277
#define TO 278
#define FUNCTION 279
#define RETURN 280
#define VOID 281
#define ADDITION 282
#define SUBSTRACTION 283
#define MULTI 284
#define DIV 285
#define MOD 286
#define LESS_THAN 287
#define MORE_THAN 288
#define NOT_EQUAL 289
#define GREATEREQ 290
#define LESSEQ 291
#define EQUAL 292
#define EQUAL_TO 293
#define AND 294
#define OR 295
#define NOT 296
#define LEFT_PAR 297
#define RIGHT_PAR 298
#define LEFT_CURLY 299
#define RIGHT_CURLY 300
#define LEFT_BRACK 301
#define RIGHT_BRACK 302
#define COLON 303
#define SEMICOLON 304
#define COMMA 305
#define ARROW 306
#define OPEN 307
#define GRAYSCALE 308
#define SAVE 309
#define BANDW 310
#define CHANGE_COLOR 311
#define HFLIP 312
#define VFLIP 313
#define CROP 314




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
#line 183 "./bin/parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

