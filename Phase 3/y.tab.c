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
#line 1 "AST.y"

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
 	struct symbolTable table[1000];
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
 

#line 317 "y.tab.c"

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
#line 246 "AST.y"

		int Int;
		float Float;
		char Char;
		char* Str;
		struct data{
 
		};
	

#line 475 "y.tab.c"

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
  YYSYMBOL_singleLoopStatement = 54,       /* singleLoopStatement  */
  YYSYMBOL_whileLoop = 55,                 /* whileLoop  */
  YYSYMBOL_whileSuffix = 56,               /* whileSuffix  */
  YYSYMBOL_inLoop = 57,                    /* inLoop  */
  YYSYMBOL_ifStatement = 58,               /* ifStatement  */
  YYSYMBOL_ifContinuer = 59,               /* ifContinuer  */
  YYSYMBOL_ES = 60,                        /* ES  */
  YYSYMBOL_ifInLoopStatement = 61,         /* ifInLoopStatement  */
  YYSYMBOL_ifInLoopContinuer = 62,         /* ifInLoopContinuer  */
  YYSYMBOL_ESLoop = 63,                    /* ESLoop  */
  YYSYMBOL_switchStatement = 64,           /* switchStatement  */
  YYSYMBOL_caseStatements = 65,            /* caseStatements  */
  YYSYMBOL_caseStatementInt = 66,          /* caseStatementInt  */
  YYSYMBOL_caseInt = 67,                   /* caseInt  */
  YYSYMBOL_caseContinuer = 68,             /* caseContinuer  */
  YYSYMBOL_defaultStatement = 69,          /* defaultStatement  */
  YYSYMBOL_basicStatements = 70,           /* basicStatements  */
  YYSYMBOL_basicStatement = 71,            /* basicStatement  */
  YYSYMBOL_assignmentStatement = 72,       /* assignmentStatement  */
  YYSYMBOL_printer = 73,                   /* printer  */
  YYSYMBOL_Scanner = 74,                   /* Scanner  */
  YYSYMBOL_declarationStatement = 75,      /* declarationStatement  */
  YYSYMBOL_arrayValuesF = 76,              /* arrayValuesF  */
  YYSYMBOL_arrayValues = 77,               /* arrayValues  */
  YYSYMBOL_prattributes = 78,              /* prattributes  */
  YYSYMBOL_scattributes = 79,              /* scattributes  */
  YYSYMBOL_declarationListInt = 80,        /* declarationListInt  */
  YYSYMBOL_declarationListFloat = 81,      /* declarationListFloat  */
  YYSYMBOL_declarationListChar = 82,       /* declarationListChar  */
  YYSYMBOL_expressionStatement = 83,       /* expressionStatement  */
  YYSYMBOL_logicalExpression = 84,         /* logicalExpression  */
  YYSYMBOL_expression = 85,                /* expression  */
  YYSYMBOL_relationalExpression = 86,      /* relationalExpression  */
  YYSYMBOL_value = 87,                     /* value  */
  YYSYMBOL_term = 88,                      /* term  */
  YYSYMBOL_factor = 89,                    /* factor  */
  YYSYMBOL_functionCall = 90,              /* functionCall  */
  YYSYMBOL_argList = 91,                   /* argList  */
  YYSYMBOL_parameters = 92,                /* parameters  */
  YYSYMBOL_paramContinuer = 93,            /* paramContinuer  */
  YYSYMBOL_parameter = 94,                 /* parameter  */
  YYSYMBOL_type = 95,                      /* type  */
  YYSYMBOL_compoundStatements = 96,        /* compoundStatements  */
  YYSYMBOL_statementList = 97,             /* statementList  */
  YYSYMBOL_returnDec = 98,                 /* returnDec  */
  YYSYMBOL_dimension = 99                  /* dimension  */
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
#define YYLAST   688

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  386

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
       0,   290,   290,   292,   293,   294,   295,   297,   298,   299,
     300,   301,   302,   303,   306,   307,   308,   319,   320,   321,
     322,   323,   324,   325,   338,   340,   341,   342,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   356,
     357,   359,   360,   362,   363,   364,   365,   365,   367,   367,
     367,   369,   370,   371,   372,   372,   374,   376,   377,   379,
     380,   382,   383,   384,   385,   387,   388,   390,   391,   394,
     395,   397,   398,   399,   399,   401,   402,   402,   403,   405,
     406,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   420,   421,   424,   425,   427,   428,
     430,   431,   433,   434,   436,   437,   438,   439,   440,   442,
     443,   444,   445,   446,   448,   449,   450,   451,   452,   454,
     455,   457,   458,   460,   461,   462,   464,   465,   466,   467,
     468,   470,   471,   472,   474,   475,   476,   477,   479,   480,
     481,   482,   483,   484,   484,   484,   485,   486,   489,   490,
     493,   494,   496,   497,   498,   500,   502,   503,   504,   506,
     508,   509,   510,   511,   512,   513,   514,   516,   517,   519,
     520,   521
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
  "singleLoopStatement", "whileLoop", "whileSuffix", "inLoop",
  "ifStatement", "ifContinuer", "ES", "ifInLoopStatement",
  "ifInLoopContinuer", "ESLoop", "switchStatement", "caseStatements",
  "caseStatementInt", "caseInt", "caseContinuer", "defaultStatement",
  "basicStatements", "basicStatement", "assignmentStatement", "printer",
  "Scanner", "declarationStatement", "arrayValuesF", "arrayValues",
  "prattributes", "scattributes", "declarationListInt",
  "declarationListFloat", "declarationListChar", "expressionStatement",
  "logicalExpression", "expression", "relationalExpression", "value",
  "term", "factor", "functionCall", "argList", "parameters",
  "paramContinuer", "parameter", "type", "compoundStatements",
  "statementList", "returnDec", "dimension", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-333)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-171)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -30,     2,    10,   133,    47,  -333,     7,     7,    -6,
      16,     0,    53,     5,    84,   116,   285,    60,  -333,  -333,
    -333,    72,    45,   166,   285,  -333,  -333,    86,   101,   225,
     641,  -333,  -333,    93,   172,   228,   285,  -333,  -333,   105,
     109,   285,   285,  -333,  -333,  -333,   240,   219,   160,   171,
     253,   287,   256,   203,   285,    34,  -333,  -333,  -333,  -333,
     208,   161,  -333,   235,   194,   144,   237,    64,  -333,   208,
     238,   157,   311,   310,  -333,    69,  -333,   208,   291,   165,
     341,   321,   329,   342,  -333,   183,   345,   350,  -333,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   274,   338,  -333,   208,   319,  -333,   360,    72,
    -333,   208,   376,   234,    86,  -333,   208,   362,    93,   361,
     356,  -333,  -333,   387,   367,   365,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
     350,  -333,   372,   379,   380,   168,   381,   382,    43,   338,
    -333,  -333,  -333,   338,   218,  -333,   338,   338,  -333,  -333,
     338,   386,  -333,  -333,  -333,    39,  -333,  -333,   402,   397,
    -333,  -333,    59,  -333,  -333,   385,   285,  -333,   390,  -333,
     285,   285,   374,  -333,   418,   414,   417,   278,   248,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,   424,   426,   405,
    -333,   429,   430,   432,   411,  -333,  -333,   413,   423,   431,
     436,  -333,  -333,   445,   446,   437,   442,  -333,   427,   461,
    -333,  -333,   438,   468,   448,   522,   407,   453,    -5,   474,
     457,  -333,   482,   258,  -333,  -333,  -333,  -333,  -333,   634,
     284,  -333,  -333,  -333,  -333,   464,   484,   486,   435,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,   476,   285,   492,   470,
     502,  -333,   475,   483,   634,   634,   634,   550,  -333,  -333,
    -333,   285,  -333,  -333,   507,   510,   435,   435,   489,   435,
     435,   435,   435,   435,   435,   198,   501,  -333,   476,  -333,
    -333,   445,  -333,   490,   284,  -333,  -333,  -333,   497,   634,
    -333,   498,   435,   435,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,   302,   515,   518,   526,   508,  -333,  -333,
     505,  -333,   285,   511,   578,  -333,  -333,   516,   517,   634,
     634,   634,  -333,   519,  -333,   435,   533,   536,   528,  -333,
    -333,  -333,   606,   435,   523,   435,   435,   634,   634,   540,
     634,   284,   294,  -333,  -333,  -333,   524,  -333,   525,   466,
    -333,  -333,  -333,   284,   285,   529,   435,  -333,  -333,   538,
     285,   534,   542,   539,  -333,   435,   494,   435,  -333,   553,
    -333,  -333,   543,  -333,   294,  -333
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     5,   108,
       0,   118,     0,   113,     0,     0,     0,     0,     1,     4,
       3,     0,     0,     0,     0,   107,    87,     0,     0,     0,
       0,   117,    90,     0,     0,     0,     0,   112,    91,     0,
       0,     0,     0,   141,   142,   143,   138,     0,   120,   122,
     125,   130,   133,   137,     0,   108,   105,   156,   158,   157,
       0,     0,   152,   153,     0,     0,   106,   118,   115,     0,
       0,     0,     0,   141,   116,   113,   110,     0,     0,     0,
     111,     0,   169,     0,   140,     0,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,    84,     0,     0,   155,     0,     0,
      86,     0,     0,   169,     0,    85,     0,     0,     0,     0,
       0,   139,   144,   151,     0,     0,    75,   119,   121,   123,
     124,   126,   127,   128,   129,   131,   132,   134,   135,   136,
       0,    78,     0,     0,     0,     0,     0,     0,   138,   166,
      15,    14,    16,   166,    70,    73,   166,   166,    72,    71,
      74,     0,   163,    81,   154,     0,   104,    82,     0,     0,
     114,    83,     0,   109,   171,     0,     0,   145,   146,    77,
       0,     0,     0,   168,     0,     0,     0,     0,     0,   162,
     161,    69,    74,   164,   165,   160,   159,     0,    99,     0,
      89,     0,     0,    97,     0,   170,   150,     0,     0,     0,
       0,   167,   101,   103,   144,     0,     0,    93,     0,     0,
      88,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,   145,   146,    98,    92,    96,    94,   147,    10,
      47,    11,    12,    13,    26,     0,     0,     0,    38,    17,
      27,    24,    23,    16,    18,    19,    58,     0,     0,     0,
       0,   149,     0,     0,    10,    10,    10,     0,    42,    40,
      41,     0,    20,    21,     0,     0,    17,    38,     0,    23,
      16,    18,    38,    38,    19,     0,    68,    57,    60,   100,
      79,   103,    80,     0,    47,     7,     8,     9,     0,    10,
      46,     0,    20,    21,    30,    35,    25,    33,    34,    31,
      36,    37,    32,     0,     0,     0,     0,     0,    59,   102,
     147,    39,     0,     0,     0,    28,    29,     0,     0,    10,
      10,    10,    56,     0,    44,    10,     0,     0,    66,    64,
      62,    67,     0,    10,     0,    10,    10,    10,    10,     0,
      10,    47,    55,    63,    61,    65,     0,    41,     0,     0,
      50,    48,    49,    47,     0,     0,    38,    54,    41,     0,
       0,     0,     0,     0,    52,    38,     0,    10,    11,    55,
      12,    13,     0,    53,    55,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -333,  -333,   343,    18,  -261,    46,  -225,  -333,  -333,   130,
    -231,  -287,  -332,  -222,  -333,  -248,  -187,  -333,   293,  -333,
    -295,  -333,   433,   -98,    15,   -85,    21,   118,   363,   366,
    -333,   292,   -18,   -31,   -15,   -16,   499,   264,   242,   289,
     243,   333,   -43,  -163,   119,   485,  -333,  -333,    75,   -14,
    -333,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,   338,   240,   276,   277,   150,   251,   304,
     151,   269,   270,   279,   361,   362,   152,   286,   287,   288,
     339,   317,   153,   281,   155,   282,   283,   158,   204,   199,
     228,   230,    10,    14,    12,   159,    48,    49,    50,    51,
      52,    53,   284,   124,    61,    62,    63,    64,   104,   161,
     162,    17
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,   250,    76,    56,   252,   154,   300,   321,    66,   268,
      21,   257,    68,   206,    74,     7,    27,     9,   156,   357,
      80,    33,     7,     7,   215,    83,    84,     1,     2,     3,
      22,   368,   258,    26,    23,   340,    28,    24,   102,   253,
      29,    34,    25,    30,    31,    35,    37,    18,    36,    11,
      21,   154,   353,   354,     4,   154,   154,    13,   154,   154,
     160,   280,   154,   268,   156,    57,    58,    59,   156,   123,
      32,   156,   156,   127,    15,   156,   321,    24,   197,   187,
      27,   351,    60,   188,   198,    33,    16,   173,    25,   280,
     280,   166,   280,   280,   280,   280,   280,   280,   202,   170,
      31,    38,   126,    54,    15,   203,   160,    30,    37,    15,
     160,   192,    36,   160,   160,   280,   280,   160,     8,    55,
     268,    57,    58,    59,   157,     8,     8,   242,   254,   184,
     360,   383,   268,    67,   367,   189,   385,   252,    69,   190,
      75,   265,   193,   194,   110,    81,   195,    70,   280,   149,
      82,   379,   115,    78,   252,   179,   280,    39,   280,   280,
     123,    40,   360,    89,   208,   209,   265,   265,   265,   242,
     157,   123,   253,    15,   157,    90,    16,   157,   157,   280,
     163,   157,   243,   255,    81,   183,   167,   108,   280,   253,
     280,   171,    57,    58,    59,   149,   266,    81,   105,   149,
     112,   265,   149,   149,    41,    81,   149,    65,   117,    77,
      42,    40,    43,    44,    45,    46,    99,   100,   101,    41,
     122,   266,   266,   266,   243,    42,   242,    43,    44,    45,
      46,   265,   265,   265,   313,    87,    88,   345,     1,     2,
       3,   107,   314,   315,   242,   345,   103,   345,   345,   265,
     265,   106,   265,   109,    41,   301,   266,   263,    91,    92,
      42,   254,    43,    44,    45,   148,    71,    97,    98,    79,
      72,   241,   249,    40,   120,   111,    85,   169,   380,   345,
      86,   243,   295,   296,   297,   264,   266,   266,   266,    39,
     140,   141,   346,   216,    93,    94,    95,    96,   262,   243,
     346,  -169,   346,   346,   266,   266,   333,   266,   142,   267,
     264,   264,   264,   241,    41,   214,   255,   323,   358,   359,
      42,    41,    43,    44,    45,    46,   114,    42,   116,    43,
      44,    45,    46,   381,   346,   131,   132,   133,   134,    57,
      58,    59,   137,   138,   139,   264,   327,   328,   369,   341,
      19,    20,   113,   263,   373,   129,   130,   118,     1,     2,
       3,   295,   142,   296,   297,   143,   119,   144,   356,   120,
     241,   145,   146,   147,    41,   264,   264,   264,   278,   121,
      42,   343,    43,    44,    45,   148,   135,   136,   241,   343,
     125,   343,   343,   264,   264,   263,   264,     4,   165,   168,
     172,   175,   174,   176,   177,   249,   178,   305,   180,   307,
     308,   309,   310,   311,   312,   181,   182,   185,   186,   200,
     201,   210,   378,   343,   244,   196,   205,     1,     2,     3,
     207,   245,   325,   326,   143,   211,   144,   212,   246,   247,
     213,   217,   218,    41,   219,   248,   220,   221,   222,    42,
     223,    43,    44,    45,   148,     1,     2,     3,   224,   245,
     225,   229,   143,   231,   144,   344,   274,   275,   226,   146,
     147,    41,   198,   227,   232,   309,   312,    42,   235,    43,
      44,    45,   148,   233,   203,   237,     1,     2,     3,   238,
     365,   256,   259,   143,   260,   144,   371,   246,   247,   261,
     271,   272,    41,   273,   366,   344,   285,   382,    42,   290,
      43,    44,    45,   148,     1,     2,     3,   291,   245,   292,
     293,   143,   294,   144,   302,   246,   247,   303,   306,   316,
      41,   320,   377,   322,   329,   324,    42,   330,    43,    44,
      45,   148,     1,     2,     3,   331,   142,   332,  -170,   143,
     334,   144,   347,   336,   337,   348,   342,   355,    41,   349,
     239,   364,   352,   363,    42,   370,    43,    44,    45,   148,
       1,     2,     3,   374,   298,   372,   376,   143,   359,   144,
     375,   318,   384,   319,   234,   236,    41,   191,   299,   128,
     289,   164,    42,     0,    43,    44,    45,   148,     1,     2,
       3,     0,   142,     0,     0,   143,     0,   144,     0,     0,
       0,     0,     0,     0,    41,     0,   335,     0,     0,     0,
      42,     0,    43,    44,    45,   148,     1,     2,     3,     0,
     142,     0,     0,   143,     0,   144,     0,     0,     0,     0,
       0,     0,    41,     0,   350,     0,     0,     0,    42,     0,
      43,    44,    45,   148,     1,     2,     3,     0,   142,     0,
       0,   143,     0,   144,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,     0,     0,    42,    41,    43,    44,
      45,   148,     0,    42,     0,    73,    44,    45,    46
};

