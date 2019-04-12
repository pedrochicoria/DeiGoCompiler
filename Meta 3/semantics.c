#include "semantics.h" 
#include <ctype.h> // sera que pode dar problemas COMPILE TIME ERROR ?
struct func_table *funcHead =NULL;                                      // ponteiro para a cabeça da lista ligada de funcoes
int line;
int column;
void criaTabelas(node* current){
 
    if(!current){
        return;

    }
    if(strcmp(current->type,"FuncDecl")==0){
        adicionaFuncao(current);
    }
    if(strcmp(current->type,"VarDecl")==0){
        adicionaVariavelGlobal(current);
    }
    // mas sera que precisa de ver os filhos ??? nao deve ser preciso


    /* tem de ver o irmao primeiro que o filho , a ordem importa p.e.

    funcao(){
        var a;
    }
    var a;
    
    onde e que ele da erro ?  no primeiro a ou no segundo

    */
    criaTabelas(current->child);  
    criaTabelas(current->brother); 

}
void adicionaFuncao(node* current){                                          // incompleta ? falta variaveis locais e parametros
     
        struct func_table *funcAux =funcHead;
        char* funcName = current->child->child->value;                  // funcDcl FuncHeader Id
        char* funcType = current->child->child->brother->type;     
        funcType[0]=tolower(funcType[0]);

         if (existeVariavelOuFuncao(funcName,current->child->child)){                           // devolve 0 se a variavel existe
            return;
        }   


        if(!funcHead){                                                       // no caso em que nao foi adicionada nenhuma funcao/variavel  
            funcHead=(struct func_table*)malloc(sizeof( func_table));
            
            //funcHead->name=(char*)malloc(strlen(current->value)*sizeof(char)+1);
            //funcHead->type=(char*)malloc(strlen(current->type)*sizeof(char)+1);
            //funcHead->type=(char*)malloc(1000*sizeof(char));

            if(strcmp(funcType,"FuncParams")==0){
                funcType="none";    
            }
            //printf("type %s\n",current->child->child->brother->value);
            funcHead->func=1;
            funcHead->name=funcName;
            funcHead->type=funcType;
            funcHead->next=NULL;
            funcHead->params=NULL;
            funcHead->vars=NULL;
            return;
        }


        while(funcAux->next){
            
            funcAux=funcAux->next;
        }
        funcAux->next=(struct func_table*)malloc(sizeof( func_table));
        funcAux=funcAux->next;

        if(strcmp(funcType,"funcParams")==0){ // esta em minusculo porque em cima foi convertido para minusculo
            funcType="none";    
        }
            
        //printf("type %s\n",current->child->child->brother->value);
        funcAux->func=1;
        funcAux->name=funcName;
        funcAux->type=funcType;
        funcAux->next=NULL;
        funcAux->params=NULL;
        funcAux->vars=NULL;
        return;
}
void adicionaVariavelGlobal(node* current){  
    

        // verificar se a variavel ja existe 
        
        char* varName = current->child->brother->value;                 // VarDcl Type Id
        char* varType = current->child->type;                           // é suposto o tipo de variaveis funcoes aparecer em maiusculo ?
        varType[0]=tolower(varType[0]);
        
        if (existeVariavelOuFuncao(varName,current->child->brother)){                           // devolve 0 se a variavel existe
            return;
        }   

        struct func_table *funcAux =funcHead;
        if(!funcHead){                                                      // no caso em que nao foi adicionada nenhuma funcao/variavel  
            funcHead=(struct func_table*)malloc(sizeof( func_table));
            
            
            funcHead->func=0;
            funcHead->name=varName;
            funcHead->type=varType;
            funcHead->next=NULL;
            funcHead->params=NULL;
            funcHead->vars=NULL;
            return;
        }


        while(funcAux->next){
            funcAux=funcAux->next;
        }
        funcAux->next=(struct func_table*)malloc(sizeof( func_table));
        funcAux=funcAux->next;
        
        funcAux->func=0;
        funcAux->name=varName;
        funcAux->type=varType;
        funcAux->next=NULL;
        funcAux->params=NULL;
        funcAux->vars=NULL;
        return;
}
void printTabelaFuncoes(){
    printf("===== Global Symbol Table =====\n");
    struct func_table *funcAux =funcHead;
    while(funcAux){
        printf("%s\t",funcAux->name);
        if(funcAux->func){
            printf("(");
            struct param_table *paramsAux=funcAux->params;
            if(paramsAux){
                printf("%s",paramsAux->type);
                paramsAux=paramsAux->next;
                while(paramsAux){
                    printf(",%s",paramsAux->type);
                    paramsAux=paramsAux->next;
                }
            }

            printf(")");
        }
        printf("\t%s\n", funcAux->type );
        funcAux=funcAux->next;
    }
}
int existeVariavelOuFuncao(char * name,node* current){
    struct func_table *funcAux =funcHead;
    while(funcAux){

        if(strcmp(funcAux->name,name)==0){
            
            int i=0;
            while(name[i]!='\0'){
                i++;
            }

            printf("Line %d, column %d: redefinition of %s\n",current->line,current->column-i,name);
            return 1;
        }
        funcAux=funcAux->next;
    }
    return 0;
}