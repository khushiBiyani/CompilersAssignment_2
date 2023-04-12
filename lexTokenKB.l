%{
    #include <stdio.h>
    int printf_count = 0;
    int scanf_count = 0;
%}
DigWO [1-9]
DigW [0-9]

%% 
[-+]?[1-9][0-9]*([eE][+-]?[1-9][0-9]*)? {printf("%s - INTEGER\n",yytext);}
[-+]?[0-9]*\.[0-9]+([eE][+-]?[1-9][0-9]*)? {printf("\tFLOAT\n",yytext);}

int|else|char|float|if|while|for|switch|case|default {printf("%s - Keyword\n",yytext);}

"+" {ECHO; printf("\tAddition Operator\n");}
"-" {ECHO; printf("\tSubtraction Operator\n");}
"*" {ECHO; printf("\tMultiplication Operator\n");}
"=" {ECHO; printf("\tAssignment Operator\n");}
"%" {ECHO; printf("\tModulus Operator\n");}
"/" {ECHO; printf("\tDivision Operator\n");}
">" {ECHO; printf("\tLeft Greater Operator\n");}
"<" {ECHO; printf("\tRight Greater Operator\n");}
">=" {ECHO; printf("\tLeft Greater than or Equal Operator\n");}
"<=" {ECHO; printf("\tRight Greater than or Equal Operator\n");}
"+=" {ECHO; printf("\tAdd & Assign Operator\n");}
"-=" {ECHO; printf("\tSubtract & Assign Operator\n");}
"/=" {ECHO; printf("\tDivide & Assign Operator\n");}
"*=" {ECHO; printf("\tMultiply & Assign Operator\n");}
"%=" {ECHO; printf("\tModulus & Assign Operator\n");}
"==" {ECHO; printf("\tEqual to Operator\n");}
"!=" {ECHO; printf("\tNot Equal to Operator\n");}
"&=" {ECHO; printf("\tBitwise AND & Assign Operator\n");}
"^=" {ECHO; printf("\tBitwise XOR & Assign Operator\n");}
"|=" {ECHO; printf("\tBitwise OR & Assign Operator\n");}
"&&" {ECHO; printf("\tLogical AND Operator\n");}
"||" {ECHO; printf("\tLogical OR Operator\n");}
"!"  {ECHO; printf("\tLogical NOT Operator\n");}
"~"  {ECHO; printf("\tBitwise NOT Operator\n");}
"?"  {ECHO; printf("Ternary conditional operator\n");}
"++" {ECHO; printf("\tIncrement Operator\n");}
"--" {ECHO; printf("\tDecrement Operator\n");}
"<<" {ECHO; printf("\tLeft Shift Operator\n");}
"<<=" {ECHO; printf("\tLeft Shift and Assign Operator\n");}
">>" {ECHO; printf("\tRight Shift Operator\n");}
">>=" {ECHO; printf("\tRight Shift and Assign Operator\n");}
"&" {ECHO; printf("\tBitwise AND Operator\n");}
"^" {ECHO; printf("\tBitwise XOR Operator\n");}
"|" {ECHO; printf("\tBitwise OR Operator\n");}

"printf" {printf_count++;}
"scanf" {scanf_count++;}

[a-zA-Z_][a-zA-Z0-9_]* {printf("%s - Identifier\n",yytext);}

[.,;:(){}\[\]]   {printf("%s - Punctuator\n",yytext);}

.|\n ; 	

%%

int main() {
    yylex();
    printf("Number of valid print statements: %d\n", printf_count);
    printf("Number of valid scan statements: %d\n", scanf_count);
    return 0;
}