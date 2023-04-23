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
		char* presentFunctionType;
      
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
     

#line 267 "y.tab.c"

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
#line 196 "SemanticAnalyzer.y"

    		int Int;
    		float Float;
    		char Char;
    		char* Str;
    		struct data{
     
    		};
    	

#line 425 "y.tab.c"

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
  YYSYMBOL_ifStatement = 71,               /* ifStatement  */
  YYSYMBOL_72_7 = 72,                      /* $@7  */
  YYSYMBOL_73_8 = 73,                      /* $@8  */
  YYSYMBOL_74_9 = 74,                      /* $@9  */
  YYSYMBOL_75_10 = 75,                     /* $@10  */
  YYSYMBOL_ifContinuer = 76,               /* ifContinuer  */
  YYSYMBOL_ES = 77,                        /* ES  */
  YYSYMBOL_78_11 = 78,                     /* $@11  */
  YYSYMBOL_79_12 = 79,                     /* $@12  */
  YYSYMBOL_80_13 = 80,                     /* $@13  */
  YYSYMBOL_81_14 = 81,                     /* $@14  */
  YYSYMBOL_82_15 = 82,                     /* $@15  */
  YYSYMBOL_83_16 = 83,                     /* $@16  */
  YYSYMBOL_84_17 = 84,                     /* $@17  */
  YYSYMBOL_ifInLoopStatement = 85,         /* ifInLoopStatement  */
  YYSYMBOL_86_18 = 86,                     /* $@18  */
  YYSYMBOL_87_19 = 87,                     /* $@19  */
  YYSYMBOL_ifInLoopContinuer = 88,         /* ifInLoopContinuer  */
  YYSYMBOL_ESLoop = 89,                    /* ESLoop  */
  YYSYMBOL_90_20 = 90,                     /* $@20  */
  YYSYMBOL_91_21 = 91,                     /* $@21  */
  YYSYMBOL_92_22 = 92,                     /* $@22  */
  YYSYMBOL_93_23 = 93,                     /* $@23  */
  YYSYMBOL_94_24 = 94,                     /* $@24  */
  YYSYMBOL_95_25 = 95,                     /* $@25  */
  YYSYMBOL_96_26 = 96,                     /* $@26  */
  YYSYMBOL_switchStatement = 97,           /* switchStatement  */
  YYSYMBOL_98_27 = 98,                     /* $@27  */
  YYSYMBOL_99_28 = 99,                     /* $@28  */
  YYSYMBOL_caseStatements = 100,           /* caseStatements  */
  YYSYMBOL_caseStatementInt = 101,         /* caseStatementInt  */
  YYSYMBOL_102_29 = 102,                   /* $@29  */
  YYSYMBOL_103_30 = 103,                   /* $@30  */
  YYSYMBOL_caseInt = 104,                  /* caseInt  */
  YYSYMBOL_caseContinuer = 105,            /* caseContinuer  */
  YYSYMBOL_defaultStatement = 106,         /* defaultStatement  */
  YYSYMBOL_107_31 = 107,                   /* $@31  */
  YYSYMBOL_basicStatements = 108,          /* basicStatements  */
  YYSYMBOL_basicStatement = 109,           /* basicStatement  */
  YYSYMBOL_assignmentStatement = 110,      /* assignmentStatement  */
  YYSYMBOL_printer = 111,                  /* printer  */
  YYSYMBOL_scanner = 112,                  /* scanner  */
  YYSYMBOL_declarationStatement = 113,     /* declarationStatement  */
  YYSYMBOL_114_32 = 114,                   /* $@32  */
  YYSYMBOL_115_33 = 115,                   /* $@33  */
  YYSYMBOL_116_34 = 116,                   /* $@34  */
  YYSYMBOL_117_35 = 117,                   /* $@35  */
  YYSYMBOL_118_36 = 118,                   /* $@36  */
  YYSYMBOL_119_37 = 119,                   /* $@37  */
  YYSYMBOL_120_38 = 120,                   /* $@38  */
  YYSYMBOL_121_39 = 121,                   /* $@39  */
  YYSYMBOL_122_40 = 122,                   /* $@40  */
  YYSYMBOL_arrayValues = 123,              /* arrayValues  */
  YYSYMBOL_prattributes = 124,             /* prattributes  */
  YYSYMBOL_scattributes = 125,             /* scattributes  */
  YYSYMBOL_declarationListInt = 126,       /* declarationListInt  */
  YYSYMBOL_declarationListFloat = 127,     /* declarationListFloat  */
  YYSYMBOL_declarationListChar = 128,      /* declarationListChar  */
  YYSYMBOL_expressionStatement = 129,      /* expressionStatement  */
  YYSYMBOL_logicalExpression = 130,        /* logicalExpression  */
  YYSYMBOL_expression = 131,               /* expression  */
  YYSYMBOL_relationalExpression = 132,     /* relationalExpression  */
  YYSYMBOL_value = 133,                    /* value  */
  YYSYMBOL_term = 134,                     /* term  */
  YYSYMBOL_factor = 135,                   /* factor  */
  YYSYMBOL_136_41 = 136,                   /* $@41  */
  YYSYMBOL_functionCall = 137,             /* functionCall  */
  YYSYMBOL_argList = 138,                  /* argList  */
  YYSYMBOL_parameters = 139,               /* parameters  */
  YYSYMBOL_140_42 = 140,                   /* $@42  */
  YYSYMBOL_paramContinuer = 141,           /* paramContinuer  */
  YYSYMBOL_parameter = 142,                /* parameter  */
  YYSYMBOL_type = 143,                     /* type  */
  YYSYMBOL_compoundStatements = 144,       /* compoundStatements  */
  YYSYMBOL_statementList = 145,            /* statementList  */
  YYSYMBOL_146_43 = 146,                   /* $@43  */
  YYSYMBOL_returnDec = 147,                /* returnDec  */
  YYSYMBOL_dimension = 148                 /* dimension  */
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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   517

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  223
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  433

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
       0,   240,   240,   242,   243,   244,   245,   247,   248,   249,
     250,   251,   252,   253,   255,   255,   256,   257,   258,   259,
     259,   259,   261,   262,   262,   263,   263,   265,   266,   267,
     268,   269,   270,   271,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   285,   285,   286,   286,   287,   288,
     288,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     300,   300,   300,   301,   301,   301,   302,   303,   305,   305,
     305,   306,   306,   306,   307,   307,   307,   308,   308,   309,
     311,   311,   311,   312,   313,   315,   315,   315,   316,   316,
     316,   317,   317,   317,   318,   318,   319,   321,   321,   321,
     322,   322,   323,   323,   323,   323,   324,   325,   326,   327,
     328,   329,   330,   330,   331,   334,   335,   337,   338,   339,
     340,   342,   343,   345,   346,   347,   347,   348,   348,   349,
     349,   350,   350,   350,   351,   351,   351,   352,   352,   352,
     353,   354,   355,   356,   357,   358,   359,   363,   364,   365,
     366,   367,   368,   370,   371,   372,   373,   374,   376,   377,
     378,   379,   380,   382,   383,   384,   385,   386,   388,   389,
     391,   392,   394,   395,   396,   398,   399,   400,   401,   402,
     404,   405,   406,   408,   409,   410,   411,   413,   414,   415,
     416,   417,   418,   419,   420,   420,   421,   422,   425,   426,
     429,   430,   432,   432,   433,   434,   436,   438,   439,   440,
     442,   444,   444,   445,   446,   447,   448,   449,   450,   452,
     453,   455,   456,   457
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
  "inLoop", "ifStatement", "$@7", "$@8", "$@9", "$@10", "ifContinuer",
  "ES", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17",
  "ifInLoopStatement", "$@18", "$@19", "ifInLoopContinuer", "ESLoop",
  "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26",
  "switchStatement", "$@27", "$@28", "caseStatements", "caseStatementInt",
  "$@29", "$@30", "caseInt", "caseContinuer", "defaultStatement", "$@31",
  "basicStatements", "basicStatement", "assignmentStatement", "printer",
  "scanner", "declarationStatement", "$@32", "$@33", "$@34", "$@35",
  "$@36", "$@37", "$@38", "$@39", "$@40", "arrayValues", "prattributes",
  "scattributes", "declarationListInt", "declarationListFloat",
  "declarationListChar", "expressionStatement", "logicalExpression",
  "expression", "relationalExpression", "value", "term", "factor", "$@41",
  "functionCall", "argList", "parameters", "$@42", "paramContinuer",
  "parameter", "type", "compoundStatements", "statementList", "$@43",
  "returnDec", "dimension", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-346)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-138)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      48,   -18,    -6,     6,     5,    67,  -346,    48,    48,   105,
      79,   140,    81,   152,    97,   406,  -346,  -346,  -346,    69,
      92,    58,   406,  -346,  -346,    87,   102,    72,   116,  -346,
    -346,   118,   130,    99,   406,  -346,  -346,   406,   406,  -346,
    -346,  -346,   150,   133,   175,   199,   193,   228,   231,   234,
      75,  -346,  -346,  -346,   242,   119,   171,   191,   141,  -346,
    -346,  -346,   168,   179,   198,   166,  -346,  -346,   192,   218,
     223,   238,  -346,   240,   215,   221,  -346,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     258,   268,  -346,  -346,  -346,  -346,   293,   279,   285,   276,
     292,    69,   298,   310,   325,   181,    87,   318,  -346,   118,
    -346,  -346,   406,   315,  -346,  -346,  -346,  -346,  -346,  -346,
    -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,   319,   319,
     242,  -346,   320,    47,   313,  -346,   319,   319,   342,   337,
    -346,   319,   319,  -346,   346,   326,   327,   307,  -346,  -346,
    -346,  -346,   355,   358,   339,   338,  -346,  -346,  -346,   366,
    -346,  -346,   406,  -346,   340,   348,  -346,   351,   357,    91,
     359,   360,   -19,   307,  -346,  -346,  -346,   307,   399,  -346,
     307,   307,  -346,  -346,  -346,   362,  -346,  -346,   349,   380,
    -346,  -346,  -346,   361,   406,   368,  -346,   364,  -346,   388,
     391,   393,   271,  -346,  -346,  -346,  -346,  -346,  -346,   307,
    -346,  -346,  -346,  -346,   387,    73,  -346,  -346,  -346,  -346,
     406,   390,  -346,   407,   409,   412,   397,  -346,   398,  -346,
     400,   402,   406,  -346,   401,   416,   408,   403,   419,   420,
    -346,   439,  -346,   252,   415,   417,   442,  -346,    -2,  -346,
     407,   444,   418,   445,  -346,   252,  -346,  -346,  -346,  -346,
     406,   406,   421,  -346,  -346,  -346,   344,   433,  -346,  -346,
     409,  -346,  -346,   252,   252,   252,   227,   253,   269,   423,
     427,   386,   431,   452,   453,  -346,  -346,  -346,  -346,  -346,
    -346,   443,  -346,   446,  -346,   434,  -346,  -346,  -346,   -12,
    -346,  -346,  -346,    73,  -346,    73,  -346,   406,    11,   455,
     457,   386,   386,   436,   386,   386,   386,   386,   406,  -346,
    -346,   458,  -346,   125,  -346,   227,   447,  -346,   252,  -346,
    -346,   462,  -346,  -346,   344,   386,   386,  -346,  -346,  -346,
    -346,  -346,  -346,  -346,   448,  -346,   440,   267,   461,   463,
     433,  -346,   406,   252,  -346,   421,   386,  -346,  -346,  -346,
     449,   252,  -346,   451,   454,   252,   252,  -346,   456,  -346,
    -346,   450,   288,  -346,   465,   467,   459,  -346,  -346,   460,
     464,  -346,   386,   252,   252,   475,  -346,   252,  -346,  -346,
    -346,  -346,  -346,   252,  -346,   466,  -346,   469,   297,   468,
    -346,   470,    22,  -346,  -346,  -346,   469,   406,   472,  -346,
     344,  -346,   473,   406,   386,  -346,   471,   474,  -346,  -346,
     476,   477,  -346,   344,  -346,   386,  -346,  -346,   479,   478,
    -346,   479,  -346
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     5,   157,
       0,   167,     0,   162,     0,     0,     1,     4,     3,     0,
     202,     0,     0,   156,   140,     0,   202,     0,     0,   166,
     143,     0,   202,     0,     0,   161,   144,     0,     0,   190,
     191,   192,   187,     0,   169,   171,   174,   179,   182,   186,
     157,   154,   132,   125,     0,     0,     0,   155,   167,   164,
     138,   127,     0,     0,   165,   162,   159,   135,     0,     0,
     160,     0,   189,   194,     0,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   207,   209,   208,   203,   204,     0,     0,     0,
     221,     0,     0,     0,     0,   221,     0,     0,   129,     0,
     188,   193,     0,     0,   121,   168,   170,   172,   173,   175,
     176,   177,   178,   180,   181,   183,   184,   185,     0,     0,
       0,   206,     0,     0,     0,   153,     0,     0,     0,     0,
     163,     0,     0,   158,   201,     0,   196,   218,   133,   126,
     205,   223,     0,   148,     0,     0,   139,   128,   142,     0,
     136,   130,     0,   195,     0,     0,    14,     0,     0,     0,
       0,     0,   187,   218,    17,    16,    18,   218,   116,   119,
     218,   218,   118,   117,   120,     0,   215,   146,     0,     0,
     222,   141,   200,     0,     0,     0,    44,     0,   220,     0,
       0,     0,     0,   214,   213,   115,   120,   216,   217,   218,
     210,   147,   145,   197,     0,     0,    15,    21,    19,    20,
       0,     0,   219,   150,   152,   193,     0,   212,    63,    39,
       0,     0,    41,    34,     0,     0,     0,     0,     0,     0,
     198,     0,    60,     0,     0,     0,     0,    40,    49,    97,
     150,     0,     0,     0,   199,    10,    64,    11,    12,    13,
       0,     0,     0,    48,    46,    45,     0,   101,   149,   123,
     152,   124,    61,    10,    10,    10,    79,     0,     0,     0,
       0,    59,     0,     0,     0,    27,    50,    33,    18,    28,
      29,   114,   100,     0,   151,     0,     7,     8,     9,    77,
      67,    65,    66,     0,    35,     0,    37,     0,    25,     0,
       0,    27,    59,     0,    33,    18,    28,    29,     0,    30,
      31,     0,    98,     0,   103,    79,     0,    71,     0,    36,
      38,    43,    22,    23,     0,    30,    31,    53,    58,    47,
      56,    57,    54,    55,     0,   112,     0,     0,     0,     0,
     105,    62,     0,    10,    78,     0,    59,    26,    51,    52,
      63,    10,    99,     0,     0,    10,    10,   104,     0,    72,
      42,     0,    60,   113,     0,     0,   111,   109,   107,    74,
       0,    24,    59,    10,    10,     0,    68,     0,    73,    81,
     108,   106,   110,    10,    75,     0,    69,    79,    96,     0,
      76,     0,    94,    84,    82,    83,    79,     0,     0,    88,
       0,    70,     0,     0,    59,    95,     0,     0,    89,    80,
      91,     0,    85,     0,    90,    59,    92,    86,    96,     0,
      93,    96,    87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -346,  -346,   317,  -242,  -322,    16,  -346,  -346,  -346,  -346,
    -346,  -346,  -346,  -252,  -287,  -346,   126,  -346,  -346,  -346,
    -346,  -346,  -272,  -271,  -346,  -346,  -346,  -346,   170,  -345,
    -346,  -346,  -346,  -346,  -346,  -346,  -346,  -246,  -346,  -346,
    -346,  -198,  -346,  -346,  -346,  -346,  -346,  -346,  -346,  -210,
    -346,  -346,  -346,   146,  -346,  -346,  -346,  -309,  -346,  -346,
     321,  -143,     1,  -346,  -346,   194,  -346,  -346,  -346,  -346,
    -346,  -346,  -346,  -346,  -346,   309,   250,   232,   -16,   -20,
     -23,   -15,   435,   259,   173,   260,   213,  -346,  -346,  -100,
    -152,    96,  -346,   371,  -346,  -346,    90,  -122,  -346,  -346,
      14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,   376,   256,   311,   195,   216,   217,   218,
     356,   219,   334,   312,   232,   246,   280,   174,   220,   265,
     281,   266,   313,   175,   255,   295,   243,   276,   301,   302,
     393,   399,   353,   380,   387,   397,   328,   314,   382,   395,
     404,   405,   425,   429,   414,   421,   423,   428,   410,   176,
     267,   346,   291,   292,   293,   350,   324,   377,   322,   361,
     177,   316,   179,   180,   181,   182,    91,   103,   142,    52,
      90,    67,   107,    60,   102,   154,   237,   239,    10,    14,
      12,   183,    44,    45,    46,    47,    48,    49,   112,   317,
     145,    53,    54,    95,    96,    97,   148,   185,   209,   186,
      23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,     7,    59,    51,   178,   300,   354,    57,     7,     7,
     192,    66,   326,   272,   286,   263,   329,   202,   330,    70,
     287,    74,    71,    72,    15,    29,   327,    35,   332,     9,
     178,   296,   297,   298,   178,   178,   264,   178,   178,   337,
     338,    11,   340,   341,   342,   343,   408,   184,    15,   333,
     226,   203,   400,    13,   300,   204,   288,   378,   207,   208,
     409,   411,   115,   358,   359,   394,   178,    16,     1,     2,
       3,   315,    29,   184,   390,   391,   114,   184,   206,    35,
     184,   184,   357,   140,   371,   135,   152,   227,   287,   143,
     229,    19,   153,   230,   231,     4,    24,   144,    30,    55,
     258,   315,   315,    56,   315,   315,   315,   315,   198,   184,
     389,   369,   274,    62,    36,    33,    50,    63,    22,   373,
       4,    19,    61,   289,   288,   315,   315,    37,    68,  -131,
     274,   274,   274,    38,    58,    39,    40,    41,    42,  -137,
      69,    20,   418,   259,    56,    21,   315,   144,    22,    75,
      76,   396,   403,   427,   199,   275,    25,    25,   415,    98,
      64,   347,    99,   173,   287,    65,   290,  -134,    31,   348,
     349,   426,   315,   275,   275,   275,    26,   287,    77,   214,
      27,    33,    31,    28,    28,   258,    73,   144,    32,   173,
      74,   289,    33,   173,     8,    34,   173,   173,    79,    80,
     288,     8,     8,    78,   315,   234,    33,   101,    98,    34,
     274,   104,   100,   288,   106,   315,   233,   247,   274,   149,
     105,   134,   274,   274,   139,   173,   156,   157,   259,   108,
     430,   160,   161,   432,   290,    81,    82,    83,    84,   109,
     274,   274,    85,    86,   258,   277,   278,    87,    88,    89,
     274,   165,   299,   275,   119,   120,   121,   122,    98,   257,
     113,   275,    92,    93,    94,   275,   275,   289,     4,   303,
     304,   273,     1,     2,     3,   110,   165,   111,   166,   167,
     289,   168,   285,   275,   275,   305,   306,   259,    37,   273,
     273,   273,   331,   275,    38,   128,    39,    40,    41,   172,
     125,   126,   127,   344,   233,   129,   233,    37,   225,   130,
     290,   363,   364,    38,   133,    39,    40,    41,    42,   -80,
     -80,   401,   402,   290,    17,    18,   131,     1,     2,     3,
     132,   165,   134,   166,   167,   136,   168,   368,   117,   118,
     169,   170,   171,    37,   257,   123,   124,   137,   138,    38,
     285,    39,    40,    41,   172,   141,   146,   147,   155,   158,
     159,   151,   162,   163,     1,     2,     3,   164,   282,   273,
     166,   167,   187,   168,   188,   283,   284,   273,   189,   190,
      37,   273,   273,   191,   194,   193,    38,   196,    39,    40,
      41,   172,   412,   197,   153,   200,   201,   212,   417,   273,
     273,   210,   213,   257,   215,   222,     1,     2,     3,   273,
     282,   221,   166,   167,   223,   168,   224,   309,   310,     1,
       2,     3,    37,   236,   228,   238,   285,   235,    38,   240,
      39,    40,    41,   172,   241,    37,   242,   252,   248,   285,
     251,    38,    37,    39,    40,    41,   172,   244,    38,   245,
      39,    40,    41,    42,   249,   250,   254,   253,   260,   262,
     261,   269,   271,  -102,   308,   270,   307,   318,   279,   319,
     320,   321,   335,   325,   336,   339,   323,   345,   355,   362,
     365,   370,   366,   352,   383,   360,   384,   372,   374,   381,
     385,   375,   392,   379,   299,   351,   367,   211,   386,   205,
     268,   150,   294,   388,   402,   398,   407,   406,   413,   419,
     416,   420,     0,   116,   422,     0,   424,   431
};

