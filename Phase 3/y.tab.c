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
     

#line 251 "y.tab.c"

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
#line 180 "SemanticAnalyzer.y"

    		int Int;
    		float Float;
    		char Char;
    		char* Str;
    		struct data{
     
    		};
    	

#line 409 "y.tab.c"

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
  YYSYMBOL_arrayValues = 117,              /* arrayValues  */
  YYSYMBOL_prattributes = 118,             /* prattributes  */
  YYSYMBOL_scattributes = 119,             /* scattributes  */
  YYSYMBOL_declarationListInt = 120,       /* declarationListInt  */
  YYSYMBOL_declarationListFloat = 121,     /* declarationListFloat  */
  YYSYMBOL_declarationListChar = 122,      /* declarationListChar  */
  YYSYMBOL_expressionStatement = 123,      /* expressionStatement  */
  YYSYMBOL_logicalExpression = 124,        /* logicalExpression  */
  YYSYMBOL_expression = 125,               /* expression  */
  YYSYMBOL_relationalExpression = 126,     /* relationalExpression  */
  YYSYMBOL_value = 127,                    /* value  */
  YYSYMBOL_term = 128,                     /* term  */
  YYSYMBOL_factor = 129,                   /* factor  */
  YYSYMBOL_130_35 = 130,                   /* $@35  */
  YYSYMBOL_functionCall = 131,             /* functionCall  */
  YYSYMBOL_argList = 132,                  /* argList  */
  YYSYMBOL_parameters = 133,               /* parameters  */
  YYSYMBOL_134_36 = 134,                   /* $@36  */
  YYSYMBOL_paramContinuer = 135,           /* paramContinuer  */
  YYSYMBOL_parameter = 136,                /* parameter  */
  YYSYMBOL_type = 137,                     /* type  */
  YYSYMBOL_compoundStatements = 138,       /* compoundStatements  */
  YYSYMBOL_statementList = 139,            /* statementList  */
  YYSYMBOL_140_37 = 140,                   /* $@37  */
  YYSYMBOL_returnDec = 141,                /* returnDec  */
  YYSYMBOL_dimension = 142                 /* dimension  */
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
#define YYLAST   518

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  217
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  427

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
       0,   224,   224,   226,   227,   228,   229,   231,   232,   233,
     234,   235,   236,   237,   239,   239,   240,   241,   242,   243,
     243,   243,   245,   246,   246,   247,   247,   249,   250,   251,
     252,   253,   254,   255,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   269,   269,   270,   270,   271,   272,
     272,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     284,   284,   284,   285,   285,   285,   286,   287,   289,   289,
     289,   290,   290,   290,   291,   291,   291,   292,   292,   293,
     295,   295,   295,   296,   297,   299,   299,   299,   300,   300,
     300,   301,   301,   301,   302,   302,   303,   305,   305,   305,
     306,   306,   307,   307,   307,   307,   308,   309,   310,   311,
     312,   313,   314,   314,   315,   318,   319,   321,   322,   323,
     324,   326,   327,   329,   330,   331,   332,   333,   334,   334,
     335,   335,   336,   336,   337,   338,   339,   340,   341,   342,
     343,   347,   348,   349,   350,   351,   352,   354,   355,   356,
     357,   358,   360,   361,   362,   363,   364,   366,   367,   368,
     369,   370,   372,   373,   375,   376,   378,   379,   380,   382,
     383,   384,   385,   386,   388,   389,   390,   392,   393,   394,
     395,   397,   398,   399,   400,   401,   402,   403,   404,   404,
     405,   406,   409,   410,   413,   414,   416,   416,   417,   418,
     420,   422,   423,   424,   426,   428,   428,   429,   430,   431,
     432,   433,   434,   436,   437,   439,   440,   441
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
  "scanner", "declarationStatement", "$@32", "$@33", "$@34", "arrayValues",
  "prattributes", "scattributes", "declarationListInt",
  "declarationListFloat", "declarationListChar", "expressionStatement",
  "logicalExpression", "expression", "relationalExpression", "value",
  "term", "factor", "$@35", "functionCall", "argList", "parameters",
  "$@36", "paramContinuer", "parameter", "type", "compoundStatements",
  "statementList", "$@37", "returnDec", "dimension", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-371)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-133)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -30,    28,    38,    47,   110,  -371,     5,     5,    89,
     109,   139,   116,   144,   123,   417,  -371,  -371,  -371,    98,
     117,    66,   417,  -371,  -371,   138,   133,   148,   175,  -371,
    -371,   154,   158,   157,   417,  -371,  -371,   417,   417,  -371,
    -371,  -371,   170,   192,   220,   227,   249,   206,   246,    43,
      53,  -371,   188,   196,   207,   125,   195,   222,    88,  -371,
     239,   241,   143,   252,   264,   151,  -371,   262,   265,   271,
     302,   282,  -371,   283,   277,   279,  -371,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     290,   290,  -371,  -371,  -371,  -371,   319,   293,   296,   304,
     306,    98,   290,   290,   320,   177,   138,   290,   290,   154,
    -371,  -371,   417,   315,  -371,  -371,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -371,   303,  -371,
    -371,   207,  -371,   318,    20,   299,  -371,  -371,  -371,   344,
     341,  -371,  -371,  -371,  -371,   349,   329,   328,   333,  -371,
     334,   335,    72,   336,   338,    55,   303,  -371,  -371,  -371,
     303,   410,  -371,   303,   303,  -371,  -371,  -371,   340,  -371,
    -371,  -371,   364,   366,   345,   342,  -371,   368,   417,  -371,
     343,   417,   351,  -371,   347,  -371,   380,   376,   379,   259,
    -371,  -371,  -371,  -371,  -371,  -371,   303,  -371,  -371,   358,
     387,  -371,  -371,  -371,   365,   370,    -6,  -371,  -371,  -371,
    -371,   417,   371,  -371,   393,   394,   400,   384,  -371,  -371,
    -371,  -371,   388,  -371,   381,   382,   417,  -371,   396,   397,
     389,   401,   419,   402,  -371,   424,  -371,   398,   404,   405,
     432,  -371,    -1,  -371,   393,   433,   411,   434,  -371,   398,
    -371,  -371,  -371,  -371,   417,   417,   413,  -371,  -371,  -371,
     331,   435,  -371,  -371,   394,  -371,  -371,   398,   398,   398,
     236,   253,   256,   423,   430,   369,   436,   451,   452,  -371,
    -371,  -371,  -371,  -371,  -371,   442,  -371,   441,  -371,   437,
    -371,  -371,  -371,    -4,  -371,  -371,  -371,    -6,  -371,    -6,
    -371,   417,    11,   456,   457,   369,   369,   438,   369,   369,
     369,   369,   417,  -371,  -371,   459,  -371,   102,  -371,   236,
     439,  -371,   398,  -371,  -371,   463,  -371,  -371,   331,   369,
     369,  -371,  -371,  -371,  -371,  -371,  -371,  -371,   443,  -371,
     444,   221,   462,   465,   435,  -371,   417,   398,  -371,   413,
     369,  -371,  -371,  -371,   447,   398,  -371,   445,   449,   398,
     398,  -371,   450,  -371,  -371,   453,   243,  -371,   469,   470,
     460,  -371,  -371,   455,   458,  -371,   369,   398,   398,   473,
    -371,   398,  -371,  -371,  -371,  -371,  -371,   398,  -371,   461,
    -371,   471,   263,   464,  -371,   466,    39,  -371,  -371,  -371,
     471,   417,   468,  -371,   331,  -371,   472,   417,   369,  -371,
     467,   474,  -371,  -371,   475,   476,  -371,   331,  -371,   369,
    -371,  -371,   481,   477,  -371,   481,  -371
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     5,   151,
       0,   161,     0,   156,     0,     0,     1,     4,     3,     0,
     196,     0,     0,   150,   134,     0,   196,     0,     0,   160,
     137,     0,   196,     0,     0,   155,   138,     0,     0,   184,
     185,   186,   181,     0,   163,   165,   168,   173,   176,   180,
     151,   148,     0,     0,     0,     0,     0,   149,   161,   158,
       0,     0,     0,     0,   159,   156,   153,     0,     0,     0,
     154,     0,   183,   188,     0,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,   203,   202,   197,   198,     0,     0,     0,
     215,     0,     0,     0,     0,   215,     0,     0,     0,     0,
     182,   187,     0,     0,   121,   162,   164,   166,   167,   169,
     170,   171,   172,   174,   175,   177,   178,   179,   212,   129,
     125,     0,   200,     0,     0,     0,   147,   133,   126,     0,
       0,   157,   131,   127,   152,   195,     0,   190,     0,    14,
       0,     0,     0,     0,     0,   181,   212,    17,    16,    18,
     212,   116,   119,   212,   212,   118,   117,   120,     0,   209,
     199,   217,     0,   142,     0,     0,   136,     0,     0,   189,
       0,     0,     0,    44,     0,   214,     0,     0,     0,     0,
     208,   207,   115,   120,   210,   211,   212,   204,   140,     0,
       0,   216,   135,   194,     0,     0,     0,    15,    21,    19,
      20,     0,     0,   213,   144,   146,   187,     0,   206,   141,
     139,   191,    63,    39,     0,     0,    41,    34,     0,     0,
       0,     0,     0,     0,   192,     0,    60,     0,     0,     0,
       0,    40,    49,    97,   144,     0,     0,     0,   193,    10,
      64,    11,    12,    13,     0,     0,     0,    48,    46,    45,
       0,   101,   143,   123,   146,   124,    61,    10,    10,    10,
      79,     0,     0,     0,     0,    59,     0,     0,     0,    27,
      50,    33,    18,    28,    29,   114,   100,     0,   145,     0,
       7,     8,     9,    77,    67,    65,    66,     0,    35,     0,
      37,     0,    25,     0,     0,    27,    59,     0,    33,    18,
      28,    29,     0,    30,    31,     0,    98,     0,   103,    79,
       0,    71,     0,    36,    38,    43,    22,    23,     0,    30,
      31,    53,    58,    47,    56,    57,    54,    55,     0,   112,
       0,     0,     0,     0,   105,    62,     0,    10,    78,     0,
      59,    26,    51,    52,    63,    10,    99,     0,     0,    10,
      10,   104,     0,    72,    42,     0,    60,   113,     0,     0,
     111,   109,   107,    74,     0,    24,    59,    10,    10,     0,
      68,     0,    73,    81,   108,   106,   110,    10,    75,     0,
      69,    79,    96,     0,    76,     0,    94,    84,    82,    83,
      79,     0,     0,    88,     0,    70,     0,     0,    59,    95,
       0,     0,    89,    80,    91,     0,    85,     0,    90,    59,
      92,    86,    96,     0,    93,    96,    87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -371,  -371,   276,  -225,  -320,   -96,  -371,  -371,  -371,  -371,
    -371,  -371,  -371,  -248,  -121,  -371,   145,  -371,  -371,  -371,
    -371,  -371,     4,  -264,  -371,  -371,  -371,  -371,   176,  -370,
    -371,  -371,  -371,  -371,  -371,  -371,  -371,  -256,  -371,  -371,
    -371,  -201,  -371,  -371,  -371,  -371,  -371,  -371,  -371,  -227,
    -371,  -371,  -371,   155,  -371,  -371,  -371,  -226,  -371,  -371,
     337,  -125,     1,  -371,  -371,   113,  -371,  -371,  -371,   308,
     257,   244,   -14,   -21,   -12,   -15,   440,   210,   160,   231,
     159,  -371,  -371,  -110,  -149,    83,  -371,   383,  -371,  -371,
      97,   -90,  -371,  -371,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,   370,   250,   305,   182,   207,   208,   209,
     350,   210,   328,   306,   226,   240,   274,   157,   211,   259,
     275,   260,   307,   158,   249,   289,   237,   270,   295,   296,
     387,   393,   347,   374,   381,   391,   322,   308,   376,   389,
     398,   399,   419,   423,   408,   415,   417,   422,   404,   159,
     261,   340,   285,   286,   287,   344,   318,   371,   316,   355,
     160,   310,   162,   163,   164,   165,    52,    67,    60,   174,
     231,   233,    10,    14,    12,   166,    44,    45,    46,    47,
      48,    49,   112,   311,   146,    53,    54,    95,    96,    97,
     129,   168,   196,   169,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,     7,   348,   161,   281,    51,   294,    57,     7,     7,
      66,   223,   280,    59,   224,   225,   257,     9,   167,    70,
     320,   394,    71,    72,   266,     1,     2,     3,   326,   203,
     405,   161,   156,   282,   321,   161,   161,   258,   161,   161,
     217,     4,   290,   291,   292,    29,   167,    35,   309,   327,
     167,   193,     4,   167,   167,   294,    87,    88,    89,   172,
     156,   388,   115,   402,   156,   173,   190,   156,   156,    19,
     191,   161,   281,   194,   195,    11,   114,   403,   309,   309,
     351,   309,   309,   309,   309,    13,   167,   136,   144,   185,
      15,   189,    29,    33,   141,    74,    22,   145,    15,    35,
     156,   282,   309,   309,    25,    19,   218,    55,    37,    61,
      16,    56,   252,     8,    38,    68,    39,    40,    41,    42,
       8,     8,   363,   309,   268,    20,    24,   253,    33,    21,
     367,    28,    22,    30,   372,   283,   397,   186,   341,   269,
      36,   251,   268,   268,   268,    50,   342,   343,   281,   309,
     284,   384,   385,   267,  -128,    25,   409,   269,   269,   269,
      31,   281,   390,   145,   279,    98,   205,    31,    99,   420,
    -132,   267,   267,   267,   145,    26,   323,   282,   324,    27,
      32,   309,    28,    98,    33,    58,   104,    34,   130,    62,
     282,    33,   309,    63,    34,  -130,   228,   252,    69,   137,
     138,    65,    56,   283,   142,   143,    73,   227,    75,    76,
      74,   241,   253,    81,    82,    83,    84,   135,   284,    64,
     140,   424,   268,    77,   426,    90,   251,    92,    93,    94,
     268,    78,   279,    91,   268,   268,   100,   269,   101,   271,
     272,   119,   120,   121,   122,   269,   125,   126,   127,   269,
     269,   267,   268,   268,    79,    80,   252,    85,    86,   267,
     148,   293,   268,   267,   267,   357,   358,   269,   269,   297,
     298,   253,   299,   300,   -80,   -80,   102,   269,   103,   283,
     106,   267,   267,    17,    18,   251,   325,   395,   396,   117,
     118,   267,   283,   105,   284,    37,   216,   338,   227,   107,
     227,    38,   108,    39,    40,    41,    42,   284,   279,   331,
     332,    98,   334,   335,   336,   337,   123,   124,   109,   110,
     111,   279,   113,     1,     2,     3,     4,   148,   128,   149,
     150,   362,   151,   352,   353,   131,   152,   153,   154,    37,
     132,   133,   134,   139,   175,    38,   135,    39,    40,    41,
     155,     1,     2,     3,   365,   276,   147,   149,   150,   171,
     151,   176,   277,   278,   177,   178,   179,    37,   180,   181,
     183,   184,   187,    38,   188,    39,    40,    41,   155,   197,
     383,   198,   199,   201,   200,   202,   406,   206,   204,     1,
       2,     3,   411,   276,   212,   149,   150,   213,   151,   214,
     303,   304,   215,   173,   220,    37,   221,   222,   229,   230,
     232,    38,   412,    39,    40,    41,   155,   234,     1,     2,
       3,   235,   148,   421,   149,   150,   236,   151,   238,   239,
       1,     2,     3,   242,    37,   243,   244,   246,   245,   247,
      38,   248,    39,    40,    41,   155,    37,   254,   255,   256,
     263,   265,    38,    37,    39,    40,    41,   155,   264,    38,
     273,    39,    40,    41,    42,  -102,   301,   302,   313,   314,
     315,   317,   312,   329,   330,   346,   319,   333,   339,   349,
     354,   359,   368,   356,   360,   366,   369,   373,   377,   378,
     386,   379,   375,   380,   364,   345,   293,   382,   192,   361,
     392,   262,   401,   400,   407,   413,   396,   219,   288,   410,
       0,   414,     0,   416,   170,   418,   425,     0,   116
};

