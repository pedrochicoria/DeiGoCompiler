
%{
    //Joao Mendes 2015233148
    //Pedro Chicoria 2015262771
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"

    #include "codegen.h"
    #include <unistd.h>


    extern int line;
    extern int column;
    int line_begin=1;
    int column_begin=1;
    int print=0;
    char STRLITERALAux[1024];
    char* idaux;
    int invalid_escape;
    int missing_semicolon=0;
    int parse=0;
    int yyparse(void);
    int lastCol=0;
    char* straux;

    extern int syntaxError;
    extern int semanticError;
    extern node* root;
%}

%option nounput 
%option noinput

%x STRLITERAL
%x MULTILINECOMENT
%x ONELINECOMENT


NUMBER  [0-9]+
EXPOENTS ("e"|"E")("+"|"-")?{NUMBER}

ID ([a-z]|[A-Z]|"_")({NUMBER}|[a-z]|[A-Z]|"_")*
INTLIT {NUMBER}|(0(x|X)([A-F]|[a-f]|[0-9])+)
REALLIT  {NUMBER}"."{NUMBER}?{EXPOENTS}?|"."{NUMBER}({EXPOENTS})?|{NUMBER}{EXPOENTS}


ESCAPE \\f|\\n|\\r|\\t|\\\\|(\\\")
RESERVED "++"|"--"|"break"|"case"|"chan"|"const"|"continue"|"default"|"defer"|"fallthrough"|"func"|"go"|"goto"|"import"|"interface"|"map"|"range"|"select"|"struct"|"switch"|"type"
NEWLINE             "\n"|"\r"|"\r\n"
SPACES              "\t"|" "|"\f"


SEMICOLON       ";" 
BLANKID         "_"
PACKAGE         "package"
RETURN          "return"
AND             "&&"
ASSIGN          "="
STAR            "*"
COMMA           ","
DIV             "/"
EQ              "=="
GE              ">="
GT              ">" 
LBRACE          "{"
LE              "<=" 
LPAR            "("
LSQ             "["
LT              "<" 
MINUS           "-" 
MOD             "%"
NE              "!="
NOT             "!"
OR              "||"
PLUS            "+"
RBRACE          "}"
RPAR            ")"
RSQ             "]"
ELSE            "else"
FOR             "for"
IF              "if"
VAR             "var"
INT             "int"
FLOAT32         "float32"
BOOL            "bool"
STRING          "string"
PRINT           "fmt.Println"
PARSEINT        "strconv.Atoi"
FUNC            "func"
CMDARGS         "os.Args"





%%

{SPACES}    {column+=yyleng;straux=yytext;}
{NEWLINE}    {  if(missing_semicolon==1){

                    lastCol=column;
                    line++;column=1;missing_semicolon=0;
                    if(print==1) {
                    printf("SEMICOLON\n");
                        
                    }
                    if(parse == 1){straux="";yylval.value = (char*) strdup(yytext);return SEMICOLON;}
                    
                    // carriage return - representa o fim de uma linha e deixa o cursor no inicio dessa mesma linha ,line feed - move o cursor para a proxima linha, end of line - combinacao dos dois
                }else{
                    line++;column=1;
                }
                
                } 
                
                            
{SEMICOLON}     {if(print==1) printf("SEMICOLON\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return SEMICOLON;}}
{BLANKID}       {if(print==1) printf("BLANKID\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return BLANKID;}}
{PACKAGE}       {if(print==1) printf("PACKAGE\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return PACKAGE;}}

{AND}           {if(print==1) printf("AND\n");column+=yyleng;missing_semicolon=0; if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return AND;}}
{ASSIGN}        {if(print==1) printf("ASSIGN\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return ASSIGN;}}
{STAR}          {if(print==1) printf("STAR\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return STAR;}}
{COMMA}         {if(print==1) printf("COMMA\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return COMMA;}}
{DIV}           {if(print==1) printf("DIV\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return DIV;}}
{MINUS}			{if(print==1) printf("MINUS\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return MINUS;}}
{PLUS}			{if(print==1) printf("PLUS\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return PLUS;}}
{NOT}		    {if(print==1) printf("NOT\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return NOT;}}
{OR}			{if(print==1) printf("OR\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return OR;}}
{MOD}		    {if(print==1) printf("MOD\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return MOD;}}

{EQ}            {if(print==1) printf("EQ\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return EQ;}}
{GE}            {if(print==1) printf("GE\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return GE;}}
{GT}            {if(print==1) printf("GT\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return GT;}}
{LE}            {if(print==1) printf("LE\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return LE;}}
{LT}            {if(print==1) printf("LT\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return LT;}}
{NE}			{if(print==1) printf("NE\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return NE;}}

{LBRACE}        {if(print==1) printf("LBRACE\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return LBRACE;}}
{LPAR}          {if(print==1) printf("LPAR\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return LPAR;}}
{LSQ}           {if(print==1) printf("LSQ\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return LSQ;}}


{FOR}			            {if(print==1) printf("FOR\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return FOR;}}
{IF}			            {if(print==1) printf("IF\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return IF;}}

{PARSEINT}                  {if(print==1) printf("PARSEINT\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return PARSEINT;}}
{RETURN}                        {if(print==1) printf("RETURN\n");column+=yyleng;missing_semicolon=1;if(parse == 1){straux=yytext;yylval.node = newNode("NULL",NULL,line,column-strlen(yytext));return RETURN;}}

{RBRACE}                    {if(print==1) printf("RBRACE\n");column+=yyleng;missing_semicolon=1;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return RBRACE;}}
{RPAR}			            {if(print==1) printf("RPAR\n");column+=yyleng;missing_semicolon=1;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return RPAR;}}                            
{RSQ}                       {if(print==1) printf("RSQ\n");column+=yyleng;missing_semicolon=1;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return RSQ;}}
{ELSE}			            {if(print==1) printf("ELSE\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return ELSE;}}
{VAR}			            {if(print==1) printf("VAR\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return VAR;}}
{INT}			            {if(print==1) printf("INT\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return INT;}}
{FLOAT32}		            {if(print==1) printf("FLOAT32\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return FLOAT32;}}
{BOOL}			            {if(print==1) printf("BOOL\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return BOOL;}}
{STRING}		            {if(print==1) printf("STRING\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return STRING;}}
{PRINT}                     {if(print==1) printf("PRINT\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return PRINT;}}
{FUNC}			            {if(print==1) printf("FUNC\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return FUNC;}}
{CMDARGS}                   {if(print==1) printf("CMDARGS\n");column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return CMDARGS;}}
{RESERVED}                  {if(print==1) printf("RESERVED(%s)\n",yytext);column+=yyleng;missing_semicolon=0;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return RESERVED;}}
{REALLIT}                       {if(print==1) printf("REALLIT(%s)\n",yytext);column+=yyleng;missing_semicolon=1;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return REALLIT;}}
{INTLIT}                        {if(print==1) printf("INTLIT(%s)\n",yytext);column+=yyleng;missing_semicolon=1;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return INTLIT;}}

{ID}                            {if(print==1) printf("ID(%s)\n",yytext);column+=yyleng;missing_semicolon=1;if(parse == 1){straux=yytext;yylval.value = (char*) strdup(yytext);return ID;}}





\"          {strcpy(STRLITERALAux,"\0"); // apaga o buffer caso contrario o que la estava pode ser acedido por outros STRLITERALs
            BEGIN STRLITERAL;
            strcat(STRLITERALAux,yytext);
            invalid_escape=0;
            line_begin=line;
            column_begin=column;
            column+=yyleng;
            }


<STRLITERAL>{NEWLINE}   {
                    missing_semicolon=0;
                    printf("Line %d, column %d: unterminated string literal\n", line_begin, column_begin);
                    line++;column=1;
                    strcpy(STRLITERALAux,"\0");
                    BEGIN 0; // volta ao estado inicial 
                    }


<STRLITERAL>{ESCAPE}    {column+=yyleng;strcat(STRLITERALAux,yytext);}

<STRLITERAL>(\\.)|(\\)         {
                            invalid_escape=1;missing_semicolon=0;
                            printf("Line %d, column %d: invalid escape sequence (%s)\n", line, column, yytext);
                            column+=yyleng;
                            strcpy(STRLITERALAux,"\0");

                            }

<STRLITERAL><<EOF>>     {
                    column+=yyleng;
                    printf("Line %d, column %d: unterminated string literal\n", line_begin, column_begin);
                    yyterminate();
                    strcpy(STRLITERALAux,"\0");
                    BEGIN 0; // volta ao estado inicial 
                    yyterminate();
                    }

<STRLITERAL>"\""        {
                    BEGIN 0;
                    straux=STRLITERALAux;
                    column+=yyleng;
                    missing_semicolon=1;
                    strcat(STRLITERALAux,yytext);
                    if (print==1){
                        if(invalid_escape==0){
                            printf("STRLIT(%s)\n",STRLITERALAux);
                        }
                    
                        
                    }
                    if(parse==1){
                        if(invalid_escape==0){
                            //printf("%s",STRLITERALAux);
                            yylval.value = (char*) strdup(STRLITERALAux);return STRLIT;
                        }
                    }
                    

                    }


<STRLITERAL>.           {column+=yyleng;strcat(STRLITERALAux,yytext);}

"//"    {BEGIN ONELINECOMENT;column+=2;}
<ONELINECOMENT>{NEWLINE}                {column=1;line++;BEGIN 0;}
<ONELINECOMENT>.                        {column+=yyleng;}

"/*"                                {BEGIN MULTILINECOMENT;line_begin=line;column_begin=column;column+=2;}

<MULTILINECOMENT>.                      {column+=yyleng;}
<MULTILINECOMENT>("\n"|"\r"|"\r\n")     {column=1;line++;}
<MULTILINECOMENT>"*/"                   {BEGIN 0;column+=yyleng;}
<MULTILINECOMENT><<EOF>>                {printf("Line %d, column %d: unterminated comment\n",line_begin,column_begin);BEGIN 0;yyterminate();}

<<EOF>>         {if(missing_semicolon==1){
                    missing_semicolon=0;
                    
                    if(print==1){
                        printf("SEMICOLON\n");
                    }
                    if(parse == 1){

                        return SEMICOLON;
                    }
                       
                }
                yylval.value = (char*) strdup("EOF");
                yyterminate();
                return EOF;
                // lastCol=column;yylval.value = (char*) strdup("EOF");return EOF;
                }
.               {printf("Line %d, column %d: illegal character (%s)\n",line,column,yytext);column+=yyleng;};


%%
int main(int argc, char *argv[]){
    line=1;
    column=1;

    if (argc>1){
        if(strcmp(argv[1],"-l")==0){
        print=1;
        yylex();
        }
        if(strcmp(argv[1],"-t")==0){
            parse=1;
            yyparse();
            if(syntaxError==0){

                printAST(root,0);
                
			}
        }
        if(strcmp(argv[1],"-s")==0){
            parse=1;
            yyparse();
            if(syntaxError==0){

                criaTabelas(root);
                printTabelaFuncoes();
                printAST(root,0);
                

			}
        }
    }else{
        parse=1;
            
        yyparse();
        
        if(syntaxError==0){
                criaTabelas(root);
                if(semanticError==0){
                    generateCode(root);
                }
			}
    }

    deleteAst(root);
	return 0;
}

int yywrap(){
	return 1;
}



