%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
    #include "ast.h"
    
    int yylex(void);
    void yyerror(char *s);
    int yyparse(void);

    node root = NULL;
    node aux = NULL;
    int syntax_error=0;
    int stat_list=0;
    
%}


%union 
{
char * value;
struct nodetree *node;
}

%token SEMICOLON BLANKID PACKAGE RETURN AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ ELSE FOR IF VAR INT FLOAT32 BOOL STRING PARSEINT FUNC CMDARGS PRINT 

%token <value> RESERVED INTLIT REALLIT STRLIT ID 

%type<node> Program Declarations VarDeclaration VarSpec Type FuncDeclaration Parameters ParametersAux VarsAndStatements Statement ParseArgs FuncInvocation Expr Expression 

%left COMMA
%right ASSIGN

%left OR 
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD

%right NOT
%left LPAR RPAR LSQ RSQ

%%
Program:
     PACKAGE ID SEMICOLON Declarations                                                                  {;}
    ;

Declarations:
    empty                                                                                               {;}
    | Declarations VarDeclaration SEMICOLON                                                             {;}
    | Declarations FuncDeclaration SEMICOLON                                                            {;}
    | VarDeclaration SEMICOLON                                                                          {;}          
    | FuncDeclaration SEMICOLON                                                                         {;}         
    ;


VarDeclaration:
    VAR VarSpec                                                                                         {;}
    | VAR LPAR VarSpec SEMICOLON RPAR                                                                   {;}
    ;    

VarSpec:
    VAR VarSpec                                                                                         {;}  
    | VAR LPAR VarSpec SEMICOLON RPAR                                                                   {;}
    ;


Type:
    INT                                                                                                 {;}
    | FLOAT32                                                                                           {;}
    | BOOL                                                                                              {;}
    | STRING                                                                                            {;}
    ;

FuncDeclaration:
    FUNC ID LPAR RPAR FuncBody                                                                          {;}
    | FUNC ID LPAR Parameters RPAR Type FuncBody                                                        {;}
    | FUNC ID LPAR Parameters RPAR  FuncBody                                                            {;}
    | FUNC ID LPAR RPAR Type FuncBody                                                                   {;}
    ;

Parameters:
    ParametersAux                                                                                       {;} 
    ;

ParametersAux:
    ParametersAux COMMA ID Type                                                                         {;}
    |ID Type                                                                                            {;}
    ;

FuncBody:
    LBRACE VarsAndStatements RBRACE                                                                     {;}
    ;

VarsAndStatements:
     VarsAndStatements SEMICOLON                                                                        {;}
     | VarsAndStatements VarDeclaration SEMICOLON                                                       {;}
     | VarsAndStatements Statement SEMICOLON                                                            {;}
     ;

Statement:
     ID ASSIGN Expr                                                                                     {;}
     | LBRACE empty RBRACE                                                                              {;}
     | LBRACE Statement SEMICOLON RBRACE                                                                {;}
     | FuncInvocation                                                                                   {;}
     | ParseArgs                                                                                        {;}
     | RETURN                                                                                           {;}
     | RETURN Expr                                                                                      {;}
     | IF Expr LBRACE empty RBRACE                                                                      {;}
     | IF Expr LBRACE Statement SEMICOLON RBRACE                                                        {;}
     | IF Expr LBRACE empty RBRACE ELSE LBRACE empty RBRACE                                             {;}
     | IF Expr LBRACE empty RBRACE ELSE LBRACE Statement SEMICOLON RBRACE                               {;}
     | IF Expr LBRACE Statement SEMICOLON RBRACE ELSE LBRACE Statement SEMICOLON RBRACE                 {;}
     | IF Expr LBRACE Statement SEMICOLON RBRACE ELSE LBRACE empty RBRACE                               {;}
     | FOR LBRACE empty RBRACE                                                                          {;}
     | FOR LBRACE Statement SEMICOLON RBRACE                                                            {;}
     | FOR Expr LBRACE Statement SEMICOLON RBRACE                                                       {;}
     | FOR Expr LBRACE RBRACE                                                                           {;}
     | PRINT LPAR Expr RPAR                                                                             {;}
     | PRINT LPAR STRLIT RPAR                                                                           {;}
     | error                                                                                            {;}
     ;

ParseArgs:
    ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                                     {;}
    | ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR                                                  {;}
    ;

FuncInvocation:
    ID LPAR error RPAR                                                                                  {;}
    | ID LPAR RPAR                                                                                      {;}
    | ID LPAR Expr empty RPAR                                                                           {;}
    | ID LPAR Expr COMMA Expr RPAR                                                                      {;}
    ;

Expr:
    INTLIT                                                                                              {;}
    | REALLIT                                                                                           {;}
    | ID                                                                                                {;}
    | FuncInvocation                                                                                    {;}
    | LPAR Expr RPAR                                                                                    {;}
    | NOT Expr                                                                                          {;}
    | MINUS Expr                                                                                        {;}
    | PLUS Expr                                                                                         {;}
    | Expr OR Expr                                                                                      {;}
    | Expr AND Expr                                                                                     {;}
    | Expr LT Expr                                                                                      {;}
    | Expr GT Expr                                                                                      {;}
    | Expr EQ Expr                                                                                      {;}
    | Expr NE Expr                                                                                      {;}
    | Expr LE Expr                                                                                      {;}
    | Expr GE Expr                                                                                      {;}
    | Expr PLUS Expr                                                                                    {;}
    | Expr MINUS Expr                                                                                   {;}
    | Expr STAR Expr                                                                                    {;}
    | Expr DIV Expr                                                                                     {;}
    | Expr MOD Expr                                                                                     {;}
    ;


Expression:
    LPAR error RPAR                                                                                     {;}
    ;

empty:                                                                                                  {;}
;
%%






