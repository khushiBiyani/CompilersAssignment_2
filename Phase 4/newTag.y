%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>
  int top=-1;
  void yyerror(char *);
  extern FILE *yyin;
  #define YYSTYPE char*
  typedef struct quadruples
  {
    char *op;
    char *arg1;
    char *arg2;
    char *res;
  }quad;
  int quadlen = 0;
  quad q[100];
%}

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

%type <Str> code declarationList declarationStatementFirst statements singleStatement specialStatement forLoop forLoop1 forLoop2 forLoop3 singleLoopStatement forAssignStatement forExpStatement forUpdateStatement whileLoop whileSuffix inLoop ifStatement ifContinuer ES ifInLoopContinuer ifInLoopStatement ESLoop basicStatements basicStatement assignmentStatement printer declarationStatement arrayValuesF arrayValues prattributes declarationListInt declarationListFloat declarationListChar expressionStatement logicalExpression expression relationalExpression value term factor paramContinuer parameters parameter type compoundStatements statementList returnDec dimension ARRAY
 
 
  
%token <Str> IDENTIFIER

%%
code
      : declarationList {printf("Input accepted.\n");}
      ;

declarationList : declarationStatementFirst

declarationStatementFirst : INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  
		| CHAR IDENTIFIER OPBRAC   parameters CLBRAC compoundStatements
		| FLOAT IDENTIFIER OPBRAC  parameters CLBRAC compoundStatements 
		| INT IDENTIFIER OPBRAC CLBRAC compoundStatements
		| CHAR IDENTIFIER OPBRAC CLBRAC compoundStatements

parameters : paramContinuer 
paramContinuer : parameter
				| parameter COMMA paramContinuer 
 
parameter : type IDENTIFIER

type : INT 
		| FLOAT 		
		| CHAR 

compoundStatements : OPCUR statementList CLCUR 

singleStatement : specialStatement 
 		   | basicStatement 

statements : specialStatement statements 
 		   | basicStatement statements 
 		   | specialStatement
           | basicStatement

statementList :   basicStatements statementList 
 				| specialStatement statementList
				| returnDec 
				| printer statementList

basicStatements : basicStatement basicStatements 
		| basicStatement

basicStatement : expressionStatement 
		| declarationStatement 
		| assignmentStatement

assignmentStatement : IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement 
		| IDENTIFIER EQUAL expressionStatement SEMICOLON 
		| IDENTIFIER dimension EQUAL expressionStatement SEMICOLON

printer : PRINTF OPBRAC STRING prattributes CLBRAC SEMICOLON

prattributes : prattributes COMMA factor 
			| COMMA factor

declarationStatement : INT declarationListInt SEMICOLON
		| CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING SEMICOLON 
		| CHAR declarationListChar SEMICOLON 
		| FLOAT declarationListFloat SEMICOLON 
		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON 
		| INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON 
		| FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON
        | FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValuesF CLCUR SEMICOLON

arrayValuesF :  FLOATVAL COMMA arrayValuesF
			| FLOATVAL 

arrayValues :  INTVAL COMMA arrayValues 
			| INTVAL

declarationListChar : declarationListChar COMMA IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();} 
		| IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();}
		| IDENTIFIER dimension 
		| IDENTIFIER

declarationListInt : declarationListInt COMMA IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();} 
		| IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();}
		| IDENTIFIER dimension 
		| IDENTIFIER

declarationListFloat : declarationListFloat COMMA IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();} 
		| IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();}
		| IDENTIFIER dimension 
		| IDENTIFIER

dimension : BOXOPEN INTVAL BOXCLOSE 
		  | BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE 
		  | BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE

returnDec : RETURN expressionStatement SEMICOLON 
			| RETURN SEMICOLON

assignmentStatement : assignmentStatement COMMA IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();}
        | ARRAY EQUAL expressionStatement SEMICOLON
		| IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();} SEMICOLON

