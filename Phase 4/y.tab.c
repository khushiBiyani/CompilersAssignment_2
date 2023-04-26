/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "newTag.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>
  int top=-1;
  void yyerror(char *);
  extern FILE *yyin;
  #define YYSTYPE char*
  typedef struct quadruples
  {
    char *op;
    char *arg1;
    char *arg2;
    char *res;
  }quad;
  int quadlen = 0;
  quad q[100];

#line 90 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LOGICALOR = 258,
    LOGICALAND = 259,
    EQUALS = 260,
    NOTEQUAL = 261,
    GREATERTHAN = 262,
    GREATERTHANEQUALTO = 263,
    LESSTHAN = 264,
    LESSTHANEQUALTO = 265,
    ADD = 266,
    SUB = 267,
    MULT = 268,
    DIV = 269,
    MOD = 270,
    COMMA = 271,
    SEMICOLON = 272,
    AMPERSAND = 273,
    COLON = 274,
    INT = 275,
    CHAR = 276,
    FLOAT = 277,
    STRING = 278,
    IF = 279,
    ELSE = 280,
    FOR = 281,
    WHILE = 282,
    DEFAULT = 283,
    SWITCH = 284,
    CASE = 285,
    BREAK = 286,
    CONTINUE = 287,
    RETURN = 288,
    PRINTF = 289,
    SCANF = 290,
    OPBRAC = 291,
    CLBRAC = 292,
    OPCUR = 293,
    CLCUR = 294,
    BOXOPEN = 295,
    BOXCLOSE = 296,
    LOGICALNOT = 297,
    EQUAL = 298,
    CHARVAL = 299,
    INTVAL = 300,
    FLOATVAL = 301,
    IDENTIFIER = 302
  };
