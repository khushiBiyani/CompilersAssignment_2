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

#line 91 "y.tab.c"

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
  YYSYMBOL_declarationStatementFirst = 51, /* declarationStatementFirst  */
  YYSYMBOL_parameters = 52,                /* parameters  */
  YYSYMBOL_paramContinuer = 53,            /* paramContinuer  */
  YYSYMBOL_parameter = 54,                 /* parameter  */
  YYSYMBOL_type = 55,                      /* type  */
  YYSYMBOL_compoundStatements = 56,        /* compoundStatements  */
  YYSYMBOL_singleStatement = 57,           /* singleStatement  */
  YYSYMBOL_statements = 58,                /* statements  */
  YYSYMBOL_statementList = 59,             /* statementList  */
  YYSYMBOL_basicStatements = 60,           /* basicStatements  */
  YYSYMBOL_basicStatement = 61,            /* basicStatement  */
  YYSYMBOL_assignmentStatement = 62,       /* assignmentStatement  */
  YYSYMBOL_printer = 63,                   /* printer  */
  YYSYMBOL_prattributes = 64,              /* prattributes  */
  YYSYMBOL_declarationStatement = 65,      /* declarationStatement  */
  YYSYMBOL_arrayValuesF = 66,              /* arrayValuesF  */
  YYSYMBOL_arrayValues = 67,               /* arrayValues  */
  YYSYMBOL_declarationListChar = 68,       /* declarationListChar  */
  YYSYMBOL_69_1 = 69,                      /* $@1  */
  YYSYMBOL_70_2 = 70,                      /* $@2  */
  YYSYMBOL_71_3 = 71,                      /* $@3  */
  YYSYMBOL_72_4 = 72,                      /* $@4  */
  YYSYMBOL_declarationListInt = 73,        /* declarationListInt  */
  YYSYMBOL_74_5 = 74,                      /* $@5  */
  YYSYMBOL_75_6 = 75,                      /* $@6  */
  YYSYMBOL_76_7 = 76,                      /* $@7  */
  YYSYMBOL_77_8 = 77,                      /* $@8  */
  YYSYMBOL_declarationListFloat = 78,      /* declarationListFloat  */
  YYSYMBOL_79_9 = 79,                      /* $@9  */
  YYSYMBOL_80_10 = 80,                     /* $@10  */
  YYSYMBOL_81_11 = 81,                     /* $@11  */
  YYSYMBOL_82_12 = 82,                     /* $@12  */
  YYSYMBOL_dimension = 83,                 /* dimension  */
  YYSYMBOL_returnDec = 84,                 /* returnDec  */
  YYSYMBOL_85_13 = 85,                     /* $@13  */
  YYSYMBOL_86_14 = 86,                     /* $@14  */
  YYSYMBOL_87_15 = 87,                     /* $@15  */
  YYSYMBOL_88_16 = 88,                     /* $@16  */
  YYSYMBOL_89_17 = 89,                     /* $@17  */
  YYSYMBOL_ARRAY = 90,                     /* ARRAY  */
  YYSYMBOL_specialStatement = 91,          /* specialStatement  */
  YYSYMBOL_forLoop = 92,                   /* forLoop  */
  YYSYMBOL_forLoop1 = 93,                  /* forLoop1  */
  YYSYMBOL_94_18 = 94,                     /* $@18  */
  YYSYMBOL_95_19 = 95,                     /* $@19  */
  YYSYMBOL_96_20 = 96,                     /* $@20  */
  YYSYMBOL_forLoop2 = 97,                  /* forLoop2  */
  YYSYMBOL_98_21 = 98,                     /* $@21  */
  YYSYMBOL_99_22 = 99,                     /* $@22  */
  YYSYMBOL_100_23 = 100,                   /* $@23  */
  YYSYMBOL_forLoop3 = 101,                 /* forLoop3  */
  YYSYMBOL_102_24 = 102,                   /* $@24  */
  YYSYMBOL_103_25 = 103,                   /* $@25  */
  YYSYMBOL_104_26 = 104,                   /* $@26  */
  YYSYMBOL_forAssignStatement = 105,       /* forAssignStatement  */
  YYSYMBOL_106_27 = 106,                   /* $@27  */
  YYSYMBOL_107_28 = 107,                   /* $@28  */
  YYSYMBOL_108_29 = 108,                   /* $@29  */
  YYSYMBOL_109_30 = 109,                   /* $@30  */
  YYSYMBOL_110_31 = 110,                   /* $@31  */
  YYSYMBOL_111_32 = 111,                   /* $@32  */
  YYSYMBOL_112_33 = 112,                   /* $@33  */
  YYSYMBOL_113_34 = 113,                   /* $@34  */
  YYSYMBOL_114_35 = 114,                   /* $@35  */
  YYSYMBOL_115_36 = 115,                   /* $@36  */
  YYSYMBOL_116_37 = 116,                   /* $@37  */
  YYSYMBOL_117_38 = 117,                   /* $@38  */
  YYSYMBOL_singleLoopStatement = 118,      /* singleLoopStatement  */
  YYSYMBOL_forExpStatement = 119,          /* forExpStatement  */
  YYSYMBOL_forUpdateStatement = 120,       /* forUpdateStatement  */
  YYSYMBOL_121_39 = 121,                   /* $@39  */
  YYSYMBOL_122_40 = 122,                   /* $@40  */
  YYSYMBOL_123_41 = 123,                   /* $@41  */
  YYSYMBOL_124_42 = 124,                   /* $@42  */
  YYSYMBOL_125_43 = 125,                   /* $@43  */
  YYSYMBOL_whileLoop = 126,                /* whileLoop  */
  YYSYMBOL_127_44 = 127,                   /* $@44  */
  YYSYMBOL_128_45 = 128,                   /* $@45  */
  YYSYMBOL_whileSuffix = 129,              /* whileSuffix  */
  YYSYMBOL_inLoop = 130,                   /* inLoop  */
  YYSYMBOL_ifStatement = 131,              /* ifStatement  */
  YYSYMBOL_132_46 = 132,                   /* $@46  */
  YYSYMBOL_133_47 = 133,                   /* $@47  */
  YYSYMBOL_134_48 = 134,                   /* $@48  */
  YYSYMBOL_135_49 = 135,                   /* $@49  */
  YYSYMBOL_ifContinuer = 136,              /* ifContinuer  */
  YYSYMBOL_ES = 137,                       /* ES  */
  YYSYMBOL_138_50 = 138,                   /* $@50  */
  YYSYMBOL_139_51 = 139,                   /* $@51  */
  YYSYMBOL_140_52 = 140,                   /* $@52  */
  YYSYMBOL_141_53 = 141,                   /* $@53  */
  YYSYMBOL_142_54 = 142,                   /* $@54  */
  YYSYMBOL_143_55 = 143,                   /* $@55  */
  YYSYMBOL_ifInLoopStatement = 144,        /* ifInLoopStatement  */
  YYSYMBOL_145_56 = 145,                   /* $@56  */
  YYSYMBOL_146_57 = 146,                   /* $@57  */
  YYSYMBOL_ifInLoopContinuer = 147,        /* ifInLoopContinuer  */
  YYSYMBOL_ESLoop = 148,                   /* ESLoop  */
  YYSYMBOL_149_58 = 149,                   /* $@58  */
  YYSYMBOL_150_59 = 150,                   /* $@59  */
  YYSYMBOL_151_60 = 151,                   /* $@60  */
  YYSYMBOL_152_61 = 152,                   /* $@61  */
  YYSYMBOL_expressionStatement = 153,      /* expressionStatement  */
  YYSYMBOL_154_62 = 154,                   /* $@62  */
  YYSYMBOL_logicalExpression = 155,        /* logicalExpression  */
  YYSYMBOL_156_63 = 156,                   /* $@63  */
  YYSYMBOL_expression = 157,               /* expression  */
  YYSYMBOL_158_64 = 158,                   /* $@64  */
  YYSYMBOL_159_65 = 159,                   /* $@65  */
  YYSYMBOL_relationalExpression = 160,     /* relationalExpression  */
  YYSYMBOL_161_66 = 161,                   /* $@66  */
  YYSYMBOL_162_67 = 162,                   /* $@67  */
  YYSYMBOL_163_68 = 163,                   /* $@68  */
  YYSYMBOL_164_69 = 164,                   /* $@69  */
  YYSYMBOL_value = 165,                    /* value  */
  YYSYMBOL_166_70 = 166,                   /* $@70  */
  YYSYMBOL_167_71 = 167,                   /* $@71  */
  YYSYMBOL_term = 168,                     /* term  */
  YYSYMBOL_169_72 = 169,                   /* $@72  */
  YYSYMBOL_170_73 = 170,                   /* $@73  */
  YYSYMBOL_171_74 = 171,                   /* $@74  */
  YYSYMBOL_factor = 172                    /* factor  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   494

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  125
/* YYNRULES -- Number of rules.  */
#define YYNRULES  229
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  440

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
       0,    56,    56,    59,    61,    62,    63,    64,    65,    67,
      68,    69,    71,    73,    74,    75,    77,    79,    80,    82,
      83,    84,    85,    87,    88,    89,    90,    92,    93,    95,
      96,    97,    99,   100,   101,   103,   105,   106,   108,   109,
     110,   111,   112,   113,   114,   115,   117,   118,   120,   121,
     123,   123,   123,   124,   124,   124,   125,   126,   128,   128,
     128,   129,   129,   129,   130,   131,   133,   133,   133,   134,
     134,   134,   135,   136,   138,   139,   140,   142,   143,   145,
     145,   145,   146,   147,   147,   147,   147,   149,   151,   152,
     153,   155,   156,   157,   159,   159,   159,   159,   160,   160,
     160,   160,   161,   161,   161,   161,   163,   164,   164,   164,
     164,   165,   165,   165,   165,   166,   166,   166,   166,   167,
     168,   168,   168,   168,   170,   171,   172,   173,   174,   176,
     178,   178,   178,   178,   179,   179,   179,   181,   181,   181,
     183,   184,   185,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   202,   202,   202,
     203,   203,   203,   205,   206,   208,   208,   208,   209,   210,
     210,   210,   211,   212,   212,   213,   213,   215,   215,   215,
     217,   218,   220,   220,   220,   221,   222,   222,   222,   223,
     226,   226,   227,   229,   229,   230,   232,   232,   233,   233,
     234,   236,   236,   237,   237,   238,   238,   239,   239,   240,
     242,   242,   243,   243,   244,   246,   246,   247,   247,   248,
     248,   249,   251,   252,   253,   254,   255,   256,   257,   258
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
  "declarationList", "declarationStatementFirst", "parameters",
  "paramContinuer", "parameter", "type", "compoundStatements",
  "singleStatement", "statements", "statementList", "basicStatements",
  "basicStatement", "assignmentStatement", "printer", "prattributes",
  "declarationStatement", "arrayValuesF", "arrayValues",
  "declarationListChar", "$@1", "$@2", "$@3", "$@4", "declarationListInt",
  "$@5", "$@6", "$@7", "$@8", "declarationListFloat", "$@9", "$@10",
  "$@11", "$@12", "dimension", "returnDec", "$@13", "$@14", "$@15", "$@16",
  "$@17", "ARRAY", "specialStatement", "forLoop", "forLoop1", "$@18",
  "$@19", "$@20", "forLoop2", "$@21", "$@22", "$@23", "forLoop3", "$@24",
  "$@25", "$@26", "forAssignStatement", "$@27", "$@28", "$@29", "$@30",
  "$@31", "$@32", "$@33", "$@34", "$@35", "$@36", "$@37", "$@38",
  "singleLoopStatement", "forExpStatement", "forUpdateStatement", "$@39",
  "$@40", "$@41", "$@42", "$@43", "whileLoop", "$@44", "$@45",
  "whileSuffix", "inLoop", "ifStatement", "$@46", "$@47", "$@48", "$@49",
  "ifContinuer", "ES", "$@50", "$@51", "$@52", "$@53", "$@54", "$@55",
  "ifInLoopStatement", "$@56", "$@57", "ifInLoopContinuer", "ESLoop",
  "$@58", "$@59", "$@60", "$@61", "expressionStatement", "$@62",
  "logicalExpression", "$@63", "expression", "$@64", "$@65",
  "relationalExpression", "$@66", "$@67", "$@68", "$@69", "value", "$@70",
  "$@71", "term", "$@72", "$@73", "$@74", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-391)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-187)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     198,   -18,     8,    20,    60,  -391,  -391,    26,    38,    45,
    -391,    50,    94,   209,  -391,  -391,  -391,    54,    61,  -391,
     114,    85,    54,   116,   118,   316,  -391,    54,   209,  -391,
    -391,    54,    54,    97,   102,   120,   145,   149,  -391,     5,
     161,    81,    81,  -391,  -391,  -391,    33,   156,   316,   179,
     189,   316,  -391,  -391,   169,   316,  -391,  -391,  -391,   213,
     238,    15,   150,   191,   222,  -391,  -391,  -391,  -391,    43,
     174,   111,   234,   128,   247,    81,    16,  -391,  -391,  -391,
    -391,   211,  -391,   212,   241,   237,   228,  -391,    52,    81,
     229,   233,  -391,  -391,  -391,   231,  -391,    81,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,    66,   245,  -391,   244,  -391,    67,   256,  -391,
     263,  -391,    77,   260,  -391,   270,  -391,   268,  -391,   272,
     274,   129,   189,  -391,    81,   278,  -391,   313,  -391,   290,
     291,   258,    81,  -391,  -391,   314,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,   134,
     292,  -391,  -391,   135,  -391,  -391,   170,  -391,  -391,   296,
    -391,  -391,   105,    81,    81,    81,   298,   300,    81,     1,
     294,   171,   297,  -391,   328,    81,   310,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,   317,   319,    81,   311,   333,    81,   321,   327,    81,
     323,   330,   404,   334,   336,   338,   339,  -391,  -391,  -391,
    -391,  -391,   331,  -391,    81,   340,   329,   341,   189,  -391,
    -391,  -391,    -5,   342,  -391,  -391,   359,  -391,  -391,    -7,
    -391,  -391,   404,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
     366,   367,   372,    58,   345,  -391,  -391,  -391,   351,   377,
      81,   378,   383,   362,   363,    81,  -391,    81,   388,   393,
     371,    81,   374,   404,   404,   259,    81,    81,    81,    81,
     368,   368,   368,  -391,   380,   397,   400,   162,  -391,  -391,
    -391,  -391,  -391,   386,   389,  -391,  -391,  -391,   384,   402,
    -391,  -391,  -391,  -391,   387,   417,  -391,  -391,  -391,  -391,
     235,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,    81,  -391,  -391,   418,   419,   162,   162,   162,
     162,   398,   162,  -391,  -391,  -391,  -391,  -391,   259,   403,
     404,  -391,   421,   425,   426,   427,   401,   409,   408,   410,
     416,   420,   162,   162,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,    81,   415,  -391,    16,    16,    16,  -391,  -391,   438,
     422,   376,   296,  -391,  -391,   424,  -391,  -391,  -391,  -391,
      81,    81,  -391,   162,  -391,   428,   296,  -391,  -391,   423,
     162,   429,   404,   430,   404,   440,  -391,   431,   404,  -391,
     404,  -391,   368,  -391,   432,   433,   434,  -391,   262,  -391,
    -391,  -391,   436,   280,  -391,  -391,  -391,   433,    81,   439,
     162,  -391,  -391,   437,    81,   441,  -391,   442,  -391,   -13,
     443,   376,   162,  -391,   444,   451,  -391,  -391,   451,  -391
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     3,     0,     0,     0,
       1,     0,     0,     0,    13,    15,    14,     0,     0,     9,
      10,     0,     0,     0,     0,     0,     7,     0,     0,    12,
       8,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,     0,     0,   225,   226,   227,   222,     0,     0,    28,
      31,     0,    30,    25,     0,     0,    90,    89,    29,   192,
     195,   200,   209,   214,   221,     4,    11,     5,     6,    65,
       0,    57,     0,    73,     0,     0,     0,    88,    93,    91,
      92,     0,    78,   222,     0,     0,     0,   224,     0,     0,
       0,     0,    16,    23,    27,     0,    26,     0,    24,   190,
     193,   196,   198,   201,   203,   205,   207,   210,   212,   215,
     217,   219,     0,     0,    64,     0,    38,     0,     0,    56,
       0,    40,     0,     0,    72,     0,    41,     0,   119,     0,
       0,     0,   106,    94,     0,     0,    77,     0,   223,     0,
       0,     0,     0,    84,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,    58,     0,    54,    50,     0,    70,    66,   160,
     107,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   228,     0,    33,     0,     0,     0,    82,   191,   194,
     197,   199,   202,   204,   206,   208,   211,   213,   216,   218,
     220,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,   129,    99,
     103,   138,   228,    37,     0,     0,     0,     0,    32,    34,
      85,    80,     0,     0,    63,    59,     0,    55,    51,     0,
      71,    67,     0,   161,    18,    17,   108,   112,   116,   121,
       0,     0,     0,     0,     0,    36,    35,    76,     0,     0,
       0,     0,    49,     0,     0,     0,    39,     0,     0,    47,
       0,     0,     0,    22,    21,     0,     0,     0,     0,     0,
       0,     0,     0,   141,     0,     0,     0,     0,   125,   124,
     142,   139,   128,     0,   229,    86,    81,    43,     0,     0,
      75,    60,    52,    44,     0,     0,    68,   158,    20,    19,
       0,   164,   162,   163,   109,   113,   117,   122,   130,    96,
     100,   104,     0,   126,   127,     0,     0,   125,   156,   124,
     155,     0,   128,   229,    48,    42,    46,    45,     0,     0,
       0,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,   127,   146,   149,   145,   148,   140,   147,
     159,     0,     0,   110,     0,     0,     0,   131,   135,     0,
       0,     0,   160,   143,   144,     0,   168,   114,   118,   123,
       0,     0,    97,     0,   105,     0,   160,   132,   136,     0,
       0,     0,     0,     0,     0,     0,   101,     0,     0,   170,
       0,   176,     0,   178,     0,     0,     0,   133,     0,   166,
     171,   174,     0,     0,   181,   179,   180,     0,     0,     0,
       0,   189,   167,     0,     0,     0,   177,     0,   185,   160,
       0,     0,     0,   187,     0,     0,   183,   188,     0,   184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -391,  -391,  -391,  -391,   283,   435,  -391,  -391,   107,  -378,
    -263,     6,   445,   -25,   -72,    40,  -391,  -391,   155,   166,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,    74,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,   -20,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -125,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -251,   123,  -269,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -284,  -272,  -391,  -391,  -391,  -391,   127,  -390,
    -391,  -391,  -391,  -391,  -391,  -391,  -252,  -391,  -391,  -391,
    -314,  -391,  -391,  -391,  -391,   -33,  -391,   322,  -391,   160,
    -391,  -391,    13,  -391,  -391,  -391,  -391,   159,  -391,  -391,
     112,  -391,  -391,  -391,  -171
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,    18,    19,    20,    21,    26,   243,
     272,    47,    48,   327,    50,   328,   179,    52,   270,   263,
      72,   207,   267,   118,   206,    70,   204,   265,   113,   203,
      74,   210,   271,   123,   209,    90,    53,   186,   260,    91,
     185,   259,    54,   329,    77,    78,   173,   250,   348,    79,
     174,   251,   349,    80,   175,   252,   350,   133,   213,   276,
     342,   214,   277,   343,   215,   278,   344,   216,   279,   345,
     330,   217,   319,   346,   380,   395,   347,   381,    56,    81,
     253,   291,   331,    57,   211,   338,   212,   275,   312,   313,
     391,   417,   392,   405,   393,   394,   332,   385,   408,   415,
     416,   430,   438,   431,   435,    58,   146,    59,   147,    60,
     148,   149,    61,   150,   151,   152,   153,    62,   154,   155,
      63,   156,   157,   158,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,   292,   290,   311,   132,    55,    84,   223,    86,    87,
     308,   309,   320,   321,   399,   410,   401,   224,  -186,  -186,
     101,   102,    82,    49,    49,  -157,    49,   422,    55,     7,
      49,    55,   268,   128,   261,    55,   129,   130,   225,   269,
     262,    41,   127,   354,   355,   356,   357,    42,   359,    43,
      44,    45,    83,   255,    93,     8,   141,    96,   292,   341,
      10,    98,    11,   131,   145,    51,   311,     9,   373,   374,
      14,    15,    16,    88,    12,   283,    89,   362,    33,    34,
      35,    13,   284,   112,    37,    38,   -61,    17,    51,   285,
     286,    51,    25,   139,    41,    51,   287,   140,    27,   389,
      42,   176,    43,    44,    45,    46,   397,   159,   163,   184,
     228,   160,   160,   188,    14,    15,    16,    41,   166,   292,
     384,   437,   160,    42,   439,    43,    44,    45,    83,    30,
      28,    22,    29,   407,    65,   404,   425,   406,    67,    68,
     218,   218,   218,   114,    69,   119,   139,   124,   434,    71,
     160,   117,   230,    31,   -53,    32,   414,   103,   104,   105,
     106,   292,   421,   192,   193,   194,   195,    73,   122,   172,
     234,   -69,    89,   237,   180,   180,   240,   201,   205,   292,
     433,    75,    33,    34,    35,    76,   284,   244,    37,    38,
     115,   116,   245,   325,   326,    92,    40,    85,    41,    33,
      34,    35,   107,   108,    42,    95,    43,    44,    45,    46,
     180,   227,    97,   208,   -74,    41,    99,   273,     1,     2,
       3,    42,   274,    43,    44,    45,    46,   296,   288,    14,
      15,    16,   301,   289,   302,   109,   110,   111,   306,   377,
     378,   379,   100,   314,   315,   316,   317,   134,   273,   273,
     120,   121,   135,   274,   274,    33,    34,    35,   136,   339,
     137,    37,    38,   125,   126,   138,   285,   286,   198,   199,
     200,    41,   142,   340,   182,   183,   143,    42,   144,    43,
      44,    45,    46,    36,   310,   288,   412,   413,   161,   351,
     289,   162,   132,   132,   132,    23,    24,   219,   220,   164,
      33,    34,    35,   167,   419,   169,    37,    38,   190,   191,
     165,   285,   286,   196,   197,   273,    41,   168,   420,   170,
     274,   171,    42,   177,    43,    44,    45,    46,   375,   178,
     180,   187,   181,   202,  -157,   221,    33,    34,    35,   226,
      36,   222,    37,    38,   131,   229,   288,   387,   388,    39,
      40,   289,    41,   231,   235,   232,   236,   256,    42,   233,
      43,    44,    45,    46,   238,   239,   241,   244,   242,   244,
     257,   254,   245,   273,   245,   273,   266,   246,   274,   247,
     274,   248,   249,   280,   281,   423,   258,   264,   288,   282,
     293,   427,   294,   289,   295,   297,    33,    34,    35,   298,
     284,   299,    37,    38,   300,   303,   288,   285,   286,   304,
     305,   289,    41,   307,   323,   318,   322,   324,    42,   335,
      43,    44,    45,    46,    33,    34,    35,   333,    36,   262,
      37,    38,   -75,   269,   337,   352,   353,   358,   363,   361,
      41,   364,   365,   366,   367,   369,    42,   370,    43,    44,
      45,    46,   368,   371,   376,   382,   402,   372,   310,   336,
     383,   386,   396,    66,   334,   360,   390,   398,   400,   189,
     403,   409,   418,   411,   426,   424,   413,     0,     0,   429,
     428,   432,     0,   436,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94
};

