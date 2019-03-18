%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include "y.tab.h"
    
    int yylex(void);
    void yyerror (const char *s);
    int yyparse(void);
    
%}

%token SEMICOLON BLANKID PACKAGE RETURN AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ ELSE FOR IF VAR INT FLOAT32 BOOL STRING PARSEINT FUNC CMDARGS

%token<value> RESERVED INTLIT REALLIT STRLIT ID 

%token<node> Program Declarations VarDeclaration VarSpec Type FuncDeclaration Parameters FuncBody VarsAndStatements Statement ParseArgs FuncInvocation Expr


%%

Program: 
    PACKAGE ID SEMICOLON Declarations
;
Declarations:
;
VarDeclaration:
    VAR VarSpec
    | VAR LPAR VarSpec SEMICOLON RPAR
;
VarSpec:
;
Type:
    INT
    | FLOAT32
    | BOOL
    | STRING
;
FuncDeclaration:
;
Parameters:
;
FuncBody:
;
VarsAndStatements:
;
Statement:
;
ParseArgs:
;
Expr:
;

%%