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
     VAR = 270,
     INT = 271,
     FLOAT32 = 272,
     BOOL = 273,
     STRING = 274,
     PARSEINT = 275,
     FUNC = 276,
     CMDARGS = 277,
     PRINT = 278,
     FOR = 279,
     RESERVED = 280,
     INTLIT = 281,
     REALLIT = 282,
     STRLIT = 283,
     ID = 284,
     ASSIGN = 285,
     OR = 286,
     AND = 287,
     NE = 288,
     EQ = 289,
     GE = 290,
     GT = 291,
     LE = 292,
     LT = 293,
     MINUS = 294,
     PLUS = 295,
     MOD = 296,
     DIV = 297,
     STAR = 298,
     NOT = 299,
     IF = 300
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
#define VAR 270
#define INT 271
#define FLOAT32 272
#define BOOL 273
#define STRING 274
#define PARSEINT 275
#define FUNC 276
#define CMDARGS 277
#define PRINT 278
#define FOR 279
#define RESERVED 280
#define INTLIT 281
#define REALLIT 282
#define STRLIT 283
#define ID 284
#define ASSIGN 285
#define OR 286
#define AND 287
#define NE 288
#define EQ 289
#define GE 290
#define GT 291
#define LE 292
#define LT 293
#define MINUS 294
#define PLUS 295
#define MOD 296
#define DIV 297
#define STAR 298
#define NOT 299
#define IF 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "gocompiler.y"
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

