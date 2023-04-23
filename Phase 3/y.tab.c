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
	int getIdentifierFunctionType(char *token, bool isArray, bool isFunction)
 	{
 		int tableIndex=currIndex;
 		for(int i=tableIndex-1;i>=0;i--)
 		{	
 			if(strcmp(table[i].lexeme,token)==0){
				for(int j = scopeIndex;j>=0;j--){
					if(table[i].scope==availableScopes[j]){
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
	int getCurrentFunctionIndex(){
		int tableIndex=currIndex;
 		for(int i=tableIndex-1;i>=0;i--)
 		{	
 			if(table[i].isFunction){
				for(int j = scopeIndex;j>=0;j--){
					if(table[i].scope==availableScopes[j]){
						return i;
					}
				}
			}
 		}
		return -1;
	}
	void pushNewScope(){// Put a new scope for every open {
		availableScopes[++scopeIndex]=++maxScope;
		currScope = maxScope;
	}
	void popScope(){ // pop latest scope on every }
		availableScopes[scopeIndex--]=-1;
		currScope = availableScopes[scopeIndex];
	}
 

#line 221 "y.tab.c"

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
#line 150 "SemanticAnalyzer.y"

		int Int;
		float Float;
		char Char;
		char* Str;
		struct data{

		};
	

#line 379 "y.tab.c"

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
  YYSYMBOL_functionCall = 130,             /* functionCall  */
  YYSYMBOL_argList = 131,                  /* argList  */
  YYSYMBOL_parameters = 132,               /* parameters  */
  YYSYMBOL_133_35 = 133,                   /* $@35  */
  YYSYMBOL_paramContinuer = 134,           /* paramContinuer  */
  YYSYMBOL_parameter = 135,                /* parameter  */
  YYSYMBOL_type = 136,                     /* type  */
  YYSYMBOL_compoundStatements = 137,       /* compoundStatements  */
  YYSYMBOL_statementList = 138,            /* statementList  */
  YYSYMBOL_returnDec = 139,                /* returnDec  */
  YYSYMBOL_dimension = 140                 /* dimension  */
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
#define YYLAST   531

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  214
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  428

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
       0,   194,   194,   196,   197,   198,   199,   201,   202,   203,
     204,   205,   206,   207,   209,   209,   210,   211,   212,   213,
     213,   213,   215,   216,   216,   217,   217,   219,   220,   221,
     222,   223,   224,   225,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   239,   239,   240,   240,   241,   242,
     242,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     254,   254,   254,   255,   255,   255,   256,   257,   259,   259,
     259,   260,   260,   260,   261,   261,   261,   262,   262,   263,
     265,   265,   265,   266,   267,   269,   269,   269,   270,   270,
     270,   271,   271,   271,   272,   272,   273,   275,   275,   275,
     276,   276,   277,   277,   277,   277,   278,   279,   280,   281,
     282,   283,   284,   284,   285,   288,   289,   291,   292,   293,
     295,   296,   298,   299,   300,   301,   302,   303,   303,   304,
     304,   305,   305,   306,   307,   308,   309,   310,   311,   312,
     316,   317,   318,   319,   320,   321,   323,   324,   325,   326,
     327,   329,   330,   331,   332,   333,   335,   336,   337,   338,
     339,   341,   342,   344,   345,   347,   348,   349,   351,   352,
     353,   354,   355,   357,   358,   359,   361,   362,   363,   364,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     378,   379,   382,   383,   385,   385,   386,   387,   389,   391,
     392,   393,   395,   397,   398,   399,   400,   401,   402,   403,
     405,   406,   408,   409,   410
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
  "term", "factor", "functionCall", "argList", "parameters", "$@35",
  "paramContinuer", "parameter", "type", "compoundStatements",
  "statementList", "returnDec", "dimension", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-399)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-192)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      72,   -26,    14,    53,    64,   117,  -399,    72,    72,    35,
     138,    68,   145,    80,   175,   180,  -399,  -399,  -399,    88,
     160,   148,   180,  -399,  -399,   155,   177,   162,   194,  -399,
    -399,   213,   235,   167,   180,  -399,  -399,   180,   180,  -399,
    -399,  -399,   173,   127,   275,   278,   228,   238,   229,   113,
      93,  -399,   248,   260,   199,    -2,   258,   289,   106,  -399,
     270,   277,     6,   269,   305,   118,  -399,   285,   286,   290,
     309,   295,  -399,   411,   288,   287,  -399,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     297,   297,  -399,  -399,  -399,  -399,   323,   294,   301,   311,
     313,    88,   297,   297,   328,   151,   155,   297,   297,   213,
    -399,  -399,   338,   318,   315,  -399,  -399,  -399,  -399,  -399,
    -399,  -399,  -399,  -399,  -399,  -399,  -399,  -399,  -399,   282,
    -399,  -399,   199,  -399,   326,   125,   312,  -399,  -399,  -399,
     342,   349,  -399,  -399,  -399,  -399,   180,  -399,   334,   341,
    -399,   343,   345,   154,   348,   356,   141,   282,  -399,  -399,
    -399,   282,   399,  -399,   282,   282,  -399,  -399,   368,   355,
    -399,  -399,  -399,   378,   380,   358,   357,  -399,   382,  -399,
     360,   180,   366,  -399,   359,  -399,   386,   389,   392,   423,
    -399,  -399,   192,  -399,  -399,  -399,   282,  -399,  -399,   372,
     401,  -399,  -399,   381,   388,    33,  -399,  -399,  -399,  -399,
     180,   391,  -399,   408,   410,   413,   400,  -399,  -399,  -399,
    -399,   398,  -399,   395,   402,   180,  -399,   414,   412,   405,
     417,   420,   424,   422,  -399,   387,   419,   421,   446,  -399,
      -4,  -399,   408,   449,   425,   454,   387,  -399,  -399,  -399,
     456,   180,   180,   427,  -399,  -399,  -399,   316,   445,  -399,
    -399,   410,  -399,  -399,   387,   387,   459,   225,  -399,   242,
     247,   434,   441,   344,   443,   463,   464,  -399,  -399,  -399,
    -399,  -399,   465,   455,  -399,   457,  -399,   447,  -399,  -399,
     387,    45,  -399,  -399,  -399,    33,  -399,    33,  -399,   180,
      -1,   467,   468,   344,   344,   450,   344,   344,   344,   471,
     180,  -399,  -399,  -399,   472,  -399,    69,  -399,   225,  -399,
     458,  -399,   387,  -399,  -399,   474,  -399,  -399,   316,   344,
     344,  -399,  -399,  -399,  -399,  -399,  -399,   344,   460,  -399,
     453,   222,   476,   477,   445,  -399,   180,   387,  -399,   427,
     344,  -399,  -399,  -399,  -399,   461,   387,  -399,   466,   469,
     387,   387,  -399,   470,  -399,  -399,   462,   244,  -399,   479,
     481,   473,  -399,  -399,   475,   478,  -399,   344,   387,   387,
     485,  -399,   387,  -399,  -399,  -399,  -399,  -399,   387,  -399,
     480,  -399,   483,   245,   482,  -399,   484,    57,  -399,  -399,
    -399,   483,   180,   486,  -399,   316,  -399,   487,   180,   344,
    -399,   488,   490,  -399,  -399,   491,   489,  -399,   316,  -399,
     344,  -399,  -399,   493,   492,  -399,   493,  -399
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     5,   150,
       0,   160,     0,   155,     0,     0,     1,     4,     3,     0,
     194,     0,     0,   149,   133,     0,   194,     0,     0,   159,
     136,     0,   194,     0,     0,   154,   137,     0,     0,   183,
     184,   185,   180,     0,   162,   164,   167,   172,   175,   179,
     150,   147,     0,     0,     0,     0,     0,   148,   160,   157,
       0,     0,     0,     0,   158,   155,   152,     0,     0,     0,
     153,     0,   182,     0,     0,     0,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   201,   200,   195,   196,     0,     0,     0,
     212,     0,     0,     0,     0,   212,     0,     0,     0,     0,
     181,   186,   193,     0,     0,   120,   161,   163,   165,   166,
     168,   169,   170,   171,   173,   174,   176,   177,   178,   209,
     128,   124,     0,   198,     0,     0,     0,   146,   132,   125,
       0,     0,   156,   130,   126,   151,     0,   187,   188,     0,
      14,     0,     0,     0,     0,     0,   180,   209,    17,    16,
      18,   209,   116,   119,   209,   209,   118,   117,     0,     0,
     206,   197,   214,     0,   141,     0,     0,   135,     0,   192,
       0,     0,     0,    44,     0,   211,     0,     0,     0,     0,
     204,   203,   180,   115,   207,   208,   209,   202,   139,     0,
       0,   213,   134,     0,     0,     0,    15,    21,    19,    20,
       0,     0,   210,   143,   145,   186,     0,   205,   140,   138,
     189,    63,    39,     0,     0,    41,    34,     0,     0,     0,
       0,     0,     0,   187,    60,     0,     0,     0,     0,    40,
      49,    97,   143,     0,     0,     0,    10,    64,    11,    12,
       0,     0,     0,     0,    48,    46,    45,     0,   101,   142,
     122,   145,   123,    61,    10,    10,     0,    79,    13,     0,
       0,     0,     0,    59,     0,     0,     0,    27,    50,    33,
      18,    28,     0,   114,   100,     0,   144,     0,     7,     8,
      10,    77,    67,    65,    66,     0,    35,     0,    37,     0,
      25,     0,     0,    27,    59,     0,    33,    18,    28,     0,
       0,    30,    31,    29,     0,    98,     0,   103,    79,     9,
       0,    71,     0,    36,    38,    43,    22,    23,     0,    30,
      31,    53,    58,    47,    56,    57,    54,    29,     0,   112,
       0,     0,     0,     0,   105,    62,     0,    10,    78,     0,
      59,    26,    51,    52,    55,    63,    10,    99,     0,     0,
      10,    10,   104,     0,    72,    42,     0,    60,   113,     0,
       0,   111,   109,   107,    74,     0,    24,    59,    10,    10,
       0,    68,     0,    73,    81,   108,   106,   110,    10,    75,
       0,    69,    79,    96,     0,    76,     0,    94,    84,    82,
      83,    79,     0,     0,    88,     0,    70,     0,     0,    59,
      95,     0,     0,    89,    80,    91,     0,    85,     0,    90,
      59,    92,    86,    96,     0,    93,    96,    87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -399,  -399,   273,  -235,  -312,  -105,  -399,  -399,  -399,  -399,
    -399,  -399,  -399,  -255,   -66,  -399,   144,  -399,  -399,  -399,
    -399,  -399,  -205,  -231,  -399,  -399,  -399,  -399,   187,  -286,
    -399,  -399,  -399,  -399,  -399,  -399,  -399,  -251,  -399,  -399,
    -399,  -398,  -399,  -399,  -399,  -399,  -399,  -399,  -399,  -240,
    -399,  -399,  -399,   166,  -399,  -399,  -399,  -222,  -399,  -399,
     347,  -117,     1,  -399,  -399,   168,  -399,  -399,  -399,   317,
     272,   250,   -16,   -27,   -20,   -15,   437,   214,   208,   234,
     165,  -399,    22,  -132,   156,  -399,   393,  -399,  -399,   -76,
    -122,  -399,     7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,   371,   247,   303,   182,   206,   207,   208,
     350,   209,   328,   304,   225,   238,   272,   158,   210,   256,
     273,   257,   305,   159,   246,   287,   235,   267,   293,   294,
     388,   394,   347,   375,   382,   392,   322,   306,   377,   390,
     399,   400,   420,   424,   409,   416,   418,   423,   405,   160,
     258,   340,   283,   284,   285,   344,   317,   372,   315,   356,
     161,   308,   163,   164,   165,   166,    52,    67,    60,   175,
     230,   232,    10,    14,    12,   167,    44,    45,    46,    47,
      48,    49,   309,   113,    53,    54,    95,    96,    97,   130,
     169,   170,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,     7,   278,    51,    66,    59,   279,    57,     7,     7,
     348,   263,   162,   254,   179,   131,   326,   280,    29,    70,
      35,     9,    71,    72,   157,   425,   138,   139,   427,   288,
     289,   143,   144,   307,   255,   190,   292,   327,    98,   191,
     162,    99,   194,   195,   162,   162,    98,   162,   162,   104,
     222,    19,   157,   223,   224,   319,   157,   216,   112,   157,
     157,    11,   116,   307,   307,    29,   307,   307,   307,   320,
     389,    20,    35,   351,   217,    21,   115,   279,    22,   162,
       4,   403,   145,   321,    25,   137,   142,   292,   280,   307,
     307,   157,     1,     2,     3,   404,    31,   307,   331,   332,
      13,   334,   335,   336,    26,   341,   395,    15,    27,    19,
     307,    28,   364,   342,   343,   406,    32,    16,   249,     4,
      33,   368,    25,    34,   352,   353,    87,    88,    89,   265,
     248,   112,   354,    33,    31,    50,    22,   307,   186,   373,
     281,   264,   398,    75,    76,   366,    33,   265,   265,    28,
     410,   168,   277,   391,   279,    24,   385,   386,    33,   264,
     264,    34,    30,   421,   173,   280,   204,   279,     8,   307,
     174,   185,   384,   265,   112,     8,     8,   189,   280,   168,
     307,    74,    61,   168,    15,   264,   168,   168,    68,    55,
      37,   136,    36,    56,   141,   227,    38,  -127,    39,    40,
      41,    42,    58,    62,   413,   249,   226,    63,    69,    73,
     239,   281,    56,    74,  -131,   422,    37,   248,   168,    92,
      93,    94,    38,   277,    39,    40,    41,    42,    73,   323,
     265,   324,    74,    79,    80,    15,   269,   270,    64,   265,
      85,    86,   264,   265,   265,    81,    82,    83,    84,   149,
     291,   264,   126,   127,   128,   264,   264,   250,   295,   296,
      65,   265,   265,   297,   298,   249,   358,   359,   266,   396,
     397,   265,  -129,   264,   264,   -80,   -80,   248,    77,   282,
      17,    18,    78,   264,   325,    90,   266,   266,   281,   120,
     121,   122,   123,   118,   119,   338,   226,    91,   226,   100,
     277,   281,     1,     2,     3,   101,   149,   102,   150,   151,
     105,   152,   266,   277,   103,   153,   154,   155,    37,   124,
     125,   106,   107,   108,    38,   109,    39,    40,    41,   156,
      98,   363,   110,   114,     4,   129,     1,     2,     3,   132,
     274,   133,   150,   151,   250,   152,   134,   275,   276,   135,
     282,   140,    37,   136,   146,   147,   148,   176,    38,   177,
      39,    40,    41,   156,     1,     2,     3,   172,   274,   266,
     150,   151,   178,   152,   180,   301,   302,   181,   266,   183,
      37,   184,   266,   266,   187,   196,    38,   407,    39,    40,
      41,   156,   188,   412,   197,   198,   199,   200,   201,   202,
     266,   266,   205,   212,   250,   203,   211,     1,     2,     3,
     266,   149,   213,   150,   151,   214,   152,   174,   219,     1,
       2,     3,   220,    37,   229,   221,   231,   282,   228,    38,
    -190,    39,    40,    41,   156,    37,   234,   233,   244,  -191,
     282,    38,   236,    39,    40,    41,   192,    37,   111,   237,
     241,   240,   242,    38,   243,    39,    40,    41,    42,    37,
     215,   245,   251,   253,   252,    38,   260,    39,    40,    41,
      42,   262,   261,   268,   271,  -102,   290,   299,   300,   310,
     311,   312,   313,   314,   329,   330,   318,   316,   337,   333,
     349,   339,   357,   365,   346,   360,   361,   355,   378,   367,
     379,   376,   387,   369,   380,   345,   370,   374,   291,   193,
     362,   286,     0,   381,   259,   117,   218,   383,   397,   393,
     402,   401,   408,     0,   411,   171,   414,   415,   419,   417,
       0,   426
};

static const yytype_int16 yycheck[] =
{
      15,     0,   257,    19,    31,    25,   257,    22,     7,     8,
     322,   246,   129,    17,   146,    91,    17,   257,    11,    34,
      13,    47,    37,    38,   129,   423,   102,   103,   426,   264,
     265,   107,   108,   273,    38,   157,   267,    38,    40,   161,
     157,    43,   164,   165,   161,   162,    40,   164,   165,    43,
      17,    16,   157,    20,    21,   290,   161,   189,    73,   164,
     165,    47,    77,   303,   304,    58,   306,   307,   308,    24,
     382,    36,    65,   328,   196,    40,    75,   328,    43,   196,
      47,    24,   109,    38,    16,   101,   106,   318,   328,   329,
     330,   196,    20,    21,    22,    38,    16,   337,   303,   304,
      47,   306,   307,   308,    36,    36,   392,    43,    40,    16,
     350,    43,   347,    44,    45,   401,    36,     0,   235,    47,
      40,   356,    16,    43,   329,   330,    13,    14,    15,   246,
     235,   146,   337,    40,    16,    47,    43,   377,   153,   361,
     257,   246,   393,    16,    17,   350,    40,   264,   265,    43,
     405,   129,   257,   388,   405,    17,   378,   379,    40,   264,
     265,    43,    17,   418,    39,   405,   181,   418,     0,   409,
      45,    17,   377,   290,   189,     7,     8,    36,   418,   157,
     420,    40,    26,   161,    43,   290,   164,   165,    32,    41,
      36,    40,    17,    45,    43,   210,    42,    37,    44,    45,
      46,    47,    47,    41,   409,   322,   205,    45,    41,    36,
     225,   328,    45,    40,    37,   420,    36,   322,   196,    20,
      21,    22,    42,   328,    44,    45,    46,    47,    36,   295,
     347,   297,    40,     5,     6,    43,   251,   252,    44,   356,
      11,    12,   347,   360,   361,     7,     8,     9,    10,    24,
      25,   356,    87,    88,    89,   360,   361,   235,    16,    17,
      47,   378,   379,    16,    17,   382,    44,    45,   246,    24,
      25,   388,    37,   378,   379,    31,    32,   382,     3,   257,
       7,     8,     4,   388,   299,    37,   264,   265,   405,    81,
      82,    83,    84,    79,    80,   310,   295,    37,   297,    41,
     405,   418,    20,    21,    22,    16,    24,    37,    26,    27,
      41,    29,   290,   418,    37,    33,    34,    35,    36,    85,
      86,    16,    37,    37,    42,    16,    44,    45,    46,    47,
      40,   346,    37,    45,    47,    38,    20,    21,    22,    16,
      24,    47,    26,    27,   322,    29,    45,    31,    32,    38,
     328,    23,    36,    40,    16,    37,    41,    45,    42,    17,
      44,    45,    46,    47,    20,    21,    22,    41,    24,   347,
      26,    27,    23,    29,    40,    31,    32,    36,   356,    36,
      36,    36,   360,   361,    36,    17,    42,   402,    44,    45,
      46,    47,    36,   408,    39,    17,    16,    39,    41,    17,
     378,   379,    36,    17,   382,    45,    47,    20,    21,    22,
     388,    24,    23,    26,    27,    23,    29,    45,    17,    20,
      21,    22,    41,    36,    16,    37,    16,   405,    37,    42,
      17,    44,    45,    46,    47,    36,    38,    37,    18,    17,
     418,    42,    47,    44,    45,    46,    47,    36,    37,    47,
      38,    37,    47,    42,    37,    44,    45,    46,    47,    36,
      37,    37,    43,    17,    43,    42,    17,    44,    45,    46,
      47,    17,    47,    17,    47,    30,    17,    43,    37,    36,
      17,    17,    17,    28,    17,    17,    39,    30,    17,    39,
      16,    19,    39,   349,    36,    19,    19,    37,    19,    38,
      19,    39,    17,    37,    31,   318,    37,    37,    25,   162,
     344,   261,    -1,    38,   242,    78,   199,    39,    25,    39,
      36,    39,    36,    -1,    37,   132,    38,    37,    39,    38,
      -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    47,    49,    50,   110,   113,    47,
     120,    47,   122,    47,   121,    43,     0,    50,    50,    16,
      36,    40,    43,   140,    17,    16,    36,    40,    43,   140,
      17,    16,    36,    40,    43,   140,    17,    36,    42,    44,
      45,    46,    47,   123,   124,   125,   126,   127,   128,   129,
      47,   120,   114,   132,   133,    41,    45,   123,    47,   122,
     116,   132,    41,    45,    44,    47,   121,   115,   132,    41,
     123,   123,   123,    36,    40,    16,    17,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      37,    37,    20,    21,    22,   134,   135,   136,    40,    43,
      41,    16,    37,    37,    43,    41,    16,    37,    37,    16,
      37,    37,   123,   131,    45,   110,   123,   124,   125,   125,
     126,   126,   126,   126,   127,   127,   128,   128,   128,    38,
     137,   137,    16,    47,    45,    38,    40,   120,   137,   137,
      23,    43,   122,   137,   137,   121,    16,    37,    41,    24,
      26,    27,    29,    33,    34,    35,    47,    53,    65,    71,
      97,   108,   109,   110,   111,   112,   113,   123,   130,   138,
     139,   134,    41,    39,    45,   117,    45,    17,    23,   131,
      40,    36,    54,    36,    36,    17,   123,    36,    36,    36,
     138,   138,    47,   108,   138,   138,    17,    39,    17,    16,
      39,    41,    17,    45,   123,    36,    55,    56,    57,    59,
      66,    47,    17,    23,    23,    37,   131,   138,   117,    17,
      41,    37,    17,    20,    21,    62,   110,   123,    37,    16,
     118,    16,   119,    37,    38,    74,    47,    47,    63,   123,
      37,    38,    47,    37,    18,    37,    72,    52,    53,   109,
     130,    43,    43,    17,    17,    38,    67,    69,    98,   118,
      17,    47,    17,    51,    53,   109,   130,    75,    17,   123,
     123,    47,    64,    68,    24,    31,    32,    53,    61,    85,
      97,   109,   130,   100,   101,   102,   119,    73,    51,    51,
      17,    25,    71,    76,    77,    16,    17,    16,    17,    43,
      37,    31,    32,    53,    61,    70,    85,    97,   109,   130,
      36,    17,    17,    17,    28,   106,    30,   104,    39,    51,
      24,    38,    84,    62,    62,   123,    17,    38,    60,    17,
      17,    70,    70,    39,    70,    70,    70,    17,   123,    19,
      99,    36,    44,    45,   103,    76,    36,    80,    52,    16,
      58,    61,    70,    70,    70,    37,   107,    39,    44,    45,
      19,    19,   101,   123,    51,    64,    70,    38,    51,    37,
      37,    51,   105,   105,    37,    81,    39,    86,    19,    19,
      31,    38,    82,    39,    70,   105,   105,    17,    78,    52,
      87,    51,    83,    39,    79,    77,    24,    25,    85,    88,
      89,    39,    36,    24,    38,    96,    77,   123,    36,    92,
      61,    37,   123,    70,    38,    37,    93,    38,    94,    39,
      90,    61,    70,    95,    91,    89,    39,    89
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
     110,   110,   111,   112,   113,   113,   113,   114,   113,   115,
     113,   116,   113,   113,   113,   113,   113,   113,   113,   113,
     117,   117,   118,   118,   119,   119,   120,   120,   120,   120,
     120,   121,   121,   121,   121,   121,   122,   122,   122,   122,
     122,   123,   123,   124,   124,   125,   125,   125,   126,   126,
     126,   126,   126,   127,   127,   127,   128,   128,   128,   128,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     130,   130,   131,   131,   133,   132,   134,   134,   135,   136,
     136,   136,   137,   138,   138,   138,   138,   138,   138,   138,
     139,   139,   140,   140,   140
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     2,     2,     3,
       0,     1,     1,     2,     0,     3,     1,     1,     1,     1,
       1,     1,     7,     0,    10,     0,     8,     1,     1,     2,
       2,     2,     1,     1,     1,     5,     6,     5,     6,     1,
       1,     0,     5,     3,     0,     6,     0,     4,     1,     0,
       2,     3,     3,     2,     2,     3,     2,     2,     2,     0,
       0,     0,    10,     0,     0,     8,     1,     1,     0,     0,
      11,     0,     0,     6,     0,     0,     9,     0,     3,     0,
       0,     0,    10,     1,     1,     0,     0,    11,     0,     0,
       6,     0,     0,     9,     0,     3,     0,     0,     0,    10,
       1,     0,     0,     0,     4,     0,     6,     4,     6,     4,
       3,     1,     0,     4,     0,     2,     1,     1,     1,     1,
       5,     4,     6,     6,     6,     6,     6,     0,     6,     0,
       6,     0,     6,     3,     8,     7,     3,     3,     9,     8,
       3,     1,     3,     0,     4,     0,     5,     3,     3,     2,
       1,     5,     3,     3,     2,     1,     5,     3,     3,     2,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       1,     3,     2,     1,     1,     1,     3,     4,     4,     7,
       3,     4,     3,     1,     0,     2,     1,     3,     2,     1,
       1,     1,     3,     2,     2,     3,     1,     2,     2,     0,
       3,     2,     3,     6,     5
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
#line 194 "SemanticAnalyzer.y"
                        {printf("Starting..\n");}
#line 1826 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 196 "SemanticAnalyzer.y"
                                                         {printf("RECURSIVE DECLARATION \n");}
#line 1832 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 198 "SemanticAnalyzer.y"
                                                        {printf("DECLARATION \n");}
#line 1838 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 201 "SemanticAnalyzer.y"
                                          {printf("Special..\n");}
#line 1844 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 202 "SemanticAnalyzer.y"
                                               {printf("Basic123..\n");}
#line 1850 "y.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 209 "SemanticAnalyzer.y"
                        {pushNewScope();}
#line 1856 "y.tab.c"
    break;

  case 22: /* forLoop1: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON  */
#line 215 "SemanticAnalyzer.y"
                                                                                                      {popScope(); printf("\nFOR SEMICOLON \n");}
#line 1862 "y.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 216 "SemanticAnalyzer.y"
                                                                                               {pushNewScope();}
#line 1868 "y.tab.c"
    break;

  case 24: /* forLoop2: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR $@2 inLoop CLCUR  */
#line 216 "SemanticAnalyzer.y"
                                                                                                                              {popScope(); popScope(); printf("\nproper FOR \n");}
#line 1874 "y.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 217 "SemanticAnalyzer.y"
                                                                                          {pushNewScope();}
#line 1880 "y.tab.c"
    break;

  case 26: /* forLoop3: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC $@3 singleLoopStatement  */
#line 217 "SemanticAnalyzer.y"
                                                                                                                                {popScope(); popScope(); printf("\nFOR SINGLE STATEMENT \n");}
#line 1886 "y.tab.c"
    break;

  case 35: /* forAssignStatement: INT IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 228 "SemanticAnalyzer.y"
                                                                                             {}
#line 1892 "y.tab.c"
    break;

  case 44: /* $@4: %empty  */
#line 239 "SemanticAnalyzer.y"
                         {pushNewScope();}
#line 1898 "y.tab.c"
    break;

  case 46: /* $@5: %empty  */
#line 240 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 1904 "y.tab.c"
    break;

  case 47: /* whileSuffix: OPCUR $@5 inLoop CLCUR  */
#line 240 "SemanticAnalyzer.y"
                                                   { popScope(); popScope(); printf("\nproper WHILE \n");}
#line 1910 "y.tab.c"
    break;

  case 48: /* whileSuffix: SEMICOLON  */
#line 241 "SemanticAnalyzer.y"
                              {popScope(); printf("\nWHILE SEMICOLON \n");}
#line 1916 "y.tab.c"
    break;

  case 49: /* $@6: %empty  */
#line 242 "SemanticAnalyzer.y"
                    {pushNewScope();}
#line 1922 "y.tab.c"
    break;

  case 50: /* whileSuffix: $@6 singleLoopStatement  */
#line 242 "SemanticAnalyzer.y"
                                                          { popScope(); popScope(); printf("\nSINGLE WHILE \n");}
#line 1928 "y.tab.c"
    break;

  case 51: /* inLoop: BREAK SEMICOLON inLoop  */
#line 244 "SemanticAnalyzer.y"
                                 {printf("\n break in loop \n");}
#line 1934 "y.tab.c"
    break;

  case 52: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 245 "SemanticAnalyzer.y"
                                            {printf("\ncontinue in loop \n");}
#line 1940 "y.tab.c"
    break;

  case 53: /* inLoop: specialStatement inLoop  */
#line 246 "SemanticAnalyzer.y"
                                          {printf("\n special statement in loop \n");}
#line 1946 "y.tab.c"
    break;

  case 54: /* inLoop: basicStatement inLoop  */
#line 247 "SemanticAnalyzer.y"
                                        {printf("\n basic statement in loop \n");}
#line 1952 "y.tab.c"
    break;

  case 55: /* inLoop: functionCall SEMICOLON inLoop  */
#line 248 "SemanticAnalyzer.y"
                                               {printf("\n basic statement in loop \n");}
#line 1958 "y.tab.c"
    break;

  case 56: /* inLoop: ifInLoopStatement inLoop  */
#line 249 "SemanticAnalyzer.y"
                                           {printf("\n if in loop \n");}
#line 1964 "y.tab.c"
    break;

  case 57: /* inLoop: switchStatement inLoop  */
#line 250 "SemanticAnalyzer.y"
                                         {printf("\n switch in loop \n");}
#line 1970 "y.tab.c"
    break;

  case 58: /* inLoop: singleLoopStatement inLoop  */
#line 251 "SemanticAnalyzer.y"
                                             {printf("\n any other statement in loop \n");}
#line 1976 "y.tab.c"
    break;

  case 60: /* $@7: %empty  */
#line 254 "SemanticAnalyzer.y"
                                                          {pushNewScope();}
#line 1982 "y.tab.c"
    break;

  case 61: /* $@8: %empty  */
#line 254 "SemanticAnalyzer.y"
                                                                                       {popScope();}
#line 1988 "y.tab.c"
    break;

  case 63: /* $@9: %empty  */
#line 255 "SemanticAnalyzer.y"
                                                               {pushNewScope();}
#line 1994 "y.tab.c"
    break;

  case 64: /* $@10: %empty  */
#line 255 "SemanticAnalyzer.y"
                                                                                                 {popScope();}
#line 2000 "y.tab.c"
    break;

  case 68: /* $@11: %empty  */
#line 259 "SemanticAnalyzer.y"
                                                      {pushNewScope();}
#line 2006 "y.tab.c"
    break;

  case 69: /* $@12: %empty  */
#line 259 "SemanticAnalyzer.y"
                                                                                   {popScope();}
#line 2012 "y.tab.c"
    break;

  case 71: /* $@13: %empty  */
#line 260 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 2018 "y.tab.c"
    break;

  case 72: /* $@14: %empty  */
#line 260 "SemanticAnalyzer.y"
                                                  {popScope();}
#line 2024 "y.tab.c"
    break;

  case 74: /* $@15: %empty  */
#line 261 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 2030 "y.tab.c"
    break;

  case 75: /* $@16: %empty  */
#line 261 "SemanticAnalyzer.y"
                                                                                     {popScope();}
#line 2036 "y.tab.c"
    break;

  case 77: /* $@17: %empty  */
#line 262 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 2042 "y.tab.c"
    break;

  case 78: /* ES: ELSE $@17 singleStatement  */
#line 262 "SemanticAnalyzer.y"
                                                 {popScope();}
#line 2048 "y.tab.c"
    break;

  case 80: /* $@18: %empty  */
#line 265 "SemanticAnalyzer.y"
                                                                {pushNewScope();}
#line 2054 "y.tab.c"
    break;

  case 81: /* $@19: %empty  */
#line 265 "SemanticAnalyzer.y"
                                                                                         {popScope;}
#line 2060 "y.tab.c"
    break;

  case 85: /* $@20: %empty  */
#line 269 "SemanticAnalyzer.y"
                                                          {pushNewScope();}
#line 2066 "y.tab.c"
    break;

  case 86: /* $@21: %empty  */
#line 269 "SemanticAnalyzer.y"
                                                                                   {popScope();}
#line 2072 "y.tab.c"
    break;

  case 88: /* $@22: %empty  */
#line 270 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 2078 "y.tab.c"
    break;

  case 89: /* $@23: %empty  */
#line 270 "SemanticAnalyzer.y"
                                              {popScope();}
#line 2084 "y.tab.c"
    break;

  case 91: /* $@24: %empty  */
#line 271 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 2090 "y.tab.c"
    break;

  case 92: /* $@25: %empty  */
#line 271 "SemanticAnalyzer.y"
                                                                                         {popScope();}
#line 2096 "y.tab.c"
    break;

  case 94: /* $@26: %empty  */
#line 272 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 2102 "y.tab.c"
    break;

  case 95: /* ESLoop: ELSE $@26 singleLoopStatement  */
#line 272 "SemanticAnalyzer.y"
                                                     {popScope();}
#line 2108 "y.tab.c"
    break;

  case 97: /* $@27: %empty  */
#line 275 "SemanticAnalyzer.y"
                                                         {pushNewScope();}
#line 2114 "y.tab.c"
    break;

  case 98: /* $@28: %empty  */
#line 275 "SemanticAnalyzer.y"
                                                                                                           {popScope();}
#line 2120 "y.tab.c"
    break;

  case 99: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR $@27 caseStatements defaultStatement $@28 CLCUR  */
#line 275 "SemanticAnalyzer.y"
                                                                                                                               {printf("SWITCH START..\n");}
#line 2126 "y.tab.c"
    break;

  case 101: /* caseStatements: %empty  */
#line 276 "SemanticAnalyzer.y"
                                     {printf("char/int..\n");}
#line 2132 "y.tab.c"
    break;

  case 102: /* $@29: %empty  */
#line 277 "SemanticAnalyzer.y"
                    {pushNewScope();}
#line 2138 "y.tab.c"
    break;

  case 103: /* $@30: %empty  */
#line 277 "SemanticAnalyzer.y"
                                              {pushNewScope();}
#line 2144 "y.tab.c"
    break;

  case 105: /* caseStatementInt: %empty  */
#line 277 "SemanticAnalyzer.y"
                                                                                   {printf("INT CASE..\n");}
#line 2150 "y.tab.c"
    break;

  case 107: /* caseInt: CASE INTVAL COLON caseContinuer  */
#line 279 "SemanticAnalyzer.y"
                                                  {printf("CASE INT : ..\n");}
#line 2156 "y.tab.c"
    break;

  case 112: /* $@31: %empty  */
#line 284 "SemanticAnalyzer.y"
                                  {pushNewScope();}
#line 2162 "y.tab.c"
    break;

  case 113: /* defaultStatement: DEFAULT COLON $@31 statements  */
#line 284 "SemanticAnalyzer.y"
                                                               {popScope();}
#line 2168 "y.tab.c"
    break;

  case 114: /* defaultStatement: %empty  */
#line 285 "SemanticAnalyzer.y"
                                          {printf(" \nDEFAULT : ..\n");}
#line 2174 "y.tab.c"
    break;

  case 117: /* basicStatement: expressionStatement  */
#line 291 "SemanticAnalyzer.y"
                                      {printf("BS->EXPS..\n");}
#line 2180 "y.tab.c"
    break;

  case 118: /* basicStatement: declarationStatement  */
#line 292 "SemanticAnalyzer.y"
                                       {printf("BS->DS..\n");}
#line 2186 "y.tab.c"
    break;

  case 119: /* basicStatement: assignmentStatement  */
#line 293 "SemanticAnalyzer.y"
                                        {printf("Basic->AS..\n");}
#line 2192 "y.tab.c"
    break;

  case 120: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 295 "SemanticAnalyzer.y"
                                                                                      {printf("AS1..\n");}
#line 2198 "y.tab.c"
    break;

  case 121: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 296 "SemanticAnalyzer.y"
                                                                 {printf("AS2..\n");}
#line 2204 "y.tab.c"
    break;

  case 124: /* declarationStatement: INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 300 "SemanticAnalyzer.y"
                                                                                    {int inst = getIdentifierFunctionType((yyvsp[-4].Str),false,true); if(inst == -1){insertInTable((yyvsp[-4].Str),strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);}else{printf("%s is already defined earlier\n",(yyvsp[-4].Str));return 1;}memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2210 "y.tab.c"
    break;

  case 125: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 301 "SemanticAnalyzer.y"
                                                                                {int inst = getIdentifierFunctionType((yyvsp[-4].Str),false,true); if(inst ==-1){insertInTable((yyvsp[-4].Str),strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-4].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2216 "y.tab.c"
    break;

  case 126: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 302 "SemanticAnalyzer.y"
                                                                                {int inst = getIdentifierFunctionType((yyvsp[-4].Str),false,true); if(inst == -1){insertInTable((yyvsp[-4].Str),strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-4].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2222 "y.tab.c"
    break;

  case 127: /* $@32: %empty  */
#line 303 "SemanticAnalyzer.y"
                                         {pushNewScope();}
#line 2228 "y.tab.c"
    break;

  case 128: /* declarationStatement: INT IDENTIFIER OPBRAC $@32 CLBRAC compoundStatements  */
#line 303 "SemanticAnalyzer.y"
                                                                                     {int inst = getIdentifierFunctionType((yyvsp[-4].Str),false,true); if(inst == -1){insertInTable((yyvsp[-4].Str),strdup("i"),strdup("i"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-4].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2234 "y.tab.c"
    break;

  case 129: /* $@33: %empty  */
#line 304 "SemanticAnalyzer.y"
                                           {pushNewScope();}
#line 2240 "y.tab.c"
    break;

  case 130: /* declarationStatement: FLOAT IDENTIFIER OPBRAC $@33 CLBRAC compoundStatements  */
#line 304 "SemanticAnalyzer.y"
                                                                                        {int inst = getIdentifierFunctionType((yyvsp[-4].Str),false,true); if(inst == -1){insertInTable((yyvsp[-4].Str),strdup("f"),strdup("f"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-4].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2246 "y.tab.c"
    break;

  case 131: /* $@34: %empty  */
#line 305 "SemanticAnalyzer.y"
                                          {pushNewScope();}
#line 2252 "y.tab.c"
    break;

  case 132: /* declarationStatement: CHAR IDENTIFIER OPBRAC $@34 CLBRAC compoundStatements  */
#line 305 "SemanticAnalyzer.y"
                                                                                       {int inst = getIdentifierFunctionType((yyvsp[-4].Str),false,true); if(inst == -1){insertInTable((yyvsp[-4].Str),strdup("c"),strdup("c"),currScope,currentParamCount,instanceParamList,NULL,0,false,true);} else{printf("%s is already defined earlier\n",(yyvsp[-4].Str));return 1;} memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2258 "y.tab.c"
    break;

  case 133: /* declarationStatement: INT declarationListInt SEMICOLON  */
#line 306 "SemanticAnalyzer.y"
                                                   {printf("DS1..\n");}
#line 2264 "y.tab.c"
    break;

  case 138: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON  */
#line 311 "SemanticAnalyzer.y"
                                                                                          {}
#line 2270 "y.tab.c"
    break;

  case 139: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON  */
#line 312 "SemanticAnalyzer.y"
                                                                              {}
#line 2276 "y.tab.c"
    break;

  case 146: /* declarationListInt: IDENTIFIER EQUAL expressionStatement COMMA declarationListInt  */
#line 323 "SemanticAnalyzer.y"
                                                                                    {printf("DSL1..\n");}
#line 2282 "y.tab.c"
    break;

  case 147: /* declarationListInt: IDENTIFIER COMMA declarationListInt  */
#line 324 "SemanticAnalyzer.y"
                                                      {}
#line 2288 "y.tab.c"
    break;

  case 148: /* declarationListInt: IDENTIFIER EQUAL expressionStatement  */
#line 325 "SemanticAnalyzer.y"
                                                       {}
#line 2294 "y.tab.c"
    break;

  case 149: /* declarationListInt: IDENTIFIER dimension  */
#line 326 "SemanticAnalyzer.y"
                                        {insertInTable((yyvsp[-1].Str),strdup("i"),strdup("i"),currScope, -1,NULL,sizes,instDim,true,false);instDim=0;sizes[0]=-1;sizes[1]=-1;}
#line 2300 "y.tab.c"
    break;

  case 150: /* declarationListInt: IDENTIFIER  */
#line 327 "SemanticAnalyzer.y"
                             {}
#line 2306 "y.tab.c"
    break;

  case 151: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListFloat  */
#line 329 "SemanticAnalyzer.y"
                                                                                        {printf("DSL1..\n");}
#line 2312 "y.tab.c"
    break;

  case 153: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement  */
#line 331 "SemanticAnalyzer.y"
                                                       {printf("DSL3..\n");}
#line 2318 "y.tab.c"
    break;

  case 154: /* declarationListFloat: IDENTIFIER dimension  */
#line 332 "SemanticAnalyzer.y"
                                        {printf("INTFLOAT ARRAY..\n");}
#line 2324 "y.tab.c"
    break;

  case 155: /* declarationListFloat: IDENTIFIER  */
#line 333 "SemanticAnalyzer.y"
                             {printf("DSL4..\n");}
#line 2330 "y.tab.c"
    break;

  case 161: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 341 "SemanticAnalyzer.y"
                                                                       {printf("ES1..\n");}
#line 2336 "y.tab.c"
    break;

  case 162: /* expressionStatement: logicalExpression  */
#line 342 "SemanticAnalyzer.y"
                                    {printf("ES2..\n");}
#line 2342 "y.tab.c"
    break;

  case 163: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 344 "SemanticAnalyzer.y"
                                                             {printf("LE1..\n");}
#line 2348 "y.tab.c"
    break;

  case 164: /* logicalExpression: expression  */
#line 345 "SemanticAnalyzer.y"
                             {printf("LE2..\n");}
#line 2354 "y.tab.c"
    break;

  case 165: /* expression: relationalExpression EQUALS expression  */
#line 347 "SemanticAnalyzer.y"
                                                     {printf("E1..\n");}
#line 2360 "y.tab.c"
    break;

  case 166: /* expression: relationalExpression NOTEQUAL expression  */
#line 348 "SemanticAnalyzer.y"
                                                           {printf("E2..\n");}
#line 2366 "y.tab.c"
    break;

  case 167: /* expression: relationalExpression  */
#line 349 "SemanticAnalyzer.y"
                                       {printf("E3..\n");}
#line 2372 "y.tab.c"
    break;

  case 172: /* relationalExpression: value  */
#line 355 "SemanticAnalyzer.y"
                        {printf("VALUE..\n");}
#line 2378 "y.tab.c"
    break;

  case 173: /* value: term ADD value  */
#line 357 "SemanticAnalyzer.y"
                        {printf("ADD..\n");}
#line 2384 "y.tab.c"
    break;

  case 175: /* value: term  */
#line 359 "SemanticAnalyzer.y"
               {printf("Basic TERM..\n");}
#line 2390 "y.tab.c"
    break;

  case 176: /* term: factor MULT term  */
#line 361 "SemanticAnalyzer.y"
                         {printf("MULT..\n");}
#line 2396 "y.tab.c"
    break;

  case 179: /* term: factor  */
#line 364 "SemanticAnalyzer.y"
                 {printf("Factor..\n");}
#line 2402 "y.tab.c"
    break;

  case 180: /* factor: IDENTIFIER  */
#line 366 "SemanticAnalyzer.y"
                     {}
#line 2408 "y.tab.c"
    break;

  case 181: /* factor: OPBRAC expressionStatement CLBRAC  */
#line 367 "SemanticAnalyzer.y"
                                            {(yyval.Str) = strdup((yyvsp[-1].Str));}
#line 2414 "y.tab.c"
    break;

  case 182: /* factor: LOGICALNOT expressionStatement  */
#line 368 "SemanticAnalyzer.y"
                                         {(yyval.Str) = strdup((yyvsp[0].Str));}
#line 2420 "y.tab.c"
    break;

  case 183: /* factor: CHARVAL  */
#line 369 "SemanticAnalyzer.y"
                  {(yyval.Str) = strdup("c");}
#line 2426 "y.tab.c"
    break;

  case 184: /* factor: INTVAL  */
#line 370 "SemanticAnalyzer.y"
                 {(yyval.Str) = strdup("i");printf("INT VALS.. %d\n",yylval);}
#line 2432 "y.tab.c"
    break;

  case 185: /* factor: FLOATVAL  */
#line 371 "SemanticAnalyzer.y"
                   {(yyval.Str) = strdup("f");}
#line 2438 "y.tab.c"
    break;

  case 188: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE  */
#line 374 "SemanticAnalyzer.y"
                                             {}
#line 2444 "y.tab.c"
    break;

  case 189: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 375 "SemanticAnalyzer.y"
                                                                     {}
#line 2450 "y.tab.c"
    break;

  case 190: /* functionCall: IDENTIFIER OPBRAC CLBRAC  */
#line 378 "SemanticAnalyzer.y"
                                         {}
#line 2456 "y.tab.c"
    break;

  case 191: /* functionCall: IDENTIFIER OPBRAC argList CLBRAC  */
#line 379 "SemanticAnalyzer.y"
                                                 {}
#line 2462 "y.tab.c"
    break;

  case 194: /* $@35: %empty  */
#line 385 "SemanticAnalyzer.y"
              {pushNewScope(); memset(instanceParamList, '\0',sizeof(instanceParamList)); currentParamCount = 0;}
#line 2468 "y.tab.c"
    break;

  case 197: /* paramContinuer: parameter COMMA paramContinuer  */
#line 387 "SemanticAnalyzer.y"
                                                                  {printf("FUNCTION params\n");}
#line 2474 "y.tab.c"
    break;

  case 198: /* parameter: type IDENTIFIER  */
#line 389 "SemanticAnalyzer.y"
                             {printf("FUNCTION param\n");insertInTable((yyvsp[0].Str),(yyvsp[-1].Str),(yyvsp[-1].Str),currScope,0,NULL,NULL,0,false,false);}
#line 2480 "y.tab.c"
    break;

  case 199: /* type: INT  */
#line 391 "SemanticAnalyzer.y"
            {(yyval.Str) = strdup("i");instanceParamList[currentParamCount++]=strdup("i");}
#line 2486 "y.tab.c"
    break;

  case 200: /* type: FLOAT  */
#line 392 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup("f");instanceParamList[currentParamCount++]=strdup("f");}
#line 2492 "y.tab.c"
    break;

  case 201: /* type: CHAR  */
#line 393 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup("c");instanceParamList[currentParamCount++]=strdup("c");}
#line 2498 "y.tab.c"
    break;

  case 202: /* compoundStatements: OPCUR statementList CLCUR  */
#line 395 "SemanticAnalyzer.y"
                                                {popScope();printf("FUNCTION statements\n");}
#line 2504 "y.tab.c"
    break;

  case 210: /* returnDec: RETURN expressionStatement SEMICOLON  */
#line 405 "SemanticAnalyzer.y"
                                                  {(yyval.Str) = strdup((yyvsp[-1].Str));}
#line 2510 "y.tab.c"
    break;

  case 212: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 408 "SemanticAnalyzer.y"
                                     {int i = (yyvsp[-1].Int); if(i<=0){printf("Array size has to be  Positive\n"); return 1;}sizes[0] = (yyvsp[-1].Int);instDim++;}
#line 2516 "y.tab.c"
    break;

  case 213: /* dimension: BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 409 "SemanticAnalyzer.y"
                                                                    {int a = (yyvsp[-4].Int); int b = (yyvsp[-1].Int); if(a<=0||b<=0){printf("Array sizes has to be  Positive\n"); return 1;}sizes[0] = (yyvsp[-4].Int); sizes[1] = (yyvsp[-1].Int);instDim+=2;}
#line 2522 "y.tab.c"
    break;

  case 214: /* dimension: BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 410 "SemanticAnalyzer.y"
                                                             {int i = (yyvsp[-1].Int); if(i<=0){printf("Array sizes has to be  Positive\n"); return 1;}sizes[1] = (yyvsp[-1].Int);instDim+=2;}
#line 2528 "y.tab.c"
    break;


#line 2532 "y.tab.c"

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

#line 411 "SemanticAnalyzer.y"

  
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
  
  
