# Compilers Assignment 2

# Authors:
1. Ankesh Pandey (2020A7PS0104H) (https://github.com/gibsonjackson)

2. Khooshrin Pithawalla (2020A7PS2067H) (https://github.com/Khooshrin)

3. Khushi Biyani (2020A7PS0194H) (https://github.com/khushiBiyani)

4. Bhavya Tibrewala (2019B2A71404H)

5. Kanishk Yadav (2019B2A71452H)

# Mini C Compiler

This code is a Mini-C compiler that consists of 5 different phases as described below:

1. Lexical Analysis: The output of this phase is a lexical table comsisting of the line number of the lexeme, the lexeme and the token which describes the lexeme. This part also displays any invalid printf and scanf stataments by taking into account the syntax and the number of parameters to be passed into the functions.

2. Syntax Analysis: The output of this code gives "Parsing Done" if the code has no syntactical errors. Else it display "Syntax Error" signifying that there is a syntactical error in the input program.

3. Semantic Analysis: The output of this code is the static symbol table of the code and the inorder string for the abstract parse tree if there are no semantic errors. Else, semantic errors such as "Type Mismatch", "Varaible used but never declared", "Multiple Declarations" are displayed highlighting the line number causing the error. The AST inorder string is then input into a python program to visualize the AST.

4. Three Address Code: The output of this file is the representation of the three address code of the input program by displaying it in a quadruple format. This code ignores any switch case statements and function calls.

5. Code Execution: This code uses the intermediate code generated using the three address codes to simulate the code and give the correct output. This code ignores any switch case statements.


# Running the Code

For each phase, there is a local README file in their directory. Please refer to that to obtain the explicit commands to run the code or understand how to utilize the runner scripts we have created.
