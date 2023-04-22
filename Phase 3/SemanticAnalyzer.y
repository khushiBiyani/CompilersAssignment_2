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
 	int scopeIndex=0;// AvailableScopes array index points to the current 
 	int currIndex=0;// table array index points to the next empty one
 	int maxScope=0;
 	int currScope=0;
	char* instanceParamList[1000];
  
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
	void printTable(){
		printf("TABLE IS THIS\n\n");
		printf("Lexeme		Value 		dataType 		isFunc		isArray			scope			paramCount		paramList		dimensionofArray	arrayList\n"); 
		for(int i=0;i<currIndex;i++){
			printf("%s		",table[i].lexeme);
			printf("%s		",table[i].value);
			printf("%s		",table[i].dataType);
			printf("%d		",table[i].isFunction);
			printf("%d		",table[i].isArray);
			printf("%d		",table[i].scope);
			printf("%d		",table[i].parameterCount);
			if(table[i].isFunction){
				for(int p = 0;p<table[i].parameterCount;p++){
					printf("%s ",table[i].parameterList[p]);
				}
			}
			printf("		");
			
			printf("%d		",table[i].dimensionofArray);
			if(table[i].isArray){
				for(int p = 0;p<table[i].dimensionofArray;p++){
					printf("%d ",table[i].arrayDimension[p]);
				}
			}
			printf("\n");
		}
	}
	void pushNewScope(){// Put a new scope for every open {
		availableScopes[++scopeIndex]=++maxScope;
		currScope = maxScope;
	}
	void popScope(){ // pop latest scope on every }
		availableScopes[scopeIndex--]=-1;
		currScope = availableScopes[scopeIndex];
	}
 %}

 %union{
		int Int;
		float Float;
		char Char;
		char* Str;
		struct data{

		};
	}
 %start code
 // 'i' for INT 
 // 'f' for FLOAT
 // 'c' for CHAR 
 // 's' for CHAR*
 /* left associative */
 %left <Str> LOGICALOR LOGICALAND EQUALS NOTEQUAL GREATERTHAN GREATERTHANEQUALTO LESSTHAN LESSTHANEQUALTO ADD SUB MULT DIV MOD
  
 /* Punctuators */
 %token <Str> COMMA SEMICOLON AMPERSAND COLON 
  
 /* Type */
 %token <Str> INT CHAR FLOAT STRING
  
 /* Keywords */
 %token <Str> IF ELSE FOR WHILE DEFAULT SWITCH CASE BREAK CONTINUE RETURN PRINTF SCANF
  
 /* parenthesis */
 %token <Str> OPBRAC CLBRAC OPCUR CLCUR BOXOPEN BOXCLOSE
  
 /* right associative */
 %right <Str> LOGICALNOT EQUAL
  
 %token <Str> CHARVAL 
 %token <Str> INTVAL
 %token <Str> FLOATVAL
  
%token <Str> IDENTIFIER
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
singleStatement : specialStatement
 		   | basicStatement 
 		   | functionCall
  
 specialStatement : FOR {pushNewScope();} forLoop 
 				 | ifStatement
 				 | whileLoop
 				 | switchStatement
 forLoop : forLoop2 | forLoop3 | forLoop1
 /* for loop */
 forLoop1 :  OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement  CLBRAC SEMICOLON {popScope(); printf("\nFOR SEMICOLON \n");}
