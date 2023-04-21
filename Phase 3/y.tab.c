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
 		int dimensionofArray;
 		char *parameterList[1000];
 		int arrayDimension[1000];
 		int parameterCount;
 	};
 	symbolTable table[1000];
 	int availableScopes[1000]={-1};
 	int scopeIndex=0;// AvailableScopes array index points to the current 
 	int currIndex=0;// table array index points to the next empty one
 	int maxScope=0;
 	int currScope=0;
  
 	// insert function
 	void insertInTable(char *token,char *type,char *val,int sc,int paramCount,char *paramList[],int arrayDim[],int dimensionofArr,bool isArr,bool isFunc){
 		symbolTable newEntry;
 		strcpy(newEntry.lexeme,token);
 		strcpy(newEntry.value,val);
 		strcpy(newEntry.dataType,type);
 		newEntry.scope=sc;
  
 		if(isFunc){
     		for(int i =0;i<paramCount;i++){
     			strcpy(newEntry.parameterList[i],paramList[i]);
     		}
     		newEntry.parameterCount=paramCount;
     	}
  
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
 			if(strcmp(table[i].lexeme,token)){
				for(int j = scopeIndex;j>=0;j--){
					if(table[i].scope==availableScopes[j]){
						strcpy(table[i].value,value);
						return;
					}
				}
			}
 		}
 	}
	void printTable(){
		printf("TABLE IS THIS\n\n");
		printf("Lexeme		Value 		dataType 		isFunc		isArray			scope			paramCount		paramList		dimensionofArray	arrayList\n"); 
		for(int i=0;i<currIndex;i++){
			printf("%s		",table[i].lexeme);
			printf("%s		",table[i].value);
			printf("%s		",table[i].dataType);
			printf("%d		",table[i].isFunction);
			printf("%d		",table[i].isArray);
			printf("%d		",table[i].scope);
			printf("%d		",table[i].parameterCount);
			if(table[i].isFunction){
				for(int p = 0;p<table[i].parameterCount;p++){
					printf("%s ",table[i].parameterList[p]);
				}
			}
			printf("		");
			
			printf("%d		",table[i].dimensionofArray);
			if(table[i].isArray){
				for(int p = 0;p<table[i].dimensionofArray;p++){
					printf("%d ",table[i].arrayDimension[p]);
				}
			}
			printf("\n");
		}
	}
	void pushNewScope(){// Put a new scope for every open {
		availableScopes[++scopeIndex]=++maxScope;
		currScope = maxScope;
	}
	void popScope(){ // pop latest scope on every }
		availableScopes[scopeIndex--]=-1;
		currScope = availableScopes[scopeIndex];
	}
 

#line 183 "y.tab.c"

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
#line 112 "SemanticAnalyzer.y"

		int Int;
		float Float;
		char Char;
		char* Str;
		struct data{

		};
	

