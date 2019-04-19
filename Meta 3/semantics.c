#include "semantics.h" 
#include <ctype.h> // sera que pode dar problemas COMPILE TIME ERROR ?
struct func_table *funcHead =NULL;                                      // ponteiro para a cabeça da lista ligada de funcoes
int line;
int column;

void criaTabelas(node* current){

    current=current->child;
    node* funcVarHead=current;

    while(strcmp(current->type,"FuncDecl")==0||strcmp(current->type,"VarDecl")==0){

        if(strcmp(current->type,"FuncDecl")==0){

            adicionaFuncao(current);
        }
        else if(strcmp(current->type,"VarDecl")==0){
            adicionaVariavelGlobal(current);
        }

        current=current->brother;           // avanca aqui
        if (current==NULL)
            break;
    }
    
    current=funcVarHead;
    
    while(strcmp(current->type,"FuncDecl")==0||strcmp(current->type,"VarDecl")==0){
        
        if(strcmp(current->type,"FuncDecl")==0){ 
                                                       
            //ponteiroFuncao(current->child->child->value);
            node* nodeAux=current->child->brother->child;                                   //  a apontar para o primeiro statement
            func_table *funcAux=ponteiroFuncao(current->child->child->value);               // funcao onde se esta
            while(nodeAux){
                if(strcmp(nodeAux->type,"VarDecl")==0){                                     // adiciona variavel a tabela
                    adicionaVarsLocais(nodeAux,funcAux);
                }
                else{                                                       // caso em que e um statement
                    anotaStatementsExpressoes(nodeAux,funcAux);
                }
                nodeAux=nodeAux->brother;
            }

        }

        current=current->brother;           // avanca aqui
        if (current==NULL)
            break;
    }
    
    /* 

    funcao(){
        var a;
    }
    var a;
    
    onde e que ele da erro ?  no primeiro a ou no segundo

    supostamente(originakl GO) nao da erro
    */
    
}
char* anotaStatementsExpressoes(node *current, func_table *funcAux){
    /*
    printf("%s ",current->type);
    if(current->value){
        printf("%s",current->value);
    }
    printf("\n");
    */
    if(strcmp(current->type,"IntLit")==0){
        if(current->value[0]=='0'&&(current->value[1]=='x'||current->value[1]=='X')){            // é um octal
            int i=2;
            while(current->value[i]!='\0'){
                if(!((current->value[i]>='A'&& current->value[i]<='F')||(current->value[i]>='a'&&current->value[i]<='f')||(current->value[i]>='0'&&current->value[i]<='8'))){
                    printf("Line %d, column %d: Invalid octal constant: %s\n",current->line,current->column,current->value);
                    addNote(current,"int");
                    return "int";

                    
                }
                i++;
            }

        }
        addNote(current,"int");
        return "int";
    }
    
    else if(strcmp(current->type,"Id")==0){

        return anotaIdFuncao(current, funcAux);
    
    }
    else if(strcmp(current->type,"Call")==0){

        // verifica se a funcao existe e tudo esta como suposto 
        // qual o tipo de erro que da se tiver +/- argumentos do que e pedido o professor nao diz no enunciado
        char *tipo=anotaStatementsExpressoes(current->child,funcAux);
        addNote(current,tipo);
        node * parametros =current->child->brother;
        while(parametros){
            anotaStatementsExpressoes(parametros,funcAux);
            parametros=parametros->brother;
        }
        return tipo ;
    
    }
    else if(strcmp(current->type,"Eq")==0||strcmp(current->type,"Lt")==0||strcmp(current->type,"Gt")==0||strcmp(current->type,"Ne")==0||strcmp(current->type,"Le")==0||strcmp(current->type,"Ge")==0){
        char *tipo1 =anotaStatementsExpressoes(current->child, funcAux);
        char *tipo2 =anotaStatementsExpressoes(current->child->brother, funcAux);
    
        if(strcmp(tipo1,"bool")==0&&strcmp(tipo2,"bool")==0){ // booleanos so podem ser comparados comparados com booleanos    
            if(strcmp(current->type,"Lt")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"<",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Gt")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,">",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Le")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"<=",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Ge")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,">=",tipo1,tipo2);               
            }
            else{
                addNote(current,tipo1);
            }
           
        
        }
        else if(strcmp(tipo1,"int")==0&&strcmp(tipo2,"int")==0){ // inteiros so podem ser comparados comparados com inteiros
            addNote(current,tipo1);

        }
        else if(strcmp(tipo1,"float32")==0&&strcmp(tipo2,"float32")==0){ // floats32 so podem ser comparados comparados com floats32
            addNote(current,tipo1);

        }
        else if(strcmp(tipo1,"string")==0&&strcmp(tipo2,"string")==0){ // strings so podem ser comparados comparados com strings
            addNote(current,tipo1);

        }
        else{
            if(strcmp(current->type,"Eq")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"==",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Lt")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"<",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Gt")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,">",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Ne")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"!=",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Le")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"<=",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Ge")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,">=",tipo1,tipo2);               
            }
            
            addNote(current,"undef");           
            if(current->brother!=NULL){
                anotaStatementsExpressoes(current->brother, funcAux);
            }
            return "undef";
        }
        if(current->brother!=NULL){
            anotaStatementsExpressoes(current->brother, funcAux);
        }
        return tipo1;

    }
    else if(strcmp(current->type,"Plus")==0||strcmp(current->type,"Sub")==0||strcmp(current->type,"Star")==0||strcmp(current->type,"Div")==0||strcmp(current->type,"Mod")==0){
        char *tipo1 =anotaStatementsExpressoes(current->child, funcAux);
        char *tipo2 =anotaStatementsExpressoes(current->child->brother, funcAux);
    
        if(strcmp(tipo1,"bool")==0&&strcmp(tipo2,"bool")==0){           // booleanos nao podem usar contas matematicas
            if(strcmp(current->type,"Plus")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"+",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Sub")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"-",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Star")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"*",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Div")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"/",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Mod")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"%",tipo1,tipo2);               
            }
            else{
                addNote(current,tipo1);
            }
           
        
        }
        else if(strcmp(tipo1,"bool")==0||strcmp(tipo2,"bool")==0){           // booleanos nao podem usar contas matematicas
            if(strcmp(current->type,"Plus")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to type %s\n",current->line,current->column,"+",tipo1);               
            }
            else if(strcmp(current->type,"Minus")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to type %s\n",current->line,current->column,"-",tipo1);                           
            }
            else if(strcmp(current->type,"Star")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to type %s\n",current->line,current->column,"*",tipo1);                            
            }
            else if(strcmp(current->type,"Div")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to type %s\n",current->line,current->column,"/",tipo1);                             
            }
            else if(strcmp(current->type,"Mod")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to type %s\n",current->line,current->column,"%",tipo1); 
            }
            else{
                addNote(current,tipo1);
            }
           
        
        }
        else if(strcmp(tipo1,"int")==0&&strcmp(tipo2,"int")==0){ // inteiros so podem ser comparados comparados com inteiros
            addNote(current,tipo1);

        }
        else if(strcmp(tipo1,"float32")==0&&strcmp(tipo2,"float32")==0){ // floats32 so podem ser comparados comparados com floats32
            addNote(current,tipo1);

        }
        else if(strcmp(tipo1,"string")==0&&strcmp(tipo2,"string")==0){ // strings so podem ser comparados comparados com strings
            addNote(current,tipo1);

        }
        else{
            if(strcmp(current->type,"Eq")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"==",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Lt")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"<",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Gt")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,">",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Ne")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"!=",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Le")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"<=",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Ge")==0){
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,">=",tipo1,tipo2);               
            }
            
            addNote(current,"undef");           
            if(current->brother!=NULL){
                anotaStatementsExpressoes(current->brother, funcAux);
            }
            return "undef";
        }
        if(current->brother!=NULL){
            anotaStatementsExpressoes(current->brother, funcAux);
        }
        return tipo1;

    }
    else if(strcmp(current->type,"Block")){
        if(current->child)
            anotaStatementsExpressoes(current->child, funcAux);
    }
    
    else{
        if(current->child)
            anotaStatementsExpressoes(current->child, funcAux);
    }
    return NULL;
}
char* anotaIdFuncao(node* current, func_table* funcAux){
   
        func_table *funcAux2=funcHead;                    // Ve nas variaveis globais   
        while(funcAux2){
            if(funcAux2->func){
                if(strcmp(funcAux2->name,current->value)==0){
                    addNote(current,funcAux2->type);
                    return funcAux2->type;
                }
            }
            
            funcAux2=funcAux2->next;
        }
        // chegou ao fim quer dizer que nao ha mais variaveis e esta nao foi encontrada
        printf("Line %d, column %d: Cannot find symbol %s\n",current->line,current->column,current->value);
        addNote(current,"undef");
        return "undef";
}
char* anotaId(node* current, func_table* funcAux){
    var_table *varAux=funcAux->vars;                    // Ve nas variaveis locais    
        while(varAux){

            if(strcmp(varAux->name,current->value)==0){

                addNote(current,varAux->type);
                return varAux->type;
            }
            varAux=varAux->next;
        }
        param_table *parAux=funcAux->params;                    // Ve nos parametros   
        while(parAux){

            if(strcmp(parAux->name,current->value)==0){
                addNote(current,parAux->type);
                return parAux->type;
            }
            parAux=parAux->next;
        }
        func_table *funcAux2=funcHead;                    // Ve nas variaveis globais   
        while(funcAux2){
            if(!funcAux2->func){
                if(strcmp(funcAux2->name,current->value)==0){
                    addNote(current,funcAux2->type);
                    return funcAux2->type;
                }
            }
            
            funcAux2=funcAux2->next;
        }
        // chegou ao fim quer dizer que nao ha mais variaveis e esta nao foi encontrada
        printf("Line %d, column %d: Cannot find symbol %s\n",current->line,current->column,current->value);
        addNote(current,"undef");
        return "undef";
}
func_table* ponteiroFuncao(char* funcaoNome){               // retorna um ponteiro para um funcao
    struct func_table *funcAux =funcHead;
    while(funcAux){
        if(strcmp(funcAux->name,funcaoNome)==0){

            return funcAux;
        }
        funcAux=funcAux->next;
    }
    return NULL;
}
func_table* adicionaFuncao(node* current){                                          // !!!!!!! NAO ESTA A VERIFICAR SE EXISTEM VARIAVEIS COM IDS IGUAIS !!!!!!!!!!!  é suposto ?
     
        struct func_table *funcAux =funcHead;

        char* funcName = (char *)malloc(sizeof( char)*100);                  // funcDcl FuncHeader Id
        strcpy(funcName,current->child->child->value);

        char* funcType = (char *)malloc(sizeof( char)*100);             // alterar o tamanho ?   
        strcpy(funcType,current->child->child->brother->type);  
        funcType[0]=tolower(funcType[0]);

         if (existeVariavelOuFuncao(funcName,current->child->child)){                           // devolve 0 se a variavel existe
            return NULL;
        }   


        if(!funcHead){                                                       // no caso em que nao foi adicionada nenhuma funcao/variavel  

            funcHead=(struct func_table*)malloc(sizeof( func_table));
         
            if(strcmp(funcType,"funcParams")==0||strcmp(funcType,"FuncParams")==0){
                funcType="none";    
            }

            funcHead->params=NULL;
            funcHead->func=1;
            funcHead->name=funcName;
            funcHead->type=funcType;
            funcHead->next=NULL;
            funcHead->params=NULL;
            funcHead->vars=NULL;

            adicionaParametros(current,funcHead);                   // os parametros podem ser adicionados porque podem ter o mesmo nome que variaveis globais/ funcoes
            //adicionaVarsLocais(current,funcHead);
            return funcHead;

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

            funcAux->func=1;
            funcAux->name=funcName;
            funcAux->type=funcType;
            funcAux->next=NULL;
            funcAux->params=NULL;
            funcAux->vars=NULL;
            adicionaParametros(current,funcAux);                    // os parametros podem ser adicionados porque podem ter o mesmo nome que variaveis globais/ funcoes
            //adicionaVarsLocais(current,funcAux);

            return funcAux;
        }

        
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
void adicionaVarsLocais(node* nodeAux,func_table * funcAux){
    param_table *parsAux =funcAux->params;
    node *nodeAux2=nodeAux->child->brother;
    while(parsAux!=NULL){
        if(strcmp(parsAux->name,nodeAux2->value)==0){
            printf("Line %d, column %d: Symbol %s already defined\n",nodeAux2->line,nodeAux2->column,nodeAux2->value);
            return;
        }
        parsAux=parsAux->next;  
    }    
    var_table *varsAux =funcAux->vars;

    if(!varsAux){
                
        varsAux= (struct var_table*)malloc(sizeof( var_table));
        varsAux->next=NULL;
        varsAux->name=(char *)malloc(sizeof( char)*100); 
        strcpy(varsAux->name,nodeAux->child->brother->value);
        varsAux->type=(char *)malloc(sizeof( char)*100);
        strcpy(varsAux->type,nodeAux->child->type); 
        varsAux->type[0]=tolower(varsAux->type[0]);
        funcAux->vars=varsAux;
        return;
    }
    if(strcmp(varsAux->name,nodeAux->child->brother->value)==0){ // compara so a cabeca da lista
        
        printf("Line %d, column %d: Symbol %s already defined\n",nodeAux2->line,nodeAux2->column,nodeAux2->value);
        return;
    }
    while(varsAux->next){                                       // compara o resto dos elemntos

        if(strcmp(varsAux->next->name,nodeAux->child->brother->value)==0){
            printf("Line %d, column %d: Symbol %s already defined\n",nodeAux2->line,nodeAux2->column,nodeAux2->value);
            return;
        }
        varsAux=varsAux->next;
    }

    varsAux->next= (struct var_table*)malloc(sizeof( var_table));
    varsAux=varsAux->next;
    varsAux->next=NULL;
    varsAux->name=(char *)malloc(sizeof( char)*100); 
    strcpy(varsAux->name,nodeAux->child->brother->value);
    varsAux->type=(char *)malloc(sizeof( char)*100);
    strcpy(varsAux->type,nodeAux->child->type); 
    varsAux->type[0]=tolower(varsAux->type[0]);

}
void printTabelaFuncoes(){ // Verificar se os \n's estao bem 
                                                                            

    printf("===== Global Symbol Table =====\n");
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
        else{
            printf("\t");
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
            printf("%s\t\t%s\n","return",funcAux->type);         // print do return 

            paramsAux=funcAux->params;
            while(paramsAux){
                printf("%s\t\t%s\tparam\n",paramsAux->name,paramsAux->type); // print dos parametros como variaveis locais
                paramsAux=paramsAux->next;
            }

            struct var_table *varsAux=funcAux->vars;  // print das variaveis locais
            while(varsAux){

                printf("%s\t\t%s\n",varsAux->name,varsAux->type);
                varsAux=varsAux->next;
            }
        }
        
        funcAux=funcAux->next;
    }
    printf("\n");
}
int existeVariavelOuFuncao(char * name,node* current){
    struct func_table *funcAux =funcHead;
    while(funcAux){

        if(strcmp(funcAux->name,name)==0){

            printf("Line %d, column %d: Symbol %s already defined\n",current->line,current->column,name);
            return 1;
        }
        funcAux=funcAux->next;
    }
    return 0;
}


