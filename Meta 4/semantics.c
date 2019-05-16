#include "semantics.h" 
#include <ctype.h> // sera que pode dar problemas COMPILE TIME ERROR ?
struct func_table *funcHead =NULL;                                      // ponteiro para a cabeça da lista ligada de funcoes
int line;
int column;
int semanticError;

void criaTabelas(node* current){
    semanticError=0;
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

            //ponteiroFuncao(current->child->child->value); // aponta para o id 
           
            node* nodeAux=current->child->brother->child;                                   //  a apontar para o primeiro statement
            func_table *funcAux=ponteiroFuncao(current->child->child->value);               // funcao onde se esta
            if(funcAux){
                while(nodeAux){
                    if(strcmp(nodeAux->type,"VarDecl")==0){                                     // adiciona variavel a tabela
                        adicionaVarsLocais(nodeAux,funcAux);
                    }
                    else if(strcmp(nodeAux->type,"NULL")!=0){                                                       // caso em que e um statement
                        anotaStatementsExpressoes(nodeAux,funcAux);
                    }
                    nodeAux=nodeAux->brother;
                }
            }
            //printf("---------------%s\n",current->child->child->value); 
            

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
    // para debugging
    /*
    printf("%s ",current->type);
    if(current->value){
        printf("%s",current->value);
    }
    printf("\n");*/
    
    if(strcmp(current->type,"VarDecl")==0){
        return "null"; 
    }
    else if(strcmp(current->type,"StrLit")==0){
        addNote(current,"string");
        return "string"; 
    }
    else if(strcmp(current->type,"Print")==0){
        anotaStatementsExpressoes(current->child,funcAux);
        return "null"; 
    }
    else if(strcmp(current->type,"ParseArgs")==0){

        char *tipo1=anotaStatementsExpressoes(current->child,funcAux);
        char *tipo2=anotaStatementsExpressoes(current->child->brother,funcAux);
        if(strcmp(tipo1,"int")!=0||strcmp(tipo2,"int")!=0){
            semanticError=1;
            printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"strconv.Atoi",tipo1,tipo2);
            addNote(current,"undef");
            return "undef";
        }
        
        addNote(current,"int");
        return "int"; 
    }
    else if(strcmp(current->type,"Return")==0){     // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! falta ver se é o mesmo tipo que a funcao!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                                                    // supostamente ja esta
        if(current->child){
            char *tipo1=anotaStatementsExpressoes(current->child,funcAux);
            if(strcmp(tipo1,funcAux->type)!=0){
                semanticError=1;
                printf("Line %d, column %d: Incompatible type %s in %s statement\n",current->child->line,current->child->column,tipo1,"return");
            }
        }
        else{
            if(strcmp("none",funcAux->type)!=0){
                semanticError=1;
                printf("Line %d, column %d: Incompatible type %s in %s statement\n",current->line,current->column,"none","return");
            }
        }
        
        return "null"; 
    }
    else if(strcmp(current->type,"RealLit")==0){
        addNote(current,"float32");
        return "float32"; 
    }
    else if(strcmp(current->type,"IntLit")==0){

        if(current->value[0]=='0'){            // é um octal ou hexadecimal
            if((current->value[1]=='x'||current->value[1]=='X')){   // é hexadecimal
                addNote(current,"int");
                return "int";
                
            }
            int i=1;

            while(current->value[i]!='\0'){     // é um octa
                if((current->value[i]<'0'||current->value[i]>'7')){
                    semanticError=1;
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
        variavelExiste(current, funcAux);
        return anotaId(current, funcAux);
    
    }
    else if(strcmp(current->type,"Not")==0){
        // resultado sempre bool
        char *tipo1=anotaStatementsExpressoes(current->child,funcAux);
        //variavelExiste(current->child, funcAux);
        if(strcmp("bool",tipo1)!=0){
            semanticError=1;
            printf("Line %d, column %d: Operator %s cannot be applied to type %s\n",current->line,current->column,"!",tipo1);
        }
        addNote(current,"bool");
        return "bool";
    }
    else if(strcmp(current->type,"Minus")==0||strcmp(current->type,"Plus")==0){
        char *tipo1=anotaStatementsExpressoes(current->child,funcAux);
        if(strcmp("int",tipo1)==0){
            addNote(current,"int");
            //variavelExiste(current->child, funcAux);
            return "int";
        }
        else if(strcmp("float32",tipo1)==0){
            addNote(current,"float32");
            //variavelExiste(current->child, funcAux);
            return "float32";
        }
        else{
            if(strcmp(current->type,"Minus")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to type %s\n",current->line,current->column,"-",tipo1);
            }
            else{
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to type %s\n",current->line,current->column,"+",tipo1);
            }
            //variavelExiste(current->child, funcAux);
            addNote(current,"undef");
            return "undef";
        }
    }
    else if(strcmp(current->type,"If")==0){
        char *tipo1=anotaStatementsExpressoes(current->child,funcAux);
        
        if(strcmp(tipo1,"bool")!=0){
            semanticError=1;
            printf("Line %d, column %d: Incompatible type %s in %s statement\n",current->child->line,current->child->column,tipo1,"if");

        }
        //variavelExiste(current->child, funcAux);
        
        anotaStatementsExpressoes(current->child->brother,funcAux);                 // bloco do if existe sempre
        anotaStatementsExpressoes(current->child->brother->brother,funcAux);        // bloco do else existe sempre mesmo que o else nao

    
    }
    else if(strcmp(current->type,"For")==0){


        if(strcmp(current->child->type,"Block")==0){

            anotaStatementsExpressoes(current->child,funcAux);
            return "null";
        }
        char *tipo1=anotaStatementsExpressoes(current->child,funcAux);
        if(strcmp(tipo1,"bool")!=0){
            semanticError=1;
            printf("Line %d, column %d: Incompatible type %s in %s statement\n",current->child->line,current->child->column,tipo1,"for");
        }
        anotaStatementsExpressoes(current->child->brother,funcAux);
        
        return "null";
    
    }
    else if(strcmp(current->type,"Call")==0){

        // verifica se a funcao existe e tudo esta como suposto 
        // qual o tipo de erro que da se tiver +/- argumentos do que e pedido o professor nao diz no enunciado
        char *tipo=anotaIdFuncao(current->child,funcAux);
        addNote(current,tipo);
        /*
        node * parametros =current->child->brother;
        while(parametros){
            anotaStatementsExpressoes(parametros,funcAux);
            parametros=parametros->brother;
        }
        
        */

        return tipo ;
    }
    
    else if(strcmp(current->type,"Assign")==0){

        // verifica se a var existe e se o tipo que lhe esta a ser dado esta correto
        char *tipo1=anotaStatementsExpressoes(current->child,funcAux);
        char *tipo2=anotaStatementsExpressoes(current->child->brother,funcAux);

        //variavelExiste(current->child, funcAux);
        //variavelExiste(current->child->brother, funcAux);


        if(strcmp(tipo1,"undef")==0||strcmp(tipo2,"undef")==0){
            semanticError=1;
            printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"=",tipo1,tipo2);   
            addNote(current,"undef");
            return tipo1;            
        }

        if(strcmp(tipo1,tipo2)==0){
            addNote(current,tipo1);
            return tipo1;
        }
        
        semanticError=1;
        printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"=",tipo1,tipo2);               
        addNote(current,tipo1);
        return tipo1;
    
    }

    else if(strcmp(current->type,"Eq")==0||strcmp(current->type,"Lt")==0||strcmp(current->type,"Gt")==0||strcmp(current->type,"Ne")==0||strcmp(current->type,"Le")==0||strcmp(current->type,"Ge")==0){
        // !! o resultado de comparacoes é sempre um booleano
        char *tipo1 =anotaStatementsExpressoes(current->child, funcAux);
        char *tipo2 =anotaStatementsExpressoes(current->child->brother, funcAux);
    

        //variavelExiste(current->child, funcAux);                    // apenas aqui ve se as variaves existem ou nao para o print aparecer depois de os outros
        //variavelExiste(current->child->brother, funcAux); 

        if(strcmp(tipo1,"bool")==0&&strcmp(tipo2,"bool")==0){ // booleanos so podem ser comparados comparados com booleanos    
            if(strcmp(current->type,"Lt")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"<",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Gt")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,">",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Le")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"<=",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Ge")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,">=",tipo1,tipo2);               
            }
            else{
                addNote(current,tipo1);
            }
            addNote(current,tipo1);
        
        }
        else if(strcmp(tipo1,"int")==0&&strcmp(tipo2,"int")==0){ // inteiros so podem ser comparados comparados com inteiros
            addNote(current,"bool");

        }
        
        else if(strcmp(tipo1,"float32")==0&&strcmp(tipo2,"float32")==0){ // floats32 so podem ser comparados comparados com floats32
            addNote(current,"bool");

        }
        else if(strcmp(tipo1,"string")==0&&strcmp(tipo2,"string")==0){ // strings so podem ser comparados comparados com strings
            addNote(current,"bool");

        }
        /*
        else if((strcmp(tipo1,"int")==0&&strcmp(tipo2,"float32")==0)||(strcmp(tipo1,"float32")==0&&strcmp(tipo2,"int")==0)){ // inteiros so podem ser comparados  com floats
            addNote(current,"bool");

        }*/
        else{
            if(strcmp(current->type,"Eq")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"==",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Lt")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"<",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Gt")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,">",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Ne")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"!=",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Le")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"<=",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Ge")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,">=",tipo1,tipo2);               
            }
            
            addNote(current,"bool");    
  
        }
                
        
        return "bool";

    }
    else if(strcmp(current->type,"Add")==0||strcmp(current->type,"Sub")==0||strcmp(current->type,"Mul")==0||strcmp(current->type,"Div")==0||strcmp(current->type,"Mod")==0){
        char *tipo1 =anotaStatementsExpressoes(current->child, funcAux);
        char *tipo2 =anotaStatementsExpressoes(current->child->brother, funcAux);
    
        if((strcmp(tipo1,"bool")==0&&strcmp(tipo2,"bool")==0)||(strcmp(tipo1,"undef")==0&&strcmp(tipo2,"undef")==0)){           // booleanos nao podem usar contas matematicas
            if(strcmp(current->type,"Add")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"+",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Sub")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"-",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Mul")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"*",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Div")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"/",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Mod")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"%",tipo1,tipo2);               
            }
            addNote(current,tipo1);
            //variavelExiste(current->child, funcAux);
            //variavelExiste(current->child->brother, funcAux);
            return "undef";
        
        }
        else if(strcmp(tipo1,tipo2)!=0){           // se sao diferentes nao aceita 
            if(strcmp(current->type,"Add")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"+",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Sub")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"-",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Mul")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"*",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Div")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"/",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Mod")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"%",tipo1,tipo2);               
            }
            addNote(current,"undef");
            //variavelExiste(current->child, funcAux);
            //variavelExiste(current->child->brother, funcAux);
            return "undef";
        
        }
        else{
            if(strcmp(tipo1,"float32")==0){
                if(strcmp(current->type,"Mod")==0){
                    semanticError=1;
                    printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"%",tipo1,tipo2);               
                    addNote(current,"undef");
                    //variavelExiste(current->child, funcAux);
                    //variavelExiste(current->child->brother, funcAux);
                    return "undef";
                }
                addNote(current,"float32");
                //variavelExiste(current->child, funcAux);
                //variavelExiste(current->child->brother, funcAux);
                return "float32";
            }
            if(strcmp(tipo1,"string")==0){
                //variavelExiste(current->child, funcAux);
                //variavelExiste(current->child->brother, funcAux);
                if(strcmp(current->type,"Add")==0){
                    addNote(current,"string");
                    return "string";               
                }
                else if(strcmp(current->type,"Sub")==0){
                    semanticError=1;
                    printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"-",tipo1,tipo2);         
                    addNote(current,"undef");
                    return "undef";      
                }
                else if(strcmp(current->type,"Mul")==0){
                    semanticError=1;
                    printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"*",tipo1,tipo2); 
                    addNote(current,"undef");
                    return "undef";                
                }
                else if(strcmp(current->type,"Div")==0){
                    semanticError=1;
                    printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"/",tipo1,tipo2); 
                    addNote(current,"undef");
                    return "undef";                
                }
                else if(strcmp(current->type,"Mod")==0){
                    semanticError=1;
                    printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"%",tipo1,tipo2); 
                    addNote(current,"undef");
                    return "undef";                
                }


                /*
                if(strcmp(current->type,"Mod")==0){
                    printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"%",tipo1,tipo2);               
                    addNote(current,"undef");
                    //variavelExiste(current->child, funcAux);
                    //variavelExiste(current->child->brother, funcAux);
                    return "undef";
                }
                addNote(current,"int");
                //variavelExiste(current->child, funcAux);
                //variavelExiste(current->child->brother, funcAux);
                return "int";*/
            }
            

            addNote(current,tipo1);
            //variavelExiste(current->child, funcAux);
            //variavelExiste(current->child->brother, funcAux);
            return tipo1;
        }
        
        return tipo1;

    }
    else if(strcmp(current->type,"And")==0||strcmp(current->type,"Or")==0){
        char *tipo1 =anotaStatementsExpressoes(current->child, funcAux);
        char *tipo2 =anotaStatementsExpressoes(current->child->brother, funcAux);
    
        //variavelExiste(current->child, funcAux);                    // apenas aqui ve se as variaves existem ou nao para o print aparecer depois de os outros
        //variavelExiste(current->child->brother, funcAux); 

        if(strcmp(tipo1,"bool")==0&&strcmp(tipo2,"bool")==0){           
            addNote(current,tipo1);
            return "bool";
        
        }
        else {           
            if(strcmp(current->type,"And")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"&&",tipo1,tipo2);               
            }
            else if(strcmp(current->type,"Or")==0){
                semanticError=1;
                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",current->line,current->column,"||",tipo1,tipo2);                           
            }

        
        }
        addNote(current,"bool");
        return "bool";

    }
    else if(strcmp(current->type,"Block")==0){
        
        
        if(current->child){
            
            node *nodeAux = current->child;
            
            while(nodeAux){
                
                anotaStatementsExpressoes(nodeAux, funcAux);
                nodeAux=nodeAux->brother;
            }
            /* para que é isto?
            if(current->brother){
                nodeAux = current->child;
                while(nodeAux){
                    anotaStatementsExpressoes(nodeAux, funcAux);
                    nodeAux=nodeAux->brother;
                }
            }*/
        }
            
    }
    // debugging para chegar a variaveis onde nao consegue chegar
    /*
    else{
        if(current->child)
            anotaStatementsExpressoes(current->child, funcAux);
    }*/
    return "null";
}
char* anotaIdFuncao(node* current, func_table* funcAux){
   
        func_table *funcAux2=funcHead;                    // Ve nas variaveis globais   
        while(funcAux2){
            if(funcAux2->func){
                if(strcmp(funcAux2->name,current->value)==0){
                    node* nodeAux=current->brother;
                    param_table *paramsAux=funcAux2->params;
                    int params1=0;          // conta o numero de parametros do no 
                    int params2=0;          // conta o numero de parametros que estao na arvore
                    int invalido=0;
                    char strAux[1024]="\0";
                    strcat(strAux,"(");
                    while(nodeAux||paramsAux){
                        char *tipo1;
                        if(nodeAux){            // precisa de anotar todos os nos , mesmo que nao haja parametros , por isso e que nao esta no if asseguir
                            tipo1=anotaStatementsExpressoes(nodeAux,funcAux);
                            if(strcmp(strAux,"(")==0){
                                strcat(strAux,tipo1);
                            }
                            else{
                                strcat(strAux,",");
                                strcat(strAux,tipo1);
                            }
                        }
                        if(nodeAux&&paramsAux){
                            //printf("%s %s\n",tipo1,paramsAux->type);
                            if(strcmp(tipo1,paramsAux->type)!=0){
                                invalido=1;
                            }
                        }
                        if(nodeAux){
                            params1++;
                            nodeAux=nodeAux->brother;
                        }
                        if(paramsAux){
                            paramsAux=paramsAux->next;
                            params2++;
                        }
                    }
                    strcat(strAux,")");
                    /*
                    printf("%d %d\n",params1,params2);
                    printf("%d\n",invalido);*/
                    if(params1==params2&&invalido==0){
                            // esta tudo bem anota o que é suposto e da return do seu tipo
                            addNote(current,strAux);
                            return funcAux2->type;
                    }
                    semanticError=1;
                    printf("Line %d, column %d: Cannot find symbol %s%s\n",current->line,current->column,current->value,strAux);
                    addNote(current,"undef");
                    return "undef";
                
                }
            }
            funcAux2=funcAux2->next;
        }
        // para o caso de a variavel nao existir
        
        node* nodeAux=current->brother;
        char strAux[1024]="\0";
        strcat(strAux,"(");
        while(nodeAux){
            char *tipo1=anotaStatementsExpressoes(nodeAux,funcAux);
            if(strcmp(strAux,"(")==0){
                strcat(strAux,tipo1);
            }
            else{
                    strcat(strAux,",");
                    strcat(strAux,tipo1);
            }            
            nodeAux=nodeAux->brother;
        }
        strcat(strAux,")");

        semanticError=1;
        // chegou ao fim quer dizer que nao ha mais variaveis e esta nao foi encontrada
        printf("Line %d, column %d: Cannot find symbol %s%s\n",current->line,current->column,current->value,strAux);
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

        


        // printf("Line %d, column %d: Cannot find symbol %s\n",current->line,current->column,current->value);

        // acaba por nao ser preciso porque o professor ordena os erros
        /*  ------------------------------------------------------------------------
            O print de variavel nao encontrada vai ser feita noutra funcao 
            p.e
            for 1 < undeclared {
            
            };
            Dava :
            Line 32, column 13: Cannot find symbol undeclared
            Line 32, column 11: Operator < cannot be applied to types int, undef
            É suposto esta :
            Line 32, column 11: Operator < cannot be applied to types int, undef 
            Line 32, column 13: Cannot find symbol undeclared

            Entao agora ele anota aqui o tipo e depois de anotado no "<" se o filho for um id ele vai verificar se ele existe ou nao e so ai faz print do erro

        */
        addNote(current,"undef");
        return "undef";
}
void variavelExiste(node* current, func_table* funcAux){
    if(strcmp("Id",current->type)!=0){
        return;
    }
    var_table *varAux=funcAux->vars;                    // Ve nas variaveis locais    
        while(varAux){

            if(strcmp(varAux->name,current->value)==0){
                return ;
            }
            varAux=varAux->next;
        }
        param_table *parAux=funcAux->params;                    // Ve nos parametros   
        while(parAux){

            if(strcmp(parAux->name,current->value)==0){

                return ;
            }
            parAux=parAux->next;
        }
        func_table *funcAux2=funcHead;                    // Ve nas variaveis globais   
        while(funcAux2){
            if(!funcAux2->func){
                if(strcmp(funcAux2->name,current->value)==0){
                    
                    return;
                }
            }
            
            funcAux2=funcAux2->next;
        }
        semanticError=1;
        // chega ao fim o que quer dizer que a variavel nao existe
        printf("Line %d, column %d: Cannot find symbol %s\n",current->line,current->column,current->value);
        
}
func_table* ponteiroFuncao(char* funcaoNome){               // retorna um ponteiro para um funcao
    struct func_table *funcAux =funcHead;
    while(funcAux){
        if(funcAux->func){
            if(strcmp(funcAux->name,funcaoNome)==0){
                if(funcAux->declared==0){
                    funcAux->declared=1;
                    return funcAux;
                }
            return NULL;
        }

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

         if (existeVariavelOuFuncao(funcName,current->child->child,1)){                           // devolve 0 se a variavel existe
            return NULL;
        }   


        if(!funcHead){                                                       // no caso em que nao foi adicionada nenhuma funcao/variavel  

            funcHead=(struct func_table*)malloc(sizeof( func_table));
         
            if(strcmp(funcType,"funcParams")==0||strcmp(funcType,"FuncParams")==0){
                funcType="none";    
            }

            funcHead->params=NULL;
            funcHead->func=1;
            funcHead->declared=0;
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
            funcAux->declared=0;
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
        
        if (existeVariavelOuFuncao(varName,current->child->brother,2)){                           // devolve 0 se a variavel existe
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
    param_table* paramsHead=NULL;
    param_table* paramsAux2=paramsHead;
    int found=0;
    while(nodeAux){   // ParamDecl -> ParamDecl
        found=0;
        paramsAux2=paramsHead;
        while(paramsAux2){
            
            if(strcmp(paramsAux2->name,nodeAux->child->brother->value)==0){  // a variavel ja é um parametro
                found=1;
                semanticError=1;
                printf("Line %d, column %d: Symbol %s already defined\n",nodeAux->child->brother->line,nodeAux->child->brother->column,nodeAux->child->brother->value);
                //printf("%s---\n",paramsAux2->name);
            }
            paramsAux2=paramsAux2->next;
            
        }
        if(!found){
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
            semanticError=1;
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
        if (usedVar(nodeAux->brother,varsAux->name)==0){
            semanticError=1;
            printf("Line %d, column %d: Symbol %s declared but never used\n",nodeAux2->line,nodeAux2->column,varsAux->name);
        }
        return;
    }
   
    if(strcmp(varsAux->name,nodeAux->child->brother->value)==0){ // compara so a cabeca da lista
        //printf("--------------%s\n",varsAux->name); 
        semanticError=1;
        printf("Line %d, column %d: Symbol %s already defined\n",nodeAux2->line,nodeAux2->column,nodeAux2->value);
        return;
    }
    while(varsAux->next){                                       // compara o resto dos elemntos

        if(strcmp(varsAux->next->name,nodeAux->child->brother->value)==0){
            semanticError=1;
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
    if (usedVar(nodeAux->brother,varsAux->name)==0){
        semanticError=1;
        printf("Line %d, column %d: Symbol %s declared but never used\n",nodeAux2->line,nodeAux2->column,varsAux->name);
    }

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
int existeVariavelOuFuncao(char * name,node* current,int opcao){
    // opcao :
    // 1 para funcao
    // 2 para variavel
    struct func_table *funcAux =funcHead;
    while(funcAux){

        if(strcmp(funcAux->name,name)==0){
            if(opcao==1){
                semanticError=1;
                printf("Line %d, column %d: Symbol %s already defined\n",current->line,current->column,name);
                /*printf("Line %d, column %d: Symbol %s(",current->line,current->column,name);
                node* nodeAux=current; // vai para id
                nodeAux=nodeAux->brother;
                if(nodeAux->brother)            // no caso de a funcao nao ser none
                    nodeAux=nodeAux->brother;

                nodeAux=nodeAux->child;
                if(nodeAux){
                    char* tipo=nodeAux->child->type;
                    tipo[0]=tolower(tipo[0]);
                    printf("%s %s",nodeAux->child->brother->value,tipo);
                    nodeAux=nodeAux->brother;
                }
                while(nodeAux){
                    char* tipo=nodeAux->child->type;
                    tipo[0]=tolower(tipo[0]);
                    printf(",%s %s",nodeAux->child->brother->value,tipo);
                    nodeAux=nodeAux->brother;
                }
                printf(") already defined\n");*/
                return 1;
            }
            else{
                semanticError=1;
                printf("Line %d, column %d: Symbol %s already defined\n",current->line,current->column,name);
                return 1;
            }
            
        }
        funcAux=funcAux->next;
    }
    return 0;
}
int usedVar(node* current,char *varName){ // retorna 0 se nao encontrar a variavel , retorna 1 se a variavel existe
    if(!current){
        return 0;
    }
    if(strcmp(current->type,"Id")==0){
        if(strcmp(current->value,varName)==0){
            return 1;
        }
        else{
            return usedVar(current->child,varName) || usedVar(current->brother,varName);
        }
    }
    else{
        return usedVar(current->child,varName) || usedVar(current->brother,varName);
    }
    

}


