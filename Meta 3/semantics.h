#include "ast.h"
typedef struct func_table{ // representa uma lista ligada de funcores e de variaveis globais
    char* name;
    char* type;
    int func;
    struct var_table *vars; //
    struct param_table *params;
    struct func_table *next;
    
} func_table;

typedef struct glblvar_table{ // representa uma lista ligada de variaveis globais
    char* name;
    char* type;
    struct glblvar *next;
} glblvar_table;

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
void adicionaFuncao(node* current);
void adicionaVariavelGlobal(node* current);
void printTabelaFuncoes();
int existeVariavelOuFuncao(char * name,node* current);
void adicionaParametros(node* current,func_table * funcAux);
void adicionaVarsLocais(node* current,func_table * funcAux);
void adicionaVarsLocais(node* current,func_table * funcAux);
