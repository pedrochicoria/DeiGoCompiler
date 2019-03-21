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
    empty
    | VarDeclaration SEMICOLON
    | FuncDeclaration SEMICOLON
    ;
VarDeclaration:
    VAR VarSpec
    | VAR LPAR VarSpec SEMICOLON RPAR
;
VarSpec:
    ID COMMA ID TYPE
    | ID empty TYPE
;
Type:
    INT
    | FLOAT32
    | BOOL
    | STRING
;
FuncDeclaration:
    FUNC ID LPAR RPAR FuncBody
    | FUNC ID LPAR Parameters RPAR Type FuncBody
    | FUNC ID LPAR Parameters RPAR  FuncBody
    | FUNC ID LPAR RPAR Type FuncBody
    | ε
;
Parameters:
    ID Type empty
    | ID TYPE COMMA ID TYPE
;
FuncBody:
    LBRACE VarsAndStatements RBRACE
;
VarsAndStatements:
     VarsAndStatement SEMICOLON
     | VarsAndStatements VarDeclaration SEMICOLON
     | VarsAndStatements Statement SEMICOLON
;
Statement:
     ID ASSIGN Expr
     | LBRACE empty RBRACE
     | LBRACE Statement SEMICOLON RBRACE
     | FuncInvocation
     | ParseArgs
     | RETURN 
     | RETURN Expr
     | IF Expr LBRACE empty RBRACE 
     | IF Expr LBRACE Statement SEMICOLON RBRACE 
     | IF Expr LBRACE empty RBRACE ELSE LBRACE empty RBRACE
     | IF Expr LBRACE empty RBRACE ELSE LBRACE Statement SEMICOLON RBRACE
     | IF Expr LBRACE Statement SEMICOLON RBRACE ELSE LBRACE Statement SEMICOLON RBRACE
     | IF Expr LBRACE Statement SEMICOLON RBRACE ELSE LBRACE empty RBRACE
     | FOR LBRACE empty RBRACE
     | FOR LBRACE Statement SEMICOLON RBRACE
     | FOR Expr LBRACE Statement SEMICOLON RBRACE
     | FOR Expr LBRACE RBRACE
     | PRINT LPAR Expr RPAR
     | PRINT LPAR STRLIT RPAR
     | error
    ;
ParseArgs:
    ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR
    | ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR
;

FuncInvocation:
    ID LPAR error RPAR
    | ID LPAR RPAR
    | ID LPAR Expr empty RPAR
    | ID LPAR Expr COMMA Expr RPAR
    ;
    
Expr:
    INTLIT
    | REALLIT
    | ID
    | FuncInvocation
    | LPAR Expr RPAR
;

empty: {};

%%