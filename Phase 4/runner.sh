yacc -d TAG.y
flex TAG.l
gcc y.tab.c -ll -ll
./a.out