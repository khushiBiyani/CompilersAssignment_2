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
    

#line 185 "y.tab.c"

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
    IDENTIFIER = 299,              /* IDENTIFIER  */
    CHARVAL = 300,                 /* CHARVAL  */
    INTVAL = 301,                  /* INTVAL  */
    FLOATVAL = 302                 /* FLOATVAL  */
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
#define IDENTIFIER 299
#define CHARVAL 300
#define INTVAL 301
#define FLOATVAL 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
  YYSYMBOL_IDENTIFIER = 44,                /* IDENTIFIER  */
  YYSYMBOL_CHARVAL = 45,                   /* CHARVAL  */
  YYSYMBOL_INTVAL = 46,                    /* INTVAL  */
  YYSYMBOL_FLOATVAL = 47,                  /* FLOATVAL  */
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
#define YYLAST   505

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
       0,   137,   137,   139,   140,   141,   142,   144,   145,   146,
     147,   148,   149,   150,   152,   152,   153,   154,   155,   156,
     156,   156,   158,   159,   159,   160,   160,   162,   163,   164,
     165,   166,   167,   168,   170,   171,   172,   173,   174,   175,
     176,   176,   177,   178,   181,   181,   182,   182,   183,   184,
     184,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     196,   196,   196,   197,   197,   197,   199,   199,   201,   201,
     201,   202,   202,   202,   203,   203,   203,   204,   204,   205,
     207,   207,   207,   209,   209,   211,   211,   211,   212,   212,
     212,   213,   213,   213,   214,   214,   215,   217,   217,   217,
     218,   218,   219,   219,   219,   219,   220,   221,   222,   223,
     225,   225,   226,   226,   226,   229,   230,   232,   233,   234,
     236,   237,   239,   240,   241,   242,   243,   244,   244,   245,
     245,   246,   246,   247,   248,   249,   250,   251,   252,   253,
     255,   255,   256,   256,   257,   257,   259,   260,   261,   262,
     263,   265,   266,   267,   268,   269,   271,   272,   274,   275,
     277,   278,   279,   281,   282,   283,   284,   285,   287,   288,
     289,   291,   292,   293,   294,   296,   297,   298,   299,   300,
     301,   302,   303,   306,   307,   310,   310,   312,   312,   313,
     313,   315,   317,   317,   317,   319,   321,   321,   321,   321,
     321,   321,   321,   323,   323,   325,   326,   327
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
  "IDENTIFIER", "CHARVAL", "INTVAL", "FLOATVAL", "$accept", "code",
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