forLoop2 : OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR {pushNewScope();} inLoop CLCUR {popScope(); popScope(); printf("\nproper FOR \n");}
 forLoop3 : OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC {pushNewScope();} singleLoopStatement {popScope(); popScope(); printf("\nFOR SINGLE STATEMENT \n");}
  
 singleLoopStatement : specialStatement 
 					| basicStatement
 					| functionCall
 					| BREAK SEMICOLON
 					| CONTINUE SEMICOLON
 					| switchStatement
 					| ifInLoopStatement
  
 forAssignStatement : assignmentStatement 
 					| INT IDENTIFIER EQUAL expressionStatement SEMICOLON {}
 					| INT IDENTIFIER EQUAL expressionStatement COMMA  forAssignStatement
 					| CHAR IDENTIFIER EQUAL expressionStatement SEMICOLON 
 					| CHAR IDENTIFIER EQUAL expressionStatement COMMA  forAssignStatement
 					| SEMICOLON
 forExpStatement : expressionStatement 
 					| 
 forUpdateStatement : IDENTIFIER EQUAL expressionStatement COMMA forUpdateStatement
 				   | IDENTIFIER EQUAL expressionStatement 
  
 /* while loop */
whileLoop : WHILE OPBRAC {pushNewScope();} expressionStatement CLBRAC whileSuffix
 whileSuffix : OPCUR {pushNewScope();}inLoop CLCUR { popScope(); popScope(); printf("\nproper WHILE \n");}
 		  | SEMICOLON {popScope(); printf("\nWHILE SEMICOLON \n");}
 		  | {pushNewScope();} singleLoopStatement { popScope(); popScope(); printf("\nSINGLE WHILE \n");}
  
 inLoop : BREAK SEMICOLON inLoop {printf("\n break in loop \n");}
 		| CONTINUE SEMICOLON inLoop {printf("\ncontinue in loop \n");}
 		| specialStatement inLoop {printf("\n special statement in loop \n");}
 		| basicStatement inLoop {printf("\n basic statement in loop \n");}
  		|functionCall inLoop {printf("\n basic statement in loop \n");}
 		| ifInLoopStatement inLoop {printf("\n if in loop \n");}
 		| switchStatement inLoop {printf("\n switch in loop \n");}
 		| singleLoopStatement inLoop {printf("\n any other statement in loop \n");}
 		|
  
 ifStatement : IF OPBRAC expressionStatement CLBRAC OPCUR {pushNewScope();} statements {popScope();} CLCUR ifContinuer
			| IF OPBRAC expressionStatement CLBRAC {pushNewScope();} singleStatement {popScope();} ifContinuer
ifContinuer : ES 
			| ifStatement
  
 ES : ELSE IF OPBRAC expressionStatement CLBRAC OPCUR {pushNewScope();} statements {popScope();} CLCUR ES
 	| ELSE OPCUR {pushNewScope();} statements {popScope();} CLCUR
 	|ELSE IF OPBRAC expressionStatement CLBRAC {pushNewScope();} singleStatement {popScope();} ES
 	| ELSE {pushNewScope();} singleStatement {popScope();}
	|
  
 ifInLoopStatement : IF OPBRAC expressionStatement CLBRAC OPCUR {pushNewScope();} inLoop {popScope;} CLCUR ifInLoopContinuer
ifInLoopContinuer : ESLoop 
					| ifInLoopStatement
  
 ESLoop : ELSE IF OPBRAC expressionStatement CLBRAC OPCUR {pushNewScope();} inLoop {popScope();}CLCUR ESLoop
 	| ELSE OPCUR {pushNewScope();} inLoop {popScope();} CLCUR
 	|ELSE IF OPBRAC expressionStatement CLBRAC {pushNewScope();} singleLoopStatement {popScope();} ESLoop
 	| ELSE {pushNewScope();} singleLoopStatement {popScope();}
	|
  
 switchStatement : SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR {pushNewScope();} caseStatements defaultStatement {popScope();} CLCUR {printf("SWITCH START..\n");}
 caseStatements : caseStatementInt | {printf("char/int..\n");}
 caseStatementInt : {pushNewScope();} caseInt {pushNewScope();} caseStatementInt | {printf("INT CASE..\n");}
 caseInt : CASE OPBRAC INTVAL CLBRAC COLON caseContinuer
 		| CASE INTVAL COLON caseContinuer {printf("CASE INT : ..\n");}
 		| CASE OPBRAC CHARVAL CLBRAC COLON caseContinuer
 		| CASE CHARVAL COLON caseContinuer
