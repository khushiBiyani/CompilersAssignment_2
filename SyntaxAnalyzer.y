%{
	#include <stdio.h>
%}

%token VARIABLE EQUAL COMMA SEMICOLON INT CHAR FLOAT CHARVAL LOGICALOR LOGICALAND EQUALS NOTEQUAL GREATERTHAN GREATERTHANEQUALTO LESSTHAN LESSTHANEQUALTO ADD SUB MULT DIV MOD OPBRAC CLBRAC LOGICALNOT INTVAL FLOATVAL SPACE

%%

basicStatements: basicStatement basicStatements
		| basicStatement

basicStatement: expressionStatement
		| declarationStatement
		| assignmentStatement
		
assignmentStatement: VARIABLE EQUAL expressionStatement COMMA assignmentStatement
		| VARIABLE EQUAL expressionStatement SEMICOLON

declarationStatement: INT SPACE declarationListIntFloat SEMICOLON
		| CHAR SPACE declarationListChar SEMICOLON
		| FLOAT SPACE declarationListIntFloat SEMICOLON
		
declarationListIntFloat: VARIABLE EQUAL expressionStatement COMMA declarationListIntFloat
		| VARIABLE COMMA declarationListIntFloat
		| VARIABLE EQUAL expressionStatement
		| VARIABLE
		
declarationListChar: VARIABLE EQUAL CHARVAL COMMA declarationListChar
		| VARIABLE COMMA declarationListChar
		| VARIABLE EQUAL CHARVAL
		| VARIABLE
		
expressionStatement: expressionStatement LOGICALOR logicalExpression
		| logicalExpression
		
logicalExpression: logicalExpression LOGICALAND expression
		| expression
		
expression: expression EQUALS relationalExpression
		| expression NOTEQUAL relationalExpression
		| relationalExpression
		
relationalExpression: relationalExpression GREATERTHAN value
		| relationalExpression GREATERTHANEQUALTO value
		| relationalExpression LESSTHAN value
		| relationalExpression LESSTHANEQUALTO value
		| value
		
value: value ADD term
	| value SUB term
	| term
	
term: term MULT factor
	| term DIV factor
	| term MOD factor
	| factor
	
factor: VARIABLE
	| OPBRAC expressionStatement CLBRAC
	| LOGICALNOT expressionStatement
	| CHARVAL
	| INTVAL
	| FLOATVAL

%%

void main(){
	printf("Enter the Expression:\n");
	yyparse();
	exit(0);
}

void yyerror(){
	printf("Invalid Statement");
	exit(0);
}