#define YYPACT_NINF (-384)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-132)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,   -31,     7,    22,    27,    79,  -384,    25,    25,    -4,
      87,    13,    89,    51,    93,   222,  -384,  -384,  -384,   101,
     113,   -25,   222,  -384,  -384,   125,   137,    -6,    74,  -384,
    -384,   140,    75,  -384,   222,   222,   154,  -384,  -384,  -384,
     147,   193,   194,   182,   205,   237,   143,    -2,  -384,   165,
     180,   188,   130,   186,   203,    52,  -384,   206,   208,   135,
     189,   207,   218,   220,   219,   228,  -384,   224,   230,  -384,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   252,   252,  -384,  -384,  -384,  -384,   279,
     255,   262,   263,   276,   101,   252,   252,   295,   163,   125,
     252,   252,  -384,   282,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,   308,  -384,
    -384,   188,  -384,   299,   -29,   285,  -384,  -384,  -384,   334,
     340,  -384,  -384,  -384,   321,   332,  -384,   335,   337,    81,
     339,   341,   103,   308,  -384,  -384,  -384,   308,   260,  -384,
     308,   308,  -384,  -384,   308,   342,  -384,  -384,  -384,   359,
     363,   347,   349,  -384,   378,   351,   222,   364,  -384,   357,
    -384,   385,   381,   382,   195,  -384,  -384,   178,  -384,  -384,
    -384,  -384,  -384,  -384,   360,   390,  -384,  -384,   369,   371,
      41,  -384,  -384,  -384,  -384,   222,   384,  -384,   399,   403,
     409,  -384,    66,  -384,  -384,  -384,   389,  -384,   386,   387,
     222,  -384,   391,   395,   392,   397,   411,   400,  -384,   222,
     422,  -384,   396,   401,   402,   429,  -384,    69,  -384,   399,
     430,   404,   432,  -384,  -384,   396,  -384,  -384,  -384,  -384,
     222,   222,   406,  -384,  -384,  -384,   338,   421,  -384,  -384,
     403,  -384,  -384,   396,   396,   396,   253,   245,   268,   410,
     415,   367,   418,   438,   439,  -384,  -384,  -384,  -384,  -384,
    -384,   431,  -384,   427,  -384,   419,  -384,  -384,  -384,    77,
    -384,  -384,  -384,    41,  -384,    41,  -384,   222,    82,   443,
     444,   367,   367,   423,   367,   367,   367,   367,   222,  -384,
    -384,   445,  -384,    14,  -384,   253,   433,  -384,   396,  -384,
    -384,   447,  -384,  -384,   338,   367,   367,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,   428,  -384,   434,   243,   448,   449,
     421,  -384,   222,   396,  -384,   406,   367,  -384,  -384,  -384,
     436,   396,  -384,   435,   440,   396,   396,  -384,   441,  -384,
    -384,   437,   280,  -384,   451,   452,   450,  -384,  -384,   442,
     446,  -384,   367,   396,   396,   458,  -384,   396,  -384,  -384,
    -384,  -384,  -384,   396,  -384,   453,  -384,   454,   290,   455,
    -384,   457,   116,  -384,  -384,  -384,   454,   222,   459,  -384,
     338,  -384,   460,   222,   367,  -384,   461,   463,  -384,  -384,
     464,   462,  -384,   338,  -384,   367,  -384,  -384,   465,   466,
    -384,   465,  -384
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     5,   150,
       0,   155,     0,   150,     0,     0,     1,     4,     3,     0,
     187,     0,     0,   149,   133,     0,   187,     0,     0,   154,
     136,   187,     0,   137,     0,     0,   175,   178,   179,   180,
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
    -384,  -384,   331,  -211,  -302,   -70,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -242,  -195,  -384,   131,  -384,  -384,  -384,
    -384,  -384,    30,  -251,  -384,  -384,  -384,  -384,   177,  -368,
    -384,  -384,  -384,  -384,  -384,  -384,  -384,  -243,  -384,  -384,
    -384,  -383,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -183,
    -384,  -384,  -384,   153,  -384,  -384,  -384,  -289,  -384,  -384,
     336,  -117,    15,  -384,  -384,   134,  -384,  -384,  -384,   302,
     258,   238,     8,   -23,   -15,   420,   275,   159,   278,   171,
    -384,   -54,  -384,   118,  -384,   368,  -384,  -384,    71,    39,
    -384,    -3
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
      40,   148,    56,   267,   266,   280,   334,    54,    29,   380,
     159,    14,    19,     9,    19,     7,    52,   160,   391,    65,
      66,    53,     7,     7,   252,   410,   148,    48,   412,    25,
     148,   148,    20,   148,   148,    59,    21,   148,    32,    22,
      60,    22,   276,   277,   278,     1,     2,     3,   143,    26,
     327,    11,    29,    27,   280,   105,    28,   358,   207,   328,
     329,   208,   209,   268,   154,   374,    13,    19,    25,     4,
      15,   267,   337,   143,   370,   371,   131,   143,   295,    16,
     143,   143,   219,   104,   143,     4,   243,    31,   309,   154,
     310,    32,    32,   154,    22,    28,   154,   154,   170,   312,
     154,   306,   126,   220,    24,   238,    30,   244,   295,   295,
      33,   295,   295,   295,   295,   307,    64,    34,   254,    61,
     313,    53,   349,    35,   171,    36,    37,    38,    39,   269,
     353,   268,   295,   295,     8,   383,   254,   254,   254,   174,
     388,     8,     8,    67,    58,    47,    15,   267,   395,    63,
    -127,   189,   237,   295,   389,   120,    80,    81,    82,   201,
     267,   406,   376,    68,    69,   253,   127,   128,   239,    55,
      91,   132,   133,    92,  -131,    91,   265,  -129,    97,   295,
     212,   255,   175,   253,   253,   253,   176,    72,    73,   179,
     180,   238,   270,   181,    67,   226,    70,   269,    71,   255,
     255,   255,    83,   125,   233,   211,   130,   268,    85,    86,
      87,   295,    74,    75,    76,    77,   254,    84,    67,    94,
     268,    15,   295,    99,   254,   257,   258,    93,   254,   254,
      98,    34,   200,   109,   110,   111,   112,    35,   237,    36,
      37,    38,    39,    95,   265,    96,   254,   254,    78,    79,
     238,   115,   116,   117,   239,   100,   254,   101,    34,    91,
     270,   283,   284,   253,    35,   102,    36,    37,    38,    39,
     103,   253,   311,   269,     4,   253,   253,   135,   279,   255,
       1,     2,     3,   324,   285,   286,   269,   255,   343,   344,
     118,   255,   255,   253,   253,   121,    34,   237,   211,   122,
     211,   124,    35,   253,   177,    37,    38,    39,   123,   255,
     255,   -80,   -80,   239,   381,   382,   125,   348,   129,   255,
     265,   317,   318,   134,   320,   321,   322,   323,     1,     2,
       3,   162,   135,   265,   136,   137,   270,   138,    17,    18,
     158,   139,   140,   141,    34,   338,   339,   107,   108,   270,
      35,   163,   142,    37,    38,    39,   113,   114,     1,     2,
       3,   165,   262,   164,   136,   137,   351,   138,   166,   263,
     264,   168,   392,   169,    34,   172,   183,   173,   397,   184,
      35,   182,   142,    37,    38,    39,   185,     1,     2,     3,
     186,   262,   369,   136,   137,   187,   138,   188,   289,   290,
     190,   196,   197,    34,   198,   199,   160,   204,   206,    35,
     205,   142,    37,    38,    39,   214,     1,     2,     3,   216,
     135,   213,   136,   137,   398,   138,   218,   221,   227,   231,
     223,   224,    34,   228,   230,   407,   229,   232,    35,   234,
     142,    37,    38,    39,   240,   241,   242,   249,   250,   251,
     259,  -102,   288,   287,   298,   299,   300,   303,   305,   301,
     315,   316,   319,   335,   325,   340,   350,   345,   346,   332,
     363,   364,   354,   342,   352,   372,   361,   355,   359,   279,
     366,   365,   331,   347,   178,   368,   203,   248,   274,   157,
     382,   106,   378,   387,   386,   393,     0,   396,     0,   399,
     400,   404,   402,     0,     0,   411
};