#endif
/* Tokens.  */
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


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   480

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  222
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  440

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
       0,    56,    56,    59,    61,    62,    63,    64,    65,    66,
      68,    69,    70,    72,    74,    75,    76,    78,    80,    81,
      83,    84,    85,    87,    88,    89,    90,    91,    96,    97,
      98,   100,   101,   102,   104,   106,   107,   109,   110,   111,
     112,   113,   114,   115,   116,   118,   119,   121,   122,   124,
     124,   124,   125,   125,   125,   126,   127,   129,   129,   129,
     129,   130,   130,   130,   131,   132,   134,   134,   134,   134,
     135,   135,   135,   136,   137,   139,   140,   141,   143,   144,
     146,   146,   146,   147,   147,   147,   147,   148,   150,   152,
     153,   154,   156,   157,   158,   160,   160,   160,   160,   161,
     161,   161,   161,   162,   162,   162,   162,   164,   165,   165,
     165,   165,   166,   166,   166,   166,   167,   167,   167,   167,
     168,   169,   169,   169,   169,   171,   172,   173,   174,   175,
     177,   178,   180,   180,   180,   180,   181,   181,   181,   183,
     183,   183,   185,   186,   187,   189,   190,   191,   192,   193,
     194,   195,   196,   198,   198,   198,   199,   199,   199,   201,
     202,   204,   204,   204,   205,   206,   206,   206,   207,   208,
     210,   210,   210,   212,   213,   215,   215,   215,   216,   217,
     217,   217,   218,   221,   221,   222,   224,   224,   225,   227,
     227,   228,   228,   229,   231,   231,   232,   232,   233,   233,
     234,   234,   235,   237,   237,   238,   238,   239,   241,   241,
     242,   242,   243,   243,   244,   246,   247,   248,   249,   250,
     251,   252,   253
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LOGICALOR", "LOGICALAND", "EQUALS",
  "NOTEQUAL", "GREATERTHAN", "GREATERTHANEQUALTO", "LESSTHAN",
  "LESSTHANEQUALTO", "ADD", "SUB", "MULT", "DIV", "MOD", "COMMA",
  "SEMICOLON", "AMPERSAND", "COLON", "INT", "CHAR", "FLOAT", "STRING",
  "IF", "ELSE", "FOR", "WHILE", "DEFAULT", "SWITCH", "CASE", "BREAK",
  "CONTINUE", "RETURN", "PRINTF", "SCANF", "OPBRAC", "CLBRAC", "OPCUR",
  "CLCUR", "BOXOPEN", "BOXCLOSE", "LOGICALNOT", "EQUAL", "CHARVAL",
  "INTVAL", "FLOATVAL", "IDENTIFIER", "$accept", "code", "declarationList",
  "declarationStatementFirst", "parameters", "paramContinuer", "parameter",
  "type", "compoundStatements", "singleStatement", "statements",
  "statementList", "basicStatement", "assignmentStatement", "printer",
  "prattributes", "declarationStatement", "arrayValuesF", "arrayValues",
  "declarationListChar", "$@1", "$@2", "$@3", "$@4", "declarationListInt",
  "$@5", "$@6", "$@7", "$@8", "$@9", "declarationListFloat", "$@10",
  "$@11", "$@12", "$@13", "$@14", "dimension", "returnDec", "$@15", "$@16",
  "$@17", "$@18", "$@19", "ARRAY", "specialStatement", "forLoop",
  "forLoop1", "$@20", "$@21", "$@22", "forLoop2", "$@23", "$@24", "$@25",
  "forLoop3", "$@26", "$@27", "$@28", "forAssignStatement", "$@29", "$@30",
  "$@31", "$@32", "$@33", "$@34", "$@35", "$@36", "$@37", "$@38", "$@39",
  "$@40", "singleLoopStatement", "forExpStatement", "forUpdateStatement",
  "$@41", "$@42", "$@43", "$@44", "$@45", "whileLoop", "$@46", "$@47",
  "whileSuffix", "inLoop", "ifStatement", "$@48", "$@49", "$@50", "$@51",
  "ifContinuer", "ES", "$@52", "$@53", "$@54", "$@55", "ifInLoopStatement",
  "$@56", "$@57", "ifInLoopContinuer", "ESLoop", "$@58", "$@59", "$@60",
  "$@61", "expressionStatement", "$@62", "logicalExpression", "$@63",
  "expression", "$@64", "$@65", "relationalExpression", "$@66", "$@67",
  "$@68", "$@69", "value", "$@70", "$@71", "term", "$@72", "$@73", "$@74",
  "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF (-349)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-180)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      75,   -24,   -15,     4,    16,  -349,  -349,    17,    24,    36,
    -349,    21,    88,   153,  -349,  -349,  -349,    43,    37,  -349,
     100,    93,    43,    85,    43,    98,   279,  -349,    43,   106,
    -349,  -349,    43,  -349,    43,   102,   108,   125,   109,   130,
    -349,     3,   132,   187,   187,  -349,  -349,  -349,    64,   143,
     279,   181,   279,  -349,  -349,   160,   279,  -349,  -349,  -349,
     206,   209,   245,   169,   282,   178,  -349,  -349,  -349,  -349,
     107,   280,   120,   291,   121,   302,   187,    -3,  -349,  -349,
    -349,  -349,   179,  -349,   182,   218,   203,   193,  -349,    11,
     187,   199,   201,  -349,  -349,   211,  -349,   187,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,    45,   222,  -349,   214,  -349,    48,   224,  -349,
     232,  -349,    73,   238,  -349,   236,  -349,   258,  -349,   255,
     257,   127,   181,  -349,   187,   265,  -349,  -349,  -349,   276,
     281,   319,   187,  -349,  -349,   303,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   141,
     289,  -349,  -349,   159,  -349,  -349,   164,  -349,  -349,   294,
    -349,  -349,    74,   187,   187,   187,   300,   299,     9,   297,
     168,   301,  -349,   329,   187,   323,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
     325,   330,   187,   337,   358,   187,   339,   346,   187,   342,
     348,   347,   352,   354,   355,   356,  -349,  -349,  -349,  -349,
    -349,   360,   187,   371,   362,   359,   181,  -349,  -349,  -349,
     -11,   361,  -349,  -349,   384,  -349,  -349,   -31,  -349,  -349,
     347,  -349,  -349,  -349,  -349,  -349,  -349,  -349,   390,   392,
     393,    56,   366,  -349,  -349,  -349,   372,   395,   187,   397,
     399,   377,   376,   187,  -349,   187,   401,   403,   381,   187,
     382,   347,   347,   320,   187,   187,   187,   187,   375,   375,
     375,  -349,   387,   407,   408,   112,  -349,  -349,  -349,  -349,
    -349,   385,   386,  -349,  -349,  -349,   383,   410,  -349,  -349,
    -349,  -349,   388,   413,  -349,  -349,  -349,  -349,   174,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
     187,  -349,  -349,   414,   415,   112,   112,   112,   112,   394,
     112,  -349,  -349,  -349,   419,  -349,  -349,   420,   320,   402,
     347,  -349,   422,   421,   424,   425,   400,   404,   405,   409,
     411,   412,   112,   112,  -349,  -349,  -349,  -349,  -349,  -349,
     398,   406,  -349,   187,   416,  -349,    -3,    -3,    -3,  -349,
    -349,   427,   418,   307,   294,  -349,  -349,   184,   434,   216,
     435,   417,  -349,  -349,  -349,  -349,   187,   187,  -349,   112,
    -349,   423,   294,  -349,  -349,   426,   112,   428,   347,   436,
    -349,   429,   347,  -349,   375,  -349,   430,   432,  -349,   331,
    -349,  -349,   431,   242,  -349,  -349,  -349,   432,   187,   437,
     112,  -349,  -349,   433,   187,   438,  -349,   439,  -349,    53,
     440,   307,   112,  -349,   441,   446,  -349,  -349,   446,  -349
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     3,     0,     0,     0,
       1,     0,     0,     0,    14,    16,    15,     0,     0,    10,
      11,     0,     0,     0,     0,     0,    27,     7,     0,     0,
      13,     8,     0,     9,     0,     0,     0,     0,     0,     0,
     139,     0,     0,     0,     0,   218,   219,   220,   215,     0,
      27,    30,    27,    29,    25,     0,    27,    91,    90,    28,
     185,   188,   193,   202,   207,   214,     4,    12,     5,     6,
      65,     0,    56,     0,    74,     0,     0,     0,    89,    94,
      92,    93,     0,    79,   215,     0,     0,     0,   217,     0,
       0,     0,     0,    17,    23,     0,    26,     0,    24,   183,
     186,   189,   191,   194,   196,   198,   200,   203,   205,   208,
     210,   212,     0,     0,    64,     0,    37,     0,     0,    55,
       0,    39,     0,     0,    73,     0,    40,     0,   120,     0,
       0,     0,   107,    95,     0,     0,    78,    36,   216,     0,
       0,     0,     0,    84,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    57,     0,    53,    49,     0,    71,    66,   156,
     108,   116,     0,   131,   131,   131,     0,     0,     0,     0,
     221,     0,    32,     0,     0,     0,    87,   184,   187,   190,
     192,   195,   197,   199,   201,   204,   206,   209,   211,   213,
       0,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,   130,   100,   104,
     140,   221,     0,     0,     0,     0,    31,    33,    85,    81,
       0,     0,    63,    58,     0,    54,    50,     0,    72,    67,
      22,   157,    19,    18,   109,   113,   117,   122,     0,     0,
       0,     0,     0,    35,    34,    77,     0,     0,     0,     0,
      48,     0,     0,     0,    38,     0,     0,    46,     0,     0,
       0,    22,    22,   169,     0,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,   152,   126,   125,   144,   141,
     129,     0,   222,    86,    82,    42,     0,     0,    76,    59,
      51,    43,     0,     0,    68,   154,    21,    20,     0,   160,
     158,   159,   110,   114,   118,   123,   132,    97,   101,   105,
       0,   127,   128,     0,     0,   126,   152,   125,   152,     0,
     129,   222,    47,    41,     0,    45,    44,     0,   169,     0,
      22,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   128,   148,   151,   147,   150,   142,   149,
       0,     0,   155,     0,     0,   111,     0,     0,     0,   133,
     137,     0,     0,     0,   156,   145,   146,    65,    60,    74,
      69,     0,   164,   115,   119,   124,     0,     0,    98,   152,
     106,     0,   156,   134,   138,     0,   152,     0,     0,     0,
     102,     0,    22,   166,     0,   171,     0,   169,   135,     0,
     162,   167,     0,     0,   174,   172,   173,   169,     0,     0,
     152,   182,   163,     0,     0,     0,   170,     0,   178,   156,
       0,     0,   152,   180,     0,     0,   176,   181,     0,   177
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -349,  -349,  -349,  -349,   345,   443,  -349,  -349,    89,    60,
    -261,    15,   -26,   -76,     5,  -349,  -349,   157,   166,  -349,
    -349,  -349,  -349,  -349,   103,  -349,  -349,  -349,  -349,  -349,
      99,  -349,  -349,  -349,  -349,  -349,   -68,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,   -23,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,   -96,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -242,   185,  -267,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  -290,  -268,  -349,  -349,  -349,  -349,   126,
    -348,  -349,  -349,  -349,  -349,  -244,  -349,  -349,  -349,  -178,
    -349,  -349,  -349,  -349,   -22,  -349,   327,  -349,   213,  -349,
    -349,    87,  -349,  -349,  -349,  -349,   223,  -349,  -349,   119,
    -349,  -349,  -349,   253
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    18,    19,    20,    21,    27,   241,
     270,    49,   325,    51,   326,   178,    53,   268,   261,    73,
     206,   265,   118,   205,    71,   203,   263,   334,   113,   202,
      75,   209,   269,   337,   123,   208,    91,    54,   185,   258,
      92,   184,   257,    55,   327,    78,    79,   173,   248,   348,
      80,   174,   249,   349,    81,   175,   250,   350,   133,   212,
     274,   342,   213,   275,   343,   214,   276,   344,   215,   277,
     345,   328,   216,   317,   346,   386,   399,   347,   387,    57,
      82,   251,   289,   329,    58,   210,   338,   211,   273,   310,
     311,   397,   417,   398,   407,   330,   391,   409,   415,   416,
     430,   438,   431,   435,    59,   146,    60,   147,    61,   148,
     149,    62,   150,   151,   152,   153,    63,   154,   155,    64,
     156,   157,   158,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,   132,   114,    56,   119,   309,   124,   290,   266,   288,
     306,   307,   318,   319,   128,   267,    10,   129,   130,    85,
      83,    87,    88,     7,    50,   222,    50,    56,   259,    56,
      50,    52,     8,    56,   260,   354,   355,   356,   357,    43,
     359,    14,    15,    16,   131,    44,   223,    45,    46,    47,
      84,     9,   139,    11,   127,    52,   140,    52,    17,   411,
      12,    52,   375,   376,   290,    94,   341,    96,   141,   422,
     309,    98,    13,   281,    28,   145,    35,    36,    37,   364,
     282,    26,    39,    40,  -179,  -179,   159,   283,   284,   163,
     160,  -153,    43,   160,   285,     1,     2,     3,    44,   395,
      45,    46,    47,    48,    89,   226,   401,    90,    14,    15,
      16,    31,   176,    33,   166,   139,    29,    66,   160,   160,
     183,    68,    32,    69,   187,    22,    14,    15,    16,   290,
     425,   390,    35,    36,    37,    34,   282,   408,    39,    40,
      30,   406,   434,   323,   324,    76,    42,   112,    43,    70,
     -61,   217,   217,   217,    44,    72,    45,    46,    47,    48,
     117,   122,   228,   -52,   -70,   414,    77,   172,    86,   290,
      90,   421,    74,    14,    15,    16,   103,   104,   105,   106,
     232,   179,    93,   235,   200,   242,   238,   290,   243,   433,
      24,   109,   110,   111,    35,    36,    37,    95,   339,   179,
      39,    40,   204,    97,   179,   283,   284,   207,   225,    99,
      43,   -75,   340,   100,   271,   134,    44,   272,    45,    46,
      47,    48,   135,    43,   172,   286,   137,   -61,   287,    44,
     138,    45,    46,    47,    84,   136,   294,   191,   192,   193,
     194,   299,   142,   300,   143,   271,   271,   304,   272,   272,
     101,   102,   312,   313,   314,   315,   172,   437,   144,   -70,
     439,   162,    35,    36,    37,   161,   419,   164,    39,    40,
     383,   384,   385,   283,   284,   197,   198,   199,    43,   165,
     420,   167,   286,   168,    44,   287,    45,    46,    47,    48,
     132,   132,   132,   107,   108,   169,   115,   116,   351,    35,
      36,    37,   170,    38,   171,    39,    40,   120,   121,   114,
     177,   124,    41,    42,   271,    43,   179,   272,   125,   126,
     186,    44,   180,    45,    46,    47,    48,    35,    36,    37,
     201,   282,  -153,    39,    40,   181,   182,   220,   283,   284,
     221,   381,   224,    43,    38,   308,   227,   286,   131,    44,
     287,    45,    46,    47,    48,   412,   413,    23,    25,   218,
     219,   189,   190,   230,   393,   394,   229,    35,    36,    37,
     231,    38,   242,    39,    40,   243,   271,   195,   196,   272,
     233,   234,   236,    43,   237,   239,   240,   286,   254,    44,
     287,    45,    46,    47,    48,   244,   423,   245,   246,   247,
     252,   264,   427,   255,   256,   286,   262,   278,   287,   279,
     280,   291,   293,   292,   295,   296,   297,   298,   301,   302,
     303,   305,   316,   320,   321,   322,   331,   333,   260,   -76,
     336,   352,   353,   358,   267,   360,   361,   366,   363,   365,
     367,   368,   371,   369,   388,   377,   372,   370,   373,   374,
     115,   125,   404,   379,   392,   382,   389,   308,   403,   335,
     380,   396,   332,   378,   362,   400,   402,   418,   405,   410,
     426,   413,    67,   424,   188,   253,   429,   428,   432,     0,
     436
};

