
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int line=1;
    int column=1;
    int line_begin=1;
    int column_begin=1;
    int print=0;
    char strLitAux[1024];
    char* idaux;
    int invalid_escape;
    int missing_semicolon=0;

%}


%X STRLIT
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

{SPACES}    {column+=yyleng;}
{NEWLINE}    {if(print==1&&missing_semicolon==1) printf("SEMICOLON\n");line++;column=1;missing_semicolon=0;} // carriage return - representa o fim de uma linha e deixa o cursor no inicio dessa mesma linha ,line feed - move o cursor para a proxima linha, end of line - combinacao dos dois
                            
{SEMICOLON}     {if(print==1) printf("SEMICOLON\n");column+=yyleng;missing_semicolon=0;}
{BLANKID}       {if(print==1) printf("BLANKID\n");column+=yyleng;missing_semicolon=0;}
{PACKAGE}       {if(print==1) printf("PACKAGE\n");column+=yyleng;missing_semicolon=0;}

{AND}           {if(print==1) printf("AND\n");column+=yyleng;missing_semicolon=0;}
{ASSIGN}        {if(print==1) printf("ASSIGN\n");column+=yyleng;missing_semicolon=0;}
{STAR}          {if(print==1) printf("STAR\n");column+=yyleng;missing_semicolon=0;}
{COMMA}         {if(print==1) printf("COMMA\n");column+=yyleng;missing_semicolon=0;}
{DIV}           {if(print==1) printf("DIV\n");column+=yyleng;missing_semicolon=0;}
{EQ}            {if(print==1) printf("EQ\n");column+=yyleng;missing_semicolon=0;}
{GE}            {if(print==1) printf("GE\n");column+=yyleng;missing_semicolon=0;}
{GT}            {if(print==1) printf("GT\n");column+=yyleng;missing_semicolon=0;}
{LBRACE}        {if(print==1) printf("LBRACE\n");column+=yyleng;missing_semicolon=0;}
{LE}            {if(print==1) printf("LE\n");column+=yyleng;missing_semicolon=0;}
{LPAR}          {if(print==1) printf("LPAR\n");column+=yyleng;missing_semicolon=0;}
{LSQ}           {if(print==1) printf("LSQ\n");column+=yyleng;missing_semicolon=0;}
{LT}            {if(print==1) printf("LT\n");column+=yyleng;missing_semicolon=0;}
{MINUS}			{if(print==1) printf("MINUS\n");column+=yyleng;missing_semicolon=0;}
{MOD}		    {if(print==1) printf("MOD\n");column+=yyleng;missing_semicolon=0;}
{NE}			{if(print==1) printf("NE\n");column+=yyleng;missing_semicolon=0;}
{NOT}		    {if(print==1) printf("NOT\n");column+=yyleng;missing_semicolon=0;}
{OR}			{if(print==1) printf("OR\n");column+=yyleng;missing_semicolon=0;}
{PLUS}			{if(print==1) printf("PLUS\n");column+=yyleng;missing_semicolon=0;}
{RBRACE}                    {if(print==1) printf("RBRACE\n");column+=yyleng;missing_semicolon=1;}
{RPAR}			            {if(print==1) printf("RPAR\n");column+=yyleng;missing_semicolon=1;}                            
{RSQ}                       {if(print==1) printf("RSQ\n");column+=yyleng;missing_semicolon=1;}
{ELSE}			            {if(print==1) printf("ELSE\n");column+=yyleng;missing_semicolon=0;}
{FOR}			            {if(print==1) printf("FOR\n");column+=yyleng;missing_semicolon=0;}
{IF}			            {if(print==1) printf("IF\n");column+=yyleng;missing_semicolon=0;}
{VAR}			            {if(print==1) printf("VAR\n");column+=yyleng;missing_semicolon=0;}
{INT}			            {if(print==1) printf("INT\n");column+=yyleng;missing_semicolon=0;}
{FLOAT32}		            {if(print==1) printf("FLOAT32\n");column+=yyleng;missing_semicolon=0;}
{BOOL}			            {if(print==1) printf("BOOL\n");column+=yyleng;missing_semicolon=0;}
{STRING}		            {if(print==1) printf("STRING\n");column+=yyleng;missing_semicolon=0;}
{PRINT}                     {if(print==1) printf("PRINT\n");column+=yyleng;missing_semicolon=0;}
{PARSEINT}                  {if(print==1) printf("PARSEINT\n");column+=yyleng;missing_semicolon=0;}
{FUNC}			            {if(print==1) printf("FUNC\n");column+=yyleng;missing_semicolon=0;}
{CMDARGS}                   {if(print==1) printf("CMDARGS\n");column+=yyleng;missing_semicolon=0;}
{RESERVED}                  {if(print==1) printf("RESERVED(%s)\n",yytext);column+=yyleng;missing_semicolon=0;}
{REALLIT}                       {if(print==1) printf("REALLIT(%s)\n",yytext);column+=yyleng;missing_semicolon=1;}
{INTLIT}                        {if(print==1) printf("INTLIT(%s)\n",yytext);column+=yyleng;missing_semicolon=1;}
{RETURN}                        {if(print==1) printf("RETURN\n");column+=yyleng;missing_semicolon=1;}
{ID}                            {if(print==1) printf("ID(%s)\n",yytext);column+=yyleng;missing_semicolon=1;}