static const yytype_int16 yycheck[] =
{
      16,   226,    33,    21,   226,   103,   267,   294,    24,   240,
      16,    16,    27,   176,    30,     0,    16,    47,   103,   351,
      36,    16,     7,     8,   187,    41,    42,    20,    21,    22,
      36,   363,    37,    17,    40,   330,    36,    43,    54,   226,
      40,    36,     9,    43,    11,    40,    13,     0,    43,    47,
      16,   149,   347,   348,    47,   153,   154,    47,   156,   157,
     103,   248,   160,   294,   149,    20,    21,    22,   153,    85,
      17,   156,   157,    89,    40,   160,   363,    43,    39,    36,
      16,   342,    37,    40,    45,    16,    43,   118,    55,   276,
     277,   109,   279,   280,   281,   282,   283,   284,    39,   114,
      67,    17,    87,    43,    40,    46,   149,    43,    75,    40,
     153,   154,    43,   156,   157,   302,   303,   160,     0,    47,
     351,    20,    21,    22,   103,     7,     8,   225,   226,   145,
     352,   379,   363,    47,   359,   149,   384,   359,    37,   153,
      47,   239,   156,   157,    69,    40,   160,    28,   335,   103,
      41,   376,    77,    34,   376,   140,   343,    41,   345,   346,
     176,    45,   384,     3,   180,   181,   264,   265,   266,   267,
     149,   187,   359,    40,   153,     4,    43,   156,   157,   366,
     105,   160,   225,   226,    40,    17,   111,    43,   375,   376,
     377,   116,    20,    21,    22,   149,   239,    40,    37,   153,
      43,   299,   156,   157,    36,    40,   160,    41,    43,    37,
      42,    45,    44,    45,    46,    47,    13,    14,    15,    36,
      37,   264,   265,   266,   267,    42,   324,    44,    45,    46,
      47,   329,   330,   331,    36,    16,    17,   335,    20,    21,
      22,    47,    44,    45,   342,   343,    38,   345,   346,   347,
     348,    16,   350,    16,    36,   271,   299,   239,     5,     6,
      42,   359,    44,    45,    46,    47,    41,    11,    12,    41,
      45,   225,   226,    45,    40,    37,    36,    43,   376,   377,
      40,   324,   264,   265,   266,   239,   329,   330,   331,    41,
      16,    17,   335,    45,     7,     8,     9,    10,    40,   342,
     343,    43,   345,   346,   347,   348,   322,   350,    24,    25,
     264,   265,   266,   267,    36,    37,   359,   299,    24,    25,
      42,    36,    44,    45,    46,    47,    16,    42,    37,    44,
      45,    46,    47,   376,   377,    93,    94,    95,    96,    20,
      21,    22,    99,   100,   101,   299,    44,    45,   364,   331,
       7,     8,    41,   335,   370,    91,    92,    16,    20,    21,
      22,   343,    24,   345,   346,    27,    45,    29,   350,    40,
     324,    33,    34,    35,    36,   329,   330,   331,   248,    37,
      42,   335,    44,    45,    46,    47,    97,    98,   342,   343,
      45,   345,   346,   347,   348,   377,   350,    47,    38,    23,
      38,    45,    41,    16,    37,   359,    41,   277,    36,   279,
     280,   281,   282,   283,   284,    36,    36,    36,    36,    17,
      23,    47,   376,   377,    17,    39,    41,    20,    21,    22,
      40,    24,   302,   303,    27,    17,    29,    23,    31,    32,
      23,    17,    16,    36,    39,    38,    17,    17,    16,    42,
      39,    44,    45,    46,    47,    20,    21,    22,    45,    24,
      37,    16,    27,    17,    29,   335,    31,    32,    37,    34,
      35,    36,    45,    37,    37,   345,   346,    42,    17,    44,
      45,    46,    47,    41,    46,    17,    20,    21,    22,    41,
      24,    38,    18,    27,    37,    29,   366,    31,    32,    17,
      36,    17,    36,    17,    38,   375,    30,   377,    42,    17,
      44,    45,    46,    47,    20,    21,    22,    47,    24,    17,
      45,    27,    39,    29,    17,    31,    32,    17,    39,    28,
      36,    41,    38,    36,    19,    37,    42,    19,    44,    45,
      46,    47,    20,    21,    22,    19,    24,    39,    43,    27,
      39,    29,    19,    37,    37,    19,    37,    17,    36,    31,
      38,    36,    39,    39,    42,    36,    44,    45,    46,    47,
      20,    21,    22,    39,    24,    37,    37,    27,    25,    29,
      38,   288,    39,   291,   218,   222,    36,   154,    38,    90,
     257,   106,    42,    -1,    44,    45,    46,    47,    20,    21,
      22,    -1,    24,    -1,    -1,    27,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      42,    -1,    44,    45,    46,    47,    20,    21,    22,    -1,
      24,    -1,    -1,    27,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    38,    -1,    -1,    -1,    42,    -1,
      44,    45,    46,    47,    20,    21,    22,    -1,    24,    -1,
      -1,    27,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    36,    44,    45,
      46,    47,    -1,    42,    -1,    44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,    21,    22,    47,    49,    50,    72,    75,    47,
      80,    47,    82,    47,    81,    40,    43,    99,     0,    50,
      50,    16,    36,    40,    43,    99,    17,    16,    36,    40,
      43,    99,    17,    16,    36,    40,    43,    99,    17,    41,
      45,    36,    42,    44,    45,    46,    47,    83,    84,    85,
      86,    87,    88,    89,    43,    47,    80,    20,    21,    22,
      37,    92,    93,    94,    95,    41,    83,    47,    82,    37,
      92,    41,    45,    44,    83,    47,    81,    37,    92,    41,
      83,    40,    41,    83,    83,    36,    40,    16,    17,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    83,    38,    96,    37,    16,    47,    43,    16,
      96,    37,    43,    41,    16,    96,    37,    43,    16,    45,
      40,    37,    37,    83,    91,    45,    72,    83,    84,    85,
      85,    86,    86,    86,    86,    87,    87,    88,    88,    88,
      16,    17,    24,    27,    29,    33,    34,    35,    47,    53,
      55,    58,    64,    70,    71,    72,    73,    74,    75,    83,
      90,    97,    98,    96,    93,    38,    80,    96,    23,    43,
      82,    96,    38,    81,    41,    45,    16,    37,    41,    72,
      36,    36,    36,    17,    83,    36,    36,    36,    40,    97,
      97,    70,    90,    97,    97,    97,    39,    39,    45,    77,
      17,    23,    39,    46,    76,    41,    91,    40,    83,    83,
      47,    17,    23,    23,    37,    91,    45,    17,    16,    39,
      17,    17,    16,    39,    45,    37,    37,    37,    78,    16,
      79,    17,    37,    41,    77,    17,    76,    17,    41,    38,
      52,    53,    71,    90,    17,    24,    31,    32,    38,    53,
      54,    56,    61,    64,    71,    90,    38,    16,    37,    18,
      37,    17,    40,    51,    53,    71,    90,    25,    58,    59,
      60,    36,    17,    17,    31,    32,    53,    54,    57,    61,
      64,    71,    73,    74,    90,    30,    65,    66,    67,    89,
      17,    47,    17,    45,    39,    51,    51,    51,    24,    38,
      52,    83,    17,    17,    57,    57,    39,    57,    57,    57,
      57,    57,    57,    36,    44,    45,    28,    69,    66,    79,
      41,    59,    36,    51,    37,    57,    57,    44,    45,    19,
      19,    19,    39,    83,    39,    38,    37,    37,    51,    68,
      68,    51,    37,    53,    57,    71,    90,    19,    19,    31,
      38,    52,    39,    68,    68,    17,    51,    60,    24,    25,
      61,    62,    63,    39,    36,    24,    38,    54,    60,    83,
      36,    57,    37,    83,    39,    38,    37,    38,    53,    54,
      71,    90,    57,    63,    39,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    50,    51,    51,    51,
      51,    52,    52,    52,    53,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    55,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    61,    62,
      62,    63,    63,    63,    63,    63,    64,    65,    65,    66,
      66,    67,    67,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    72,    72,    72,    72,    73,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    80,    80,    81,
      81,    81,    81,    81,    82,    82,    82,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    86,    86,    86,    86,
      86,    87,    87,    87,    88,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    90,    90,
      91,    91,    92,    93,    93,    94,    95,    95,    95,    96,
      97,    97,    97,    97,    97,    97,    97,    98,    98,    99,
      99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     2,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     5,     3,     1,     1,     3,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     8,
       6,     1,     1,     9,     4,     7,     2,     0,     8,     1,
       1,     9,     4,     7,     2,     0,     8,     1,     0,     2,
       0,     6,     4,     6,     4,     3,     1,     3,     0,     2,
       1,     1,     1,     1,     1,     5,     4,     6,     5,     6,
       6,     6,     6,     6,     5,     5,     5,     3,     8,     7,
       3,     3,     9,     8,     9,     8,     3,     1,     3,     1,
       3,     0,     4,     0,     5,     3,     3,     2,     1,     5,
       3,     3,     2,     1,     5,     3,     3,     2,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     1,     3,
       2,     1,     1,     1,     3,     4,     4,     7,     4,     5,
       3,     1,     1,     1,     3,     2,     1,     1,     1,     3,
       2,     2,     2,     1,     2,     2,     0,     3,     2,     3,
       6,     5
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
#line 290 "AST.y"
                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#code#DL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@@");(yyval.Str)=strdup(temp);fprintf(outFile,"%s",(yyval.Str));}
#line 1874 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 292 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#DS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#DL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1880 "y.tab.c"
    break;

  case 4: /* declarationList: assignmentStatement declarationList  */
#line 293 "AST.y"
                                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#AS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#DL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1886 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 294 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#DS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1892 "y.tab.c"
    break;

  case 6: /* declarationList: assignmentStatement  */
#line 295 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#AS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1898 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 297 "AST.y"
                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Satements#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1904 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 298 "AST.y"
                                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Satements#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1910 "y.tab.c"
    break;

  case 9: /* statements: functionCall statements  */
#line 299 "AST.y"
                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Satements#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1916 "y.tab.c"
    break;

  case 10: /* statements: %empty  */
#line 300 "AST.y"
                     {(yyval.Str)=strdup("#Epsilon@");}
#line 1922 "y.tab.c"
    break;

  case 11: /* singleStatement: specialStatement  */
#line 301 "AST.y"
                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1928 "y.tab.c"
    break;

  case 12: /* singleStatement: basicStatement  */
#line 302 "AST.y"
                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1934 "y.tab.c"
    break;

  case 13: /* singleStatement: functionCall  */
#line 303 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1940 "y.tab.c"
    break;

  case 14: /* specialStatement: ifStatement  */
#line 306 "AST.y"
                                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IFS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1946 "y.tab.c"
    break;

  case 15: /* specialStatement: whileLoop  */
#line 307 "AST.y"
                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#WL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1952 "y.tab.c"
    break;

  case 16: /* specialStatement: switchStatement  */
#line 308 "AST.y"
                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SWS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1958 "y.tab.c"
    break;

  case 17: /* singleLoopStatement: specialStatement  */
#line 319 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1964 "y.tab.c"
    break;

  case 18: /* singleLoopStatement: basicStatement  */
#line 320 "AST.y"
                                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1970 "y.tab.c"
    break;

  case 19: /* singleLoopStatement: functionCall  */
#line 321 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1976 "y.tab.c"
    break;

  case 20: /* singleLoopStatement: BREAK SEMICOLON  */
#line 322 "AST.y"
                                                          {(yyval.Str)=strdup("#break@#;@");}
#line 1982 "y.tab.c"
    break;

  case 21: /* singleLoopStatement: CONTINUE SEMICOLON  */
#line 323 "AST.y"
                                                             {(yyval.Str)=strdup("#continue@#;@");}
#line 1988 "y.tab.c"
    break;

  case 22: /* singleLoopStatement: switchStatement  */
#line 324 "AST.y"
                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SWS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1994 "y.tab.c"
    break;

  case 23: /* singleLoopStatement: ifInLoopStatement  */
#line 325 "AST.y"
                                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfLoop#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2000 "y.tab.c"
    break;

  case 24: /* whileLoop: WHILE OPBRAC expressionStatement CLBRAC whileSuffix  */
#line 338 "AST.y"
                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#while@#(@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#WSuffix#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2006 "y.tab.c"
    break;

  case 25: /* whileSuffix: OPCUR inLoop CLCUR  */
#line 340 "AST.y"
                                 {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#{@#InL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2012 "y.tab.c"
    break;

  case 26: /* whileSuffix: SEMICOLON  */
#line 341 "AST.y"
                              {(yyval.Str)=strdup(";");}
#line 2018 "y.tab.c"
    break;

  case 27: /* whileSuffix: singleLoopStatement  */
#line 342 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SLS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2024 "y.tab.c"
    break;

  case 28: /* inLoop: BREAK SEMICOLON inLoop  */
#line 344 "AST.y"
                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#break@#;@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2030 "y.tab.c"
    break;

  case 29: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 345 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#continue@#;@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2036 "y.tab.c"
    break;

  case 30: /* inLoop: specialStatement inLoop  */
#line 346 "AST.y"
                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2042 "y.tab.c"
    break;

  case 31: /* inLoop: basicStatement inLoop  */
#line 347 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2048 "y.tab.c"
    break;

  case 32: /* inLoop: functionCall inLoop  */
#line 348 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2054 "y.tab.c"
    break;

  case 33: /* inLoop: ifInLoopStatement inLoop  */
#line 349 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfInL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2060 "y.tab.c"
    break;

  case 34: /* inLoop: switchStatement inLoop  */
#line 350 "AST.y"
                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2066 "y.tab.c"
    break;

  case 35: /* inLoop: singleLoopStatement inLoop  */
#line 351 "AST.y"
                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SLS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2072 "y.tab.c"
    break;

  case 36: /* inLoop: printer inLoop  */
#line 352 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#printer#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2078 "y.tab.c"
    break;

  case 37: /* inLoop: Scanner inLoop  */
#line 353 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Scanner#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2084 "y.tab.c"
    break;

  case 38: /* inLoop: %empty  */
#line 354 "AST.y"
                  {(yyval.Str)=strdup("#Epsilon@");}
#line 2090 "y.tab.c"
    break;

  case 39: /* ifStatement: IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ifContinuer  */
#line 356 "AST.y"
                                                                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IF@#(@#ES#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#)@#{@#Satements#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2096 "y.tab.c"
    break;

  case 40: /* ifStatement: IF OPBRAC expressionStatement CLBRAC singleStatement ifContinuer  */
#line 357 "AST.y"
                                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IF@#(@#ES#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#)@#SingleS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2102 "y.tab.c"
    break;

  case 41: /* ifContinuer: ES  */
#line 359 "AST.y"
                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2108 "y.tab.c"
    break;

  case 42: /* ifContinuer: ifStatement  */
#line 360 "AST.y"
                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2114 "y.tab.c"
    break;

  case 43: /* ES: ELSE IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ES  */
#line 362 "AST.y"
                                                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#)@#{@#STMTS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2120 "y.tab.c"
    break;

  case 44: /* ES: ELSE OPCUR statements CLCUR  */
#line 363 "AST.y"
                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#{@#STMTS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2126 "y.tab.c"
    break;

  case 45: /* ES: ELSE IF OPBRAC expressionStatement CLBRAC singleStatement ES  */
#line 364 "AST.y"
                                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#)@#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#ElS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2132 "y.tab.c"
    break;

  case 46: /* ES: ELSE singleStatement  */
#line 365 "AST.y"
                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2138 "y.tab.c"
    break;

  case 47: /* ES: %empty  */
#line 365 "AST.y"
                                                                                                                                                                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2144 "y.tab.c"
    break;

  case 48: /* ifInLoopStatement: IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ifInLoopContinuer  */
#line 367 "AST.y"
                                                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#if@#(@#ES#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#)@#{@#IL#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#IILC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2150 "y.tab.c"
    break;

  case 49: /* ifInLoopContinuer: ESLoop  */
#line 367 "AST.y"
                                                                                                                                                                                                                                                                                                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ESL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2156 "y.tab.c"
    break;

  case 50: /* ifInLoopContinuer: ifInLoopStatement  */
#line 367 "AST.y"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IILS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2162 "y.tab.c"
    break;

  case 51: /* ESLoop: ELSE IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ESLoop  */
#line 369 "AST.y"
                                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#)@#IL#");strcat(temp,(yyvsp[-3].Str)); strcat(temp,"@@#ESL#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2168 "y.tab.c"
    break;

  case 52: /* ESLoop: ELSE OPCUR inLoop CLCUR  */
#line 370 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#{@#IL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2174 "y.tab.c"
    break;

  case 53: /* ESLoop: ELSE IF OPBRAC expressionStatement CLBRAC singleLoopStatement ESLoop  */
#line 371 "AST.y"
                                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#)@#SLS#");strcat(temp,(yyvsp[-1].Str)); strcat(temp,"@@#ESL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2180 "y.tab.c"
    break;

  case 54: /* ESLoop: ELSE singleLoopStatement  */
#line 372 "AST.y"
                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#SLS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2186 "y.tab.c"
    break;

  case 55: /* ESLoop: %empty  */
#line 372 "AST.y"
                                                                                                                                                                                  {(yyval.Str)=strdup("#Epsilon@");}
#line 2192 "y.tab.c"
    break;

  case 56: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR  */
#line 374 "AST.y"
                                                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000); strcat(temp,"#switch@#(@#Identifier#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#(@#{@#CS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#DS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2198 "y.tab.c"
    break;

  case 57: /* caseStatements: caseStatementInt  */
#line 376 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#CSI#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2204 "y.tab.c"
    break;

  case 58: /* caseStatements: %empty  */
#line 377 "AST.y"
                                  {(yyval.Str)=strdup("#Epsilon@");}
#line 2210 "y.tab.c"
    break;

  case 59: /* caseStatementInt: caseInt caseStatementInt  */
#line 379 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#CI#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#CSI#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2216 "y.tab.c"
    break;

  case 60: /* caseStatementInt: %empty  */
#line 380 "AST.y"
                                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2222 "y.tab.c"
    break;

  case 61: /* caseInt: CASE OPBRAC INTVAL CLBRAC COLON caseContinuer  */
#line 382 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#(@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#)@#:@#CC#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2228 "y.tab.c"
    break;

  case 62: /* caseInt: CASE INTVAL COLON caseContinuer  */
#line 383 "AST.y"
                                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#:@#CC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2234 "y.tab.c"
    break;

  case 63: /* caseInt: CASE OPBRAC CHARVAL CLBRAC COLON caseContinuer  */
#line 384 "AST.y"
                                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#(@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#)@#:@#CC#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2240 "y.tab.c"
    break;

  case 64: /* caseInt: CASE CHARVAL COLON caseContinuer  */
#line 385 "AST.y"
                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#:@#CC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2246 "y.tab.c"
    break;

  case 65: /* caseContinuer: statements BREAK SEMICOLON  */
#line 387 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#STMTS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#break@#;@");(yyval.Str)=strdup(temp);}
#line 2252 "y.tab.c"
    break;

  case 66: /* caseContinuer: statements  */
#line 388 "AST.y"
                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#STMTS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2258 "y.tab.c"
    break;

  case 67: /* defaultStatement: DEFAULT COLON statements  */
#line 390 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#default@#:@#STMTS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2264 "y.tab.c"
    break;

  case 68: /* defaultStatement: %empty  */
#line 391 "AST.y"
                                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2270 "y.tab.c"
    break;

  case 69: /* basicStatements: basicStatement basicStatements  */
#line 394 "AST.y"
                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#BSs#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2276 "y.tab.c"
    break;

  case 70: /* basicStatements: basicStatement  */
#line 395 "AST.y"
                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2282 "y.tab.c"
    break;

  case 71: /* basicStatement: expressionStatement  */
#line 397 "AST.y"
                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2288 "y.tab.c"
    break;

  case 72: /* basicStatement: declarationStatement  */
#line 398 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#DS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2294 "y.tab.c"
    break;

  case 73: /* basicStatement: assignmentStatement  */
#line 399 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#AS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2300 "y.tab.c"
    break;

  case 74: /* basicStatement: functionCall  */
#line 399 "AST.y"
                                                                                                                                                                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2306 "y.tab.c"
    break;

  case 75: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 401 "AST.y"
                                                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@");strcat(temp,"#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#AS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2312 "y.tab.c"
    break;

  case 76: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 402 "AST.y"
                                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@");strcat(temp,"#=@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2318 "y.tab.c"
    break;

  case 77: /* assignmentStatement: IDENTIFIER dimension EQUAL expressionStatement COMMA assignmentStatement  */
#line 402 "AST.y"
                                                                                                                                                                                                                                                                                                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#AS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2324 "y.tab.c"
    break;

  case 78: /* assignmentStatement: IDENTIFIER dimension EQUAL expressionStatement SEMICOLON  */
#line 403 "AST.y"
                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2330 "y.tab.c"
    break;

  case 79: /* printer: PRINTF OPBRAC STRING prattributes CLBRAC SEMICOLON  */
#line 405 "AST.y"
                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#printf@#(@#String#\\");strcat(temp,(yyvsp[-3].Str));strcat(temp,"\\\"@@#PrA#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#;@");(yyval.Str)=strdup(temp);}
#line 2336 "y.tab.c"
    break;

  case 80: /* Scanner: SCANF OPBRAC STRING scattributes CLBRAC SEMICOLON  */
#line 406 "AST.y"
                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#scanf@#(@#String#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#SCA#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#;@");(yyval.Str)=strdup(temp);}
#line 2342 "y.tab.c"
    break;

  case 81: /* declarationStatement: INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 408 "AST.y"
                                                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#(@#PS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2348 "y.tab.c"
    break;

  case 82: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 409 "AST.y"
                                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#(@#PS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2354 "y.tab.c"
    break;

  case 83: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 410 "AST.y"
                                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#(@#PS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2360 "y.tab.c"
    break;

  case 84: /* declarationStatement: INT IDENTIFIER OPBRAC CLBRAC compoundStatements  */
#line 411 "AST.y"
                                                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2366 "y.tab.c"
    break;

  case 85: /* declarationStatement: FLOAT IDENTIFIER OPBRAC CLBRAC compoundStatements  */
#line 412 "AST.y"
                                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2372 "y.tab.c"
    break;

  case 86: /* declarationStatement: CHAR IDENTIFIER OPBRAC CLBRAC compoundStatements  */
#line 413 "AST.y"
                                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2378 "y.tab.c"
    break;

  case 87: /* declarationStatement: INT declarationListInt SEMICOLON  */
#line 414 "AST.y"
                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#DLI#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2384 "y.tab.c"
    break;

  case 88: /* declarationStatement: CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING SEMICOLON  */
#line 415 "AST.y"
                                                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@#[@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#]@#=@#STRING#\\");strcat(temp,(yyvsp[-1].Str));strcat(temp,"\\\"@@#;@");(yyval.Str)=strdup(temp);}
#line 2390 "y.tab.c"
    break;

  case 89: /* declarationStatement: CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING SEMICOLON  */
#line 416 "AST.y"
                                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#[@#]@#=@#STRING#\\");strcat(temp,(yyvsp[-1].Str));strcat(temp,"\\\"@@#;@");(yyval.Str)=strdup(temp);}
#line 2396 "y.tab.c"
    break;

  case 90: /* declarationStatement: CHAR declarationListChar SEMICOLON  */
#line 417 "AST.y"
                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#DLC#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2402 "y.tab.c"
    break;

  case 91: /* declarationStatement: FLOAT declarationListFloat SEMICOLON  */
#line 418 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#DLF#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2408 "y.tab.c"
    break;

  case 92: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON  */
#line 419 "AST.y"
                                                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,(yyvsp[-7].Str));strcat(temp,"@@#[@#]@#=@#{@#AV#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#;@");(yyval.Str)=strdup(temp);}