ARRAY : IDENTIFIER dimension 

specialStatement : FOR forLoop 
 				 | ifStatement 
 				 | whileLoop 

forLoop : forLoop2
		| forLoop3
		| forLoop1

forLoop1 :  OPBRAC forAssignStatement {for1();} forExpStatement {for2();} SEMICOLON forUpdateStatement {for3();} CLBRAC SEMICOLON {for4();}
forLoop2 : OPBRAC forAssignStatement {for1();} forExpStatement {for2();} SEMICOLON forUpdateStatement {for3();} CLBRAC OPCUR inLoop CLCUR {for4();}
forLoop3 : OPBRAC forAssignStatement {for1();} forExpStatement {for2();} SEMICOLON forUpdateStatement {for3();} CLBRAC singleLoopStatement {for4();}

forAssignStatement : assignmentStatement
					| INT IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();} SEMICOLON 
					| INT IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();} COMMA forAssignStatement
					| CHAR IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();} COMMA forAssignStatement 
					| SEMICOLON
					| CHAR IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();} COMMA forAssignStatement

singleLoopStatement : specialStatement 
					| basicStatement 
					| BREAK SEMICOLON
					| CONTINUE SEMICOLON 
					| ifInLoopStatement

forExpStatement : expressionStatement 

forUpdateStatement : IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();} COMMA forUpdateStatement 
					| IDENTIFIER {push();} EQUAL {push();} expressionStatement {codegen_assign();}

whileLoop : WHILE {while1();} OPBRAC expressionStatement CLBRAC {while2();} whileSuffix {while3();}

whileSuffix : OPCUR inLoop CLCUR 
 		  | SEMICOLON 
 		  | singleLoopStatement 
  
inLoop : BREAK SEMICOLON inLoop 
 		| CONTINUE SEMICOLON inLoop 
 		| specialStatement inLoop 
 		| basicStatement inLoop 
 		| ifInLoopStatement inLoop 
 		| singleLoopStatement inLoop  
 		| printer inLoop  
		| BREAK SEMICOLON  
 		| CONTINUE SEMICOLON  
 		| specialStatement  
 		| basicStatement  
 		| ifInLoopStatement  
 		| singleLoopStatement   
 		| printer   
  
ifStatement : IF OPBRAC expressionStatement CLBRAC {ifelse1();} OPCUR statements CLCUR {ifelse2();} ifContinuer 
			| IF OPBRAC expressionStatement CLBRAC {ifelse1();} singleStatement {ifelse2();} ifContinuer 

ifContinuer : ES 
			| ifStatement 
  
ES : ELSE IF OPBRAC expressionStatement CLBRAC {ifelse1();} OPCUR statements CLCUR {ifelse2();} ES 
	| ELSE OPCUR statements CLCUR {ifelse3();}
    | ELSE IF OPBRAC expressionStatement CLBRAC {ifelse1();} singleStatement {ifelse2();} ES
	| ELSE singleLoopStatement {ifelse3();}
    | ELSE IF OPBRAC expressionStatement CLBRAC {ifelse1();} OPCUR statements CLCUR {ifelse2();} 
    | ELSE IF OPBRAC expressionStatement CLBRAC {ifelse1();} singleStatement {ifelse2();} 
 
ifInLoopStatement : IF OPBRAC expressionStatement CLBRAC {ifelse1();} OPCUR inLoop CLCUR {ifelse2();} ifInLoopContinuer 

ifInLoopContinuer : ESLoop
				| ifInLoopStatement

ESLoop : ELSE IF OPBRAC expressionStatement CLBRAC {ifelse1();} OPCUR inLoop CLCUR {ifelse2();} ESLoop
	| ELSE OPCUR inLoop CLCUR {ifelse3();}
	| ELSE IF OPBRAC expressionStatement CLBRAC {ifelse1();} singleLoopStatement {ifelse2();} ESLoop 
	| ELSE singleLoopStatement {ifelse3();}