#line 341 "y.tab.c"

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
  YYSYMBOL_declarationListIntFloat = 120,  /* declarationListIntFloat  */
  YYSYMBOL_declarationListChar = 121,      /* declarationListChar  */
  YYSYMBOL_expressionStatement = 122,      /* expressionStatement  */
  YYSYMBOL_logicalExpression = 123,        /* logicalExpression  */
  YYSYMBOL_expression = 124,               /* expression  */
  YYSYMBOL_relationalExpression = 125,     /* relationalExpression  */
  YYSYMBOL_value = 126,                    /* value  */
  YYSYMBOL_term = 127,                     /* term  */
  YYSYMBOL_factor = 128,                   /* factor  */
  YYSYMBOL_functionCall = 129,             /* functionCall  */
  YYSYMBOL_argList = 130,                  /* argList  */
  YYSYMBOL_parameters = 131,               /* parameters  */
  YYSYMBOL_132_35 = 132,                   /* $@35  */
  YYSYMBOL_paramContinuer = 133,           /* paramContinuer  */
  YYSYMBOL_parameter = 134,                /* parameter  */
  YYSYMBOL_type = 135,                     /* type  */
  YYSYMBOL_compoundStatements = 136,       /* compoundStatements  */
  YYSYMBOL_statementList = 137,            /* statementList  */
  YYSYMBOL_returnDec = 138,                /* returnDec  */
  YYSYMBOL_dimension = 139                 /* dimension  */
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
#define YYLAST   536

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  207
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  413

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
       0,   152,   152,   154,   155,   156,   157,   159,   160,   161,
     162,   163,   164,   165,   167,   167,   168,   169,   170,   171,
     171,   171,   173,   174,   174,   175,   175,   177,   178,   179,
     180,   181,   182,   183,   185,   186,   187,   188,   189,   190,
     191,   191,   192,   193,   196,   196,   197,   197,   198,   199,
     199,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     211,   211,   211,   212,   212,   212,   213,   213,   215,   215,
     215,   216,   216,   216,   217,   217,   217,   218,   218,   219,
     221,   221,   221,   222,   222,   224,   224,   224,   225,   225,
     225,   226,   226,   226,   227,   227,   228,   230,   230,   230,
     231,   231,   232,   232,   232,   232,   233,   234,   235,   236,
     237,   237,   238,   238,   238,   241,   242,   244,   245,   246,
     248,   249,   251,   252,   253,   254,   255,   256,   256,   257,
     257,   258,   258,   259,   260,   261,   262,   263,   264,   265,
     267,   267,   268,   268,   269,   269,   271,   272,   273,   274,
     275,   277,   278,   279,   280,   281,   283,   284,   286,   287,
     289,   290,   291,   293,   294,   295,   296,   297,   299,   300,
     301,   303,   304,   305,   306,   308,   309,   310,   311,   312,
     313,   314,   315,   318,   319,   322,   322,   324,   324,   325,
     325,   327,   329,   330,   331,   333,   335,   335,   335,   335,
     335,   335,   335,   337,   337,   339,   340,   341
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
  "prattributes", "scattributes", "declarationListIntFloat",
  "declarationListChar", "expressionStatement", "logicalExpression",
  "expression", "relationalExpression", "value", "term", "factor",
  "functionCall", "argList", "parameters", "$@35", "paramContinuer",
  "parameter", "type", "compoundStatements", "statementList", "returnDec",
  "dimension", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-312)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-132)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      38,   -19,   -12,     3,     2,    74,  -312,    38,    38,    13,
      73,    51,   102,    52,   153,   195,  -312,  -312,  -312,   130,
     157,   -24,   195,  -312,  -312,   149,   161,     6,   159,  -312,
    -312,   171,    41,  -312,   195,   195,  -312,  -312,  -312,   170,
     128,   214,   215,   144,   205,   155,   238,    -2,  -312,   186,
     199,   237,    67,   202,   229,    63,  -312,   218,   253,   135,
     254,   258,   271,   277,   259,   278,  -312,   256,   269,  -312,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   280,   280,  -312,  -312,  -312,  -312,   307,
     284,   293,   301,   300,   130,   280,   280,   324,   178,   149,
     280,   280,  -312,   310,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,   308,  -312,
    -312,   237,  -312,   315,   -29,   303,  -312,  -312,  -312,   340,
     345,  -312,  -312,  -312,   321,   327,  -312,   335,   337,    81,
     339,   341,   166,   308,  -312,  -312,  -312,   308,   260,  -312,
     308,   308,  -312,  -312,   308,   342,  -312,  -312,  -312,   359,
     363,   347,   349,  -312,   378,   352,   195,   364,  -312,   354,
    -312,   385,   381,   382,   127,  -312,  -312,   187,  -312,  -312,
    -312,  -312,  -312,  -312,   361,   390,  -312,  -312,   369,   371,
      -8,  -312,  -312,  -312,  -312,   195,   384,  -312,   399,   403,
     409,  -312,     9,  -312,  -312,  -312,   389,  -312,   383,   386,
     195,  -312,   391,   393,   387,   392,   418,   400,  -312,   195,
     422,  -312,   396,   401,   402,   429,  -312,    19,  -312,   399,
     430,   404,   431,  -312,  -312,   396,  -312,  -312,  -312,  -312,
     195,   195,   405,  -312,  -312,  -312,   338,   419,  -312,  -312,
     403,  -312,  -312,   396,   396,   396,   163,   232,   245,   407,
     416,   367,   420,   437,   438,  -312,  -312,  -312,  -312,  -312,
    -312,   432,  -312,   427,  -312,   423,  -312,  -312,  -312,    -6,
    -312,  -312,  -312,    -8,  -312,    -8,  -312,   195,    23,   441,
     442,   367,   367,   424,   367,   367,   367,   367,   195,  -312,
    -312,   445,  -312,    98,  -312,   163,   425,  -312,   396,  -312,
    -312,   449,  -312,  -312,   338,   367,   367,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,   433,  -312,   428,   223,   447,   450,
     419,  -312,   195,   396,  -312,   405,   367,  -312,  -312,  -312,
     434,   396,  -312,   436,   439,   396,   396,  -312,   440,  -312,
    -312,   435,   246,  -312,   452,   456,   448,  -312,  -312,   443,
     444,  -312,   367,   396,   396,   451,  -312,   396,  -312,  -312,
    -312,  -312,  -312,   396,  -312,   446,  -312,   453,   264,   454,
    -312,   455,   116,  -312,  -312,  -312,   453,   195,   458,  -312,
     338,  -312,   459,   195,   367,  -312,   457,   460,  -312,  -312,
     461,   462,  -312,   338,  -312,   367,  -312,  -312,   463,   464,
    -312,   463,  -312
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     5,   150,
       0,   155,     0,   150,     0,     0,     1,     4,     3,     0,
     187,     0,     0,   149,   133,     0,   187,     0,     0,   154,
     136,   187,     0,   137,     0,     0,   178,   179,   180,   175,
       0,   157,   159,   162,   167,   170,   174,   150,   147,     0,
       0,     0,     0,     0,   148,   155,   152,     0,     0,     0,
       0,   153,     0,     0,     0,     0,   177,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   192,   194,   193,   188,   189,
       0,     0,     0,   205,     0,     0,     0,     0,   205,     0,
       0,     0,   176,     0,   120,   156,   158,   160,   161,   163,
     164,   165,   166,   168,   169,   171,   172,   173,   202,   128,
     124,     0,   191,     0,     0,     0,   146,   132,   125,     0,
       0,   151,   130,   126,   181,     0,    14,     0,     0,     0,
       0,     0,   175,   202,    17,    16,    18,   202,   116,   119,
     202,   202,   118,   117,   202,     0,   199,   190,   207,     0,
     141,     0,     0,   135,     0,     0,     0,     0,    44,     0,
     204,     0,     0,     0,     0,   197,   196,   175,   115,   200,
     201,   198,   195,   139,     0,     0,   206,   134,     0,     0,
       0,    15,    21,    19,    20,     0,     0,   203,   143,   145,
       0,   186,     0,   140,   138,   182,    63,    39,     0,     0,
      41,    34,     0,     0,     0,     0,     0,     0,   183,     0,
       0,    60,     0,     0,     0,     0,    40,    49,    97,   143,
       0,     0,     0,   185,   184,    10,    64,    11,    12,    13,
       0,     0,     0,    48,    46,    45,     0,   101,   142,   122,
     145,   123,    61,    10,    10,    10,    79,     0,     0,     0,
       0,    59,     0,     0,     0,    27,    50,    33,    18,    28,
      29,   114,   100,     0,   144,     0,     7,     8,     9,    77,
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
    -312,  -312,   262,  -211,  -302,   -70,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -242,  -184,  -312,   145,  -312,  -312,  -312,
    -312,  -312,    30,  -251,  -312,  -312,  -312,  -312,   177,  -311,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -243,  -312,  -312,
    -312,  -253,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -183,
    -312,  -312,  -312,   154,  -312,  -312,  -312,  -207,  -312,  -312,
     344,  -117,    15,  -312,  -312,    62,  -312,  -312,  -312,   302,
     261,   239,     8,   -23,   -15,   465,   212,   158,   233,   184,
    -312,   -54,  -312,   115,  -312,   366,  -312,  -312,    20,    39,
    -312,    -3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,   356,   236,   291,   167,   191,   192,   193,
     336,   194,   314,   292,   210,   225,   260,   144,   195,   245,
     261,   246,   293,   145,   235,   275,   222,   256,   281,   282,
     373,   379,   333,   360,   367,   377,   308,   294,   362,   375,
     384,   385,   405,   409,   394,   401,   403,   408,   390,   146,
     247,   326,   271,   272,   273,   330,   304,   357,   302,   341,
     147,   296,   149,   150,   151,   152,    49,    62,    57,   161,
     215,   217,    10,    12,   153,    41,    42,    43,    44,    45,
      46,   297,   202,    50,    51,    88,    89,    90,   119,   155,
     156,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,   148,    56,   267,   266,   280,   334,    54,    29,   207,
     159,    14,   208,   209,    19,     7,   160,    52,   306,    65,
      66,    53,     7,     7,   252,   219,   148,    48,     9,    19,
     148,   148,   307,   148,   148,    11,   243,   148,    32,     4,
     312,    22,   276,   277,   278,    15,   220,    59,   143,    20,
      13,    60,    29,    21,   280,   105,    22,   244,     1,     2,
       3,   313,     8,   268,   154,   374,   380,    25,    19,     8,
       8,   267,   337,   143,    16,   391,   131,   143,   295,    25,
     143,   143,    64,   104,   143,     4,    53,    26,    31,   154,
      24,    27,    32,   154,    28,    22,   154,   154,   170,   309,
     154,   310,   126,    32,   120,   238,    28,    91,   295,   295,
      92,   295,   295,   295,   295,   127,   128,    34,   254,    30,
     132,   133,   349,    35,   171,    36,    37,    38,    39,   269,
     353,   268,   295,   295,   327,   383,   254,   254,   254,   358,
     388,    58,   328,   329,    68,    69,    63,   267,   395,    72,
      73,   189,   237,   295,   389,   410,   370,   371,   412,   201,
     267,   406,   376,    34,   200,   253,    78,    79,   239,    35,
      33,    36,    37,    38,    39,    91,   265,    47,    97,   295,
     212,   255,   175,   253,   253,   253,   176,   135,   279,   179,
     180,   238,   270,   181,  -127,   226,    55,   269,  -131,   255,
     255,   255,   174,    61,   233,   211,    67,   268,  -129,    15,
      67,   295,    74,    75,    76,    77,   254,    70,   125,    71,
     268,   130,   295,    83,   254,   257,   258,    67,   254,   254,
      15,    34,   109,   110,   111,   112,    84,    35,   237,    36,
      37,    38,    39,    93,   265,    94,   254,   254,   283,   284,
     238,    80,    81,    82,   239,    95,   254,    85,    86,    87,
     270,   285,   286,   253,   115,   116,   117,   343,   344,    17,
      18,   253,   311,   269,    99,   253,   253,   -80,   -80,   255,
       1,     2,     3,   324,   107,   108,   269,   255,   381,   382,
      96,   255,   255,   253,   253,    98,    34,   237,   211,    91,
     211,   103,    35,   253,    36,    37,    38,   177,   100,   255,
     255,   113,   114,   239,   101,   102,     4,   348,   118,   255,
     265,   317,   318,   121,   320,   321,   322,   323,     1,     2,
       3,   122,   135,   265,   136,   137,   270,   138,   123,   124,
     125,   139,   140,   141,    34,   338,   339,   129,   162,   270,
      35,   134,    36,    37,    38,   142,   158,   163,     1,     2,
       3,   165,   262,   166,   136,   137,   351,   138,   164,   263,
     264,   168,   392,   169,    34,   172,   183,   173,   397,   184,
      35,   182,    36,    37,    38,   142,   185,     1,     2,     3,
     186,   262,   369,   136,   137,   187,   138,   188,   289,   290,
     190,   196,   197,    34,   198,   199,   160,   204,   206,    35,
     205,    36,    37,    38,   142,   214,     1,     2,     3,   216,
     135,   213,   136,   137,   398,   138,   218,   221,   227,   230,
     223,   228,    34,   224,   229,   407,   231,   232,    35,   234,
      36,    37,    38,   142,   240,   241,   242,   249,   251,  -102,
     287,   250,   259,   288,   299,   300,   298,   303,   315,   316,
     301,   332,   305,   319,   325,   335,   345,   342,   372,   346,
     340,   363,   352,   354,   361,   364,   355,   359,   279,   365,
     350,   366,   331,   368,   347,   378,   203,   157,   382,   274,
     248,   387,   178,   386,   393,   399,   396,   400,     0,   402,
       0,   404,     0,   411,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106
};

