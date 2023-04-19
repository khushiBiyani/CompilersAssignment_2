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
#line 1 "SyntaxAnalyzer.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>

#line 77 "y.tab.c"

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
  YYSYMBOL_declarationStatement = 72,      /* declarationStatement  */
  YYSYMBOL_prattributes = 73,              /* prattributes  */
  YYSYMBOL_scattributes = 74,              /* scattributes  */
  YYSYMBOL_declarationListIntFloat = 75,   /* declarationListIntFloat  */
  YYSYMBOL_declarationListChar = 76,       /* declarationListChar  */
  YYSYMBOL_expressionStatement = 77,       /* expressionStatement  */
  YYSYMBOL_logicalExpression = 78,         /* logicalExpression  */
  YYSYMBOL_expression = 79,                /* expression  */
  YYSYMBOL_relationalExpression = 80,      /* relationalExpression  */
  YYSYMBOL_value = 81,                     /* value  */
  YYSYMBOL_term = 82,                      /* term  */
  YYSYMBOL_factor = 83,                    /* factor  */
  YYSYMBOL_functionCall = 84,              /* functionCall  */
  YYSYMBOL_argList = 85,                   /* argList  */
  YYSYMBOL_parameters = 86,                /* parameters  */
  YYSYMBOL_parameter = 87,                 /* parameter  */
  YYSYMBOL_type = 88,                      /* type  */
  YYSYMBOL_compoundStatements = 89,        /* compoundStatements  */
  YYSYMBOL_statementList = 90,             /* statementList  */
  YYSYMBOL_returnDec = 91,                 /* returnDec  */
  YYSYMBOL_dimension = 92                  /* dimension  */
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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   532

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  358

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
static const yytype_uint8 yyrline[] =
{
       0,    30,    30,    32,    33,    34,    35,    37,    38,    39,
      40,    42,    43,    44,    45,    48,    49,    50,    52,    53,
      54,    55,    56,    57,    58,    60,    61,    62,    63,    64,
      65,    66,    66,    67,    68,    71,    72,    73,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    85,    86,    88,
      89,    90,    92,    93,    95,    96,    97,    99,   100,   100,
     101,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   110,   113,   114,   116,   117,   118,   120,   121,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   137,   137,   138,   138,   140,   141,   142,   143,
     144,   146,   147,   148,   149,   150,   152,   153,   155,   156,
     158,   159,   160,   162,   163,   164,   165,   166,   168,   169,
     170,   172,   173,   174,   175,   177,   178,   179,   180,   181,
     182,   183,   184,   191,   192,   195,   195,   197,   197,   199,
     201,   201,   201,   203,   205,   205,   205,   205,   205,   207,
     207,   211,   213,   214,   215
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
  "basicStatement", "assignmentStatement", "declarationStatement",
  "prattributes", "scattributes", "declarationListIntFloat",
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

#define YYPACT_NINF (-229)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      97,    -3,     5,    21,    31,    49,    57,   130,  -229,    97,
      97,    -4,    75,    26,    93,    44,   131,   136,   143,   134,
    -229,  -229,  -229,   125,    87,    37,   134,  -229,  -229,   133,
      92,    99,   147,  -229,  -229,   113,  -229,   208,   227,   134,
     134,   202,  -229,  -229,  -229,     8,   241,   243,   158,   192,
     178,   169,    61,  -229,  -229,  -229,  -229,   213,   215,   238,
     211,   217,   222,   251,    63,  -229,   213,   235,   -21,   236,
     260,   213,   245,   234,   246,   266,   252,   253,  -229,   250,
     254,  -229,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   445,  -229,   213,   194,  -229,
     256,   257,   125,  -229,   213,   276,    54,   133,  -229,   213,
     208,   283,   263,   291,  -229,   268,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
     267,   274,   277,   278,   279,    12,    85,   445,  -229,  -229,
    -229,  -229,   445,   259,  -229,  -229,  -229,   445,   273,  -229,
    -229,  -229,   275,   272,  -229,  -229,   303,   298,  -229,  -229,
    -229,  -229,   227,  -229,   285,    59,   134,    17,   134,   284,
    -229,   312,   485,  -229,  -229,   112,  -229,  -229,  -229,  -229,
     290,  -229,   315,  -229,   287,   110,   297,  -229,   295,   302,
     134,  -229,   310,   314,  -229,   318,  -229,     7,  -229,  -229,
     311,   117,   317,   320,   321,   343,  -229,   358,   323,  -229,
     134,   348,  -229,   344,   473,   134,   134,   322,  -229,   332,
     352,   355,   417,  -229,  -229,  -229,  -229,  -229,  -229,   347,
    -229,  -229,   303,   334,   473,   473,   473,   187,   195,   331,
     346,   134,  -229,  -229,   364,   369,   417,   417,   356,   417,
     417,   417,   417,   -18,   363,  -229,   347,   170,  -229,  -229,
    -229,    17,  -229,    17,  -229,   134,   389,   360,   417,   417,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,   163,   379,   380,
     382,   368,  -229,    -8,  -229,  -229,  -229,  -229,   392,  -229,
     417,  -229,   374,  -229,  -229,   377,   385,   473,   473,   473,
    -229,   381,   473,   322,   387,   417,   400,   409,   398,   399,
    -229,   134,   393,  -229,  -229,   417,   401,   417,   417,   473,
     473,   425,   428,   410,  -229,   209,   419,   423,  -229,  -229,
     418,   421,    -7,  -229,  -229,   438,   441,   473,   134,   424,
     417,  -229,  -229,   429,   433,   134,   434,   450,   439,   446,
    -229,  -229,   417,   444,   417,   437,   459,  -229
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     2,     6,
       5,   100,     0,   105,     0,   100,     0,     0,     0,     0,
       1,     4,     3,     0,     0,     0,     0,    99,    85,     0,
       0,     0,     0,   104,    88,     0,    89,    93,    95,     0,
       0,   125,   128,   129,   130,     0,   107,   109,   112,   117,
     120,   124,   100,    97,   140,   142,   141,     0,     0,   137,
       0,     0,     0,    98,   105,   102,     0,     0,     0,     0,
     103,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,    82,     0,     0,   139,
       0,   152,     0,    84,     0,     0,   152,     0,    83,     0,
      93,     0,     0,     0,   126,     0,    77,   106,   108,   110,
     111,   113,   114,   115,   116,   118,   119,   121,   122,   123,
       0,     0,     0,     0,     0,     0,   125,   148,    11,    13,
      12,    14,   148,    73,    76,    75,    74,   148,     0,   147,
      79,   138,     0,     0,    96,    80,     0,     0,   101,    81,
      92,    90,    95,    91,   131,   105,     0,     0,     0,     0,
     150,     0,     0,   145,   144,   125,    72,   146,   143,   154,
       0,    87,     0,    94,     0,     0,     0,    30,     0,     0,
      32,    25,     0,     0,   149,     0,   136,     0,   153,    86,
       0,     0,     0,     0,     0,     0,    31,     0,     0,   133,
       0,     0,   132,     0,    10,     0,     0,     0,    36,     0,
       0,     0,    46,    18,    37,    24,    14,    19,    20,    59,
     135,   134,   151,     0,    10,    10,    10,     0,     0,     0,
       0,     0,    21,    22,     0,     0,    18,    46,     0,    24,
      14,    19,    20,     0,    71,    58,    61,    51,     7,     8,
       9,     0,    26,     0,    28,     0,     0,     0,    21,    22,
      40,    45,    35,    43,    44,    41,    42,     0,     0,     0,
       0,     0,    60,     0,    48,    47,    27,    29,    34,    16,
      46,    17,     0,    38,    39,     0,     0,    10,    10,    10,
      57,     0,    10,     0,     0,    10,     0,     0,    69,    65,
      70,     0,     0,    33,    15,    10,     0,    10,    10,    10,
      10,     0,     0,     0,    50,    56,    67,    63,    68,    64,
       0,     0,     0,    53,    52,     0,     0,    10,     0,     0,
      46,    66,    62,     0,     0,     0,     0,    51,     0,     0,
      55,    49,    46,     0,    46,     0,    56,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -229,  -229,   226,    39,   -49,  -229,  -192,  -228,  -229,   182,
    -229,  -179,   229,   141,  -202,   140,    51,  -229,   242,  -229,
    -229,   361,   -92,     1,   127,   391,   341,     3,   -25,   -19,
     422,   153,   132,   150,   137,  -229,    25,  -229,   -22,  -229,
    -229,   -57,   -51,  -229,   -11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     7,     8,   233,   246,   138,   247,   190,   205,   240,
     139,   270,   140,   285,   249,   334,   250,   254,   255,   256,
     281,   142,   251,   144,   145,    74,    76,    12,    14,   146,
      46,    47,    48,    49,    50,    51,   252,   197,    58,    59,
      60,    96,   148,   149,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,     9,    33,   143,    65,   225,    16,    63,    67,   103,
       9,     9,    23,    72,   108,   224,   301,   339,   277,   100,
      77,    78,   105,   210,    80,    81,    53,   278,   279,   170,
     302,   340,    24,   286,   187,   287,    25,   188,   189,    26,
     150,    11,    29,   248,   211,   143,   137,   155,    39,    13,
     143,   143,   159,    33,    40,   143,    41,    42,    43,    44,
      23,     6,    30,   117,   225,    15,    31,    17,   271,    32,
     273,   274,   275,   276,   291,    29,   151,    23,    61,    29,
      35,   116,   158,    62,    25,    18,   173,    26,   137,   293,
     294,   174,    28,   137,   153,    30,   177,   157,   137,   185,
      19,    25,    32,    25,    26,   154,    32,    54,    55,    56,
      34,   304,    54,    55,    56,   227,   171,     1,     2,     3,
     147,   172,   235,   333,    57,    79,   316,    10,    19,    66,
      20,     4,     5,    54,    55,    56,    10,    10,   275,   276,
      68,     6,   235,   235,   235,    69,   141,   186,    36,   192,
      71,   201,    79,   196,    33,    19,    69,   100,   223,    37,
     213,   346,   147,    84,    85,   234,    38,   147,   191,    52,
      39,   206,   147,   316,   227,   355,    40,    64,    41,    42,
      43,    44,    92,    93,    94,   234,   234,   234,   141,    90,
      91,   230,    70,   141,   131,   283,   237,   238,   141,    86,
      87,    88,    89,   261,   262,   235,   235,   235,   295,   296,
     235,   263,   264,   317,    54,    55,    56,   223,   121,   122,
     123,   124,   267,   317,    73,   317,   317,   235,   235,   127,
     128,   129,   228,   331,   332,    21,    22,   119,   120,   236,
     125,   126,    79,    75,    82,   235,   288,    83,   234,   234,
     234,    95,    97,   234,    98,    99,   315,   100,   226,   236,
     236,   236,   191,   101,   191,   141,   315,   102,   315,   315,
     234,   234,   104,   258,   259,   260,   107,   106,   110,     1,
       2,     3,   109,   111,   112,   141,   141,   141,   234,   113,
     114,   228,   323,     4,     5,    39,   115,   153,     6,   156,
     161,    40,   152,   175,    42,    43,    44,   162,   163,   164,
     166,   165,   178,   167,   168,   169,   179,   226,   180,   344,
     181,   182,   236,   236,   236,   184,   349,   236,   193,   194,
     318,   198,   199,   200,   202,   209,   308,   309,   310,   203,
     318,   312,   318,   318,   236,   236,   204,   207,   141,   141,
     141,   208,   212,   141,   258,   214,   259,   260,   326,   327,
     217,   229,   236,   215,   216,   231,   239,   232,   241,   242,
     141,   141,   243,   257,   265,   218,   343,   253,     1,     2,
       3,   268,   219,   266,   132,   133,   269,   134,   141,   220,
     221,   280,     4,     5,    39,   272,   222,   292,   297,   298,
      40,   299,   136,    42,    43,    44,   289,   300,   303,     1,
       2,     3,   305,   219,   306,   132,   133,   311,   134,   319,
     220,   221,   307,     4,     5,    39,   314,   290,   320,   321,
     322,    40,   324,   136,    42,    43,    44,     1,     2,     3,
     325,   219,   328,   132,   133,   329,   134,   330,   244,   245,
     335,     4,     5,    39,   336,   341,   337,   338,   342,    40,
     345,   136,    42,    43,    44,     1,   130,     3,   347,   131,
     348,   132,   133,   350,   134,   283,   356,   352,   135,     4,
       5,    39,   354,   353,   332,   313,   284,    40,   351,   136,
      42,    43,    44,     1,     2,     3,   357,   131,   282,   132,
     133,   160,   134,   183,   176,   118,     0,     4,     5,    39,
       0,     0,     0,     0,     0,    40,     0,   136,    42,    43,
      44,    39,   195,     0,     0,     0,     0,    40,     0,    41,
      42,    43,    44
};

