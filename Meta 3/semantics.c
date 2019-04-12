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
    else if(strcmp(current->type,"VarDecl")==0){
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
    else{
        criaTabelas(current->child); 
    }
    criaTabelas(current->brother);

}
void adicionaFuncao(node* current){                                          // incompleta ? falta variaveis locais 
     
        struct func_table *funcAux =funcHead;

        char* funcName = (char *)malloc(sizeof( char)*100);                  // funcDcl FuncHeader Id
        strcpy(funcName,current->child->child->value);

        char* funcType = (char *)malloc(sizeof( char)*100);             // alterar o tamanho ?   
        strcpy(funcType,current->child->child->brother->type);  
        funcType[0]=tolower(funcType[0]);

         if (existeVariavelOuFuncao(funcName,current->child->child)){                           // devolve 0 se a variavel existe
            return;
        }   


        if(!funcHead){                                                       // no caso em que nao foi adicionada nenhuma funcao/variavel  
            funcHead=(struct func_table*)malloc(sizeof( func_table));
         
            if(strcmp(funcType,"funcParams")==0||strcmp(funcType,"FuncParams")==0){
                funcType="none";    
            }

                                                                        // adiciona o return as fariaveis locais
            
            funcHead->vars=(struct var_table*)malloc(sizeof( var_table)); 
            funcHead->vars->name=(char *)malloc(sizeof( char)*100) ;
            strcpy(funcHead->vars->name,"return");
            funcHead->vars->type=(char *)malloc(sizeof( char)*100) ; 
            strcpy(funcHead->vars->type,funcType);
            funcHead->vars->isParam=0;
            funcHead->vars->next=NULL;
            
            funcHead->func=1;
            funcHead->name=funcName;
            funcHead->type=funcType;
            funcHead->next=NULL;
            funcHead->params=NULL;
            adicionaParametros(current,funcHead);
            adicionaVarsLocais(current,funcHead);


        }
        else{

            while(funcAux->next){
            
                funcAux=funcAux->next;
            }
            funcAux->next=(struct func_table*)malloc(sizeof( func_table));
            funcAux=funcAux->next;

        
            if(strcmp(funcType,"funcParams")==0||strcmp(funcType,"FuncParams")==0){ // esta em minusculo porque em cima foi convertido para minusculo
                funcType="none";                                                    // adiciona Type none se nao houver type

            }
                                                                        // adiciona o return as fariaveis locais
            funcAux->vars=(struct var_table*)malloc(sizeof( var_table)); 
            funcAux->vars->name=(char *)malloc(sizeof( char)*100) ;
            strcpy(funcAux->vars->name,"return");
            funcAux->vars->type=(char *)malloc(sizeof( char)*100) ; 
            strcpy(funcAux->vars->type,funcType);
            funcAux->vars->next=NULL;
            

            funcAux->func=1;
            funcAux->name=funcName;
            funcAux->type=funcType;
            funcAux->next=NULL;
            funcAux->params=NULL;
            adicionaParametros(current,funcAux);
            adicionaVarsLocais(current,funcAux);
        }

        return;
}
void adicionaVariavelGlobal(node* current){  
    
        char* varName = (char *)malloc(sizeof( char)*100);                 // VarDcl Type Id
        strcpy(varName,current->child->brother->value);

        char* varType =(char *)malloc(sizeof( char)*100) ;              // alterar o tamanho ?
        strcpy(varType,current->child->type);
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
void adicionaParametros(node* current,func_table * funcAux){
    node* nodeAux=current->child->child; // a apontar para o id
    nodeAux=nodeAux->brother;

    if(strcmp(nodeAux->type,"FuncParams")!=0&&strcmp(nodeAux->type,"funcParams")!=0){ // porque depois do id nao vem necessariamente um type , pode ser de tipo none 
        nodeAux=nodeAux->brother;
    }

    if(!nodeAux->child){                                                                // No caso de nao ter parametros simplesmente sai porque nao ha nada para adicionar
        return;
    }

    nodeAux=nodeAux->child; // FuncParams -> ParamDecl
    param_table* paramsAux=NULL;
    param_table* paramsHead;
    param_table* paramsAux2=paramsAux;
    while(nodeAux){   // ParamDecl -> ParamDecl
        if(!paramsAux){
            paramsAux = (struct param_table*)malloc(sizeof( param_table));
            paramsAux->next=NULL;
            paramsAux->name=(char *)malloc(sizeof( char)*100); 
            strcpy(paramsAux->name,nodeAux->child->brother->value);
            paramsAux->type=(char *)malloc(sizeof( char)*100);
            strcpy(paramsAux->type,nodeAux->child->type); 
            paramsAux->type[0]=tolower(paramsAux->type[0]);
            paramsHead=paramsAux;                                     // para guardar a cabeca da lista de parametros porque e isso que tem de ser guardado
        }
        else{

            paramsAux ->next = (struct param_table*)malloc(sizeof( param_table));
            paramsAux=paramsAux->next;
            paramsAux->next=NULL;
            paramsAux->name=(char *)malloc(sizeof( char)*100); 
            strcpy(paramsAux->name,nodeAux->child->brother->value);
            paramsAux->type=(char *)malloc(sizeof( char)*100);
            strcpy(paramsAux->type,nodeAux->child->type); 
            paramsAux->type[0]=tolower(paramsAux->type[0]);

        }
        
        nodeAux=nodeAux->brother;
    }
    paramsAux2=paramsHead;
    funcAux->params=paramsHead;

}
void adicionaVarsLocais(node* current,func_table * funcAux){
    node* nodeAux=current->child->brother->child; // a apontar para o primeiro statement
    var_table *paramsAux =funcAux->vars;
    printf("--------------%s\n",current->child->brother->child->type);
    while(nodeAux){   // ParamDecl -> ParamDecl || outra coisa
       if(strcmp(nodeAux->type,"VarDecl")==0){
           printf("okasdasddas\n");
            paramsAux ->next = (struct var_table*)malloc(sizeof( var_table));
            paramsAux=paramsAux->next;
            paramsAux->next=NULL;
            paramsAux->name=(char *)malloc(sizeof( char)*100); 
            strcpy(paramsAux->name,nodeAux->child->brother->value);
            paramsAux->type=(char *)malloc(sizeof( char)*100);
            strcpy(paramsAux->type,nodeAux->child->type); 
            paramsAux->type[0]=tolower(paramsAux->type[0]);

        }
        nodeAux=nodeAux->brother;
    }

}
void printTabelaFuncoes(){ // Verificar se os \n's estao bem
    printf("\n===== Global Symbol Table =====\n");
    struct func_table *funcAux =funcHead;
    while(funcAux){
        
        printf("%s",funcAux->name);
        if(funcAux->func){
            printf("\t(");
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
    
    funcAux=funcHead;
    while(funcAux){
        if(funcAux->func){
            printf("\n===== Function ");
            printf("%s(",funcAux->name);
            struct param_table *paramsAux=funcAux->params;
            if(paramsAux){
                printf("%s",paramsAux->type);
                paramsAux=paramsAux->next;
                while(paramsAux){
                    printf(",%s",paramsAux->type);
                    paramsAux=paramsAux->next;
                }
            }
            printf(") Symbol Table =====\n");
            struct var_table *varsAux=funcAux->vars;
            while(varsAux){
                printf("%s \t %s\n",varsAux->name,varsAux->type);
                varsAux=varsAux->next;
            }
        }
        
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