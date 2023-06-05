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
#line 248 "./bin/parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 261 "./bin/parser.tab.c"

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
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  102
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNRULES -- Number of states.  */
#define YYNSTATES  262

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    14,    19,    20,    25,    29,
      31,    34,    38,    40,    44,    47,    48,    49,    50,    51,
      66,    68,    70,    71,    78,    79,    83,    87,    89,    91,
      93,    95,    97,   103,   107,   108,   109,   113,   114,   118,
     119,   123,   124,   125,   129,   131,   132,   136,   137,   141,
     142,   146,   147,   151,   152,   156,   157,   161,   162,   166,
     167,   168,   172,   173,   177,   178,   182,   183,   184,   189,
     191,   192,   193,   197,   198,   202,   203,   207,   208,   209,
     213,   214,   219,   221,   223,   225,   227,   229,   231,   232,
     233,   239,   240,   243,   244,   247,   249,   250,   255,   256,
     260,   261,   262,   267,   268,   271,   272,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   293,   295,   297,   299,
     301,   303,   311,   318,   320,   324,   325,   330,   332,   333,
     337,   338,   339,   340,   349,   350,   354,   355,   356,   361,
     362,   363,   371,   372,   373,   379,   380,   383,   386,   389,
     390,   396,   399,   400,   405,   407,   408,   415,   417,   419,
     420,   421,   430,   431,   432,   433,   434
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      62,     0,    -1,    -1,    -1,     8,     7,    63,    50,    65,
      70,    64,    79,    -1,     9,    66,    50,    65,    -1,    -1,
      69,    49,    80,    67,    -1,    69,    49,    80,    -1,    68,
      -1,    68,    67,    -1,    47,     3,    48,    -1,     7,    -1,
       7,    51,    69,    -1,    71,    70,    -1,    -1,    -1,    -1,
      -1,    25,     7,    72,    43,    81,    44,    49,    73,    75,
      45,    65,    74,   125,    46,    -1,    80,    -1,    27,    -1,
      -1,    26,    77,    43,    82,    44,    50,    -1,    -1,    26,
      78,    50,    -1,    45,   125,    46,    -1,    10,    -1,    11,
      -1,    12,    -1,    13,    -1,    14,    -1,     7,    49,    80,
      51,    81,    -1,     7,    49,    80,    -1,    -1,    -1,    87,
      83,    84,    -1,    -1,    40,    85,    82,    -1,    -1,    41,
      86,    82,    -1,    -1,    -1,    42,    88,    89,    -1,    89,
      -1,    -1,    98,    90,    91,    -1,    -1,    34,    92,    89,
      -1,    -1,    33,    93,    89,    -1,    -1,    39,    94,    89,
      -1,    -1,    35,    95,    89,    -1,    -1,    36,    96,    89,
      -1,    -1,    37,    97,    89,    -1,    -1,    -1,   103,    99,
     100,    -1,    -1,    28,   101,    98,    -1,    -1,    29,   102,
      98,    -1,    -1,    -1,   105,   110,   104,   106,    -1,    29,
      -1,    -1,    -1,    30,   107,   103,    -1,    -1,    31,   108,
     103,    -1,    -1,    32,   109,   103,    -1,    -1,    -1,     7,
     111,   114,    -1,    -1,    43,   112,    82,    44,    -1,   113,
      -1,   147,    -1,     4,    -1,     3,    -1,     5,    -1,     6,
      -1,    -1,    -1,   115,    43,   116,   121,    44,    -1,    -1,
     117,   118,    -1,    -1,   119,   118,    -1,   119,    -1,    -1,
      47,    82,   120,    48,    -1,    -1,    82,   122,   123,    -1,
      -1,    -1,    51,    82,   124,   123,    -1,    -1,   126,   125,
      -1,    -1,   130,    50,    -1,   128,    -1,   134,    -1,   142,
      -1,   150,    -1,   154,    -1,    76,    -1,    54,    -1,    55,
      -1,    53,    -1,    56,    -1,    57,    -1,    58,    -1,    59,
      -1,    60,    -1,     7,    52,   127,    43,   129,    44,    50,
      -1,     7,    52,   127,    43,    44,    50,    -1,    82,    -1,
      82,    51,   129,    -1,    -1,   132,    38,   131,    82,    -1,
       7,    -1,    -1,     7,   133,   118,    -1,    -1,    -1,    -1,
       7,   135,    43,   136,   138,    44,   137,    50,    -1,    -1,
      82,   139,   140,    -1,    -1,    -1,    51,    82,   141,   140,
      -1,    -1,    -1,    17,   143,    43,    82,   144,    44,    50,
      -1,    -1,    -1,   145,    51,   146,    82,   144,    -1,    -1,
      18,   148,    -1,    19,   148,    -1,    20,   148,    -1,    -1,
      43,   149,    82,   144,    44,    -1,    43,    44,    -1,    -1,
     152,    16,   151,    79,    -1,   152,    -1,    -1,    15,    43,
      82,    44,   153,    79,    -1,   155,    -1,   158,    -1,    -1,
      -1,    23,   156,    43,    82,    44,   157,    22,    79,    -1,
      -1,    -1,    -1,    -1,    21,   159,    43,   130,   160,    24,
      82,   161,    44,   162,    79,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   110,   110,   113,   110,   121,   124,   129,   133,   138,
     142,   148,   153,   157,   163,   164,   167,   169,   171,   167,
     184,   187,   192,   192,   199,   199,   205,   208,   209,   210,
     211,   212,   215,   219,   223,   228,   228,   233,   233,   236,
     236,   239,   242,   242,   247,   250,   250,   255,   255,   258,
     258,   261,   261,   264,   264,   267,   267,   270,   270,   273,
     276,   276,   281,   281,   284,   284,   287,   290,   290,   298,
     303,   308,   308,   311,   311,   314,   314,   317,   320,   320,
     323,   323,   328,   329,   332,   335,   338,   341,   346,   349,
     346,   360,   360,   366,   371,   372,   375,   375,   382,   382,
     385,   388,   388,   391,   394,   395,   398,   399,   400,   401,
     402,   403,   404,   407,   410,   413,   416,   419,   422,   425,
     428,   433,   437,   443,   448,   455,   455,   462,   465,   465,
     474,   476,   480,   474,   487,   487,   490,   493,   493,   496,
     499,   499,   507,   510,   507,   513,   516,   519,   522,   527,
     527,   532,   535,   535,   540,   545,   545,   550,   551,   554,
     556,   554,   563,   565,   569,   574,   563
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CTE_INT", "CTE_FLOAT", "CTE_BOOL",
  "CTE_STRING", "ID", "PROGRAM", "VAR", "INT", "FLOAT", "BOOL", "STRING",
  "IMAGE", "IF", "ELSE", "PRINT", "INPUT", "FINPUT", "SINPUT", "FOR", "DO",
  "WHILE", "TO", "FUNCTION", "RETURN", "VOID", "ADDITION", "SUBSTRACTION",
  "MULTI", "DIV", "MOD", "LESS_THAN", "MORE_THAN", "NOT_EQUAL",
  "GREATEREQ", "LESSEQ", "EQUAL", "EQUAL_TO", "AND", "OR", "NOT",
  "LEFT_PAR", "RIGHT_PAR", "LEFT_CURLY", "RIGHT_CURLY", "LEFT_BRACK",
  "RIGHT_BRACK", "COLON", "SEMICOLON", "COMMA", "ARROW", "OPEN",
  "GRAYSCALE", "SAVE", "BANDW", "CHANGE_COLOR", "HFLIP", "VFLIP", "CROP",
  "$accept", "program", "@1", "@2", "vars", "var", "array_list",
  "array_declaration", "var_list", "functions", "function", "@3", "@4",
  "@5", "function_type", "return", "@6", "@7", "block", "type", "params",
  "expression", "@8", "expression2", "@9", "@10", "not_expression", "@11",
  "comp", "@12", "comp2", "@13", "@14", "@15", "@16", "@17", "@18", "exp",
  "@19", "exp2", "@20", "@21", "term", "@22", "negation", "term2", "@23",
  "@24", "@25", "factor", "@26", "@27", "var_cte", "array_or_func", "@28",
  "@29", "@30", "arrays", "array", "@31", "arguments", "@32", "arguments2",
  "@33", "statements", "statement", "image_function", "image_call",
  "image_arguments", "assignment", "@34", "assignee", "@35", "call", "@36",
  "@37", "@38", "call2", "@39", "call3", "@40", "printing", "@41",
  "printing_2", "@42", "@43", "inputting", "input_message", "@44",
  "conditional", "@45", "conditional_if", "@46", "repetition", "rep_cond",
  "@47", "@48", "rep_no_cond", "@49", "@50", "@51", "@52", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    63,    64,    62,    65,    65,    66,    66,    67,
      67,    68,    69,    69,    70,    70,    72,    73,    74,    71,
      75,    75,    77,    76,    78,    76,    79,    80,    80,    80,
      80,    80,    81,    81,    81,    83,    82,    85,    84,    86,
      84,    84,    88,    87,    87,    90,    89,    92,    91,    93,
      91,    94,    91,    95,    91,    96,    91,    97,    91,    91,
      99,    98,   101,   100,   102,   100,   100,   104,   103,   105,
     105,   107,   106,   108,   106,   109,   106,   106,   111,   110,
     112,   110,   110,   110,   113,   113,   113,   113,   115,   116,
     114,   117,   114,   114,   118,   118,   120,   119,   122,   121,
     121,   124,   123,   123,   125,   125,   126,   126,   126,   126,
     126,   126,   126,   127,   127,   127,   127,   127,   127,   127,
     127,   128,   128,   129,   129,   131,   130,   132,   133,   132,
     135,   136,   137,   134,   139,   138,   138,   141,   140,   140,
     143,   142,   145,   146,   144,   144,   147,   147,   147,   149,
     148,   148,   151,   150,   150,   153,   152,   154,   154,   156,
     157,   155,   159,   160,   161,   162,   158
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     4,     0,     4,     3,     1,
       2,     3,     1,     3,     2,     0,     0,     0,     0,    14,
       1,     1,     0,     6,     0,     3,     3,     1,     1,     1,
       1,     1,     5,     3,     0,     0,     3,     0,     3,     0,
       3,     0,     0,     3,     1,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       0,     3,     0,     3,     0,     3,     0,     0,     4,     1,
       0,     0,     3,     0,     3,     0,     3,     0,     0,     3,
       0,     4,     1,     1,     1,     1,     1,     1,     0,     0,
       5,     0,     2,     0,     2,     1,     0,     4,     0,     3,
       0,     0,     4,     0,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     6,     1,     3,     0,     4,     1,     0,     3,
       0,     0,     0,     8,     0,     3,     0,     0,     4,     0,
       0,     7,     0,     0,     5,     0,     2,     2,     2,     0,
       5,     2,     0,     4,     1,     0,     6,     1,     1,     0,
       0,     8,     0,     0,     0,     0,    11
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     6,     0,    15,    12,
       0,     0,     0,     3,    15,     0,     6,     0,    16,     0,
      14,    13,     5,    27,    28,    29,    30,    31,     8,     0,
     105,     4,     0,     7,     9,    34,   127,     0,   140,   162,
     159,    22,   112,     0,   105,   107,     0,     0,   108,   109,
     110,   154,   111,   157,   158,     0,    10,     0,     0,     0,
       0,     0,    70,     0,     0,     0,     0,     0,    26,   104,
     106,   125,   152,    11,     0,     0,   115,   113,   114,   116,
     117,   118,   119,   120,     0,    70,   129,    95,   131,    69,
      42,     0,    35,    44,    45,    60,     0,    70,     0,    70,
      70,    25,    70,     0,    33,    17,    70,    96,    94,    70,
      70,   155,    41,    59,    66,    85,    84,    86,    87,    78,
       0,     0,     0,    80,    67,    82,    83,   142,   127,   163,
       0,     0,   126,   153,    34,     0,     0,   123,     0,     0,
     134,     0,    43,     0,    37,    39,    36,    49,    47,    53,
      55,    57,    51,    46,    62,    64,    61,    93,   149,   146,
     147,   148,    70,    77,     0,     0,     0,   160,     0,    32,
      21,     0,    20,   122,    70,     0,    97,   139,   132,   156,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      79,     0,     0,   151,    70,     0,    71,    73,    75,    68,
       0,   143,    70,     0,    23,     6,   124,   121,    70,   135,
       0,    38,    40,    50,    48,    54,    56,    58,    52,    63,
      65,    89,    92,   142,    81,    70,    70,    70,   141,    70,
     164,     0,    18,   137,   133,    70,     0,    72,    74,    76,
     142,     0,   161,   105,   139,    98,     0,   150,   144,   165,
       0,   138,   103,    90,     0,    19,    70,    99,   166,   101,
     103,   102
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    19,     8,    10,    33,    34,    11,    13,
      14,    29,   135,   243,   171,    42,    66,    67,    31,    28,
      58,   137,   112,   146,   180,   181,    92,   110,    93,   113,
     153,   183,   182,   187,   184,   185,   186,    94,   114,   156,
     188,   189,    95,   163,    96,   199,   225,   226,   227,   124,
     157,   162,   125,   190,   191,   235,   192,    86,    87,   139,
     246,   252,   257,   260,    43,    44,    84,    45,   138,    46,
     102,    47,    60,    48,    61,   109,   210,   141,   177,   209,
     244,    49,    63,   164,   165,   229,   126,   159,   194,    50,
     103,    51,   143,    52,    53,    65,   203,    54,    64,   166,
     241,   254
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -196
static const yytype_int16 yypact[] =
{
      25,    16,    44,  -196,  -196,     4,    47,    69,    63,    49,
      53,    55,    95,  -196,    63,    69,    47,    52,  -196,    61,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,    58,    64,
      14,  -196,   105,  -196,    58,   103,     6,    68,  -196,  -196,
    -196,    62,  -196,    67,    14,  -196,    65,    76,  -196,  -196,
    -196,   100,  -196,  -196,  -196,    70,  -196,    72,    73,    15,
      75,    80,    18,    81,    82,    83,    84,    78,  -196,  -196,
    -196,  -196,  -196,  -196,    52,    85,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,    86,    18,  -196,    75,  -196,  -196,
    -196,    88,  -196,  -196,  -196,  -196,     7,    18,   123,    18,
      18,  -196,    18,    61,    87,  -196,   -22,  -196,  -196,    13,
     106,  -196,   -32,    50,    23,  -196,  -196,  -196,  -196,  -196,
      93,    93,    93,  -196,  -196,  -196,  -196,    96,    90,  -196,
      98,    99,  -196,  -196,   103,     5,    89,    94,   102,   101,
    -196,   104,  -196,    61,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,   -13,   107,  -196,
    -196,  -196,    18,    60,   108,   109,   120,  -196,   111,  -196,
    -196,   110,  -196,  -196,    18,   112,  -196,   113,  -196,  -196,
      18,    18,   106,   106,   106,   106,   106,   106,   106,   106,
    -196,   114,    75,  -196,    18,   115,  -196,  -196,  -196,  -196,
     116,  -196,    18,   128,  -196,    47,  -196,  -196,    18,  -196,
     117,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,    96,  -196,   106,   106,   106,  -196,    18,
    -196,    61,  -196,  -196,  -196,    17,   119,  -196,  -196,  -196,
      96,   121,  -196,    14,   113,  -196,   125,  -196,  -196,  -196,
     124,  -196,   122,  -196,    61,  -196,    18,  -196,  -196,  -196,
     122,  -196
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -196,  -196,   -14,  -196,   137,  -196,   138,   142,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -100,   -68,
      24,   -61,  -196,  -196,  -196,  -196,  -196,  -196,  -105,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,   -92,  -196,  -196,
    -196,  -196,  -132,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,   -83,  -196,  -196,
    -196,  -196,   -88,  -196,   -44,  -196,  -196,  -196,     1,    79,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   -66,
    -196,  -196,  -196,  -195,  -196,  -196,  -196,   -23,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -146
static const yytype_int16 yytable[] =
{
      69,    91,    22,   133,   108,   142,   104,    89,   144,   145,
     115,   116,   117,   118,   119,    23,    24,    25,    26,    27,
      90,    36,   136,     3,   107,   120,   121,   122,   236,    37,
     -88,    38,   170,     1,   -91,    39,   127,    40,   130,   131,
      41,   132,    89,   179,     4,   248,    89,    89,   140,  -130,
     123,   154,   155,  -128,     6,    90,     7,  -136,    59,    90,
      90,  -100,    23,    24,    25,    26,    27,   172,    76,    77,
      78,    79,    80,    81,    82,    83,     9,   213,   214,   215,
     216,   217,   218,   147,   148,   149,   150,   151,    12,   152,
     196,   197,   198,   237,   238,   239,   219,   220,   160,   161,
      15,   195,    18,    16,    17,    32,    30,    35,    55,   222,
      57,    62,   -24,    68,    71,    70,    72,    75,    73,   211,
     212,    74,    85,    88,    97,    98,    99,   100,   101,   106,
     128,   242,   111,   223,   105,    89,   158,  -128,   134,   173,
    -145,   230,   167,   168,   202,   174,   175,   233,   178,   176,
     231,   193,   200,    21,   258,   205,    20,   221,   169,   224,
     201,   204,   207,   247,   208,   249,   228,   234,   240,   253,
     255,    56,   261,   256,   245,   206,     0,   129,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,     0,     0,     0,   259,     0,     0,     0,   250
};

static const yytype_int16 yycheck[] =
{
      44,    62,    16,   103,    87,   110,    74,    29,    40,    41,
       3,     4,     5,     6,     7,    10,    11,    12,    13,    14,
      42,     7,    44,     7,    85,    18,    19,    20,   223,    15,
      43,    17,    27,     8,    47,    21,    97,    23,    99,   100,
      26,   102,    29,   143,     0,   240,    29,    29,   109,    43,
      43,    28,    29,    47,    50,    42,     9,    44,    52,    42,
      42,    44,    10,    11,    12,    13,    14,   135,    53,    54,
      55,    56,    57,    58,    59,    60,     7,   182,   183,   184,
     185,   186,   187,    33,    34,    35,    36,    37,    25,    39,
      30,    31,    32,   225,   226,   227,   188,   189,   121,   122,
      51,   162,     7,    50,    49,    47,    45,    43,     3,   192,
       7,    43,    50,    46,    38,    50,    16,    44,    48,   180,
     181,    49,    47,    43,    43,    43,    43,    43,    50,    43,
       7,   231,    44,   194,    49,    29,    43,    47,    51,    50,
      44,   202,    44,    44,    24,    51,    44,   208,    44,    48,
      22,    44,    44,    15,   254,    45,    14,    43,   134,    44,
      51,    50,    50,    44,    51,    44,    50,    50,   229,    44,
      46,    34,   260,    51,   235,   174,    -1,    98,   244,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,   256,    -1,    -1,    -1,   243
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    62,     7,     0,    63,    50,     9,    65,     7,
      66,    69,    25,    70,    71,    51,    50,    49,     7,    64,
      70,    69,    65,    10,    11,    12,    13,    14,    80,    72,
      45,    79,    47,    67,    68,    43,     7,    15,    17,    21,
      23,    26,    76,   125,   126,   128,   130,   132,   134,   142,
     150,   152,   154,   155,   158,     3,    67,     7,    81,    52,
     133,   135,    43,   143,   159,   156,    77,    78,    46,   125,
      50,    38,    16,    48,    49,    44,    53,    54,    55,    56,
      57,    58,    59,    60,   127,    47,   118,   119,    43,    29,
      42,    82,    87,    89,    98,   103,   105,    43,    43,    43,
      43,    50,   131,   151,    80,    49,    43,    82,   118,   136,
      88,    44,    83,    90,    99,     3,     4,     5,     6,     7,
      18,    19,    20,    43,   110,   113,   147,    82,     7,   130,
      82,    82,    82,    79,    51,    73,    44,    82,   129,   120,
      82,   138,    89,   153,    40,    41,    84,    33,    34,    35,
      36,    37,    39,    91,    28,    29,   100,   111,    43,   148,
     148,   148,   112,   104,   144,   145,   160,    44,    44,    81,
      27,    75,    80,    50,    51,    44,    48,   139,    44,    79,
      85,    86,    93,    92,    95,    96,    97,    94,   101,   102,
     114,   115,   117,    44,   149,    82,    30,    31,    32,   106,
      44,    51,    24,   157,    50,    45,   129,    50,    51,   140,
     137,    82,    82,    89,    89,    89,    89,    89,    89,    98,
      98,    43,   118,    82,    44,   107,   108,   109,    50,   146,
      82,    22,    65,    82,    50,   116,   144,   103,   103,   103,
      82,   161,    79,    74,   141,    82,   121,    44,   144,    44,
     125,   140,   122,    44,   162,    46,    51,   123,    79,    82,
     124,   123
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
#line 110 "./src/parser.y"
    {
        declareMainFunction((yyvsp[(2) - (2)].sval), lineas, &functionDirectory);
        setProgramName((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 3:
#line 113 "./src/parser.y"
    {
        fillMain();
    ;}
    break;

  case 4:
#line 115 "./src/parser.y"
    {
        printf("Valid syntax.\n");
        generateObject();
    ;}
    break;

  case 5:
#line 121 "./src/parser.y"
    {
        (yyval.ivar) = (yyvsp[(4) - (4)].ivar) + 1;
    ;}
    break;

  case 6:
#line 124 "./src/parser.y"
    {
        (yyval.ivar) = 0;
    ;}
    break;

  case 7:
#line 129 "./src/parser.y"
    {
        (yyvsp[(4) - (4)].arrNode)->calculateRs();
        declareVariables((yyvsp[(1) - (4)].nodeID), (yyvsp[(3) - (4)].chType), (yyvsp[(4) - (4)].arrNode), lineas);
    ;}
    break;

  case 8:
#line 133 "./src/parser.y"
    {
        declareVariables((yyvsp[(1) - (3)].nodeID), (yyvsp[(3) - (3)].chType), nullptr, lineas);
    ;}
    break;

  case 9:
#line 138 "./src/parser.y"
    {
        ArrayNode *node = new ArrayNode((yyvsp[(1) - (1)].iarray));
        (yyval.arrNode) = node;
    ;}
    break;

  case 10:
#line 142 "./src/parser.y"
    {
        ArrayNode *node = new ArrayNode((yyvsp[(1) - (2)].iarray), (yyvsp[(2) - (2)].arrNode));
        (yyval.arrNode) = node;
    ;}
    break;

  case 11:
#line 148 "./src/parser.y"
    {
        (yyval.iarray) = (yyvsp[(2) - (3)].ival);
    ;}
    break;

  case 12:
#line 153 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (1)].sval));
        (yyval.nodeID) = node;
    ;}
    break;

  case 13:
#line 157 "./src/parser.y"
    {
        IDNode *node = new IDNode((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].nodeID));
        (yyval.nodeID) = node;
    ;}
    break;

  case 16:
#line 167 "./src/parser.y"
    {
        declareFunction((yyvsp[(2) - (2)].sval), 7, lineas);
    ;}
    break;

  case 17:
#line 169 "./src/parser.y"
    {
        setCurrentParamCount((yyvsp[(5) - (7)].iparam));
    ;}
    break;

  case 18:
#line 171 "./src/parser.y"
    {
        setCurrentLocalVarCount((yyvsp[(11) - (11)].ivar));
        setCurrentCurrQuad();
        setCurrentFuncType((yyvsp[(9) - (11)].chType));
        setCurrentFunc((yyvsp[(2) - (11)].sval));
        createReturnAddress();
    ;}
    break;

  case 19:
#line 177 "./src/parser.y"
    {
        popReturnAddress();
        generateEndFunc();
        functionDirectory.removeVariableTable((yyvsp[(2) - (14)].sval));
    ;}
    break;

  case 20:
#line 184 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = (yyvsp[(1) - (1)].chType);
    ;}
    break;

  case 21:
#line 187 "./src/parser.y"
    {
        functionDirectory.currentFunction()->type = VOID_;
    ;}
    break;

  case 22:
#line 192 "./src/parser.y"
    {
        pushOperator(RETURN_);
    ;}
    break;

  case 23:
#line 194 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({RETURN_}));
        setFunctionReturn();
        verifyReturnType(getCurrentFuncType());
    ;}
    break;

  case 24:
#line 199 "./src/parser.y"
    {
        generateVoidReturn();
        verifyReturnType(getCurrentFuncType(), VOID_);
    ;}
    break;

  case 32:
#line 215 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), lineas, declareVariable((yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].chType), nullptr, lineas)->address);
        (yyval.iparam) = (yyvsp[(5) - (5)].iparam) + 1;
    ;}
    break;

  case 33:
#line 219 "./src/parser.y"
    {
        declareParameter((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), lineas, declareVariable((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].chType), nullptr, lineas)->address);
        (yyval.iparam) = 1;
    ;}
    break;

  case 34:
#line 223 "./src/parser.y"
    {
        (yyval.iparam) = 0;
    ;}
    break;

  case 35:
#line 228 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({AND_, OR_}));
    ;}
    break;

  case 37:
#line 233 "./src/parser.y"
    {
        pushOperator(AND_);
    ;}
    break;

  case 39:
#line 236 "./src/parser.y"
    {
        pushOperator(OR_);
    ;}
    break;

  case 42:
#line 242 "./src/parser.y"
    {
        pushOperator(NOT_);
    ;}
    break;

  case 43:
#line 244 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({NOT_}));
    ;}
    break;

  case 45:
#line 250 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({GREATER_, LESS_, EQUALTO_, NOTEQUAL_, GREATEREQ_, LESSEQ_}));
    ;}
    break;

  case 47:
#line 255 "./src/parser.y"
    {
        pushOperator(GREATER_);
    ;}
    break;

  case 49:
#line 258 "./src/parser.y"
    {
        pushOperator(LESS_);
    ;}
    break;

  case 51:
#line 261 "./src/parser.y"
    {
        pushOperator(EQUALTO_);
    ;}
    break;

  case 53:
#line 264 "./src/parser.y"
    {
        pushOperator(NOTEQUAL_);
    ;}
    break;

  case 55:
#line 267 "./src/parser.y"
    {
        pushOperator(GREATEREQ_);
    ;}
    break;

  case 57:
#line 270 "./src/parser.y"
    {
        pushOperator(LESSEQ_);
    ;}
    break;

  case 60:
#line 276 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({ADD_, SUB_}));
    ;}
    break;

  case 62:
#line 281 "./src/parser.y"
    {
        pushOperator(ADD_);
    ;}
    break;

  case 64:
#line 284 "./src/parser.y"
    {
        pushOperator(SUB_);
    ;}
    break;

  case 67:
#line 290 "./src/parser.y"
    {
        if (getCurrentFactorWasNegated()) {
            checkIfShouldDoOperation(vector<int>({MULTI_}));
        }
        checkIfShouldDoOperation(vector<int>({MULTI_, DIV_, MOD_}));
    ;}
    break;

  case 69:
#line 298 "./src/parser.y"
    {
        setCurrentFactorWasNegated(true);
        pushOperator(MULTI_);
        pushOperandOfType(declareCte(INT_, -1), INT_);
    ;}
    break;

  case 70:
#line 303 "./src/parser.y"
    {
        setCurrentFactorWasNegated(false);
    ;}
    break;

  case 71:
#line 308 "./src/parser.y"
    {
        pushOperator(MULTI_);
    ;}
    break;

  case 73:
#line 311 "./src/parser.y"
    {
        pushOperator(DIV_);
    ;}
    break;

  case 75:
#line 314 "./src/parser.y"
    {
        pushOperator(MOD_);
    ;}
    break;

  case 78:
#line 320 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 80:
#line 323 "./src/parser.y"
    {
        pushOperator(LEFTPAR_);
    ;}
    break;

  case 81:
#line 325 "./src/parser.y"
    {
        pushOperator(RIGHTPAR_);
    ;}
    break;

  case 84:
#line 332 "./src/parser.y"
    {
        pushOperandOfType(declareCte(FLOAT_, (yyvsp[(1) - (1)].fval)), FLOAT_);
    ;}
    break;

  case 85:
#line 335 "./src/parser.y"
    {
        pushOperandOfType(declareCte(INT_, (yyvsp[(1) - (1)].ival)), INT_);
    ;}
    break;

  case 86:
#line 338 "./src/parser.y"
    {
        pushOperandOfType(declareCte(BOOL_, (yyvsp[(1) - (1)].bval)), BOOL_);
    ;}
    break;

  case 87:
#line 341 "./src/parser.y"
    {
        pushOperandOfType(declareCte(STRING_, (yyvsp[(1) - (1)].strval)), STRING_);
    ;}
    break;

  case 88:
#line 346 "./src/parser.y"
    {
        verifyFunctionExists(getIDExpression(), lineas);
        setCurrentCall(getIDExpression());
    ;}
    break;

  case 89:
#line 349 "./src/parser.y"
    {
        generateEra(getCurrentCall());
        resetParameterCount(getCurrentCall());
        pushOperator(FAKEBOT_);
    ;}
    break;

  case 90:
#line 353 "./src/parser.y"
    {
        verifyParameters(getCurrentCall());
        generateGosub(getCurrentCall());
        pushOperandResult(getCurrentCall());
        setCurrentCall("");
        popOperator(FAKEBOT_);
    ;}
    break;

  case 91:
#line 360 "./src/parser.y"
    {
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 92:
#line 363 "./src/parser.y"
    {
        popOperator(FAKEBOT_);
    ;}
    break;

  case 93:
#line 366 "./src/parser.y"
    {
        pushOperandByID(getIDExpression());
    ;}
    break;

  case 96:
#line 375 "./src/parser.y"
    {
        generateVerify();
    ;}
    break;

  case 97:
#line 377 "./src/parser.y"
    {
        generateAccess();
    ;}
    break;

  case 98:
#line 382 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 101:
#line 388 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 113:
#line 407 "./src/parser.y"
    {
        (yyval.imgFunc) = GRAYSCALE_;
    ;}
    break;

  case 114:
#line 410 "./src/parser.y"
    {
        (yyval.imgFunc) = SAVE_;
    ;}
    break;

  case 115:
#line 413 "./src/parser.y"
    {
        (yyval.imgFunc) = OPEN_;
    ;}
    break;

  case 116:
#line 416 "./src/parser.y"
    {
        (yyval.imgFunc) = BANDW_;
    ;}
    break;

  case 117:
#line 419 "./src/parser.y"
    {
        (yyval.imgFunc) = CHANGECOLOR_;
    ;}
    break;

  case 118:
#line 422 "./src/parser.y"
    {
        (yyval.imgFunc) = HFLIP_;
    ;}
    break;

  case 119:
#line 425 "./src/parser.y"
    {
        (yyval.imgFunc) = VFLIP_;
    ;}
    break;

  case 120:
#line 428 "./src/parser.y"
    {
        (yyval.imgFunc) = CROP_;
    ;}
    break;

  case 121:
#line 433 "./src/parser.y"
    {
        verifyImageParameterCount((yyvsp[(3) - (7)].imgFunc), (yyvsp[(5) - (7)].paramNode)->count);
        performImageCall((yyvsp[(1) - (7)].sval), (yyvsp[(3) - (7)].imgFunc), (yyvsp[(5) - (7)].paramNode));
    ;}
    break;

  case 122:
#line 437 "./src/parser.y"
    {
        verifyImageParameterCount((yyvsp[(3) - (6)].imgFunc), 0);
        performImageCall((yyvsp[(1) - (6)].sval), (yyvsp[(3) - (6)].imgFunc), nullptr);
    ;}
    break;

  case 123:
#line 443 "./src/parser.y"
    {
        int type = topOperandType();
        ParamNode *node = new ParamNode(popOperand(), type);
        (yyval.paramNode) = node;
    ;}
    break;

  case 124:
#line 448 "./src/parser.y"
    {
        int type = topOperandType();
        ParamNode *node = new ParamNode(popOperand(), type, (yyvsp[(3) - (3)].paramNode));
        (yyval.paramNode) = node;
    ;}
    break;

  case 125:
#line 455 "./src/parser.y"
    {
        pushOperator(EQUALS_);
    ;}
    break;

  case 126:
#line 457 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({EQUALS_}));
    ;}
    break;

  case 127:
#line 462 "./src/parser.y"
    {
        pushOperandByID((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 128:
#line 465 "./src/parser.y"
    {
        handleIDExpression((yyvsp[(1) - (1)].sval));
        pushOperator(FAKEBOT_);
        verifyIsArray(getIDExpression());
    ;}
    break;

  case 129:
#line 469 "./src/parser.y"
    {
        popOperator(FAKEBOT_);
    ;}
    break;

  case 130:
#line 474 "./src/parser.y"
    {
        verifyFunctionExists((yyvsp[(1) - (1)].sval), lineas);
    ;}
    break;

  case 131:
#line 476 "./src/parser.y"
    {
        generateEra((yyvsp[(1) - (3)].sval));
        setCurrentCall((yyvsp[(1) - (3)].sval));
        resetParameterCount((yyvsp[(1) - (3)].sval));
    ;}
    break;

  case 132:
#line 480 "./src/parser.y"
    {
        verifyParameters((yyvsp[(1) - (6)].sval));
        generateGosub((yyvsp[(1) - (6)].sval));
        setCurrentCall("");
    ;}
    break;

  case 134:
#line 487 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 137:
#line 493 "./src/parser.y"
    {
        generateParam();
    ;}
    break;

  case 140:
#line 499 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 141:
#line 501 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
        generateNewline();
    ;}
    break;

  case 142:
#line 507 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
    ;}
    break;

  case 143:
#line 510 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 146:
#line 516 "./src/parser.y"
    {
        generateInput(INT_);
    ;}
    break;

  case 147:
#line 519 "./src/parser.y"
    {
        generateInput(FLOAT_);
    ;}
    break;

  case 148:
#line 522 "./src/parser.y"
    {
        generateInput(STRING_);
    ;}
    break;

  case 149:
#line 527 "./src/parser.y"
    {
        pushOperator(PRINT_);
    ;}
    break;

  case 150:
#line 529 "./src/parser.y"
    {
        checkIfShouldDoOperation(vector<int>({PRINT_}));
    ;}
    break;

  case 152:
#line 535 "./src/parser.y"
    {
        generateElse();
    ;}
    break;

  case 153:
#line 537 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 154:
#line 540 "./src/parser.y"
    {
        fillJumpIf();
    ;}
    break;

  case 155:
#line 545 "./src/parser.y"
    {
        generateIf();
    ;}
    break;

  case 159:
#line 554 "./src/parser.y"
    {
        pushJumpCurrent();
    ;}
    break;

  case 160:
#line 556 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 161:
#line 558 "./src/parser.y"
    {
        fillJumpWhile();
    ;}
    break;

  case 162:
#line 563 "./src/parser.y"
    {
        // pushJumpCurrent();
    ;}
    break;

  case 163:
#line 565 "./src/parser.y"
    {
        pushLastAssignment();
        saveForVariable();
        pushJumpCurrent(-1);
    ;}
    break;

  case 164:
#line 569 "./src/parser.y"
    {
        validateLastAssignment(INT_);
        validateLastOperand(INT_);
        pushOperator(LESS_);
        doOperation();
    ;}
    break;

  case 165:
#line 574 "./src/parser.y"
    {
        generateWhile();
    ;}
    break;

  case 166:
#line 576 "./src/parser.y"
    {
        fillJumpFor();
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2501 "./bin/parser.tab.c"
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


#line 580 "./src/parser.y"


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