#line 2414 "y.tab.c"
    break;

  case 93: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON  */
#line 420 "AST.y"
                                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@#[@#]@#=@#{@#}@#;@");(yyval.Str)=strdup(temp);}
#line 2420 "y.tab.c"
    break;

  case 94: /* declarationStatement: FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValuesF CLCUR SEMICOLON  */
#line 420 "AST.y"
                                                                                                                                                                                                                                                                                                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,(yyvsp[-7].Str));strcat(temp,"@@#[@#]@#=@#{@#AVF#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#;@");(yyval.Str)=strdup(temp);}
#line 2426 "y.tab.c"
    break;

  case 95: /* declarationStatement: FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON  */
#line 421 "AST.y"
                                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@#[@#]@#=@#{@#}@#;@");(yyval.Str)=strdup(temp);}
#line 2432 "y.tab.c"
    break;

  case 96: /* arrayValuesF: FLOATVAL COMMA arrayValuesF  */
#line 424 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#,@#AVF#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2438 "y.tab.c"
    break;

  case 97: /* arrayValuesF: FLOATVAL  */
#line 425 "AST.y"
                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2444 "y.tab.c"
    break;

  case 98: /* arrayValues: INTVAL COMMA arrayValues  */
#line 427 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#,@#AV#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2450 "y.tab.c"
    break;

  case 99: /* arrayValues: INTVAL  */
