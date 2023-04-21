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
    	int scopeIndex=0;
    	int currIndex=0;
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

				}
    		}
     
    	}
     
     
    

#line 147 "y.tab.c"

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
  YYSYMBOL_singleLoopStatement = 54,       /* singleLoopStatement  */
  YYSYMBOL_forAssignStatement = 55,        /* forAssignStatement  */
  YYSYMBOL_forExpStatement = 56,           /* forExpStatement  */
  YYSYMBOL_forUpdateStatement = 57,        /* forUpdateStatement  */
  YYSYMBOL_whileLoop = 58,                 /* whileLoop  */
  YYSYMBOL_inLoop = 59,                    /* inLoop  */
  YYSYMBOL_ifStatement = 60,               /* ifStatement  */
  YYSYMBOL_ES = 61,                        /* ES  */
  YYSYMBOL_ifInLoopStatement = 62,         /* ifInLoopStatement  */
  YYSYMBOL_ESLoop = 63,                    /* ESLoop  */
  YYSYMBOL_switchStatement = 64,           /* switchStatement  */
  YYSYMBOL_caseStatements = 65,            /* caseStatements  */
  YYSYMBOL_caseStatementInt = 66,          /* caseStatementInt  */
  YYSYMBOL_caseInt = 67,                   /* caseInt  */
  YYSYMBOL_defaultStatement = 68,          /* defaultStatement  */
  YYSYMBOL_basicStatements = 69,           /* basicStatements  */
  YYSYMBOL_basicStatement = 70,            /* basicStatement  */
  YYSYMBOL_assignmentStatement = 71,       /* assignmentStatement  */
  YYSYMBOL_printer = 72,                   /* printer  */
  YYSYMBOL_scanner = 73,                   /* scanner  */
  YYSYMBOL_declarationStatement = 74,      /* declarationStatement  */
  YYSYMBOL_arrayValues = 75,               /* arrayValues  */
  YYSYMBOL_prattributes = 76,              /* prattributes  */
  YYSYMBOL_scattributes = 77,              /* scattributes  */
  YYSYMBOL_declarationListIntFloat = 78,   /* declarationListIntFloat  */
  YYSYMBOL_declarationListChar = 79,       /* declarationListChar  */
  YYSYMBOL_expressionStatement = 80,       /* expressionStatement  */
  YYSYMBOL_logicalExpression = 81,         /* logicalExpression  */
  YYSYMBOL_expression = 82,                /* expression  */
  YYSYMBOL_relationalExpression = 83,      /* relationalExpression  */
  YYSYMBOL_value = 84,                     /* value  */
  YYSYMBOL_term = 85,                      /* term  */
  YYSYMBOL_factor = 86,                    /* factor  */
  YYSYMBOL_functionCall = 87,              /* functionCall  */
  YYSYMBOL_argList = 88,                   /* argList  */
  YYSYMBOL_parameters = 89,                /* parameters  */
  YYSYMBOL_parameter = 90,                 /* parameter  */
  YYSYMBOL_type = 91,                      /* type  */
  YYSYMBOL_compoundStatements = 92,        /* compoundStatements  */
  YYSYMBOL_statementList = 93,             /* statementList  */
  YYSYMBOL_returnDec = 94,                 /* returnDec  */
  YYSYMBOL_dimension = 95                  /* dimension  */
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
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  374

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
       0,    99,    99,   101,   102,   103,   104,   106,   107,   108,
     109,   111,   112,   113,   114,   117,   118,   119,   121,   122,
     123,   124,   125,   126,   127,   129,   130,   131,   132,   133,
     134,   135,   135,   136,   137,   140,   141,   142,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   154,   155,   157,
     158,   159,   161,   162,   164,   165,   166,   168,   169,   169,
     170,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   179,   182,   183,   185,   186,   187,   189,   190,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   208,   208,   209,   209,   210,   210,
     212,   213,   214,   215,   216,   218,   219,   220,   221,   222,
     224,   225,   227,   228,   230,   231,   232,   234,   235,   236,
     237,   238,   240,   241,   242,   244,   245,   246,   247,   249,
     250,   251,   252,   253,   254,   255,   256,   263,   264,   267,
     267,   269,   269,   271,   273,   273,   273,   275,   277,   277,
     277,   277,   277,   277,   277,   279,   279,   283,   285,   286,
     287
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
  "declarationList", "statements", "specialStatement", "forLoop",
  "singleLoopStatement", "forAssignStatement", "forExpStatement",
  "forUpdateStatement", "whileLoop", "inLoop", "ifStatement", "ES",
  "ifInLoopStatement", "ESLoop", "switchStatement", "caseStatements",
  "caseStatementInt", "caseInt", "defaultStatement", "basicStatements",
  "basicStatement", "assignmentStatement", "printer", "scanner",
  "declarationStatement", "arrayValues", "prattributes", "scattributes",
  "declarationListIntFloat", "declarationListChar", "expressionStatement",
  "logicalExpression", "expression", "relationalExpression", "value",
  "term", "factor", "functionCall", "argList", "parameters", "parameter",
  "type", "compoundStatements", "statementList", "returnDec", "dimension", YY_NULLPTR
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

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      96,   -17,    22,    26,    56,   156,  -256,    96,    96,    20,
      12,    29,   153,    48,   155,   198,  -256,  -256,  -256,   135,
      59,   118,   198,  -256,  -256,   139,   164,   128,   136,  -256,
    -256,   194,   148,  -256,   198,   198,   147,  -256,  -256,  -256,
      24,   192,   193,    41,   210,    63,   131,    52,  -256,  -256,
    -256,  -256,   167,   162,   197,   177,    84,   168,   211,    71,
    -256,   167,   195,   112,   200,   246,   167,   202,   207,   232,
    -256,   230,   252,  -256,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,    86,  -256,   167,
     260,  -256,   263,   281,   284,   135,  -256,   167,   303,   215,
     139,  -256,   167,  -256,   289,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,   287,
     297,   298,   300,   301,   -12,   308,   317,    46,    86,  -256,
    -256,  -256,  -256,    86,   146,  -256,    86,    86,  -256,  -256,
      86,   319,  -256,  -256,  -256,   318,   -21,   315,  -256,  -256,
     345,   340,  -256,  -256,   324,   137,   198,    -6,   198,   321,
    -256,   349,   346,   347,   269,  -256,  -256,   223,  -256,  -256,
    -256,  -256,  -256,  -256,   351,   355,   333,   332,  -256,   357,
     336,   165,   350,  -256,   348,   352,   198,  -256,   356,   361,
    -256,   368,   373,   377,  -256,     0,  -256,   353,   385,  -256,
    -256,   366,   224,   370,   367,   369,   392,  -256,   359,   375,
     372,   374,   396,   380,  -256,   198,   401,  -256,  -256,  -256,
     397,   467,   198,   198,   378,  -256,   383,   404,   406,   439,
    -256,  -256,  -256,  -256,  -256,  -256,   394,   368,   415,   390,
     420,  -256,  -256,   345,   400,   467,   467,   467,   240,   257,
     399,   407,   198,  -256,  -256,   426,   429,   439,   439,   410,
     439,   439,   439,   439,    93,   424,  -256,   394,  -256,  -256,
     373,  -256,   110,  -256,  -256,  -256,    -6,  -256,    -6,  -256,
     198,   409,   411,   439,   439,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,   241,   438,   448,   450,   419,  -256,  -256,     4,
    -256,  -256,  -256,  -256,   456,  -256,   439,  -256,   435,  -256,
    -256,   437,   440,   467,   467,   467,  -256,   442,   467,   378,
     441,   439,   457,   460,   451,   459,  -256,   198,   453,  -256,
    -256,   439,   458,   439,   439,   467,   467,   478,   481,   462,
    -256,   275,   469,   470,  -256,  -256,   464,   468,    15,  -256,
    -256,   488,   489,   467,   198,   471,   439,  -256,  -256,   476,
     473,   198,   477,   483,   479,   482,  -256,  -256,   439,   480,
     439,   484,   495,  -256
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     5,   104,
       0,   109,     0,   104,     0,     0,     1,     4,     3,     0,
       0,     0,     0,   103,    87,     0,     0,     0,     0,   108,
      90,     0,     0,    91,     0,     0,   129,   132,   133,   134,
       0,   111,   113,   116,   121,   124,   128,   104,   101,   144,
     146,   145,     0,     0,   141,     0,     0,     0,   102,   109,
     106,     0,     0,     0,     0,   107,     0,     0,     0,     0,
     131,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,    84,     0,
       0,   143,     0,     0,   158,     0,    86,     0,     0,   158,
       0,    85,     0,   130,     0,    77,   110,   112,   114,   115,
     117,   118,   119,   120,   122,   123,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   154,    11,
      13,    12,    14,   154,    73,    76,   154,   154,    75,    74,
     154,     0,   151,    81,   142,     0,     0,     0,   100,    82,
       0,     0,   105,    83,   135,   109,     0,     0,     0,     0,
     156,     0,     0,     0,     0,   149,   148,   129,    72,   152,
     153,   150,   147,   160,     0,    95,     0,     0,    89,     0,
       0,     0,     0,    30,     0,     0,    32,    25,     0,     0,
     155,    97,    99,     0,   140,     0,    93,     0,     0,   159,
      88,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,   137,     0,     0,    94,    92,   136,
       0,    10,     0,     0,     0,    36,     0,     0,     0,    46,
      18,    37,    24,    14,    19,    20,    59,    97,     0,     0,
       0,   139,   138,   157,     0,    10,    10,    10,     0,     0,
       0,     0,     0,    21,    22,     0,     0,    18,    46,     0,
      24,    14,    19,    20,     0,    71,    58,    61,    96,    79,
      99,    80,    51,     7,     8,     9,     0,    26,     0,    28,
       0,     0,     0,    21,    22,    40,    45,    35,    43,    44,
      41,    42,     0,     0,     0,     0,     0,    60,    98,     0,
      48,    47,    27,    29,    34,    16,    46,    17,     0,    38,
      39,     0,     0,    10,    10,    10,    57,     0,    10,     0,
       0,    10,     0,     0,    69,    65,    70,     0,     0,    33,
      15,    10,     0,    10,    10,    10,    10,     0,     0,     0,
      50,    56,    67,    63,    68,    64,     0,     0,     0,    53,
      52,     0,     0,    10,     0,     0,    46,    66,    62,     0,
       0,     0,     0,    51,     0,     0,    55,    49,    46,     0,
      46,     0,    56,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -256,  -256,   296,     7,   -43,  -256,  -198,  -255,  -256,   203,
    -256,  -158,   249,   163,  -204,   152,    94,  -256,   258,  -256,
    -256,   393,   -85,     1,  -256,  -256,    50,   331,   292,   261,
       3,   -22,   -15,   455,   231,   145,   235,   199,  -256,    14,
    -256,   -14,  -256,  -256,   -35,   161,  -256,     2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,   244,   257,   129,   258,   186,   206,   251,
     130,   285,   131,   301,   260,   350,   132,   265,   266,   267,
     296,   133,   262,   135,   136,   137,   138,   176,   211,   213,
      10,    12,   139,    41,    42,    43,    44,    45,    46,   263,
     195,    53,    54,    55,    88,   141,   142,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,     7,   134,    60,   232,   160,    14,    58,     7,     7,
     231,   183,    62,    29,   184,   185,   215,    67,   174,    69,
      70,   302,    48,   303,    34,   175,    96,     9,   317,    24,
      35,   101,    36,    37,    38,    39,    19,   216,     4,   355,
      72,    73,   318,   134,   128,    25,    76,    77,   134,   134,
       8,   134,   134,   356,   143,   134,    20,     8,     8,   106,
      21,    29,   149,    22,    19,    26,    11,   153,    19,    27,
      13,   259,    28,   105,    82,    83,   144,   232,   152,    49,
      50,    51,   164,   307,    31,   128,    71,    25,    32,    15,
     128,    22,    32,   128,   128,    22,    52,   128,   148,    15,
     286,   140,   288,   289,   290,   291,     1,   119,     3,   161,
     120,    32,   121,   122,    28,   123,     1,     2,     3,   124,
     125,   126,    34,   234,    92,   309,   310,    93,    35,   292,
     127,    37,    38,    39,   120,   299,   246,   349,   293,   294,
       4,   182,   140,   188,    84,    85,    86,   140,   320,   194,
     140,   140,    92,    25,   140,    98,    16,    29,   187,    56,
     246,   246,   246,   332,    57,   230,     1,     2,     3,    63,
      30,   207,    33,    26,    64,   290,   291,   181,   245,    47,
      28,    65,    34,    59,    49,    50,    51,    71,    35,    68,
     167,    37,    38,    39,    57,    74,   234,    75,   362,    89,
     241,    61,   245,   245,   245,    87,   202,   248,   249,    94,
     332,    64,   371,    90,    49,    50,    51,    78,    79,    80,
      81,    91,   235,   110,   111,   112,   113,    95,   246,   246,
     246,    66,    97,   246,    34,   247,   333,   282,   230,   102,
      35,    99,    36,    37,    38,    39,   333,    92,   333,   333,
     246,   246,   273,   274,   275,   147,   276,   277,   151,   247,
     247,   247,   100,    71,    92,   304,    15,   220,   246,   103,
     245,   245,   245,   278,   279,   245,   104,   187,   331,   187,
      49,    50,    51,   116,   117,   118,   311,   312,   331,   165,
     331,   331,   245,   245,   166,   235,     4,   169,   170,   347,
     348,   171,   233,    17,    18,    34,   193,   108,   109,   145,
     245,    35,   339,    36,    37,    38,    39,   114,   115,   146,
     324,   325,   326,   261,   147,   328,   150,   247,   247,   247,
     154,   155,   247,   156,   157,   334,   158,   159,   273,   360,
     274,   275,   342,   343,   162,   334,   365,   334,   334,   247,
     247,   261,   261,   163,   261,   261,   261,   261,   172,   173,
     359,   177,   178,   179,   180,   189,   190,   247,   196,   191,
     192,   197,   198,   199,   200,   233,   225,   261,   261,     1,
       2,     3,   201,   226,   210,   121,   122,   203,   123,   212,
     227,   228,   204,   208,   214,    34,   205,   229,   209,   175,
     261,    35,   218,   127,    37,    38,    39,   219,   221,   224,
     222,   238,   223,   236,   239,   261,   237,   240,   242,   252,
     243,   253,   250,   254,   264,   261,   305,   261,   261,     1,
       2,     3,   269,   226,   270,   121,   122,   271,   123,   272,
     227,   228,   280,   283,   281,    34,   284,   306,   308,   287,
     261,    35,   295,   127,    37,    38,    39,   313,   316,     1,
       2,     3,   261,   226,   261,   121,   122,   314,   123,   315,
     255,   256,   319,   321,   322,    34,   335,   323,   327,   336,
     330,    35,   337,   127,    37,    38,    39,     1,     2,     3,
     338,   120,   340,   121,   122,   344,   123,   341,   345,   346,
     351,   352,   353,    34,   354,   357,   358,   361,   299,    35,
     364,   127,    37,    38,    39,   363,   366,   368,   370,   369,
     348,   300,   329,   372,   373,   297,   367,   168,   217,   268,
     107,   298
};

