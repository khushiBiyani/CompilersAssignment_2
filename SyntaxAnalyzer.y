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
code : declarationList {printf("Starting..\n");return 0;}

declarationList :  declarationStatement declarationList {printf("RECURSIVE DECLARATION \n");}
				|  declarationStatement {printf("DECLARATION \n");}

statements : specialStatement statements {printf("Special..\n");}
		   | basicStatement statements {printf("Basic123..\n");}
		   | functionCall
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

declarationStatement : INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  {printf("INT F WITH PARAMS..\n");}
		| CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements {printf("char F WITH PARAMS..\n");}
		| FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements {printf("float F WITH PARAMS..\n");}
		| INT IDENTIFIER OPBRAC CLBRAC compoundStatements
		| FLOAT IDENTIFIER OPBRAC CLBRAC compoundStatements
		| CHAR IDENTIFIER OPBRAC CLBRAC compoundStatements
		| INT declarationListIntFloat SEMICOLON {printf("DS1..\n");}
		| CHAR declarationListChar SEMICOLON
		| FLOAT declarationListIntFloat SEMICOLON
		
		
declarationListIntFloat : IDENTIFIER EQUAL expressionStatement COMMA declarationListIntFloat {printf("DSL1..\n");}
		| IDENTIFIER COMMA declarationListIntFloat
		| IDENTIFIER EQUAL expressionStatement {printf("DSL3..\n");}
		| IDENTIFIER dimension  {printf("INTFLOAT ARRAY..\n");}
		| IDENTIFIER {printf("DSL4..\n");}
		
declarationListChar : IDENTIFIER EQUAL CHARVAL COMMA declarationListChar
		| IDENTIFIER COMMA declarationListChar
		| IDENTIFIER EQUAL CHARVAL
		| IDENTIFIER dimension
		| IDENTIFIER
		
expressionStatement : logicalExpression LOGICALOR expressionStatement {printf("ES1..\n");}
		| logicalExpression {printf("ES2..\n");}
		
logicalExpression : expression LOGICALAND logicalExpression {printf("LE1..\n");}
		| expression {printf("LE2..\n");}
		
expression : relationalExpression EQUALS expression {printf("E1..\n");}
		| relationalExpression NOTEQUAL expression {printf("E2..\n");}
		| relationalExpression {printf("E3..\n");}
		
relationalExpression : value GREATERTHAN relationalExpression
		| value GREATERTHANEQUALTO relationalExpression
		| value LESSTHAN relationalExpression
		| value LESSTHANEQUALTO relationalExpression
		| value {printf("VALUE..\n");}
		
value : term ADD value {printf("ADD..\n");}
	| term SUB value
	| term {printf("Basic TERM..\n");}
	
term : factor MULT term {printf("MULT..\n");}
	| factor DIV term
	| factor MOD term
	| factor {printf("Factor..\n");}
	
factor : IDENTIFIER
	| OPBRAC expressionStatement CLBRAC
	| LOGICALNOT expressionStatement
	| CHARVAL
	| INTVAL {printf("INT VALS.. %d\n",yylval);}
	| FLOATVAL
	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE 
	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE 


/* function */
functionDec : type IDENTIFIER OPBRAC parameters CLBRAC compoundStatements {printf("FUNCTIONDEC\n");}
            | type IDENTIFIER OPBRAC CLBRAC compoundStatements {printf("FUNCTIONDEC without param\n");}

functionCall : IDENTIFIER OPBRAC CLBRAC SEMICOLON
             | IDENTIFIER OPBRAC argList CLBRAC SEMICOLON 

/* changes to be made - either expressionStatement or expression */
argList : argList COMMA expressionStatement | expressionStatement 

parameters : parameter | parameter COMMA parameters  {printf("FUNCTION params\n");}

parameter : type IDENTIFIER {printf("FUNCTION param\n");}

type : INT | FLOAT | CHAR 

compoundStatements : OPCUR statementList CLCUR {printf("FUNCTION statements\n");}

statementList : basicStatements statementList | specialStatement statementList | functionCall statementList | returnDec |

returnDec : RETURN expressionStatement SEMICOLON | RETURN SEMICOLON 
/* array */
arrayDec : type declarator SEMICOLON {printf("ARRAY START..\n");}
declarator : IDENTIFIER dimension {printf("declarator..\n");}
dimension : BOXOPEN INTVAL BOXCLOSE {printf("size..\n");}
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
