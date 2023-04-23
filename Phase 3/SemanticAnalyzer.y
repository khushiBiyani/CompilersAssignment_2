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
     		int dimensionofArray=-1;
     		char *parameterList[1000];
     		int arrayDimension[2]={-1,-1};
     		int parameterCount=-1;
     	};
     	symbolTable table[1000];
     	int availableScopes[1000]={-1};
     	int scopeIndex=0;// AvailableScopes array index points to the current 
     	int currIndex=0;// table array index points to the next empty one
     	int maxScope=0;
     	int currScope=0;
    	char* instanceParamList[1000];
    	int currentParamCount = 0;
    	int sizes[2]={-1,-1};
    	int instDim=0;
		char* arglistArray[500];
		int argindex = 0;
      
     	// insert function
     	void insertInTable(char *token,char *type,char *val,int sc,int paramCount,char *paramList[],int arrayDim[],int dimensionofArr,bool isArr,bool isFunc){
     		symbolTable newEntry;
     		newEntry.lexeme = strdup(token);
     		newEntry.value = strdup(val);
     		newEntry.dataType = strdup(type);
     		newEntry.scope=sc;
     
     		if(isFunc){
         		for(int i =0;i<paramCount;i++){
         			newEntry.parameterList[i] = strdup(paramList[i]);
         		}
         		newEntry.parameterCount=paramCount;
         	}
    		newEntry.isFunction = isFunc;
    		
     		newEntry.isArray = isArr;
         	if(isArr){
         		for(int i =0;i<dimensionofArr;i++){
         				newEntry.arrayDimension[i]=arrayDim[i];
         		}
         		newEntry.dimensionofArray=dimensionofArr;
         	}
     		table[currIndex++]=newEntry;
    		printf("INSIDE TABLE INSERTION\n");
     	}
      
     	// update value of token
     	void updateVal(int sc,char *token,char *value)
     	{
     		int instScopeIndex=sc;
     		int tableIndex=currIndex;
     		for(int i=tableIndex-1;i>=0;i--)
     		{	
     			if(strcmp(table[i].lexeme,token)==0){
    				for(int j = scopeIndex;j>=0;j--){
    					if(table[i].scope==availableScopes[j]){
    						strcpy(table[i].value,value);
    						return;
    					}
    				}
    			}
     		}
     	}
    	int getIdentifierIndex(char *token, bool isArray, bool isFunction)
     	{
     		int tableIndex=currIndex;
     		for(int i=tableIndex-1;i>=0;i--)
     		{	
     			if(strcmp(table[i].lexeme,token)==0){
    				for(int j = scopeIndex;j>=0;j--){
    					if(table[i].scope==availableScopes[j]&&table[i].isArray==isArray&&isFunction==table[i].isFunction){
    						return i;
    					}
    				}
    			}
     		}
    		return -1;
     	}
    	void printTable(){
    		printf("TABLE IS THIS\n\n");
     
    		for(int i=0;i<currIndex;i++){
    			printf("lexeme = %s		",table[i].lexeme);
    			printf("value = %s		",table[i].value);
    			printf("type = %s		",table[i].dataType);
    			printf(" isFunction = %d		",table[i].isFunction);
    			printf("isArray = %d		",table[i].isArray);
    			printf("scope = %d		",table[i].scope);
    			printf("paramCount = %d		",table[i].parameterCount);
    			if(table[i].isFunction){
    				printf("Parameter array = ");
    				for(int p = 0;p<table[i].parameterCount;p++){
    					
    					printf("%s ",table[i].parameterList[p]);
    				}
    			}
    			printf("		");
    			
    			printf(" dimensionofArr = %d		",table[i].dimensionofArray);
    			if(table[i].isArray){
    				printf("Parameter array = ");
    				for(int p = 0;p<table[i].dimensionofArray;p++){
    					printf("%d ",table[i].arrayDimension[p]);
    				}
    			}
    			printf("\n");
    		}
    	}
		bool checkVariable(char* token, int scope, bool isArray, bool isFunction){
			int tableIndex=currIndex;
     		for(int i=tableIndex-1;i>=0;i--)
     		{	
     			if(strcmp(table[i].lexeme,token)==0&&table[i].isArray==isArray&&table[i].isFunction==isFunction){
    				for(int j = scopeIndex;j>=0;j--){
    					if(table[i].scope==availableScopes[j]&& availableScopes[j]==scope){
    						return true;
    					}
    				}
    			}
     		}
    		return false;
		}
		int checkVariableScope(char* token, int scope, bool isArray, bool isFunction){
			int tableIndex=currIndex;
     		for(int i=tableIndex-1;i>=0;i--)
     		{	
     			if(strcmp(table[i].lexeme,token)==0&&table[i].isArray==isArray&&table[i].isFunction==isFunction){
    				for(int j = scopeIndex;j>=0;j--){
    					if(table[i].scope==availableScopes[j]){
							printf("VARIABLE %s FOUND\n\n\n\n",token);
    						return i;
    					}
    				}
    			}
     		}
			printf("VARIABLE %s NOT FOUND\n\n\n\n",token);
    		return -1;
		}
		bool compareParam(char* args[], char* params[], int arg, int par){
			int n = arg;
			if(par>arg){
				n = par;
			}
			for(int i = 0;i<n;i++){
				if(strcmp(args[i],params[i])!=0){
					return false;
				}
			}
			return true;
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
     %token <Int> INTVAL
     %token <Float> FLOATVAL
     
     %type <Str> expressionStatement type term value relationalExpression expression logicalExpression factor
     
     
      
    %token <Str> IDENTIFIER
     %%
      
     /* start of the program */
     code : declarationList {}
      
     declarationList :  declarationStatement declarationList {}
     				|  assignmentStatement declarationList
     				|  declarationStatement {}
     				|  assignmentStatement
      
     statements : specialStatement statements {}
     		   | basicStatement statements {}
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
     forLoop1 :  OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement  CLBRAC SEMICOLON {popScope(); }
    forLoop2 : OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR {pushNewScope();} inLoop CLCUR {popScope(); popScope(); }
     forLoop3 : OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC {pushNewScope();} singleLoopStatement {popScope(); popScope(); }
      
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
     whileSuffix : OPCUR {pushNewScope();}inLoop CLCUR { popScope(); popScope(); }
     		  | SEMICOLON {popScope(); printf("\nWHILE SEMICOLON \n");}
     		  | {pushNewScope();} singleLoopStatement { popScope(); popScope();}
      
     inLoop : BREAK SEMICOLON inLoop {}
     		| CONTINUE SEMICOLON inLoop {}
     		| specialStatement inLoop {}
     		| basicStatement inLoop {}
      		|functionCall inLoop {}
     		| ifInLoopStatement inLoop {}
     		| switchStatement inLoop {}
     		| singleLoopStatement inLoop {}
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
      
     switchStatement : SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR {pushNewScope();} caseStatements defaultStatement {popScope();} CLCUR {}
     caseStatements : caseStatementInt | {}
     caseStatementInt : {pushNewScope();} caseInt {pushNewScope();} caseStatementInt | {}
     caseInt : CASE OPBRAC INTVAL CLBRAC COLON caseContinuer
     		| CASE INTVAL COLON caseContinuer {}
     		| CASE OPBRAC CHARVAL CLBRAC COLON caseContinuer
     		| CASE CHARVAL COLON caseContinuer
    caseContinuer :  statements BREAK SEMICOLON 
    				| statements 
     defaultStatement : DEFAULT COLON {pushNewScope();} statements {popScope();} 
     					| {}
      
     /* basic statements */
     basicStatements : basicStatement basicStatements
     		| basicStatement
      
     basicStatement : expressionStatement {}
     		| declarationStatement {}
     		| assignmentStatement	{}
    		| functionCall
     		
     assignmentStatement : IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement {}
     		| IDENTIFIER EQUAL expressionStatement SEMICOLON {}
      
     printer : PRINTF OPBRAC STRING prattributes CLBRAC SEMICOLON
     scanner : SCANF OPBRAC STRING scattributes CLBRAC SEMICOLON
     declarationStatement : INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  {int inst = getIdentifierIndex($2,false,true); if(inst == -1){insertInTable($2,strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);}else{printf("%s is already defined earlier\n",$2);return 1;}memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
     		| CHAR IDENTIFIER OPBRAC   parameters CLBRAC compoundStatements {int inst = getIdentifierIndex($2,false,true); if(inst ==-1){insertInTable($2,strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",$2);return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
     		| FLOAT IDENTIFIER OPBRAC  parameters CLBRAC compoundStatements {int inst = getIdentifierIndex($2,false,true); if(inst == -1){insertInTable($2,strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",$2);return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
     		| INT IDENTIFIER OPBRAC  {pushNewScope();} CLBRAC compoundStatements {int inst = getIdentifierIndex($2,false,true); if(inst == -1){insertInTable($2,strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",$2);return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
     		| FLOAT IDENTIFIER OPBRAC  {pushNewScope();}  CLBRAC compoundStatements {int inst = getIdentifierIndex($2,false,true); if(inst == -1){insertInTable($2,strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",$2);return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
     		| CHAR IDENTIFIER OPBRAC  {pushNewScope();}  CLBRAC compoundStatements {int inst = getIdentifierIndex($2,false,true); if(inst == -1){insertInTable($2,strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",$2);return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
     		| INT declarationListInt SEMICOLON {}
     		| CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING SEMICOLON
     		| CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING SEMICOLON
     		| CHAR declarationListChar SEMICOLON
     		| FLOAT declarationListFloat SEMICOLON
     		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON {}
     		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON {}
     
    		// IF FLOAT ALLOW ONLY FLOAT IN EXP, same for char and INT 
      
     arrayValues :  INTVAL COMMA arrayValues 
     			| INTVAL 
     prattributes : COMMA IDENTIFIER prattributes 
     			| 
     scattributes : COMMA AMPERSAND IDENTIFIER scattributes 
     			| 
     		
     declarationListInt : IDENTIFIER EQUAL expressionStatement COMMA declarationListInt {printf("DSL1..\n");}
     		| IDENTIFIER COMMA declarationListInt { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
     		| IDENTIFIER EQUAL expressionStatement {}
     		| IDENTIFIER dimension  {if(checkVariable($1,currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
     		| IDENTIFIER { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
     		
     declarationListFloat : IDENTIFIER EQUAL expressionStatement COMMA declarationListFloat {printf("DSL1..\n");}
     		| IDENTIFIER COMMA declarationListFloat { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
     		| IDENTIFIER EQUAL expressionStatement {printf("DSL3..\n");}
     		| IDENTIFIER dimension  {if(checkVariable($1,currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;} 
     		| IDENTIFIER { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
     
     declarationListChar : IDENTIFIER EQUAL CHARVAL COMMA declarationListChar 
     		| IDENTIFIER COMMA declarationListChar { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
     		| IDENTIFIER EQUAL CHARVAL
     		| IDENTIFIER dimension {if(checkVariable($1,currScope,true,true)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;} 
     		| IDENTIFIER { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
     		
     expressionStatement : logicalExpression LOGICALOR expressionStatement {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     		| logicalExpression {$<Str>$ = strdup($1);}
     		
     logicalExpression : expression LOGICALAND logicalExpression {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     		| expression {$<Str>$ = strdup($1);}
     		
     expression : relationalExpression EQUALS expression {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     		| relationalExpression NOTEQUAL expression {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     		| relationalExpression {$<Str>$ = strdup($1);}
     		
     relationalExpression : value GREATERTHAN relationalExpression {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     		| value GREATERTHANEQUALTO relationalExpression {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     		| value LESSTHAN relationalExpression {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     		| value LESSTHANEQUALTO relationalExpression {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     		| value {$<Str>$ = strdup($1);}
     		
     value : term ADD value {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     	| term SUB value {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     	| term {$<Str>$ = strdup($1);}
     	
     term : factor MULT term {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     	| factor DIV term {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     	| factor MOD term {if(strcmp($1,$3)==0){$<Str>$ = strdup($1);}else{printf("TYPES dont match\n\n");return 1;}}
     	| factor {$<Str>$ = strdup($1);}
     	
     factor : IDENTIFIER {int inst = checkVariableScope($1,currScope,false,false); if(inst!=-1){$<Str>$ = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",$1);return 1;}} // need function to get type of IDENTIFIER
     	| OPBRAC expressionStatement CLBRAC {$<Str>$ = strdup($2);}
     	| LOGICALNOT expressionStatement {$<Str>$ = strdup($2);}
     	| CHARVAL {$<Str>$ = strdup("c");}
     	| INTVAL {$<Str>$ = strdup("i");printf("INT VALS.. %d\n",yylval);}
     	| FLOATVAL {$<Str>$ = strdup("f");}
    	| IDENTIFIER OPBRAC CLBRAC {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0; int inst = getIdentifierIndex($1,false,true);if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){$<Str>$ = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}} 
    	| IDENTIFIER OPBRAC {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;} argList CLBRAC {int inst = getIdentifierIndex($1,false,true); if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){$<Str>$ = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}}
     	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE {int inst = checkVariableScope($1,currScope,true,false); if(inst!=-1){$<Str>$ = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",$1);return 1;}} // need function to get type of IDENTIFIER
     	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE {int inst = checkVariableScope($1,currScope,true,false); if(inst!=-1){$<Str>$ = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",$1);return 1;}} // need function to get type of IDENTIFIER
      
      
     functionCall : IDENTIFIER OPBRAC CLBRAC SEMICOLON{} // need function to get type of IDENTIFIER
                  | IDENTIFIER OPBRAC argList CLBRAC SEMICOLON{} // need function to get type of IDENTIFIER
      
     /* changes to be made - either expressionStatement or expression */
     argList : expressionStatement COMMA argList {arglistArray[argindex++]=strdup($1);}
     		| expressionStatement {arglistArray[argindex++]=strdup($1);}
      
     parameters : {pushNewScope(); memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;} paramContinuer
    paramContinuer : parameter 
    				| parameter COMMA paramContinuer  {printf("FUNCTION params\n");}
      
     parameter : type IDENTIFIER {printf("FUNCTION param\n");insertInTable($2,$1,$1,currScope,0,NULL,NULL,0,false,false);}
      
     type : INT {$<Str>$ = strdup("i");instanceParamList[currentParamCount++]=strdup("i");} 
     		| FLOAT {$<Str>$ = strdup("f");instanceParamList[currentParamCount++]=strdup("f");}
    		| CHAR  {$<Str>$ = strdup("c");instanceParamList[currentParamCount++]=strdup("c");}
      
     compoundStatements : OPCUR statementList CLCUR {popScope();printf("FUNCTION statements\n");}
      
     statementList : functionCall {printf("checked if function call");}statementList {printf("direct function call in list");}
     				| basicStatements statementList 
     				| specialStatement statementList
    				| returnDec 
    				| printer statementList 
    				| scanner statementList 
    				| 
      
     returnDec : RETURN expressionStatement SEMICOLON {$<Str>$ = strdup($2);} // Get function type and compare types here
     			| RETURN SEMICOLON 
     
     dimension : BOXOPEN INTVAL BOXCLOSE {int i = $2; if(i<=0){printf("Array size has to be  Positive\n"); return 1;}sizes[0] = $2;instDim++;}
     		  | BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE {int a = $2; int b = $5; if(a<=0||b<=0){printf("Array sizes has to be  Positive\n"); return 1;}sizes[0] = $2; sizes[1] = $5;instDim+=2;}
     		  | BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE {int i = $4; if(i<=0){printf("Array sizes has to be  Positive\n"); return 1;}sizes[1] = $4;instDim+=2;}
     %%
      
     #include "lex.yy.c"
     int main(){
     	yyin = fopen("./Test Cases/input.txt","r");
    	availableScopes[0] = 0;
     	if(!yyparse())
     	{
     		printf("\n\nParsed Successfully\n\n");
		
     	}
     	else 
     		printf("\n\nParsing Failed\n\n");
    	
			printTable();
     	exit(0);
     }
      
      