static const yytype_int16 yycheck[] =
{
      15,   118,    25,   246,   246,   256,   308,    22,    11,   377,
      39,     3,    16,    44,    16,     0,    41,    46,   386,    34,
      35,    46,     7,     8,   235,   408,   143,    19,   411,    16,
     147,   148,    36,   150,   151,    41,    40,   154,    40,    43,
      46,    43,   253,   254,   255,    20,    21,    22,   118,    36,
      36,    44,    55,    40,   305,    70,    43,   346,    17,    45,
      46,    20,    21,   246,   118,   367,    44,    16,    16,    44,
      43,   314,   314,   143,   363,   364,    99,   147,   261,     0,
     150,   151,    16,    68,   154,    44,    17,    36,   283,   143,
     285,    40,    40,   147,    43,    43,   150,   151,    17,    17,
     154,    24,    94,    37,    17,   222,    17,    38,   291,   292,
      17,   294,   295,   296,   297,    38,    41,    36,   235,    45,
      38,    46,   333,    42,   139,    44,    45,    46,    47,   246,
     341,   314,   315,   316,     0,   378,   253,   254,   255,    36,
      24,     7,     8,    40,    26,    44,    43,   390,   390,    31,
      37,   166,   222,   336,    38,    84,    13,    14,    15,   174,
     403,   403,   373,    16,    17,   235,    95,    96,   222,    44,
      40,   100,   101,    43,    37,    40,   246,    37,    43,   362,
     195,   235,   143,   253,   254,   255,   147,     5,     6,   150,
     151,   308,   246,   154,    40,   210,     3,   314,     4,   253,
     254,   255,    37,    40,   219,   190,    43,   390,    20,    21,
      22,   394,     7,     8,     9,    10,   333,    37,    40,    16,
     403,    43,   405,    16,   341,   240,   241,    41,   345,   346,
      41,    36,    37,    74,    75,    76,    77,    42,   308,    44,
      45,    46,    47,    37,   314,    37,   363,   364,    11,    12,
     367,    80,    81,    82,   308,    37,   373,    37,    36,    40,
     314,    16,    17,   333,    42,    37,    44,    45,    46,    47,
      46,   341,   287,   390,    44,   345,   346,    24,    25,   333,
      20,    21,    22,   298,    16,    17,   403,   341,    45,    46,
      38,   345,   346,   363,   364,    16,    36,   367,   283,    44,
     285,    38,    42,   373,    44,    45,    46,    47,    46,   363,
     364,    31,    32,   367,    24,    25,    40,   332,    23,   373,
     390,   291,   292,    41,   294,   295,   296,   297,    20,    21,
      22,    46,    24,   403,    26,    27,   390,    29,     7,     8,
      41,    33,    34,    35,    36,   315,   316,    72,    73,   403,
      42,    17,    44,    45,    46,    47,    78,    79,    20,    21,
      22,    40,    24,    23,    26,    27,   336,    29,    36,    31,
      32,    36,   387,    36,    36,    36,    17,    36,   393,    16,
      42,    39,    44,    45,    46,    47,    39,    20,    21,    22,
      41,    24,   362,    26,    27,    17,    29,    46,    31,    32,
      36,    44,    17,    36,    23,    23,    46,    17,    37,    42,
      41,    44,    45,    46,    47,    16,    20,    21,    22,    16,
      24,    37,    26,    27,   394,    29,    17,    38,    37,    18,
      44,    44,    36,    38,    37,   405,    44,    37,    42,    17,
      44,    45,    46,    47,    43,    43,    17,    17,    44,    17,
      44,    30,    37,    43,    36,    17,    17,    30,    39,    28,
      17,    17,    39,    16,    19,    37,   335,    19,    19,    36,
      19,    19,    37,    39,    38,    17,    39,    37,    37,    25,
      38,    31,   305,   330,   148,    39,   184,   229,   250,   121,
      25,    71,    39,    36,    39,    36,    -1,    37,    -1,    38,
      37,    39,    38,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    44,    49,    50,   110,   113,    44,
     120,    44,   121,    44,   120,    43,     0,    50,    50,    16,
      36,    40,    43,   139,    17,    16,    36,    40,    43,   139,
      17,    36,    40,    17,    36,    42,    44,    45,    46,    47,
     122,   123,   124,   125,   126,   127,   128,    44,   120,   114,
     131,   132,    41,    46,   122,    44,   121,   116,   131,    41,
      46,    45,   115,   131,    41,   122,   122,    40,    16,    17,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    37,    37,    20,    21,    22,   133,   134,
     135,    40,    43,    41,    16,    37,    37,    43,    41,    16,
      37,    37,    37,    46,   110,   122,   123,   124,   124,   125,
     125,   125,   125,   126,   126,   127,   127,   127,    38,   136,
     136,    16,    44,    46,    38,    40,   120,   136,   136,    23,
      43,   121,   136,   136,    41,    24,    26,    27,    29,    33,
      34,    35,    44,    53,    65,    71,    97,   108,   109,   110,
     111,   112,   113,   122,   129,   137,   138,   133,    41,    39,
      46,   117,    46,    17,    23,    40,    36,    54,    36,    36,
      17,   122,    36,    36,    36,   137,   137,    44,   108,   137,
     137,   137,    39,    17,    16,    39,    41,    17,    46,   122,
      36,    55,    56,    57,    59,    66,    44,    17,    23,    23,
      37,   122,   130,   117,    17,    41,    37,    17,    20,    21,
      62,   110,   122,    37,    16,   118,    16,   119,    17,    16,
      37,    38,    74,    44,    44,    63,   122,    37,    38,    44,
      37,    18,    37,   122,    17,    72,    52,    53,   109,   129,
      43,    43,    17,    17,    38,    67,    69,    98,   118,    17,
      44,    17,    51,    53,   109,   129,    75,   122,   122,    44,
      64,    68,    24,    31,    32,    53,    61,    85,    97,   109,
     129,   100,   101,   102,   119,    73,    51,    51,    51,    25,
      71,    76,    77,    16,    17,    16,    17,    43,    37,    31,
      32,    53,    61,    70,    85,    97,   109,   129,    36,    17,
      17,    28,   106,    30,   104,    39,    24,    38,    84,    62,
      62,   122,    17,    38,    60,    17,    17,    70,    70,    39,
      70,    70,    70,    70,   122,    19,    99,    36,    45,    46,
     103,    76,    36,    80,    52,    16,    58,    61,    70,    70,
      37,   107,    39,    45,    46,    19,    19,   101,   122,    51,
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
#line 137 "SemanticAnalyzer.y"
                           {printf("Starting..\n");}
#line 1761 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 139 "SemanticAnalyzer.y"
                                                            {printf("RECURSIVE DECLARATION \n");}
#line 1767 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 141 "SemanticAnalyzer.y"
                                                        {printf("DECLARATION \n");}
#line 1773 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 144 "SemanticAnalyzer.y"
                                             {printf("Special..\n");}
#line 1779 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 145 "SemanticAnalyzer.y"
                                               {printf("Basic123..\n");}
#line 1785 "y.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 152 "SemanticAnalyzer.y"
                           {pushNewScope();}
#line 1791 "y.tab.c"
    break;

  case 22: /* forLoop1: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON  */
#line 158 "SemanticAnalyzer.y"
                                                                                                         {popScope(); printf("\nFOR SEMICOLON \n");}
#line 1797 "y.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 159 "SemanticAnalyzer.y"
                                                                                                       {pushNewScope();}
#line 1803 "y.tab.c"
    break;

  case 24: /* forLoop2: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR $@2 inLoop CLCUR  */
#line 159 "SemanticAnalyzer.y"
                                                                                                                                      {popScope(); popScope(); printf("\nproper FOR \n");}
#line 1809 "y.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 160 "SemanticAnalyzer.y"
                                                                                             {pushNewScope();}
#line 1815 "y.tab.c"
    break;

  case 26: /* forLoop3: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC $@3 singleLoopStatement  */
#line 160 "SemanticAnalyzer.y"
                                                                                                                                   {popScope(); popScope(); printf("\nFOR SINGLE STATEMENT \n");}
#line 1821 "y.tab.c"
    break;

  case 44: /* $@4: %empty  */
#line 181 "SemanticAnalyzer.y"
                                 {pushNewScope();}
#line 1827 "y.tab.c"
    break;

  case 46: /* $@5: %empty  */
#line 182 "SemanticAnalyzer.y"
                        {pushNewScope();}
#line 1833 "y.tab.c"
    break;

  case 47: /* whileSuffix: OPCUR $@5 inLoop CLCUR  */
#line 182 "SemanticAnalyzer.y"
                                                      { popScope(); popScope(); printf("\nproper WHILE \n");}
#line 1839 "y.tab.c"
    break;

  case 48: /* whileSuffix: SEMICOLON  */
#line 183 "SemanticAnalyzer.y"
                              {popScope(); printf("\nWHILE SEMICOLON \n");}
#line 1845 "y.tab.c"
    break;

  case 49: /* $@6: %empty  */
#line 184 "SemanticAnalyzer.y"
                    {pushNewScope();}
#line 1851 "y.tab.c"
    break;

  case 50: /* whileSuffix: $@6 singleLoopStatement  */
#line 184 "SemanticAnalyzer.y"
                                                          { popScope(); popScope(); printf("\nSINGLE WHILE \n");}
#line 1857 "y.tab.c"
    break;

  case 51: /* inLoop: BREAK SEMICOLON inLoop  */
#line 186 "SemanticAnalyzer.y"
                                    {printf("\n break in loop \n");}
#line 1863 "y.tab.c"
    break;

  case 52: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 187 "SemanticAnalyzer.y"
                                            {printf("\ncontinue in loop \n");}
#line 1869 "y.tab.c"
    break;

  case 53: /* inLoop: specialStatement inLoop  */
#line 188 "SemanticAnalyzer.y"
                                          {printf("\n special statement in loop \n");}
#line 1875 "y.tab.c"
    break;

  case 54: /* inLoop: basicStatement inLoop  */
#line 189 "SemanticAnalyzer.y"
                                        {printf("\n basic statement in loop \n");}
#line 1881 "y.tab.c"
    break;

  case 55: /* inLoop: functionCall inLoop  */
#line 190 "SemanticAnalyzer.y"
                                     {printf("\n basic statement in loop \n");}
#line 1887 "y.tab.c"
    break;

  case 56: /* inLoop: ifInLoopStatement inLoop  */
#line 191 "SemanticAnalyzer.y"
                                           {printf("\n if in loop \n");}
#line 1893 "y.tab.c"
    break;

  case 57: /* inLoop: switchStatement inLoop  */
#line 192 "SemanticAnalyzer.y"
                                         {printf("\n switch in loop \n");}
#line 1899 "y.tab.c"
    break;

  case 58: /* inLoop: singleLoopStatement inLoop  */
#line 193 "SemanticAnalyzer.y"
                                             {printf("\n any other statement in loop \n");}
#line 1905 "y.tab.c"
    break;

  case 60: /* $@7: %empty  */
#line 196 "SemanticAnalyzer.y"
                                                             {pushNewScope();}
#line 1911 "y.tab.c"
    break;

  case 61: /* $@8: %empty  */
#line 196 "SemanticAnalyzer.y"
                                                                                          {popScope();}
#line 1917 "y.tab.c"
    break;

  case 63: /* $@9: %empty  */
#line 197 "SemanticAnalyzer.y"
                                                                       {pushNewScope();}
#line 1923 "y.tab.c"
    break;

  case 64: /* $@10: %empty  */
#line 197 "SemanticAnalyzer.y"
                                                                                                         {popScope();}
#line 1929 "y.tab.c"
    break;

  case 68: /* $@11: %empty  */
#line 201 "SemanticAnalyzer.y"
                                                         {pushNewScope();}
#line 1935 "y.tab.c"
    break;

  case 69: /* $@12: %empty  */
#line 201 "SemanticAnalyzer.y"
                                                                                      {popScope();}
#line 1941 "y.tab.c"
    break;

  case 71: /* $@13: %empty  */
#line 202 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 1947 "y.tab.c"
    break;

  case 72: /* $@14: %empty  */
#line 202 "SemanticAnalyzer.y"
                                                  {popScope();}
#line 1953 "y.tab.c"
    break;

  case 74: /* $@15: %empty  */
#line 203 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 1959 "y.tab.c"
    break;

  case 75: /* $@16: %empty  */
#line 203 "SemanticAnalyzer.y"
                                                                                     {popScope();}
#line 1965 "y.tab.c"
    break;

  case 77: /* $@17: %empty  */
#line 204 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 1971 "y.tab.c"
    break;

  case 78: /* ES: ELSE $@17 singleStatement  */
#line 204 "SemanticAnalyzer.y"
                                                 {popScope();}
#line 1977 "y.tab.c"
    break;

  case 80: /* $@18: %empty  */
#line 207 "SemanticAnalyzer.y"
                                                                   {pushNewScope();}
#line 1983 "y.tab.c"
    break;

  case 81: /* $@19: %empty  */
#line 207 "SemanticAnalyzer.y"
                                                                                            {popScope;}
#line 1989 "y.tab.c"
    break;

  case 85: /* $@20: %empty  */
#line 211 "SemanticAnalyzer.y"
                                                             {pushNewScope();}
#line 1995 "y.tab.c"
    break;

  case 86: /* $@21: %empty  */
#line 211 "SemanticAnalyzer.y"
                                                                                      {popScope();}
#line 2001 "y.tab.c"
    break;

  case 88: /* $@22: %empty  */
#line 212 "SemanticAnalyzer.y"
                     {pushNewScope();}
#line 2007 "y.tab.c"
    break;

  case 89: /* $@23: %empty  */
#line 212 "SemanticAnalyzer.y"
                                              {popScope();}
#line 2013 "y.tab.c"
    break;

  case 91: /* $@24: %empty  */
#line 213 "SemanticAnalyzer.y"
                                                   {pushNewScope();}
#line 2019 "y.tab.c"
    break;

  case 92: /* $@25: %empty  */
#line 213 "SemanticAnalyzer.y"
                                                                                         {popScope();}
#line 2025 "y.tab.c"
    break;

  case 94: /* $@26: %empty  */
#line 214 "SemanticAnalyzer.y"
               {pushNewScope();}
#line 2031 "y.tab.c"
    break;

  case 95: /* ESLoop: ELSE $@26 singleLoopStatement  */
#line 214 "SemanticAnalyzer.y"
                                                     {popScope();}
#line 2037 "y.tab.c"
    break;

  case 97: /* $@27: %empty  */
#line 217 "SemanticAnalyzer.y"
                                                            {pushNewScope();}
#line 2043 "y.tab.c"
    break;

  case 98: /* $@28: %empty  */
#line 217 "SemanticAnalyzer.y"
                                                                                                              {popScope();}
#line 2049 "y.tab.c"
    break;

  case 99: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR $@27 caseStatements defaultStatement $@28 CLCUR  */
#line 217 "SemanticAnalyzer.y"
                                                                                                                                  {printf("SWITCH START..\n");}
#line 2055 "y.tab.c"
    break;

  case 101: /* caseStatements: %empty  */
#line 218 "SemanticAnalyzer.y"
                                        {printf("char/int..\n");}
#line 2061 "y.tab.c"
    break;

  case 102: /* $@29: %empty  */
#line 219 "SemanticAnalyzer.y"
                       {pushNewScope();}
#line 2067 "y.tab.c"
    break;

  case 103: /* $@30: %empty  */
#line 219 "SemanticAnalyzer.y"
                                                 {pushNewScope();}
#line 2073 "y.tab.c"
    break;

  case 105: /* caseStatementInt: %empty  */
#line 219 "SemanticAnalyzer.y"
                                                                                      {printf("INT CASE..\n");}
#line 2079 "y.tab.c"
    break;

  case 107: /* caseInt: CASE INTVAL COLON caseContinuer  */
#line 221 "SemanticAnalyzer.y"
                                                  {printf("CASE INT : ..\n");}
#line 2085 "y.tab.c"
    break;

  case 112: /* $@31: %empty  */
#line 226 "SemanticAnalyzer.y"
                                     {pushNewScope();}
#line 2091 "y.tab.c"
    break;

  case 113: /* defaultStatement: DEFAULT COLON $@31 statements  */
#line 226 "SemanticAnalyzer.y"
                                                                  {popScope();}
#line 2097 "y.tab.c"
    break;

  case 114: /* defaultStatement: %empty  */
#line 226 "SemanticAnalyzer.y"
                                                                                  {printf(" \nDEFAULT : ..\n");}
#line 2103 "y.tab.c"
    break;

  case 117: /* basicStatement: expressionStatement  */
#line 232 "SemanticAnalyzer.y"
                                         {printf("BS->EXPS..\n");}
#line 2109 "y.tab.c"
    break;

  case 118: /* basicStatement: declarationStatement  */
#line 233 "SemanticAnalyzer.y"
                                       {printf("BS->DS..\n");}
#line 2115 "y.tab.c"
    break;

  case 119: /* basicStatement: assignmentStatement  */
#line 234 "SemanticAnalyzer.y"
                                        {printf("Basic->AS..\n");}
#line 2121 "y.tab.c"
    break;

  case 120: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 236 "SemanticAnalyzer.y"
                                                                                         {printf("AS1..\n");}
#line 2127 "y.tab.c"
    break;

  case 121: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 237 "SemanticAnalyzer.y"
                                                                 {printf("AS2..\n");}
#line 2133 "y.tab.c"
    break;

  case 124: /* declarationStatement: INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 241 "SemanticAnalyzer.y"
                                                                                       {printf("INT F WITH PARAMS..\n");}
#line 2139 "y.tab.c"
    break;

  case 125: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 242 "SemanticAnalyzer.y"
                                                                                {printf("char F WITH PARAMS..\n");}
#line 2145 "y.tab.c"
    break;

  case 126: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 243 "SemanticAnalyzer.y"
                                                                                {printf("float F WITH PARAMS..\n");}
#line 2151 "y.tab.c"
    break;

  case 127: /* $@32: %empty  */
#line 244 "SemanticAnalyzer.y"
                                         {pushNewScope();}
#line 2157 "y.tab.c"
    break;

  case 129: /* $@33: %empty  */
#line 245 "SemanticAnalyzer.y"
                                           {pushNewScope();}
#line 2163 "y.tab.c"
    break;

  case 131: /* $@34: %empty  */
#line 246 "SemanticAnalyzer.y"
                                          {pushNewScope();}
#line 2169 "y.tab.c"
    break;

  case 133: /* declarationStatement: INT declarationListIntFloat SEMICOLON  */
#line 247 "SemanticAnalyzer.y"
                                                        {printf("DS1..\n");}
#line 2175 "y.tab.c"
    break;

  case 146: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListIntFloat  */
#line 259 "SemanticAnalyzer.y"
                                                                                                 {printf("DSL1..\n");}
#line 2181 "y.tab.c"
    break;

  case 148: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement  */
#line 261 "SemanticAnalyzer.y"
                                                       {printf("DSL3..\n");}
#line 2187 "y.tab.c"
    break;

  case 149: /* declarationListIntFloat: IDENTIFIER dimension  */
#line 262 "SemanticAnalyzer.y"
                                        {printf("INTFLOAT ARRAY..\n");}
#line 2193 "y.tab.c"
    break;

  case 150: /* declarationListIntFloat: IDENTIFIER  */
#line 263 "SemanticAnalyzer.y"
                             {printf("DSL4..\n");}
#line 2199 "y.tab.c"
    break;

  case 156: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 271 "SemanticAnalyzer.y"
                                                                          {printf("ES1..\n");}
#line 2205 "y.tab.c"
    break;

  case 157: /* expressionStatement: logicalExpression  */
#line 272 "SemanticAnalyzer.y"
                                    {printf("ES2..\n");}
#line 2211 "y.tab.c"
    break;

  case 158: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 274 "SemanticAnalyzer.y"
                                                                {printf("LE1..\n");}
#line 2217 "y.tab.c"
    break;

  case 159: /* logicalExpression: expression  */
#line 275 "SemanticAnalyzer.y"
                             {printf("LE2..\n");}
#line 2223 "y.tab.c"
    break;

  case 160: /* expression: relationalExpression EQUALS expression  */
#line 277 "SemanticAnalyzer.y"
                                                        {printf("E1..\n");}
#line 2229 "y.tab.c"
    break;

  case 161: /* expression: relationalExpression NOTEQUAL expression  */
#line 278 "SemanticAnalyzer.y"
                                                           {printf("E2..\n");}
#line 2235 "y.tab.c"
    break;

  case 162: /* expression: relationalExpression  */
#line 279 "SemanticAnalyzer.y"
                                       {printf("E3..\n");}
#line 2241 "y.tab.c"
    break;

  case 167: /* relationalExpression: value  */
#line 285 "SemanticAnalyzer.y"
                        {printf("VALUE..\n");}
#line 2247 "y.tab.c"
    break;

  case 168: /* value: term ADD value  */
#line 287 "SemanticAnalyzer.y"
                           {printf("ADD..\n");}
#line 2253 "y.tab.c"
    break;

  case 170: /* value: term  */
#line 289 "SemanticAnalyzer.y"
               {printf("Basic TERM..\n");}
#line 2259 "y.tab.c"
    break;

  case 171: /* term: factor MULT term  */
#line 291 "SemanticAnalyzer.y"
                            {printf("MULT..\n");}
#line 2265 "y.tab.c"
    break;

  case 174: /* term: factor  */
#line 294 "SemanticAnalyzer.y"
                 {printf("Factor..\n");}
#line 2271 "y.tab.c"
    break;

  case 179: /* factor: INTVAL  */
#line 300 "SemanticAnalyzer.y"
                 {printf("INT VALS.. %d\n",yylval);}
#line 2277 "y.tab.c"
    break;

  case 187: /* $@35: %empty  */
#line 312 "SemanticAnalyzer.y"
                 {pushNewScope();}
#line 2283 "y.tab.c"
    break;

  case 190: /* paramContinuer: parameter COMMA paramContinuer  */
#line 313 "SemanticAnalyzer.y"
                                                                     {printf("FUNCTION params\n");}
#line 2289 "y.tab.c"
    break;

  case 191: /* parameter: type IDENTIFIER  */
#line 315 "SemanticAnalyzer.y"
                                {printf("FUNCTION param\n");}
#line 2295 "y.tab.c"
    break;

  case 195: /* compoundStatements: OPCUR statementList CLCUR  */
#line 319 "SemanticAnalyzer.y"
                                                   {popScope();printf("FUNCTION statements\n");}
#line 2301 "y.tab.c"
    break;

  case 205: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 325 "SemanticAnalyzer.y"
                                        {printf("size..\n");}
#line 2307 "y.tab.c"
    break;


#line 2311 "y.tab.c"

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

#line 328 "SemanticAnalyzer.y"

     
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
    	exit(0);
    }
     
     
