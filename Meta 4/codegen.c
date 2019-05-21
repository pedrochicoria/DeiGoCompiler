    //Joao Mendes 2015233148
    //Pedro Chicoria 2015262771
#include "codegen.h"
#include <string.h>

extern struct func_table *funcHead; 
struct str_list *strHead =NULL ;
int strCount=0;  // contador de strs global
int operacao=1;  // contador de variaveis temporarias

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
				printf("@global.var.%s = common global double 0.0000e+00, align 8\n", funcAux->name);
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


	// para fazer print das strings usadas para prints
	print_Global_Str();


	// Para nao se queixar que nao tem main
	// printf("define i32 @main(){\tret i32 0\n}\n");

}
void add_Func(func_table* funcAux){
	printf("define ");
	param_table *paramsAux;
	// para a main adiciona coisas especificas
	if(strcmp(funcAux->name,"main")==0){
		printf("i32 ");
		
		printf("@%s(",funcAux->name);
	
		// ---------------------- Argumentos ----------------------
		paramsAux = funcAux->params;
		printf("i32 %%argc, i8** %%argv");
		printf(") {\n");
		
		
		// adiciona os parametros a funcao
		paramsAux = funcAux->params;
		add_Params(paramsAux);
		printf("\t%%argc.addr = alloca i32, align 4\n");
		printf("\t%%argv.addr = alloca i8**, align 8\n");
		printf("\tstore i32 %%argc, i32* %%argc.addr, align 4\n");
		printf("\tstore i8** %%argv, i8*** %%argv.addr, align 8\n");

	
	}
	
	//uma funcao que nao seja a main  
	else{
		if(strcmp(funcAux->type,"int")==0){
			printf("i32 ");
		}
		else if(strcmp(funcAux->type,"float32")==0){
			printf("double ");
		}
		else if(strcmp(funcAux->type,"bool")==0){
			printf("i1 ");
		}
		
		else if(strcmp(funcAux->type,"none")==0){
			printf("void ");
		}
		printf("@%s(",funcAux->name);
	
		// ---------------------- Argumentos ----------------------
		paramsAux = funcAux->params;
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

	}
	
	
	// adciona variaveis locais
	add_Local_Vars(funcAux->vars);

	// faz store dos parametros
	paramsAux = funcAux->params;
	add_Store_Params(paramsAux);

	// gera o código apartir da arvore (semelhante a anotar a arvore ), mas ignorando declaracao de variaveis que ja foi feita em cima
	
	node* nodeAux=get_Node_Of_Func(funcAux->name,root); // aponta para o FuncDecl dessa funcao
	nodeAux=nodeAux->child->brother->child; 			// aponta para o primeiro statement
	while(nodeAux){
		generate_From_Tree(nodeAux); 		// ve apartir do filho se nao vai ver outras funcoes
		nodeAux=nodeAux->brother;
	}
	
	// ver se os returns estao bem
	if(strcmp(funcAux->name,"main")==0){
		printf("\tret i32 0\n");
	}
	else{
		if(strcmp(funcAux->type,"int")==0){
			printf("\tret i32 0\n");
		}
		else if(strcmp(funcAux->type,"float32")==0){
			printf("\tret double 0.0\n");
		}
		else if(strcmp(funcAux->type,"bool")==0){
			printf("\tret i1 true\n");
		}
		
		else if(strcmp(funcAux->type,"none")==0){
			printf("\tret void \n");
		}
	}
	
	
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
		char* strNew=(char *) malloc(1024*sizeof(char));
		if(strcmp(current->child->note,"int")==0){
			//printf("@.str.%d = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\", align 1\n",strCount); // adciona a lista de strlits
			sprintf(strNew,"@.str.%d = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\", align 1\n",strCount);
			generate_From_Tree(current->child);
			printf("\t%%%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.%d, i32 0, i32 0), i32 %%%d)\n", operacao, strCount, operacao-1);
			add_StrLit(strNew);
			operacao++;
		}
		else if(strcmp(current->child->note,"float32")==0){
			sprintf(strNew, "@.str.%d = private unnamed_addr constant [7 x i8] c\"%%.08f\\0A\\00\", align 1\n", strCount);
			generate_From_Tree(current->child);
			printf("\t%%%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.%d, i32 0, i32 0), double %%%d)\n", operacao, strCount, operacao-1);
			add_StrLit(strNew);
			operacao++;
		}
		else if(strcmp(current->child->note,"bool")==0){
			//sprintf(strNew, "@.global.strlit.%d = private unnamed_addr constant [6 x i8] c\"true\\0A\\00\", align 1\n", strCount);
			// como fazer ???? para true e false 
			// fazer codigo em llvm para ver o que dá ???
			sprintf(strNew, "@.str.%d = private unnamed_addr constant [7 x i8] c\"false\\0A\\00\", align 1\n", strCount);
			add_StrLit(strNew);
		}
		else if(strcmp(current->child->note,"string")==0){
			char *oldString=current->child->value;  // para remover as aspas
			char newString[(int)strlen(oldString)-2];

			int i ;
			for(i=0;oldString[i+1]!='"';i++){

				newString[i]=oldString[i+1];
			}
			newString[i]='\0';
		
			sprintf(strNew, "@.str.%d = private unnamed_addr constant [%d x i8] c\"%s\\0A\\00\", align 1\n", strCount,(int )strlen(newString)+2,newString);
			add_StrLit(strNew);
			printf("\t%%%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([%d x i8], [%d x i8]* @.str.%d, i32 0, i32 0))\n",operacao,(int )strlen(newString)+2,(int )strlen(newString)+2,strCount);
			operacao++;
		}

		strCount++;
		free(strNew);

	}
	else if(strcmp(current->type,"ParseArgs")==0){
		// so aceita ser atribuido a int 
		// so aceita que seja passado um int

		
		// 				!!!!!!!ATENCAO QUE O QUE ESTA DENTRO DO ATOI PODE SER UMA EXPRESSAO !!!!!!!

		printf("\t%%%d = load i8**, i8*** %%argv.addr, align 8\n",operacao);
		operacao++;

		// vai buscar o current->child->brother que é o numero do argumento 
		int operacaoAux=operacao-1;
		generate_From_Tree(current->child->brother);



		printf("\t%%%d = getelementptr inbounds i8*, i8** %%%d, i32 %%%d\n",operacao,operacaoAux,operacao-1);
		operacao++;
		printf("\t%%%d = load i8*, i8** %%%d, align 8\n",operacao,operacao-1);
		operacao++;
		printf("\t%%%d = call i32 @atoi(i8* %%%d)\n",operacao,operacao-1);
		operacao++;
		if(isGlobal(current->child->value)==0){
			printf("\tstore i32 %%%d, i32* %%%s, align 4\n",operacao-1,current->child->value);
		}
		else{
			printf("\tstore i32 %%%d, i32* @global.var.%s, align 4\n",operacao-1,current->child->value);
		}


		
	}
	else if(strcmp(current->type,"VarDecl")==0){
		//Nao faz nada porque a declaracao de variaveis ja foi feita antes
		return;
	}
	else if(strcmp(current->type,"Assign")==0){
		if(strcmp(current->child->note,"int")==0){
			if(isGlobal(current->child->value)){
				printf("\t%%%d = load i32, i32* @global.var.%s, align 4\n",operacao,current->child->value);
			}
			else{
				printf("\t%%%d = load i32, i32* %%%s, align 4\n",operacao,current->child->value);
			}
			operacao++;
			generate_From_Tree(current->child->brother);

			if(isGlobal(current->child->value)){
				printf("\tstore i32 %%%d, i32* @global.var.%s, align 8\n",operacao-1,current->child->value);
			}
			else{
				printf("\tstore i32 %%%d, i32* %%%s, align 8\n",operacao-1,current->child->value);
			}
			
			generate_From_Tree(current->child);
		}
		else if(strcmp(current->child->note,"float32")==0){
			if(isGlobal(current->child->value)){
				printf("\t%%%d = load double, double* @global.var.%s, align 4\n",operacao,current->child->value);
			}
			else{
				printf("\t%%%d = load double, double* %%%s, align 4\n",operacao,current->child->value);
			}
			operacao++;
			generate_From_Tree(current->child->brother);
			if(isGlobal(current->child->value)){
				printf("\tstore double %%%d, double* @global.var.%s, align 8\n",operacao-1,current->child->value);
			}
			else{
				printf("\tstore double %%%d, double* %%%s, align 8\n",operacao-1,current->child->value);
			}
			
			generate_From_Tree(current->child);
		}
		else if(strcmp(current->child->note,"bool")==0){ // falta fazer aqui !!!

		}
	}
	else if(strcmp(current->type,"Add")==0){
		//printf("%%%d = add %%%d, %%%d",operacao);
		
	}
	else if(strcmp(current->type,"Id")==0){
		if(strcmp(current->note,"int")==0){
			if(isGlobal(current->value)){
				printf("\t%%%d = load i32, i32* @global.var.%s, align 4\n",operacao,current->value);
			}
			else{
				printf("\t%%%d = load i32, i32* %%%s, align 4\n",operacao,current->value);
			}
			operacao++;
		}
		else if(strcmp(current->note,"float32")==0){
			if(isGlobal(current->value)){
				printf("\t%%%d = load double, double* @global.var.%s, align 4\n",operacao,current->value);
			}
			else{
				printf("\t%%%d = load double, double* %%%s, align 4\n",operacao,current->value);
			}
			
			operacao++;
		}

	}
	else if(strcmp(current->type,"IntLit")==0){
		printf("\t%%%d = add i32 0, %s\n",operacao,current->value);
		operacao++;
	}
	else if(strcmp(current->type,"RealLit")==0){
		

		// ESTA MAL ? CASAS DECIMAIS A MAIS
		printf("\t%%%d = fadd double 0.000000e+00, %s000000e+00\n",operacao,current->value);
		operacao++;
	}
	

	
	else{
		generate_From_Tree(current->child);
		
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
void add_StrLit(char* strAdd){
	str_list *strAux=strHead;
	if(!strHead){ // se nao houver nenhum adiciona a cabeca
		strHead=(str_list *)malloc(sizeof(str_list));
		strHead->str=(char *)strdup(strAdd);
		strHead->next=NULL;
		return;
	}

	while(strAux->next){
		strAux=strAux->next;
	}
	strAux->next=(str_list *)malloc(sizeof(str_list));
	strAux=strAux->next;
	strAux->str=(char *)strdup(strAdd);
	strAux->next=NULL;

}
void print_Global_Str(){
	struct str_list *strAux=strHead;
	while(strAux){
		printf("%s",strAux->str);
		strAux=strAux->next;
	}
}
int isGlobal(char *varName){
	struct func_table *funcAux=funcHead;
	while(funcAux){
		if(strcmp(funcAux->name,varName)==0){
			return 1;
		}
		funcAux=funcAux->next;
	}
	return 0;
}
// funcao que cria a main no caso de o ficheiro estar vazio
void create_Main(){
	
}
