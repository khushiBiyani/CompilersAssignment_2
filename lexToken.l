%{
    include<stdio.h>
%}

%% 

"int" | "else" | "char" | "float" | "if" | "while" | "for" | "switch" | "case" | "default" {ECHO; printf("\tKeyword\n");}
+ {ECHO; printf("\tAddition Operator\n");}
- {ECHO; printf("\tSubtraction Operator\n");}
* {ECHO; printf("\tMultiplication Operator\n");}
= {ECHO; printf("\tAssignment Operator\n");}
% {ECHO; printf("\tModulus Operator\n");}
/ {ECHO; printf("\tDivision Operator\n");}
{0-9}+   {ECHO; printf("\tNumber\n");}
scanf    {printf("Scanf encountered.\n");}
printf   {printf("Printf encountered.\n");}
[a-zA-Z_][a-zA-Z0-9_]* {ECHO; printf("\tIdentifier\n");}
[.,;:(){}\[\]]   { ECHO ; printf("\tPunctuator\n");}
.|\n ; 	

%%

int main() {
    yylex();
    return 0;
}
