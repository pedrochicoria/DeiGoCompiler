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
    printf("Chega aqui\n");
    
    node * node = current;

    if (node == NULL)
    {
        return;
    }
    if (node->type != NULL)
    {
        for (int i = 0; i < npontos; i++)
            printf("..");

        printf("%s\n", node->type);
    }

    printAST(node->child, npontos + 1);
    printAST(node->brother, npontos);
}
