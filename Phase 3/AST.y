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
code : declarationList {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#code#DL#");strcat(temp,$1);strcat(temp,"@@@");$<Str>$=strdup(temp);fprintf(outFile,"%s",$<Str>$);}
  
declarationList :  declarationStatement declarationList {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#DS#");strcat(temp,$1);strcat(temp,"@@#DL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 				|  assignmentStatement declarationList {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#AS#");strcat(temp,$1);strcat(temp,"@@#DL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 				|  declarationStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#DS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 				|  assignmentStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#AS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
  
statements : specialStatement statements {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,$1);strcat(temp,"@@#Satements#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		   | basicStatement statements {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@#Satements#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		   | functionCall statements {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,$1);strcat(temp,"@@#Satements#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		   | {$<Str>$=strdup("#Epsilon@");}
singleStatement : specialStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		   | basicStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		   | functionCall {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
  
specialStatement : FOR forLoop {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#for@#");strcat(temp,"FL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 				 | ifStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IFS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 				 | whileLoop {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#WL#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 				 | switchStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SWS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}

forLoop : forLoop2 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FLMany#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| forLoop3 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FL1#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| forLoop1 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FL#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
 /* for loop */
forLoop1 :  OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement  CLBRAC SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#");strcat(temp,"ForA#");strcat(temp,$2);strcat(temp,"@@#ForE#");strcat(temp,$3);strcat(temp,"@@#;@#ForU#");strcat(temp,$5);strcat(temp,"@@#)@#;@");$<Str>$=strdup(temp);}
forLoop2 : OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR inLoop CLCUR {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#");strcat(temp,"ForA#");strcat(temp,$2);strcat(temp,"@@#ForE#");strcat(temp,$3);strcat(temp,"@@#;@#ForU#");strcat(temp,$5);strcat(temp,"@@#)@#{@");strcat(temp,"#InL#");strcat(temp,$8);strcat(temp,"@@#}@");$<Str>$=strdup(temp);}
forLoop3 : OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC singleLoopStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#");strcat(temp,"ForA#");strcat(temp,$2);strcat(temp,"@@#ForE#");strcat(temp,$3);strcat(temp,"@@#;@#ForU#");strcat(temp,$5);strcat(temp,"@@#)@#");strcat(temp,"SL#");strcat(temp,$7);strcat(temp,"@@");$<Str>$=strdup(temp);}
  
singleLoopStatement : specialStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| basicStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| functionCall {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| BREAK SEMICOLON {$<Str>$=strdup("#break@#;@");}
					| CONTINUE SEMICOLON {$<Str>$=strdup("#continue@#;@");}
					| switchStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SWS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| ifInLoopStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfLoop#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| returnDec {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfLoop#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 
forAssignStatement : assignmentStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FA#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| INT IDENTIFIER EQUAL expressionStatement SEMICOLON {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#");strcat(temp,$2);strcat(temp,"@#=@#ES#");strcat(temp,$4);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}
					| INT IDENTIFIER EQUAL expressionStatement COMMA forAssignStatement {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#");strcat(temp,$2);strcat(temp,"@#=@#ES#");strcat(temp,$4);strcat(temp,"@@#,@#FA#");strcat(temp,$6);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| CHAR IDENTIFIER EQUAL expressionStatement COMMA forAssignStatement {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#");strcat(temp,$2);strcat(temp,"@#=@#ES#");strcat(temp,$4);strcat(temp,"@@#,@#FA#");strcat(temp,$6);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| SEMICOLON
					| CHAR IDENTIFIER EQUAL expressionStatement COMMA forAssignStatement

forExpStatement : expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
				| {$<Str>$=strdup("#Epsilon@");}

forUpdateStatement : IDENTIFIER EQUAL expressionStatement COMMA forUpdateStatement {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#identifier#");strcat(temp,$1);strcat(temp,"@@#=@#ES#");strcat(temp,$3);strcat(temp,"@@#,@#ForU#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| IDENTIFIER EQUAL expressionStatement 
 /* while loop */
whileLoop : WHILE OPBRAC expressionStatement CLBRAC whileSuffix {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#while@#(@#ES#");strcat(temp,$3);strcat(temp,"@@#)@#WSuffix#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}

whileSuffix : OPCUR inLoop CLCUR {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#{@#InL#");strcat(temp,$2);strcat(temp,"@@#}@");$<Str>$=strdup(temp);}
 		  | SEMICOLON {$<Str>$=strdup(";");}
 		  | singleLoopStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SLS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
  
inLoop : BREAK SEMICOLON inLoop {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#break@#;@#InL#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| CONTINUE SEMICOLON inLoop {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#continue@#;@#InL#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| specialStatement inLoop {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| basicStatement inLoop {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
  		| functionCall inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| ifInLoopStatement inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfInL#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| switchStatement inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| singleLoopStatement inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SLS#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| printer inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#printer#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| Scanner inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Scanner#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| returnDec inLoop  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Scanner#");strcat(temp,$1);strcat(temp,"@@#InL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| {$<Str>$=strdup("#Epsilon@");}
  
ifStatement : IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ifContinuer {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IF@#(@#ES#");strcat(temp,$3);strcat(temp,"@@#)@#{@#Satements#");strcat(temp,$6);strcat(temp,"@@#}@#");strcat(temp,$8);strcat(temp,"@");$<Str>$=strdup(temp);}
			| IF OPBRAC expressionStatement CLBRAC singleStatement ifContinuer {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IF@#(@#ES#");strcat(temp,$3);strcat(temp,"@@#)@#SingleS#");strcat(temp,$5);strcat(temp,"@@#");strcat(temp,$6);strcat(temp,"@");$<Str>$=strdup(temp);}

ifContinuer : ES {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
			| ifStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
  
ES : ELSE IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ES {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,$4);strcat(temp,"@@#)@#{@#STMTS#");strcat(temp,$7);strcat(temp,"@@#}@#ES#");strcat(temp,$9);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| ELSE OPCUR statements CLCUR {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#{@#STMTS#");strcat(temp,$3);strcat(temp,"@@#}@");$<Str>$=strdup(temp);}
	| ELSE IF OPBRAC expressionStatement CLBRAC singleStatement ES {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,$4);strcat(temp,"@@#)@#SS#");strcat(temp,$6);strcat(temp,"@@#ElS#");strcat(temp,$7);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| ELSE singleStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#SS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}	| {$<Str>$=strdup("#Epsilon@");}
 
ifInLoopStatement : IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ifInLoopContinuer {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#if@#(@#ES#");strcat(temp,$3);strcat(temp,"@@#)@#{@#IL#");strcat(temp,$6);strcat(temp,"@@#}@#IILC#");strcat(temp,$8);strcat(temp,"@@");$<Str>$=strdup(temp);}	ifInLoopContinuer : ESLoop {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ESL#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}					| ifInLoopStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IILS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 
ESLoop : ELSE IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ESLoop {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,$4);strcat(temp,"@@#)@#IL#");strcat(temp,$6); strcat(temp,"@@#ESL#");strcat(temp,$7);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| ELSE OPCUR inLoop CLCUR {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#{@#IL#");strcat(temp,$3);strcat(temp,"@@#}@");$<Str>$=strdup(temp);}
	|ELSE IF OPBRAC expressionStatement CLBRAC singleLoopStatement ESLoop {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,$4);strcat(temp,"@@#)@#SLS#");strcat(temp,$6); strcat(temp,"@@#ESL#");strcat(temp,$7);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| ELSE singleLoopStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#SLS#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}	| {$<Str>$=strdup("#Epsilon@");}
 
switchStatement : SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR {char* temp; temp=(char *)malloc(sizeof(char)*10000); strcat(temp,"#switch@#(@#Identifier#");strcat(temp,$3);strcat(temp,"@@#(@#{@#CS#");strcat(temp,$6);strcat(temp,"@@#DS#");strcat(temp,$7);strcat(temp,"@@#}@");$<Str>$=strdup(temp);}

caseStatements : caseStatementInt {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#CSI#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
				| {$<Str>$=strdup("#Epsilon@");}

caseStatementInt : caseInt caseStatementInt {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#CI#");strcat(temp,$1);strcat(temp,"@@#CSI#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
					| {$<Str>$=strdup("#Epsilon@");}

caseInt : CASE OPBRAC INTVAL CLBRAC COLON caseContinuer {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#(@#");strcat(temp,$2);strcat(temp,"@#)@#:@#CC#");strcat(temp,$4);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| CASE INTVAL COLON caseContinuer {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#");strcat(temp,$2);strcat(temp,"@#:@#CC#");strcat(temp,$4);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| CASE OPBRAC CHARVAL CLBRAC COLON caseContinuer {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#(@#");strcat(temp,$2);strcat(temp,"@#)@#:@#CC#");strcat(temp,$4);strcat(temp,"@@");$<Str>$=strdup(temp);}
 		| CASE CHARVAL COLON caseContinuer {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#");strcat(temp,$2);strcat(temp,"@#:@#CC#");strcat(temp,$4);strcat(temp,"@@");$<Str>$=strdup(temp);}

caseContinuer :  statements BREAK SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#STMTS#");strcat(temp,$1);strcat(temp,"@@#break@#;@");$<Str>$=strdup(temp);}
				| statements {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#STMTS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}

defaultStatement : DEFAULT COLON statements {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#default@#:@#STMTS#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);} 
 					| {$<Str>$=strdup("#Epsilon@");}
  
 /* basic statements */
basicStatements : basicStatement basicStatements {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@#BSs#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| basicStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| returnDec {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 
basicStatement : expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| declarationStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#DS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| assignmentStatement	{char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#AS#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}		| functionCall {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
assignmentStatement : IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");strcat(temp,"#=@#ES#");strcat(temp,$3);strcat(temp,"@@#,@#AS#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER EQUAL expressionStatement SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");strcat(temp,"#=@#ES#");strcat(temp,$4);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}		| IDENTIFIER dimension EQUAL expressionStatement COMMA assignmentStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#Dim#");strcat(temp,$2);strcat(temp,"@@#=@#ES#");strcat(temp,$4);strcat(temp,"@@#,@#AS#");strcat(temp,$6);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER dimension EQUAL expressionStatement SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#Dim#");strcat(temp,$2);strcat(temp,"@@#=@#ES#");strcat(temp,$4);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}
 
printer : PRINTF OPBRAC STRING prattributes CLBRAC SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#printf@#(@#String#\\");strcat(temp,$3);strcat(temp,"\\\"@@#PrA#");strcat(temp,$4);strcat(temp,"@@#)@#;@");$<Str>$=strdup(temp);}
Scanner : SCANF OPBRAC STRING scattributes CLBRAC SEMICOLON{char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#scanf@#(@#String#");strcat(temp,$3);strcat(temp,"@@#SCA#");strcat(temp,$4);strcat(temp,"@@#)@#;@");$<Str>$=strdup(temp);}

declarationStatement : INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,$2);strcat(temp,"@@#(@#PS#");strcat(temp,$4);strcat(temp,"@@#)@#CS#");strcat(temp,$6);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| CHAR IDENTIFIER OPBRAC   parameters CLBRAC compoundStatements {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,$2);strcat(temp,"@@#(@#PS#");strcat(temp,$4);strcat(temp,"@@#)@#CS#");strcat(temp,$6);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| FLOAT IDENTIFIER OPBRAC  parameters CLBRAC compoundStatements {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,$2);strcat(temp,"@@#(@#PS#");strcat(temp,$4);strcat(temp,"@@#)@#CS#");strcat(temp,$6);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| INT IDENTIFIER OPBRAC CLBRAC compoundStatements {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,$2);strcat(temp,"@@#(@#)@#CS#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| FLOAT IDENTIFIER OPBRAC CLBRAC compoundStatements {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,$2);strcat(temp,"@@#(@#)@#CS#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| CHAR IDENTIFIER OPBRAC CLBRAC compoundStatements {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,$2);strcat(temp,"@@#(@#)@#CS#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| INT declarationListInt SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#DLI#");strcat(temp,$2);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}
		| CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,$2);strcat(temp,"@@#[@#");strcat(temp,$4);strcat(temp,"@#]@#=@#STRING#\\");strcat(temp,$7);strcat(temp,"\\\"@@#;@");$<Str>$=strdup(temp);}
		| CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,$2);strcat(temp,"@@#[@#]@#=@#STRING#\\");strcat(temp,$6);strcat(temp,"\\\"@@#;@");$<Str>$=strdup(temp);} 
		| CHAR declarationListChar SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#DLC#");strcat(temp,$2);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}
		| FLOAT declarationListFloat SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#DLF#");strcat(temp,$2);strcat(temp,"@@#;@");$<Str>$=strdup(temp);}
		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,$2);strcat(temp,"@@#[@#]@#=@#{@#AV#");strcat(temp,$7);strcat(temp,"@@#}@#;@");$<Str>$=strdup(temp);} 
		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,$2);strcat(temp,"@@#[@#]@#=@#{@#}@#;@");$<Str>$=strdup(temp);} 		| FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValuesF CLCUR SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,$2);strcat(temp,"@@#[@#]@#=@#{@#AVF#");strcat(temp,$7);strcat(temp,"@@#}@#;@");$<Str>$=strdup(temp);} 
		| FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,$2);strcat(temp,"@@#[@#]@#=@#{@#}@#;@");$<Str>$=strdup(temp);} 
		// IF FLOAT ALLOW ONLY FLOAT IN EXP, same for char and INT 

arrayValuesF :  FLOATVAL COMMA arrayValuesF {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@#,@#AVF#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
			| FLOATVAL {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@");$<Str>$=strdup(temp);}

arrayValues :  INTVAL COMMA arrayValues {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@#,@#AV#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
			| INTVAL {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@");$<Str>$=strdup(temp);}

prattributes : prattributes COMMA factor {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#PrA#");strcat(temp,$1);strcat(temp,"@@#,@#factor#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
			| {$<Str>$=strdup("#Epsilon@");}

scattributes : COMMA AMPERSAND IDENTIFIER scattributes {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#,@#&@#Identifier#");strcat(temp,$3);strcat(temp,"@@#,@#SCA#");strcat(temp,$4);strcat(temp,"@@");$<Str>$=strdup(temp);}
			| {$<Str>$=strdup("#Epsilon@");}
		
declarationListInt : IDENTIFIER EQUAL expressionStatement COMMA declarationListInt {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#=@#ES#");strcat(temp,$3);strcat(temp,"@@#,@#DLI#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER COMMA declarationListInt {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#,@#DLI#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER EQUAL expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#=@#ES#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER dimension  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#Dim#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
declarationListFloat : IDENTIFIER EQUAL expressionStatement COMMA declarationListFloat {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#=@#ES#");strcat(temp,$3);strcat(temp,"@@#,@#DLF#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER COMMA declarationListFloat {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#,@#DLF#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER EQUAL expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#=@#ES#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER dimension  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#Dim#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}

declarationListChar : IDENTIFIER EQUAL CHARVAL COMMA declarationListChar  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#=@#");strcat(temp,$3);strcat(temp,"@#,@#DLC#");strcat(temp,$5);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER COMMA declarationListChar {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#,@#DLC#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER EQUAL expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#=@#ES#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER dimension {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#Dim#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| IDENTIFIER {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
expressionStatement : logicalExpression LOGICALOR expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#LE#");strcat(temp,$1);strcat(temp,"@@#||@#ES#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| logicalExpression {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#LE#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
logicalExpression : expression LOGICALAND logicalExpression {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Exp#");strcat(temp,$1);strcat(temp,"@@#&&@#LE#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| expression {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Exp#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
expression : relationalExpression EQUALS expression {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RE#");strcat(temp,$1);strcat(temp,"@@#==@#Exp#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| relationalExpression NOTEQUAL expression {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RE#");strcat(temp,$1);strcat(temp,"@@#!=@#Exp#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| relationalExpression {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RE#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
relationalExpression : value GREATERTHAN relationalExpression {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,$1);strcat(temp,"@@#>@#RE#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| value GREATERTHANEQUALTO relationalExpression {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,$1);strcat(temp,"@@#>=@#RE#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| value LESSTHAN relationalExpression {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,$1);strcat(temp,"@@#<@#RE#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| value LESSTHANEQUALTO relationalExpression {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,$1);strcat(temp,"@@#<=@#RE#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| value {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
		
value : term ADD value {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#term#");strcat(temp,$1);strcat(temp,"@@#+@#value#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| term SUB value {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#term#");strcat(temp,$1);strcat(temp,"@@#-@#value#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| term {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#term#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
	
term : factor MULT term {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,$1);strcat(temp,"@@#*@#term#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| factor DIV term {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,$1);strcat(temp,"@@#/@#term#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| factor MOD term {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,$1);strcat(temp,"@@#%@#term#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| factor {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
	
factor : IDENTIFIER {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| OPBRAC expressionStatement CLBRAC {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#ES#");strcat(temp,$2);strcat(temp,"@@#)@");$<Str>$=strdup(temp);}
	| LOGICALNOT expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#!@#ES#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
	| CHARVAL {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@");$<Str>$=strdup(temp);}
	| INTVAL {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@");$<Str>$=strdup(temp);}
	| FLOATVAL {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,$1);strcat(temp,"@");$<Str>$=strdup(temp);}	| IDENTIFIER OPBRAC CLBRAC {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#(@#)@");$<Str>$=strdup(temp);}	| IDENTIFIER OPBRAC argList CLBRAC {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#(@#AL#");strcat(temp,$3);strcat(temp,"@@#)@");$<Str>$=strdup(temp);}
	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");strcat(temp,"#[@#");strcat(temp,$3);strcat(temp,"@#]@");$<Str>$=strdup(temp);}
	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@");strcat(temp,"#[@#");strcat(temp,$3);strcat(temp,"@#]@#[@#");strcat(temp,$6);strcat(temp,"@#]@");$<Str>$=strdup(temp);}
 
 
functionCall : IDENTIFIER OPBRAC CLBRAC SEMICOLON {{char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#(@#;@");$<Str>$=strdup(temp);}}
             | IDENTIFIER OPBRAC argList CLBRAC SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,$1);strcat(temp,"@@#(@#AL#");strcat(temp,$3);strcat(temp,"@@#)@#;@");$<Str>$=strdup(temp);}
 
/* changes to be made - either expressionStatement or expression */
argList : expressionStatement COMMA argList {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,$1);strcat(temp,"@@#,@#AL#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
		| expressionStatement {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
 
parameters : paramContinuer {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#PC#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
paramContinuer : parameter {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#P#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}				
				| parameter COMMA paramContinuer  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#P#");strcat(temp,$1);strcat(temp,"@@#,@#PC#");strcat(temp,$3);strcat(temp,"@@");$<Str>$=strdup(temp);}
 
parameter : type IDENTIFIER {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#type#");strcat(temp,$1);strcat(temp,"@@#Identifier#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 
type : INT {$<Str>$=strdup("#int@");} 
		| FLOAT {$<Str>$=strdup("#float@");}		
		| CHAR  {$<Str>$=strdup("#char@");}
 
compoundStatements : OPCUR statementList CLCUR {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#{@#SL#");strcat(temp,$2);strcat(temp,"@@#}@");$<Str>$=strdup(temp);}
 
statementList : functionCall statementList {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,$1);strcat(temp,"@@#SL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
				| basicStatements statementList {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,$1);strcat(temp,"@@#SL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
 				| specialStatement statementList {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,$1);strcat(temp,"@@#SL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
				| returnDec {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RD#");strcat(temp,$1);strcat(temp,"@@");$<Str>$=strdup(temp);}
				| printer statementList {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#printer#");strcat(temp,$1);strcat(temp,"@@#SL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
				| Scanner statementList {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Scanner#");strcat(temp,$1);strcat(temp,"@@#SL#");strcat(temp,$2);strcat(temp,"@@");$<Str>$=strdup(temp);}
				| {$<Str>$=strdup("#Epsilon@");}
 
returnDec : RETURN expressionStatement SEMICOLON {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#return@#ES#");strcat(temp,$1);strcat(temp,"@@#;@");$<Str>$=strdup(temp);} 
			| RETURN SEMICOLON {$<Str>$=strdup("#return@#;@");}

dimension : BOXOPEN INTVAL BOXCLOSE {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#[@#");strcat(temp,$2);strcat(temp,"@#]@");$<Str>$=strdup(temp);}
		  | BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#[@#");strcat(temp,$2);strcat(temp,"@#]@#[@#");strcat(temp,$5);strcat(temp,"@#]@");$<Str>$=strdup(temp);}
		  | BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#[@#]@#[@#");strcat(temp,$4);strcat(temp,"@#]@");$<Str>$=strdup(temp);}
%%
 
#include "lex.yy.c"
int main(){
	yyin = fopen("./Test Cases/input.txt","r");	
	if(!yyparse())
	{
		printf("\n\nParsed Successfully\n\n");		
		// printTable();
	}
	else 
		printf("\n\nParsing Failed\n\n");			
	exit(0);
}