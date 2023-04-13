%{
    #include <stdio.h>
%}
DigWO [1-9]
DigW [0-9]
%% 
[-+]?[1-9][0-9]*([eE][+-]?[1-9][0-9]*)? {printf("%s - INTEGER\n",yytext);}
[-+]?[0-9]*\.[0-9]+([eE][+-]?[1-9][0-9]*)? {printf("\tFLOAT\n",yytext);}
int {printf("%s - Integer Keyword\n",yytext);}
else {printf("%s - Else Keyword\n",yytext);}
char {printf("%s - Char Keyword\n",yytext);}
float {printf("%s - Float Keyword\n",yytext);}
if {printf("%s - If Keyword\n",yytext);}
while {printf("%s - While Keyword\n",yytext);}
for {printf("%s - For Keyword\n",yytext);}
switch {printf("%s - Switch Keyword\n",yytext);}
case {printf("%s - Case Keyword\n",yytext);}
default {printf("%s - Default Keyword\n",yytext);}
"+" {printf("%s - Addition Operator\n",yytext);}
"-" {printf("%s - Subtraction Operator\n",yytext);}
"*" {printf("%s - Multiplication Operator\n",yytext);}
"=" {printf("%s - Assignment Operator\n",yytext);}
"%" {printf("%s - Modulus Operator\n",yytext);}
"/" {printf("%s - Division Operator\n",yytext);}
"scanf"    {printf("Scanf encountered.\n",yytext);}
"printf"   {printf("Printf encountered.\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("%s - Identifier\n",yytext);}
[.,;:(){}\[\]]   {printf("%s - Punctuator\n",yytext);}
.|\n ; 	

%%

int main() {
    yylex();
    return 0;
}