static const yytype_int16 yycheck[] =
{
      25,   253,   253,   275,    76,    25,    39,   178,    41,    42,
     273,   274,   281,   282,   392,   405,   394,    16,    31,    32,
       5,     6,    17,    48,    49,    38,    51,   417,    48,    47,
      55,    51,    39,    17,    39,    55,    20,    21,    37,    46,
      45,    36,    75,   327,   328,   329,   330,    42,   332,    44,
      45,    46,    47,   224,    48,    47,    89,    51,   310,   310,
       0,    55,    36,    47,    97,    25,   338,    47,   352,   353,
      20,    21,    22,    40,    36,    17,    43,   340,    20,    21,
      22,    36,    24,    40,    26,    27,    43,    37,    48,    31,
      32,    51,    38,    41,    36,    55,    38,    45,    37,   383,
      42,   134,    44,    45,    46,    47,   390,    41,    41,   142,
     182,    45,    45,   146,    20,    21,    22,    36,    41,   371,
     371,   435,    45,    42,   438,    44,    45,    46,    47,    22,
      16,    37,    47,   402,    27,   398,   420,   400,    31,    32,
     173,   174,   175,    69,    47,    71,    41,    73,   432,    47,
      45,    40,   185,    37,    43,    37,   408,     7,     8,     9,
      10,   413,   413,   150,   151,   152,   153,    47,    40,    40,
     203,    43,    43,   206,    40,    40,   209,    43,    43,   431,
     431,    36,    20,    21,    22,    36,    24,   212,    26,    27,
      16,    17,   212,    31,    32,    39,    34,    36,    36,    20,
      21,    22,    11,    12,    42,    16,    44,    45,    46,    47,
      40,    40,    43,    43,    43,    36,     3,   242,    20,    21,
      22,    42,   242,    44,    45,    46,    47,   260,   253,    20,
      21,    22,   265,   253,   267,    13,    14,    15,   271,   364,
     365,   366,     4,   276,   277,   278,   279,    36,   273,   274,
      16,    17,    40,   273,   274,    20,    21,    22,    17,    24,
      23,    26,    27,    16,    17,    37,    31,    32,   156,   157,
     158,    36,    43,    38,    16,    17,    43,    42,    47,    44,
      45,    46,    47,    24,    25,   310,    24,    25,    43,   322,
     310,    47,   364,   365,   366,    12,    13,   174,   175,    43,
      20,    21,    22,    43,    24,    37,    26,    27,   148,   149,
      47,    31,    32,   154,   155,   340,    36,    47,    38,    47,
     340,    47,    42,    45,    44,    45,    46,    47,   361,    16,
      40,    17,    41,    41,    38,    37,    20,    21,    22,    45,
      24,    41,    26,    27,    47,    17,   371,   380,   381,    33,
      34,   371,    36,    43,    43,    38,    23,    17,    42,    40,
      44,    45,    46,    47,    43,    38,    43,   392,    38,   394,
      41,    40,   392,   398,   394,   400,    17,    43,   398,    43,
     400,    43,    43,    17,    17,   418,    45,    45,   413,    17,
      45,   424,    41,   413,    17,    17,    20,    21,    22,    16,
      24,    39,    26,    27,    41,    17,   431,    31,    32,    16,
      39,   431,    36,    39,    17,    47,    36,    17,    42,    17,
      44,    45,    46,    47,    20,    21,    22,    41,    24,    45,
      26,    27,    43,    46,    17,    17,    17,    39,    17,    36,
      36,    16,    16,    16,    43,    37,    42,    37,    44,    45,
      46,    47,    43,    37,    39,    17,    16,    37,    25,   304,
      38,    37,    39,    28,   298,   338,    38,    38,    38,   147,
      39,    39,    36,    39,    37,    36,    25,    -1,    -1,    37,
      39,    38,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    22,    49,    50,    51,    47,    47,    47,
       0,    36,    36,    36,    20,    21,    22,    37,    52,    53,
      54,    55,    37,    52,    52,    38,    56,    37,    16,    47,
      56,    37,    37,    20,    21,    22,    24,    26,    27,    33,
      34,    36,    42,    44,    45,    46,    47,    59,    60,    61,
      62,    63,    65,    84,    90,    91,   126,   131,   153,   155,
     157,   160,   165,   168,   172,    56,    53,    56,    56,    47,
      73,    47,    68,    47,    78,    36,    36,    92,    93,    97,
     101,   127,    17,    47,   153,    36,   153,   153,    40,    43,
      83,    87,    39,    59,    60,    16,    59,    43,    59,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    40,    76,    83,    16,    17,    40,    71,    83,
      16,    17,    40,    81,    83,    16,    17,   153,    17,    20,
      21,    47,    62,   105,    36,    40,    17,    23,    37,    41,
      45,   153,    43,    43,    47,   153,   154,   156,   158,   159,
     161,   162,   163,   164,   166,   167,   169,   170,   171,    41,
      45,    43,    47,    41,    43,    47,    41,    43,    47,    37,
      47,    47,    40,    94,    98,   102,   153,    45,    16,    64,
      40,    41,    16,    17,   153,    88,    85,    17,   153,   155,
     157,   157,   160,   160,   160,   160,   165,   165,   168,   168,
     168,    43,    41,    77,    74,    43,    72,    69,    43,    82,
      79,   132,   134,   106,   109,   112,   115,   119,   153,   119,
     119,    37,    41,   172,    16,    37,    45,    40,    62,    17,
     153,    43,    38,    40,   153,    43,    23,   153,    43,    38,
     153,    43,    38,    57,    61,    91,    43,    43,    43,    43,
      95,    99,   103,   128,    40,   172,    17,    41,    45,    89,
      86,    39,    45,    67,    45,    75,    17,    70,    39,    46,
      66,    80,    58,    61,    91,   135,   107,   110,   113,   116,
      17,    17,    17,    17,    24,    31,    32,    38,    61,    91,
     118,   129,   144,    45,    41,    17,   153,    17,    16,    39,
      41,   153,   153,    17,    16,    39,   153,    39,    58,    58,
      25,   131,   136,   137,   153,   153,   153,   153,    47,   120,
     120,   120,    36,    17,    17,    31,    32,    61,    63,    91,
     118,   130,   144,    41,    67,    17,    66,    17,   133,    24,
      38,   118,   108,   111,   114,   117,   121,   124,    96,   100,
     104,   153,    17,    17,   130,   130,   130,   130,    39,   130,
     136,    36,    58,    17,    16,    16,    16,    43,    43,    37,
      37,    37,    37,   130,   130,   153,    39,   105,   105,   105,
     122,   125,    17,    38,   118,   145,    37,   153,   153,   130,
      38,   138,   140,   142,   143,   123,    39,   130,    38,    57,
      38,    57,    16,    39,    58,   141,    58,   120,   146,    39,
     137,    39,    24,    25,   144,   147,   148,   139,    36,    24,
      38,   118,   137,   153,    36,   130,    37,   153,    39,    37,
     149,   151,    38,   118,   130,   152,    39,   148,   150,   148
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    51,    51,    51,    52,
      53,    53,    54,    55,    55,    55,    56,    57,    57,    58,
      58,    58,    58,    59,    59,    59,    59,    60,    60,    61,
      61,    61,    62,    62,    62,    63,    64,    64,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    67,    67,
      69,    70,    68,    71,    72,    68,    68,    68,    74,    75,
      73,    76,    77,    73,    73,    73,    79,    80,    78,    81,
      82,    78,    78,    78,    83,    83,    83,    84,    84,    85,
      86,    62,    62,    87,    88,    89,    62,    90,    91,    91,
      91,    92,    92,    92,    94,    95,    96,    93,    98,    99,
     100,    97,   102,   103,   104,   101,   105,   106,   107,   108,
     105,   109,   110,   111,   105,   112,   113,   114,   105,   105,
     115,   116,   117,   105,   118,   118,   118,   118,   118,   119,
     121,   122,   123,   120,   124,   125,   120,   127,   128,   126,
     129,   129,   129,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   132,   133,   131,
     134,   135,   131,   136,   136,   138,   139,   137,   137,   140,
     141,   137,   137,   142,   137,   143,   137,   145,   146,   144,
     147,   147,   149,   150,   148,   148,   151,   152,   148,   148,
     154,   153,   153,   156,   155,   155,   158,   157,   159,   157,
     157,   161,   160,   162,   160,   163,   160,   164,   160,   160,
     166,   165,   167,   165,   165,   169,   168,   170,   168,   171,
     168,   168,   172,   172,   172,   172,   172,   172,   172,   172
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     6,     6,     6,     5,     5,     1,
       1,     3,     2,     1,     1,     1,     3,     1,     1,     2,
       2,     1,     1,     2,     2,     1,     2,     2,     1,     1,
       1,     1,     5,     4,     5,     6,     3,     2,     3,     7,
       3,     3,     9,     8,     8,     9,     3,     1,     3,     1,
       0,     0,     7,     0,     0,     5,     2,     1,     0,     0,
       7,     0,     0,     5,     2,     1,     0,     0,     7,     0,
       0,     5,     2,     1,     3,     6,     5,     3,     2,     0,
       0,     7,     4,     0,     0,     0,     7,     2,     2,     1,
       1,     1,     1,     1,     0,     0,     0,    10,     0,     0,
       0,    12,     0,     0,     0,    10,     1,     0,     0,     0,
       8,     0,     0,     0,     9,     0,     0,     0,     9,     1,
       0,     0,     0,     9,     1,     1,     2,     2,     1,     1,
       0,     0,     0,     8,     0,     0,     5,     0,     0,     7,
       3,     1,     1,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     0,     0,    10,
       0,     0,     8,     1,     1,     0,     0,    11,     4,     0,
       0,     9,     2,     0,     9,     0,     7,     0,     0,    10,
       1,     1,     0,     0,    11,     4,     0,     0,     9,     2,
       0,     4,     1,     0,     4,     1,     0,     4,     0,     4,
       1,     0,     4,     0,     4,     0,     4,     0,     4,     1,
       0,     4,     0,     4,     1,     0,     4,     0,     4,     0,
       4,     1,     1,     3,     2,     1,     1,     1,     4,     7
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
#line 56 "newTag.y"
                        {printf("Input accepted.\n");}
#line 1714 "y.tab.c"
    break;

  case 50: /* $@1: %empty  */
#line 123 "newTag.y"
                                                           {push();}
#line 1720 "y.tab.c"
    break;

  case 51: /* $@2: %empty  */
#line 123 "newTag.y"
                                                                           {push();}
#line 1726 "y.tab.c"
    break;

  case 52: /* declarationListChar: declarationListChar COMMA IDENTIFIER $@1 EQUAL $@2 expressionStatement  */
#line 123 "newTag.y"
                                                                                                         {codegen_assign();}
#line 1732 "y.tab.c"
    break;

  case 53: /* $@3: %empty  */
#line 124 "newTag.y"
                             {push();}
#line 1738 "y.tab.c"
    break;

  case 54: /* $@4: %empty  */
#line 124 "newTag.y"
                                             {push();}
#line 1744 "y.tab.c"
    break;

  case 55: /* declarationListChar: IDENTIFIER $@3 EQUAL $@4 expressionStatement  */
#line 124 "newTag.y"
                                                                           {codegen_assign();}
#line 1750 "y.tab.c"
    break;

  case 58: /* $@5: %empty  */
#line 128 "newTag.y"
                                                         {push();}
#line 1756 "y.tab.c"
    break;

  case 59: /* $@6: %empty  */
#line 128 "newTag.y"
                                                                         {push();}
#line 1762 "y.tab.c"
    break;

  case 60: /* declarationListInt: declarationListInt COMMA IDENTIFIER $@5 EQUAL $@6 expressionStatement  */
#line 128 "newTag.y"
                                                                                                       {codegen_assign();}
#line 1768 "y.tab.c"
    break;

  case 61: /* $@7: %empty  */
#line 129 "newTag.y"
                             {push();}
#line 1774 "y.tab.c"
    break;

  case 62: /* $@8: %empty  */
#line 129 "newTag.y"
                                             {push();}
#line 1780 "y.tab.c"
    break;

  case 63: /* declarationListInt: IDENTIFIER $@7 EQUAL $@8 expressionStatement  */
#line 129 "newTag.y"
                                                                           {codegen_assign();}
#line 1786 "y.tab.c"
    break;

  case 66: /* $@9: %empty  */
#line 133 "newTag.y"
                                                             {push();}
#line 1792 "y.tab.c"
    break;

  case 67: /* $@10: %empty  */
#line 133 "newTag.y"
                                                                             {push();}
#line 1798 "y.tab.c"
    break;

  case 68: /* declarationListFloat: declarationListFloat COMMA IDENTIFIER $@9 EQUAL $@10 expressionStatement  */
#line 133 "newTag.y"
                                                                                                           {codegen_assign();}
#line 1804 "y.tab.c"
    break;

  case 69: /* $@11: %empty  */
#line 134 "newTag.y"
                             {push();}
#line 1810 "y.tab.c"
    break;

  case 70: /* $@12: %empty  */
#line 134 "newTag.y"
                                             {push();}
#line 1816 "y.tab.c"
    break;

  case 71: /* declarationListFloat: IDENTIFIER $@11 EQUAL $@12 expressionStatement  */
#line 134 "newTag.y"
                                                                           {codegen_assign();}
#line 1822 "y.tab.c"
    break;

  case 79: /* $@13: %empty  */
#line 145 "newTag.y"
                                                           {push();}
#line 1828 "y.tab.c"
    break;

  case 80: /* $@14: %empty  */
#line 145 "newTag.y"
                                                                           {push();}
#line 1834 "y.tab.c"
    break;

  case 81: /* assignmentStatement: assignmentStatement COMMA IDENTIFIER $@13 EQUAL $@14 expressionStatement  */
#line 145 "newTag.y"
                                                                                                         {codegen_assign();}
#line 1840 "y.tab.c"
    break;

  case 83: /* $@15: %empty  */
#line 147 "newTag.y"
                             {push();}
#line 1846 "y.tab.c"
    break;

  case 84: /* $@16: %empty  */
#line 147 "newTag.y"
                                             {push();}
#line 1852 "y.tab.c"
    break;

  case 85: /* $@17: %empty  */
#line 147 "newTag.y"
                                                                           {codegen_assign();}
#line 1858 "y.tab.c"
    break;

  case 94: /* $@18: %empty  */
#line 159 "newTag.y"
                                      {for1();}
#line 1864 "y.tab.c"
    break;

  case 95: /* $@19: %empty  */
#line 159 "newTag.y"
                                                                {for2();}
#line 1870 "y.tab.c"
    break;

  case 96: /* $@20: %empty  */
#line 159 "newTag.y"
                                                                                                       {for3();}
#line 1876 "y.tab.c"
    break;

  case 97: /* forLoop1: OPBRAC forAssignStatement $@18 forExpStatement $@19 SEMICOLON forUpdateStatement $@20 CLBRAC SEMICOLON  */
#line 159 "newTag.y"
                                                                                                                                  {for4();}
#line 1882 "y.tab.c"
    break;

  case 98: /* $@21: %empty  */
#line 160 "newTag.y"
                                     {for1();}
#line 1888 "y.tab.c"
    break;

  case 99: /* $@22: %empty  */
#line 160 "newTag.y"
                                                               {for2();}
#line 1894 "y.tab.c"
    break;

  case 100: /* $@23: %empty  */
#line 160 "newTag.y"
                                                                                                      {for3();}
#line 1900 "y.tab.c"
    break;

  case 101: /* forLoop2: OPBRAC forAssignStatement $@21 forExpStatement $@22 SEMICOLON forUpdateStatement $@23 CLBRAC OPCUR inLoop CLCUR  */
#line 160 "newTag.y"
                                                                                                                                          {for4();}
#line 1906 "y.tab.c"
    break;

  case 102: /* $@24: %empty  */
#line 161 "newTag.y"
                                     {for1();}
#line 1912 "y.tab.c"
    break;

  case 103: /* $@25: %empty  */
#line 161 "newTag.y"
                                                               {for2();}
#line 1918 "y.tab.c"
    break;

  case 104: /* $@26: %empty  */
#line 161 "newTag.y"
                                                                                                      {for3();}
#line 1924 "y.tab.c"
    break;

  case 105: /* forLoop3: OPBRAC forAssignStatement $@24 forExpStatement $@25 SEMICOLON forUpdateStatement $@26 CLBRAC singleLoopStatement  */
#line 161 "newTag.y"
                                                                                                                                           {for4();}
#line 1930 "y.tab.c"
    break;

  case 107: /* $@27: %empty  */
#line 164 "newTag.y"
                                                         {push();}
#line 1936 "y.tab.c"
    break;

  case 108: /* $@28: %empty  */
#line 164 "newTag.y"
                                                                         {push();}
#line 1942 "y.tab.c"
    break;

  case 109: /* $@29: %empty  */
#line 164 "newTag.y"
                                                                                                       {codegen_assign();}
#line 1948 "y.tab.c"
    break;

  case 111: /* $@30: %empty  */
#line 165 "newTag.y"
                                                         {push();}
#line 1954 "y.tab.c"
    break;

  case 112: /* $@31: %empty  */
#line 165 "newTag.y"
                                                                         {push();}
#line 1960 "y.tab.c"
    break;

  case 113: /* $@32: %empty  */
#line 165 "newTag.y"
                                                                                                       {codegen_assign();}
#line 1966 "y.tab.c"
    break;

  case 115: /* $@33: %empty  */
#line 166 "newTag.y"
                                                          {push();}
#line 1972 "y.tab.c"
    break;

  case 116: /* $@34: %empty  */
#line 166 "newTag.y"
                                                                          {push();}
#line 1978 "y.tab.c"
    break;

  case 117: /* $@35: %empty  */
#line 166 "newTag.y"
                                                                                                        {codegen_assign();}
#line 1984 "y.tab.c"
    break;

  case 120: /* $@36: %empty  */
#line 168 "newTag.y"
                                                          {push();}
#line 1990 "y.tab.c"
    break;

  case 121: /* $@37: %empty  */
#line 168 "newTag.y"
                                                                          {push();}
#line 1996 "y.tab.c"
    break;

  case 122: /* $@38: %empty  */
#line 168 "newTag.y"
                                                                                                        {codegen_assign();}
#line 2002 "y.tab.c"
    break;

  case 130: /* $@39: %empty  */
#line 178 "newTag.y"
                                {push();}
#line 2008 "y.tab.c"
    break;

  case 131: /* $@40: %empty  */
#line 178 "newTag.y"
                                                {push();}
#line 2014 "y.tab.c"
    break;

  case 132: /* $@41: %empty  */
#line 178 "newTag.y"
                                                                              {codegen_assign();}
#line 2020 "y.tab.c"
    break;

  case 134: /* $@42: %empty  */
#line 179 "newTag.y"
                                                     {push();}
#line 2026 "y.tab.c"
    break;

  case 135: /* $@43: %empty  */
#line 179 "newTag.y"
                                                                     {push();}
#line 2032 "y.tab.c"
    break;

  case 136: /* forUpdateStatement: IDENTIFIER $@42 EQUAL $@43 expressionStatement  */
#line 179 "newTag.y"
                                                                                                   {codegen_assign();}
#line 2038 "y.tab.c"
    break;

  case 137: /* $@44: %empty  */
#line 181 "newTag.y"
                  {while1();}
#line 2044 "y.tab.c"
    break;

  case 138: /* $@45: %empty  */
#line 181 "newTag.y"
                                                                {while2();}
#line 2050 "y.tab.c"
    break;

  case 139: /* whileLoop: WHILE $@44 OPBRAC expressionStatement CLBRAC $@45 whileSuffix  */
#line 181 "newTag.y"
                                                                                        {while3();}
#line 2056 "y.tab.c"
    break;

  case 157: /* $@46: %empty  */
#line 202 "newTag.y"
                                                   {ifelse1();}
#line 2062 "y.tab.c"
    break;

  case 158: /* $@47: %empty  */
#line 202 "newTag.y"
                                                                                       {ifelse2();}
#line 2068 "y.tab.c"
    break;

  case 160: /* $@48: %empty  */
#line 203 "newTag.y"
                                                               {ifelse1();}
#line 2074 "y.tab.c"
    break;

  case 161: /* $@49: %empty  */
#line 203 "newTag.y"
                                                                                            {ifelse2();}
#line 2080 "y.tab.c"
    break;

  case 165: /* $@50: %empty  */
#line 208 "newTag.y"
                                               {ifelse1();}
#line 2086 "y.tab.c"
    break;

  case 166: /* $@51: %empty  */
#line 208 "newTag.y"
                                                                                   {ifelse2();}
#line 2092 "y.tab.c"
    break;

  case 168: /* ES: ELSE OPCUR statements CLCUR  */
#line 209 "newTag.y"
                                      {ifelse3();}
#line 2098 "y.tab.c"
    break;

  case 169: /* $@52: %empty  */
#line 210 "newTag.y"
                                                {ifelse1();}
#line 2104 "y.tab.c"
    break;

  case 170: /* $@53: %empty  */
#line 210 "newTag.y"
                                                                             {ifelse2();}
#line 2110 "y.tab.c"
    break;

  case 172: /* ES: ELSE singleLoopStatement  */
#line 211 "newTag.y"
                                   {ifelse3();}
#line 2116 "y.tab.c"
    break;

  case 173: /* $@54: %empty  */
#line 212 "newTag.y"
                                                {ifelse1();}
#line 2122 "y.tab.c"
    break;

  case 174: /* ES: ELSE IF OPBRAC expressionStatement CLBRAC $@54 OPCUR statements CLCUR  */
#line 212 "newTag.y"
                                                                                    {ifelse2();}
#line 2128 "y.tab.c"
    break;

  case 175: /* $@55: %empty  */
#line 213 "newTag.y"
                                                {ifelse1();}
#line 2134 "y.tab.c"
    break;

  case 176: /* ES: ELSE IF OPBRAC expressionStatement CLBRAC $@55 singleStatement  */
#line 213 "newTag.y"
                                                                             {ifelse2();}
#line 2140 "y.tab.c"
    break;

  case 177: /* $@56: %empty  */
#line 215 "newTag.y"
                                                         {ifelse1();}
#line 2146 "y.tab.c"
    break;

  case 178: /* $@57: %empty  */
#line 215 "newTag.y"
                                                                                         {ifelse2();}
#line 2152 "y.tab.c"
    break;

  case 182: /* $@58: %empty  */
#line 220 "newTag.y"
                                                   {ifelse1();}
#line 2158 "y.tab.c"
    break;

  case 183: /* $@59: %empty  */
#line 220 "newTag.y"
                                                                                   {ifelse2();}
#line 2164 "y.tab.c"
    break;

  case 185: /* ESLoop: ELSE OPCUR inLoop CLCUR  */
#line 221 "newTag.y"
                                  {ifelse3();}
#line 2170 "y.tab.c"
    break;

  case 186: /* $@60: %empty  */
#line 222 "newTag.y"
                                                    {ifelse1();}
#line 2176 "y.tab.c"
    break;

  case 187: /* $@61: %empty  */
#line 222 "newTag.y"
                                                                                     {ifelse2();}
#line 2182 "y.tab.c"
    break;

  case 189: /* ESLoop: ELSE singleLoopStatement  */
#line 223 "newTag.y"
                                   {ifelse3();}
#line 2188 "y.tab.c"
    break;

  case 190: /* $@62: %empty  */
#line 226 "newTag.y"
                                                  {codegen_assigna();}
#line 2194 "y.tab.c"
    break;

  case 192: /* expressionStatement: logicalExpression  */
#line 227 "newTag.y"
                                    {codegen_assigna();}
#line 2200 "y.tab.c"
    break;

  case 193: /* $@63: %empty  */
#line 229 "newTag.y"
                                          {codegen_assigna();}
#line 2206 "y.tab.c"
    break;

  case 195: /* logicalExpression: expression  */
#line 230 "newTag.y"
                             {codegen_assigna();}
#line 2212 "y.tab.c"
    break;

  case 196: /* $@64: %empty  */
#line 232 "newTag.y"
                                         {push();}
#line 2218 "y.tab.c"
    break;

  case 198: /* $@65: %empty  */
#line 233 "newTag.y"
                                                {push();}
#line 2224 "y.tab.c"
    break;

  case 201: /* $@66: %empty  */
#line 236 "newTag.y"
                                         {push();}
#line 2230 "y.tab.c"
    break;

  case 202: /* relationalExpression: value GREATERTHAN $@66 relationalExpression  */
#line 236 "newTag.y"
                                                                        {codegen();}
#line 2236 "y.tab.c"
    break;

  case 203: /* $@67: %empty  */
#line 237 "newTag.y"
                                           {push();}
#line 2242 "y.tab.c"
    break;

  case 204: /* relationalExpression: value GREATERTHANEQUALTO $@67 relationalExpression  */
#line 237 "newTag.y"
                                                                          {codegen();}
#line 2248 "y.tab.c"
    break;

  case 205: /* $@68: %empty  */
#line 238 "newTag.y"
                                 {push();}
#line 2254 "y.tab.c"
    break;

  case 206: /* relationalExpression: value LESSTHAN $@68 relationalExpression  */
#line 238 "newTag.y"
                                                                {codegen();}
#line 2260 "y.tab.c"
    break;

  case 207: /* $@69: %empty  */
#line 239 "newTag.y"
                                        {push();}
#line 2266 "y.tab.c"
    break;

  case 208: /* relationalExpression: value LESSTHANEQUALTO $@69 relationalExpression  */
#line 239 "newTag.y"
                                                                       {codegen();}
#line 2272 "y.tab.c"
    break;

  case 209: /* relationalExpression: value  */
#line 240 "newTag.y"
                        {pushab();}
#line 2278 "y.tab.c"
    break;

  case 210: /* $@70: %empty  */
#line 242 "newTag.y"
                 {push();}
#line 2284 "y.tab.c"
    break;

  case 212: /* $@71: %empty  */
#line 243 "newTag.y"
                   {push();}
#line 2290 "y.tab.c"
    break;

  case 215: /* $@72: %empty  */
#line 246 "newTag.y"
                   {push();}
#line 2296 "y.tab.c"
    break;

  case 216: /* term: factor MULT $@72 term  */
#line 246 "newTag.y"
                                  {codegen();}
#line 2302 "y.tab.c"
    break;

  case 217: /* $@73: %empty  */
#line 247 "newTag.y"
                     {push();}
#line 2308 "y.tab.c"
    break;

  case 218: /* term: factor DIV $@73 term  */
#line 247 "newTag.y"
                                    {codegen();}
#line 2314 "y.tab.c"
    break;

  case 219: /* $@74: %empty  */
#line 248 "newTag.y"
                     {push();}
#line 2320 "y.tab.c"
    break;

  case 220: /* term: factor MOD $@74 term  */
#line 248 "newTag.y"
                                    {codegen();}
#line 2326 "y.tab.c"
    break;

  case 222: /* factor: IDENTIFIER  */
#line 251 "newTag.y"
                    {push();}
#line 2332 "y.tab.c"
    break;

  case 224: /* factor: LOGICALNOT expressionStatement  */
#line 253 "newTag.y"
                                         {codegen_assigna();}
#line 2338 "y.tab.c"
    break;

  case 225: /* factor: CHARVAL  */
#line 254 "newTag.y"
                  {push();}
#line 2344 "y.tab.c"
    break;

  case 226: /* factor: INTVAL  */
#line 255 "newTag.y"
                 {push();}
#line 2350 "y.tab.c"
    break;

  case 227: /* factor: FLOATVAL  */
#line 256 "newTag.y"
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

#line 260 "newTag.y"


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
