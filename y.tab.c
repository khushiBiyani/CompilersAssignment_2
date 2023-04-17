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
    OPBRAC = 289,                  /* OPBRAC  */
    CLBRAC = 290,                  /* CLBRAC  */
    OPCUR = 291,                   /* OPCUR  */
    CLCUR = 292,                   /* CLCUR  */
    BOXOPEN = 293,                 /* BOXOPEN  */
    BOXCLOSE = 294,                /* BOXCLOSE  */
    LOGICALNOT = 295,              /* LOGICALNOT  */
    EQUAL = 296,                   /* EQUAL  */
    IDENTIFIER = 297,              /* IDENTIFIER  */
    CHARVAL = 298,                 /* CHARVAL  */
    INTVAL = 299,                  /* INTVAL  */
    FLOATVAL = 300                 /* FLOATVAL  */
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
#define OPBRAC 289
#define CLBRAC 290
#define OPCUR 291
#define CLCUR 292
#define BOXOPEN 293
#define BOXCLOSE 294
#define LOGICALNOT 295
#define EQUAL 296
#define IDENTIFIER 297
#define CHARVAL 298
#define INTVAL 299
#define FLOATVAL 300

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
  YYSYMBOL_OPBRAC = 34,                    /* OPBRAC  */
  YYSYMBOL_CLBRAC = 35,                    /* CLBRAC  */
  YYSYMBOL_OPCUR = 36,                     /* OPCUR  */
  YYSYMBOL_CLCUR = 37,                     /* CLCUR  */
  YYSYMBOL_BOXOPEN = 38,                   /* BOXOPEN  */
  YYSYMBOL_BOXCLOSE = 39,                  /* BOXCLOSE  */
  YYSYMBOL_LOGICALNOT = 40,                /* LOGICALNOT  */
  YYSYMBOL_EQUAL = 41,                     /* EQUAL  */
  YYSYMBOL_IDENTIFIER = 42,                /* IDENTIFIER  */
  YYSYMBOL_CHARVAL = 43,                   /* CHARVAL  */
  YYSYMBOL_INTVAL = 44,                    /* INTVAL  */
  YYSYMBOL_FLOATVAL = 45,                  /* FLOATVAL  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_code = 47,                      /* code  */
  YYSYMBOL_declarationList = 48,           /* declarationList  */
  YYSYMBOL_statements = 49,                /* statements  */
  YYSYMBOL_specialStatement = 50,          /* specialStatement  */
  YYSYMBOL_forLoop = 51,                   /* forLoop  */
  YYSYMBOL_forAssignStatement = 52,        /* forAssignStatement  */
  YYSYMBOL_forExpStatement = 53,           /* forExpStatement  */
  YYSYMBOL_forUpdateStatement = 54,        /* forUpdateStatement  */
  YYSYMBOL_whileLoop = 55,                 /* whileLoop  */
  YYSYMBOL_inLoop = 56,                    /* inLoop  */
  YYSYMBOL_ifStatement = 57,               /* ifStatement  */
  YYSYMBOL_ES = 58,                        /* ES  */
  YYSYMBOL_ifInLoopStatement = 59,         /* ifInLoopStatement  */
  YYSYMBOL_ESLoop = 60,                    /* ESLoop  */
  YYSYMBOL_switchStatement = 61,           /* switchStatement  */
  YYSYMBOL_caseStatements = 62,            /* caseStatements  */
  YYSYMBOL_caseStatementInt = 63,          /* caseStatementInt  */
  YYSYMBOL_caseInt = 64,                   /* caseInt  */
  YYSYMBOL_caseStatementChar = 65,         /* caseStatementChar  */
  YYSYMBOL_caseChar = 66,                  /* caseChar  */
  YYSYMBOL_defaultStatement = 67,          /* defaultStatement  */
  YYSYMBOL_basicStatements = 68,           /* basicStatements  */
  YYSYMBOL_basicStatement = 69,            /* basicStatement  */
  YYSYMBOL_assignmentStatement = 70,       /* assignmentStatement  */
  YYSYMBOL_declarationStatement = 71,      /* declarationStatement  */
  YYSYMBOL_declarationListIntFloat = 72,   /* declarationListIntFloat  */
  YYSYMBOL_declarationListChar = 73,       /* declarationListChar  */
  YYSYMBOL_expressionStatement = 74,       /* expressionStatement  */
  YYSYMBOL_logicalExpression = 75,         /* logicalExpression  */
  YYSYMBOL_expression = 76,                /* expression  */
  YYSYMBOL_relationalExpression = 77,      /* relationalExpression  */
  YYSYMBOL_value = 78,                     /* value  */
  YYSYMBOL_term = 79,                      /* term  */
  YYSYMBOL_factor = 80,                    /* factor  */
  YYSYMBOL_functionCall = 81,              /* functionCall  */
  YYSYMBOL_argList = 82,                   /* argList  */
  YYSYMBOL_parameters = 83,                /* parameters  */
  YYSYMBOL_parameter = 84,                 /* parameter  */
  YYSYMBOL_type = 85,                      /* type  */
  YYSYMBOL_compoundStatements = 86,        /* compoundStatements  */
  YYSYMBOL_statementList = 87,             /* statementList  */
  YYSYMBOL_returnDec = 88,                 /* returnDec  */
  YYSYMBOL_dimension = 89                  /* dimension  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   370

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  284

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    30,    30,    32,    33,    35,    36,    37,    38,    40,
      41,    42,    43,    46,    47,    49,    49,    50,    50,    51,
      52,    55,    56,    58,    59,    60,    61,    62,    63,    65,
      66,    68,    69,    71,    72,    74,    75,    77,    78,    78,
      78,    79,    79,    80,    81,    81,    82,    83,    83,    86,
      87,    89,    90,    91,    93,    94,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   107,   108,   109,   110,   111,
     113,   114,   115,   116,   117,   119,   120,   122,   123,   125,
     126,   127,   129,   130,   131,   132,   133,   135,   136,   137,
     139,   140,   141,   142,   144,   145,   146,   147,   148,   149,
     150,   151,   158,   159,   162,   162,   164,   164,   166,   168,
     168,   168,   170,   172,   172,   172,   172,   172,   174,   174,
     178,   179,   180
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
  "BREAK", "CONTINUE", "RETURN", "OPBRAC", "CLBRAC", "OPCUR", "CLCUR",
  "BOXOPEN", "BOXCLOSE", "LOGICALNOT", "EQUAL", "IDENTIFIER", "CHARVAL",
  "INTVAL", "FLOATVAL", "$accept", "code", "declarationList", "statements",
  "specialStatement", "forLoop", "forAssignStatement", "forExpStatement",
  "forUpdateStatement", "whileLoop", "inLoop", "ifStatement", "ES",
  "ifInLoopStatement", "ESLoop", "switchStatement", "caseStatements",
  "caseStatementInt", "caseInt", "caseStatementChar", "caseChar",
  "defaultStatement", "basicStatements", "basicStatement",
  "assignmentStatement", "declarationStatement", "declarationListIntFloat",
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

#define YYPACT_NINF (-174)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     108,   -27,   -17,    12,    81,  -174,   108,     1,    75,    41,
      91,    57,   100,  -174,  -174,    79,    89,   -32,   228,  -174,
    -174,    93,   105,   102,  -174,  -174,   155,  -174,   -10,  -174,
    -174,  -174,  -174,   117,   126,   147,   124,   130,   132,   228,
     228,   141,  -174,  -174,  -174,   176,   182,   212,    78,   196,
     139,   211,    61,  -174,   117,   183,   192,   117,   186,   167,
    -174,   117,   219,  -174,   190,   209,   225,  -174,   223,    79,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,  -174,   117,    93,  -174,   117,   235,   246,
     247,   248,    19,   161,   167,  -174,  -174,  -174,  -174,   167,
     208,  -174,  -174,  -174,   167,   249,  -174,  -174,  -174,   244,
     240,  -174,   251,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
     228,   243,   228,   245,  -174,   271,   221,   228,  -174,  -174,
      62,  -174,  -174,  -174,  -174,   252,   254,   258,   253,   228,
    -174,   260,   261,  -174,   272,  -174,    -6,   157,  -174,   255,
     262,   280,  -174,    49,   264,  -174,   228,   284,   243,  -174,
     263,   193,   265,  -174,   138,   273,  -174,  -174,  -174,  -174,
     267,   193,   193,  -174,   268,   270,   274,   289,   293,   138,
     275,   138,   138,   277,   285,  -174,   286,  -174,   287,   173,
    -174,  -174,   228,    50,   228,   138,   138,  -174,  -174,  -174,
    -174,   188,   295,   278,   288,  -174,   290,  -174,    13,  -174,
    -174,   302,  -174,   138,   291,  -174,  -174,   292,   294,   193,
    -174,   276,   282,   296,   193,   265,   297,   283,   304,   309,
     314,   228,   298,  -174,  -174,   138,   193,   193,  -174,   301,
    -174,   112,   300,   307,   308,   305,   250,   315,   316,   193,
     306,    70,  -174,  -174,  -174,  -174,   310,   228,   311,   138,
     317,   313,   228,   312,  -174,   318,   320,  -174,   138,   321,
     138,   319,   325,  -174
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,    69,     0,    74,
       0,    69,     0,     1,     3,     0,     0,     0,     0,    68,
      62,     0,     0,     0,    73,    63,     0,    64,    69,    66,
     109,   111,   110,     0,     0,   106,     0,     0,     0,     0,
       0,    94,    97,    98,    99,    67,    76,    78,    81,    86,
      89,    93,    74,    71,     0,     0,    72,     0,     0,   117,
      59,     0,     0,   108,     0,   120,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,     0,    60,     0,     0,     0,
       0,     0,     0,    94,   117,     9,    11,    10,    12,   117,
      50,    53,    52,    51,   117,     0,   116,    56,   107,     0,
       0,    95,     0,    65,    75,    77,    79,    80,    82,    83,
      84,    85,    87,    88,    90,    91,    92,    57,    70,    58,
       0,    16,     0,     0,   119,     0,     0,     0,   114,   113,
      94,    49,   115,   112,   122,     0,   100,     0,     0,    18,
      15,     0,     0,   118,     0,   105,     0,     0,   121,     0,
       0,     0,    17,     0,     0,   102,     0,     0,     0,    55,
       0,     8,     0,    22,     8,    40,   104,   103,    54,   101,
       0,     8,     8,     7,     0,     0,     0,     0,     0,     8,
       0,     8,     8,     0,    48,    38,    42,    39,    45,     0,
       5,     6,     0,     0,     0,     8,     8,    25,    21,    26,
      27,     0,     0,     0,     0,    41,     0,    44,     0,    30,
      29,    20,    14,     8,     0,    23,    24,     0,     0,     8,
      37,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    13,     8,     8,     8,    47,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     0,    34,    33,    46,    43,     0,     0,     0,     8,
       0,     0,     0,     0,    31,     0,     0,    36,     8,     0,
       8,     0,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,  -174,   337,  -158,   -48,  -174,  -174,  -174,    86,  -174,
    -165,   145,    76,    95,    71,  -173,  -174,   156,  -174,   160,
    -174,  -174,   259,   -56,  -123,   116,    -1,   -16,   -18,   299,
     204,   169,   200,   177,  -174,   -39,  -174,     8,  -174,  -174,
      36,    43,  -174,    -5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,   189,   181,    95,   149,   161,   185,    96,
     207,    97,   220,   191,   263,    98,   194,   195,   196,   197,
     198,   213,    99,   182,   101,   102,     8,    10,   103,    46,
      47,    48,    49,    50,    51,   183,   156,    34,    35,    36,
      60,   105,   106,    19
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   192,    12,   100,    24,    53,    15,    37,   150,   190,
     166,    94,    38,   180,    29,     7,   192,    15,   192,   192,
     104,    66,    67,   200,   201,     9,   209,   210,    17,   167,
      55,    18,   192,   192,    58,    16,   134,   233,   100,    17,
     225,   226,    18,   100,   100,   178,    94,    24,   100,   234,
     192,    94,   114,    39,    11,   104,    94,    21,   236,    40,
     104,    41,    42,    43,    44,   104,   173,   222,   113,   128,
     108,   240,   192,    15,   135,    22,   242,    21,   192,    17,
     252,    13,    23,    72,    73,   174,   223,   251,   253,   254,
      83,    26,    20,    86,   268,    17,   192,   107,    18,    17,
      68,   266,    23,   137,   273,   192,   269,   192,    25,    30,
      31,    32,   147,   252,   151,   281,     6,    27,   155,   157,
     127,    28,     6,   129,    33,    30,    31,    32,     1,     2,
       3,   162,     1,     2,     3,    52,   186,   138,    89,    90,
      54,    91,   139,   187,   188,    56,    39,   142,   176,   199,
      78,    79,    40,    59,    93,    42,    43,    44,     1,     2,
       3,    61,   186,    62,    89,    90,    63,    91,    64,   187,
     188,    65,    39,   168,   169,    30,    31,    32,    40,    68,
      93,    42,    43,    44,   221,    70,   224,     1,     2,     3,
      57,    88,    69,    89,    90,   136,    91,    88,   218,    68,
      92,    39,   137,    74,    75,    76,    77,    40,    85,    93,
      42,    43,    44,     1,     2,     3,    71,    88,    84,    89,
      90,    87,    91,   249,    80,    81,    82,    39,     1,     2,
       3,   227,   228,    40,   109,    93,    42,    43,    44,    30,
      31,    32,    39,   118,   119,   120,   121,   110,    40,   271,
     140,    42,    43,    44,   276,    39,   154,   124,   125,   126,
     111,    40,    39,    41,    42,    43,    44,   112,    40,   130,
      41,    42,    43,    44,   260,   261,   116,   117,   122,   123,
     131,   132,   133,   144,   145,   148,   143,   152,   153,   165,
     146,   158,   159,   160,   137,   163,   164,   172,   171,   170,
     175,   177,   179,   193,   199,   203,   205,   184,   204,   202,
     206,   211,   208,   212,   229,   230,   214,   216,   235,   245,
     228,   243,   231,   246,   232,   227,   237,   238,   247,   239,
     241,   248,   264,   265,   244,   250,   255,   256,   257,   258,
     267,   259,   218,    14,   219,   272,   274,   270,   275,   277,
     261,   262,   215,   283,   278,   279,   282,   280,   217,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115
};

static const yytype_int16 yycheck[] =
{
      18,   174,     3,    59,     9,    21,    16,    39,   131,   174,
      16,    59,    44,   171,    15,    42,   189,    16,   191,   192,
      59,    39,    40,   181,   182,    42,   191,   192,    38,    35,
      22,    41,   205,   206,    26,    34,    17,    24,    94,    38,
     205,   206,    41,    99,   100,   168,    94,    52,   104,    36,
     223,    99,    70,    34,    42,    94,   104,    16,   223,    40,
      99,    42,    43,    44,    45,   104,    17,    17,    69,    85,
      62,   229,   245,    16,    92,    34,   234,    16,   251,    38,
     245,     0,    41,     5,     6,    36,    36,   245,   246,   247,
      54,    34,    17,    57,    24,    38,   269,    61,    41,    38,
      38,   259,    41,    41,   269,   278,    36,   280,    17,    20,
      21,    22,   130,   278,   132,   280,     0,    17,   136,   137,
      84,    42,     6,    87,    35,    20,    21,    22,    20,    21,
      22,   149,    20,    21,    22,    42,    24,    94,    26,    27,
      35,    29,    99,    31,    32,    43,    34,   104,   166,    37,
      11,    12,    40,    36,    42,    43,    44,    45,    20,    21,
      22,    35,    24,    16,    26,    27,    42,    29,    38,    31,
      32,    39,    34,    16,    17,    20,    21,    22,    40,    38,
      42,    43,    44,    45,   202,     3,   204,    20,    21,    22,
      35,    24,    16,    26,    27,    34,    29,    24,    25,    38,
      33,    34,    41,     7,     8,     9,    10,    40,    16,    42,
      43,    44,    45,    20,    21,    22,     4,    24,    35,    26,
      27,    35,    29,   241,    13,    14,    15,    34,    20,    21,
      22,    43,    44,    40,    44,    42,    43,    44,    45,    20,
      21,    22,    34,    74,    75,    76,    77,    38,    40,   267,
      42,    43,    44,    45,   272,    34,    35,    80,    81,    82,
      35,    40,    34,    42,    43,    44,    45,    44,    40,    34,
      42,    43,    44,    45,    24,    25,    72,    73,    78,    79,
      34,    34,    34,    39,    44,    42,    37,    42,    17,    17,
      39,    39,    38,    35,    41,    35,    35,    17,    36,    44,
      36,    17,    39,    30,    37,    35,    17,    42,    34,    41,
      17,    34,    37,    28,    19,    37,    30,    30,    16,    36,
      44,   235,    34,    19,    34,    43,    35,    35,    19,    35,
      34,    17,    17,    17,    37,    37,    35,    37,    31,    31,
      34,    36,    25,     6,   199,    34,   270,    37,    35,    37,
      25,   256,   196,   282,    36,    35,    37,    36,   198,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,    21,    22,    47,    48,    71,    42,    72,    42,
      73,    42,    72,     0,    48,    16,    34,    38,    41,    89,
      17,    16,    34,    41,    89,    17,    34,    17,    42,    72,
      20,    21,    22,    35,    83,    84,    85,    39,    44,    34,
      40,    42,    43,    44,    45,    74,    75,    76,    77,    78,
      79,    80,    42,    73,    35,    83,    43,    35,    83,    36,
      86,    35,    16,    42,    38,    39,    74,    74,    38,    16,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    86,    35,    16,    86,    35,    24,    26,
      27,    29,    33,    42,    50,    51,    55,    57,    61,    68,
      69,    70,    71,    74,    81,    87,    88,    86,    83,    44,
      38,    35,    44,    72,    74,    75,    76,    76,    77,    77,
      77,    77,    78,    78,    79,    79,    79,    86,    73,    86,
      34,    34,    34,    34,    17,    74,    34,    41,    87,    87,
      42,    68,    87,    37,    39,    44,    39,    74,    42,    52,
      70,    74,    42,    17,    35,    74,    82,    74,    39,    38,
      35,    53,    74,    35,    35,    17,    16,    35,    16,    17,
      44,    36,    17,    17,    36,    36,    74,    17,    70,    39,
      49,    50,    69,    81,    42,    54,    24,    31,    32,    49,
      56,    59,    61,    30,    62,    63,    64,    65,    66,    37,
      49,    49,    41,    35,    34,    17,    17,    56,    37,    56,
      56,    34,    28,    67,    30,    63,    30,    65,    25,    57,
      58,    74,    17,    36,    74,    56,    56,    43,    44,    19,
      37,    34,    34,    24,    36,    16,    56,    35,    35,    35,
      49,    34,    49,    54,    37,    36,    19,    19,    17,    74,
      37,    49,    56,    49,    49,    35,    37,    31,    31,    36,
      24,    25,    59,    60,    17,    17,    49,    34,    24,    36,
      37,    74,    34,    56,    58,    35,    74,    37,    36,    35,
      36,    56,    37,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    50,
      50,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    62,    62,
      62,    63,    63,    64,    65,    65,    66,    67,    67,    68,
      68,    69,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    74,    74,    75,    75,    76,
      76,    76,    77,    77,    77,    77,    77,    78,    78,    78,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    85,
      85,    85,    86,    87,    87,    87,    87,    87,    88,    88,
      89,    89,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     1,     0,     1,
       1,     1,     1,    10,     8,     1,     0,     1,     0,     5,
       3,     7,     5,     3,     3,     2,     2,     2,     0,     8,
       8,     9,     4,     8,     8,     9,     4,     8,     1,     1,
       0,     2,     0,     8,     2,     0,     8,     4,     0,     2,
       1,     1,     1,     1,     5,     4,     6,     6,     6,     5,
       5,     5,     3,     3,     3,     5,     3,     3,     2,     1,
       5,     3,     3,     2,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     3,     2,     1,     1,     1,
       4,     7,     4,     5,     3,     1,     1,     3,     2,     1,
       1,     1,     3,     2,     2,     2,     1,     0,     3,     2,
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
#line 30 "SyntaxAnalyzer.y"
                       {printf("Starting..\n");return 0;}
#line 1492 "y.tab.c"
    break;

  case 3: /* declarationList: declarationStatement declarationList  */
