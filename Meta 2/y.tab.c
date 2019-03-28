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
     SEMICOLON = 258,
     BLANKID = 259,
     PACKAGE = 260,
     RETURN = 261,
     AND = 262,
     ASSIGN = 263,
     STAR = 264,
     COMMA = 265,
     DIV = 266,
     EQ = 267,
     GE = 268,
     GT = 269,
     LBRACE = 270,
     LE = 271,
     LPAR = 272,
     LSQ = 273,
     LT = 274,
     MINUS = 275,
     MOD = 276,
     NE = 277,
     NOT = 278,
     OR = 279,
     PLUS = 280,
     RBRACE = 281,
     RPAR = 282,
     RSQ = 283,
     ELSE = 284,
     FOR = 285,
     IF = 286,
     VAR = 287,
     INT = 288,
     FLOAT32 = 289,
     BOOL = 290,
     STRING = 291,
     PARSEINT = 292,
     FUNC = 293,
     CMDARGS = 294,
     PRINT = 295,
     RESERVED = 296,
     INTLIT = 297,
     REALLIT = 298,
     STRLIT = 299,
     ID = 300
   };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define BLANKID 259
#define PACKAGE 260
#define RETURN 261
#define AND 262
#define ASSIGN 263
#define STAR 264
#define COMMA 265
#define DIV 266
#define EQ 267
#define GE 268
#define GT 269
#define LBRACE 270
#define LE 271
#define LPAR 272
#define LSQ 273
#define LT 274
#define MINUS 275
#define MOD 276
#define NE 277
#define NOT 278
#define OR 279
#define PLUS 280
#define RBRACE 281
#define RPAR 282
#define RSQ 283
#define ELSE 284
#define FOR 285
#define IF 286
#define VAR 287
#define INT 288
#define FLOAT32 289
#define BOOL 290
#define STRING 291
#define PARSEINT 292
#define FUNC 293
#define CMDARGS 294
#define PRINT 295
#define RESERVED 296
#define INTLIT 297
#define REALLIT 298
#define STRLIT 299
#define ID 300




