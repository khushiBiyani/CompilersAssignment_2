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
 

#line 88 "y.tab.c"

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
#line 17 "AST.y"

		int Int;
		float Float;
		char Char;
		char* Str;
		struct data{
 
		};
	

#line 246 "y.tab.c"

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
  YYSYMBOL_forLoop = 54,                   /* forLoop  */
  YYSYMBOL_forLoop1 = 55,                  /* forLoop1  */
  YYSYMBOL_forLoop2 = 56,                  /* forLoop2  */
  YYSYMBOL_forLoop3 = 57,                  /* forLoop3  */
  YYSYMBOL_singleLoopStatement = 58,       /* singleLoopStatement  */
  YYSYMBOL_forAssignStatement = 59,        /* forAssignStatement  */
  YYSYMBOL_forExpStatement = 60,           /* forExpStatement  */
  YYSYMBOL_forUpdateStatement = 61,        /* forUpdateStatement  */
  YYSYMBOL_whileLoop = 62,                 /* whileLoop  */
  YYSYMBOL_whileSuffix = 63,               /* whileSuffix  */
  YYSYMBOL_inLoop = 64,                    /* inLoop  */
  YYSYMBOL_ifStatement = 65,               /* ifStatement  */
  YYSYMBOL_ifContinuer = 66,               /* ifContinuer  */
  YYSYMBOL_ES = 67,                        /* ES  */
  YYSYMBOL_ifInLoopStatement = 68,         /* ifInLoopStatement  */
  YYSYMBOL_ifInLoopContinuer = 69,         /* ifInLoopContinuer  */
  YYSYMBOL_ESLoop = 70,                    /* ESLoop  */
  YYSYMBOL_switchStatement = 71,           /* switchStatement  */
  YYSYMBOL_caseStatements = 72,            /* caseStatements  */
  YYSYMBOL_caseStatementInt = 73,          /* caseStatementInt  */
  YYSYMBOL_caseInt = 74,                   /* caseInt  */
  YYSYMBOL_caseContinuer = 75,             /* caseContinuer  */
  YYSYMBOL_defaultStatement = 76,          /* defaultStatement  */
  YYSYMBOL_basicStatements = 77,           /* basicStatements  */
  YYSYMBOL_basicStatement = 78,            /* basicStatement  */
  YYSYMBOL_assignmentStatement = 79,       /* assignmentStatement  */
  YYSYMBOL_printer = 80,                   /* printer  */
  YYSYMBOL_Scanner = 81,                   /* Scanner  */
  YYSYMBOL_declarationStatement = 82,      /* declarationStatement  */
  YYSYMBOL_arrayValuesF = 83,              /* arrayValuesF  */
  YYSYMBOL_arrayValues = 84,               /* arrayValues  */
  YYSYMBOL_prattributes = 85,              /* prattributes  */
  YYSYMBOL_scattributes = 86,              /* scattributes  */
  YYSYMBOL_declarationListInt = 87,        /* declarationListInt  */
  YYSYMBOL_declarationListFloat = 88,      /* declarationListFloat  */
  YYSYMBOL_declarationListChar = 89,       /* declarationListChar  */
  YYSYMBOL_expressionStatement = 90,       /* expressionStatement  */
  YYSYMBOL_logicalExpression = 91,         /* logicalExpression  */
  YYSYMBOL_expression = 92,                /* expression  */
  YYSYMBOL_relationalExpression = 93,      /* relationalExpression  */
  YYSYMBOL_value = 94,                     /* value  */
  YYSYMBOL_term = 95,                      /* term  */
  YYSYMBOL_factor = 96,                    /* factor  */
  YYSYMBOL_functionCall = 97,              /* functionCall  */
  YYSYMBOL_argList = 98,                   /* argList  */
  YYSYMBOL_parameters = 99,                /* parameters  */
  YYSYMBOL_paramContinuer = 100,           /* paramContinuer  */
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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   803

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  191
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
       0,    61,    61,    63,    64,    65,    66,    68,    69,    70,
      71,    72,    73,    74,    76,    77,    78,    79,    81,    82,
      83,    86,    87,    88,    90,    91,    92,    93,    94,    95,
      96,    97,    99,   100,   101,   102,   103,   104,   106,   107,
     109,   110,   112,   114,   115,   116,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   131,   132,
     134,   135,   137,   138,   139,   140,   140,   142,   142,   142,
     144,   145,   146,   147,   147,   149,   151,   152,   154,   155,
     157,   158,   159,   160,   162,   163,   165,   166,   169,   170,
     171,   173,   174,   175,   175,   177,   178,   178,   179,   181,
     182,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   196,   197,   200,   201,   203,   204,
     206,   207,   209,   210,   212,   213,   214,   215,   216,   218,
     219,   220,   221,   222,   224,   225,   226,   227,   228,   230,
     231,   233,   234,   236,   237,   238,   240,   241,   242,   243,
     244,   246,   247,   248,   250,   251,   252,   253,   255,   256,
     257,   258,   259,   260,   260,   260,   261,   262,   265,   266,
     269,   270,   272,   273,   274,   276,   278,   279,   280,   282,
     284,   285,   286,   287,   288,   289,   290,   292,   293,   295,
     296,   297
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
  "forLoop", "forLoop1", "forLoop2", "forLoop3", "singleLoopStatement",
  "forAssignStatement", "forExpStatement", "forUpdateStatement",
  "whileLoop", "whileSuffix", "inLoop", "ifStatement", "ifContinuer", "ES",
  "ifInLoopStatement", "ifInLoopContinuer", "ESLoop", "switchStatement",
  "caseStatements", "caseStatementInt", "caseInt", "caseContinuer",
  "defaultStatement", "basicStatements", "basicStatement",
  "assignmentStatement", "printer", "Scanner", "declarationStatement",
  "arrayValuesF", "arrayValues", "prattributes", "scattributes",
  "declarationListInt", "declarationListFloat", "declarationListChar",
  "expressionStatement", "logicalExpression", "expression",
  "relationalExpression", "value", "term", "factor", "functionCall",
  "argList", "parameters", "paramContinuer", "parameter", "type",
  "compoundStatements", "statementList", "returnDec", "dimension", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-381)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-191)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,   -11,    14,    19,   124,   140,  -381,    21,    21,    85,
      58,   110,    65,   115,   107,    47,   749,   102,  -381,  -381,
    -381,   105,   159,    82,   749,  -381,  -381,   125,   197,    88,
     756,  -381,  -381,   127,   237,   149,   749,  -381,  -381,   122,
     106,   749,   749,  -381,  -381,  -381,   225,   166,   202,   210,
     258,   298,   282,   100,   749,     6,  -381,  -381,  -381,  -381,
     169,   179,  -381,   208,   182,   203,   220,   101,  -381,   169,
     212,   241,   275,   262,  -381,   120,  -381,   169,   249,   255,
     305,   284,   302,   314,  -381,   367,   313,   316,  -381,   749,
     749,   749,   749,   749,   749,   749,   749,   749,   749,   749,
     749,   749,   283,   590,  -381,   169,   250,  -381,   327,   105,
    -381,   169,   349,   271,   125,  -381,   169,   338,   127,   342,
     347,  -381,  -381,   389,   369,   366,  -381,  -381,  -381,  -381,
    -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,
     316,  -381,   372,   374,   380,   381,   153,   382,   383,   240,
     590,  -381,  -381,  -381,   590,   461,  -381,   590,   590,  -381,
    -381,   590,   388,  -381,  -381,  -381,   -33,  -381,  -381,   412,
     407,  -381,  -381,    -9,  -381,  -381,   390,   749,  -381,   392,
    -381,   749,     7,  -381,  -381,  -381,  -381,   749,   386,  -381,
     417,   413,   414,   742,   232,  -381,  -381,  -381,  -381,  -381,
    -381,  -381,  -381,  -381,   422,   428,   408,  -381,   429,   431,
     433,   411,  -381,  -381,   406,   416,  -381,   409,   410,   749,
    -381,   418,   432,  -381,  -381,   443,   451,   436,   434,  -381,
     425,   457,  -381,  -381,   430,   467,   437,   618,   442,   444,
     469,  -381,   335,   450,    15,   473,   455,  -381,   478,   272,
    -381,  -381,  -381,  -381,  -381,   730,   323,  -381,  -381,  -381,
     749,   749,   449,  -381,   462,   482,   484,   206,  -381,  -381,
    -381,  -381,  -381,  -381,  -381,  -381,   472,   749,   487,   465,
     496,  -381,   470,   475,   730,   730,   730,   646,  -381,  -381,
    -381,   333,   501,   476,   481,   749,  -381,  -381,   504,   505,
     206,   206,   489,   206,   206,   206,   206,   206,   206,   206,
      74,   498,  -381,   472,  -381,  -381,   443,  -381,   492,   323,
    -381,  -381,  -381,   502,   730,  -381,     7,  -381,     7,   749,
     503,   500,   206,   206,  -381,  -381,  -381,  -381,  -381,  -381,
    -381,  -381,  -381,  -381,   325,   521,   523,   527,   512,  -381,
    -381,   509,  -381,   749,   514,  -381,  -381,   541,  -381,   206,
    -381,   674,  -381,  -381,   522,   525,   730,   730,   730,  -381,
     531,  -381,   449,   530,   206,   552,   555,   546,  -381,  -381,
    -381,   702,  -381,  -381,   206,   548,   206,   206,   730,   730,
     568,   730,   323,   350,  -381,  -381,  -381,   551,  -381,   556,
     534,  -381,  -381,  -381,   323,   749,   560,   206,  -381,  -381,
     564,   749,   558,   561,   565,  -381,   206,   562,   206,  -381,
     578,  -381,  -381,   566,  -381,   350,  -381
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     5,   128,
       0,   138,     0,   133,     0,     0,     0,     0,     1,     4,
       3,     0,     0,     0,     0,   127,   107,     0,     0,     0,
       0,   137,   110,     0,     0,     0,     0,   132,   111,     0,
       0,     0,     0,   161,   162,   163,   158,     0,   140,   142,
     145,   150,   153,   157,     0,   128,   125,   176,   178,   177,
       0,     0,   172,   173,     0,     0,   126,   138,   135,     0,
       0,     0,     0,   161,   136,   133,   130,     0,     0,     0,
     131,     0,   189,     0,   160,     0,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,   104,     0,     0,   175,     0,     0,
     106,     0,     0,   189,     0,   105,     0,     0,     0,     0,
       0,   159,   164,   171,     0,     0,    95,   139,   141,   143,
     144,   146,   147,   148,   149,   151,   152,   154,   155,   156,
       0,    98,     0,     0,     0,     0,     0,     0,     0,   158,
     186,    16,    15,    17,   186,    89,    93,   186,   186,    92,
      91,    94,     0,    90,   101,   174,     0,   124,   102,     0,
       0,   134,   103,     0,   129,   191,     0,     0,   165,   166,
      97,     0,     0,    14,    20,    18,    19,     0,     0,   188,
       0,     0,     0,     0,     0,   182,   181,    88,    94,    90,
     184,   185,   180,   179,     0,   119,     0,   109,     0,     0,
     117,     0,   190,   170,     0,     0,    36,     0,     0,    39,
      32,     0,     0,   187,   121,   123,   164,     0,     0,   113,
       0,     0,   108,   115,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,     0,   168,   165,   166,
     118,   112,   116,   114,   167,    10,    66,    11,    12,    13,
       0,     0,     0,    44,     0,     0,     0,    57,    24,    45,
      42,    30,    17,    25,    26,    31,    77,     0,     0,     0,
       0,   169,     0,     0,    10,    10,    10,     0,    61,    59,
      60,     0,     0,     0,     0,     0,    27,    28,     0,     0,
      24,    57,     0,    30,    17,    25,    57,    57,    26,    31,
       0,    87,    76,    79,   120,    99,   123,   100,     0,    66,
       7,     8,     9,     0,    10,    65,     0,    33,     0,     0,
       0,     0,    27,    28,    48,    53,    43,    51,    52,    49,
      54,    55,    50,    56,     0,     0,     0,     0,     0,    78,
     122,   167,    58,     0,     0,    34,    35,    41,    21,    57,
      23,     0,    46,    47,     0,     0,    10,    10,    10,    75,
       0,    63,     0,     0,    10,     0,     0,    85,    83,    81,
      86,     0,    40,    22,    10,     0,    10,    10,    10,    10,
       0,    10,    66,    74,    82,    80,    84,     0,    60,     0,
       0,    69,    67,    68,    66,     0,     0,    57,    73,    60,
       0,     0,     0,     0,     0,    71,    57,     0,    10,    11,
      74,    12,    13,     0,    72,    74,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -381,  -381,   378,  -252,  -282,    54,  -381,  -381,  -381,  -381,
    -225,  -278,  -381,   243,  -381,  -381,   157,  -255,  -308,  -357,
    -224,  -381,  -380,    93,  -381,   300,  -381,  -310,  -381,   463,
     -99,     2,   -87,   -50,   247,   387,   397,  -381,   304,   -14,
     -20,   -12,   -16,   532,   296,   238,   293,   245,   351,   -64,
    -133,    75,   524,  -381,  -381,    43,    52,   -74,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,   377,   256,   300,   183,   184,   185,   186,
     301,   219,   240,   294,   151,   270,   334,   152,   289,   290,
     303,   402,   403,   153,   311,   312,   313,   378,   348,   154,
     305,   156,   306,   307,   159,   211,   206,   244,   246,    10,
      14,    12,   160,    48,    49,    50,    51,    52,    53,   308,
     124,    61,    62,    63,    64,   104,   162,   309,    17
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,   288,     7,   283,   155,   325,   204,    56,    66,     7,
       7,   352,   205,    76,    74,    68,   157,   269,   271,    25,
      80,    31,    21,    37,   216,    83,    84,   217,   218,   163,
     209,   277,   320,   321,   322,   398,     9,   210,   102,   161,
     424,     1,     2,     3,   213,   426,    15,   409,   355,    24,
     356,   155,   278,   158,     4,   155,   155,   379,   155,   155,
     227,    11,   155,   157,   288,    25,    13,   157,     4,   123,
     157,   157,   354,   127,   157,    26,   163,    31,   394,   395,
     163,   199,    32,   163,   163,    37,   161,   163,    39,   126,
     161,   198,    40,   161,   161,   167,   352,   161,   174,   392,
     158,    21,   171,    70,   158,   360,   271,   158,   158,    78,
     344,   158,   110,    99,   100,   101,   380,    27,   345,   346,
     115,    22,   283,    65,    38,    23,    27,    40,    24,    71,
     190,    33,   320,    72,   321,   322,    33,   288,   258,   397,
      18,    15,   180,   273,    30,    54,    28,    82,   164,   288,
      29,    34,    55,    30,   168,    35,   285,   150,    36,   172,
      15,   123,    81,    36,    15,   215,   283,    16,   275,   401,
     189,   221,    67,   259,    75,   408,   271,   123,   274,    57,
      58,    59,    87,    88,   220,   285,   285,   285,   258,    41,
      79,   286,   420,   271,    40,    42,    60,    43,    44,    45,
      46,   401,   195,   241,   150,    89,   196,   103,   150,   200,
     201,   150,   150,   202,    90,   150,   105,    57,    58,    59,
     286,   286,   286,   259,   106,   285,     1,     2,     3,   107,
     264,   273,   143,   144,    69,   145,   109,   298,   299,   146,
     147,   148,    41,    81,   291,   292,   108,     8,    42,   111,
      43,    44,    45,   149,     8,     8,   275,    57,    58,    59,
     286,    85,   258,    91,    92,    86,   274,   285,   285,   285,
      57,    58,    59,    39,    77,   386,   193,   228,   114,   331,
     194,    81,   258,    16,   112,   386,   116,   386,   386,   285,
     285,   257,   285,    97,    98,    81,   268,   259,   117,   140,
     141,   273,   286,   286,   286,    93,    94,    95,    96,   284,
     387,   120,   282,   357,   170,  -189,   113,   259,   421,   386,
     387,   118,   387,   387,   286,   286,   275,   286,   220,   119,
     220,   131,   132,   133,   134,   272,   274,   370,   284,   284,
     284,   257,   120,   275,   137,   138,   139,   142,   287,   326,
     327,   121,   263,   422,   387,     1,     2,     3,   125,   264,
     304,   143,   144,     4,   145,   166,   265,   266,   146,   364,
     365,    41,   169,   267,   399,   400,   173,    42,   284,    43,
      44,    45,   149,   175,   268,    19,    20,   129,   130,   410,
     135,   136,   176,   304,   304,   414,   304,   304,   304,   304,
     304,   304,   304,    41,   122,   177,   178,   179,   181,    42,
     182,    43,    44,    45,    46,   257,   187,   188,   191,   192,
     284,   284,   284,   272,   302,   304,   304,   203,   384,   207,
     208,   212,   214,   222,   223,   257,   224,   225,   384,   229,
     384,   384,   284,   284,   230,   284,   232,   231,   233,   234,
     235,   236,   304,   237,   268,   242,   238,   239,   335,   245,
     337,   338,   339,   340,   341,   342,   343,   304,   247,   243,
     205,   419,   384,   248,   251,   249,   210,   304,   254,   304,
     304,     1,     2,     3,   253,   260,   262,   261,   276,   362,
     363,   279,   280,   272,   146,   281,   293,    41,   295,   296,
     304,   297,   310,    42,   315,    43,    44,    45,   149,   304,
     272,   304,   316,   317,   319,   318,   373,   328,   330,   329,
     358,   332,   333,     1,     2,     3,   347,   264,   336,   143,
     144,   385,   145,   351,   265,   266,   146,   361,   353,    41,
     366,   359,   367,   339,   342,    42,   368,    43,    44,    45,
     149,   369,  -190,   371,     1,     2,     3,   372,   406,   375,
     143,   144,   376,   145,   412,   265,   266,   146,   381,   383,
      41,   388,   407,   385,   389,   423,    42,   390,    43,    44,
      45,   149,     1,     2,     3,   396,   264,   393,   143,   144,
     404,   145,   405,   265,   266,   146,   411,   415,    41,   416,
     418,   413,   417,   400,    42,   425,    43,    44,    45,   149,
       1,     2,     3,   349,   142,   382,   143,   144,   197,   145,
     350,   252,   128,   146,   147,   148,    41,   250,   314,     0,
     165,     0,    42,     0,    43,    44,    45,   149,     1,     2,
       3,     0,   142,     0,   143,   144,     0,   145,     0,     0,
       0,     0,     0,     0,    41,     0,   255,     0,     0,     0,
      42,     0,    43,    44,    45,   149,     1,     2,     3,     0,
     323,     0,   143,   144,     0,   145,     0,     0,     0,     0,
       0,     0,    41,     0,   324,     0,     0,     0,    42,     0,
      43,    44,    45,   149,     1,     2,     3,     0,   142,     0,
     143,   144,     0,   145,     0,     0,     0,     0,     0,     0,
      41,     0,   374,     0,     0,     0,    42,     0,    43,    44,
      45,   149,     1,     2,     3,     0,   142,     0,   143,   144,
       0,   145,     0,     0,     0,     0,     0,     0,    41,     0,
     391,     0,     0,     0,    42,     0,    43,    44,    45,   149,
       1,     2,     3,     0,   142,     0,   143,   144,     0,   145,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
       0,     0,    42,     0,    43,    44,    45,   149,    41,   226,
       0,     0,     0,     0,    42,    41,    43,    44,    45,    46,
       0,    42,    41,    43,    44,    45,    46,     0,    42,     0,
      73,    44,    45,    46
};

