yacc -d SyntaxAnalyzer.y
flex SyntaxAnalyzer.l
g++ y.tab.c -ll -ll
./a.out