static const yytype_int16 yycheck[] =
{
      15,     0,    25,    19,   147,   276,   328,    22,     7,     8,
     162,    31,    24,   255,   266,    17,   303,    36,   305,    34,
     266,    40,    37,    38,    43,    11,    38,    13,    17,    47,
     173,   273,   274,   275,   177,   178,    38,   180,   181,   311,
     312,    47,   314,   315,   316,   317,    24,   147,    43,    38,
     202,   173,   397,    47,   325,   177,   266,   366,   180,   181,
      38,   406,    77,   335,   336,   387,   209,     0,    20,    21,
      22,   281,    58,   173,   383,   384,    75,   177,   178,    65,
     180,   181,   334,   106,   356,   101,    39,   209,   334,   109,
      17,    16,    45,    20,    21,    47,    17,   112,    17,    41,
     243,   311,   312,    45,   314,   315,   316,   317,    17,   209,
     382,   353,   255,    41,    17,    40,    47,    45,    43,   361,
      47,    16,    26,   266,   334,   335,   336,    36,    32,    37,
     273,   274,   275,    42,    47,    44,    45,    46,    47,    37,
      41,    36,   414,   243,    45,    40,   356,   162,    43,    16,
      17,   393,   398,   425,   169,   255,    16,    16,   410,    40,
      44,    36,    43,   147,   410,    47,   266,    37,    16,    44,
      45,   423,   382,   273,   274,   275,    36,   423,     3,   194,
      40,    40,    16,    43,    43,   328,    36,   202,    36,   173,
      40,   334,    40,   177,     0,    43,   180,   181,     5,     6,
     410,     7,     8,     4,   414,   220,    40,    16,    40,    43,
     353,    43,    41,   423,    16,   425,   215,   232,   361,   129,
      41,    40,   365,   366,    43,   209,   136,   137,   328,    37,
     428,   141,   142,   431,   334,     7,     8,     9,    10,    16,
     383,   384,    11,    12,   387,   260,   261,    13,    14,    15,
     393,    24,    25,   353,    81,    82,    83,    84,    40,   243,
      45,   361,    20,    21,    22,   365,   366,   410,    47,    16,
      17,   255,    20,    21,    22,    37,    24,    37,    26,    27,
     423,    29,   266,   383,   384,    16,    17,   387,    36,   273,
     274,   275,   307,   393,    42,    37,    44,    45,    46,    47,
      87,    88,    89,   318,   303,    37,   305,    36,    37,    16,
     410,    44,    45,    42,    38,    44,    45,    46,    47,    31,
      32,    24,    25,   423,     7,     8,    47,    20,    21,    22,
      45,    24,    40,    26,    27,    37,    29,   352,    79,    80,
      33,    34,    35,    36,   328,    85,    86,    37,    23,    42,
     334,    44,    45,    46,    47,    37,    41,    38,    45,    17,
      23,    41,    16,    37,    20,    21,    22,    40,    24,   353,
      26,    27,    17,    29,    16,    31,    32,   361,    39,    41,
      36,   365,   366,    17,    36,    45,    42,    36,    44,    45,
      46,    47,   407,    36,    45,    36,    36,    17,   413,   383,
     384,    39,    41,   387,    36,    17,    20,    21,    22,   393,
      24,    47,    26,    27,    23,    29,    23,    31,    32,    20,
      21,    22,    36,    16,    37,    16,   410,    37,    42,    17,
      44,    45,    46,    47,    37,    36,    38,    18,    37,   423,
      37,    42,    36,    44,    45,    46,    47,    47,    42,    47,
      44,    45,    46,    47,    38,    47,    17,    37,    43,    17,
      43,    17,    17,    30,    37,    47,    43,    36,    47,    17,
      17,    28,    17,    39,    17,    39,    30,    19,    16,    39,
      19,   355,    19,    36,    19,    37,    19,    38,    37,    39,
      31,    37,    17,    37,    25,   325,   350,   188,    38,   178,
     250,   130,   270,    39,    25,    39,    36,    39,    36,    38,
      37,    37,    -1,    78,    38,    -1,    39,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    47,    49,    50,   110,   113,    47,
     126,    47,   128,    47,   127,    43,     0,    50,    50,    16,
      36,    40,    43,   148,    17,    16,    36,    40,    43,   148,
      17,    16,    36,    40,    43,   148,    17,    36,    42,    44,
      45,    46,    47,   129,   130,   131,   132,   133,   134,   135,
      47,   126,   117,   139,   140,    41,    45,   129,    47,   128,
     121,   139,    41,    45,    44,    47,   127,   119,   139,    41,
     129,   129,   129,    36,    40,    16,    17,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
     118,   114,    20,    21,    22,   141,   142,   143,    40,    43,
      41,    16,   122,   115,    43,    41,    16,   120,    37,    16,
      37,    37,   136,    45,   110,   129,   130,   131,   131,   132,
     132,   132,   132,   133,   133,   134,   134,   134,    37,    37,
      16,    47,    45,    38,    40,   126,    37,    37,    23,    43,
     128,    37,   116,   127,   129,   138,    41,    38,   144,   144,
     141,    41,    39,    45,   123,    45,   144,   144,    17,    23,
     144,   144,    16,    37,    40,    24,    26,    27,    29,    33,
      34,    35,    47,    53,    65,    71,    97,   108,   109,   110,
     111,   112,   113,   129,   137,   145,   147,    17,    16,    39,
      41,    17,   138,    45,    36,    54,    36,    36,    17,   129,
      36,    36,    36,   145,   145,   108,   137,   145,   145,   146,
      39,   123,    17,    41,   129,    36,    55,    56,    57,    59,
      66,    47,    17,    23,    23,    37,   138,   145,    37,    17,
      20,    21,    62,   110,   129,    37,    16,   124,    16,   125,
      17,    37,    38,    74,    47,    47,    63,   129,    37,    38,
      47,    37,    18,    37,    17,    72,    52,    53,   109,   137,
      43,    43,    17,    17,    38,    67,    69,    98,   124,    17,
      47,    17,    51,    53,   109,   137,    75,   129,   129,    47,
      64,    68,    24,    31,    32,    53,    61,    85,    97,   109,
     137,   100,   101,   102,   125,    73,    51,    51,    51,    25,
      71,    76,    77,    16,    17,    16,    17,    43,    37,    31,
      32,    53,    61,    70,    85,    97,   109,   137,    36,    17,
      17,    28,   106,    30,   104,    39,    24,    38,    84,    62,
      62,   129,    17,    38,    60,    17,    17,    70,    70,    39,
      70,    70,    70,    70,   129,    19,    99,    36,    44,    45,
     103,    76,    36,    80,    52,    16,    58,    61,    70,    70,
      37,   107,    39,    44,    45,    19,    19,   101,   129,    51,
      64,    70,    38,    51,    37,    37,    51,   105,   105,    37,
      81,    39,    86,    19,    19,    31,    38,    82,    39,    70,
     105,   105,    17,    78,    52,    87,    51,    83,    39,    79,
      77,    24,    25,    85,    88,    89,    39,    36,    24,    38,
      96,    77,   129,    36,    92,    61,    37,   129,    70,    38,
      37,    93,    38,    94,    39,    90,    61,    70,    95,    91,
      89,    39,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    50,    51,    51,    51,
      51,    52,    52,    52,    54,    53,    53,    53,    53,    55,
      55,    55,    56,    58,    57,    60,    59,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    66,    65,    68,    67,    67,    69,
      67,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      72,    73,    71,    74,    75,    71,    76,    76,    78,    79,
      77,    80,    81,    77,    82,    83,    77,    84,    77,    77,
      86,    87,    85,    88,    88,    90,    91,    89,    92,    93,
      89,    94,    95,    89,    96,    89,    89,    98,    99,    97,
     100,   100,   102,   103,   101,   101,   104,   104,   104,   104,
     105,   105,   107,   106,   106,   108,   108,   109,   109,   109,
     109,   110,   110,   111,   112,   114,   113,   115,   113,   116,
     113,   117,   118,   113,   119,   120,   113,   121,   122,   113,
     113,   113,   113,   113,   113,   113,   113,   123,   123,   124,
     124,   125,   125,   126,   126,   126,   126,   126,   127,   127,
     127,   127,   127,   128,   128,   128,   128,   128,   129,   129,
     130,   130,   131,   131,   131,   132,   132,   132,   132,   132,
     133,   133,   133,   134,   134,   134,   134,   135,   135,   135,
     135,   135,   135,   135,   136,   135,   135,   135,   137,   137,
     138,   138,   140,   139,   141,   141,   142,   143,   143,   143,
     144,   146,   145,   145,   145,   145,   145,   145,   145,   147,
     147,   148,   148,   148
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     2,     2,     2,
       0,     1,     1,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     7,     0,    10,     0,     8,     1,     1,     1,
       2,     2,     1,     1,     1,     5,     6,     5,     6,     1,
       1,     0,     5,     3,     0,     6,     0,     4,     1,     0,
       2,     3,     3,     2,     2,     2,     2,     2,     2,     0,
       0,     0,    10,     0,     0,     8,     1,     1,     0,     0,
      11,     0,     0,     6,     0,     0,     9,     0,     3,     0,
       0,     0,    10,     1,     1,     0,     0,    11,     0,     0,
       6,     0,     0,     9,     0,     3,     0,     0,     0,    10,
       1,     0,     0,     0,     4,     0,     6,     4,     6,     4,
       3,     1,     0,     4,     0,     2,     1,     1,     1,     1,
       1,     5,     4,     6,     6,     0,     7,     0,     7,     0,
       7,     0,     0,     7,     0,     0,     7,     0,     0,     7,
       3,     8,     7,     3,     3,     9,     8,     3,     1,     3,
       0,     4,     0,     5,     3,     3,     2,     1,     5,     3,
       3,     2,     1,     5,     3,     3,     2,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     1,     3,     2,
       1,     1,     1,     3,     0,     5,     4,     7,     4,     5,
       3,     1,     0,     2,     1,     3,     2,     1,     1,     1,
       3,     0,     3,     2,     2,     1,     2,     2,     0,     3,
       2,     3,     6,     5
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
#line 240 "SemanticAnalyzer.y"
                            {}
#line 1885 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 242 "SemanticAnalyzer.y"
                                                             {}
#line 1891 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 244 "SemanticAnalyzer.y"
                                                        {}
#line 1897 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 247 "SemanticAnalyzer.y"
                                              {}
#line 1903 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 248 "SemanticAnalyzer.y"
                                               {}
#line 1909 "y.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 255 "SemanticAnalyzer.y"
                            {pushNewScope();}
#line 1915 "y.tab.c"
    break;

  case 22: /* forLoop1: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON  */
#line 261 "SemanticAnalyzer.y"
                                                                                                          {popScope(); }
#line 1921 "y.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 262 "SemanticAnalyzer.y"
                                                                                                   {pushNewScope();}
#line 1927 "y.tab.c"
    break;

  case 24: /* forLoop2: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR $@2 inLoop CLCUR  */
#line 262 "SemanticAnalyzer.y"
                                                                                                                                  {popScope(); popScope(); }
#line 1933 "y.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 263 "SemanticAnalyzer.y"
                                                                                              {pushNewScope();}
#line 1939 "y.tab.c"
    break;

  case 26: /* forLoop3: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC $@3 singleLoopStatement  */
#line 263 "SemanticAnalyzer.y"
                                                                                                                                    {popScope(); popScope(); }
#line 1945 "y.tab.c"
    break;

  case 35: /* forAssignStatement: INT IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 274 "SemanticAnalyzer.y"
                                                                                             {}
#line 1951 "y.tab.c"
    break;

  case 44: /* $@4: %empty  */
#line 285 "SemanticAnalyzer.y"
                             {pushNewScope();}
#line 1957 "y.tab.c"
    break;

  case 46: /* $@5: %empty  */
#line 286 "SemanticAnalyzer.y"
                         {pushNewScope();}
#line 1963 "y.tab.c"
    break;

  case 47: /* whileSuffix: OPCUR $@5 inLoop CLCUR  */
#line 286 "SemanticAnalyzer.y"
                                                       { popScope(); popScope(); }
#line 1969 "y.tab.c"
    break;

  case 48: /* whileSuffix: SEMICOLON  */
#line 287 "SemanticAnalyzer.y"
                              {popScope(); printf("\nWHILE SEMICOLON \n");}
#line 1975 "y.tab.c"
    break;

  case 49: /* $@6: %empty  */
#line 288 "SemanticAnalyzer.y"
                    {pushNewScope();}
#line 1981 "y.tab.c"
    break;

  case 50: /* whileSuffix: $@6 singleLoopStatement  */
#line 288 "SemanticAnalyzer.y"
                                                          { popScope(); popScope();}
#line 1987 "y.tab.c"
    break;

  case 51: /* inLoop: BREAK SEMICOLON inLoop  */
#line 290 "SemanticAnalyzer.y"
                                     {}
#line 1993 "y.tab.c"
    break;

  case 52: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 291 "SemanticAnalyzer.y"
                                            {}
#line 1999 "y.tab.c"
    break;

  case 53: /* inLoop: specialStatement inLoop  */
#line 292 "SemanticAnalyzer.y"
                                          {}
#line 2005 "y.tab.c"
    break;

  case 54: /* inLoop: basicStatement inLoop  */
#line 293 "SemanticAnalyzer.y"
                                        {}
#line 2011 "y.tab.c"
    break;

  case 55: /* inLoop: functionCall inLoop  */
#line 294 "SemanticAnalyzer.y"
                                     {}
#line 2017 "y.tab.c"
    break;

  case 56: /* inLoop: ifInLoopStatement inLoop  */
#line 295 "SemanticAnalyzer.y"
                                           {}
#line 2023 "y.tab.c"
    break;

  case 57: /* inLoop: switchStatement inLoop  */
#line 296 "SemanticAnalyzer.y"
                                         {}
#line 2029 "y.tab.c"
    break;

  case 58: /* inLoop: singleLoopStatement inLoop  */
#line 297 "SemanticAnalyzer.y"
                                             {}
#line 2035 "y.tab.c"
    break;

  case 60: /* $@7: %empty  */
#line 300 "SemanticAnalyzer.y"
                                                              {pushNewScope();}
#line 2041 "y.tab.c"
    break;

  case 61: /* $@8: %empty  */
#line 300 "SemanticAnalyzer.y"
                                                                                           {popScope();}
#line 2047 "y.tab.c"
    break;

  case 63: /* $@9: %empty  */
#line 301 "SemanticAnalyzer.y"
                                                               {pushNewScope();}
#line 2053 "y.tab.c"
    break;

  case 64: /* $@10: %empty  */
#line 301 "SemanticAnalyzer.y"
                                                                                                 {popScope();}
#line 2059 "y.tab.c"
    break;

  case 68: /* $@11: %empty  */
#line 305 "SemanticAnalyzer.y"
                                                          {pushNewScope();}
#line 2065 "y.tab.c"
    break;

  case 69: /* $@12: %empty  */
#line 305 "SemanticAnalyzer.y"
                                                                                       {popScope();}
#line 2071 "y.tab.c"
    break;

  case 71: /* $@13: %empty  */
#line 306 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 2077 "y.tab.c"
    break;

  case 72: /* $@14: %empty  */
#line 306 "SemanticAnalyzer.y"
                                                  {popScope();}
#line 2083 "y.tab.c"
    break;

  case 74: /* $@15: %empty  */
#line 307 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 2089 "y.tab.c"
    break;

  case 75: /* $@16: %empty  */
#line 307 "SemanticAnalyzer.y"
                                                                                     {popScope();}
#line 2095 "y.tab.c"
    break;

  case 77: /* $@17: %empty  */
#line 308 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 2101 "y.tab.c"
    break;

  case 78: /* ES: ELSE $@17 singleStatement  */
#line 308 "SemanticAnalyzer.y"
                                                 {popScope();}
#line 2107 "y.tab.c"
    break;

  case 80: /* $@18: %empty  */
#line 311 "SemanticAnalyzer.y"
                                                                    {pushNewScope();}
#line 2113 "y.tab.c"
    break;

  case 81: /* $@19: %empty  */
#line 311 "SemanticAnalyzer.y"
                                                                                             {popScope;}
#line 2119 "y.tab.c"
    break;

  case 85: /* $@20: %empty  */
#line 315 "SemanticAnalyzer.y"
                                                              {pushNewScope();}
#line 2125 "y.tab.c"
    break;

  case 86: /* $@21: %empty  */
#line 315 "SemanticAnalyzer.y"
                                                                                       {popScope();}
#line 2131 "y.tab.c"
    break;

  case 88: /* $@22: %empty  */
#line 316 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 2137 "y.tab.c"
    break;

  case 89: /* $@23: %empty  */
#line 316 "SemanticAnalyzer.y"
                                              {popScope();}
#line 2143 "y.tab.c"
    break;

  case 91: /* $@24: %empty  */
#line 317 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 2149 "y.tab.c"
    break;

  case 92: /* $@25: %empty  */
#line 317 "SemanticAnalyzer.y"
                                                                                         {popScope();}
#line 2155 "y.tab.c"
    break;

  case 94: /* $@26: %empty  */
#line 318 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 2161 "y.tab.c"
    break;

  case 95: /* ESLoop: ELSE $@26 singleLoopStatement  */
#line 318 "SemanticAnalyzer.y"
                                                     {popScope();}
#line 2167 "y.tab.c"
    break;

  case 97: /* $@27: %empty  */
#line 321 "SemanticAnalyzer.y"
                                                             {pushNewScope();}
#line 2173 "y.tab.c"
    break;

  case 98: /* $@28: %empty  */
#line 321 "SemanticAnalyzer.y"
                                                                                                               {popScope();}
#line 2179 "y.tab.c"
    break;

  case 99: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR $@27 caseStatements defaultStatement $@28 CLCUR  */
#line 321 "SemanticAnalyzer.y"
                                                                                                                                   {}
#line 2185 "y.tab.c"
    break;

  case 101: /* caseStatements: %empty  */
#line 322 "SemanticAnalyzer.y"
                                         {}
#line 2191 "y.tab.c"
    break;

  case 102: /* $@29: %empty  */
#line 323 "SemanticAnalyzer.y"
                        {pushNewScope();}
#line 2197 "y.tab.c"
    break;

  case 103: /* $@30: %empty  */
#line 323 "SemanticAnalyzer.y"
                                                  {pushNewScope();}
#line 2203 "y.tab.c"
    break;

  case 105: /* caseStatementInt: %empty  */
#line 323 "SemanticAnalyzer.y"
                                                                                       {}
#line 2209 "y.tab.c"
    break;

  case 107: /* caseInt: CASE INTVAL COLON caseContinuer  */
#line 325 "SemanticAnalyzer.y"
                                                  {}
#line 2215 "y.tab.c"
    break;

  case 112: /* $@31: %empty  */
#line 330 "SemanticAnalyzer.y"
                                      {pushNewScope();}
#line 2221 "y.tab.c"
    break;

  case 113: /* defaultStatement: DEFAULT COLON $@31 statements  */
#line 330 "SemanticAnalyzer.y"
                                                                   {popScope();}
#line 2227 "y.tab.c"
    break;

  case 114: /* defaultStatement: %empty  */
#line 331 "SemanticAnalyzer.y"
                                          {}
#line 2233 "y.tab.c"
    break;

  case 117: /* basicStatement: expressionStatement  */
#line 337 "SemanticAnalyzer.y"
                                          {}
#line 2239 "y.tab.c"
    break;

  case 118: /* basicStatement: declarationStatement  */
#line 338 "SemanticAnalyzer.y"
                                       {}
#line 2245 "y.tab.c"
    break;

  case 119: /* basicStatement: assignmentStatement  */
#line 339 "SemanticAnalyzer.y"
                                        {}
#line 2251 "y.tab.c"
    break;

  case 121: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 342 "SemanticAnalyzer.y"
                                                                                          {}
#line 2257 "y.tab.c"
    break;

  case 122: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 343 "SemanticAnalyzer.y"
                                                                 {}
#line 2263 "y.tab.c"
    break;

  case 125: /* $@32: %empty  */
#line 347 "SemanticAnalyzer.y"
                                                             {presentFunctionType = strdup("i");}
#line 2269 "y.tab.c"
    break;

  case 126: /* declarationStatement: INT IDENTIFIER OPBRAC parameters $@32 CLBRAC compoundStatements  */
#line 347 "SemanticAnalyzer.y"
                                                                                                                             {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);}else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;}memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2275 "y.tab.c"
    break;

  case 127: /* $@33: %empty  */
