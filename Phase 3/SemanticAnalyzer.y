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
		char* printlistArray[500];
		int printindex = 0;
		char* scanlistArray[500];
		int scanindex = 0;
		char* presentFunctionType;
		char* instanceStringList[500];
		int instanceStringIndex = 0;
		void populate(char* str, int len){
			for(int i = 0; i < len; i++) {
       			 if(str[i] == '%' && str[i+1] != '\0' && strchr("cdfs", str[i+1])) {
				if(str[i+1]=='d'){
					instanceStringList[instanceStringIndex++] = strdup("i");
				}
				else if(str[i+1]=='f'){
					instanceStringList[instanceStringIndex++] = strdup("f");
				}
				else if(str[i+1]=='c'){
					instanceStringList[instanceStringIndex++] = strdup("c");
				}
        		}
	  		}
		}
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
		int getPresentFunctionIndex()
     	{
     		int tableIndex=currIndex;
     		for(int i=tableIndex-1;i>=0;i--)
     		{	
     			if(table[i].isFunction){
    				for(int j = scopeIndex;j>=0;j--){
    					if(table[i].scope==availableScopes[j]&&table[i].isFunction){
    						return i;
    					}
    				}
    			}
     		}
    		return -1;
     	}
    	void printTable(){
    		printf("SYMBOL TABLE: \n\n");
			printf("Lexeme 	  	Val	Type	isFunc	isArr	scope	parameterCount	 paramList	dimArr 		arrList\n");
    		for(int i=0;i<currIndex;i++){
    			printf("%s		",table[i].lexeme);
    			printf("%s	",table[i].value);
    			printf("%s	",table[i].dataType);
    			printf("%d	",table[i].isFunction);
    			printf("%d	",table[i].isArray);
    			printf("%d		",table[i].scope);
    			printf("%d	   ",table[i].parameterCount);
    			if(table[i].isFunction){
    				printf("");
    				for(int p = 0;p<table[i].parameterCount;p++){
    					
    					printf("%s ",table[i].parameterList[p]);
    				}
    			}
    			printf("		");
    			
    			printf("%d		",table[i].dimensionofArray);
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
    						return i;
    					}
    				}
    			}
     		}
    		return -1;
		}
		bool compareParam(char* args[], char* params[], int arg, int par){
			if(arg!=par){
				return false;
			}
			int n = arg;
			
			for(int i = 0;i<n;i++){
				if(strcmp(args[i],params[i])!=0){
					return false;
				}
			}
			return true;
		}
		bool compareString(char* str,char* param[],int len,int sizep){
			int yup = 0;
			int re = 0;
			for(int i = 0; i < len; i++) {
       			 if(str[i] == '%' && str[i+1] != '\0' && strchr("cdes", str[i+1])) {
				re++;
				yup++;
            	i++;
        		}
	  		}
			return true;
		}
		void printArray(char* arr[],int len){
			
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
						| returnDec
      
     forAssignStatement : assignmentStatement 
     					| INT IDENTIFIER EQUAL expressionStatement SEMICOLON { if(checkVariable($2,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$2);return 1;}if(strcmp($4,strdup("i"))!=0){printf("Type Mismatch");return 1;}insertInTable($2,strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
     					| INT IDENTIFIER EQUAL expressionStatement COMMA  forAssignStatement { if(checkVariable($2,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$2);return 1;}if(strcmp($4,strdup("i"))!=0){printf("Type Mismatch");return 1;}insertInTable($2,strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
     					| CHAR IDENTIFIER EQUAL expressionStatement SEMICOLON { if(checkVariable($2,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$2);return 1;}if(strcmp($4,strdup("c"))!=0){printf("Type Mismatch");return 1;}insertInTable($2,strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
     					| CHAR IDENTIFIER EQUAL expressionStatement COMMA  forAssignStatement { if(checkVariable($2,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$2);return 1;}if(strcmp($4,strdup("c"))!=0){printf("Type Mismatch");return 1;}insertInTable($2,strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
     					| SEMICOLON
     forExpStatement : expressionStatement 
     					| 
     forUpdateStatement : IDENTIFIER EQUAL expressionStatement COMMA forUpdateStatement {int inst = getIdentifierIndex($1,false,false); if(inst==-1){printf("VARIABLE NOT FOUND");return 1;}if(strcmp(table[inst].dataType,$3)!=0){printf("VARIABLE NOT FOUND");return 1;}}
     				   | IDENTIFIER EQUAL expressionStatement {int inst = getIdentifierIndex($1,false,false); if(inst==-1){printf("VARIABLE NOT FOUND");return 1;}if(strcmp(table[inst].dataType,$3)!=0){printf("VARIABLE NOT FOUND");return 1;}}
      
     /* while loop */
    whileLoop : WHILE OPBRAC {pushNewScope();} expressionStatement CLBRAC whileSuffix
     whileSuffix : OPCUR {pushNewScope();}inLoop CLCUR { popScope(); popScope(); }
     		  | SEMICOLON {popScope(); }
     		  | {pushNewScope();} singleLoopStatement { popScope(); popScope();}
      
     inLoop : BREAK SEMICOLON inLoop {}
     		| CONTINUE SEMICOLON inLoop {}
     		| specialStatement inLoop {}
     		| basicStatement inLoop {}
      		|functionCall inLoop {}
     		| ifInLoopStatement inLoop {}
     		| switchStatement inLoop {}
     		| singleLoopStatement inLoop {}
			| returnDec
     		| printer {memset(printlistArray,'\0',sizeof(printlistArray));printindex = 0;} inLoop
			| scanner {memset(scanlistArray,'\0',sizeof(scanlistArray));scanindex = 0;} inLoop
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
			| returnDec
    		| functionCall
     		
     assignmentStatement : IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement {int inst = getIdentifierIndex($1,false,false);if(inst>=0){if(strcmp(table[inst].dataType,$3)!=0){printf("Type Mismatch");return 1;}}else{printf("VARIABLE NOT FOUND"); return 1;}}
     		| IDENTIFIER EQUAL expressionStatement SEMICOLON {int inst = getIdentifierIndex($1,false,false);if(inst>=0){if(strcmp(table[inst].dataType,$3)!=0){printf("Type Mismatch");return 1;}}else{printf("VARIABLE NOT FOUND"); return 1;}}
			| IDENTIFIER dimension EQUAL expressionStatement COMMA assignmentStatement {int inst = getIdentifierIndex($1,true,false);if(inst>=0){if(strcmp(table[inst].dataType,$3)!=0){printf("Type Mismatch");return 1;}}else{printf("VARIABLE NOT FOUND"); return 1;}}
     		| IDENTIFIER dimension EQUAL expressionStatement SEMICOLON {int inst = getIdentifierIndex($1,true,false);if(inst>=0){if(strcmp(table[inst].dataType,$3)!=0){printf("Type Mismatch");return 1;}}else{printf("VARIABLE NOT FOUND"); return 1;}}
      
     printer : PRINTF OPBRAC STRING prattributes CLBRAC SEMICOLON {char* presentPrintString = strdup($3); int len = strlen(presentPrintString);printArray(printlistArray,printindex);populate(presentPrintString,len);if(!compareParam(instanceStringList,printlistArray,instanceStringIndex,printindex)){printf("PRINTF TYPE DONOT MATCH\n\n");return 1;}memset(instanceStringList,'\0',sizeof(instanceStringList));memset(printlistArray,'\0',sizeof(printlistArray));instanceStringIndex = 0;printindex = 0;}
     scanner : SCANF OPBRAC STRING scattributes CLBRAC SEMICOLON {char* presentPrintString = strdup($3); int len = strlen(presentPrintString); printArray(scanlistArray,scanindex);populate(presentPrintString,len);if(!compareParam(instanceStringList,scanlistArray,instanceStringIndex,scanindex)){printf("SCANF TYPE DONOT MATCH\n\n");return 1;}memset(instanceStringList,'\0',sizeof(instanceStringList));memset(scanlistArray,'\0',sizeof(scanlistArray));instanceStringIndex = 0;scanindex = 0;}
     declarationStatement : INT IDENTIFIER OPBRAC parameters {presentFunctionType = strdup("i");} CLBRAC compoundStatements  {int inst = getIdentifierIndex($2,false,true); if(inst == -1){insertInTable($2,strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);}else{printf("%s is already defined earlier\n",$2);return 1;}memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
     		| CHAR IDENTIFIER OPBRAC   parameters {presentFunctionType = strdup("c");} CLBRAC compoundStatements {int inst = getIdentifierIndex($2,false,true); if(inst ==-1){insertInTable($2,strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",$2);return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
     		| FLOAT IDENTIFIER OPBRAC  parameters CLBRAC {presentFunctionType = strdup("f");} compoundStatements {int inst = getIdentifierIndex($2,false,true); if(inst == -1){insertInTable($2,strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",$2);return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
     		| INT IDENTIFIER OPBRAC  {pushNewScope();}{presentFunctionType = strdup("i");}  CLBRAC compoundStatements {int inst = getIdentifierIndex($2,false,true); if(inst == -1){insertInTable($2,strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",$2);return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
     		| FLOAT IDENTIFIER OPBRAC  {pushNewScope();}{presentFunctionType = strdup("f");}   CLBRAC compoundStatements {int inst = getIdentifierIndex($2,false,true); if(inst == -1){insertInTable($2,strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",$2);return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
     		| CHAR IDENTIFIER OPBRAC  {pushNewScope();}{presentFunctionType = strdup("c");}   CLBRAC compoundStatements {int inst = getIdentifierIndex($2,false,true); if(inst == -1){insertInTable($2,strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",$2);return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
     		| INT declarationListInt SEMICOLON {}
     		| CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING SEMICOLON {if(checkVariable($2,currScope,true,true)){printf("MULTIPLE DECLARATIONS %s\n\n",$2);return 1;}insertInTable($2,strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;} 
     		| CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING SEMICOLON {if(checkVariable($2,currScope,true,true)){printf("MULTIPLE DECLARATIONS %s\n\n",$2);return 1;}insertInTable($2,strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;} 
     		| CHAR declarationListChar SEMICOLON
     		| FLOAT declarationListFloat SEMICOLON
     		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON {if(checkVariable($2,currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$2);return 1;}insertInTable($2,strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
     		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON {if(checkVariable($2,currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$2);return 1;}insertInTable($2,strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
			| FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValuesF CLCUR SEMICOLON {if(checkVariable($2,currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$2);return 1;}insertInTable($2,strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;} 
     		| FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON {if(checkVariable($2,currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$2);return 1;}insertInTable($2,strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;} 
     
    		// IF FLOAT ALLOW ONLY FLOAT IN EXP, same for char and INT 
      arrayValuesF :  FLOATVAL COMMA arrayValuesF 
     			| FLOATVAL 
     arrayValues :  INTVAL COMMA arrayValues 
     			| INTVAL 
     prattributes : prattributes COMMA factor {printlistArray[printindex++]=strdup($3);}
     			| 
     scattributes : scattributes COMMA AMPERSAND factor {scanlistArray[scanindex++]=strdup($4);}
     			| 
     		
     declarationListInt : IDENTIFIER EQUAL expressionStatement COMMA declarationListInt { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}if(strcmp($3,strdup("i"))!=0){printf("Type Mismatch");return 1;}insertInTable($1,strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
     		| IDENTIFIER COMMA declarationListInt { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
     		| IDENTIFIER EQUAL expressionStatement { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}if(strcmp($3,strdup("i"))!=0){printf("Type Mismatch");return 1;}insertInTable($1,strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
     		| IDENTIFIER dimension  {if(checkVariable($1,currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
     		| IDENTIFIER { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
     		
     declarationListFloat : IDENTIFIER EQUAL expressionStatement COMMA declarationListFloat { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}if(strcmp($3,strdup("f"))!=0){printf("Type Mismatch");return 1;}insertInTable($1,strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
     		| IDENTIFIER COMMA declarationListFloat { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
     		| IDENTIFIER EQUAL expressionStatement { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}if(strcmp($3,strdup("f"))!=0){printf("Type Mismatch");return 1;}insertInTable($1,strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
     		| IDENTIFIER dimension  {if(checkVariable($1,currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;} 
     		| IDENTIFIER { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
     
     declarationListChar : IDENTIFIER EQUAL CHARVAL COMMA declarationListChar {if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
     		| IDENTIFIER COMMA declarationListChar { if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
     		| IDENTIFIER EQUAL expressionStatement {if(checkVariable($1,currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",$1);return 1;}insertInTable($1,strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
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
     	| INTVAL {$<Str>$ = strdup("i");}
     	| FLOATVAL {$<Str>$ = strdup("f");}
    	| IDENTIFIER OPBRAC CLBRAC {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0; int inst = getIdentifierIndex($1,false,true);if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){$<Str>$ = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;} 
    	| IDENTIFIER OPBRAC {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;} argList CLBRAC {int inst = getIdentifierIndex($1,false,true); printArray(arglistArray,argindex); if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){$<Str>$ = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
     	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE {int inst = checkVariableScope($1,currScope,true,false); if(inst!=-1){$<Str>$ = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",$1);return 1;}} // need function to get type of IDENTIFIER
     	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE {int inst = checkVariableScope($1,currScope,true,false); if(inst!=-1){$<Str>$ = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",$1);return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;} // need function to get type of IDENTIFIER
      
      
     functionCall : IDENTIFIER OPBRAC CLBRAC SEMICOLON{memset(arglistArray,'\0',sizeof(arglistArray));argindex=0; int inst = getIdentifierIndex($1,false,true);if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){$<Str>$ = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;} // need function to get type of IDENTIFIER
                  | IDENTIFIER OPBRAC argList CLBRAC SEMICOLON {int inst = getIdentifierIndex($1,false,true); if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){$<Str>$ = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;} // need function to get type of IDENTIFIER
      
     /* changes to be made - either expressionStatement or expression */
     argList : argList COMMA expressionStatement  {arglistArray[argindex++]=strdup($3);}
     		| expressionStatement {arglistArray[argindex++]=strdup($1);}
      
     parameters : {pushNewScope(); memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;} paramContinuer
    paramContinuer : parameter 
    				| parameter COMMA paramContinuer  
      
     parameter : type IDENTIFIER {insertInTable($2,$1,$1,currScope,0,NULL,NULL,0,false,false);}
      
     type : INT {$<Str>$ = strdup("i");instanceParamList[currentParamCount++]=strdup("i");} 
     		| FLOAT {$<Str>$ = strdup("f");instanceParamList[currentParamCount++]=strdup("f");}
    		| CHAR  {$<Str>$ = strdup("c");instanceParamList[currentParamCount++]=strdup("c");}
      
     compoundStatements : OPCUR statementList CLCUR {popScope();}
      
     statementList : functionCall statementList 
     				| basicStatements statementList 
     				| specialStatement statementList
    				| returnDec 
    				| printer {memset(printlistArray,'\0',sizeof(printlistArray));
		printindex = 0;} statementList 
    				| scanner {memset(scanlistArray,'\0',sizeof(scanlistArray));
		scanindex = 0;} statementList 
    				| 
     
     returnDec : RETURN expressionStatement SEMICOLON {if(strcmp(presentFunctionType,$2)==0){$<Str>$ = strdup($2);}else{printf("INVALID RETURN");return 1;}} 
     			| RETURN SEMICOLON {int inst = getPresentFunctionIndex(); $<Str>$ = strdup(presentFunctionType);}
     
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
			printTable();
     	}
     	else 
     		printf("\n\nParsing Failed\n\n");
    	
			
     	exit(0);
     }
      
      