/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 45 "parser.y" /* yacc.c:1909  */


	struct string_list_node{
		char * data;
		struct string_list_node * next;
	};

	struct string_and_type_list_node{
		char * data;
		int type;
		struct string_and_type_list_node * next;
	};

	struct integer_list_node{
		int data;
		struct integer_list_node * next;
	};

	struct function_parameters{
		struct string_and_type_list_node * params;
		int size;
	};

	struct function_signature{
		struct string_list_node * identifiers;
		struct string_and_type_list_node * params;
		struct integer_list_node * param_count;
	};

	struct data_with_type{
		char * data;
		int type;
	};

	struct name_with_data{
		char * data;
		char * name;
	};


#line 85 "y.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    STRING_LITERAL = 259,
    NUMBER_LITERAL = 260,
    TRUE_LITERAL = 261,
    FALSE_LITERAL = 262,
    EXIT = 263,
    NUMBER = 264,
    STRING = 265,
    BOOLEAN = 266,
    VOID = 267,
    FUNCTION = 268,
    IF = 269,
    ELSE = 270,
    WHILE = 271,
    BREAK = 272,
    CONTINUE = 273,
    PRINT = 274,
    SCAN = 275,
    EQ_OP = 276,
    GE_OP = 277,
    LE_OP = 278,
    NE_OP = 279,
    INC_OP = 280,
    DEC_OP = 281,
    SUCCESSFUL = 282,
    FAILED = 283,
    IFX = 284,
    UNARY_MINUS = 285
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING_LITERAL 259
#define NUMBER_LITERAL 260
#define TRUE_LITERAL 261
#define FALSE_LITERAL 262
#define EXIT 263
#define NUMBER 264
#define STRING 265
#define BOOLEAN 266
#define VOID 267
#define FUNCTION 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define BREAK 272
#define CONTINUE 273
#define PRINT 274
#define SCAN 275
#define EQ_OP 276
#define GE_OP 277
#define LE_OP 278
#define NE_OP 279
#define INC_OP 280
#define DEC_OP 281
#define SUCCESSFUL 282
#define FAILED 283
#define IFX 284
#define UNARY_MINUS 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 86 "parser.y" /* yacc.c:1909  */

	char* string;
	struct function_parameters function_params;
	struct function_signature function;
	struct data_with_type data_and_type;
	struct name_with_data name_and_data;

#line 165 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
