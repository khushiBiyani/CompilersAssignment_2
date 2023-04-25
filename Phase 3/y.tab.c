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
#define YYLAST   835

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  188
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  423

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
      96,    98,    99,   100,   101,   102,   103,   105,   106,   108,
     109,   111,   113,   114,   115,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   129,   130,   132,   133,
     135,   136,   137,   138,   138,   140,   140,   140,   142,   143,
     144,   145,   145,   147,   149,   150,   152,   153,   155,   156,
     157,   158,   160,   161,   163,   164,   167,   168,   170,   171,
     172,   172,   174,   175,   175,   176,   178,   179,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   193,   194,   197,   198,   200,   201,   203,   204,   206,
     207,   209,   210,   211,   212,   213,   215,   216,   217,   218,
     219,   221,   222,   223,   224,   225,   227,   228,   230,   231,
     233,   234,   235,   237,   238,   239,   240,   241,   243,   244,
     245,   247,   248,   249,   250,   252,   253,   254,   255,   256,
     257,   257,   257,   258,   259,   262,   263,   266,   267,   269,
     270,   271,   273,   275,   276,   277,   279,   281,   282,   283,
     284,   285,   286,   287,   289,   290,   292,   293,   294
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

#define YYPACT_NINF (-329)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-188)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,    -5,    35,    71,    27,   125,  -329,    10,    10,    79,
      75,   104,   126,   110,   134,    92,   227,   129,  -329,  -329,
    -329,   131,    29,   145,   227,  -329,  -329,   149,   148,   173,
     261,  -329,  -329,   176,   171,   201,   227,  -329,  -329,   191,
     175,   227,   227,  -329,  -329,  -329,    45,    87,   230,   237,
      17,   244,   146,   306,   227,    -4,  -329,  -329,  -329,  -329,
     246,   228,  -329,   280,   251,   224,   284,    58,  -329,   246,
     265,   236,   268,   298,  -329,    98,  -329,   246,   289,   250,
     316,   296,   303,   327,  -329,   190,   310,   313,  -329,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   318,   592,  -329,   246,   302,  -329,   333,   131,
    -329,   246,   349,   273,   149,  -329,   246,   335,   176,   336,
     329,  -329,  -329,   360,   341,   338,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
     313,  -329,   344,   345,   346,   347,    -1,   350,   353,   169,
     592,  -329,  -329,  -329,   592,   153,  -329,   592,   592,  -329,
    -329,   592,   354,  -329,  -329,  -329,    78,  -329,  -329,   375,
     371,  -329,  -329,    40,  -329,  -329,   356,   227,  -329,   358,
    -329,   227,     7,  -329,  -329,  -329,  -329,   227,   348,  -329,
     379,   378,   386,   203,   225,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,   399,   401,   380,  -329,   404,   405,   402,
     384,  -329,  -329,   387,   392,  -329,   377,   388,   227,  -329,
     397,   400,  -329,  -329,   420,   424,   407,   408,  -329,   406,
     425,  -329,  -329,   409,   435,   412,   676,   411,   414,   441,
    -329,   505,   422,    31,   443,   426,  -329,   445,   275,  -329,
    -329,  -329,  -329,  -329,   788,   267,  -329,  -329,  -329,   227,
     227,   418,  -329,   430,   450,   451,   564,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,   439,   227,   453,   427,   455,  -329,
     428,   436,   788,   788,   788,   704,  -329,  -329,  -329,   323,
     462,   437,   448,   227,  -329,  -329,   465,   469,   564,   564,
     449,   564,   564,   564,   564,   564,   564,    66,   459,  -329,
     439,  -329,  -329,   420,  -329,   452,   267,  -329,  -329,  -329,
     454,   788,  -329,     7,  -329,     7,   227,   536,   457,   564,
     564,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
     305,   470,   476,   477,   460,  -329,  -329,   458,  -329,   227,
     461,  -329,  -329,   482,  -329,   564,  -329,   732,  -329,  -329,
     466,   468,   788,   788,   788,  -329,   471,  -329,   418,   463,
     564,   487,   488,   478,  -329,  -329,  -329,   760,  -329,  -329,
     564,   472,   564,   564,   788,   788,   493,   788,   267,   328,
    -329,  -329,  -329,   479,  -329,   480,   620,  -329,  -329,  -329,
     267,   227,   481,   564,  -329,  -329,   483,   227,   485,   490,
     496,  -329,   564,   648,   564,  -329,   494,  -329,  -329,   491,
    -329,   328,  -329
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     5,   125,
       0,   135,     0,   130,     0,     0,     0,     0,     1,     4,
       3,     0,     0,     0,     0,   124,   104,     0,     0,     0,
       0,   134,   107,     0,     0,     0,     0,   129,   108,     0,
       0,     0,     0,   158,   159,   160,   155,     0,   137,   139,
     142,   147,   150,   154,     0,   125,   122,   173,   175,   174,
       0,     0,   169,   170,     0,     0,   123,   135,   132,     0,
       0,     0,     0,   158,   133,   130,   127,     0,     0,     0,
     128,     0,   186,     0,   157,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   101,     0,     0,   172,     0,     0,
     103,     0,     0,   186,     0,   102,     0,     0,     0,     0,
       0,   156,   161,   168,     0,     0,    92,   136,   138,   140,
     141,   143,   144,   145,   146,   148,   149,   151,   152,   153,
       0,    95,     0,     0,     0,     0,     0,     0,     0,   155,
     183,    16,    15,    17,   183,    87,    90,   183,   183,    89,
      88,    91,     0,   180,    98,   171,     0,   121,    99,     0,
       0,   131,   100,     0,   126,   188,     0,     0,   162,   163,
      94,     0,     0,    14,    20,    18,    19,     0,     0,   185,
       0,     0,     0,     0,     0,   179,   178,    86,    91,   181,
     182,   177,   176,     0,   116,     0,   106,     0,     0,   114,
       0,   187,   167,     0,     0,    35,     0,     0,    38,    31,
       0,     0,   184,   118,   120,   161,     0,     0,   110,     0,
       0,   105,   112,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,   165,   162,   163,   115,
     109,   113,   111,   164,    10,    64,    11,    12,    13,     0,
       0,     0,    43,     0,     0,     0,    55,    24,    44,    41,
      30,    17,    25,    26,    75,     0,     0,     0,     0,   166,
       0,     0,    10,    10,    10,     0,    59,    57,    58,     0,
       0,     0,     0,     0,    27,    28,     0,     0,    24,    55,
       0,    30,    17,    25,    55,    55,    26,     0,    85,    74,
      77,   117,    96,   120,    97,     0,    64,     7,     8,     9,
       0,    10,    63,     0,    32,     0,     0,     0,     0,    27,
      28,    47,    52,    42,    50,    51,    48,    53,    54,    49,
       0,     0,     0,     0,     0,    76,   119,   164,    56,     0,
       0,    33,    34,    40,    21,    55,    23,     0,    45,    46,
       0,     0,    10,    10,    10,    73,     0,    61,     0,     0,
      10,     0,     0,    83,    81,    79,    84,     0,    39,    22,
      10,     0,    10,    10,    10,    10,     0,    10,    64,    72,
      80,    78,    82,     0,    58,     0,     0,    67,    65,    66,
      64,     0,     0,    55,    71,    58,     0,     0,     0,     0,
       0,    69,    55,     0,    10,    11,    72,    12,    13,     0,
      70,    72,    66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -329,  -329,   355,  -176,  -280,    63,  -329,  -329,  -329,  -329,
    -237,  -122,  -329,   167,  -329,  -329,   109,  -252,  -301,  -328,
    -234,  -329,  -267,   101,  -329,   232,  -329,  -323,  -329,   383,
    -102,     2,   -70,   -45,   222,   307,   315,  -329,   226,   -15,
     -22,   -14,   -16,   456,   274,   193,   271,   229,   270,   -26,
    -159,    93,   442,  -329,  -329,   -40,     6,  -329,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,   373,   255,   298,   183,   184,   185,   186,
     299,   218,   239,   292,   151,   269,   331,   152,   287,   288,
     301,   398,   399,   153,   308,   309,   310,   374,   344,   154,
     303,   156,   304,   305,   159,   210,   205,   243,   245,    10,
      14,    12,   160,    48,    49,    50,    51,    52,    53,   306,
     124,    61,    62,    63,    64,   104,   162,   163,    17
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,   155,     7,   286,   268,   322,    56,   270,    66,     7,
       7,    76,    21,    68,    74,   348,   189,    25,   212,    31,
      80,    37,    91,    92,   215,    83,    84,   216,   217,   110,
       1,     2,     3,   157,   226,    41,    15,   115,   102,    24,
     375,    42,     9,    43,    44,    45,    46,   275,   155,    57,
      58,    59,   155,   155,     4,   155,   155,     4,   158,   155,
     394,   390,   391,    25,   286,   164,    60,    15,   276,   123,
      16,   168,   405,   127,    27,    31,   172,   161,   281,   208,
     157,    85,    11,    37,   157,    86,   209,   157,   157,   126,
     356,   157,    26,   270,   167,    21,   174,   388,    15,   348,
     171,    30,   340,    87,    88,   158,   317,   318,   319,   158,
     341,   342,   158,   158,    33,    22,   158,   203,    13,    23,
      27,    70,    24,   204,   161,    18,    33,    78,   161,   198,
     190,   161,   161,    39,   257,   161,   286,    40,    15,   272,
      28,    36,   180,    32,    29,   350,    34,    30,   286,   420,
      35,    38,   283,    36,   422,   397,   195,    97,    98,   404,
     196,   123,   270,   199,   200,   214,   150,   201,    57,    58,
      59,   220,    54,     1,     2,     3,   416,   123,    55,   270,
     283,   283,   283,   257,   219,    69,    65,   397,   376,    41,
      40,    57,    58,    59,   281,    42,    67,    43,    44,    45,
     149,   351,   240,   352,   317,   193,   318,   319,    77,   194,
     258,   393,    16,   150,    71,   273,    82,   150,    72,   283,
     150,   150,     8,    75,   150,   272,    41,   122,   284,     8,
       8,    81,    42,    89,    43,    44,    45,    46,   281,    41,
     225,    90,    79,   289,   290,    42,    40,    43,    44,    45,
      46,    93,    94,    95,    96,   257,   284,   284,   284,   258,
     283,   283,   283,    41,    81,   105,    39,   108,   382,    42,
     227,    43,    44,    45,    46,   257,    81,   328,   382,   112,
     382,   382,   283,   283,   103,   283,   131,   132,   133,   134,
      81,   142,   285,   117,   272,   284,   106,    41,   107,   256,
     109,   273,   111,    42,   267,    73,    44,    45,    46,   113,
     353,   417,   382,   120,   114,   280,   170,   282,  -186,    99,
     100,   101,    57,    58,    59,   219,   116,   219,   137,   138,
     139,   258,   118,   366,   140,   141,   284,   284,   284,   323,
     324,   119,   271,   120,   383,   282,   282,   282,   256,   360,
     361,   258,   395,   396,   383,   125,   383,   383,   284,   284,
       4,   284,    19,    20,   121,   129,   130,   302,   135,   136,
     273,   166,   169,   173,   176,   300,   177,   175,   178,   179,
     181,   182,   187,   188,   282,   406,   191,   418,   383,   192,
     267,   410,   206,   202,   207,   221,   222,   211,   213,   302,
     302,   223,   302,   302,   302,   302,   302,   302,   332,   224,
     334,   335,   336,   337,   338,   339,   228,   229,   233,   230,
     256,   231,   232,   234,   237,   282,   282,   282,   271,   236,
     302,   302,   235,   380,   241,   238,   244,   242,   358,   359,
     256,   246,   250,   380,   247,   380,   380,   282,   282,   248,
     282,   204,   252,   253,   259,   209,   302,   260,   261,   267,
     274,   277,   279,   278,   369,   291,   293,   294,   295,   307,
     312,   302,   314,   315,   313,   316,   415,   380,   325,   381,
     326,   302,   329,   302,   302,   327,   330,   343,   333,   362,
     349,   336,   339,   347,   357,   363,   364,   271,   368,   365,
     367,  -187,   379,   371,   302,   372,   384,   385,   377,   386,
     392,   389,   408,   302,   271,   302,   401,   407,   400,   396,
     409,   381,   262,   419,   411,     1,     2,     3,   412,   263,
     421,   143,   144,   413,   145,   378,   264,   265,   197,   346,
     251,    41,   345,   266,   249,   311,   128,    42,   165,    43,
      44,    45,   149,   354,     0,     0,     1,     2,     3,     0,
     263,     0,   143,   144,     0,   145,     0,   264,   265,     0,
       0,     0,    41,     0,   355,     0,     0,     0,    42,     0,
      43,    44,    45,   149,     1,     2,     3,     0,   263,     0,
     143,   144,     0,   145,     0,   296,   297,     0,   147,   148,
      41,     0,     0,     0,     0,     0,    42,     0,    43,    44,
      45,   149,     1,     2,     3,     0,   142,     0,   143,   144,
       0,   145,     0,     0,     0,   146,   147,   148,    41,     0,
       0,     0,     0,     0,    42,     0,    43,    44,    45,   149,
       1,     2,     3,     0,   402,     0,   143,   144,     0,   145,
       0,   264,   265,     0,     0,     0,    41,     0,   403,     0,
       0,     0,    42,     0,    43,    44,    45,   149,     1,     2,
       3,     0,   263,     0,   143,   144,     0,   145,     0,   264,
     265,     0,     0,     0,    41,     0,   414,     0,     0,     0,
      42,     0,    43,    44,    45,   149,     1,     2,     3,     0,
     142,     0,   143,   144,     0,   145,     0,     0,     0,     0,
       0,     0,    41,     0,   254,     0,     0,     0,    42,     0,
      43,    44,    45,   149,     1,     2,     3,     0,   320,     0,
     143,   144,     0,   145,     0,     0,     0,     0,     0,     0,
      41,     0,   321,     0,     0,     0,    42,     0,    43,    44,
      45,   149,     1,     2,     3,     0,   142,     0,   143,   144,
       0,   145,     0,     0,     0,     0,     0,     0,    41,     0,
     370,     0,     0,     0,    42,     0,    43,    44,    45,   149,
       1,     2,     3,     0,   142,     0,   143,   144,     0,   145,
       0,     0,     0,     0,     0,     0,    41,     0,   387,     0,
       0,     0,    42,     0,    43,    44,    45,   149,     1,     2,
       3,     0,   142,     0,   143,   144,     0,   145,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
      42,     0,    43,    44,    45,   149
};

