%{
    include<stdio.h>
%}

%% 

"int" | "else" | "char" | "float" | "if" | "while" | "for" | "switch" | "case" {ECHO; printf("\tKeyword\n");}
[+-/=*%]   {ECHO; printf("\tOperator\n");}
{0-9}+   {ECHO; printf("\tNumber\n");}
[a-zA-Z_][a-zA-Z0-9_]* {ECHO; printf("\tIdentifier\n");}
[.,;:(){}\[\]]   { ECHO ; printf("\tPunctuator\n");}
.|\n ; 	

%%

int main() {
    yylex();
    return 0;
}