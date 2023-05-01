/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "SemanticAnalyzer.y"

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
     

#line 300 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LOGICALOR = 258,               /* LOGICALOR  */
    LOGICALAND = 259,              /* LOGICALAND  */
    EQUALS = 260,                  /* EQUALS  */
    NOTEQUAL = 261,                /* NOTEQUAL  */
    GREATERTHAN = 262,             /* GREATERTHAN  */
    GREATERTHANEQUALTO = 263,      /* GREATERTHANEQUALTO  */
    LESSTHAN = 264,                /* LESSTHAN  */
    LESSTHANEQUALTO = 265,         /* LESSTHANEQUALTO  */
    ADD = 266,                     /* ADD  */
    SUB = 267,                     /* SUB  */
    MULT = 268,                    /* MULT  */
    DIV = 269,                     /* DIV  */
    MOD = 270,                     /* MOD  */
    COMMA = 271,                   /* COMMA  */
    SEMICOLON = 272,               /* SEMICOLON  */
    AMPERSAND = 273,               /* AMPERSAND  */
    COLON = 274,                   /* COLON  */
    INT = 275,                     /* INT  */
    CHAR = 276,                    /* CHAR  */
    FLOAT = 277,                   /* FLOAT  */
    STRING = 278,                  /* STRING  */
    IF = 279,                      /* IF  */
    ELSE = 280,                    /* ELSE  */
    FOR = 281,                     /* FOR  */
    WHILE = 282,                   /* WHILE  */
    DEFAULT = 283,                 /* DEFAULT  */
    SWITCH = 284,                  /* SWITCH  */
    CASE = 285,                    /* CASE  */
    BREAK = 286,                   /* BREAK  */
    CONTINUE = 287,                /* CONTINUE  */
    RETURN = 288,                  /* RETURN  */
    PRINTF = 289,                  /* PRINTF  */
    SCANF = 290,                   /* SCANF  */
    OPBRAC = 291,                  /* OPBRAC  */
    CLBRAC = 292,                  /* CLBRAC  */
    OPCUR = 293,                   /* OPCUR  */
    CLCUR = 294,                   /* CLCUR  */
    BOXOPEN = 295,                 /* BOXOPEN  */
    BOXCLOSE = 296,                /* BOXCLOSE  */
    LOGICALNOT = 297,              /* LOGICALNOT  */
    EQUAL = 298,                   /* EQUAL  */
    CHARVAL = 299,                 /* CHARVAL  */
    INTVAL = 300,                  /* INTVAL  */
    FLOATVAL = 301,                /* FLOATVAL  */
    IDENTIFIER = 302               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LOGICALOR 258
#define LOGICALAND 259
#define EQUALS 260
#define NOTEQUAL 261
#define GREATERTHAN 262
#define GREATERTHANEQUALTO 263
#define LESSTHAN 264
#define LESSTHANEQUALTO 265
#define ADD 266
#define SUB 267
#define MULT 268
#define DIV 269
#define MOD 270
#define COMMA 271
#define SEMICOLON 272
#define AMPERSAND 273
#define COLON 274
#define INT 275
#define CHAR 276
#define FLOAT 277
#define STRING 278
#define IF 279
#define ELSE 280
#define FOR 281
#define WHILE 282
#define DEFAULT 283
#define SWITCH 284
#define CASE 285
#define BREAK 286
#define CONTINUE 287
#define RETURN 288
#define PRINTF 289
#define SCANF 290
#define OPBRAC 291
#define CLBRAC 292
#define OPCUR 293
#define CLCUR 294
#define BOXOPEN 295
#define BOXCLOSE 296
#define LOGICALNOT 297
#define EQUAL 298
#define CHARVAL 299
#define INTVAL 300
#define FLOATVAL 301
#define IDENTIFIER 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 229 "SemanticAnalyzer.y"

    		int Int;
    		float Float;
    		char Char;
    		char* Str;
    		struct data{
     
    		};
    	