static const yytype_int16 yycheck[] =
{
      19,     0,    13,    95,    29,   207,     3,    26,    30,    66,
       9,    10,    16,    35,    71,   207,    24,    24,    36,    40,
      39,    40,    43,    16,    16,    17,    23,    45,    46,    17,
      38,    38,    36,   261,    17,   263,    40,    20,    21,    43,
      97,    44,    16,   222,    37,   137,    95,   104,    36,    44,
     142,   143,   109,    64,    42,   147,    44,    45,    46,    47,
      16,    44,    36,    82,   266,    44,    40,    36,   247,    43,
     249,   250,   251,   252,   266,    16,    98,    16,    41,    16,
      36,    80,   107,    46,    40,    36,   137,    43,   137,   268,
     269,   142,    17,   142,    40,    36,   147,    43,   147,    40,
      43,    40,    43,    40,    43,   102,    43,    20,    21,    22,
      17,   290,    20,    21,    22,   207,   135,    20,    21,    22,
      95,    36,   214,   325,    37,    40,   305,     0,    43,    37,
       0,    34,    35,    20,    21,    22,     9,    10,   317,   318,
      41,    44,   234,   235,   236,    46,    95,   166,    17,   168,
      37,    41,    40,   172,   165,    43,    46,    40,   207,    23,
      43,   340,   137,     5,     6,   214,    23,   142,   167,    44,
      36,   190,   147,   352,   266,   354,    42,    44,    44,    45,
      46,    47,    13,    14,    15,   234,   235,   236,   137,    11,
      12,   210,    45,   142,    24,    25,   215,   216,   147,     7,
       8,     9,    10,    16,    17,   297,   298,   299,    45,    46,
     302,    16,    17,   305,    20,    21,    22,   266,    86,    87,
      88,    89,   241,   315,    16,   317,   318,   319,   320,    92,
      93,    94,   207,    24,    25,     9,    10,    84,    85,   214,
      90,    91,    40,    16,     3,   337,   265,     4,   297,   298,
     299,    38,    37,   302,    16,    44,   305,    40,   207,   234,
     235,   236,   261,    41,   263,   214,   315,    16,   317,   318,
     319,   320,    37,   234,   235,   236,    16,    41,    44,    20,
      21,    22,    37,    37,    18,   234,   235,   236,   337,    37,
      37,   266,   311,    34,    35,    36,    46,    40,    44,    23,
      17,    42,    46,    44,    45,    46,    47,    44,    17,    41,
      36,    44,    39,    36,    36,    36,    41,   266,    46,   338,
      17,    23,   297,   298,   299,    40,   345,   302,    44,    17,
     305,    41,    17,    46,    37,    17,   297,   298,   299,    44,
     315,   302,   317,   318,   319,   320,    44,    37,   297,   298,
     299,    37,    41,   302,   315,    38,   317,   318,   319,   320,
      17,    38,   337,    43,    43,    17,    44,    23,    36,    17,
     319,   320,    17,    39,    43,    17,   337,    30,    20,    21,
      22,    17,    24,    37,    26,    27,    17,    29,   337,    31,
      32,    28,    34,    35,    36,    39,    38,    37,    19,    19,
      42,    19,    44,    45,    46,    47,    17,    39,    16,    20,
      21,    22,    38,    24,    37,    26,    27,    36,    29,    19,
      31,    32,    37,    34,    35,    36,    39,    38,    19,    31,
      31,    42,    39,    44,    45,    46,    47,    20,    21,    22,
      39,    24,    17,    26,    27,    17,    29,    37,    31,    32,
      31,    34,    35,    36,    31,    17,    38,    36,    17,    42,
      36,    44,    45,    46,    47,    20,    21,    22,    39,    24,
      37,    26,    27,    39,    29,    25,    39,    38,    33,    34,
      35,    36,    38,    37,    25,   303,   257,    42,   347,    44,
      45,    46,    47,    20,    21,    22,   356,    24,   256,    26,
      27,   110,    29,   162,   143,    83,    -1,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    45,    46,
      47,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,    44,
      45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,    21,    22,    34,    35,    44,    49,    50,    71,
      72,    44,    75,    44,    76,    44,    75,    36,    36,    43,
       0,    50,    50,    16,    36,    40,    43,    92,    17,    16,
      36,    40,    43,    92,    17,    36,    17,    23,    23,    36,
      42,    44,    45,    46,    47,    77,    78,    79,    80,    81,
      82,    83,    44,    75,    20,    21,    22,    37,    86,    87,
      88,    41,    46,    77,    44,    76,    37,    86,    41,    46,
      45,    37,    86,    16,    73,    16,    74,    77,    77,    40,
      16,    17,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    38,    89,    37,    16,    44,
      40,    41,    16,    89,    37,    43,    41,    16,    89,    37,
      44,    37,    18,    37,    37,    46,    71,    77,    78,    79,
      79,    80,    80,    80,    80,    81,    81,    82,    82,    82,
      21,    24,    26,    27,    29,    33,    44,    52,    53,    58,
      60,    64,    69,    70,    71,    72,    77,    84,    90,    91,
      89,    86,    46,    40,    75,    89,    23,    43,    76,    89,
      73,    17,    44,    17,    41,    44,    36,    36,    36,    36,
      17,    77,    36,    90,    90,    44,    69,    90,    39,    41,
      46,    17,    23,    74,    40,    40,    77,    17,    20,    21,
      55,    71,    77,    44,    17,    37,    77,    85,    41,    17,
      46,    41,    37,    44,    44,    56,    77,    37,    37,    17,
      16,    37,    41,    43,    38,    43,    43,    17,    17,    24,
      31,    32,    38,    52,    54,    62,    64,    70,    84,    38,
      77,    17,    23,    51,    52,    70,    84,    77,    77,    44,
      57,    36,    17,    17,    31,    32,    52,    54,    59,    62,
      64,    70,    84,    30,    65,    66,    67,    39,    51,    51,
      51,    16,    17,    16,    17,    43,    37,    77,    17,    17,
      59,    59,    39,    59,    59,    59,    59,    36,    45,    46,
      28,    68,    66,    25,    60,    61,    55,    55,    77,    17,
      38,    54,    37,    59,    59,    45,    46,    19,    19,    19,
      39,    24,    38,    16,    59,    38,    37,    37,    51,    51,
      51,    36,    51,    57,    39,    52,    59,    70,    84,    19,
      19,    31,    31,    77,    39,    39,    51,    51,    17,    17,
      37,    24,    25,    62,    63,    31,    31,    38,    36,    24,
      38,    17,    17,    51,    77,    36,    59,    39,    37,    77,
      39,    61,    38,    37,    38,    59,    39,    63
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
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    76,    76,    76,    76,    76,    77,    77,    78,    78,
      79,    79,    79,    80,    80,    80,    80,    80,    81,    81,
      81,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      88,    88,    88,    89,    90,    90,    90,    90,    90,    91,
      91,    91,    92,    92,    92
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
       6,     6,     5,     5,     5,     3,     8,     7,     3,     3,
       6,     6,     3,     0,     4,     0,     5,     3,     3,     2,
       1,     5,     3,     3,     2,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     3,     2,     1,     1,
       1,     4,     7,     4,     5,     3,     1,     1,     3,     2,
       1,     1,     1,     3,     2,     2,     2,     1,     0,     3,
       2,     6,     3,     6,     5
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
#line 30 "SyntaxAnalyzer.y"
                       {printf("Starting..\n");}
#line 1562 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 32 "SyntaxAnalyzer.y"
                                                        {printf("RECURSIVE DECLARATION \n");}
#line 1568 "y.tab.c"
    break;

  case 5: /* declarationList: declarationStatement  */
#line 34 "SyntaxAnalyzer.y"
                                                        {printf("DECLARATION \n");}
#line 1574 "y.tab.c"
    break;

  case 7: /* statements: specialStatement statements  */
#line 37 "SyntaxAnalyzer.y"
                                         {printf("Special..\n");}
#line 1580 "y.tab.c"
    break;

  case 8: /* statements: basicStatement statements  */
#line 38 "SyntaxAnalyzer.y"
                                               {printf("Basic123..\n");}
#line 1586 "y.tab.c"
    break;

  case 15: /* forLoop: FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC OPCUR inLoop CLCUR  */
#line 48 "SyntaxAnalyzer.y"
                                                                                                               {printf("\nproper FOR \n");}
#line 1592 "y.tab.c"
    break;

  case 16: /* forLoop: FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC SEMICOLON  */
#line 49 "SyntaxAnalyzer.y"
                                                                                                              {printf("\nFOR SEMICOLON \n");}
#line 1598 "y.tab.c"
    break;

  case 17: /* forLoop: FOR OPBRAC forAssignStatement forExpStatement SEMICOLON forUpdateStatement CLBRAC singleLoopStatement  */
#line 50 "SyntaxAnalyzer.y"
                                                                                                                        {printf("\nFOR SINGLE STATEMENT \n");}
#line 1604 "y.tab.c"
    break;

  case 35: /* whileLoop: WHILE OPBRAC expressionStatement CLBRAC OPCUR inLoop CLCUR  */
#line 71 "SyntaxAnalyzer.y"
                                                                       {printf("\nproper WHILE \n");}
#line 1610 "y.tab.c"
    break;

  case 36: /* whileLoop: WHILE OPBRAC expressionStatement CLBRAC SEMICOLON  */
#line 72 "SyntaxAnalyzer.y"
                                                                      {printf("\nWHILE SEMICOLON \n");}
#line 1616 "y.tab.c"
    break;

  case 37: /* whileLoop: WHILE OPBRAC expressionStatement CLBRAC singleLoopStatement  */
#line 73 "SyntaxAnalyzer.y"
                                                                                {printf("\nSINGLE WHILE \n");}
#line 1622 "y.tab.c"
    break;

  case 38: /* inLoop: BREAK SEMICOLON inLoop  */
#line 75 "SyntaxAnalyzer.y"
                                {printf("\n break in loop \n");}
#line 1628 "y.tab.c"
    break;

  case 39: /* inLoop: CONTINUE SEMICOLON inLoop  */
#line 76 "SyntaxAnalyzer.y"
                                            {printf("\ncontinue in loop \n");}
#line 1634 "y.tab.c"
    break;

  case 40: /* inLoop: specialStatement inLoop  */
#line 77 "SyntaxAnalyzer.y"
                                          {printf("\n special statement in loop \n");}
#line 1640 "y.tab.c"
    break;

  case 41: /* inLoop: basicStatement inLoop  */
#line 78 "SyntaxAnalyzer.y"
                                        {printf("\n basic statement in loop \n");}
#line 1646 "y.tab.c"
    break;

  case 42: /* inLoop: functionCall inLoop  */
#line 79 "SyntaxAnalyzer.y"
                                     {printf("\n basic statement in loop \n");}
#line 1652 "y.tab.c"
    break;

  case 43: /* inLoop: ifInLoopStatement inLoop  */
#line 80 "SyntaxAnalyzer.y"
                                           {printf("\n if in loop \n");}
#line 1658 "y.tab.c"
    break;

  case 44: /* inLoop: switchStatement inLoop  */
#line 81 "SyntaxAnalyzer.y"
                                         {printf("\n switch in loop \n");}
#line 1664 "y.tab.c"
    break;

  case 45: /* inLoop: singleLoopStatement inLoop  */
#line 82 "SyntaxAnalyzer.y"
                                             {printf("\n any other statement in loop \n");}
#line 1670 "y.tab.c"
    break;

  case 57: /* switchStatement: SWITCH OPBRAC IDENTIFIER CLBRAC OPCUR caseStatements defaultStatement CLCUR  */
#line 99 "SyntaxAnalyzer.y"
                                                                                              {printf("SWITCH START..\n");}
#line 1676 "y.tab.c"
    break;

  case 59: /* caseStatements: %empty  */
#line 100 "SyntaxAnalyzer.y"
                                    {printf("char/int..\n");}
#line 1682 "y.tab.c"
    break;

  case 61: /* caseStatementInt: %empty  */
#line 101 "SyntaxAnalyzer.y"
                                              {printf("INT CASE..\n");}
#line 1688 "y.tab.c"
    break;

  case 62: /* caseInt: CASE OPBRAC INTVAL CLBRAC COLON statements BREAK SEMICOLON  */
#line 102 "SyntaxAnalyzer.y"
                                                                     {printf("case (INT) : break; ..\n");}
#line 1694 "y.tab.c"
    break;

  case 63: /* caseInt: CASE OPBRAC INTVAL CLBRAC COLON statements  */
#line 103 "SyntaxAnalyzer.y"
                                                             {printf("case (INT) : ..\n");}
#line 1700 "y.tab.c"
    break;

  case 64: /* caseInt: CASE INTVAL COLON statements BREAK SEMICOLON  */
#line 104 "SyntaxAnalyzer.y"
                                                               {printf("case INT : BREAK;..\n");}
#line 1706 "y.tab.c"
    break;

  case 65: /* caseInt: CASE INTVAL COLON statements  */
#line 105 "SyntaxAnalyzer.y"
                                               {printf("CASE INT : ..\n");}
#line 1712 "y.tab.c"
    break;

  case 66: /* caseInt: CASE OPBRAC CHARVAL CLBRAC COLON statements BREAK SEMICOLON  */
#line 106 "SyntaxAnalyzer.y"
                                                                              {printf("case (char) : break; ..\n");}
#line 1718 "y.tab.c"
    break;

  case 67: /* caseInt: CASE OPBRAC CHARVAL CLBRAC COLON statements  */
#line 107 "SyntaxAnalyzer.y"
                                                              {printf("case (char) : ..\n");}
#line 1724 "y.tab.c"
    break;

  case 68: /* caseInt: CASE CHARVAL COLON statements BREAK SEMICOLON  */
#line 108 "SyntaxAnalyzer.y"
                                                                {printf("case char : BREAK;..\n");}
#line 1730 "y.tab.c"
    break;

  case 69: /* caseInt: CASE CHARVAL COLON statements  */
#line 109 "SyntaxAnalyzer.y"
                                                {printf("CASE char : ..\n");}
#line 1736 "y.tab.c"
    break;

  case 71: /* defaultStatement: %empty  */
#line 110 "SyntaxAnalyzer.y"
                                               {printf(" \nDEFAULT : ..\n");}
#line 1742 "y.tab.c"
    break;

  case 74: /* basicStatement: expressionStatement  */
#line 116 "SyntaxAnalyzer.y"
                                     {printf("BS->EXPS..\n");}
#line 1748 "y.tab.c"
    break;

  case 75: /* basicStatement: declarationStatement  */
#line 117 "SyntaxAnalyzer.y"
                                       {printf("BS->DS..\n");}
#line 1754 "y.tab.c"
    break;

  case 76: /* basicStatement: assignmentStatement  */
#line 118 "SyntaxAnalyzer.y"
                                        {printf("Basic->AS..\n");}
#line 1760 "y.tab.c"
    break;

  case 77: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 120 "SyntaxAnalyzer.y"
                                                                                     {printf("AS1..\n");}
#line 1766 "y.tab.c"
    break;

  case 78: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 121 "SyntaxAnalyzer.y"
                                                                 {printf("AS2..\n");}
#line 1772 "y.tab.c"
    break;

  case 79: /* declarationStatement: INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 123 "SyntaxAnalyzer.y"
                                                                                   {printf("INT F WITH PARAMS..\n");}
#line 1778 "y.tab.c"
    break;

  case 80: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 124 "SyntaxAnalyzer.y"
                                                                              {printf("char F WITH PARAMS..\n");}
#line 1784 "y.tab.c"
    break;

  case 81: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 125 "SyntaxAnalyzer.y"
                                                                               {printf("float F WITH PARAMS..\n");}
#line 1790 "y.tab.c"
    break;

  case 85: /* declarationStatement: INT declarationListIntFloat SEMICOLON  */
#line 129 "SyntaxAnalyzer.y"
                                                        {printf("DS1..\n");}
#line 1796 "y.tab.c"
    break;

  case 96: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListIntFloat  */
#line 140 "SyntaxAnalyzer.y"
                                                                                             {printf("DSL1..\n");}
#line 1802 "y.tab.c"
    break;

  case 98: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement  */
#line 142 "SyntaxAnalyzer.y"
                                                       {printf("DSL3..\n");}
#line 1808 "y.tab.c"
    break;

  case 99: /* declarationListIntFloat: IDENTIFIER dimension  */
#line 143 "SyntaxAnalyzer.y"
                                        {printf("INTFLOAT ARRAY..\n");}
#line 1814 "y.tab.c"
    break;

  case 100: /* declarationListIntFloat: IDENTIFIER  */
#line 144 "SyntaxAnalyzer.y"
                             {printf("DSL4..\n");}
#line 1820 "y.tab.c"
    break;

  case 106: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 152 "SyntaxAnalyzer.y"
                                                                      {printf("ES1..\n");}
#line 1826 "y.tab.c"
    break;

  case 107: /* expressionStatement: logicalExpression  */
#line 153 "SyntaxAnalyzer.y"
                                    {printf("ES2..\n");}
#line 1832 "y.tab.c"
    break;

  case 108: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 155 "SyntaxAnalyzer.y"
                                                            {printf("LE1..\n");}
#line 1838 "y.tab.c"
    break;

  case 109: /* logicalExpression: expression  */
#line 156 "SyntaxAnalyzer.y"
                             {printf("LE2..\n");}
#line 1844 "y.tab.c"
    break;

  case 110: /* expression: relationalExpression EQUALS expression  */
#line 158 "SyntaxAnalyzer.y"
                                                    {printf("E1..\n");}
#line 1850 "y.tab.c"
    break;

  case 111: /* expression: relationalExpression NOTEQUAL expression  */
#line 159 "SyntaxAnalyzer.y"
                                                           {printf("E2..\n");}
#line 1856 "y.tab.c"
    break;

  case 112: /* expression: relationalExpression  */
#line 160 "SyntaxAnalyzer.y"
                                       {printf("E3..\n");}
#line 1862 "y.tab.c"
    break;

  case 117: /* relationalExpression: value  */
#line 166 "SyntaxAnalyzer.y"
                        {printf("VALUE..\n");}
#line 1868 "y.tab.c"
    break;

  case 118: /* value: term ADD value  */
#line 168 "SyntaxAnalyzer.y"
                       {printf("ADD..\n");}
#line 1874 "y.tab.c"
    break;

  case 120: /* value: term  */
#line 170 "SyntaxAnalyzer.y"
               {printf("Basic TERM..\n");}
#line 1880 "y.tab.c"
    break;

  case 121: /* term: factor MULT term  */
#line 172 "SyntaxAnalyzer.y"
                        {printf("MULT..\n");}
#line 1886 "y.tab.c"
    break;

  case 124: /* term: factor  */
#line 175 "SyntaxAnalyzer.y"
                 {printf("Factor..\n");}
#line 1892 "y.tab.c"
    break;

  case 129: /* factor: INTVAL  */
#line 181 "SyntaxAnalyzer.y"
                 {printf("INT VALS.. %d\n",yylval);}
#line 1898 "y.tab.c"
    break;

  case 138: /* parameters: parameter COMMA parameters  */
#line 197 "SyntaxAnalyzer.y"
                                                     {printf("FUNCTION params\n");}
#line 1904 "y.tab.c"
    break;

  case 139: /* parameter: type IDENTIFIER  */
#line 199 "SyntaxAnalyzer.y"
                            {printf("FUNCTION param\n");}
#line 1910 "y.tab.c"
    break;

  case 143: /* compoundStatements: OPCUR statementList CLCUR  */
#line 203 "SyntaxAnalyzer.y"
                                               {printf("FUNCTION statements\n");}
#line 1916 "y.tab.c"
    break;

  case 152: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 213 "SyntaxAnalyzer.y"
                                    {printf("size..\n");}
#line 1922 "y.tab.c"
    break;


#line 1926 "y.tab.c"

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

#line 216 "SyntaxAnalyzer.y"

 
#include "lex.yy.c"
void main(){
	yyin = fopen("./Test Cases/input.txt","r");
	if(!yyparse())
	{
		printf("Parsing Done\n");
	}
	else 
		printf("Failed\n");
	exit(0);
}
 
void yyerror(){
	printf("Invalid Statement");
	exit(0);
}