#line 32 "SyntaxAnalyzer.y"
                                                        {printf("RECURSIVE DECLARATION \n");}
#line 1498 "y.tab.c"
    break;

  case 4: /* declarationList: declarationStatement  */
#line 33 "SyntaxAnalyzer.y"
                                                        {printf("DECLARATION \n");}
#line 1504 "y.tab.c"
    break;

  case 5: /* statements: specialStatement statements  */
#line 35 "SyntaxAnalyzer.y"
                                         {printf("Special..\n");}
#line 1510 "y.tab.c"
    break;

  case 6: /* statements: basicStatement statements  */
#line 36 "SyntaxAnalyzer.y"
                                               {printf("Basic123..\n");}
#line 1516 "y.tab.c"
    break;

  case 51: /* basicStatement: expressionStatement  */
#line 89 "SyntaxAnalyzer.y"
                                     {printf("BS->EXPS..\n");}
#line 1522 "y.tab.c"
    break;

  case 52: /* basicStatement: declarationStatement  */
#line 90 "SyntaxAnalyzer.y"
                                       {printf("BS->DS..\n");}
#line 1528 "y.tab.c"
    break;

  case 53: /* basicStatement: assignmentStatement  */
#line 91 "SyntaxAnalyzer.y"
                                        {printf("Basic->AS..\n");}