static const yytype_int16 yycheck[] =
{
      26,    77,    70,    26,    72,   273,    74,   251,    39,   251,
     271,   272,   279,   280,    17,    46,     0,    20,    21,    41,
      17,    43,    44,    47,    50,    16,    52,    50,    39,    52,
      56,    26,    47,    56,    45,   325,   326,   327,   328,    36,
     330,    20,    21,    22,    47,    42,    37,    44,    45,    46,
      47,    47,    41,    36,    76,    50,    45,    52,    37,   407,
      36,    56,   352,   353,   308,    50,   308,    52,    90,   417,
     338,    56,    36,    17,    37,    97,    20,    21,    22,   340,
      24,    38,    26,    27,    31,    32,    41,    31,    32,    41,
      45,    38,    36,    45,    38,    20,    21,    22,    42,   389,
      44,    45,    46,    47,    40,   181,   396,    43,    20,    21,
      22,    22,   134,    24,    41,    41,    16,    28,    45,    45,
     142,    32,    37,    34,   146,    37,    20,    21,    22,   373,
     420,   373,    20,    21,    22,    37,    24,   404,    26,    27,
      47,   402,   432,    31,    32,    36,    34,    40,    36,    47,
      43,   173,   174,   175,    42,    47,    44,    45,    46,    47,
      40,    40,   184,    43,    43,   409,    36,    40,    36,   413,
      43,   413,    47,    20,    21,    22,     7,     8,     9,    10,
     202,    40,    39,   205,    43,   211,   208,   431,   211,   431,
      37,    13,    14,    15,    20,    21,    22,    16,    24,    40,
      26,    27,    43,    43,    40,    31,    32,    43,    40,     3,
      36,    43,    38,     4,   240,    36,    42,   240,    44,    45,
      46,    47,    40,    36,    40,   251,    23,    43,   251,    42,
      37,    44,    45,    46,    47,    17,   258,   150,   151,   152,
     153,   263,    43,   265,    43,   271,   272,   269,   271,   272,
       5,     6,   274,   275,   276,   277,    40,   435,    47,    43,
     438,    47,    20,    21,    22,    43,    24,    43,    26,    27,
     366,   367,   368,    31,    32,   156,   157,   158,    36,    47,
      38,    43,   308,    47,    42,   308,    44,    45,    46,    47,
     366,   367,   368,    11,    12,    37,    16,    17,   320,    20,
      21,    22,    47,    24,    47,    26,    27,    16,    17,   377,
      45,   379,    33,    34,   340,    36,    40,   340,    16,    17,
      17,    42,    41,    44,    45,    46,    47,    20,    21,    22,
      41,    24,    38,    26,    27,    16,    17,    37,    31,    32,
      41,   363,    45,    36,    24,    25,    17,   373,    47,    42,
     373,    44,    45,    46,    47,    24,    25,    12,    13,   174,
     175,   148,   149,    38,   386,   387,    43,    20,    21,    22,
      40,    24,   398,    26,    27,   398,   402,   154,   155,   402,
      43,    23,    43,    36,    38,    43,    38,   413,    17,    42,
     413,    44,    45,    46,    47,    43,   418,    43,    43,    43,
      40,    17,   424,    41,    45,   431,    45,    17,   431,    17,
      17,    45,    17,    41,    17,    16,    39,    41,    17,    16,
      39,    39,    47,    36,    17,    17,    41,    17,    45,    43,
      17,    17,    17,    39,    46,    16,    16,    16,    36,    17,
      16,    16,    37,    43,    17,    47,    37,    43,    37,    37,
      16,    16,    16,    47,    37,    39,    38,    25,   398,   302,
     361,    38,   296,   360,   338,    39,    38,    36,    39,    39,
      37,    25,    29,    36,   147,   222,    37,    39,    38,    -1,
      39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    49,    50,    51,    47,    47,    47,
       0,    36,    36,    36,    20,    21,    22,    37,    52,    53,
      54,    55,    37,    52,    37,    52,    38,    56,    37,    16,
      47,    56,    37,    56,    37,    20,    21,    22,    24,    26,
      27,    33,    34,    36,    42,    44,    45,    46,    47,    59,
      60,    61,    62,    64,    85,    91,    92,   127,   132,   152,
     154,   156,   159,   164,   167,   171,    56,    53,    56,    56,
      47,    72,    47,    67,    47,    78,    36,    36,    93,    94,
      98,   102,   128,    17,    47,   152,    36,   152,   152,    40,
      43,    84,    88,    39,    59,    16,    59,    43,    59,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    40,    76,    84,    16,    17,    40,    70,    84,
      16,    17,    40,    82,    84,    16,    17,   152,    17,    20,
      21,    47,    61,   106,    36,    40,    17,    23,    37,    41,
      45,   152,    43,    43,    47,   152,   153,   155,   157,   158,
     160,   161,   162,   163,   165,   166,   168,   169,   170,    41,
      45,    43,    47,    41,    43,    47,    41,    43,    47,    37,
      47,    47,    40,    95,    99,   103,   152,    45,    63,    40,
      41,    16,    17,   152,    89,    86,    17,   152,   154,   156,
     156,   159,   159,   159,   159,   164,   164,   167,   167,   167,
      43,    41,    77,    73,    43,    71,    68,    43,    83,    79,
     133,   135,   107,   110,   113,   116,   120,   152,   120,   120,
      37,    41,    16,    37,    45,    40,    61,    17,   152,    43,
      38,    40,   152,    43,    23,   152,    43,    38,   152,    43,
      38,    57,    60,    92,    43,    43,    43,    43,    96,   100,
     104,   129,    40,   171,    17,    41,    45,    90,    87,    39,
      45,    66,    45,    74,    17,    69,    39,    46,    65,    80,
      58,    60,    92,   136,   108,   111,   114,   117,    17,    17,
      17,    17,    24,    31,    32,    38,    60,    92,   119,   130,
     143,    45,    41,    17,   152,    17,    16,    39,    41,   152,
     152,    17,    16,    39,   152,    39,    58,    58,    25,   132,
     137,   138,   152,   152,   152,   152,    47,   121,   121,   121,
      36,    17,    17,    31,    32,    60,    62,    92,   119,   131,
     143,    41,    66,    17,    75,    65,    17,    81,   134,    24,
      38,   119,   109,   112,   115,   118,   122,   125,    97,   101,
     105,   152,    17,    17,   131,   131,   131,   131,    39,   131,
      16,    16,   137,    36,    58,    17,    16,    16,    16,    43,
      43,    37,    37,    37,    37,   131,   131,    47,    72,    47,
      78,   152,    39,   106,   106,   106,   123,   126,    17,    38,
     119,   144,    37,   152,   152,   131,    38,   139,   141,   124,
      39,   131,    38,    57,    16,    39,    58,   142,   121,   145,
      39,   138,    24,    25,   143,   146,   147,   140,    36,    24,
      38,   119,   138,   152,    36,   131,    37,   152,    39,    37,
     148,   150,    38,   119,   131,   151,    39,   147,   149,   147
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    51,    51,    51,    51,
      52,    53,    53,    54,    55,    55,    55,    56,    57,    57,
      58,    58,    58,    59,    59,    59,    59,    59,    60,    60,
      60,    61,    61,    61,    62,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    66,    66,    68,
      69,    67,    70,    71,    67,    67,    67,    73,    74,    75,
      72,    76,    77,    72,    72,    72,    79,    80,    81,    78,
      82,    83,    78,    78,    78,    84,    84,    84,    85,    85,
      86,    87,    61,    88,    89,    90,    61,    61,    91,    92,
      92,    92,    93,    93,    93,    95,    96,    97,    94,    99,
     100,   101,    98,   103,   104,   105,   102,   106,   107,   108,
     109,   106,   110,   111,   112,   106,   113,   114,   115,   106,
     106,   116,   117,   118,   106,   119,   119,   119,   119,   119,
     120,   120,   122,   123,   124,   121,   125,   126,   121,   128,
     129,   127,   130,   130,   130,   131,   131,   131,   131,   131,
     131,   131,   131,   133,   134,   132,   135,   136,   132,   137,
     137,   139,   140,   138,   138,   141,   142,   138,   138,   138,
     144,   145,   143,   146,   146,   148,   149,   147,   147,   150,
     151,   147,   147,   153,   152,   152,   155,   154,   154,   157,
     156,   158,   156,   156,   160,   159,   161,   159,   162,   159,
     163,   159,   159,   165,   164,   166,   164,   164,   168,   167,
     169,   167,   170,   167,   167,   171,   171,   171,   171,   171,
     171,   171,   171
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     6,     6,     6,     5,     5,     5,
       1,     1,     3,     2,     1,     1,     1,     3,     1,     1,
       2,     2,     0,     2,     2,     1,     2,     0,     1,     1,
       1,     5,     4,     5,     6,     3,     0,     3,     7,     3,
       3,     9,     8,     8,     9,     3,     1,     3,     1,     0,
       0,     7,     0,     0,     5,     2,     1,     0,     0,     0,
      10,     0,     0,     5,     2,     1,     0,     0,     0,    10,
       0,     0,     5,     2,     1,     3,     6,     5,     3,     2,
       0,     0,     7,     0,     0,     0,     7,     4,     2,     2,
       1,     1,     1,     1,     1,     0,     0,     0,    10,     0,
       0,     0,    12,     0,     0,     0,    10,     1,     0,     0,
       0,     8,     0,     0,     0,     9,     0,     0,     0,     9,
       1,     0,     0,     0,     9,     1,     1,     2,     2,     1,
       1,     0,     0,     0,     0,     8,     0,     0,     5,     0,
       0,     7,     3,     1,     1,     3,     3,     2,     2,     2,
       2,     2,     0,     0,     0,    10,     0,     0,     8,     1,
       1,     0,     0,    11,     4,     0,     0,     9,     2,     0,
       0,     0,    10,     1,     1,     0,     0,    11,     4,     0,
       0,     9,     2,     0,     4,     1,     0,     4,     1,     0,
       4,     0,     4,     1,     0,     4,     0,     4,     0,     4,
       0,     4,     1,     0,     4,     0,     4,     1,     0,     4,
       0,     4,     0,     4,     1,     1,     3,     2,     1,     1,
       1,     4,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 56 "newTag.y"
                        {printf("Input accepted.\n");}
#line 1738 "y.tab.c"
    break;

  case 49:
#line 124 "newTag.y"
                                                           {push();}
#line 1744 "y.tab.c"
    break;

  case 50:
#line 124 "newTag.y"
                                                                           {push();}
#line 1750 "y.tab.c"
    break;

  case 51:
#line 124 "newTag.y"
                                                                                                         {codegen_assign();}
#line 1756 "y.tab.c"
    break;

  case 52:
#line 125 "newTag.y"
                             {push();}
#line 1762 "y.tab.c"
    break;

  case 53:
#line 125 "newTag.y"
                                             {push();}
#line 1768 "y.tab.c"
    break;

  case 54:
#line 125 "newTag.y"
                                                                           {codegen_assign();}
#line 1774 "y.tab.c"
    break;

  case 57:
#line 129 "newTag.y"
                                                         {push();}
#line 1780 "y.tab.c"
    break;

  case 58:
#line 129 "newTag.y"
                                                                         {push();}
#line 1786 "y.tab.c"
    break;

  case 59:
#line 129 "newTag.y"
                                                                                                       {codegen_assign();}
#line 1792 "y.tab.c"
    break;

  case 61:
#line 130 "newTag.y"
                             {push();printf("pushed identifier\n");}
#line 1798 "y.tab.c"
    break;

  case 62:
#line 130 "newTag.y"
                                                                           {push();}
#line 1804 "y.tab.c"
    break;

  case 63:
#line 130 "newTag.y"
                                                                                                         {codegen_assign();}
#line 1810 "y.tab.c"
    break;

  case 66:
#line 134 "newTag.y"
                                                             {push();}
#line 1816 "y.tab.c"
    break;

  case 67:
#line 134 "newTag.y"
                                                                             {push();}
#line 1822 "y.tab.c"
    break;

  case 68:
#line 134 "newTag.y"
                                                                                                           {codegen_assign();}
#line 1828 "y.tab.c"
    break;

  case 70:
#line 135 "newTag.y"
                             {push();}
#line 1834 "y.tab.c"
    break;

  case 71:
#line 135 "newTag.y"
                                             {push();}
#line 1840 "y.tab.c"
    break;

  case 72:
#line 135 "newTag.y"
                                                                           {codegen_assign();}
#line 1846 "y.tab.c"
    break;

  case 80:
#line 146 "newTag.y"
                                                           {push();}
#line 1852 "y.tab.c"
    break;

  case 81:
#line 146 "newTag.y"
                                                                           {push();}
#line 1858 "y.tab.c"
    break;

  case 82:
#line 146 "newTag.y"
                                                                                                         {codegen_assign();}
#line 1864 "y.tab.c"
    break;

  case 83:
#line 147 "newTag.y"
                             {push();}
#line 1870 "y.tab.c"
    break;

  case 84:
#line 147 "newTag.y"
                                             {push();}
#line 1876 "y.tab.c"
    break;

  case 85:
#line 147 "newTag.y"
                                                                           {codegen_assign();}
#line 1882 "y.tab.c"
    break;

  case 95:
#line 160 "newTag.y"
                                      {for1();}
#line 1888 "y.tab.c"
    break;

  case 96:
#line 160 "newTag.y"
                                                                {for2();}
#line 1894 "y.tab.c"
    break;

  case 97:
#line 160 "newTag.y"
                                                                                                       {for3();}
#line 1900 "y.tab.c"
    break;

  case 98:
#line 160 "newTag.y"
                                                                                                                                  {for4();}
#line 1906 "y.tab.c"
    break;

  case 99:
#line 161 "newTag.y"
                                     {for1();}
#line 1912 "y.tab.c"
    break;

  case 100:
#line 161 "newTag.y"
                                                               {for2();}
#line 1918 "y.tab.c"
    break;

  case 101:
#line 161 "newTag.y"
                                                                                                      {for3();}
#line 1924 "y.tab.c"
    break;

  case 102:
#line 161 "newTag.y"
                                                                                                                                          {for4();}
#line 1930 "y.tab.c"
    break;

  case 103:
#line 162 "newTag.y"
                                     {for1();}
#line 1936 "y.tab.c"
    break;

  case 104:
#line 162 "newTag.y"
                                                               {for2();}
#line 1942 "y.tab.c"
    break;

  case 105:
#line 162 "newTag.y"
                                                                                                      {for3();}
#line 1948 "y.tab.c"
    break;

  case 106:
#line 162 "newTag.y"
                                                                                                                                           {for4();}
#line 1954 "y.tab.c"
    break;

  case 108:
#line 165 "newTag.y"
                                                         {push();}
#line 1960 "y.tab.c"
    break;

  case 109:
#line 165 "newTag.y"
                                                                         {push();}
#line 1966 "y.tab.c"
    break;

  case 110:
#line 165 "newTag.y"
                                                                                                       {codegen_assign();}
#line 1972 "y.tab.c"
    break;

  case 112:
#line 166 "newTag.y"
                                                         {push();}
#line 1978 "y.tab.c"
    break;

  case 113:
#line 166 "newTag.y"
                                                                         {push();}
#line 1984 "y.tab.c"
    break;

  case 114:
#line 166 "newTag.y"
                                                                                                       {codegen_assign();}
#line 1990 "y.tab.c"
    break;

  case 116:
#line 167 "newTag.y"
                                                          {push();}
#line 1996 "y.tab.c"
    break;

  case 117:
#line 167 "newTag.y"
                                                                          {push();}
#line 2002 "y.tab.c"
    break;

  case 118:
#line 167 "newTag.y"
                                                                                                        {codegen_assign();}
#line 2008 "y.tab.c"
    break;

  case 121:
#line 169 "newTag.y"
                                                          {push();}
#line 2014 "y.tab.c"
    break;

  case 122:
#line 169 "newTag.y"
                                                                          {push();}
#line 2020 "y.tab.c"
    break;

  case 123:
#line 169 "newTag.y"
                                                                                                        {codegen_assign();}
#line 2026 "y.tab.c"
    break;

  case 132:
#line 180 "newTag.y"
                                {push();}
#line 2032 "y.tab.c"
    break;

  case 133:
#line 180 "newTag.y"
                                                {push();}
#line 2038 "y.tab.c"
    break;

  case 134:
#line 180 "newTag.y"
                                                                              {codegen_assign();}
#line 2044 "y.tab.c"
    break;

  case 136:
#line 181 "newTag.y"
                                                     {push();}
#line 2050 "y.tab.c"
    break;

  case 137:
#line 181 "newTag.y"
                                                                     {push();}
#line 2056 "y.tab.c"
    break;

  case 138:
#line 181 "newTag.y"
                                                                                                   {codegen_assign();}
#line 2062 "y.tab.c"
    break;

  case 139:
#line 183 "newTag.y"
                  {while1();}
#line 2068 "y.tab.c"
    break;

  case 140:
#line 183 "newTag.y"
                                                                {while2();}
#line 2074 "y.tab.c"
    break;

  case 141:
#line 183 "newTag.y"
                                                                                        {while3();}
#line 2080 "y.tab.c"
    break;

  case 153:
#line 198 "newTag.y"
                                                   {ifelse1();}
#line 2086 "y.tab.c"
    break;

  case 154:
#line 198 "newTag.y"
                                                                                       {ifelse2();}
#line 2092 "y.tab.c"
    break;

  case 156:
#line 199 "newTag.y"
                                                               {ifelse1();}
#line 2098 "y.tab.c"
    break;

  case 157:
#line 199 "newTag.y"
                                                                                            {ifelse2();}
#line 2104 "y.tab.c"
    break;

  case 161:
#line 204 "newTag.y"
                                               {ifelse1();}
#line 2110 "y.tab.c"
    break;

  case 162:
#line 204 "newTag.y"
                                                                                   {ifelse2();}
#line 2116 "y.tab.c"
    break;

  case 164:
#line 205 "newTag.y"
                                      {ifelse3();}
#line 2122 "y.tab.c"
    break;

  case 165:
#line 206 "newTag.y"
                                                {ifelse1();}
#line 2128 "y.tab.c"
    break;

  case 166:
#line 206 "newTag.y"
                                                                             {ifelse2();}
#line 2134 "y.tab.c"
    break;

  case 168:
#line 207 "newTag.y"
                                   {ifelse3();}
#line 2140 "y.tab.c"
    break;

  case 170:
#line 210 "newTag.y"
                                                         {ifelse1();}
#line 2146 "y.tab.c"
    break;

  case 171:
#line 210 "newTag.y"
                                                                                         {ifelse2();}
#line 2152 "y.tab.c"
    break;

  case 175:
#line 215 "newTag.y"
                                                   {ifelse1();}
#line 2158 "y.tab.c"
    break;

  case 176:
#line 215 "newTag.y"
                                                                                   {ifelse2();}
#line 2164 "y.tab.c"
    break;

  case 178:
#line 216 "newTag.y"
                                  {ifelse3();}
#line 2170 "y.tab.c"
    break;

  case 179:
#line 217 "newTag.y"
                                                    {ifelse1();}
#line 2176 "y.tab.c"
    break;

  case 180:
#line 217 "newTag.y"
                                                                                     {ifelse2();}
#line 2182 "y.tab.c"
    break;

  case 182:
#line 218 "newTag.y"
                                   {ifelse3();}
#line 2188 "y.tab.c"
    break;

  case 183:
#line 221 "newTag.y"
                                                  {codegen_assigna();}
#line 2194 "y.tab.c"
    break;

  case 185:
#line 222 "newTag.y"
                                    {codegen_assigna();}
#line 2200 "y.tab.c"
    break;

  case 186:
#line 224 "newTag.y"
                                          {codegen_assigna();}
#line 2206 "y.tab.c"
    break;

  case 188:
#line 225 "newTag.y"
                             {codegen_assigna();}
#line 2212 "y.tab.c"
    break;

  case 189:
#line 227 "newTag.y"
                                         {push();}
#line 2218 "y.tab.c"
    break;

  case 191:
#line 228 "newTag.y"
                                                {push();}
#line 2224 "y.tab.c"
    break;

  case 194:
#line 231 "newTag.y"
                                         {push();}
#line 2230 "y.tab.c"
    break;

  case 195:
#line 231 "newTag.y"
                                                                        {codegen();}
#line 2236 "y.tab.c"
    break;

  case 196:
#line 232 "newTag.y"
                                           {push();}
#line 2242 "y.tab.c"
    break;

  case 197:
#line 232 "newTag.y"
                                                                          {codegen();}
#line 2248 "y.tab.c"
    break;

  case 198:
#line 233 "newTag.y"
                                 {push();}
#line 2254 "y.tab.c"
    break;

  case 199:
#line 233 "newTag.y"
                                                                {codegen();}
#line 2260 "y.tab.c"
    break;

  case 200:
#line 234 "newTag.y"
                                        {push();}
#line 2266 "y.tab.c"
    break;

  case 201:
#line 234 "newTag.y"
                                                                       {codegen();}
#line 2272 "y.tab.c"
    break;

  case 202:
#line 235 "newTag.y"
                        {pushab();}
#line 2278 "y.tab.c"
    break;

  case 203:
#line 237 "newTag.y"
                 {push();}
#line 2284 "y.tab.c"
    break;

  case 205:
#line 238 "newTag.y"
                   {push();}
#line 2290 "y.tab.c"
    break;

  case 208:
#line 241 "newTag.y"
                   {push();}
#line 2296 "y.tab.c"
    break;

  case 209:
#line 241 "newTag.y"
                                  {codegen();}
#line 2302 "y.tab.c"
    break;

  case 210:
#line 242 "newTag.y"
                     {push();}
#line 2308 "y.tab.c"
    break;

  case 211:
#line 242 "newTag.y"
                                    {codegen();}
#line 2314 "y.tab.c"
    break;

  case 212:
#line 243 "newTag.y"
                     {push();}
#line 2320 "y.tab.c"
    break;

  case 213:
#line 243 "newTag.y"
                                    {codegen();}
#line 2326 "y.tab.c"
    break;

  case 215:
#line 246 "newTag.y"
                    {push();}
#line 2332 "y.tab.c"
    break;

  case 217:
#line 248 "newTag.y"
                                         {codegen_assigna();}
#line 2338 "y.tab.c"
    break;

  case 218:
#line 249 "newTag.y"
                  {push();}
#line 2344 "y.tab.c"
    break;

  case 219:
#line 250 "newTag.y"
                 {push();}
#line 2350 "y.tab.c"
    break;

  case 220:
#line 251 "newTag.y"
                   {push();}
#line 2356 "y.tab.c"
    break;


#line 2360 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 255 "newTag.y"


#include "lex.yy.c"
#include<ctype.h>
char st[100][100];

char i_[2]="0";
int temp_i=0;
char tmp_i[3];
char temp[2]="t";
int label[20];
int lnum=0;
int ltop=0;
int abcd=0;
int l_while=0;
int l_for=0;
int flag_set = 1;

int main(int argc,char *argv[])
{

  yyin = fopen("input.c","r");
  if(!yyparse())  //yyparse-> 0 if success
  {
    printf("Parsing Complete\n");
    printf("---------------------Quadruples-------------------------\n\n");
    printf("Operator \t Arg1 \t\t Arg2 \t\t Result \n");
    int i;
    for(i=0;i<quadlen;i++)
    {
        printf("%-8s \t %-8s \t %-8s \t %-6s \n",q[i].op,q[i].arg1,q[i].arg2,q[i].res);
    }
  }
  else
  {
    printf("Parsing failed\n");
  }

  fclose(yyin);
  return 0;
}

void yyerror(char *s)
{
  printf("Error :%s at %d \n",yylval,yylineno);
}

push()
{
strcpy(st[++top],yylval);
printf("pushed: %s\n",yylval);
}
pusha()
{
strcpy(st[++top],"  ");
printf("pushed one space\n");
}
pushx()
{
strcpy(st[++top],"x ");
}
pushab()
{
strcpy(st[++top],"  ");
strcpy(st[++top],"  ");
strcpy(st[++top],"  ");
printf("pushed 3 space\n");
}
codegen()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    //printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-1]);
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    top-=2;
    strcpy(st[top],temp);

temp_i++;
}
codegen_assigna()
{
strcpy(temp,"T");
sprintf(tmp_i, "%d", temp_i);
strcat(temp,tmp_i);
//printf("%s = %s %s %s %s\n",temp,st[top-3],st[top-2],st[top-1],st[top]);
////printf("%d\n",strlen(st[top]));
if(strlen(st[top])==1)
{
	////printf("hello");
	
    char t[20];
	////printf("hello");
	strcpy(t,st[top-2]);
	strcat(t,st[top-1]);
	q[quadlen].op = (char*)malloc(sizeof(char)*strlen(t));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,t);
    strcpy(q[quadlen].arg1,st[top-3]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    
}
else
{
	q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-2]);
    strcpy(q[quadlen].arg1,st[top-3]);
    strcpy(q[quadlen].arg2,st[top-1]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
}
top-=4;

