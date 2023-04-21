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
  YYSYMBOL_specialStatement = 52,          /* specialStatement  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_forLoop = 54,                   /* forLoop  */
  YYSYMBOL_forLoop1 = 55,                  /* forLoop1  */
  YYSYMBOL_forLoop2 = 56,                  /* forLoop2  */
  YYSYMBOL_57_2 = 57,                      /* $@2  */
  YYSYMBOL_forLoop3 = 58,                  /* forLoop3  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_singleLoopStatement = 60,       /* singleLoopStatement  */
  YYSYMBOL_forAssignStatement = 61,        /* forAssignStatement  */
  YYSYMBOL_forExpStatement = 62,           /* forExpStatement  */
  YYSYMBOL_forUpdateStatement = 63,        /* forUpdateStatement  */
  YYSYMBOL_whileLoop = 64,                 /* whileLoop  */
  YYSYMBOL_whileSuffix = 65,               /* whileSuffix  */
  YYSYMBOL_inLoop = 66,                    /* inLoop  */
  YYSYMBOL_ifStatement = 67,               /* ifStatement  */
  YYSYMBOL_ES = 68,                        /* ES  */
  YYSYMBOL_ifInLoopStatement = 69,         /* ifInLoopStatement  */
  YYSYMBOL_ESLoop = 70,                    /* ESLoop  */
  YYSYMBOL_switchStatement = 71,           /* switchStatement  */
  YYSYMBOL_caseStatements = 72,            /* caseStatements  */
  YYSYMBOL_caseStatementInt = 73,          /* caseStatementInt  */
  YYSYMBOL_caseInt = 74,                   /* caseInt  */
  YYSYMBOL_defaultStatement = 75,          /* defaultStatement  */
  YYSYMBOL_basicStatements = 76,           /* basicStatements  */
  YYSYMBOL_basicStatement = 77,            /* basicStatement  */
  YYSYMBOL_assignmentStatement = 78,       /* assignmentStatement  */
  YYSYMBOL_printer = 79,                   /* printer  */
  YYSYMBOL_scanner = 80,                   /* scanner  */
  YYSYMBOL_declarationStatement = 81,      /* declarationStatement  */
  YYSYMBOL_82_4 = 82,                      /* $@4  */
  YYSYMBOL_83_5 = 83,                      /* $@5  */
  YYSYMBOL_84_6 = 84,                      /* $@6  */
  YYSYMBOL_85_7 = 85,                      /* $@7  */
  YYSYMBOL_86_8 = 86,                      /* $@8  */
  YYSYMBOL_87_9 = 87,                      /* $@9  */
  YYSYMBOL_arrayValues = 88,               /* arrayValues  */
  YYSYMBOL_prattributes = 89,              /* prattributes  */
  YYSYMBOL_scattributes = 90,              /* scattributes  */
  YYSYMBOL_declarationListIntFloat = 91,   /* declarationListIntFloat  */
  YYSYMBOL_declarationListChar = 92,       /* declarationListChar  */
  YYSYMBOL_expressionStatement = 93,       /* expressionStatement  */
  YYSYMBOL_logicalExpression = 94,         /* logicalExpression  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_relationalExpression = 96,      /* relationalExpression  */
  YYSYMBOL_value = 97,                     /* value  */
  YYSYMBOL_term = 98,                      /* term  */
  YYSYMBOL_factor = 99,                    /* factor  */
  YYSYMBOL_functionCall = 100,             /* functionCall  */
  YYSYMBOL_argList = 101,                  /* argList  */
  YYSYMBOL_parameters = 102,               /* parameters  */
  YYSYMBOL_parameter = 103,                /* parameter  */
  YYSYMBOL_type = 104,                     /* type  */
  YYSYMBOL_compoundStatements = 105,       /* compoundStatements  */
  YYSYMBOL_statementList = 106,            /* statementList  */
  YYSYMBOL_returnDec = 107,                /* returnDec  */
  YYSYMBOL_dimension = 108                 /* dimension  */
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
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  172
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  381

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
     147,   149,   149,   150,   151,   152,   153,   153,   153,   155,
     156,   156,   157,   157,   159,   160,   161,   162,   163,   164,
     165,   167,   168,   169,   170,   171,   172,   173,   173,   174,
     175,   178,   179,   180,   181,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   193,   194,   196,   197,   198,   200,
     201,   203,   204,   205,   207,   208,   208,   209,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   218,   221,
     222,   224,   225,   226,   228,   229,   231,   232,   233,   233,
     234,   234,   235,   235,   236,   236,   237,   237,   238,   238,
     239,   240,   241,   242,   243,   244,   245,   247,   247,   248,
     248,   249,   249,   251,   252,   253,   254,   255,   257,   258,
     259,   260,   261,   263,   264,   266,   267,   269,   270,   271,
     273,   274,   275,   276,   277,   279,   280,   281,   283,   284,
     285,   286,   288,   289,   290,   291,   292,   293,   294,   295,
     298,   299,   302,   302,   304,   304,   306,   308,   308,   308,
     310,   312,   312,   312,   312,   312,   312,   312,   314,   314,
     316,   317,   318
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
  "declarationList", "statements", "specialStatement", "$@1", "forLoop",
  "forLoop1", "forLoop2", "$@2", "forLoop3", "$@3", "singleLoopStatement",
  "forAssignStatement", "forExpStatement", "forUpdateStatement",
  "whileLoop", "whileSuffix", "inLoop", "ifStatement", "ES",
  "ifInLoopStatement", "ESLoop", "switchStatement", "caseStatements",
  "caseStatementInt", "caseInt", "defaultStatement", "basicStatements",
  "basicStatement", "assignmentStatement", "printer", "scanner",
  "declarationStatement", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9",
  "arrayValues", "prattributes", "scattributes", "declarationListIntFloat",
  "declarationListChar", "expressionStatement", "logicalExpression",
  "expression", "relationalExpression", "value", "term", "factor",
  "functionCall", "argList", "parameters", "parameter", "type",
  "compoundStatements", "statementList", "returnDec", "dimension", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-220)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-99)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     159,    16,    36,    46,   -21,    92,  -220,   159,   159,    -2,
      12,    15,   112,    59,   122,   125,  -220,  -220,  -220,    98,
     120,   -28,   125,  -220,  -220,   129,   148,    85,   155,  -220,
    -220,   167,   136,  -220,   125,   125,   173,  -220,  -220,  -220,
      56,   227,   217,   104,   247,   154,   286,    63,  -220,   297,
     200,    19,   208,   245,    95,  -220,   297,   231,    48,   233,
     256,   297,   239,   274,   287,  -220,   277,   282,  -220,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,  -220,  -220,  -220,   288,   311,   284,   291,   285,
     292,   295,    98,   303,   291,   309,    61,   129,   304,   291,
    -220,   301,  -220,  -220,  -220,  -220,  -220,  -220,  -220,  -220,
    -220,  -220,  -220,  -220,  -220,  -220,   291,   297,  -220,   362,
    -220,   302,   -22,   298,  -220,   291,  -220,   331,   326,  -220,
     291,  -220,   310,  -220,  -220,   316,  -220,   321,   328,    40,
     332,   333,   237,   362,  -220,  -220,  -220,   362,   142,  -220,
     362,   362,  -220,  -220,   362,   323,  -220,  -220,   350,   355,
     335,   336,  -220,  -220,   356,  -220,   329,   125,   349,   125,
     343,  -220,   373,   369,   370,   170,  -220,  -220,    77,  -220,
    -220,  -220,  -220,  -220,  -220,   348,   382,  -220,  -220,   359,
     364,     6,  -220,  -220,  -220,  -220,   365,   366,  -220,   389,
     397,   398,  -220,     0,  -220,  -220,  -220,   380,  -220,   376,
     379,   125,  -220,   334,   386,   381,   391,   409,   392,  -220,
     125,   413,   101,   388,   400,   416,  -220,  -220,   405,   429,
     431,   390,  -220,  -220,  -220,  -220,  -220,  -220,  -220,   421,
     389,   435,   411,   436,  -220,  -220,   417,   101,   101,   101,
     125,   125,   414,   125,  -220,  -220,   440,   442,   390,   390,
     422,   390,   390,   390,   390,   105,   438,  -220,   421,  -220,
    -220,   397,  -220,   166,  -220,  -220,  -220,   194,   202,   424,
     432,   433,   390,   390,  -220,  -220,  -220,  -220,  -220,  -220,
    -220,   181,   449,   452,   453,   434,  -220,  -220,    28,  -220,
    -220,     6,  -220,     6,  -220,   125,    31,   437,  -220,  -220,
     439,   441,   101,   101,   101,  -220,   443,   101,  -220,  -220,
     458,  -220,  -220,   418,   390,   461,   462,   446,   451,  -220,
     125,   444,   414,   390,  -220,   390,   445,   390,   390,   101,
     101,   468,   469,   450,  -220,  -220,   454,   218,   457,   459,
    -220,  -220,   456,  -220,   455,    29,  -220,  -220,   472,   475,
     101,   125,   460,   390,  -220,  -220,   463,   464,   125,   465,
     470,   467,   466,  -220,  -220,   390,   471,   390,   473,   474,
    -220
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     5,   117,
       0,   122,     0,   117,     0,     0,     1,     4,     3,     0,
      88,     0,     0,   116,   100,     0,    90,     0,     0,   121,
     103,    92,     0,   104,     0,     0,   142,   145,   146,   147,
       0,   124,   126,   129,   134,   137,   141,   117,   114,     0,
       0,     0,     0,   115,   122,   119,     0,     0,     0,     0,
     120,     0,     0,     0,     0,   144,     0,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   159,   158,     0,   154,     0,     0,     0,
       0,   170,     0,     0,     0,     0,   170,     0,     0,     0,
     143,     0,    84,   123,   125,   127,   128,   130,   131,   132,
     133,   135,   136,   138,   139,   140,     0,     0,   156,   167,
      95,     0,     0,     0,   113,     0,    99,     0,     0,   118,
       0,    97,   148,    89,   155,     0,    11,     0,     0,     0,
       0,     0,   142,   167,    14,    13,    15,   167,    80,    83,
     167,   167,    82,    81,   167,     0,   164,   172,     0,   108,
       0,     0,    91,   102,     0,    93,     0,     0,     0,     0,
       0,   169,     0,     0,     0,     0,   162,   161,   142,    79,
     165,   166,   163,   160,   106,     0,     0,   171,   101,     0,
       0,     0,    12,    18,    16,    17,     0,     0,   168,   110,
     112,     0,   153,     0,   107,   105,   149,     0,    36,     0,
       0,    38,    31,     0,     0,     0,     0,     0,     0,   150,
       0,     0,    10,     0,     0,     0,    37,    43,     0,     0,
       0,    53,    24,    44,    41,    30,    15,    25,    26,    66,
     110,     0,     0,     0,   152,   151,     0,    10,    10,    10,
       0,     0,     0,     0,    27,    28,     0,     0,    24,    53,
       0,    30,    15,    25,    26,     0,    78,    65,    68,   109,
      86,   112,    87,    58,     7,     8,     9,     0,     0,     0,
       0,     0,    27,    28,    47,    52,    42,    50,    51,    48,
      49,     0,     0,     0,     0,     0,    67,   111,     0,    55,
      54,     0,    32,     0,    34,     0,    22,     0,    45,    46,
       0,     0,    10,    10,    10,    64,     0,    10,    33,    35,
      40,    19,    20,     0,    10,     0,     0,    76,    72,    77,
       0,     0,     0,    53,    23,    10,     0,    10,    10,    10,
      10,     0,     0,     0,    57,    39,     0,    63,    74,    70,
      75,    71,     0,    21,     0,     0,    60,    59,     0,     0,
      10,     0,     0,    53,    73,    69,     0,     0,     0,     0,
      58,     0,     0,    62,    56,    53,     0,    53,     0,    63,
      61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -220,  -220,   281,    -1,   -73,  -220,  -220,  -220,  -220,  -220,
    -220,  -220,  -210,  -148,  -220,   165,  -220,  -220,  -219,   225,
     130,  -211,   127,   -30,  -220,   240,  -220,  -220,   363,  -115,
       1,  -220,  -220,   108,  -220,  -220,  -220,  -220,  -220,  -220,
     322,   270,   242,     2,   -14,   -15,   447,   220,   222,   232,
     241,  -220,   -54,  -220,   -46,  -220,  -220,   -69,   128,  -220,
      -5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,   246,   258,   168,   192,   193,   194,   333,
     195,   323,   259,   211,   225,   280,   144,   234,   284,   145,
     300,   261,   357,   146,   266,   267,   268,   295,   147,   263,
     149,   150,   151,   152,    49,    56,    61,    50,    62,    57,
     160,   216,   218,    10,    12,   153,    41,    42,    43,    44,
      45,    46,   264,   203,    85,    86,    87,   120,   155,   156,
      23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,     7,   235,   233,   148,    14,    29,    53,     7,     7,
      93,    55,   260,    51,    19,    98,   220,   158,    52,    64,
      65,    48,    15,   208,   159,   126,   209,   210,   148,    24,
     131,    25,   148,   148,    20,   148,   148,   221,    21,   148,
     285,    22,   287,   288,   289,   290,   143,   133,   321,    29,
       4,    26,   316,   362,   103,    27,   162,   171,    28,    89,
       9,   165,    90,   308,   309,   154,   317,   363,   102,   322,
     143,   134,    67,    68,   143,    19,    34,   143,   143,    19,
      11,   143,    35,   129,    36,    37,    38,    39,    89,   154,
      13,    95,    16,   154,   124,    31,   154,   154,   237,    32,
     154,   123,    22,    32,   128,   336,    22,   248,     8,    71,
      72,    25,   235,   334,   346,     8,     8,    66,   289,   290,
      15,     1,     2,     3,   172,   135,    58,   136,   137,    30,
     138,    59,   248,   248,   248,    32,   356,    34,    28,    33,
     232,   291,    47,    35,   369,   142,    37,    38,    39,   247,
     292,   293,   190,   318,   196,   319,   336,   -94,   378,   238,
     202,    34,     1,     2,     3,    77,    78,    35,   249,    36,
      37,    38,    39,    54,   247,   247,   247,    63,    34,     1,
       2,     3,    52,   236,    35,   -98,   178,    37,    38,    39,
     135,   298,   212,   249,   249,   249,   226,   248,   248,   248,
      60,   262,   248,     4,   -96,   244,    34,   201,   237,   337,
     301,   302,    35,    66,    36,    37,    38,    39,   303,   304,
     337,    70,   337,   337,   248,   248,   310,   311,   262,   262,
      69,   262,   262,   262,   262,   277,   278,    88,   281,   247,
     247,   247,   354,   355,   247,   248,   274,   275,   276,    91,
     232,   335,   262,   262,    73,    74,    75,    76,   249,   249,
     249,    92,   335,   249,   335,   335,   247,   247,    94,   238,
     338,   176,    97,   175,    96,   177,    99,    66,   180,   181,
      15,   338,   182,   338,   338,   249,   249,   247,    17,    18,
     320,   105,   106,   236,   262,   107,   108,   109,   110,    79,
      80,    81,   212,   262,   212,   262,   249,   262,   262,   111,
     112,   327,   328,   329,    89,   343,   331,    82,    83,    84,
     113,   114,   115,   101,   100,   116,     4,   117,   118,   119,
     122,   121,   127,   262,   274,   123,   275,   276,   348,   349,
     125,   130,   132,   157,   161,   262,   367,   262,   163,   164,
     166,   227,   167,   372,     1,     2,     3,   169,   228,   366,
     136,   137,   183,   138,   170,   229,   230,   184,   173,   174,
      34,   185,   231,   188,   186,   189,    35,   187,   142,    37,
      38,    39,     1,     2,     3,   191,   135,   197,   136,   137,
     198,   138,   199,   200,   159,   139,   140,   141,    34,   205,
     206,   207,   213,   214,    35,   215,   142,    37,    38,    39,
       1,     2,     3,   217,   228,   219,   136,   137,   222,   138,
     223,   256,   257,   224,   239,   240,    34,   242,   241,   243,
     245,   250,    35,   252,   142,    37,    38,    39,     1,     2,
       3,   253,   228,   251,   136,   137,   254,   138,   255,   229,
     230,   265,   270,   272,    34,   271,   273,   282,   279,   283,
      35,   286,   142,    37,    38,    39,   294,   305,   312,   306,
     307,   313,   314,   315,   332,   324,   325,   341,   326,   330,
     339,   340,   342,   344,   347,   350,   351,   352,   358,   364,
     359,   361,   365,   353,   360,   298,   368,   345,   299,   355,
     374,   371,   370,   376,   373,   375,   380,   204,   296,   377,
     269,   179,   379,   297,     0,     0,     0,   104
};

