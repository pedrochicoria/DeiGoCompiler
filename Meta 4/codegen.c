    //Joao Mendes 2015233148
    //Pedro Chicoria 2015262771
#include "codegen.h"

extern struct func_table *funcHead; 
struct str_list *srtHead;
int strCount=0;  // contador de strs global

node* root; 
void generateCode(node*  current){
	global_Vars_Fun(current);
}

void global_Vars_Fun(node *current){
	func_table *funcAux=funcHead;

	//podemos declara las no inicio
	printf("declare i32 @atoi(i8*)\n");
	printf("declare i32 @printf(i8*, ...)\n");


	// ---------------------------- Variaveis globais ---------------------------- 
	while(funcAux){
		if(funcAux->func==0){
			if(strcmp(funcAux->type,"int")==0){
				printf("@global.var.%s = common global i32 0, align 4\n", funcAux->name);
			}
			else if(strcmp(funcAux->type,"float32")==0){
				printf("@global.var.%s = common global double 0, align 8\n", funcAux->name);
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

	// faz store dos parametros
	add_Store_Params(paramsAux);

	// gera o código apartir da arvore (semelhante a anotar a arvore ), mas ignorando declaracao de variaveis que ja foi feita em cima
	node* nodeAux=get_Node_Of_Func(funcAux->name,root); // aponta para o FuncDecl dessa funcao
	generate_From_Tree(nodeAux->child); 		// ve apartir do filho se nao vai ver outras funcoes
	

	// requer um bloco, !!! depois apagar
	printf("\tret i32 1\n");
	
	
	printf("}\n");


	// auxiliar para ver a arvore
	//printAST(root, 0);
}
void add_Params(param_table *paramsAux){
	while(paramsAux){

		printf("\t%%%s.addr = alloca ",paramsAux->name);
		if(strcmp(paramsAux->type,"int")==0){
			printf("i32 ");
			printf(", align 4\n");
		}
		else if(strcmp(paramsAux->type,"float32")==0){
			printf("double ");
			printf(", align 8\n");
		}
		else if(strcmp(paramsAux->type,"bool")==0){
			printf("i1 ");
			printf(", align 4\n");
		}
		
		paramsAux=paramsAux->next;
	}
}
void add_Store_Params(param_table *paramsAux){ // depois de allocar variaveis para os parametros é preciso fazer store de ponteiros
	while(paramsAux){

		printf("\tstore ");
		if(strcmp(paramsAux->type,"int")==0){
			printf("i32 ");
			printf("%%%s, ",paramsAux->name);
			printf("i32* ");
			printf("%%%s.addr, align 4",paramsAux->name);


		}
		else if(strcmp(paramsAux->type,"float32")==0){
			printf("double ");
			printf("%%%s, ",paramsAux->name);
			printf("double* ");
			printf("%%%s.addr, align 8",paramsAux->name);
		}
		else if(strcmp(paramsAux->type,"bool")==0){
			printf("i1 ");
			printf("%%%s, ",paramsAux->name);
			printf("i1* ");
			printf("%%%s.addr, align 4",paramsAux->name);
		}
		printf("\n");
		
		
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
			printf(", align 8\n");
		}
		else if(strcmp(varAux->type,"bool")==0){
			printf("i1 ");
			printf(", align 4\n");
		}
		
		varAux=varAux->next;
	}
}
void generate_From_Tree(node* current){  
	
	if(current==NULL){
		return;
	}
	//printf("%s\n",current->type);
	if(strcmp(current->type,"Print")==0){
		if(strcmp(current->type,"Print")==0){
		if(strcmp(current->child->note,"int")==0){
			printf("\t@.str.%d = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\", align 1\n",strCount); // adciona a lista de strlits
			strCount++;
			generate_From_Tree(current->brother);
		}
		if(strcmp(current->child->note,"float32")==0){

		}
		if(strcmp(current->child->note,"bool")==0){

		}
		if(strcmp(current->child->note,"str")==0){

		}

		
		strCount++;
	}

	}
	else{
		generate_From_Tree(current->child);
		generate_From_Tree(current->brother);
	}
	
}

// vai encontrar o nó pertencente a uma funcao
node* get_Node_Of_Func(char *funcName,node* current){

	if (!current){
		return NULL;
	}
	if(strcmp(current->type,"FuncDecl")==0&&strcmp(current->child->child->value,funcName)==0){
		return current;

	}else{
		// falta return
		node* aux1;
		node *aux2;
		aux1=get_Node_Of_Func(funcName,current->child);
		aux2=get_Node_Of_Func(funcName,current->brother);
		if(aux1!=NULL){
			return aux1;
		}
		if(aux2!=NULL){
			return aux2;
		}
	}	
	return NULL;
}

// adiciona a str a lista ligada de listas

void print_Globa_Str(){
	struct str_list *strAux=srtHead;
	while(strAux){
		printf("%s",strAux->str);
		strAux=strAux->next;
	}
}