#line 428 "AST.y"
                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2456 "y.tab.c"
    break;

  case 100: /* prattributes: prattributes COMMA factor  */
#line 430 "AST.y"
                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#PrA#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#factor#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2462 "y.tab.c"
    break;

  case 101: /* prattributes: %empty  */
#line 431 "AST.y"
                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2468 "y.tab.c"
    break;

  case 102: /* scattributes: COMMA AMPERSAND IDENTIFIER scattributes  */
#line 433 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#,@#&@#Identifier#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#,@#SCA#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2474 "y.tab.c"
    break;

  case 103: /* scattributes: %empty  */
#line 434 "AST.y"
                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2480 "y.tab.c"
    break;

  case 104: /* declarationListInt: IDENTIFIER EQUAL expressionStatement COMMA declarationListInt  */
#line 436 "AST.y"
                                                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLI#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2486 "y.tab.c"
    break;

  case 105: /* declarationListInt: IDENTIFIER COMMA declarationListInt  */
#line 437 "AST.y"
                                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLI#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2492 "y.tab.c"
    break;

  case 106: /* declarationListInt: IDENTIFIER EQUAL expressionStatement  */
#line 438 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2498 "y.tab.c"
    break;

  case 107: /* declarationListInt: IDENTIFIER dimension  */
