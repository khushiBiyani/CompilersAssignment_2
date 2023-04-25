yacc -d AST.y
flex AST.l
g++ y.tab.c -ll -ll
./a.out
