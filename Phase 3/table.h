#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <stack>
#include <set>
#define size 500

struct table {
    int lineNo;
    char* lexeme;
    char* dataType;
    float value;
    bool isFunction;
    bool isArray;
    int arrayDimension;
    char* parameterList [50];
    int parameterCount;
    int depthInTree;
    struct tableEntry *next;
}

struct depth{
    int startLine;
    int endLine;
    int depth;
}