#line 439 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2504 "y.tab.c"
    break;

  case 108: /* declarationListInt: IDENTIFIER  */
#line 440 "AST.y"
                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2510 "y.tab.c"
    break;

  case 109: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListFloat  */
#line 442 "AST.y"
                                                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLF#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2516 "y.tab.c"
    break;

  case 110: /* declarationListFloat: IDENTIFIER COMMA declarationListFloat  */
#line 443 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLF#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2522 "y.tab.c"
    break;

  case 111: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement  */
#line 444 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2528 "y.tab.c"
    break;

  case 112: /* declarationListFloat: IDENTIFIER dimension  */
#line 445 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2534 "y.tab.c"
    break;

  case 113: /* declarationListFloat: IDENTIFIER  */
#line 446 "AST.y"
                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2540 "y.tab.c"
    break;

  case 114: /* declarationListChar: IDENTIFIER EQUAL CHARVAL COMMA declarationListChar  */
#line 448 "AST.y"
                                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#,@#DLC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2546 "y.tab.c"
    break;

  case 115: /* declarationListChar: IDENTIFIER COMMA declarationListChar  */
#line 449 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2552 "y.tab.c"
    break;

  case 116: /* declarationListChar: IDENTIFIER EQUAL expressionStatement  */
#line 450 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2558 "y.tab.c"
    break;

  case 117: /* declarationListChar: IDENTIFIER dimension  */
