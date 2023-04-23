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
  YYSYMBOL_returnDec = 146,                /* returnDec  */
  YYSYMBOL_dimension = 147                 /* dimension  */
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
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  222
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  432

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
     442,   444,   445,   446,   447,   448,   449,   450,   452,   453,
     455,   456,   457
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
  "parameter", "type", "compoundStatements", "statementList", "returnDec",
  "dimension", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-342)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-138)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,    18,    33,    40,    50,    98,  -342,    12,    12,    13,
     110,    59,   115,    78,   134,   191,  -342,  -342,  -342,    68,
     131,    64,   191,  -342,  -342,   123,   144,    72,   146,  -342,
    -342,   151,   165,   101,   191,  -342,  -342,   191,   191,  -342,
    -342,  -342,   117,   208,   226,   228,   254,   247,   266,   227,
      60,  -342,  -342,  -342,   242,   -25,   210,   258,    76,  -342,
    -342,  -342,    67,   240,   276,    85,  -342,  -342,   263,   277,
     287,   268,  -342,   285,   281,   280,  -342,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     291,   292,  -342,  -342,  -342,  -342,   314,   286,   289,   299,
     298,    68,   305,   306,   321,   142,   123,   308,  -342,   151,
    -342,  -342,   191,   310,  -342,  -342,  -342,  -342,  -342,  -342,
    -342,  -342,  -342,  -342,  -342,  -342,  -342,  -342,   309,   309,
     242,  -342,   312,    -4,   301,  -342,   309,   309,   339,   336,
    -342,   309,   309,  -342,   349,   329,   327,   328,  -342,  -342,
    -342,  -342,   351,   353,   340,   343,  -342,  -342,  -342,   364,
    -342,  -342,   191,  -342,   344,   354,  -342,   357,   358,   150,
     359,   360,   105,   328,  -342,  -342,  -342,   328,   114,  -342,
     328,   328,  -342,  -342,   328,   365,  -342,  -342,   361,   382,
    -342,  -342,  -342,   366,   191,   369,  -342,   374,  -342,   394,
     390,   393,   164,  -342,  -342,  -342,  -342,  -342,  -342,  -342,
    -342,  -342,  -342,  -342,   385,    10,  -342,  -342,  -342,  -342,
     191,   386,  -342,   409,   410,   411,   402,   389,  -342,   384,
     397,   191,  -342,   404,   408,   400,   412,   430,   413,  -342,
     434,  -342,   416,   414,   421,   436,  -342,     0,  -342,   409,
     437,   418,   438,  -342,   416,  -342,  -342,  -342,  -342,   191,
     191,   419,  -342,  -342,  -342,   356,   426,  -342,  -342,   410,
    -342,  -342,   416,   416,   416,   255,   269,   273,   424,   422,
     388,   432,   452,   453,  -342,  -342,  -342,  -342,  -342,  -342,
     443,  -342,   442,  -342,   435,  -342,  -342,  -342,     4,  -342,
    -342,  -342,    10,  -342,    10,  -342,   191,    20,   456,   458,
     388,   388,   439,   388,   388,   388,   388,   191,  -342,  -342,
     457,  -342,   127,  -342,   255,   441,  -342,   416,  -342,  -342,
     463,  -342,  -342,   356,   388,   388,  -342,  -342,  -342,  -342,
    -342,  -342,  -342,   444,  -342,   445,   250,   461,   464,   426,
    -342,   191,   416,  -342,   419,   388,  -342,  -342,  -342,   447,
     416,  -342,   449,   450,   416,   416,  -342,   451,  -342,  -342,
     454,   265,  -342,   470,   471,   460,  -342,  -342,   459,   455,
    -342,   388,   416,   416,   465,  -342,   416,  -342,  -342,  -342,
    -342,  -342,   416,  -342,   462,  -342,   467,   274,   466,  -342,
     468,    16,  -342,  -342,  -342,   467,   191,   472,  -342,   356,
    -342,   469,   191,   388,  -342,   473,   475,  -342,  -342,   476,
     474,  -342,   356,  -342,   388,  -342,  -342,   477,   478,  -342,
     477,  -342
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
     220,     0,     0,     0,     0,   220,     0,     0,   129,     0,
     188,   193,     0,     0,   121,   168,   170,   172,   173,   175,
     176,   177,   178,   180,   181,   183,   184,   185,     0,     0,
       0,   206,     0,     0,     0,   153,     0,     0,     0,     0,
     163,     0,     0,   158,   201,     0,   196,   217,   133,   126,
     205,   222,     0,   148,     0,     0,   139,   128,   142,     0,
     136,   130,     0,   195,     0,     0,    14,     0,     0,     0,
       0,     0,   187,   217,    17,    16,    18,   217,   116,   119,
     217,   217,   118,   117,   120,     0,   214,   146,     0,     0,
     221,   141,   200,     0,     0,     0,    44,     0,   219,     0,
       0,     0,     0,   213,   212,   115,   120,   215,   216,   211,
     210,   147,   145,   197,     0,     0,    15,    21,    19,    20,
       0,     0,   218,   150,   152,   193,     0,    63,    39,     0,
       0,    41,    34,     0,     0,     0,     0,     0,     0,   198,
       0,    60,     0,     0,     0,     0,    40,    49,    97,   150,
       0,     0,     0,   199,    10,    64,    11,    12,    13,     0,
       0,     0,    48,    46,    45,     0,   101,   149,   123,   152,
     124,    61,    10,    10,    10,    79,     0,     0,     0,     0,
      59,     0,     0,     0,    27,    50,    33,    18,    28,    29,
     114,   100,     0,   151,     0,     7,     8,     9,    77,    67,
      65,    66,     0,    35,     0,    37,     0,    25,     0,     0,
      27,    59,     0,    33,    18,    28,    29,     0,    30,    31,
       0,    98,     0,   103,    79,     0,    71,     0,    36,    38,
      43,    22,    23,     0,    30,    31,    53,    58,    47,    56,
      57,    54,    55,     0,   112,     0,     0,     0,     0,   105,
      62,     0,    10,    78,     0,    59,    26,    51,    52,    63,
      10,    99,     0,     0,    10,    10,   104,     0,    72,    42,
       0,    60,   113,     0,     0,   111,   109,   107,    74,     0,
      24,    59,    10,    10,     0,    68,     0,    73,    81,   108,
     106,   110,    10,    75,     0,    69,    79,    96,     0,    76,
       0,    94,    84,    82,    83,    79,     0,     0,    88,     0,
      70,     0,     0,    59,    95,     0,     0,    89,    80,    91,
       0,    85,     0,    90,    59,    92,    86,    96,     0,    93,
      96,    87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -342,  -342,   300,  -248,  -323,   -51,  -342,  -342,  -342,  -342,
    -342,  -342,  -342,  -260,   -89,  -342,   141,  -342,  -342,  -342,
    -342,  -342,     5,  -264,  -342,  -342,  -342,  -342,   172,  -341,
    -342,  -342,  -342,  -342,  -342,  -342,  -342,  -245,  -342,  -342,
    -342,  -223,  -342,  -342,  -342,  -342,  -342,  -342,  -342,  -244,
    -342,  -342,  -342,   149,  -342,  -342,  -342,  -259,  -342,  -342,
     322,  -134,     2,  -342,  -342,   212,  -342,  -342,  -342,  -342,
    -342,  -342,  -342,  -342,  -342,   311,   260,   234,   -18,   -23,
     -22,   -15,   429,   232,   186,   239,   184,  -342,  -342,   -99,
    -150,    19,  -342,   380,  -342,  -342,    47,    66,  -342,     3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,   375,   255,   310,   195,   216,   217,   218,
     355,   219,   333,   311,   231,   245,   279,   174,   220,   264,
     280,   265,   312,   175,   254,   294,   242,   275,   300,   301,
     392,   398,   352,   379,   386,   396,   327,   313,   381,   394,
     403,   404,   424,   428,   413,   420,   422,   427,   409,   176,
     266,   345,   290,   291,   292,   349,   323,   376,   321,   360,
     177,   315,   179,   180,   181,   182,    91,   103,   142,    52,
      90,    67,   107,    60,   102,   154,   236,   238,    10,    14,
      12,   183,    44,    45,    46,    47,    48,    49,   112,   316,
     145,    53,    54,    95,    96,    97,   148,   185,   186,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    51,     7,    59,   353,   285,   271,    57,    66,     7,
       7,   299,   192,   178,    29,    98,    35,   262,    99,    70,
     286,   287,    71,    72,   295,   296,   297,   228,   325,    19,
     229,   230,     1,     2,     3,   152,   314,   331,   263,   178,
     407,   153,   326,   178,   178,    61,   178,   178,   184,    20,
     178,    68,   226,    21,   408,   399,    22,     4,   332,     4,
     299,    29,   115,   393,   410,     9,   314,   314,    35,   314,
     314,   314,   314,   356,   184,    25,    19,   114,   184,   206,
      11,   184,   184,   135,   140,   184,   143,    13,   286,   287,
     314,   314,    25,    15,    31,    26,   173,   144,    16,    27,
      33,    31,    28,    22,   368,    55,   377,    98,   257,    56,
     104,   314,   372,    62,    32,    50,    33,    63,    33,    28,
     273,    34,   173,   389,   390,    33,   173,    24,    34,   173,
     173,   288,    30,   173,     1,     2,     3,   314,   273,   273,
     273,   202,    69,   258,   395,    74,    56,   144,    15,   414,
      37,    36,   402,    73,   199,   274,    38,    74,    39,    40,
      41,   172,   425,   346,   286,   287,   289,   198,  -131,   314,
      58,   347,   348,   274,   274,   274,   149,   286,   287,   214,
     314,  -137,   134,   156,   157,   139,    37,   144,   160,   161,
      64,   256,    38,   257,    39,    40,    41,    42,    65,   288,
      37,   225,  -134,   272,   429,   233,    38,   431,    39,    40,
      41,    42,     8,   328,   284,   329,   246,   232,   273,     8,
       8,   272,   272,   272,    75,    76,   273,    37,   258,    77,
     273,   273,    78,    38,   289,    39,    40,    41,    42,   203,
      87,    88,    89,   204,   276,   277,   207,   208,   273,   273,
     209,   100,   257,   274,    81,    82,    83,    84,   273,    79,
      80,   274,    92,    93,    94,   274,   274,   119,   120,   121,
     122,   125,   126,   127,   101,   288,   256,    85,    86,   165,
     298,   105,   284,   274,   274,   302,   303,   258,   288,   304,
     305,   330,   106,   274,   362,   363,   -80,   -80,   400,   401,
     108,   272,   343,   109,   232,   110,   232,    17,    18,   272,
     289,   117,   118,   272,   272,   336,   337,    98,   339,   340,
     341,   342,   111,   289,   123,   124,   113,     4,   128,   129,
     130,   272,   272,   131,   132,   256,   367,   133,   134,   357,
     358,   272,   136,   137,   138,   141,   155,   147,     1,     2,
       3,   146,   165,   151,   166,   167,   158,   168,   284,   159,
     370,   169,   170,   171,    37,   162,   163,   164,   187,   188,
      38,   284,    39,    40,    41,   172,     1,     2,     3,   189,
     281,   191,   166,   167,   190,   168,   388,   282,   283,   193,
     194,   411,    37,   196,   197,   200,   201,   416,    38,   212,
      39,    40,    41,   172,   210,   215,   153,   213,     1,     2,
       3,   222,   281,   223,   166,   167,   224,   168,   417,   308,
     309,   221,   227,   234,    37,   235,   237,   241,   239,   426,
      38,   243,    39,    40,    41,   172,     1,     2,     3,   240,
     165,   247,   166,   167,   244,   168,   248,   249,   251,   250,
     252,   253,    37,   261,   268,   270,  -102,   259,    38,   307,
      39,    40,    41,   172,   260,   269,   278,   306,   317,   318,
     319,   320,   322,   334,   324,   335,   344,   351,   338,   354,
     364,   359,   391,   365,   361,   371,   373,   374,   378,   382,
     383,   384,   298,   380,   387,   369,   350,   385,   366,   211,
     205,   397,   401,   293,   406,   405,   415,   116,   412,   267,
     150,   418,   419,   423,   421,     0,     0,   430
};