temp_i++;
strcpy(st[++top],temp);
}

codegen_umin()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    //printf("%s = -%s\n",temp,st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"-");
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    top--;
    strcpy(st[top],temp);
    temp_i++;
}
codegen_assign()
{
    //printf("%s = %s\n",st[top-3],st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(st[top-3]));
    strcpy(q[quadlen].op,"=");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,st[top-3]);
    quadlen++;
    top-=2;
}

if1()
{
 lnum++;
 strcpy(temp,"T");
 sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
 //printf("%s = not %s\n",temp,st[top]);
 q[quadlen].op = (char*)malloc(sizeof(char)*4);
 q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
 q[quadlen].arg2 = NULL;
 q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
 strcpy(q[quadlen].op,"not");
 strcpy(q[quadlen].arg1,st[top]);
 strcpy(q[quadlen].res,temp);
 quadlen++;
 //printf("if %s goto L%d\n",temp,lnum);
 q[quadlen].op = (char*)malloc(sizeof(char)*3);
 q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
 q[quadlen].arg2 = NULL;
 q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
 strcpy(q[quadlen].op,"if");
 strcpy(q[quadlen].arg1,st[top-2]);
 char x[10];
 sprintf(x,"%d",lnum);
 char l[]="L";
 strcpy(q[quadlen].res,strcat(l,x));
 quadlen++;

 temp_i++;
 label[++ltop]=lnum;
}

