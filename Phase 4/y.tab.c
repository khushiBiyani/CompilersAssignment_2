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
#define YYLAST   489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  126
/* YYNRULES -- Number of rules.  */
#define YYNRULES  223
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  435

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
       0,    56,    56,    59,    61,    62,    63,    64,    65,    67,
      68,    69,    71,    73,    74,    75,    77,    79,    80,    82,
      83,    84,    86,    87,    88,    89,    91,    92,    94,    95,
      96,    98,    99,   100,   102,   104,   105,   107,   108,   109,
     110,   111,   112,   113,   114,   116,   117,   119,   120,   122,
     122,   122,   122,   123,   123,   123,   124,   125,   127,   127,
     127,   127,   128,   128,   128,   129,   130,   132,   132,   132,
     132,   133,   133,   133,   134,   135,   137,   138,   139,   141,
     142,   144,   144,   144,   144,   145,   145,   145,   145,   146,
     148,   149,   150,   152,   153,   154,   156,   156,   156,   156,
     157,   157,   157,   157,   158,   158,   158,   158,   160,   161,
     161,   161,   161,   162,   162,   162,   162,   163,   163,   163,
     163,   164,   165,   165,   165,   165,   167,   168,   169,   170,
     171,   173,   174,   176,   176,   176,   176,   177,   177,   177,
     179,   179,   179,   181,   182,   183,   185,   186,   187,   188,
     189,   190,   191,   192,   194,   194,   194,   195,   195,   195,
     197,   198,   200,   200,   200,   201,   202,   202,   202,   203,
     204,   206,   206,   206,   208,   209,   211,   211,   211,   212,
     213,   213,   213,   214,   217,   217,   218,   220,   220,   221,
     223,   223,   224,   224,   225,   227,   227,   228,   228,   229,
     229,   230,   230,   231,   233,   233,   234,   234,   235,   237,
     237,   238,   238,   239,   239,   240,   242,   243,   244,   245,
     246,   247,   248,   249
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
  "statementList", "basicStatements", "basicStatement",
  "assignmentStatement", "printer", "prattributes", "declarationStatement",
  "arrayValuesF", "arrayValues", "declarationListChar", "$@1", "$@2",
  "$@3", "$@4", "$@5", "declarationListInt", "$@6", "$@7", "$@8", "$@9",
  "$@10", "declarationListFloat", "$@11", "$@12", "$@13", "$@14", "$@15",
  "dimension", "returnDec", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21",
  "specialStatement", "forLoop", "forLoop1", "$@22", "$@23", "$@24",
  "forLoop2", "$@25", "$@26", "$@27", "forLoop3", "$@28", "$@29", "$@30",
  "forAssignStatement", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36",
  "$@37", "$@38", "$@39", "$@40", "$@41", "$@42", "singleLoopStatement",
  "forExpStatement", "forUpdateStatement", "$@43", "$@44", "$@45", "$@46",
  "$@47", "whileLoop", "$@48", "$@49", "whileSuffix", "inLoop",
  "ifStatement", "$@50", "$@51", "$@52", "$@53", "ifContinuer", "ES",
  "$@54", "$@55", "$@56", "$@57", "ifInLoopStatement", "$@58", "$@59",
  "ifInLoopContinuer", "ESLoop", "$@60", "$@61", "$@62", "$@63",
  "expressionStatement", "$@64", "logicalExpression", "$@65", "expression",
  "$@66", "$@67", "relationalExpression", "$@68", "$@69", "$@70", "$@71",
  "value", "$@72", "$@73", "term", "$@74", "$@75", "$@76", "factor", YY_NULLPTR
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

