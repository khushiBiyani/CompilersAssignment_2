flex scanner.l && yacc -d parser.y && gcc y.tab.c lex.yy.c -w
./a.out input.c
./executor.bin