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
     STRING = 268,
     IMAGE = 269,
     IF = 270,
     ELSE = 271,
     PRINT = 272,
     INPUT = 273,
     FINPUT = 274,
     SINPUT = 275,
     FOR = 276,
     DO = 277,
     WHILE = 278,
     TO = 279,
     FUNCTION = 280,
     RETURN = 281,
     VOID = 282,
     ADDITION = 283,
     SUBSTRACTION = 284,
     MULTI = 285,
     DIV = 286,
     MOD = 287,
     LESS_THAN = 288,
     MORE_THAN = 289,
     NOT_EQUAL = 290,
     GREATEREQ = 291,
     LESSEQ = 292,
     EQUAL = 293,
     EQUAL_TO = 294,
     AND = 295,
     OR = 296,
     NOT = 297,
     LEFT_PAR = 298,
     RIGHT_PAR = 299,
     LEFT_CURLY = 300,
     RIGHT_CURLY = 301,
     LEFT_BRACK = 302,
     RIGHT_BRACK = 303,
     COLON = 304,
     SEMICOLON = 305,
     COMMA = 306,
     ARROW = 307,
     OPEN = 308,
     GRAYSCALE = 309,
     SAVE = 310,
     BANDW = 311,
     CHANGE_COLOR = 312,
     HFLIP = 313,
     VFLIP = 314,
     CROP = 315
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
#define STRING 268
#define IMAGE 269
#define IF 270
#define ELSE 271
#define PRINT 272
#define INPUT 273
#define FINPUT 274
#define SINPUT 275
#define FOR 276
#define DO 277
#define WHILE 278
#define TO 279
#define FUNCTION 280
#define RETURN 281
#define VOID 282
#define ADDITION 283
#define SUBSTRACTION 284
#define MULTI 285
#define DIV 286
#define MOD 287
#define LESS_THAN 288
#define MORE_THAN 289
#define NOT_EQUAL 290
#define GREATEREQ 291
#define LESSEQ 292
#define EQUAL 293
#define EQUAL_TO 294
#define AND 295
#define OR 296
#define NOT 297
#define LEFT_PAR 298
#define RIGHT_PAR 299
#define LEFT_CURLY 300
#define RIGHT_CURLY 301
#define LEFT_BRACK 302
#define RIGHT_BRACK 303
#define COLON 304
#define SEMICOLON 305
#define COMMA 306
#define ARROW 307
#define OPEN 308
#define GRAYSCALE 309
#define SAVE 310
#define BANDW 311
#define CHANGE_COLOR 312
#define HFLIP 313
#define VFLIP 314
#define CROP 315




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
#line 185 "./bin/parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

