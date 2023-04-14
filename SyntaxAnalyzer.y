%{
	#include <stdio.h>
%}

/* left associative */
%left LOGICALOR LOGICALAND EQUALS NOTEQUAL GREATERTHAN GREATERTHANEQUALTO LESSTHAN LESSTHANEQUALTO ADD SUB MULT DIV MOD

/* Punctuators */
%token COMMA SEMICOLON AMPERSAND COLON

/* Type */
%token INT CHAR FLOAT 

/* Keywords */
%token IF ELSE FOR WHILE DEFAULT SWITCH CASE BREAK CONTINUE RETURN 

/* parenthesis */
%token OPBRAC CLBRAC OPCUR CLCUR BOXOPEN BOXCLOSE

/* right associative */
%right LOGICALNOT EQUAL

%token IDENTIFIER CHARVAL INTVAL FLOATVAL
%%

/* start of the program */
start: statements 
statements: specialStatement statements 
		   | basicStatement statements
		   | 

specialStatement: forLoop 
				 | ifStatement
				 | whileLoop
				 | switchStatement

/* for loop */
forLoop: FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR inLoop CLCUR
		| FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON 

forAssignStatement: assignmentStatement | 
forExpStatement: expressionStatement | 
forUpdateStatement: IDENTIFIER EQUAL expressionStatement COMMA forUpdateStatement
				   | IDENTIFIER EQUAL expressionStatement 

/* while loop */
whileLoop: WHILE OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR 
		  | WHILE OPBRAC expressionStatement CLBRAC SEMICOLON

inLoop: BREAK SEMICOLON inLoop 
		| CONTINUE SEMICOLON inLoop
		| statements inLoop
		| ifInLoopStatement inLoop
		| switchStatement inLoop
		| 

ifStatement: IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ES
			| IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ifStatement

ES: ELSE IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ES
	| ELSE OPCUR statements CLCUR

ifInLoopStatement: IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ESLoop
			| IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ifInLoopStatement

ESLoop: ELSE IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ESLoop
	| ELSE OPCUR inLoop CLCUR

switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR
caseStatements: caseStatementInt | caseStatementChar | 
caseStatementInt: caseInt caseStatementInt | 
caseInt: CASE OPBRAC INTVAL CLBRAC COLON statements BREAK SEMICOLON 
caseStatementChar: caseChar caseStatementChar |
caseChar:  CASE OPBRAC CHARVAL CLBRAC COLON statements BREAK SEMICOLON 
defaultStatement: DEFAULT COLON statements SEMICOLON | 

/* basic statements */
basicStatements: basicStatement basicStatements
		| basicStatement

basicStatement: expressionStatement
		| declarationStatement
		| assignmentStatement
		
assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement
		| IDENTIFIER EQUAL expressionStatement SEMICOLON

declarationStatement: INT declarationListIntFloat SEMICOLON
		| CHAR declarationListChar SEMICOLON
		| FLOAT declarationListIntFloat SEMICOLON
		
declarationListIntFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListIntFloat
		| IDENTIFIER COMMA declarationListIntFloat
		| IDENTIFIER EQUAL expressionStatement
		| IDENTIFIER
		
declarationListChar: IDENTIFIER EQUAL CHARVAL COMMA declarationListChar
		| IDENTIFIER COMMA declarationListChar
		| IDENTIFIER EQUAL CHARVAL
		| IDENTIFIER
		
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
	
factor: IDENTIFIER
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

parameters: parameter | parameter COMMA parameters 

parameter : type IDENTIFIER 

type: INT | FLOAT | CHAR 

compoundStatements : OPCUR CLCUR | OPCUR statementList CLCUR 

statementList : statementList basicStatements | statementList specialStatement | 

/* array */
arrayDec : type declarator SEMICOLON
declarator : IDENTIFIER dimension
dimension : BOXOPEN INTVAL BOXCLOSE 
		  | BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE 
		  | BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE
%%

void main(){
	printf("Enter the Expression:\n");
	yyparse();
	printf("Done\n");
	exit(0);
}

void yyerror(){
	printf("Invalid Statement");
	exit(0);
}
