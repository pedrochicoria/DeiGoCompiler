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
    node* aux=NULL;
    
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

%type<node> Program Declarations  VarDeclaration VarSpec VarSpecAux Type FuncDeclaration Parameters ParametersAux VarsAndStatements Statement StatementSEMICOLON StatementExprSTRLIT ParseArgs FuncInvocation FuncInvocationAux Expr FuncBody  IdAux

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



Declarations:                                                                                           {$$=NULL;}
    | Declarations VarDeclaration SEMICOLON                                                             {$$=$1; addBrother($1,$2);}
    | Declarations FuncDeclaration SEMICOLON                                                            {$$=$1; addBrother($1,$2);}
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
    IdAux Type                                                                                             {$$=$2;}  
    | IdAux VarSpecAux Type                                                                                {$$=$2;
                                                                                                        addBrother($2,$3);
                                                                                                        }
    ;

VarSpecAux:
    VarSpecAux COMMA IdAux                                                                                 {$$=$1; addBrother($1,$3);}
    | COMMA IdAux                                                                                          {$$=$2;}
    ; 

Type:
    INT                                                                                                 {$$=newNode("Int",NULL);}
    | FLOAT32                                                                                           {$$=newNode("Float32",NULL);}
    | BOOL                                                                                              {$$=newNode("Bool",NULL);}
    | STRING                                                                                            {$$=newNode("String",NULL);}
    ;

FuncDeclaration:
    FUNC IdAux LPAR RPAR FuncBody                                                                          {$$=newNode("FuncDecl",NULL);
                                                                                                        aux= newNode("FuncHeader",NULL);
                                                                                                        addChild($$,aux);
                                                                                                        addChild(aux,$2);
                                                                                                        addBrother($2,newNode("FuncParams",NULL));
                                                                                                        addBrother(aux,$5);
                                                                                                        

                                                                                                            
                                                                                                        }
    | FUNC IdAux LPAR Parameters RPAR Type FuncBody                                                        {$$=newNode("FuncDecl",NULL);
                                                                                                        aux= newNode("FuncHeader",NULL);
                                                                                                        addChild($$,aux);
                                                                                                        addBrother(aux,$7);
                                                                                                        addChild(aux,$2);
                                                                                                        addBrother($6,$4);
                                                                                                        addBrother($2,$6);
                                                                                                         }
    | FUNC IdAux LPAR Parameters RPAR  FuncBody                                                            {$$=newNode("FuncDecl",NULL);
                                                                                                        aux= newNode("FuncHeader",NULL);
                                                                                                        addChild($$,aux);
                                                                                                        addBrother(aux,$6);
                                                                                                        addChild(aux,$2);
                                                                                                        addBrother($2,$4);
                                                                                                        
                                                                                                         }
    | FUNC IdAux LPAR RPAR Type FuncBody                                                                   {$$=newNode("FuncDecl",NULL);
                                                                                                        aux= newNode("FuncHeader",NULL);
                                                                                                        addChild($$,aux);
                                                                                                        addBrother(aux,$6);
                                                                                                        addChild(aux,$2);
                                                                                                        addBrother($2,$5);
                                                                                                        addBrother($5,newNode("FuncParams",NULL));
                                                                                                         }

    ;

Parameters:
    ParametersAux                                                                                       {$$=newNode("FuncParams",NULL);
                                                                                                         addChild($$,$1);
                                                                                                        } 
    ;

ParametersAux:
    ParametersAux COMMA IdAux Type                                                                         {$$=$1; addBrother($1,$4);}
    |IdAux Type                                                                                            {$$=$2;}
    ;

FuncBody:
    LBRACE VarsAndStatements RBRACE                                                                     {$$=newNode("FuncBody",NULL);
                                                                                                        addChild($$,$2);
                                                                                                        }
    ;

VarsAndStatements:
     VarsAndStatements SEMICOLON                                                                        {$1=$1;}
     | VarsAndStatements VarDeclaration SEMICOLON                                                       {$$=$1; addBrother($1,$2);}
     | VarsAndStatements Statement SEMICOLON                                                            {$$=$1; addBrother($1,$2);;}
     |                                                                                                  {$$=NULL;}
     ;

Statement:
     IdAux ASSIGN Expr                                                                                     {;}


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

    | error                                                                                             {;}



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
    IdAux COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                                     {;}
    | IdAux COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR                                                  {;}
    ;

FuncInvocation:
    IdAux LPAR error RPAR                                                                                  {;}
    | IdAux LPAR RPAR                                                                                      {;}
    | IdAux LPAR Expr RPAR                                                                                 {;}
    | IdAux LPAR Expr FuncInvocationAux RPAR                                                               {;}
    ;

FuncInvocationAux:
    FuncInvocationAux COMMA Expr                                                                        {;}
    | COMMA Expr                                                                                        {;}
;

IdAux:
    ID                                                                                                  {$$=newNode("Id",yylval.value);}
;
Expr:
    INTLIT                                                                                              {$$=newNode("IntLit",$1);}
    | REALLIT                                                                                           {$$=newNode("Id",$1);}
    | ID                                                                                                {$$=newNode("Id",$1);}
    | FuncInvocation                                                                                    {$$=newNode("Call",NULL);
                                                                                                        addChild($$,newNode("Id",$1));}
    | LPAR Expr RPAR                                                                                    {$$=$2;}
    | NOT Expr                                                                                          {$$=newNode("Not",NULL);
                                                                                                        addChild($$,$2);}
    | MINUS Expr                                                                                        {$$=newNode("Minus",NULL);
                                                                                                        addChild($$,$2);}
    | PLUS Expr                                                                                         {$$=newNode("Plus",NULL);
                                                                                                        addChild($$,$2);}
    | Expr OR Expr                                                                                      {$$ =  newNode("Or",NULL);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr AND Expr                                                                                     {$$ =  newNode("And",NULL);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr LT Expr                                                                                      {$$ =  newNode("Lt",NULL);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr GT Expr                                                                                      {$$ =  newNode("Gt",NULL);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr EQ Expr                                                                                      {$$ =  newNode("Eq",NULL);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr NE Expr                                                                                      {$$ =  newNode("Ne",NULL);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr LE Expr                                                                                      {$$ =  newNode("Ne",NULL);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr GE Expr                                                                                      {$$ =  newNode("Ge",NULL);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr PLUS Expr                                                                                    {$$ =  newNode("Add",NULL);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr MINUS Expr                                                                                   {$$ =  newNode("Sub",NULL);
                                                                                            addChild($$,$1);
                                                                                            addBrother($1,$3);}
    | Expr STAR Expr                                                                                    {$$ =  newNode("Mul",NULL);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr DIV Expr                                                                                     {$$ =  newNode("Div",NULL);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr MOD Expr                                                                                     {$$ =  newNode("Mod",NULL);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | LPAR error RPAR                                                                                   {$$=newNode("Error",NULL);syntaxError=1;}
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


