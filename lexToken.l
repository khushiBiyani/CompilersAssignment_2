%{
    #include <stdio.h>
%}
DigWO [1-9]
DigW [0-9]
%% 



[-+]?[1-9][0-9]*([eE][+-]?[1-9][0-9]*)? {ECHO; printf("\tINTEGER\n");}
[-+]?[0-9]*\.[0-9]+([eE][+-]?[1-9][0-9]*)? {ECHO; printf("\tFLOAT\n");}
["int" | "else" | "char" | "float" | "if" | "while" | "for" | "switch" | "case" | "default"] {ECHO; printf("\tKeyword\n");}
"+" {ECHO; printf("\tAddition Operator\n");}
"-" {ECHO; printf("\tSubtraction Operator\n");}
"*" {ECHO; printf("\tMultiplication Operator\n");}
"=" {ECHO; printf("\tAssignment Operator\n");}
"%" {ECHO; printf("\tModulus Operator\n");}
"/" {ECHO; printf("\tDivision Operator\n");}
"scanf"    {printf("Scanf encountered.\n");}
"printf"   {printf("Printf encountered.\n");}
[a-zA-Z_][a-zA-Z0-9_]* {ECHO; printf("\tIdentifier\n");}
[.,;:(){}\[\]]   { ECHO ; printf("\tPunctuator\n");}
.|\n ; 	

%%

int main() {
    yylex();
    return 0;
}