/* Copy the first part of user declarations.  */
#line 1 "gocompiler.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
    #include "ast.h"
    
    int yylex(void);
    void yyerror(char *s);
    int yyparse(void);

    node* root=NULL;
    node* aux=NULL;
    node* aux2=NULL;
    
    int syntax_error=0;
    int stat_list=0;
    int column;
    int line;
    int lastCol;
    char* straux;
    
    int syntaxError=0;


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
#line 27 "gocompiler.y"
{
    char* value ;
    struct node* node;
    
}
/* Line 193 of yacc.c.  */
#line 217 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 230 "y.tab.c"

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
#define YYLAST   554

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,     9,    11,    15,    19,    22,    25,
      28,    34,    37,    41,    45,    48,    50,    52,    54,    56,
      62,    70,    77,    84,    86,    91,    94,    98,   101,   105,
     109,   110,   114,   117,   121,   126,   132,   140,   149,   158,
     168,   172,   177,   183,   188,   190,   193,   195,   197,   202,
     204,   208,   211,   213,   215,   227,   236,   241,   245,   250,
     256,   260,   263,   265,   267,   269,   271,   273,   277,   280,
     283,   286,   290,   294,   298,   302,   306,   310,   314,   318,
     322,   326,   330,   334,   338
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,     5,    45,     3,    48,    -1,    -1,    49,
      -1,    49,    50,     3,    -1,    49,    54,     3,    -1,    50,
       3,    -1,    54,     3,    -1,    32,    51,    -1,    32,    17,
      51,     3,    27,    -1,    65,    53,    -1,    65,    52,    53,
      -1,    52,    10,    65,    -1,    10,    65,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1,    38,    65,    17,    27,
      57,    -1,    38,    65,    17,    55,    27,    53,    57,    -1,
      38,    65,    17,    55,    27,    57,    -1,    38,    65,    17,
      27,    53,    57,    -1,    56,    -1,    56,    10,    65,    53,
      -1,    65,    53,    -1,    15,    58,    26,    -1,    58,     3,
      -1,    58,    50,     3,    -1,    58,    59,     3,    -1,    -1,
      65,     8,    66,    -1,    15,    26,    -1,    15,    60,    26,
      -1,    31,    66,    15,    26,    -1,    31,    66,    15,    60,
      26,    -1,    31,    66,    15,    26,    29,    15,    26,    -1,
      31,    66,    15,    26,    29,    15,    60,    26,    -1,    31,
      66,    15,    60,    26,    29,    15,    26,    -1,    31,    66,
      15,    60,    26,    29,    15,    60,    26,    -1,    30,    15,
      26,    -1,    30,    66,    15,    26,    -1,    30,    66,    15,
      60,    26,    -1,    30,    15,    60,    26,    -1,     6,    -1,
       6,    66,    -1,    63,    -1,    62,    -1,    40,    17,    61,
      27,    -1,     1,    -1,    60,    59,     3,    -1,    59,     3,
      -1,    66,    -1,    44,    -1,    65,    10,     4,     8,    37,
      17,    39,    18,    66,    28,    27,    -1,    65,    10,     4,
       8,    37,    17,     1,    27,    -1,    65,    17,     1,    27,
      -1,    65,    17,    27,    -1,    65,    17,    66,    27,    -1,
      65,    17,    66,    64,    27,    -1,    64,    10,    66,    -1,
      10,    66,    -1,    45,    -1,    42,    -1,    43,    -1,    65,
      -1,    63,    -1,    17,    66,    27,    -1,    23,    66,    -1,
      20,    66,    -1,    25,    66,    -1,    66,    24,    66,    -1,
      66,     7,    66,    -1,    66,    19,    66,    -1,    66,    14,
      66,    -1,    66,    12,    66,    -1,    66,    22,    66,    -1,
      66,    16,    66,    -1,    66,    13,    66,    -1,    66,    25,
      66,    -1,    66,    20,    66,    -1,    66,     9,    66,    -1,
      66,    11,    66,    -1,    66,    21,    66,    -1,    17,     1,
      27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    61,    62,    66,    67,    68,    69,    74,
      75,    79,    83,    98,   103,   110,   111,   112,   113,   117,
     127,   135,   143,   155,   161,   165,   172,   178,   179,   180,
     181,   186,   190,   191,   192,   198,   204,   210,   217,   223,
     233,   236,   239,   245,   251,   252,   254,   255,   257,   259,
     266,   267,   271,   272,   276,   277,   281,   282,   283,   284,
     288,   289,   293,   296,   297,   298,   299,   301,   302,   304,
     306,   308,   311,   314,   317,   320,   323,   326,   329,   332,
     335,   338,   341,   344,   347
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "BLANKID", "PACKAGE",
  "RETURN", "AND", "ASSIGN", "STAR", "COMMA", "DIV", "EQ", "GE", "GT",
  "LBRACE", "LE", "LPAR", "LSQ", "LT", "MINUS", "MOD", "NE", "NOT", "OR",
  "PLUS", "RBRACE", "RPAR", "RSQ", "ELSE", "FOR", "IF", "VAR", "INT",
  "FLOAT32", "BOOL", "STRING", "PARSEINT", "FUNC", "CMDARGS", "PRINT",
  "RESERVED", "INTLIT", "REALLIT", "STRLIT", "ID", "$accept", "Program",
  "Declarations", "DeclarationsAux", "VarDeclaration", "VarSpec",
  "VarSpecAux", "Type", "FuncDeclaration", "Parameters", "ParametersAux",
  "FuncBody", "VarsAndStatements", "Statement", "StatementSEMICOLON",
  "StatementExprSTRLIT", "ParseArgs", "FuncInvocation",
  "FuncInvocationAux", "IdAux", "Expr", 0
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
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    54,
      54,    54,    54,    55,    56,    56,    57,    58,    58,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      64,    64,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     1,     3,     3,     2,     2,     2,
       5,     2,     3,     3,     2,     1,     1,     1,     1,     5,
       7,     6,     6,     1,     4,     2,     3,     2,     3,     3,
       0,     3,     2,     3,     4,     5,     7,     8,     8,     9,
       3,     4,     5,     4,     1,     2,     1,     1,     4,     1,
       3,     2,     1,     1,    11,     8,     4,     3,     4,     5,
       3,     2,     1,     1,     1,     1,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,     2,     4,
       0,     0,     0,    62,     9,     0,     0,     0,     0,     7,
       8,     0,     0,    15,    16,    17,    18,     0,    11,     0,
       5,     6,     0,    14,     0,    12,     0,     0,    23,     0,
      10,    13,    30,     0,    19,     0,     0,    25,     0,    22,
       0,    21,     0,    49,    27,    44,     0,    26,     0,     0,
       0,     0,     0,    47,    46,     0,    20,    24,     0,     0,
       0,     0,    63,    64,    66,    65,    45,    32,     0,     0,
       0,     0,     0,     0,    28,    29,     0,     0,     0,     0,
       0,    69,    68,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    33,     0,
      40,     0,     0,     0,    53,     0,    52,    31,     0,     0,
      57,     0,    84,    67,    72,    81,    82,    75,    78,    74,
      77,    73,    80,    83,    76,    71,    79,    50,    43,    41,
       0,    34,     0,    48,     0,    56,     0,    58,     0,    42,
       0,    35,     0,    61,     0,    59,     0,     0,     0,    60,
      36,     0,     0,     0,     0,    37,    38,     0,    55,     0,
      39,     0,     0,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    14,    27,    28,    11,    37,
      38,    44,    48,    78,    79,   115,    63,    74,   148,    75,
      76
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
      10,   -36,    26,    24,   -70,   -13,     0,   -14,   -70,   -13,
      35,    46,   -14,   -70,   -70,   152,    41,    49,    60,   -70,
     -70,    67,   -14,   -70,   -70,   -70,   -70,   333,   -70,   -23,
     -70,   -70,    55,   -70,   -14,   -70,   186,    56,    62,   518,
     -70,   -70,   -70,    69,   -70,   186,   -14,   -70,    45,   -70,
      69,   -70,   518,   -70,   -70,   337,   151,   -70,   330,   337,
      71,    83,    86,   -70,   -70,     4,   -70,   -70,   150,   337,
     337,   337,   -70,   -70,   -70,    74,   470,   -70,    89,   168,
     199,   432,   451,    36,   -70,   -70,   337,    91,    12,    73,
     413,     9,   -70,     9,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   -70,   -70,    95,
     -70,   201,   222,   234,   -70,    76,   470,   470,    96,    81,
     -70,   394,   -70,   -70,   504,   -70,   -70,   519,   525,   525,
     525,   525,     9,   -70,   519,   489,     9,   -70,   -70,   -70,
     255,    80,   257,   -70,    82,   -70,   337,   -70,    -3,   -70,
     102,    93,   103,   470,   337,   -70,   283,   108,     2,   470,
     -70,   290,   311,    98,   109,   -70,   -70,   318,   -70,   337,
     -70,   374,   101,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -70,   -70,    -1,   118,   -70,   230,   123,   -70,
     -70,    19,   -70,   -43,   -69,   -70,   -70,   -46,   -70,    -6,
      43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      15,    16,    64,   163,    36,    62,    15,   154,    17,     3,
      64,   111,    86,   119,    87,     1,    33,    12,    95,     6,
      96,    88,    13,    39,   155,     7,     4,     5,    41,    68,
     103,    13,    69,    64,    64,    70,   109,    71,    19,   120,
      52,   164,    65,   140,   142,    13,    53,    61,    54,    20,
      65,    55,    30,    68,    72,    73,    69,    13,    29,    70,
      56,    71,    49,    31,    51,    64,    64,    64,   109,    66,
      32,    57,    46,    65,    65,    58,    59,     6,    72,    73,
     114,    13,    40,    45,    42,    60,    84,   161,    83,    85,
      13,    88,   107,   167,    64,   118,    64,   109,   137,   109,
     122,    81,    82,   143,   144,    65,    65,    65,   145,   150,
      64,    90,    91,    92,    93,    64,    64,   156,   109,   152,
     158,    64,   157,   162,   109,   168,   116,   169,   173,   117,
      21,   121,    18,     0,    65,     0,    65,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
      65,    89,    53,     0,     0,    65,    65,    55,     0,     0,
       0,    65,    22,     0,     0,     0,    56,    68,     0,    53,
      69,     0,     0,    70,    55,    71,     0,    77,     0,     0,
       0,    58,    59,    56,     0,    23,    24,    25,    26,   153,
       0,    60,    72,    73,   108,    13,    13,   159,    58,    59,
      53,    42,    53,     0,     0,    55,     0,    55,    60,     0,
       0,     0,   171,    13,    56,     0,    56,     0,     0,    23,
      24,    25,    26,    53,     0,   110,     0,   138,    55,    58,
      59,    58,    59,     0,     0,    53,     0,    56,     0,    60,
      55,    60,     0,     0,    13,     0,    13,     0,   139,    56,
       0,     0,    58,    59,     0,     0,    53,    35,    53,     0,
     141,    55,    60,    55,    58,    59,    43,    13,     0,    47,
      56,     0,    56,     0,    60,    50,     0,     0,     0,    13,
       0,   149,    67,   151,    53,    58,    59,    58,    59,    55,
       0,    53,     0,     0,     0,    60,    55,    60,    56,     0,
      13,     0,    13,     0,     0,    56,     0,     0,     0,   160,
       0,     0,    53,    58,    59,     0,   165,    55,     0,    53,
      58,    59,     0,    60,    55,     0,    56,     0,    13,     0,
      60,     0,     0,    56,     0,    13,     0,   166,     0,     0,
       0,    58,    59,    34,   170,    80,     0,    68,    58,    59,
      69,    60,     0,    70,    68,    71,    13,    69,    60,     0,
      70,     0,    71,    13,     0,     0,    23,    24,    25,    26,
       0,     0,    72,    73,     0,    13,     0,     0,     0,    72,
      73,    94,    13,    95,     0,    96,    97,    98,    99,     0,
     100,     0,     0,   101,   102,   103,   104,     0,   105,   106,
       0,    94,   172,    95,   146,    96,    97,    98,    99,     0,
     100,     0,     0,   101,   102,   103,   104,     0,   105,   106,
      94,   147,    95,     0,    96,    97,    98,    99,     0,   100,
       0,     0,   101,   102,   103,   104,     0,   105,   106,    94,
     123,    95,     0,    96,    97,    98,    99,   112,   100,     0,
       0,   101,   102,   103,   104,     0,   105,   106,    94,     0,
      95,     0,    96,    97,    98,    99,   113,   100,     0,     0,
     101,   102,   103,   104,     0,   105,   106,    94,     0,    95,
       0,    96,    97,    98,    99,     0,   100,     0,     0,   101,
     102,   103,   104,     0,   105,   106,    94,     0,    95,     0,
      96,    97,    98,    99,     0,   100,     0,     0,   101,   102,
     103,   104,     0,    95,   106,    96,    97,    98,    99,     0,
     100,     0,     0,   101,   102,   103,   104,     0,    95,   106,
      96,     0,    98,    99,    95,   100,    96,     0,   101,   102,
     103,     0,     0,     0,   106,   102,   103,     0,     0,     0,
     106,    23,    24,    25,    26
};

