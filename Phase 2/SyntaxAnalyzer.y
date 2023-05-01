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
%token IF ELSE FOR WHILE DEFAULT SWITCH CASE BREAK CONTINUE RETURN PRINTF SCANF
 
/* parenthesis */
%token OPBRAC CLBRAC OPCUR CLCUR BOXOPEN BOXCLOSE
 
/* right associative */
%right LOGICALNOT EQUAL
 
%token IDENTIFIER CHARVAL INTVAL FLOATVAL
 
%%
 
/* start of the program */
code : declarationList 
 
declarationList :  declarationStatement declarationList 
				|  assignmentStatement declarationList
				|  declarationStatement 
				|  assignmentStatement
 
statements : specialStatement statements 
		   | basicStatement statements 
		   | functionCall statements
		   | 
 
specialStatement : forLoop 
				 | ifStatement
				 | whileLoop
				 | switchStatement
 
/* for loop */
forLoop : FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR inLoop CLCUR 
		| FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON 
		| FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC singleLoopStatement 

singleLoopStatement : specialStatement 
					| basicStatement
					| functionCall
					| BREAK SEMICOLON
					| CONTINUE SEMICOLON
					| switchStatement
					| ifInLoopStatement
 
forAssignStatement : assignmentStatement 
					| INT IDENTIFIER EQUAL expressionStatement SEMICOLON 
					| INT IDENTIFIER EQUAL expressionStatement COMMA  forAssignStatement
					| CHAR IDENTIFIER EQUAL expressionStatement SEMICOLON 
					| CHAR IDENTIFIER EQUAL expressionStatement COMMA  forAssignStatement
					| SEMICOLON
forExpStatement : expressionStatement | 
forUpdateStatement : IDENTIFIER EQUAL expressionStatement COMMA forUpdateStatement
				   | IDENTIFIER EQUAL expressionStatement 
 
/* while loop */
whileLoop : WHILE OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR 
		  | WHILE OPBRAC expressionStatement CLBRAC SEMICOLON 
		  | WHILE OPBRAC expressionStatement CLBRAC singleLoopStatement 
 
inLoop : BREAK SEMICOLON inLoop 
		| CONTINUE SEMICOLON inLoop 
		| specialStatement inLoop 
		| basicStatement inLoop 
 		|functionCall inLoop 
		| ifInLoopStatement inLoop 
		| switchStatement inLoop 
		| singleLoopStatement inLoop 
		|
 
ifStatement : IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ES
			| IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ifStatement
 
ES : ELSE IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ES
	| ELSE OPCUR statements CLCUR
	|
 
ifInLoopStatement : IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ESLoop
			| IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ifInLoopStatement
 
ESLoop : ELSE IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ESLoop
	| ELSE OPCUR inLoop CLCUR
	|
 
switchStatement : SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR 
caseStatements : caseStatementInt | 
caseStatementInt : caseInt caseStatementInt | 
caseInt : CASE OPBRAC INTVAL CLBRAC COLON statements BREAK SEMICOLON  
		| CASE OPBRAC INTVAL CLBRAC COLON statements 
		| CASE INTVAL COLON statements BREAK SEMICOLON 
		| CASE INTVAL COLON statements 
		| CASE OPBRAC CHARVAL CLBRAC COLON statements BREAK SEMICOLON  
		| CASE OPBRAC CHARVAL CLBRAC COLON statements 
		| CASE CHARVAL COLON statements BREAK SEMICOLON 
		| CASE CHARVAL COLON statements 
defaultStatement : DEFAULT COLON statements  | 
 
/* basic statements */
basicStatements : basicStatement basicStatements
		| basicStatement
 
basicStatement : expressionStatement 
		| declarationStatement 
		| assignmentStatement	
		| returnDec
		
assignmentStatement : IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement 
		| IDENTIFIER EQUAL expressionStatement SEMICOLON 

printer : PRINTF OPBRAC STRING prattributes CLBRAC SEMICOLON
scanner : SCANF OPBRAC STRING scattributes CLBRAC SEMICOLON
declarationStatement : INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  
		| CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements 
		| FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements 
		| INT IDENTIFIER OPBRAC CLBRAC compoundStatements
		| FLOAT IDENTIFIER OPBRAC CLBRAC compoundStatements
		| CHAR IDENTIFIER OPBRAC CLBRAC compoundStatements
		| INT declarationListIntFloat SEMICOLON 
		| CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING SEMICOLON
		| CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING SEMICOLON
		| CHAR declarationListChar SEMICOLON
		| FLOAT declarationListIntFloat SEMICOLON

prattributes : COMMA IDENTIFIER prattributes | 
scattributes : COMMA AMPERSAND IDENTIFIER scattributes | 
		
declarationListIntFloat : IDENTIFIER EQUAL expressionStatement COMMA declarationListIntFloat 
		| IDENTIFIER COMMA declarationListIntFloat
		| IDENTIFIER EQUAL expressionStatement 
		| IDENTIFIER dimension  
		| IDENTIFIER 
		
declarationListChar : IDENTIFIER EQUAL CHARVAL COMMA declarationListChar
		| IDENTIFIER COMMA declarationListChar
		| IDENTIFIER EQUAL expressionStatement
		| IDENTIFIER dimension
		| IDENTIFIER
		
expressionStatement : logicalExpression LOGICALOR expressionStatement 
		| logicalExpression 
		
logicalExpression : expression LOGICALAND logicalExpression 
		| expression 
		
expression : relationalExpression EQUALS expression 
		| relationalExpression NOTEQUAL expression 
		| relationalExpression 
		
relationalExpression : value GREATERTHAN relationalExpression
		| value GREATERTHANEQUALTO relationalExpression
		| value LESSTHAN relationalExpression
		| value LESSTHANEQUALTO relationalExpression
		| value 
		
value : term ADD value 
	| term SUB value
	| term 
	
term : factor MULT term 
	| factor DIV term
	| factor MOD term
	| factor 
	
factor : IDENTIFIER
	| OPBRAC expressionStatement CLBRAC
	| LOGICALNOT expressionStatement
	| CHARVAL
	| INTVAL 
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
 
compoundStatements : OPCUR statementList CLCUR 
 
statementList : basicStatements statementList | specialStatement statementList | functionCall statementList | returnDec | printer statementList | scanner statementList | 
 
returnDec : RETURN expressionStatement SEMICOLON | RETURN SEMICOLON 
/* array */
// arrayDec : type declarator SEMICOLON  | charArrayDec
// charArrayDec : CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING
			|  CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING
declarator : IDENTIFIER dimension 
dimension : BOXOPEN INTVAL BOXCLOSE 
		  | BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE 
		  | BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE
%%
 
#include "lex.yy.c"
void main(){
	yyin = fopen("./Test Cases/input.txt","r");
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
