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
     HFLIP = 310,
     VFLIP = 311,
     CROP = 312
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
#define VFLIP 311
#define CROP 312




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
#line 242 "./bin/parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 255 "./bin/parser.tab.c"

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
#define YYLAST   187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNRULES -- Number of states.  */
#define YYNSTATES  248

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

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
      55,    56,    57
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
     281,   283,   285,   287,   289,   291,   293,   295,   303,   310,
     312,   316,   317,   322,   324,   325,   329,   330,   331,   332,
     341,   342,   346,   347,   348,   353,   354,   355,   363,   364,
     365,   371,   372,   374,   376,   377,   382,   384,   385,   392,
     394,   396,   397,   398,   407,   408,   409,   410,   411
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      59,     0,    -1,    -1,    -1,     8,     7,    60,    47,    62,
      67,    61,    75,    -1,     9,    63,    47,    62,    -1,    -1,
      66,    46,    76,    64,    -1,    66,    46,    76,    -1,    65,
      -1,    65,    64,    -1,    44,     3,    45,    -1,     7,    -1,
       7,    48,    66,    -1,    68,    67,    -1,    -1,    -1,    -1,
      -1,    22,     7,    69,    40,    77,    41,    46,    70,    72,
      42,    62,    71,   121,    43,    -1,    76,    -1,    24,    -1,
      -1,    23,    74,    40,    78,    41,    47,    -1,    23,    47,
      -1,    42,   121,    43,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,     7,    46,    76,    48,    77,    -1,     7,
      46,    76,    -1,    -1,    -1,    83,    79,    80,    -1,    -1,
      37,    81,    78,    -1,    -1,    38,    82,    78,    -1,    -1,
      -1,    39,    84,    85,    -1,    85,    -1,    -1,    94,    86,
      87,    -1,    -1,    31,    88,    85,    -1,    -1,    30,    89,
      85,    -1,    -1,    36,    90,    85,    -1,    -1,    32,    91,
      85,    -1,    -1,    33,    92,    85,    -1,    -1,    34,    93,
      85,    -1,    -1,    -1,    99,    95,    96,    -1,    -1,    25,
      97,    94,    -1,    -1,    26,    98,    94,    -1,    -1,    -1,
     101,   106,   100,   102,    -1,    26,    -1,    -1,    -1,    27,
     103,    99,    -1,    -1,    28,   104,    99,    -1,    -1,    29,
     105,    99,    -1,    -1,    -1,     7,   107,   110,    -1,    -1,
      40,   108,    78,    41,    -1,   109,    -1,     4,    -1,     3,
      -1,     5,    -1,    -1,    -1,   111,    40,   112,   117,    41,
      -1,    -1,   113,   114,    -1,    -1,   115,   114,    -1,   115,
      -1,    -1,    44,    78,   116,    45,    -1,    -1,    78,   118,
     119,    -1,    -1,    -1,    48,    78,   120,   119,    -1,    -1,
     122,   121,    -1,    -1,   126,    47,    -1,   124,    -1,   130,
      -1,   138,    -1,   144,    -1,   148,    -1,    73,    -1,    51,
      -1,    52,    -1,    50,    -1,    53,    -1,    54,    -1,    55,
      -1,    56,    -1,    57,    -1,     7,    49,   123,    40,   125,
      41,    47,    -1,     7,    49,   123,    40,    41,    47,    -1,
     143,    -1,   143,    48,   125,    -1,    -1,   128,    35,   127,
      78,    -1,     7,    -1,    -1,     7,   129,   114,    -1,    -1,
      -1,    -1,     7,   131,    40,   132,   134,    41,   133,    47,
      -1,    -1,    78,   135,   136,    -1,    -1,    -1,    48,    78,
     137,   136,    -1,    -1,    -1,    16,   139,    40,   143,   140,
      41,    47,    -1,    -1,    -1,   141,    48,   142,   143,   140,
      -1,    -1,    78,    -1,     6,    -1,    -1,   146,    15,   145,
      75,    -1,   146,    -1,    -1,    14,    40,    78,    41,   147,
      75,    -1,   149,    -1,   152,    -1,    -1,    -1,    20,   150,
      40,    78,    41,   151,    19,    75,    -1,    -1,    -1,    -1,
      -1,    18,   153,    40,   126,   154,    21,    78,   155,    41,
     156,    75,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   110,   107,   118,   121,   126,   130,   135,
     139,   145,   150,   154,   160,   161,   164,   166,   168,   164,
     181,   184,   189,   189,   196,   199,   202,   203,   204,   205,
     208,   212,   216,   221,   221,   226,   226,   229,   229,   232,
     235,   235,   240,   243,   243,   248,   248,   251,   251,   254,
     254,   257,   257,   260,   260,   263,   263,   266,   269,   269,
     274,   274,   277,   277,   280,   283,   283,   289,   293,   299,
     299,   302,   302,   305,   305,   308,   311,   311,   314,   314,
     319,   322,   325,   328,   333,   336,   333,   347,   347,   353,
     358,   359,   362,   362,   369,   369,   373,   376,   376,   379,
     382,   383,   386,   387,   388,   389,   390,   391,   392,   395,
     398,   401,   404,   407,   410,   413,   416,   421,   424,   429,
     434,   441,   441,   448,   451,   451,   460,   462,   466,   460,
     473,   473,   476,   479,   479,   482,   485,   485,   493,   496,
     493,   499,   507,   508,   513,   513,   518,   523,   523,   528,
     529,   532,   534,   532,   541,   543,   547,   552,   541
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
  "HFLIP", "VFLIP", "CROP", "$accept", "program", "@1", "@2", "vars",
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
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    60,    61,    59,    62,    62,    63,    63,    64,
      64,    65,    66,    66,    67,    67,    69,    70,    71,    68,
      72,    72,    74,    73,    73,    75,    76,    76,    76,    76,
      77,    77,    77,    79,    78,    81,    80,    82,    80,    80,
      84,    83,    83,    86,    85,    88,    87,    89,    87,    90,
      87,    91,    87,    92,    87,    93,    87,    87,    95,    94,
      97,    96,    98,    96,    96,   100,    99,   101,   101,   103,
     102,   104,   102,   105,   102,   102,   107,   106,   108,   106,
     106,   109,   109,   109,   111,   112,   110,   113,   110,   110,
     114,   114,   116,   115,   118,   117,   117,   120,   119,   119,
     121,   121,   122,   122,   122,   122,   122,   122,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   125,
     125,   127,   126,   128,   129,   128,   131,   132,   133,   130,
     135,   134,   134,   137,   136,   136,   139,   138,   141,   142,
     140,   140,   143,   143,   145,   144,   144,   147,   146,   148,
     148,   150,   151,   149,   153,   154,   155,   156,   152
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
       1,     1,     1,     1,     1,     1,     1,     7,     6,     1,
       3,     0,     4,     1,     0,     3,     0,     0,     0,     8,
       0,     3,     0,     0,     4,     0,     0,     7,     0,     0,
       5,     0,     1,     1,     0,     4,     1,     0,     6,     1,
       1,     0,     0,     8,     0,     0,     0,     0,    11
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     6,     0,    15,    12,
       0,     0,     0,     3,    15,     0,     6,     0,    16,     0,
      14,    13,     5,    26,    27,    28,    29,     8,     0,   101,
       4,     0,     7,     9,    32,   123,     0,   136,   154,   151,
      22,   108,     0,   101,   103,     0,     0,   104,   105,   106,
     146,   107,   149,   150,     0,    10,     0,     0,     0,     0,
       0,    68,     0,     0,     0,    24,     0,    25,   100,   102,
     121,   144,    11,     0,     0,   111,   109,   110,   112,   113,
     114,   115,   116,     0,    68,   125,    91,   127,    67,    40,
       0,    33,    42,    43,    58,     0,    68,     0,    68,    68,
      68,     0,    31,    17,    68,    92,    90,    68,    68,   147,
      39,    57,    64,    82,    81,    83,    76,    78,    65,    80,
     143,   142,   138,   123,   155,     0,     0,   122,   145,    32,
       0,     0,     0,   119,     0,   130,     0,    41,     0,    35,
      37,    34,    47,    45,    51,    53,    55,    49,    44,    60,
      62,    59,    89,    68,    75,     0,     0,     0,   152,     0,
      30,    21,     0,    20,   118,     0,    68,    93,   135,   128,
     148,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    77,     0,     0,     0,    69,    71,    73,    66,     0,
     139,    68,     0,    23,     6,   117,   120,    68,   131,     0,
      36,    38,    48,    46,    52,    54,    56,    50,    61,    63,
      85,    88,    79,    68,    68,    68,   137,    68,   156,     0,
      18,   133,   129,    68,    70,    72,    74,   138,     0,   153,
     101,   135,    94,     0,   140,   157,     0,   134,    99,    86,
       0,    19,    68,    95,   158,    97,    99,    98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    19,     8,    10,    32,    33,    11,    13,
      14,    28,   130,   230,   162,    41,    66,    30,    27,    57,
     121,   110,   141,   171,   172,    91,   108,    92,   111,   148,
     174,   173,   178,   175,   176,   177,    93,   112,   151,   179,
     180,    94,   154,    95,   188,   213,   214,   215,   118,   152,
     153,   119,   181,   182,   223,   183,    85,    86,   134,   233,
     238,   243,   246,    42,    43,    83,    44,   132,    45,   100,
      46,    59,    47,    60,   107,   199,   136,   168,   198,   231,
      48,    62,   155,   156,   217,   133,    49,   101,    50,   138,
      51,    52,    64,   192,    53,    63,   157,   228,   240
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -147
static const yytype_int16 yypact[] =
{
       3,    13,    14,  -147,  -147,   -24,    46,    43,    60,    44,
      49,    52,    90,  -147,    60,    43,    46,    74,  -147,    57,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,    56,    61,    11,
    -147,   100,  -147,    56,    97,   -23,    66,  -147,  -147,  -147,
      58,  -147,    64,    11,  -147,    62,    73,  -147,  -147,  -147,
      95,  -147,  -147,  -147,    68,  -147,    69,    75,     6,    70,
      77,    -7,    78,    79,    80,  -147,    81,  -147,  -147,  -147,
    -147,  -147,  -147,    74,    82,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,    83,    -7,  -147,    70,  -147,  -147,  -147,
      84,  -147,  -147,  -147,  -147,     5,    10,   119,    -7,    -7,
      -7,    57,    85,  -147,     7,  -147,  -147,   -11,   101,  -147,
      51,    47,    65,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,    88,    86,  -147,    91,    93,  -147,  -147,    97,
      41,    89,    94,    92,    96,  -147,    98,  -147,    57,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,    26,    -7,    15,   103,    99,   117,  -147,   102,
    -147,  -147,   104,  -147,  -147,   105,    10,  -147,   106,  -147,
    -147,    -7,    -7,   101,   101,   101,   101,   101,   101,   101,
     101,  -147,   108,    70,   109,  -147,  -147,  -147,  -147,   110,
    -147,    -7,   123,  -147,    46,  -147,  -147,    -7,  -147,   111,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,   101,   101,   101,  -147,    10,  -147,    57,
    -147,  -147,  -147,    -4,  -147,  -147,  -147,    88,   112,  -147,
      11,   106,  -147,   114,  -147,  -147,   113,  -147,   116,  -147,
      57,  -147,    -7,  -147,  -147,  -147,   116,  -147
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,  -147,   -14,  -147,   118,  -147,   130,   145,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,   -97,   -66,    31,
     -60,  -147,  -147,  -147,  -147,  -147,  -147,  -102,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,   -85,  -147,  -147,  -147,
    -147,  -146,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,   -81,  -147,  -147,  -147,
    -147,   -84,  -147,   -43,  -147,  -147,  -147,    -5,    71,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,   -65,  -147,
    -147,  -147,   -62,  -147,  -147,   -93,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -142
static const yytype_int16 yytable[] =
{
      68,    90,    22,   122,   128,   106,   137,   102,   113,   114,
     115,     1,   116,   120,     4,    88,   120,  -126,    35,    88,
       3,  -124,    88,     6,   105,    36,    58,    37,    89,    38,
    -132,    39,    89,    88,    40,    89,    88,   -96,   125,   126,
     127,   170,   185,   186,   187,   117,    89,   135,   131,    89,
       9,    23,    24,    25,    26,     7,    75,    76,    77,    78,
      79,    80,    81,    82,   163,   161,   -84,   224,   225,   226,
     -87,   202,   203,   204,   205,   206,   207,   142,   143,   144,
     145,   146,    12,   147,    23,    24,    25,    26,   139,   140,
     149,   150,    15,   184,   208,   209,    16,    18,    17,    29,
      31,    34,   211,    54,    56,    65,    61,    67,    70,    69,
      71,   200,   201,    72,    84,    73,    74,    87,    96,    97,
      98,    99,   229,   104,   227,   109,   123,    88,   103,  -141,
    -124,   218,   158,   129,   159,   165,   164,   221,   191,   169,
     166,   167,   219,   244,   189,    21,   194,   190,   210,   193,
     212,    55,   195,   235,   197,   239,   241,   216,   222,    20,
     160,   196,   247,   232,   242,   234,   237,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,     0,   245,     0,     0,     0,     0,   236
};

static const yytype_int16 yycheck[] =
{
      43,    61,    16,    96,   101,    86,   108,    73,     3,     4,
       5,     8,     7,     6,     0,    26,     6,    40,     7,    26,
       7,    44,    26,    47,    84,    14,    49,    16,    39,    18,
      41,    20,    39,    26,    23,    39,    26,    41,    98,    99,
     100,   138,    27,    28,    29,    40,    39,   107,    41,    39,
       7,    10,    11,    12,    13,     9,    50,    51,    52,    53,
      54,    55,    56,    57,   130,    24,    40,   213,   214,   215,
      44,   173,   174,   175,   176,   177,   178,    30,    31,    32,
      33,    34,    22,    36,    10,    11,    12,    13,    37,    38,
      25,    26,    48,   153,   179,   180,    47,     7,    46,    42,
      44,    40,   183,     3,     7,    47,    40,    43,    35,    47,
      15,   171,   172,    45,    44,    46,    41,    40,    40,    40,
      40,    40,   219,    40,   217,    41,     7,    26,    46,    41,
      44,   191,    41,    48,    41,    41,    47,   197,    21,    41,
      48,    45,    19,   240,    41,    15,    42,    48,    40,    47,
      41,    33,    47,    41,    48,    41,    43,    47,    47,    14,
     129,   166,   246,   223,    48,   227,   231,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   242,    -1,    -1,    -1,    -1,   230
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    59,     7,     0,    60,    47,     9,    62,     7,
      63,    66,    22,    67,    68,    48,    47,    46,     7,    61,
      67,    66,    62,    10,    11,    12,    13,    76,    69,    42,
      75,    44,    64,    65,    40,     7,    14,    16,    18,    20,
      23,    73,   121,   122,   124,   126,   128,   130,   138,   144,
     146,   148,   149,   152,     3,    64,     7,    77,    49,   129,
     131,    40,   139,   153,   150,    47,    74,    43,   121,    47,
      35,    15,    45,    46,    41,    50,    51,    52,    53,    54,
      55,    56,    57,   123,    44,   114,   115,    40,    26,    39,
      78,    83,    85,    94,    99,   101,    40,    40,    40,    40,
     127,   145,    76,    46,    40,    78,   114,   132,    84,    41,
      79,    86,    95,     3,     4,     5,     7,    40,   106,   109,
       6,    78,   143,     7,   126,    78,    78,    78,    75,    48,
      70,    41,   125,   143,   116,    78,   134,    85,   147,    37,
      38,    80,    30,    31,    32,    33,    34,    36,    87,    25,
      26,    96,   107,   108,   100,   140,   141,   154,    41,    41,
      77,    24,    72,    76,    47,    41,    48,    45,   135,    41,
      75,    81,    82,    89,    88,    91,    92,    93,    90,    97,
      98,   110,   111,   113,    78,    27,    28,    29,   102,    41,
      48,    21,   151,    47,    42,    47,   125,    48,   136,   133,
      78,    78,    85,    85,    85,    85,    85,    85,    94,    94,
      40,   114,    41,   103,   104,   105,    47,   142,    78,    19,
      62,    78,    47,   112,    99,    99,    99,   143,   155,    75,
      71,   137,    78,   117,   140,    41,   121,   136,   118,    41,
     156,    43,    48,   119,    75,    78,   120,   119
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
#line 107 "./src/parser.y"
    {
        declareMainFunction((yyvsp[(2) - (2)].sval), lineas, &functionDirectory);
        setProgramName((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 3:
#line 110 "./src/parser.y"
    {
        fillMain();
    ;}
    break;

  case 4:
#line 112 "./src/parser.y"
    {
        printf("Valid syntax.\n");
        generateObject();
    ;}
    break;

  case 5:
#line 118 "./src/parser.y"
    {
        (yyval.ivar) = (yyvsp[(4) - (4)].ivar) + 1;
    ;}
    break;

  case 6:
#line 121 "./src/parser.y"
    {
        (yyval.ivar) = 0;
    ;}
    break;

  case 7:
#line 126 "./src/parser.y"
    {
        (yyvsp[(4) - (4)].arrNode)->calculateRs();
        declareVariables((yyvsp[(1) - (4)].nodeID), (yyvsp[(3) - (4)].chType), (yyvsp[(4) - (4)].arrNode), lineas);
    ;}
    break;

  case 8:
#line 130 "./src/parser.y"
    {
        declareVariables((yyvsp[(1) - (3)].nodeID), (yyvsp[(3) - (3)].chType), nullptr, lineas);
    ;}
    break;

  case 9:
#line 135 "./src/parser.y"
    {
        ArrayNode *node = new ArrayNode((yyvsp[(1) - (1)].iarray));
        (yyval.arrNode) = node;
    ;}
    break;

  case 10:
#line 139 "./src/parser.y"
    {
        ArrayNode *node = new ArrayNode((yyvsp[(1) - (2)].iarray), (yyvsp[(2) - (2)].arrNode));
        (yyval.arrNode) = node;
    ;}
    break;

  case 11:
#line 145 "./src/parser.y"
    {
        (yyval.iarray) = (yyvsp[(2) - (3)].ival);
    ;}
    break;

  case 12:
#line 150 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (1)].sval));
        (yyval.nodeID) = node;
    ;}
    break;

  case 13:
#line 154 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].nodeID));
        (yyval.nodeID) = node;
    ;}
    break;

  case 16:
#line 164 "./src/parser.y"
    {
        declareFunction((yyvsp[(2) - (2)].sval), 7, lineas);
    ;}
    break;

  case 17:
#line 166 "./src/parser.y"
    {
        setCurrentParamCount((yyvsp[(5) - (7)].iparam));
    ;}
    break;

  case 18:
#line 168 "./src/parser.y"
    {
        setCurrentLocalVarCount((yyvsp[(11) - (11)].ivar));
        setCurrentCurrQuad();
        setCurrentFuncType((yyvsp[(9) - (11)].chType));
        setCurrentFunc((yyvsp[(2) - (11)].sval));
        createReturnAddress();
    ;}
    break;

  case 19:
#line 174 "./src/parser.y"
    {
        popReturnAddress();
        generateEndFunc();
        functionDirectory.removeVariableTable((yyvsp[(2) - (14)].sval));
    ;}
    break;

  case 20:
#line 181 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = (yyvsp[(1) - (1)].chType);
    ;}
    break;

  case 21:
#line 184 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = VOID_;
    ;}
    break;

  case 22:
#line 189 "./src/parser.y"
    {
        pushOperator(RETURN_);
    ;}
    break;

  case 23:
#line 191 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({RETURN_}));
        setFunctionReturn();
        verifyReturnType(getCurrentFuncType());
    ;}
    break;

  case 30:
#line 208 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), lineas, declareVariable((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), nullptr, lineas)->address);
        (yyval.iparam) = (yyvsp[(5) - (5)].iparam) + 1;
    ;}
    break;

  case 31:
#line 212 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), lineas, declareVariable((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), nullptr, lineas)->address);
        (yyval.iparam) = 1;
    ;}
    break;

  case 32:
#line 216 "./src/parser.y"
    {
        (yyval.iparam) = 0;
    ;}
    break;

  case 33:
#line 221 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({AND_, OR_}));
    ;}
    break;

  case 35:
#line 226 "./src/parser.y"
    {
        pushOperator(AND_);
    ;}
    break;

  case 37:
#line 229 "./src/parser.y"
    {
        pushOperator(OR_);
    ;}
    break;

  case 40:
#line 235 "./src/parser.y"
    {
        pushOperator(NOT_);
    ;}
    break;

  case 41:
#line 237 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({NOT_}));
    ;}
    break;

  case 43:
#line 243 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({GREATER_, LESS_, EQUALTO_, NOTEQUAL_, GREATEREQ_, LESSEQ_}));
    ;}
    break;

  case 45:
#line 248 "./src/parser.y"
    {
        pushOperator(GREATER_);
    ;}
    break;

  case 47:
#line 251 "./src/parser.y"
    {
        pushOperator(LESS_);
    ;}
    break;

  case 49:
#line 254 "./src/parser.y"
    {
        pushOperator(EQUALTO_);
    ;}
    break;

  case 51:
#line 257 "./src/parser.y"
    {
        pushOperator(NOTEQUAL_);
    ;}
    break;

  case 53:
#line 260 "./src/parser.y"
    {
        pushOperator(GREATEREQ_);
    ;}
    break;

  case 55:
#line 263 "./src/parser.y"
    {
        pushOperator(LESSEQ_);
    ;}
    break;

  case 58:
#line 269 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({ADD_, SUB_}));
    ;}
    break;

  case 60:
#line 274 "./src/parser.y"
    {
        pushOperator(ADD_);
    ;}
    break;

  case 62:
#line 277 "./src/parser.y"
    {
        pushOperator(SUB_);
    ;}
    break;

  case 65:
#line 283 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({MULTI_}));
        checkIfShouldDoOperation(vector<int>({MULTI_, DIV_, MOD_}));
    ;}
    break;

  case 67:
#line 289 "./src/parser.y"
    {
        pushOperator(MULTI_);
        pushOperandOfType(declareCte(INT_, -1), INT_);
    ;}
    break;

  case 68:
#line 293 "./src/parser.y"
    {
        pushOperator(MULTI_);
        pushOperandOfType(declareCte(INT_, 1), INT_);
    ;}
    break;

  case 69:
#line 299 "./src/parser.y"
    {
        pushOperator(MULTI_);
    ;}
    break;

  case 71:
#line 302 "./src/parser.y"
    {
        pushOperator(DIV_);
    ;}
    break;

  case 73:
#line 305 "./src/parser.y"
    {
        pushOperator(MOD_);
    ;}
    break;

  case 76:
#line 311 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 78:
#line 314 "./src/parser.y"
    {
        pushOperator(LEFTPAR_);
    ;}
    break;

  case 79:
#line 316 "./src/parser.y"
    {
        pushOperator(RIGHTPAR_);
    ;}
    break;

  case 81:
#line 322 "./src/parser.y"
    {
        pushOperandOfType(declareCte(FLOAT_, (yyvsp[(1) - (1)].fval)), FLOAT_);
    ;}
    break;

  case 82:
#line 325 "./src/parser.y"
    {
        pushOperandOfType(declareCte(INT_, (yyvsp[(1) - (1)].ival)), INT_);
    ;}
    break;

  case 83:
#line 328 "./src/parser.y"
    {
        pushOperandOfType(declareCte(BOOL_, (yyvsp[(1) - (1)].bval)), BOOL_);
    ;}
    break;

  case 84:
#line 333 "./src/parser.y"
    {
        verifyFunctionExists(getIDExpression(), lineas);
        setCurrentCall(getIDExpression());
    ;}
    break;

  case 85:
#line 336 "./src/parser.y"
    {
        generateEra(getCurrentCall());
        resetParameterCount(getCurrentCall());
        pushOperator(FAKEBOT_);
    ;}
    break;

  case 86:
#line 340 "./src/parser.y"
    {
        verifyParameters(getCurrentCall());
        generateGosub(getCurrentCall());
        pushOperandResult(getCurrentCall());
        setCurrentCall("");
        popOperator(FAKEBOT_);
    ;}
    break;

  case 87:
#line 347 "./src/parser.y"
    {
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 88:
#line 350 "./src/parser.y"
    {
        popOperator(FAKEBOT_);
    ;}
    break;

  case 89:
#line 353 "./src/parser.y"
    {
        pushOperandByID(getIDExpression());
    ;}
    break;

  case 92:
#line 362 "./src/parser.y"
    {
        generateVerify();
    ;}
    break;

  case 93:
#line 364 "./src/parser.y"
    {
        generateAccess();
    ;}
    break;

  case 94:
#line 369 "./src/parser.y"
    {
        cout << "gen param" << endl;
        generateParam();
    ;}
    break;

  case 97:
#line 376 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 109:
#line 395 "./src/parser.y"
    {
        (yyval.imgFunc) = GRAYSCALE_;
    ;}
    break;

  case 110:
#line 398 "./src/parser.y"
    {
        (yyval.imgFunc) = SAVE_;
    ;}
    break;

  case 111:
#line 401 "./src/parser.y"
    {
        (yyval.imgFunc) = OPEN_;
    ;}
    break;

  case 112:
#line 404 "./src/parser.y"
    {
        (yyval.imgFunc) = BANDW_;
    ;}
    break;

  case 113:
#line 407 "./src/parser.y"
    {
        (yyval.imgFunc) = CHANGECOLOR_;
    ;}
    break;

  case 114:
#line 410 "./src/parser.y"
    {
        (yyval.imgFunc) = HFLIP_;
    ;}
    break;

  case 115:
#line 413 "./src/parser.y"
    {
        (yyval.imgFunc) = VFLIP_;
    ;}
    break;

  case 116:
#line 416 "./src/parser.y"
    {
        (yyval.imgFunc) = CROP_;
    ;}
    break;

  case 117:
#line 421 "./src/parser.y"
    {
        performImageCall((yyvsp[(1) - (7)].sval), (yyvsp[(3) - (7)].imgFunc), (yyvsp[(5) - (7)].paramNode));
    ;}
    break;

  case 118:
#line 424 "./src/parser.y"
    {
        performImageCall((yyvsp[(1) - (6)].sval), (yyvsp[(3) - (6)].imgFunc), nullptr);
    ;}
    break;

  case 119:
#line 429 "./src/parser.y"
    {
        int type = topOperandType();
        ParamNode *node = new ParamNode(popOperand(), type);
        (yyval.paramNode) = node;
    ;}
    break;

  case 120:
#line 434 "./src/parser.y"
    {
        int type = topOperandType();
        ParamNode *node = new ParamNode(popOperand(), type, (yyvsp[(3) - (3)].paramNode));
        (yyval.paramNode) = node;
    ;}
    break;

  case 121:
#line 441 "./src/parser.y"
    {
        pushOperator(EQUALS_);
    ;}
    break;

  case 122:
#line 443 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({EQUALS_}));
    ;}
    break;

  case 123:
#line 448 "./src/parser.y"
    {
        pushOperandByID((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 124:
#line 451 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 125:
#line 455 "./src/parser.y"
    {
        popOperator(FAKEBOT_);
    ;}
    break;

  case 126:
#line 460 "./src/parser.y"
    {
        verifyFunctionExists((yyvsp[(1) - (1)].sval), lineas);
    ;}
    break;

  case 127:
#line 462 "./src/parser.y"
    {
        generateEra((yyvsp[(1) - (3)].sval));
        setCurrentCall((yyvsp[(1) - (3)].sval));
        resetParameterCount((yyvsp[(1) - (3)].sval));
    ;}
    break;

  case 128:
#line 466 "./src/parser.y"
    {
        verifyParameters((yyvsp[(1) - (6)].sval));
        generateGosub((yyvsp[(1) - (6)].sval));
        setCurrentCall("");
    ;}
    break;

  case 130:
#line 473 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 133:
#line 479 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 136:
#line 485 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 137:
#line 487 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
        generateNewline();
    ;}
    break;

  case 138:
#line 493 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
    ;}
    break;

  case 139:
#line 496 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 143:
#line 508 "./src/parser.y"
    {
        pushOperandOfType(declareCte(STRING_, (yyvsp[(1) - (1)].strval)), STRING_);
    ;}
    break;

  case 144:
#line 513 "./src/parser.y"
    {
        generateElse();
    ;}
    break;

  case 145:
#line 515 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 146:
#line 518 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 147:
#line 523 "./src/parser.y"
    {
        generateIf();
    ;}
    break;

  case 151:
#line 532 "./src/parser.y"
    {
        pushJumpCurrent();
    ;}
    break;

  case 152:
#line 534 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 153:
#line 536 "./src/parser.y"
    {
        fillJumpWhile();
    ;}
    break;

  case 154:
#line 541 "./src/parser.y"
    {
        // pushJumpCurrent();
    ;}
    break;

  case 155:
#line 543 "./src/parser.y"
    {
        pushLastAssignment();
        saveForVariable();
        pushJumpCurrent(-1);
    ;}
    break;

  case 156:
#line 547 "./src/parser.y"
    {
        validateLastAssignment(INT_);
        validateLastOperand(INT_);
        pushOperator(LESS_);
        doOperation();
    ;}
    break;

  case 157:
#line 552 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 158:
#line 554 "./src/parser.y"
    {
        fillJumpFor();
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2432 "./bin/parser.tab.c"
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


#line 558 "./src/parser.y"


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