#line 1534 "y.tab.c"
    break;

  case 54: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement COMMA assignmentStatement  */
#line 93 "SyntaxAnalyzer.y"
                                                                                     {printf("AS1..\n");}
#line 1540 "y.tab.c"
    break;

  case 55: /* assignmentStatement: IDENTIFIER EQUAL expressionStatement SEMICOLON  */
#line 94 "SyntaxAnalyzer.y"
                                                                 {printf("AS2..\n");}
#line 1546 "y.tab.c"
    break;

  case 56: /* declarationStatement: INT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 96 "SyntaxAnalyzer.y"
                                                                                   {printf("INT F WITH PARAMS..\n");}
#line 1552 "y.tab.c"
    break;

  case 57: /* declarationStatement: CHAR IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 97 "SyntaxAnalyzer.y"
                                                                              {printf("char F WITH PARAMS..\n");}
#line 1558 "y.tab.c"
    break;

  case 58: /* declarationStatement: FLOAT IDENTIFIER OPBRAC parameters CLBRAC compoundStatements  */
#line 98 "SyntaxAnalyzer.y"
                                                                               {printf("float F WITH PARAMS..\n");}
#line 1564 "y.tab.c"
    break;

  case 62: /* declarationStatement: INT declarationListIntFloat SEMICOLON  */
