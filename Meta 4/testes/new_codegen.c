//Joao Mendes 2015233148
//Pedro Chicoria 2015262771
#include "codegen.h"

extern struct func_table *funcHead;

void global_Vars_Fun(node *current)
{
    func_table *funcAux = funcHead;

    // ---------------------------- Variaveis globais ----------------------------
    while (funcAux)
    {
        if (funcAux->func == 0)
        {
            if (strcmp(funcAux->type, "int") == 0)
            {
                printf("@global.var.%s = common global i32 0, align 4\n", funcAux->name);
            }
            else if (strcmp(funcAux->type, "float32") == 0)
            {
                printf("@global.var.%s = common global double 0, align 8\n", funcAux->name);
            }
            else if (strcmp(funcAux->type, "bool") == 0)
            {
                printf("@global.var.%s = common global i1 0, align 4\n", funcAux->name);
            }
        }
        funcAux = funcAux->next;
    }
    funcAux = funcHead;
    // ---------------------------- Funcoes ----------------------------
    /*
	pode se percorrer adicionar primeiro todas as variaveis(primeiros parametros e depois locais) porque em ficheiros .ll nas funcoes o 
	que aparece primeiro sao as variaveis
	*/

    while (funcAux)
    {

        if (funcAux->func == 1)
        {
            add_Func(funcAux);
        }

        funcAux = funcAux->next;
    }

    // Para nao se queixar que nao tem main
    // printf("define i32 @main(){\tret i32 0\n}\n");
}