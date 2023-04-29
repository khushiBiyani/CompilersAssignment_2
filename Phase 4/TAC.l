%{
    #include <stdio.h>
    #include<stdlib.h>
    #include <stdbool.h>
    #include "y.tab.h"
    bool error=0;
    int lineCount=0;
    int line = 0;
    #define YYSTYPE char *
%}
%x SLCOMMENT
%x COMMENT
%option yylineno
%%
"/*"                                {BEGIN COMMENT;}
<COMMENT>.|[ \t\r\f\v\n]             ;
<COMMENT>"*/"                       {BEGIN INITIAL;}
<COMMENT>"/*"                       {printf("Error on line %d: Nested comments are invalid\n",lineCount);yyterminate();}
<COMMENT><<EOF>>                    {printf("Error on line %d: Unterminated comments are invalid\n",lineCount); yyterminate();}
"//"                                {BEGIN SLCOMMENT;}
<SLCOMMENT>.                        ;
<SLCOMMENT>\n                       {lineCount++; BEGIN INITIAL;}

"else" {yylval = strdup(yytext);return ELSE;}
"if" {yylval = strdup(yytext);return IF;}
"default" {yylval = strdup(yytext);return DEFAULT;}
"switch" {yylval = strdup(yytext);return SWITCH;}
"case" {yylval = strdup(yytext);return CASE;}
"for" {yylval = strdup(yytext);return FOR;}
"while" {yylval = strdup(yytext);return WHILE;}
"break" {yylval = strdup(yytext);return BREAK;}
"continue" {yylval = strdup(yytext);return CONTINUE;}
"int" {yylval = strdup(yytext);return INT;}
"char" {yylval = strdup(yytext);return CHAR;}
"float" {yylval = strdup(yytext);return FLOAT;}
"return" {yylval = strdup(yytext);return RETURN;}
"printf" {yylval = strdup(yytext);return PRINTF;}
"scanf" {yylval = strdup(yytext);return SCANF;}
[ \t\f\v\r] ;
"=" {yylval = strdup(yytext);yylval = strdup(yytext);return EQUAL;}
"," {yylval = strdup(yytext);return COMMA;}
"&" {yylval = strdup(yytext);return AMPERSAND;}
":" {yylval = strdup(yytext);return COLON;}

[a-zA-Z_][a-zA-Z0-9_]* {yylval = strdup(yytext);return IDENTIFIER;}
[0-9]+([a-zA-Z]|_)+  {printf("Error: Illegal identifier format\n");error=1;}
"||" {yylval = strdup(yytext);return LOGICALOR;}
"&&" {yylval = strdup(yytext);return LOGICALAND;}
"==" {yylval = strdup(yytext);return EQUALS;}
"!=" {yylval = strdup(yytext);return NOTEQUAL;}
">" {yylval = strdup(yytext);return GREATERTHAN;}
">=" {yylval = strdup(yytext);return GREATERTHANEQUALTO;}
"<" {yylval = strdup(yytext);return LESSTHAN;}
"<=" {yylval = strdup(yytext);return LESSTHANEQUALTO;}
"+" {yylval = strdup(yytext);return ADD;}
"-" {yylval = strdup(yytext);return SUB;}
"*" {yylval = strdup(yytext);return MULT;}
"/" {yylval = strdup(yytext);return DIV;}
"%" {yylval = strdup(yytext);return MOD;}
"!" {yylval = strdup(yytext);return LOGICALNOT;}
[-]?[0-9]+([eE][+-]?[1-9][0-9]*)? {yylval = strdup(yytext);return INTVAL;}
[-]?[0-9]*\.[0-9]+([eE][+-]?[1-9][0-9]*)? {yylval = strdup(yytext);return FLOATVAL;}
\'[^\'\n]\' {yylval = strdup(yytext);return CHARVAL;}   
\"[^\"\n]*\" {yylval = strdup(yytext);return STRING;}
\n {lineCount++;}
. {return yytext[0];}
%%