expressionStatement : logicalExpression LOGICALOR {codegen_assigna();} expressionStatement 
		| logicalExpression {codegen_assigna();}
		
logicalExpression : expression LOGICALAND {codegen_assigna();} logicalExpression 
		| expression {codegen_assigna();}
		
expression : relationalExpression EQUALS {push();} expression 
		| relationalExpression NOTEQUAL {push();} expression
		| relationalExpression 
		
relationalExpression : value GREATERTHAN {push();} relationalExpression {codegen();}
		| value GREATERTHANEQUALTO {push();} relationalExpression {codegen();}
		| value LESSTHAN {push();} relationalExpression {codegen();}
		| value LESSTHANEQUALTO {push();} relationalExpression {codegen();}
		| value {pushab();}
		
value : term ADD {push();} value 
	| term SUB {push();} value 
	| term 
	
term : factor MULT {push();} term {codegen();}
	| factor DIV {push();} term {codegen();}
	| factor MOD {push();} term {codegen();}
	| factor
	
factor : IDENTIFIER {push();}
	| OPBRAC expressionStatement CLBRAC 
	| LOGICALNOT expressionStatement {codegen_assigna();}
	| CHARVAL {push();}
	| INTVAL {push();}
	| FLOATVAL {push();}
	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE
	| IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE
   
%%

#include "lex.yy.c"
#include<ctype.h>
char st[100][100];

char i_[2]="0";
int temp_i=0;
char tmp_i[3];
char temp[2]="t";
int label[20];
int lnum=0;
int ltop=0;
int abcd=0;
int l_while=0;
int l_for=0;
int flag_set = 1;

int main(int argc,char *argv[])
{

  yyin = fopen("input.c","r");
  if(!yyparse())  //yyparse-> 0 if success
  {
    printf("Parsing Complete\n");
    printf("---------------------Quadruples-------------------------\n\n");
    printf("Operator \t Arg1 \t\t Arg2 \t\t Result \n");
    int i;
    for(i=0;i<quadlen;i++)
    {
        printf("%-8s \t %-8s \t %-8s \t %-6s \n",q[i].op,q[i].arg1,q[i].arg2,q[i].res);
    }
  }
  else
  {
    printf("Parsing failed\n");
  }

  fclose(yyin);
  return 0;
}

void yyerror(char *s)
{
  printf("Error :%s at %d \n",yytext,yylineno);
}

push()
{
strcpy(st[++top],yytext);
}
pusha()
{
strcpy(st[++top],"  ");
}
pushx()
{
strcpy(st[++top],"x ");
}
pushab()
{
strcpy(st[++top],"  ");
strcpy(st[++top],"  ");
strcpy(st[++top],"  ");
}
codegen()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    //printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-1]);
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    top-=2;
    strcpy(st[top],temp);

temp_i++;
}
codegen_assigna()
{
strcpy(temp,"T");
sprintf(tmp_i, "%d", temp_i);
strcat(temp,tmp_i);
//printf("%s = %s %s %s %s\n",temp,st[top-3],st[top-2],st[top-1],st[top]);
////printf("%d\n",strlen(st[top]));
if(strlen(st[top])==1)
{
	////printf("hello");
	
    char t[20];
	////printf("hello");
	strcpy(t,st[top-2]);
	strcat(t,st[top-1]);
	q[quadlen].op = (char*)malloc(sizeof(char)*strlen(t));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,t);
    strcpy(q[quadlen].arg1,st[top-3]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    
}
else
{
	q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-2]);
    strcpy(q[quadlen].arg1,st[top-3]);
    strcpy(q[quadlen].arg2,st[top-1]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
}
top-=4;

temp_i++;
strcpy(st[++top],temp);
}

codegen_umin()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    //printf("%s = -%s\n",temp,st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"-");
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    top--;
    strcpy(st[top],temp);
    temp_i++;
}
codegen_assign()
{
    //printf("%s = %s\n",st[top-3],st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    strcpy(q[quadlen].op,"=");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,st[top-3]);
    quadlen++;
    top-=2;
}

