/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "./src/parser.y"

    #include <iostream>
    #include "../include/compiler.hpp"
    using namespace std;

    extern "C" FILE *yyin;
    extern "C" char *yytext;
    extern "C" int yylex();
    extern "C" int yyparse();

    extern "C" int lineas;
    extern "C" FunctionDirectory functionDirectory;
     
    void yyerror(const char *s);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 246 "./bin/parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 259 "./bin/parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNRULES -- Number of states.  */
#define YYNSTATES  259

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    14,    19,    20,    25,    29,
      31,    34,    38,    40,    44,    47,    48,    49,    50,    51,
      66,    68,    70,    71,    78,    79,    83,    87,    89,    91,
      93,    95,   101,   105,   106,   107,   111,   112,   116,   117,
     121,   122,   123,   127,   129,   130,   134,   135,   139,   140,
     144,   145,   149,   150,   154,   155,   159,   160,   164,   165,
     166,   170,   171,   175,   176,   180,   181,   182,   187,   189,
     190,   191,   195,   196,   200,   201,   205,   206,   207,   211,
     212,   217,   219,   221,   223,   225,   227,   228,   229,   235,
     236,   239,   240,   243,   245,   246,   251,   252,   256,   257,
     258,   263,   264,   267,   268,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   293,   295,   297,   299,
     307,   314,   316,   320,   321,   326,   328,   329,   333,   334,
     335,   336,   345,   346,   350,   351,   352,   357,   358,   359,
     367,   368,   369,   375,   376,   380,   384,   388,   390,   392,
     393,   398,   400,   401,   408,   410,   412,   413,   414,   423,
     424,   425,   426,   427
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      61,     0,    -1,    -1,    -1,     8,     7,    62,    49,    64,
      69,    63,    78,    -1,     9,    65,    49,    64,    -1,    -1,
      68,    48,    79,    66,    -1,    68,    48,    79,    -1,    67,
      -1,    67,    66,    -1,    46,     3,    47,    -1,     7,    -1,
       7,    50,    68,    -1,    70,    69,    -1,    -1,    -1,    -1,
      -1,    24,     7,    71,    42,    80,    43,    48,    72,    74,
      44,    64,    73,   124,    45,    -1,    79,    -1,    26,    -1,
      -1,    25,    76,    42,    81,    43,    49,    -1,    -1,    25,
      77,    49,    -1,    44,   124,    45,    -1,    10,    -1,    11,
      -1,    12,    -1,    13,    -1,     7,    48,    79,    50,    80,
      -1,     7,    48,    79,    -1,    -1,    -1,    86,    82,    83,
      -1,    -1,    39,    84,    81,    -1,    -1,    40,    85,    81,
      -1,    -1,    -1,    41,    87,    88,    -1,    88,    -1,    -1,
      97,    89,    90,    -1,    -1,    33,    91,    88,    -1,    -1,
      32,    92,    88,    -1,    -1,    38,    93,    88,    -1,    -1,
      34,    94,    88,    -1,    -1,    35,    95,    88,    -1,    -1,
      36,    96,    88,    -1,    -1,    -1,   102,    98,    99,    -1,
      -1,    27,   100,    97,    -1,    -1,    28,   101,    97,    -1,
      -1,    -1,   104,   109,   103,   105,    -1,    28,    -1,    -1,
      -1,    29,   106,   102,    -1,    -1,    30,   107,   102,    -1,
      -1,    31,   108,   102,    -1,    -1,    -1,     7,   110,   113,
      -1,    -1,    42,   111,    81,    43,    -1,   112,    -1,   146,
      -1,     4,    -1,     3,    -1,     5,    -1,    -1,    -1,   114,
      42,   115,   120,    43,    -1,    -1,   116,   117,    -1,    -1,
     118,   117,    -1,   118,    -1,    -1,    46,    81,   119,    47,
      -1,    -1,    81,   121,   122,    -1,    -1,    -1,    50,    81,
     123,   122,    -1,    -1,   125,   124,    -1,    -1,   129,    49,
      -1,   127,    -1,   133,    -1,   141,    -1,   148,    -1,   152,
      -1,    75,    -1,    53,    -1,    54,    -1,    52,    -1,    55,
      -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,     7,
      51,   126,    42,   128,    43,    49,    -1,     7,    51,   126,
      42,    43,    49,    -1,   147,    -1,   147,    50,   128,    -1,
      -1,   131,    37,   130,    81,    -1,     7,    -1,    -1,     7,
     132,   117,    -1,    -1,    -1,    -1,     7,   134,    42,   135,
     137,    43,   136,    49,    -1,    -1,    81,   138,   139,    -1,
      -1,    -1,    50,    81,   140,   139,    -1,    -1,    -1,    16,
     142,    42,   147,   143,    43,    49,    -1,    -1,    -1,   144,
      50,   145,   147,   143,    -1,    -1,    17,    42,    43,    -1,
      18,    42,    43,    -1,    19,    42,    43,    -1,    81,    -1,
       6,    -1,    -1,   150,    15,   149,    78,    -1,   150,    -1,
      -1,    14,    42,    81,    43,   151,    78,    -1,   153,    -1,
     156,    -1,    -1,    -1,    22,   154,    42,    81,    43,   155,
      21,    78,    -1,    -1,    -1,    -1,    -1,    20,   157,    42,
     129,   158,    23,    81,   159,    43,   160,    78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   109,   109,   112,   109,   120,   123,   128,   132,   137,
     141,   147,   152,   156,   162,   163,   166,   168,   170,   166,
     183,   186,   191,   191,   198,   198,   204,   207,   208,   209,
     210,   213,   217,   221,   226,   226,   231,   231,   234,   234,
     237,   240,   240,   245,   248,   248,   253,   253,   256,   256,
     259,   259,   262,   262,   265,   265,   268,   268,   271,   274,
     274,   279,   279,   282,   282,   285,   288,   288,   294,   298,
     304,   304,   307,   307,   310,   310,   313,   316,   316,   319,
     319,   324,   325,   328,   331,   334,   339,   342,   339,   353,
     353,   359,   364,   365,   368,   368,   375,   375,   378,   381,
     381,   384,   387,   388,   391,   392,   393,   394,   395,   396,
     397,   400,   403,   406,   409,   412,   415,   418,   421,   426,
     430,   436,   441,   448,   448,   455,   458,   458,   467,   469,
     473,   467,   480,   480,   483,   486,   486,   489,   492,   492,
     500,   503,   500,   506,   509,   512,   515,   520,   521,   526,
     526,   531,   536,   536,   541,   542,   545,   547,   545,   554,
     556,   560,   565,   554
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CTE_INT", "CTE_FLOAT", "CTE_BOOL",
  "CTE_STRING", "ID", "PROGRAM", "VAR", "INT", "FLOAT", "BOOL", "IMAGE",
  "IF", "ELSE", "PRINT", "INPUT", "FINPUT", "SINPUT", "FOR", "DO", "WHILE",
  "TO", "FUNCTION", "RETURN", "VOID", "ADDITION", "SUBSTRACTION", "MULTI",
  "DIV", "MOD", "LESS_THAN", "MORE_THAN", "NOT_EQUAL", "GREATEREQ",
  "LESSEQ", "EQUAL", "EQUAL_TO", "AND", "OR", "NOT", "LEFT_PAR",
  "RIGHT_PAR", "LEFT_CURLY", "RIGHT_CURLY", "LEFT_BRACK", "RIGHT_BRACK",
  "COLON", "SEMICOLON", "COMMA", "ARROW", "OPEN", "GRAYSCALE", "SAVE",
  "BANDW", "CHANGE_COLOR", "HFLIP", "VFLIP", "CROP", "$accept", "program",
  "@1", "@2", "vars", "var", "array_list", "array_declaration", "var_list",
  "functions", "function", "@3", "@4", "@5", "function_type", "return",
  "@6", "@7", "block", "type", "params", "expression", "@8", "expression2",
  "@9", "@10", "not_expression", "@11", "comp", "@12", "comp2", "@13",
  "@14", "@15", "@16", "@17", "@18", "exp", "@19", "exp2", "@20", "@21",
  "term", "@22", "negation", "term2", "@23", "@24", "@25", "factor", "@26",
  "@27", "var_cte", "array_or_func", "@28", "@29", "@30", "arrays",
  "array", "@31", "arguments", "@32", "arguments2", "@33", "statements",
  "statement", "image_function", "image_call", "image_arguments",
  "assignment", "@34", "assignee", "@35", "call", "@36", "@37", "@38",
  "call2", "@39", "call3", "@40", "printing", "@41", "printing_2", "@42",
  "@43", "inputting", "expression_or_str", "conditional", "@44",
  "conditional_if", "@45", "repetition", "rep_cond", "@46", "@47",
  "rep_no_cond", "@48", "@49", "@50", "@51", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    62,    63,    61,    64,    64,    65,    65,    66,
      66,    67,    68,    68,    69,    69,    71,    72,    73,    70,
      74,    74,    76,    75,    77,    75,    78,    79,    79,    79,
      79,    80,    80,    80,    82,    81,    84,    83,    85,    83,
      83,    87,    86,    86,    89,    88,    91,    90,    92,    90,
      93,    90,    94,    90,    95,    90,    96,    90,    90,    98,
      97,   100,    99,   101,    99,    99,   103,   102,   104,   104,
     106,   105,   107,   105,   108,   105,   105,   110,   109,   111,
     109,   109,   109,   112,   112,   112,   114,   115,   113,   116,
     113,   113,   117,   117,   119,   118,   121,   120,   120,   123,
     122,   122,   124,   124,   125,   125,   125,   125,   125,   125,
     125,   126,   126,   126,   126,   126,   126,   126,   126,   127,
     127,   128,   128,   130,   129,   131,   132,   131,   134,   135,
     136,   133,   138,   137,   137,   140,   139,   139,   142,   141,
     144,   145,   143,   143,   146,   146,   146,   147,   147,   149,
     148,   148,   151,   150,   152,   152,   154,   155,   153,   157,
     158,   159,   160,   156
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     4,     0,     4,     3,     1,
       2,     3,     1,     3,     2,     0,     0,     0,     0,    14,
       1,     1,     0,     6,     0,     3,     3,     1,     1,     1,
       1,     5,     3,     0,     0,     3,     0,     3,     0,     3,
       0,     0,     3,     1,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     0,
       3,     0,     3,     0,     3,     0,     0,     4,     1,     0,
       0,     3,     0,     3,     0,     3,     0,     0,     3,     0,
       4,     1,     1,     1,     1,     1,     0,     0,     5,     0,
       2,     0,     2,     1,     0,     4,     0,     3,     0,     0,
       4,     0,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       6,     1,     3,     0,     4,     1,     0,     3,     0,     0,
       0,     8,     0,     3,     0,     0,     4,     0,     0,     7,
       0,     0,     5,     0,     3,     3,     3,     1,     1,     0,
       4,     1,     0,     6,     1,     1,     0,     0,     8,     0,
       0,     0,     0,    11
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     6,     0,    15,    12,
       0,     0,     0,     3,    15,     0,     6,     0,    16,     0,
      14,    13,     5,    27,    28,    29,    30,     8,     0,   103,
       4,     0,     7,     9,    33,   125,     0,   138,   159,   156,
      22,   110,     0,   103,   105,     0,     0,   106,   107,   108,
     151,   109,   154,   155,     0,    10,     0,     0,     0,     0,
       0,    69,     0,     0,     0,     0,     0,    26,   102,   104,
     123,   149,    11,     0,     0,   113,   111,   112,   114,   115,
     116,   117,   118,     0,    69,   127,    93,   129,    68,    41,
       0,    34,    43,    44,    59,     0,    69,     0,    69,    69,
      25,    69,     0,    32,    17,    69,    94,    92,    69,    69,
     152,    40,    58,    65,    84,    83,    85,    77,     0,     0,
       0,    79,    66,    81,    82,   148,   147,   140,   125,   160,
       0,     0,   124,   150,    33,     0,     0,     0,   121,     0,
     132,     0,    42,     0,    36,    38,    35,    48,    46,    52,
      54,    56,    50,    45,    61,    63,    60,    91,     0,     0,
       0,    69,    76,     0,     0,     0,   157,     0,    31,    21,
       0,    20,   120,     0,    69,    95,   137,   130,   153,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    78,
       0,     0,   144,   145,   146,     0,    70,    72,    74,    67,
       0,   141,    69,     0,    23,     6,   119,   122,    69,   133,
       0,    37,    39,    49,    47,    53,    55,    57,    51,    62,
      64,    87,    90,    80,    69,    69,    69,   139,    69,   161,
       0,    18,   135,   131,    69,    71,    73,    75,   140,     0,
     158,   103,   137,    96,     0,   142,   162,     0,   136,   101,
      88,     0,    19,    69,    97,   163,    99,   101,   100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    19,     8,    10,    32,    33,    11,    13,
      14,    28,   135,   241,   170,    41,    65,    66,    30,    27,
      57,   126,   111,   146,   179,   180,    91,   109,    92,   112,
     153,   182,   181,   186,   183,   184,   185,    93,   113,   156,
     187,   188,    94,   162,    95,   199,   224,   225,   226,   122,
     157,   161,   123,   189,   190,   234,   191,    85,    86,   139,
     244,   249,   254,   257,    42,    43,    83,    44,   137,    45,
     101,    46,    59,    47,    60,   108,   210,   141,   176,   209,
     242,    48,    62,   163,   164,   228,   124,   138,    49,   102,
      50,   143,    51,    52,    64,   203,    53,    63,   165,   239,
     251
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -130
static const yytype_int16 yypact[] =
{
       1,     7,    17,  -130,  -130,   -21,    28,    40,    30,     6,
       3,    20,    68,  -130,    30,    40,    28,    53,  -130,    33,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,    54,    62,    35,
    -130,   102,  -130,    54,    99,    16,    65,  -130,  -130,  -130,
      59,  -130,    64,    35,  -130,    66,    74,  -130,  -130,  -130,
      97,  -130,  -130,  -130,    67,  -130,    69,    70,    32,    72,
      79,   -18,    80,    81,    82,    83,    77,  -130,  -130,  -130,
    -130,  -130,  -130,    53,    84,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,    85,   -18,  -130,    72,  -130,  -130,  -130,
      73,  -130,  -130,  -130,  -130,     8,    12,   121,   -18,   -18,
    -130,   -18,    33,    87,  -130,     2,  -130,  -130,   -12,   101,
    -130,    -6,    38,    71,  -130,  -130,  -130,  -130,    88,    91,
      92,  -130,  -130,  -130,  -130,  -130,  -130,    95,    89,  -130,
      96,    98,  -130,  -130,    99,     9,    94,   103,    90,   100,
    -130,   106,  -130,    33,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,   -10,   107,   108,
     110,   -18,    63,   111,   105,   122,  -130,   109,  -130,  -130,
     112,  -130,  -130,   113,    12,  -130,   114,  -130,  -130,   -18,
     -18,   101,   101,   101,   101,   101,   101,   101,   101,  -130,
     115,    72,  -130,  -130,  -130,   116,  -130,  -130,  -130,  -130,
     117,  -130,   -18,   123,  -130,    28,  -130,  -130,   -18,  -130,
     118,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,   101,   101,   101,  -130,    12,  -130,
      33,  -130,  -130,  -130,    18,  -130,  -130,  -130,    95,   120,
    -130,    35,   114,  -130,   125,  -130,  -130,   124,  -130,   126,
    -130,    33,  -130,   -18,  -130,  -130,  -130,   126,  -130
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,  -130,  -130,   -14,  -130,   127,  -130,   146,   151,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,   -99,   -66,
      36,   -60,  -130,  -130,  -130,  -130,  -130,  -130,  -103,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,   -85,  -130,  -130,
    -130,  -130,  -129,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,   -81,  -130,  -130,
    -130,  -130,   -86,  -130,   -43,  -130,  -130,  -130,    -2,    76,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,   -67,
    -130,  -130,  -130,   -61,  -130,  -130,  -130,   -92,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -144
static const yytype_int16 yytable[] =
{
      68,    90,    22,   133,   127,   107,   142,   103,   125,     1,
      88,   114,   115,   116,     3,   117,    88,     4,   125,    23,
      24,    25,    26,    89,   106,   118,   119,   120,     6,    89,
      88,  -134,   -86,   144,   145,   169,   -89,     7,   130,   131,
      88,   132,    35,    89,   178,   136,    88,     9,   140,    36,
     121,    37,    16,    89,    12,    38,    15,    39,  -128,    89,
      40,   -98,  -126,    23,    24,    25,    26,    58,    17,   171,
     147,   148,   149,   150,   151,    18,   152,    29,   213,   214,
     215,   216,   217,   218,    75,    76,    77,    78,    79,    80,
      81,    82,   196,   197,   198,   235,   236,   237,   154,   155,
      31,   195,   219,   220,    34,    54,    56,    61,   -24,    67,
     222,    70,    71,    74,    72,    69,   110,    73,    84,   211,
     212,    87,    96,    97,    98,    99,   100,   105,   128,    88,
     158,   240,   104,   159,   160,  -126,   238,   134,  -143,   166,
     174,   167,   229,   172,   230,   202,   173,   175,   232,   177,
     192,   193,   255,   194,   200,   201,   205,   221,   204,   223,
      55,    21,   206,   246,   208,    20,   227,   233,   250,   252,
     168,   258,   207,   129,   243,   248,   253,   245,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   231,     0,   256,     0,     0,     0,     0,   247
};

static const yytype_int16 yycheck[] =
{
      43,    61,    16,   102,    96,    86,   109,    73,     6,     8,
      28,     3,     4,     5,     7,     7,    28,     0,     6,    10,
      11,    12,    13,    41,    84,    17,    18,    19,    49,    41,
      28,    43,    42,    39,    40,    26,    46,     9,    98,    99,
      28,   101,     7,    41,   143,    43,    28,     7,   108,    14,
      42,    16,    49,    41,    24,    20,    50,    22,    42,    41,
      25,    43,    46,    10,    11,    12,    13,    51,    48,   135,
      32,    33,    34,    35,    36,     7,    38,    44,   181,   182,
     183,   184,   185,   186,    52,    53,    54,    55,    56,    57,
      58,    59,    29,    30,    31,   224,   225,   226,    27,    28,
      46,   161,   187,   188,    42,     3,     7,    42,    49,    45,
     191,    37,    15,    43,    47,    49,    43,    48,    46,   179,
     180,    42,    42,    42,    42,    42,    49,    42,     7,    28,
      42,   230,    48,    42,    42,    46,   228,    50,    43,    43,
      50,    43,   202,    49,    21,    23,    43,    47,   208,    43,
      43,    43,   251,    43,    43,    50,    44,    42,    49,    43,
      33,    15,    49,    43,    50,    14,    49,    49,    43,    45,
     134,   257,   174,    97,   234,   242,    50,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,    -1,   253,    -1,    -1,    -1,    -1,   241
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    61,     7,     0,    62,    49,     9,    64,     7,
      65,    68,    24,    69,    70,    50,    49,    48,     7,    63,
      69,    68,    64,    10,    11,    12,    13,    79,    71,    44,
      78,    46,    66,    67,    42,     7,    14,    16,    20,    22,
      25,    75,   124,   125,   127,   129,   131,   133,   141,   148,
     150,   152,   153,   156,     3,    66,     7,    80,    51,   132,
     134,    42,   142,   157,   154,    76,    77,    45,   124,    49,
      37,    15,    47,    48,    43,    52,    53,    54,    55,    56,
      57,    58,    59,   126,    46,   117,   118,    42,    28,    41,
      81,    86,    88,    97,   102,   104,    42,    42,    42,    42,
      49,   130,   149,    79,    48,    42,    81,   117,   135,    87,
      43,    82,    89,    98,     3,     4,     5,     7,    17,    18,
      19,    42,   109,   112,   146,     6,    81,   147,     7,   129,
      81,    81,    81,    78,    50,    72,    43,   128,   147,   119,
      81,   137,    88,   151,    39,    40,    83,    32,    33,    34,
      35,    36,    38,    90,    27,    28,    99,   110,    42,    42,
      42,   111,   103,   143,   144,   158,    43,    43,    80,    26,
      74,    79,    49,    43,    50,    47,   138,    43,    78,    84,
      85,    92,    91,    94,    95,    96,    93,   100,   101,   113,
     114,   116,    43,    43,    43,    81,    29,    30,    31,   105,
      43,    50,    23,   155,    49,    44,    49,   128,    50,   139,
     136,    81,    81,    88,    88,    88,    88,    88,    88,    97,
      97,    42,   117,    43,   106,   107,   108,    49,   145,    81,
      21,    64,    81,    49,   115,   102,   102,   102,   147,   159,
      78,    73,   140,    81,   120,   143,    43,   124,   139,   121,
      43,   160,    45,    50,   122,    78,    81,   123,   122
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 109 "./src/parser.y"
    {
        declareMainFunction((yyvsp[(2) - (2)].sval), lineas, &functionDirectory);
        setProgramName((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 3:
#line 112 "./src/parser.y"
    {
        fillMain();
    ;}
    break;

  case 4:
#line 114 "./src/parser.y"
    {
        printf("Valid syntax.\n");
        generateObject();
    ;}
    break;

  case 5:
#line 120 "./src/parser.y"
    {
        (yyval.ivar) = (yyvsp[(4) - (4)].ivar) + 1;
    ;}
    break;

  case 6:
#line 123 "./src/parser.y"
    {
        (yyval.ivar) = 0;
    ;}
    break;

  case 7:
#line 128 "./src/parser.y"
    {
        (yyvsp[(4) - (4)].arrNode)->calculateRs();
        declareVariables((yyvsp[(1) - (4)].nodeID), (yyvsp[(3) - (4)].chType), (yyvsp[(4) - (4)].arrNode), lineas);
    ;}
    break;

  case 8:
#line 132 "./src/parser.y"
    {
        declareVariables((yyvsp[(1) - (3)].nodeID), (yyvsp[(3) - (3)].chType), nullptr, lineas);
    ;}
    break;

  case 9:
#line 137 "./src/parser.y"
    {
        ArrayNode *node = new ArrayNode((yyvsp[(1) - (1)].iarray));
        (yyval.arrNode) = node;
    ;}
    break;

  case 10:
#line 141 "./src/parser.y"
    {
        ArrayNode *node = new ArrayNode((yyvsp[(1) - (2)].iarray), (yyvsp[(2) - (2)].arrNode));
        (yyval.arrNode) = node;
    ;}
    break;

  case 11:
#line 147 "./src/parser.y"
    {
        (yyval.iarray) = (yyvsp[(2) - (3)].ival);
    ;}
    break;

  case 12:
#line 152 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (1)].sval));
        (yyval.nodeID) = node;
    ;}
    break;

  case 13:
#line 156 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].nodeID));
        (yyval.nodeID) = node;
    ;}
    break;

  case 16:
#line 166 "./src/parser.y"
    {
        declareFunction((yyvsp[(2) - (2)].sval), 7, lineas);
    ;}
    break;

  case 17:
#line 168 "./src/parser.y"
    {
        setCurrentParamCount((yyvsp[(5) - (7)].iparam));
    ;}
    break;

  case 18:
#line 170 "./src/parser.y"
    {
        setCurrentLocalVarCount((yyvsp[(11) - (11)].ivar));
        setCurrentCurrQuad();
        setCurrentFuncType((yyvsp[(9) - (11)].chType));
        setCurrentFunc((yyvsp[(2) - (11)].sval));
        createReturnAddress();
    ;}
    break;

  case 19:
#line 176 "./src/parser.y"
    {
        popReturnAddress();
        generateEndFunc();
        functionDirectory.removeVariableTable((yyvsp[(2) - (14)].sval));
    ;}
    break;

  case 20:
#line 183 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = (yyvsp[(1) - (1)].chType);
    ;}
    break;

  case 21:
#line 186 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = VOID_;
    ;}
    break;

  case 22:
#line 191 "./src/parser.y"
    {
        pushOperator(RETURN_);
    ;}
    break;

  case 23:
#line 193 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({RETURN_}));
        setFunctionReturn();
        verifyReturnType(getCurrentFuncType());
    ;}
    break;

  case 24:
#line 198 "./src/parser.y"
    {
        generateVoidReturn();
        verifyReturnType(getCurrentFuncType(), VOID_);
    ;}
    break;

  case 31:
#line 213 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), lineas, declareVariable((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), nullptr, lineas)->address);
        (yyval.iparam) = (yyvsp[(5) - (5)].iparam) + 1;
    ;}
    break;

  case 32:
#line 217 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), lineas, declareVariable((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), nullptr, lineas)->address);
        (yyval.iparam) = 1;
    ;}
    break;

  case 33:
#line 221 "./src/parser.y"
    {
        (yyval.iparam) = 0;
    ;}
    break;

  case 34:
#line 226 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({AND_, OR_}));
    ;}
    break;

  case 36:
#line 231 "./src/parser.y"
    {
        pushOperator(AND_);
    ;}
    break;

  case 38:
#line 234 "./src/parser.y"
    {
        pushOperator(OR_);
    ;}
    break;

  case 41:
#line 240 "./src/parser.y"
    {
        pushOperator(NOT_);
    ;}
    break;

  case 42:
#line 242 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({NOT_}));
    ;}
    break;

  case 44:
#line 248 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({GREATER_, LESS_, EQUALTO_, NOTEQUAL_, GREATEREQ_, LESSEQ_}));
    ;}
    break;

  case 46:
#line 253 "./src/parser.y"
    {
        pushOperator(GREATER_);
    ;}
    break;

  case 48:
#line 256 "./src/parser.y"
    {
        pushOperator(LESS_);
    ;}
    break;

  case 50:
#line 259 "./src/parser.y"
    {
        pushOperator(EQUALTO_);
    ;}
    break;

  case 52:
#line 262 "./src/parser.y"
    {
        pushOperator(NOTEQUAL_);
    ;}
    break;

  case 54:
#line 265 "./src/parser.y"
    {
        pushOperator(GREATEREQ_);
    ;}
    break;

  case 56:
#line 268 "./src/parser.y"
    {
        pushOperator(LESSEQ_);
    ;}
    break;

  case 59:
#line 274 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({ADD_, SUB_}));
    ;}
    break;

  case 61:
#line 279 "./src/parser.y"
    {
        pushOperator(ADD_);
    ;}
    break;

  case 63:
#line 282 "./src/parser.y"
    {
        pushOperator(SUB_);
    ;}
    break;

  case 66:
#line 288 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({MULTI_}));
        checkIfShouldDoOperation(vector<int>({MULTI_, DIV_, MOD_}));
    ;}
    break;

  case 68:
#line 294 "./src/parser.y"
    {
        pushOperator(MULTI_);
        pushOperandOfType(declareCte(INT_, -1), INT_);
    ;}
    break;

  case 69:
#line 298 "./src/parser.y"
    {
        pushOperator(MULTI_);
        pushOperandOfType(declareCte(INT_, 1), INT_);
    ;}
    break;

  case 70:
#line 304 "./src/parser.y"
    {
        pushOperator(MULTI_);
    ;}
    break;

  case 72:
#line 307 "./src/parser.y"
    {
        pushOperator(DIV_);
    ;}
    break;

  case 74:
#line 310 "./src/parser.y"
    {
        pushOperator(MOD_);
    ;}
    break;

  case 77:
#line 316 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 79:
#line 319 "./src/parser.y"
    {
        pushOperator(LEFTPAR_);
    ;}
    break;

  case 80:
#line 321 "./src/parser.y"
    {
        pushOperator(RIGHTPAR_);
    ;}
    break;

  case 83:
#line 328 "./src/parser.y"
    {
        pushOperandOfType(declareCte(FLOAT_, (yyvsp[(1) - (1)].fval)), FLOAT_);
    ;}
    break;

  case 84:
#line 331 "./src/parser.y"
    {
        pushOperandOfType(declareCte(INT_, (yyvsp[(1) - (1)].ival)), INT_);
    ;}
    break;

  case 85:
#line 334 "./src/parser.y"
    {
        pushOperandOfType(declareCte(BOOL_, (yyvsp[(1) - (1)].bval)), BOOL_);
    ;}
    break;

  case 86:
#line 339 "./src/parser.y"
    {
        verifyFunctionExists(getIDExpression(), lineas);
        setCurrentCall(getIDExpression());
    ;}
    break;

  case 87:
#line 342 "./src/parser.y"
    {
        generateEra(getCurrentCall());
        resetParameterCount(getCurrentCall());
        pushOperator(FAKEBOT_);
    ;}
    break;

  case 88:
#line 346 "./src/parser.y"
    {
        verifyParameters(getCurrentCall());
        generateGosub(getCurrentCall());
        pushOperandResult(getCurrentCall());
        setCurrentCall("");
        popOperator(FAKEBOT_);
    ;}
    break;

  case 89:
#line 353 "./src/parser.y"
    {
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 90:
#line 356 "./src/parser.y"
    {
        popOperator(FAKEBOT_);
    ;}
    break;

  case 91:
#line 359 "./src/parser.y"
    {
        pushOperandByID(getIDExpression());
    ;}
    break;

  case 94:
#line 368 "./src/parser.y"
    {
        generateVerify();
    ;}
    break;

  case 95:
#line 370 "./src/parser.y"
    {
        generateAccess();
    ;}
    break;

  case 96:
#line 375 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 99:
#line 381 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 111:
#line 400 "./src/parser.y"
    {
        (yyval.imgFunc) = GRAYSCALE_;
    ;}
    break;

  case 112:
#line 403 "./src/parser.y"
    {
        (yyval.imgFunc) = SAVE_;
    ;}
    break;

  case 113:
#line 406 "./src/parser.y"
    {
        (yyval.imgFunc) = OPEN_;
    ;}
    break;

  case 114:
#line 409 "./src/parser.y"
    {
        (yyval.imgFunc) = BANDW_;
    ;}
    break;

  case 115:
#line 412 "./src/parser.y"
    {
        (yyval.imgFunc) = CHANGECOLOR_;
    ;}
    break;

  case 116:
#line 415 "./src/parser.y"
    {
        (yyval.imgFunc) = HFLIP_;
    ;}
    break;

  case 117:
#line 418 "./src/parser.y"
    {
        (yyval.imgFunc) = VFLIP_;
    ;}
    break;

  case 118:
#line 421 "./src/parser.y"
    {
        (yyval.imgFunc) = CROP_;
    ;}
    break;

  case 119:
#line 426 "./src/parser.y"
    {
        verifyImageParameterCount((yyvsp[(3) - (7)].imgFunc), (yyvsp[(5) - (7)].paramNode)->count);
        performImageCall((yyvsp[(1) - (7)].sval), (yyvsp[(3) - (7)].imgFunc), (yyvsp[(5) - (7)].paramNode));
    ;}
    break;

  case 120:
#line 430 "./src/parser.y"
    {
        verifyImageParameterCount((yyvsp[(3) - (6)].imgFunc), 0);
        performImageCall((yyvsp[(1) - (6)].sval), (yyvsp[(3) - (6)].imgFunc), nullptr);
    ;}
    break;

  case 121:
#line 436 "./src/parser.y"
    {
        int type = topOperandType();
        ParamNode *node = new ParamNode(popOperand(), type);
        (yyval.paramNode) = node;
    ;}
    break;

  case 122:
#line 441 "./src/parser.y"
    {
        int type = topOperandType();
        ParamNode *node = new ParamNode(popOperand(), type, (yyvsp[(3) - (3)].paramNode));
        (yyval.paramNode) = node;
    ;}
    break;

  case 123:
#line 448 "./src/parser.y"
    {
        pushOperator(EQUALS_);
    ;}
    break;

  case 124:
#line 450 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({EQUALS_}));
    ;}
    break;

  case 125:
#line 455 "./src/parser.y"
    {
        pushOperandByID((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 126:
#line 458 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 127:
#line 462 "./src/parser.y"
    {
        popOperator(FAKEBOT_);
    ;}
    break;

  case 128:
#line 467 "./src/parser.y"
    {
        verifyFunctionExists((yyvsp[(1) - (1)].sval), lineas);
    ;}
    break;

  case 129:
#line 469 "./src/parser.y"
    {
        generateEra((yyvsp[(1) - (3)].sval));
        setCurrentCall((yyvsp[(1) - (3)].sval));
        resetParameterCount((yyvsp[(1) - (3)].sval));
    ;}
    break;

  case 130:
#line 473 "./src/parser.y"
    {
        verifyParameters((yyvsp[(1) - (6)].sval));
        generateGosub((yyvsp[(1) - (6)].sval));
        setCurrentCall("");
    ;}
    break;

  case 132:
#line 480 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 135:
#line 486 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 138:
#line 492 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 139:
#line 494 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
        generateNewline();
    ;}
    break;

  case 140:
#line 500 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
    ;}
    break;

  case 141:
#line 503 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 144:
#line 509 "./src/parser.y"
    {
        generateInput(INT_);
    ;}
    break;

  case 145:
#line 512 "./src/parser.y"
    {
        generateInput(FLOAT_);
    ;}
    break;

  case 146:
#line 515 "./src/parser.y"
    {
        generateInput(STRING_);
    ;}
    break;

  case 148:
#line 521 "./src/parser.y"
    {
        pushOperandOfType(declareCte(STRING_, (yyvsp[(1) - (1)].strval)), STRING_);
    ;}
    break;

  case 149:
#line 526 "./src/parser.y"
    {
        generateElse();
    ;}
    break;

  case 150:
#line 528 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 151:
#line 531 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 152:
#line 536 "./src/parser.y"
    {
        generateIf();
    ;}
    break;

  case 156:
#line 545 "./src/parser.y"
    {
        pushJumpCurrent();
    ;}
    break;

  case 157:
#line 547 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 158:
#line 549 "./src/parser.y"
    {
        fillJumpWhile();
    ;}
    break;

  case 159:
#line 554 "./src/parser.y"
    {
        // pushJumpCurrent();
    ;}
    break;

  case 160:
#line 556 "./src/parser.y"
    {
        pushLastAssignment();
        saveForVariable();
        pushJumpCurrent(-1);
    ;}
    break;

  case 161:
#line 560 "./src/parser.y"
    {
        validateLastAssignment(INT_);
        validateLastOperand(INT_);
        pushOperator(LESS_);
        doOperation();
    ;}
    break;

  case 162:
#line 565 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 163:
#line 567 "./src/parser.y"
    {
        fillJumpFor();
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2478 "./bin/parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 571 "./src/parser.y"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "ERROR: Need source code filename." << endl;
        exit(-1);
    }
    string filename = argv[1];
    if (filename == "") {
        filename = "code.txt";
    } else {
        filename = "./src/tests/" + filename + ".txt";
    }
    FILE *myfile = fopen(filename.c_str(), "r");
    if (!myfile) {
        cout << "No file found for source code." << endl;
        return -1;
    }

    yyin = myfile;
    do {
        yyparse();
    }
    while (!feof(yyin));

    return 0;
}

void yyerror(const char *s) {
    printf("SyntaxError: Invalid token on line %d. '%s'\n", lineas, yytext);
    exit(-1);
}