#line 102 "SyntaxAnalyzer.y"
                                                        {printf("DS1..\n");}
#line 1570 "y.tab.c"
    break;

  case 65: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement COMMA declarationListIntFloat  */
#line 107 "SyntaxAnalyzer.y"
                                                                                             {printf("DSL1..\n");}
#line 1576 "y.tab.c"
    break;

  case 67: /* declarationListIntFloat: IDENTIFIER EQUAL expressionStatement  */
#line 109 "SyntaxAnalyzer.y"
                                                       {printf("DSL3..\n");}
#line 1582 "y.tab.c"
    break;

  case 68: /* declarationListIntFloat: IDENTIFIER dimension  */
#line 110 "SyntaxAnalyzer.y"
                                        {printf("INTFLOAT ARRAY..\n");}
#line 1588 "y.tab.c"
    break;

  case 69: /* declarationListIntFloat: IDENTIFIER  */
#line 111 "SyntaxAnalyzer.y"
                             {printf("DSL4..\n");}
#line 1594 "y.tab.c"
    break;

  case 75: /* expressionStatement: logicalExpression LOGICALOR expressionStatement  */
#line 119 "SyntaxAnalyzer.y"
                                                                      {printf("ES1..\n");}
#line 1600 "y.tab.c"
    break;

  case 76: /* expressionStatement: logicalExpression  */