static const yytype_int16 yycheck[] =
{
      16,   256,     0,   255,   103,   287,    39,    21,    24,     7,
       8,   319,    45,    33,    30,    27,   103,   242,   242,     9,
      36,    11,    16,    13,    17,    41,    42,    20,    21,   103,
      39,    16,   284,   285,   286,   392,    47,    46,    54,   103,
     420,    20,    21,    22,   177,   425,    40,   404,   326,    43,
     328,   150,    37,   103,    47,   154,   155,   367,   157,   158,
     193,    47,   161,   150,   319,    55,    47,   154,    47,    85,
     157,   158,   324,    89,   161,    17,   150,    67,   388,   389,
     154,   155,    17,   157,   158,    75,   150,   161,    41,    87,
     154,   155,    45,   157,   158,   109,   404,   161,   118,   381,
     150,    16,   114,    28,   154,   330,   330,   157,   158,    34,
      36,   161,    69,    13,    14,    15,   368,    16,    44,    45,
      77,    36,   374,    41,    17,    40,    16,    45,    43,    41,
     146,    16,   384,    45,   386,   387,    16,   392,   237,   391,
       0,    40,   140,   242,    43,    43,    36,    41,   105,   404,
      40,    36,    47,    43,   111,    40,   255,   103,    43,   116,
      40,   177,    40,    43,    40,   181,   418,    43,   242,   393,
      17,   187,    47,   237,    47,   400,   400,   193,   242,    20,
      21,    22,    16,    17,   182,   284,   285,   286,   287,    36,
      41,   255,   417,   417,    45,    42,    37,    44,    45,    46,
      47,   425,   150,   219,   150,     3,   154,    38,   154,   157,
     158,   157,   158,   161,     4,   161,    37,    20,    21,    22,
     284,   285,   286,   287,    16,   324,    20,    21,    22,    47,
      24,   330,    26,    27,    37,    29,    16,    31,    32,    33,
      34,    35,    36,    40,   260,   261,    43,     0,    42,    37,
      44,    45,    46,    47,     7,     8,   330,    20,    21,    22,
     324,    36,   361,     5,     6,    40,   330,   366,   367,   368,
      20,    21,    22,    41,    37,   374,    36,    45,    16,   295,
      40,    40,   381,    43,    43,   384,    37,   386,   387,   388,
     389,   237,   391,    11,    12,    40,   242,   361,    43,    16,
      17,   400,   366,   367,   368,     7,     8,     9,    10,   255,
     374,    40,    40,   329,    43,    43,    41,   381,   417,   418,
     384,    16,   386,   387,   388,   389,   400,   391,   326,    45,
     328,    93,    94,    95,    96,   242,   400,   353,   284,   285,
     286,   287,    40,   417,    99,   100,   101,    24,    25,    16,
      17,    37,    17,   417,   418,    20,    21,    22,    45,    24,
     267,    26,    27,    47,    29,    38,    31,    32,    33,    44,
      45,    36,    23,    38,    24,    25,    38,    42,   324,    44,
      45,    46,    47,    41,   330,     7,     8,    91,    92,   405,
      97,    98,    45,   300,   301,   411,   303,   304,   305,   306,
     307,   308,   309,    36,    37,    16,    37,    41,    36,    42,
      36,    44,    45,    46,    47,   361,    36,    36,    36,    36,
     366,   367,   368,   330,   267,   332,   333,    39,   374,    17,
      23,    41,    40,    47,    17,   381,    23,    23,   384,    17,
     386,   387,   388,   389,    16,   391,    17,    39,    17,    16,
      39,    45,   359,    37,   400,    37,    47,    47,   301,    16,
     303,   304,   305,   306,   307,   308,   309,   374,    17,    37,
      45,   417,   418,    37,    17,    41,    46,   384,    41,   386,
     387,    20,    21,    22,    17,    43,    17,    43,    38,   332,
     333,    18,    37,   400,    33,    17,    47,    36,    36,    17,
     407,    17,    30,    42,    17,    44,    45,    46,    47,   416,
     417,   418,    47,    17,    39,    45,   359,    16,    37,    43,
      17,    17,    17,    20,    21,    22,    28,    24,    39,    26,
      27,   374,    29,    41,    31,    32,    33,    37,    36,    36,
      19,    38,    19,   386,   387,    42,    19,    44,    45,    46,
      47,    39,    43,    39,    20,    21,    22,    16,    24,    37,
      26,    27,    37,    29,   407,    31,    32,    33,    37,    39,
      36,    19,    38,   416,    19,   418,    42,    31,    44,    45,
      46,    47,    20,    21,    22,    17,    24,    39,    26,    27,
      39,    29,    36,    31,    32,    33,    36,    39,    36,    38,
      38,    37,    37,    25,    42,    39,    44,    45,    46,    47,
      20,    21,    22,   313,    24,   372,    26,    27,   155,    29,
     316,   234,    90,    33,    34,    35,    36,   230,   277,    -1,
     106,    -1,    42,    -1,    44,    45,    46,    47,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      42,    -1,    44,    45,    46,    47,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    38,    -1,    -1,    -1,    42,    -1,
      44,    45,    46,    47,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,    -1,    -1,    -1,    42,    -1,    44,    45,
      46,    47,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    36,    37,
      -1,    -1,    -1,    -1,    42,    36,    44,    45,    46,    47,
      -1,    42,    36,    44,    45,    46,    47,    -1,    42,    -1,
      44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,    21,    22,    47,    49,    50,    79,    82,    47,
      87,    47,    89,    47,    88,    40,    43,   106,     0,    50,
      50,    16,    36,    40,    43,   106,    17,    16,    36,    40,
      43,   106,    17,    16,    36,    40,    43,   106,    17,    41,
      45,    36,    42,    44,    45,    46,    47,    90,    91,    92,
      93,    94,    95,    96,    43,    47,    87,    20,    21,    22,
      37,    99,   100,   101,   102,    41,    90,    47,    89,    37,
      99,    41,    45,    44,    90,    47,    88,    37,    99,    41,
      90,    40,    41,    90,    90,    36,    40,    16,    17,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    90,    38,   103,    37,    16,    47,    43,    16,
     103,    37,    43,    41,    16,   103,    37,    43,    16,    45,
      40,    37,    37,    90,    98,    45,    79,    90,    91,    92,
      92,    93,    93,    93,    93,    94,    94,    95,    95,    95,
      16,    17,    24,    26,    27,    29,    33,    34,    35,    47,
      53,    62,    65,    71,    77,    78,    79,    80,    81,    82,
      90,    97,   104,   105,   103,   100,    38,    87,   103,    23,
      43,    89,   103,    38,    88,    41,    45,    16,    37,    41,
      79,    36,    36,    54,    55,    56,    57,    36,    36,    17,
      90,    36,    36,    36,    40,   104,   104,    77,    97,   105,
     104,   104,   104,    39,    39,    45,    84,    17,    23,    39,
      46,    83,    41,    98,    40,    90,    17,    20,    21,    59,
      79,    90,    47,    17,    23,    23,    37,    98,    45,    17,
      16,    39,    17,    17,    16,    39,    45,    37,    47,    47,
      60,    90,    37,    37,    85,    16,    86,    17,    37,    41,
      84,    17,    83,    17,    41,    38,    52,    53,    78,    97,
      43,    43,    17,    17,    24,    31,    32,    38,    53,    58,
      63,    68,    71,    78,    97,   105,    38,    16,    37,    18,
      37,    17,    40,    51,    53,    78,    97,    25,    65,    66,
      67,    90,    90,    47,    61,    36,    17,    17,    31,    32,
      53,    58,    64,    68,    71,    78,    80,    81,    97,   105,
      30,    72,    73,    74,    96,    17,    47,    17,    45,    39,
      51,    51,    51,    24,    38,    52,    16,    17,    16,    43,
      37,    90,    17,    17,    64,    64,    39,    64,    64,    64,
      64,    64,    64,    64,    36,    44,    45,    28,    76,    73,
      86,    41,    66,    36,    51,    59,    59,    90,    17,    38,
      58,    37,    64,    64,    44,    45,    19,    19,    19,    39,
      90,    39,    16,    64,    38,    37,    37,    51,    75,    75,
      51,    37,    61,    39,    53,    64,    78,    97,    19,    19,
      31,    38,    52,    39,    75,    75,    17,    51,    67,    24,
      25,    68,    69,    70,    39,    36,    24,    38,    58,    67,
      90,    36,    64,    37,    90,    39,    38,    37,    38,    53,
      58,    78,    97,    64,    70,    39,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    50,    51,    51,    51,
      51,    52,    52,    52,    53,    53,    53,    53,    54,    54,
      54,    55,    56,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    63,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    68,    69,    69,
      70,    70,    70,    70,    70,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      77,    78,    78,    78,    78,    79,    79,    79,    79,    80,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    87,    87,    87,    88,
      88,    88,    88,    88,    89,    89,    89,    89,    89,    90,
      90,    91,    91,    92,    92,    92,    93,    93,    93,    93,
      93,    94,    94,    94,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    97,
      98,    98,    99,   100,   100,   101,   102,   102,   102,   103,
     104,   104,   104,   104,   104,   104,   104,   105,   105,   106,
     106,   106
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     2,     2,     2,
       0,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     7,     9,     7,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     5,     6,     6,     1,     6,     1,     0,
       5,     3,     5,     3,     1,     1,     3,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     0,     8,     6,
       1,     1,     9,     4,     7,     2,     0,     8,     1,     1,
       9,     4,     7,     2,     0,     8,     1,     0,     2,     0,
       6,     4,     6,     4,     3,     1,     3,     0,     2,     1,
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
#line 61 "AST.y"
                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#code#DL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@@");(yyval.Str)=strdup(temp);fprintf(outFile,"%s",(yyval.Str));}
#line 1695 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 63 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#DS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#DL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1701 "y.tab.c"
    break;

  case 4: /* declarationList: assignmentStatement declarationList  */
#line 64 "AST.y"
                                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#AS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#DL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1707 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 65 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#DS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1713 "y.tab.c"
    break;

  case 6: /* declarationList: assignmentStatement  */
#line 66 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#AS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1719 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 68 "AST.y"
                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Satements#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1725 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 69 "AST.y"
                                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Satements#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1731 "y.tab.c"
    break;

  case 9: /* statements: functionCall statements  */
#line 70 "AST.y"
                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Satements#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1737 "y.tab.c"
    break;

  case 10: /* statements: %empty  */
#line 71 "AST.y"
                     {(yyval.Str)=strdup("#Epsilon@");}
#line 1743 "y.tab.c"
    break;

  case 11: /* singleStatement: specialStatement  */
#line 72 "AST.y"
                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1749 "y.tab.c"
    break;

  case 12: /* singleStatement: basicStatement  */
#line 73 "AST.y"
                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1755 "y.tab.c"
    break;

  case 13: /* singleStatement: functionCall  */
#line 74 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1761 "y.tab.c"
    break;

  case 14: /* specialStatement: FOR forLoop  */
#line 76 "AST.y"
                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#for@#");strcat(temp,"FL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1767 "y.tab.c"
    break;

  case 15: /* specialStatement: ifStatement  */
#line 77 "AST.y"
                                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IFS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1773 "y.tab.c"
    break;

  case 16: /* specialStatement: whileLoop  */
#line 78 "AST.y"
                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#WL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1779 "y.tab.c"
    break;

  case 17: /* specialStatement: switchStatement  */
#line 79 "AST.y"
                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SWS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1785 "y.tab.c"
    break;

  case 18: /* forLoop: forLoop2  */
#line 81 "AST.y"
                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FLMany#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1791 "y.tab.c"
    break;

  case 19: /* forLoop: forLoop3  */
#line 82 "AST.y"
                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FL1#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1797 "y.tab.c"
    break;

  case 20: /* forLoop: forLoop1  */
#line 83 "AST.y"
                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1803 "y.tab.c"
    break;

  case 21: /* forLoop1: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON  */
#line 86 "AST.y"
                                                                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#");strcat(temp,"ForA#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#ForE#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#;@#ForU#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#;@");(yyval.Str)=strdup(temp);}
#line 1809 "y.tab.c"
    break;

  case 22: /* forLoop2: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR inLoop CLCUR  */
#line 87 "AST.y"
                                                                                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#");strcat(temp,"ForA#");strcat(temp,(yyvsp[-7].Str));strcat(temp,"@@#ForE#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@#;@#ForU#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#)@#{@");strcat(temp,"#InL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 1815 "y.tab.c"
    break;

  case 23: /* forLoop3: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC singleLoopStatement  */
#line 88 "AST.y"
                                                                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#");strcat(temp,"ForA#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#ForE#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#;@#ForU#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#");strcat(temp,"SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1821 "y.tab.c"
    break;

  case 24: /* singleLoopStatement: specialStatement  */
#line 90 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1827 "y.tab.c"
    break;

  case 25: /* singleLoopStatement: basicStatement  */
#line 91 "AST.y"
                                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1833 "y.tab.c"
    break;

  case 26: /* singleLoopStatement: functionCall  */
#line 92 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1839 "y.tab.c"
    break;

  case 27: /* singleLoopStatement: BREAK SEMICOLON  */
#line 93 "AST.y"
                                                          {(yyval.Str)=strdup("#break@#;@");}
#line 1845 "y.tab.c"
    break;

  case 28: /* singleLoopStatement: CONTINUE SEMICOLON  */
#line 94 "AST.y"
                                                             {(yyval.Str)=strdup("#continue@#;@");}
#line 1851 "y.tab.c"
    break;

  case 29: /* singleLoopStatement: switchStatement  */
#line 95 "AST.y"
                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SWS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1857 "y.tab.c"
    break;

  case 30: /* singleLoopStatement: ifInLoopStatement  */
#line 96 "AST.y"
                                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfLoop#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1863 "y.tab.c"
    break;

  case 31: /* singleLoopStatement: returnDec  */
#line 97 "AST.y"
                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfLoop#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1869 "y.tab.c"
    break;

  case 32: /* forAssignStatement: assignmentStatement  */
#line 99 "AST.y"
                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FA#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1875 "y.tab.c"
    break;

  case 33: /* forAssignStatement: INT IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 100 "AST.y"
                                                                                             {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@#=@#ES#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 1881 "y.tab.c"
    break;

  case 34: /* forAssignStatement: INT IDENTIFIER EQUAL expressionStatement COMMA forAssignStatement  */
#line 101 "AST.y"
                                                                                                            {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#FA#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1887 "y.tab.c"
    break;

  case 35: /* forAssignStatement: CHAR IDENTIFIER EQUAL expressionStatement COMMA forAssignStatement  */
#line 102 "AST.y"
                                                                                                             {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#FA#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1893 "y.tab.c"
    break;

  case 38: /* forExpStatement: expressionStatement  */
#line 106 "AST.y"
                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1899 "y.tab.c"
    break;

  case 39: /* forExpStatement: %empty  */
#line 107 "AST.y"
                                  {(yyval.Str)=strdup("#Epsilon@");}
#line 1905 "y.tab.c"
    break;

  case 40: /* forUpdateStatement: IDENTIFIER EQUAL expressionStatement COMMA forUpdateStatement  */
#line 109 "AST.y"
                                                                                   {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#ForU#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1911 "y.tab.c"
    break;

  case 42: /* whileLoop: WHILE OPBRAC expressionStatement CLBRAC whileSuffix  */
#line 112 "AST.y"
                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#while@#(@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#WSuffix#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1917 "y.tab.c"
    break;

  case 43: /* whileSuffix: OPCUR inLoop CLCUR  */
#line 114 "AST.y"
                                 {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#{@#InL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 1923 "y.tab.c"
    break;

  case 44: /* whileSuffix: SEMICOLON  */
#line 115 "AST.y"
                              {(yyval.Str)=strdup(";");}
#line 1929 "y.tab.c"
    break;

  case 45: /* whileSuffix: singleLoopStatement  */
#line 116 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SLS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1935 "y.tab.c"
    break;

  case 46: /* inLoop: BREAK SEMICOLON inLoop  */
#line 118 "AST.y"
                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#break@#;@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1941 "y.tab.c"
    break;

  case 47: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 119 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#continue@#;@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1947 "y.tab.c"
    break;

  case 48: /* inLoop: specialStatement inLoop  */
#line 120 "AST.y"
                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1953 "y.tab.c"
    break;

  case 49: /* inLoop: basicStatement inLoop  */
#line 121 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1959 "y.tab.c"
    break;

  case 50: /* inLoop: functionCall inLoop  */
#line 122 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1965 "y.tab.c"
    break;

  case 51: /* inLoop: ifInLoopStatement inLoop  */
#line 123 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfInL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1971 "y.tab.c"
    break;

  case 52: /* inLoop: switchStatement inLoop  */
#line 124 "AST.y"
                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1977 "y.tab.c"
    break;

  case 53: /* inLoop: singleLoopStatement inLoop  */
#line 125 "AST.y"
                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SLS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1983 "y.tab.c"
    break;

  case 54: /* inLoop: printer inLoop  */
#line 126 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#printer#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1989 "y.tab.c"
    break;

  case 55: /* inLoop: Scanner inLoop  */
#line 127 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Scanner#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1995 "y.tab.c"
    break;

  case 56: /* inLoop: returnDec inLoop  */
#line 128 "AST.y"
                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Scanner#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2001 "y.tab.c"
    break;

  case 57: /* inLoop: %empty  */
#line 129 "AST.y"
                  {(yyval.Str)=strdup("#Epsilon@");}
#line 2007 "y.tab.c"
    break;

  case 58: /* ifStatement: IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ifContinuer  */
#line 131 "AST.y"
                                                                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IF@#(@#ES#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#)@#{@#Satements#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2013 "y.tab.c"
    break;

  case 59: /* ifStatement: IF OPBRAC expressionStatement CLBRAC singleStatement ifContinuer  */
#line 132 "AST.y"
                                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IF@#(@#ES#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#)@#SingleS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2019 "y.tab.c"
    break;

  case 60: /* ifContinuer: ES  */
#line 134 "AST.y"
                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2025 "y.tab.c"
    break;

  case 61: /* ifContinuer: ifStatement  */
#line 135 "AST.y"
                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2031 "y.tab.c"
    break;

  case 62: /* ES: ELSE IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ES  */
#line 137 "AST.y"
                                                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#)@#{@#STMTS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2037 "y.tab.c"
    break;

  case 63: /* ES: ELSE OPCUR statements CLCUR  */
#line 138 "AST.y"
                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#{@#STMTS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2043 "y.tab.c"
    break;

  case 64: /* ES: ELSE IF OPBRAC expressionStatement CLBRAC singleStatement ES  */
#line 139 "AST.y"
                                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#)@#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#ElS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2049 "y.tab.c"
    break;

  case 65: /* ES: ELSE singleStatement  */
#line 140 "AST.y"
                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2055 "y.tab.c"
    break;

  case 66: /* ES: %empty  */
#line 140 "AST.y"
                                                                                                                                                                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2061 "y.tab.c"
    break;

  case 67: /* ifInLoopStatement: IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ifInLoopContinuer  */
#line 142 "AST.y"
                                                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#if@#(@#ES#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#)@#{@#IL#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#IILC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2067 "y.tab.c"
    break;

  case 68: /* ifInLoopContinuer: ESLoop  */
#line 142 "AST.y"
                                                                                                                                                                                                                                                                                                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ESL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2073 "y.tab.c"
    break;

  case 69: /* ifInLoopContinuer: ifInLoopStatement  */
#line 142 "AST.y"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IILS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2079 "y.tab.c"
    break;

  case 70: /* ESLoop: ELSE IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ESLoop  */
#line 144 "AST.y"
                                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#)@#IL#");strcat(temp,(yyvsp[-3].Str)); strcat(temp,"@@#ESL#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2085 "y.tab.c"
    break;

  case 71: /* ESLoop: ELSE OPCUR inLoop CLCUR  */
#line 145 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#{@#IL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2091 "y.tab.c"
    break;

  case 72: /* ESLoop: ELSE IF OPBRAC expressionStatement CLBRAC singleLoopStatement ESLoop  */
#line 146 "AST.y"
                                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#)@#SLS#");strcat(temp,(yyvsp[-1].Str)); strcat(temp,"@@#ESL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2097 "y.tab.c"
    break;

  case 73: /* ESLoop: ELSE singleLoopStatement  */
#line 147 "AST.y"
                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#SLS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2103 "y.tab.c"
    break;

  case 74: /* ESLoop: %empty  */
#line 147 "AST.y"
                                                                                                                                                                                  {(yyval.Str)=strdup("#Epsilon@");}
#line 2109 "y.tab.c"
    break;

  case 75: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR  */
#line 149 "AST.y"
                                                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000); strcat(temp,"#switch@#(@#Identifier#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#(@#{@#CS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#DS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2115 "y.tab.c"
    break;

  case 76: /* caseStatements: caseStatementInt  */
#line 151 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#CSI#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2121 "y.tab.c"
    break;

  case 77: /* caseStatements: %empty  */
#line 152 "AST.y"
                                  {(yyval.Str)=strdup("#Epsilon@");}
#line 2127 "y.tab.c"
    break;

  case 78: /* caseStatementInt: caseInt caseStatementInt  */
#line 154 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#CI#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#CSI#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2133 "y.tab.c"
    break;

  case 79: /* caseStatementInt: %empty  */
#line 155 "AST.y"
                                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2139 "y.tab.c"
    break;

  case 80: /* caseInt: CASE OPBRAC INTVAL CLBRAC COLON caseContinuer  */
#line 157 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#(@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#)@#:@#CC#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2145 "y.tab.c"
    break;

  case 81: /* caseInt: CASE INTVAL COLON caseContinuer  */
#line 158 "AST.y"
                                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#:@#CC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2151 "y.tab.c"
    break;

  case 82: /* caseInt: CASE OPBRAC CHARVAL CLBRAC COLON caseContinuer  */
#line 159 "AST.y"
                                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#(@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#)@#:@#CC#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2157 "y.tab.c"
    break;

  case 83: /* caseInt: CASE CHARVAL COLON caseContinuer  */
#line 160 "AST.y"
                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#:@#CC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2163 "y.tab.c"
    break;

  case 84: /* caseContinuer: statements BREAK SEMICOLON  */
#line 162 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#STMTS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#break@#;@");(yyval.Str)=strdup(temp);}
#line 2169 "y.tab.c"
    break;

  case 85: /* caseContinuer: statements  */
#line 163 "AST.y"
                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#STMTS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2175 "y.tab.c"
    break;

  case 86: /* defaultStatement: DEFAULT COLON statements  */
#line 165 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#default@#:@#STMTS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2181 "y.tab.c"
    break;

  case 87: /* defaultStatement: %empty  */
#line 166 "AST.y"
                                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2187 "y.tab.c"
    break;

  case 88: /* basicStatements: basicStatement basicStatements  */
#line 169 "AST.y"
                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#BSs#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2193 "y.tab.c"
    break;

  case 89: /* basicStatements: basicStatement  */
#line 170 "AST.y"
                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2199 "y.tab.c"
    break;

  case 90: /* basicStatements: returnDec  */
#line 171 "AST.y"
                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2205 "y.tab.c"
    break;

  case 91: /* basicStatement: expressionStatement  */
#line 173 "AST.y"
                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2211 "y.tab.c"
    break;

  case 92: /* basicStatement: declarationStatement  */
#line 174 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#DS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2217 "y.tab.c"
    break;

  case 93: /* basicStatement: assignmentStatement  */
#line 175 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#AS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2223 "y.tab.c"
    break;

  case 94: /* basicStatement: functionCall  */
#line 175 "AST.y"
                                                                                                                                                                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2229 "y.tab.c"
    break;

  case 95: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 177 "AST.y"
                                                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@");strcat(temp,"#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#AS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2235 "y.tab.c"
    break;

  case 96: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 178 "AST.y"
                                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@");strcat(temp,"#=@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2241 "y.tab.c"
    break;

  case 97: /* assignmentStatement: IDENTIFIER dimension EQUAL expressionStatement COMMA assignmentStatement  */
#line 178 "AST.y"
                                                                                                                                                                                                                                                                                                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#AS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2247 "y.tab.c"
    break;

  case 98: /* assignmentStatement: IDENTIFIER dimension EQUAL expressionStatement SEMICOLON  */
#line 179 "AST.y"
                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2253 "y.tab.c"
    break;

  case 99: /* printer: PRINTF OPBRAC STRING prattributes CLBRAC SEMICOLON  */
#line 181 "AST.y"
                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#printf@#(@#String#\\");strcat(temp,(yyvsp[-3].Str));strcat(temp,"\\\"@@#PrA#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#;@");(yyval.Str)=strdup(temp);}
#line 2259 "y.tab.c"
    break;

  case 100: /* Scanner: SCANF OPBRAC STRING scattributes CLBRAC SEMICOLON  */
#line 182 "AST.y"
                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#scanf@#(@#String#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#SCA#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#;@");(yyval.Str)=strdup(temp);}
#line 2265 "y.tab.c"
    break;

  case 101: /* declarationStatement: INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 184 "AST.y"
                                                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#(@#PS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2271 "y.tab.c"
    break;

  case 102: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 185 "AST.y"
                                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#(@#PS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2277 "y.tab.c"
    break;

  case 103: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 186 "AST.y"
                                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#(@#PS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2283 "y.tab.c"
    break;

  case 104: /* declarationStatement: INT IDENTIFIER OPBRAC CLBRAC compoundStatements  */
#line 187 "AST.y"
                                                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2289 "y.tab.c"
    break;

  case 105: /* declarationStatement: FLOAT IDENTIFIER OPBRAC CLBRAC compoundStatements  */
#line 188 "AST.y"
                                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2295 "y.tab.c"
    break;

  case 106: /* declarationStatement: CHAR IDENTIFIER OPBRAC CLBRAC compoundStatements  */
#line 189 "AST.y"
                                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2301 "y.tab.c"
    break;

  case 107: /* declarationStatement: INT declarationListInt SEMICOLON  */
#line 190 "AST.y"
                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#DLI#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2307 "y.tab.c"
    break;

  case 108: /* declarationStatement: CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING SEMICOLON  */
#line 191 "AST.y"
                                                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@#[@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#]@#=@#STRING#\\");strcat(temp,(yyvsp[-1].Str));strcat(temp,"\\\"@@#;@");(yyval.Str)=strdup(temp);}
#line 2313 "y.tab.c"
    break;

  case 109: /* declarationStatement: CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING SEMICOLON  */
#line 192 "AST.y"
                                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#[@#]@#=@#STRING#\\");strcat(temp,(yyvsp[-1].Str));strcat(temp,"\\\"@@#;@");(yyval.Str)=strdup(temp);}
#line 2319 "y.tab.c"
    break;

  case 110: /* declarationStatement: CHAR declarationListChar SEMICOLON  */
#line 193 "AST.y"
                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#DLC#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2325 "y.tab.c"
    break;

  case 111: /* declarationStatement: FLOAT declarationListFloat SEMICOLON  */
#line 194 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#DLF#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2331 "y.tab.c"
    break;

  case 112: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON  */
#line 195 "AST.y"
                                                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,(yyvsp[-7].Str));strcat(temp,"@@#[@#]@#=@#{@#AV#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#;@");(yyval.Str)=strdup(temp);}
#line 2337 "y.tab.c"
    break;

  case 113: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON  */
#line 196 "AST.y"
                                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@#[@#]@#=@#{@#}@#;@");(yyval.Str)=strdup(temp);}
#line 2343 "y.tab.c"
    break;

  case 114: /* declarationStatement: FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValuesF CLCUR SEMICOLON  */
#line 196 "AST.y"
                                                                                                                                                                                                                                                                                                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,(yyvsp[-7].Str));strcat(temp,"@@#[@#]@#=@#{@#AVF#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#;@");(yyval.Str)=strdup(temp);}
#line 2349 "y.tab.c"
    break;

  case 115: /* declarationStatement: FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON  */
#line 197 "AST.y"
                                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@#[@#]@#=@#{@#}@#;@");(yyval.Str)=strdup(temp);}
#line 2355 "y.tab.c"
    break;

  case 116: /* arrayValuesF: FLOATVAL COMMA arrayValuesF  */
#line 200 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#,@#AVF#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2361 "y.tab.c"
    break;

  case 117: /* arrayValuesF: FLOATVAL  */
#line 201 "AST.y"
                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2367 "y.tab.c"
    break;

  case 118: /* arrayValues: INTVAL COMMA arrayValues  */
#line 203 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#,@#AV#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2373 "y.tab.c"
    break;

  case 119: /* arrayValues: INTVAL  */
#line 204 "AST.y"
                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2379 "y.tab.c"
    break;

  case 120: /* prattributes: prattributes COMMA factor  */
#line 206 "AST.y"
                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#PrA#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#factor#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2385 "y.tab.c"
    break;

  case 121: /* prattributes: %empty  */
#line 207 "AST.y"
                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2391 "y.tab.c"
    break;

  case 122: /* scattributes: COMMA AMPERSAND IDENTIFIER scattributes  */
#line 209 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#,@#&@#Identifier#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#,@#SCA#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2397 "y.tab.c"
    break;

  case 123: /* scattributes: %empty  */
#line 210 "AST.y"
                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2403 "y.tab.c"
    break;

  case 124: /* declarationListInt: IDENTIFIER EQUAL expressionStatement COMMA declarationListInt  */
#line 212 "AST.y"
                                                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLI#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2409 "y.tab.c"
    break;

  case 125: /* declarationListInt: IDENTIFIER COMMA declarationListInt  */
#line 213 "AST.y"
                                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLI#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2415 "y.tab.c"
    break;

  case 126: /* declarationListInt: IDENTIFIER EQUAL expressionStatement  */
#line 214 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2421 "y.tab.c"
    break;

  case 127: /* declarationListInt: IDENTIFIER dimension  */
#line 215 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2427 "y.tab.c"
    break;

  case 128: /* declarationListInt: IDENTIFIER  */
#line 216 "AST.y"
                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2433 "y.tab.c"
    break;

  case 129: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListFloat  */
#line 218 "AST.y"
                                                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLF#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2439 "y.tab.c"
    break;

  case 130: /* declarationListFloat: IDENTIFIER COMMA declarationListFloat  */
#line 219 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLF#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2445 "y.tab.c"
    break;

  case 131: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement  */
#line 220 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2451 "y.tab.c"
    break;

  case 132: /* declarationListFloat: IDENTIFIER dimension  */
#line 221 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2457 "y.tab.c"
    break;

  case 133: /* declarationListFloat: IDENTIFIER  */
#line 222 "AST.y"
                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2463 "y.tab.c"
    break;

  case 134: /* declarationListChar: IDENTIFIER EQUAL CHARVAL COMMA declarationListChar  */
#line 224 "AST.y"
                                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#,@#DLC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2469 "y.tab.c"
    break;

  case 135: /* declarationListChar: IDENTIFIER COMMA declarationListChar  */
#line 225 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2475 "y.tab.c"
    break;

  case 136: /* declarationListChar: IDENTIFIER EQUAL expressionStatement  */
#line 226 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2481 "y.tab.c"
    break;

  case 137: /* declarationListChar: IDENTIFIER dimension  */
#line 227 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2487 "y.tab.c"
    break;

  case 138: /* declarationListChar: IDENTIFIER  */
#line 228 "AST.y"
                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2493 "y.tab.c"
    break;

  case 139: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 230 "AST.y"
                                                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#LE#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#||@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2499 "y.tab.c"
    break;

  case 140: /* expressionStatement: logicalExpression  */
#line 231 "AST.y"
                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#LE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2505 "y.tab.c"
    break;

  case 141: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 233 "AST.y"
                                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Exp#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#&&@#LE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2511 "y.tab.c"
    break;

  case 142: /* logicalExpression: expression  */
#line 234 "AST.y"
                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Exp#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2517 "y.tab.c"
    break;

  case 143: /* expression: relationalExpression EQUALS expression  */
#line 236 "AST.y"
                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RE#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#==@#Exp#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2523 "y.tab.c"
    break;

  case 144: /* expression: relationalExpression NOTEQUAL expression  */
#line 237 "AST.y"
                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RE#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#!=@#Exp#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2529 "y.tab.c"
    break;

  case 145: /* expression: relationalExpression  */
#line 238 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2535 "y.tab.c"
    break;

  case 146: /* relationalExpression: value GREATERTHAN relationalExpression  */
#line 240 "AST.y"
                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#>@#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2541 "y.tab.c"
    break;

  case 147: /* relationalExpression: value GREATERTHANEQUALTO relationalExpression  */
#line 241 "AST.y"
                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#>=@#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2547 "y.tab.c"
    break;

  case 148: /* relationalExpression: value LESSTHAN relationalExpression  */
#line 242 "AST.y"
                                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#<@#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2553 "y.tab.c"
    break;

  case 149: /* relationalExpression: value LESSTHANEQUALTO relationalExpression  */
#line 243 "AST.y"
                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#<=@#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2559 "y.tab.c"
    break;

  case 150: /* relationalExpression: value  */
#line 244 "AST.y"
                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2565 "y.tab.c"
    break;

  case 151: /* value: term ADD value  */
#line 246 "AST.y"
                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#term#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#+@#value#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2571 "y.tab.c"
    break;

  case 152: /* value: term SUB value  */
#line 247 "AST.y"
                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#term#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#-@#value#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2577 "y.tab.c"
    break;

  case 153: /* value: term  */
#line 248 "AST.y"
               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#term#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2583 "y.tab.c"
    break;

  case 154: /* term: factor MULT term  */
#line 250 "AST.y"
                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#*@#term#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2589 "y.tab.c"
    break;

  case 155: /* term: factor DIV term  */
#line 251 "AST.y"
                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#/@#term#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2595 "y.tab.c"
    break;

  case 156: /* term: factor MOD term  */
#line 252 "AST.y"
                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#%@#term#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2601 "y.tab.c"
    break;

  case 157: /* term: factor  */
#line 253 "AST.y"
                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2607 "y.tab.c"
    break;

  case 158: /* factor: IDENTIFIER  */
#line 255 "AST.y"
                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2613 "y.tab.c"
    break;

  case 159: /* factor: OPBRAC expressionStatement CLBRAC  */
#line 256 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#ES#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#)@");(yyval.Str)=strdup(temp);}
#line 2619 "y.tab.c"
    break;

  case 160: /* factor: LOGICALNOT expressionStatement  */
#line 257 "AST.y"
                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#!@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2625 "y.tab.c"
    break;

  case 161: /* factor: CHARVAL  */
#line 258 "AST.y"
                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2631 "y.tab.c"
    break;

  case 162: /* factor: INTVAL  */
#line 259 "AST.y"
                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2637 "y.tab.c"
    break;

  case 163: /* factor: FLOATVAL  */
#line 260 "AST.y"
                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2643 "y.tab.c"
    break;

  case 164: /* factor: IDENTIFIER OPBRAC CLBRAC  */
#line 260 "AST.y"
                                                                                                                                                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#(@#)@");(yyval.Str)=strdup(temp);}
#line 2649 "y.tab.c"
    break;

  case 165: /* factor: IDENTIFIER OPBRAC argList CLBRAC  */
#line 260 "AST.y"
                                                                                                                                                                                                                                                                                                                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#AL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#)@");(yyval.Str)=strdup(temp);}
#line 2655 "y.tab.c"
    break;

  case 166: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE  */
#line 261 "AST.y"
                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@");strcat(temp,"#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2661 "y.tab.c"
    break;

  case 167: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 262 "AST.y"
                                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@");strcat(temp,"#[@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#]@#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2667 "y.tab.c"
    break;

  case 168: /* functionCall: IDENTIFIER OPBRAC CLBRAC SEMICOLON  */
#line 265 "AST.y"
                                                  {{char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#;@");(yyval.Str)=strdup(temp);}}
#line 2673 "y.tab.c"
    break;

  case 169: /* functionCall: IDENTIFIER OPBRAC argList CLBRAC SEMICOLON  */
#line 266 "AST.y"
                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#(@#AL#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#;@");(yyval.Str)=strdup(temp);}
#line 2679 "y.tab.c"
    break;

  case 170: /* argList: expressionStatement COMMA argList  */
#line 269 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#AL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2685 "y.tab.c"
    break;

  case 171: /* argList: expressionStatement  */
#line 270 "AST.y"
                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2691 "y.tab.c"
    break;

  case 172: /* parameters: paramContinuer  */
#line 272 "AST.y"
                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#PC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2697 "y.tab.c"
    break;

  case 173: /* paramContinuer: parameter  */
#line 273 "AST.y"
                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#P#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2703 "y.tab.c"
    break;

  case 174: /* paramContinuer: parameter COMMA paramContinuer  */
#line 274 "AST.y"
                                                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#P#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#PC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2709 "y.tab.c"
    break;

  case 175: /* parameter: type IDENTIFIER  */
#line 276 "AST.y"
                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#type#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2715 "y.tab.c"
    break;

  case 176: /* type: INT  */
#line 278 "AST.y"
           {(yyval.Str)=strdup("#int@");}
#line 2721 "y.tab.c"
    break;

  case 177: /* type: FLOAT  */
#line 279 "AST.y"
                        {(yyval.Str)=strdup("#float@");}
#line 2727 "y.tab.c"
    break;

  case 178: /* type: CHAR  */
#line 280 "AST.y"
                        {(yyval.Str)=strdup("#char@");}
#line 2733 "y.tab.c"
    break;

  case 179: /* compoundStatements: OPCUR statementList CLCUR  */
#line 282 "AST.y"
                                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#{@#SL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2739 "y.tab.c"
    break;

  case 180: /* statementList: functionCall statementList  */
#line 284 "AST.y"
                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2745 "y.tab.c"
    break;

  case 181: /* statementList: basicStatements statementList  */
#line 285 "AST.y"
                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2751 "y.tab.c"
    break;

  case 182: /* statementList: specialStatement statementList  */
#line 286 "AST.y"
                                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2757 "y.tab.c"
    break;

  case 183: /* statementList: returnDec  */
#line 287 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RD#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2763 "y.tab.c"
    break;

  case 184: /* statementList: printer statementList  */
#line 288 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#printer#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2769 "y.tab.c"
    break;

  case 185: /* statementList: Scanner statementList  */
#line 289 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Scanner#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2775 "y.tab.c"
    break;

  case 186: /* statementList: %empty  */
#line 290 "AST.y"
                                  {(yyval.Str)=strdup("#Epsilon@");}
#line 2781 "y.tab.c"
    break;

  case 187: /* returnDec: RETURN expressionStatement SEMICOLON  */
#line 292 "AST.y"
                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#return@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2787 "y.tab.c"
    break;

  case 188: /* returnDec: RETURN SEMICOLON  */
#line 293 "AST.y"
                                           {(yyval.Str)=strdup("#return@#;@");}
#line 2793 "y.tab.c"
    break;

  case 189: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 295 "AST.y"
                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2799 "y.tab.c"
    break;

  case 190: /* dimension: BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 296 "AST.y"
                                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#[@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#]@#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2805 "y.tab.c"
    break;

  case 191: /* dimension: BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 297 "AST.y"
                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#[@#]@#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2811 "y.tab.c"
    break;


#line 2815 "y.tab.c"

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

#line 298 "AST.y"

 
#include "lex.yy.c"
int main(){
	yyin = fopen("./Test Cases/input.txt","r");	
	if(!yyparse())
	{
		printf("\n\nParsed Successfully\n\n");		
		// printTable();
	}
	else 
		printf("\n\nParsing Failed\n\n");			
	exit(0);
}
