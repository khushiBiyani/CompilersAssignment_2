/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
