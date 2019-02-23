
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int line=1;
    int column=1;
    int line_begin=1;
    int column_begin=1;
    int print=0;
    char* strLitAux;
    char* idaux;
    int invalid_escape;

%}


%X STRLIT
%X IDSTATE


NUMBER  [0-9]+
EXPOENTS ("e"|"E")("+"|"-")?{NUMBER}

ID ([a-z]|[A-Z]|"_")({NUMBER}|[a-z]|[A-Z]|"_")*
INTLIT {NUMBER}|(0(x|X)([a-fA-F]|{NUMBER}))
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

{NEWLINE}    {line++;column=1;} // carriage return - representa o fim de uma linha e deixa o cursor no inicio dessa mesma linha ,line feed - move o cursor para a proxima linha, end of line - combinacao dos dois
{ID}{SPACES}*{NEWLINE}        {if(print==1) printf("ID(%s)\n",yytext);
                                if(print==1) printf("SEMICOLON\n");
                            }
{SEMICOLON}     {if(print==1) printf("SEMICOLON\n");column+=yyleng;}
{BLANKID}       {if(print==1) printf("BLANKID\n");column+=yyleng;}
{PACKAGE}       {if(print==1) printf("PACKAGE\n");column+=yyleng;}
{RETURN}        {if(print==1) printf("RETURN\n");column+=yyleng;}
{AND}           {if(print==1) printf("AND\n");column+=yyleng;}
{ASSIGN}        {if(print==1) printf("ASSIGN\n");column+=yyleng;}
{STAR}          {if(print==1) printf("STAR\n");column+=yyleng;}
{COMMA}         {if(print==1) printf("COMMA\n");column+=yyleng;}
{DIV}           {if(print==1) printf("DIV\n");column+=yyleng;}
{EQ}            {if(print==1) printf("EQ\n");column+=yyleng;}
{GE}            {if(print==1) printf("GE\n");column+=yyleng;}
{GT}            {if(print==1) printf("GT\n");column+=yyleng;}
{LBRACE}        {if(print==1) printf("LBRACE\n");column+=yyleng;}
{LE}            {if(print==1) printf("LE\n");column+=yyleng;}
{LPAR}          {if(print==1) printf("LPAR\n");column+=yyleng;}
{LSQ}           {if(print==1) printf("LSQ\n");column+=yyleng;}
{LT}            {if(print==1) printf("LT\n");column+=yyleng;}
{MINUS}			{if(print==1) printf("MINUS\n");column+=yyleng;}
{MOD}		    {if(print==1) printf("MOD\n");column+=yyleng;}
{NE}			{if(print==1) printf("NE\n");column+=yyleng;}
{NOT}		    {if(print==1) printf("NOT\n");column+=yyleng;}
{OR}			{if(print==1) printf("OR\n");column+=yyleng;}
{PLUS}			{if(print==1) printf("PLUS\n");column+=yyleng;}
{RBRACE}        {if(print==1) printf("RBRACE\n");column+=yyleng;}
{RPAR}			{if(print==1) printf("RPAR\n");column+=yyleng;}
{RSQ}           {if(print==1) printf("RSQ\n");column+=yyleng;}
{ELSE}			{if(print==1) printf("ELSE\n");column+=yyleng;}
{FOR}			{if(print==1) printf("FOR\n");column+=yyleng;}
{IF}			{if(print==1) printf("IF\n");column+=yyleng;}
{VAR}			{if(print==1) printf("VAR\n");column+=yyleng;}
{INT}			{if(print==1) printf("INT\n");column+=yyleng;}
{FLOAT32}		{if(print==1) printf("FLOAT32\n");column+=yyleng;}
{BOOL}			{if(print==1) printf("BOOL\n");column+=yyleng;}
{STRING}		{if(print==1) printf("STRING\n");column+=yyleng;}
{PRINT}         {if(print==1) printf("PRINT\n");column+=yyleng;}
{PARSEINT}      {if(print==1) printf("PARSEINT\n");column+=yyleng;}
{FUNC}			{if(print==1) printf("FUNC\n");column+=yyleng;}
{CMDARGS}       {if(print==1) printf("CMDARGS\n");column+=yyleng;}


{REALLIT}       {if(print==1) printf("REALLIT(%s)\n",yytext);column+=yyleng;}

{INTLIT}        {if(print==1) printf("INTLIT(%s)\n",yytext);column+=yyleng;}
{RESERVED}      {if(print==1) printf("RESERVED(%s)\n",yytext);column+=yyleng;}


{SPACES}    {column+=yyleng;}


{ID}                            {if(print==1) printf("ID(%s)\n",yytext);}






\"          {BEGIN STRLIT;
            strLitAux=yytext; 
            invalid_escape=0;
            line_begin=line;
            column_begin=column;
            column+=yyleng;
            }

<STRLIT>{ESCAPE}    {column+=yyleng;}

<STRLIT>(\\.)|(\\)         {
                            invalid_escape=1;
                            printf("Line %d, column %d: invalid escape sequence (%s)\n", line, column, yytext);
                            column+=yyleng;
                            }


<STRLIT>{NEWLINE}   {line++;column=1;
                    printf("Line %d, column %d: unterminated string literal\n", line_begin, column_begin);
                    BEGIN 0; // volta ao estado inicial 
                    }

<STRLIT><<EOF>>     {
                    column+=yyleng;
                    printf("Line %d, column %d: unterminated string literal\n", line_begin, column_begin);
                    BEGIN 0; // volta ao estado inicial 
                    }

<STRLIT>\"          {
                    column+=yyleng;
                    if (print==1){
                        if(invalid_escape==0){
                            printf("STRLIT(%s)\n",strLitAux);
                        }
                        
                    }
                    BEGIN 0;
                    }
<STRLIT>.           {column+=yyleng;}


. {printf("Line %d, column %d: illegal character (%s)\n",line,column,yytext);column+=yyleng;};


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