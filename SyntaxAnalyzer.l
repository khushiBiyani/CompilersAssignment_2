%{
	#include "y.tab.h"
	#include <stdlib.h>
	
%}


%%

" " {return SPACE;}
"=" {return EQUAL;}
"," {return COMMA;}
";" {return SEMICOLON;}
"int" {return INT;}
"char" {return CHAR;}
"float" {return FLOAT;}
[a-zA-Z_][a-zA-Z0-9_]* {return VARIABLE;}
"||" {return LOGICALOR;}
"&&" {return LOGICALAND;}
"==" {return EQUALS;}
"!=" {return NOTEQUAL;}
">" {return GREATERTHAN;}
">=" {return GREATERTHANEQUALTO;}
"<" {return LESSTHAN;}
"<=" {return LESSTHANEQUALTO;}
"+" {return ADD;}
"-" {return SUB;}
"*" {return MULT;}
"/" {return DIV;}
"%" {return MOD;}
"(" {return OPBRAC;}
")" {return CLBRAC;}
"!" {return LOGICALNOT;}
[-+]?[1-9][0-9]*([eE][+-]?[1-9][0-9]*)? {return INTVAL;}
[-+]?[0-9]*\.[0-9]+([eE][+-]?[1-9][0-9]*)? {return FLOATVAL;}
. {return CHARVAL;}

%%
