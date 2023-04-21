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
  YYSYMBOL_forLoop = 53,                   /* forLoop  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_forSuffix = 56,                 /* forSuffix  */
  YYSYMBOL_57_3 = 57,                      /* $@3  */
  YYSYMBOL_singleLoopStatement = 58,       /* singleLoopStatement  */
  YYSYMBOL_forAssignStatement = 59,        /* forAssignStatement  */
  YYSYMBOL_forExpStatement = 60,           /* forExpStatement  */
  YYSYMBOL_forUpdateStatement = 61,        /* forUpdateStatement  */
  YYSYMBOL_whileLoop = 62,                 /* whileLoop  */
  YYSYMBOL_whileSuffix = 63,               /* whileSuffix  */
  YYSYMBOL_inLoop = 64,                    /* inLoop  */
  YYSYMBOL_ifStatement = 65,               /* ifStatement  */
  YYSYMBOL_ES = 66,                        /* ES  */
  YYSYMBOL_ifInLoopStatement = 67,         /* ifInLoopStatement  */
  YYSYMBOL_ESLoop = 68,                    /* ESLoop  */
  YYSYMBOL_switchStatement = 69,           /* switchStatement  */
  YYSYMBOL_caseStatements = 70,            /* caseStatements  */
  YYSYMBOL_caseStatementInt = 71,          /* caseStatementInt  */
  YYSYMBOL_caseInt = 72,                   /* caseInt  */
  YYSYMBOL_defaultStatement = 73,          /* defaultStatement  */
  YYSYMBOL_basicStatements = 74,           /* basicStatements  */
  YYSYMBOL_basicStatement = 75,            /* basicStatement  */
  YYSYMBOL_assignmentStatement = 76,       /* assignmentStatement  */
  YYSYMBOL_printer = 77,                   /* printer  */
  YYSYMBOL_scanner = 78,                   /* scanner  */
  YYSYMBOL_declarationStatement = 79,      /* declarationStatement  */
  YYSYMBOL_80_4 = 80,                      /* $@4  */
  YYSYMBOL_81_5 = 81,                      /* $@5  */
  YYSYMBOL_82_6 = 82,                      /* $@6  */
  YYSYMBOL_83_7 = 83,                      /* $@7  */
  YYSYMBOL_84_8 = 84,                      /* $@8  */
  YYSYMBOL_85_9 = 85,                      /* $@9  */
  YYSYMBOL_arrayValues = 86,               /* arrayValues  */
  YYSYMBOL_prattributes = 87,              /* prattributes  */
  YYSYMBOL_scattributes = 88,              /* scattributes  */
  YYSYMBOL_declarationListIntFloat = 89,   /* declarationListIntFloat  */
  YYSYMBOL_declarationListChar = 90,       /* declarationListChar  */
  YYSYMBOL_expressionStatement = 91,       /* expressionStatement  */
  YYSYMBOL_logicalExpression = 92,         /* logicalExpression  */
  YYSYMBOL_expression = 93,                /* expression  */
  YYSYMBOL_relationalExpression = 94,      /* relationalExpression  */
  YYSYMBOL_value = 95,                     /* value  */
  YYSYMBOL_term = 96,                      /* term  */
  YYSYMBOL_factor = 97,                    /* factor  */
  YYSYMBOL_functionCall = 98,              /* functionCall  */
  YYSYMBOL_argList = 99,                   /* argList  */
  YYSYMBOL_parameters = 100,               /* parameters  */
  YYSYMBOL_parameter = 101,                /* parameter  */
  YYSYMBOL_type = 102,                     /* type  */
  YYSYMBOL_compoundStatements = 103,       /* compoundStatements  */
  YYSYMBOL_statementList = 104,            /* statementList  */
  YYSYMBOL_returnDec = 105,                /* returnDec  */
  YYSYMBOL_dimension = 106                 /* dimension  */
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
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  170
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  379

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
     147,   149,   150,   151,   152,   153,   153,   153,   155,   156,
     156,   157,   159,   160,   161,   162,   163,   164,   165,   167,
     168,   169,   170,   171,   172,   173,   173,   174,   175,   178,
     179,   180,   181,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   193,   194,   196,   197,   198,   200,   201,   203,
     204,   205,   207,   208,   208,   209,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   218,   221,   222,   224,
     225,   226,   228,   229,   231,   232,   233,   233,   234,   234,
     235,   235,   236,   236,   237,   237,   238,   238,   239,   240,
     241,   242,   243,   244,   245,   247,   247,   248,   248,   249,
     249,   251,   252,   253,   254,   255,   257,   258,   259,   260,
     261,   263,   264,   266,   267,   269,   270,   271,   273,   274,
     275,   276,   277,   279,   280,   281,   283,   284,   285,   286,
     288,   289,   290,   291,   292,   293,   294,   295,   298,   299,
     302,   302,   304,   304,   306,   308,   308,   308,   310,   312,
     312,   312,   312,   312,   312,   312,   314,   314,   316,   317,
     318
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
  "declarationList", "statements", "specialStatement", "forLoop", "$@1",
  "$@2", "forSuffix", "$@3", "singleLoopStatement", "forAssignStatement",
  "forExpStatement", "forUpdateStatement", "whileLoop", "whileSuffix",
  "inLoop", "ifStatement", "ES", "ifInLoopStatement", "ESLoop",
  "switchStatement", "caseStatements", "caseStatementInt", "caseInt",
  "defaultStatement", "basicStatements", "basicStatement",
  "assignmentStatement", "printer", "scanner", "declarationStatement",
  "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "arrayValues", "prattributes",
  "scattributes", "declarationListIntFloat", "declarationListChar",
  "expressionStatement", "logicalExpression", "expression",
  "relationalExpression", "value", "term", "factor", "functionCall",
  "argList", "parameters", "parameter", "type", "compoundStatements",
  "statementList", "returnDec", "dimension", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-256)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-97)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      81,   -29,   -20,    14,    23,    49,  -256,    81,    81,    12,
      75,    37,    83,    51,    89,   183,  -256,  -256,  -256,    64,
      96,   -28,   183,  -256,  -256,    97,   123,   108,   113,  -256,
    -256,   129,   128,  -256,   183,   183,   130,  -256,  -256,  -256,
     110,   165,   172,   145,   269,   169,   240,    -4,  -256,   247,
     149,   135,   176,   191,    28,  -256,   247,   162,   158,   185,
     198,   247,   187,   194,   205,  -256,   212,   200,  -256,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,  -256,  -256,  -256,   248,   215,   216,   227,   225,
     263,   279,    64,   284,   227,   299,   166,    97,   289,   227,
    -256,   287,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,   227,   247,  -256,   374,
    -256,   290,    -6,   291,  -256,   227,  -256,   316,   313,  -256,
     227,  -256,   298,  -256,  -256,   306,   307,   310,   317,    68,
     318,   320,   116,   374,  -256,  -256,  -256,  -256,   374,    98,
    -256,   374,   374,  -256,  -256,   374,   301,  -256,  -256,   335,
     345,   324,   325,  -256,  -256,   351,  -256,   329,   183,  -256,
     183,   327,  -256,   360,   355,   356,   244,  -256,  -256,   173,
    -256,  -256,  -256,  -256,  -256,  -256,   340,   370,  -256,  -256,
     347,   352,     6,   353,   354,  -256,   376,   377,   380,  -256,
       5,  -256,  -256,  -256,   364,  -256,   361,   362,   183,  -256,
     303,   366,   368,   378,   396,   388,  -256,   183,   400,   430,
     384,   387,   415,  -256,  -256,   399,   419,   420,   402,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,   409,   376,   423,   397,
     425,  -256,  -256,   404,   430,   430,   430,   183,   183,   401,
     183,  -256,  -256,   436,   438,   402,   402,   421,   402,   402,
     402,   402,    71,   433,  -256,   409,  -256,  -256,   377,  -256,
     167,  -256,  -256,  -256,   223,   234,   422,  -256,   426,   402,
     402,  -256,  -256,  -256,  -256,  -256,  -256,  -256,   237,   439,
     443,   445,   428,  -256,  -256,    -7,  -256,  -256,     6,  -256,
       6,  -256,   183,   431,   432,  -256,  -256,   434,   441,   430,
     430,   430,  -256,   437,   430,  -256,  -256,   453,   338,   402,
     460,   461,   450,   451,  -256,   183,   444,   401,  -256,  -256,
    -256,  -256,   402,   446,   402,   402,   430,   430,   467,   469,
     452,  -256,  -256,   402,   268,   456,   457,  -256,  -256,   454,
     455,   459,    50,  -256,  -256,   473,   474,   430,  -256,   183,
     462,   402,  -256,  -256,   458,   463,   183,   464,   468,   466,
     465,  -256,  -256,   402,   470,   402,   471,   476,  -256
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     5,   115,
       0,   120,     0,   115,     0,     0,     1,     4,     3,     0,
      86,     0,     0,   114,    98,     0,    88,     0,     0,   119,
     101,    90,     0,   102,     0,     0,   140,   143,   144,   145,
       0,   122,   124,   127,   132,   135,   139,   115,   112,     0,
       0,     0,     0,   113,   120,   117,     0,     0,     0,     0,
     118,     0,     0,     0,     0,   142,     0,     0,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   157,   156,     0,   152,     0,     0,     0,
       0,   168,     0,     0,     0,     0,   168,     0,     0,     0,
     141,     0,    82,   121,   123,   125,   126,   128,   129,   130,
     131,   133,   134,   136,   137,   138,     0,     0,   154,   165,
      93,     0,     0,     0,   111,     0,    97,     0,     0,   116,
       0,    95,   146,    87,   153,     0,     0,     0,     0,     0,
       0,     0,   140,   165,    11,    13,    12,    14,   165,    78,
      81,   165,   165,    80,    79,   165,     0,   162,   170,     0,
     106,     0,     0,    89,   100,     0,    91,     0,     0,    15,
       0,     0,   167,     0,     0,     0,     0,   160,   159,   140,
      77,   163,   164,   161,   158,   104,     0,     0,   169,    99,
       0,     0,     0,     0,     0,   166,   108,   110,     0,   151,
       0,   105,   103,   147,     0,    34,     0,     0,    36,    29,
       0,     0,     0,     0,     0,     0,   148,     0,     0,    10,
       0,     0,     0,    35,    41,     0,     0,     0,    51,    22,
      42,    39,    28,    14,    23,    24,    64,   108,     0,     0,
       0,   150,   149,     0,    10,    10,    10,     0,     0,     0,
       0,    25,    26,     0,     0,    22,    51,     0,    28,    14,
      23,    24,     0,    76,    63,    66,   107,    84,   110,    85,
      56,     7,     8,     9,     0,     0,     0,    16,     0,    25,
      26,    45,    50,    40,    48,    49,    46,    47,     0,     0,
       0,     0,     0,    65,   109,     0,    53,    52,     0,    30,
       0,    32,     0,     0,     0,    43,    44,     0,     0,    10,
      10,    10,    62,     0,    10,    31,    33,    38,     0,    10,
       0,     0,    74,    70,    75,     0,     0,     0,    18,    19,
      17,    21,    10,     0,    10,    10,    10,    10,     0,     0,
       0,    55,    37,    51,    61,    72,    68,    73,    69,     0,
       0,     0,     0,    58,    57,     0,     0,    10,    20,     0,
       0,    51,    71,    67,     0,     0,     0,     0,    56,     0,
       0,    60,    54,    51,     0,    51,     0,    61,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -256,  -256,   304,  -147,   -73,  -256,  -256,  -256,  -256,  -256,
    -207,  -255,  -256,   178,  -256,  -256,    38,   226,   131,  -209,
     132,  -196,  -256,   241,  -256,  -256,   358,  -114,     2,  -256,
    -256,   121,  -256,  -256,  -256,  -256,  -256,  -256,   326,   274,
     245,     3,   -21,   -15,   447,   242,   230,   238,   228,  -256,
     -62,  -256,   -45,  -256,  -256,   -69,    60,  -256,    -3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,   243,   255,   144,   192,   303,   330,   343,
     256,   208,   222,   277,   145,   231,   281,   146,   297,   258,
     354,   147,   263,   264,   265,   292,   148,   260,   150,   151,
     152,   153,    49,    56,    61,    50,    62,    57,   161,   213,
     215,    10,    12,   154,    41,    42,    43,    44,    45,    46,
     261,   200,    85,    86,    87,   120,   156,   157,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,   232,     7,   230,    55,   149,    14,    53,    29,     7,
       7,    93,    19,    51,   233,     9,    98,   313,    52,    64,
      65,   217,    48,   205,    11,   126,   206,   207,    19,   149,
     131,   314,   259,   159,   149,   149,    32,   149,   149,    22,
     160,   149,   218,   315,    25,   316,   143,   133,    20,    16,
       4,    29,    21,    25,   103,    22,   163,   155,    13,   259,
     259,   166,   259,   259,   259,   259,    15,    19,    32,   102,
     143,    28,   134,    26,   360,   143,   129,    27,   143,   143,
      28,   155,   143,   259,   259,   172,   155,    31,   361,   155,
     155,    32,    24,   155,    22,   124,   234,   271,   272,   273,
      30,     1,     2,     3,    34,   245,    33,   288,    47,   232,
      35,   331,    36,    37,    38,    39,   289,   290,     1,     2,
       3,     8,   233,   259,   173,     4,    67,    68,     8,     8,
     245,   245,   245,   -92,    34,   353,   259,   229,   259,   259,
      35,    54,   179,    37,    38,    39,   244,   259,   235,    58,
      71,    72,   176,   191,    59,   193,    66,   246,    60,    15,
     -96,   199,   322,   323,   324,   259,   -94,   326,    69,    63,
      66,   244,   244,   244,    52,    89,    70,   259,    90,   259,
      77,    78,   246,   246,   246,   271,    88,   272,   273,   345,
     346,   135,   295,   223,   209,   245,   245,   245,    89,    94,
     245,    95,   241,   177,   234,   334,   123,    92,   178,   128,
     364,   181,   182,    66,    97,   183,    15,    91,   334,    34,
     334,   334,   245,   245,    99,    35,    96,    36,    37,    38,
      39,   117,   274,   275,    89,   278,   244,   244,   244,   298,
     299,   244,   100,   245,     4,   229,   332,   246,   246,   246,
     300,   301,   246,    79,    80,    81,   235,   335,   101,   332,
     118,   332,   332,   244,   244,   119,   257,    82,    83,    84,
     335,   121,   335,   335,   246,   246,    73,    74,    75,    76,
      34,   198,   307,   308,   244,   116,    35,   317,    36,    37,
      38,    39,   351,   352,   282,   246,   284,   285,   286,   287,
     209,   122,   209,   107,   108,   109,   110,   113,   114,   115,
     340,    17,    18,   105,   106,   111,   112,   305,   306,   123,
     224,   125,   127,     1,     2,     3,   130,   225,   132,   136,
     137,   158,   138,   164,   226,   227,   165,   162,   167,    34,
     184,   228,   168,   169,   365,    35,   170,   142,    37,    38,
      39,   370,   185,   171,   174,   328,   175,   333,     1,     2,
       3,   186,   225,   187,   136,   137,   188,   138,   189,   226,
     227,   194,   286,   287,    34,   190,   329,   195,   196,   197,
      35,   350,   142,    37,    38,    39,   160,   202,   203,   204,
     210,   211,   212,   214,     1,     2,     3,   216,   135,   367,
     136,   137,   219,   138,   236,   220,   221,   139,   140,   141,
      34,   333,   237,   376,   239,   238,    35,   242,   142,    37,
      38,    39,     1,     2,     3,   240,   225,   247,   136,   137,
     248,   138,   249,   253,   254,   250,   251,   252,    34,   262,
     267,   268,   269,   270,    35,   276,   142,    37,    38,    39,
       1,     2,     3,   279,   135,   280,   136,   137,   309,   138,
     283,   291,   310,   304,   311,   302,    34,   312,   318,   327,
     319,   320,    35,   325,   142,    37,    38,    39,   321,   336,
     337,   338,   339,   341,   347,   344,   348,   355,   356,   349,
     362,   363,   357,   295,   358,   359,   296,   368,   366,   372,
     369,   352,   374,   371,   373,   342,   293,   180,   375,   378,
     377,   266,   201,   294,     0,     0,     0,   104
};