static const yytype_int16 yycheck[] =
{
      15,     0,   213,   213,   119,     3,    11,    22,     7,     8,
      56,    25,   231,    41,    16,    61,    16,    39,    46,    34,
      35,    19,    43,    17,    46,    94,    20,    21,   143,    17,
      99,    16,   147,   148,    36,   150,   151,    37,    40,   154,
     259,    43,   261,   262,   263,   264,   119,   116,    17,    54,
      44,    36,    24,    24,    69,    40,   125,    17,    43,    40,
      44,   130,    43,   282,   283,   119,    38,    38,    67,    38,
     143,   117,    16,    17,   147,    16,    36,   150,   151,    16,
      44,   154,    42,    97,    44,    45,    46,    47,    40,   143,
      44,    43,     0,   147,    92,    36,   150,   151,   213,    40,
     154,    40,    43,    40,    43,   324,    43,   222,     0,     5,
       6,    16,   323,   323,   333,     7,     8,    40,   337,   338,
      43,    20,    21,    22,   139,    24,    41,    26,    27,    17,
      29,    46,   247,   248,   249,    40,   347,    36,    43,    17,
     213,    36,    44,    42,   363,    44,    45,    46,    47,   222,
      45,    46,   167,   301,   169,   303,   375,    37,   377,   213,
     175,    36,    20,    21,    22,    11,    12,    42,   222,    44,
      45,    46,    47,    44,   247,   248,   249,    41,    36,    20,
      21,    22,    46,   213,    42,    37,    44,    45,    46,    47,
      24,    25,   191,   247,   248,   249,   211,   312,   313,   314,
      45,   231,   317,    44,    37,   220,    36,    37,   323,   324,
      16,    17,    42,    40,    44,    45,    46,    47,    16,    17,
     335,     4,   337,   338,   339,   340,    45,    46,   258,   259,
       3,   261,   262,   263,   264,   250,   251,    37,   253,   312,
     313,   314,    24,    25,   317,   360,   247,   248,   249,    41,
     323,   324,   282,   283,     7,     8,     9,    10,   312,   313,
     314,    16,   335,   317,   337,   338,   339,   340,    37,   323,
     324,   143,    16,    36,    41,   147,    37,    40,   150,   151,
      43,   335,   154,   337,   338,   339,   340,   360,     7,     8,
     305,    71,    72,   323,   324,    73,    74,    75,    76,    13,
      14,    15,   301,   333,   303,   335,   360,   337,   338,    77,
      78,   312,   313,   314,    40,   330,   317,    20,    21,    22,
      79,    80,    81,    46,    37,    37,    44,    16,    44,    38,
      38,    46,    23,   363,   335,    40,   337,   338,   339,   340,
      37,    37,    41,    41,    46,   375,   361,   377,    17,    23,
      40,    17,    36,   368,    20,    21,    22,    36,    24,   360,
      26,    27,    39,    29,    36,    31,    32,    17,    36,    36,
      36,    16,    38,    17,    39,    46,    42,    41,    44,    45,
      46,    47,    20,    21,    22,    36,    24,    44,    26,    27,
      17,    29,    23,    23,    46,    33,    34,    35,    36,    17,
      41,    37,    37,    37,    42,    16,    44,    45,    46,    47,
      20,    21,    22,    16,    24,    17,    26,    27,    38,    29,
      44,    31,    32,    44,    38,    44,    36,    18,    37,    37,
      17,    43,    42,    17,    44,    45,    46,    47,    20,    21,
      22,    36,    24,    43,    26,    27,    17,    29,    17,    31,
      32,    30,    17,    17,    36,    44,    39,    17,    44,    17,
      42,    39,    44,    45,    46,    47,    28,    43,    19,    37,
      37,    19,    19,    39,    16,    38,    37,    31,    37,    36,
      19,    19,    31,    39,    39,    17,    17,    37,    31,    17,
      31,    36,    17,    39,    38,    25,    36,   332,   273,    25,
     370,    37,    39,    37,    39,    38,   379,   185,   268,    38,
     240,   148,    39,   271,    -1,    -1,    -1,    70
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,    21,    22,    44,    49,    50,    78,    81,    44,
      91,    44,    92,    44,    91,    43,     0,    50,    50,    16,
      36,    40,    43,   108,    17,    16,    36,    40,    43,   108,
      17,    36,    40,    17,    36,    42,    44,    45,    46,    47,
      93,    94,    95,    96,    97,    98,    99,    44,    91,    82,
      85,    41,    46,    93,    44,    92,    83,    87,    41,    46,
      45,    84,    86,    41,    93,    93,    40,    16,    17,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    20,    21,    22,   102,   103,   104,    37,    40,
      43,    41,    16,   102,    37,    43,    41,    16,   102,    37,
      37,    46,    78,    93,    94,    95,    95,    96,    96,    96,
      96,    97,    97,    98,    98,    98,    37,    16,    44,    38,
     105,    46,    38,    40,    91,    37,   105,    23,    43,    92,
      37,   105,    41,   105,   102,    24,    26,    27,    29,    33,
      34,    35,    44,    52,    64,    67,    71,    76,    77,    78,
      79,    80,    81,    93,   100,   106,   107,    41,    39,    46,
      88,    46,   105,    17,    23,   105,    40,    36,    53,    36,
      36,    17,    93,    36,    36,    36,   106,   106,    44,    76,
     106,   106,   106,    39,    17,    16,    39,    41,    17,    46,
      93,    36,    54,    55,    56,    58,    93,    44,    17,    23,
      23,    37,    93,   101,    88,    17,    41,    37,    17,    20,
      21,    61,    78,    37,    37,    16,    89,    16,    90,    17,
      16,    37,    38,    44,    44,    62,    93,    17,    24,    31,
      32,    38,    52,    60,    65,    69,    71,    77,   100,    38,
      44,    37,    18,    37,    93,    17,    51,    52,    77,   100,
      43,    43,    17,    36,    17,    17,    31,    32,    52,    60,
      66,    69,    71,    77,   100,    30,    72,    73,    74,    89,
      17,    44,    17,    39,    51,    51,    51,    93,    93,    44,
      63,    93,    17,    17,    66,    66,    39,    66,    66,    66,
      66,    36,    45,    46,    28,    75,    73,    90,    25,    67,
      68,    16,    17,    16,    17,    43,    37,    37,    66,    66,
      45,    46,    19,    19,    19,    39,    24,    38,    61,    61,
      93,    17,    38,    59,    38,    37,    37,    51,    51,    51,
      36,    51,    16,    57,    60,    52,    66,    77,   100,    19,
      19,    31,    31,    93,    39,    63,    66,    39,    51,    51,
      17,    17,    37,    39,    24,    25,    69,    70,    31,    31,
      38,    36,    24,    38,    17,    17,    51,    93,    36,    66,
      39,    37,    93,    39,    68,    38,    37,    38,    66,    39,
      70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    50,    51,    51,    51,
      51,    53,    52,    52,    52,    52,    54,    54,    54,    55,
      57,    56,    59,    58,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    62,    62,    63,
      63,    64,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    70,    71,    72,    72,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      76,    77,    77,    77,    78,    78,    79,    80,    82,    81,
      83,    81,    84,    81,    85,    81,    86,    81,    87,    81,
      81,    81,    81,    81,    81,    81,    81,    88,    88,    89,
      89,    90,    90,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    93,    93,    94,    94,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      98,    98,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   104,   104,   104,
     105,   106,   106,   106,   106,   106,   106,   106,   107,   107,
     108,   108,   108
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     2,     2,     2,
       0,     0,     3,     1,     1,     1,     1,     1,     1,     7,
       0,    10,     0,     8,     1,     1,     1,     2,     2,     1,
       1,     1,     5,     6,     5,     6,     1,     1,     0,     5,
       3,     5,     3,     1,     1,     3,     3,     2,     2,     2,
       2,     2,     2,     0,     8,     8,     9,     4,     0,     8,
       8,     9,     4,     0,     8,     1,     0,     2,     0,     8,
       6,     6,     4,     8,     6,     6,     4,     3,     0,     2,
       1,     1,     1,     1,     5,     4,     6,     6,     0,     7,
       0,     7,     0,     7,     0,     6,     0,     6,     0,     6,
       3,     8,     7,     3,     3,     9,     8,     3,     1,     3,
       0,     4,     0,     5,     3,     3,     2,     1,     5,     3,
       3,     2,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     1,     3,     2,     1,     1,     1,     4,     7,
       4,     5,     3,     1,     1,     3,     2,     1,     1,     1,
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
#line 137 "SemanticAnalyzer.y"
                           {printf("Starting..\n");}
#line 1703 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 139 "SemanticAnalyzer.y"
                                                            {printf("RECURSIVE DECLARATION \n");}
#line 1709 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 141 "SemanticAnalyzer.y"
                                                        {printf("DECLARATION \n");}
#line 1715 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 144 "SemanticAnalyzer.y"
                                             {printf("Special..\n");}
#line 1721 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 145 "SemanticAnalyzer.y"
                                               {printf("Basic123..\n");}
#line 1727 "y.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 149 "SemanticAnalyzer.y"
                           {pushNewScope();}
#line 1733 "y.tab.c"
    break;

  case 19: /* forLoop1: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON  */
#line 155 "SemanticAnalyzer.y"
                                                                                                         {popScope(); printf("\nFOR SEMICOLON \n");}
#line 1739 "y.tab.c"
    break;

  case 20: /* $@2: %empty  */
#line 156 "SemanticAnalyzer.y"
                                                                                                       {pushNewScope();}
#line 1745 "y.tab.c"
    break;

  case 21: /* forLoop2: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR $@2 inLoop CLCUR  */
#line 156 "SemanticAnalyzer.y"
                                                                                                                                      {popScope(); popScope(); printf("\nproper FOR \n");}
#line 1751 "y.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 157 "SemanticAnalyzer.y"
                                                                                             {pushNewScope();}
#line 1757 "y.tab.c"
    break;

  case 23: /* forLoop3: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC $@3 singleLoopStatement  */
#line 157 "SemanticAnalyzer.y"
                                                                                                                                   {popScope(); popScope(); printf("\nFOR SINGLE STATEMENT \n");}
#line 1763 "y.tab.c"
    break;

  case 42: /* whileSuffix: OPCUR inLoop CLCUR  */
#line 179 "SemanticAnalyzer.y"
                                     {printf("\nproper WHILE \n");}
#line 1769 "y.tab.c"
    break;

  case 43: /* whileSuffix: SEMICOLON  */
#line 180 "SemanticAnalyzer.y"
                              {printf("\nWHILE SEMICOLON \n");}
#line 1775 "y.tab.c"
    break;

  case 44: /* whileSuffix: singleLoopStatement  */
#line 181 "SemanticAnalyzer.y"
                                        {printf("\nSINGLE WHILE \n");}
#line 1781 "y.tab.c"
    break;

  case 45: /* inLoop: BREAK SEMICOLON inLoop  */
#line 183 "SemanticAnalyzer.y"
                                    {printf("\n break in loop \n");}
#line 1787 "y.tab.c"
    break;

  case 46: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 184 "SemanticAnalyzer.y"
                                            {printf("\ncontinue in loop \n");}
#line 1793 "y.tab.c"
    break;

  case 47: /* inLoop: specialStatement inLoop  */
#line 185 "SemanticAnalyzer.y"
                                          {printf("\n special statement in loop \n");}
#line 1799 "y.tab.c"
    break;

  case 48: /* inLoop: basicStatement inLoop  */
#line 186 "SemanticAnalyzer.y"
                                        {printf("\n basic statement in loop \n");}
#line 1805 "y.tab.c"
    break;

  case 49: /* inLoop: functionCall inLoop  */
#line 187 "SemanticAnalyzer.y"
                                     {printf("\n basic statement in loop \n");}
#line 1811 "y.tab.c"
    break;

  case 50: /* inLoop: ifInLoopStatement inLoop  */
#line 188 "SemanticAnalyzer.y"
                                           {printf("\n if in loop \n");}
#line 1817 "y.tab.c"
    break;

  case 51: /* inLoop: switchStatement inLoop  */
#line 189 "SemanticAnalyzer.y"
                                         {printf("\n switch in loop \n");}
#line 1823 "y.tab.c"
    break;

  case 52: /* inLoop: singleLoopStatement inLoop  */
#line 190 "SemanticAnalyzer.y"
                                             {printf("\n any other statement in loop \n");}
#line 1829 "y.tab.c"
    break;

  case 64: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR  */
#line 207 "SemanticAnalyzer.y"
                                                                                                  {printf("SWITCH START..\n");}
#line 1835 "y.tab.c"
    break;

  case 66: /* caseStatements: %empty  */
#line 208 "SemanticAnalyzer.y"
                                        {printf("char/int..\n");}
#line 1841 "y.tab.c"
    break;

  case 68: /* caseStatementInt: %empty  */
#line 209 "SemanticAnalyzer.y"
                                                  {printf("INT CASE..\n");}
#line 1847 "y.tab.c"
    break;

  case 69: /* caseInt: CASE OPBRAC INTVAL CLBRAC COLON statements BREAK SEMICOLON  */
#line 210 "SemanticAnalyzer.y"
                                                                         {printf("case (INT) : break; ..\n");}
#line 1853 "y.tab.c"
    break;

  case 70: /* caseInt: CASE OPBRAC INTVAL CLBRAC COLON statements  */
#line 211 "SemanticAnalyzer.y"
                                                             {printf("case (INT) : ..\n");}
#line 1859 "y.tab.c"
    break;

  case 71: /* caseInt: CASE INTVAL COLON statements BREAK SEMICOLON  */
#line 212 "SemanticAnalyzer.y"
                                                               {printf("case INT : BREAK;..\n");}
#line 1865 "y.tab.c"
    break;

  case 72: /* caseInt: CASE INTVAL COLON statements  */
#line 213 "SemanticAnalyzer.y"
                                               {printf("CASE INT : ..\n");}
#line 1871 "y.tab.c"
    break;

  case 73: /* caseInt: CASE OPBRAC CHARVAL CLBRAC COLON statements BREAK SEMICOLON  */
#line 214 "SemanticAnalyzer.y"
                                                                              {printf("case (char) : break; ..\n");}
#line 1877 "y.tab.c"
    break;

  case 74: /* caseInt: CASE OPBRAC CHARVAL CLBRAC COLON statements  */
#line 215 "SemanticAnalyzer.y"
                                                              {printf("case (char) : ..\n");}
#line 1883 "y.tab.c"
    break;

  case 75: /* caseInt: CASE CHARVAL COLON statements BREAK SEMICOLON  */
#line 216 "SemanticAnalyzer.y"
                                                                {printf("case char : BREAK;..\n");}
#line 1889 "y.tab.c"
    break;

  case 76: /* caseInt: CASE CHARVAL COLON statements  */
#line 217 "SemanticAnalyzer.y"
                                                {printf("CASE char : ..\n");}
#line 1895 "y.tab.c"
    break;

  case 78: /* defaultStatement: %empty  */
#line 218 "SemanticAnalyzer.y"
                                                   {printf(" \nDEFAULT : ..\n");}
#line 1901 "y.tab.c"
    break;

  case 81: /* basicStatement: expressionStatement  */
#line 224 "SemanticAnalyzer.y"
                                         {printf("BS->EXPS..\n");}
#line 1907 "y.tab.c"
    break;

  case 82: /* basicStatement: declarationStatement  */
#line 225 "SemanticAnalyzer.y"
                                       {printf("BS->DS..\n");}
#line 1913 "y.tab.c"
    break;

  case 83: /* basicStatement: assignmentStatement  */
#line 226 "SemanticAnalyzer.y"
                                        {printf("Basic->AS..\n");}
#line 1919 "y.tab.c"
    break;

  case 84: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 228 "SemanticAnalyzer.y"
                                                                                         {printf("AS1..\n");}
#line 1925 "y.tab.c"
    break;

  case 85: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 229 "SemanticAnalyzer.y"
                                                                 {printf("AS2..\n");}
#line 1931 "y.tab.c"
    break;

  case 88: /* $@4: %empty  */
#line 233 "SemanticAnalyzer.y"
                                                 {pushNewScope();}
#line 1937 "y.tab.c"
    break;

  case 89: /* declarationStatement: INT IDENTIFIER OPBRAC $@4 parameters CLBRAC compoundStatements  */
#line 233 "SemanticAnalyzer.y"
                                                                                                         {printf("INT F WITH PARAMS..\n");}
#line 1943 "y.tab.c"
    break;

  case 90: /* $@5: %empty  */
#line 234 "SemanticAnalyzer.y"
                                          {pushNewScope();}
#line 1949 "y.tab.c"
    break;

  case 91: /* declarationStatement: CHAR IDENTIFIER OPBRAC $@5 parameters CLBRAC compoundStatements  */
#line 234 "SemanticAnalyzer.y"
                                                                                                  {printf("char F WITH PARAMS..\n");}
#line 1955 "y.tab.c"
    break;

  case 92: /* $@6: %empty  */
#line 235 "SemanticAnalyzer.y"
                                           {pushNewScope();}
#line 1961 "y.tab.c"
    break;

  case 93: /* declarationStatement: FLOAT IDENTIFIER OPBRAC $@6 parameters CLBRAC compoundStatements  */
#line 235 "SemanticAnalyzer.y"
                                                                                                  {printf("float F WITH PARAMS..\n");}
#line 1967 "y.tab.c"
    break;

  case 94: /* $@7: %empty  */
#line 236 "SemanticAnalyzer.y"
                                         {pushNewScope();}
#line 1973 "y.tab.c"
    break;

  case 96: /* $@8: %empty  */
#line 237 "SemanticAnalyzer.y"
                                           {pushNewScope();}
#line 1979 "y.tab.c"
    break;

  case 98: /* $@9: %empty  */
#line 238 "SemanticAnalyzer.y"
                                          {pushNewScope();}
#line 1985 "y.tab.c"
    break;

  case 100: /* declarationStatement: INT declarationListIntFloat SEMICOLON  */
#line 239 "SemanticAnalyzer.y"
                                                        {printf("DS1..\n");}
#line 1991 "y.tab.c"
    break;

  case 113: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListIntFloat  */
#line 251 "SemanticAnalyzer.y"
                                                                                                 {printf("DSL1..\n");}
#line 1997 "y.tab.c"
    break;

  case 115: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement  */
#line 253 "SemanticAnalyzer.y"
                                                       {printf("DSL3..\n");}
#line 2003 "y.tab.c"
    break;

  case 116: /* declarationListIntFloat: IDENTIFIER dimension  */
#line 254 "SemanticAnalyzer.y"
                                        {printf("INTFLOAT ARRAY..\n");}
#line 2009 "y.tab.c"
    break;

  case 117: /* declarationListIntFloat: IDENTIFIER  */
#line 255 "SemanticAnalyzer.y"
                             {printf("DSL4..\n");}
#line 2015 "y.tab.c"
    break;

  case 123: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 263 "SemanticAnalyzer.y"
                                                                          {printf("ES1..\n");}
#line 2021 "y.tab.c"
    break;

  case 124: /* expressionStatement: logicalExpression  */
#line 264 "SemanticAnalyzer.y"
                                    {printf("ES2..\n");}
#line 2027 "y.tab.c"
    break;

  case 125: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 266 "SemanticAnalyzer.y"
                                                                {printf("LE1..\n");}
#line 2033 "y.tab.c"
    break;

  case 126: /* logicalExpression: expression  */
#line 267 "SemanticAnalyzer.y"
                             {printf("LE2..\n");}
#line 2039 "y.tab.c"
    break;

  case 127: /* expression: relationalExpression EQUALS expression  */
#line 269 "SemanticAnalyzer.y"
                                                        {printf("E1..\n");}
#line 2045 "y.tab.c"
    break;

  case 128: /* expression: relationalExpression NOTEQUAL expression  */
#line 270 "SemanticAnalyzer.y"
                                                           {printf("E2..\n");}
#line 2051 "y.tab.c"
    break;

  case 129: /* expression: relationalExpression  */
#line 271 "SemanticAnalyzer.y"
                                       {printf("E3..\n");}
#line 2057 "y.tab.c"
    break;

  case 134: /* relationalExpression: value  */
#line 277 "SemanticAnalyzer.y"
                        {printf("VALUE..\n");}
#line 2063 "y.tab.c"
    break;

  case 135: /* value: term ADD value  */
#line 279 "SemanticAnalyzer.y"
                           {printf("ADD..\n");}
#line 2069 "y.tab.c"
    break;

  case 137: /* value: term  */
#line 281 "SemanticAnalyzer.y"
               {printf("Basic TERM..\n");}
#line 2075 "y.tab.c"
    break;

  case 138: /* term: factor MULT term  */
#line 283 "SemanticAnalyzer.y"
                            {printf("MULT..\n");}
#line 2081 "y.tab.c"
    break;

  case 141: /* term: factor  */
#line 286 "SemanticAnalyzer.y"
                 {printf("Factor..\n");}
#line 2087 "y.tab.c"
    break;

  case 146: /* factor: INTVAL  */
#line 292 "SemanticAnalyzer.y"
                 {printf("INT VALS.. %d\n",yylval);}
#line 2093 "y.tab.c"
    break;

  case 155: /* parameters: parameter COMMA parameters  */
#line 304 "SemanticAnalyzer.y"
                                                         {printf("FUNCTION params\n");}
#line 2099 "y.tab.c"
    break;

  case 156: /* parameter: type IDENTIFIER  */
#line 306 "SemanticAnalyzer.y"
                                {printf("FUNCTION param\n");}
#line 2105 "y.tab.c"
    break;

  case 160: /* compoundStatements: OPCUR statementList CLCUR  */
#line 310 "SemanticAnalyzer.y"
                                                   {popScope();printf("FUNCTION statements\n");}
#line 2111 "y.tab.c"
    break;

  case 170: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 316 "SemanticAnalyzer.y"
                                        {printf("size..\n");}
#line 2117 "y.tab.c"
    break;


#line 2121 "y.tab.c"

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

#line 319 "SemanticAnalyzer.y"

     
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
     
     
