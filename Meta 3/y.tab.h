/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     COMMA = 262,
     LBRACE = 263,
     LPAR = 264,
     LSQ = 265,
     RBRACE = 266,
     RPAR = 267,
     RSQ = 268,
     ELSE = 269,
     FOR = 270,
     IF = 271,
     VAR = 272,
     INT = 273,
     FLOAT32 = 274,
     BOOL = 275,
     STRING = 276,
     PARSEINT = 277,
     FUNC = 278,
     CMDARGS = 279,
     PRINT = 280,
     RESERVED = 281,
     INTLIT = 282,
     REALLIT = 283,
     STRLIT = 284,
     ID = 285,
     ASSIGN = 286,
     OR = 287,
     AND = 288,
     NE = 289,
     EQ = 290,
     GE = 291,
     GT = 292,
     LE = 293,
     LT = 294,
     MINUS = 295,
     PLUS = 296,
     MOD = 297,
     DIV = 298,
     STAR = 299,
     NOT = 300
   };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define BLANKID 259
#define PACKAGE 260
#define RETURN 261
#define COMMA 262
#define LBRACE 263
#define LPAR 264
#define LSQ 265
#define RBRACE 266
#define RPAR 267
#define RSQ 268
#define ELSE 269
#define FOR 270
#define IF 271
#define VAR 272
#define INT 273
#define FLOAT32 274
#define BOOL 275
#define STRING 276
#define PARSEINT 277
#define FUNC 278
#define CMDARGS 279
#define PRINT 280
#define RESERVED 281
#define INTLIT 282
#define REALLIT 283
#define STRLIT 284
#define ID 285
#define ASSIGN 286
#define OR 287
#define AND 288
#define NE 289
#define EQ 290
#define GE 291
#define GT 292
#define LE 293
#define LT 294
#define MINUS 295
#define PLUS 296
#define MOD 297
#define DIV 298
#define STAR 299
#define NOT 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "gocompiler.y"
{
    char* value ;
    struct node* node;
    
}
/* Line 1529 of yacc.c.  */
#line 145 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

