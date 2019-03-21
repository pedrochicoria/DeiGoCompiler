%union 
{
char * value;
node * node;
}

%type<node> Program Declarations VarDeclaration VarSpec Type FuncDeclaration Parameters FuncBody VarsAndStatements Statement ParseArgs FuncInvocation Expr Expression

%token<value> RESERVED INTLIT REALLIT STRLIT ID 

%%

Program:
     PACKAGE ID SEMICOLON Declarations  {}
    ;
Declarations:
    empty {}
    | VarDeclaration SEMICOLON Declarations         {}          
    | FuncDeclaration SEMICOLON Declarations        {}         
    ;
VarDeclaration:
    VAR VarSpec                                     {}
    | VAR LPAR VarSpec SEMICOLON RPAR               {}
    ;
VarSpec:
    VAR VarSpec                                     {}  
    | VAR LPAR VarSpec SEMICOLON RPAR               {}
    ;
FuncDeclaration:
    FUNC ID LPAR RPAR FuncBody                      {}
    | FUNC ID LPAR Parameters RPAR Type FuncBody    {}
    | FUNC ID LPAR Parameters RPAR  FuncBody        {}
    | FUNC ID LPAR RPAR Type FuncBody               {}
    ;

FuncBody:
    LBRACE VarsAndStatements RBRACE                 {}
;

VarsAndStatements:
     VarsAndStatements SEMICOLON                     {}
     | VarsAndStatements VarDeclaration SEMICOLON   {}
     | VarsAndStatements Statement SEMICOLON        {}
;

Statement:
     ID ASSIGN Expr                                 {}
     | LBRACE empty RBRACE                          {}
     | LBRACE Statement SEMICOLON RBRACE            {}
     | FuncInvocation                               {}
     | ParseArgs                                    {}
     | RETURN                                       {}
     | RETURN Expr                                  {}
     | IF Expr LBRACE empty RBRACE                  {}
     | IF Expr LBRACE Statement SEMICOLON RBRACE                         {}
     | IF Expr LBRACE empty RBRACE ELSE LBRACE empty RBRACE                 {}
     | IF Expr LBRACE empty RBRACE ELSE LBRACE Statement SEMICOLON RBRACE   {}
     | IF Expr LBRACE Statement SEMICOLON RBRACE ELSE LBRACE Statement SEMICOLON RBRACE {}
     | IF Expr LBRACE Statement SEMICOLON RBRACE ELSE LBRACE empty RBRACE   {}
     | FOR LBRACE empty RBRACE  {}
     | FOR LBRACE Statement SEMICOLON RBRACE    {}
     | FOR Expr LBRACE Statement SEMICOLON RBRACE   {}
     | FOR Expr LBRACE RBRACE           {}
     | PRINT LPAR Expr RPAR             {}
     | PRINT LPAR STRLIT RPAR           {}
     | error                            {}
    ;

Type:
    INT     {}
    | FLOAT32  {}
    | BOOL  {}
    | STRING  {}
;

FuncDeclaration:
    FUNC ID LPAR RPAR FuncBody                  {}
    | FUNC ID LPAR Parameters RPAR Type FuncBody {}
    | FUNC ID LPAR Parameters RPAR  FuncBody {}
    | FUNC ID LPAR RPAR Type FuncBody {}
    
;


Parameters:
    ID Type empty           {} 
    | ID Type COMMA ID Type  {}
;
FuncBody:
    LBRACE VarsAndStatements RBRACE  {}
;

ParseArgs:
    ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR    {}
    | ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR    {}
;

FuncInvocation:
    ID LPAR error RPAR      {}
    | ID LPAR RPAR             {}
    | ID LPAR Expr empty RPAR           {}
    | ID LPAR Expr COMMA Expr RPAR      {}
    ;



Expression:
    LPAR error RPAR     {}
    ;


Expr:
    INTLIT          {}
    | REALLIT       {}
    | ID            {}
    | FuncInvocation    {}
    | LPAR Expr RPAR {}
    | NOT Expr {}
    | MINUS Expr {}
    | PLUS Expr {}
    | Expr OR Expr {}
    | Expr AND Expr {}
    | Expr LT Expr {}
    | Expr GT Expr {}
    | Expr EQ Expr {}
    | Expr NE Expr {}
    | Expr LE Expr {}
    | Expr GE Expr {}
    | Expr PLUS Expr {}
    | Expr MINUS Expr {}
    | Expr STAR Expr {}
    | Expr DIV Expr {}
    | Expr MOD Expr {}
    ;
