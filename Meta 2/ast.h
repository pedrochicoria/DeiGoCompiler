#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

typedef struct nodetree* node;
typedef struct nodetree{
    char *value;
    char * label;
    int depth;
    node son;
    node brother;
} nodetree;