caseContinuer :  statements BREAK SEMICOLON 
				| statements 
 defaultStatement : DEFAULT COLON {pushNewScope();} statements {popScope();} 
 					| {printf(" \nDEFAULT : ..\n");}
  
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
 		| CHAR IDENTIFIER OPBRAC   parameters CLBRAC compoundStatements {printf("char F WITH PARAMS..\n");}
 		| FLOAT IDENTIFIER OPBRAC  parameters CLBRAC compoundStatements {printf("float F WITH PARAMS..\n");}
 		| INT IDENTIFIER OPBRAC  {pushNewScope();} CLBRAC compoundStatements
 		| FLOAT IDENTIFIER OPBRAC  {pushNewScope();}  CLBRAC compoundStatements
 		| CHAR IDENTIFIER OPBRAC  {pushNewScope();}  CLBRAC compoundStatements
 		| INT declarationListIntFloat SEMICOLON {printf("DS1..\n");}
 		| CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING SEMICOLON
 		| CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING SEMICOLON
 		| CHAR declarationListChar SEMICOLON
 		| FLOAT declarationListIntFloat SEMICOLON
 		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON
 		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON
  
 arrayValues :  INTVAL COMMA arrayValues 
 			| INTVAL 
 prattributes : COMMA IDENTIFIER prattributes 
 			| 
 scattributes : COMMA AMPERSAND IDENTIFIER scattributes 
 			| 
 		
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
 	
 factor : IDENTIFIER {} // need function to get type of IDENTIFIER
 	| OPBRAC expressionStatement CLBRAC {$<Str>$ = strdup($2);}
 	| LOGICALNOT expressionStatement {$<Str>$ = strdup($2);}
 	| CHARVAL {$<Str>$ = strdup("c");}
 	| INTVAL {$<Str>$ = strdup("i");printf("INT VALS.. %d\n",yylval);}
 	| FLOATVAL {$<Str>$ = strdup("f");}
 	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE {} // need function to get type of IDENTIFIER
 	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE {} // need function to get type of IDENTIFIER
  
  
 functionCall : IDENTIFIER OPBRAC CLBRAC SEMICOLON {} // need function to get type of IDENTIFIER
              | IDENTIFIER OPBRAC argList CLBRAC SEMICOLON {} // need function to get type of IDENTIFIER
  
 /* changes to be made - either expressionStatement or expression */
 argList : argList COMMA expressionStatement 
 		| expressionStatement 
  
 parameters : {pushNewScope();} paramContinuer
paramContinuer : parameter 
				| parameter COMMA paramContinuer  {printf("FUNCTION params\n");}
  
 parameter : type IDENTIFIER {printf("FUNCTION param\n");insertInTable($2,$1,$1,currScope,0,NULL,NULL.0,false,false);}
  
 type : INT {$<Str>$ = strdup("i");} 
 		| FLOAT {$<Str>$ = strdup("f");}
		| CHAR  {$<Str>$ = strdup("c");}
  
 compoundStatements : OPCUR statementList CLCUR {popScope();printf("FUNCTION statements\n");}
  
 statementList : basicStatements statementList 
 				| specialStatement statementList 
				| functionCall statementList 
				| returnDec 
				| printer statementList 
				| scanner statementList 
				| 
  
 returnDec : RETURN expressionStatement SEMICOLON {$<Str>$ = strdup($2);} 
 			| RETURN SEMICOLON 

 declarator : IDENTIFIER dimension {printf("declarator..\n");}

 dimension : BOXOPEN INTVAL BOXCLOSE {printf("size..\n");}
 		  | BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE 
 		  | BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE
 %%
  
 #include "lex.yy.c"
 int main(){
 	yyin = fopen("./Test Cases/input.txt","r");
	availableScopes[0] = 0;
 	if(!yyparse())
 	{
 		printf("Parsing Done\n");
 	}
 	else 
 		printf("Failed\n");
	
	printTable();
 	exit(0);
 }
  
  