if3()
{
    int y;
    y=label[ltop--];
    //printf("L%d: \n",y);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
}

ifelse1()
{
    lnum++;
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    //printf("%s = not %s\n",temp,st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    //printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
    temp_i++;
    label[++ltop]=lnum;
}

ifelse2()
{
    int x;
    lnum++;
    x=label[ltop--];
    //printf("goto L%d\n",lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
    //printf("L%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");

    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
    label[++ltop]=lnum;
}

ifelse3()
{
int y;
y=label[ltop--];
//printf("L%d: \n",y);
q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
lnum++;
}

ternary1()
{
 lnum++;
 strcpy(temp,"T");
 sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
 //printf("%s = not %s\n",temp,st[top]);
 q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
 //printf("if %s goto L%d\n",temp,lnum);
 q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

 temp_i++;
 label[++ltop]=lnum;
}

ternary2()
{
int x;
lnum++;
x=label[ltop--];
//printf("goto L%d\n",lnum);
q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
//printf("L%d: \n",x);
q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
    label[++ltop]=lnum;
}

ternary3()
{
int y;
y=label[ltop--];
//printf("L%d: \n",y);
q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",y);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
lnum++;
}

while1()
{

    l_while = lnum;
    //printf("L%d: \n",lnum++);
	lnum++;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
}

