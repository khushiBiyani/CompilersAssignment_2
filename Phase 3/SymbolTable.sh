yacc -d SemanticAnalyzer.y
flex SemanticAnalyzer.l
g++ y.tab.c -ll -ll
./a.out