static const yytype_int16 yycheck[] =
{
      15,     0,    87,    25,   208,    17,     3,    22,     7,     8,
     208,    17,    26,    11,    20,    21,    16,    31,    39,    34,
      35,   276,    19,   278,    36,    46,    61,    44,    24,    17,
      42,    66,    44,    45,    46,    47,    16,    37,    44,    24,
      16,    17,    38,   128,    87,    16,     5,     6,   133,   134,
       0,   136,   137,    38,    89,   140,    36,     7,     8,    74,
      40,    59,    97,    43,    16,    36,    44,   102,    16,    40,
      44,   229,    43,    72,    11,    12,    90,   281,   100,    20,
      21,    22,    36,   281,    36,   128,    40,    16,    40,    43,
     133,    43,    40,   136,   137,    43,    37,   140,    95,    43,
     258,    87,   260,   261,   262,   263,    20,    21,    22,   124,
      24,    40,    26,    27,    43,    29,    20,    21,    22,    33,
      34,    35,    36,   208,    40,   283,   284,    43,    42,    36,
      44,    45,    46,    47,    24,    25,   221,   341,    45,    46,
      44,   156,   128,   158,    13,    14,    15,   133,   306,   164,
     136,   137,    40,    16,   140,    43,     0,   155,   157,    41,
     245,   246,   247,   321,    46,   208,    20,    21,    22,    41,
      17,   186,    17,    36,    46,   333,   334,    40,   221,    44,
      43,    45,    36,    44,    20,    21,    22,    40,    42,    41,
      44,    45,    46,    47,    46,     3,   281,     4,   356,    37,
     215,    37,   245,   246,   247,    38,    41,   222,   223,    41,
     368,    46,   370,    16,    20,    21,    22,     7,     8,     9,
      10,    44,   208,    78,    79,    80,    81,    16,   313,   314,
     315,    37,    37,   318,    36,   221,   321,   252,   281,    37,
      42,    41,    44,    45,    46,    47,   331,    40,   333,   334,
     335,   336,   245,   246,   247,    40,    16,    17,    43,   245,
     246,   247,    16,    40,    40,   280,    43,    43,   353,    37,
     313,   314,   315,    16,    17,   318,    46,   276,   321,   278,
      20,    21,    22,    84,    85,    86,    45,    46,   331,   128,
     333,   334,   335,   336,   133,   281,    44,   136,   137,    24,
      25,   140,   208,     7,     8,    36,    37,    76,    77,    46,
     353,    42,   327,    44,    45,    46,    47,    82,    83,    38,
     313,   314,   315,   229,    40,   318,    23,   313,   314,   315,
      41,    44,   318,    36,    36,   321,    36,    36,   331,   354,
     333,   334,   335,   336,    36,   331,   361,   333,   334,   335,
     336,   257,   258,    36,   260,   261,   262,   263,    39,    41,
     353,    46,    17,    23,    40,    44,    17,   353,    17,    23,
      23,    16,    39,    41,    17,   281,    17,   283,   284,    20,
      21,    22,    46,    24,    16,    26,    27,    37,    29,    16,
      31,    32,    44,    37,    17,    36,    44,    38,    37,    46,
     306,    42,    17,    44,    45,    46,    47,    41,    38,    17,
      43,    37,    43,    38,    18,   321,    44,    37,    17,    36,
      23,    17,    44,    17,    30,   331,    17,   333,   334,    20,
      21,    22,    17,    24,    44,    26,    27,    17,    29,    39,
      31,    32,    43,    17,    37,    36,    17,    38,    37,    39,
     356,    42,    28,    44,    45,    46,    47,    19,    39,    20,
      21,    22,   368,    24,   370,    26,    27,    19,    29,    19,
      31,    32,    16,    38,    37,    36,    19,    37,    36,    19,
      39,    42,    31,    44,    45,    46,    47,    20,    21,    22,
      31,    24,    39,    26,    27,    17,    29,    39,    17,    37,
      31,    31,    38,    36,    36,    17,    17,    36,    25,    42,
      37,    44,    45,    46,    47,    39,    39,    38,    38,    37,
      25,   272,   319,    39,   372,   267,   363,   134,   197,   237,
      75,   270
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,    21,    22,    44,    49,    50,    71,    74,    44,
      78,    44,    79,    44,    78,    43,     0,    50,    50,    16,
      36,    40,    43,    95,    17,    16,    36,    40,    43,    95,
      17,    36,    40,    17,    36,    42,    44,    45,    46,    47,
      80,    81,    82,    83,    84,    85,    86,    44,    78,    20,
      21,    22,    37,    89,    90,    91,    41,    46,    80,    44,
      79,    37,    89,    41,    46,    45,    37,    89,    41,    80,
      80,    40,    16,    17,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    38,    92,    37,
      16,    44,    40,    43,    41,    16,    92,    37,    43,    41,
      16,    92,    37,    37,    46,    71,    80,    81,    82,    82,
      83,    83,    83,    83,    84,    84,    85,    85,    85,    21,
      24,    26,    27,    29,    33,    34,    35,    44,    52,    53,
      58,    60,    64,    69,    70,    71,    72,    73,    74,    80,
      87,    93,    94,    92,    89,    46,    38,    40,    78,    92,
      23,    43,    79,    92,    41,    44,    36,    36,    36,    36,
      17,    80,    36,    36,    36,    93,    93,    44,    69,    93,
      93,    93,    39,    41,    39,    46,    75,    46,    17,    23,
      40,    40,    80,    17,    20,    21,    55,    71,    80,    44,
      17,    23,    23,    37,    80,    88,    17,    16,    39,    41,
      17,    46,    41,    37,    44,    44,    56,    80,    37,    37,
      16,    76,    16,    77,    17,    16,    37,    75,    17,    41,
      43,    38,    43,    43,    17,    17,    24,    31,    32,    38,
      52,    54,    62,    64,    70,    87,    38,    44,    37,    18,
      37,    80,    17,    23,    51,    52,    70,    87,    80,    80,
      44,    57,    36,    17,    17,    31,    32,    52,    54,    59,
      62,    64,    70,    87,    30,    65,    66,    67,    76,    17,
      44,    17,    39,    51,    51,    51,    16,    17,    16,    17,
      43,    37,    80,    17,    17,    59,    59,    39,    59,    59,
      59,    59,    36,    45,    46,    28,    68,    66,    77,    25,
      60,    61,    55,    55,    80,    17,    38,    54,    37,    59,
      59,    45,    46,    19,    19,    19,    39,    24,    38,    16,
      59,    38,    37,    37,    51,    51,    51,    36,    51,    57,
      39,    52,    59,    70,    87,    19,    19,    31,    31,    80,
      39,    39,    51,    51,    17,    17,    37,    24,    25,    62,
      63,    31,    31,    38,    36,    24,    38,    17,    17,    51,
      80,    36,    59,    39,    37,    80,    39,    61,    38,    37,
      38,    59,    39,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    50,    51,    51,    51,
      51,    52,    52,    52,    52,    53,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    56,    56,    57,    57,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    61,
      61,    61,    62,    62,    63,    63,    63,    64,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    70,    71,    71,    72,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    79,    79,    79,    79,    79,
      80,    80,    81,    81,    82,    82,    82,    83,    83,    83,
      83,    83,    84,    84,    84,    85,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    91,    91,    91,    92,    93,    93,
      93,    93,    93,    93,    93,    94,    94,    94,    95,    95,
      95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     2,     2,     2,
       0,     1,     1,     1,     1,    10,     8,     8,     1,     1,
       1,     2,     2,     1,     1,     1,     5,     6,     5,     6,
       1,     1,     0,     5,     3,     7,     5,     5,     3,     3,
       2,     2,     2,     2,     2,     2,     0,     8,     8,     9,
       4,     0,     8,     8,     9,     4,     0,     8,     1,     0,
       2,     0,     8,     6,     6,     4,     8,     6,     6,     4,
       3,     0,     2,     1,     1,     1,     1,     5,     4,     6,
       6,     6,     6,     6,     5,     5,     5,     3,     8,     7,
       3,     3,     9,     8,     3,     1,     3,     0,     4,     0,
       5,     3,     3,     2,     1,     5,     3,     3,     2,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     1,
       3,     2,     1,     1,     1,     4,     7,     4,     5,     3,
       1,     1,     3,     2,     1,     1,     1,     3,     2,     2,
       2,     1,     2,     2,     0,     3,     2,     6,     3,     6,
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
#line 99 "SemanticAnalyzer.y"
                           {printf("Starting..\n");}
#line 1644 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 101 "SemanticAnalyzer.y"
                                                            {printf("RECURSIVE DECLARATION \n");}
#line 1650 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 103 "SemanticAnalyzer.y"
                                                        {printf("DECLARATION \n");}
#line 1656 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 106 "SemanticAnalyzer.y"
                                             {printf("Special..\n");}
#line 1662 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 107 "SemanticAnalyzer.y"
                                               {printf("Basic123..\n");}
#line 1668 "y.tab.c"
    break;

  case 15: /* forLoop: FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR inLoop CLCUR  */
#line 117 "SemanticAnalyzer.y"
                                                                                                                   {printf("\nproper FOR \n");}
#line 1674 "y.tab.c"
    break;

  case 16: /* forLoop: FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON  */
#line 118 "SemanticAnalyzer.y"
                                                                                                              {printf("\nFOR SEMICOLON \n");}
#line 1680 "y.tab.c"
    break;

  case 17: /* forLoop: FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC singleLoopStatement  */
#line 119 "SemanticAnalyzer.y"
                                                                                                                        {printf("\nFOR SINGLE STATEMENT \n");}
#line 1686 "y.tab.c"
    break;

  case 35: /* whileLoop: WHILE OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR  */
#line 140 "SemanticAnalyzer.y"
                                                                           {printf("\nproper WHILE \n");}
#line 1692 "y.tab.c"
    break;

  case 36: /* whileLoop: WHILE OPBRAC expressionStatement CLBRAC SEMICOLON  */
#line 141 "SemanticAnalyzer.y"
                                                                      {printf("\nWHILE SEMICOLON \n");}
#line 1698 "y.tab.c"
    break;

  case 37: /* whileLoop: WHILE OPBRAC expressionStatement CLBRAC singleLoopStatement  */
#line 142 "SemanticAnalyzer.y"
                                                                                {printf("\nSINGLE WHILE \n");}
#line 1704 "y.tab.c"
    break;

  case 38: /* inLoop: BREAK SEMICOLON inLoop  */
#line 144 "SemanticAnalyzer.y"
                                    {printf("\n break in loop \n");}
#line 1710 "y.tab.c"
    break;

  case 39: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 145 "SemanticAnalyzer.y"
                                            {printf("\ncontinue in loop \n");}
#line 1716 "y.tab.c"
    break;

  case 40: /* inLoop: specialStatement inLoop  */
#line 146 "SemanticAnalyzer.y"
                                          {printf("\n special statement in loop \n");}
#line 1722 "y.tab.c"
    break;

  case 41: /* inLoop: basicStatement inLoop  */
#line 147 "SemanticAnalyzer.y"
                                        {printf("\n basic statement in loop \n");}
#line 1728 "y.tab.c"
    break;

  case 42: /* inLoop: functionCall inLoop  */
#line 148 "SemanticAnalyzer.y"
                                     {printf("\n basic statement in loop \n");}
#line 1734 "y.tab.c"
    break;

  case 43: /* inLoop: ifInLoopStatement inLoop  */
#line 149 "SemanticAnalyzer.y"
                                           {printf("\n if in loop \n");}
#line 1740 "y.tab.c"
    break;

  case 44: /* inLoop: switchStatement inLoop  */
#line 150 "SemanticAnalyzer.y"
                                         {printf("\n switch in loop \n");}
#line 1746 "y.tab.c"
    break;

  case 45: /* inLoop: singleLoopStatement inLoop  */
#line 151 "SemanticAnalyzer.y"
                                             {printf("\n any other statement in loop \n");}
#line 1752 "y.tab.c"
    break;

  case 57: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR  */
#line 168 "SemanticAnalyzer.y"
                                                                                                  {printf("SWITCH START..\n");}
#line 1758 "y.tab.c"
    break;

  case 59: /* caseStatements: %empty  */
#line 169 "SemanticAnalyzer.y"
                                        {printf("char/int..\n");}
#line 1764 "y.tab.c"
    break;

  case 61: /* caseStatementInt: %empty  */
#line 170 "SemanticAnalyzer.y"
                                                  {printf("INT CASE..\n");}
#line 1770 "y.tab.c"
    break;

  case 62: /* caseInt: CASE OPBRAC INTVAL CLBRAC COLON statements BREAK SEMICOLON  */
#line 171 "SemanticAnalyzer.y"
                                                                         {printf("case (INT) : break; ..\n");}
#line 1776 "y.tab.c"
    break;

  case 63: /* caseInt: CASE OPBRAC INTVAL CLBRAC COLON statements  */
#line 172 "SemanticAnalyzer.y"
                                                             {printf("case (INT) : ..\n");}
#line 1782 "y.tab.c"
    break;

  case 64: /* caseInt: CASE INTVAL COLON statements BREAK SEMICOLON  */
#line 173 "SemanticAnalyzer.y"
                                                               {printf("case INT : BREAK;..\n");}
#line 1788 "y.tab.c"
    break;

  case 65: /* caseInt: CASE INTVAL COLON statements  */
#line 174 "SemanticAnalyzer.y"
                                               {printf("CASE INT : ..\n");}
#line 1794 "y.tab.c"
    break;

  case 66: /* caseInt: CASE OPBRAC CHARVAL CLBRAC COLON statements BREAK SEMICOLON  */
#line 175 "SemanticAnalyzer.y"
                                                                              {printf("case (char) : break; ..\n");}
#line 1800 "y.tab.c"
    break;

  case 67: /* caseInt: CASE OPBRAC CHARVAL CLBRAC COLON statements  */
#line 176 "SemanticAnalyzer.y"
                                                              {printf("case (char) : ..\n");}
#line 1806 "y.tab.c"
    break;

  case 68: /* caseInt: CASE CHARVAL COLON statements BREAK SEMICOLON  */
#line 177 "SemanticAnalyzer.y"
                                                                {printf("case char : BREAK;..\n");}
#line 1812 "y.tab.c"
    break;

  case 69: /* caseInt: CASE CHARVAL COLON statements  */
#line 178 "SemanticAnalyzer.y"
                                                {printf("CASE char : ..\n");}
#line 1818 "y.tab.c"
    break;

  case 71: /* defaultStatement: %empty  */
#line 179 "SemanticAnalyzer.y"
                                                   {printf(" \nDEFAULT : ..\n");}
#line 1824 "y.tab.c"
    break;

  case 74: /* basicStatement: expressionStatement  */
#line 185 "SemanticAnalyzer.y"
                                         {printf("BS->EXPS..\n");}
#line 1830 "y.tab.c"
    break;

  case 75: /* basicStatement: declarationStatement  */
#line 186 "SemanticAnalyzer.y"
                                       {printf("BS->DS..\n");}
#line 1836 "y.tab.c"
    break;

  case 76: /* basicStatement: assignmentStatement  */
#line 187 "SemanticAnalyzer.y"
                                        {printf("Basic->AS..\n");}
#line 1842 "y.tab.c"
    break;

  case 77: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 189 "SemanticAnalyzer.y"
                                                                                         {printf("AS1..\n");}
#line 1848 "y.tab.c"
    break;

  case 78: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 190 "SemanticAnalyzer.y"
                                                                 {printf("AS2..\n");}
#line 1854 "y.tab.c"
    break;

  case 81: /* declarationStatement: INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 194 "SemanticAnalyzer.y"
                                                                                       {printf("INT F WITH PARAMS..\n");}
#line 1860 "y.tab.c"
    break;

  case 82: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 195 "SemanticAnalyzer.y"
                                                                              {printf("char F WITH PARAMS..\n");}
#line 1866 "y.tab.c"
    break;

  case 83: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 196 "SemanticAnalyzer.y"
                                                                               {printf("float F WITH PARAMS..\n");}
#line 1872 "y.tab.c"
    break;

  case 87: /* declarationStatement: INT declarationListIntFloat SEMICOLON  */
#line 200 "SemanticAnalyzer.y"
                                                        {printf("DS1..\n");}
#line 1878 "y.tab.c"
    break;

  case 100: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListIntFloat  */
#line 212 "SemanticAnalyzer.y"
                                                                                                 {printf("DSL1..\n");}
#line 1884 "y.tab.c"
    break;

  case 102: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement  */
#line 214 "SemanticAnalyzer.y"
                                                       {printf("DSL3..\n");}
#line 1890 "y.tab.c"
    break;

  case 103: /* declarationListIntFloat: IDENTIFIER dimension  */
#line 215 "SemanticAnalyzer.y"
                                        {printf("INTFLOAT ARRAY..\n");}
#line 1896 "y.tab.c"
    break;

  case 104: /* declarationListIntFloat: IDENTIFIER  */
#line 216 "SemanticAnalyzer.y"
                             {printf("DSL4..\n");}
#line 1902 "y.tab.c"
    break;

  case 110: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 224 "SemanticAnalyzer.y"
                                                                          {printf("ES1..\n");}
#line 1908 "y.tab.c"
    break;

  case 111: /* expressionStatement: logicalExpression  */
#line 225 "SemanticAnalyzer.y"
                                    {printf("ES2..\n");}
#line 1914 "y.tab.c"
    break;

  case 112: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 227 "SemanticAnalyzer.y"
                                                                {printf("LE1..\n");}
#line 1920 "y.tab.c"
    break;

  case 113: /* logicalExpression: expression  */
#line 228 "SemanticAnalyzer.y"
                             {printf("LE2..\n");}
#line 1926 "y.tab.c"
    break;

  case 114: /* expression: relationalExpression EQUALS expression  */
#line 230 "SemanticAnalyzer.y"
                                                        {printf("E1..\n");}
#line 1932 "y.tab.c"
    break;

  case 115: /* expression: relationalExpression NOTEQUAL expression  */
#line 231 "SemanticAnalyzer.y"
                                                           {printf("E2..\n");}
#line 1938 "y.tab.c"
    break;

  case 116: /* expression: relationalExpression  */
#line 232 "SemanticAnalyzer.y"
                                       {printf("E3..\n");}
#line 1944 "y.tab.c"
    break;

  case 121: /* relationalExpression: value  */
#line 238 "SemanticAnalyzer.y"
                        {printf("VALUE..\n");}
#line 1950 "y.tab.c"
    break;

  case 122: /* value: term ADD value  */
#line 240 "SemanticAnalyzer.y"
                           {printf("ADD..\n");}
#line 1956 "y.tab.c"
    break;

  case 124: /* value: term  */
#line 242 "SemanticAnalyzer.y"
               {printf("Basic TERM..\n");}
#line 1962 "y.tab.c"
    break;

  case 125: /* term: factor MULT term  */
#line 244 "SemanticAnalyzer.y"
                            {printf("MULT..\n");}
#line 1968 "y.tab.c"
    break;

  case 128: /* term: factor  */
#line 247 "SemanticAnalyzer.y"
                 {printf("Factor..\n");}
#line 1974 "y.tab.c"
    break;

  case 133: /* factor: INTVAL  */
#line 253 "SemanticAnalyzer.y"
                 {printf("INT VALS.. %d\n",yylval);}
#line 1980 "y.tab.c"
    break;

  case 142: /* parameters: parameter COMMA parameters  */
#line 269 "SemanticAnalyzer.y"
                                                         {printf("FUNCTION params\n");}
#line 1986 "y.tab.c"
    break;

  case 143: /* parameter: type IDENTIFIER  */
#line 271 "SemanticAnalyzer.y"
                                {printf("FUNCTION param\n");}
#line 1992 "y.tab.c"
    break;

  case 147: /* compoundStatements: OPCUR statementList CLCUR  */
#line 275 "SemanticAnalyzer.y"
                                                   {printf("FUNCTION statements\n");}
#line 1998 "y.tab.c"
    break;

  case 158: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 285 "SemanticAnalyzer.y"
                                        {printf("size..\n");}
#line 2004 "y.tab.c"
    break;


#line 2008 "y.tab.c"

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

#line 288 "SemanticAnalyzer.y"

     
    #include "lex.yy.c"
    int main(){
    	yyin = fopen("./Test Cases/input.txt","r");
    	if(!yyparse())
    	{
    		printf("Parsing Done\n");
    	}
    	else 
    		printf("Failed\n");
    	exit(0);
    }
     
     
