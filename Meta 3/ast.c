#include "ast.h"

node *newNode(char *type, char *value,int line,int column)
{

    node *new = (node *)malloc(sizeof(node));
    new->type = (char *)strdup(type);
    new->child = NULL;
    new->brother = NULL;
    new->line = line;
    new->column=column;
    new->note=NULL;
    if (value == NULL)
    {
        new->value = NULL;
        return new;
    }
    new->value = (char *)strdup(value);
    
    return new;
}
void addNote(node *nodeAux,char* note){

    nodeAux->note=(char *)strdup(note);
    return;
}
void addBrother(node *brother, node *newBrother)
{
    if (brother != NULL && newBrother != NULL)
    {

        node *auxBrother = brother;

        while (auxBrother->brother != NULL)
        {
            auxBrother = auxBrother->brother;
        }
        auxBrother->brother = newBrother;
    }
}
void addChild(node *dad, node *child)
{
    if (dad != NULL && child != NULL)
    {
        dad->child = child;
    }
}
void printAST(node *current, int npontos)
{
    
    if (current != NULL)
    {
        if (current->type != NULL)
        {
            if(strcmp(current->type,"NULL")!=0){
                for (int i = 0; i < npontos; i++)
                printf("..");

                // para ver se as linhas e as colunas dos nos estao bem
                //printf("%d %d ", current->line, current->column);
                
                if (current->value != NULL)
                {
                    printf("%s(%s)", current->type, current->value);
                }
                else
                {
                    printf("%s", current->type);
                }
                if(current->note!=NULL){

                    printf(" - %s",current->note);
                }
                printf("\n");
                if (current->child != NULL)
                    printAST(current->child, npontos + 1);
                if (current->brother != NULL)
                    printAST(current->brother, npontos);
            }
                else{
                    if (current->child != NULL)
                        printAST(current->child, npontos );
                    if (current->brother != NULL)
                        printAST(current->brother, npontos);
            }
            
        }

        
    }
}
void deleteAst(node* current ){
    if (current==NULL)
        return;
    if (!current->type)
    {
        free(current->type);
        current->type=NULL;

    }
    if(!current->value){
        free(current->value);
        current->value=NULL;
    }

    deleteAst(current->child);
    current->child = NULL;
    
    deleteAst(current->brother);
    current->brother = NULL;

    free(current);
    current = NULL;
}
