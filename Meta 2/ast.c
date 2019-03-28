#include "ast.h"

node *newNode(char *type, char *value)
{

    node *new = (node *)malloc(sizeof(node));
    new->type = (char *)strdup(type);
    new->child = NULL;
    new->brother = NULL;

    if (value == NULL)
    {
        new->value = NULL;
        return new;
    }
    new->value = (char *)strdup(value);
    return new;
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
    if (current == NULL)
    {
        return;
    }
    if (current != NULL)
    {
        if (current->type != NULL)
        {
            if(strcmp(current->type,"NULL")!=0){
                for (int i = 0; i < npontos; i++)
                printf("..");

                if (current->value != NULL)
                {
                    printf("%s(%s)\n", current->type, current->value);
                }
                else
                {
                    printf("%s\n", current->type);
                }
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
