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
    node* aux2=NULL;
    
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

%type<node> Program Declarations DeclarationsAux VarDeclaration VarSpec VarSpecAux Type FuncDeclaration Parameters ParametersAux VarsAndStatements Statement StatementSEMICOLON StatementExprSTRLIT ParseArgs FuncInvocation FuncInvocationAux Expr FuncBody  IdAux

%left COMMA
%right ASSIGN

%left OR 
%left AND
%left LT LE GT GE EQ NE
%left PLUS MINUS
%left STAR DIV MOD

%right NOT
%left LPAR RPAR LSQ RSQ

%nonassoc ELSE IF
%%
Program:
PACKAGE ID SEMICOLON Declarations                                                                  {root=newNode("Program",NULL,line,column); 
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
    VAR VarSpec                                                                                         {$$=$2;  }
    | VAR LPAR VarSpec SEMICOLON RPAR                                                                   {$$=$3;}
    ;    

VarSpec:
    IdAux Type                                                                                             {$$=newNode("VarDecl",NULL,line,column);
                                                                                                            addChild($$,$2);
                                                                                                            addBrother($2,$1);
                                                                                                            }  
    | IdAux VarSpecAux Type                                                                                {$$=newNode("VarDecl",NULL,line,column);
                                                                                                            addChild($$,$3);
                                                                                                            addBrother($3,$1);
                                                                                                            addBrother($$,$2);
                                                                                                            aux2=$$->brother;
                                                                                                            while(aux2!=NULL&&strcmp(aux2->child->type,"faketype")==0){
                                                                                                        
                                                                                                                strcpy(aux2->child->type,$3->type);
                                                                                                                //aux2->type=$3->type;
                                                                                                                aux2=aux2->brother;
                                                                                                            }
                                                                                                            }  
    ;

VarSpecAux:
    COMMA IdAux VarSpecAux                                                                                  {$$=newNode("VarDecl",NULL,line,column);
                                                                                                            aux=newNode("faketype",NULL,line,column);
                                                                                                            addBrother($$,$3);
                                                                                                            addChild($$,aux);
                                                                                                            addBrother(aux,$2);}
    | COMMA IdAux                                                                                          {$$=newNode("VarDecl",NULL,line,column);
                                                                                                            aux=newNode("faketype",NULL,line,column);
                                                                                                            addChild($$,aux);
                                                                                                            addBrother(aux,$2);}
    ;

Type:
    INT                                                                                                 {$$=newNode("Int",NULL,line,column);}
    | FLOAT32                                                                                           {$$=newNode("Float32",NULL,line,column);}
    | BOOL                                                                                              {$$=newNode("Bool",NULL,line,column);}
    | STRING                                                                                            {$$=newNode("String",NULL,line,column);}
    ;

FuncDeclaration:
    FUNC IdAux LPAR RPAR FuncBody                                                                          {$$=newNode("FuncDecl",NULL,line,column);
                                                                                                        aux= newNode("FuncHeader",NULL,line,column);
                                                                                                        addChild($$,aux);
                                                                                                        addChild(aux,$2);
                                                                                                        addBrother($2,newNode("FuncParams",NULL,line,column));
                                                                                                        addBrother(aux,$5);
                                                                                                        

                                                                                                            
                                                                                                        }
    | FUNC IdAux LPAR Parameters RPAR Type FuncBody                                                        {$$=newNode("FuncDecl",NULL,line,column);
                                                                                                        aux= newNode("FuncHeader",NULL,line,column);
                                                                                                        addChild($$,aux);
                                                                                                        addBrother(aux,$7);
                                                                                                        addChild(aux,$2);
                                                                                                        addBrother($6,$4);
                                                                                                        addBrother($2,$6);
                                                                                                         }
    | FUNC IdAux LPAR Parameters RPAR  FuncBody                                                            {$$=newNode("FuncDecl",NULL,line,column);
                                                                                                        aux= newNode("FuncHeader",NULL,line,column);
                                                                                                        addChild($$,aux);
                                                                                                        addBrother(aux,$6);
                                                                                                        addChild(aux,$2);
                                                                                                        addBrother($2,$4);
                                                                                                        
                                                                                                         }
    | FUNC IdAux LPAR RPAR Type FuncBody                                                                   {$$=newNode("FuncDecl",NULL,line,column);
                                                                                                        aux= newNode("FuncHeader",NULL,line,column);
                                                                                                        addChild($$,aux);
                                                                                                        addBrother(aux,$6);
                                                                                                        addChild(aux,$2);
                                                                                                        addBrother($2,$5);
                                                                                                        addBrother($5,newNode("FuncParams",NULL,line,column));
                                                                                                         }

    ;

Parameters:
    ParametersAux                                                                                       {$$=newNode("FuncParams",NULL,line,column);
                                                                                                         addChild($$,$1);
                                                                                                        } 
    ;

ParametersAux:
    IdAux Type COMMA ParametersAux                                                                      {$$=newNode("ParamDecl",NULL,line,column); 
                                                                                                        addChild($$,$2);
                                                                                                        addBrother($2,$1);
                                                                                                        addBrother($$,$4);
                                                                                                        }
    |IdAux Type                                                                                         {$$=newNode("ParamDecl",NULL,line,column); 
                                                                                                        addChild($$,$2);
                                                                                                        addBrother($2,$1);
                                                                                                        }
    ;

FuncBody:
    LBRACE VarsAndStatements RBRACE                                                                     {$$=newNode("FuncBody",NULL,line,column);
                                                                                                        addChild($$,$2);
                                                                                                        }
    ;

VarsAndStatements:
     VarsAndStatements SEMICOLON                                                                        {$1=$1;}
     | VarsAndStatements VarDeclaration SEMICOLON                                                       {$$=$1; addBrother($1,$2);}
     | VarsAndStatements Statement SEMICOLON                                                            {$$=$1; addBrother($1,$2);}
     |                                                                                                  {$$=newNode("NULL",NULL,line,column);}
     ;

Statement:
    
     IdAux ASSIGN Expr                                                                                  {$$ =  newNode("Assign",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}

     | LBRACE  RBRACE                                                                                   {$$=newNode("NULL",NULL,line,column);}
     | LBRACE StatementSEMICOLON RBRACE                                                                 {aux2=$2;
                                                                                                        int numStatements=0;
                                                                                                        while(aux2!=NULL){
                                                                                                            if(strcmp(aux2->type,"NULL")!=0){
                                                                                                                numStatements++;
                                                                                                            }
                                                                                                            aux2=aux2->brother;
                                                                                                        }
                                                                                                        if(numStatements>=2){
                                                                                                            $$=newNode("Block",NULL,line,column);
                                                                                                            addChild($$,$2);
                                                                                                        }
                                                                                                        else{
                                                                                                            $$=$2;
                                                                                                        }
                                                                                                        }
     | IF Expr LBRACE  RBRACE                                                                           {$$ =  newNode("If",NULL,line,column);
                                                                                                        addChild($$,$2);
                                                                                                        aux=newNode("Block",NULL,line,column);
                                                                                                        addBrother($2,aux);
                                                                                                        addBrother(aux,newNode("Block",NULL,line,column));
                                                                                                        }
     | IF Expr LBRACE StatementSEMICOLON RBRACE                                                         {$$ =  newNode("If",NULL,line,column);
                                                                                                        addChild($$,$2);
                                                                                                        aux=newNode("Block",NULL,line,column);
                                                                                                        addBrother($2,aux);
                                                                                                        addChild(aux,$4);
                                                                                                        addBrother(aux,newNode("Block",NULL,line,column));
                                                                                                        }
     | IF Expr LBRACE  RBRACE ELSE LBRACE RBRACE                                                        {$$ =  newNode("If",NULL,line,column);
                                                                                                        addChild($$,$2);
                                                                                                        aux=newNode("Block",NULL,line,column);
                                                                                                        addBrother($2,aux);
                                                                                                        addBrother(aux,newNode("Block",NULL,line,column));}

     | IF Expr LBRACE  RBRACE ELSE LBRACE StatementSEMICOLON RBRACE                                     {$$ =  newNode("If",NULL,line,column);
                                                                                                        addChild($$,$2);
                                                                                                        aux=newNode("Block",NULL,line,column);
                                                                                                        aux2=newNode("Block",NULL,line,column);
                                                                                                        addBrother($2,aux);
                                                                                                        addBrother(aux,aux2);
                                                                                                        addChild(aux2,$7);}
     | IF Expr LBRACE StatementSEMICOLON RBRACE ELSE LBRACE RBRACE                                      {$$ =  newNode("If",NULL,line,column);
                                                                                                        addChild($$,$2);
                                                                                                        aux=newNode("Block",NULL,line,column);
                                                                                                        addBrother($2,aux);
                                                                                                        addChild(aux,$4);
                                                                                                        addBrother(aux,newNode("Block",NULL,line,column));}
     | IF Expr LBRACE StatementSEMICOLON RBRACE ELSE LBRACE StatementSEMICOLON RBRACE                   {$$ =  newNode("If",NULL,line,column);
                                                                                                        addChild($$,$2);
                                                                                                        aux=newNode("Block",NULL,line,column);
                                                                                                        aux2=newNode("Block",NULL,line,column);
                                                                                                        addBrother($2,aux);
                                                                                                        addChild(aux,$4);
                                                                                                        addBrother(aux,aux2);
                                                                                                        addChild(aux2,$8);
                                                                                                        }

     | FOR LBRACE RBRACE                                                                                {$$ =  newNode("For",NULL,line,column);
                                                                                                        addChild($$,newNode("Block",NULL,line,column));
                                                                                                        }
     | FOR Expr LBRACE RBRACE                                                                           {$$ =  newNode("For",NULL,line,column);
                                                                                                        addChild($$,$2);
                                                                                                        addBrother($2,newNode("Block",NULL,line,column));}
     | FOR Expr LBRACE StatementSEMICOLON RBRACE                                                        {$$ =  newNode("For",NULL,line,column);
                                                                                                        addChild($$,$2);
                                                                                                        aux=newNode("Block",NULL,line,column);
                                                                                                        addBrother($2,aux);
                                                                                                        addChild(aux,$4);
                                                                                                        }
     | FOR LBRACE StatementSEMICOLON RBRACE                                                             {$$ =  newNode("For",NULL,line,column);
                                                                                                        aux=newNode("Block",NULL,line,column);
                                                                                                        addChild($$,aux);
                                                                                                        addChild(aux,$3);
                                                                                                        }

     | RETURN                                                                                           {$$ =  newNode("Return",NULL,line,column);}
     | RETURN Expr                                                                                      {$$ =  newNode("Return",NULL,line,column);addChild($$,$2);}

     | FuncInvocation                                                                                   {$$=newNode("Call",NULL,line,column);addChild($$,$1);}
     | ParseArgs                                                                                        {$$=$1;}

     | PRINT LPAR StatementExprSTRLIT RPAR                                                              {$$ =  newNode("Print",NULL,line,column);addChild($$,$3);}

    | error                                                                                             {$$=newNode("Error",NULL,line,column);syntaxError=1;}



     ;

StatementSEMICOLON:
    StatementSEMICOLON Statement SEMICOLON                                                              {$$=$1;addBrother($1,$2);}
    | Statement SEMICOLON                                                                               {$$=$1;}
    ;

StatementExprSTRLIT:
    Expr                                                                                                {$$=$1;}
    | STRLIT                                                                                            {$$=newNode("StrLit",$1,line,column);}
    ;

ParseArgs:
    IdAux COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                                     {$$=newNode("ParseArgs",NULL,line,column);addChild($$,$1);addBrother($1,$9);}
    | IdAux COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR                                                  {$$=newNode("ParseArgs",NULL,line,column);addChild($$,$1);addBrother($1,newNode("Error",NULL,line,column));syntaxError=1;}
    ;

FuncInvocation:
    IdAux LPAR error RPAR                                                                                  {$$=$1;addBrother($1,newNode("Error",NULL,line,column));syntaxError=1;}
    | IdAux LPAR RPAR                                                                                      {$$=$1;}
    | IdAux LPAR Expr RPAR                                                                                 {$$=$1;addBrother($1,$3);}
    | IdAux LPAR Expr FuncInvocationAux RPAR                                                               {$$=$1;addBrother($1,$3);addBrother($3,$4);}
    ;

FuncInvocationAux:
    FuncInvocationAux COMMA Expr                                                                        {$$=$1;addBrother($1,$3);}
    | COMMA Expr                                                                                        {$$=$2;}
;

IdAux:
    ID                                                                                                  {$$=newNode("Id",yylval.value,line,column);}
;
Expr:
    INTLIT                                                                                              {$$=newNode("IntLit",$1,line,column);}
    | REALLIT                                                                                           {$$=newNode("RealLit",$1,line,column);}
    | IdAux                                                                                               {$$=$1;}
    | FuncInvocation                                                                                    {$$=newNode("Call",NULL,line,column);
                                                                                                        addChild($$,$1);}
    | LPAR Expr RPAR                                                                                    {$$=$2;}
    | NOT Expr                                                                                          {$$=newNode("Not",NULL,line,column);
                                                                                                        addChild($$,$2);}
    | MINUS Expr          %prec NOT                                                                    {$$=newNode("Minus",NULL,line,column);
                                                                                                        addChild($$,$2);}
    | PLUS Expr           %prec NOT                                                                            {$$=newNode("Plus",NULL,line,column);
                                                                                                        addChild($$,$2);}
    | Expr OR Expr                                                                                      {$$ =  newNode("Or",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr AND Expr                                                                                     {$$ =  newNode("And",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr LT Expr                                                                                      {$$ =  newNode("Lt",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr GT Expr                                                                                      {$$ =  newNode("Gt",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr EQ Expr                                                                                      {$$ =  newNode("Eq",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr NE Expr                                                                                      {$$ =  newNode("Ne",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr LE Expr                                                                                      {$$ =  newNode("Le",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr GE Expr                                                                                      {$$ =  newNode("Ge",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr PLUS Expr                                                                                    {$$ =  newNode("Add",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr MINUS Expr                                                                                   {$$ =  newNode("Sub",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr STAR Expr                                                                                    {$$ =  newNode("Mul",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr DIV Expr                                                                                     {$$ =  newNode("Div",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | Expr MOD Expr                                                                                     {$$ =  newNode("Mod",NULL,line,column);
                                                                                                        addChild($$,$1);
                                                                                                        addBrother($1,$3);}
    | LPAR  error RPAR                                                                                   {$$=newNode("Error",NULL,line,column);syntaxError=1;}
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


