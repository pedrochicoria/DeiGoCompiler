#include "ast.h"
typedef struct func_table{ // representa uma lista ligada de funcores e de variaveis globais
    char* name;
    char* type;
    int func;
    int declared;
    struct var_table *vars; //
    struct param_table *params;
    struct func_table *next;
    
} func_table;


typedef struct param_table{ // representa uma lista ligada de parametros de uma funcao
    char* name;
    char* type;
    struct param_table *next;
} param_table;

typedef struct var_table{ // representa uma lista ligada de variaveis locais de uma funcao
    int isParam;
    char* name;
    char* type;
    struct var_table *next;
} var_table;

void criaTabelas(node* current);
char* anotaStatementsExpressoes(node *current, func_table *funcAux);
func_table* ponteiroFuncao(char* funcaoNome);
func_table* adicionaFuncao(node* current);
void adicionaVariavelGlobal(node* current);
void printTabelaFuncoes();
int existeVariavelOuFuncao(char * name,node* current,int opcao);
void adicionaParametros(node* current,func_table * funcAux);
void adicionaVarsLocais(node* current,func_table * funcAux);
void adicionaVarsLocais(node* current,func_table * funcAux);
char* anotaId(node* current, func_table* funcAux);
char* anotaIdFuncao(node* current, func_table* funcAux);
void variavelExiste(node* current, func_table* funcAux);
int usedVar(node* current,char *varName);
