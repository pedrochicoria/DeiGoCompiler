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
	// ---------------------------- Funcoes ---------------------------- 
	/*
	pode se percorrer adicionar primeiro todas as variaveis(primeiros parametros e depois locais) porque em ficheiros .ll nas funcoes o 
	que aparece primeiro sao as variaveis
	*/

	while(funcAux){
		
		if(funcAux->func==1){
			add_Func(funcAux);
		}
	
		funcAux=funcAux->next;
	}
	
	// Para nao se queixar que nao tem main
	// printf("define i32 @main(){\tret i32 0\n}\n");

}
void add_Func(func_table* funcAux){
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
	
	
	// adiciona os parametros a funcao
	paramsAux = funcAux->params;
	add_Params(paramsAux);

	// adciona variaveis locais
	add_Local_Vars(funcAux->vars);

	// requer um bloco, depois apagar 
	printf("\tret i32 1\n");
	printf("}\n");
}
void add_Params(param_table *paramsAux){
	while(paramsAux){

		printf("\t%%%s.addr = alloca ",paramsAux->name);
		if(strcmp(paramsAux->type,"int")==0){
			printf("i32 ");
			printf(", align 4\n");
		}
		else if(strcmp(paramsAux->type,"float32")==0){
			printf("float ");
			printf(", align 4\n");
		}
		else if(strcmp(paramsAux->type,"bool")==0){
			printf("i1 ");
			printf(", align 4\n");
		}
		
		paramsAux=paramsAux->next;
	}
}
void add_Local_Vars(var_table *varAux){
	while(varAux){

		printf("\t%%%s = alloca ",varAux->name);
		if(strcmp(varAux->type,"int")==0){
			printf("i32 ");
			printf(", align 4\n");
		}
		else if(strcmp(varAux->type,"float32")==0){
			printf("double ");
			printf(", align 4\n");
		}
		else if(strcmp(varAux->type,"bool")==0){
			printf("i1 ");
			printf(", align 4\n");
		}
		
		varAux=varAux->next;
	}
}