#line 458 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LOGICALOR = 3,                  /* LOGICALOR  */
  YYSYMBOL_LOGICALAND = 4,                 /* LOGICALAND  */
  YYSYMBOL_EQUALS = 5,                     /* EQUALS  */
  YYSYMBOL_NOTEQUAL = 6,                   /* NOTEQUAL  */
  YYSYMBOL_GREATERTHAN = 7,                /* GREATERTHAN  */
  YYSYMBOL_GREATERTHANEQUALTO = 8,         /* GREATERTHANEQUALTO  */
  YYSYMBOL_LESSTHAN = 9,                   /* LESSTHAN  */
  YYSYMBOL_LESSTHANEQUALTO = 10,           /* LESSTHANEQUALTO  */
  YYSYMBOL_ADD = 11,                       /* ADD  */
  YYSYMBOL_SUB = 12,                       /* SUB  */
  YYSYMBOL_MULT = 13,                      /* MULT  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_MOD = 15,                       /* MOD  */
  YYSYMBOL_COMMA = 16,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_AMPERSAND = 18,                 /* AMPERSAND  */
  YYSYMBOL_COLON = 19,                     /* COLON  */
  YYSYMBOL_INT = 20,                       /* INT  */
  YYSYMBOL_CHAR = 21,                      /* CHAR  */
  YYSYMBOL_FLOAT = 22,                     /* FLOAT  */
  YYSYMBOL_STRING = 23,                    /* STRING  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_DEFAULT = 28,                   /* DEFAULT  */
  YYSYMBOL_SWITCH = 29,                    /* SWITCH  */
  YYSYMBOL_CASE = 30,                      /* CASE  */
  YYSYMBOL_BREAK = 31,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 32,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_PRINTF = 34,                    /* PRINTF  */
  YYSYMBOL_SCANF = 35,                     /* SCANF  */
  YYSYMBOL_OPBRAC = 36,                    /* OPBRAC  */
  YYSYMBOL_CLBRAC = 37,                    /* CLBRAC  */
  YYSYMBOL_OPCUR = 38,                     /* OPCUR  */
  YYSYMBOL_CLCUR = 39,                     /* CLCUR  */
  YYSYMBOL_BOXOPEN = 40,                   /* BOXOPEN  */
  YYSYMBOL_BOXCLOSE = 41,                  /* BOXCLOSE  */
  YYSYMBOL_LOGICALNOT = 42,                /* LOGICALNOT  */
  YYSYMBOL_EQUAL = 43,                     /* EQUAL  */
  YYSYMBOL_CHARVAL = 44,                   /* CHARVAL  */
  YYSYMBOL_INTVAL = 45,                    /* INTVAL  */
  YYSYMBOL_FLOATVAL = 46,                  /* FLOATVAL  */
  YYSYMBOL_IDENTIFIER = 47,                /* IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_code = 49,                      /* code  */
  YYSYMBOL_declarationList = 50,           /* declarationList  */
  YYSYMBOL_statements = 51,                /* statements  */
  YYSYMBOL_singleStatement = 52,           /* singleStatement  */
  YYSYMBOL_specialStatement = 53,          /* specialStatement  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_forLoop = 55,                   /* forLoop  */
  YYSYMBOL_forLoop1 = 56,                  /* forLoop1  */
  YYSYMBOL_forLoop2 = 57,                  /* forLoop2  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_forLoop3 = 59,                  /* forLoop3  */
  YYSYMBOL_60_3 = 60,                      /* $@3  */
  YYSYMBOL_singleLoopStatement = 61,       /* singleLoopStatement  */
  YYSYMBOL_forAssignStatement = 62,        /* forAssignStatement  */
  YYSYMBOL_forExpStatement = 63,           /* forExpStatement  */
  YYSYMBOL_forUpdateStatement = 64,        /* forUpdateStatement  */
  YYSYMBOL_whileLoop = 65,                 /* whileLoop  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_whileSuffix = 67,               /* whileSuffix  */
  YYSYMBOL_68_5 = 68,                      /* $@5  */
  YYSYMBOL_69_6 = 69,                      /* $@6  */
  YYSYMBOL_inLoop = 70,                    /* inLoop  */
  YYSYMBOL_71_7 = 71,                      /* $@7  */
  YYSYMBOL_72_8 = 72,                      /* $@8  */
  YYSYMBOL_ifStatement = 73,               /* ifStatement  */
  YYSYMBOL_74_9 = 74,                      /* $@9  */
  YYSYMBOL_75_10 = 75,                     /* $@10  */
  YYSYMBOL_76_11 = 76,                     /* $@11  */
  YYSYMBOL_77_12 = 77,                     /* $@12  */
  YYSYMBOL_ifContinuer = 78,               /* ifContinuer  */
  YYSYMBOL_ES = 79,                        /* ES  */
  YYSYMBOL_80_13 = 80,                     /* $@13  */
  YYSYMBOL_81_14 = 81,                     /* $@14  */
  YYSYMBOL_82_15 = 82,                     /* $@15  */
  YYSYMBOL_83_16 = 83,                     /* $@16  */
  YYSYMBOL_84_17 = 84,                     /* $@17  */
  YYSYMBOL_85_18 = 85,                     /* $@18  */
  YYSYMBOL_86_19 = 86,                     /* $@19  */
  YYSYMBOL_ifInLoopStatement = 87,         /* ifInLoopStatement  */
  YYSYMBOL_88_20 = 88,                     /* $@20  */
  YYSYMBOL_89_21 = 89,                     /* $@21  */
  YYSYMBOL_ifInLoopContinuer = 90,         /* ifInLoopContinuer  */
  YYSYMBOL_ESLoop = 91,                    /* ESLoop  */
  YYSYMBOL_92_22 = 92,                     /* $@22  */
  YYSYMBOL_93_23 = 93,                     /* $@23  */
  YYSYMBOL_94_24 = 94,                     /* $@24  */
  YYSYMBOL_95_25 = 95,                     /* $@25  */
  YYSYMBOL_96_26 = 96,                     /* $@26  */
  YYSYMBOL_97_27 = 97,                     /* $@27  */
  YYSYMBOL_98_28 = 98,                     /* $@28  */
  YYSYMBOL_switchStatement = 99,           /* switchStatement  */
  YYSYMBOL_100_29 = 100,                   /* $@29  */
  YYSYMBOL_101_30 = 101,                   /* $@30  */
  YYSYMBOL_caseStatements = 102,           /* caseStatements  */
  YYSYMBOL_caseStatementInt = 103,         /* caseStatementInt  */
  YYSYMBOL_104_31 = 104,                   /* $@31  */
  YYSYMBOL_105_32 = 105,                   /* $@32  */
  YYSYMBOL_caseInt = 106,                  /* caseInt  */
  YYSYMBOL_caseContinuer = 107,            /* caseContinuer  */
  YYSYMBOL_defaultStatement = 108,         /* defaultStatement  */
  YYSYMBOL_109_33 = 109,                   /* $@33  */
  YYSYMBOL_basicStatements = 110,          /* basicStatements  */
  YYSYMBOL_basicStatement = 111,           /* basicStatement  */
  YYSYMBOL_assignmentStatement = 112,      /* assignmentStatement  */
  YYSYMBOL_printer = 113,                  /* printer  */
  YYSYMBOL_scanner = 114,                  /* scanner  */
  YYSYMBOL_declarationStatement = 115,     /* declarationStatement  */
  YYSYMBOL_116_34 = 116,                   /* $@34  */
  YYSYMBOL_117_35 = 117,                   /* $@35  */
  YYSYMBOL_118_36 = 118,                   /* $@36  */
  YYSYMBOL_119_37 = 119,                   /* $@37  */
  YYSYMBOL_120_38 = 120,                   /* $@38  */
  YYSYMBOL_121_39 = 121,                   /* $@39  */
  YYSYMBOL_122_40 = 122,                   /* $@40  */
  YYSYMBOL_123_41 = 123,                   /* $@41  */
  YYSYMBOL_124_42 = 124,                   /* $@42  */
  YYSYMBOL_arrayValuesF = 125,             /* arrayValuesF  */
  YYSYMBOL_arrayValues = 126,              /* arrayValues  */
  YYSYMBOL_prattributes = 127,             /* prattributes  */
  YYSYMBOL_scattributes = 128,             /* scattributes  */
  YYSYMBOL_declarationListInt = 129,       /* declarationListInt  */
  YYSYMBOL_declarationListFloat = 130,     /* declarationListFloat  */
  YYSYMBOL_declarationListChar = 131,      /* declarationListChar  */
  YYSYMBOL_expressionStatement = 132,      /* expressionStatement  */
  YYSYMBOL_logicalExpression = 133,        /* logicalExpression  */
  YYSYMBOL_expression = 134,               /* expression  */
  YYSYMBOL_relationalExpression = 135,     /* relationalExpression  */
  YYSYMBOL_value = 136,                    /* value  */
  YYSYMBOL_term = 137,                     /* term  */
  YYSYMBOL_factor = 138,                   /* factor  */
  YYSYMBOL_139_43 = 139,                   /* $@43  */
  YYSYMBOL_functionCall = 140,             /* functionCall  */
  YYSYMBOL_argList = 141,                  /* argList  */
  YYSYMBOL_parameters = 142,               /* parameters  */
  YYSYMBOL_143_44 = 143,                   /* $@44  */
  YYSYMBOL_paramContinuer = 144,           /* paramContinuer  */
  YYSYMBOL_parameter = 145,                /* parameter  */
  YYSYMBOL_type = 146,                     /* type  */
  YYSYMBOL_compoundStatements = 147,       /* compoundStatements  */
  YYSYMBOL_statementList = 148,            /* statementList  */
  YYSYMBOL_149_45 = 149,                   /* $@45  */
  YYSYMBOL_150_46 = 150,                   /* $@46  */
  YYSYMBOL_returnDec = 151,                /* returnDec  */
  YYSYMBOL_dimension = 152                 /* dimension  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   606

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  237
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  466

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   273,   273,   275,   276,   277,   278,   280,   281,   282,
     283,   284,   285,   286,   288,   288,   289,   290,   291,   292,
     292,   292,   294,   295,   295,   296,   296,   298,   299,   300,
     301,   302,   303,   304,   305,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   319,   319,   320,   320,   321,
     322,   322,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   333,   334,   334,   335,   337,   337,   337,   338,
     338,   338,   339,   340,   342,   342,   342,   343,   343,   343,
     344,   344,   344,   345,   345,   346,   348,   348,   348,   349,
     350,   352,   352,   352,   353,   353,   353,   354,   354,   354,
     355,   355,   356,   358,   358,   358,   359,   359,   360,   360,
     360,   360,   361,   362,   363,   364,   365,   366,   367,   367,
     368,   371,   372,   374,   375,   376,   377,   378,   380,   381,
     382,   383,   385,   386,   387,   387,   388,   388,   389,   389,
     390,   390,   390,   391,   391,   391,   392,   392,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   404,   405,
     406,   407,   408,   409,   410,   411,   413,   414,   415,   416,
     417,   419,   420,   421,   422,   423,   425,   426,   427,   428,
     429,   431,   432,   434,   435,   437,   438,   439,   441,   442,
     443,   444,   445,   447,   448,   449,   451,   452,   453,   454,
     456,   457,   458,   459,   460,   461,   462,   463,   463,   464,
     465,   468,   469,   472,   473,   475,   475,   476,   477,   479,
     481,   482,   483,   485,   487,   488,   489,   490,   491,   491,
     493,   493,   495,   497,   498,   500,   501,   502
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LOGICALOR",
  "LOGICALAND", "EQUALS", "NOTEQUAL", "GREATERTHAN", "GREATERTHANEQUALTO",
  "LESSTHAN", "LESSTHANEQUALTO", "ADD", "SUB", "MULT", "DIV", "MOD",
  "COMMA", "SEMICOLON", "AMPERSAND", "COLON", "INT", "CHAR", "FLOAT",
  "STRING", "IF", "ELSE", "FOR", "WHILE", "DEFAULT", "SWITCH", "CASE",
  "BREAK", "CONTINUE", "RETURN", "PRINTF", "SCANF", "OPBRAC", "CLBRAC",
  "OPCUR", "CLCUR", "BOXOPEN", "BOXCLOSE", "LOGICALNOT", "EQUAL",
  "CHARVAL", "INTVAL", "FLOATVAL", "IDENTIFIER", "$accept", "code",
  "declarationList", "statements", "singleStatement", "specialStatement",
  "$@1", "forLoop", "forLoop1", "forLoop2", "$@2", "forLoop3", "$@3",
  "singleLoopStatement", "forAssignStatement", "forExpStatement",
  "forUpdateStatement", "whileLoop", "$@4", "whileSuffix", "$@5", "$@6",
  "inLoop", "$@7", "$@8", "ifStatement", "$@9", "$@10", "$@11", "$@12",
  "ifContinuer", "ES", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18",
  "$@19", "ifInLoopStatement", "$@20", "$@21", "ifInLoopContinuer",
  "ESLoop", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28",
  "switchStatement", "$@29", "$@30", "caseStatements", "caseStatementInt",
  "$@31", "$@32", "caseInt", "caseContinuer", "defaultStatement", "$@33",
  "basicStatements", "basicStatement", "assignmentStatement", "printer",
  "scanner", "declarationStatement", "$@34", "$@35", "$@36", "$@37",
  "$@38", "$@39", "$@40", "$@41", "$@42", "arrayValuesF", "arrayValues",
  "prattributes", "scattributes", "declarationListInt",
  "declarationListFloat", "declarationListChar", "expressionStatement",
  "logicalExpression", "expression", "relationalExpression", "value",
  "term", "factor", "$@43", "functionCall", "argList", "parameters",
  "$@44", "paramContinuer", "parameter", "type", "compoundStatements",
  "statementList", "$@45", "$@46", "returnDec", "dimension", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-383)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-237)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      55,    -6,     5,    79,    52,   151,  -383,    55,    55,    38,
     141,    87,   150,   104,   162,    83,   187,   149,  -383,  -383,
    -383,   147,   223,   118,   187,  -383,  -383,   155,   250,   152,
     217,  -383,  -383,   207,   258,   176,   187,  -383,  -383,   268,
     257,   187,   187,  -383,  -383,  -383,   186,   211,   321,   330,
     242,   262,   225,   297,   187,     0,  -383,  -383,  -383,   294,
     134,   316,    51,  -383,  -383,  -383,   209,   296,   323,  -383,
     109,  -383,  -383,   309,   248,   327,   324,   314,   331,  -383,
     345,   338,   339,  -383,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   312,   348,   350,
    -383,  -383,  -383,  -383,   372,   343,   353,   147,   355,   356,
     371,   249,   155,   358,  -383,   361,   207,   359,   362,  -383,
    -383,   187,   360,  -383,  -383,  -383,  -383,  -383,  -383,  -383,
    -383,  -383,  -383,  -383,  -383,  -383,  -383,   339,  -383,   370,
     370,   294,  -383,   165,  -383,   370,   370,   392,   387,  -383,
     370,   370,   -33,  -383,  -383,   373,  -383,     2,   376,  -383,
     512,  -383,  -383,  -383,   396,   401,   379,  -383,  -383,  -383,
     402,  -383,  -383,   405,   407,   386,  -383,   187,  -383,   382,
     393,  -383,   395,   397,    71,   398,   399,   169,   512,  -383,
    -383,  -383,   512,   260,  -383,  -383,  -383,  -383,  -383,   512,
     389,  -383,  -383,   391,   415,  -383,  -383,   394,   428,  -383,
     406,   187,   413,  -383,   404,  -383,   438,   435,   437,   154,
     197,  -383,  -383,  -383,  -383,  -383,   512,   512,  -383,  -383,
    -383,  -383,  -383,  -383,  -383,   429,    16,  -383,  -383,  -383,
    -383,   187,   430,  -383,  -383,  -383,   448,    28,   427,  -383,
    -383,   431,  -383,   423,   424,   187,  -383,   436,   434,    43,
      77,  -383,   460,   254,  -383,   417,   439,   440,   462,  -383,
      91,  -383,   187,   464,   467,   470,  -383,   443,   417,  -383,
    -383,  -383,  -383,   187,   187,   445,  -383,  -383,  -383,   540,
     463,  -383,  -383,   187,  -383,   449,  -383,   417,   417,   417,
     241,   325,   332,   451,   458,   484,   466,   479,   481,  -383,
    -383,  -383,  -383,  -383,  -383,  -383,   471,  -383,   473,  -383,
     457,   468,  -383,  -383,  -383,   -14,  -383,  -383,  -383,    16,
    -383,    16,  -383,   187,    93,   492,   495,   484,   484,   482,
     484,   484,   484,  -383,  -383,   484,  -383,   187,  -383,  -383,
     503,  -383,   142,  -383,   241,   487,  -383,   417,  -383,  -383,
     508,  -383,  -383,   540,   484,   484,  -383,  -383,  -383,  -383,
    -383,  -383,   484,   484,  -383,   488,  -383,   496,   306,   518,
     521,   463,  -383,   187,   417,  -383,   445,   484,  -383,  -383,
    -383,  -383,  -383,   489,   417,  -383,   505,   506,   417,   417,
    -383,   507,  -383,  -383,   510,   244,  -383,   531,   532,   522,
    -383,  -383,   514,   516,  -383,   484,   417,   417,   546,  -383,
     417,  -383,  -383,  -383,  -383,  -383,   417,  -383,   526,  -383,
     543,   328,   535,  -383,   534,   126,  -383,  -383,  -383,   543,
     187,   539,  -383,   540,  -383,   541,   187,   484,  -383,   542,
     544,  -383,  -383,   545,   538,  -383,   540,  -383,   484,  -383,
    -383,   554,   549,  -383,   554,  -383
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     5,   170,
       0,   180,     0,   175,     0,     0,     0,     0,     1,     4,
       3,     0,   215,     0,     0,   169,   149,     0,   215,     0,
       0,   179,   152,     0,   215,     0,     0,   174,   153,     0,
       0,     0,     0,   203,   204,   205,   200,     0,   182,   184,
     187,   192,   195,   199,     0,   170,   167,   141,   134,     0,
       0,   168,   180,   177,   147,   136,     0,     0,   203,   178,
     175,   172,   144,     0,     0,   173,     0,   235,     0,   202,
     207,     0,     0,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   222,   221,   216,   217,     0,     0,     0,     0,     0,
       0,   235,     0,     0,   138,     0,     0,     0,     0,   201,
     206,     0,     0,   128,   181,   183,   185,   186,   188,   189,
     190,   191,   193,   194,   196,   197,   198,     0,   131,     0,
       0,     0,   219,     0,   166,     0,     0,     0,     0,   176,
       0,     0,     0,   171,   237,     0,   214,     0,   209,   130,
     232,   142,   135,   218,     0,   161,     0,   148,   137,   151,
       0,   145,   139,     0,   159,     0,   236,     0,   208,     0,
       0,    14,     0,     0,     0,     0,     0,   200,   232,    17,
      16,    18,   232,   122,   125,   228,   230,   124,   123,   127,
       0,   126,   155,     0,     0,   150,   157,     0,     0,   213,
       0,     0,     0,    45,     0,   234,     0,     0,     0,     0,
       0,   226,   225,   121,   127,   126,   232,   232,   224,   223,
     160,   154,   158,   156,   210,     0,     0,    15,    21,    19,
      20,     0,     0,   233,   163,   165,   206,     0,     0,   229,
     231,    69,    40,     0,     0,    42,    35,     0,     0,     0,
       0,   211,     0,   209,    66,     0,     0,     0,     0,    41,
      50,   103,     0,     0,     0,     0,   212,     0,    10,    70,
      11,    12,    13,     0,     0,     0,    49,    47,    46,     0,
     107,   162,   132,     0,   133,     0,    67,    10,    10,    10,
      85,     0,     0,     0,     0,    65,     0,     0,     0,    27,
      51,    33,    18,    28,    29,    34,   120,   106,     0,   164,
     210,     0,     7,     8,     9,    83,    73,    71,    72,     0,
      36,     0,    38,     0,    25,     0,     0,    27,    65,     0,
      33,    18,    28,    61,    63,    29,    34,     0,    30,    31,
       0,   104,     0,   109,    85,     0,    77,     0,    37,    39,
      44,    22,    23,     0,    30,    31,    54,    59,    48,    57,
      58,    55,    65,    65,    56,     0,   118,     0,     0,     0,
       0,   111,    68,     0,    10,    84,     0,    65,    26,    52,
      53,    62,    64,    69,    10,   105,     0,     0,    10,    10,
     110,     0,    78,    43,     0,    66,   119,     0,     0,   117,
     115,   113,    80,     0,    24,    65,    10,    10,     0,    74,
       0,    79,    87,   114,   112,   116,    10,    81,     0,    75,
      85,   102,     0,    82,     0,   100,    90,    88,    89,    85,
       0,     0,    94,     0,    76,     0,     0,    65,   101,     0,
       0,    95,    86,    97,     0,    91,     0,    96,    65,    98,
      92,   102,     0,    99,   102,    93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -383,  -383,   351,  -251,  -348,    58,  -383,  -383,  -383,  -383,
    -383,  -383,  -383,  -267,  -220,  -383,   203,  -383,  -383,  -383,
    -383,  -383,    39,  -383,  -383,  -293,  -383,  -383,  -383,  -383,
     236,  -277,  -383,  -383,  -383,  -383,  -383,  -383,  -383,  -274,
    -383,  -383,  -383,  -382,  -383,  -383,  -383,  -383,  -383,  -383,
    -383,    33,  -383,  -383,  -383,   210,  -383,  -383,  -383,  -280,
    -383,  -383,   400,  -143,     4,  -128,  -126,    21,  -383,  -383,
    -383,  -383,  -383,  -383,  -383,  -383,  -383,   385,   403,  -383,
    -383,   -20,   -31,   -22,   -16,   509,   274,   230,   272,   231,
    -151,  -383,   -54,   377,   185,  -383,   454,  -383,  -383,    20,
    -169,  -383,  -383,  -157,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,   409,   279,   337,   212,   237,   238,   239,
     387,   240,   363,   338,   255,   268,   304,   189,   241,   288,
     305,   289,   339,   372,   373,   190,   278,   321,   265,   300,
     327,   328,   426,   432,   384,   413,   420,   430,   357,   340,
     415,   428,   437,   438,   458,   462,   447,   454,   456,   461,
     443,   191,   290,   377,   316,   317,   318,   381,   353,   410,
     351,   394,   192,   342,   194,   343,   344,   197,    99,   109,
     151,    57,    98,    72,   113,    64,   108,   175,   166,   259,
     260,    10,    14,    12,   198,    48,    49,    50,    51,    52,
      53,   121,   345,   157,    58,    59,   103,   104,   105,   161,
     200,   226,   227,   225,    17
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    56,    71,   201,     7,    63,   173,   326,    61,   385,
     355,     7,     7,   174,    69,   311,    21,   193,   177,   221,
      75,     8,   310,   222,   356,    78,    79,   296,     8,     8,
     228,   201,   195,   252,   196,   201,   253,   254,    97,   178,
      15,     9,   201,    24,   177,   193,   322,   323,   324,   193,
     193,    25,    11,    31,    21,    37,   193,   249,   250,   272,
     195,   326,   196,     4,   195,   262,   196,    27,   124,   201,
     201,   195,   427,   196,    22,     1,     2,     3,    23,   463,
     273,    24,   465,   193,   193,   153,   123,   144,   215,   311,
     149,    15,    15,   274,    30,    16,   388,    25,   195,   195,
     196,   196,     4,    27,    31,   156,   199,    41,   286,   358,
     361,   359,    37,    42,   275,    43,    44,    45,    46,   411,
      33,   291,   281,    28,    39,    33,    13,    29,    40,   287,
      30,   362,   315,   402,   199,   298,   423,   424,   199,   224,
      34,   159,   319,   406,    35,   199,   313,    36,   346,    15,
     441,    18,    36,   433,   298,   298,   298,   436,    26,    60,
     162,   209,   444,    40,   442,   167,   168,    32,   216,   311,
     171,   172,   199,   199,    76,   429,   448,   106,   378,    38,
     346,   346,   311,   346,   346,   346,   379,   380,   346,   459,
      41,   246,    54,    66,    55,   235,    42,    67,    43,    44,
      45,    46,    62,   156,   164,   219,   315,   346,   346,   220,
     165,   282,    16,    65,   281,   346,   346,    74,   188,    73,
     313,    40,    80,    41,   299,   257,    81,    82,    83,    42,
     346,    43,    44,    45,    46,   314,    92,    93,    39,   269,
     256,   298,   248,   299,   299,   299,   188,    86,    87,    76,
     188,   298,   110,    41,    70,   298,   298,   188,   346,    42,
    -140,    68,    44,    45,    46,   180,   325,   301,   302,    88,
      89,    90,    91,   298,   298,   -86,   -86,   281,   -86,   -86,
       1,     2,     3,   298,   188,   188,   315,  -146,    76,   118,
     346,   115,   148,   184,   277,  -143,    41,  -235,    77,   315,
     313,   346,    42,   282,    43,    44,    45,   187,    76,   314,
      94,    95,    96,   313,   100,   101,   102,   360,   128,   129,
     130,   131,   312,   280,    84,   134,   135,   136,   137,   138,
     299,   375,   107,   256,    85,   256,   297,   111,   341,   112,
     299,   329,   330,   116,   299,   299,   114,   309,   331,   332,
     396,   397,   434,   435,   118,   297,   297,   297,    19,    20,
     126,   127,   299,   299,   132,   133,   282,   401,   119,   117,
     341,   341,   299,   341,   341,   341,   366,   367,   341,   369,
     370,   371,   120,   122,   374,   139,     4,   140,   141,   314,
     142,   143,   145,   146,   147,   150,   312,   341,   341,   152,
     154,   158,   314,   389,   390,   341,   341,   155,   160,   169,
     170,   391,   392,   202,   176,   280,   179,   203,   204,   205,
     341,   309,   206,   207,   445,   208,   404,   210,   229,   211,
     450,   213,   231,   214,   217,   218,   165,     1,     2,     3,
     174,   180,   297,   181,   182,   233,   183,   234,   341,   236,
     184,   242,   297,    41,   422,   243,   297,   297,   244,    42,
     245,    43,    44,    45,   187,   261,   251,   258,   263,   264,
     266,   267,   271,   270,   297,   297,   312,   276,   280,   285,
     341,   292,   283,   284,   297,   293,   451,   294,   295,   312,
     320,   341,   303,  -108,   333,   334,   348,   460,   349,   350,
    -236,   309,   347,   352,     1,     2,     3,   354,   306,   364,
     181,   182,   365,   183,   309,   335,   336,   184,   185,   186,
      41,   368,   376,   383,   386,   393,    42,   405,    43,    44,
      45,   187,     1,     2,     3,   395,   180,   398,   181,   182,
     399,   183,   407,   408,   412,   184,   185,   186,    41,   414,
     416,   417,   419,   418,    42,   421,    43,    44,    45,   187,
       1,     2,     3,   425,   306,   431,   181,   182,   325,   183,
     440,   307,   308,   184,   439,   446,    41,   457,   449,   435,
     452,   453,    42,   455,    43,    44,    45,   187,   464,   403,
     382,   400,   232,   223,   125,   163,   247,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230
};

static const yytype_int16 yycheck[] =
{
      16,    21,    33,   160,     0,    27,    39,   300,    24,   357,
      24,     7,     8,    46,    30,   289,    16,   160,    16,   188,
      36,     0,   289,   192,    38,    41,    42,   278,     7,     8,
     199,   188,   160,    17,   160,   192,    20,    21,    54,    37,
      40,    47,   199,    43,    16,   188,   297,   298,   299,   192,
     193,     9,    47,    11,    16,    13,   199,   226,   227,    16,
     188,   354,   188,    47,   192,    37,   192,    16,    84,   226,
     227,   199,   420,   199,    36,    20,    21,    22,    40,   461,
      37,    43,   464,   226,   227,   116,    82,   107,    17,   363,
     112,    40,    40,    16,    43,    43,   363,    55,   226,   227,
     226,   227,    47,    16,    62,   121,   160,    36,    17,   329,
      17,   331,    70,    42,    37,    44,    45,    46,    47,   399,
      16,   272,   265,    36,    41,    16,    47,    40,    45,    38,
      43,    38,   289,   384,   188,   278,   416,   417,   192,   193,
      36,   137,   293,   394,    40,   199,   289,    43,   305,    40,
      24,     0,    43,   430,   297,   298,   299,   431,    17,    41,
     140,   177,   439,    45,    38,   145,   146,    17,   184,   443,
     150,   151,   226,   227,    40,   426,   443,    43,    36,    17,
     337,   338,   456,   340,   341,   342,    44,    45,   345,   456,
      36,    37,    43,    41,    47,   211,    42,    45,    44,    45,
      46,    47,    47,   219,    39,    36,   363,   364,   365,    40,
      45,   265,    43,    28,   357,   372,   373,    41,   160,    34,
     363,    45,    36,    36,   278,   241,    40,    16,    17,    42,
     387,    44,    45,    46,    47,   289,    11,    12,    41,   255,
     236,   384,    45,   297,   298,   299,   188,     5,     6,    40,
     192,   394,    43,    36,    47,   398,   399,   199,   415,    42,
      37,    44,    45,    46,    47,    24,    25,   283,   284,     7,
       8,     9,    10,   416,   417,    31,    32,   420,    34,    35,
      20,    21,    22,   426,   226,   227,   443,    37,    40,    40,
     447,    43,    43,    33,    40,    37,    36,    43,    41,   456,
     443,   458,    42,   357,    44,    45,    46,    47,    40,   363,
      13,    14,    15,   456,    20,    21,    22,   333,    88,    89,
      90,    91,   289,   265,     3,    94,    95,    96,    16,    17,
     384,   347,    16,   329,     4,   331,   278,    41,   305,    16,
     394,    16,    17,    16,   398,   399,    37,   289,    16,    17,
      44,    45,    24,    25,    40,   297,   298,   299,     7,     8,
      86,    87,   416,   417,    92,    93,   420,   383,    37,    45,
     337,   338,   426,   340,   341,   342,   337,   338,   345,   340,
     341,   342,    37,    45,   345,    37,    47,    37,    16,   443,
      47,    38,    37,    37,    23,    37,   363,   364,   365,    38,
      41,    41,   456,   364,   365,   372,   373,    45,    38,    17,
      23,   372,   373,    17,    41,   357,    40,    16,    39,    17,
     387,   363,    17,    16,   440,    39,   387,    45,    39,    36,
     446,    36,    17,    36,    36,    36,    45,    20,    21,    22,
      46,    24,   384,    26,    27,    17,    29,    41,   415,    36,
      33,    47,   394,    36,   415,    17,   398,   399,    23,    42,
      23,    44,    45,    46,    47,    17,    37,    37,    41,    38,
      47,    47,    38,    37,   416,   417,   443,    17,   420,    17,
     447,    17,    43,    43,   426,    18,   447,    17,    45,   456,
      41,   458,    47,    30,    43,    37,    17,   458,    17,    28,
      43,   443,    36,    30,    20,    21,    22,    39,    24,    17,
      26,    27,    17,    29,   456,    31,    32,    33,    34,    35,
      36,    39,    19,    36,    16,    37,    42,    38,    44,    45,
      46,    47,    20,    21,    22,    39,    24,    19,    26,    27,
      19,    29,    37,    37,    37,    33,    34,    35,    36,    39,
      19,    19,    38,    31,    42,    39,    44,    45,    46,    47,
      20,    21,    22,    17,    24,    39,    26,    27,    25,    29,
      36,    31,    32,    33,    39,    36,    36,    39,    37,    25,
      38,    37,    42,    38,    44,    45,    46,    47,    39,   386,
     354,   381,   207,   193,    85,   141,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   203
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    47,    49,    50,   112,   115,    47,
     129,    47,   131,    47,   130,    40,    43,   152,     0,    50,
      50,    16,    36,    40,    43,   152,    17,    16,    36,    40,
      43,   152,    17,    16,    36,    40,    43,   152,    17,    41,
      45,    36,    42,    44,    45,    46,    47,   132,   133,   134,
     135,   136,   137,   138,    43,    47,   129,   119,   142,   143,
      41,   132,    47,   131,   123,   142,    41,    45,    44,   132,
      47,   130,   121,   142,    41,   132,    40,    41,   132,   132,
      36,    40,    16,    17,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,   132,   120,   116,
      20,    21,    22,   144,   145,   146,    43,    16,   124,   117,
      43,    41,    16,   122,    37,    43,    16,    45,    40,    37,
      37,   139,    45,   112,   132,   133,   134,   134,   135,   135,
     135,   135,   136,   136,   137,   137,   137,    16,    17,    37,
      37,    16,    47,    38,   129,    37,    37,    23,    43,   131,
      37,   118,    38,   130,    41,    45,   132,   141,    41,   112,
      38,   147,   147,   144,    39,    45,   126,   147,   147,    17,
      23,   147,   147,    39,    46,   125,    41,    16,    37,    40,
      24,    26,    27,    29,    33,    34,    35,    47,    53,    65,
      73,    99,   110,   111,   112,   113,   114,   115,   132,   140,
     148,   151,    17,    16,    39,    17,    17,    16,    39,   132,
      45,    36,    54,    36,    36,    17,   132,    36,    36,    36,
      40,   148,   148,   110,   140,   151,   149,   150,   148,    39,
     126,    17,   125,    17,    41,   132,    36,    55,    56,    57,
      59,    66,    47,    17,    23,    23,    37,   141,    45,   148,
     148,    37,    17,    20,    21,    62,   112,   132,    37,   127,
     128,    17,    37,    41,    38,    76,    47,    47,    63,   132,
      37,    38,    16,    37,    16,    37,    17,    40,    74,    52,
      53,   111,   140,    43,    43,    17,    17,    38,    67,    69,
     100,   138,    17,    18,    17,    45,    51,    53,   111,   140,
      77,   132,   132,    47,    64,    68,    24,    31,    32,    53,
      61,    87,    99,   111,   140,   151,   102,   103,   104,   138,
      41,    75,    51,    51,    51,    25,    73,    78,    79,    16,
      17,    16,    17,    43,    37,    31,    32,    53,    61,    70,
      87,    99,   111,   113,   114,   140,   151,    36,    17,    17,
      28,   108,    30,   106,    39,    24,    38,    86,    62,    62,
     132,    17,    38,    60,    17,    17,    70,    70,    39,    70,
      70,    70,    71,    72,    70,   132,    19,   101,    36,    44,
      45,   105,    78,    36,    82,    52,    16,    58,    61,    70,
      70,    70,    70,    37,   109,    39,    44,    45,    19,    19,
     103,   132,    51,    64,    70,    38,    51,    37,    37,    51,
     107,   107,    37,    83,    39,    88,    19,    19,    31,    38,
      84,    39,    70,   107,   107,    17,    80,    52,    89,    51,
      85,    39,    81,    79,    24,    25,    87,    90,    91,    39,
      36,    24,    38,    98,    79,   132,    36,    94,    61,    37,
     132,    70,    38,    37,    95,    38,    96,    39,    92,    61,
      70,    97,    93,    91,    39,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    50,    51,    51,    51,
      51,    52,    52,    52,    54,    53,    53,    53,    53,    55,
      55,    55,    56,    58,    57,    60,    59,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    66,    65,    68,    67,    67,
      69,    67,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    70,    72,    70,    70,    74,    75,    73,    76,
      77,    73,    78,    78,    80,    81,    79,    82,    83,    79,
      84,    85,    79,    86,    79,    79,    88,    89,    87,    90,
      90,    92,    93,    91,    94,    95,    91,    96,    97,    91,
      98,    91,    91,   100,   101,    99,   102,   102,   104,   105,
     103,   103,   106,   106,   106,   106,   107,   107,   109,   108,
     108,   110,   110,   111,   111,   111,   111,   111,   112,   112,
     112,   112,   113,   114,   116,   115,   117,   115,   118,   115,
     119,   120,   115,   121,   122,   115,   123,   124,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   129,   129,
     129,   130,   130,   130,   130,   130,   131,   131,   131,   131,
     131,   132,   132,   133,   133,   134,   134,   134,   135,   135,
     135,   135,   135,   136,   136,   136,   137,   137,   137,   137,
     138,   138,   138,   138,   138,   138,   138,   139,   138,   138,
     138,   140,   140,   141,   141,   143,   142,   144,   144,   145,
     146,   146,   146,   147,   148,   148,   148,   148,   149,   148,
     150,   148,   148,   151,   151,   152,   152,   152
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     2,     2,     2,
       0,     1,     1,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     7,     0,    10,     0,     8,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     5,     6,     5,     6,
       1,     1,     0,     5,     3,     0,     6,     0,     4,     1,
       0,     2,     3,     3,     2,     2,     2,     2,     2,     2,
       1,     0,     3,     0,     3,     0,     0,     0,    10,     0,
       0,     8,     1,     1,     0,     0,    11,     0,     0,     6,
       0,     0,     9,     0,     3,     0,     0,     0,    10,     1,
       1,     0,     0,    11,     0,     0,     6,     0,     0,     9,
       0,     3,     0,     0,     0,    10,     1,     0,     0,     0,
       4,     0,     6,     4,     6,     4,     3,     1,     0,     4,
       0,     2,     1,     1,     1,     1,     1,     1,     5,     4,
       6,     5,     6,     6,     0,     7,     0,     7,     0,     7,
       0,     0,     7,     0,     0,     7,     0,     0,     7,     3,
       8,     7,     3,     3,     9,     8,     9,     8,     3,     1,
       3,     1,     3,     0,     4,     0,     5,     3,     3,     2,
       1,     5,     3,     3,     2,     1,     5,     3,     3,     2,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       1,     3,     2,     1,     1,     1,     3,     0,     5,     4,
       7,     4,     5,     3,     1,     0,     2,     1,     3,     2,
       1,     1,     1,     3,     2,     2,     2,     1,     0,     3,
       0,     3,     0,     3,     2,     3,     6,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* code: declarationList  */
