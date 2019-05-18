    //Joao Mendes 2015233148
    //Pedro Chicoria 2015262771
#include "semantics.h"
typedef struct str_list{ // representa uma lista ligada strings para fazer prints
    char* str;
    struct str_list *next;
} str_list;
void generateCode(node*  current);
void global_Vars_Fun(node *current);
void add_Func(func_table* funcHead);
void add_Params(param_table *paramsAux);
void add_Store_Params(param_table *paramsAux);
void add_Local_Vars(var_table *varAux);
void generate_From_Tree(node* current);
node* get_Node_Of_Func(char *funcName,node* current);
void add_StrLit(char* strAdd);
void print_Global_Str();