#define YYPACT_NINF (-356)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-181)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     156,     2,    12,    20,    87,  -356,  -356,    79,    86,    93,
    -356,    64,    76,   167,  -356,  -356,  -356,   101,    63,  -356,
     141,   115,   101,   132,   134,   159,  -356,   101,   167,  -356,
    -356,   101,   101,   147,   153,   155,   176,   181,  -356,    46,
     187,    74,    74,  -356,  -356,  -356,   112,   188,   159,   281,
    -356,   159,  -356,  -356,   159,  -356,  -356,  -356,   226,   227,
     261,   189,   265,   244,  -356,  -356,  -356,  -356,    -8,   220,
       5,   237,    13,   251,    74,    17,  -356,  -356,  -356,  -356,
     234,  -356,   240,   257,   264,   248,  -356,    54,    74,   249,
     290,   292,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,
    -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,
      62,   295,   296,  -356,  -356,    82,   297,   302,  -356,  -356,
      97,   307,   308,  -356,  -356,   268,  -356,   252,   282,   206,
    -356,  -356,    74,   313,  -356,  -356,  -356,   319,   312,   256,
      74,  -356,  -356,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,   207,   320,  -356,  -356,
     208,  -356,  -356,   212,  -356,  -356,   322,  -356,  -356,   113,
      74,    74,    74,   325,   323,    -2,   318,   213,   324,  -356,
     348,    74,    74,  -356,  -356,  -356,  -356,  -356,  -356,  -356,
    -356,  -356,  -356,  -356,  -356,  -356,   328,   327,    74,    74,
     346,    74,    74,   335,    74,    74,   338,   104,   334,   336,
     337,   339,  -356,  -356,  -356,  -356,  -356,   344,    74,   361,
     350,   349,  -356,  -356,  -356,  -356,   -26,   351,  -356,  -356,
     372,  -356,  -356,    -6,  -356,  -356,   104,  -356,  -356,  -356,
    -356,  -356,  -356,  -356,   378,   382,   383,    34,   359,  -356,
    -356,  -356,   364,   390,   392,   397,   391,   376,   375,   401,
    -356,   402,   403,   405,   380,   406,   384,   104,   104,   266,
      74,    74,    74,    74,   377,   377,   377,  -356,   389,   409,
     410,   194,  -356,  -356,  -356,  -356,  -356,   387,   386,   324,
    -356,  -356,   385,   414,  -356,   388,   393,  -356,   395,   415,
     396,  -356,  -356,  -356,   262,  -356,  -356,  -356,  -356,  -356,
    -356,  -356,  -356,  -356,  -356,  -356,    74,  -356,  -356,   416,
     417,   194,   194,   194,   194,   398,   194,  -356,  -356,  -356,
    -356,    22,  -356,    31,  -356,  -356,  -356,    35,  -356,   266,
     400,   104,  -356,   421,   423,   426,   428,   404,   407,   408,
     411,   412,   418,   194,   194,  -356,  -356,  -356,  -356,  -356,
    -356,  -356,    74,   413,  -356,    17,    17,    17,  -356,  -356,
     429,   419,   366,   322,  -356,  -356,   422,  -356,  -356,  -356,
    -356,    74,    74,  -356,   194,  -356,   420,   322,  -356,  -356,
     424,   194,   427,   104,   435,  -356,   425,   104,  -356,   377,
    -356,   430,   431,  -356,   286,  -356,  -356,   432,   310,  -356,
    -356,  -356,   431,    74,   434,   194,  -356,  -356,   436,    74,
     433,  -356,   437,  -356,   -11,   438,   366,   194,  -356,   439,
     441,  -356,  -356,   441,  -356
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     3,     0,     0,     0,
       1,     0,     0,     0,    13,    15,    14,     0,     0,     9,
      10,     0,     0,     0,     0,     0,     7,     0,     0,    12,
       8,     0,     0,     0,     0,     0,     0,     0,   140,     0,
       0,     0,     0,   219,   220,   221,   216,     0,     0,    27,
      30,     0,    29,    24,     0,    92,    91,    28,   186,   189,
     194,   203,   208,   215,     4,    11,     5,     6,    58,     0,
      49,     0,    67,     0,     0,     0,    90,    95,    93,    94,
       0,    80,   216,     0,     0,     0,   218,     0,     0,     0,
       0,     0,    16,    22,    26,    25,    23,   184,   187,   190,
     192,   195,   197,   199,   201,   204,   206,   209,   211,   213,
       0,     0,     0,    65,    37,     0,     0,     0,    56,    39,
       0,     0,     0,    74,    40,     0,   121,     0,     0,     0,
     108,    96,     0,     0,    79,    36,   217,     0,     0,     0,
       0,    82,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,    63,
       0,    50,    54,     0,    68,    72,   157,   109,   117,     0,
     132,   132,   132,     0,     0,     0,     0,   222,     0,    32,
       0,     0,     0,   185,   188,   191,   193,   196,   198,   200,
     202,   205,   207,   210,   212,   214,     0,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,   131,   101,   105,   141,   222,     0,     0,
       0,     0,    31,    33,    83,    87,     0,     0,    60,    64,
       0,    51,    55,     0,    69,    73,    21,   158,    18,    17,
     110,   114,   118,   123,     0,     0,     0,     0,     0,    35,
      34,    78,     0,     0,     0,     0,    48,     0,     0,     0,
      38,     0,     0,    46,     0,     0,     0,    21,    21,   170,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,   153,   127,   126,   145,   142,   130,     0,   223,     0,
      88,    42,     0,     0,    77,     0,     0,    43,     0,     0,
       0,   155,    20,    19,     0,   161,   159,   160,   111,   115,
     119,   124,   133,    98,   102,   106,     0,   128,   129,     0,
       0,   127,   153,   126,   153,     0,   130,   223,    84,    47,
      41,    58,    61,    49,    52,    45,    44,    67,    70,   170,
       0,    21,   169,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   129,   149,   152,   148,   151,   143,
     150,   156,     0,     0,   112,     0,     0,     0,   134,   138,
       0,     0,     0,   157,   146,   147,     0,   165,   116,   120,
     125,     0,     0,    99,   153,   107,     0,   157,   135,   139,
       0,   153,     0,     0,     0,   103,     0,    21,   167,     0,
     172,     0,   170,   136,     0,   163,   168,     0,     0,   175,
     173,   174,   170,     0,     0,   153,   183,   164,     0,     0,
       0,   171,     0,   179,   157,     0,     0,   153,   181,     0,
       0,   177,   182,     0,   178
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -356,  -356,  -356,  -356,   300,   443,  -356,  -356,   143,    61,
    -252,   105,   440,   -25,   -70,    58,  -356,  -356,   162,   161,
     165,  -356,  -356,  -356,  -356,  -356,   172,  -356,  -356,  -356,
    -356,  -356,   175,  -356,  -356,  -356,  -356,  -356,   -62,  -356,
    -356,  -356,  -356,  -356,  -356,  -356,   -23,  -356,  -356,  -356,
    -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,
    -105,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,
    -356,  -356,  -356,  -235,   148,  -258,  -356,  -356,  -356,  -356,
    -356,  -356,  -356,  -356,  -356,  -280,  -262,  -356,  -356,  -356,
    -356,   123,  -355,  -356,  -356,  -356,  -356,  -236,  -356,  -356,
    -356,  -316,  -356,  -356,  -356,  -356,   -38,  -356,   333,  -356,
     169,  -356,  -356,    60,  -356,  -356,  -356,  -356,   170,  -356,
    -356,   110,  -356,  -356,  -356,   263
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    18,    19,    20,    21,    26,   237,
     266,    47,    48,   321,    50,   322,   175,    52,   264,   257,
      71,   116,   201,   261,   117,   202,    69,   111,   198,   259,
     112,   199,    73,   121,   204,   265,   122,   205,    89,    53,
      90,   181,   253,    91,   182,   254,   323,    76,    77,   170,
     244,   349,    78,   171,   245,   350,    79,   172,   246,   351,
     131,   208,   270,   343,   209,   271,   344,   210,   272,   345,
     211,   273,   346,   324,   212,   313,   347,   381,   394,   348,
     382,    55,    80,   247,   285,   325,    56,   206,   339,   207,
     269,   306,   307,   392,   412,   393,   402,   326,   386,   404,
     410,   411,   425,   433,   426,   430,    57,   143,    58,   144,
      59,   145,   146,    60,   147,   148,   149,   150,    61,   151,
     152,    62,   153,   154,   155,    63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    83,    54,    85,    86,   130,   113,   305,   118,   -66,
     123,   286,   284,   255,   218,   302,   303,   314,   315,   256,
    -180,  -180,   -57,    49,    49,    54,    49,  -154,    54,    49,
     -75,    54,   110,   262,   126,   219,   125,   127,   128,   -66,
     263,   355,   356,   357,   358,   115,   360,   406,   -57,     7,
     139,   277,   -75,   120,    33,    34,    35,   417,   278,     8,
      37,    38,   169,    81,   129,   279,   280,     9,   286,   342,
      41,   169,   281,   374,   375,   169,    42,   305,    43,    44,
      45,    46,    41,    51,    14,    15,    16,    10,    42,   363,
      43,    44,    45,    82,   173,   137,    14,    15,    16,   138,
      27,    17,   180,   156,   390,   183,    51,   157,   222,    51,
      41,   396,    51,    22,   432,    11,    42,   434,    43,    44,
      45,    82,    12,   160,    33,    34,    35,   157,    36,    13,
      37,    38,   213,   213,   213,   420,   286,   385,   163,    25,
      41,   403,   157,   224,   225,   401,    42,   429,    43,    44,
      45,    46,    87,    93,   137,    88,    95,    28,   157,    96,
     228,   229,    29,   231,   232,    30,   234,   235,   409,    31,
      64,    32,   286,   416,    66,    67,     1,     2,     3,    33,
      34,    35,   238,    36,   239,    37,    38,    14,    15,    16,
     286,   428,    39,    40,    68,    41,   101,   102,   103,   104,
      70,    42,    72,    43,    44,    45,    46,   187,   188,   189,
     190,   267,    74,   268,    33,    34,    35,    75,   278,   328,
      37,    38,   282,    84,   283,   319,   320,    92,    40,    97,
      41,    98,   308,   309,   310,   311,    42,   114,    43,    44,
      45,    46,   267,   267,   268,   268,   169,   176,   176,    88,
     196,   200,   176,   221,   119,   203,   -76,   107,   108,   109,
     378,   379,   380,   193,   194,   195,    99,   100,   124,   113,
     132,   118,   178,   179,   134,   123,   105,   106,   352,   282,
     133,   283,    33,    34,    35,   136,   340,   135,    37,    38,
      36,   304,   140,   279,   280,   130,   130,   130,    41,   167,
     341,    33,    34,    35,    42,   166,    43,    44,    45,    46,
     407,   408,    23,    24,   185,   186,   267,    41,   268,   214,
     215,   191,   192,    42,   376,    43,    44,    45,    46,   168,
      33,    34,    35,   141,   414,   142,    37,    38,   158,   159,
     161,   279,   280,   388,   389,   162,    41,   282,   415,   283,
     164,   165,    42,   177,    43,    44,    45,    46,   174,   176,
    -154,   197,   216,   220,   217,   223,   226,   227,   238,   230,
     239,   129,   267,   233,   268,   418,   236,   240,   250,   241,
     242,   422,   243,   282,   248,   283,    33,    34,    35,   260,
     278,   251,    37,    38,   252,   274,   258,   279,   280,   275,
     276,   282,    41,   283,   287,   288,   289,   292,    42,   290,
      43,    44,    45,    46,   291,   293,   294,   295,   296,   299,
     297,   298,   300,   301,   312,   316,   317,   318,   327,   -77,
     256,   330,   336,   353,   354,   331,   362,   359,   364,   365,
     333,   263,   366,   337,   367,   370,   383,   368,   371,   372,
     369,   399,   377,   329,   398,   373,   304,   384,   391,   387,
     335,   334,   361,   395,   400,   397,   408,   332,   413,   405,
     419,    65,   423,   421,   424,   338,   427,   184,   431,     0,
       0,   249,     0,     0,     0,     0,     0,     0,     0,    94
};

