%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
    #include "ast.h"
    
    int yylex(void);
    void yyerror(char *s);
    int yyparse(void);

    node* root=NULL;
    int syntax_error=0;
    int stat_list=0;
    int column;
    int line;
    int lastCol;
    char* straux;
    
    int syntaxError=0;
%}


%union{
    char* value ;
    struct node* node;
    
};

%token SEMICOLON BLANKID PACKAGE RETURN AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ ELSE FOR IF VAR INT FLOAT32 BOOL STRING PARSEINT FUNC CMDARGS PRINT 

%token <value> RESERVED INTLIT REALLIT STRLIT ID 

%type<node> Program Declarations DeclarationsAux VarDeclaration VarSpec VarSpecAux Type FuncDeclaration Parameters ParametersAux VarsAndStatements Statement StatementSEMICOLON StatementExprSTRLIT ParseArgs FuncInvocation FuncInvocationAux Expr

%left COMMA
%right ASSIGN

%left OR 
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left STAR DIV MOD

%right NOT
%left LPAR RPAR LSQ RSQ

%%
Program:
PACKAGE ID SEMICOLON Declarations                                                                  {root=newNode("Program",NULL); 
                                                                                                    addChild(root,$4);
                                                                                                     }
    ;

Declarations:
                                                                                                        {$$=NULL;}
    | DeclarationsAux                                                                                   {$$=$1;}
    ;

DeclarationsAux:
    DeclarationsAux VarDeclaration SEMICOLON                                                            {$$=$1; addBrother($1,$2);}
    | DeclarationsAux FuncDeclaration SEMICOLON                                                         {$$=$1; addBrother($1,$2);}
    | VarDeclaration SEMICOLON                                                                          {$$=$1;}
    | FuncDeclaration SEMICOLON                                                                         {$$=$1;}
    ;

VarDeclaration:
    VAR VarSpec                                                                                         {$$=newNode("VarDecl",NULL);
                                                                                                         addChild($$,$2);   }
    | VAR LPAR VarSpec SEMICOLON RPAR                                                                   {$$=newNode("VarDecl",NULL);
                                                                                                        addChild($$,$3);}
    ;    

VarSpec:
    ID Type                                                                                             {;}  
    | ID VarSpecAux Type                                                                                {;}
    ;

VarSpecAux:
    VarSpecAux COMMA ID                                                                                 {;}
    | COMMA ID                                                                                          {;}
    ; 

Type:
    INT                                                                                                 {$$=newNode("Int");}
    | FLOAT32                                                                                           {$$=newNode("Float32");}
    | BOOL                                                                                              {$$=newNode("Bool");}
    | STRING                                                                                            {$$=newNode("String");}
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
     |                                                                                                  {;}
     ;

Statement:
     ID ASSIGN Expr                                                                                     {;}


     | LBRACE StatementSEMICOLON RBRACE                                                                 {;}
     | IF Expr LBRACE  RBRACE                                                                           {;}
     | IF Expr LBRACE StatementSEMICOLON RBRACE                                                         {;}
     | IF Expr LBRACE  RBRACE ELSE LBRACE RBRACE                                                        {;}
     | IF Expr LBRACE  RBRACE ELSE LBRACE StatementSEMICOLON RBRACE                                     {;}
     | IF Expr LBRACE StatementSEMICOLON RBRACE ELSE LBRACE RBRACE                                      {;}
     | IF Expr LBRACE StatementSEMICOLON RBRACE ELSE LBRACE StatementSEMICOLON RBRACE                   {;}

     | FOR LBRACE RBRACE                                                                                {;}
     | FOR Expr LBRACE RBRACE                                                                           {;}
     | FOR Expr LBRACE StatementSEMICOLON RBRACE                                                        {;}
     | FOR LBRACE StatementSEMICOLON RBRACE                                                             {;}

     | RETURN                                                                                           {;}
     | RETURN Expr                                                                                      {;}

     | FuncInvocation                                                                                   {;}
     | ParseArgs                                                                                        {;}

     | PRINT LPAR StatementExprSTRLIT RPAR                                                              {;}

    | error                                                                                            {;}



     ;

StatementSEMICOLON:
    StatementSEMICOLON Statement SEMICOLON                                                              {;}
    | Statement SEMICOLON                                                                               {;}
    ;

StatementExprSTRLIT:
    Expr                                                                                                {;}
    | STRLIT                                                                                            {;}
    ;

ParseArgs:
    ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                                     {;}
    | ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR                                                  {;}
    ;

FuncInvocation:
    ID LPAR error RPAR                                                                                  {;}
    | ID LPAR RPAR                                                                                      {;}
    | ID LPAR Expr RPAR                                                                                 {;}
    | ID LPAR Expr FuncInvocationAux RPAR                                                               {;}
    ;

FuncInvocationAux:
    FuncInvocationAux COMMA Expr                                                                        {;}
    | COMMA Expr                                                                                        {;}
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
    | LPAR error RPAR                                                                                   {;}
    ;



%%



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