\"          {BEGIN STRLIT;
            strcat(strLitAux,yytext);
            invalid_escape=0;
            line_begin=line;
            column_begin=column;
            column+=yyleng;
            }


<STRLIT>{NEWLINE}   {
                    missing_semicolon=0;
                    printf("Line %d, column %d: unterminated string literal\n", line_begin, column_begin);
                    line++;column=1;
                    strcpy(strLitAux,"\0");
                    BEGIN 0; // volta ao estado inicial 
                    }


<STRLIT>{ESCAPE}    {column+=yyleng;strcat(strLitAux,yytext);}

<STRLIT>(\\.)|(\\)         {
                            invalid_escape=1;missing_semicolon=0;
                            printf("Line %d, column %d: invalid escape sequence (%s)\n", line, column, yytext);
                            column+=yyleng;
                            strcpy(strLitAux,"\0");

                            }

<STRLIT><<EOF>>     {
                    column+=yyleng;
                    printf("Line %d, column %d: unterminated string literal\n", line_begin, column_begin);
                    strcpy(strLitAux,"\0");
                    BEGIN 0; // volta ao estado inicial 
                    }

<STRLIT>"\""        {
                    column+=yyleng;
                    missing_semicolon=1;
                    strcat(strLitAux,yytext);
                    if (print==1){
                        if(invalid_escape==0){
                            printf("STRLIT(%s)\n",strLitAux);
                        }
                        
                    }
                    strcpy(strLitAux,"\0"); // apaga o buffer caso contrario o que la estava pode ser acedido por outros strlits
                    BEGIN 0;
                    }


<STRLIT>.           {column+=yyleng;strcat(strLitAux,yytext);}

"//"    {BEGIN ONELINECOMENT;column+=2;}
<ONELINECOMENT>{NEWLINE}                {column=1;line++;BEGIN 0;}
<ONELINECOMENT>.                        {column+=yyleng;}

"/*"                                {BEGIN MULTILINECOMENT;line_begin=line;column_begin=column;column+=2;}

<MULTILINECOMENT>.                      {column+=yyleng;}
<MULTILINECOMENT>("\n"|"\r"|"\r\n")     {column=1;line++;}
<MULTILINECOMENT>"*/"                   {BEGIN 0;column+=yyleng;}
<MULTILINECOMENT><<EOF>>                {printf("Line %d, column %d: unterminated comment\n",line_begin,column_begin);BEGIN 0;}
<<EOF>>         {if(missing_semicolon==1){
                    printf("SEMICOLON\n");
                        
                }
                return 0;}
.               {printf("Line %d, column %d: illegal character (%s)\n",line,column,yytext);column+=yyleng;};


%%
int main(int argc, char *argv[]){
    if(strcmp(argv[1],"-l")==0){
		print=1;
        yylex();
    }
	return 0;
}

int yywrap(){
	return 1;
}

void yyerror(char *s){
    printf("Line %d, col %d: %s: %s\n",line,(int)(column-(int)yyleng),s,yytext);
}
