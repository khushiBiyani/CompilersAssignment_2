typedef enum { cnst, iden , oprt } nodeEnum;

struct cnstNode {
    char value[1000];
};

struct idenNode{
    char name[1000];
} ;

struct operNode{
    int oper;
    int oprCount;
    struct nodeTypeTag *op[1];
} ;

typedef struct nodeTypeTag
{

    nodeEnum type;
    union 
    {
        cnstNode constant;
        idenNode identify;
        operNode opr;
    };
}nodeType;