#line 273 "SemanticAnalyzer.y"
                            {}
#line 1952 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 275 "SemanticAnalyzer.y"
                                                             {}
#line 1958 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 277 "SemanticAnalyzer.y"
                                                        {}
#line 1964 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 280 "SemanticAnalyzer.y"
                                              {}
#line 1970 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 281 "SemanticAnalyzer.y"
                                               {}
#line 1976 "y.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 288 "SemanticAnalyzer.y"
                            {pushNewScope();}
#line 1982 "y.tab.c"
    break;

  case 22: /* forLoop1: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON  */
#line 294 "SemanticAnalyzer.y"
                                                                                                          {popScope(); }
#line 1988 "y.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 295 "SemanticAnalyzer.y"
                                                                                                   {pushNewScope();}
#line 1994 "y.tab.c"
    break;

  case 24: /* forLoop2: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR $@2 inLoop CLCUR  */
#line 295 "SemanticAnalyzer.y"
                                                                                                                                  {popScope(); popScope(); }
#line 2000 "y.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 296 "SemanticAnalyzer.y"
                                                                                              {pushNewScope();}
#line 2006 "y.tab.c"
    break;

  case 26: /* forLoop3: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC $@3 singleLoopStatement  */
#line 296 "SemanticAnalyzer.y"
                                                                                                                                    {popScope(); popScope(); }