static const yytype_int16 yycheck[] =
{
       6,     7,    48,     1,    27,    48,    12,    10,     9,    45,
      56,    80,     8,     1,    10,     5,    22,    17,     9,    32,
      11,    17,    45,    29,    27,    38,     0,     3,    34,    17,
      21,    45,    20,    79,    80,    23,    79,    25,     3,    27,
      46,    39,    48,   112,   113,    45,     1,    48,     3,     3,
      56,     6,     3,    17,    42,    43,    20,    45,    17,    23,
      15,    25,    43,     3,    45,   111,   112,   113,   111,    50,
       3,    26,    10,    79,    80,    30,    31,    32,    42,    43,
      44,    45,    27,    27,    15,    40,     3,   156,    17,     3,
      45,    17,     3,   162,   140,     4,   142,   140,     3,   142,
      27,    58,    59,    27,     8,   111,   112,   113,    27,    29,
     156,    68,    69,    70,    71,   161,   162,    15,   161,    37,
      17,   167,    29,    15,   167,    27,    83,    18,    27,    86,
      12,    88,     9,    -1,   140,    -1,   142,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     156,     1,     1,    -1,    -1,   161,   162,     6,    -1,    -1,
      -1,   167,    10,    -1,    -1,    -1,    15,    17,    -1,     1,
      20,    -1,    -1,    23,     6,    25,    -1,    26,    -1,    -1,
      -1,    30,    31,    15,    -1,    33,    34,    35,    36,   146,
      -1,    40,    42,    43,    26,    45,    45,   154,    30,    31,
       1,    15,     1,    -1,    -1,     6,    -1,     6,    40,    -1,
      -1,    -1,   169,    45,    15,    -1,    15,    -1,    -1,    33,
      34,    35,    36,     1,    -1,    26,    -1,    26,     6,    30,
      31,    30,    31,    -1,    -1,     1,    -1,    15,    -1,    40,
       6,    40,    -1,    -1,    45,    -1,    45,    -1,    26,    15,
      -1,    -1,    30,    31,    -1,    -1,     1,    27,     1,    -1,
      26,     6,    40,     6,    30,    31,    36,    45,    -1,    39,
      15,    -1,    15,    -1,    40,    45,    -1,    -1,    -1,    45,
      -1,    26,    52,    26,     1,    30,    31,    30,    31,     6,
      -1,     1,    -1,    -1,    -1,    40,     6,    40,    15,    -1,
      45,    -1,    45,    -1,    -1,    15,    -1,    -1,    -1,    26,
      -1,    -1,     1,    30,    31,    -1,    26,     6,    -1,     1,
      30,    31,    -1,    40,     6,    -1,    15,    -1,    45,    -1,
      40,    -1,    -1,    15,    -1,    45,    -1,    26,    -1,    -1,
      -1,    30,    31,    10,    26,    15,    -1,    17,    30,    31,
      20,    40,    -1,    23,    17,    25,    45,    20,    40,    -1,
      23,    -1,    25,    45,    -1,    -1,    33,    34,    35,    36,
      -1,    -1,    42,    43,    -1,    45,    -1,    -1,    -1,    42,
      43,     7,    45,     9,    -1,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    19,    20,    21,    22,    -1,    24,    25,
      -1,     7,    28,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    19,    20,    21,    22,    -1,    24,    25,
       7,    27,     9,    -1,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    19,    20,    21,    22,    -1,    24,    25,     7,
      27,     9,    -1,    11,    12,    13,    14,    15,    16,    -1,
      -1,    19,    20,    21,    22,    -1,    24,    25,     7,    -1,
       9,    -1,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    25,     7,    -1,     9,
      -1,    11,    12,    13,    14,    -1,    16,    -1,    -1,    19,
      20,    21,    22,    -1,    24,    25,     7,    -1,     9,    -1,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    19,    20,
      21,    22,    -1,     9,    25,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    19,    20,    21,    22,    -1,     9,    25,
      11,    -1,    13,    14,     9,    16,    11,    -1,    19,    20,
      21,    -1,    -1,    -1,    25,    20,    21,    -1,    -1,    -1,
      25,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    47,    45,     0,     3,    32,    38,    48,    49,
      50,    54,    17,    45,    51,    65,    65,    50,    54,     3,
       3,    51,    10,    33,    34,    35,    36,    52,    53,    17,
       3,     3,     3,    65,    10,    53,    27,    55,    56,    65,
      27,    65,    15,    53,    57,    27,    10,    53,    58,    57,
      53,    57,    65,     1,     3,     6,    15,    26,    30,    31,
      40,    50,    59,    62,    63,    65,    57,    53,    17,    20,
      23,    25,    42,    43,    63,    65,    66,    26,    59,    60,
      15,    66,    66,    17,     3,     3,     8,    10,    17,     1,
      66,    66,    66,    66,     7,     9,    11,    12,    13,    14,
      16,    19,    20,    21,    22,    24,    25,     3,    26,    59,
      26,    60,    15,    15,    44,    61,    66,    66,     4,     1,
      27,    66,    27,    27,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,     3,    26,    26,
      60,    26,    60,    27,     8,    27,    10,    27,    64,    26,
      29,    26,    37,    66,    10,    27,    15,    29,    17,    66,
      26,    60,    15,     1,    39,    26,    26,    60,    27,    18,
      26,    66,    28,    27
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
#line 54 "gocompiler.y"
    {root=newNode("Program",NULL); 
                                                                                                    addChild(root,(yyvsp[(4) - (4)].node));
                                                                                                     }
    break;

  case 3:
#line 61 "gocompiler.y"
    {(yyval.node)=NULL;}
    break;

  case 4:
#line 62 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 5:
#line 66 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node); addBrother((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));}
    break;

  case 6:
#line 67 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node); addBrother((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));}
    break;

  case 7:
#line 68 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node);}
    break;

  case 8:
#line 69 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node);}
    break;

  case 9:
#line 74 "gocompiler.y"
    {(yyval.node)=(yyvsp[(2) - (2)].node);  }
    break;

  case 10:
#line 75 "gocompiler.y"
    {(yyval.node)=(yyvsp[(3) - (5)].node);}
    break;

  case 11:
#line 79 "gocompiler.y"
    {(yyval.node)=newNode("VarDecl",NULL);
                                                                                                            addChild((yyval.node),(yyvsp[(2) - (2)].node));
                                                                                                            addBrother((yyvsp[(2) - (2)].node),(yyvsp[(1) - (2)].node));
                                                                                                            }
    break;

  case 12:
#line 83 "gocompiler.y"
    {(yyval.node)=newNode("VarDecl",NULL);
                                                                                                            addChild((yyval.node),(yyvsp[(3) - (3)].node));
                                                                                                            addBrother((yyvsp[(3) - (3)].node),(yyvsp[(1) - (3)].node));
                                                                                                            addBrother((yyval.node),(yyvsp[(2) - (3)].node));
                                                                                                            aux2=(yyval.node)->brother;
                                                                                                            while(aux2!=NULL&&strcmp(aux2->child->type,"faketype")==0){
                                                                                                        
                                                                                                                strcpy(aux2->child->type,(yyvsp[(3) - (3)].node)->type);
                                                                                                                //aux2->type=$3->type;
                                                                                                                aux2=aux2->brother;
                                                                                                            }
                                                                                                            }
    break;

  case 13:
#line 98 "gocompiler.y"
    {(yyval.node)=newNode("VarDecl",NULL);
                                                                                                            aux=newNode("faketype",NULL);
                                                                                                            addBrother((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                            addChild((yyval.node),aux);
                                                                                                            addBrother(aux,(yyvsp[(3) - (3)].node));}
    break;

  case 14:
#line 103 "gocompiler.y"
    {(yyval.node)=newNode("VarDecl",NULL);
                                                                                                            aux=newNode("faketype",NULL);
                                                                                                            addChild((yyval.node),aux);
                                                                                                            addBrother(aux,(yyvsp[(2) - (2)].node));}
    break;

  case 15:
#line 110 "gocompiler.y"
    {(yyval.node)=newNode("Int",NULL);}
    break;

  case 16:
#line 111 "gocompiler.y"
    {(yyval.node)=newNode("Float32",NULL);}
    break;

  case 17:
#line 112 "gocompiler.y"
    {(yyval.node)=newNode("Bool",NULL);}
    break;

  case 18:
#line 113 "gocompiler.y"
    {(yyval.node)=newNode("String",NULL);}
    break;

  case 19:
#line 117 "gocompiler.y"
    {(yyval.node)=newNode("FuncDecl",NULL);
                                                                                                        aux= newNode("FuncHeader",NULL);
                                                                                                        addChild((yyval.node),aux);
                                                                                                        addChild(aux,(yyvsp[(2) - (5)].node));
                                                                                                        addBrother((yyvsp[(2) - (5)].node),newNode("FuncParams",NULL));
                                                                                                        addBrother(aux,(yyvsp[(5) - (5)].node));
                                                                                                        

                                                                                                            
                                                                                                        }
    break;

  case 20:
#line 127 "gocompiler.y"
    {(yyval.node)=newNode("FuncDecl",NULL);
                                                                                                        aux= newNode("FuncHeader",NULL);
                                                                                                        addChild((yyval.node),aux);
                                                                                                        addBrother(aux,(yyvsp[(7) - (7)].node));
                                                                                                        addChild(aux,(yyvsp[(2) - (7)].node));
                                                                                                        addBrother((yyvsp[(6) - (7)].node),(yyvsp[(4) - (7)].node));
                                                                                                        addBrother((yyvsp[(2) - (7)].node),(yyvsp[(6) - (7)].node));
                                                                                                         }
    break;

  case 21:
#line 135 "gocompiler.y"
    {(yyval.node)=newNode("FuncDecl",NULL);
                                                                                                        aux= newNode("FuncHeader",NULL);
                                                                                                        addChild((yyval.node),aux);
                                                                                                        addBrother(aux,(yyvsp[(6) - (6)].node));
                                                                                                        addChild(aux,(yyvsp[(2) - (6)].node));
                                                                                                        addBrother((yyvsp[(2) - (6)].node),(yyvsp[(4) - (6)].node));
                                                                                                        
                                                                                                         }
    break;

  case 22:
#line 143 "gocompiler.y"
    {(yyval.node)=newNode("FuncDecl",NULL);
                                                                                                        aux= newNode("FuncHeader",NULL);
                                                                                                        addChild((yyval.node),aux);
                                                                                                        addBrother(aux,(yyvsp[(6) - (6)].node));
                                                                                                        addChild(aux,(yyvsp[(2) - (6)].node));
                                                                                                        addBrother((yyvsp[(2) - (6)].node),(yyvsp[(5) - (6)].node));
                                                                                                        addBrother((yyvsp[(5) - (6)].node),newNode("FuncParams",NULL));
                                                                                                         }
    break;

  case 23:
#line 155 "gocompiler.y"
    {(yyval.node)=newNode("FuncParams",NULL);
                                                                                                         addChild((yyval.node),(yyvsp[(1) - (1)].node));
                                                                                                        }
    break;

  case 24:
#line 161 "gocompiler.y"
    {(yyval.node)=newNode("ParamDecl",NULL); 
                                                                                                        addChild((yyval.node),(yyvsp[(4) - (4)].node));
                                                                                                        addBrother((yyvsp[(4) - (4)].node),(yyvsp[(3) - (4)].node));
                                                                                                        }
    break;

  case 25:
#line 165 "gocompiler.y"
    {(yyval.node)=newNode("ParamDecl",NULL); 
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (2)].node));
                                                                                                        addBrother((yyvsp[(2) - (2)].node),(yyvsp[(1) - (2)].node));
                                                                                                        }
    break;

  case 26:
#line 172 "gocompiler.y"
    {(yyval.node)=newNode("FuncBody",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (3)].node));
                                                                                                        }
    break;

  case 27:
#line 178 "gocompiler.y"
    {(yyvsp[(1) - (2)].node)=(yyvsp[(1) - (2)].node);}
    break;

  case 28:
#line 179 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node); addBrother((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));}
    break;

  case 29:
#line 180 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node); addBrother((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));}
    break;

  case 30:
#line 181 "gocompiler.y"
    {(yyval.node)=newNode("NULL",NULL);}
    break;

  case 31:
#line 186 "gocompiler.y"
    {(yyval.node) =  newNode("Assign",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 32:
#line 190 "gocompiler.y"
    {(yyval.node)=NULL;}
    break;

  case 33:
#line 191 "gocompiler.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);/* BLOCK AQUI ??? parece que sim , fazer um while para ver o numero de filhos que tem */}
    break;

  case 34:
#line 192 "gocompiler.y"
    {(yyval.node) =  newNode("If",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (4)].node));
                                                                                                        aux=newNode("Block",NULL);
                                                                                                        addBrother((yyvsp[(2) - (4)].node),aux);
                                                                                                        addBrother(aux,newNode("Block",NULL));
                                                                                                        }
    break;

  case 35:
#line 198 "gocompiler.y"
    {(yyval.node) =  newNode("If",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (5)].node));
                                                                                                        aux=newNode("Block",NULL);
                                                                                                        addBrother((yyvsp[(2) - (5)].node),aux);
                                                                                                        addChild(aux,(yyvsp[(4) - (5)].node));
                                                                                                        }
    break;

  case 36:
#line 204 "gocompiler.y"
    {(yyval.node) =  newNode("If",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (7)].node));
                                                                                                        aux=newNode("Block",NULL);
                                                                                                        addBrother((yyvsp[(2) - (7)].node),aux);
                                                                                                        addBrother(aux,newNode("Block",NULL));}
    break;

  case 37:
#line 210 "gocompiler.y"
    {(yyval.node) =  newNode("If",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (8)].node));
                                                                                                        aux=newNode("Block",NULL);
                                                                                                        aux2=newNode("Block",NULL);
                                                                                                        addBrother((yyvsp[(2) - (8)].node),aux);
                                                                                                        addBrother(aux,aux2);
                                                                                                        addChild(aux2,(yyvsp[(7) - (8)].node));}
    break;

  case 38:
#line 217 "gocompiler.y"
    {(yyval.node) =  newNode("If",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (8)].node));
                                                                                                        aux=newNode("Block",NULL);
                                                                                                        addBrother((yyvsp[(2) - (8)].node),aux);
                                                                                                        addChild(aux,(yyvsp[(4) - (8)].node));
                                                                                                        addBrother(aux,newNode("Block",NULL));}
    break;

  case 39:
#line 223 "gocompiler.y"
    {(yyval.node) =  newNode("If",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (9)].node));
                                                                                                        aux=newNode("Block",NULL);
                                                                                                        aux2=newNode("Block",NULL);
                                                                                                        addBrother((yyvsp[(2) - (9)].node),aux);
                                                                                                        addChild(aux,(yyvsp[(4) - (9)].node));
                                                                                                        addBrother(aux,aux2);
                                                                                                        addChild(aux2,(yyvsp[(8) - (9)].node));
                                                                                                        }
    break;

  case 40:
#line 233 "gocompiler.y"
    {(yyval.node) =  newNode("For",NULL);
                                                                                                        addChild((yyval.node),newNode("Block",NULL));
                                                                                                        }
    break;

  case 41:
#line 236 "gocompiler.y"
    {(yyval.node) =  newNode("For",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (4)].node));
                                                                                                        addBrother((yyvsp[(2) - (4)].node),newNode("Block",NULL));}
    break;

  case 42:
#line 239 "gocompiler.y"
    {(yyval.node) =  newNode("For",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (5)].node));
                                                                                                        aux=newNode("Block",NULL);
                                                                                                        addBrother((yyvsp[(2) - (5)].node),aux);
                                                                                                        addChild(aux,(yyvsp[(4) - (5)].node));
                                                                                                        }
    break;

  case 43:
#line 245 "gocompiler.y"
    {(yyval.node) =  newNode("For",NULL);
                                                                                                        aux=newNode("Block",NULL);
                                                                                                        addChild((yyval.node),aux);
                                                                                                        addChild(aux,(yyvsp[(3) - (4)].node));
                                                                                                        }
    break;

  case 44:
#line 251 "gocompiler.y"
    {(yyval.node) =  newNode("Return",NULL);}
    break;

  case 45:
#line 252 "gocompiler.y"
    {(yyval.node) =  newNode("Return",NULL);addChild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 46:
#line 254 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 47:
#line 255 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 48:
#line 257 "gocompiler.y"
    {(yyval.node) =  newNode("Print",NULL);addChild((yyval.node),(yyvsp[(3) - (4)].node));}
    break;

  case 49:
#line 259 "gocompiler.y"
    {(yyval.node)=newNode("Error",NULL);syntaxError=1;}
    break;

  case 50:
#line 266 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node);addBrother((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));}
    break;

  case 51:
#line 267 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node);}
    break;

  case 52:
#line 271 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 53:
#line 272 "gocompiler.y"
    {(yyval.node)=newNode("StrLit",(yyvsp[(1) - (1)].value));}
    break;

  case 54:
#line 276 "gocompiler.y"
    {(yyval.node)=newNode("ParseArgs",NULL);addChild((yyval.node),(yyvsp[(1) - (11)].node));addBrother((yyvsp[(1) - (11)].node),(yyvsp[(9) - (11)].node));}
    break;

  case 55:
#line 277 "gocompiler.y"
    {(yyval.node)=newNode("ParseArgs",NULL);addChild((yyval.node),(yyvsp[(1) - (8)].node));addBrother((yyvsp[(1) - (8)].node),newNode("Error",NULL));}
    break;

  case 56:
#line 281 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (4)].node);addBrother((yyvsp[(1) - (4)].node),newNode("Error",NULL));}
    break;

  case 57:
#line 282 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node);}
    break;

  case 58:
#line 283 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (4)].node);addBrother((yyvsp[(1) - (4)].node),(yyvsp[(3) - (4)].node));}
    break;

  case 59:
#line 284 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (5)].node);addBrother((yyvsp[(1) - (5)].node),(yyvsp[(3) - (5)].node));addBrother((yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node));}
    break;

  case 60:
#line 288 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node);addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 61:
#line 289 "gocompiler.y"
    {(yyval.node)=(yyvsp[(2) - (2)].node);}
    break;

  case 62:
#line 293 "gocompiler.y"
    {(yyval.node)=newNode("Id",yylval.value);}
    break;

  case 63:
#line 296 "gocompiler.y"
    {(yyval.node)=newNode("IntLit",(yyvsp[(1) - (1)].value));}
    break;

  case 64:
#line 297 "gocompiler.y"
    {(yyval.node)=newNode("RealLit",(yyvsp[(1) - (1)].value));}
    break;

  case 65:
#line 298 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 66:
#line 299 "gocompiler.y"
    {(yyval.node)=newNode("Call",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 67:
#line 301 "gocompiler.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 68:
#line 302 "gocompiler.y"
    {(yyval.node)=newNode("Not",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 69:
#line 304 "gocompiler.y"
    {(yyval.node)=newNode("Minus",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 70:
#line 306 "gocompiler.y"
    {(yyval.node)=newNode("Plus",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 71:
#line 308 "gocompiler.y"
    {(yyval.node) =  newNode("Or",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 72:
#line 311 "gocompiler.y"
    {(yyval.node) =  newNode("And",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 73:
#line 314 "gocompiler.y"
    {(yyval.node) =  newNode("Lt",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 74:
#line 317 "gocompiler.y"
    {(yyval.node) =  newNode("Gt",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 75:
#line 320 "gocompiler.y"
    {(yyval.node) =  newNode("Eq",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 76:
#line 323 "gocompiler.y"
    {(yyval.node) =  newNode("Ne",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 77:
#line 326 "gocompiler.y"
    {(yyval.node) =  newNode("Ne",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 78:
#line 329 "gocompiler.y"
    {(yyval.node) =  newNode("Ge",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 79:
#line 332 "gocompiler.y"
    {(yyval.node) =  newNode("Add",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 80:
#line 335 "gocompiler.y"
    {(yyval.node) =  newNode("Sub",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 81:
#line 338 "gocompiler.y"
    {(yyval.node) =  newNode("Mul",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 82:
#line 341 "gocompiler.y"
    {(yyval.node) =  newNode("Div",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 83:
#line 344 "gocompiler.y"
    {(yyval.node) =  newNode("Mod",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 84:
#line 347 "gocompiler.y"
    {(yyval.node)=newNode("Error",NULL);syntaxError=1;}
    break;


/* Line 1267 of yacc.c.  */
#line 2214 "y.tab.c"
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


#line 354 "gocompiler.y"




void yyerror(char *s){
    int i=0;
    while(straux[i]!='\0'){
        i++;
    }
    if(strcmp(yylval.value,"\n")==0){
        printf("Line %d, column %d: %s: %s\n",(int)(line),(int)(column-i),s,straux);
    }
    else{
        if(strcmp(yylval.value,"EOF")==0){
            printf("Line %d, column %d: %s: %s\n",(int)(line),(int)(column-1),s,straux);
            return;
        }
        else{
            i=0;
            while(yylval.value[i]!='\0'){
                i++;
            }
            printf("Line %d, column %d: %s: %s\n",(int)(line),(int)(column-i),s,yylval.value);
        }
        
    }
    
    
}