static const yytype_int16 yycheck[] =
{
      15,    19,     0,    25,   327,   265,   254,    22,    31,     7,
       8,   275,   162,   147,    11,    40,    13,    17,    43,    34,
     265,   265,    37,    38,   272,   273,   274,    17,    24,    16,
      20,    21,    20,    21,    22,    39,   280,    17,    38,   173,
      24,    45,    38,   177,   178,    26,   180,   181,   147,    36,
     184,    32,   202,    40,    38,   396,    43,    47,    38,    47,
     324,    58,    77,   386,   405,    47,   310,   311,    65,   313,
     314,   315,   316,   333,   173,    16,    16,    75,   177,   178,
      47,   180,   181,   101,   106,   184,   109,    47,   333,   333,
     334,   335,    16,    43,    16,    36,   147,   112,     0,    40,
      40,    16,    43,    43,   352,    41,   365,    40,   242,    45,
      43,   355,   360,    41,    36,    47,    40,    45,    40,    43,
     254,    43,   173,   382,   383,    40,   177,    17,    43,   180,
     181,   265,    17,   184,    20,    21,    22,   381,   272,   273,
     274,    36,    41,   242,   392,    40,    45,   162,    43,   409,
      36,    17,   397,    36,   169,   254,    42,    40,    44,    45,
      46,    47,   422,    36,   409,   409,   265,    17,    37,   413,
      47,    44,    45,   272,   273,   274,   129,   422,   422,   194,
     424,    37,    40,   136,   137,    43,    36,   202,   141,   142,
      44,   242,    42,   327,    44,    45,    46,    47,    47,   333,
      36,    37,    37,   254,   427,   220,    42,   430,    44,    45,
      46,    47,     0,   302,   265,   304,   231,   215,   352,     7,
       8,   272,   273,   274,    16,    17,   360,    36,   327,     3,
     364,   365,     4,    42,   333,    44,    45,    46,    47,   173,
      13,    14,    15,   177,   259,   260,   180,   181,   382,   383,
     184,    41,   386,   352,     7,     8,     9,    10,   392,     5,
       6,   360,    20,    21,    22,   364,   365,    81,    82,    83,
      84,    87,    88,    89,    16,   409,   327,    11,    12,    24,
      25,    41,   333,   382,   383,    16,    17,   386,   422,    16,
      17,   306,    16,   392,    44,    45,    31,    32,    24,    25,
      37,   352,   317,    16,   302,    37,   304,     7,     8,   360,
     409,    79,    80,   364,   365,   310,   311,    40,   313,   314,
     315,   316,    37,   422,    85,    86,    45,    47,    37,    37,
      16,   382,   383,    47,    45,   386,   351,    38,    40,   334,
     335,   392,    37,    37,    23,    37,    45,    38,    20,    21,
      22,    41,    24,    41,    26,    27,    17,    29,   409,    23,
     355,    33,    34,    35,    36,    16,    37,    40,    17,    16,
      42,   422,    44,    45,    46,    47,    20,    21,    22,    39,
      24,    17,    26,    27,    41,    29,   381,    31,    32,    45,
      36,   406,    36,    36,    36,    36,    36,   412,    42,    17,
      44,    45,    46,    47,    39,    36,    45,    41,    20,    21,
      22,    17,    24,    23,    26,    27,    23,    29,   413,    31,
      32,    47,    37,    37,    36,    16,    16,    38,    17,   424,
      42,    47,    44,    45,    46,    47,    20,    21,    22,    37,
      24,    37,    26,    27,    47,    29,    38,    47,    18,    37,
      37,    17,    36,    17,    17,    17,    30,    43,    42,    37,
      44,    45,    46,    47,    43,    47,    47,    43,    36,    17,
      17,    28,    30,    17,    39,    17,    19,    36,    39,    16,
      19,    37,    17,    19,    39,    38,    37,    37,    37,    19,
      19,    31,    25,    39,    39,   354,   324,    38,   349,   188,
     178,    39,    25,   269,    36,    39,    37,    78,    36,   249,
     130,    38,    37,    39,    38,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    47,    49,    50,   110,   113,    47,
     126,    47,   128,    47,   127,    43,     0,    50,    50,    16,
      36,    40,    43,   147,    17,    16,    36,    40,    43,   147,
      17,    16,    36,    40,    43,   147,    17,    36,    42,    44,
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
     111,   112,   113,   129,   137,   145,   146,    17,    16,    39,
      41,    17,   138,    45,    36,    54,    36,    36,    17,   129,
      36,    36,    36,   145,   145,   108,   137,   145,   145,   145,
      39,   123,    17,    41,   129,    36,    55,    56,    57,    59,
      66,    47,    17,    23,    23,    37,   138,    37,    17,    20,
      21,    62,   110,   129,    37,    16,   124,    16,   125,    17,
      37,    38,    74,    47,    47,    63,   129,    37,    38,    47,
      37,    18,    37,    17,    72,    52,    53,   109,   137,    43,
      43,    17,    17,    38,    67,    69,    98,   124,    17,    47,
      17,    51,    53,   109,   137,    75,   129,   129,    47,    64,
      68,    24,    31,    32,    53,    61,    85,    97,   109,   137,
     100,   101,   102,   125,    73,    51,    51,    51,    25,    71,
      76,    77,    16,    17,    16,    17,    43,    37,    31,    32,
      53,    61,    70,    85,    97,   109,   137,    36,    17,    17,
      28,   106,    30,   104,    39,    24,    38,    84,    62,    62,
     129,    17,    38,    60,    17,    17,    70,    70,    39,    70,
      70,    70,    70,   129,    19,    99,    36,    44,    45,   103,
      76,    36,    80,    52,    16,    58,    61,    70,    70,    37,
     107,    39,    44,    45,    19,    19,   101,   129,    51,    64,
      70,    38,    51,    37,    37,    51,   105,   105,    37,    81,
      39,    86,    19,    19,    31,    38,    82,    39,    70,   105,
     105,    17,    78,    52,    87,    51,    83,    39,    79,    77,
      24,    25,    85,    88,    89,    39,    36,    24,    38,    96,
      77,   129,    36,    92,    61,    37,   129,    70,    38,    37,
      93,    38,    94,    39,    90,    61,    70,    95,    91,    89,
      39,    89
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
     144,   145,   145,   145,   145,   145,   145,   145,   146,   146,
     147,   147,   147
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
       3,     2,     2,     2,     1,     2,     2,     0,     3,     2,
       3,     6,     5
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
#line 1882 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 242 "SemanticAnalyzer.y"
                                                             {}
#line 1888 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 244 "SemanticAnalyzer.y"
                                                        {}
#line 1894 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 247 "SemanticAnalyzer.y"
                                              {}
#line 1900 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 248 "SemanticAnalyzer.y"
                                               {}
#line 1906 "y.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 255 "SemanticAnalyzer.y"
                            {pushNewScope();}
#line 1912 "y.tab.c"
    break;

  case 22: /* forLoop1: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON  */
#line 261 "SemanticAnalyzer.y"
                                                                                                          {popScope(); }
#line 1918 "y.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 262 "SemanticAnalyzer.y"
                                                                                                   {pushNewScope();}
#line 1924 "y.tab.c"
    break;

  case 24: /* forLoop2: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR $@2 inLoop CLCUR  */
#line 262 "SemanticAnalyzer.y"
                                                                                                                                  {popScope(); popScope(); }
#line 1930 "y.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 263 "SemanticAnalyzer.y"
                                                                                              {pushNewScope();}
#line 1936 "y.tab.c"
    break;

  case 26: /* forLoop3: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC $@3 singleLoopStatement  */
#line 263 "SemanticAnalyzer.y"
                                                                                                                                    {popScope(); popScope(); }
#line 1942 "y.tab.c"
    break;

  case 35: /* forAssignStatement: INT IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 274 "SemanticAnalyzer.y"
                                                                                             {}
#line 1948 "y.tab.c"
    break;

  case 44: /* $@4: %empty  */
#line 285 "SemanticAnalyzer.y"
                             {pushNewScope();}
#line 1954 "y.tab.c"
    break;

  case 46: /* $@5: %empty  */
#line 286 "SemanticAnalyzer.y"
                         {pushNewScope();}
#line 1960 "y.tab.c"
    break;

  case 47: /* whileSuffix: OPCUR $@5 inLoop CLCUR  */
#line 286 "SemanticAnalyzer.y"
                                                       { popScope(); popScope(); }
#line 1966 "y.tab.c"
    break;

  case 48: /* whileSuffix: SEMICOLON  */
#line 287 "SemanticAnalyzer.y"
                              {popScope(); printf("\nWHILE SEMICOLON \n");}
#line 1972 "y.tab.c"
    break;

  case 49: /* $@6: %empty  */
#line 288 "SemanticAnalyzer.y"
                    {pushNewScope();}
#line 1978 "y.tab.c"
    break;

  case 50: /* whileSuffix: $@6 singleLoopStatement  */
#line 288 "SemanticAnalyzer.y"
                                                          { popScope(); popScope();}
#line 1984 "y.tab.c"
    break;

  case 51: /* inLoop: BREAK SEMICOLON inLoop  */
#line 290 "SemanticAnalyzer.y"
                                     {}
#line 1990 "y.tab.c"
    break;

  case 52: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 291 "SemanticAnalyzer.y"
                                            {}
#line 1996 "y.tab.c"
    break;

  case 53: /* inLoop: specialStatement inLoop  */
#line 292 "SemanticAnalyzer.y"
                                          {}
#line 2002 "y.tab.c"
    break;

  case 54: /* inLoop: basicStatement inLoop  */
#line 293 "SemanticAnalyzer.y"
                                        {}
#line 2008 "y.tab.c"
    break;

  case 55: /* inLoop: functionCall inLoop  */
#line 294 "SemanticAnalyzer.y"
                                     {}
#line 2014 "y.tab.c"
    break;

  case 56: /* inLoop: ifInLoopStatement inLoop  */
#line 295 "SemanticAnalyzer.y"
                                           {}
#line 2020 "y.tab.c"
    break;

  case 57: /* inLoop: switchStatement inLoop  */
#line 296 "SemanticAnalyzer.y"
                                         {}
#line 2026 "y.tab.c"
    break;

  case 58: /* inLoop: singleLoopStatement inLoop  */
#line 297 "SemanticAnalyzer.y"
                                             {}
#line 2032 "y.tab.c"
    break;

  case 60: /* $@7: %empty  */
#line 300 "SemanticAnalyzer.y"
                                                              {pushNewScope();}
#line 2038 "y.tab.c"
    break;

  case 61: /* $@8: %empty  */
#line 300 "SemanticAnalyzer.y"
                                                                                           {popScope();}
#line 2044 "y.tab.c"
    break;

  case 63: /* $@9: %empty  */
#line 301 "SemanticAnalyzer.y"
                                                               {pushNewScope();}
#line 2050 "y.tab.c"
    break;

  case 64: /* $@10: %empty  */
#line 301 "SemanticAnalyzer.y"
                                                                                                 {popScope();}
#line 2056 "y.tab.c"
    break;

  case 68: /* $@11: %empty  */
#line 305 "SemanticAnalyzer.y"
                                                          {pushNewScope();}
#line 2062 "y.tab.c"
    break;

  case 69: /* $@12: %empty  */
#line 305 "SemanticAnalyzer.y"
                                                                                       {popScope();}
#line 2068 "y.tab.c"
    break;

  case 71: /* $@13: %empty  */
#line 306 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 2074 "y.tab.c"
    break;

  case 72: /* $@14: %empty  */
#line 306 "SemanticAnalyzer.y"
                                                  {popScope();}
#line 2080 "y.tab.c"
    break;

  case 74: /* $@15: %empty  */
#line 307 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 2086 "y.tab.c"
    break;

  case 75: /* $@16: %empty  */
#line 307 "SemanticAnalyzer.y"
                                                                                     {popScope();}
#line 2092 "y.tab.c"
    break;

  case 77: /* $@17: %empty  */
#line 308 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 2098 "y.tab.c"
    break;

  case 78: /* ES: ELSE $@17 singleStatement  */
#line 308 "SemanticAnalyzer.y"
                                                 {popScope();}
#line 2104 "y.tab.c"
    break;

  case 80: /* $@18: %empty  */
#line 311 "SemanticAnalyzer.y"
                                                                    {pushNewScope();}
#line 2110 "y.tab.c"
    break;

  case 81: /* $@19: %empty  */
#line 311 "SemanticAnalyzer.y"
                                                                                             {popScope;}
#line 2116 "y.tab.c"
    break;

  case 85: /* $@20: %empty  */
#line 315 "SemanticAnalyzer.y"
                                                              {pushNewScope();}
#line 2122 "y.tab.c"
    break;

  case 86: /* $@21: %empty  */
#line 315 "SemanticAnalyzer.y"
                                                                                       {popScope();}
#line 2128 "y.tab.c"
    break;

  case 88: /* $@22: %empty  */
#line 316 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 2134 "y.tab.c"
    break;

  case 89: /* $@23: %empty  */
#line 316 "SemanticAnalyzer.y"
                                              {popScope();}
#line 2140 "y.tab.c"
    break;

  case 91: /* $@24: %empty  */
#line 317 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 2146 "y.tab.c"
    break;

  case 92: /* $@25: %empty  */
#line 317 "SemanticAnalyzer.y"
                                                                                         {popScope();}
#line 2152 "y.tab.c"
    break;

  case 94: /* $@26: %empty  */
#line 318 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 2158 "y.tab.c"
    break;

  case 95: /* ESLoop: ELSE $@26 singleLoopStatement  */
#line 318 "SemanticAnalyzer.y"
                                                     {popScope();}
#line 2164 "y.tab.c"
    break;

  case 97: /* $@27: %empty  */
#line 321 "SemanticAnalyzer.y"
                                                             {pushNewScope();}
#line 2170 "y.tab.c"
    break;

  case 98: /* $@28: %empty  */
#line 321 "SemanticAnalyzer.y"
                                                                                                               {popScope();}
#line 2176 "y.tab.c"
    break;

  case 99: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR $@27 caseStatements defaultStatement $@28 CLCUR  */
#line 321 "SemanticAnalyzer.y"
                                                                                                                                   {}
#line 2182 "y.tab.c"
    break;

  case 101: /* caseStatements: %empty  */
#line 322 "SemanticAnalyzer.y"
                                         {}
#line 2188 "y.tab.c"
    break;

  case 102: /* $@29: %empty  */
#line 323 "SemanticAnalyzer.y"
                        {pushNewScope();}
#line 2194 "y.tab.c"
    break;

  case 103: /* $@30: %empty  */
#line 323 "SemanticAnalyzer.y"
                                                  {pushNewScope();}
#line 2200 "y.tab.c"
    break;

  case 105: /* caseStatementInt: %empty  */
#line 323 "SemanticAnalyzer.y"
                                                                                       {}
#line 2206 "y.tab.c"
    break;

  case 107: /* caseInt: CASE INTVAL COLON caseContinuer  */
#line 325 "SemanticAnalyzer.y"
                                                  {}
#line 2212 "y.tab.c"
    break;

  case 112: /* $@31: %empty  */
#line 330 "SemanticAnalyzer.y"
                                      {pushNewScope();}
#line 2218 "y.tab.c"
    break;

  case 113: /* defaultStatement: DEFAULT COLON $@31 statements  */
#line 330 "SemanticAnalyzer.y"
                                                                   {popScope();}
#line 2224 "y.tab.c"
    break;

  case 114: /* defaultStatement: %empty  */
#line 331 "SemanticAnalyzer.y"
                                          {}
#line 2230 "y.tab.c"
    break;

  case 117: /* basicStatement: expressionStatement  */
#line 337 "SemanticAnalyzer.y"
                                          {}
#line 2236 "y.tab.c"
    break;

  case 118: /* basicStatement: declarationStatement  */
#line 338 "SemanticAnalyzer.y"
                                       {}
#line 2242 "y.tab.c"
    break;

  case 119: /* basicStatement: assignmentStatement  */
#line 339 "SemanticAnalyzer.y"
                                        {}
#line 2248 "y.tab.c"
    break;

  case 121: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 342 "SemanticAnalyzer.y"
                                                                                          {}
#line 2254 "y.tab.c"
    break;

  case 122: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 343 "SemanticAnalyzer.y"
                                                                 {}
#line 2260 "y.tab.c"
    break;

  case 125: /* $@32: %empty  */
#line 347 "SemanticAnalyzer.y"
                                                             {presentFunctionType = strdup("i");}
#line 2266 "y.tab.c"
    break;

  case 126: /* declarationStatement: INT IDENTIFIER OPBRAC parameters $@32 CLBRAC compoundStatements  */
#line 347 "SemanticAnalyzer.y"
                                                                                                                             {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);}else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;}memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2272 "y.tab.c"
    break;

  case 127: /* $@33: %empty  */
