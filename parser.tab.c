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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

    #include <iostream>
    #include "compiler.h"
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
#line 17 "parser.y"
{
    char *sval;
    int ival;
    float fval;
    struct IDNode *nodeID;
    int chType; // 0 int, 1 float, 2 string, 3 void, 4 prog, 5 int arr, 6 float arr, 7 temp, -1 err
    int ivar;
    int iparam;
}
/* Line 193 of yacc.c.  */
#line 202 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 215 "parser.tab.c"

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
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    12,    17,    18,    22,    29,    31,
      35,    38,    39,    40,    41,    42,    57,    59,    61,    67,
      70,    74,    76,    78,    84,    88,    89,    90,    95,    97,
      99,   101,   102,   103,   108,   110,   112,   114,   116,   118,
     119,   123,   124,   128,   129,   133,   134,   135,   139,   140,
     144,   145,   149,   150,   152,   155,   156,   161,   162,   166,
     167,   171,   173,   175,   177,   179,   181,   185,   189,   193,
     195,   198,   199,   201,   203,   205,   207,   209,   212,   213,
     215,   217,   221,   222,   228,   230,   235,   236,   243,   246,
     247,   251,   252,   258,   262,   264,   266,   268,   269,   274,
     276,   277,   284,   286,   288,   289,   290,   299
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    -1,     7,     6,    43,    39,    44,    47,
      54,    -1,     8,    45,    39,    44,    -1,    -1,    46,    38,
      55,    -1,    46,    38,    55,    36,     3,    37,    -1,     6,
      -1,     6,    40,    46,    -1,    48,    47,    -1,    -1,    -1,
      -1,    -1,    18,     6,    49,    32,    56,    33,    38,    50,
      52,    34,    44,    51,    83,    35,    -1,    55,    -1,    20,
      -1,    19,    32,    57,    33,    39,    -1,    19,    39,    -1,
      34,    81,    35,    -1,     9,    -1,    10,    -1,     6,    38,
      55,    40,    56,    -1,     6,    38,    55,    -1,    -1,    -1,
      60,    58,    59,    60,    -1,    60,    -1,    30,    -1,    31,
      -1,    -1,    -1,    63,    61,    62,    63,    -1,    63,    -1,
      26,    -1,    25,    -1,    29,    -1,    27,    -1,    -1,    68,
      64,    65,    -1,    -1,    21,    66,    63,    -1,    -1,    22,
      67,    63,    -1,    -1,    -1,    73,    69,    70,    -1,    -1,
      23,    71,    68,    -1,    -1,    24,    72,    68,    -1,    -1,
       6,    -1,     6,    79,    -1,    -1,    32,    74,    57,    33,
      -1,    -1,    21,    75,    78,    -1,    -1,    22,    76,    78,
      -1,    78,    -1,    57,    -1,     3,    -1,     4,    -1,     3,
      -1,    32,    80,    33,    -1,    36,    77,    37,    -1,    57,
      40,    80,    -1,    57,    -1,    82,    81,    -1,    -1,    85,
      -1,    88,    -1,    92,    -1,    95,    -1,    99,    -1,    84,
      83,    -1,    -1,    82,    -1,    53,    -1,    87,    28,    88,
      -1,    -1,    87,    28,    86,    57,    39,    -1,     6,    -1,
       6,    36,    77,    37,    -1,    -1,     6,    89,    32,    90,
      33,    39,    -1,    57,    91,    -1,    -1,    40,    57,    91,
      -1,    -1,    13,    32,    93,    33,    39,    -1,    94,    40,
      93,    -1,    94,    -1,    57,    -1,     5,    -1,    -1,    97,
      12,    96,    54,    -1,    97,    -1,    -1,    11,    32,    57,
      33,    98,    54,    -1,   100,    -1,   103,    -1,    -1,    -1,
      16,   101,    32,    57,    33,   102,    15,    54,    -1,    14,
      32,     6,    28,    57,    17,    57,    33,    54,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    79,    87,    90,    95,    98,   103,   107,
     113,   114,   117,   119,   121,   117,   130,   133,   138,   139,
     142,   145,   146,   149,   154,   159,   164,   164,   167,   170,
     173,   176,   179,   179,   182,   185,   188,   191,   194,   199,
     199,   204,   204,   207,   207,   210,   213,   213,   218,   218,
     221,   221,   224,   227,   230,   231,   231,   236,   236,   239,
     239,   242,   245,   246,   249,   252,   257,   258,   261,   262,
     265,   266,   269,   270,   271,   272,   273,   276,   277,   280,
     281,   284,   285,   285,   292,   295,   298,   298,   303,   304,
     307,   308,   311,   314,   315,   318,   319,   322,   322,   325,
     328,   328,   335,   336,   339,   341,   339,   348
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CTE_INT", "CTE_FLOAT", "CTE_STRING",
  "ID", "PROGRAM", "VAR", "INT", "FLOAT", "IF", "ELSE", "PRINT", "FOR",
  "DO", "WHILE", "TO", "FUNCTION", "RETURN", "VOID", "ADDITION",
  "SUBSTRACTION", "MULTI", "DIV", "LESS_THAN", "MORE_THAN", "NOT_EQUAL",
  "EQUAL", "EQUAL_TO", "AND", "OR", "LEFT_PAR", "RIGHT_PAR", "LEFT_CURLY",
  "RIGHT_CURLY", "LEFT_BRACK", "RIGHT_BRACK", "COLON", "SEMICOLON",
  "COMMA", "$accept", "program", "@1", "vars", "var", "var_list",
  "functions", "function", "@2", "@3", "@4", "function_type", "return",
  "block", "type", "params", "expression", "@5", "expression2", "comp",
  "@6", "comp2", "exp", "@7", "exp2", "@8", "@9", "term", "@10", "term2",
  "@11", "@12", "factor", "@13", "@14", "@15", "index", "var_cte",
  "array_or_func", "arguments", "statements", "statement",
  "function_statements", "function_statement", "assignment", "@16",
  "assignee", "call", "@17", "call2", "call3", "printing", "printing_2",
  "printing_3", "conditional", "@18", "conditional_if", "@19",
  "repetition", "rep_cond", "@20", "@21", "rep_no_cond", 0
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
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    43,    42,    44,    44,    45,    45,    46,    46,
      47,    47,    49,    50,    51,    48,    52,    52,    53,    53,
      54,    55,    55,    56,    56,    56,    58,    57,    57,    59,
      59,    59,    61,    60,    60,    62,    62,    62,    62,    64,
      63,    66,    65,    67,    65,    65,    69,    68,    71,    70,
      72,    70,    70,    73,    73,    74,    73,    75,    73,    76,
      73,    73,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    82,    82,    82,    83,    83,    84,
      84,    85,    86,    85,    87,    87,    89,    88,    90,    90,
      91,    91,    92,    93,    93,    94,    94,    96,    95,    95,
      98,    97,    99,    99,   101,   102,   100,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     4,     0,     3,     6,     1,     3,
       2,     0,     0,     0,     0,    14,     1,     1,     5,     2,
       3,     1,     1,     5,     3,     0,     0,     4,     1,     1,
       1,     0,     0,     4,     1,     1,     1,     1,     1,     0,
       3,     0,     3,     0,     3,     0,     0,     3,     0,     3,
       0,     3,     0,     1,     2,     0,     4,     0,     3,     0,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       2,     0,     1,     1,     1,     1,     1,     2,     0,     1,
       1,     3,     0,     5,     1,     4,     0,     6,     2,     0,
       3,     0,     5,     3,     1,     1,     1,     0,     4,     1,
       0,     6,     1,     1,     0,     0,     8,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     5,     0,    11,     8,
       0,     0,     0,     0,    11,     0,     5,     0,    12,    71,
       3,    10,     9,     4,    21,    22,     6,     0,    84,     0,
       0,     0,   104,     0,    71,    72,     0,    73,    74,    75,
      99,    76,   102,   103,     0,    25,     0,     0,     0,     0,
       0,     0,    20,    70,    82,    97,     0,     0,     0,    65,
      64,    53,    57,    59,    55,    62,    26,    34,    39,    46,
       0,    61,    89,    65,     0,    96,    95,     0,    94,     0,
       0,    86,     0,    81,     0,     7,     0,     0,     0,     0,
      54,     0,     0,     0,    31,     0,    45,    52,    85,    91,
       0,   100,     0,     0,     0,     0,     0,    98,    24,    13,
      69,     0,     0,    58,    60,     0,    29,    30,     0,    36,
      35,    38,    37,     0,    41,    43,    40,    48,    50,    47,
       0,    88,     0,     0,    92,    93,     0,   105,    83,    25,
       0,     0,    66,    67,    56,    27,    33,     0,     0,     0,
       0,    91,    87,   101,     0,     0,    23,    17,     0,    16,
      68,    42,    44,    49,    51,    90,     0,     0,     5,     0,
     106,    14,   107,    78,     0,    80,    79,     0,    78,     0,
      19,    15,    77,     0,     0,    18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     8,    10,    11,    13,    14,    27,   140,
     173,   158,   175,    20,    26,    58,    65,    94,   118,    66,
      95,   123,    67,    96,   126,   147,   148,    68,    97,   129,
     149,   150,    69,    93,    91,    92,    70,    71,    90,   111,
      33,    34,   177,   178,    35,    82,    36,    37,    47,   100,
     131,    38,    77,    78,    39,    84,    40,   133,    41,    42,
      51,   155,    43
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -157
static const yytype_int16 yypact[] =
{
       4,    20,    36,  -157,  -157,    14,    47,    55,    50,    37,
      48,    42,    76,    58,    50,    55,    47,    11,  -157,    65,
    -157,  -157,  -157,  -157,  -157,  -157,    66,    69,    18,    71,
      73,    74,  -157,    75,    65,  -157,    80,  -157,  -157,  -157,
      92,  -157,  -157,  -157,   106,   105,     6,    81,    10,     2,
     108,    83,  -157,  -157,   110,  -157,    82,    79,    85,    84,
    -157,    28,  -157,  -157,  -157,  -157,    26,    22,  -157,  -157,
      86,  -157,    10,  -157,    87,  -157,  -157,    89,    88,    96,
      10,  -157,    10,  -157,    58,  -157,    11,    91,    10,     6,
    -157,    41,    41,    10,    43,    64,    63,    72,  -157,    90,
      93,  -157,    94,     2,    10,    98,    95,  -157,    97,  -157,
      99,   102,   101,  -157,  -157,   103,  -157,  -157,    10,  -157,
    -157,  -157,  -157,    10,  -157,  -157,  -157,  -157,  -157,  -157,
      10,  -157,   104,    58,  -157,  -157,   123,  -157,  -157,   105,
       9,    10,  -157,  -157,  -157,  -157,  -157,    10,    10,    10,
      10,    90,  -157,  -157,    10,   112,  -157,  -157,    78,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,   109,    58,    47,    58,
    -157,  -157,  -157,    56,    -2,  -157,  -157,   111,    56,    10,
    -157,  -157,  -157,   114,   115,  -157
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,   -16,  -157,   126,   130,  -157,  -157,  -157,
    -157,  -157,  -157,   -81,   -82,   -14,   -47,  -157,  -157,    27,
    -157,  -157,  -108,  -157,  -157,  -157,  -157,   -52,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,    59,     8,  -157,    12,
     116,  -156,   -29,  -157,  -157,  -157,  -157,   107,  -157,  -157,
       0,  -157,    52,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -87
static const yytype_int16 yytable[] =
{
      23,    74,    76,   107,   108,    73,    60,    75,    61,    59,
      60,     1,    61,    73,    60,   146,    61,   176,    24,    25,
      24,    25,   176,    62,    63,    99,     3,    62,    63,   157,
     179,    62,    63,   105,    64,   106,     4,   180,    64,   161,
     162,   110,    64,   -28,    73,    60,   115,   -32,   -32,   -32,
     -86,   -32,   153,     6,    46,     7,    76,   136,   159,   -28,
      88,     9,    28,   -28,    89,   -28,   -28,    29,    12,    30,
      31,    28,    32,   116,   117,   174,    29,    15,    30,    31,
      17,    32,    18,   151,   124,   125,   170,    16,   172,   119,
     120,   121,    19,   122,   110,   127,   128,   163,   164,   113,
     114,    45,    44,    48,    55,    49,    50,   166,    54,    56,
      52,    57,   168,    72,    79,    80,    81,    86,    87,    85,
     101,   -63,   102,    98,   104,   156,   132,   167,   103,   109,
     130,   137,   183,   134,   138,   142,   144,   139,   143,   141,
     154,    22,   169,   152,    21,   145,   181,   184,   112,   182,
      53,   165,   171,   160,   185,   135,     0,     0,     0,     0,
       0,    83
};

static const yytype_int16 yycheck[] =
{
      16,    48,    49,    84,    86,     3,     4,     5,     6,     3,
       4,     7,     6,     3,     4,   123,     6,   173,     9,    10,
       9,    10,   178,    21,    22,    72,     6,    21,    22,    20,
      32,    21,    22,    80,    32,    82,     0,    39,    32,   147,
     148,    88,    32,    17,     3,     4,    93,    25,    26,    27,
      32,    29,   133,    39,    36,     8,   103,   104,   140,    33,
      32,     6,     6,    37,    36,    39,    40,    11,    18,    13,
      14,     6,    16,    30,    31,    19,    11,    40,    13,    14,
      38,    16,     6,   130,    21,    22,   167,    39,   169,    25,
      26,    27,    34,    29,   141,    23,    24,   149,   150,    91,
      92,    32,    36,    32,    12,    32,    32,   154,    28,     3,
      35,     6,    34,    32,     6,    32,     6,    38,    33,    37,
      33,    37,    33,    37,    28,   139,    33,    15,    40,    38,
      40,    33,   179,    39,    39,    33,    33,    40,    37,    40,
      17,    15,    33,    39,    14,   118,    35,    33,    89,   178,
      34,   151,   168,   141,    39,   103,    -1,    -1,    -1,    -1,
      -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    42,     6,     0,    43,    39,     8,    44,     6,
      45,    46,    18,    47,    48,    40,    39,    38,     6,    34,
      54,    47,    46,    44,     9,    10,    55,    49,     6,    11,
      13,    14,    16,    81,    82,    85,    87,    88,    92,    95,
      97,    99,   100,   103,    36,    32,    36,    89,    32,    32,
      32,   101,    35,    81,    28,    12,     3,     6,    56,     3,
       4,     6,    21,    22,    32,    57,    60,    63,    68,    73,
      77,    78,    32,     3,    57,     5,    57,    93,    94,     6,
      32,     6,    86,    88,    96,    37,    38,    33,    32,    36,
      79,    75,    76,    74,    58,    61,    64,    69,    37,    57,
      90,    33,    33,    40,    28,    57,    57,    54,    55,    38,
      57,    80,    77,    78,    78,    57,    30,    31,    59,    25,
      26,    27,    29,    62,    21,    22,    65,    23,    24,    70,
      40,    91,    33,    98,    39,    93,    57,    33,    39,    40,
      50,    40,    33,    37,    33,    60,    63,    66,    67,    71,
      72,    57,    39,    54,    17,   102,    56,    20,    52,    55,
      80,    63,    63,    68,    68,    91,    57,    15,    34,    33,
      54,    44,    54,    51,    19,    53,    82,    83,    84,    32,
      39,    35,    83,    57,    33,    39
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
#line 79 "parser.y"
    {
        declareMainFunction((yyvsp[(2) - (2)].sval), lineas, &functionDirectory);
    ;}
    break;

  case 3:
#line 81 "parser.y"
    {
        printf("Valid syntax.\n");
        printQuads();
    ;}
    break;

  case 4:
#line 87 "parser.y"
    {
        (yyval.ivar) = (yyvsp[(4) - (4)].ivar) + 1;
    ;}
    break;

  case 5:
#line 90 "parser.y"
    {
        (yyval.ivar) = 0;
    ;}
    break;

  case 6:
#line 95 "parser.y"
    {
        declareVariables((yyvsp[(1) - (3)].nodeID), (yyvsp[(3) - (3)].chType), lineas);
    ;}
    break;

  case 7:
#line 98 "parser.y"
    {
        declareArrays((yyvsp[(1) - (6)].nodeID), (yyvsp[(3) - (6)].chType), (yyvsp[(5) - (6)].ival), lineas);
    ;}
    break;

  case 8:
#line 103 "parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (1)].sval));
        (yyval.nodeID) = node;
    ;}
    break;

  case 9:
#line 107 "parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].nodeID));
        (yyval.nodeID) = node;
    ;}
    break;

  case 12:
#line 117 "parser.y"
    {
        declareFunction((yyvsp[(2) - (2)].sval), 7, lineas);
    ;}
    break;

  case 13:
#line 119 "parser.y"
    {
        setCurrentParamCount((yyvsp[(5) - (7)].iparam));
    ;}
    break;

  case 14:
#line 121 "parser.y"
    {
        setCurrentLocalVarCount((yyvsp[(9) - (11)].chType));
        setCurrentCurrQuad();
    ;}
    break;

  case 15:
#line 124 "parser.y"
    {
        generateEndFunc();
        functionDirectory.remove((yyvsp[(2) - (14)].sval));
    ;}
    break;

  case 16:
#line 130 "parser.y"
    {
        functionDirectory.currentFunction()->type = (yyvsp[(1) - (1)].chType);
    ;}
    break;

  case 17:
#line 133 "parser.y"
    {
        functionDirectory.currentFunction()->type = 5;
    ;}
    break;

  case 23:
#line 149 "parser.y"
    {
        declareParameter((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), lineas);
        declareVariable((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), lineas);
        (yyval.iparam) = (yyvsp[(5) - (5)].iparam) + 1;
    ;}
    break;

  case 24:
#line 154 "parser.y"
    {
        declareParameter((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), lineas);
        declareVariable((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), lineas);
        (yyval.iparam) = 1;
    ;}
    break;

  case 25:
#line 159 "parser.y"
    {
        (yyval.iparam) = 0;
    ;}
    break;

  case 26:
#line 164 "parser.y"
    {
        checkIfShouldDoOperation(vector<int>({9, 10}));
    ;}
    break;

  case 29:
#line 170 "parser.y"
    {
        pushOperator(9);
    ;}
    break;

  case 30:
#line 173 "parser.y"
    {
        pushOperator(10);
    ;}
    break;

  case 32:
#line 179 "parser.y"
    {
        checkIfShouldDoOperation(vector<int>({5, 6, 7, 8}));
    ;}
    break;

  case 35:
#line 185 "parser.y"
    {
        pushOperator(5);
    ;}
    break;

  case 36:
#line 188 "parser.y"
    {
        pushOperator(6);
    ;}
    break;

  case 37:
#line 191 "parser.y"
    {
        pushOperator(7);
    ;}
    break;

  case 38:
#line 194 "parser.y"
    {
        pushOperator(8);
    ;}
    break;

  case 39:
#line 199 "parser.y"
    {
        checkIfShouldDoOperation(vector<int>({1, 2}));
    ;}
    break;

  case 41:
#line 204 "parser.y"
    {
        pushOperator(1);
    ;}
    break;

  case 43:
#line 207 "parser.y"
    {
        pushOperator(2);
    ;}
    break;

  case 46:
#line 213 "parser.y"
    {
        checkIfShouldDoOperation(vector<int>({3, 4}));
    ;}
    break;

  case 48:
#line 218 "parser.y"
    {
        pushOperator(3);
    ;}
    break;

  case 50:
#line 221 "parser.y"
    {
        pushOperator(4)
    ;}
    break;

  case 53:
#line 227 "parser.y"
    {
        pushOperandByID((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 55:
#line 231 "parser.y"
    {
        pushOperator(11);
    ;}
    break;

  case 56:
#line 233 "parser.y"
    {
        pushOperator(12);
    ;}
    break;

  case 57:
#line 236 "parser.y"
    {
        pushOperator(1);
    ;}
    break;

  case 59:
#line 239 "parser.y"
    {
        pushOperator(2);
    ;}
    break;

  case 64:
#line 249 "parser.y"
    {
        pushOperandOfType(declareCte(1), 1);
    ;}
    break;

  case 65:
#line 252 "parser.y"
    {
        pushOperandOfType(declareCte(0), 0);
    ;}
    break;

  case 82:
#line 285 "parser.y"
    {
        pushOperator(0);
    ;}
    break;

  case 83:
#line 287 "parser.y"
    {
        checkIfShouldDoOperation(vector<int>({0}));
    ;}
    break;

  case 84:
#line 292 "parser.y"
    {
        pushOperandByID((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 86:
#line 298 "parser.y"
    {
        verifyFunctionExists((yyvsp[(1) - (1)].sval), lineas);
    ;}
    break;

  case 97:
#line 322 "parser.y"
    {
        generateElse();
    ;}
    break;

  case 100:
#line 328 "parser.y"
    {
        generateIf();
    ;}
    break;

  case 101:
#line 330 "parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 104:
#line 339 "parser.y"
    {
        pushJumpCurrent();
    ;}
    break;

  case 105:
#line 341 "parser.y"
    {
        generateWhile();
    ;}
    break;

  case 106:
#line 343 "parser.y"
    {
        fillJumpWhile();
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1929 "parser.tab.c"
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


#line 350 "parser.y"


int main() {
    FILE *myfile = fopen("code.txt", "r");
    if (!myfile) {
        cout << "No 'code.txt' file found." << endl;
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
