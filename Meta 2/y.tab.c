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
#line 26 "gocompiler.y"
{
    char* value ;
    struct node* node;
    
}
/* Line 193 of yacc.c.  */
#line 216 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 229 "y.tab.c"

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
#define YYLAST   532

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  172

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
       0,     0,     3,     8,     9,    13,    17,    20,    23,    26,
      32,    35,    39,    43,    46,    48,    50,    52,    54,    60,
      68,    75,    82,    84,    89,    92,    96,    99,   103,   107,
     108,   112,   116,   121,   127,   135,   144,   153,   163,   167,
     172,   178,   183,   185,   188,   190,   192,   197,   199,   203,
     206,   208,   210,   222,   231,   236,   240,   245,   251,   255,
     258,   260,   262,   264,   266,   268,   272,   275,   278,   281,
     285,   289,   293,   297,   301,   305,   309,   313,   317,   321,
     325,   329,   333
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,     5,    45,     3,    48,    -1,    -1,    48,
      49,     3,    -1,    48,    53,     3,    -1,    49,     3,    -1,
      53,     3,    -1,    32,    50,    -1,    32,    17,    50,     3,
      27,    -1,    64,    52,    -1,    64,    51,    52,    -1,    51,
      10,    64,    -1,    10,    64,    -1,    33,    -1,    34,    -1,
      35,    -1,    36,    -1,    38,    64,    17,    27,    56,    -1,
      38,    64,    17,    54,    27,    52,    56,    -1,    38,    64,
      17,    54,    27,    56,    -1,    38,    64,    17,    27,    52,
      56,    -1,    55,    -1,    55,    10,    64,    52,    -1,    64,
      52,    -1,    15,    57,    26,    -1,    57,     3,    -1,    57,
      49,     3,    -1,    57,    58,     3,    -1,    -1,    64,     8,
      65,    -1,    15,    59,    26,    -1,    31,    65,    15,    26,
      -1,    31,    65,    15,    59,    26,    -1,    31,    65,    15,
      26,    29,    15,    26,    -1,    31,    65,    15,    26,    29,
      15,    59,    26,    -1,    31,    65,    15,    59,    26,    29,
      15,    26,    -1,    31,    65,    15,    59,    26,    29,    15,
      59,    26,    -1,    30,    15,    26,    -1,    30,    65,    15,
      26,    -1,    30,    65,    15,    59,    26,    -1,    30,    15,
      59,    26,    -1,     6,    -1,     6,    65,    -1,    62,    -1,
      61,    -1,    40,    17,    60,    27,    -1,     1,    -1,    59,
      58,     3,    -1,    58,     3,    -1,    65,    -1,    44,    -1,
      64,    10,     4,     8,    37,    17,    39,    18,    65,    28,
      27,    -1,    64,    10,     4,     8,    37,    17,     1,    27,
      -1,    64,    17,     1,    27,    -1,    64,    17,    27,    -1,
      64,    17,    65,    27,    -1,    64,    17,    65,    63,    27,
      -1,    63,    10,    65,    -1,    10,    65,    -1,    45,    -1,
      42,    -1,    43,    -1,    64,    -1,    62,    -1,    17,    65,
      27,    -1,    23,    65,    -1,    20,    65,    -1,    25,    65,
      -1,    65,    24,    65,    -1,    65,     7,    65,    -1,    65,
      19,    65,    -1,    65,    14,    65,    -1,    65,    12,    65,
      -1,    65,    22,    65,    -1,    65,    16,    65,    -1,    65,
      13,    65,    -1,    65,    25,    65,    -1,    65,    20,    65,
      -1,    65,     9,    65,    -1,    65,    11,    65,    -1,    65,
      21,    65,    -1,    17,     1,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    53,    53,    60,    61,    62,    63,    64,    68,    70,
      75,    76,    82,    83,    87,    88,    89,    90,    94,   104,
     112,   120,   132,   138,   139,   143,   149,   150,   151,   152,
     156,   161,   162,   163,   169,   170,   171,   172,   174,   175,
     176,   177,   179,   180,   182,   183,   185,   187,   194,   195,
     199,   200,   204,   205,   209,   210,   211,   212,   216,   217,
     221,   224,   225,   226,   227,   229,   230,   232,   234,   236,
     239,   242,   245,   248,   251,   254,   257,   260,   263,   266,
     269,   272,   275
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
  "Declarations", "VarDeclaration", "VarSpec", "VarSpecAux", "Type",
  "FuncDeclaration", "Parameters", "ParametersAux", "FuncBody",
  "VarsAndStatements", "Statement", "StatementSEMICOLON",
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
       0,    46,    47,    48,    48,    48,    48,    48,    49,    49,
      50,    50,    51,    51,    52,    52,    52,    52,    53,    53,
      53,    53,    54,    55,    55,    56,    57,    57,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    62,    62,    63,    63,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     3,     3,     2,     2,     2,     5,
       2,     3,     3,     2,     1,     1,     1,     1,     5,     7,
       6,     6,     1,     4,     2,     3,     2,     3,     3,     0,
       3,     3,     4,     5,     7,     8,     8,     9,     3,     4,
       5,     4,     1,     2,     1,     1,     4,     1,     3,     2,
       1,     1,    11,     8,     4,     3,     4,     5,     3,     2,
       1,     1,     1,     1,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,     2,     0,
       0,     0,    60,     8,     0,     0,     0,     0,     6,     7,
       0,     0,    14,    15,    16,    17,     0,    10,     0,     4,
       5,     0,    13,     0,    11,     0,     0,    22,     0,     9,
      12,    29,     0,    18,     0,     0,    24,     0,    21,     0,
      20,     0,    47,    26,    42,     0,    25,     0,     0,     0,
       0,     0,    45,    44,     0,    19,    23,     0,     0,     0,
       0,    61,    62,    64,    63,    43,     0,     0,     0,     0,
       0,     0,    27,    28,     0,     0,     0,     0,     0,    67,
      66,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,    31,     0,    38,     0,
       0,     0,    51,     0,    50,    30,     0,     0,    55,     0,
      82,    65,    70,    79,    80,    73,    76,    72,    75,    71,
      78,    81,    74,    69,    77,    48,    41,    39,     0,    32,
       0,    46,     0,    54,     0,    56,     0,    40,     0,    33,
       0,    59,     0,    57,     0,     0,     0,    58,    34,     0,
       0,     0,     0,    35,    36,     0,    53,     0,    37,     0,
       0,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    13,    26,    27,    10,    36,    37,
      43,    47,    76,    77,   113,    62,    73,   146,    74,    75
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
      -1,   -31,    16,    15,   -67,   -21,   -10,   -25,   -21,    21,
      26,   -25,   -67,   -67,    77,    17,    35,    37,   -67,   -67,
      40,   -25,   -67,   -67,   -67,   -67,   315,   -67,   -19,   -67,
     -67,    23,   -67,   -25,   -67,   352,    29,    47,   306,   -67,
     -67,   -67,    44,   -67,   352,   -25,   -67,    22,   -67,    44,
     -67,   306,   -67,   -67,    38,    45,   -67,   301,    38,    52,
      67,    70,   -67,   -67,   226,   -67,   -67,   186,    38,    38,
      38,   -67,   -67,   -67,    57,   458,    75,    76,   116,   420,
     439,   311,   -67,   -67,    38,    80,   159,    59,   401,    10,
     -67,    10,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,   -67,   -67,    86,   -67,   182,
     190,   218,   -67,    65,   458,   458,    88,    73,   -67,   382,
     -67,   -67,   492,   -67,   -67,   507,   124,   124,   124,   124,
      10,   -67,   507,   477,    10,   -67,   -67,   -67,   231,    50,
     239,   -67,    61,   -67,    38,   -67,     3,   -67,    93,    72,
     102,   458,    38,   -67,   266,   111,     8,   458,   -67,   272,
     274,   100,   118,   -67,   -67,   307,   -67,    38,   -67,   350,
     110,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,    -5,   132,   -67,   215,   142,   -67,   -67,
      81,   -67,   -41,   -66,   -67,   -67,   -45,   -67,    -6,    71
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      14,    15,    63,    16,     1,    14,    61,    11,    35,   161,
      63,     6,   109,   152,     3,    32,     4,     7,     5,    93,
      12,    94,    38,    52,    18,    53,    12,    40,    54,    19,
     153,   101,    63,    63,    28,    12,   107,    55,    29,    51,
      30,    64,    60,    31,   138,   140,    52,   162,    56,    64,
      39,    54,    57,    58,     6,    67,    44,    45,    68,    41,
      55,    69,    59,    70,    63,    63,    63,    12,   107,    81,
      82,    64,    64,    83,    86,    57,    58,    52,   105,   148,
      71,    72,    54,    12,   116,    59,   120,    21,   159,   135,
      12,    55,   141,    63,   165,    63,   142,   107,   150,   107,
     143,   155,   106,    64,    64,    64,    57,    58,   154,    63,
      22,    23,    24,    25,    63,    63,    59,    52,   107,   156,
      63,    12,    54,    48,   107,    50,   160,   166,    79,    80,
      65,    55,    64,    93,    64,    94,   167,   171,    88,    89,
      90,    91,   108,    20,   100,   101,    57,    58,    64,   104,
      17,     0,   114,    64,    64,   115,    59,   119,     0,    64,
     117,    12,     0,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    67,     0,     0,    68,
       0,     0,    69,    52,    70,     0,   118,    87,    54,     0,
       0,    52,     0,     0,     0,     0,    54,    55,     0,     0,
       0,    71,    72,    67,    12,    55,    68,     0,   136,    69,
       0,    70,    57,    58,     0,   151,   137,     0,     0,    52,
      57,    58,    59,   157,    54,     0,     0,    12,    71,    72,
      59,    12,    52,    55,    84,    12,    85,    54,   169,     0,
      52,    34,     0,    86,   139,    54,    55,     0,    57,    58,
      42,     0,     0,    46,    55,     0,     0,   147,    59,    49,
       0,    57,    58,    12,     0,   149,    66,    52,     0,    57,
      58,    59,    54,    52,     0,    52,    12,     0,    54,    59,
      54,    55,     0,     0,    12,     0,     0,    55,     0,    55,
       0,     0,   158,     0,     0,     0,    57,    58,   163,     0,
     164,     0,    57,    58,    57,    58,    59,     0,    52,     0,
       0,    12,    59,    54,    59,     0,    78,    12,    67,    12,
       0,    68,    55,     0,    69,    33,    70,     0,    67,     0,
       0,    68,     0,   168,    69,     0,    70,    57,    58,    22,
      23,    24,    25,    71,    72,     0,    12,    59,    22,    23,
      24,    25,    12,    71,    72,   112,    12,    92,     0,    93,
       0,    94,    95,    96,    97,     0,    98,    41,     0,    99,
     100,   101,   102,     0,   103,   104,     0,     0,   170,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    92,
       0,    93,   144,    94,    95,    96,    97,     0,    98,     0,
       0,    99,   100,   101,   102,     0,   103,   104,    92,   145,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
      99,   100,   101,   102,     0,   103,   104,    92,   121,    93,
       0,    94,    95,    96,    97,   110,    98,     0,     0,    99,
     100,   101,   102,     0,   103,   104,    92,     0,    93,     0,
      94,    95,    96,    97,   111,    98,     0,     0,    99,   100,
     101,   102,     0,   103,   104,    92,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,    99,   100,   101,
     102,     0,   103,   104,    92,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,    99,   100,   101,   102,
       0,    93,   104,    94,    95,    96,    97,     0,    98,     0,
       0,    99,   100,   101,   102,     0,    93,   104,    94,     0,
      96,    97,     0,    98,     0,     0,    99,   100,   101,     0,
       0,     0,   104
};