#line 120 "SyntaxAnalyzer.y"
                                    {printf("ES2..\n");}
#line 1606 "y.tab.c"
    break;

  case 77: /* logicalExpression: expression LOGICALAND logicalExpression  */
#line 122 "SyntaxAnalyzer.y"
                                                            {printf("LE1..\n");}
#line 1612 "y.tab.c"
    break;

  case 78: /* logicalExpression: expression  */
#line 123 "SyntaxAnalyzer.y"
                             {printf("LE2..\n");}
#line 1618 "y.tab.c"
    break;

  case 79: /* expression: relationalExpression EQUALS expression  */
#line 125 "SyntaxAnalyzer.y"
                                                    {printf("E1..\n");}
#line 1624 "y.tab.c"
    break;

  case 80: /* expression: relationalExpression NOTEQUAL expression  */
#line 126 "SyntaxAnalyzer.y"
                                                           {printf("E2..\n");}
#line 1630 "y.tab.c"
    break;

  case 81: /* expression: relationalExpression  */
#line 127 "SyntaxAnalyzer.y"
                                       {printf("E3..\n");}
#line 1636 "y.tab.c"
    break;

  case 86: /* relationalExpression: value  */
#line 133 "SyntaxAnalyzer.y"
                        {printf("VALUE..\n");}
