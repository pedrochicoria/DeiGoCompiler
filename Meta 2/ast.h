#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

typedef struct nodetree* node;
typedef struct nodetree{
    char *value;
    char * type;
    int depth;
    node child;
    node brother;
} nodetree;



node newNode(char* type,char* value);
void addBrother(node brother,node  newBrother);
void addChild(node dad,node child);
void printAST(node current, int npontos);