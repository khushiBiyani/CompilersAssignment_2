%{
    #include <stdio.h>
    #include<stdlib.h>
    #include <stdbool.h>
    #include "y.tab.h"
    bool error=0;
    int lineCount=0;
%}
%x SLCOMMENT
%x COMMENT
%%
"/*"                                {BEGIN COMMENT;}
<COMMENT>.|[ \t\r\f\v\n]             ;
<COMMENT>"*/"                       {BEGIN INITIAL;}
<COMMENT>"/*"                       {printf("Error on line %d: Nested comments are invalid\n",lineCount);yyterminate();}
<COMMENT><<EOF>>                    {printf("Error on line %d: Unterminated comments are invalid\n",lineCount); yyterminate();}
"//"                                {BEGIN SLCOMMENT;}
<SLCOMMENT>.                        ;
<SLCOMMENT>\n                       {lineCount++; BEGIN INITIAL;}

"else" {return ELSE;}
"if" {return IF;}
"default" {return DEFAULT;}
"switch" {return SWITCH;}
"case" {return CASE;}
"for" {return FOR;}
"while" {return WHILE;}
"break" {return BREAK;}
"continue" {return CONTINUE;}
"int" {return INT;}
"char" {return CHAR;}
"float" {return FLOAT;}
"return" {return RETURN;}
"printf" {return PRINTF;}
"scanf" {return SCANF;}
[ \t\f\v\r] ;
"=" {return EQUAL;}
"," {return COMMA;}
"&" {return AMPERSAND;}
":" {return COLON;}
";" {return SEMICOLON;}
[a-zA-Z_][a-zA-Z0-9_]* {strcpy(yylval.identifier,yytext);return IDENTIFIER;}
[0-9]+([a-zA-Z]|_)+  {printf("Error: Illegal identifier format\n");error=1;}
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
"{" {return OPCUR;}
"}" {return CLCUR;}
"[" {return BOXOPEN;}
"]" {return BOXCLOSE;}
"!" {return LOGICALNOT;}
[-]?[0-9]+([eE][+-]?[1-9][0-9]*)? {yylval.number=atoi(yytext);return INTVAL;}
[-]?[0-9]*\.[0-9]+([eE][+-]?[1-9][0-9]*)? {yylval.numberf=atoi(yytext);return FLOATVAL;}
\'[^\'\n]\' {yylval.singleChar = yytext[0];return CHARVAL;}
\"[^\"\n]*\" {strcpy(yylval.longString,yytext);return STRING;}
\n {lineCount++;}
. {return yytext[0];}
%%