#line 451 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2564 "y.tab.c"
    break;

  case 118: /* declarationListChar: IDENTIFIER  */
#line 452 "AST.y"
                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2570 "y.tab.c"
    break;

  case 119: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 454 "AST.y"
                                                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#LE#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#||@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2576 "y.tab.c"
    break;

  case 120: /* expressionStatement: logicalExpression  */
#line 455 "AST.y"
                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#LE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2582 "y.tab.c"
    break;

  case 121: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 457 "AST.y"
                                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Exp#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#&&@#LE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2588 "y.tab.c"
    break;

  case 122: /* logicalExpression: expression  */
#line 458 "AST.y"
                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Exp#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2594 "y.tab.c"
    break;

  case 123: /* expression: relationalExpression EQUALS expression  */
#line 460 "AST.y"
                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RE#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#==@#Exp#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2600 "y.tab.c"
    break;

  case 124: /* expression: relationalExpression NOTEQUAL expression  */
#line 461 "AST.y"
                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RE#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#!=@#Exp#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2606 "y.tab.c"
    break;

  case 125: /* expression: relationalExpression  */
#line 462 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2612 "y.tab.c"
    break;

  case 126: /* relationalExpression: value GREATERTHAN relationalExpression  */
#line 464 "AST.y"
                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#>@#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2618 "y.tab.c"
    break;

  case 127: /* relationalExpression: value GREATERTHANEQUALTO relationalExpression  */