#line 2012 "y.tab.c"
    break;

  case 36: /* forAssignStatement: INT IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 308 "SemanticAnalyzer.y"
                                                                                             { if(checkVariable((yyvsp[-3].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-3].Str));return 1;}if(strcmp((yyvsp[-1].Str),strdup("i"))!=0){printf("Type Mismatch");return 1;}insertInTable((yyvsp[-3].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2018 "y.tab.c"
    break;

  case 37: /* forAssignStatement: INT IDENTIFIER EQUAL expressionStatement COMMA forAssignStatement  */
#line 309 "SemanticAnalyzer.y"
                                                                                                             { if(checkVariable((yyvsp[-4].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-4].Str));return 1;}if(strcmp((yyvsp[-2].Str),strdup("i"))!=0){printf("Type Mismatch");return 1;}insertInTable((yyvsp[-4].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2024 "y.tab.c"
    break;

  case 38: /* forAssignStatement: CHAR IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 310 "SemanticAnalyzer.y"
                                                                                              { if(checkVariable((yyvsp[-3].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-3].Str));return 1;}if(strcmp((yyvsp[-1].Str),strdup("c"))!=0){printf("Type Mismatch");return 1;}insertInTable((yyvsp[-3].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2030 "y.tab.c"
    break;

  case 39: /* forAssignStatement: CHAR IDENTIFIER EQUAL expressionStatement COMMA forAssignStatement  */
#line 311 "SemanticAnalyzer.y"
                                                                                                              { if(checkVariable((yyvsp[-4].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-4].Str));return 1;}if(strcmp((yyvsp[-2].Str),strdup("c"))!=0){printf("Type Mismatch");return 1;}insertInTable((yyvsp[-4].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2036 "y.tab.c"
    break;

  case 43: /* forUpdateStatement: IDENTIFIER EQUAL expressionStatement COMMA forUpdateStatement  */
#line 315 "SemanticAnalyzer.y"
                                                                                        {int inst = getIdentifierIndex((yyvsp[-4].Str),false,false); if(inst==-1){printf("VARIABLE NOT FOUND");return 1;}if(strcmp(table[inst].dataType,(yyvsp[-2].Str))!=0){printf("VARIABLE NOT FOUND");return 1;}}
#line 2042 "y.tab.c"
    break;

  case 44: /* forUpdateStatement: IDENTIFIER EQUAL expressionStatement  */
#line 316 "SemanticAnalyzer.y"
                                                                          {int inst = getIdentifierIndex((yyvsp[-2].Str),false,false); if(inst==-1){printf("VARIABLE NOT FOUND");return 1;}if(strcmp(table[inst].dataType,(yyvsp[0].Str))!=0){printf("VARIABLE NOT FOUND");return 1;}}
#line 2048 "y.tab.c"
    break;

  case 45: /* $@4: %empty  */
#line 319 "SemanticAnalyzer.y"
                             {pushNewScope();}
#line 2054 "y.tab.c"
    break;

  case 47: /* $@5: %empty  */
#line 320 "SemanticAnalyzer.y"
                         {pushNewScope();}
#line 2060 "y.tab.c"
    break;

  case 48: /* whileSuffix: OPCUR $@5 inLoop CLCUR  */
#line 320 "SemanticAnalyzer.y"
                                                       { popScope(); popScope(); }
#line 2066 "y.tab.c"
    break;

  case 49: /* whileSuffix: SEMICOLON  */
#line 321 "SemanticAnalyzer.y"
                              {popScope(); }
#line 2072 "y.tab.c"
    break;

  case 50: /* $@6: %empty  */
#line 322 "SemanticAnalyzer.y"
                    {pushNewScope();}
#line 2078 "y.tab.c"
    break;

  case 51: /* whileSuffix: $@6 singleLoopStatement  */
#line 322 "SemanticAnalyzer.y"
                                                          { popScope(); popScope();}
#line 2084 "y.tab.c"
    break;

  case 52: /* inLoop: BREAK SEMICOLON inLoop  */
#line 324 "SemanticAnalyzer.y"
                                     {}
#line 2090 "y.tab.c"
    break;

  case 53: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 325 "SemanticAnalyzer.y"
                                            {}
#line 2096 "y.tab.c"
    break;

  case 54: /* inLoop: specialStatement inLoop  */
#line 326 "SemanticAnalyzer.y"
                                          {}
#line 2102 "y.tab.c"
    break;

  case 55: /* inLoop: basicStatement inLoop  */
#line 327 "SemanticAnalyzer.y"
                                        {}
#line 2108 "y.tab.c"
    break;

  case 56: /* inLoop: functionCall inLoop  */
#line 328 "SemanticAnalyzer.y"
                                     {}
#line 2114 "y.tab.c"
    break;

  case 57: /* inLoop: ifInLoopStatement inLoop  */
#line 329 "SemanticAnalyzer.y"
                                           {}
#line 2120 "y.tab.c"
    break;

  case 58: /* inLoop: switchStatement inLoop  */
#line 330 "SemanticAnalyzer.y"
                                         {}
#line 2126 "y.tab.c"
    break;

  case 59: /* inLoop: singleLoopStatement inLoop  */
#line 331 "SemanticAnalyzer.y"
                                             {}
#line 2132 "y.tab.c"
    break;

  case 61: /* $@7: %empty  */
#line 333 "SemanticAnalyzer.y"
                          {memset(printlistArray,'\0',sizeof(printlistArray));printindex = 0;}
#line 2138 "y.tab.c"
    break;

  case 63: /* $@8: %empty  */
#line 334 "SemanticAnalyzer.y"
                                  {memset(scanlistArray,'\0',sizeof(scanlistArray));scanindex = 0;}
#line 2144 "y.tab.c"
    break;

  case 66: /* $@9: %empty  */
#line 337 "SemanticAnalyzer.y"
                                                              {pushNewScope();}
#line 2150 "y.tab.c"
    break;

  case 67: /* $@10: %empty  */
#line 337 "SemanticAnalyzer.y"
                                                                                           {popScope();}
#line 2156 "y.tab.c"
    break;

  case 69: /* $@11: %empty  */
#line 338 "SemanticAnalyzer.y"
                                                               {pushNewScope();}
#line 2162 "y.tab.c"
    break;

  case 70: /* $@12: %empty  */
#line 338 "SemanticAnalyzer.y"
                                                                                                 {popScope();}
#line 2168 "y.tab.c"
    break;

  case 74: /* $@13: %empty  */
#line 342 "SemanticAnalyzer.y"
                                                          {pushNewScope();}
#line 2174 "y.tab.c"
    break;

  case 75: /* $@14: %empty  */
#line 342 "SemanticAnalyzer.y"
                                                                                       {popScope();}
#line 2180 "y.tab.c"
    break;

  case 77: /* $@15: %empty  */
#line 343 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 2186 "y.tab.c"
    break;

  case 78: /* $@16: %empty  */
#line 343 "SemanticAnalyzer.y"
                                                  {popScope();}
#line 2192 "y.tab.c"
    break;

  case 80: /* $@17: %empty  */
#line 344 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 2198 "y.tab.c"
    break;

  case 81: /* $@18: %empty  */
#line 344 "SemanticAnalyzer.y"
                                                                                     {popScope();}
#line 2204 "y.tab.c"
    break;

  case 83: /* $@19: %empty  */
#line 345 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 2210 "y.tab.c"
    break;

  case 84: /* ES: ELSE $@19 singleStatement  */
#line 345 "SemanticAnalyzer.y"
                                                 {popScope();}
#line 2216 "y.tab.c"
    break;

  case 86: /* $@20: %empty  */
#line 348 "SemanticAnalyzer.y"
                                                                    {pushNewScope();}
#line 2222 "y.tab.c"
    break;

  case 87: /* $@21: %empty  */
#line 348 "SemanticAnalyzer.y"
                                                                                             {popScope;}
#line 2228 "y.tab.c"
    break;

  case 91: /* $@22: %empty  */
#line 352 "SemanticAnalyzer.y"
                                                              {pushNewScope();}
#line 2234 "y.tab.c"
    break;

  case 92: /* $@23: %empty  */
#line 352 "SemanticAnalyzer.y"
                                                                                       {popScope();}
#line 2240 "y.tab.c"
    break;

  case 94: /* $@24: %empty  */
#line 353 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 2246 "y.tab.c"
    break;

  case 95: /* $@25: %empty  */
#line 353 "SemanticAnalyzer.y"
                                              {popScope();}
#line 2252 "y.tab.c"
    break;

  case 97: /* $@26: %empty  */
#line 354 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 2258 "y.tab.c"
    break;

  case 98: /* $@27: %empty  */
#line 354 "SemanticAnalyzer.y"
                                                                                         {popScope();}
#line 2264 "y.tab.c"
    break;

  case 100: /* $@28: %empty  */
#line 355 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 2270 "y.tab.c"
    break;

  case 101: /* ESLoop: ELSE $@28 singleLoopStatement  */
#line 355 "SemanticAnalyzer.y"
                                                     {popScope();}
#line 2276 "y.tab.c"
    break;

  case 103: /* $@29: %empty  */
#line 358 "SemanticAnalyzer.y"
                                                             {pushNewScope();}
#line 2282 "y.tab.c"
    break;

  case 104: /* $@30: %empty  */
#line 358 "SemanticAnalyzer.y"
                                                                                                               {popScope();}
#line 2288 "y.tab.c"
    break;

  case 105: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR $@29 caseStatements defaultStatement $@30 CLCUR  */
#line 358 "SemanticAnalyzer.y"
                                                                                                                                   {}
#line 2294 "y.tab.c"
    break;

  case 107: /* caseStatements: %empty  */
#line 359 "SemanticAnalyzer.y"
                                         {}
#line 2300 "y.tab.c"
    break;

  case 108: /* $@31: %empty  */
#line 360 "SemanticAnalyzer.y"
                        {pushNewScope();}
#line 2306 "y.tab.c"
    break;

  case 109: /* $@32: %empty  */
#line 360 "SemanticAnalyzer.y"
                                                  {pushNewScope();}
#line 2312 "y.tab.c"
    break;

  case 111: /* caseStatementInt: %empty  */
#line 360 "SemanticAnalyzer.y"
                                                                                       {}
#line 2318 "y.tab.c"
    break;

  case 113: /* caseInt: CASE INTVAL COLON caseContinuer  */
#line 362 "SemanticAnalyzer.y"
                                                  {}
#line 2324 "y.tab.c"
    break;

  case 118: /* $@33: %empty  */
#line 367 "SemanticAnalyzer.y"
                                      {pushNewScope();}
#line 2330 "y.tab.c"
    break;

  case 119: /* defaultStatement: DEFAULT COLON $@33 statements  */
#line 367 "SemanticAnalyzer.y"
                                                                   {popScope();}
#line 2336 "y.tab.c"
    break;

  case 120: /* defaultStatement: %empty  */
#line 368 "SemanticAnalyzer.y"
                                          {}
#line 2342 "y.tab.c"
    break;

  case 123: /* basicStatement: expressionStatement  */
#line 374 "SemanticAnalyzer.y"
                                          {}
#line 2348 "y.tab.c"
    break;

  case 124: /* basicStatement: declarationStatement  */
#line 375 "SemanticAnalyzer.y"
                                       {}
#line 2354 "y.tab.c"
    break;

  case 125: /* basicStatement: assignmentStatement  */
#line 376 "SemanticAnalyzer.y"
                                        {}
#line 2360 "y.tab.c"
    break;

  case 128: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 380 "SemanticAnalyzer.y"
                                                                                          {int inst = getIdentifierIndex((yyvsp[-4].Str),false,false);if(inst>=0){if(strcmp(table[inst].dataType,(yyvsp[-2].Str))!=0){printf("Type Mismatch");return 1;}}else{printf("VARIABLE NOT FOUND"); return 1;}}
#line 2366 "y.tab.c"
    break;

  case 129: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 381 "SemanticAnalyzer.y"
                                                                 {int inst = getIdentifierIndex((yyvsp[-3].Str),false,false);if(inst>=0){if(strcmp(table[inst].dataType,(yyvsp[-1].Str))!=0){printf("Type Mismatch");return 1;}}else{printf("VARIABLE NOT FOUND"); return 1;}}
#line 2372 "y.tab.c"
    break;

  case 130: /* assignmentStatement: IDENTIFIER dimension EQUAL expressionStatement COMMA assignmentStatement  */
#line 382 "SemanticAnalyzer.y"
                                                                                                   {int inst = getIdentifierIndex((yyvsp[-5].Str),true,false);if(inst>=0){if(strcmp(table[inst].dataType,(yyvsp[-3].Str))!=0){printf("Type Mismatch");return 1;}}else{printf("VARIABLE NOT FOUND"); return 1;}}
#line 2378 "y.tab.c"
    break;

  case 131: /* assignmentStatement: IDENTIFIER dimension EQUAL expressionStatement SEMICOLON  */
#line 383 "SemanticAnalyzer.y"
                                                                           {int inst = getIdentifierIndex((yyvsp[-4].Str),true,false);if(inst>=0){if(strcmp(table[inst].dataType,(yyvsp[-2].Str))!=0){printf("Type Mismatch");return 1;}}else{printf("VARIABLE NOT FOUND"); return 1;}}
#line 2384 "y.tab.c"
    break;

  case 132: /* printer: PRINTF OPBRAC STRING prattributes CLBRAC SEMICOLON  */
#line 385 "SemanticAnalyzer.y"
                                                                  {char* presentPrintString = strdup((yyvsp[-3].Str)); int len = strlen(presentPrintString);printArray(printlistArray,printindex);populate(presentPrintString,len);if(!compareParam(instanceStringList,printlistArray,instanceStringIndex,printindex)){printf("PRINTF TYPE DONOT MATCH\n\n");return 1;}memset(instanceStringList,'\0',sizeof(instanceStringList));memset(printlistArray,'\0',sizeof(printlistArray));instanceStringIndex = 0;printindex = 0;}
#line 2390 "y.tab.c"
    break;

  case 133: /* scanner: SCANF OPBRAC STRING scattributes CLBRAC SEMICOLON  */
#line 386 "SemanticAnalyzer.y"
                                                                 {char* presentPrintString = strdup((yyvsp[-3].Str)); int len = strlen(presentPrintString); printArray(scanlistArray,scanindex);populate(presentPrintString,len);if(!compareParam(instanceStringList,scanlistArray,instanceStringIndex,scanindex)){printf("SCANF TYPE DONOT MATCH\n\n");return 1;}memset(instanceStringList,'\0',sizeof(instanceStringList));memset(scanlistArray,'\0',sizeof(scanlistArray));instanceStringIndex = 0;scanindex = 0;}
#line 2396 "y.tab.c"
    break;

  case 134: /* $@34: %empty  */
#line 387 "SemanticAnalyzer.y"
                                                             {presentFunctionType = strdup("i");}
#line 2402 "y.tab.c"
    break;

  case 135: /* declarationStatement: INT IDENTIFIER OPBRAC parameters $@34 CLBRAC compoundStatements  */
#line 387 "SemanticAnalyzer.y"
                                                                                                                             {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);}else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;}memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2408 "y.tab.c"
    break;

  case 136: /* $@35: %empty  */
#line 388 "SemanticAnalyzer.y"
                                                      {presentFunctionType = strdup("c");}
#line 2414 "y.tab.c"
    break;

  case 137: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters $@35 CLBRAC compoundStatements  */
#line 388 "SemanticAnalyzer.y"
                                                                                                                     {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst ==-1){insertInTable((yyvsp[-5].Str),strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2420 "y.tab.c"
    break;

  case 138: /* $@36: %empty  */
#line 389 "SemanticAnalyzer.y"
                                                             {presentFunctionType = strdup("f");}
#line 2426 "y.tab.c"
    break;

  case 139: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC $@36 compoundStatements  */
#line 389 "SemanticAnalyzer.y"
                                                                                                                     {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2432 "y.tab.c"
    break;

  case 140: /* $@37: %empty  */
#line 390 "SemanticAnalyzer.y"
                                         {pushNewScope();}
#line 2438 "y.tab.c"
    break;

  case 141: /* $@38: %empty  */
#line 390 "SemanticAnalyzer.y"
                                                          {presentFunctionType = strdup("i");}
#line 2444 "y.tab.c"
    break;

  case 142: /* declarationStatement: INT IDENTIFIER OPBRAC $@37 $@38 CLBRAC compoundStatements  */
#line 390 "SemanticAnalyzer.y"
                                                                                                                          {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2450 "y.tab.c"
    break;

  case 143: /* $@39: %empty  */
#line 391 "SemanticAnalyzer.y"
                                           {pushNewScope();}
#line 2456 "y.tab.c"
    break;

  case 144: /* $@40: %empty  */
#line 391 "SemanticAnalyzer.y"
                                                            {presentFunctionType = strdup("f");}
#line 2462 "y.tab.c"
    break;

  case 145: /* declarationStatement: FLOAT IDENTIFIER OPBRAC $@39 $@40 CLBRAC compoundStatements  */
#line 391 "SemanticAnalyzer.y"
                                                                                                                             {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2468 "y.tab.c"
    break;

  case 146: /* $@41: %empty  */
#line 392 "SemanticAnalyzer.y"
                                          {pushNewScope();}
#line 2474 "y.tab.c"
    break;

  case 147: /* $@42: %empty  */
#line 392 "SemanticAnalyzer.y"
                                                           {presentFunctionType = strdup("c");}
#line 2480 "y.tab.c"
    break;

  case 148: /* declarationStatement: CHAR IDENTIFIER OPBRAC $@41 $@42 CLBRAC compoundStatements  */
#line 392 "SemanticAnalyzer.y"
                                                                                                                            {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2486 "y.tab.c"
    break;

  case 149: /* declarationStatement: INT declarationListInt SEMICOLON  */
#line 393 "SemanticAnalyzer.y"
                                                   {}
#line 2492 "y.tab.c"
    break;

  case 150: /* declarationStatement: CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING SEMICOLON  */
#line 394 "SemanticAnalyzer.y"
                                                                                 {if(checkVariable((yyvsp[-6].Str),currScope,true,true)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-6].Str));return 1;}insertInTable((yyvsp[-6].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2498 "y.tab.c"
    break;

  case 151: /* declarationStatement: CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING SEMICOLON  */
#line 395 "SemanticAnalyzer.y"
                                                                          {if(checkVariable((yyvsp[-5].Str),currScope,true,true)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-5].Str));return 1;}insertInTable((yyvsp[-5].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2504 "y.tab.c"
    break;

  case 154: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON  */
#line 398 "SemanticAnalyzer.y"
                                                                                          {if(checkVariable((yyvsp[-7].Str),currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-7].Str));return 1;}insertInTable((yyvsp[-7].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2510 "y.tab.c"
    break;

  case 155: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON  */
#line 399 "SemanticAnalyzer.y"
                                                                              {if(checkVariable((yyvsp[-6].Str),currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-6].Str));return 1;}insertInTable((yyvsp[-6].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2516 "y.tab.c"
    break;

  case 156: /* declarationStatement: FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValuesF CLCUR SEMICOLON  */
#line 400 "SemanticAnalyzer.y"
                                                                                                     {if(checkVariable((yyvsp[-7].Str),currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-7].Str));return 1;}insertInTable((yyvsp[-7].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2522 "y.tab.c"
    break;

  case 157: /* declarationStatement: FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON  */
#line 401 "SemanticAnalyzer.y"
                                                                                {if(checkVariable((yyvsp[-6].Str),currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-6].Str));return 1;}insertInTable((yyvsp[-6].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2528 "y.tab.c"
    break;

  case 162: /* prattributes: prattributes COMMA factor  */
#line 408 "SemanticAnalyzer.y"
                                              {printlistArray[printindex++]=strdup((yyvsp[0].Str));}
#line 2534 "y.tab.c"
    break;

  case 164: /* scattributes: scattributes COMMA AMPERSAND factor  */
#line 410 "SemanticAnalyzer.y"
                                                        {scanlistArray[scanindex++]=strdup((yyvsp[0].Str));}
#line 2540 "y.tab.c"
    break;

  case 166: /* declarationListInt: IDENTIFIER EQUAL expressionStatement COMMA declarationListInt  */
#line 413 "SemanticAnalyzer.y"
                                                                                        { if(checkVariable((yyvsp[-4].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-4].Str));return 1;}if(strcmp((yyvsp[-2].Str),strdup("i"))!=0){printf("Type Mismatch");return 1;}insertInTable((yyvsp[-4].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2546 "y.tab.c"
    break;

  case 167: /* declarationListInt: IDENTIFIER COMMA declarationListInt  */
#line 414 "SemanticAnalyzer.y"
                                                      { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2552 "y.tab.c"
    break;

  case 168: /* declarationListInt: IDENTIFIER EQUAL expressionStatement  */
#line 415 "SemanticAnalyzer.y"
                                                       { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}if(strcmp((yyvsp[0].Str),strdup("i"))!=0){printf("Type Mismatch");return 1;}insertInTable((yyvsp[-2].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2558 "y.tab.c"
    break;

  case 169: /* declarationListInt: IDENTIFIER dimension  */
#line 416 "SemanticAnalyzer.y"
                                        {if(checkVariable((yyvsp[-1].Str),currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-1].Str));return 1;}insertInTable((yyvsp[-1].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2564 "y.tab.c"
    break;

  case 170: /* declarationListInt: IDENTIFIER  */
#line 417 "SemanticAnalyzer.y"
                             { if(checkVariable((yyvsp[0].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[0].Str));return 1;}insertInTable((yyvsp[0].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2570 "y.tab.c"
    break;

  case 171: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListFloat  */
#line 419 "SemanticAnalyzer.y"
                                                                                            { if(checkVariable((yyvsp[-4].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-4].Str));return 1;}if(strcmp((yyvsp[-2].Str),strdup("f"))!=0){printf("Type Mismatch");return 1;}insertInTable((yyvsp[-4].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2576 "y.tab.c"
    break;

  case 172: /* declarationListFloat: IDENTIFIER COMMA declarationListFloat  */
#line 420 "SemanticAnalyzer.y"
                                                        { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2582 "y.tab.c"
    break;

  case 173: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement  */
#line 421 "SemanticAnalyzer.y"
                                                       { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}if(strcmp((yyvsp[0].Str),strdup("f"))!=0){printf("Type Mismatch");return 1;}insertInTable((yyvsp[-2].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2588 "y.tab.c"
    break;

  case 174: /* declarationListFloat: IDENTIFIER dimension  */
#line 422 "SemanticAnalyzer.y"
                                        {if(checkVariable((yyvsp[-1].Str),currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-1].Str));return 1;}insertInTable((yyvsp[-1].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2594 "y.tab.c"
    break;

  case 175: /* declarationListFloat: IDENTIFIER  */
#line 423 "SemanticAnalyzer.y"
                             { if(checkVariable((yyvsp[0].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[0].Str));return 1;}insertInTable((yyvsp[0].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2600 "y.tab.c"
    break;

  case 176: /* declarationListChar: IDENTIFIER EQUAL CHARVAL COMMA declarationListChar  */
#line 425 "SemanticAnalyzer.y"
                                                                              {if(checkVariable((yyvsp[-4].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-4].Str));return 1;}insertInTable((yyvsp[-4].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2606 "y.tab.c"
    break;

  case 177: /* declarationListChar: IDENTIFIER COMMA declarationListChar  */
#line 426 "SemanticAnalyzer.y"
                                                       { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2612 "y.tab.c"
    break;

  case 178: /* declarationListChar: IDENTIFIER EQUAL expressionStatement  */
#line 427 "SemanticAnalyzer.y"
                                                       {if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2618 "y.tab.c"
    break;

  case 179: /* declarationListChar: IDENTIFIER dimension  */
#line 428 "SemanticAnalyzer.y"
                                       {if(checkVariable((yyvsp[-1].Str),currScope,true,true)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-1].Str));return 1;}insertInTable((yyvsp[-1].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2624 "y.tab.c"
    break;

  case 180: /* declarationListChar: IDENTIFIER  */
#line 429 "SemanticAnalyzer.y"
                             { if(checkVariable((yyvsp[0].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[0].Str));return 1;}insertInTable((yyvsp[0].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2630 "y.tab.c"
    break;

  case 181: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 431 "SemanticAnalyzer.y"
                                                                           {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2636 "y.tab.c"
    break;

  case 182: /* expressionStatement: logicalExpression  */
#line 432 "SemanticAnalyzer.y"
                                    {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2642 "y.tab.c"
    break;

  case 183: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 434 "SemanticAnalyzer.y"
                                                                 {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2648 "y.tab.c"
    break;

  case 184: /* logicalExpression: expression  */
#line 435 "SemanticAnalyzer.y"
                             {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2654 "y.tab.c"
    break;

  case 185: /* expression: relationalExpression EQUALS expression  */
#line 437 "SemanticAnalyzer.y"
                                                         {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2660 "y.tab.c"
    break;

  case 186: /* expression: relationalExpression NOTEQUAL expression  */
#line 438 "SemanticAnalyzer.y"
                                                           {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2666 "y.tab.c"
    break;

  case 187: /* expression: relationalExpression  */
#line 439 "SemanticAnalyzer.y"
                                       {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2672 "y.tab.c"
    break;

  case 188: /* relationalExpression: value GREATERTHAN relationalExpression  */
#line 441 "SemanticAnalyzer.y"
                                                                   {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2678 "y.tab.c"
    break;

  case 189: /* relationalExpression: value GREATERTHANEQUALTO relationalExpression  */
#line 442 "SemanticAnalyzer.y"
                                                                {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2684 "y.tab.c"
    break;

  case 190: /* relationalExpression: value LESSTHAN relationalExpression  */
#line 443 "SemanticAnalyzer.y"
                                                      {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2690 "y.tab.c"
    break;

  case 191: /* relationalExpression: value LESSTHANEQUALTO relationalExpression  */
#line 444 "SemanticAnalyzer.y"
                                                             {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2696 "y.tab.c"
    break;

  case 192: /* relationalExpression: value  */
#line 445 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2702 "y.tab.c"
    break;

  case 193: /* value: term ADD value  */
#line 447 "SemanticAnalyzer.y"
                            {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2708 "y.tab.c"
    break;

  case 194: /* value: term SUB value  */
#line 448 "SemanticAnalyzer.y"
                         {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2714 "y.tab.c"
    break;

  case 195: /* value: term  */
#line 449 "SemanticAnalyzer.y"
               {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2720 "y.tab.c"
    break;

  case 196: /* term: factor MULT term  */
#line 451 "SemanticAnalyzer.y"
                             {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2726 "y.tab.c"
    break;

  case 197: /* term: factor DIV term  */
#line 452 "SemanticAnalyzer.y"
                          {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2732 "y.tab.c"
    break;

  case 198: /* term: factor MOD term  */
#line 453 "SemanticAnalyzer.y"
                          {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2738 "y.tab.c"
    break;

  case 199: /* term: factor  */
#line 454 "SemanticAnalyzer.y"
                 {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2744 "y.tab.c"
    break;

  case 200: /* factor: IDENTIFIER  */
#line 456 "SemanticAnalyzer.y"
                         {int inst = checkVariableScope((yyvsp[0].Str),currScope,false,false); if(inst!=-1){(yyval.Str) = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",(yyvsp[0].Str));return 1;}}
#line 2750 "y.tab.c"
    break;

  case 201: /* factor: OPBRAC expressionStatement CLBRAC  */
#line 457 "SemanticAnalyzer.y"
                                            {(yyval.Str) = strdup((yyvsp[-1].Str));}
#line 2756 "y.tab.c"
    break;

  case 202: /* factor: LOGICALNOT expressionStatement  */
#line 458 "SemanticAnalyzer.y"
                                         {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2762 "y.tab.c"
    break;

  case 203: /* factor: CHARVAL  */
#line 459 "SemanticAnalyzer.y"
                  {(yyval.Str) = strdup("c");}
#line 2768 "y.tab.c"
    break;

  case 204: /* factor: INTVAL  */
#line 460 "SemanticAnalyzer.y"
                 {(yyval.Str) = strdup("i");}
#line 2774 "y.tab.c"
    break;

  case 205: /* factor: FLOATVAL  */
#line 461 "SemanticAnalyzer.y"
                   {(yyval.Str) = strdup("f");}
#line 2780 "y.tab.c"
    break;

  case 206: /* factor: IDENTIFIER OPBRAC CLBRAC  */
#line 462 "SemanticAnalyzer.y"
                                   {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0; int inst = getIdentifierIndex((yyvsp[-2].Str),false,true);if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){(yyval.Str) = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2786 "y.tab.c"
    break;

  case 207: /* $@43: %empty  */
#line 463 "SemanticAnalyzer.y"
                            {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2792 "y.tab.c"
    break;

  case 208: /* factor: IDENTIFIER OPBRAC $@43 argList CLBRAC  */
#line 463 "SemanticAnalyzer.y"
                                                                                                        {int inst = getIdentifierIndex((yyvsp[-4].Str),false,true); printArray(arglistArray,argindex); if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){(yyval.Str) = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2798 "y.tab.c"
    break;

  case 209: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE  */
#line 464 "SemanticAnalyzer.y"
                                             {int inst = checkVariableScope((yyvsp[-3].Str),currScope,true,false); if(inst!=-1){(yyval.Str) = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",(yyvsp[-3].Str));return 1;}}
#line 2804 "y.tab.c"
    break;

  case 210: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 465 "SemanticAnalyzer.y"
                                                                     {int inst = checkVariableScope((yyvsp[-6].Str),currScope,true,false); if(inst!=-1){(yyval.Str) = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",(yyvsp[-6].Str));return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2810 "y.tab.c"
    break;

  case 211: /* functionCall: IDENTIFIER OPBRAC CLBRAC SEMICOLON  */
#line 468 "SemanticAnalyzer.y"
                                                      {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0; int inst = getIdentifierIndex((yyvsp[-3].Str),false,true);if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){(yyval.Str) = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2816 "y.tab.c"
    break;

  case 212: /* functionCall: IDENTIFIER OPBRAC argList CLBRAC SEMICOLON  */
#line 469 "SemanticAnalyzer.y"
                                                               {int inst = getIdentifierIndex((yyvsp[-4].Str),false,true); if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){(yyval.Str) = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2822 "y.tab.c"
    break;

  case 213: /* argList: argList COMMA expressionStatement  */
#line 472 "SemanticAnalyzer.y"
                                                  {arglistArray[argindex++]=strdup((yyvsp[0].Str));}
#line 2828 "y.tab.c"
    break;

  case 214: /* argList: expressionStatement  */
#line 473 "SemanticAnalyzer.y"
                                      {arglistArray[argindex++]=strdup((yyvsp[0].Str));}
#line 2834 "y.tab.c"
    break;

  case 215: /* $@44: %empty  */
#line 475 "SemanticAnalyzer.y"
                  {pushNewScope(); memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2840 "y.tab.c"
    break;

  case 219: /* parameter: type IDENTIFIER  */
#line 479 "SemanticAnalyzer.y"
                                 {insertInTable((yyvsp[0].Str),(yyvsp[-1].Str),(yyvsp[-1].Str),currScope,0,NULL,NULL,0,false,false);}
#line 2846 "y.tab.c"
    break;

  case 220: /* type: INT  */
#line 481 "SemanticAnalyzer.y"
                {(yyval.Str) = strdup("i");instanceParamList[currentParamCount++]=strdup("i");}
#line 2852 "y.tab.c"
    break;

  case 221: /* type: FLOAT  */
#line 482 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup("f");instanceParamList[currentParamCount++]=strdup("f");}
#line 2858 "y.tab.c"
    break;

  case 222: /* type: CHAR  */
#line 483 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup("c");instanceParamList[currentParamCount++]=strdup("c");}
#line 2864 "y.tab.c"
    break;

  case 223: /* compoundStatements: OPCUR statementList CLCUR  */
#line 485 "SemanticAnalyzer.y"
                                                    {popScope();}
#line 2870 "y.tab.c"
    break;

  case 228: /* $@45: %empty  */
#line 491 "SemanticAnalyzer.y"
                                          {memset(printlistArray,'\0',sizeof(printlistArray));
		printindex = 0;}
#line 2877 "y.tab.c"
    break;

  case 230: /* $@46: %empty  */
#line 493 "SemanticAnalyzer.y"
                                          {memset(scanlistArray,'\0',sizeof(scanlistArray));
		scanindex = 0;}
#line 2884 "y.tab.c"
    break;

  case 233: /* returnDec: RETURN expressionStatement SEMICOLON  */
#line 497 "SemanticAnalyzer.y"
                                                      {if(strcmp(presentFunctionType,(yyvsp[-1].Str))==0){(yyval.Str) = strdup((yyvsp[-1].Str));}else{printf("INVALID RETURN");return 1;}}
#line 2890 "y.tab.c"
    break;

  case 234: /* returnDec: RETURN SEMICOLON  */
#line 498 "SemanticAnalyzer.y"
                                           {int inst = getPresentFunctionIndex(); (yyval.Str) = strdup(presentFunctionType);}
#line 2896 "y.tab.c"
    break;

  case 235: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 500 "SemanticAnalyzer.y"
                                         {int i = (yyvsp[-1].Int); if(i<=0){printf("Array size has to be  Positive\n"); return 1;}sizes[0] = (yyvsp[-1].Int);instDim++;}
#line 2902 "y.tab.c"
    break;

  case 236: /* dimension: BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 501 "SemanticAnalyzer.y"
                                                                    {int a = (yyvsp[-4].Int); int b = (yyvsp[-1].Int); if(a<=0||b<=0){printf("Array sizes has to be  Positive\n"); return 1;}sizes[0] = (yyvsp[-4].Int); sizes[1] = (yyvsp[-1].Int);instDim+=2;}
#line 2908 "y.tab.c"
    break;

  case 237: /* dimension: BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 502 "SemanticAnalyzer.y"
                                                             {int i = (yyvsp[-1].Int); if(i<=0){printf("Array sizes has to be  Positive\n"); return 1;}sizes[1] = (yyvsp[-1].Int);instDim+=2;}
#line 2914 "y.tab.c"
    break;


#line 2918 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 503 "SemanticAnalyzer.y"

      
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
      
      