while2()
{
 strcpy(temp,"T");
 sprintf(tmp_i, "%d", temp_i);
 strcat(temp,tmp_i);
 //printf("%s = not %s\n",temp,st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    //printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

 temp_i++;
 }

while3()
{

//printf("goto L%d \n",l_while);
q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(l_while+2));
    strcpy(q[quadlen].op,"goto");
    char x[10];
    sprintf(x,"%d",l_while);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
    //printf("L%d: \n",lnum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x1[10];
    sprintf(x1,"%d",lnum-1);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,x1));
    quadlen++;
}

for1()
{
    l_for = lnum;
    //printf("L%d: \n",lnum++);
	lnum++;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
}
for2()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    //printf("%s = not %s\n",temp,st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    //printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;

    temp_i++;
    label[++ltop]=lnum;
    lnum++;
    //printf("goto L%d\n",lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char x1[10];
    sprintf(x1,"%d",lnum);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,x1));
    quadlen++;
    label[++ltop]=lnum;
    //printf("L%d: \n",++lnum);
	++lnum;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x2[10];
    sprintf(x2,"%d",lnum);
    char l2[]="L";
    strcpy(q[quadlen].res,strcat(l2,x2));
    quadlen++;
 }
for3()
{
    int x;
    x=label[ltop--];
    //printf("goto L%d \n",l_for);

    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",l_for);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;


    //printf("L%d: \n",x);

    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;

}

for4()
{
    int x;
    x=label[ltop--];
    //printf("goto L%d \n",lnum);

    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;

    //printf("L%d: \n",x);

    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
}