#line 465 "AST.y"
                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#>=@#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2624 "y.tab.c"
    break;

  case 128: /* relationalExpression: value LESSTHAN relationalExpression  */
#line 466 "AST.y"
                                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#<@#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2630 "y.tab.c"
    break;

  case 129: /* relationalExpression: value LESSTHANEQUALTO relationalExpression  */
#line 467 "AST.y"
                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#<=@#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2636 "y.tab.c"
    break;

  case 130: /* relationalExpression: value  */
#line 468 "AST.y"
                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2642 "y.tab.c"
    break;

  case 131: /* value: term ADD value  */
#line 470 "AST.y"
                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#term#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#+@#value#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2648 "y.tab.c"
    break;

  case 132: /* value: term SUB value  */
#line 471 "AST.y"
                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#term#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#-@#value#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2654 "y.tab.c"
    break;

  case 133: /* value: term  */
#line 472 "AST.y"
               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#term#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2660 "y.tab.c"
    break;

  case 134: /* term: factor MULT term  */
#line 474 "AST.y"
                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#*@#term#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2666 "y.tab.c"
    break;

  case 135: /* term: factor DIV term  */
#line 475 "AST.y"
                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#/@#term#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2672 "y.tab.c"
    break;

  case 136: /* term: factor MOD term  */
