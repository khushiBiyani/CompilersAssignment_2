    %{
    	#include <stdio.h>
    	#include <stdlib.h>
    	#include <string.h>
    	#include <stdbool.h>
    	int yylex();
     
    	// error function
    	void yyerror(const char*){
    	printf("Invalid Statement");
    	exit(0);
    	}
     
    	// symbol table structure
    	struct symbolTable{
    		char *lexeme;
    		char *value;
    		char *dataType;
    		bool isFunction;
    		bool isArray;
    		int scope;
    		int dimensionofArray;
    		char *parameterList[1000];
    		int arrayDimension[1000];
    		int parameterCount;
    	};
    	symbolTable table[1000];
    	int availableScopes[1000]={-1};
    	int scopeIndex=0;
    	int currIndex=0;
    	int maxScope=0;
    	int currScope=0;
     
    	// insert function
    	void insertInTable(char *token,char *type,char *val,int sc,int paramCount,char *paramList[],int arrayDim[],int dimensionofArr,bool isArr,bool isFunc){
    		symbolTable newEntry;
    		strcpy(newEntry.lexeme,token);
    		strcpy(newEntry.value,val);
    		strcpy(newEntry.dataType,type);
    		newEntry.scope=sc;
     
    		if(isFunc){
        		for(int i =0;i<paramCount;i++){
        			strcpy(newEntry.parameterList[i],paramList[i]);
        		}
        		newEntry.parameterCount=paramCount;
        	}
     
    		newEntry.isArray = isArr;
        	if(isArr){
        		for(int i =0;i<dimensionofArr;i++){
        				newEntry.arrayDimension[i]=arrayDim[i];
        		}
        		newEntry.dimensionofArray=dimensionofArr;
        	}
    		table[currIndex++]=newEntry;
    	}
     
    	// update value of token
    	void updateVal(int sc,char *token,char *value)
    	{
    		int instScopeIndex=sc;
    		int tableIndex=currIndex;
    		for(int i=tableIndex-1;i>=0;i--)
    		{	
    			if(strcmp(table[i].lexeme,token)){
					for(int j = scopeIndex;j>=0;j--){
						if(table[i].scope==availableScopes[j]){
							strcpy(table[i].value,value);
							return;
						}
					}
				}
    		}
     
    	}
     
     
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
    code : declarationList {printf("Starting..\n");}
     
    declarationList :  declarationStatement declarationList {printf("RECURSIVE DECLARATION \n");}
    				|  assignmentStatement declarationList
    				|  declarationStatement {printf("DECLARATION \n");}
    				|  assignmentStatement
     
    statements : specialStatement statements {printf("Special..\n");}
    		   | basicStatement statements {printf("Basic123..\n");}
    		   | functionCall statements
    		   | 
     
    specialStatement : forLoop 
    				 | ifStatement
    				 | whileLoop
    				 | switchStatement
     
    /* for loop */
    forLoop : FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR inLoop CLCUR {printf("\nproper FOR \n");}
    		| FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON {printf("\nFOR SEMICOLON \n");}
    		| FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC singleLoopStatement {printf("\nFOR SINGLE STATEMENT \n");}
     
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
    whileLoop : WHILE OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR {printf("\nproper WHILE \n");}
    		  | WHILE OPBRAC expressionStatement CLBRAC SEMICOLON {printf("\nWHILE SEMICOLON \n");}
    		  | WHILE OPBRAC expressionStatement CLBRAC singleLoopStatement {printf("\nSINGLE WHILE \n");}
     
    inLoop : BREAK SEMICOLON inLoop {printf("\n break in loop \n");}
    		| CONTINUE SEMICOLON inLoop {printf("\ncontinue in loop \n");}
    		| specialStatement inLoop {printf("\n special statement in loop \n");}
    		| basicStatement inLoop {printf("\n basic statement in loop \n");}
     		|functionCall inLoop {printf("\n basic statement in loop \n");}
    		| ifInLoopStatement inLoop {printf("\n if in loop \n");}
    		| switchStatement inLoop {printf("\n switch in loop \n");}
    		| singleLoopStatement inLoop {printf("\n any other statement in loop \n");}
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
     
    switchStatement : SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR {printf("SWITCH START..\n");}
    caseStatements : caseStatementInt | {printf("char/int..\n");}
    caseStatementInt : caseInt caseStatementInt | {printf("INT CASE..\n");}
    caseInt : CASE OPBRAC INTVAL CLBRAC COLON statements BREAK SEMICOLON {printf("case (INT) : break; ..\n");} 
    		| CASE OPBRAC INTVAL CLBRAC COLON statements {printf("case (INT) : ..\n");}
    		| CASE INTVAL COLON statements BREAK SEMICOLON {printf("case INT : BREAK;..\n");}
    		| CASE INTVAL COLON statements {printf("CASE INT : ..\n");}
    		| CASE OPBRAC CHARVAL CLBRAC COLON statements BREAK SEMICOLON {printf("case (char) : break; ..\n");} 
    		| CASE OPBRAC CHARVAL CLBRAC COLON statements {printf("case (char) : ..\n");}
    		| CASE CHARVAL COLON statements BREAK SEMICOLON {printf("case char : BREAK;..\n");}
    		| CASE CHARVAL COLON statements {printf("CASE char : ..\n");}
    defaultStatement : DEFAULT COLON statements  | {printf(" \nDEFAULT : ..\n");}
     
    /* basic statements */
    basicStatements : basicStatement basicStatements
    		| basicStatement
     
    basicStatement : expressionStatement {printf("BS->EXPS..\n");}
    		| declarationStatement {printf("BS->DS..\n");}
    		| assignmentStatement	{printf("Basic->AS..\n");}
    		
    assignmentStatement : IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement {printf("AS1..\n");}
    		| IDENTIFIER EQUAL expressionStatement SEMICOLON {printf("AS2..\n");}
     
    printer : PRINTF OPBRAC STRING prattributes CLBRAC SEMICOLON
    scanner : SCANF OPBRAC STRING scattributes CLBRAC SEMICOLON
    declarationStatement : INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  {printf("INT F WITH PARAMS..\n");}
    		| CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements {printf("char F WITH PARAMS..\n");}
    		| FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements {printf("float F WITH PARAMS..\n");}
    		| INT IDENTIFIER OPBRAC CLBRAC compoundStatements
    		| FLOAT IDENTIFIER OPBRAC CLBRAC compoundStatements
    		| CHAR IDENTIFIER OPBRAC CLBRAC compoundStatements
    		| INT declarationListIntFloat SEMICOLON {printf("DS1..\n");}
    		| CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING SEMICOLON
    		| CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING SEMICOLON
    		| CHAR declarationListChar SEMICOLON
    		| FLOAT declarationListIntFloat SEMICOLON
    		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON
    		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON
     
    arrayValues :  INTVAL COMMA arrayValues | INTVAL 
    prattributes : COMMA IDENTIFIER prattributes | 
    scattributes : COMMA AMPERSAND IDENTIFIER scattributes | 
    		
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
     
    statementList : basicStatements statementList | specialStatement statementList | functionCall statementList | returnDec | printer statementList | scanner statementList | 
     
    returnDec : RETURN expressionStatement SEMICOLON | RETURN SEMICOLON 
    /* array */
    // arrayDec : type declarator SEMICOLON {printf("ARRAY START..\n");} | charArrayDec
    // charArrayDec : CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING
    			|  CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING
    declarator : IDENTIFIER dimension {printf("declarator..\n");}
    dimension : BOXOPEN INTVAL BOXCLOSE {printf("size..\n");}
    		  | BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE 
    		  | BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE
    %%
     
    #include "lex.yy.c"
    int main(){
    	yyin = fopen("./Test Cases/input.txt","r");
    	if(!yyparse())
    	{
    		printf("Parsing Done\n");
    	}
    	else 
    		printf("Failed\n");
    	exit(0);
    }
     
     