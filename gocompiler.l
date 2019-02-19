%x comment
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"

    int line=1;
    int collumn=1;
    int line_begin=1;
    int collumn_begin=1;
    int print=0;
%}

RESERVED "break"|"case"|"chan"|"const"|"continue"|"default"|"defer"|"else"|"fallthrough"|"for"|"func"|"go"|"goto"|"if"|"import"|"interface"|"map"|"package"|"range"|"return"|"select"|"struct"|"switch"|"type"|"var"
INTLIT [0-9]+

ID ([a-zA-Z_])([0-9]|[a-zA-Z_])*

REALLIT  {INTLIT}"."{INTLIT}?{EXPOENTS}?|"."{INTLIT}({EXPOENTS})?|{INTLIT}{EXPOENTS}

EXPOENTS ("e"|"E")("+"|"-")?{INTLIT}


%%
"\t"|" "	{collumn+=yyleng;}
"\n"|"\r"|"\r\n"    {line++;collumn=1;}

"/*"    {BEGIN comment; collumn_begin=collumn;line_begin=line;collumn+=yyleng;}/*begin of comment*/
<comment>\r|\n|\r\n {line++;collumn=1;}/*change of line, lines ++ and collumn = 1*/
<comment>\t  {line=1;collumn++;} /*space, collumn++ and line = 1*/
<comment>"*/" {BEGIN 0;collumn+=yyleng;} /*end of comment*/
<comment><<EOF>> {printf("Line %d, col %d: unterminated comment\n",line_begin, collumn_begin);
                 collumn+=1; 
                 yyterminate();}
<comment>. {collumn+=yyleng;} /*any character */


";"             {if(print==1) printf("SEMICOLON\n");collumn+=yyleng;}
"_"             {if(print==1) printf("BLANKID\n");collumn+=yyleng;}
"package"       {if(print==1) printf("PACKAGE\n");collumn+=yyleng;}
"return"        {if(print==1) printf("RETURN\n");collumn+=yyleng;}
"&&"            {if(print==1) printf("AND\n");collumn+=yyleng;}
"="             {if(print==1) printf("ASSIGN\n");collumn+=yyleng;}
"*"             {if(print==1) printf("STAR\n");collumn+=yyleng;}
","             {if(print==1) printf("COMMA\n");collumn+=yyleng;}
"/"             {if(print==1) printf("DIV\n");collumn+=yyleng;}
"=="            {if(print==1) printf("EQ\n");collumn+=yyleng;}
">="            {if(print==1) printf("GE\n");collumn+=yyleng;}
">"             {if(print==1) printf("GT\n");collumn+=yyleng;}
"{"             {if(print==1) printf("LBRACE\n");collumn+=yyleng;}
"<="            {if(print==1) printf("LE\n");collumn+=yyleng;}
"("             {if(print==1) printf("LPAR\n");collumn+=yyleng;}
"["             {if(print==1) printf("LSQ\n");collumn+=yyleng;}
"<"             {if(print==1) printf("LT\n");collumn+=yyleng;}
"-"				{if(print==1) printf("MINUS\n");collumn+=yyleng;}
"%"				{if(print==1) printf("MOD\n");collumn+=yyleng;}
"!="			{if(print==1) printf("NE\n");collumn+=yyleng;}
"!"				{if(print==1) printf("NOT\n");collumn+=yyleng;}
"||"			{if(print==1) printf("OR\n");collumn+=yyleng;}
"+"				{if(print==1) printf("PLUS\n");collumn+=yyleng;}
"}"				{if(print==1) printf("RBRACE\n");collumn+=yyleng;}
")"				{if(print==1) printf("RPAR\n");collumn+=yyleng;}
"]"             {if(print==1) printf("LRQ\n");collumn+=yyleng;}
"else"			{if(print==1) printf("ELSE\n");collumn+=yyleng;}
"for"			{if(print==1) printf("FOR\n");collumn+=yyleng;}
"if"			{if(print==1) printf("IF\n");collumn+=yyleng;}
"var"			{if(print==1) printf("VAR\n");collumn+=yyleng;}
"int"			{if(print==1) printf("INT\n");collumn+=yyleng;}
"float32"		{if(print==1) printf("FLOAT32\n");collumn+=yyleng;}
"bool"			{if(print==1) printf("BOOL\n");collumn+=yyleng;}
"string"		{if(print==1) printf("STRING\n");collumn+=yyleng;}
"fmt.Println"   {if(print==1) printf("PRINT\n");collumn+=yyleng;}
"strconv.Atoi"  {if(print==1) printf("PARSEINT\n");collumn+=yyleng;}
"func"			{if(print==1) printf("FUNC\n");collumn+=yyleng;}
"os.Args"       {if(print==1) printf("CMDARGS \n");collumn+=yyleng;}
{REALLIT}		{if(print==1) printf("REALLIT(%s)\n",yytext);collumn+=yyleng;}
{ID}            {if(print==1) printf("ID(%s)\n",yytext);collumn+=yyleng;}
{RESERVED}		{if(print==1) printf("RESERVED(%s)\n",yytext);collumn+=yyleng;}

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