#line 1642 "y.tab.c"
    break;

  case 87: /* value: term ADD value  */
#line 135 "SyntaxAnalyzer.y"
                       {printf("ADD..\n");}
#line 1648 "y.tab.c"
    break;

  case 89: /* value: term  */
#line 137 "SyntaxAnalyzer.y"
               {printf("Basic TERM..\n");}
#line 1654 "y.tab.c"
    break;

  case 90: /* term: factor MULT term  */
#line 139 "SyntaxAnalyzer.y"
                        {printf("MULT..\n");}
#line 1660 "y.tab.c"
    break;

  case 93: /* term: factor  */
#line 142 "SyntaxAnalyzer.y"
                 {printf("Factor..\n");}
#line 1666 "y.tab.c"
    break;

  case 98: /* factor: INTVAL  */
#line 148 "SyntaxAnalyzer.y"
                 {printf("INT VALS.. %d\n",yylval);}
#line 1672 "y.tab.c"
    break;

  case 107: /* parameters: parameter COMMA parameters  */
#line 164 "SyntaxAnalyzer.y"
                                                     {printf("FUNCTION params\n");}
#line 1678 "y.tab.c"
    break;

  case 108: /* parameter: type IDENTIFIER  */
#line 166 "SyntaxAnalyzer.y"
                            {printf("FUNCTION param\n");}
#line 1684 "y.tab.c"
    break;

  case 112: /* compoundStatements: OPCUR statementList CLCUR  */
#line 170 "SyntaxAnalyzer.y"
                                               {printf("FUNCTION statements\n");}
#line 1690 "y.tab.c"
    break;

  case 120: /* dimension: BOXOPEN INTVAL BOXCLOSE  */
#line 178 "SyntaxAnalyzer.y"
                                    {printf("size..\n");}
#line 1696 "y.tab.c"
    break;


#line 1700 "y.tab.c"

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

#line 181 "SyntaxAnalyzer.y"


#include "lex.yy.c"
void main(){
	yyin = fopen("input.txt","r");
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
