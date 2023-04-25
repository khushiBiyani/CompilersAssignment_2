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
	FILE *outFile=fopen("astString.txt","w");
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
     		printf("%c\n", str[i+1]);
    		}
  		}
		printf("STRING PARAMS = ");
		for(int i = 0;i<instanceStringIndex;i++){
			printf("%s ",instanceStringList[i]);
		}
		printf("\n");
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
		printf("%d %d\n",len,sizep);
		for(int i = 0; i < len; i++) {
   			 if(str[i] == '%' && str[i+1] != '\0' && strchr("cdes", str[i+1])) {
			re++;
			yup++;
     		printf("%c\n", str[i+1]);
        	i++;
    		}
			printf("%d %d %d\n",yup,re,i);
  		}
		return true;
	}
	void printArray(char* arr[],int len){
		printf("Args = ");
		for(int i = 0;i<len;i++){
			printf("%s ",arr[i]);
		}
		printf("\n");
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

%type <Str> code declarationList statements singleStatement specialStatement forLoop forLoop1 forLoop2 forLoop3 singleLoopStatement forAssignStatement forExpStatement forUpdateStatement whileLoop whileSuffix inLoop ifStatement ifContinuer ES ifInLoopContinuer ifInLoopStatement ESLoop switchStatement caseStatements caseStatementInt caseInt caseContinuer defaultStatement basicStatements basicStatement assignmentStatement printer Scanner declarationStatement arrayValuesF arrayValues prattributes scattributes declarationListInt declarationListFloat declarationListChar expressionStatement logicalExpression expression relationalExpression value term factor functionCall argList paramContinuer parameters parameter type compoundStatements statementList returnDec dimension
 
 
  
%token <Str> IDENTIFIER
 %%
  
 /* start of the program */
code : declarationList {}
  
declarationList :  declarationStatement declarationList {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#DS#");strcat(temp,$1);strcat(temp,"@@#DL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
 				|  assignmentStatement declarationList {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#AS#");strcat(temp,$1);strcat(temp,"@@#DL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
 				|  declarationStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#DS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 				|  assignmentStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#AS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
  
statements : specialStatement statements {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#SS#");strcat(temp,$1);strcat(temp,"@@#Satements#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
 		   | basicStatement statements {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@#Satements#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
 		   | functionCall statements {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#FC#");strcat(temp,$1);strcat(temp,"@@#Satements#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
 		   | 
singleStatement : specialStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#SS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		   | basicStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		   | functionCall {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#FC#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
  
specialStatement : FOR forLoop {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#for@#");strcat(temp,"FL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 				 | ifStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#IFS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 				 | whileLoop {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#WL#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 				 | switchStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#SWS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}

forLoop : forLoop2 {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#FLMany#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| forLoop3 {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#FL1#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| forLoop1 {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#FL;#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
 /* for loop */
forLoop1 :  OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement  CLBRAC SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#(@#");strcat(temp,"ForA#");strcat(temp,$2);strcat(temp,"@@#ForE#");strcat(temp,$3);strcat(temp,"@@#;@#ForU#");strcat(temp,$5);strcat(temp,"@@#)@#;@");$<Str>$=strdup(temp);}
forLoop2 : OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR inLoop CLCUR {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#(@#");strcat(temp,"ForA#");strcat(temp,$2);strcat(temp,"@@#ForE#");strcat(temp,$3);strcat(temp,"@@#;@#ForU#");strcat(temp,$5);strcat(temp,"@@#)@#{@");strcat(temp,"#InL#");strcat(temp,$8);strcat("@@#}@");$<Str>$=strdup(temp);}
forLoop3 : OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC singleLoopStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#(@#");strcat(temp,"ForA#");strcat(temp,$2);strcat(temp,"@@#ForE#");strcat(temp,$3);strcat(temp,"@@#;@#ForU#");strcat(temp,$5);strcat(temp,"@@#)@#");strcat(temp,"SL#");strcat(temp,$7);strcat(temp,"@@");$<Str>$=strdup(temp);}
  
singleLoopStatement : specialStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#SS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| basicStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| functionCall {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#FC#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| BREAK SEMICOLON {$<Str>$=strdup("#break@#;@");}
					| CONTINUE SEMICOLON {$<Str>$=strdup("#continue@#;@");}
					| switchStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#SWS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| ifInLoopStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#IfLoop#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 
forAssignStatement : assignmentStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#FA#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| INT IDENTIFIER EQUAL expressionStatement SEMICOLON {char *temp;temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#int@#");strcat(temp,$2);strcat("@#=@#ES#");strcat(temp,$4);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}
					| INT IDENTIFIER EQUAL expressionStatement COMMA forAssignStatement {char *temp;temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#int@#");strcat(temp,$2);strcat("@#=@#ES#");strcat(temp,$4);strcat(temp,"@@#,@#FA#")strcat(temp,$6);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| CHAR IDENTIFIER EQUAL expressionStatement COMMA forAssignStatement {char *temp;temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#char@#");strcat(temp,$2);strcat("@#=@#ES#");strcat(temp,$4);strcat(temp,"@@#,@#FA#")strcat(temp,$6);strcat(temp,"@@");$<Str>$=strdup(temp);}

forExpStatement : expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#ES#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
				| {$<Str>$=strdup("#Epsilon@");}

forUpdateStatement : IDENTIFIER EQUAL expressionStatement COMMA forUpdateStatement {char *temp;temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#identifier#");strcat(temp,$1);strcat("@@#=@#ES#");strcat(temp,$3);strcat(temp,"@@#,@#ForU#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
  
 /* while loop */
whileLoop : WHILE OPBRAC expressionStatement CLBRAC whileSuffix {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#while@#(@#ES#");strcat(temp,$3);strcat(temp,"@@#)@#WSuffix#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}

whileSuffix : OPCUR inLoop CLCUR {char *temp;temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#{@#InL#");strcat(temp,$2);strcat(temp,"@@#}@");$<Str>$=strdup(temp);}
 		  | SEMICOLON {$<Str>$=strdup(";");}
 		  | singleLoopStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#SLS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
  
inLoop : BREAK SEMICOLON inLoop {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#break@#;@#InL#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| CONTINUE SEMICOLON inLoop {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#continue@#;@#InL#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| specialStatement inLoop {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#SS#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| basicStatement inLoop {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
  		| functionCall inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#FC#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| ifInLoopStatement inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#IfInL#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| switchStatement inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#SS#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| singleLoopStatement inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#SLS#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| printer inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#printer#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| Scanner inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Scanner#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| {$<Str>$=strdup("#Epsilon@");}
  
ifStatement : IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ifContinuer {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#IF@#(@#ES#");strcat(temp,$3);strcat(temp,"@@#)@#{@#Satements#");strcat(temp,$6);strcat(temp,"@@#}@#");strcat(temp,$8);strcat(temp,"@");$<Str>$=strdup(temp);}
			| IF OPBRAC expressionStatement CLBRAC singleStatement ifContinuer {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#IF@#(@#ES#");strcat(temp,$3);strcat(temp,"@@#)@#SingleS#");strcat(temp,$5);strcat(temp,"@@#");strcat(temp,$6);strcat(temp,"@");$<Str>$=strdup(temp);}

ifContinuer : ES {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#ES#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
			| ifStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#IfS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
  
ES : ELSE IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ES {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#elseif@#(@#ES#");strcat(temp,$4);strcat(temp,"@@#)@#{@#STMTS#");strcat(temp,$7);strcat(temp,"@@#}@#ES#");strcat(temp,$9);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| ELSE OPCUR statements CLCUR {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#else@#{@#STMTS#");strcat(temp,$3);strcat(temp,"@@#}@");$<Str>$=strdup(temp);}
	| ELSE IF OPBRAC expressionStatement CLBRAC singleStatement ES {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#elseif@#(@#ES#");strcat(temp,$4);strcat(temp,"@@#)@#SS#");strcat(temp,$6);strcat(temp,"@@#ElS#");strcat(temp,$7);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| ELSE singleStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#else@#SS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}	| {$<Str>$=strdup("#Epsilon@");}
 
ifInLoopStatement : IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ifInLoopContinuer {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#if@#(@#ES#");strcat(temp,$3);strcat(temp,"@@#)@#{@#IL#");strcat(temp,$6);strcat(temp,"@@#}@#IILC#");strcat(temp,$8);strcat(temp,"@@");$<Str>$=strdup(temp);}	ifInLoopContinuer : ESLoop {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#ESL#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}					| ifInLoopStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#IILS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 
ESLoop : ELSE IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ESLoop {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#elseif@#(@#ES#");strcat(temp,$4);strcat(temp,"@@#)@#IL#");strcat(temp,$6); strcat(temp,"@@#ESL#");strcat(temp,$7);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| ELSE OPCUR inLoop CLCUR {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#else@#{@#IL#");strcat(temp,$3);strcat(temp,"@@#}@");$<Str>$=strdup(temp);}
	|ELSE IF OPBRAC expressionStatement CLBRAC singleLoopStatement ESLoop {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#elseif@#(@#ES#");strcat(temp,$4);strcat(temp,"@@#)@#SLS#");strcat(temp,$6); strcat(temp,"@@#ESL#");strcat(temp,$7);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| ELSE singleLoopStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#else@#SLS#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}	| {$<Str>$=strdup("#Epsilon@");}
 
switchStatement : SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR {char* temp; temp=(char *)malloc(sizeof(char)*100); strcat(temp,"#switch@#(@#Identifier#");strcat(temp,$3);strcat(temp,"@@#(@#{@#CS#");strcat(temp,$6);strcat(temp,"@@#DS#");strcat(temp,$7);strcat(temp,"@@#}@");$<Str>$=strdup(temp);}

caseStatements : caseStatementInt {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#CSI#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
				| {$<Str>$=strdup("#Epsilon@");}

caseStatementInt : caseInt caseStatementInt {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#CI#");strcat(temp,$1);strcat(temp,"@@#CSI#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| {$<Str>$=strdup("#Epsilon@");}

caseInt : CASE OPBRAC INTVAL CLBRAC COLON caseContinuer {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#case@#(@#");strcat(temp,$2);strcat(temp,"@#)@#:@#CC#");strcat(temp,$4);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| CASE INTVAL COLON caseContinuer {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#case@#");strcat(temp,$2);strcat(temp,"@#:@#CC#");strcat(temp,$4);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| CASE OPBRAC CHARVAL CLBRAC COLON caseContinuer {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#case@#(@#");strcat(temp,$2);strcat(temp,"@#)@#:@#CC#");strcat(temp,$4);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| CASE CHARVAL COLON caseContinuer {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#case@#");strcat(temp,$2);strcat(temp,"@#:@#CC#");strcat(temp,$4);strcat(temp,"@@");$<Str>$=strdup(temp);}

caseContinuer :  statements BREAK SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#STMTS#");strcat(temp,$1);strcat(temp,"@@#break@#;@");$<Str>$=strdup(temp);}
				| statements {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#STMTS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}

defaultStatement : DEFAULT COLON statements {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#default@#:@#STMTS#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);} 
 					| {$<Str>$=strdup("#Epsilon@");}
  
 /* basic statements */
basicStatements : basicStatement basicStatements {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@#BSs#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| basicStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 
basicStatement : expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#ES#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| declarationStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#DS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| assignmentStatement	{char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#AS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}		| functionCall {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#FC#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
assignmentStatement : IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");strcat(temp,"#=@#ES#");strcat(temp,$3);strcat(temp,"@@#,@#AS#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER EQUAL expressionStatement SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");strcat(temp,"#=@#ES#");strcat(temp,$4);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}		| IDENTIFIER dimension EQUAL expressionStatement COMMA assignmentStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#Dim#");strcat(temp,$2);strcat(temp,"@@#=@#ES#");strcat(temp,$4);strcat(temp,"@@#,@#AS#");strcat(temp,$6);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER dimension EQUAL expressionStatement SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#Dim#");strcat(temp,$2);strcat(temp,"@@#=@#ES#");strcat(temp,$4);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}
 
printer : PRINTF OPBRAC STRING prattributes CLBRAC SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#printf@#(@#String#");strcat(temp,$3);strcat(temp,"@@#PrA#");strcat(temp,$4);strcat(temp,"@@#)@#;@");$<Str>$=strdup(temp);}
Scanner : SCANF OPBRAC STRING scattributes CLBRAC SEMICOLON{char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#scanf@#(@#String#");strcat(temp,$3);strcat(temp,"@@#SCA#");strcat(temp,$4);strcat(temp,"@@#)@#;@");$<Str>$=strdup(temp);}

declarationStatement : INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#int@#Identifier#");strcat(temp,$2);strcat(temp,"@@#(@#PS#");strcat(temp,$4);strcat(temp,"@@#)@#CS#");strcat(temp,$6);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| CHAR IDENTIFIER OPBRAC   parameters CLBRAC compoundStatements {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#char@#Identifier#");strcat(temp,$2);strcat(temp,"@@#(@#PS#");strcat(temp,$4);strcat(temp,"@@#)@#CS#");strcat(temp,$6);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| FLOAT IDENTIFIER OPBRAC  parameters CLBRAC compoundStatements {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#float@#Identifier#");strcat(temp,$2);strcat(temp,"@@#(@#PS#");strcat(temp,$4);strcat(temp,"@@#)@#CS#");strcat(temp,$6);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| INT IDENTIFIER OPBRAC CLBRAC compoundStatements {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#int@#Identifier#");strcat(temp,$2);strcat(temp,"@@#(@#)@#CS#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| FLOAT IDENTIFIER OPBRAC CLBRAC compoundStatements {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#float@#Identifier#");strcat(temp,$2);strcat(temp,"@@#(@#)@#CS#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| CHAR IDENTIFIER OPBRAC CLBRAC compoundStatements {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#char@#Identifier#");strcat(temp,$2);strcat(temp,"@@#(@#)@#CS#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| INT declarationListInt SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#int@#DLI#");strcat(temp,$2);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}
		| CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#char@#Identifier#");strcat(temp,$2);strcat(temp,"@@#[@#");strcat(temp,$4);strcat(temp,"@#]@#=@#STRING#");strcat(temp,$7);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}
		| CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#char@#Identifier#");strcat(temp,$2);strcat(temp,"@@#[@#]@#=@#String#");strcat(temp,$6);strcat(temp,"@@#;@");$<Str>$=strdup(temp);} 
		| CHAR declarationListChar SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#char@#DLC#");strcat(temp,$2);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}
		| FLOAT declarationListFloat SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#float@#DLF#");strcat(temp,$2);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}
		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#int@#Identifier#");strcat(temp,$2);strcat(temp,"@@#[@#]@#=@#{@#AV#");strcat(temp,$7);strcat(temp,"@@#}@#;@");$<Str>$=strdup(temp);} 
		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#int@#Identifier#");strcat(temp,$2);strcat(temp,"@@#[@#]@#=@#{@#}@#;@");$<Str>$=strdup(temp);} 		| FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValuesF CLCUR SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#float@#Identifier#");strcat(temp,$2);strcat(temp,"@@#[@#]@#=@#{@#AVF#");strcat(temp,$7);strcat(temp,"@@#}@#;@");$<Str>$=strdup(temp);} 
		| FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#float@#Identifier#");strcat(temp,$2);strcat(temp,"@@#[@#]@#=@#{@#}@#;@");$<Str>$=strdup(temp);} 
		// IF FLOAT ALLOW ONLY FLOAT IN EXP, same for char and INT 

arrayValuesF :  FLOATVAL COMMA arrayValuesF {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@#,@#AVF#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
			| FLOATVAL {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@");$<Str>$=strdup(temp);}

arrayValues :  INTVAL COMMA arrayValues {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@#,@#AV#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
			| INTVAL {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@");$<Str>$=strdup(temp);}

prattributes : prattributes COMMA factor {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#PrA#");strcat(temp,$1);strcat(temp,"@@#,@#factor#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
			| {$<Str>$=strdup("#Epsilon@");}

scattributes : COMMA AMPERSAND IDENTIFIER scattributes {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#,@#&@#Identifier#");strcat(temp,$3);strcat(temp,"@@#,@#SCA#");strcat(temp,$4);strcat(temp,"@@");$<Str>$=strdup(temp);}
			| {$<Str>$=strdup("#Epsilon@");}
		
declarationListInt : IDENTIFIER EQUAL expressionStatement COMMA declarationListInt {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#=@#ES#");strcat(temp,$3);strcat(temp,"@@#,@#DLI#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER COMMA declarationListInt {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#,@#DLI#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER EQUAL expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#=@#ES#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER dimension  {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#Dim#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
declarationListFloat : IDENTIFIER EQUAL expressionStatement COMMA declarationListFloat {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#=@#ES#");strcat(temp,$3);strcat(temp,"@@#,@#DLF#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER COMMA declarationListFloat {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#,@#DLF#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER EQUAL expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#=@#ES#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER dimension  {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#Dim#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}

declarationListChar : IDENTIFIER EQUAL CHARVAL COMMA declarationListChar  {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#=@#");strcat(temp,$3);strcat(temp,"@#,@#DLC#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER COMMA declarationListChar {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#,@#DLC#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER EQUAL expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#=@#ES#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER dimension {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#Dim#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
expressionStatement : logicalExpression LOGICALOR expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#LE#");strcat(temp,$1);strcat(temp,"@@#||@#ES#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| logicalExpression {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#LE#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
logicalExpression : expression LOGICALAND logicalExpression {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Exp#");strcat(temp,$1);strcat(temp,"@@#&&@#LE#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| expression {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Exp#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
expression : relationalExpression EQUALS expression {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#RE#");strcat(temp,$1);strcat(temp,"@@#==@#Exp#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| relationalExpression NOTEQUAL expression {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#RE#");strcat(temp,$1);strcat(temp,"@@#!=@#Exp#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| relationalExpression {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#RE#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
relationalExpression : value GREATERTHAN relationalExpression {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#value#");strcat(temp,$1);strcat(temp,"@@#>@#RE#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| value GREATERTHANEQUALTO relationalExpression {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#value#");strcat(temp,$1);strcat(temp,"@@#>=@#RE#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| value LESSTHAN relationalExpression {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#value#");strcat(temp,$1);strcat(temp,"@@#<@#RE#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| value LESSTHANEQUALTO relationalExpression {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#value#");strcat(temp,$1);strcat(temp,"@@#<=@#RE#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| value {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#value#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
value : term ADD value {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#term#");strcat(temp,$1);strcat(temp,"@@#+@#value#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| term SUB value {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#term#");strcat(temp,$1);strcat(temp,"@@#-@#value#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| term {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#term#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
	
term : factor MULT term {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#factor#");strcat(temp,$1);strcat(temp,"@@#*@#term#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| factor DIV term {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#factor#");strcat(temp,$1);strcat(temp,"@@#/@#term#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| factor MOD term {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#factor#");strcat(temp,$1);strcat(temp,"@@#%@#term#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| factor {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#factor#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
	
factor : IDENTIFIER {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| OPBRAC expressionStatement CLBRAC {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#(@#ES#");strcat(temp,$2);strcat(temp,"@@#)@");$<Str>$=strdup(temp);}
	| LOGICALNOT expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#!@#ES#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| CHARVAL {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@");$<Str>$=strdup(temp);}
	| INTVAL {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@");$<Str>$=strdup(temp);}
	| FLOATVAL {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@");$<Str>$=strdup(temp);}	| IDENTIFIER OPBRAC CLBRAC {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#(@#)@");$<Str>$=strdup(temp);}	| IDENTIFIER OPBRAC argList CLBRAC {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#(@#AL#");strcat(temp,$3);strcat(temp,"@@#)@");$<Str>$=strdup(temp);}
	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");strcat(temp,"#[@#");strcat(temp,$3);strcat(temp,"@#]@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");strcat(temp,"#[@#");strcat(temp,$3);strcat(temp,"@#]@#[@");strcat(temp,$6);strcat(temp,"@#]@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
 
 
functionCall : IDENTIFIER OPBRAC CLBRAC SEMICOLON {{char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#(@#;@");$<Str>$=strdup(temp);}}
             | IDENTIFIER OPBRAC argList CLBRAC SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#(@#AL#");strcat(temp,$3);strcat(temp,"@@#)@#;@");$<Str>$=strdup(temp);}
 
/* changes to be made - either expressionStatement or expression */
argList : expressionStatement COMMA argList {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#ES#");strcat(temp,$1);strcat(temp,"@@#,@#AL#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#ES#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 
parameters : paramContinuer {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#PC#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
paramContinuer : parameter {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#P#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}				
				| parameter COMMA paramContinuer  {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#P#");strcat(temp,$1);strcat(temp,"@@#,@#PC#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
 
parameter : type IDENTIFIER {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#type#");strcat(temp,$1);strcat(temp,"@@#Identifier#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 
type : INT {$<Str>$=strdup("#int@");} 
		| FLOAT {$<Str>$=strdup("#float@");}		
		| CHAR  {$<Str>$=strdup("#char@");}
 
compoundStatements : OPCUR statementList CLCUR {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#{@#SL#");strcat(temp,$2);strcat(temp,"@@#}@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
 
statementList : functionCall statementList {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#FC#");strcat(temp,$1);strcat(temp,"@@#SL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
				| basicStatements statementList {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@#SL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
 				| specialStatement statementList {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#SS#");strcat(temp,$1);strcat(temp,"@@#SL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
				| returnDec {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#RD#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
				| printer statementList {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#printer#");strcat(temp,$1);strcat(temp,"@@#SL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
				| Scanner statementList {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#Scanner#");strcat(temp,$1);strcat(temp,"@@#SL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
				| {$<Str>$=strdup("#Epsilon@");fprintf(outFile,"%s\n",$<Str>$);}
 
returnDec : RETURN expressionStatement SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#return@#ES#");strcat(temp,$1);strcat(temp,"@@#;@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);} 
			| RETURN SEMICOLON {$<Str>$=strdup("#return@#;@");}

dimension : BOXOPEN INTVAL BOXCLOSE {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#[@#");strcat(temp,$2);strcat(temp,"@#]@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
		  | BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#[@#");strcat(temp,$2);strcat(temp,"@#]@#[@");strcat(temp,$5);strcat(temp,"@#]@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
		  | BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE {char* temp; temp=(char *)malloc(sizeof(char)*100);strcat(temp,"#[@#]@#[@#");strcat(temp,$4);strcat(temp,"@#]@");$<Str>$=strdup(temp);fprintf(outFile,"%s\n",$<Str>$);}
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
     
     
