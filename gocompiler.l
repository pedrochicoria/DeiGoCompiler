
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int line=1;
    int collumn=1;
    int line_begin=1;
    int collumn_begin=1;
    int print=0;
%}

NUMBER  [0-9]+
EXPOENTS ("e"|"E")("+"|"-")?{NUMBER}

ID ([a-zA-Z]|"_")({NUMBER}|[a-zA-Z]|"_")*
INTLIT {NUMBER}|(0(x|X)([a-fA-F]|{NUMBER}))
REALLIT  {NUMBER}"."{NUMBER}?{EXPOENTS}?|"."{NUMBER}({EXPOENTS})?|{NUMBER}{EXPOENTS}
STRLIT  \"(({ESCAPE}|[^"^\\]|" ")*)\"
UNTERMINATED_STRLIT \"([^\"])*
ESCAPE \\f|\\n|\\r|\\t|\\\\|(\\\")
RESERVED "++"|"--"|"break"|"case"|"chan"|"const"|"continue"|"default"|"defer"|"fallthrough"|"func"|"go"|"goto"|"import"|"interface"|"map"|"range"|"select"|"struct"|"switch"|"type"



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



{SEMICOLON}     {if(print==1) printf("SEMICOLON\n");collumn+=yyleng;}
{BLANKID}       {if(print==1) printf("BLANKID\n");collumn+=yyleng;}
{PACKAGE}       {if(print==1) printf("PACKAGE\n");collumn+=yyleng;}
{RETURN}        {if(print==1) printf("RETURN\n");collumn+=yyleng;}
{AND}           {if(print==1) printf("AND\n");collumn+=yyleng;}
{ASSIGN}        {if(print==1) printf("ASSIGN\n");collumn+=yyleng;}
{STAR}          {if(print==1) printf("STAR\n");collumn+=yyleng;}
{COMMA}         {if(print==1) printf("COMMA\n");collumn+=yyleng;}
{DIV}           {if(print==1) printf("DIV\n");collumn+=yyleng;}
{EQ}            {if(print==1) printf("EQ\n");collumn+=yyleng;}
{GE}            {if(print==1) printf("GE\n");collumn+=yyleng;}
{GT}            {if(print==1) printf("GT\n");collumn+=yyleng;}
{LBRACE}        {if(print==1) printf("LBRACE\n");collumn+=yyleng;}
{LE}            {if(print==1) printf("LE\n");collumn+=yyleng;}
{LPAR}          {if(print==1) printf("LPAR\n");collumn+=yyleng;}
{LSQ}           {if(print==1) printf("LSQ\n");collumn+=yyleng;}
{LT}            {if(print==1) printf("LT\n");collumn+=yyleng;}
{MINUS}			{if(print==1) printf("MINUS\n");collumn+=yyleng;}
{MOD}		    {if(print==1) printf("MOD\n");collumn+=yyleng;}
{NE}			{if(print==1) printf("NE\n");collumn+=yyleng;}
{NOT}		    {if(print==1) printf("NOT\n");collumn+=yyleng;}
{OR}			{if(print==1) printf("OR\n");collumn+=yyleng;}
{PLUS}			{if(print==1) printf("PLUS\n");collumn+=yyleng;}
{RBRACE}        {if(print==1) printf("RBRACE\n");collumn+=yyleng;}
{RPAR}			{if(print==1) printf("RPAR\n");collumn+=yyleng;}
{RSQ}           {if(print==1) printf("RSQ\n");collumn+=yyleng;}
{ELSE}			{if(print==1) printf("ELSE\n");collumn+=yyleng;}
{FOR}			{if(print==1) printf("FOR\n");collumn+=yyleng;}
{IF}			{if(print==1) printf("IF\n");collumn+=yyleng;}
{VAR}			{if(print==1) printf("VAR\n");collumn+=yyleng;}
{INT}			{if(print==1) printf("INT\n");collumn+=yyleng;}
{FLOAT32}		{if(print==1) printf("FLOAT32\n");collumn+=yyleng;}
{BOOL}			{if(print==1) printf("BOOL\n");collumn+=yyleng;}
{STRING}		{if(print==1) printf("STRING\n");collumn+=yyleng;}
{PRINT}         {if(print==1) printf("PRINT\n");collumn+=yyleng;}
{PARSEINT}      {if(print==1) printf("PARSEINT\n");collumn+=yyleng;}
{FUNC}			{if(print==1) printf("FUNC\n");collumn+=yyleng;}
{CMDARGS}       {if(print==1) printf("CMDARGS\n");collumn+=yyleng;}


{REALLIT}       {if(print==1) printf("REALLIT(%s)\n",yytext);collumn+=yyleng;}
{STRLIT}        {if(print==1) printf("STRLIT(%s)\n",yytext);collumn+=yyleng;}
{ID}            {if(print==1) printf("ID(%s)\n",yytext);collumn+=yyleng;}
{INTLIT}        {if(print==1) printf("INTLIT(%s)\n",yytext);collumn+=yyleng;}
{RESERVED}      {if(print==1) printf("RESERVED(%s)\n",yytext);collumn+=yyleng;}
{UNTERMINATED_STRLIT} {printf("Line %d, column %d: unterminated string literal\n\n",line,collumn);collumn+=yyleng;}


"\t"|" "|"\f"    {collumn+=yyleng;}
"\r"    {line++;collumn=1;} // carriage return - representa o fim de uma linha e deixa o cursor no inicio dessa mesma linha
"\n"    {line++;collumn=1;} // line feed - move o cursor para a proxima linha
"\r\n"    {line++;collumn=1;} // end of line - combinacao dos dois


. {printf("Line %d, col %d: illegal character (%s)\n",line,collumn,yytext);collumn+=yyleng;};


%%
int main(int argc, char *argv[]){
    if(argc>=2 && strcmp(argv[1],"-l")==0){
		print=1;
        yylex();
    }
	return 0;
}

int yywrap(){
	return 1;
}

void yyerror(char *s){
    printf("Line %d, col %d: %s: %s\n",line,(int)(collumn-(int)yyleng),s,yytext);
}