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
     NOT = 287,
     LEFT_PAR = 288,
     RIGHT_PAR = 289,
     LEFT_CURLY = 290,
     RIGHT_CURLY = 291,
     LEFT_BRACK = 292,
     RIGHT_BRACK = 293,
     COLON = 294,
     SEMICOLON = 295,
     COMMA = 296
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
#define NOT 287
#define LEFT_PAR 288
#define RIGHT_PAR 289
#define LEFT_CURLY 290
#define RIGHT_CURLY 291
#define LEFT_BRACK 292
#define RIGHT_BRACK 293
#define COLON 294
#define SEMICOLON 295
#define COMMA 296




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
    struct IDNode *nodeID;
    struct ArrayNode *arrNode;
    int chType; // 0 int, 1 float, 2 string, 3 void, 4 prog, 5 int arr, 6 float arr, 7 temp, -1 err
    int ivar;
    int iparam;
    int iarray;
}
/* Line 193 of yacc.c.  */
#line 207 "./bin/parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 220 "./bin/parser.tab.c"

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
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNRULES -- Number of states.  */
#define YYNSTATES  214

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    14,    19,    20,    25,    29,
      31,    34,    38,    40,    44,    47,    48,    49,    50,    51,
      66,    68,    70,    71,    78,    81,    85,    87,    89,    95,
      99,   100,   101,   105,   106,   110,   111,   115,   116,   117,
     121,   123,   124,   128,   129,   133,   134,   138,   139,   143,
     144,   148,   149,   150,   154,   155,   159,   160,   164,   165,
     166,   170,   171,   175,   176,   180,   181,   182,   186,   187,
     192,   194,   196,   198,   199,   200,   206,   207,   210,   211,
     214,   216,   217,   222,   223,   227,   228,   229,   234,   235,
     238,   239,   242,   244,   246,   248,   250,   252,   253,   258,
     260,   261,   265,   266,   267,   268,   277,   278,   282,   283,
     284,   289,   290,   291,   299,   300,   301,   307,   308,   310,
     312,   313,   318,   320,   321,   328,   330,   332,   333,   334,
     343,   344,   345,   346,   347
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      43,     0,    -1,    -1,    -1,     7,     6,    44,    40,    46,
      51,    45,    59,    -1,     8,    47,    40,    46,    -1,    -1,
      50,    39,    60,    48,    -1,    50,    39,    60,    -1,    49,
      -1,    49,    48,    -1,    37,     3,    38,    -1,     6,    -1,
       6,    41,    50,    -1,    52,    51,    -1,    -1,    -1,    -1,
      -1,    18,     6,    53,    33,    61,    34,    39,    54,    56,
      35,    46,    55,   101,    36,    -1,    60,    -1,    20,    -1,
      -1,    19,    58,    33,    62,    34,    40,    -1,    19,    40,
      -1,    35,   101,    36,    -1,     9,    -1,    10,    -1,     6,
      39,    60,    41,    61,    -1,     6,    39,    60,    -1,    -1,
      -1,    67,    63,    64,    -1,    -1,    30,    65,    62,    -1,
      -1,    31,    66,    62,    -1,    -1,    -1,    32,    68,    69,
      -1,    69,    -1,    -1,    76,    70,    71,    -1,    -1,    26,
      72,    69,    -1,    -1,    25,    73,    69,    -1,    -1,    29,
      74,    69,    -1,    -1,    27,    75,    69,    -1,    -1,    -1,
      81,    77,    78,    -1,    -1,    21,    79,    76,    -1,    -1,
      22,    80,    76,    -1,    -1,    -1,    86,    82,    83,    -1,
      -1,    23,    84,    81,    -1,    -1,    24,    85,    81,    -1,
      -1,    -1,     6,    87,    90,    -1,    -1,    33,    88,    62,
      34,    -1,    89,    -1,     4,    -1,     3,    -1,    -1,    -1,
      91,    33,    92,    97,    34,    -1,    -1,    93,    94,    -1,
      -1,    95,    94,    -1,    95,    -1,    -1,    37,    62,    96,
      38,    -1,    -1,    62,    98,    99,    -1,    -1,    -1,    41,
      62,   100,    99,    -1,    -1,   102,   101,    -1,    -1,   103,
      40,    -1,   107,    -1,   115,    -1,   121,    -1,   125,    -1,
      57,    -1,    -1,   105,    28,   104,    62,    -1,     6,    -1,
      -1,     6,   106,    94,    -1,    -1,    -1,    -1,     6,   108,
      33,   109,   111,    34,   110,    40,    -1,    -1,    62,   112,
     113,    -1,    -1,    -1,    41,    62,   114,   113,    -1,    -1,
      -1,    13,   116,    33,   120,   117,    34,    40,    -1,    -1,
      -1,   118,    41,   119,   120,   117,    -1,    -1,    62,    -1,
       5,    -1,    -1,   123,    12,   122,    59,    -1,   123,    -1,
      -1,    11,    33,    62,    34,   124,    59,    -1,   126,    -1,
     129,    -1,    -1,    -1,    16,   127,    33,    62,    34,   128,
      15,    59,    -1,    -1,    -1,    -1,    -1,    14,   130,    33,
     103,   131,    17,    62,   132,    34,   133,    59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    88,    85,    96,    99,   104,   108,   113,
     117,   123,   128,   132,   138,   139,   142,   144,   146,   142,
     159,   162,   167,   167,   174,   177,   180,   181,   184,   188,
     192,   197,   197,   202,   202,   205,   205,   208,   211,   211,
     216,   219,   219,   224,   224,   227,   227,   230,   230,   233,
     233,   236,   239,   239,   244,   244,   247,   247,   250,   253,
     253,   258,   258,   261,   261,   264,   267,   267,   270,   270,
     281,   284,   287,   292,   295,   292,   306,   306,   312,   317,
     318,   321,   321,   328,   328,   331,   334,   334,   337,   340,
     341,   344,   345,   346,   347,   348,   349,   352,   352,   359,
     362,   362,   371,   373,   377,   371,   384,   384,   387,   390,
     390,   393,   396,   396,   404,   407,   404,   410,   413,   414,
     419,   419,   424,   429,   429,   434,   435,   438,   440,   438,
     447,   449,   453,   458,   447
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
  "EQUAL", "EQUAL_TO", "AND", "OR", "NOT", "LEFT_PAR", "RIGHT_PAR",
  "LEFT_CURLY", "RIGHT_CURLY", "LEFT_BRACK", "RIGHT_BRACK", "COLON",
  "SEMICOLON", "COMMA", "$accept", "program", "@1", "@2", "vars", "var",
  "array_list", "array_declaration", "var_list", "functions", "function",
  "@3", "@4", "@5", "function_type", "return", "@6", "block", "type",
  "params", "expression", "@7", "expression2", "@8", "@9",
  "not_expression", "@10", "comp", "@11", "comp2", "@12", "@13", "@14",
  "@15", "exp", "@16", "exp2", "@17", "@18", "term", "@19", "term2", "@20",
  "@21", "factor", "@22", "@23", "var_cte", "array_or_func", "@24", "@25",
  "@26", "arrays", "array", "@27", "arguments", "@28", "arguments2", "@29",
  "statements", "statement", "assignment", "@30", "assignee", "@31",
  "call", "@32", "@33", "@34", "call2", "@35", "call3", "@36", "printing",
  "@37", "printing_2", "@38", "@39", "expression_or_str", "conditional",
  "@40", "conditional_if", "@41", "repetition", "rep_cond", "@42", "@43",
  "rep_no_cond", "@44", "@45", "@46", "@47", 0
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
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    45,    43,    46,    46,    47,    47,    48,
      48,    49,    50,    50,    51,    51,    53,    54,    55,    52,
      56,    56,    58,    57,    57,    59,    60,    60,    61,    61,
      61,    63,    62,    65,    64,    66,    64,    64,    68,    67,
      67,    70,    69,    72,    71,    73,    71,    74,    71,    75,
      71,    71,    77,    76,    79,    78,    80,    78,    78,    82,
      81,    84,    83,    85,    83,    83,    87,    86,    88,    86,
      86,    89,    89,    91,    92,    90,    93,    90,    90,    94,
      94,    96,    95,    98,    97,    97,   100,    99,    99,   101,
     101,   102,   102,   102,   102,   102,   102,   104,   103,   105,
     106,   105,   108,   109,   110,   107,   112,   111,   111,   114,
     113,   113,   116,   115,   118,   119,   117,   117,   120,   120,
     122,   121,   121,   124,   123,   125,   125,   127,   128,   126,
     130,   131,   132,   133,   129
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     4,     0,     4,     3,     1,
       2,     3,     1,     3,     2,     0,     0,     0,     0,    14,
       1,     1,     0,     6,     2,     3,     1,     1,     5,     3,
       0,     0,     3,     0,     3,     0,     3,     0,     0,     3,
       1,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     0,     3,     0,     3,     0,     3,     0,     0,
       3,     0,     3,     0,     3,     0,     0,     3,     0,     4,
       1,     1,     1,     0,     0,     5,     0,     2,     0,     2,
       1,     0,     4,     0,     3,     0,     0,     4,     0,     2,
       0,     2,     1,     1,     1,     1,     1,     0,     4,     1,
       0,     3,     0,     0,     0,     8,     0,     3,     0,     0,
       4,     0,     0,     7,     0,     0,     5,     0,     1,     1,
       0,     4,     1,     0,     6,     1,     1,     0,     0,     8,
       0,     0,     0,     0,    11
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     6,     0,    15,    12,
       0,     0,     0,     3,    15,     0,     6,     0,    16,     0,
      14,    13,     5,    26,    27,     8,     0,    90,     4,     0,
       7,     9,    30,    99,     0,   112,   130,   127,    22,    96,
       0,    90,     0,     0,    92,    93,    94,   122,    95,   125,
     126,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,    25,    89,    91,    97,   120,    11,     0,
       0,     0,   101,    80,   103,    72,    71,    66,    38,    68,
       0,    31,    40,    41,    52,    59,    70,     0,     0,     0,
       0,     0,     0,    29,    17,    81,    79,   108,    78,     0,
       0,   123,    37,    51,    58,    65,   119,   118,   114,    99,
     131,     0,     0,    98,   121,    30,     0,     0,   106,     0,
      67,     0,     0,    39,     0,     0,    33,    35,    32,    45,
      43,    49,    47,    42,    54,    56,    53,    61,    63,    60,
       0,     0,     0,   128,     0,    28,    21,     0,    20,    82,
     111,   104,    74,    77,    69,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,     0,     0,
      23,     6,     0,   107,     0,    85,    34,    36,    46,    44,
      50,    48,    55,    57,    62,    64,   113,     0,   132,     0,
      18,   109,   105,    83,     0,   114,     0,   129,    90,   111,
      88,    75,   116,   133,     0,   110,     0,    84,     0,    19,
      86,   134,    88,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    19,     8,    10,    30,    31,    11,    13,
      14,    26,   116,   198,   147,    39,    62,    28,    25,    54,
     107,   102,   128,   156,   157,    81,    99,    82,   103,   133,
     159,   158,   161,   160,    83,   104,   136,   162,   163,    84,
     105,   139,   164,   165,    85,    98,   100,    86,   120,   121,
     175,   122,    72,    73,   117,   194,   200,   207,   212,    40,
      41,    42,    91,    43,    55,    44,    56,    97,   174,   119,
     150,   173,   199,    45,    58,   140,   141,   187,   108,    46,
      92,    47,   125,    48,    49,    60,   169,    50,    59,   142,
     196,   208
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -97
static const yytype_int8 yypact[] =
{
       0,    18,    47,   -97,   -97,     9,    21,    45,    39,    20,
      30,    34,    68,   -97,    39,    45,    21,    22,   -97,    40,
     -97,   -97,   -97,   -97,   -97,    41,    44,    14,   -97,    73,
     -97,    41,    74,   -11,    46,   -97,   -97,   -97,    42,   -97,
      48,    14,    49,    53,   -97,   -97,   -97,    71,   -97,   -97,
     -97,    50,   -97,    51,    52,    54,    59,    11,    60,    61,
      62,   -97,    63,   -97,   -97,   -97,   -97,   -97,   -97,    22,
      58,    11,   -97,    54,   -97,   -97,   -97,   -97,   -97,   -97,
      64,   -97,   -97,   -97,   -97,   -97,   -97,     5,    79,    11,
      11,    11,    40,    65,   -97,   -97,   -97,    11,    13,    15,
      11,   -97,    10,    29,    38,    43,   -97,   -97,    66,    67,
     -97,    75,    76,   -97,   -97,    74,     3,    69,   -97,    77,
     -97,    72,    54,   -97,    78,    40,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
      80,    82,    70,   -97,    81,   -97,   -97,    83,   -97,   -97,
      84,   -97,   -97,   -97,   -97,   -97,    11,    11,    15,    15,
      15,    15,    15,    15,    15,    15,    86,   -97,    11,    93,
     -97,    21,    11,   -97,    87,    11,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,     5,   -97,    40,
     -97,   -97,   -97,   -97,    85,    66,    90,   -97,    14,    84,
      88,   -97,   -97,   -97,    92,   -97,    11,   -97,    40,   -97,
     -97,   -97,    88,   -97
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -97,   -97,   -97,   -97,   -15,   -97,    99,   -97,   100,   102,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -86,   -64,   -16,
     -55,   -97,   -97,   -97,   -97,   -97,   -97,   -96,   -97,   -97,
     -97,   -97,   -97,   -97,   -94,   -97,   -97,   -97,   -97,   -93,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -69,   -97,   -97,   -97,   -97,   -81,   -97,   -41,
     -97,    55,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -67,   -97,   -97,   -97,   -62,   -97,   -97,   -53,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -118
static const yytype_int16 yytable[] =
{
      64,    22,    80,   123,    96,    93,   114,     1,    75,    76,
     106,    77,    23,    24,    75,    76,    95,    77,    75,    76,
      33,    77,  -102,   146,     3,    34,  -100,    35,    36,     7,
      37,    23,    24,    38,   111,   112,   113,    78,    79,   155,
     126,   127,   118,    78,    79,   124,   -73,     4,    79,     6,
     -76,     9,   148,   153,   129,   130,   131,    12,   132,   134,
     135,    15,   178,   179,   180,   181,   137,   138,   182,   183,
      16,   184,   185,    17,    18,    27,    51,    32,    29,    57,
      53,    66,    61,    67,    63,   109,    70,   168,    68,    65,
      69,    71,    74,    87,    88,    89,    90,    94,   101,   145,
    -117,   176,   177,   197,  -100,   152,   115,   149,   189,   143,
     144,   151,   154,   188,   166,    21,    20,   191,   171,   201,
     193,   170,   211,   167,   203,   172,   186,   192,   209,   206,
      52,   213,   205,   202,   195,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,   190,   204
};

static const yytype_int16 yycheck[] =
{
      41,    16,    57,    99,    73,    69,    92,     7,     3,     4,
       5,     6,     9,    10,     3,     4,    71,     6,     3,     4,
       6,     6,    33,    20,     6,    11,    37,    13,    14,     8,
      16,     9,    10,    19,    89,    90,    91,    32,    33,   125,
      30,    31,    97,    32,    33,   100,    33,     0,    33,    40,
      37,     6,   116,   122,    25,    26,    27,    18,    29,    21,
      22,    41,   158,   159,   160,   161,    23,    24,   162,   163,
      40,   164,   165,    39,     6,    35,     3,    33,    37,    33,
       6,    28,    40,    12,    36,     6,    34,    17,    38,    40,
      39,    37,    33,    33,    33,    33,    33,    39,    34,   115,
      34,   156,   157,   189,    37,    33,    41,    38,    15,    34,
      34,    34,    34,   168,    34,    15,    14,   172,    35,    34,
     175,    40,   208,    41,    34,    41,    40,    40,    36,    41,
      31,   212,   199,   195,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,    -1,    -1,    -1,    -1,   171,   198
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    43,     6,     0,    44,    40,     8,    46,     6,
      47,    50,    18,    51,    52,    41,    40,    39,     6,    45,
      51,    50,    46,     9,    10,    60,    53,    35,    59,    37,
      48,    49,    33,     6,    11,    13,    14,    16,    19,    57,
     101,   102,   103,   105,   107,   115,   121,   123,   125,   126,
     129,     3,    48,     6,    61,   106,   108,    33,   116,   130,
     127,    40,    58,    36,   101,    40,    28,    12,    38,    39,
      34,    37,    94,    95,    33,     3,     4,     6,    32,    33,
      62,    67,    69,    76,    81,    86,    89,    33,    33,    33,
      33,   104,   122,    60,    39,    62,    94,   109,    87,    68,
      88,    34,    63,    70,    77,    82,     5,    62,   120,     6,
     103,    62,    62,    62,    59,    41,    54,    96,    62,   111,
      90,    91,    93,    69,    62,   124,    30,    31,    64,    25,
      26,    27,    29,    71,    21,    22,    78,    23,    24,    83,
     117,   118,   131,    34,    34,    61,    20,    56,    60,    38,
     112,    34,    33,    94,    34,    59,    65,    66,    73,    72,
      75,    74,    79,    80,    84,    85,    34,    41,    17,   128,
      40,    35,    41,   113,   110,    92,    62,    62,    69,    69,
      69,    69,    76,    76,    81,    81,    40,   119,    62,    15,
      46,    62,    40,    62,    97,   120,   132,    59,    55,   114,
      98,    34,   117,    34,   101,   113,    41,    99,   133,    36,
      62,    59,   100,    99
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
#line 85 "./src/parser.y"
    {
        declareMainFunction((yyvsp[(2) - (2)].sval), lineas, &functionDirectory);
        setProgramName((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 3:
#line 88 "./src/parser.y"
    {
        fillMain();
    ;}
    break;

  case 4:
#line 90 "./src/parser.y"
    {
        printf("Valid syntax.\n");
        generateObject();
    ;}
    break;

  case 5:
#line 96 "./src/parser.y"
    {
        (yyval.ivar) = (yyvsp[(4) - (4)].ivar) + 1;
    ;}
    break;

  case 6:
#line 99 "./src/parser.y"
    {
        (yyval.ivar) = 0;
    ;}
    break;

  case 7:
#line 104 "./src/parser.y"
    {
        (yyvsp[(4) - (4)].arrNode)->calculateRs();
        declareVariables((yyvsp[(1) - (4)].nodeID), (yyvsp[(3) - (4)].chType), (yyvsp[(4) - (4)].arrNode), lineas);
    ;}
    break;

  case 8:
#line 108 "./src/parser.y"
    {
        declareVariables((yyvsp[(1) - (3)].nodeID), (yyvsp[(3) - (3)].chType), nullptr, lineas);
    ;}
    break;

  case 9:
#line 113 "./src/parser.y"
    {
        ArrayNode *node = new ArrayNode((yyvsp[(1) - (1)].iarray));
        (yyval.arrNode) = node;
    ;}
    break;

  case 10:
#line 117 "./src/parser.y"
    {
        ArrayNode *node = new ArrayNode((yyvsp[(1) - (2)].iarray), (yyvsp[(2) - (2)].arrNode));
        (yyval.arrNode) = node;
    ;}
    break;

  case 11:
#line 123 "./src/parser.y"
    {
        (yyval.iarray) = (yyvsp[(2) - (3)].ival);
    ;}
    break;

  case 12:
#line 128 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (1)].sval));
        (yyval.nodeID) = node;
    ;}
    break;

  case 13:
#line 132 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].nodeID));
        (yyval.nodeID) = node;
    ;}
    break;

  case 16:
#line 142 "./src/parser.y"
    {
        declareFunction((yyvsp[(2) - (2)].sval), 7, lineas);
    ;}
    break;

  case 17:
#line 144 "./src/parser.y"
    {
        setCurrentParamCount((yyvsp[(5) - (7)].iparam));
    ;}
    break;

  case 18:
#line 146 "./src/parser.y"
    {
        setCurrentLocalVarCount((yyvsp[(11) - (11)].ivar));
        setCurrentCurrQuad();
        setCurrentFuncType((yyvsp[(9) - (11)].chType));
        setCurrentFunc((yyvsp[(2) - (11)].sval));
        createReturnAddress();
    ;}
    break;

  case 19:
#line 152 "./src/parser.y"
    {
        popReturnAddress();
        generateEndFunc();
        functionDirectory.removeVariableTable((yyvsp[(2) - (14)].sval));
    ;}
    break;

  case 20:
#line 159 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = (yyvsp[(1) - (1)].chType);
    ;}
    break;

  case 21:
#line 162 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = VOID_;
    ;}
    break;

  case 22:
#line 167 "./src/parser.y"
    {
        pushOperator(RETURN_);
    ;}
    break;

  case 23:
#line 169 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({RETURN_}));
        setFunctionReturn();
        verifyReturnType(getCurrentFuncType());
    ;}
    break;

  case 28:
#line 184 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), lineas, declareVariable((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), nullptr, lineas)->address);
        (yyval.iparam) = (yyvsp[(5) - (5)].iparam) + 1;
    ;}
    break;

  case 29:
#line 188 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), lineas, declareVariable((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), nullptr, lineas)->address);
        (yyval.iparam) = 1;
    ;}
    break;

  case 30:
#line 192 "./src/parser.y"
    {
        (yyval.iparam) = 0;
    ;}
    break;

  case 31:
#line 197 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({AND_, OR_}));
    ;}
    break;

  case 33:
#line 202 "./src/parser.y"
    {
        pushOperator(AND_);
    ;}
    break;

  case 35:
#line 205 "./src/parser.y"
    {
        pushOperator(OR_);
    ;}
    break;

  case 38:
#line 211 "./src/parser.y"
    {
        pushOperator(NOT_);
    ;}
    break;

  case 39:
#line 213 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({NOT_}));
    ;}
    break;

  case 41:
#line 219 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({GREATER_, LESS_, EQUALTO_, NOTEQUAL_}));
    ;}
    break;

  case 43:
#line 224 "./src/parser.y"
    {
        pushOperator(GREATER_);
    ;}
    break;

  case 45:
#line 227 "./src/parser.y"
    {
        pushOperator(LESS_);
    ;}
    break;

  case 47:
#line 230 "./src/parser.y"
    {
        pushOperator(EQUALTO_);
    ;}
    break;

  case 49:
#line 233 "./src/parser.y"
    {
        pushOperator(NOTEQUAL_);
    ;}
    break;

  case 52:
#line 239 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({ADD_, SUB_}));
    ;}
    break;

  case 54:
#line 244 "./src/parser.y"
    {
        pushOperator(ADD_);
    ;}
    break;

  case 56:
#line 247 "./src/parser.y"
    {
        pushOperator(SUB_);
    ;}
    break;

  case 59:
#line 253 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({MULTI_, DIV_}));
    ;}
    break;

  case 61:
#line 258 "./src/parser.y"
    {
        pushOperator(MULTI_);
    ;}
    break;

  case 63:
#line 261 "./src/parser.y"
    {
        pushOperator(DIV_);
    ;}
    break;

  case 66:
#line 267 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 68:
#line 270 "./src/parser.y"
    {
        pushOperator(LEFTPAR_);
    ;}
    break;

  case 69:
#line 272 "./src/parser.y"
    {
        pushOperator(RIGHTPAR_);
    ;}
    break;

  case 71:
#line 284 "./src/parser.y"
    {
        pushOperandOfType(declareCte(FLOAT_, (yyvsp[(1) - (1)].fval)), FLOAT_);
    ;}
    break;

  case 72:
#line 287 "./src/parser.y"
    {
        pushOperandOfType(declareCte(INT_, (yyvsp[(1) - (1)].ival)), INT_);
    ;}
    break;

  case 73:
#line 292 "./src/parser.y"
    {
        verifyFunctionExists(getIDExpression(), lineas);
        setCurrentCall(getIDExpression());
    ;}
    break;

  case 74:
#line 295 "./src/parser.y"
    {
        generateEra(getCurrentCall());
        resetParameterCount(getCurrentCall());
        pushOperator(FAKEBOT_);
    ;}
    break;

  case 75:
#line 299 "./src/parser.y"
    {
        verifyParameters(getCurrentCall());
        generateGosub(getCurrentCall());
        pushOperandResult(getCurrentCall());
        setCurrentCall("");
        popOperator(FAKEBOT_);
    ;}
    break;

  case 76:
#line 306 "./src/parser.y"
    {
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 77:
#line 309 "./src/parser.y"
    {
        popOperator(FAKEBOT_);
    ;}
    break;

  case 78:
#line 312 "./src/parser.y"
    {
        pushOperandByID(getIDExpression());
    ;}
    break;

  case 81:
#line 321 "./src/parser.y"
    {
        generateVerify();
    ;}
    break;

  case 82:
#line 323 "./src/parser.y"
    {
        generateAccess();
    ;}
    break;

  case 83:
#line 328 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 86:
#line 334 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 97:
#line 352 "./src/parser.y"
    {
        pushOperator(EQUALS_);
    ;}
    break;

  case 98:
#line 354 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({EQUALS_}));
    ;}
    break;

  case 99:
#line 359 "./src/parser.y"
    {
        pushOperandByID((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 100:
#line 362 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 101:
#line 366 "./src/parser.y"
    {
        popOperator(FAKEBOT_);
    ;}
    break;

  case 102:
#line 371 "./src/parser.y"
    {
        verifyFunctionExists((yyvsp[(1) - (1)].sval), lineas);
    ;}
    break;

  case 103:
#line 373 "./src/parser.y"
    {
        generateEra((yyvsp[(1) - (3)].sval));
        setCurrentCall((yyvsp[(1) - (3)].sval));
        resetParameterCount((yyvsp[(1) - (3)].sval));
    ;}
    break;

  case 104:
#line 377 "./src/parser.y"
    {
        verifyParameters((yyvsp[(1) - (6)].sval));
        generateGosub((yyvsp[(1) - (6)].sval));
        setCurrentCall("");
    ;}
    break;

  case 106:
#line 384 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 109:
#line 390 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 112:
#line 396 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 113:
#line 398 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
        generateNewline();
    ;}
    break;

  case 114:
#line 404 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
    ;}
    break;

  case 115:
#line 407 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 119:
#line 414 "./src/parser.y"
    {
        pushOperandOfType(declareCte(STRING_, (yyvsp[(1) - (1)].strval)), STRING_);
    ;}
    break;

  case 120:
#line 419 "./src/parser.y"
    {
        generateElse();
    ;}
    break;

  case 121:
#line 421 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 122:
#line 424 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 123:
#line 429 "./src/parser.y"
    {
        generateIf();
    ;}
    break;

  case 127:
#line 438 "./src/parser.y"
    {
        pushJumpCurrent();
    ;}
    break;

  case 128:
#line 440 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 129:
#line 442 "./src/parser.y"
    {
        fillJumpWhile();
    ;}
    break;

  case 130:
#line 447 "./src/parser.y"
    {
        // pushJumpCurrent();
    ;}
    break;

  case 131:
#line 449 "./src/parser.y"
    {
        pushLastAssignment();
        saveForVariable();
        pushJumpCurrent(-1);
    ;}
    break;

  case 132:
#line 453 "./src/parser.y"
    {
        validateLastAssignment(INT_);
        validateLastOperand(INT_);
        pushOperator(LESS_);
        doOperation();
    ;}
    break;

  case 133:
#line 458 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 134:
#line 460 "./src/parser.y"
    {
        fillJumpFor();
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2226 "./bin/parser.tab.c"
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


#line 464 "./src/parser.y"


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