#line 348 "SemanticAnalyzer.y"
                                                      {presentFunctionType = strdup("c");}
#line 2281 "y.tab.c"
    break;

  case 128: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters $@33 CLBRAC compoundStatements  */
#line 348 "SemanticAnalyzer.y"
                                                                                                                     {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst ==-1){insertInTable((yyvsp[-5].Str),strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2287 "y.tab.c"
    break;

  case 129: /* $@34: %empty  */
#line 349 "SemanticAnalyzer.y"
                                                             {presentFunctionType = strdup("f");}
#line 2293 "y.tab.c"
    break;

  case 130: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC $@34 compoundStatements  */
#line 349 "SemanticAnalyzer.y"
                                                                                                                     {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2299 "y.tab.c"
    break;

  case 131: /* $@35: %empty  */
#line 350 "SemanticAnalyzer.y"
                                         {pushNewScope();}
#line 2305 "y.tab.c"
    break;

  case 132: /* $@36: %empty  */
#line 350 "SemanticAnalyzer.y"
                                                          {presentFunctionType = strdup("i");}
#line 2311 "y.tab.c"
    break;

  case 133: /* declarationStatement: INT IDENTIFIER OPBRAC $@35 $@36 CLBRAC compoundStatements  */
#line 350 "SemanticAnalyzer.y"
                                                                                                                          {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2317 "y.tab.c"
    break;

  case 134: /* $@37: %empty  */
#line 351 "SemanticAnalyzer.y"
                                           {pushNewScope();}
#line 2323 "y.tab.c"
    break;

  case 135: /* $@38: %empty  */
#line 351 "SemanticAnalyzer.y"
                                                            {presentFunctionType = strdup("f");}
#line 2329 "y.tab.c"
    break;

  case 136: /* declarationStatement: FLOAT IDENTIFIER OPBRAC $@37 $@38 CLBRAC compoundStatements  */
#line 351 "SemanticAnalyzer.y"
                                                                                                                             {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2335 "y.tab.c"
    break;

  case 137: /* $@39: %empty  */
#line 352 "SemanticAnalyzer.y"
                                          {pushNewScope();}
#line 2341 "y.tab.c"
    break;

  case 138: /* $@40: %empty  */
#line 352 "SemanticAnalyzer.y"
                                                           {presentFunctionType = strdup("c");}
#line 2347 "y.tab.c"
    break;

  case 139: /* declarationStatement: CHAR IDENTIFIER OPBRAC $@39 $@40 CLBRAC compoundStatements  */
#line 352 "SemanticAnalyzer.y"
                                                                                                                            {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2353 "y.tab.c"
    break;

  case 140: /* declarationStatement: INT declarationListInt SEMICOLON  */
#line 353 "SemanticAnalyzer.y"
                                                   {}
#line 2359 "y.tab.c"
    break;

  case 145: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON  */
#line 358 "SemanticAnalyzer.y"
                                                                                          {}
#line 2365 "y.tab.c"
    break;

  case 146: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON  */
#line 359 "SemanticAnalyzer.y"
                                                                              {}
#line 2371 "y.tab.c"
    break;

  case 153: /* declarationListInt: IDENTIFIER EQUAL expressionStatement COMMA declarationListInt  */
#line 370 "SemanticAnalyzer.y"
                                                                                        {printf("DSL1..\n");}
#line 2377 "y.tab.c"
    break;

  case 154: /* declarationListInt: IDENTIFIER COMMA declarationListInt  */
#line 371 "SemanticAnalyzer.y"
                                                      { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2383 "y.tab.c"
    break;

  case 155: /* declarationListInt: IDENTIFIER EQUAL expressionStatement  */
#line 372 "SemanticAnalyzer.y"
                                                       {}
#line 2389 "y.tab.c"
    break;

  case 156: /* declarationListInt: IDENTIFIER dimension  */
#line 373 "SemanticAnalyzer.y"
                                        {if(checkVariable((yyvsp[-1].Str),currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-1].Str));return 1;}insertInTable((yyvsp[-1].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2395 "y.tab.c"
    break;

  case 157: /* declarationListInt: IDENTIFIER  */
#line 374 "SemanticAnalyzer.y"
                             { if(checkVariable((yyvsp[0].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[0].Str));return 1;}insertInTable((yyvsp[0].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2401 "y.tab.c"
    break;

  case 158: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListFloat  */
#line 376 "SemanticAnalyzer.y"
                                                                                            {printf("DSL1..\n");}
#line 2407 "y.tab.c"
    break;

  case 159: /* declarationListFloat: IDENTIFIER COMMA declarationListFloat  */
#line 377 "SemanticAnalyzer.y"
                                                        { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2413 "y.tab.c"
    break;

  case 160: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement  */
#line 378 "SemanticAnalyzer.y"
                                                       {printf("DSL3..\n");}
#line 2419 "y.tab.c"
    break;

  case 161: /* declarationListFloat: IDENTIFIER dimension  */
#line 379 "SemanticAnalyzer.y"
                                        {if(checkVariable((yyvsp[-1].Str),currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-1].Str));return 1;}insertInTable((yyvsp[-1].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2425 "y.tab.c"
    break;

  case 162: /* declarationListFloat: IDENTIFIER  */
#line 380 "SemanticAnalyzer.y"
                             { if(checkVariable((yyvsp[0].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[0].Str));return 1;}insertInTable((yyvsp[0].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2431 "y.tab.c"
    break;

  case 164: /* declarationListChar: IDENTIFIER COMMA declarationListChar  */
#line 383 "SemanticAnalyzer.y"
                                                       { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2437 "y.tab.c"
    break;

  case 166: /* declarationListChar: IDENTIFIER dimension  */
#line 385 "SemanticAnalyzer.y"
                                       {if(checkVariable((yyvsp[-1].Str),currScope,true,true)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-1].Str));return 1;}insertInTable((yyvsp[-1].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2443 "y.tab.c"
    break;

  case 167: /* declarationListChar: IDENTIFIER  */
#line 386 "SemanticAnalyzer.y"
                             { if(checkVariable((yyvsp[0].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[0].Str));return 1;}insertInTable((yyvsp[0].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2449 "y.tab.c"
    break;

  case 168: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 388 "SemanticAnalyzer.y"
                                                                           {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2455 "y.tab.c"
    break;

  case 169: /* expressionStatement: logicalExpression  */
#line 389 "SemanticAnalyzer.y"
                                    {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2461 "y.tab.c"
    break;

  case 170: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 391 "SemanticAnalyzer.y"
                                                                 {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2467 "y.tab.c"
    break;

  case 171: /* logicalExpression: expression  */
#line 392 "SemanticAnalyzer.y"
                             {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2473 "y.tab.c"
    break;

  case 172: /* expression: relationalExpression EQUALS expression  */
#line 394 "SemanticAnalyzer.y"
                                                         {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2479 "y.tab.c"
    break;

  case 173: /* expression: relationalExpression NOTEQUAL expression  */
#line 395 "SemanticAnalyzer.y"
                                                           {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2485 "y.tab.c"
    break;

  case 174: /* expression: relationalExpression  */
#line 396 "SemanticAnalyzer.y"
                                       {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2491 "y.tab.c"
    break;

  case 175: /* relationalExpression: value GREATERTHAN relationalExpression  */
#line 398 "SemanticAnalyzer.y"
                                                                   {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2497 "y.tab.c"
    break;

  case 176: /* relationalExpression: value GREATERTHANEQUALTO relationalExpression  */
#line 399 "SemanticAnalyzer.y"
                                                                {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2503 "y.tab.c"
    break;

  case 177: /* relationalExpression: value LESSTHAN relationalExpression  */
#line 400 "SemanticAnalyzer.y"
                                                      {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2509 "y.tab.c"
    break;

  case 178: /* relationalExpression: value LESSTHANEQUALTO relationalExpression  */
#line 401 "SemanticAnalyzer.y"
                                                             {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2515 "y.tab.c"
    break;

  case 179: /* relationalExpression: value  */
#line 402 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2521 "y.tab.c"
    break;

  case 180: /* value: term ADD value  */
#line 404 "SemanticAnalyzer.y"
                            {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2527 "y.tab.c"
    break;

  case 181: /* value: term SUB value  */
#line 405 "SemanticAnalyzer.y"
                         {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2533 "y.tab.c"
    break;

  case 182: /* value: term  */
#line 406 "SemanticAnalyzer.y"
               {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2539 "y.tab.c"
    break;

  case 183: /* term: factor MULT term  */
#line 408 "SemanticAnalyzer.y"
                             {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2545 "y.tab.c"
    break;

  case 184: /* term: factor DIV term  */
#line 409 "SemanticAnalyzer.y"
                          {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2551 "y.tab.c"
    break;

  case 185: /* term: factor MOD term  */
#line 410 "SemanticAnalyzer.y"
                          {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2557 "y.tab.c"
    break;

  case 186: /* term: factor  */
#line 411 "SemanticAnalyzer.y"
                 {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2563 "y.tab.c"
    break;

  case 187: /* factor: IDENTIFIER  */
#line 413 "SemanticAnalyzer.y"
                         {int inst = checkVariableScope((yyvsp[0].Str),currScope,false,false); if(inst!=-1){(yyval.Str) = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",(yyvsp[0].Str));return 1;}}
#line 2569 "y.tab.c"
    break;

  case 188: /* factor: OPBRAC expressionStatement CLBRAC  */
#line 414 "SemanticAnalyzer.y"
                                            {(yyval.Str) = strdup((yyvsp[-1].Str));}
#line 2575 "y.tab.c"
    break;

  case 189: /* factor: LOGICALNOT expressionStatement  */
#line 415 "SemanticAnalyzer.y"
                                         {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2581 "y.tab.c"
    break;

  case 190: /* factor: CHARVAL  */
#line 416 "SemanticAnalyzer.y"
                  {(yyval.Str) = strdup("c");}
#line 2587 "y.tab.c"
    break;

  case 191: /* factor: INTVAL  */
#line 417 "SemanticAnalyzer.y"
                 {(yyval.Str) = strdup("i");printf("INT VALS.. %d\n",yylval);}
#line 2593 "y.tab.c"
    break;

  case 192: /* factor: FLOATVAL  */
#line 418 "SemanticAnalyzer.y"
                   {(yyval.Str) = strdup("f");}
#line 2599 "y.tab.c"
    break;

  case 193: /* factor: IDENTIFIER OPBRAC CLBRAC  */
#line 419 "SemanticAnalyzer.y"
                                   {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0; int inst = getIdentifierIndex((yyvsp[-2].Str),false,true);if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){(yyval.Str) = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}}
#line 2605 "y.tab.c"
    break;

  case 194: /* $@41: %empty  */
#line 420 "SemanticAnalyzer.y"
                            {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2611 "y.tab.c"
    break;

  case 195: /* factor: IDENTIFIER OPBRAC $@41 argList CLBRAC  */
#line 420 "SemanticAnalyzer.y"
                                                                                                        {int inst = getIdentifierIndex((yyvsp[-4].Str),false,true); if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){(yyval.Str) = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}}
#line 2617 "y.tab.c"
    break;

  case 196: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE  */
#line 421 "SemanticAnalyzer.y"
                                             {int inst = checkVariableScope((yyvsp[-3].Str),currScope,true,false); if(inst!=-1){(yyval.Str) = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",(yyvsp[-3].Str));return 1;}}
#line 2623 "y.tab.c"
    break;

  case 197: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 422 "SemanticAnalyzer.y"
                                                                     {int inst = checkVariableScope((yyvsp[-6].Str),currScope,true,false); if(inst!=-1){(yyval.Str) = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",(yyvsp[-6].Str));return 1;}}
#line 2629 "y.tab.c"
    break;

  case 198: /* functionCall: IDENTIFIER OPBRAC CLBRAC SEMICOLON  */
#line 425 "SemanticAnalyzer.y"
                                                      {}
#line 2635 "y.tab.c"
    break;

  case 199: /* functionCall: IDENTIFIER OPBRAC argList CLBRAC SEMICOLON  */
#line 426 "SemanticAnalyzer.y"
                                                              {}
#line 2641 "y.tab.c"
    break;

  case 200: /* argList: expressionStatement COMMA argList  */
#line 429 "SemanticAnalyzer.y"
                                                 {arglistArray[argindex++]=strdup((yyvsp[-2].Str));}
#line 2647 "y.tab.c"
    break;

  case 201: /* argList: expressionStatement  */
#line 430 "SemanticAnalyzer.y"
                                      {arglistArray[argindex++]=strdup((yyvsp[0].Str));}
#line 2653 "y.tab.c"
    break;

  case 202: /* $@42: %empty  */
#line 432 "SemanticAnalyzer.y"
                  {pushNewScope(); memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2659 "y.tab.c"
    break;

  case 205: /* paramContinuer: parameter COMMA paramContinuer  */
#line 434 "SemanticAnalyzer.y"
                                                                  {printf("FUNCTION params\n");}
#line 2665 "y.tab.c"
    break;

  case 206: /* parameter: type IDENTIFIER  */
#line 436 "SemanticAnalyzer.y"
                                 {printf("FUNCTION param\n");insertInTable((yyvsp[0].Str),(yyvsp[-1].Str),(yyvsp[-1].Str),currScope,0,NULL,NULL,0,false,false);}
#line 2671 "y.tab.c"
    break;

  case 207: /* type: INT  */
#line 438 "SemanticAnalyzer.y"
                {(yyval.Str) = strdup("i");instanceParamList[currentParamCount++]=strdup("i");}
#line 2677 "y.tab.c"
    break;

  case 208: /* type: FLOAT  */
#line 439 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup("f");instanceParamList[currentParamCount++]=strdup("f");}
#line 2683 "y.tab.c"
    break;

  case 209: /* type: CHAR  */
#line 440 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup("c");instanceParamList[currentParamCount++]=strdup("c");}
#line 2689 "y.tab.c"
    break;

  case 210: /* compoundStatements: OPCUR statementList CLCUR  */
#line 442 "SemanticAnalyzer.y"
                                                    {popScope();printf("FUNCTION statements\n");}
#line 2695 "y.tab.c"
    break;

  case 211: /* $@43: %empty  */
#line 444 "SemanticAnalyzer.y"
                                  {printf("checked if function call");}
#line 2701 "y.tab.c"
    break;

  case 212: /* statementList: functionCall $@43 statementList  */
#line 444 "SemanticAnalyzer.y"
                                                                                     {printf("direct function call in list");}
#line 2707 "y.tab.c"
    break;

  case 219: /* returnDec: RETURN expressionStatement SEMICOLON  */
#line 452 "SemanticAnalyzer.y"
                                                      {if(strcmp(presentFunctionType,(yyvsp[-1].Str))==0){(yyval.Str) = strdup((yyvsp[-1].Str));}else{printf("INVALID RETURN");return 1;}}
#line 2713 "y.tab.c"
    break;

  case 220: /* returnDec: RETURN SEMICOLON  */
#line 453 "SemanticAnalyzer.y"
                                           {int inst = getPresentFunctionIndex(); (yyval.Str) = strdup(presentFunctionType);}
#line 2719 "y.tab.c"
    break;

  case 221: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 455 "SemanticAnalyzer.y"
                                         {int i = (yyvsp[-1].Int); if(i<=0){printf("Array size has to be  Positive\n"); return 1;}sizes[0] = (yyvsp[-1].Int);instDim++;}
#line 2725 "y.tab.c"
    break;

  case 222: /* dimension: BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 456 "SemanticAnalyzer.y"
                                                                    {int a = (yyvsp[-4].Int); int b = (yyvsp[-1].Int); if(a<=0||b<=0){printf("Array sizes has to be  Positive\n"); return 1;}sizes[0] = (yyvsp[-4].Int); sizes[1] = (yyvsp[-1].Int);instDim+=2;}
#line 2731 "y.tab.c"
    break;

  case 223: /* dimension: BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 457 "SemanticAnalyzer.y"
                                                             {int i = (yyvsp[-1].Int); if(i<=0){printf("Array sizes has to be  Positive\n"); return 1;}sizes[1] = (yyvsp[-1].Int);instDim+=2;}
#line 2737 "y.tab.c"
    break;


#line 2741 "y.tab.c"

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

#line 458 "SemanticAnalyzer.y"

      
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
      
      