static const yytype_int16 yycheck[] =
{
       6,     7,    47,     8,     5,    11,    47,    17,    27,     1,
      55,    32,    78,    10,    45,    21,     0,    38,     3,     9,
      45,    11,    28,     1,     3,     3,    45,    33,     6,     3,
      27,    21,    77,    78,    17,    45,    77,    15,     3,    45,
       3,    47,    47,     3,   110,   111,     1,    39,    26,    55,
      27,     6,    30,    31,    32,    17,    27,    10,    20,    15,
      15,    23,    40,    25,   109,   110,   111,    45,   109,    17,
       3,    77,    78,     3,    17,    30,    31,     1,     3,    29,
      42,    43,     6,    45,     4,    40,    27,    10,   154,     3,
      45,    15,    27,   138,   160,   140,     8,   138,    37,   140,
      27,    29,    26,   109,   110,   111,    30,    31,    15,   154,
      33,    34,    35,    36,   159,   160,    40,     1,   159,    17,
     165,    45,     6,    42,   165,    44,    15,    27,    57,    58,
      49,    15,   138,     9,   140,    11,    18,    27,    67,    68,
      69,    70,    26,    11,    20,    21,    30,    31,   154,    25,
       8,    -1,    81,   159,   160,    84,    40,    86,    -1,   165,
       1,    45,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    17,    -1,    -1,    20,
      -1,    -1,    23,     1,    25,    -1,    27,     1,     6,    -1,
      -1,     1,    -1,    -1,    -1,    -1,     6,    15,    -1,    -1,
      -1,    42,    43,    17,    45,    15,    20,    -1,    26,    23,
      -1,    25,    30,    31,    -1,   144,    26,    -1,    -1,     1,
      30,    31,    40,   152,     6,    -1,    -1,    45,    42,    43,
      40,    45,     1,    15,     8,    45,    10,     6,   167,    -1,
       1,    26,    -1,    17,    26,     6,    15,    -1,    30,    31,
      35,    -1,    -1,    38,    15,    -1,    -1,    26,    40,    44,
      -1,    30,    31,    45,    -1,    26,    51,     1,    -1,    30,
      31,    40,     6,     1,    -1,     1,    45,    -1,     6,    40,
       6,    15,    -1,    -1,    45,    -1,    -1,    15,    -1,    15,
      -1,    -1,    26,    -1,    -1,    -1,    30,    31,    26,    -1,
      26,    -1,    30,    31,    30,    31,    40,    -1,     1,    -1,
      -1,    45,    40,     6,    40,    -1,    15,    45,    17,    45,
      -1,    20,    15,    -1,    23,    10,    25,    -1,    17,    -1,
      -1,    20,    -1,    26,    23,    -1,    25,    30,    31,    33,
      34,    35,    36,    42,    43,    -1,    45,    40,    33,    34,
      35,    36,    45,    42,    43,    44,    45,     7,    -1,     9,
      -1,    11,    12,    13,    14,    -1,    16,    15,    -1,    19,
      20,    21,    22,    -1,    24,    25,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,     7,
      -1,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
      -1,    19,    20,    21,    22,    -1,    24,    25,     7,    27,
       9,    -1,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    25,     7,    27,     9,
      -1,    11,    12,    13,    14,    15,    16,    -1,    -1,    19,
      20,    21,    22,    -1,    24,    25,     7,    -1,     9,    -1,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    -1,    24,    25,     7,    -1,     9,    -1,    11,
      12,    13,    14,    -1,    16,    -1,    -1,    19,    20,    21,
      22,    -1,    24,    25,     7,    -1,     9,    -1,    11,    12,
      13,    14,    -1,    16,    -1,    -1,    19,    20,    21,    22,
      -1,     9,    25,    11,    12,    13,    14,    -1,    16,    -1,
      -1,    19,    20,    21,    22,    -1,     9,    25,    11,    -1,
      13,    14,    -1,    16,    -1,    -1,    19,    20,    21,    -1,
      -1,    -1,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    47,    45,     0,     3,    32,    38,    48,    49,
      53,    17,    45,    50,    64,    64,    49,    53,     3,     3,
      50,    10,    33,    34,    35,    36,    51,    52,    17,     3,
       3,     3,    64,    10,    52,    27,    54,    55,    64,    27,
      64,    15,    52,    56,    27,    10,    52,    57,    56,    52,
      56,    64,     1,     3,     6,    15,    26,    30,    31,    40,
      49,    58,    61,    62,    64,    56,    52,    17,    20,    23,
      25,    42,    43,    62,    64,    65,    58,    59,    15,    65,
      65,    17,     3,     3,     8,    10,    17,     1,    65,    65,
      65,    65,     7,     9,    11,    12,    13,    14,    16,    19,
      20,    21,    22,    24,    25,     3,    26,    58,    26,    59,
      15,    15,    44,    60,    65,    65,     4,     1,    27,    65,
      27,    27,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,     3,    26,    26,    59,    26,
      59,    27,     8,    27,    10,    27,    63,    26,    29,    26,
      37,    65,    10,    27,    15,    29,    17,    65,    26,    59,
      15,     1,    39,    26,    26,    59,    27,    18,    26,    65,
      28,    27
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
#line 53 "gocompiler.y"
    {root=newNode("Program",NULL); 
                                                                                                    addChild(root,(yyvsp[(4) - (4)].node));
                                                                                                     }
    break;

  case 3:
#line 60 "gocompiler.y"
    {(yyval.node)=NULL;}
    break;

  case 4:
#line 61 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node); addBrother((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));}
    break;

  case 5:
#line 62 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node); addBrother((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));}
    break;

  case 6:
#line 63 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node);}
    break;

  case 7:
#line 64 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node);}
    break;

  case 8:
#line 68 "gocompiler.y"
    {(yyval.node)=newNode("VarDecl",NULL);
                                                                                                         addChild((yyval.node),(yyvsp[(2) - (2)].node));   }
    break;

  case 9:
#line 70 "gocompiler.y"
    {(yyval.node)=newNode("VarDecl",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(3) - (5)].node));}
    break;

  case 10:
#line 75 "gocompiler.y"
    {(yyval.node)=(yyvsp[(2) - (2)].node);}
    break;

  case 11:
#line 76 "gocompiler.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);
                                                                                                        addBrother((yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));
                                                                                                        }
    break;

  case 12:
#line 82 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node); addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 13:
#line 83 "gocompiler.y"
    {(yyval.node)=(yyvsp[(2) - (2)].node);}
    break;

  case 14:
#line 87 "gocompiler.y"
    {(yyval.node)=newNode("Int",NULL);}
    break;

  case 15:
#line 88 "gocompiler.y"
    {(yyval.node)=newNode("Float32",NULL);}
    break;

  case 16:
#line 89 "gocompiler.y"
    {(yyval.node)=newNode("Bool",NULL);}
    break;

  case 17:
#line 90 "gocompiler.y"
    {(yyval.node)=newNode("String",NULL);}
    break;

  case 18:
#line 94 "gocompiler.y"
    {(yyval.node)=newNode("FuncDecl",NULL);
                                                                                                        aux= newNode("FuncHeader",NULL);
                                                                                                        addChild((yyval.node),aux);
                                                                                                        addChild(aux,(yyvsp[(2) - (5)].node));
                                                                                                        addBrother((yyvsp[(2) - (5)].node),newNode("FuncParams",NULL));
                                                                                                        addBrother(aux,(yyvsp[(5) - (5)].node));
                                                                                                        

                                                                                                            
                                                                                                        }
    break;

  case 19:
#line 104 "gocompiler.y"
    {(yyval.node)=newNode("FuncDecl",NULL);
                                                                                                        aux= newNode("FuncHeader",NULL);
                                                                                                        addChild((yyval.node),aux);
                                                                                                        addBrother(aux,(yyvsp[(7) - (7)].node));
                                                                                                        addChild(aux,(yyvsp[(2) - (7)].node));
                                                                                                        addBrother((yyvsp[(6) - (7)].node),(yyvsp[(4) - (7)].node));
                                                                                                        addBrother((yyvsp[(2) - (7)].node),(yyvsp[(6) - (7)].node));
                                                                                                         }
    break;

  case 20:
#line 112 "gocompiler.y"
    {(yyval.node)=newNode("FuncDecl",NULL);
                                                                                                        aux= newNode("FuncHeader",NULL);
                                                                                                        addChild((yyval.node),aux);
                                                                                                        addBrother(aux,(yyvsp[(6) - (6)].node));
                                                                                                        addChild(aux,(yyvsp[(2) - (6)].node));
                                                                                                        addBrother((yyvsp[(2) - (6)].node),(yyvsp[(4) - (6)].node));
                                                                                                        
                                                                                                         }
    break;

  case 21:
#line 120 "gocompiler.y"
    {(yyval.node)=newNode("FuncDecl",NULL);
                                                                                                        aux= newNode("FuncHeader",NULL);
                                                                                                        addChild((yyval.node),aux);
                                                                                                        addBrother(aux,(yyvsp[(6) - (6)].node));
                                                                                                        addChild(aux,(yyvsp[(2) - (6)].node));
                                                                                                        addBrother((yyvsp[(2) - (6)].node),(yyvsp[(5) - (6)].node));
                                                                                                        addBrother((yyvsp[(5) - (6)].node),newNode("FuncParams",NULL));
                                                                                                         }
    break;

  case 22:
#line 132 "gocompiler.y"
    {(yyval.node)=newNode("FuncParams",NULL);
                                                                                                         addChild((yyval.node),(yyvsp[(1) - (1)].node));
                                                                                                        }
    break;

  case 23:
#line 138 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (4)].node); addBrother((yyvsp[(1) - (4)].node),(yyvsp[(4) - (4)].node));}
    break;

  case 24:
#line 139 "gocompiler.y"
    {(yyval.node)=(yyvsp[(2) - (2)].node);}
    break;

  case 25:
#line 143 "gocompiler.y"
    {(yyval.node)=newNode("FuncBody",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (3)].node));
                                                                                                        }
    break;

  case 26:
#line 149 "gocompiler.y"
    {(yyvsp[(1) - (2)].node)=(yyvsp[(1) - (2)].node);}
    break;

  case 27:
#line 150 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node); addBrother((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));}
    break;

  case 28:
#line 151 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node); addBrother((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));}
    break;

  case 29:
#line 152 "gocompiler.y"
    {(yyval.node)=NULL;}
    break;

  case 30:
#line 156 "gocompiler.y"
    {(yyval.node) =  newNode("Assign",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 31:
#line 161 "gocompiler.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 32:
#line 162 "gocompiler.y"
    {(yyval.node) =  newNode("If",NULL);addChild((yyval.node),(yyvsp[(2) - (4)].node));addBrother((yyval.node),"Block",NULL);}
    break;

  case 33:
#line 163 "gocompiler.y"
    {(yyval.node) =  newNode("If",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (5)].node));
                                                                                                        aux=newNode("Block",NULL);
                                                                                                        addBrother((yyval.node),aux);
                                                                                                        addChild(aux,(yyvsp[(4) - (5)].node));
                                                                                                        }
    break;

  case 34:
#line 169 "gocompiler.y"
    {;}
    break;

  case 35:
#line 170 "gocompiler.y"
    {;}
    break;

  case 36:
#line 171 "gocompiler.y"
    {;}
    break;

  case 37:
#line 172 "gocompiler.y"
    {;}
    break;

  case 38:
#line 174 "gocompiler.y"
    {;}
    break;

  case 39:
#line 175 "gocompiler.y"
    {;}
    break;

  case 40:
#line 176 "gocompiler.y"
    {;}
    break;

  case 41:
#line 177 "gocompiler.y"
    {;}
    break;

  case 42:
#line 179 "gocompiler.y"
    {(yyval.node) =  newNode("Return",NULL);}
    break;

  case 43:
#line 180 "gocompiler.y"
    {(yyval.node) =  newNode("Return",NULL);addChild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 44:
#line 182 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 45:
#line 183 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 46:
#line 185 "gocompiler.y"
    {(yyval.node) =  newNode("Print",NULL);addChild((yyval.node),(yyvsp[(3) - (4)].node));}
    break;

  case 47:
#line 187 "gocompiler.y"
    {;}
    break;

  case 48:
#line 194 "gocompiler.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 49:
#line 195 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node);}
    break;

  case 50:
#line 199 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 51:
#line 200 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].value);}
    break;

  case 52:
#line 204 "gocompiler.y"
    {(yyval.node)=newNode("ParseArgs",NULL);addChild((yyval.node),(yyvsp[(1) - (11)].node));addBrother((yyvsp[(1) - (11)].node),(yyvsp[(9) - (11)].node));}
    break;

  case 53:
#line 205 "gocompiler.y"
    {(yyval.node)=newNode("ParseArgs",NULL);addChild((yyval.node),(yyvsp[(1) - (8)].node));addBrother((yyvsp[(1) - (8)].node),newNode("Error",NULL));}
    break;

  case 54:
#line 209 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (4)].node);addBrother((yyvsp[(1) - (4)].node),newNode("Error",NULL));}
    break;

  case 55:
#line 210 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node);}
    break;

  case 56:
#line 211 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (4)].node);addBrother((yyvsp[(1) - (4)].node),(yyvsp[(3) - (4)].node));}
    break;

  case 57:
#line 212 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (5)].node);addBrother((yyvsp[(1) - (5)].node),(yyvsp[(3) - (5)].node));addBrother((yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node));}
    break;

  case 58:
#line 216 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (3)].node);addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 59:
#line 217 "gocompiler.y"
    {(yyval.node)=(yyvsp[(2) - (2)].node);}
    break;

  case 60:
#line 221 "gocompiler.y"
    {(yyval.node)=newNode("Id",yylval.value);}
    break;

  case 61:
#line 224 "gocompiler.y"
    {(yyval.node)=newNode("IntLit",(yyvsp[(1) - (1)].value));}
    break;

  case 62:
#line 225 "gocompiler.y"
    {(yyval.node)=newNode("Id",(yyvsp[(1) - (1)].value));}
    break;

  case 63:
#line 226 "gocompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 64:
#line 227 "gocompiler.y"
    {(yyval.node)=newNode("Call",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 65:
#line 229 "gocompiler.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 66:
#line 230 "gocompiler.y"
    {(yyval.node)=newNode("Not",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 67:
#line 232 "gocompiler.y"
    {(yyval.node)=newNode("Minus",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 68:
#line 234 "gocompiler.y"
    {(yyval.node)=newNode("Plus",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 69:
#line 236 "gocompiler.y"
    {(yyval.node) =  newNode("Or",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 70:
#line 239 "gocompiler.y"
    {(yyval.node) =  newNode("And",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 71:
#line 242 "gocompiler.y"
    {(yyval.node) =  newNode("Lt",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 72:
#line 245 "gocompiler.y"
    {(yyval.node) =  newNode("Gt",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 73:
#line 248 "gocompiler.y"
    {(yyval.node) =  newNode("Eq",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 74:
#line 251 "gocompiler.y"
    {(yyval.node) =  newNode("Ne",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 75:
#line 254 "gocompiler.y"
    {(yyval.node) =  newNode("Ne",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 76:
#line 257 "gocompiler.y"
    {(yyval.node) =  newNode("Ge",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 77:
#line 260 "gocompiler.y"
    {(yyval.node) =  newNode("Add",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 78:
#line 263 "gocompiler.y"
    {(yyval.node) =  newNode("Sub",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 79:
#line 266 "gocompiler.y"
    {(yyval.node) =  newNode("Mul",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 80:
#line 269 "gocompiler.y"
    {(yyval.node) =  newNode("Div",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 81:
#line 272 "gocompiler.y"
    {(yyval.node) =  newNode("Mod",NULL);
                                                                                                        addChild((yyval.node),(yyvsp[(1) - (3)].node));
                                                                                                        addBrother((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 82:
#line 275 "gocompiler.y"
    {(yyval.node)=newNode("Error",NULL);syntaxError=1;}
    break;


/* Line 1267 of yacc.c.  */
#line 2132 "y.tab.c"
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


#line 282 "gocompiler.y"




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



