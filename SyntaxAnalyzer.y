%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
%}
%start code
/* left associative */
%left LOGICALOR LOGICALAND EQUALS NOTEQUAL GREATERTHAN GREATERTHANEQUALTO LESSTHAN LESSTHANEQUALTO ADD SUB MULT DIV MOD

/* Punctuators */
%token COMMA SEMICOLON AMPERSAND COLON 

/* Type */
%token INT CHAR FLOAT STRING

/* Keywords */
%token IF ELSE FOR WHILE DEFAULT SWITCH CASE BREAK CONTINUE RETURN 

/* parenthesis */
%token OPBRAC CLBRAC OPCUR CLCUR BOXOPEN BOXCLOSE

/* right associative */
%right LOGICALNOT EQUAL

%token IDENTIFIER CHARVAL INTVAL FLOATVAL

%%

/* start of the program */
code : statements {printf("Starting..\n");return 0;}
statements : specialStatement statements {printf("Special..\n");}
		   | basicStatement statements {printf("Basic123..\n");}
		   | 

specialStatement : forLoop 
				 | ifStatement
				 | whileLoop
				 | switchStatement

/* for loop */
forLoop : FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR inLoop CLCUR
		| FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON 

forAssignStatement : assignmentStatement | 
forExpStatement : expressionStatement | 
forUpdateStatement : IDENTIFIER EQUAL expressionStatement COMMA forUpdateStatement
				   | IDENTIFIER EQUAL expressionStatement 

/* while loop */
whileLoop : WHILE OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR 
		  | WHILE OPBRAC expressionStatement CLBRAC SEMICOLON

inLoop : BREAK SEMICOLON inLoop 
		| CONTINUE SEMICOLON inLoop
		| statements inLoop
		| ifInLoopStatement inLoop
		| switchStatement inLoop
		| 

ifStatement : IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ES
			| IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ifStatement

ES : ELSE IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ES
	| ELSE OPCUR statements CLCUR

ifInLoopStatement : IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ESLoop
			| IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ifInLoopStatement

ESLoop : ELSE IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ESLoop
	| ELSE OPCUR inLoop CLCUR

switchStatement : SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR
caseStatements : caseStatementInt | caseStatementChar | 
caseStatementInt : caseInt caseStatementInt | 
caseInt : CASE OPBRAC INTVAL CLBRAC COLON statements BREAK SEMICOLON 
caseStatementChar : caseChar caseStatementChar |
caseChar :  CASE OPBRAC CHARVAL CLBRAC COLON statements BREAK SEMICOLON 
defaultStatement : DEFAULT COLON statements SEMICOLON | 

/* basic statements */
basicStatements : basicStatement basicStatements
		| basicStatement

basicStatement : expressionStatement {printf("BS->EXPS..\n");}
		| declarationStatement {printf("BS->DS..\n");}
		| assignmentStatement	{printf("Basic->AS..\n");}
		
assignmentStatement : IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement {printf("AS1..\n");}
		| IDENTIFIER EQUAL expressionStatement SEMICOLON {printf("AS2..\n");}

declarationStatement : INT declarationListIntFloat SEMICOLON {printf("DS1..\n");}
		| CHAR declarationListChar SEMICOLON
		| FLOAT declarationListIntFloat SEMICOLON
		
declarationListIntFloat : IDENTIFIER EQUAL expressionStatement COMMA declarationListIntFloat {printf("DSL1..\n");}
		| IDENTIFIER COMMA declarationListIntFloat
		| IDENTIFIER EQUAL expressionStatement {printf("DSL3..\n");}
		| IDENTIFIER {printf("DSL4..\n");}
		
declarationListChar : IDENTIFIER EQUAL CHARVAL COMMA declarationListChar
		| IDENTIFIER COMMA declarationListChar
		| IDENTIFIER EQUAL CHARVAL
		| IDENTIFIER
		
expressionStatement : expressionStatement LOGICALOR logicalExpression {printf("ES1..\n");}
		| logicalExpression {printf("ES2..\n");}
		
logicalExpression : logicalExpression LOGICALAND expression {printf("LE1..\n");}
		| expression {printf("LE2..\n");}
		
expression : expression EQUALS relationalExpression {printf("E1..\n");}
		| expression NOTEQUAL relationalExpression {printf("E2..\n");}
		| relationalExpression {printf("E3..\n");}
		
relationalExpression : relationalExpression GREATERTHAN value 
		| relationalExpression GREATERTHANEQUALTO value
		| relationalExpression LESSTHAN value
		| relationalExpression LESSTHANEQUALTO value
		| value {printf("VALUE..\n");}
		
value : value ADD term {printf("ADD..\n");}
	| value SUB term
	| term {printf("Basic TERM..\n");}
	
term : factor MULT term {printf("MULT..\n");}
	| factor DIV term
	| factor MOD term
	| factor {printf("F..\n");}
	
factor : IDENTIFIER
	| OPBRAC expressionStatement CLBRAC
	| LOGICALNOT expressionStatement
	| CHARVAL
	| INTVAL {printf("arey waah.. %d\n",yylval);}
	| FLOATVAL
	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE 
	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE 


/* function */
functionDec : type IDENTIFIER OPBRAC parameters CLBRAC compoundStatements 
            | type IDENTIFIER OPBRAC CLBRAC compoundStatements

functionCall : IDENTIFIER OPBRAC CLBRAC SEMICOLON
             | IDENTIFIER OPBRAC argList CLBRAC SEMICOLON 

/* changes to be made - either expressionStatement or expression */
argList : argList COMMA expressionStatement | expressionStatement 

parameters : parameter | parameter COMMA parameters 

parameter : type IDENTIFIER 

type : INT | FLOAT | CHAR 

compoundStatements : OPCUR CLCUR | OPCUR statementList CLCUR 

statementList : statementList basicStatements | statementList specialStatement | 

/* array */
arrayDec : type declarator SEMICOLON
declarator : IDENTIFIER dimension
dimension : BOXOPEN INTVAL BOXCLOSE 
		  | BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE 
		  | BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE
%%

#include "lex.yy.c"
void main(){
	yyin = fopen("input.txt","r");
	if(!yyparse())
	{
		printf("Parsing Done\n");
	}
	else 
		printf("Failed\n");
	exit(0);
}

void yyerror(){
	printf("Invalid Statement");
	exit(0);
}
