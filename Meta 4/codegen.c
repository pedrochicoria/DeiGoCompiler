    //Joao Mendes 2015233148
    //Pedro Chicoria 2015262771
#include "codegen.h"

extern struct func_table *funcHead;  
void generateCode(node*  current){
	global_Vars_Fun(current);
}

void global_Vars_Fun(node *current){
	func_table *funcAux=funcHead;

	// ---------------------------- Variaveis globais ---------------------------- 
	while(funcAux){
		if(funcAux->func==0){
			if(strcmp(funcAux->type,"int")==0){
				printf("@global.var.%s = common global i32 0, align 4\n", funcAux->name);
			}
			else if(strcmp(funcAux->type,"float32")==0){
				printf("@global.var.%s = common global double 0, align 4\n", funcAux->name);
			}
			else if(strcmp(funcAux->type,"bool")==0){
				printf("@global.var.%s = common global i1 0, align 4\n", funcAux->name);
			}
		}
		funcAux=funcAux->next;
	}
	funcAux=funcHead;
	/*
	while(current){
		if(strcmp(current->type,"FuncDcl")==0||strcmp(current->type,"VarDcl")==0){
			while(current){
				if(strcmp(current->type,"FuncDcl")==0){
					printf("FUNCAO");
				}
				current=current->brother;
			}
		}
		else{
			current=current->child;
		}
		
	}*/
	// ---------------------------- Funcoes ---------------------------- 
	/*
	pode se percorrer adicionar primeiro todas as variaveis(primeiros parametros e depois locais) porque em ficheiros .ll nas funcoes o 
	que aparece primeiro sao as variaveis
	*/

	while(funcAux){
		
		if(funcAux->func==1){
			add_Vars_To_Func(funcAux);
		}
	
		funcAux=funcAux->next;
	}
	
	// Para nao se queixar que nao tem main
	// printf("define i32 @main(){\tret i32 0\n}\n");

}
void add_Vars_To_Func(func_table* funcAux){
	printf("define ");
	if(strcmp(funcAux->type,"int")==0){
		printf("i32 ");
	}
	else if(strcmp(funcAux->type,"float32")==0){
		printf("double ");
	}
	else if(strcmp(funcAux->type,"bool")==0){
		printf("i1 ");
	}
	printf("@%s(",funcAux->name);
	
	// ---------------------- Argumentos ----------------------
	param_table *paramsAux = funcAux->params;
	while(paramsAux){
		if(strcmp(paramsAux->type,"int")==0){
			printf("i32 ");
		}
		else if(strcmp(paramsAux->type,"float32")==0){
			printf("double ");
		}
		else if(strcmp(paramsAux->type,"bool")==0){
			printf("i1 ");
		}
		printf("%%");
		printf("%s",paramsAux->name);
		if(paramsAux->next){ // para por  a virgula
				printf(", ");
		}
		paramsAux=paramsAux->next;
	}

	printf(") {\n");


	// requer um bloco, depois apagar 
	printf("\tret i32 1\n");
	printf("}");
}