#line 348 "SemanticAnalyzer.y"
                                                      {presentFunctionType = strdup("c");}
#line 2278 "y.tab.c"
    break;

  case 128: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters $@33 CLBRAC compoundStatements  */
#line 348 "SemanticAnalyzer.y"
                                                                                                                     {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst ==-1){insertInTable((yyvsp[-5].Str),strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2284 "y.tab.c"
    break;

  case 129: /* $@34: %empty  */
#line 349 "SemanticAnalyzer.y"
                                                             {presentFunctionType = strdup("f");}
#line 2290 "y.tab.c"
    break;

  case 130: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC $@34 compoundStatements  */
#line 349 "SemanticAnalyzer.y"
                                                                                                                     {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2296 "y.tab.c"
    break;

  case 131: /* $@35: %empty  */
#line 350 "SemanticAnalyzer.y"
                                         {pushNewScope();}
#line 2302 "y.tab.c"
    break;

  case 132: /* $@36: %empty  */
#line 350 "SemanticAnalyzer.y"
                                                          {presentFunctionType = strdup("i");}
#line 2308 "y.tab.c"
    break;

  case 133: /* declarationStatement: INT IDENTIFIER OPBRAC $@35 $@36 CLBRAC compoundStatements  */
#line 350 "SemanticAnalyzer.y"
                                                                                                                          {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2314 "y.tab.c"
    break;

  case 134: /* $@37: %empty  */
#line 351 "SemanticAnalyzer.y"
                                           {pushNewScope();}
#line 2320 "y.tab.c"
    break;

  case 135: /* $@38: %empty  */
#line 351 "SemanticAnalyzer.y"
                                                            {presentFunctionType = strdup("f");}
#line 2326 "y.tab.c"
    break;

  case 136: /* declarationStatement: FLOAT IDENTIFIER OPBRAC $@37 $@38 CLBRAC compoundStatements  */
#line 351 "SemanticAnalyzer.y"
                                                                                                                             {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2332 "y.tab.c"
    break;

  case 137: /* $@39: %empty  */
#line 352 "SemanticAnalyzer.y"
                                          {pushNewScope();}
#line 2338 "y.tab.c"
    break;

  case 138: /* $@40: %empty  */
#line 352 "SemanticAnalyzer.y"
                                                           {presentFunctionType = strdup("c");}
#line 2344 "y.tab.c"
    break;

  case 139: /* declarationStatement: CHAR IDENTIFIER OPBRAC $@39 $@40 CLBRAC compoundStatements  */
#line 352 "SemanticAnalyzer.y"
                                                                                                                            {int inst = getIdentifierIndex((yyvsp[-5].Str),false,true); if(inst == -1){insertInTable((yyvsp[-5].Str),strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-5].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2350 "y.tab.c"
    break;

  case 140: /* declarationStatement: INT declarationListInt SEMICOLON  */
#line 353 "SemanticAnalyzer.y"
                                                   {}
#line 2356 "y.tab.c"
    break;

  case 145: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON  */
#line 358 "SemanticAnalyzer.y"
                                                                                          {}
#line 2362 "y.tab.c"
    break;

  case 146: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON  */
#line 359 "SemanticAnalyzer.y"
                                                                              {}
#line 2368 "y.tab.c"
    break;

  case 153: /* declarationListInt: IDENTIFIER EQUAL expressionStatement COMMA declarationListInt  */
#line 370 "SemanticAnalyzer.y"
                                                                                        {printf("DSL1..\n");}
#line 2374 "y.tab.c"
    break;

  case 154: /* declarationListInt: IDENTIFIER COMMA declarationListInt  */
#line 371 "SemanticAnalyzer.y"
                                                      { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2380 "y.tab.c"
    break;

  case 155: /* declarationListInt: IDENTIFIER EQUAL expressionStatement  */
#line 372 "SemanticAnalyzer.y"
                                                       {}
#line 2386 "y.tab.c"
    break;

  case 156: /* declarationListInt: IDENTIFIER dimension  */
#line 373 "SemanticAnalyzer.y"
                                        {if(checkVariable((yyvsp[-1].Str),currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-1].Str));return 1;}insertInTable((yyvsp[-1].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2392 "y.tab.c"
    break;

  case 157: /* declarationListInt: IDENTIFIER  */
#line 374 "SemanticAnalyzer.y"
                             { if(checkVariable((yyvsp[0].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[0].Str));return 1;}insertInTable((yyvsp[0].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2398 "y.tab.c"
    break;

  case 158: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListFloat  */
#line 376 "SemanticAnalyzer.y"
                                                                                            {printf("DSL1..\n");}
#line 2404 "y.tab.c"
    break;

  case 159: /* declarationListFloat: IDENTIFIER COMMA declarationListFloat  */
#line 377 "SemanticAnalyzer.y"
                                                        { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2410 "y.tab.c"
    break;

  case 160: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement  */
#line 378 "SemanticAnalyzer.y"
                                                       {printf("DSL3..\n");}
#line 2416 "y.tab.c"
    break;

  case 161: /* declarationListFloat: IDENTIFIER dimension  */
#line 379 "SemanticAnalyzer.y"
                                        {if(checkVariable((yyvsp[-1].Str),currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-1].Str));return 1;}insertInTable((yyvsp[-1].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2422 "y.tab.c"
    break;

  case 162: /* declarationListFloat: IDENTIFIER  */
#line 380 "SemanticAnalyzer.y"
                             { if(checkVariable((yyvsp[0].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[0].Str));return 1;}insertInTable((yyvsp[0].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2428 "y.tab.c"
    break;

  case 164: /* declarationListChar: IDENTIFIER COMMA declarationListChar  */
#line 383 "SemanticAnalyzer.y"
                                                       { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2434 "y.tab.c"
    break;

  case 166: /* declarationListChar: IDENTIFIER dimension  */
#line 385 "SemanticAnalyzer.y"
                                       {if(checkVariable((yyvsp[-1].Str),currScope,true,true)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-1].Str));return 1;}insertInTable((yyvsp[-1].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2440 "y.tab.c"
    break;

  case 167: /* declarationListChar: IDENTIFIER  */
#line 386 "SemanticAnalyzer.y"
                             { if(checkVariable((yyvsp[0].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[0].Str));return 1;}insertInTable((yyvsp[0].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2446 "y.tab.c"
    break;

  case 168: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 388 "SemanticAnalyzer.y"
                                                                           {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2452 "y.tab.c"
    break;

  case 169: /* expressionStatement: logicalExpression  */
#line 389 "SemanticAnalyzer.y"
                                    {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2458 "y.tab.c"
    break;

  case 170: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 391 "SemanticAnalyzer.y"
                                                                 {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2464 "y.tab.c"
    break;

  case 171: /* logicalExpression: expression  */
#line 392 "SemanticAnalyzer.y"
                             {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2470 "y.tab.c"
    break;

  case 172: /* expression: relationalExpression EQUALS expression  */
#line 394 "SemanticAnalyzer.y"
                                                         {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2476 "y.tab.c"
    break;

  case 173: /* expression: relationalExpression NOTEQUAL expression  */
#line 395 "SemanticAnalyzer.y"
                                                           {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2482 "y.tab.c"
    break;

  case 174: /* expression: relationalExpression  */
#line 396 "SemanticAnalyzer.y"
                                       {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2488 "y.tab.c"
    break;

  case 175: /* relationalExpression: value GREATERTHAN relationalExpression  */
#line 398 "SemanticAnalyzer.y"
                                                                   {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2494 "y.tab.c"
    break;

  case 176: /* relationalExpression: value GREATERTHANEQUALTO relationalExpression  */
#line 399 "SemanticAnalyzer.y"
                                                                {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2500 "y.tab.c"
    break;

  case 177: /* relationalExpression: value LESSTHAN relationalExpression  */
#line 400 "SemanticAnalyzer.y"
                                                      {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2506 "y.tab.c"
    break;

  case 178: /* relationalExpression: value LESSTHANEQUALTO relationalExpression  */
#line 401 "SemanticAnalyzer.y"
                                                             {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2512 "y.tab.c"
    break;

  case 179: /* relationalExpression: value  */
#line 402 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2518 "y.tab.c"
    break;

  case 180: /* value: term ADD value  */
#line 404 "SemanticAnalyzer.y"
                            {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2524 "y.tab.c"
    break;

  case 181: /* value: term SUB value  */
#line 405 "SemanticAnalyzer.y"
                         {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2530 "y.tab.c"
    break;

  case 182: /* value: term  */
#line 406 "SemanticAnalyzer.y"
               {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2536 "y.tab.c"
    break;

  case 183: /* term: factor MULT term  */
#line 408 "SemanticAnalyzer.y"
                             {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2542 "y.tab.c"
    break;

  case 184: /* term: factor DIV term  */
#line 409 "SemanticAnalyzer.y"
                          {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2548 "y.tab.c"
    break;

  case 185: /* term: factor MOD term  */
#line 410 "SemanticAnalyzer.y"
                          {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2554 "y.tab.c"
    break;

  case 186: /* term: factor  */
#line 411 "SemanticAnalyzer.y"
                 {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2560 "y.tab.c"
    break;

  case 187: /* factor: IDENTIFIER  */
#line 413 "SemanticAnalyzer.y"
                         {int inst = checkVariableScope((yyvsp[0].Str),currScope,false,false); if(inst!=-1){(yyval.Str) = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",(yyvsp[0].Str));return 1;}}
#line 2566 "y.tab.c"
    break;

  case 188: /* factor: OPBRAC expressionStatement CLBRAC  */
#line 414 "SemanticAnalyzer.y"
                                            {(yyval.Str) = strdup((yyvsp[-1].Str));}
#line 2572 "y.tab.c"
    break;

  case 189: /* factor: LOGICALNOT expressionStatement  */
#line 415 "SemanticAnalyzer.y"
                                         {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2578 "y.tab.c"
    break;

  case 190: /* factor: CHARVAL  */
#line 416 "SemanticAnalyzer.y"
                  {(yyval.Str) = strdup("c");}
#line 2584 "y.tab.c"
    break;

  case 191: /* factor: INTVAL  */
#line 417 "SemanticAnalyzer.y"
                 {(yyval.Str) = strdup("i");printf("INT VALS.. %d\n",yylval);}
#line 2590 "y.tab.c"
    break;

  case 192: /* factor: FLOATVAL  */
#line 418 "SemanticAnalyzer.y"
                   {(yyval.Str) = strdup("f");}
#line 2596 "y.tab.c"
    break;

  case 193: /* factor: IDENTIFIER OPBRAC CLBRAC  */
#line 419 "SemanticAnalyzer.y"
                                   {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0; int inst = getIdentifierIndex((yyvsp[-2].Str),false,true);if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){(yyval.Str) = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2602 "y.tab.c"
    break;

  case 194: /* $@41: %empty  */
#line 420 "SemanticAnalyzer.y"
                            {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2608 "y.tab.c"
    break;

  case 195: /* factor: IDENTIFIER OPBRAC $@41 argList CLBRAC  */
#line 420 "SemanticAnalyzer.y"
                                                                                                        {int inst = getIdentifierIndex((yyvsp[-4].Str),false,true); if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){(yyval.Str) = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2614 "y.tab.c"
    break;

  case 196: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE  */
#line 421 "SemanticAnalyzer.y"
                                             {int inst = checkVariableScope((yyvsp[-3].Str),currScope,true,false); if(inst!=-1){(yyval.Str) = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",(yyvsp[-3].Str));return 1;}}
#line 2620 "y.tab.c"
    break;

  case 197: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 422 "SemanticAnalyzer.y"
                                                                     {int inst = checkVariableScope((yyvsp[-6].Str),currScope,true,false); if(inst!=-1){(yyval.Str) = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",(yyvsp[-6].Str));return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2626 "y.tab.c"
    break;

  case 198: /* functionCall: IDENTIFIER OPBRAC CLBRAC SEMICOLON  */
#line 425 "SemanticAnalyzer.y"
                                                      {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0; int inst = getIdentifierIndex((yyvsp[-3].Str),false,true);if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){(yyval.Str) = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2632 "y.tab.c"
    break;

  case 199: /* functionCall: IDENTIFIER OPBRAC argList CLBRAC SEMICOLON  */
#line 426 "SemanticAnalyzer.y"
                                                               {int inst = getIdentifierIndex((yyvsp[-4].Str),false,true); if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){(yyval.Str) = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2638 "y.tab.c"
    break;

  case 200: /* argList: expressionStatement COMMA argList  */
#line 429 "SemanticAnalyzer.y"
                                                 {arglistArray[argindex++]=strdup((yyvsp[-2].Str));}
#line 2644 "y.tab.c"
    break;

  case 201: /* argList: expressionStatement  */
#line 430 "SemanticAnalyzer.y"
                                      {arglistArray[argindex++]=strdup((yyvsp[0].Str));}
#line 2650 "y.tab.c"
    break;

  case 202: /* $@42: %empty  */
#line 432 "SemanticAnalyzer.y"
                  {pushNewScope(); memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2656 "y.tab.c"
    break;

  case 205: /* paramContinuer: parameter COMMA paramContinuer  */
#line 434 "SemanticAnalyzer.y"
                                                                  {printf("FUNCTION params\n");}
#line 2662 "y.tab.c"
    break;

  case 206: /* parameter: type IDENTIFIER  */
#line 436 "SemanticAnalyzer.y"
                                 {printf("FUNCTION param\n");insertInTable((yyvsp[0].Str),(yyvsp[-1].Str),(yyvsp[-1].Str),currScope,0,NULL,NULL,0,false,false);}
#line 2668 "y.tab.c"
    break;

  case 207: /* type: INT  */
#line 438 "SemanticAnalyzer.y"
                {(yyval.Str) = strdup("i");instanceParamList[currentParamCount++]=strdup("i");}
#line 2674 "y.tab.c"
    break;

  case 208: /* type: FLOAT  */
#line 439 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup("f");instanceParamList[currentParamCount++]=strdup("f");}
#line 2680 "y.tab.c"
    break;

  case 209: /* type: CHAR  */
#line 440 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup("c");instanceParamList[currentParamCount++]=strdup("c");}
#line 2686 "y.tab.c"
    break;

  case 210: /* compoundStatements: OPCUR statementList CLCUR  */
#line 442 "SemanticAnalyzer.y"
                                                    {popScope();printf("FUNCTION statements\n");}
#line 2692 "y.tab.c"
    break;

  case 218: /* returnDec: RETURN expressionStatement SEMICOLON  */
#line 452 "SemanticAnalyzer.y"
                                                      {if(strcmp(presentFunctionType,(yyvsp[-1].Str))==0){(yyval.Str) = strdup((yyvsp[-1].Str));}else{printf("INVALID RETURN");return 1;}}
#line 2698 "y.tab.c"
    break;

  case 219: /* returnDec: RETURN SEMICOLON  */
#line 453 "SemanticAnalyzer.y"
                                           {int inst = getPresentFunctionIndex(); (yyval.Str) = strdup(presentFunctionType);}
#line 2704 "y.tab.c"
    break;

  case 220: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 455 "SemanticAnalyzer.y"
                                         {int i = (yyvsp[-1].Int); if(i<=0){printf("Array size has to be  Positive\n"); return 1;}sizes[0] = (yyvsp[-1].Int);instDim++;}
#line 2710 "y.tab.c"
    break;

  case 221: /* dimension: BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 456 "SemanticAnalyzer.y"
                                                                    {int a = (yyvsp[-4].Int); int b = (yyvsp[-1].Int); if(a<=0||b<=0){printf("Array sizes has to be  Positive\n"); return 1;}sizes[0] = (yyvsp[-4].Int); sizes[1] = (yyvsp[-1].Int);instDim+=2;}
#line 2716 "y.tab.c"
    break;

  case 222: /* dimension: BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 457 "SemanticAnalyzer.y"
                                                             {int i = (yyvsp[-1].Int); if(i<=0){printf("Array sizes has to be  Positive\n"); return 1;}sizes[1] = (yyvsp[-1].Int);instDim+=2;}
#line 2722 "y.tab.c"
    break;


#line 2726 "y.tab.c"

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
			printTable();
     	}
     	else 
     		printf("\n\nParsing Failed\n\n");
    	
			
     	exit(0);
     }
      
      
