%{
    #include <stdio.h>
    int printf_count = 0;
    int scanf_count = 0;
%}

%% 
[-+]?[1-9][0-9]*([eE][+-]?[1-9][0-9]*)? {printf("%s - INTEGER\n",yytext);}
[-+]?[0-9]*\.[0-9]+([eE][+-]?[1-9][0-9]*)? {printf("%s -FLOAT\n",yytext);}

int|else|char|float|if|while|for|switch|case|default {printf("%s - Keyword\n",yytext);}

printf\s*\(\s*\"[a-zA-Z:,\s*]*\s*\%[c|s|d|f|u]\s*[a-zA-Z:,\s*]*\s*\"\s*,\s*[a-zA-Z_][a-zA-Z0-9_]*\s*\); {printf_count=printf_count+1;}
scanf\s*\(\s*\"[a-zA-Z:,\s*]*\s*\%[c|s|d|f|u]\s*[a-zA-Z:,\s*]*\s*\"\s*,\s*\&[a-zA-Z_][a-zA-Z0-9_]*\s*\); {scanf_count=scanf_count+1;}

"+" {ECHO; printf("\tAddition Operator\n");}
"-" {ECHO; printf("\tSubtraction Operator\n");}
"*" {ECHO; printf("\tMultiplication Operator\n");}
"=" {ECHO; printf("\tAssignment Operator\n");}
"%" {ECHO; printf("\tModulus Operator\n");}
"/" {ECHO; printf("\tDivision Operator\n");}
">" {ECHO; printf("\tLeft Greater Operator\n");}
"<" {ECHO; printf("\tRight Greater Operator\n");}
">=" {ECHO; printf("\tLeft Greater than or Equal Operator\n");}
"==" {ECHO; printf("\tEqual to Operator\n");}
"!=" {ECHO; printf("\tNot Equal to Operator\n");}
"&&" {ECHO; printf("\tLogical AND Operator\n");}
"||" {ECHO; printf("\tLogical OR Operator\n");}
"!"  {ECHO; printf("\tLogical NOT Operator\n");}



[a-zA-Z_][a-zA-Z0-9_]* {printf("%s - Identifier\n",yytext);}

[.,;:(){}\[\]]   {printf("%s - Punctuator\n",yytext);}

.|\n ; 	

%%

int main() {
    yylex();
    printf("Number of valid print statements: %d\n", printf_count);
    printf("Number of valid scan statements: %d\n", scanf_count);
}