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
#line 230 "./bin/parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 243 "./bin/parser.tab.c"

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
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNRULES -- Number of states.  */
#define YYNSTATES  243

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

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
      45,    46,    47,    48,    49,    50,    51
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
     281,   283,   285,   293,   300,   302,   306,   307,   312,   314,
     315,   319,   320,   321,   322,   331,   332,   336,   337,   338,
     343,   344,   345,   353,   354,   355,   361,   362,   364,   366,
     367,   372,   374,   375,   382,   384,   386,   387,   388,   397,
     398,   399,   400,   401
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      53,     0,    -1,    -1,    -1,     8,     7,    54,    46,    56,
      61,    55,    69,    -1,     9,    57,    46,    56,    -1,    -1,
      60,    45,    70,    58,    -1,    60,    45,    70,    -1,    59,
      -1,    59,    58,    -1,    43,     3,    44,    -1,     7,    -1,
       7,    47,    60,    -1,    62,    61,    -1,    -1,    -1,    -1,
      -1,    21,     7,    63,    39,    71,    40,    45,    64,    66,
      41,    56,    65,   115,    42,    -1,    70,    -1,    23,    -1,
      -1,    22,    68,    39,    72,    40,    46,    -1,    22,    46,
      -1,    41,   115,    42,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,     7,    45,    70,    47,    71,    -1,     7,
      45,    70,    -1,    -1,    -1,    77,    73,    74,    -1,    -1,
      36,    75,    72,    -1,    -1,    37,    76,    72,    -1,    -1,
      -1,    38,    78,    79,    -1,    79,    -1,    -1,    88,    80,
      81,    -1,    -1,    30,    82,    79,    -1,    -1,    29,    83,
      79,    -1,    -1,    35,    84,    79,    -1,    -1,    31,    85,
      79,    -1,    -1,    32,    86,    79,    -1,    -1,    33,    87,
      79,    -1,    -1,    -1,    93,    89,    90,    -1,    -1,    24,
      91,    88,    -1,    -1,    25,    92,    88,    -1,    -1,    -1,
      95,   100,    94,    96,    -1,    25,    -1,    -1,    -1,    26,
      97,    93,    -1,    -1,    27,    98,    93,    -1,    -1,    28,
      99,    93,    -1,    -1,    -1,     7,   101,   104,    -1,    -1,
      39,   102,    72,    40,    -1,   103,    -1,     4,    -1,     3,
      -1,     5,    -1,    -1,    -1,   105,    39,   106,   111,    40,
      -1,    -1,   107,   108,    -1,    -1,   109,   108,    -1,   109,
      -1,    -1,    43,    72,   110,    44,    -1,    -1,    72,   112,
     113,    -1,    -1,    -1,    47,    72,   114,   113,    -1,    -1,
     116,   115,    -1,    -1,   120,    46,    -1,   118,    -1,   124,
      -1,   132,    -1,   138,    -1,   142,    -1,    67,    -1,    50,
      -1,    51,    -1,    49,    -1,     7,    48,   117,    39,   119,
      40,    46,    -1,     7,    48,   117,    39,    40,    46,    -1,
     137,    -1,   137,    47,   119,    -1,    -1,   122,    34,   121,
      72,    -1,     7,    -1,    -1,     7,   123,   108,    -1,    -1,
      -1,    -1,     7,   125,    39,   126,   128,    40,   127,    46,
      -1,    -1,    72,   129,   130,    -1,    -1,    -1,    47,    72,
     131,   130,    -1,    -1,    -1,    16,   133,    39,   137,   134,
      40,    46,    -1,    -1,    -1,   135,    47,   136,   137,   134,
      -1,    -1,    72,    -1,     6,    -1,    -1,   140,    15,   139,
      69,    -1,   140,    -1,    -1,    14,    39,    72,    40,   141,
      69,    -1,   143,    -1,   146,    -1,    -1,    -1,    19,   144,
      39,    72,    40,   145,    18,    69,    -1,    -1,    -1,    -1,
      -1,    17,   147,    39,   120,   148,    20,    72,   149,    40,
     150,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   104,   101,   112,   115,   120,   124,   129,
     133,   139,   144,   148,   154,   155,   158,   160,   162,   158,
     175,   178,   183,   183,   190,   193,   196,   197,   198,   199,
     202,   206,   210,   215,   215,   220,   220,   223,   223,   226,
     229,   229,   234,   237,   237,   242,   242,   245,   245,   248,
     248,   251,   251,   254,   254,   257,   257,   260,   263,   263,
     268,   268,   271,   271,   274,   277,   277,   283,   287,   293,
     293,   296,   296,   299,   299,   302,   305,   305,   308,   308,
     313,   316,   319,   322,   327,   330,   327,   341,   341,   347,
     352,   353,   356,   356,   363,   363,   367,   370,   370,   373,
     376,   377,   380,   381,   382,   383,   384,   385,   386,   389,
     392,   395,   400,   403,   408,   413,   420,   420,   427,   430,
     430,   439,   441,   445,   439,   452,   452,   455,   458,   458,
     461,   464,   464,   472,   475,   472,   478,   481,   482,   487,
     487,   492,   497,   497,   502,   503,   506,   508,   506,   515,
     517,   521,   526,   515
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CTE_INT", "CTE_FLOAT", "CTE_BOOL",
  "CTE_STRING", "ID", "PROGRAM", "VAR", "INT", "FLOAT", "BOOL", "IMAGE",
  "IF", "ELSE", "PRINT", "FOR", "DO", "WHILE", "TO", "FUNCTION", "RETURN",
  "VOID", "ADDITION", "SUBSTRACTION", "MULTI", "DIV", "MOD", "LESS_THAN",
  "MORE_THAN", "NOT_EQUAL", "GREATEREQ", "LESSEQ", "EQUAL", "EQUAL_TO",
  "AND", "OR", "NOT", "LEFT_PAR", "RIGHT_PAR", "LEFT_CURLY", "RIGHT_CURLY",
  "LEFT_BRACK", "RIGHT_BRACK", "COLON", "SEMICOLON", "COMMA", "ARROW",
  "OPEN", "GRAYSCALE", "SAVE", "$accept", "program", "@1", "@2", "vars",
  "var", "array_list", "array_declaration", "var_list", "functions",
  "function", "@3", "@4", "@5", "function_type", "return", "@6", "block",
  "type", "params", "expression", "@7", "expression2", "@8", "@9",
  "not_expression", "@10", "comp", "@11", "comp2", "@12", "@13", "@14",
  "@15", "@16", "@17", "exp", "@18", "exp2", "@19", "@20", "term", "@21",
  "negation", "term2", "@22", "@23", "@24", "factor", "@25", "@26",
  "var_cte", "array_or_func", "@27", "@28", "@29", "arrays", "array",
  "@30", "arguments", "@31", "arguments2", "@32", "statements",
  "statement", "image_function", "image_call", "image_arguments",
  "assignment", "@33", "assignee", "@34", "call", "@35", "@36", "@37",
  "call2", "@38", "call3", "@39", "printing", "@40", "printing_2", "@41",
  "@42", "expression_or_str", "conditional", "@43", "conditional_if",
  "@44", "repetition", "rep_cond", "@45", "@46", "rep_no_cond", "@47",
  "@48", "@49", "@50", 0
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
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    54,    55,    53,    56,    56,    57,    57,    58,
      58,    59,    60,    60,    61,    61,    63,    64,    65,    62,
      66,    66,    68,    67,    67,    69,    70,    70,    70,    70,
      71,    71,    71,    73,    72,    75,    74,    76,    74,    74,
      78,    77,    77,    80,    79,    82,    81,    83,    81,    84,
      81,    85,    81,    86,    81,    87,    81,    81,    89,    88,
      91,    90,    92,    90,    90,    94,    93,    95,    95,    97,
      96,    98,    96,    99,    96,    96,   101,   100,   102,   100,
     100,   103,   103,   103,   105,   106,   104,   107,   104,   104,
     108,   108,   110,   109,   112,   111,   111,   114,   113,   113,
     115,   115,   116,   116,   116,   116,   116,   116,   116,   117,
     117,   117,   118,   118,   119,   119,   121,   120,   122,   123,
     122,   125,   126,   127,   124,   129,   128,   128,   131,   130,
     130,   133,   132,   135,   136,   134,   134,   137,   137,   139,
     138,   138,   141,   140,   142,   142,   144,   145,   143,   147,
     148,   149,   150,   146
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
       1,     1,     7,     6,     1,     3,     0,     4,     1,     0,
       3,     0,     0,     0,     8,     0,     3,     0,     0,     4,
       0,     0,     7,     0,     0,     5,     0,     1,     1,     0,
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
      14,    13,     5,    26,    27,    28,    29,     8,     0,   101,
       4,     0,     7,     9,    32,   118,     0,   131,   149,   146,
      22,   108,     0,   101,   103,     0,     0,   104,   105,   106,
     141,   107,   144,   145,     0,    10,     0,     0,     0,     0,
       0,    68,     0,     0,     0,    24,     0,    25,   100,   102,
     116,   139,    11,     0,     0,   111,   109,   110,     0,    68,
     120,    91,   122,    67,    40,     0,    33,    42,    43,    58,
       0,    68,     0,    68,    68,    68,     0,    31,    17,    68,
      92,    90,    68,    68,   142,    39,    57,    64,    82,    81,
      83,    76,    78,    65,    80,   138,   137,   133,   118,   150,
       0,     0,   117,   140,    32,     0,     0,     0,   114,     0,
     125,     0,    41,     0,    35,    37,    34,    47,    45,    51,
      53,    55,    49,    44,    60,    62,    59,    89,    68,    75,
       0,     0,     0,   147,     0,    30,    21,     0,    20,   113,
       0,    68,    93,   130,   123,   143,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    77,     0,     0,     0,
      69,    71,    73,    66,     0,   134,    68,     0,    23,     6,
     112,   115,    68,   126,     0,    36,    38,    48,    46,    52,
      54,    56,    50,    61,    63,    85,    88,    79,    68,    68,
      68,   132,    68,   151,     0,    18,   128,   124,    68,    70,
      72,    74,   133,     0,   148,   101,   130,    94,     0,   135,
     152,     0,   129,    99,    86,     0,    19,    68,    95,   153,
      97,    99,    98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    19,     8,    10,    32,    33,    11,    13,
      14,    28,   125,   225,   157,    41,    66,    30,    27,    57,
     116,   105,   136,   166,   167,    86,   103,    87,   106,   143,
     169,   168,   173,   170,   171,   172,    88,   107,   146,   174,
     175,    89,   149,    90,   183,   208,   209,   210,   113,   147,
     148,   114,   176,   177,   218,   178,    80,    81,   129,   228,
     233,   238,   241,    42,    43,    78,    44,   127,    45,    95,
      46,    59,    47,    60,   102,   194,   131,   163,   193,   226,
      48,    62,   150,   151,   212,   128,    49,    96,    50,   133,
      51,    52,    64,   187,    53,    63,   152,   223,   235
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -126
static const yytype_int8 yypact[] =
{
       8,    15,    31,  -126,  -126,   -21,    29,    34,    41,    17,
      24,     1,    86,  -126,    41,    34,    29,    56,  -126,    53,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,    52,    57,     4,
    -126,    94,  -126,    52,    91,     0,    60,  -126,  -126,  -126,
      55,  -126,    58,     4,  -126,    59,    69,  -126,  -126,  -126,
      89,  -126,  -126,  -126,    64,  -126,    66,    70,    28,    71,
      73,    -1,    74,    76,    77,  -126,    78,  -126,  -126,  -126,
    -126,  -126,  -126,    56,    75,  -126,  -126,  -126,    79,    -1,
    -126,    71,  -126,  -126,  -126,    82,  -126,  -126,  -126,  -126,
       5,    11,   102,    -1,    -1,    -1,    53,    72,  -126,     7,
    -126,  -126,   -11,    98,  -126,    50,    25,    65,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,    84,    85,  -126,
      87,    90,  -126,  -126,    91,    40,    83,    93,    88,    92,
    -126,    97,  -126,    53,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,    22,    -1,    54,
      99,    96,   111,  -126,    95,  -126,  -126,   103,  -126,  -126,
     100,    11,  -126,   101,  -126,  -126,    -1,    -1,    98,    98,
      98,    98,    98,    98,    98,    98,  -126,   106,    71,   107,
    -126,  -126,  -126,  -126,   104,  -126,    -1,   116,  -126,    29,
    -126,  -126,    -1,  -126,   105,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,    98,    98,
      98,  -126,    11,  -126,    53,  -126,  -126,  -126,   -10,  -126,
    -126,  -126,    84,   109,  -126,     4,   101,  -126,   112,  -126,
    -126,   113,  -126,   110,  -126,    53,  -126,    -1,  -126,  -126,
    -126,   110,  -126
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -126,  -126,  -126,  -126,   -14,  -126,   120,  -126,   123,   126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,   -93,   -66,    30,
     -60,  -126,  -126,  -126,  -126,  -126,  -126,   -97,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,   -83,  -126,  -126,  -126,
    -126,  -125,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,   -76,  -126,  -126,  -126,
    -126,   -85,  -126,   -43,  -126,  -126,  -126,    -2,    68,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,   -65,  -126,
    -126,  -126,   -59,  -126,  -126,   -87,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -137
static const yytype_int16 yytable[] =
{
      68,    85,    22,   123,   117,   101,   132,    97,   108,   109,
     110,    35,   111,   115,    83,    83,     1,   115,    36,   100,
      37,    38,     3,    39,    83,     6,    40,    84,    84,  -127,
     -96,     4,    83,   120,   121,   122,    83,    84,     7,  -121,
     165,     9,   130,  -119,   112,    84,    17,   126,    58,    84,
      23,    24,    25,    26,   137,   138,   139,   140,   141,   158,
     142,   -84,    12,   156,    15,   -87,    23,    24,    25,    26,
      16,   197,   198,   199,   200,   201,   202,    75,    76,    77,
     180,   181,   182,   219,   220,   221,   134,   135,   179,   144,
     145,   203,   204,    18,    29,    31,    34,    54,    56,    61,
      67,    65,   206,    70,    71,    69,   195,   196,    72,   118,
      74,    73,    82,    91,    79,    92,    93,    94,    99,   124,
      98,   224,   104,    83,  -136,   222,   213,   153,  -119,   159,
     154,   186,   216,   160,   214,   161,   162,   164,    21,   184,
      20,   188,   239,   185,   189,   205,   190,   207,   192,   230,
     211,   217,   234,    55,   155,   236,   242,   237,   227,   191,
     119,   232,     0,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,     0,   240,     0,     0,
       0,     0,   231
};

static const yytype_int16 yycheck[] =
{
      43,    61,    16,    96,    91,    81,   103,    73,     3,     4,
       5,     7,     7,     6,    25,    25,     8,     6,    14,    79,
      16,    17,     7,    19,    25,    46,    22,    38,    38,    40,
      40,     0,    25,    93,    94,    95,    25,    38,     9,    39,
     133,     7,   102,    43,    39,    38,    45,    40,    48,    38,
      10,    11,    12,    13,    29,    30,    31,    32,    33,   125,
      35,    39,    21,    23,    47,    43,    10,    11,    12,    13,
      46,   168,   169,   170,   171,   172,   173,    49,    50,    51,
      26,    27,    28,   208,   209,   210,    36,    37,   148,    24,
      25,   174,   175,     7,    41,    43,    39,     3,     7,    39,
      42,    46,   178,    34,    15,    46,   166,   167,    44,     7,
      40,    45,    39,    39,    43,    39,    39,    39,    39,    47,
      45,   214,    40,    25,    40,   212,   186,    40,    43,    46,
      40,    20,   192,    40,    18,    47,    44,    40,    15,    40,
      14,    46,   235,    47,    41,    39,    46,    40,    47,    40,
      46,    46,    40,    33,   124,    42,   241,    47,   218,   161,
      92,   226,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,    -1,   237,    -1,    -1,
      -1,    -1,   225
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    53,     7,     0,    54,    46,     9,    56,     7,
      57,    60,    21,    61,    62,    47,    46,    45,     7,    55,
      61,    60,    56,    10,    11,    12,    13,    70,    63,    41,
      69,    43,    58,    59,    39,     7,    14,    16,    17,    19,
      22,    67,   115,   116,   118,   120,   122,   124,   132,   138,
     140,   142,   143,   146,     3,    58,     7,    71,    48,   123,
     125,    39,   133,   147,   144,    46,    68,    42,   115,    46,
      34,    15,    44,    45,    40,    49,    50,    51,   117,    43,
     108,   109,    39,    25,    38,    72,    77,    79,    88,    93,
      95,    39,    39,    39,    39,   121,   139,    70,    45,    39,
      72,   108,   126,    78,    40,    73,    80,    89,     3,     4,
       5,     7,    39,   100,   103,     6,    72,   137,     7,   120,
      72,    72,    72,    69,    47,    64,    40,   119,   137,   110,
      72,   128,    79,   141,    36,    37,    74,    29,    30,    31,
      32,    33,    35,    81,    24,    25,    90,   101,   102,    94,
     134,   135,   148,    40,    40,    71,    23,    66,    70,    46,
      40,    47,    44,   129,    40,    69,    75,    76,    83,    82,
      85,    86,    87,    84,    91,    92,   104,   105,   107,    72,
      26,    27,    28,    96,    40,    47,    20,   145,    46,    41,
      46,   119,    47,   130,   127,    72,    72,    79,    79,    79,
      79,    79,    79,    88,    88,    39,   108,    40,    97,    98,
      99,    46,   136,    72,    18,    56,    72,    46,   106,    93,
      93,    93,   137,   149,    69,    65,   131,    72,   111,   134,
      40,   115,   130,   112,    40,   150,    42,    47,   113,    69,
      72,   114,   113
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
#line 101 "./src/parser.y"
    {
        declareMainFunction((yyvsp[(2) - (2)].sval), lineas, &functionDirectory);
        setProgramName((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 3:
#line 104 "./src/parser.y"
    {
        fillMain();
    ;}
    break;

  case 4:
#line 106 "./src/parser.y"
    {
        printf("Valid syntax.\n");
        generateObject();
    ;}
    break;

  case 5:
#line 112 "./src/parser.y"
    {
        (yyval.ivar) = (yyvsp[(4) - (4)].ivar) + 1;
    ;}
    break;

  case 6:
#line 115 "./src/parser.y"
    {
        (yyval.ivar) = 0;
    ;}
    break;

  case 7:
#line 120 "./src/parser.y"
    {
        (yyvsp[(4) - (4)].arrNode)->calculateRs();
        declareVariables((yyvsp[(1) - (4)].nodeID), (yyvsp[(3) - (4)].chType), (yyvsp[(4) - (4)].arrNode), lineas);
    ;}
    break;

  case 8:
#line 124 "./src/parser.y"
    {
        declareVariables((yyvsp[(1) - (3)].nodeID), (yyvsp[(3) - (3)].chType), nullptr, lineas);
    ;}
    break;

  case 9:
#line 129 "./src/parser.y"
    {
        ArrayNode *node = new ArrayNode((yyvsp[(1) - (1)].iarray));
        (yyval.arrNode) = node;
    ;}
    break;

  case 10:
#line 133 "./src/parser.y"
    {
        ArrayNode *node = new ArrayNode((yyvsp[(1) - (2)].iarray), (yyvsp[(2) - (2)].arrNode));
        (yyval.arrNode) = node;
    ;}
    break;

  case 11:
#line 139 "./src/parser.y"
    {
        (yyval.iarray) = (yyvsp[(2) - (3)].ival);
    ;}
    break;

  case 12:
#line 144 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (1)].sval));
        (yyval.nodeID) = node;
    ;}
    break;

  case 13:
#line 148 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].nodeID));
        (yyval.nodeID) = node;
    ;}
    break;

  case 16:
#line 158 "./src/parser.y"
    {
        declareFunction((yyvsp[(2) - (2)].sval), 7, lineas);
    ;}
    break;

  case 17:
#line 160 "./src/parser.y"
    {
        setCurrentParamCount((yyvsp[(5) - (7)].iparam));
    ;}
    break;

  case 18:
#line 162 "./src/parser.y"
    {
        setCurrentLocalVarCount((yyvsp[(11) - (11)].ivar));
        setCurrentCurrQuad();
        setCurrentFuncType((yyvsp[(9) - (11)].chType));
        setCurrentFunc((yyvsp[(2) - (11)].sval));
        createReturnAddress();
    ;}
    break;

  case 19:
#line 168 "./src/parser.y"
    {
        popReturnAddress();
        generateEndFunc();
        functionDirectory.removeVariableTable((yyvsp[(2) - (14)].sval));
    ;}
    break;

  case 20:
#line 175 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = (yyvsp[(1) - (1)].chType);
    ;}
    break;

  case 21:
#line 178 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = VOID_;
    ;}
    break;

  case 22:
#line 183 "./src/parser.y"
    {
        pushOperator(RETURN_);
    ;}
    break;

  case 23:
#line 185 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({RETURN_}));
        setFunctionReturn();
        verifyReturnType(getCurrentFuncType());
    ;}
    break;

  case 30:
#line 202 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), lineas, declareVariable((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), nullptr, lineas)->address);
        (yyval.iparam) = (yyvsp[(5) - (5)].iparam) + 1;
    ;}
    break;

  case 31:
#line 206 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), lineas, declareVariable((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), nullptr, lineas)->address);
        (yyval.iparam) = 1;
    ;}
    break;

  case 32:
#line 210 "./src/parser.y"
    {
        (yyval.iparam) = 0;
    ;}
    break;

  case 33:
#line 215 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({AND_, OR_}));
    ;}
    break;

  case 35:
#line 220 "./src/parser.y"
    {
        pushOperator(AND_);
    ;}
    break;

  case 37:
#line 223 "./src/parser.y"
    {
        pushOperator(OR_);
    ;}
    break;

  case 40:
#line 229 "./src/parser.y"
    {
        pushOperator(NOT_);
    ;}
    break;

  case 41:
#line 231 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({NOT_}));
    ;}
    break;

  case 43:
#line 237 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({GREATER_, LESS_, EQUALTO_, NOTEQUAL_, GREATEREQ_, LESSEQ_}));
    ;}
    break;

  case 45:
#line 242 "./src/parser.y"
    {
        pushOperator(GREATER_);
    ;}
    break;

  case 47:
#line 245 "./src/parser.y"
    {
        pushOperator(LESS_);
    ;}
    break;

  case 49:
#line 248 "./src/parser.y"
    {
        pushOperator(EQUALTO_);
    ;}
    break;

  case 51:
#line 251 "./src/parser.y"
    {
        pushOperator(NOTEQUAL_);
    ;}
    break;

  case 53:
#line 254 "./src/parser.y"
    {
        pushOperator(GREATEREQ_);
    ;}
    break;

  case 55:
#line 257 "./src/parser.y"
    {
        pushOperator(LESSEQ_);
    ;}
    break;

  case 58:
#line 263 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({ADD_, SUB_}));
    ;}
    break;

  case 60:
#line 268 "./src/parser.y"
    {
        pushOperator(ADD_);
    ;}
    break;

  case 62:
#line 271 "./src/parser.y"
    {
        pushOperator(SUB_);
    ;}
    break;

  case 65:
#line 277 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({MULTI_}));
        checkIfShouldDoOperation(vector<int>({MULTI_, DIV_, MOD_}));
    ;}
    break;

  case 67:
#line 283 "./src/parser.y"
    {
        pushOperator(MULTI_);
        pushOperandOfType(declareCte(INT_, -1), INT_);
    ;}
    break;

  case 68:
#line 287 "./src/parser.y"
    {
        pushOperator(MULTI_);
        pushOperandOfType(declareCte(INT_, 1), INT_);
    ;}
    break;

  case 69:
#line 293 "./src/parser.y"
    {
        pushOperator(MULTI_);
    ;}
    break;

  case 71:
#line 296 "./src/parser.y"
    {
        pushOperator(DIV_);
    ;}
    break;

  case 73:
#line 299 "./src/parser.y"
    {
        pushOperator(MOD_);
    ;}
    break;

  case 76:
#line 305 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 78:
#line 308 "./src/parser.y"
    {
        pushOperator(LEFTPAR_);
    ;}
    break;

  case 79:
#line 310 "./src/parser.y"
    {
        pushOperator(RIGHTPAR_);
    ;}
    break;

  case 81:
#line 316 "./src/parser.y"
    {
        pushOperandOfType(declareCte(FLOAT_, (yyvsp[(1) - (1)].fval)), FLOAT_);
    ;}
    break;

  case 82:
#line 319 "./src/parser.y"
    {
        pushOperandOfType(declareCte(INT_, (yyvsp[(1) - (1)].ival)), INT_);
    ;}
    break;

  case 83:
#line 322 "./src/parser.y"
    {
        pushOperandOfType(declareCte(BOOL_, (yyvsp[(1) - (1)].bval)), BOOL_);
    ;}
    break;

  case 84:
#line 327 "./src/parser.y"
    {
        verifyFunctionExists(getIDExpression(), lineas);
        setCurrentCall(getIDExpression());
    ;}
    break;

  case 85:
#line 330 "./src/parser.y"
    {
        generateEra(getCurrentCall());
        resetParameterCount(getCurrentCall());
        pushOperator(FAKEBOT_);
    ;}
    break;

  case 86:
#line 334 "./src/parser.y"
    {
        verifyParameters(getCurrentCall());
        generateGosub(getCurrentCall());
        pushOperandResult(getCurrentCall());
        setCurrentCall("");
        popOperator(FAKEBOT_);
    ;}
    break;

  case 87:
#line 341 "./src/parser.y"
    {
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 88:
#line 344 "./src/parser.y"
    {
        popOperator(FAKEBOT_);
    ;}
    break;

  case 89:
#line 347 "./src/parser.y"
    {
        pushOperandByID(getIDExpression());
    ;}
    break;

  case 92:
#line 356 "./src/parser.y"
    {
        generateVerify();
    ;}
    break;

  case 93:
#line 358 "./src/parser.y"
    {
        generateAccess();
    ;}
    break;

  case 94:
#line 363 "./src/parser.y"
    {
        cout << "gen param" << endl;
        generateParam();
    ;}
    break;

  case 97:
#line 370 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 109:
#line 389 "./src/parser.y"
    {
        (yyval.imgFunc) = GRAYSCALE_
    ;}
    break;

  case 110:
#line 392 "./src/parser.y"
    {
        (yyval.imgFunc) = SAVE_
    ;}
    break;

  case 111:
#line 395 "./src/parser.y"
    {
        (yyval.imgFunc) = OPEN_
    ;}
    break;

  case 112:
#line 400 "./src/parser.y"
    {
        performImageCall((yyvsp[(1) - (7)].sval), (yyvsp[(3) - (7)].imgFunc), (yyvsp[(5) - (7)].paramNode));
    ;}
    break;

  case 113:
#line 403 "./src/parser.y"
    {
        performImageCall((yyvsp[(1) - (6)].sval), (yyvsp[(3) - (6)].imgFunc), nullptr);
    ;}
    break;

  case 114:
#line 408 "./src/parser.y"
    {
        int type = topOperandType();
        ParamNode *node = new ParamNode(popOperand(), type);
        (yyval.paramNode) = node;
    ;}
    break;

  case 115:
#line 413 "./src/parser.y"
    {
        int type = topOperandType();
        ParamNode *node = new ParamNode(popOperand(), type, (yyvsp[(3) - (3)].paramNode));
        (yyval.paramNode) = node;
    ;}
    break;

  case 116:
#line 420 "./src/parser.y"
    {
        pushOperator(EQUALS_);
    ;}
    break;

  case 117:
#line 422 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({EQUALS_}));
    ;}
    break;

  case 118:
#line 427 "./src/parser.y"
    {
        pushOperandByID((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 119:
#line 430 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 120:
#line 434 "./src/parser.y"
    {
        popOperator(FAKEBOT_);
    ;}
    break;

  case 121:
#line 439 "./src/parser.y"
    {
        verifyFunctionExists((yyvsp[(1) - (1)].sval), lineas);
    ;}
    break;

  case 122:
#line 441 "./src/parser.y"
    {
        generateEra((yyvsp[(1) - (3)].sval));
        setCurrentCall((yyvsp[(1) - (3)].sval));
        resetParameterCount((yyvsp[(1) - (3)].sval));
    ;}
    break;

  case 123:
#line 445 "./src/parser.y"
    {
        verifyParameters((yyvsp[(1) - (6)].sval));
        generateGosub((yyvsp[(1) - (6)].sval));
        setCurrentCall("");
    ;}
    break;

  case 125:
#line 452 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 128:
#line 458 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 131:
#line 464 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 132:
#line 466 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
        generateNewline();
    ;}
    break;

  case 133:
#line 472 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
    ;}
    break;

  case 134:
#line 475 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 138:
#line 482 "./src/parser.y"
    {
        pushOperandOfType(declareCte(STRING_, (yyvsp[(1) - (1)].strval)), STRING_);
    ;}
    break;

  case 139:
#line 487 "./src/parser.y"
    {
        generateElse();
    ;}
    break;

  case 140:
#line 489 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 141:
#line 492 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 142:
#line 497 "./src/parser.y"
    {
        generateIf();
    ;}
    break;

  case 146:
#line 506 "./src/parser.y"
    {
        pushJumpCurrent();
    ;}
    break;

  case 147:
#line 508 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 148:
#line 510 "./src/parser.y"
    {
        fillJumpWhile();
    ;}
    break;

  case 149:
#line 515 "./src/parser.y"
    {
        // pushJumpCurrent();
    ;}
    break;

  case 150:
#line 517 "./src/parser.y"
    {
        pushLastAssignment();
        saveForVariable();
        pushJumpCurrent(-1);
    ;}
    break;

  case 151:
#line 521 "./src/parser.y"
    {
        validateLastAssignment(INT_);
        validateLastOperand(INT_);
        pushOperator(LESS_);
        doOperation();
    ;}
    break;

  case 152:
#line 526 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 153:
#line 528 "./src/parser.y"
    {
        fillJumpFor();
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2382 "./bin/parser.tab.c"
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


#line 532 "./src/parser.y"


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
