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
     FOREACH = 269,
     IN = 270,
     FOR = 271,
     DO = 272,
     END = 273,
     FUNCTION = 274,
     RETURN = 275,
     SUMA = 276,
     RESTA = 277,
     MULTI = 278,
     DIV = 279,
     MENOR_QUE = 280,
     MAYOR_QUE = 281,
     NO_IGUAL = 282,
     IGUAL = 283,
     PLUS = 284,
     MINUS = 285,
     PAR_IZQ = 286,
     PAR_DER = 287,
     LLAVE_IZQ = 288,
     LLAVE_DER = 289,
     CORCH_IZQ = 290,
     CORCH_DER = 291,
     DOS_PUNTOS = 292,
     PUNTO_COMA = 293,
     COMA = 294
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
#define FOREACH 269
#define IN 270
#define FOR 271
#define DO 272
#define END 273
#define FUNCTION 274
#define RETURN 275
#define SUMA 276
#define RESTA 277
#define MULTI 278
#define DIV 279
#define MENOR_QUE 280
#define MAYOR_QUE 281
#define NO_IGUAL 282
#define IGUAL 283
#define PLUS 284
#define MINUS 285
#define PAR_IZQ 286
#define PAR_DER 287
#define LLAVE_IZQ 288
#define LLAVE_DER 289
#define CORCH_IZQ 290
#define CORCH_DER 291
#define DOS_PUNTOS 292
#define PUNTO_COMA 293
#define COMA 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "parser.y"
{
    char *sval;
    int ival;
    float fval;
}
/* Line 1529 of yacc.c.  */
#line 133 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