static const yytype_int16 yycheck[] =
{
      16,   103,     0,   255,   241,   285,    21,   241,    24,     7,
       8,    33,    16,    27,    30,   316,    17,     9,   177,    11,
      36,    13,     5,     6,    17,    41,    42,    20,    21,    69,
      20,    21,    22,   103,   193,    36,    40,    77,    54,    43,
     363,    42,    47,    44,    45,    46,    47,    16,   150,    20,
      21,    22,   154,   155,    47,   157,   158,    47,   103,   161,
     388,   384,   385,    55,   316,   105,    37,    40,    37,    85,
      43,   111,   400,    89,    16,    67,   116,   103,   254,    39,
     150,    36,    47,    75,   154,    40,    46,   157,   158,    87,
     327,   161,    17,   327,   109,    16,   118,   377,    40,   400,
     114,    43,    36,    16,    17,   150,   282,   283,   284,   154,
      44,    45,   157,   158,    16,    36,   161,    39,    47,    40,
      16,    28,    43,    45,   150,     0,    16,    34,   154,   155,
     146,   157,   158,    41,   236,   161,   388,    45,    40,   241,
      36,    43,   140,    17,    40,   321,    36,    43,   400,   416,
      40,    17,   254,    43,   421,   389,   150,    11,    12,   396,
     154,   177,   396,   157,   158,   181,   103,   161,    20,    21,
      22,   187,    43,    20,    21,    22,   413,   193,    47,   413,
     282,   283,   284,   285,   182,    37,    41,   421,   364,    36,
      45,    20,    21,    22,   370,    42,    47,    44,    45,    46,
      47,   323,   218,   325,   380,    36,   382,   383,    37,    40,
     236,   387,    43,   150,    41,   241,    41,   154,    45,   321,
     157,   158,     0,    47,   161,   327,    36,    37,   254,     7,
       8,    40,    42,     3,    44,    45,    46,    47,   414,    36,
      37,     4,    41,   259,   260,    42,    45,    44,    45,    46,
      47,     7,     8,     9,    10,   357,   282,   283,   284,   285,
     362,   363,   364,    36,    40,    37,    41,    43,   370,    42,
      45,    44,    45,    46,    47,   377,    40,   293,   380,    43,
     382,   383,   384,   385,    38,   387,    93,    94,    95,    96,
      40,    24,    25,    43,   396,   321,    16,    36,    47,   236,
      16,   327,    37,    42,   241,    44,    45,    46,    47,    41,
     326,   413,   414,    40,    16,    40,    43,   254,    43,    13,
      14,    15,    20,    21,    22,   323,    37,   325,    99,   100,
     101,   357,    16,   349,    16,    17,   362,   363,   364,    16,
      17,    45,   241,    40,   370,   282,   283,   284,   285,    44,
      45,   377,    24,    25,   380,    45,   382,   383,   384,   385,
      47,   387,     7,     8,    37,    91,    92,   266,    97,    98,
     396,    38,    23,    38,    45,   266,    16,    41,    37,    41,
      36,    36,    36,    36,   321,   401,    36,   413,   414,    36,
     327,   407,    17,    39,    23,    47,    17,    41,    40,   298,
     299,    23,   301,   302,   303,   304,   305,   306,   299,    23,
     301,   302,   303,   304,   305,   306,    17,    16,    16,    39,
     357,    17,    17,    39,    47,   362,   363,   364,   327,    37,
     329,   330,    45,   370,    37,    47,    16,    37,   329,   330,
     377,    17,    17,   380,    37,   382,   383,   384,   385,    41,
     387,    45,    17,    41,    43,    46,   355,    43,    17,   396,
      38,    18,    17,    37,   355,    47,    36,    17,    17,    30,
      17,   370,    17,    45,    47,    39,   413,   414,    16,   370,
      43,   380,    17,   382,   383,    37,    17,    28,    39,    19,
      36,   382,   383,    41,    37,    19,    19,   396,    16,    39,
      39,    43,    39,    37,   403,    37,    19,    19,    37,    31,
      17,    39,   403,   412,   413,   414,    36,    36,    39,    25,
      37,   412,    17,   414,    39,    20,    21,    22,    38,    24,
      39,    26,    27,    37,    29,   368,    31,    32,   155,   313,
     233,    36,   310,    38,   229,   275,    90,    42,   106,    44,
      45,    46,    47,    17,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    36,    -1,    38,    -1,    -1,    -1,    42,    -1,
      44,    45,    46,    47,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    29,    -1,    31,    32,    -1,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    45,
      46,    47,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    29,    -1,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    29,
      -1,    31,    32,    -1,    -1,    -1,    36,    -1,    38,    -1,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    29,    -1,    31,
      32,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    -1,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    45,    46,    47
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
      90,    36,    36,    36,    40,   104,   104,    77,    97,   104,
     104,   104,    39,    39,    45,    84,    17,    23,    39,    46,
      83,    41,    98,    40,    90,    17,    20,    21,    59,    79,
      90,    47,    17,    23,    23,    37,    98,    45,    17,    16,
      39,    17,    17,    16,    39,    45,    37,    47,    47,    60,
      90,    37,    37,    85,    16,    86,    17,    37,    41,    84,
      17,    83,    17,    41,    38,    52,    53,    78,    97,    43,
      43,    17,    17,    24,    31,    32,    38,    53,    58,    63,
      68,    71,    78,    97,    38,    16,    37,    18,    37,    17,
      40,    51,    53,    78,    97,    25,    65,    66,    67,    90,
      90,    47,    61,    36,    17,    17,    31,    32,    53,    58,
      64,    68,    71,    78,    80,    81,    97,    30,    72,    73,
      74,    96,    17,    47,    17,    45,    39,    51,    51,    51,
      24,    38,    52,    16,    17,    16,    43,    37,    90,    17,
      17,    64,    64,    39,    64,    64,    64,    64,    64,    64,
      36,    44,    45,    28,    76,    73,    86,    41,    66,    36,
      51,    59,    59,    90,    17,    38,    58,    37,    64,    64,
      44,    45,    19,    19,    19,    39,    90,    39,    16,    64,
      38,    37,    37,    51,    75,    75,    51,    37,    61,    39,
      53,    64,    78,    97,    19,    19,    31,    38,    52,    39,
      75,    75,    17,    51,    67,    24,    25,    68,    69,    70,
      39,    36,    24,    38,    58,    67,    90,    36,    64,    37,
      90,    39,    38,    37,    38,    53,    58,    78,    97,    64,
      70,    39,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    50,    51,    51,    51,
      51,    52,    52,    52,    53,    53,    53,    53,    54,    54,
      54,    55,    56,    57,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    59,    59,    59,    59,    60,    60,    61,
      61,    62,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    67,    67,    67,    68,    69,    69,    70,    70,
      70,    70,    70,    71,    72,    72,    73,    73,    74,    74,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    78,    79,    79,    79,    79,    80,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    84,    84,    85,    85,    86,
      86,    87,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    90,    90,    91,    91,
      92,    92,    92,    93,    93,    93,    93,    93,    94,    94,
      94,    95,    95,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    98,    98,    99,
     100,   100,   101,   102,   102,   102,   103,   104,   104,   104,
     104,   104,   104,   104,   105,   105,   106,   106,   106
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     2,     2,     2,
       0,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     7,     9,     7,     1,     1,     1,     2,     2,     1,
       1,     1,     5,     6,     6,     1,     6,     1,     0,     5,
       3,     5,     3,     1,     1,     3,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     0,     8,     6,     1,     1,
       9,     4,     7,     2,     0,     8,     1,     1,     9,     4,
       7,     2,     0,     8,     1,     0,     2,     0,     6,     4,
       6,     4,     3,     1,     3,     0,     2,     1,     1,     1,
       1,     1,     5,     4,     6,     5,     6,     6,     6,     6,
       6,     5,     5,     5,     3,     8,     7,     3,     3,     9,
       8,     9,     8,     3,     1,     3,     1,     3,     0,     4,
       0,     5,     3,     3,     2,     1,     5,     3,     3,     2,
       1,     5,     3,     3,     2,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     3,     2,     1,     1,
       1,     3,     4,     4,     7,     4,     5,     3,     1,     1,
       1,     3,     2,     1,     1,     1,     3,     2,     2,     2,
       1,     2,     2,     0,     3,     2,     3,     6,     5
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
#line 1698 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 63 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#DS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#DL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1704 "y.tab.c"
    break;

  case 4: /* declarationList: assignmentStatement declarationList  */
#line 64 "AST.y"
                                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#AS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#DL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1710 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 65 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#DS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1716 "y.tab.c"
    break;

  case 6: /* declarationList: assignmentStatement  */
#line 66 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#AS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1722 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 68 "AST.y"
                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Satements#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1728 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 69 "AST.y"
                                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Satements#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1734 "y.tab.c"
    break;

  case 9: /* statements: functionCall statements  */
#line 70 "AST.y"
                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Satements#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1740 "y.tab.c"
    break;

  case 10: /* statements: %empty  */
#line 71 "AST.y"
                     {(yyval.Str)=strdup("#Epsilon@");}
#line 1746 "y.tab.c"
    break;

  case 11: /* singleStatement: specialStatement  */
#line 72 "AST.y"
                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1752 "y.tab.c"
    break;

  case 12: /* singleStatement: basicStatement  */
#line 73 "AST.y"
                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1758 "y.tab.c"
    break;

  case 13: /* singleStatement: functionCall  */
#line 74 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1764 "y.tab.c"
    break;

  case 14: /* specialStatement: FOR forLoop  */
#line 76 "AST.y"
                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#for@#");strcat(temp,"FL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1770 "y.tab.c"
    break;

  case 15: /* specialStatement: ifStatement  */
#line 77 "AST.y"
                                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IFS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1776 "y.tab.c"
    break;

  case 16: /* specialStatement: whileLoop  */
#line 78 "AST.y"
                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#WL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1782 "y.tab.c"
    break;

  case 17: /* specialStatement: switchStatement  */
#line 79 "AST.y"
                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SWS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1788 "y.tab.c"
    break;

  case 18: /* forLoop: forLoop2  */
#line 81 "AST.y"
                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FLMany#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1794 "y.tab.c"
    break;

  case 19: /* forLoop: forLoop3  */
#line 82 "AST.y"
                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FL1#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1800 "y.tab.c"
    break;

  case 20: /* forLoop: forLoop1  */
#line 83 "AST.y"
                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1806 "y.tab.c"
    break;

  case 21: /* forLoop1: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON  */
#line 86 "AST.y"
                                                                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#");strcat(temp,"ForA#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#ForE#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#;@#ForU#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#;@");(yyval.Str)=strdup(temp);}
#line 1812 "y.tab.c"
    break;

  case 22: /* forLoop2: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR inLoop CLCUR  */
#line 87 "AST.y"
                                                                                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#");strcat(temp,"ForA#");strcat(temp,(yyvsp[-7].Str));strcat(temp,"@@#ForE#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@#;@#ForU#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#)@#{@");strcat(temp,"#InL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 1818 "y.tab.c"
    break;

  case 23: /* forLoop3: OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC singleLoopStatement  */
#line 88 "AST.y"
                                                                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#");strcat(temp,"ForA#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#ForE#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#;@#ForU#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#");strcat(temp,"SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1824 "y.tab.c"
    break;

  case 24: /* singleLoopStatement: specialStatement  */
#line 90 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1830 "y.tab.c"
    break;

  case 25: /* singleLoopStatement: basicStatement  */
#line 91 "AST.y"
                                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1836 "y.tab.c"
    break;

  case 26: /* singleLoopStatement: functionCall  */
#line 92 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1842 "y.tab.c"
    break;

  case 27: /* singleLoopStatement: BREAK SEMICOLON  */
#line 93 "AST.y"
                                                          {(yyval.Str)=strdup("#break@#;@");}
#line 1848 "y.tab.c"
    break;

  case 28: /* singleLoopStatement: CONTINUE SEMICOLON  */
#line 94 "AST.y"
                                                             {(yyval.Str)=strdup("#continue@#;@");}
#line 1854 "y.tab.c"
    break;

  case 29: /* singleLoopStatement: switchStatement  */
#line 95 "AST.y"
                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SWS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1860 "y.tab.c"
    break;

  case 30: /* singleLoopStatement: ifInLoopStatement  */
#line 96 "AST.y"
                                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfLoop#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1866 "y.tab.c"
    break;

  case 31: /* forAssignStatement: assignmentStatement  */
#line 98 "AST.y"
                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FA#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1872 "y.tab.c"
    break;

  case 32: /* forAssignStatement: INT IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 99 "AST.y"
                                                                                             {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@#=@#ES#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 1878 "y.tab.c"
    break;

  case 33: /* forAssignStatement: INT IDENTIFIER EQUAL expressionStatement COMMA forAssignStatement  */
#line 100 "AST.y"
                                                                                                            {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#FA#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1884 "y.tab.c"
    break;

  case 34: /* forAssignStatement: CHAR IDENTIFIER EQUAL expressionStatement COMMA forAssignStatement  */
#line 101 "AST.y"
                                                                                                             {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#FA#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1890 "y.tab.c"
    break;

  case 37: /* forExpStatement: expressionStatement  */
#line 105 "AST.y"
                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1896 "y.tab.c"
    break;

  case 38: /* forExpStatement: %empty  */
#line 106 "AST.y"
                                  {(yyval.Str)=strdup("#Epsilon@");}
#line 1902 "y.tab.c"
    break;

  case 39: /* forUpdateStatement: IDENTIFIER EQUAL expressionStatement COMMA forUpdateStatement  */
#line 108 "AST.y"
                                                                                   {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#ForU#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1908 "y.tab.c"
    break;

  case 41: /* whileLoop: WHILE OPBRAC expressionStatement CLBRAC whileSuffix  */
#line 111 "AST.y"
                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#while@#(@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#WSuffix#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1914 "y.tab.c"
    break;

  case 42: /* whileSuffix: OPCUR inLoop CLCUR  */
#line 113 "AST.y"
                                 {char *temp;temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#{@#InL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 1920 "y.tab.c"
    break;

  case 43: /* whileSuffix: SEMICOLON  */
#line 114 "AST.y"
                              {(yyval.Str)=strdup(";");}
#line 1926 "y.tab.c"
    break;

  case 44: /* whileSuffix: singleLoopStatement  */
#line 115 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SLS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1932 "y.tab.c"
    break;

  case 45: /* inLoop: BREAK SEMICOLON inLoop  */
#line 117 "AST.y"
                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#break@#;@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1938 "y.tab.c"
    break;

  case 46: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 118 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#continue@#;@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1944 "y.tab.c"
    break;

  case 47: /* inLoop: specialStatement inLoop  */
#line 119 "AST.y"
                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1950 "y.tab.c"
    break;

  case 48: /* inLoop: basicStatement inLoop  */
#line 120 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1956 "y.tab.c"
    break;

  case 49: /* inLoop: functionCall inLoop  */
#line 121 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1962 "y.tab.c"
    break;

  case 50: /* inLoop: ifInLoopStatement inLoop  */
#line 122 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfInL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1968 "y.tab.c"
    break;

  case 51: /* inLoop: switchStatement inLoop  */
#line 123 "AST.y"
                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1974 "y.tab.c"
    break;

  case 52: /* inLoop: singleLoopStatement inLoop  */
#line 124 "AST.y"
                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SLS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1980 "y.tab.c"
    break;

  case 53: /* inLoop: printer inLoop  */
#line 125 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#printer#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1986 "y.tab.c"
    break;

  case 54: /* inLoop: Scanner inLoop  */
#line 126 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Scanner#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#InL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 1992 "y.tab.c"
    break;

  case 55: /* inLoop: %empty  */
#line 127 "AST.y"
                  {(yyval.Str)=strdup("#Epsilon@");}
#line 1998 "y.tab.c"
    break;

  case 56: /* ifStatement: IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ifContinuer  */
#line 129 "AST.y"
                                                                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IF@#(@#ES#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#)@#{@#Satements#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2004 "y.tab.c"
    break;

  case 57: /* ifStatement: IF OPBRAC expressionStatement CLBRAC singleStatement ifContinuer  */
#line 130 "AST.y"
                                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IF@#(@#ES#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#)@#SingleS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2010 "y.tab.c"
    break;

  case 58: /* ifContinuer: ES  */
#line 132 "AST.y"
                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2016 "y.tab.c"
    break;

  case 59: /* ifContinuer: ifStatement  */
#line 133 "AST.y"
                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IfS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2022 "y.tab.c"
    break;

  case 60: /* ES: ELSE IF OPBRAC expressionStatement CLBRAC OPCUR statements CLCUR ES  */
#line 135 "AST.y"
                                                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#)@#{@#STMTS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2028 "y.tab.c"
    break;

  case 61: /* ES: ELSE OPCUR statements CLCUR  */
#line 136 "AST.y"
                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#{@#STMTS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2034 "y.tab.c"
    break;

  case 62: /* ES: ELSE IF OPBRAC expressionStatement CLBRAC singleStatement ES  */
#line 137 "AST.y"
                                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#)@#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#ElS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2040 "y.tab.c"
    break;

  case 63: /* ES: ELSE singleStatement  */
#line 138 "AST.y"
                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2046 "y.tab.c"
    break;

  case 64: /* ES: %empty  */
#line 138 "AST.y"
                                                                                                                                                                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2052 "y.tab.c"
    break;

  case 65: /* ifInLoopStatement: IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ifInLoopContinuer  */
#line 140 "AST.y"
                                                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#if@#(@#ES#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#)@#{@#IL#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#IILC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2058 "y.tab.c"
    break;

  case 66: /* ifInLoopContinuer: ESLoop  */
#line 140 "AST.y"
                                                                                                                                                                                                                                                                                                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ESL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2064 "y.tab.c"
    break;

  case 67: /* ifInLoopContinuer: ifInLoopStatement  */
#line 140 "AST.y"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#IILS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2070 "y.tab.c"
    break;

  case 68: /* ESLoop: ELSE IF OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR ESLoop  */
#line 142 "AST.y"
                                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#)@#IL#");strcat(temp,(yyvsp[-3].Str)); strcat(temp,"@@#ESL#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2076 "y.tab.c"
    break;

  case 69: /* ESLoop: ELSE OPCUR inLoop CLCUR  */
#line 143 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#{@#IL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2082 "y.tab.c"
    break;

  case 70: /* ESLoop: ELSE IF OPBRAC expressionStatement CLBRAC singleLoopStatement ESLoop  */
#line 144 "AST.y"
                                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#elseif@#(@#ES#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#)@#SLS#");strcat(temp,(yyvsp[-1].Str)); strcat(temp,"@@#ESL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2088 "y.tab.c"
    break;

  case 71: /* ESLoop: ELSE singleLoopStatement  */
#line 145 "AST.y"
                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#else@#SLS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2094 "y.tab.c"
    break;

  case 72: /* ESLoop: %empty  */
#line 145 "AST.y"
                                                                                                                                                                                  {(yyval.Str)=strdup("#Epsilon@");}
#line 2100 "y.tab.c"
    break;

  case 73: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR  */
#line 147 "AST.y"
                                                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000); strcat(temp,"#switch@#(@#Identifier#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#(@#{@#CS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#DS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2106 "y.tab.c"
    break;

  case 74: /* caseStatements: caseStatementInt  */
#line 149 "AST.y"
                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#CSI#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2112 "y.tab.c"
    break;

  case 75: /* caseStatements: %empty  */
#line 150 "AST.y"
                                  {(yyval.Str)=strdup("#Epsilon@");}
#line 2118 "y.tab.c"
    break;

  case 76: /* caseStatementInt: caseInt caseStatementInt  */
#line 152 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#CI#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#CSI#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2124 "y.tab.c"
    break;

  case 77: /* caseStatementInt: %empty  */
#line 153 "AST.y"
                                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2130 "y.tab.c"
    break;

  case 78: /* caseInt: CASE OPBRAC INTVAL CLBRAC COLON caseContinuer  */
#line 155 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#(@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#)@#:@#CC#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2136 "y.tab.c"
    break;

  case 79: /* caseInt: CASE INTVAL COLON caseContinuer  */
#line 156 "AST.y"
                                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#:@#CC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2142 "y.tab.c"
    break;

  case 80: /* caseInt: CASE OPBRAC CHARVAL CLBRAC COLON caseContinuer  */
#line 157 "AST.y"
                                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#(@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#)@#:@#CC#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2148 "y.tab.c"
    break;

  case 81: /* caseInt: CASE CHARVAL COLON caseContinuer  */
#line 158 "AST.y"
                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#case@#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#:@#CC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2154 "y.tab.c"
    break;

  case 82: /* caseContinuer: statements BREAK SEMICOLON  */
#line 160 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#STMTS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#break@#;@");(yyval.Str)=strdup(temp);}
#line 2160 "y.tab.c"
    break;

  case 83: /* caseContinuer: statements  */
#line 161 "AST.y"
                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#STMTS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2166 "y.tab.c"
    break;

  case 84: /* defaultStatement: DEFAULT COLON statements  */
#line 163 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#default@#:@#STMTS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2172 "y.tab.c"
    break;

  case 85: /* defaultStatement: %empty  */
#line 164 "AST.y"
                                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2178 "y.tab.c"
    break;

  case 86: /* basicStatements: basicStatement basicStatements  */
#line 167 "AST.y"
                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#BSs#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2184 "y.tab.c"
    break;

  case 87: /* basicStatements: basicStatement  */
#line 168 "AST.y"
                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2190 "y.tab.c"
    break;

  case 88: /* basicStatement: expressionStatement  */
#line 170 "AST.y"
                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2196 "y.tab.c"
    break;

  case 89: /* basicStatement: declarationStatement  */
#line 171 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#DS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2202 "y.tab.c"
    break;

  case 90: /* basicStatement: assignmentStatement  */
#line 172 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#AS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2208 "y.tab.c"
    break;

  case 91: /* basicStatement: functionCall  */
#line 172 "AST.y"
                                                                                                                                                                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2214 "y.tab.c"
    break;

  case 92: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 174 "AST.y"
                                                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@");strcat(temp,"#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#AS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2220 "y.tab.c"
    break;

  case 93: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 175 "AST.y"
                                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@");strcat(temp,"#=@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2226 "y.tab.c"
    break;

  case 94: /* assignmentStatement: IDENTIFIER dimension EQUAL expressionStatement COMMA assignmentStatement  */
#line 175 "AST.y"
                                                                                                                                                                                                                                                                                                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#AS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2232 "y.tab.c"
    break;

  case 95: /* assignmentStatement: IDENTIFIER dimension EQUAL expressionStatement SEMICOLON  */
#line 176 "AST.y"
                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2238 "y.tab.c"
    break;

  case 96: /* printer: PRINTF OPBRAC STRING prattributes CLBRAC SEMICOLON  */
#line 178 "AST.y"
                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#printf@#(@#String#\\");strcat(temp,(yyvsp[-3].Str));strcat(temp,"\\\"@@#PrA#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#;@");(yyval.Str)=strdup(temp);}
#line 2244 "y.tab.c"
    break;

  case 97: /* Scanner: SCANF OPBRAC STRING scattributes CLBRAC SEMICOLON  */
#line 179 "AST.y"
                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#scanf@#(@#String#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#SCA#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#;@");(yyval.Str)=strdup(temp);}
#line 2250 "y.tab.c"
    break;

  case 98: /* declarationStatement: INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 181 "AST.y"
                                                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#(@#PS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2256 "y.tab.c"
    break;

  case 99: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 182 "AST.y"
                                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#(@#PS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2262 "y.tab.c"
    break;

  case 100: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 183 "AST.y"
                                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#(@#PS#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2268 "y.tab.c"
    break;

  case 101: /* declarationStatement: INT IDENTIFIER OPBRAC CLBRAC compoundStatements  */
#line 184 "AST.y"
                                                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2274 "y.tab.c"
    break;

  case 102: /* declarationStatement: FLOAT IDENTIFIER OPBRAC CLBRAC compoundStatements  */
#line 185 "AST.y"
                                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2280 "y.tab.c"
    break;

  case 103: /* declarationStatement: CHAR IDENTIFIER OPBRAC CLBRAC compoundStatements  */
#line 186 "AST.y"
                                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#)@#CS#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2286 "y.tab.c"
    break;

  case 104: /* declarationStatement: INT declarationListInt SEMICOLON  */
#line 187 "AST.y"
                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#DLI#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2292 "y.tab.c"
    break;

  case 105: /* declarationStatement: CHAR IDENTIFIER BOXOPEN INTVAL BOXCLOSE EQUAL STRING SEMICOLON  */
#line 188 "AST.y"
                                                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@#[@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#]@#=@#STRING#\\");strcat(temp,(yyvsp[-1].Str));strcat(temp,"\\\"@@#;@");(yyval.Str)=strdup(temp);}
#line 2298 "y.tab.c"
    break;

  case 106: /* declarationStatement: CHAR IDENTIFIER BOXOPEN BOXCLOSE EQUAL STRING SEMICOLON  */
#line 189 "AST.y"
                                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#Identifier#");strcat(temp,(yyvsp[-5].Str));strcat(temp,"@@#[@#]@#=@#STRING#\\");strcat(temp,(yyvsp[-1].Str));strcat(temp,"\\\"@@#;@");(yyval.Str)=strdup(temp);}
#line 2304 "y.tab.c"
    break;

  case 107: /* declarationStatement: CHAR declarationListChar SEMICOLON  */
#line 190 "AST.y"
                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#char@#DLC#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2310 "y.tab.c"
    break;

  case 108: /* declarationStatement: FLOAT declarationListFloat SEMICOLON  */
#line 191 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#DLF#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2316 "y.tab.c"
    break;

  case 109: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValues CLCUR SEMICOLON  */
#line 192 "AST.y"
                                                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,(yyvsp[-7].Str));strcat(temp,"@@#[@#]@#=@#{@#AV#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#;@");(yyval.Str)=strdup(temp);}
#line 2322 "y.tab.c"
    break;

  case 110: /* declarationStatement: INT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON  */
#line 193 "AST.y"
                                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#int@#Identifier#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@#[@#]@#=@#{@#}@#;@");(yyval.Str)=strdup(temp);}
#line 2328 "y.tab.c"
    break;

  case 111: /* declarationStatement: FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR arrayValuesF CLCUR SEMICOLON  */
#line 193 "AST.y"
                                                                                                                                                                                                                                                                                                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,(yyvsp[-7].Str));strcat(temp,"@@#[@#]@#=@#{@#AVF#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#}@#;@");(yyval.Str)=strdup(temp);}
#line 2334 "y.tab.c"
    break;

  case 112: /* declarationStatement: FLOAT IDENTIFIER BOXOPEN BOXCLOSE EQUAL OPCUR CLCUR SEMICOLON  */
#line 194 "AST.y"
                                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#float@#Identifier#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@#[@#]@#=@#{@#}@#;@");(yyval.Str)=strdup(temp);}
#line 2340 "y.tab.c"
    break;

  case 113: /* arrayValuesF: FLOATVAL COMMA arrayValuesF  */
#line 197 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#,@#AVF#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2346 "y.tab.c"
    break;

  case 114: /* arrayValuesF: FLOATVAL  */
#line 198 "AST.y"
                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2352 "y.tab.c"
    break;

  case 115: /* arrayValues: INTVAL COMMA arrayValues  */
#line 200 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#,@#AV#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2358 "y.tab.c"
    break;

  case 116: /* arrayValues: INTVAL  */
#line 201 "AST.y"
                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2364 "y.tab.c"
    break;

  case 117: /* prattributes: prattributes COMMA factor  */
#line 203 "AST.y"
                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#PrA#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#factor#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2370 "y.tab.c"
    break;

  case 118: /* prattributes: %empty  */
#line 204 "AST.y"
                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2376 "y.tab.c"
    break;

  case 119: /* scattributes: COMMA AMPERSAND IDENTIFIER scattributes  */
#line 206 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#,@#&@#Identifier#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#,@#SCA#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2382 "y.tab.c"
    break;

  case 120: /* scattributes: %empty  */
#line 207 "AST.y"
                          {(yyval.Str)=strdup("#Epsilon@");}
#line 2388 "y.tab.c"
    break;

  case 121: /* declarationListInt: IDENTIFIER EQUAL expressionStatement COMMA declarationListInt  */
#line 209 "AST.y"
                                                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLI#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2394 "y.tab.c"
    break;

  case 122: /* declarationListInt: IDENTIFIER COMMA declarationListInt  */
#line 210 "AST.y"
                                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLI#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2400 "y.tab.c"
    break;

  case 123: /* declarationListInt: IDENTIFIER EQUAL expressionStatement  */
#line 211 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2406 "y.tab.c"
    break;

  case 124: /* declarationListInt: IDENTIFIER dimension  */
#line 212 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2412 "y.tab.c"
    break;

  case 125: /* declarationListInt: IDENTIFIER  */
#line 213 "AST.y"
                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2418 "y.tab.c"
    break;

  case 126: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListFloat  */
#line 215 "AST.y"
                                                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLF#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2424 "y.tab.c"
    break;

  case 127: /* declarationListFloat: IDENTIFIER COMMA declarationListFloat  */
#line 216 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLF#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2430 "y.tab.c"
    break;

  case 128: /* declarationListFloat: IDENTIFIER EQUAL expressionStatement  */
#line 217 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2436 "y.tab.c"
    break;

  case 129: /* declarationListFloat: IDENTIFIER dimension  */
#line 218 "AST.y"
                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2442 "y.tab.c"
    break;

  case 130: /* declarationListFloat: IDENTIFIER  */
#line 219 "AST.y"
                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2448 "y.tab.c"
    break;

  case 131: /* declarationListChar: IDENTIFIER EQUAL CHARVAL COMMA declarationListChar  */
#line 221 "AST.y"
                                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#=@#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@#,@#DLC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2454 "y.tab.c"
    break;

  case 132: /* declarationListChar: IDENTIFIER COMMA declarationListChar  */
#line 222 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#DLC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2460 "y.tab.c"
    break;

  case 133: /* declarationListChar: IDENTIFIER EQUAL expressionStatement  */
#line 223 "AST.y"
                                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#=@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2466 "y.tab.c"
    break;

  case 134: /* declarationListChar: IDENTIFIER dimension  */
#line 224 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Dim#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2472 "y.tab.c"
    break;

  case 135: /* declarationListChar: IDENTIFIER  */
#line 225 "AST.y"
                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2478 "y.tab.c"
    break;

  case 136: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 227 "AST.y"
                                                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#LE#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#||@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2484 "y.tab.c"
    break;

  case 137: /* expressionStatement: logicalExpression  */
#line 228 "AST.y"
                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#LE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2490 "y.tab.c"
    break;

  case 138: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 230 "AST.y"
                                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Exp#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#&&@#LE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2496 "y.tab.c"
    break;

  case 139: /* logicalExpression: expression  */
#line 231 "AST.y"
                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Exp#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2502 "y.tab.c"
    break;

  case 140: /* expression: relationalExpression EQUALS expression  */
#line 233 "AST.y"
                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RE#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#==@#Exp#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2508 "y.tab.c"
    break;

  case 141: /* expression: relationalExpression NOTEQUAL expression  */
#line 234 "AST.y"
                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RE#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#!=@#Exp#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2514 "y.tab.c"
    break;

  case 142: /* expression: relationalExpression  */
#line 235 "AST.y"
                                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2520 "y.tab.c"
    break;

  case 143: /* relationalExpression: value GREATERTHAN relationalExpression  */
#line 237 "AST.y"
                                                              {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#>@#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2526 "y.tab.c"
    break;

  case 144: /* relationalExpression: value GREATERTHANEQUALTO relationalExpression  */
#line 238 "AST.y"
                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#>=@#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2532 "y.tab.c"
    break;

  case 145: /* relationalExpression: value LESSTHAN relationalExpression  */
#line 239 "AST.y"
                                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#<@#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2538 "y.tab.c"
    break;

  case 146: /* relationalExpression: value LESSTHANEQUALTO relationalExpression  */
#line 240 "AST.y"
                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#<=@#RE#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2544 "y.tab.c"
    break;

  case 147: /* relationalExpression: value  */
#line 241 "AST.y"
                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#value#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2550 "y.tab.c"
    break;

  case 148: /* value: term ADD value  */
#line 243 "AST.y"
                       {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#term#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#+@#value#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2556 "y.tab.c"
    break;

  case 149: /* value: term SUB value  */
#line 244 "AST.y"
                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#term#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#-@#value#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2562 "y.tab.c"
    break;

  case 150: /* value: term  */
#line 245 "AST.y"
               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#term#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2568 "y.tab.c"
    break;

  case 151: /* term: factor MULT term  */
#line 247 "AST.y"
                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#*@#term#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2574 "y.tab.c"
    break;

  case 152: /* term: factor DIV term  */
#line 248 "AST.y"
                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#/@#term#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2580 "y.tab.c"
    break;

  case 153: /* term: factor MOD term  */
#line 249 "AST.y"
                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#%@#term#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2586 "y.tab.c"
    break;

  case 154: /* term: factor  */
#line 250 "AST.y"
                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#factor#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2592 "y.tab.c"
    break;

  case 155: /* factor: IDENTIFIER  */
#line 252 "AST.y"
                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2598 "y.tab.c"
    break;

  case 156: /* factor: OPBRAC expressionStatement CLBRAC  */
#line 253 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#(@#ES#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#)@");(yyval.Str)=strdup(temp);}
#line 2604 "y.tab.c"
    break;

  case 157: /* factor: LOGICALNOT expressionStatement  */
#line 254 "AST.y"
                                         {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#!@#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2610 "y.tab.c"
    break;

  case 158: /* factor: CHARVAL  */
#line 255 "AST.y"
                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2616 "y.tab.c"
    break;

  case 159: /* factor: INTVAL  */
#line 256 "AST.y"
                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2622 "y.tab.c"
    break;

  case 160: /* factor: FLOATVAL  */
#line 257 "AST.y"
                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@");(yyval.Str)=strdup(temp);}
#line 2628 "y.tab.c"
    break;

  case 161: /* factor: IDENTIFIER OPBRAC CLBRAC  */
#line 257 "AST.y"
                                                                                                                                                                                   {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#(@#)@");(yyval.Str)=strdup(temp);}
#line 2634 "y.tab.c"
    break;

  case 162: /* factor: IDENTIFIER OPBRAC argList CLBRAC  */
#line 257 "AST.y"
                                                                                                                                                                                                                                                                                                                                                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#AL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#)@");(yyval.Str)=strdup(temp);}
#line 2640 "y.tab.c"
    break;

  case 163: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE  */
#line 258 "AST.y"
                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@");strcat(temp,"#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2646 "y.tab.c"
    break;

  case 164: /* factor: IDENTIFIER BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 259 "AST.y"
                                                                     {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-6].Str));strcat(temp,"@@");strcat(temp,"#[@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#]@#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2652 "y.tab.c"
    break;

  case 165: /* functionCall: IDENTIFIER OPBRAC CLBRAC SEMICOLON  */
#line 262 "AST.y"
                                                  {{char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-3].Str));strcat(temp,"@@#(@#;@");(yyval.Str)=strdup(temp);}}
#line 2658 "y.tab.c"
    break;

  case 166: /* functionCall: IDENTIFIER OPBRAC argList CLBRAC SEMICOLON  */
#line 263 "AST.y"
                                                          {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Identifier#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@@#(@#AL#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#)@#;@");(yyval.Str)=strdup(temp);}
#line 2664 "y.tab.c"
    break;

  case 167: /* argList: expressionStatement COMMA argList  */
#line 266 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#AL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2670 "y.tab.c"
    break;

  case 168: /* argList: expressionStatement  */
#line 267 "AST.y"
                                      {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#ES#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2676 "y.tab.c"
    break;

  case 169: /* parameters: paramContinuer  */
#line 269 "AST.y"
                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#PC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2682 "y.tab.c"
    break;

  case 170: /* paramContinuer: parameter  */
#line 270 "AST.y"
                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#P#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2688 "y.tab.c"
    break;

  case 171: /* paramContinuer: parameter COMMA paramContinuer  */
#line 271 "AST.y"
                                                                  {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#P#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#,@#PC#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2694 "y.tab.c"
    break;

  case 172: /* parameter: type IDENTIFIER  */
#line 273 "AST.y"
                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#type#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#Identifier#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2700 "y.tab.c"
    break;

  case 173: /* type: INT  */
#line 275 "AST.y"
           {(yyval.Str)=strdup("#int@");}
#line 2706 "y.tab.c"
    break;

  case 174: /* type: FLOAT  */
#line 276 "AST.y"
                        {(yyval.Str)=strdup("#float@");}
#line 2712 "y.tab.c"
    break;

  case 175: /* type: CHAR  */
#line 277 "AST.y"
                        {(yyval.Str)=strdup("#char@");}
#line 2718 "y.tab.c"
    break;

  case 176: /* compoundStatements: OPCUR statementList CLCUR  */
#line 279 "AST.y"
                                               {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#{@#SL#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#}@");(yyval.Str)=strdup(temp);}
#line 2724 "y.tab.c"
    break;

  case 177: /* statementList: functionCall statementList  */
#line 281 "AST.y"
                                           {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#FC#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2730 "y.tab.c"
    break;

  case 178: /* statementList: basicStatements statementList  */
#line 282 "AST.y"
                                                                {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#BS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2736 "y.tab.c"
    break;

  case 179: /* statementList: specialStatement statementList  */
#line 283 "AST.y"
                                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#SS#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2742 "y.tab.c"
    break;

  case 180: /* statementList: returnDec  */
#line 284 "AST.y"
                                            {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#RD#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2748 "y.tab.c"
    break;

  case 181: /* statementList: printer statementList  */
#line 285 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#printer#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2754 "y.tab.c"
    break;

  case 182: /* statementList: Scanner statementList  */
#line 286 "AST.y"
                                                        {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#Scanner#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@@#SL#");strcat(temp,(yyvsp[0].Str));strcat(temp,"@@");(yyval.Str)=strdup(temp);}
#line 2760 "y.tab.c"
    break;

  case 183: /* statementList: %empty  */
#line 287 "AST.y"
                                  {(yyval.Str)=strdup("#Epsilon@");}
#line 2766 "y.tab.c"
    break;

  case 184: /* returnDec: RETURN expressionStatement SEMICOLON  */
#line 289 "AST.y"
                                                 {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#return@#ES#");strcat(temp,(yyvsp[-2].Str));strcat(temp,"@@#;@");(yyval.Str)=strdup(temp);}
#line 2772 "y.tab.c"
    break;

  case 185: /* returnDec: RETURN SEMICOLON  */
#line 290 "AST.y"
                                           {(yyval.Str)=strdup("#return@#;@");}
#line 2778 "y.tab.c"
    break;

  case 186: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 292 "AST.y"
                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2784 "y.tab.c"
    break;

  case 187: /* dimension: BOXOPEN INTVAL BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 293 "AST.y"
                                                                    {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#[@#");strcat(temp,(yyvsp[-4].Str));strcat(temp,"@#]@#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2790 "y.tab.c"
    break;

  case 188: /* dimension: BOXOPEN BOXCLOSE BOXOPEN INTVAL BOXCLOSE  */
#line 294 "AST.y"
                                                             {char* temp; temp=(char *)malloc(sizeof(char)*10000);strcat(temp,"#[@#]@#[@#");strcat(temp,(yyvsp[-1].Str));strcat(temp,"@#]@");(yyval.Str)=strdup(temp);}
#line 2796 "y.tab.c"
    break;


#line 2800 "y.tab.c"

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

#line 295 "AST.y"

 
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