static const yytype_int16 yycheck[] =
{
      15,   118,    25,   246,   246,   256,   308,    22,    11,    17,
      39,     3,    20,    21,    16,     0,    45,    41,    24,    34,
      35,    45,     7,     8,   235,    16,   143,    19,    47,    16,
     147,   148,    38,   150,   151,    47,    17,   154,    40,    47,
      17,    43,   253,   254,   255,    43,    37,    41,   118,    36,
      47,    45,    55,    40,   305,    70,    43,    38,    20,    21,
      22,    38,     0,   246,   118,   367,   377,    16,    16,     7,
       8,   314,   314,   143,     0,   386,    99,   147,   261,    16,
     150,   151,    41,    68,   154,    47,    45,    36,    36,   143,
      17,    40,    40,   147,    43,    43,   150,   151,    17,   283,
     154,   285,    94,    40,    84,   222,    43,    40,   291,   292,
      43,   294,   295,   296,   297,    95,    96,    36,   235,    17,
     100,   101,   333,    42,   139,    44,    45,    46,    47,   246,
     341,   314,   315,   316,    36,   378,   253,   254,   255,   346,
      24,    26,    44,    45,    16,    17,    31,   390,   390,     5,
       6,   166,   222,   336,    38,   408,   363,   364,   411,   174,
     403,   403,   373,    36,    37,   235,    11,    12,   222,    42,
      17,    44,    45,    46,    47,    40,   246,    47,    43,   362,
     195,   235,   143,   253,   254,   255,   147,    24,    25,   150,
     151,   308,   246,   154,    37,   210,    47,   314,    37,   253,
     254,   255,    36,    44,   219,   190,    40,   390,    37,    43,
      40,   394,     7,     8,     9,    10,   333,     3,    40,     4,
     403,    43,   405,    37,   341,   240,   241,    40,   345,   346,
      43,    36,    74,    75,    76,    77,    37,    42,   308,    44,
      45,    46,    47,    41,   314,    16,   363,   364,    16,    17,
     367,    13,    14,    15,   308,    37,   373,    20,    21,    22,
     314,    16,    17,   333,    80,    81,    82,    44,    45,     7,
       8,   341,   287,   390,    16,   345,   346,    31,    32,   333,
      20,    21,    22,   298,    72,    73,   403,   341,    24,    25,
      37,   345,   346,   363,   364,    41,    36,   367,   283,    40,
     285,    45,    42,   373,    44,    45,    46,    47,    37,   363,
     364,    78,    79,   367,    37,    37,    47,   332,    38,   373,
     390,   291,   292,    16,   294,   295,   296,   297,    20,    21,
      22,    47,    24,   403,    26,    27,   390,    29,    45,    38,
      40,    33,    34,    35,    36,   315,   316,    23,    45,   403,
      42,    41,    44,    45,    46,    47,    41,    17,    20,    21,
      22,    40,    24,    36,    26,    27,   336,    29,    23,    31,
      32,    36,   387,    36,    36,    36,    17,    36,   393,    16,
      42,    39,    44,    45,    46,    47,    39,    20,    21,    22,
      41,    24,   362,    26,    27,    17,    29,    45,    31,    32,
      36,    47,    17,    36,    23,    23,    45,    17,    37,    42,
      41,    44,    45,    46,    47,    16,    20,    21,    22,    16,
      24,    37,    26,    27,   394,    29,    17,    38,    37,    37,
      47,    38,    36,    47,    47,   405,    18,    37,    42,    17,
      44,    45,    46,    47,    43,    43,    17,    17,    17,    30,
      43,    47,    47,    37,    17,    17,    36,    30,    17,    17,
      28,    36,    39,    39,    19,    16,    19,    39,    17,    19,
      37,    19,    38,    37,    39,    19,    37,    37,    25,    31,
     335,    38,   305,    39,   330,    39,   184,   121,    25,   250,
     229,    36,   148,    39,    36,    38,    37,    37,    -1,    38,
      -1,    39,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    47,    49,    50,   110,   113,    47,
     120,    47,   121,    47,   120,    43,     0,    50,    50,    16,
      36,    40,    43,   139,    17,    16,    36,    40,    43,   139,
      17,    36,    40,    17,    36,    42,    44,    45,    46,    47,
     122,   123,   124,   125,   126,   127,   128,    47,   120,   114,
     131,   132,    41,    45,   122,    47,   121,   116,   131,    41,
      45,    44,   115,   131,    41,   122,   122,    40,    16,    17,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    37,    37,    20,    21,    22,   133,   134,
     135,    40,    43,    41,    16,    37,    37,    43,    41,    16,
      37,    37,    37,    45,   110,   122,   123,   124,   124,   125,
     125,   125,   125,   126,   126,   127,   127,   127,    38,   136,
     136,    16,    47,    45,    38,    40,   120,   136,   136,    23,
      43,   121,   136,   136,    41,    24,    26,    27,    29,    33,
      34,    35,    47,    53,    65,    71,    97,   108,   109,   110,
     111,   112,   113,   122,   129,   137,   138,   133,    41,    39,
      45,   117,    45,    17,    23,    40,    36,    54,    36,    36,
      17,   122,    36,    36,    36,   137,   137,    47,   108,   137,
     137,   137,    39,    17,    16,    39,    41,    17,    45,   122,
      36,    55,    56,    57,    59,    66,    47,    17,    23,    23,
      37,   122,   130,   117,    17,    41,    37,    17,    20,    21,
      62,   110,   122,    37,    16,   118,    16,   119,    17,    16,
      37,    38,    74,    47,    47,    63,   122,    37,    38,    47,
      37,    18,    37,   122,    17,    72,    52,    53,   109,   129,
      43,    43,    17,    17,    38,    67,    69,    98,   118,    17,
      47,    17,    51,    53,   109,   129,    75,   122,   122,    47,
      64,    68,    24,    31,    32,    53,    61,    85,    97,   109,
     129,   100,   101,   102,   119,    73,    51,    51,    51,    25,
      71,    76,    77,    16,    17,    16,    17,    43,    37,    31,
      32,    53,    61,    70,    85,    97,   109,   129,    36,    17,
      17,    28,   106,    30,   104,    39,    24,    38,    84,    62,
      62,   122,    17,    38,    60,    17,    17,    70,    70,    39,
      70,    70,    70,    70,   122,    19,    99,    36,    44,    45,
     103,    76,    36,    80,    52,    16,    58,    61,    70,    70,
      37,   107,    39,    44,    45,    19,    19,   101,   122,    51,
      64,    70,    38,    51,    37,    37,    51,   105,   105,    37,
      81,    39,    86,    19,    19,    31,    38,    82,    39,    70,
     105,   105,    17,    78,    52,    87,    51,    83,    39,    79,
      77,    24,    25,    85,    88,    89,    39,    36,    24,    38,
      96,    77,   122,    36,    92,    61,    37,   122,    70,    38,
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
     110,   110,   111,   112,   113,   113,   113,   114,   113,   115,
     113,   116,   113,   113,   113,   113,   113,   113,   113,   113,
     117,   117,   118,   118,   119,   119,   120,   120,   120,   120,
     120,   121,   121,   121,   121,   121,   122,   122,   123,   123,
     124,   124,   124,   125,   125,   125,   125,   125,   126,   126,
     126,   127,   127,   127,   127,   128,   128,   128,   128,   128,
     128,   128,   128,   129,   129,   130,   130,   132,   131,   133,
     133,   134,   135,   135,   135,   136,   137,   137,   137,   137,
     137,   137,   137,   138,   138,   139,   139,   139
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
       5,     4,     6,     6,     6,     6,     6,     0,     6,     0,
       6,     0,     6,     3,     8,     7,     3,     3,     9,     8,
       3,     1,     3,     0,     4,     0,     5,     3,     3,     2,
       1,     5,     3,     3,     2,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     3,     2,     1,     1,
       1,     4,     7,     4,     5,     3,     1,     0,     2,     1,
       3,     2,     1,     1,     1,     3,     2,     2,     2,     1,
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
#line 152 "SemanticAnalyzer.y"
                        {printf("Starting..\n");}
#line 1781 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 154 "SemanticAnalyzer.y"
                                                         {printf("RECURSIVE DECLARATION \n");}
#line 1787 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 156 "SemanticAnalyzer.y"
                                                        {printf("DECLARATION \n");}
#line 1793 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 159 "SemanticAnalyzer.y"
                                          {printf("Special..\n");}
#line 1799 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 160 "SemanticAnalyzer.y"
                                               {printf("Basic123..\n");}
#line 1805 "y.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 167 "SemanticAnalyzer.y"
                        {pushNewScope();}
#line 1811 "y.tab.c"
    break;

  case 22: /* forLoop1: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON  */
#line 173 "SemanticAnalyzer.y"
                                                                                                      {popScope(); printf("\nFOR SEMICOLON \n");}
#line 1817 "y.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 174 "SemanticAnalyzer.y"
                                                                                               {pushNewScope();}
#line 1823 "y.tab.c"
    break;

  case 24: /* forLoop2: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR $@2 inLoop CLCUR  */
#line 174 "SemanticAnalyzer.y"
                                                                                                                              {popScope(); popScope(); printf("\nproper FOR \n");}
#line 1829 "y.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 175 "SemanticAnalyzer.y"
                                                                                          {pushNewScope();}
#line 1835 "y.tab.c"
    break;

  case 26: /* forLoop3: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC $@3 singleLoopStatement  */
#line 175 "SemanticAnalyzer.y"
                                                                                                                                {popScope(); popScope(); printf("\nFOR SINGLE STATEMENT \n");}
#line 1841 "y.tab.c"
    break;

  case 35: /* forAssignStatement: INT IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 186 "SemanticAnalyzer.y"
                                                                                             {}
#line 1847 "y.tab.c"
    break;

  case 44: /* $@4: %empty  */
#line 196 "SemanticAnalyzer.y"
                         {pushNewScope();}
#line 1853 "y.tab.c"
    break;

  case 46: /* $@5: %empty  */
#line 197 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 1859 "y.tab.c"
    break;

  case 47: /* whileSuffix: OPCUR $@5 inLoop CLCUR  */
#line 197 "SemanticAnalyzer.y"
                                                   { popScope(); popScope(); printf("\nproper WHILE \n");}
#line 1865 "y.tab.c"
    break;

  case 48: /* whileSuffix: SEMICOLON  */
#line 198 "SemanticAnalyzer.y"
                              {popScope(); printf("\nWHILE SEMICOLON \n");}
#line 1871 "y.tab.c"
    break;

  case 49: /* $@6: %empty  */
#line 199 "SemanticAnalyzer.y"
                    {pushNewScope();}
#line 1877 "y.tab.c"
    break;

  case 50: /* whileSuffix: $@6 singleLoopStatement  */
#line 199 "SemanticAnalyzer.y"
                                                          { popScope(); popScope(); printf("\nSINGLE WHILE \n");}
#line 1883 "y.tab.c"
    break;

  case 51: /* inLoop: BREAK SEMICOLON inLoop  */
#line 201 "SemanticAnalyzer.y"
                                 {printf("\n break in loop \n");}
#line 1889 "y.tab.c"
    break;

  case 52: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 202 "SemanticAnalyzer.y"
                                            {printf("\ncontinue in loop \n");}
#line 1895 "y.tab.c"
    break;

  case 53: /* inLoop: specialStatement inLoop  */
#line 203 "SemanticAnalyzer.y"
                                          {printf("\n special statement in loop \n");}
#line 1901 "y.tab.c"
    break;

  case 54: /* inLoop: basicStatement inLoop  */
#line 204 "SemanticAnalyzer.y"
                                        {printf("\n basic statement in loop \n");}
#line 1907 "y.tab.c"
    break;

  case 55: /* inLoop: functionCall inLoop  */
#line 205 "SemanticAnalyzer.y"
                                     {printf("\n basic statement in loop \n");}
#line 1913 "y.tab.c"
    break;

  case 56: /* inLoop: ifInLoopStatement inLoop  */
#line 206 "SemanticAnalyzer.y"
                                           {printf("\n if in loop \n");}
#line 1919 "y.tab.c"
    break;

  case 57: /* inLoop: switchStatement inLoop  */
#line 207 "SemanticAnalyzer.y"
                                         {printf("\n switch in loop \n");}
#line 1925 "y.tab.c"
    break;

  case 58: /* inLoop: singleLoopStatement inLoop  */
#line 208 "SemanticAnalyzer.y"
                                             {printf("\n any other statement in loop \n");}
#line 1931 "y.tab.c"
    break;

  case 60: /* $@7: %empty  */
#line 211 "SemanticAnalyzer.y"
                                                          {pushNewScope();}
#line 1937 "y.tab.c"
    break;

  case 61: /* $@8: %empty  */
#line 211 "SemanticAnalyzer.y"
                                                                                       {popScope();}
#line 1943 "y.tab.c"
    break;

  case 63: /* $@9: %empty  */
#line 212 "SemanticAnalyzer.y"
                                                               {pushNewScope();}
#line 1949 "y.tab.c"
    break;

  case 64: /* $@10: %empty  */
#line 212 "SemanticAnalyzer.y"
                                                                                                 {popScope();}
#line 1955 "y.tab.c"
    break;

  case 68: /* $@11: %empty  */
#line 215 "SemanticAnalyzer.y"
                                                      {pushNewScope();}
#line 1961 "y.tab.c"
    break;

  case 69: /* $@12: %empty  */
#line 215 "SemanticAnalyzer.y"
                                                                                   {popScope();}
#line 1967 "y.tab.c"
    break;

  case 71: /* $@13: %empty  */
#line 216 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 1973 "y.tab.c"
    break;

  case 72: /* $@14: %empty  */
#line 216 "SemanticAnalyzer.y"
                                                  {popScope();}
#line 1979 "y.tab.c"
    break;

  case 74: /* $@15: %empty  */
#line 217 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 1985 "y.tab.c"
    break;

  case 75: /* $@16: %empty  */
#line 217 "SemanticAnalyzer.y"
                                                                                     {popScope();}
#line 1991 "y.tab.c"
    break;

  case 77: /* $@17: %empty  */
#line 218 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 1997 "y.tab.c"
    break;

  case 78: /* ES: ELSE $@17 singleStatement  */
#line 218 "SemanticAnalyzer.y"
                                                 {popScope();}
#line 2003 "y.tab.c"
    break;

  case 80: /* $@18: %empty  */
#line 221 "SemanticAnalyzer.y"
                                                                {pushNewScope();}
#line 2009 "y.tab.c"
    break;

  case 81: /* $@19: %empty  */
#line 221 "SemanticAnalyzer.y"
                                                                                         {popScope;}
#line 2015 "y.tab.c"
    break;

  case 85: /* $@20: %empty  */
#line 224 "SemanticAnalyzer.y"
                                                          {pushNewScope();}
#line 2021 "y.tab.c"
    break;

  case 86: /* $@21: %empty  */
#line 224 "SemanticAnalyzer.y"
                                                                                   {popScope();}
#line 2027 "y.tab.c"
    break;

  case 88: /* $@22: %empty  */
#line 225 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 2033 "y.tab.c"
    break;

  case 89: /* $@23: %empty  */
#line 225 "SemanticAnalyzer.y"
                                              {popScope();}
#line 2039 "y.tab.c"
    break;

  case 91: /* $@24: %empty  */
#line 226 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 2045 "y.tab.c"
    break;

  case 92: /* $@25: %empty  */
#line 226 "SemanticAnalyzer.y"
                                                                                         {popScope();}
#line 2051 "y.tab.c"
    break;

  case 94: /* $@26: %empty  */
#line 227 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 2057 "y.tab.c"
    break;

  case 95: /* ESLoop: ELSE $@26 singleLoopStatement  */
#line 227 "SemanticAnalyzer.y"
                                                     {popScope();}
#line 2063 "y.tab.c"
    break;

  case 97: /* $@27: %empty  */
#line 230 "SemanticAnalyzer.y"
                                                         {pushNewScope();}
#line 2069 "y.tab.c"
    break;

  case 98: /* $@28: %empty  */
#line 230 "SemanticAnalyzer.y"
                                                                                                           {popScope();}
#line 2075 "y.tab.c"
    break;

  case 99: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR $@27 caseStatements defaultStatement $@28 CLCUR  */
#line 230 "SemanticAnalyzer.y"
                                                                                                                               {printf("SWITCH START..\n");}
#line 2081 "y.tab.c"
    break;

  case 101: /* caseStatements: %empty  */
#line 231 "SemanticAnalyzer.y"
                                     {printf("char/int..\n");}
#line 2087 "y.tab.c"
    break;

  case 102: /* $@29: %empty  */
#line 232 "SemanticAnalyzer.y"
                    {pushNewScope();}
#line 2093 "y.tab.c"
    break;

  case 103: /* $@30: %empty  */
#line 232 "SemanticAnalyzer.y"
                                              {pushNewScope();}
#line 2099 "y.tab.c"
    break;

  case 105: /* caseStatementInt: %empty  */
#line 232 "SemanticAnalyzer.y"
                                                                                   {printf("INT CASE..\n");}
#line 2105 "y.tab.c"
    break;

  case 107: /* caseInt: CASE INTVAL COLON caseContinuer  */
#line 234 "SemanticAnalyzer.y"
                                                  {printf("CASE INT : ..\n");}
#line 2111 "y.tab.c"
    break;

  case 112: /* $@31: %empty  */
#line 238 "SemanticAnalyzer.y"
                                  {pushNewScope();}
#line 2117 "y.tab.c"
    break;

  case 113: /* defaultStatement: DEFAULT COLON $@31 statements  */
#line 238 "SemanticAnalyzer.y"
                                                               {popScope();}
#line 2123 "y.tab.c"
    break;

  case 114: /* defaultStatement: %empty  */
#line 238 "SemanticAnalyzer.y"
                                                                               {printf(" \nDEFAULT : ..\n");}
#line 2129 "y.tab.c"
    break;

  case 117: /* basicStatement: expressionStatement  */
#line 244 "SemanticAnalyzer.y"
                                      {printf("BS->EXPS..\n");}
#line 2135 "y.tab.c"
    break;

  case 118: /* basicStatement: declarationStatement  */
#line 245 "SemanticAnalyzer.y"
                                       {printf("BS->DS..\n");}
#line 2141 "y.tab.c"
    break;

  case 119: /* basicStatement: assignmentStatement  */
#line 246 "SemanticAnalyzer.y"
                                        {printf("Basic->AS..\n");}
#line 2147 "y.tab.c"
    break;

  case 120: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 248 "SemanticAnalyzer.y"
                                                                                      {printf("AS1..\n");}
#line 2153 "y.tab.c"
    break;

  case 121: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 249 "SemanticAnalyzer.y"
                                                                 {printf("AS2..\n");}
#line 2159 "y.tab.c"
    break;

  case 124: /* declarationStatement: INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 253 "SemanticAnalyzer.y"
                                                                                    {printf("INT F WITH PARAMS..\n");}
#line 2165 "y.tab.c"
    break;

  case 125: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 254 "SemanticAnalyzer.y"
                                                                                {printf("char F WITH PARAMS..\n");}
#line 2171 "y.tab.c"
    break;

  case 126: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 255 "SemanticAnalyzer.y"
                                                                                {printf("float F WITH PARAMS..\n");}
#line 2177 "y.tab.c"
    break;

  case 127: /* $@32: %empty  */
#line 256 "SemanticAnalyzer.y"
                                         {pushNewScope();}
#line 2183 "y.tab.c"
    break;

  case 129: /* $@33: %empty  */
#line 257 "SemanticAnalyzer.y"
                                           {pushNewScope();}
#line 2189 "y.tab.c"
    break;

  case 131: /* $@34: %empty  */
#line 258 "SemanticAnalyzer.y"
                                          {pushNewScope();}
#line 2195 "y.tab.c"
    break;

  case 133: /* declarationStatement: INT declarationListIntFloat SEMICOLON  */
#line 259 "SemanticAnalyzer.y"
                                                        {printf("DS1..\n");}
#line 2201 "y.tab.c"
    break;

  case 146: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListIntFloat  */
#line 271 "SemanticAnalyzer.y"
                                                                                              {printf("DSL1..\n");}
#line 2207 "y.tab.c"
    break;

  case 148: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement  */
#line 273 "SemanticAnalyzer.y"
                                                       {printf("DSL3..\n");}
#line 2213 "y.tab.c"
    break;

  case 149: /* declarationListIntFloat: IDENTIFIER dimension  */
#line 274 "SemanticAnalyzer.y"
                                        {printf("INTFLOAT ARRAY..\n");}
#line 2219 "y.tab.c"
    break;

  case 150: /* declarationListIntFloat: IDENTIFIER  */
#line 275 "SemanticAnalyzer.y"
                             {printf("DSL4..\n");}
#line 2225 "y.tab.c"
    break;

  case 156: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 283 "SemanticAnalyzer.y"
                                                                       {printf("ES1..\n");}
#line 2231 "y.tab.c"
    break;

  case 157: /* expressionStatement: logicalExpression  */
#line 284 "SemanticAnalyzer.y"
                                    {printf("ES2..\n");}
#line 2237 "y.tab.c"
    break;

  case 158: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 286 "SemanticAnalyzer.y"
                                                             {printf("LE1..\n");}
#line 2243 "y.tab.c"
    break;

  case 159: /* logicalExpression: expression  */
#line 287 "SemanticAnalyzer.y"
                             {printf("LE2..\n");}
#line 2249 "y.tab.c"
    break;

  case 160: /* expression: relationalExpression EQUALS expression  */
#line 289 "SemanticAnalyzer.y"
                                                     {printf("E1..\n");}
#line 2255 "y.tab.c"
    break;

  case 161: /* expression: relationalExpression NOTEQUAL expression  */
#line 290 "SemanticAnalyzer.y"
                                                           {printf("E2..\n");}
#line 2261 "y.tab.c"
    break;

  case 162: /* expression: relationalExpression  */
#line 291 "SemanticAnalyzer.y"
                                       {printf("E3..\n");}
#line 2267 "y.tab.c"
    break;

  case 167: /* relationalExpression: value  */
#line 297 "SemanticAnalyzer.y"
                        {printf("VALUE..\n");}
#line 2273 "y.tab.c"
    break;

  case 168: /* value: term ADD value  */
#line 299 "SemanticAnalyzer.y"
                        {printf("ADD..\n");}
#line 2279 "y.tab.c"
    break;

  case 170: /* value: term  */
#line 301 "SemanticAnalyzer.y"
               {printf("Basic TERM..\n");}
#line 2285 "y.tab.c"
    break;

  case 171: /* term: factor MULT term  */
#line 303 "SemanticAnalyzer.y"
                         {printf("MULT..\n");}
#line 2291 "y.tab.c"
    break;

  case 174: /* term: factor  */
#line 306 "SemanticAnalyzer.y"
                 {printf("Factor..\n");}
#line 2297 "y.tab.c"
    break;

  case 179: /* factor: INTVAL  */
#line 312 "SemanticAnalyzer.y"
                 {printf("INT VALS.. %d\n",yylval);}
#line 2303 "y.tab.c"
    break;

  case 187: /* $@35: %empty  */
#line 324 "SemanticAnalyzer.y"
              {pushNewScope();}
#line 2309 "y.tab.c"
    break;

  case 190: /* paramContinuer: parameter COMMA paramContinuer  */
#line 325 "SemanticAnalyzer.y"
                                                             {printf("FUNCTION params\n");}
#line 2315 "y.tab.c"
    break;

  case 191: /* parameter: type IDENTIFIER  */
#line 327 "SemanticAnalyzer.y"
                             {printf("FUNCTION param\n");}
#line 2321 "y.tab.c"
    break;

  case 192: /* type: INT  */
#line 329 "SemanticAnalyzer.y"
            {(yyval.Str) = strdup("i");}
#line 2327 "y.tab.c"
    break;

  case 193: /* type: FLOAT  */
#line 330 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup("f");}
#line 2333 "y.tab.c"
    break;

  case 194: /* type: CHAR  */
#line 331 "SemanticAnalyzer.y"
                        {(yyval.Str) = strdup("c");}
#line 2339 "y.tab.c"
    break;

  case 195: /* compoundStatements: OPCUR statementList CLCUR  */
#line 333 "SemanticAnalyzer.y"
                                                {popScope();printf("FUNCTION statements\n");}
#line 2345 "y.tab.c"
    break;

  case 205: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 339 "SemanticAnalyzer.y"
                                     {printf("size..\n");}
#line 2351 "y.tab.c"
    break;


#line 2355 "y.tab.c"

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

#line 342 "SemanticAnalyzer.y"

  
 #include "lex.yy.c"
 int main(){
 	yyin = fopen("./Test Cases/input.txt","r");
	availableScopes[0] = 0;
 	if(!yyparse())
 	{
 		printf("Parsing Done\n");
 	}
 	else 
 		printf("Failed\n");
	
	printTable();
 	exit(0);
 }
  
  