if1()
{
 lnum++;
 strcpy(temp,"T");
 sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
 //printf("%s = not %s\n",temp,st[top]);
 q[quadlen].op = (char*)malloc(sizeof(char)*4);
 q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
 q[quadlen].arg2 = NULL;
 q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
 strcpy(q[quadlen].op,"not");
 strcpy(q[quadlen].arg1,st[top]);
 strcpy(q[quadlen].res,temp);
 quadlen++;
 //printf("if %s goto L%d\n",temp,lnum);
 q[quadlen].op = (char*)malloc(sizeof(char)*3);
 q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
 q[quadlen].arg2 = NULL;
 q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
 strcpy(q[quadlen].op,"if");
 strcpy(q[quadlen].arg1,st[top-2]);
 char x[10];
 sprintf(x,"%d",lnum);
 char l[]="L";
 strcpy(q[quadlen].res,strcat(l,x));
 quadlen++;

 temp_i++;
 label[++ltop]=lnum;
}

if3()
{
    int y;
    y=label[ltop--];
    //printf("L%d: \n",y);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
}

ifelse1()
{
    lnum++;
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    //printf("%s = not %s\n",temp,st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    //printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
    temp_i++;
    label[++ltop]=lnum;
}

ifelse2()
{
    int x;
    lnum++;
    x=label[ltop--];
    //printf("goto L%d\n",lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
    //printf("L%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");

    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
    label[++ltop]=lnum;
}

ifelse3()
{
int y;
y=label[ltop--];
//printf("L%d: \n",y);
q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
lnum++;
}

ternary1()
{
 lnum++;
 strcpy(temp,"T");
 sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
 //printf("%s = not %s\n",temp,st[top]);
 q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
 //printf("if %s goto L%d\n",temp,lnum);
 q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

 temp_i++;
 label[++ltop]=lnum;
}

ternary2()
{
int x;
lnum++;
x=label[ltop--];
//printf("goto L%d\n",lnum);
q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
//printf("L%d: \n",x);
q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
    label[++ltop]=lnum;
}

ternary3()
{
int y;
y=label[ltop--];
//printf("L%d: \n",y);
q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
lnum++;
}

while1()
{

    l_while = lnum;
    //printf("L%d: \n",lnum++);
	lnum++;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
}

while2()
{
 strcpy(temp,"T");
 sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
 //printf("%s = not %s\n",temp,st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    //printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

 temp_i++;
 }

while3()
{

//printf("goto L%d \n",l_while);
q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(l_while+2));
    strcpy(q[quadlen].op,"goto");
    char x[10];
    sprintf(x,"%d",l_while);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
    //printf("L%d: \n",lnum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x1[10];
    sprintf(x1,"%d",lnum-1);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,x1));
    quadlen++;
}

for1()
{
    l_for = lnum;
    //printf("L%d: \n",lnum++);
	lnum++;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
}
for2()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    //printf("%s = not %s\n",temp,st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    //printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    temp_i++;
    label[++ltop]=lnum;
    lnum++;
    //printf("goto L%d\n",lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char x1[10];
    sprintf(x1,"%d",lnum);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,x1));
    quadlen++;
    label[++ltop]=lnum;
    //printf("L%d: \n",++lnum);
	++lnum;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x2[10];
    sprintf(x2,"%d",lnum);
    char l2[]="L";
    strcpy(q[quadlen].res,strcat(l2,x2));
    quadlen++;
 }
for3()
{
    int x;
    x=label[ltop--];
    //printf("goto L%d \n",l_for);

    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",l_for);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;


    //printf("L%d: \n",x);

    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;

}

for4()
{
    int x;
    x=label[ltop--];
    //printf("goto L%d \n",lnum);

    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;

    //printf("L%d: \n",x);

    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
}