static const yytype_int16 yycheck[] =
{
      25,    39,    25,    41,    42,    75,    68,   269,    70,    17,
      72,   247,   247,    39,    16,   267,   268,   275,   276,    45,
      31,    32,    17,    48,    49,    48,    51,    38,    51,    54,
      17,    54,    40,    39,    17,    37,    74,    20,    21,    17,
      46,   321,   322,   323,   324,    40,   326,   402,    17,    47,
      88,    17,    17,    40,    20,    21,    22,   412,    24,    47,
      26,    27,    40,    17,    47,    31,    32,    47,   304,   304,
      36,    40,    38,   353,   354,    40,    42,   339,    44,    45,
      46,    47,    36,    25,    20,    21,    22,     0,    42,   341,
      44,    45,    46,    47,   132,    41,    20,    21,    22,    45,
      37,    37,   140,    41,   384,   143,    48,    45,   178,    51,
      36,   391,    54,    37,   430,    36,    42,   433,    44,    45,
      46,    47,    36,    41,    20,    21,    22,    45,    24,    36,
      26,    27,   170,   171,   172,   415,   372,   372,    41,    38,
      36,   399,    45,   181,   182,   397,    42,   427,    44,    45,
      46,    47,    40,    48,    41,    43,    51,    16,    45,    54,
     198,   199,    47,   201,   202,    22,   204,   205,   404,    37,
      27,    37,   408,   408,    31,    32,    20,    21,    22,    20,
      21,    22,   207,    24,   207,    26,    27,    20,    21,    22,
     426,   426,    33,    34,    47,    36,     7,     8,     9,    10,
      47,    42,    47,    44,    45,    46,    47,   147,   148,   149,
     150,   236,    36,   236,    20,    21,    22,    36,    24,   289,
      26,    27,   247,    36,   247,    31,    32,    39,    34,     3,
      36,     4,   270,   271,   272,   273,    42,    17,    44,    45,
      46,    47,   267,   268,   267,   268,    40,    40,    40,    43,
      43,    43,    40,    40,    17,    43,    43,    13,    14,    15,
     365,   366,   367,   153,   154,   155,     5,     6,    17,   331,
      36,   333,    16,    17,    17,   337,    11,    12,   316,   304,
      40,   304,    20,    21,    22,    37,    24,    23,    26,    27,
      24,    25,    43,    31,    32,   365,   366,   367,    36,    47,
      38,    20,    21,    22,    42,    37,    44,    45,    46,    47,
      24,    25,    12,    13,   145,   146,   341,    36,   341,   171,
     172,   151,   152,    42,   362,    44,    45,    46,    47,    47,
      20,    21,    22,    43,    24,    43,    26,    27,    43,    43,
      43,    31,    32,   381,   382,    43,    36,   372,    38,   372,
      43,    43,    42,    41,    44,    45,    46,    47,    45,    40,
      38,    41,    37,    45,    41,    17,    38,    40,   393,    23,
     393,    47,   397,    38,   397,   413,    38,    43,    17,    43,
      43,   419,    43,   408,    40,   408,    20,    21,    22,    17,
      24,    41,    26,    27,    45,    17,    45,    31,    32,    17,
      17,   426,    36,   426,    45,    41,    16,    16,    42,    17,
      44,    45,    46,    47,    17,    39,    41,    16,    16,    39,
      17,    16,    16,    39,    47,    36,    17,    17,    41,    43,
      45,    17,    17,    17,    17,    47,    36,    39,    17,    16,
      47,    46,    16,    47,    16,    37,    17,    43,    37,    37,
      43,    16,    39,   292,   393,    37,    25,    38,    38,    37,
     298,   296,   339,    39,    39,    38,    25,   295,    36,    39,
      36,    28,    39,    37,    37,   300,    38,   144,    39,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    49,    50,    51,    47,    47,    47,
       0,    36,    36,    36,    20,    21,    22,    37,    52,    53,
      54,    55,    37,    52,    52,    38,    56,    37,    16,    47,
      56,    37,    37,    20,    21,    22,    24,    26,    27,    33,
      34,    36,    42,    44,    45,    46,    47,    59,    60,    61,
      62,    63,    65,    87,    94,   129,   134,   154,   156,   158,
     161,   166,   169,   173,    56,    53,    56,    56,    47,    74,
      47,    68,    47,    80,    36,    36,    95,    96,   100,   104,
     130,    17,    47,   154,    36,   154,   154,    40,    43,    86,
      88,    91,    39,    59,    60,    59,    59,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      40,    75,    78,    86,    17,    40,    69,    72,    86,    17,
      40,    81,    84,    86,    17,   154,    17,    20,    21,    47,
      62,   108,    36,    40,    17,    23,    37,    41,    45,   154,
      43,    43,    43,   155,   157,   159,   160,   162,   163,   164,
     165,   167,   168,   170,   171,   172,    41,    45,    43,    43,
      41,    43,    43,    41,    43,    43,    37,    47,    47,    40,
      97,   101,   105,   154,    45,    64,    40,    41,    16,    17,
     154,    89,    92,   154,   156,   158,   158,   161,   161,   161,
     161,   166,   166,   169,   169,   169,    43,    41,    76,    79,
      43,    70,    73,    43,    82,    85,   135,   137,   109,   112,
     115,   118,   122,   154,   122,   122,    37,    41,    16,    37,
      45,    40,    62,    17,   154,   154,    38,    40,   154,   154,
      23,   154,   154,    38,   154,   154,    38,    57,    61,    94,
      43,    43,    43,    43,    98,   102,   106,   131,    40,   173,
      17,    41,    45,    90,    93,    39,    45,    67,    45,    77,
      17,    71,    39,    46,    66,    83,    58,    61,    94,   138,
     110,   113,   116,   119,    17,    17,    17,    17,    24,    31,
      32,    38,    61,    94,   121,   132,   145,    45,    41,    16,
      17,    17,    16,    39,    41,    16,    16,    17,    16,    39,
      16,    39,    58,    58,    25,   134,   139,   140,   154,   154,
     154,   154,    47,   123,   123,   123,    36,    17,    17,    31,
      32,    61,    63,    94,   121,   133,   145,    41,    62,    67,
      17,    47,    74,    47,    68,    66,    17,    47,    80,   136,
      24,    38,   121,   111,   114,   117,   120,   124,   127,    99,
     103,   107,   154,    17,    17,   133,   133,   133,   133,    39,
     133,   139,    36,    58,    17,    16,    16,    16,    43,    43,
      37,    37,    37,    37,   133,   133,   154,    39,   108,   108,
     108,   125,   128,    17,    38,   121,   146,    37,   154,   154,
     133,    38,   141,   143,   126,    39,   133,    38,    57,    16,
      39,    58,   144,   123,   147,    39,   140,    24,    25,   145,
     148,   149,   142,    36,    24,    38,   121,   140,   154,    36,
     133,    37,   154,    39,    37,   150,   152,    38,   121,   133,
     153,    39,   149,   151,   149
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    51,    51,    51,    52,
      53,    53,    54,    55,    55,    55,    56,    57,    57,    58,
      58,    58,    59,    59,    59,    59,    60,    60,    61,    61,
      61,    62,    62,    62,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    67,    67,    69,
      70,    71,    68,    72,    73,    68,    68,    68,    75,    76,
      77,    74,    78,    79,    74,    74,    74,    81,    82,    83,
      80,    84,    85,    80,    80,    80,    86,    86,    86,    87,
      87,    88,    89,    90,    62,    91,    92,    93,    62,    62,
      94,    94,    94,    95,    95,    95,    97,    98,    99,    96,
     101,   102,   103,   100,   105,   106,   107,   104,   108,   109,
     110,   111,   108,   112,   113,   114,   108,   115,   116,   117,
     108,   108,   118,   119,   120,   108,   121,   121,   121,   121,
     121,   122,   122,   124,   125,   126,   123,   127,   128,   123,
     130,   131,   129,   132,   132,   132,   133,   133,   133,   133,
     133,   133,   133,   133,   135,   136,   134,   137,   138,   134,
     139,   139,   141,   142,   140,   140,   143,   144,   140,   140,
     140,   146,   147,   145,   148,   148,   150,   151,   149,   149,
     152,   153,   149,   149,   155,   154,   154,   157,   156,   156,
     159,   158,   160,   158,   158,   162,   161,   163,   161,   164,
     161,   165,   161,   161,   167,   166,   168,   166,   166,   170,
     169,   171,   169,   172,   169,   169,   173,   173,   173,   173,
     173,   173,   173,   173
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     6,     6,     6,     5,     5,     1,
       1,     3,     2,     1,     1,     1,     3,     1,     1,     2,
       2,     0,     2,     2,     1,     2,     2,     1,     1,     1,
       1,     5,     4,     5,     6,     3,     0,     3,     7,     3,
       3,     9,     8,     8,     9,     3,     1,     3,     1,     0,
       0,     0,     8,     0,     0,     5,     2,     1,     0,     0,
       0,     8,     0,     0,     5,     2,     1,     0,     0,     0,
       8,     0,     0,     5,     2,     1,     3,     6,     5,     3,
       2,     0,     0,     0,     8,     0,     0,     0,     7,     5,
       2,     1,     1,     1,     1,     1,     0,     0,     0,    10,
       0,     0,     0,    12,     0,     0,     0,    10,     1,     0,
       0,     0,     8,     0,     0,     0,     9,     0,     0,     0,
       9,     1,     0,     0,     0,     9,     1,     1,     2,     2,
       1,     1,     0,     0,     0,     0,     8,     0,     0,     5,
       0,     0,     7,     3,     1,     1,     3,     3,     2,     2,
       2,     2,     2,     0,     0,     0,    10,     0,     0,     8,
       1,     1,     0,     0,    11,     4,     0,     0,     9,     2,
       0,     0,     0,    10,     1,     1,     0,     0,    11,     4,
       0,     0,     9,     2,     0,     4,     1,     0,     4,     1,
       0,     4,     0,     4,     1,     0,     4,     0,     4,     0,
       4,     0,     4,     1,     0,     4,     0,     4,     1,     0,
       4,     0,     4,     0,     4,     1,     1,     3,     2,     1,
       1,     1,     4,     7
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
#line 122 "newTag.y"
                                 {push();}
#line 1744 "y.tab.c"
    break;

  case 50:
#line 122 "newTag.y"
                                                 {push();}
#line 1750 "y.tab.c"
    break;

  case 51:
#line 122 "newTag.y"
                                                                               {codegen_assign();}
#line 1756 "y.tab.c"
    break;

  case 53:
#line 123 "newTag.y"
                             {push();}
#line 1762 "y.tab.c"
    break;

  case 54:
#line 123 "newTag.y"
                                             {push();}
#line 1768 "y.tab.c"
    break;

  case 55:
#line 123 "newTag.y"
                                                                           {codegen_assign();}
#line 1774 "y.tab.c"
    break;

  case 58:
#line 127 "newTag.y"
                                {push();}
#line 1780 "y.tab.c"
    break;

  case 59:
#line 127 "newTag.y"
                                                {push();}
#line 1786 "y.tab.c"
    break;

  case 60:
#line 127 "newTag.y"
                                                                              {codegen_assign();}
#line 1792 "y.tab.c"
    break;

  case 62:
#line 128 "newTag.y"
                             {push();}
#line 1798 "y.tab.c"
    break;

  case 63:
#line 128 "newTag.y"
                                             {push();}
#line 1804 "y.tab.c"
    break;

  case 64:
#line 128 "newTag.y"
                                                                           {codegen_assign();}
#line 1810 "y.tab.c"
    break;

  case 67:
#line 132 "newTag.y"
                                  {push();}
#line 1816 "y.tab.c"
    break;

  case 68:
#line 132 "newTag.y"
                                                  {push();}
#line 1822 "y.tab.c"
    break;

  case 69:
#line 132 "newTag.y"
                                                                                {codegen_assign();}
#line 1828 "y.tab.c"
    break;

  case 71:
#line 133 "newTag.y"
                             {push();}
#line 1834 "y.tab.c"
    break;

  case 72:
#line 133 "newTag.y"
                                             {push();}
#line 1840 "y.tab.c"
    break;

  case 73:
#line 133 "newTag.y"
                                                                           {codegen_assign();}
#line 1846 "y.tab.c"
    break;

  case 81:
#line 144 "newTag.y"
                                 {push();}
#line 1852 "y.tab.c"
    break;

  case 82:
#line 144 "newTag.y"
                                                 {push();}
#line 1858 "y.tab.c"
    break;

  case 83:
#line 144 "newTag.y"
                                                                               {codegen_assign();}
#line 1864 "y.tab.c"
    break;

  case 85:
#line 145 "newTag.y"
                             {push();}
#line 1870 "y.tab.c"
    break;

  case 86:
#line 145 "newTag.y"
                                             {push();}
#line 1876 "y.tab.c"
    break;

  case 87:
#line 145 "newTag.y"
                                                                           {codegen_assign();}
#line 1882 "y.tab.c"
    break;

  case 96:
#line 156 "newTag.y"
                                      {for1();}
#line 1888 "y.tab.c"
    break;

  case 97:
#line 156 "newTag.y"
                                                                {for2();}
#line 1894 "y.tab.c"
    break;

  case 98:
#line 156 "newTag.y"
                                                                                                       {for3();}
#line 1900 "y.tab.c"
    break;

  case 99:
#line 156 "newTag.y"
                                                                                                                                  {for4();}
#line 1906 "y.tab.c"
    break;

  case 100:
#line 157 "newTag.y"
                                     {for1();}
#line 1912 "y.tab.c"
    break;

  case 101:
#line 157 "newTag.y"
                                                               {for2();}
#line 1918 "y.tab.c"
    break;

  case 102:
#line 157 "newTag.y"
                                                                                                      {for3();}
#line 1924 "y.tab.c"
    break;

  case 103:
#line 157 "newTag.y"
                                                                                                                                          {for4();}
#line 1930 "y.tab.c"
    break;

  case 104:
#line 158 "newTag.y"
                                     {for1();}
#line 1936 "y.tab.c"
    break;

  case 105:
#line 158 "newTag.y"
                                                               {for2();}
#line 1942 "y.tab.c"
    break;

  case 106:
#line 158 "newTag.y"
                                                                                                      {for3();}
#line 1948 "y.tab.c"
    break;

  case 107:
#line 158 "newTag.y"
                                                                                                                                           {for4();}
#line 1954 "y.tab.c"
    break;

  case 109:
#line 161 "newTag.y"
                                                         {push();}
#line 1960 "y.tab.c"
    break;

  case 110:
#line 161 "newTag.y"
                                                                         {push();}
#line 1966 "y.tab.c"
    break;

  case 111:
#line 161 "newTag.y"
                                                                                                       {codegen_assign();}
#line 1972 "y.tab.c"
    break;

  case 113:
#line 162 "newTag.y"
                                                         {push();}
#line 1978 "y.tab.c"
    break;

  case 114:
#line 162 "newTag.y"
                                                                         {push();}
#line 1984 "y.tab.c"
    break;

  case 115:
#line 162 "newTag.y"
                                                                                                       {codegen_assign();}
#line 1990 "y.tab.c"
    break;

  case 117:
#line 163 "newTag.y"
                                                          {push();}
#line 1996 "y.tab.c"
    break;

  case 118:
#line 163 "newTag.y"
                                                                          {push();}
#line 2002 "y.tab.c"
    break;

  case 119:
#line 163 "newTag.y"
                                                                                                        {codegen_assign();}
#line 2008 "y.tab.c"
    break;

  case 122:
#line 165 "newTag.y"
                                                          {push();}
#line 2014 "y.tab.c"
    break;

  case 123:
#line 165 "newTag.y"
                                                                          {push();}
#line 2020 "y.tab.c"
    break;

  case 124:
#line 165 "newTag.y"
                                                                                                        {codegen_assign();}
#line 2026 "y.tab.c"
    break;

  case 133:
#line 176 "newTag.y"
                                {push();}
#line 2032 "y.tab.c"
    break;

  case 134:
#line 176 "newTag.y"
                                                {push();}
#line 2038 "y.tab.c"
    break;

  case 135:
#line 176 "newTag.y"
                                                                              {codegen_assign();}
#line 2044 "y.tab.c"
    break;

  case 137:
#line 177 "newTag.y"
                                                     {push();}
#line 2050 "y.tab.c"
    break;

  case 138:
#line 177 "newTag.y"
                                                                     {push();}
#line 2056 "y.tab.c"
    break;

  case 139:
#line 177 "newTag.y"
                                                                                                   {codegen_assign();}
#line 2062 "y.tab.c"
    break;

  case 140:
#line 179 "newTag.y"
                  {while1();}
#line 2068 "y.tab.c"
    break;

  case 141:
#line 179 "newTag.y"
                                                                {while2();}
#line 2074 "y.tab.c"
    break;

  case 142:
#line 179 "newTag.y"
                                                                                        {while3();}
#line 2080 "y.tab.c"
    break;

  case 154:
#line 194 "newTag.y"
                                                   {ifelse1();}
#line 2086 "y.tab.c"
    break;

  case 155:
#line 194 "newTag.y"
                                                                                       {ifelse2();}
#line 2092 "y.tab.c"
    break;

  case 157:
#line 195 "newTag.y"
                                                               {ifelse1();}
#line 2098 "y.tab.c"
    break;

  case 158:
#line 195 "newTag.y"
                                                                                            {ifelse2();}
#line 2104 "y.tab.c"
    break;

  case 162:
#line 200 "newTag.y"
                                               {ifelse1();}
#line 2110 "y.tab.c"
    break;

  case 163:
#line 200 "newTag.y"
                                                                                   {ifelse2();}
#line 2116 "y.tab.c"
    break;

  case 165:
#line 201 "newTag.y"
                                      {ifelse3();}
#line 2122 "y.tab.c"
    break;

  case 166:
#line 202 "newTag.y"
                                                {ifelse1();}
#line 2128 "y.tab.c"
    break;

  case 167:
#line 202 "newTag.y"
                                                                             {ifelse2();}
#line 2134 "y.tab.c"
    break;

  case 169:
#line 203 "newTag.y"
                                   {ifelse3();}
#line 2140 "y.tab.c"
    break;

  case 171:
#line 206 "newTag.y"
                                                         {ifelse1();}
#line 2146 "y.tab.c"
    break;

  case 172:
#line 206 "newTag.y"
                                                                                         {ifelse2();}
#line 2152 "y.tab.c"
    break;

  case 176:
#line 211 "newTag.y"
                                                   {ifelse1();}
#line 2158 "y.tab.c"
    break;

  case 177:
#line 211 "newTag.y"
                                                                                   {ifelse2();}
#line 2164 "y.tab.c"
    break;

  case 179:
#line 212 "newTag.y"
                                  {ifelse3();}
#line 2170 "y.tab.c"
    break;

  case 180:
#line 213 "newTag.y"
                                                    {ifelse1();}
#line 2176 "y.tab.c"
    break;

  case 181:
#line 213 "newTag.y"
                                                                                     {ifelse2();}
#line 2182 "y.tab.c"
    break;

  case 183:
#line 214 "newTag.y"
                                   {ifelse3();}
#line 2188 "y.tab.c"
    break;

  case 184:
#line 217 "newTag.y"
                                                  {codegen_assigna();}
#line 2194 "y.tab.c"
    break;

  case 186:
#line 218 "newTag.y"
                                    {codegen_assigna();}
#line 2200 "y.tab.c"
    break;

  case 187:
#line 220 "newTag.y"
                                          {codegen_assigna();}
#line 2206 "y.tab.c"
    break;

  case 189:
#line 221 "newTag.y"
                             {codegen_assigna();}
#line 2212 "y.tab.c"
    break;

  case 190:
#line 223 "newTag.y"
                                         {push();}
#line 2218 "y.tab.c"
    break;

  case 192:
#line 224 "newTag.y"
                                                {push();}
#line 2224 "y.tab.c"
    break;

  case 195:
#line 227 "newTag.y"
                                         {push();}
#line 2230 "y.tab.c"
    break;

  case 196:
#line 227 "newTag.y"
                                                                        {codegen();}
#line 2236 "y.tab.c"
    break;

  case 197:
#line 228 "newTag.y"
                                           {push();}
#line 2242 "y.tab.c"
    break;

  case 198:
#line 228 "newTag.y"
                                                                          {codegen();}
#line 2248 "y.tab.c"
    break;

  case 199:
#line 229 "newTag.y"
                                 {push();}
#line 2254 "y.tab.c"
    break;

  case 200:
#line 229 "newTag.y"
                                                                {codegen();}
#line 2260 "y.tab.c"
    break;

  case 201:
#line 230 "newTag.y"
                                        {push();}
#line 2266 "y.tab.c"
    break;

  case 202:
#line 230 "newTag.y"
                                                                       {codegen();}
#line 2272 "y.tab.c"
    break;

  case 203:
#line 231 "newTag.y"
                        {pushab();}
#line 2278 "y.tab.c"
    break;

  case 204:
#line 233 "newTag.y"
                 {push();}
#line 2284 "y.tab.c"
    break;

  case 206:
#line 234 "newTag.y"
                   {push();}
#line 2290 "y.tab.c"
    break;

  case 209:
#line 237 "newTag.y"
                   {push();}
#line 2296 "y.tab.c"
    break;

  case 210:
#line 237 "newTag.y"
                                  {codegen();}
#line 2302 "y.tab.c"
    break;

  case 211:
#line 238 "newTag.y"
                     {push();}
#line 2308 "y.tab.c"
    break;

  case 212:
#line 238 "newTag.y"
                                    {codegen();}
#line 2314 "y.tab.c"
    break;

  case 213:
#line 239 "newTag.y"
                     {push();}
#line 2320 "y.tab.c"
    break;

  case 214:
#line 239 "newTag.y"
                                    {codegen();}
#line 2326 "y.tab.c"
    break;

  case 216:
#line 242 "newTag.y"
                    {push();}
#line 2332 "y.tab.c"
    break;

  case 218:
#line 244 "newTag.y"
                                         {codegen_assigna();}
#line 2338 "y.tab.c"
    break;

  case 219:
#line 245 "newTag.y"
                  {push();}
#line 2344 "y.tab.c"
    break;

  case 220:
#line 246 "newTag.y"
                 {push();}
#line 2350 "y.tab.c"
    break;

  case 221:
#line 247 "newTag.y"
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
#line 251 "newTag.y"


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
  printf("Error :%s at %d \n",yytext,yylineno);
}

push()
{
strcpy(st[++top],yytext);
}
pusha()
{
strcpy(st[++top],"  ");
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
