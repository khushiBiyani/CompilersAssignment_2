yacc -d newnewTag.y
flex newTag.l
gcc y.tab.c -ll -ll
./a.out