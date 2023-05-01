yacc -d SyntaxAnalyzer.y
flex SyntaxAnalyzer.l
gcc y.tab.c -ll -ll
./a.out
