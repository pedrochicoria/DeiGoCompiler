#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

typedef struct node{
	struct node *child;
    struct node *brother;
    char* value;
    char* type;
	
} node;



node *newNode(char* type,char* value);
void addBrother(node* brother,node * newBrother);
void addChild(node *dad,node *child);
void printAST(node *current, int npontos);