#line 476 "AST.y"
                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#%@#term#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2678 "y.tab.c"
    break;

  case 137: /* term: factor  */
#line 477 "AST.y"
                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2684 "y.tab.c"
    break;

  case 138: /* factor: IDENTIFIER  */
#line 479 "AST.y"
                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2690 "y.tab.c"
    break;

  case 139: /* factor: OPBRAC expressionStatement CLBRAC  */
#line 480 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#ES#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#)@");(yyval.Str)=strdup(temp);}
#line 2696 "y.tab.c"
    break;

  case 140: /* factor: LOGICALNOT expressionStatement  */
#line 481 "AST.y"
                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#!@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2702 "y.tab.c"
    break;

  case 141: /* factor: CHARVAL  */
#line 482 "AST.y"
                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2708 "y.tab.c"
    break;

  case 142: /* factor: INTVAL  */
#line 483 "AST.y"
                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2714 "y.tab.c"
    break;

  case 143: /* factor: FLOATVAL  */
#line 484 "AST.y"
                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2720 "y.tab.c"
    break;

  case 144: /* factor: IDENTIFIER OPBRAC CLBRAC  */
#line 484 "AST.y"
                                                                                                                                                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#(@#)@");(yyval.Str)=strdup(temp);}
#line 2726 "y.tab.c"
    break;

  case 145: /* factor: IDENTIFIER OPBRAC argList CLBRAC  */
#line 484 "AST.y"
                                                                                                                                                                                                                                                                                                                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#AL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#)@");(yyval.Str)=strdup(temp);}
#line 2732 "y.tab.c"
    break;

  case 146: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE  */
#line 485 "AST.y"
                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@");strcat(temp,"#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2738 "y.tab.c"
    break;

  case 147: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 486 "AST.y"
                                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@");strcat(temp,"#[@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#]@#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2744 "y.tab.c"
    break;

  case 148: /* functionCall: IDENTIFIER OPBRAC CLBRAC SEMICOLON  */
#line 489 "AST.y"
                                                  {{char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#;@");(yyval.Str)=strdup(temp);}}
#line 2750 "y.tab.c"
    break;

  case 149: /* functionCall: IDENTIFIER OPBRAC argList CLBRAC SEMICOLON  */
#line 490 "AST.y"
                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#(@#AL#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#;@");(yyval.Str)=strdup(temp);}
#line 2756 "y.tab.c"
    break;

  case 150: /* argList: expressionStatement COMMA argList  */
#line 493 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#AL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2762 "y.tab.c"
    break;

  case 151: /* argList: expressionStatement  */
#line 494 "AST.y"
                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2768 "y.tab.c"
    break;

  case 152: /* parameters: paramContinuer  */
#line 496 "AST.y"
                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#PC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2774 "y.tab.c"
    break;

  case 153: /* paramContinuer: parameter  */
#line 497 "AST.y"
                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#P#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2780 "y.tab.c"
    break;

  case 154: /* paramContinuer: parameter COMMA paramContinuer  */
#line 498 "AST.y"
                                                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#P#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#PC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2786 "y.tab.c"
    break;

  case 155: /* parameter: type IDENTIFIER  */
#line 500 "AST.y"
                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#type#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2792 "y.tab.c"
    break;

  case 156: /* type: INT  */
#line 502 "AST.y"
           {(yyval.Str)=strdup("#int@");}
#line 2798 "y.tab.c"
    break;

  case 157: /* type: FLOAT  */
#line 503 "AST.y"
                        {(yyval.Str)=strdup("#float@");}
#line 2804 "y.tab.c"
    break;

  case 158: /* type: CHAR  */
#line 504 "AST.y"
                        {(yyval.Str)=strdup("#char@");}
#line 2810 "y.tab.c"
    break;

  case 159: /* compoundStatements: OPCUR statementList CLCUR  */
#line 506 "AST.y"
                                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#{@#SL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2816 "y.tab.c"
    break;

  case 160: /* statementList: functionCall statementList  */
#line 508 "AST.y"
                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2822 "y.tab.c"
    break;

  case 161: /* statementList: basicStatements statementList  */
#line 509 "AST.y"
                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2828 "y.tab.c"
    break;

  case 162: /* statementList: specialStatement statementList  */
#line 510 "AST.y"
                                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2834 "y.tab.c"
    break;

  case 163: /* statementList: returnDec  */
#line 511 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RD#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2840 "y.tab.c"
    break;

  case 164: /* statementList: printer statementList  */
#line 512 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#printer#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2846 "y.tab.c"
    break;

  case 165: /* statementList: Scanner statementList  */
#line 513 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Scanner#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2852 "y.tab.c"
    break;

  case 166: /* statementList: %empty  */
#line 514 "AST.y"
                                  {(yyval.Str)=strdup("#Epsilon@");}
#line 2858 "y.tab.c"
    break;

  case 167: /* returnDec: RETURN expressionStatement SEMICOLON  */
#line 516 "AST.y"
                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#return@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2864 "y.tab.c"
    break;

  case 168: /* returnDec: RETURN SEMICOLON  */
#line 517 "AST.y"
                                           {(yyval.Str)=strdup("#return@#;@");}
#line 2870 "y.tab.c"
    break;

  case 169: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 519 "AST.y"
                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2876 "y.tab.c"
    break;

  case 170: /* dimension: BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 520 "AST.y"
                                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#[@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#]@#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2882 "y.tab.c"
    break;

  case 171: /* dimension: BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 521 "AST.y"
                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#[@#]@#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2888 "y.tab.c"
    break;


#line 2892 "y.tab.c"

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

#line 522 "AST.y"

 
#include "lex.yy.c"
int main(){
	yyin = fopen("./Test Cases/inputSWITCH.txt","r");	
	availableScopes[0] = 0;
	if(!yyparse())
	{
		printf("\n\nParsed Successfully\n\n");		
		// printTable();
	}
	else 
		printf("\n\nParsing Failed\n\n");			
	exit(0);
}
     
     