static const yytype_int16 yycheck[] =
{
      15,   210,     0,   210,    25,   119,     3,    22,    11,     7,
       8,    56,    16,    41,   210,    44,    61,    24,    46,    34,
      35,    16,    19,    17,    44,    94,    20,    21,    16,   143,
      99,    38,   228,    39,   148,   149,    40,   151,   152,    43,
      46,   155,    37,   298,    16,   300,   119,   116,    36,     0,
      44,    54,    40,    16,    69,    43,   125,   119,    44,   255,
     256,   130,   258,   259,   260,   261,    43,    16,    40,    67,
     143,    43,   117,    36,    24,   148,    97,    40,   151,   152,
      43,   143,   155,   279,   280,    17,   148,    36,    38,   151,
     152,    40,    17,   155,    43,    92,   210,   244,   245,   246,
      17,    20,    21,    22,    36,   219,    17,    36,    44,   318,
      42,   318,    44,    45,    46,    47,    45,    46,    20,    21,
      22,     0,   318,   319,   139,    44,    16,    17,     7,     8,
     244,   245,   246,    37,    36,   344,   332,   210,   334,   335,
      42,    44,    44,    45,    46,    47,   219,   343,   210,    41,
       5,     6,    36,   168,    46,   170,    40,   219,    45,    43,
      37,   176,   309,   310,   311,   361,    37,   314,     3,    41,
      40,   244,   245,   246,    46,    40,     4,   373,    43,   375,
      11,    12,   244,   245,   246,   332,    37,   334,   335,   336,
     337,    24,    25,   208,   192,   309,   310,   311,    40,    37,
     314,    43,   217,   143,   318,   319,    40,    16,   148,    43,
     357,   151,   152,    40,    16,   155,    43,    41,   332,    36,
     334,   335,   336,   337,    37,    42,    41,    44,    45,    46,
      47,    16,   247,   248,    40,   250,   309,   310,   311,    16,
      17,   314,    37,   357,    44,   318,   319,   309,   310,   311,
      16,    17,   314,    13,    14,    15,   318,   319,    46,   332,
      44,   334,   335,   336,   337,    38,   228,    20,    21,    22,
     332,    46,   334,   335,   336,   337,     7,     8,     9,    10,
      36,    37,    45,    46,   357,    37,    42,   302,    44,    45,
      46,    47,    24,    25,   256,   357,   258,   259,   260,   261,
     298,    38,   300,    73,    74,    75,    76,    79,    80,    81,
     325,     7,     8,    71,    72,    77,    78,   279,   280,    40,
      17,    37,    23,    20,    21,    22,    37,    24,    41,    26,
      27,    41,    29,    17,    31,    32,    23,    46,    40,    36,
      39,    38,    36,    36,   359,    42,    36,    44,    45,    46,
      47,   366,    17,    36,    36,    17,    36,   319,    20,    21,
      22,    16,    24,    39,    26,    27,    41,    29,    17,    31,
      32,    44,   334,   335,    36,    46,    38,    17,    23,    23,
      42,   343,    44,    45,    46,    47,    46,    17,    41,    37,
      37,    37,    16,    16,    20,    21,    22,    17,    24,   361,
      26,    27,    38,    29,    38,    44,    44,    33,    34,    35,
      36,   373,    44,   375,    18,    37,    42,    17,    44,    45,
      46,    47,    20,    21,    22,    37,    24,    43,    26,    27,
      43,    29,    17,    31,    32,    36,    17,    17,    36,    30,
      17,    44,    17,    39,    42,    44,    44,    45,    46,    47,
      20,    21,    22,    17,    24,    17,    26,    27,    19,    29,
      39,    28,    19,    37,    19,    43,    36,    39,    37,    16,
      38,    37,    42,    36,    44,    45,    46,    47,    37,    19,
      19,    31,    31,    39,    17,    39,    17,    31,    31,    37,
      17,    17,    38,    25,    39,    36,   270,    39,    36,   368,
      37,    25,    37,    39,    38,   327,   265,   149,    38,   377,
      39,   237,   186,   268,    -1,    -1,    -1,    70
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,    21,    22,    44,    49,    50,    76,    79,    44,
      89,    44,    90,    44,    89,    43,     0,    50,    50,    16,
      36,    40,    43,   106,    17,    16,    36,    40,    43,   106,
      17,    36,    40,    17,    36,    42,    44,    45,    46,    47,
      91,    92,    93,    94,    95,    96,    97,    44,    89,    80,
      83,    41,    46,    91,    44,    90,    81,    85,    41,    46,
      45,    82,    84,    41,    91,    91,    40,    16,    17,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    20,    21,    22,   100,   101,   102,    37,    40,
      43,    41,    16,   100,    37,    43,    41,    16,   100,    37,
      37,    46,    76,    91,    92,    93,    93,    94,    94,    94,
      94,    95,    95,    96,    96,    96,    37,    16,    44,    38,
     103,    46,    38,    40,    89,    37,   103,    23,    43,    90,
      37,   103,    41,   103,   100,    24,    26,    27,    29,    33,
      34,    35,    44,    52,    53,    62,    65,    69,    74,    75,
      76,    77,    78,    79,    91,    98,   104,   105,    41,    39,
      46,    86,    46,   103,    17,    23,   103,    40,    36,    36,
      36,    36,    17,    91,    36,    36,    36,   104,   104,    44,
      74,   104,   104,   104,    39,    17,    16,    39,    41,    17,
      46,    91,    54,    91,    44,    17,    23,    23,    37,    91,
      99,    86,    17,    41,    37,    17,    20,    21,    59,    76,
      37,    37,    16,    87,    16,    88,    17,    16,    37,    38,
      44,    44,    60,    91,    17,    24,    31,    32,    38,    52,
      58,    63,    67,    69,    75,    98,    38,    44,    37,    18,
      37,    91,    17,    51,    52,    75,    98,    43,    43,    17,
      36,    17,    17,    31,    32,    52,    58,    64,    67,    69,
      75,    98,    30,    70,    71,    72,    87,    17,    44,    17,
      39,    51,    51,    51,    91,    91,    44,    61,    91,    17,
      17,    64,    64,    39,    64,    64,    64,    64,    36,    45,
      46,    28,    73,    71,    88,    25,    65,    66,    16,    17,
      16,    17,    43,    55,    37,    64,    64,    45,    46,    19,
      19,    19,    39,    24,    38,    59,    59,    91,    37,    38,
      37,    37,    51,    51,    51,    36,    51,    16,    17,    38,
      56,    58,    52,    64,    75,    98,    19,    19,    31,    31,
      91,    39,    61,    57,    39,    51,    51,    17,    17,    37,
      64,    24,    25,    67,    68,    31,    31,    38,    39,    36,
      24,    38,    17,    17,    51,    91,    36,    64,    39,    37,
      91,    39,    66,    38,    37,    38,    64,    39,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    50,    51,    51,    51,
      51,    52,    52,    52,    52,    54,    55,    53,    56,    57,
      56,    56,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    59,    59,    59,    59,    60,    60,    61,    61,    62,
      63,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    66,    66,    66,    67,    67,    68,
      68,    68,    69,    70,    70,    71,    71,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    76,    76,    77,    78,    80,    79,    81,    79,
      82,    79,    83,    79,    84,    79,    85,    79,    79,    79,
      79,    79,    79,    79,    79,    86,    86,    87,    87,    88,
      88,    89,    89,    89,    89,    89,    90,    90,    90,    90,
      90,    91,    91,    92,    92,    93,    93,    93,    94,    94,
      94,    94,    94,    95,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   102,   102,   102,   103,   104,
     104,   104,   104,   104,   104,   104,   105,   105,   106,   106,
     106
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     2,     2,     2,
       0,     1,     1,     1,     1,     0,     0,    10,     1,     0,
       4,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       5,     6,     5,     6,     1,     1,     0,     5,     3,     5,
       3,     1,     1,     3,     3,     2,     2,     2,     2,     2,
       2,     0,     8,     8,     9,     4,     0,     8,     8,     9,
       4,     0,     8,     1,     0,     2,     0,     8,     6,     6,
       4,     8,     6,     6,     4,     3,     0,     2,     1,     1,
       1,     1,     5,     4,     6,     6,     0,     7,     0,     7,
       0,     7,     0,     6,     0,     6,     0,     6,     3,     8,
       7,     3,     3,     9,     8,     3,     1,     3,     0,     4,
       0,     5,     3,     3,     2,     1,     5,     3,     3,     2,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       1,     3,     2,     1,     1,     1,     4,     7,     4,     5,
       3,     1,     1,     3,     2,     1,     1,     1,     3,     2,
       2,     2,     1,     2,     2,     0,     3,     2,     3,     6,
       5
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
#line 1696 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 139 "SemanticAnalyzer.y"
                                                            {printf("RECURSIVE DECLARATION \n");}
#line 1702 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 141 "SemanticAnalyzer.y"
                                                        {printf("DECLARATION \n");}
#line 1708 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 144 "SemanticAnalyzer.y"
                                             {printf("Special..\n");}
#line 1714 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 145 "SemanticAnalyzer.y"
                                               {printf("Basic123..\n");}
#line 1720 "y.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 153 "SemanticAnalyzer.y"
                          {pushNewScope();printf("\nFOR LOOP 2\n");}
#line 1726 "y.tab.c"
    break;

  case 16: /* $@2: %empty  */
#line 153 "SemanticAnalyzer.y"
                                                                                                                                      {popScope();}
#line 1732 "y.tab.c"
    break;

  case 18: /* forSuffix: SEMICOLON  */
#line 155 "SemanticAnalyzer.y"
                          {printf("\nFOR SEMICOLON \n");}
#line 1738 "y.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 156 "SemanticAnalyzer.y"
                 {pushNewScope();}
#line 1744 "y.tab.c"
    break;

  case 20: /* forSuffix: OPCUR $@3 inLoop CLCUR  */
#line 156 "SemanticAnalyzer.y"
                                                {popScope(); popScope(); printf("\nproper FOR \n");}
#line 1750 "y.tab.c"
    break;

  case 21: /* forSuffix: singleLoopStatement  */
#line 157 "SemanticAnalyzer.y"
                          {popScope(); popScope(); printf("\nFOR SINGLE STATEMENT \n");}
#line 1756 "y.tab.c"
    break;

  case 40: /* whileSuffix: OPCUR inLoop CLCUR  */
#line 179 "SemanticAnalyzer.y"
                                     {printf("\nproper WHILE \n");}
#line 1762 "y.tab.c"
    break;

  case 41: /* whileSuffix: SEMICOLON  */
#line 180 "SemanticAnalyzer.y"
                              {printf("\nWHILE SEMICOLON \n");}
#line 1768 "y.tab.c"
    break;

  case 42: /* whileSuffix: singleLoopStatement  */
#line 181 "SemanticAnalyzer.y"
                                        {printf("\nSINGLE WHILE \n");}
#line 1774 "y.tab.c"
    break;

  case 43: /* inLoop: BREAK SEMICOLON inLoop  */
#line 183 "SemanticAnalyzer.y"
                                    {printf("\n break in loop \n");}
#line 1780 "y.tab.c"
    break;

  case 44: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 184 "SemanticAnalyzer.y"
                                            {printf("\ncontinue in loop \n");}
#line 1786 "y.tab.c"
    break;

  case 45: /* inLoop: specialStatement inLoop  */
#line 185 "SemanticAnalyzer.y"
                                          {printf("\n special statement in loop \n");}
#line 1792 "y.tab.c"
    break;

  case 46: /* inLoop: basicStatement inLoop  */
#line 186 "SemanticAnalyzer.y"
                                        {printf("\n basic statement in loop \n");}
#line 1798 "y.tab.c"
    break;

  case 47: /* inLoop: functionCall inLoop  */
#line 187 "SemanticAnalyzer.y"
                                     {printf("\n basic statement in loop \n");}
#line 1804 "y.tab.c"
    break;

  case 48: /* inLoop: ifInLoopStatement inLoop  */
#line 188 "SemanticAnalyzer.y"
                                           {printf("\n if in loop \n");}
#line 1810 "y.tab.c"
    break;

  case 49: /* inLoop: switchStatement inLoop  */
#line 189 "SemanticAnalyzer.y"
                                         {printf("\n switch in loop \n");}
#line 1816 "y.tab.c"
    break;

  case 50: /* inLoop: singleLoopStatement inLoop  */
#line 190 "SemanticAnalyzer.y"
                                             {printf("\n any other statement in loop \n");}
#line 1822 "y.tab.c"
    break;

  case 62: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR  */
#line 207 "SemanticAnalyzer.y"
                                                                                                  {printf("SWITCH START..\n");}
#line 1828 "y.tab.c"
    break;

  case 64: /* caseStatements: %empty  */
#line 208 "SemanticAnalyzer.y"
                                        {printf("char/int..\n");}
#line 1834 "y.tab.c"
    break;

  case 66: /* caseStatementInt: %empty  */
#line 209 "SemanticAnalyzer.y"
                                                  {printf("INT CASE..\n");}
#line 1840 "y.tab.c"
    break;

  case 67: /* caseInt: CASE OPBRAC INTVAL CLBRAC COLON statements BREAK SEMICOLON  */
#line 210 "SemanticAnalyzer.y"
                                                                         {printf("case (INT) : break; ..\n");}
#line 1846 "y.tab.c"
    break;

  case 68: /* caseInt: CASE OPBRAC INTVAL CLBRAC COLON statements  */
#line 211 "SemanticAnalyzer.y"
                                                             {printf("case (INT) : ..\n");}
#line 1852 "y.tab.c"
    break;

  case 69: /* caseInt: CASE INTVAL COLON statements BREAK SEMICOLON  */
#line 212 "SemanticAnalyzer.y"
                                                               {printf("case INT : BREAK;..\n");}
#line 1858 "y.tab.c"
    break;

  case 70: /* caseInt: CASE INTVAL COLON statements  */
#line 213 "SemanticAnalyzer.y"
                                               {printf("CASE INT : ..\n");}
#line 1864 "y.tab.c"
    break;

  case 71: /* caseInt: CASE OPBRAC CHARVAL CLBRAC COLON statements BREAK SEMICOLON  */
#line 214 "SemanticAnalyzer.y"
                                                                              {printf("case (char) : break; ..\n");}
#line 1870 "y.tab.c"
    break;

  case 72: /* caseInt: CASE OPBRAC CHARVAL CLBRAC COLON statements  */
#line 215 "SemanticAnalyzer.y"
                                                              {printf("case (char) : ..\n");}
#line 1876 "y.tab.c"
    break;

  case 73: /* caseInt: CASE CHARVAL COLON statements BREAK SEMICOLON  */
#line 216 "SemanticAnalyzer.y"
                                                                {printf("case char : BREAK;..\n");}
#line 1882 "y.tab.c"
    break;

  case 74: /* caseInt: CASE CHARVAL COLON statements  */
#line 217 "SemanticAnalyzer.y"
                                                {printf("CASE char : ..\n");}
#line 1888 "y.tab.c"
    break;

  case 76: /* defaultStatement: %empty  */
#line 218 "SemanticAnalyzer.y"
                                                   {printf(" \nDEFAULT : ..\n");}
#line 1894 "y.tab.c"
    break;

  case 79: /* basicStatement: expressionStatement  */
#line 224 "SemanticAnalyzer.y"
                                         {printf("BS->EXPS..\n");}
#line 1900 "y.tab.c"
    break;

  case 80: /* basicStatement: declarationStatement  */
#line 225 "SemanticAnalyzer.y"
                                       {printf("BS->DS..\n");}
#line 1906 "y.tab.c"
    break;

  case 81: /* basicStatement: assignmentStatement  */
#line 226 "SemanticAnalyzer.y"
                                        {printf("Basic->AS..\n");}
#line 1912 "y.tab.c"
    break;

  case 82: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 228 "SemanticAnalyzer.y"
                                                                                         {printf("AS1..\n");}
#line 1918 "y.tab.c"
    break;

  case 83: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 229 "SemanticAnalyzer.y"
                                                                 {printf("AS2..\n");}
#line 1924 "y.tab.c"
    break;

  case 86: /* $@4: %empty  */
#line 233 "SemanticAnalyzer.y"
                                                 {pushNewScope();}
#line 1930 "y.tab.c"
    break;

  case 87: /* declarationStatement: INT IDENTIFIER OPBRAC $@4 parameters CLBRAC compoundStatements  */
#line 233 "SemanticAnalyzer.y"
                                                                                                         {printf("INT F WITH PARAMS..\n");}
#line 1936 "y.tab.c"
    break;

  case 88: /* $@5: %empty  */
#line 234 "SemanticAnalyzer.y"
                                          {pushNewScope();}
#line 1942 "y.tab.c"
    break;

  case 89: /* declarationStatement: CHAR IDENTIFIER OPBRAC $@5 parameters CLBRAC compoundStatements  */
#line 234 "SemanticAnalyzer.y"
                                                                                                  {printf("char F WITH PARAMS..\n");}
#line 1948 "y.tab.c"
    break;

  case 90: /* $@6: %empty  */
#line 235 "SemanticAnalyzer.y"
                                           {pushNewScope();}
#line 1954 "y.tab.c"
    break;

  case 91: /* declarationStatement: FLOAT IDENTIFIER OPBRAC $@6 parameters CLBRAC compoundStatements  */
#line 235 "SemanticAnalyzer.y"
                                                                                                  {printf("float F WITH PARAMS..\n");}
#line 1960 "y.tab.c"
    break;

  case 92: /* $@7: %empty  */
#line 236 "SemanticAnalyzer.y"
                                         {pushNewScope();}
#line 1966 "y.tab.c"
    break;

  case 94: /* $@8: %empty  */
#line 237 "SemanticAnalyzer.y"
                                           {pushNewScope();}
#line 1972 "y.tab.c"
    break;

  case 96: /* $@9: %empty  */
#line 238 "SemanticAnalyzer.y"
                                          {pushNewScope();}
#line 1978 "y.tab.c"
    break;

  case 98: /* declarationStatement: INT declarationListIntFloat SEMICOLON  */
#line 239 "SemanticAnalyzer.y"
                                                        {printf("DS1..\n");}
#line 1984 "y.tab.c"
    break;

  case 111: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListIntFloat  */
#line 251 "SemanticAnalyzer.y"
                                                                                                 {printf("DSL1..\n");}
#line 1990 "y.tab.c"
    break;

  case 113: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement  */
#line 253 "SemanticAnalyzer.y"
                                                       {printf("DSL3..\n");}
#line 1996 "y.tab.c"
    break;

  case 114: /* declarationListIntFloat: IDENTIFIER dimension  */
#line 254 "SemanticAnalyzer.y"
                                        {printf("INTFLOAT ARRAY..\n");}
#line 2002 "y.tab.c"
    break;

  case 115: /* declarationListIntFloat: IDENTIFIER  */
#line 255 "SemanticAnalyzer.y"
                             {printf("DSL4..\n");}
#line 2008 "y.tab.c"
    break;

  case 121: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 263 "SemanticAnalyzer.y"
                                                                          {printf("ES1..\n");}
#line 2014 "y.tab.c"
    break;

  case 122: /* expressionStatement: logicalExpression  */
#line 264 "SemanticAnalyzer.y"
                                    {printf("ES2..\n");}
#line 2020 "y.tab.c"
    break;

  case 123: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 266 "SemanticAnalyzer.y"
                                                                {printf("LE1..\n");}
#line 2026 "y.tab.c"
    break;

  case 124: /* logicalExpression: expression  */
#line 267 "SemanticAnalyzer.y"
                             {printf("LE2..\n");}
#line 2032 "y.tab.c"
    break;

  case 125: /* expression: relationalExpression EQUALS expression  */
#line 269 "SemanticAnalyzer.y"
                                                        {printf("E1..\n");}
#line 2038 "y.tab.c"
    break;

  case 126: /* expression: relationalExpression NOTEQUAL expression  */
#line 270 "SemanticAnalyzer.y"
                                                           {printf("E2..\n");}
#line 2044 "y.tab.c"
    break;

  case 127: /* expression: relationalExpression  */
#line 271 "SemanticAnalyzer.y"
                                       {printf("E3..\n");}
#line 2050 "y.tab.c"
    break;

  case 132: /* relationalExpression: value  */
#line 277 "SemanticAnalyzer.y"
                        {printf("VALUE..\n");}
#line 2056 "y.tab.c"
    break;

  case 133: /* value: term ADD value  */
#line 279 "SemanticAnalyzer.y"
                           {printf("ADD..\n");}
#line 2062 "y.tab.c"
    break;

  case 135: /* value: term  */
#line 281 "SemanticAnalyzer.y"
               {printf("Basic TERM..\n");}
#line 2068 "y.tab.c"
    break;

  case 136: /* term: factor MULT term  */
#line 283 "SemanticAnalyzer.y"
                            {printf("MULT..\n");}
#line 2074 "y.tab.c"
    break;

  case 139: /* term: factor  */
#line 286 "SemanticAnalyzer.y"
                 {printf("Factor..\n");}
#line 2080 "y.tab.c"
    break;

  case 144: /* factor: INTVAL  */
#line 292 "SemanticAnalyzer.y"
                 {printf("INT VALS.. %d\n",yylval);}
#line 2086 "y.tab.c"
    break;

  case 153: /* parameters: parameter COMMA parameters  */
#line 304 "SemanticAnalyzer.y"
                                                         {printf("FUNCTION params\n");}
#line 2092 "y.tab.c"
    break;

  case 154: /* parameter: type IDENTIFIER  */
#line 306 "SemanticAnalyzer.y"
                                {printf("FUNCTION param\n");}
#line 2098 "y.tab.c"
    break;

  case 158: /* compoundStatements: OPCUR statementList CLCUR  */
#line 310 "SemanticAnalyzer.y"
                                                   {popScope();printf("FUNCTION statements\n");}
#line 2104 "y.tab.c"
    break;

  case 168: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 316 "SemanticAnalyzer.y"
                                        {printf("size..\n");}
#line 2110 "y.tab.c"
    break;


#line 2114 "y.tab.c"

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
     
     
