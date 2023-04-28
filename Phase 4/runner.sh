yacc -d TAC.y
flex TAC.l
gcc y.tab.c -ll -ll
./a.out