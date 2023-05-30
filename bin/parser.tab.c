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
    int chType; // 0 int, 1 float, 2 string, 3 void, 4 prog, 5 int arr, 6 float arr, 7 temp, -1 err
    int ivar;
    int iparam;
}
/* Line 193 of yacc.c.  */
#line 203 "./bin/parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 216 "./bin/parser.tab.c"

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
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  86
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNRULES -- Number of states.  */
#define YYNSTATES  204

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
       0,     0,     3,     4,     5,    14,    19,    20,    24,    31,
      33,    37,    40,    41,    42,    43,    44,    59,    61,    63,
      64,    71,    74,    78,    80,    82,    88,    92,    93,    94,
      98,    99,   103,   104,   108,   109,   110,   114,   115,   119,
     120,   124,   125,   129,   130,   134,   135,   136,   140,   141,
     145,   146,   150,   151,   152,   156,   157,   161,   162,   166,
     167,   168,   172,   173,   178,   180,   182,   184,   185,   186,
     192,   194,   197,   198,   199,   200,   206,   207,   211,   212,
     213,   218,   219,   222,   223,   226,   228,   230,   232,   234,
     236,   237,   242,   244,   245,   246,   247,   255,   256,   257,
     258,   267,   268,   272,   273,   274,   279,   280,   281,   288,
     290,   292,   293,   298,   300,   301,   308,   310,   312,   313,
     314,   323,   324,   325,   326,   327
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    -1,    -1,     7,     6,    43,    39,    45,
      48,    44,    56,    -1,     8,    46,    39,    45,    -1,    -1,
      47,    38,    57,    -1,    47,    38,    57,    36,     3,    37,
      -1,     6,    -1,     6,    40,    47,    -1,    49,    48,    -1,
      -1,    -1,    -1,    -1,    18,     6,    50,    32,    58,    33,
      38,    51,    53,    34,    45,    52,    95,    35,    -1,    57,
      -1,    20,    -1,    -1,    19,    55,    32,    59,    33,    39,
      -1,    19,    39,    -1,    34,    95,    35,    -1,     9,    -1,
      10,    -1,     6,    38,    57,    40,    58,    -1,     6,    38,
      57,    -1,    -1,    -1,    64,    60,    61,    -1,    -1,    30,
      62,    59,    -1,    -1,    31,    63,    59,    -1,    -1,    -1,
      71,    65,    66,    -1,    -1,    26,    67,    64,    -1,    -1,
      25,    68,    64,    -1,    -1,    29,    69,    64,    -1,    -1,
      27,    70,    64,    -1,    -1,    -1,    76,    72,    73,    -1,
      -1,    21,    74,    71,    -1,    -1,    22,    75,    71,    -1,
      -1,    -1,    81,    77,    78,    -1,    -1,    23,    79,    76,
      -1,    -1,    24,    80,    76,    -1,    -1,    -1,     6,    82,
      85,    -1,    -1,    32,    83,    59,    33,    -1,    84,    -1,
       4,    -1,     3,    -1,    -1,    -1,    86,    32,    87,    91,
      33,    -1,    88,    -1,    88,    88,    -1,    -1,    -1,    -1,
      36,    89,    59,    90,    37,    -1,    -1,    59,    92,    93,
      -1,    -1,    -1,    40,    59,    94,    93,    -1,    -1,    96,
      95,    -1,    -1,    97,    39,    -1,   103,    -1,   111,    -1,
     114,    -1,   118,    -1,    54,    -1,    -1,    99,    28,    98,
      59,    -1,     6,    -1,    -1,    -1,    -1,     6,   100,    36,
     101,    59,   102,    37,    -1,    -1,    -1,    -1,     6,   104,
      32,   105,   107,    33,   106,    39,    -1,    -1,    59,   108,
     109,    -1,    -1,    -1,    40,    59,   110,   109,    -1,    -1,
      -1,    13,   112,    32,   113,    33,    39,    -1,    59,    -1,
       5,    -1,    -1,   116,    12,   115,    56,    -1,   116,    -1,
      -1,    11,    32,    59,    33,   117,    56,    -1,   119,    -1,
     122,    -1,    -1,    -1,    16,   120,    32,    59,    33,   121,
      15,    56,    -1,    -1,    -1,    -1,    -1,    14,   123,    32,
      97,   124,    17,    59,   125,    33,   126,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    83,    80,    91,    94,    99,   102,   107,
     111,   117,   118,   121,   123,   125,   121,   138,   141,   146,
     146,   154,   157,   160,   161,   164,   168,   172,   177,   177,
     182,   182,   185,   185,   188,   191,   191,   196,   196,   199,
     199,   202,   202,   205,   205,   208,   211,   211,   216,   216,
     219,   219,   222,   225,   225,   230,   230,   233,   233,   236,
     239,   239,   242,   242,   253,   256,   259,   264,   267,   264,
     278,   279,   280,   285,   288,   285,   296,   296,   299,   302,
     302,   305,   308,   309,   312,   313,   314,   315,   316,   317,
     320,   320,   327,   330,   332,   335,   330,   343,   345,   349,
     343,   356,   356,   359,   362,   362,   365,   368,   368,   379,
     380,   385,   385,   390,   395,   395,   400,   401,   404,   406,
     404,   413,   415,   419,   424,   413
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
  "COMMA", "$accept", "program", "@1", "@2", "vars", "var", "var_list",
  "functions", "function", "@3", "@4", "@5", "function_type", "return",
  "@6", "block", "type", "params", "expression", "@7", "expression2", "@8",
  "@9", "comp", "@10", "comp2", "@11", "@12", "@13", "@14", "exp", "@15",
  "exp2", "@16", "@17", "term", "@18", "term2", "@19", "@20", "factor",
  "@21", "@22", "var_cte", "array_or_func", "@23", "@24", "array", "@25",
  "@26", "arguments", "@27", "arguments2", "@28", "statements",
  "statement", "assignment", "@29", "assignee", "@30", "@31", "@32",
  "call", "@33", "@34", "@35", "call2", "@36", "call3", "@37", "printing",
  "@38", "printing_3", "conditional", "@39", "conditional_if", "@40",
  "repetition", "rep_cond", "@41", "@42", "rep_no_cond", "@43", "@44",
  "@45", "@46", 0
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
       0,    41,    43,    44,    42,    45,    45,    46,    46,    47,
      47,    48,    48,    50,    51,    52,    49,    53,    53,    55,
      54,    54,    56,    57,    57,    58,    58,    58,    60,    59,
      62,    61,    63,    61,    61,    65,    64,    67,    66,    68,
      66,    69,    66,    70,    66,    66,    72,    71,    74,    73,
      75,    73,    73,    77,    76,    79,    78,    80,    78,    78,
      82,    81,    83,    81,    81,    84,    84,    86,    87,    85,
      85,    85,    85,    89,    90,    88,    92,    91,    91,    94,
      93,    93,    95,    95,    96,    96,    96,    96,    96,    96,
      98,    97,    99,   100,   101,   102,    99,   104,   105,   106,
     103,   108,   107,   107,   110,   109,   109,   112,   111,   113,
     113,   115,   114,   114,   117,   116,   118,   118,   120,   121,
     119,   123,   124,   125,   126,   122
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     4,     0,     3,     6,     1,
       3,     2,     0,     0,     0,     0,    14,     1,     1,     0,
       6,     2,     3,     1,     1,     5,     3,     0,     0,     3,
       0,     3,     0,     3,     0,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     0,     3,     0,     3,
       0,     3,     0,     0,     3,     0,     3,     0,     3,     0,
       0,     3,     0,     4,     1,     1,     1,     0,     0,     5,
       1,     2,     0,     0,     0,     5,     0,     3,     0,     0,
       4,     0,     2,     0,     2,     1,     1,     1,     1,     1,
       0,     4,     1,     0,     0,     0,     7,     0,     0,     0,
       8,     0,     3,     0,     0,     4,     0,     0,     6,     1,
       1,     0,     4,     1,     0,     6,     1,     1,     0,     0,
       8,     0,     0,     0,     0,    11
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     6,     0,    12,     9,
       0,     0,     0,     3,    12,     0,     6,     0,    13,     0,
      11,    10,     5,    23,    24,     7,     0,    83,     4,     0,
      27,    92,     0,   107,   121,   118,    19,    89,     0,    83,
       0,     0,    85,    86,    87,   113,    88,   116,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
      22,    82,    84,    90,   111,     8,     0,     0,    94,    98,
      66,    65,    60,    62,     0,    28,    35,    46,    53,    64,
       0,     0,     0,     0,     0,     0,    26,    14,     0,   103,
      72,     0,   114,    34,    45,    52,    59,   110,   109,     0,
      92,   122,     0,     0,    91,   112,    27,     0,    95,   101,
       0,    73,    61,     0,    70,     0,     0,    30,    32,    29,
      39,    37,    43,    41,    36,    48,    50,    47,    55,    57,
      54,     0,     0,   119,     0,    25,    18,     0,    17,     0,
     106,    99,     0,    68,    71,    63,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
      20,     6,    96,     0,   102,     0,    74,    78,    31,    33,
      40,    38,    44,    42,    49,    51,    56,    58,   123,     0,
      15,   104,   100,     0,    76,     0,     0,   120,    83,   106,
      75,    81,    69,   124,     0,   105,     0,    77,     0,    16,
      79,   125,    81,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    19,     8,    10,    11,    13,    14,    26,
     107,   188,   137,    37,    59,    28,    25,    51,    74,    93,
     119,   147,   148,    75,    94,   124,   150,   149,   152,   151,
      76,    95,   127,   153,   154,    77,    96,   130,   155,   156,
      78,    90,    91,    79,   112,   113,   167,   114,   142,   183,
     185,   191,   197,   202,    38,    39,    40,    84,    41,    52,
      88,   139,    42,    53,    89,   165,   110,   140,   164,   189,
      43,    55,    99,    44,    85,    45,   116,    46,    47,    57,
     159,    48,    56,   132,   186,   198
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int8 yypact[] =
{
       2,    32,    29,  -101,  -101,     7,    49,    54,    43,    25,
      24,    28,    56,  -101,    43,    54,    49,    27,  -101,    33,
    -101,  -101,  -101,  -101,  -101,    35,    36,    14,  -101,    69,
      67,   -24,    42,  -101,  -101,  -101,    37,  -101,    40,    14,
      38,    50,  -101,  -101,  -101,    70,  -101,  -101,  -101,    44,
      41,    51,    47,    55,    15,    58,    59,    60,  -101,    61,
    -101,  -101,  -101,  -101,  -101,  -101,    27,    48,  -101,  -101,
    -101,  -101,  -101,  -101,    62,  -101,  -101,  -101,  -101,  -101,
      11,    82,    15,    15,    15,    33,    63,  -101,    15,    15,
       3,    15,  -101,    10,    -3,    23,    30,  -101,  -101,    65,
      64,  -101,    66,    68,  -101,  -101,    67,    22,  -101,  -101,
      71,  -101,  -101,    73,    72,    74,    33,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,    57,    77,  -101,    75,  -101,  -101,    76,  -101,    78,
      79,  -101,    15,  -101,  -101,  -101,  -101,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,  -101,    15,    87,
    -101,    49,  -101,    15,  -101,    81,  -101,    15,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,    33,
    -101,  -101,  -101,    80,  -101,    88,    89,  -101,    14,    79,
    -101,    83,  -101,  -101,    90,  -101,    15,  -101,    33,  -101,
    -101,  -101,    83,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -101,  -101,  -101,  -101,   -15,  -101,    91,    95,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,   -82,   -59,     5,   -78,  -101,
    -101,  -101,  -101,  -100,  -101,  -101,  -101,  -101,  -101,  -101,
     -98,  -101,  -101,  -101,  -101,   -97,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,    -2,  -101,  -101,
    -101,  -101,   -89,  -101,   -39,  -101,    45,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,   -65,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -98
static const yytype_int16 yytable[] =
{
      61,    22,    98,   105,   102,   103,   104,    86,   -97,     1,
     108,   109,   -93,   115,    70,    71,    97,    72,    70,    71,
      31,    72,   120,   121,   122,    32,   123,    33,    34,     4,
      35,    23,    24,    36,   146,   -67,    23,    24,     3,   111,
     117,   118,   136,    73,   125,   126,     6,    73,   138,   170,
     171,   172,   173,   128,   129,   174,   175,     7,   176,   177,
       9,    12,    18,    16,   166,    15,    17,    27,    30,   168,
     169,    29,    49,    50,    54,    60,    58,    62,    63,    66,
     178,    65,    64,    68,    67,   181,    87,    69,   100,   184,
      80,    81,    82,    83,   158,    92,   157,   187,   131,   133,
     -93,   134,   179,   106,   141,   143,    21,   145,   111,    20,
     161,   135,   144,   203,   160,   162,   201,   190,   200,   163,
     182,   192,   193,   196,   195,   199,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,     0,     0,   194
};

static const yytype_int16 yycheck[] =
{
      39,    16,    80,    85,    82,    83,    84,    66,    32,     7,
      88,    89,    36,    91,     3,     4,     5,     6,     3,     4,
       6,     6,    25,    26,    27,    11,    29,    13,    14,     0,
      16,     9,    10,    19,   116,    32,     9,    10,     6,    36,
      30,    31,    20,    32,    21,    22,    39,    32,   107,   149,
     150,   151,   152,    23,    24,   153,   154,     8,   155,   156,
       6,    18,     6,    39,   142,    40,    38,    34,    32,   147,
     148,    36,     3,     6,    32,    35,    39,    39,    28,    38,
     158,    37,    12,    36,    33,   163,    38,    32,     6,   167,
      32,    32,    32,    32,    17,    33,    39,   179,    33,    33,
      36,    33,    15,    40,    33,    32,    15,    33,    36,    14,
      34,   106,   114,   202,    39,    37,   198,    37,   196,    40,
      39,    33,    33,    40,   189,    35,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,   188
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    42,     6,     0,    43,    39,     8,    45,     6,
      46,    47,    18,    48,    49,    40,    39,    38,     6,    44,
      48,    47,    45,     9,    10,    57,    50,    34,    56,    36,
      32,     6,    11,    13,    14,    16,    19,    54,    95,    96,
      97,    99,   103,   111,   114,   116,   118,   119,   122,     3,
       6,    58,   100,   104,    32,   112,   123,   120,    39,    55,
      35,    95,    39,    28,    12,    37,    38,    33,    36,    32,
       3,     4,     6,    32,    59,    64,    71,    76,    81,    84,
      32,    32,    32,    32,    98,   115,    57,    38,   101,   105,
      82,    83,    33,    60,    65,    72,    77,     5,    59,   113,
       6,    97,    59,    59,    59,    56,    40,    51,    59,    59,
     107,    36,    85,    86,    88,    59,   117,    30,    31,    61,
      25,    26,    27,    29,    66,    21,    22,    73,    23,    24,
      78,    33,   124,    33,    33,    58,    20,    53,    57,   102,
     108,    33,    89,    32,    88,    33,    56,    62,    63,    68,
      67,    70,    69,    74,    75,    79,    80,    39,    17,   121,
      39,    34,    37,    40,   109,   106,    59,    87,    59,    59,
      64,    64,    64,    64,    71,    71,    76,    76,    59,    15,
      45,    59,    39,    90,    59,    91,   125,    56,    52,   110,
      37,    92,    33,    33,    95,   109,    40,    93,   126,    35,
      59,    56,    94,    93
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
#line 80 "./src/parser.y"
    {
        declareMainFunction((yyvsp[(2) - (2)].sval), lineas, &functionDirectory);
        setProgramName((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 3:
#line 83 "./src/parser.y"
    {
        fillMain();
    ;}
    break;

  case 4:
#line 85 "./src/parser.y"
    {
        printf("Valid syntax.\n");
        generateObject();
    ;}
    break;

  case 5:
#line 91 "./src/parser.y"
    {
        (yyval.ivar) = (yyvsp[(4) - (4)].ivar) + 1;
    ;}
    break;

  case 6:
#line 94 "./src/parser.y"
    {
        (yyval.ivar) = 0;
    ;}
    break;

  case 7:
#line 99 "./src/parser.y"
    {
        declareVariables((yyvsp[(1) - (3)].nodeID), (yyvsp[(3) - (3)].chType), lineas);
    ;}
    break;

  case 8:
#line 102 "./src/parser.y"
    {
        declareArrays((yyvsp[(1) - (6)].nodeID), (yyvsp[(3) - (6)].chType), (yyvsp[(5) - (6)].ival), lineas);
    ;}
    break;

  case 9:
#line 107 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (1)].sval));
        (yyval.nodeID) = node;
    ;}
    break;

  case 10:
#line 111 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].nodeID));
        (yyval.nodeID) = node;
    ;}
    break;

  case 13:
#line 121 "./src/parser.y"
    {
        declareFunction((yyvsp[(2) - (2)].sval), 7, lineas);
    ;}
    break;

  case 14:
#line 123 "./src/parser.y"
    {
        setCurrentParamCount((yyvsp[(5) - (7)].iparam));
    ;}
    break;

  case 15:
#line 125 "./src/parser.y"
    {
        setCurrentLocalVarCount((yyvsp[(11) - (11)].ivar));
        setCurrentCurrQuad();
        setCurrentFuncType((yyvsp[(9) - (11)].chType));
        setCurrentFunc((yyvsp[(2) - (11)].sval));
        createReturnAddress();
    ;}
    break;

  case 16:
#line 131 "./src/parser.y"
    {
        popReturnAddress();
        generateEndFunc();
        functionDirectory.removeVariableTable((yyvsp[(2) - (14)].sval));
    ;}
    break;

  case 17:
#line 138 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = (yyvsp[(1) - (1)].chType);
    ;}
    break;

  case 18:
#line 141 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = VOID_;
    ;}
    break;

  case 19:
#line 146 "./src/parser.y"
    {
        cout << "return in return push " << endl;
        pushOperator(RETURN_);
    ;}
    break;

  case 20:
#line 149 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({RETURN_}));
        setFunctionReturn();
        verifyReturnType(getCurrentFuncType());
    ;}
    break;

  case 25:
#line 164 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), lineas, declareVariable((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), 1, lineas)->address);
        (yyval.iparam) = (yyvsp[(5) - (5)].iparam) + 1;
    ;}
    break;

  case 26:
#line 168 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), lineas, declareVariable((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), 1, lineas)->address);
        (yyval.iparam) = 1;
    ;}
    break;

  case 27:
#line 172 "./src/parser.y"
    {
        (yyval.iparam) = 0;
    ;}
    break;

  case 28:
#line 177 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({AND_, OR_}));
    ;}
    break;

  case 30:
#line 182 "./src/parser.y"
    {
        pushOperator(AND_);
    ;}
    break;

  case 32:
#line 185 "./src/parser.y"
    {
        pushOperator(OR_);
    ;}
    break;

  case 35:
#line 191 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({GREATER_, LESS_, EQUALTO_, NOTEQUAL_}));
    ;}
    break;

  case 37:
#line 196 "./src/parser.y"
    {
        pushOperator(GREATER_);
    ;}
    break;

  case 39:
#line 199 "./src/parser.y"
    {
        pushOperator(LESS_);
    ;}
    break;

  case 41:
#line 202 "./src/parser.y"
    {
        pushOperator(EQUALTO_);
    ;}
    break;

  case 43:
#line 205 "./src/parser.y"
    {
        pushOperator(NOTEQUAL_);
    ;}
    break;

  case 46:
#line 211 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({ADD_, SUB_}));
    ;}
    break;

  case 48:
#line 216 "./src/parser.y"
    {
        pushOperator(ADD_);
    ;}
    break;

  case 50:
#line 219 "./src/parser.y"
    {
        pushOperator(SUB_);
    ;}
    break;

  case 53:
#line 225 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({MULTI_, DIV_}));
    ;}
    break;

  case 55:
#line 230 "./src/parser.y"
    {
        pushOperator(MULTI_);
    ;}
    break;

  case 57:
#line 233 "./src/parser.y"
    {
        pushOperator(DIV_);
    ;}
    break;

  case 60:
#line 239 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 62:
#line 242 "./src/parser.y"
    {
        pushOperator(LEFTPAR_);
    ;}
    break;

  case 63:
#line 244 "./src/parser.y"
    {
        pushOperator(RIGHTPAR_);
    ;}
    break;

  case 65:
#line 256 "./src/parser.y"
    {
        pushOperandOfType(declareCte(FLOAT_, (yyvsp[(1) - (1)].fval)), FLOAT_);
    ;}
    break;

  case 66:
#line 259 "./src/parser.y"
    {
        pushOperandOfType(declareCte(INT_, (yyvsp[(1) - (1)].ival)), INT_);
    ;}
    break;

  case 67:
#line 264 "./src/parser.y"
    {
        verifyFunctionExists(getIDExpression(), lineas);
        setCurrentCall(getIDExpression());
    ;}
    break;

  case 68:
#line 267 "./src/parser.y"
    {
        generateEra(getCurrentCall());
        resetParameterCount(getCurrentCall());
        pushOperator(FAKEBOT_);
    ;}
    break;

  case 69:
#line 271 "./src/parser.y"
    {
        verifyParameters(getCurrentCall());
        generateGosub(getCurrentCall());
        pushOperandResult(getCurrentCall());
        setCurrentCall("");
        popOperator(FAKEBOT_);
    ;}
    break;

  case 72:
#line 280 "./src/parser.y"
    {
        pushOperandByID(getIDExpression());
    ;}
    break;

  case 73:
#line 285 "./src/parser.y"
    {
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 74:
#line 288 "./src/parser.y"
    {
        generateVerify();
    ;}
    break;

  case 75:
#line 290 "./src/parser.y"
    {
        generateAccess();
        popOperator(FAKEBOT_);
    ;}
    break;

  case 76:
#line 296 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 79:
#line 302 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 90:
#line 320 "./src/parser.y"
    {
        pushOperator(EQUALS_);
    ;}
    break;

  case 91:
#line 322 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({EQUALS_}));
    ;}
    break;

  case 92:
#line 327 "./src/parser.y"
    {
        pushOperandByID((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 93:
#line 330 "./src/parser.y"
    {
        // pushOperandByID($1);
    ;}
    break;

  case 94:
#line 332 "./src/parser.y"
    {
        pushOperator(FAKEBOT_);
        verifyIsArray((yyvsp[(1) - (3)].sval));
    ;}
    break;

  case 95:
#line 335 "./src/parser.y"
    {
        generateVerify();
    ;}
    break;

  case 96:
#line 337 "./src/parser.y"
    {
        generateAccess();
        popOperator(FAKEBOT_);
    ;}
    break;

  case 97:
#line 343 "./src/parser.y"
    {
        verifyFunctionExists((yyvsp[(1) - (1)].sval), lineas);
    ;}
    break;

  case 98:
#line 345 "./src/parser.y"
    {
        generateEra((yyvsp[(1) - (3)].sval));
        setCurrentCall((yyvsp[(1) - (3)].sval));
        resetParameterCount((yyvsp[(1) - (3)].sval));
    ;}
    break;

  case 99:
#line 349 "./src/parser.y"
    {
        verifyParameters((yyvsp[(1) - (6)].sval));
        generateGosub((yyvsp[(1) - (6)].sval));
        setCurrentCall("");
    ;}
    break;

  case 101:
#line 356 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 104:
#line 362 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 107:
#line 368 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 108:
#line 370 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
    ;}
    break;

  case 110:
#line 380 "./src/parser.y"
    {
        pushOperandOfType(declareCte(STRING_, (yyvsp[(1) - (1)].strval)), STRING_);
    ;}
    break;

  case 111:
#line 385 "./src/parser.y"
    {
        generateElse();
    ;}
    break;

  case 112:
#line 387 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 113:
#line 390 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 114:
#line 395 "./src/parser.y"
    {
        generateIf();
    ;}
    break;

  case 118:
#line 404 "./src/parser.y"
    {
        pushJumpCurrent();
    ;}
    break;

  case 119:
#line 406 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 120:
#line 408 "./src/parser.y"
    {
        fillJumpWhile();
    ;}
    break;

  case 121:
#line 413 "./src/parser.y"
    {
        // pushJumpCurrent();
    ;}
    break;

  case 122:
#line 415 "./src/parser.y"
    {
        pushLastAssignment();
        saveForVariable();
        pushJumpCurrent(-1);
    ;}
    break;

  case 123:
#line 419 "./src/parser.y"
    {
        validateLastAssignment(INT_);
        validateLastOperand(INT_);
        pushOperator(LESS_);
        doOperation();
    ;}
    break;

  case 124:
#line 424 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 125:
#line 426 "./src/parser.y"
    {
        fillJumpFor();
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2164 "./bin/parser.tab.c"
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


#line 430 "./src/parser.y"


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
