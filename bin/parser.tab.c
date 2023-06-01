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
     FOR = 273,
     DO = 274,
     WHILE = 275,
     TO = 276,
     FUNCTION = 277,
     RETURN = 278,
     VOID = 279,
     ADDITION = 280,
     SUBSTRACTION = 281,
     MULTI = 282,
     DIV = 283,
     MOD = 284,
     LESS_THAN = 285,
     MORE_THAN = 286,
     NOT_EQUAL = 287,
     GREATEREQ = 288,
     LESSEQ = 289,
     EQUAL = 290,
     EQUAL_TO = 291,
     AND = 292,
     OR = 293,
     NOT = 294,
     LEFT_PAR = 295,
     RIGHT_PAR = 296,
     LEFT_CURLY = 297,
     RIGHT_CURLY = 298,
     LEFT_BRACK = 299,
     RIGHT_BRACK = 300,
     COLON = 301,
     SEMICOLON = 302,
     COMMA = 303,
     ARROW = 304,
     OPEN = 305,
     GRAYSCALE = 306,
     SAVE = 307,
     BANDW = 308,
     CHANGE_COLOR = 309,
     HFLIP = 310
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
#define FOR 273
#define DO 274
#define WHILE 275
#define TO 276
#define FUNCTION 277
#define RETURN 278
#define VOID 279
#define ADDITION 280
#define SUBSTRACTION 281
#define MULTI 282
#define DIV 283
#define MOD 284
#define LESS_THAN 285
#define MORE_THAN 286
#define NOT_EQUAL 287
#define GREATEREQ 288
#define LESSEQ 289
#define EQUAL 290
#define EQUAL_TO 291
#define AND 292
#define OR 293
#define NOT 294
#define LEFT_PAR 295
#define RIGHT_PAR 296
#define LEFT_CURLY 297
#define RIGHT_CURLY 298
#define LEFT_BRACK 299
#define RIGHT_BRACK 300
#define COLON 301
#define SEMICOLON 302
#define COMMA 303
#define ARROW 304
#define OPEN 305
#define GRAYSCALE 306
#define SAVE 307
#define BANDW 308
#define CHANGE_COLOR 309
#define HFLIP 310




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
#line 238 "./bin/parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 251 "./bin/parser.tab.c"

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
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNRULES -- Number of states.  */
#define YYNSTATES  246

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
      55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    14,    19,    20,    25,    29,
      31,    34,    38,    40,    44,    47,    48,    49,    50,    51,
      66,    68,    70,    71,    78,    81,    85,    87,    89,    91,
      93,    99,   103,   104,   105,   109,   110,   114,   115,   119,
     120,   121,   125,   127,   128,   132,   133,   137,   138,   142,
     143,   147,   148,   152,   153,   157,   158,   162,   163,   164,
     168,   169,   173,   174,   178,   179,   180,   185,   187,   188,
     189,   193,   194,   198,   199,   203,   204,   205,   209,   210,
     215,   217,   219,   221,   223,   224,   225,   231,   232,   235,
     236,   239,   241,   242,   247,   248,   252,   253,   254,   259,
     260,   263,   264,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   299,   306,   308,   312,
     313,   318,   320,   321,   325,   326,   327,   328,   337,   338,
     342,   343,   344,   349,   350,   351,   359,   360,   361,   367,
     368,   370,   372,   373,   378,   380,   381,   388,   390,   392,
     393,   394,   403,   404,   405,   406,   407
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      57,     0,    -1,    -1,    -1,     8,     7,    58,    47,    60,
      65,    59,    73,    -1,     9,    61,    47,    60,    -1,    -1,
      64,    46,    74,    62,    -1,    64,    46,    74,    -1,    63,
      -1,    63,    62,    -1,    44,     3,    45,    -1,     7,    -1,
       7,    48,    64,    -1,    66,    65,    -1,    -1,    -1,    -1,
      -1,    22,     7,    67,    40,    75,    41,    46,    68,    70,
      42,    60,    69,   119,    43,    -1,    74,    -1,    24,    -1,
      -1,    23,    72,    40,    76,    41,    47,    -1,    23,    47,
      -1,    42,   119,    43,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,     7,    46,    74,    48,    75,    -1,     7,
      46,    74,    -1,    -1,    -1,    81,    77,    78,    -1,    -1,
      37,    79,    76,    -1,    -1,    38,    80,    76,    -1,    -1,
      -1,    39,    82,    83,    -1,    83,    -1,    -1,    92,    84,
      85,    -1,    -1,    31,    86,    83,    -1,    -1,    30,    87,
      83,    -1,    -1,    36,    88,    83,    -1,    -1,    32,    89,
      83,    -1,    -1,    33,    90,    83,    -1,    -1,    34,    91,
      83,    -1,    -1,    -1,    97,    93,    94,    -1,    -1,    25,
      95,    92,    -1,    -1,    26,    96,    92,    -1,    -1,    -1,
      99,   104,    98,   100,    -1,    26,    -1,    -1,    -1,    27,
     101,    97,    -1,    -1,    28,   102,    97,    -1,    -1,    29,
     103,    97,    -1,    -1,    -1,     7,   105,   108,    -1,    -1,
      40,   106,    76,    41,    -1,   107,    -1,     4,    -1,     3,
      -1,     5,    -1,    -1,    -1,   109,    40,   110,   115,    41,
      -1,    -1,   111,   112,    -1,    -1,   113,   112,    -1,   113,
      -1,    -1,    44,    76,   114,    45,    -1,    -1,    76,   116,
     117,    -1,    -1,    -1,    48,    76,   118,   117,    -1,    -1,
     120,   119,    -1,    -1,   124,    47,    -1,   122,    -1,   128,
      -1,   136,    -1,   142,    -1,   146,    -1,    71,    -1,    51,
      -1,    52,    -1,    50,    -1,    53,    -1,    54,    -1,    55,
      -1,     7,    49,   121,    40,   123,    41,    47,    -1,     7,
      49,   121,    40,    41,    47,    -1,   141,    -1,   141,    48,
     123,    -1,    -1,   126,    35,   125,    76,    -1,     7,    -1,
      -1,     7,   127,   112,    -1,    -1,    -1,    -1,     7,   129,
      40,   130,   132,    41,   131,    47,    -1,    -1,    76,   133,
     134,    -1,    -1,    -1,    48,    76,   135,   134,    -1,    -1,
      -1,    16,   137,    40,   141,   138,    41,    47,    -1,    -1,
      -1,   139,    48,   140,   141,   138,    -1,    -1,    76,    -1,
       6,    -1,    -1,   144,    15,   143,    73,    -1,   144,    -1,
      -1,    14,    40,    76,    41,   145,    73,    -1,   147,    -1,
     150,    -1,    -1,    -1,    20,   148,    40,    76,    41,   149,
      19,    73,    -1,    -1,    -1,    -1,    -1,    18,   151,    40,
     124,   152,    21,    76,   153,    41,   154,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   108,   105,   116,   119,   124,   128,   133,
     137,   143,   148,   152,   158,   159,   162,   164,   166,   162,
     179,   182,   187,   187,   194,   197,   200,   201,   202,   203,
     206,   210,   214,   219,   219,   224,   224,   227,   227,   230,
     233,   233,   238,   241,   241,   246,   246,   249,   249,   252,
     252,   255,   255,   258,   258,   261,   261,   264,   267,   267,
     272,   272,   275,   275,   278,   281,   281,   287,   291,   297,
     297,   300,   300,   303,   303,   306,   309,   309,   312,   312,
     317,   320,   323,   326,   331,   334,   331,   345,   345,   351,
     356,   357,   360,   360,   367,   367,   371,   374,   374,   377,
     380,   381,   384,   385,   386,   387,   388,   389,   390,   393,
     396,   399,   402,   405,   408,   413,   416,   421,   426,   433,
     433,   440,   443,   443,   452,   454,   458,   452,   465,   465,
     468,   471,   471,   474,   477,   477,   485,   488,   485,   491,
     499,   500,   505,   505,   510,   515,   515,   520,   521,   524,
     526,   524,   533,   535,   539,   544,   533
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CTE_INT", "CTE_FLOAT", "CTE_BOOL",
  "CTE_STRING", "ID", "PROGRAM", "VAR", "INT", "FLOAT", "BOOL", "IMAGE",
  "IF", "ELSE", "PRINT", "INPUT", "FOR", "DO", "WHILE", "TO", "FUNCTION",
  "RETURN", "VOID", "ADDITION", "SUBSTRACTION", "MULTI", "DIV", "MOD",
  "LESS_THAN", "MORE_THAN", "NOT_EQUAL", "GREATEREQ", "LESSEQ", "EQUAL",
  "EQUAL_TO", "AND", "OR", "NOT", "LEFT_PAR", "RIGHT_PAR", "LEFT_CURLY",
  "RIGHT_CURLY", "LEFT_BRACK", "RIGHT_BRACK", "COLON", "SEMICOLON",
  "COMMA", "ARROW", "OPEN", "GRAYSCALE", "SAVE", "BANDW", "CHANGE_COLOR",
  "HFLIP", "$accept", "program", "@1", "@2", "vars", "var", "array_list",
  "array_declaration", "var_list", "functions", "function", "@3", "@4",
  "@5", "function_type", "return", "@6", "block", "type", "params",
  "expression", "@7", "expression2", "@8", "@9", "not_expression", "@10",
  "comp", "@11", "comp2", "@12", "@13", "@14", "@15", "@16", "@17", "exp",
  "@18", "exp2", "@19", "@20", "term", "@21", "negation", "term2", "@22",
  "@23", "@24", "factor", "@25", "@26", "var_cte", "array_or_func", "@27",
  "@28", "@29", "arrays", "array", "@30", "arguments", "@31", "arguments2",
  "@32", "statements", "statement", "image_function", "image_call",
  "image_arguments", "assignment", "@33", "assignee", "@34", "call", "@35",
  "@36", "@37", "call2", "@38", "call3", "@39", "printing", "@40",
  "printing_2", "@41", "@42", "expression_or_str", "conditional", "@43",
  "conditional_if", "@44", "repetition", "rep_cond", "@45", "@46",
  "rep_no_cond", "@47", "@48", "@49", "@50", 0
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
     305,   306,   307,   308,   309,   310
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    58,    59,    57,    60,    60,    61,    61,    62,
      62,    63,    64,    64,    65,    65,    67,    68,    69,    66,
      70,    70,    72,    71,    71,    73,    74,    74,    74,    74,
      75,    75,    75,    77,    76,    79,    78,    80,    78,    78,
      82,    81,    81,    84,    83,    86,    85,    87,    85,    88,
      85,    89,    85,    90,    85,    91,    85,    85,    93,    92,
      95,    94,    96,    94,    94,    98,    97,    99,    99,   101,
     100,   102,   100,   103,   100,   100,   105,   104,   106,   104,
     104,   107,   107,   107,   109,   110,   108,   111,   108,   108,
     112,   112,   114,   113,   116,   115,   115,   118,   117,   117,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   121,   121,   121,   121,   122,   122,   123,   123,   125,
     124,   126,   127,   126,   129,   130,   131,   128,   133,   132,
     132,   135,   134,   134,   137,   136,   139,   140,   138,   138,
     141,   141,   143,   142,   142,   145,   144,   146,   146,   148,
     149,   147,   151,   152,   153,   154,   150
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     4,     0,     4,     3,     1,
       2,     3,     1,     3,     2,     0,     0,     0,     0,    14,
       1,     1,     0,     6,     2,     3,     1,     1,     1,     1,
       5,     3,     0,     0,     3,     0,     3,     0,     3,     0,
       0,     3,     1,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     0,     3,
       0,     3,     0,     3,     0,     0,     4,     1,     0,     0,
       3,     0,     3,     0,     3,     0,     0,     3,     0,     4,
       1,     1,     1,     1,     0,     0,     5,     0,     2,     0,
       2,     1,     0,     4,     0,     3,     0,     0,     4,     0,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     7,     6,     1,     3,     0,
       4,     1,     0,     3,     0,     0,     0,     8,     0,     3,
       0,     0,     4,     0,     0,     7,     0,     0,     5,     0,
       1,     1,     0,     4,     1,     0,     6,     1,     1,     0,
       0,     8,     0,     0,     0,     0,    11
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     6,     0,    15,    12,
       0,     0,     0,     3,    15,     0,     6,     0,    16,     0,
      14,    13,     5,    26,    27,    28,    29,     8,     0,   101,
       4,     0,     7,     9,    32,   121,     0,   134,   152,   149,
      22,   108,     0,   101,   103,     0,     0,   104,   105,   106,
     144,   107,   147,   148,     0,    10,     0,     0,     0,     0,
       0,    68,     0,     0,     0,    24,     0,    25,   100,   102,
     119,   142,    11,     0,     0,   111,   109,   110,   112,   113,
     114,     0,    68,   123,    91,   125,    67,    40,     0,    33,
      42,    43,    58,     0,    68,     0,    68,    68,    68,     0,
      31,    17,    68,    92,    90,    68,    68,   145,    39,    57,
      64,    82,    81,    83,    76,    78,    65,    80,   141,   140,
     136,   121,   153,     0,     0,   120,   143,    32,     0,     0,
       0,   117,     0,   128,     0,    41,     0,    35,    37,    34,
      47,    45,    51,    53,    55,    49,    44,    60,    62,    59,
      89,    68,    75,     0,     0,     0,   150,     0,    30,    21,
       0,    20,   116,     0,    68,    93,   133,   126,   146,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    77,
       0,     0,     0,    69,    71,    73,    66,     0,   137,    68,
       0,    23,     6,   115,   118,    68,   129,     0,    36,    38,
      48,    46,    52,    54,    56,    50,    61,    63,    85,    88,
      79,    68,    68,    68,   135,    68,   154,     0,    18,   131,
     127,    68,    70,    72,    74,   136,     0,   151,   101,   133,
      94,     0,   138,   155,     0,   132,    99,    86,     0,    19,
      68,    95,   156,    97,    99,    98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    19,     8,    10,    32,    33,    11,    13,
      14,    28,   128,   228,   160,    41,    66,    30,    27,    57,
     119,   108,   139,   169,   170,    89,   106,    90,   109,   146,
     172,   171,   176,   173,   174,   175,    91,   110,   149,   177,
     178,    92,   152,    93,   186,   211,   212,   213,   116,   150,
     151,   117,   179,   180,   221,   181,    83,    84,   132,   231,
     236,   241,   244,    42,    43,    81,    44,   130,    45,    98,
      46,    59,    47,    60,   105,   197,   134,   166,   196,   229,
      48,    62,   153,   154,   215,   131,    49,    99,    50,   136,
      51,    52,    64,   190,    53,    63,   155,   226,   238
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -153
static const yytype_int16 yypact[] =
{
      18,     5,    35,  -153,  -153,    -5,    44,    56,    70,    46,
      48,    47,    89,  -153,    70,    56,    44,    73,  -153,    55,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,    54,    59,     9,
    -153,    97,  -153,    54,    94,   -25,    63,  -153,  -153,  -153,
      57,  -153,    64,     9,  -153,    58,    71,  -153,  -153,  -153,
      93,  -153,  -153,  -153,    66,  -153,    67,    74,    27,    68,
      76,    -9,    77,    78,    79,  -153,    80,  -153,  -153,  -153,
    -153,  -153,  -153,    73,    81,  -153,  -153,  -153,  -153,  -153,
    -153,    82,    -9,  -153,    68,  -153,  -153,  -153,    83,  -153,
    -153,  -153,  -153,     6,     8,   107,    -9,    -9,    -9,    55,
      75,  -153,     2,  -153,  -153,    -8,   100,  -153,   -17,    34,
      62,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
      87,    86,  -153,    90,    91,  -153,  -153,    94,    45,    92,
      95,    85,    96,  -153,    99,  -153,    55,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
       4,    -9,    22,   102,    98,   113,  -153,   101,  -153,  -153,
     103,  -153,  -153,   104,     8,  -153,   105,  -153,  -153,    -9,
      -9,   100,   100,   100,   100,   100,   100,   100,   100,  -153,
     109,    68,   106,  -153,  -153,  -153,  -153,   108,  -153,    -9,
     118,  -153,    44,  -153,  -153,    -9,  -153,   110,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,   100,   100,   100,  -153,     8,  -153,    55,  -153,  -153,
    -153,    13,  -153,  -153,  -153,    87,   111,  -153,     9,   105,
    -153,   115,  -153,  -153,   116,  -153,   112,  -153,    55,  -153,
      -9,  -153,  -153,  -153,   112,  -153
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -153,  -153,   -14,  -153,   117,  -153,   123,   130,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,   -96,   -66,    31,
     -60,  -153,  -153,  -153,  -153,  -153,  -153,  -100,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,   -88,  -153,  -153,  -153,
    -153,  -152,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,   -79,  -153,  -153,  -153,
    -153,   -82,  -153,   -43,  -153,  -153,  -153,   -10,    69,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,   -64,  -153,
    -153,  -153,   -62,  -153,  -153,   -90,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -140
static const yytype_int16 yytable[] =
{
      68,    88,    22,   126,   120,   104,   135,   100,   118,   111,
     112,   113,     3,   114,   118,  -124,    35,    86,    86,  -122,
     137,   138,   103,    36,    58,    37,     1,    38,    86,    39,
      87,    87,    40,  -130,    86,     4,   123,   124,   125,    86,
     168,    87,     6,   129,   -84,   133,   115,    87,   -87,   183,
     184,   185,    87,     7,   -96,    23,    24,    25,    26,   222,
     223,   224,   161,     9,   140,   141,   142,   143,   144,   159,
     145,   200,   201,   202,   203,   204,   205,    75,    76,    77,
      78,    79,    80,    23,    24,    25,    26,   147,   148,   206,
     207,   182,    12,    17,    15,    16,    18,    29,    31,    34,
      54,    56,   209,    61,    65,    69,    70,    67,    71,   198,
     199,    72,    82,    73,   121,    74,    85,    94,    95,    96,
      97,   227,   102,   127,   107,   225,    86,   101,  -139,   216,
    -122,   156,   157,   164,   189,   219,   163,   217,    21,   162,
     167,   165,   242,   187,    20,   192,   188,   210,   191,   208,
      55,   193,   233,   195,   194,   214,   237,   220,   158,   239,
     240,   230,   245,   232,   122,   235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   218,     0,
     243,     0,     0,     0,     0,   234
};

static const yytype_int16 yycheck[] =
{
      43,    61,    16,    99,    94,    84,   106,    73,     6,     3,
       4,     5,     7,     7,     6,    40,     7,    26,    26,    44,
      37,    38,    82,    14,    49,    16,     8,    18,    26,    20,
      39,    39,    23,    41,    26,     0,    96,    97,    98,    26,
     136,    39,    47,    41,    40,   105,    40,    39,    44,    27,
      28,    29,    39,     9,    41,    10,    11,    12,    13,   211,
     212,   213,   128,     7,    30,    31,    32,    33,    34,    24,
      36,   171,   172,   173,   174,   175,   176,    50,    51,    52,
      53,    54,    55,    10,    11,    12,    13,    25,    26,   177,
     178,   151,    22,    46,    48,    47,     7,    42,    44,    40,
       3,     7,   181,    40,    47,    47,    35,    43,    15,   169,
     170,    45,    44,    46,     7,    41,    40,    40,    40,    40,
      40,   217,    40,    48,    41,   215,    26,    46,    41,   189,
      44,    41,    41,    48,    21,   195,    41,    19,    15,    47,
      41,    45,   238,    41,    14,    42,    48,    41,    47,    40,
      33,    47,    41,    48,   164,    47,    41,    47,   127,    43,
      48,   221,   244,   225,    95,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,
     240,    -1,    -1,    -1,    -1,   228
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    57,     7,     0,    58,    47,     9,    60,     7,
      61,    64,    22,    65,    66,    48,    47,    46,     7,    59,
      65,    64,    60,    10,    11,    12,    13,    74,    67,    42,
      73,    44,    62,    63,    40,     7,    14,    16,    18,    20,
      23,    71,   119,   120,   122,   124,   126,   128,   136,   142,
     144,   146,   147,   150,     3,    62,     7,    75,    49,   127,
     129,    40,   137,   151,   148,    47,    72,    43,   119,    47,
      35,    15,    45,    46,    41,    50,    51,    52,    53,    54,
      55,   121,    44,   112,   113,    40,    26,    39,    76,    81,
      83,    92,    97,    99,    40,    40,    40,    40,   125,   143,
      74,    46,    40,    76,   112,   130,    82,    41,    77,    84,
      93,     3,     4,     5,     7,    40,   104,   107,     6,    76,
     141,     7,   124,    76,    76,    76,    73,    48,    68,    41,
     123,   141,   114,    76,   132,    83,   145,    37,    38,    78,
      30,    31,    32,    33,    34,    36,    85,    25,    26,    94,
     105,   106,    98,   138,   139,   152,    41,    41,    75,    24,
      70,    74,    47,    41,    48,    45,   133,    41,    73,    79,
      80,    87,    86,    89,    90,    91,    88,    95,    96,   108,
     109,   111,    76,    27,    28,    29,   100,    41,    48,    21,
     149,    47,    42,    47,   123,    48,   134,   131,    76,    76,
      83,    83,    83,    83,    83,    83,    92,    92,    40,   112,
      41,   101,   102,   103,    47,   140,    76,    19,    60,    76,
      47,   110,    97,    97,    97,   141,   153,    73,    69,   135,
      76,   115,   138,    41,   119,   134,   116,    41,   154,    43,
      48,   117,    73,    76,   118,   117
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
#line 105 "./src/parser.y"
    {
        declareMainFunction((yyvsp[(2) - (2)].sval), lineas, &functionDirectory);
        setProgramName((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 3:
#line 108 "./src/parser.y"
    {
        fillMain();
    ;}
    break;

  case 4:
#line 110 "./src/parser.y"
    {
        printf("Valid syntax.\n");
        generateObject();
    ;}
    break;

  case 5:
#line 116 "./src/parser.y"
    {
        (yyval.ivar) = (yyvsp[(4) - (4)].ivar) + 1;
    ;}
    break;

  case 6:
#line 119 "./src/parser.y"
    {
        (yyval.ivar) = 0;
    ;}
    break;

  case 7:
#line 124 "./src/parser.y"
    {
        (yyvsp[(4) - (4)].arrNode)->calculateRs();
        declareVariables((yyvsp[(1) - (4)].nodeID), (yyvsp[(3) - (4)].chType), (yyvsp[(4) - (4)].arrNode), lineas);
    ;}
    break;

  case 8:
#line 128 "./src/parser.y"
    {
        declareVariables((yyvsp[(1) - (3)].nodeID), (yyvsp[(3) - (3)].chType), nullptr, lineas);
    ;}
    break;

  case 9:
#line 133 "./src/parser.y"
    {
        ArrayNode *node = new ArrayNode((yyvsp[(1) - (1)].iarray));
        (yyval.arrNode) = node;
    ;}
    break;

  case 10:
#line 137 "./src/parser.y"
    {
        ArrayNode *node = new ArrayNode((yyvsp[(1) - (2)].iarray), (yyvsp[(2) - (2)].arrNode));
        (yyval.arrNode) = node;
    ;}
    break;

  case 11:
#line 143 "./src/parser.y"
    {
        (yyval.iarray) = (yyvsp[(2) - (3)].ival);
    ;}
    break;

  case 12:
#line 148 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (1)].sval));
        (yyval.nodeID) = node;
    ;}
    break;

  case 13:
#line 152 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].nodeID));
        (yyval.nodeID) = node;
    ;}
    break;

  case 16:
#line 162 "./src/parser.y"
    {
        declareFunction((yyvsp[(2) - (2)].sval), 7, lineas);
    ;}
    break;

  case 17:
#line 164 "./src/parser.y"
    {
        setCurrentParamCount((yyvsp[(5) - (7)].iparam));
    ;}
    break;

  case 18:
#line 166 "./src/parser.y"
    {
        setCurrentLocalVarCount((yyvsp[(11) - (11)].ivar));
        setCurrentCurrQuad();
        setCurrentFuncType((yyvsp[(9) - (11)].chType));
        setCurrentFunc((yyvsp[(2) - (11)].sval));
        createReturnAddress();
    ;}
    break;

  case 19:
#line 172 "./src/parser.y"
    {
        popReturnAddress();
        generateEndFunc();
        functionDirectory.removeVariableTable((yyvsp[(2) - (14)].sval));
    ;}
    break;

  case 20:
#line 179 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = (yyvsp[(1) - (1)].chType);
    ;}
    break;

  case 21:
#line 182 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = VOID_;
    ;}
    break;

  case 22:
#line 187 "./src/parser.y"
    {
        pushOperator(RETURN_);
    ;}
    break;

  case 23:
#line 189 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({RETURN_}));
        setFunctionReturn();
        verifyReturnType(getCurrentFuncType());
    ;}
    break;

  case 30:
#line 206 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), lineas, declareVariable((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), nullptr, lineas)->address);
        (yyval.iparam) = (yyvsp[(5) - (5)].iparam) + 1;
    ;}
    break;

  case 31:
#line 210 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), lineas, declareVariable((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), nullptr, lineas)->address);
        (yyval.iparam) = 1;
    ;}
    break;

  case 32:
#line 214 "./src/parser.y"
    {
        (yyval.iparam) = 0;
    ;}
    break;

  case 33:
#line 219 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({AND_, OR_}));
    ;}
    break;

  case 35:
#line 224 "./src/parser.y"
    {
        pushOperator(AND_);
    ;}
    break;

  case 37:
#line 227 "./src/parser.y"
    {
        pushOperator(OR_);
    ;}
    break;

  case 40:
#line 233 "./src/parser.y"
    {
        pushOperator(NOT_);
    ;}
    break;

  case 41:
#line 235 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({NOT_}));
    ;}
    break;

  case 43:
#line 241 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({GREATER_, LESS_, EQUALTO_, NOTEQUAL_, GREATEREQ_, LESSEQ_}));
    ;}
    break;

  case 45:
#line 246 "./src/parser.y"
    {
        pushOperator(GREATER_);
    ;}
    break;

  case 47:
#line 249 "./src/parser.y"
    {
        pushOperator(LESS_);
    ;}
    break;

  case 49:
#line 252 "./src/parser.y"
    {
        pushOperator(EQUALTO_);
    ;}
    break;

  case 51:
#line 255 "./src/parser.y"
    {
        pushOperator(NOTEQUAL_);
    ;}
    break;

  case 53:
#line 258 "./src/parser.y"
    {
        pushOperator(GREATEREQ_);
    ;}
    break;

  case 55:
#line 261 "./src/parser.y"
    {
        pushOperator(LESSEQ_);
    ;}
    break;

  case 58:
#line 267 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({ADD_, SUB_}));
    ;}
    break;

  case 60:
#line 272 "./src/parser.y"
    {
        pushOperator(ADD_);
    ;}
    break;

  case 62:
#line 275 "./src/parser.y"
    {
        pushOperator(SUB_);
    ;}
    break;

  case 65:
#line 281 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({MULTI_}));
        checkIfShouldDoOperation(vector<int>({MULTI_, DIV_, MOD_}));
    ;}
    break;

  case 67:
#line 287 "./src/parser.y"
    {
        pushOperator(MULTI_);
        pushOperandOfType(declareCte(INT_, -1), INT_);
    ;}
    break;

  case 68:
#line 291 "./src/parser.y"
    {
        pushOperator(MULTI_);
        pushOperandOfType(declareCte(INT_, 1), INT_);
    ;}
    break;

  case 69:
#line 297 "./src/parser.y"
    {
        pushOperator(MULTI_);
    ;}
    break;

  case 71:
#line 300 "./src/parser.y"
    {
        pushOperator(DIV_);
    ;}
    break;

  case 73:
#line 303 "./src/parser.y"
    {
        pushOperator(MOD_);
    ;}
    break;

  case 76:
#line 309 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 78:
#line 312 "./src/parser.y"
    {
        pushOperator(LEFTPAR_);
    ;}
    break;

  case 79:
#line 314 "./src/parser.y"
    {
        pushOperator(RIGHTPAR_);
    ;}
    break;

  case 81:
#line 320 "./src/parser.y"
    {
        pushOperandOfType(declareCte(FLOAT_, (yyvsp[(1) - (1)].fval)), FLOAT_);
    ;}
    break;

  case 82:
#line 323 "./src/parser.y"
    {
        pushOperandOfType(declareCte(INT_, (yyvsp[(1) - (1)].ival)), INT_);
    ;}
    break;

  case 83:
#line 326 "./src/parser.y"
    {
        pushOperandOfType(declareCte(BOOL_, (yyvsp[(1) - (1)].bval)), BOOL_);
    ;}
    break;

  case 84:
#line 331 "./src/parser.y"
    {
        verifyFunctionExists(getIDExpression(), lineas);
        setCurrentCall(getIDExpression());
    ;}
    break;

  case 85:
#line 334 "./src/parser.y"
    {
        generateEra(getCurrentCall());
        resetParameterCount(getCurrentCall());
        pushOperator(FAKEBOT_);
    ;}
    break;

  case 86:
#line 338 "./src/parser.y"
    {
        verifyParameters(getCurrentCall());
        generateGosub(getCurrentCall());
        pushOperandResult(getCurrentCall());
        setCurrentCall("");
        popOperator(FAKEBOT_);
    ;}
    break;

  case 87:
#line 345 "./src/parser.y"
    {
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 88:
#line 348 "./src/parser.y"
    {
        popOperator(FAKEBOT_);
    ;}
    break;

  case 89:
#line 351 "./src/parser.y"
    {
        pushOperandByID(getIDExpression());
    ;}
    break;

  case 92:
#line 360 "./src/parser.y"
    {
        generateVerify();
    ;}
    break;

  case 93:
#line 362 "./src/parser.y"
    {
        generateAccess();
    ;}
    break;

  case 94:
#line 367 "./src/parser.y"
    {
        cout << "gen param" << endl;
        generateParam();
    ;}
    break;

  case 97:
#line 374 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 109:
#line 393 "./src/parser.y"
    {
        (yyval.imgFunc) = GRAYSCALE_;
    ;}
    break;

  case 110:
#line 396 "./src/parser.y"
    {
        (yyval.imgFunc) = SAVE_;
    ;}
    break;

  case 111:
#line 399 "./src/parser.y"
    {
        (yyval.imgFunc) = OPEN_;
    ;}
    break;

  case 112:
#line 402 "./src/parser.y"
    {
        (yyval.imgFunc) = BANDW_;
    ;}
    break;

  case 113:
#line 405 "./src/parser.y"
    {
        (yyval.imgFunc) = CHANGECOLOR_;
    ;}
    break;

  case 114:
#line 408 "./src/parser.y"
    {
        (yyval.imgFunc) = HFLIP_;
    ;}
    break;

  case 115:
#line 413 "./src/parser.y"
    {
        performImageCall((yyvsp[(1) - (7)].sval), (yyvsp[(3) - (7)].imgFunc), (yyvsp[(5) - (7)].paramNode));
    ;}
    break;

  case 116:
#line 416 "./src/parser.y"
    {
        performImageCall((yyvsp[(1) - (6)].sval), (yyvsp[(3) - (6)].imgFunc), nullptr);
    ;}
    break;

  case 117:
#line 421 "./src/parser.y"
    {
        int type = topOperandType();
        ParamNode *node = new ParamNode(popOperand(), type);
        (yyval.paramNode) = node;
    ;}
    break;

  case 118:
#line 426 "./src/parser.y"
    {
        int type = topOperandType();
        ParamNode *node = new ParamNode(popOperand(), type, (yyvsp[(3) - (3)].paramNode));
        (yyval.paramNode) = node;
    ;}
    break;

  case 119:
#line 433 "./src/parser.y"
    {
        pushOperator(EQUALS_);
    ;}
    break;

  case 120:
#line 435 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({EQUALS_}));
    ;}
    break;

  case 121:
#line 440 "./src/parser.y"
    {
        pushOperandByID((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 122:
#line 443 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 123:
#line 447 "./src/parser.y"
    {
        popOperator(FAKEBOT_);
    ;}
    break;

  case 124:
#line 452 "./src/parser.y"
    {
        verifyFunctionExists((yyvsp[(1) - (1)].sval), lineas);
    ;}
    break;

  case 125:
#line 454 "./src/parser.y"
    {
        generateEra((yyvsp[(1) - (3)].sval));
        setCurrentCall((yyvsp[(1) - (3)].sval));
        resetParameterCount((yyvsp[(1) - (3)].sval));
    ;}
    break;

  case 126:
#line 458 "./src/parser.y"
    {
        verifyParameters((yyvsp[(1) - (6)].sval));
        generateGosub((yyvsp[(1) - (6)].sval));
        setCurrentCall("");
    ;}
    break;

  case 128:
#line 465 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 131:
#line 471 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 134:
#line 477 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 135:
#line 479 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
        generateNewline();
    ;}
    break;

  case 136:
#line 485 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
    ;}
    break;

  case 137:
#line 488 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 141:
#line 500 "./src/parser.y"
    {
        pushOperandOfType(declareCte(STRING_, (yyvsp[(1) - (1)].strval)), STRING_);
    ;}
    break;

  case 142:
#line 505 "./src/parser.y"
    {
        generateElse();
    ;}
    break;

  case 143:
#line 507 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 144:
#line 510 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 145:
#line 515 "./src/parser.y"
    {
        generateIf();
    ;}
    break;

  case 149:
#line 524 "./src/parser.y"
    {
        pushJumpCurrent();
    ;}
    break;

  case 150:
#line 526 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 151:
#line 528 "./src/parser.y"
    {
        fillJumpWhile();
    ;}
    break;

  case 152:
#line 533 "./src/parser.y"
    {
        // pushJumpCurrent();
    ;}
    break;

  case 153:
#line 535 "./src/parser.y"
    {
        pushLastAssignment();
        saveForVariable();
        pushJumpCurrent(-1);
    ;}
    break;

  case 154:
#line 539 "./src/parser.y"
    {
        validateLastAssignment(INT_);
        validateLastOperand(INT_);
        pushOperator(LESS_);
        doOperation();
    ;}
    break;

  case 155:
#line 544 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 156:
#line 546 "./src/parser.y"
    {
        fillJumpFor();
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2412 "./bin/parser.tab.c"
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


#line 550 "./src/parser.y"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Need source code filename." << endl;
        exit(-1);
    }
    string filename = argv[1];
    filename = "./src/tests/" + filename + ".txt";
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