static const yytype_int16 yycheck[] =
{
      15,     0,   322,   128,   260,    19,   270,    22,     7,     8,
      31,    17,   260,    25,    20,    21,    17,    47,   128,    34,
      24,   391,    37,    38,   249,    20,    21,    22,    17,   178,
     400,   156,   128,   260,    38,   160,   161,    38,   163,   164,
     189,    47,   267,   268,   269,    11,   156,    13,   275,    38,
     160,   161,    47,   163,   164,   319,    13,    14,    15,    39,
     156,   381,    77,    24,   160,    45,   156,   163,   164,    16,
     160,   196,   328,   163,   164,    47,    75,    38,   305,   306,
     328,   308,   309,   310,   311,    47,   196,   101,   109,    17,
      43,    36,    58,    40,   106,    40,    43,   112,    43,    65,
     196,   328,   329,   330,    16,    16,   196,    41,    36,    26,
       0,    45,   237,     0,    42,    32,    44,    45,    46,    47,
       7,     8,   347,   350,   249,    36,    17,   237,    40,    40,
     355,    43,    43,    17,   360,   260,   392,   152,    36,   249,
      17,   237,   267,   268,   269,    47,    44,    45,   404,   376,
     260,   377,   378,   249,    37,    16,   404,   267,   268,   269,
      16,   417,   387,   178,   260,    40,   181,    16,    43,   417,
      37,   267,   268,   269,   189,    36,   297,   404,   299,    40,
      36,   408,    43,    40,    40,    47,    43,    43,    91,    41,
     417,    40,   419,    45,    43,    37,   211,   322,    41,   102,
     103,    47,    45,   328,   107,   108,    36,   206,    16,    17,
      40,   226,   322,     7,     8,     9,    10,    40,   328,    44,
      43,   422,   347,     3,   425,    37,   322,    20,    21,    22,
     355,     4,   328,    37,   359,   360,    41,   347,    16,   254,
     255,    81,    82,    83,    84,   355,    87,    88,    89,   359,
     360,   347,   377,   378,     5,     6,   381,    11,    12,   355,
      24,    25,   387,   359,   360,    44,    45,   377,   378,    16,
      17,   381,    16,    17,    31,    32,    37,   387,    37,   404,
      16,   377,   378,     7,     8,   381,   301,    24,    25,    79,
      80,   387,   417,    41,   404,    36,    37,   312,   297,    37,
     299,    42,    37,    44,    45,    46,    47,   417,   404,   305,
     306,    40,   308,   309,   310,   311,    85,    86,    16,    37,
      37,   417,    45,    20,    21,    22,    47,    24,    38,    26,
      27,   346,    29,   329,   330,    16,    33,    34,    35,    36,
      47,    45,    38,    23,    45,    42,    40,    44,    45,    46,
      47,    20,    21,    22,   350,    24,    41,    26,    27,    41,
      29,    17,    31,    32,    23,    16,    37,    36,    40,    36,
      36,    36,    36,    42,    36,    44,    45,    46,    47,    39,
     376,    17,    16,    41,    39,    17,   401,    36,    45,    20,
      21,    22,   407,    24,    47,    26,    27,    17,    29,    23,
      31,    32,    23,    45,    17,    36,    41,    37,    37,    16,
      16,    42,   408,    44,    45,    46,    47,    17,    20,    21,
      22,    37,    24,   419,    26,    27,    38,    29,    47,    47,
      20,    21,    22,    37,    36,    38,    47,    18,    37,    37,
      42,    17,    44,    45,    46,    47,    36,    43,    43,    17,
      17,    17,    42,    36,    44,    45,    46,    47,    47,    42,
      47,    44,    45,    46,    47,    30,    43,    37,    17,    17,
      28,    30,    36,    17,    17,    36,    39,    39,    19,    16,
      37,    19,    37,    39,    19,    38,    37,    37,    19,    19,
      17,    31,    39,    38,   349,   319,    25,    39,   161,   344,
      39,   244,    36,    39,    36,    38,    25,   199,   264,    37,
      -1,    37,    -1,    38,   131,    39,    39,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    47,    49,    50,   110,   113,    47,
     120,    47,   122,    47,   121,    43,     0,    50,    50,    16,
      36,    40,    43,   142,    17,    16,    36,    40,    43,   142,
      17,    16,    36,    40,    43,   142,    17,    36,    42,    44,
      45,    46,    47,   123,   124,   125,   126,   127,   128,   129,
      47,   120,   114,   133,   134,    41,    45,   123,    47,   122,
     116,   133,    41,    45,    44,    47,   121,   115,   133,    41,
     123,   123,   123,    36,    40,    16,    17,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      37,    37,    20,    21,    22,   135,   136,   137,    40,    43,
      41,    16,    37,    37,    43,    41,    16,    37,    37,    16,
      37,    37,   130,    45,   110,   123,   124,   125,   125,   126,
     126,   126,   126,   127,   127,   128,   128,   128,    38,   138,
     138,    16,    47,    45,    38,    40,   120,   138,   138,    23,
      43,   122,   138,   138,   121,   123,   132,    41,    24,    26,
      27,    29,    33,    34,    35,    47,    53,    65,    71,    97,
     108,   109,   110,   111,   112,   113,   123,   131,   139,   141,
     135,    41,    39,    45,   117,    45,    17,    23,    16,    37,
      40,    36,    54,    36,    36,    17,   123,    36,    36,    36,
     139,   139,   108,   131,   139,   139,   140,    39,    17,    16,
      39,    41,    17,   132,    45,   123,    36,    55,    56,    57,
      59,    66,    47,    17,    23,    23,    37,   132,   139,   117,
      17,    41,    37,    17,    20,    21,    62,   110,   123,    37,
      16,   118,    16,   119,    17,    37,    38,    74,    47,    47,
      63,   123,    37,    38,    47,    37,    18,    37,    17,    72,
      52,    53,   109,   131,    43,    43,    17,    17,    38,    67,
      69,    98,   118,    17,    47,    17,    51,    53,   109,   131,
      75,   123,   123,    47,    64,    68,    24,    31,    32,    53,
      61,    85,    97,   109,   131,   100,   101,   102,   119,    73,
      51,    51,    51,    25,    71,    76,    77,    16,    17,    16,
      17,    43,    37,    31,    32,    53,    61,    70,    85,    97,
     109,   131,    36,    17,    17,    28,   106,    30,   104,    39,
      24,    38,    84,    62,    62,   123,    17,    38,    60,    17,
      17,    70,    70,    39,    70,    70,    70,    70,   123,    19,
      99,    36,    44,    45,   103,    76,    36,    80,    52,    16,
      58,    61,    70,    70,    37,   107,    39,    44,    45,    19,
      19,   101,   123,    51,    64,    70,    38,    51,    37,    37,
      51,   105,   105,    37,    81,    39,    86,    19,    19,    31,
      38,    82,    39,    70,   105,   105,    17,    78,    52,    87,
      51,    83,    39,    79,    77,    24,    25,    85,    88,    89,
      39,    36,    24,    38,    96,    77,   123,    36,    92,    61,
      37,   123,    70,    38,    37,    93,    38,    94,    39,    90,
      61,    70,    95,    91,    89,    39,    89
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
     109,   110,   110,   111,   112,   113,   113,   113,   114,   113,
     115,   113,   116,   113,   113,   113,   113,   113,   113,   113,
     113,   117,   117,   118,   118,   119,   119,   120,   120,   120,
     120,   120,   121,   121,   121,   121,   121,   122,   122,   122,
     122,   122,   123,   123,   124,   124,   125,   125,   125,   126,
     126,   126,   126,   126,   127,   127,   127,   128,   128,   128,
     128,   129,   129,   129,   129,   129,   129,   129,   130,   129,
     129,   129,   131,   131,   132,   132,   134,   133,   135,   135,
     136,   137,   137,   137,   138,   140,   139,   139,   139,   139,
     139,   139,   139,   141,   141,   142,   142,   142
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
       1,     5,     4,     6,     6,     6,     6,     6,     0,     6,
       0,     6,     0,     6,     3,     8,     7,     3,     3,     9,
       8,     3,     1,     3,     0,     4,     0,     5,     3,     3,
       2,     1,     5,     3,     3,     2,     1,     5,     3,     3,
       2,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     1,     3,     2,     1,     1,     1,     3,     0,     5,
       4,     7,     4,     5,     3,     1,     0,     2,     1,     3,
       2,     1,     1,     1,     3,     0,     3,     2,     2,     1,
       2,     2,     0,     3,     2,     3,     6,     5
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
#line 224 "SemanticAnalyzer.y"
                            {}
#line 1854 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 226 "SemanticAnalyzer.y"
                                                             {}
#line 1860 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 228 "SemanticAnalyzer.y"
                                                        {}
#line 1866 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 231 "SemanticAnalyzer.y"
                                              {}
#line 1872 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 232 "SemanticAnalyzer.y"
                                               {}
#line 1878 "y.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 239 "SemanticAnalyzer.y"
                            {pushNewScope();}
#line 1884 "y.tab.c"
    break;

  case 22: /* forLoop1: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON  */
#line 245 "SemanticAnalyzer.y"
                                                                                                          {popScope(); }
#line 1890 "y.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 246 "SemanticAnalyzer.y"
                                                                                                   {pushNewScope();}
#line 1896 "y.tab.c"
    break;

  case 24: /* forLoop2: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR $@2 inLoop CLCUR  */
#line 246 "SemanticAnalyzer.y"
                                                                                                                                  {popScope(); popScope(); }
#line 1902 "y.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 247 "SemanticAnalyzer.y"
                                                                                              {pushNewScope();}
#line 1908 "y.tab.c"
    break;

  case 26: /* forLoop3: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC $@3 singleLoopStatement  */
#line 247 "SemanticAnalyzer.y"
                                                                                                                                    {popScope(); popScope(); }
#line 1914 "y.tab.c"
    break;

  case 35: /* forAssignStatement: INT IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 258 "SemanticAnalyzer.y"
                                                                                             {}
#line 1920 "y.tab.c"
    break;

  case 44: /* $@4: %empty  */
#line 269 "SemanticAnalyzer.y"
                             {pushNewScope();}
#line 1926 "y.tab.c"
    break;

  case 46: /* $@5: %empty  */
#line 270 "SemanticAnalyzer.y"
                         {pushNewScope();}
#line 1932 "y.tab.c"
    break;

  case 47: /* whileSuffix: OPCUR $@5 inLoop CLCUR  */
#line 270 "SemanticAnalyzer.y"
                                                       { popScope(); popScope(); }
#line 1938 "y.tab.c"
    break;

  case 48: /* whileSuffix: SEMICOLON  */
#line 271 "SemanticAnalyzer.y"
                              {popScope(); printf("\nWHILE SEMICOLON \n");}
#line 1944 "y.tab.c"
    break;

  case 49: /* $@6: %empty  */
#line 272 "SemanticAnalyzer.y"
                    {pushNewScope();}
#line 1950 "y.tab.c"
    break;

  case 50: /* whileSuffix: $@6 singleLoopStatement  */
#line 272 "SemanticAnalyzer.y"
                                                          { popScope(); popScope();}
#line 1956 "y.tab.c"
    break;

  case 51: /* inLoop: BREAK SEMICOLON inLoop  */
#line 274 "SemanticAnalyzer.y"
                                     {}
#line 1962 "y.tab.c"
    break;

  case 52: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 275 "SemanticAnalyzer.y"
                                            {}
#line 1968 "y.tab.c"
    break;

  case 53: /* inLoop: specialStatement inLoop  */
#line 276 "SemanticAnalyzer.y"
                                          {}
#line 1974 "y.tab.c"
    break;

  case 54: /* inLoop: basicStatement inLoop  */
#line 277 "SemanticAnalyzer.y"
                                        {}
#line 1980 "y.tab.c"
    break;

  case 55: /* inLoop: functionCall inLoop  */
#line 278 "SemanticAnalyzer.y"
                                     {}
#line 1986 "y.tab.c"
    break;

  case 56: /* inLoop: ifInLoopStatement inLoop  */
#line 279 "SemanticAnalyzer.y"
                                           {}
#line 1992 "y.tab.c"
    break;

  case 57: /* inLoop: switchStatement inLoop  */
#line 280 "SemanticAnalyzer.y"
                                         {}
#line 1998 "y.tab.c"
    break;

  case 58: /* inLoop: singleLoopStatement inLoop  */
#line 281 "SemanticAnalyzer.y"
                                             {}
#line 2004 "y.tab.c"
    break;

  case 60: /* $@7: %empty  */
#line 284 "SemanticAnalyzer.y"
                                                              {pushNewScope();}
#line 2010 "y.tab.c"
    break;

  case 61: /* $@8: %empty  */
#line 284 "SemanticAnalyzer.y"
                                                                                           {popScope();}
#line 2016 "y.tab.c"
    break;

  case 63: /* $@9: %empty  */
#line 285 "SemanticAnalyzer.y"
                                                               {pushNewScope();}
#line 2022 "y.tab.c"
    break;

  case 64: /* $@10: %empty  */
#line 285 "SemanticAnalyzer.y"
                                                                                                 {popScope();}
#line 2028 "y.tab.c"
    break;

  case 68: /* $@11: %empty  */
#line 289 "SemanticAnalyzer.y"
                                                          {pushNewScope();}
#line 2034 "y.tab.c"
    break;

  case 69: /* $@12: %empty  */
#line 289 "SemanticAnalyzer.y"
                                                                                       {popScope();}
#line 2040 "y.tab.c"
    break;

  case 71: /* $@13: %empty  */
#line 290 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 2046 "y.tab.c"
    break;

  case 72: /* $@14: %empty  */
#line 290 "SemanticAnalyzer.y"
                                                  {popScope();}
#line 2052 "y.tab.c"
    break;

  case 74: /* $@15: %empty  */
#line 291 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 2058 "y.tab.c"
    break;

  case 75: /* $@16: %empty  */
#line 291 "SemanticAnalyzer.y"
                                                                                     {popScope();}
#line 2064 "y.tab.c"
    break;

  case 77: /* $@17: %empty  */
#line 292 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 2070 "y.tab.c"
    break;

  case 78: /* ES: ELSE $@17 singleStatement  */
#line 292 "SemanticAnalyzer.y"
                                                 {popScope();}
#line 2076 "y.tab.c"
    break;

  case 80: /* $@18: %empty  */
#line 295 "SemanticAnalyzer.y"
                                                                    {pushNewScope();}
#line 2082 "y.tab.c"
    break;

  case 81: /* $@19: %empty  */
#line 295 "SemanticAnalyzer.y"
                                                                                             {popScope;}
#line 2088 "y.tab.c"
    break;

  case 85: /* $@20: %empty  */
#line 299 "SemanticAnalyzer.y"
                                                              {pushNewScope();}
#line 2094 "y.tab.c"
    break;

  case 86: /* $@21: %empty  */
#line 299 "SemanticAnalyzer.y"
                                                                                       {popScope();}
#line 2100 "y.tab.c"
    break;

  case 88: /* $@22: %empty  */
#line 300 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 2106 "y.tab.c"
    break;

  case 89: /* $@23: %empty  */
#line 300 "SemanticAnalyzer.y"
                                              {popScope();}
#line 2112 "y.tab.c"
    break;

  case 91: /* $@24: %empty  */
#line 301 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 2118 "y.tab.c"
    break;

  case 92: /* $@25: %empty  */
#line 301 "SemanticAnalyzer.y"
                                                                                         {popScope();}
#line 2124 "y.tab.c"
    break;

  case 94: /* $@26: %empty  */
#line 302 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 2130 "y.tab.c"
    break;

  case 95: /* ESLoop: ELSE $@26 singleLoopStatement  */
#line 302 "SemanticAnalyzer.y"
                                                     {popScope();}
#line 2136 "y.tab.c"
    break;

  case 97: /* $@27: %empty  */
#line 305 "SemanticAnalyzer.y"
                                                             {pushNewScope();}
#line 2142 "y.tab.c"
    break;

  case 98: /* $@28: %empty  */
#line 305 "SemanticAnalyzer.y"
                                                                                                               {popScope();}
#line 2148 "y.tab.c"
    break;

  case 99: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR $@27 caseStatements defaultStatement $@28 CLCUR  */
#line 305 "SemanticAnalyzer.y"
                                                                                                                                   {}
#line 2154 "y.tab.c"
    break;

  case 101: /* caseStatements: %empty  */
#line 306 "SemanticAnalyzer.y"
                                         {}
#line 2160 "y.tab.c"
    break;

  case 102: /* $@29: %empty  */
#line 307 "SemanticAnalyzer.y"
                        {pushNewScope();}
#line 2166 "y.tab.c"
    break;

  case 103: /* $@30: %empty  */
#line 307 "SemanticAnalyzer.y"
                                                  {pushNewScope();}
#line 2172 "y.tab.c"
    break;

  case 105: /* caseStatementInt: %empty  */
#line 307 "SemanticAnalyzer.y"
                                                                                       {}
#line 2178 "y.tab.c"
    break;

  case 107: /* caseInt: CASE INTVAL COLON caseContinuer  */
#line 309 "SemanticAnalyzer.y"
                                                  {}
#line 2184 "y.tab.c"
    break;

  case 112: /* $@31: %empty  */
#line 314 "SemanticAnalyzer.y"
                                      {pushNewScope();}
#line 2190 "y.tab.c"
    break;

  case 113: /* defaultStatement: DEFAULT COLON $@31 statements  */
#line 314 "SemanticAnalyzer.y"
                                                                   {popScope();}
#line 2196 "y.tab.c"
    break;

  case 114: /* defaultStatement: %empty  */
#line 315 "SemanticAnalyzer.y"
                                          {}
#line 2202 "y.tab.c"
    break;

  case 117: /* basicStatement: expressionStatement  */
#line 321 "SemanticAnalyzer.y"
                                          {}
#line 2208 "y.tab.c"
    break;

  case 118: /* basicStatement: declarationStatement  */
#line 322 "SemanticAnalyzer.y"
                                       {}
#line 2214 "y.tab.c"
    break;

  case 119: /* basicStatement: assignmentStatement  */
#line 323 "SemanticAnalyzer.y"
                                        {}
#line 2220 "y.tab.c"
    break;

  case 121: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 326 "SemanticAnalyzer.y"
                                                                                          {}
#line 2226 "y.tab.c"
    break;

  case 122: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 327 "SemanticAnalyzer.y"
                                                                 {}
#line 2232 "y.tab.c"
    break;

  case 125: /* declarationStatement: INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 331 "SemanticAnalyzer.y"
                                                                                        {int inst = getIdentifierIndex((yyvsp[-4].Str),false,true); if(inst == -1){insertInTable((yyvsp[-4].Str),strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);}else{printf("%s is already defined earlier\n",(yyvsp[-4].Str));return 1;}memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2238 "y.tab.c"
    break;

  case 126: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 332 "SemanticAnalyzer.y"
                                                                                {int inst = getIdentifierIndex((yyvsp[-4].Str),false,true); if(inst ==-1){insertInTable((yyvsp[-4].Str),strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-4].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2244 "y.tab.c"
    break;

  case 127: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 333 "SemanticAnalyzer.y"
                                                                                {int inst = getIdentifierIndex((yyvsp[-4].Str),false,true); if(inst == -1){insertInTable((yyvsp[-4].Str),strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-4].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2250 "y.tab.c"
    break;

  case 128: /* $@32: %empty  */
#line 334 "SemanticAnalyzer.y"
                                         {pushNewScope();}
#line 2256 "y.tab.c"
    break;

  case 129: /* declarationStatement: INT IDENTIFIER OPBRAC $@32 CLBRAC compoundStatements  */
#line 334 "SemanticAnalyzer.y"
                                                                                     {int inst = getIdentifierIndex((yyvsp[-4].Str),false,true); if(inst == -1){insertInTable((yyvsp[-4].Str),strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-4].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2262 "y.tab.c"
    break;

  case 130: /* $@33: %empty  */
#line 335 "SemanticAnalyzer.y"
                                           {pushNewScope();}
#line 2268 "y.tab.c"
    break;

  case 131: /* declarationStatement: FLOAT IDENTIFIER OPBRAC $@33 CLBRAC compoundStatements  */
#line 335 "SemanticAnalyzer.y"
                                                                                        {int inst = getIdentifierIndex((yyvsp[-4].Str),false,true); if(inst == -1){insertInTable((yyvsp[-4].Str),strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-4].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2274 "y.tab.c"
    break;

  case 132: /* $@34: %empty  */
#line 336 "SemanticAnalyzer.y"
                                          {pushNewScope();}
#line 2280 "y.tab.c"
    break;

  case 133: /* declarationStatement: CHAR IDENTIFIER OPBRAC $@34 CLBRAC compoundStatements  */
#line 336 "SemanticAnalyzer.y"
                                                                                       {int inst = getIdentifierIndex((yyvsp[-4].Str),false,true); if(inst == -1){insertInTable((yyvsp[-4].Str),strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-4].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2286 "y.tab.c"
    break;

  case 134: /* declarationStatement: INT declarationListInt SEMICOLON  */
#line 337 "SemanticAnalyzer.y"
                                                   {}
#line 2292 "y.tab.c"
    break;

  case 139: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON  */
#line 342 "SemanticAnalyzer.y"
                                                                                          {}
#line 2298 "y.tab.c"
    break;

  case 140: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON  */
#line 343 "SemanticAnalyzer.y"
                                                                              {}
#line 2304 "y.tab.c"
    break;

  case 147: /* declarationListInt: IDENTIFIER EQUAL expressionStatement COMMA declarationListInt  */
#line 354 "SemanticAnalyzer.y"
                                                                                        {printf("DSL1..\n");}
#line 2310 "y.tab.c"
    break;

  case 148: /* declarationListInt: IDENTIFIER COMMA declarationListInt  */
#line 355 "SemanticAnalyzer.y"
                                                      { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2316 "y.tab.c"
    break;

  case 149: /* declarationListInt: IDENTIFIER EQUAL expressionStatement  */
#line 356 "SemanticAnalyzer.y"
                                                       {}
#line 2322 "y.tab.c"
    break;

  case 150: /* declarationListInt: IDENTIFIER dimension  */
#line 357 "SemanticAnalyzer.y"
                                        {if(checkVariable((yyvsp[-1].Str),currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-1].Str));return 1;}insertInTable((yyvsp[-1].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2328 "y.tab.c"
    break;

  case 151: /* declarationListInt: IDENTIFIER  */
#line 358 "SemanticAnalyzer.y"
                             { if(checkVariable((yyvsp[0].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[0].Str));return 1;}insertInTable((yyvsp[0].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2334 "y.tab.c"
    break;

  case 152: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListFloat  */
#line 360 "SemanticAnalyzer.y"
                                                                                            {printf("DSL1..\n");}
#line 2340 "y.tab.c"
    break;

  case 153: /* declarationListFloat: IDENTIFIER COMMA declarationListFloat  */
#line 361 "SemanticAnalyzer.y"
                                                        { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2346 "y.tab.c"
    break;

  case 154: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement  */
#line 362 "SemanticAnalyzer.y"
                                                       {printf("DSL3..\n");}
#line 2352 "y.tab.c"
    break;

  case 155: /* declarationListFloat: IDENTIFIER dimension  */
#line 363 "SemanticAnalyzer.y"
                                        {if(checkVariable((yyvsp[-1].Str),currScope,true,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-1].Str));return 1;}insertInTable((yyvsp[-1].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2358 "y.tab.c"
    break;

  case 156: /* declarationListFloat: IDENTIFIER  */
#line 364 "SemanticAnalyzer.y"
                             { if(checkVariable((yyvsp[0].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[0].Str));return 1;}insertInTable((yyvsp[0].Str),strdup("f"),strdup("f"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2364 "y.tab.c"
    break;

  case 158: /* declarationListChar: IDENTIFIER COMMA declarationListChar  */
#line 367 "SemanticAnalyzer.y"
                                                       { if(checkVariable((yyvsp[-2].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-2].Str));return 1;}insertInTable((yyvsp[-2].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2370 "y.tab.c"
    break;

  case 160: /* declarationListChar: IDENTIFIER dimension  */
#line 369 "SemanticAnalyzer.y"
                                       {if(checkVariable((yyvsp[-1].Str),currScope,true,true)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[-1].Str));return 1;}insertInTable((yyvsp[-1].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2376 "y.tab.c"
    break;

  case 161: /* declarationListChar: IDENTIFIER  */
#line 370 "SemanticAnalyzer.y"
                             { if(checkVariable((yyvsp[0].Str),currScope,false,false)){printf("MULTIPLE DECLARATIONS %s\n\n",(yyvsp[0].Str));return 1;}insertInTable((yyvsp[0].Str),strdup("c"),strdup("c"),currScope, -1,NULL,sizes,instDim,false,false);}
#line 2382 "y.tab.c"
    break;

  case 162: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 372 "SemanticAnalyzer.y"
                                                                           {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2388 "y.tab.c"
    break;

  case 163: /* expressionStatement: logicalExpression  */
#line 373 "SemanticAnalyzer.y"
                                    {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2394 "y.tab.c"
    break;

  case 164: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 375 "SemanticAnalyzer.y"
                                                                 {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2400 "y.tab.c"
    break;

  case 165: /* logicalExpression: expression  */
#line 376 "SemanticAnalyzer.y"
                             {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2406 "y.tab.c"
    break;

  case 166: /* expression: relationalExpression EQUALS expression  */
#line 378 "SemanticAnalyzer.y"
                                                         {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2412 "y.tab.c"
    break;

  case 167: /* expression: relationalExpression NOTEQUAL expression  */
#line 379 "SemanticAnalyzer.y"
                                                           {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2418 "y.tab.c"
    break;

  case 168: /* expression: relationalExpression  */
#line 380 "SemanticAnalyzer.y"
                                       {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2424 "y.tab.c"
    break;

  case 169: /* relationalExpression: value GREATERTHAN relationalExpression  */
#line 382 "SemanticAnalyzer.y"
                                                                   {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2430 "y.tab.c"
    break;

  case 170: /* relationalExpression: value GREATERTHANEQUALTO relationalExpression  */
#line 383 "SemanticAnalyzer.y"
                                                                {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2436 "y.tab.c"
    break;

  case 171: /* relationalExpression: value LESSTHAN relationalExpression  */
#line 384 "SemanticAnalyzer.y"
                                                      {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2442 "y.tab.c"
    break;

  case 172: /* relationalExpression: value LESSTHANEQUALTO relationalExpression  */
#line 385 "SemanticAnalyzer.y"
                                                             {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2448 "y.tab.c"
    break;

  case 173: /* relationalExpression: value  */
#line 386 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2454 "y.tab.c"
    break;

  case 174: /* value: term ADD value  */
#line 388 "SemanticAnalyzer.y"
                            {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2460 "y.tab.c"
    break;

  case 175: /* value: term SUB value  */
#line 389 "SemanticAnalyzer.y"
                         {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2466 "y.tab.c"
    break;

  case 176: /* value: term  */
#line 390 "SemanticAnalyzer.y"
               {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2472 "y.tab.c"
    break;

  case 177: /* term: factor MULT term  */
#line 392 "SemanticAnalyzer.y"
                             {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2478 "y.tab.c"
    break;

  case 178: /* term: factor DIV term  */
#line 393 "SemanticAnalyzer.y"
                          {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2484 "y.tab.c"
    break;

  case 179: /* term: factor MOD term  */
#line 394 "SemanticAnalyzer.y"
                          {if(strcmp((yyvsp[-2].Str),(yyvsp[0].Str))==0){(yyval.Str) = strdup((yyvsp[-2].Str));}else{printf("TYPES dont match\n\n");return 1;}}
#line 2490 "y.tab.c"
    break;

  case 180: /* term: factor  */
#line 395 "SemanticAnalyzer.y"
                 {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2496 "y.tab.c"
    break;

  case 181: /* factor: IDENTIFIER  */
#line 397 "SemanticAnalyzer.y"
                         {int inst = checkVariableScope((yyvsp[0].Str),currScope,false,false); if(inst!=-1){(yyval.Str) = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",(yyvsp[0].Str));return 1;}}
#line 2502 "y.tab.c"
    break;

  case 182: /* factor: OPBRAC expressionStatement CLBRAC  */
#line 398 "SemanticAnalyzer.y"
                                            {(yyval.Str) = strdup((yyvsp[-1].Str));}
#line 2508 "y.tab.c"
    break;

  case 183: /* factor: LOGICALNOT expressionStatement  */
#line 399 "SemanticAnalyzer.y"
                                         {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2514 "y.tab.c"
    break;

  case 184: /* factor: CHARVAL  */
#line 400 "SemanticAnalyzer.y"
                  {(yyval.Str) = strdup("c");}
#line 2520 "y.tab.c"
    break;

  case 185: /* factor: INTVAL  */
#line 401 "SemanticAnalyzer.y"
                 {(yyval.Str) = strdup("i");printf("INT VALS.. %d\n",yylval);}
#line 2526 "y.tab.c"
    break;

  case 186: /* factor: FLOATVAL  */
#line 402 "SemanticAnalyzer.y"
                   {(yyval.Str) = strdup("f");}
#line 2532 "y.tab.c"
    break;

  case 187: /* factor: IDENTIFIER OPBRAC CLBRAC  */
#line 403 "SemanticAnalyzer.y"
                                   {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0; int inst = getIdentifierIndex((yyvsp[-2].Str),false,true);if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){(yyval.Str) = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}}
#line 2538 "y.tab.c"
    break;

  case 188: /* $@35: %empty  */
#line 404 "SemanticAnalyzer.y"
                            {memset(arglistArray,'\0',sizeof(arglistArray));argindex=0;}
#line 2544 "y.tab.c"
    break;

  case 189: /* factor: IDENTIFIER OPBRAC $@35 argList CLBRAC  */
#line 404 "SemanticAnalyzer.y"
                                                                                                        {int inst = getIdentifierIndex((yyvsp[-4].Str),false,true); if(compareParam(arglistArray,table[inst].parameterList,argindex,table[inst].parameterCount)){(yyval.Str) = strdup(table[inst].dataType);}else{printf("PARAMETERS DONT MATCH");return 1;}}
#line 2550 "y.tab.c"
    break;

  case 190: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE  */
#line 405 "SemanticAnalyzer.y"
                                             {int inst = checkVariableScope((yyvsp[-3].Str),currScope,true,false); if(inst!=-1){(yyval.Str) = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",(yyvsp[-3].Str));return 1;}}
#line 2556 "y.tab.c"
    break;

  case 191: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 406 "SemanticAnalyzer.y"
                                                                     {int inst = checkVariableScope((yyvsp[-6].Str),currScope,true,false); if(inst!=-1){(yyval.Str) = strdup(table[inst].dataType);}else{printf("Variable %s not found\n\n",(yyvsp[-6].Str));return 1;}}
#line 2562 "y.tab.c"
    break;

  case 192: /* functionCall: IDENTIFIER OPBRAC CLBRAC SEMICOLON  */
#line 409 "SemanticAnalyzer.y"
                                                      {}
#line 2568 "y.tab.c"
    break;

  case 193: /* functionCall: IDENTIFIER OPBRAC argList CLBRAC SEMICOLON  */
#line 410 "SemanticAnalyzer.y"
                                                              {}
#line 2574 "y.tab.c"
    break;

  case 194: /* argList: expressionStatement COMMA argList  */
#line 413 "SemanticAnalyzer.y"
                                                 {arglistArray[argindex++]=strdup((yyvsp[-2].Str));}
#line 2580 "y.tab.c"
    break;

  case 195: /* argList: expressionStatement  */
#line 414 "SemanticAnalyzer.y"
                                      {arglistArray[argindex++]=strdup((yyvsp[0].Str));}
#line 2586 "y.tab.c"
    break;

  case 196: /* $@36: %empty  */
#line 416 "SemanticAnalyzer.y"
                  {pushNewScope(); memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2592 "y.tab.c"
    break;

  case 199: /* paramContinuer: parameter COMMA paramContinuer  */
#line 418 "SemanticAnalyzer.y"
                                                                  {printf("FUNCTION params\n");}
#line 2598 "y.tab.c"
    break;

  case 200: /* parameter: type IDENTIFIER  */
#line 420 "SemanticAnalyzer.y"
                                 {printf("FUNCTION param\n");insertInTable((yyvsp[0].Str),(yyvsp[-1].Str),(yyvsp[-1].Str),currScope,0,NULL,NULL,0,false,false);}
#line 2604 "y.tab.c"
    break;

  case 201: /* type: INT  */
#line 422 "SemanticAnalyzer.y"
                {(yyval.Str) = strdup("i");instanceParamList[currentParamCount++]=strdup("i");}
#line 2610 "y.tab.c"
    break;

  case 202: /* type: FLOAT  */
#line 423 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup("f");instanceParamList[currentParamCount++]=strdup("f");}
#line 2616 "y.tab.c"
    break;

  case 203: /* type: CHAR  */
#line 424 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup("c");instanceParamList[currentParamCount++]=strdup("c");}
#line 2622 "y.tab.c"
    break;

  case 204: /* compoundStatements: OPCUR statementList CLCUR  */
#line 426 "SemanticAnalyzer.y"
                                                    {popScope();printf("FUNCTION statements\n");}
#line 2628 "y.tab.c"
    break;

  case 205: /* $@37: %empty  */
#line 428 "SemanticAnalyzer.y"
                                  {printf("checked if function call");}
#line 2634 "y.tab.c"
    break;

  case 206: /* statementList: functionCall $@37 statementList  */
#line 428 "SemanticAnalyzer.y"
                                                                                     {printf("direct function call in list");}
#line 2640 "y.tab.c"
    break;

  case 213: /* returnDec: RETURN expressionStatement SEMICOLON  */
#line 436 "SemanticAnalyzer.y"
                                                      {(yyval.Str) = strdup((yyvsp[-1].Str));}
#line 2646 "y.tab.c"
    break;

  case 215: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 439 "SemanticAnalyzer.y"
                                         {int i = (yyvsp[-1].Int); if(i<=0){printf("Array size has to be  Positive\n"); return 1;}sizes[0] = (yyvsp[-1].Int);instDim++;}
#line 2652 "y.tab.c"
    break;

  case 216: /* dimension: BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 440 "SemanticAnalyzer.y"
                                                                    {int a = (yyvsp[-4].Int); int b = (yyvsp[-1].Int); if(a<=0||b<=0){printf("Array sizes has to be  Positive\n"); return 1;}sizes[0] = (yyvsp[-4].Int); sizes[1] = (yyvsp[-1].Int);instDim+=2;}
#line 2658 "y.tab.c"
    break;

  case 217: /* dimension: BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 441 "SemanticAnalyzer.y"
                                                             {int i = (yyvsp[-1].Int); if(i<=0){printf("Array sizes has to be  Positive\n"); return 1;}sizes[1] = (yyvsp[-1].Int);instDim+=2;}
#line 2664 "y.tab.c"
    break;


#line 2668 "y.tab.c"

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

#line 442 "SemanticAnalyzer.y"

      
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
      
      
