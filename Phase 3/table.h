#include <stdio.h>
#include <stdlib.h>
#define size 10000

struct table {
    int lineNo;
    char* lexeme;
    char* dataType;
    char* value;
    bool isFunction;
    bool isArray;
    int arrayDimension[size];
    char* parameterList [size];
    int parameterCount;
    int depthInTree;
    struct tableEntry *next;
};