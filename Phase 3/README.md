# This Phase covers the Semantic Analysis of input program

To run the code to generate static symbol table:

run command

./bash SymbolTable.sh

The code can also explicitly be run using the commands:
1. yacc -d SemanticAnalyzer.y
2. flex SemanticAnalyzer.l
3. g++ y.tab.c -ll -ll
4. ./a.out


To run the code to generate inorder string for abtract syntax tree (AST):

run command

./bash AST.sh

The code can also explicitly be run using the commands:
1. yacc -d AST.y
2. flex AST.l
3. g++ y.tab.c -ll -ll
4. ./a.out

This gives the AST STRING as output written to the text file astString.txt

paste the AST STRING in the drawTree.py and run

python drawTree.py or python3 drawTree.py depending on the python version installed

This displays the abstract syntax tree using NLTK Library

Both the lex and yacc files take input from the file "Test Cases/input.c"
