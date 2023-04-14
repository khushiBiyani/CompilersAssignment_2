yacc -d SyntaxAnalyzer.y
lex SyntaxAnalyzer.l
gcc y.tab.c -ll -ll
./a.out