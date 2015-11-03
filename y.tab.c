/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	enum types{
		ARRAY = 1, TYPE_STRING, TYPE_STRING_ARRAY, TYPE_BOOLEAN, TYPE_BOOLEAN_ARRAY, TYPE_NUMBER, TYPE_NUMBER_ARRAY, TYPE_VOID, NOT_FOUND
	};
	
	struct symbol_node{
		char * name;
		int type;
		int scope_level;
		struct symbol_node * next;
	};
	
	struct function_node{
		char * name;
		int * param_types;
		int param_count;
		int return_type;
		int is_defined;
		struct function_node * next;
	};


	int yylex(void);
	void yyerror(char *);
	void add_symbol(char * name, int type, int level);
	int get_symbol_type(char * name);
	void delete_symbols(int level);
	void add_function(char * name, int * param_types, int param_count, int return_type);
	int get_function_return_type(char * name);
	struct function_node * get_function(char * name);
	extern FILE * yyin;


	struct function_node * function_list = NULL;
	struct symbol_node * symbol_list = NULL;
	int current_level = 0;
	FILE * output = NULL;
	

#line 110 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 45 "parser.y" /* yacc.c:355  */


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


#line 181 "y.tab.c" /* yacc.c:355  */

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
#line 86 "parser.y" /* yacc.c:355  */

	char* string;
	struct function_parameters function_params;
	struct function_signature function;
	struct data_with_type data_and_type;
	struct name_with_data name_and_data;

#line 261 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 276 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   480

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    38,    31,     2,
      41,    42,    36,    34,    43,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      33,    48,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,    30,    45,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   128,   138,   149,   157,   166,   227,   294,
     355,   424,   430,   436,   445,   470,   484,   489,   497,   514,
     530,   530,   545,   558,   630,   708,   780,   862,   873,   884,
     884,   898,   911,   927,   944,   961,   979,   993,  1009,  1028,
    1041,  1054,  1061,  1068,  1081,  1081,  1095,  1108,  1124,  1141,
    1158,  1177,  1192,  1208,  1227,  1240,  1253,  1260,  1267,  1274,
    1281,  1294,  1303,  1311,  1325,  1339,  1353,  1367,  1381,  1395,
    1409,  1423,  1437,  1451,  1465,  1479,  1493,  1507,  1521,  1534,
    1554,  1565,  1571,  1577,  1583,  1589,  1606,  1668,  1737,  1761,
    1774,  1779,  1787,  1801
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL",
  "NUMBER_LITERAL", "TRUE_LITERAL", "FALSE_LITERAL", "EXIT", "NUMBER",
  "STRING", "BOOLEAN", "VOID", "FUNCTION", "IF", "ELSE", "WHILE", "BREAK",
  "CONTINUE", "PRINT", "SCAN", "EQ_OP", "GE_OP", "LE_OP", "NE_OP",
  "INC_OP", "DEC_OP", "SUCCESSFUL", "FAILED", "IFX", "'|'", "'&'", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "UNARY_MINUS", "';'", "'('",
  "')'", "','", "'{'", "'}'", "'['", "']'", "'='", "$accept", "start",
  "program", "main", "function_declaration_statement",
  "function_declaration", "var_type", "function", "params", "param_list",
  "function_definition_block", "$@1", "function_definition", "statements",
  "statement", "$@2", "while_statement", "$@3", "while_statements",
  "expression", "function_call_statement", "function_call", "args",
  "arg_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     124,    38,    62,    60,    43,    45,    42,    47,    37,   285,
      59,    40,    41,    44,   123,   125,    91,    93,    61
};
# endif

#define YYPACT_NINF -152

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-152)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     215,     1,  -152,  -152,  -152,    56,   -31,   -22,   119,    17,
      16,    23,  -152,    41,  -152,  -152,   215,    42,   230,  -152,
      40,    81,    50,    52,    72,   119,  -152,    82,    55,    82,
     119,   119,    45,  -152,  -152,  -152,  -152,   119,   337,  -152,
      58,    62,    63,   230,  -152,    92,   -23,  -152,  -152,    67,
    -152,  -152,  -152,   417,   -36,   357,    70,   110,  -152,   112,
     249,   271,  -152,  -152,   119,  -152,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,  -152,
    -152,  -152,  -152,    90,   127,  -152,  -152,   111,  -152,  -152,
     119,  -152,     2,  -152,    70,    70,   230,   193,   231,   435,
     435,   435,   435,   442,   442,   435,   435,   109,   109,  -152,
    -152,  -152,  -152,    82,    82,    75,    74,   417,  -152,   126,
      30,  -152,   133,   102,   100,   101,   115,   120,   119,   146,
     143,   144,  -152,   158,  -152,   123,  -152,   161,   163,   122,
     129,  -152,  -152,   148,   230,   130,   131,   119,   119,   119,
    -152,  -152,   377,   132,   134,   135,   193,    -6,  -152,    70,
      70,  -152,   230,  -152,   175,  -152,  -152,  -152,   397,   293,
     315,  -152,  -152,  -152,  -152,  -152,    19,  -152,   179,   178,
    -152,  -152,   230,   193,  -152,  -152,   138,  -152,   171,  -152,
     150,   230,  -152,  -152
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,    11,    13,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     2,     4,     0,     0,     5,    28,
       0,    86,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,    80,    82,    81,    83,    84,     0,     0,    85,
       0,     0,     0,     0,     1,     0,     0,    27,    43,    87,
      39,    40,    91,    93,     0,     0,     0,     9,     6,     7,
       0,     0,    68,    69,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,    41,    42,     0,     0,     3,    31,     0,    88,    90,
       0,    36,     0,    15,    10,     8,     0,     0,     0,    74,
      75,    76,    77,    73,    72,    70,    71,    63,    64,    65,
      66,    67,    30,     0,     0,     0,     0,    92,    17,     0,
       0,    14,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,    33,     0,    79,    25,    23,    20,
       0,    19,    16,     0,     0,     0,     0,     0,     0,     0,
      56,    57,     0,     0,     0,     0,     0,     0,    60,    26,
      24,    22,     0,    32,     0,    35,    54,    55,     0,     0,
       0,    52,    53,    58,    59,    62,     0,    46,     0,     0,
      18,    51,     0,     0,    45,    61,     0,    21,    49,    48,
       0,     0,    47,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,   177,  -152,  -152,  -152,    -3,   -26,   139,  -152,
    -152,  -152,  -152,   -42,   -14,  -152,  -151,  -152,  -152,   -16,
       0,  -152,   151,  -152
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    28,    17,    57,   121,   120,
      85,   162,   115,    18,    19,    43,   134,   156,   176,    38,
      39,    21,    26,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    83,    29,    59,    47,   175,    89,    90,    53,    55,
      30,     2,     3,     4,    60,    61,    20,    86,    20,    31,
      40,    65,   123,    87,    41,   185,    22,    23,     2,     3,
       4,    42,   189,   124,   177,   125,   126,   127,   128,   129,
     178,    44,    24,    20,   118,    46,   130,   131,    98,    25,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   132,   184,     2,     3,     4,    27,    47,
      62,    63,   142,   143,   117,    32,    33,    34,    35,    36,
      48,   114,   122,    20,    49,    56,    24,   137,   138,   119,
      50,    64,    51,     1,   133,    58,    20,   135,    80,     2,
       3,     4,    81,    82,     6,    84,     7,    37,    24,     8,
       9,    92,   152,    94,    52,    95,   116,    10,    11,   139,
     179,   140,    32,    33,    34,    35,    36,   145,   146,   141,
     165,   168,   169,   170,    12,   112,     2,     3,     4,   113,
     164,   148,   149,    24,    20,    76,    77,    78,   144,   153,
     147,   154,   155,   133,    37,   150,   135,     2,     3,     4,
     151,   157,    20,   158,   159,    47,   160,   161,   188,   163,
     166,   167,   172,   133,   173,   174,   135,   193,   180,    20,
     133,     1,    20,   135,   186,   190,   191,     2,     3,     4,
     192,    20,     6,    45,     7,    93,   123,     8,     9,     0,
      88,     0,     2,     3,     4,    10,    11,   124,     0,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     1,     0,
     130,   131,    12,   187,     2,     3,     4,     0,     5,     6,
       0,     7,     0,     1,     8,     9,     0,   132,     0,     2,
       3,     4,    10,    11,     6,     0,     7,     0,     0,     8,
       9,     0,    66,    67,    68,    69,     0,    10,    11,    12,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      66,    67,    68,    69,    12,     0,     0,     0,   136,    70,
      71,    72,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    96,    66,    67,    68,    69,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,     0,     0,    97,    66,    67,    68,    69,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     0,     0,   182,    66,    67,    68,    69,
       0,     0,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     0,     0,     0,   183,    66,    67,
      68,    69,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,    79,    66,    67,
      68,    69,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,    91,    66,    67,
      68,    69,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,   171,    66,    67,
      68,    69,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,   181,    66,    67,
      68,    69,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
       0,     0,     0,    66,    67,    68,    69,    -1,    -1,    74,
      75,    76,    77,    78,    72,    73,    74,    75,    76,    77,
      78
};

static const yytype_int16 yycheck[] =
{
       0,    43,     5,    29,    18,   156,    42,    43,    24,    25,
      41,     9,    10,    11,    30,    31,    16,    40,    18,    41,
       3,    37,     3,    46,     8,   176,    25,    26,     9,    10,
      11,     8,   183,    14,    40,    16,    17,    18,    19,    20,
      46,     0,    41,    43,    42,     3,    27,    28,    64,    48,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    44,    45,     9,    10,    11,    12,    83,
      25,    26,    42,    43,    90,     3,     4,     5,     6,     7,
      40,    84,    96,    83,     3,     3,    41,   113,   114,    92,
      40,    46,    40,     3,    97,    40,    96,    97,    40,     9,
      10,    11,    40,    40,    14,    13,    16,    35,    41,    19,
      20,    41,   128,     3,    42,     3,     5,    27,    28,    44,
     162,    47,     3,     4,     5,     6,     7,    25,    26,     3,
     144,   147,   148,   149,    44,    45,     9,    10,    11,    12,
     143,    41,    41,    41,   144,    36,    37,    38,    15,     3,
      48,     8,     8,   156,    35,    40,   156,     9,    10,    11,
      40,     3,   162,    40,     3,   179,     3,    45,   182,    40,
      40,    40,    40,   176,    40,    40,   176,   191,     3,   179,
     183,     3,   182,   183,     5,    47,    15,     9,    10,    11,
      40,   191,    14,    16,    16,    56,     3,    19,    20,    -1,
      49,    -1,     9,    10,    11,    27,    28,    14,    -1,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,     3,    -1,
      27,    28,    44,    45,     9,    10,    11,    -1,    13,    14,
      -1,    16,    -1,     3,    19,    20,    -1,    44,    -1,     9,
      10,    11,    27,    28,    14,    -1,    16,    -1,    -1,    19,
      20,    -1,    21,    22,    23,    24,    -1,    27,    28,    44,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      21,    22,    23,    24,    44,    -1,    -1,    -1,    47,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    42,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    42,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    42,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    21,    22,    23,    24,
      -1,    -1,    -1,    21,    22,    23,    24,    32,    33,    34,
      35,    36,    37,    38,    32,    33,    34,    35,    36,    37,
      38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    10,    11,    13,    14,    16,    19,    20,
      27,    28,    44,    50,    51,    52,    53,    55,    62,    63,
      69,    70,    25,    26,    41,    48,    71,    12,    54,    55,
      41,    41,     3,     4,     5,     6,     7,    35,    68,    69,
       3,     8,     8,    64,     0,    51,     3,    63,    40,     3,
      40,    40,    42,    68,    72,    68,     3,    56,    40,    56,
      68,    68,    25,    26,    46,    68,    21,    22,    23,    24,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    40,
      40,    40,    40,    62,    13,    59,    40,    46,    71,    42,
      43,    40,    41,    57,     3,     3,    42,    42,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    45,    12,    55,    61,     5,    68,    42,    55,
      58,    57,    63,     3,    14,    16,    17,    18,    19,    20,
      27,    28,    44,    55,    65,    69,    47,    56,    56,    44,
      47,     3,    42,    43,    15,    25,    26,    48,    41,    41,
      40,    40,    68,     3,     8,     8,    66,     3,    40,     3,
       3,    45,    60,    40,    55,    63,    40,    40,    68,    68,
      68,    40,    40,    40,    40,    65,    67,    40,    46,    62,
       3,    40,    42,    42,    45,    65,     5,    45,    63,    65,
      47,    15,    40,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    53,    54,    54,    54,
      54,    55,    55,    55,    56,    56,    57,    57,    58,    58,
      60,    59,    59,    61,    61,    61,    61,    62,    62,    64,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    66,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     3,     2,     3,     2,
       3,     1,     1,     1,     3,     2,     3,     2,     4,     2,
       0,     6,     4,     2,     3,     2,     3,     2,     1,     0,
       4,     3,     6,     5,     5,     7,     4,     3,     3,     3,
       3,     3,     3,     2,     0,     4,     3,     6,     5,     5,
       7,     4,     3,     3,     3,     3,     2,     2,     3,     3,
       2,     2,     1,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       3,     2,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 119 "parser.y" /* yacc.c:1646  */
    {
												printf("PARSER: start Found!\n");
												fprintf(output, "#include<stdio.h>\n#include<stdlib.h>\n\n%s", (yyvsp[0].string));
												printf("\nCompilation was successful!\n\n");
											
											}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 128 "parser.y" /* yacc.c:1646  */
    {
												printf("PARSER: program Found!\n");
												int size = strlen((yyvsp[-2].string)) + strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 4;
												(yyval.string) = (char*) malloc(size * sizeof(char));
												sprintf((yyval.string), "%s\n\n%s\n%s", (yyvsp[-2].string), (yyvsp[-1].string), (yyvsp[0].string));
												free((yyvsp[-2].string));
												free((yyvsp[-1].string));
												free((yyvsp[0].string));
											}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 138 "parser.y" /* yacc.c:1646  */
    {
												printf("PARSER: program Found!\n");
												int size = strlen((yyvsp[0].string)) + strlen("\nint main()\n\n{\nreturn 0;\n}") + 1;
												(yyval.string) = (char*) malloc(size * sizeof(char));
												sprintf((yyval.string), "\nint main()\n\n{\n%sreturn 0;\n}", (yyvsp[0].string));
												free((yyvsp[0].string));
											}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 149 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: main Found!\n");
										(yyval.string) = (yyvsp[0].string);
									}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 157 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_declaration_statement Found!\n");
										int size = strlen((yyvsp[-1].string)) + 2;
										(yyval.string) = (char *) malloc(size * sizeof(char));
										sprintf((yyval.string), "%s;", (yyvsp[-1].string));
									}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 166 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_declaration Found!\n");
										struct string_list_node * current = (yyvsp[0].function).identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = (yyvsp[0].function).identifiers;
										struct integer_list_node * current_count = (yyvsp[0].function).param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										int params_size = 0, param_count = 0;
										struct string_and_type_list_node * current_param = (yyvsp[0].function).params;
										while(current_param != NULL){
											param_count++;
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										int * param_types = (int *) malloc(param_count * sizeof(int));
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = (yyvsp[0].function).params;
										int i = 0;
										while(current_param != NULL){
											param_types[i++] = current_param->type;
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										int size = strlen((yyvsp[-1].data_and_type).data) + functionId_size + params_size + 4;
										(yyval.string) = (char *) malloc(size * sizeof(char));
										sprintf((yyval.string), "%s %s(%s)", (yyvsp[-1].data_and_type).data, functionId, params);
										if(get_function(functionId) != NULL){
											yyerror("Semantic Error: Function is already declared!");
											exit(1);
										}
										add_function(functionId, param_types, param_count, (yyvsp[-1].data_and_type).type);
										free(params);
									}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 227 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_declaration Found!\n");
										struct string_list_node * current = (yyvsp[-1].function).identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										functionId_size += strlen((yyvsp[0].string)) + 2;
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = (yyvsp[-1].function).identifiers;
										struct integer_list_node * current_count = (yyvsp[-1].function).param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										temp = (char *) malloc((strlen((yyvsp[0].string)) + 2) * sizeof(char));
										sprintf(temp, "%s%d", (yyvsp[0].string), (current_count != NULL) ? current_count->data : 0);
										strcat(functionId, temp);
										free(temp);
										
										int params_size = 0, param_count = 0;
										struct string_and_type_list_node * current_param = (yyvsp[-1].function).params;
										while(current_param != NULL){
											param_count++;
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										int * param_types = (int *) malloc(param_count * sizeof(int));
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = (yyvsp[-1].function).params;
										int i = 0;
										while(current_param != NULL){
											param_types[i++] = current_param->type;
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + functionId_size + params_size + 4;
										(yyval.string) = (char *) malloc(size * sizeof(char));
										sprintf((yyval.string), "%s %s(%s)", (yyvsp[-2].data_and_type).data, functionId, params);
										if(get_function(functionId) != NULL){
											yyerror("Semantic Error: Function is already declared!");
											exit(1);
										}
										add_function(functionId, param_types, param_count, (yyvsp[-2].data_and_type).type);
										free(params);
									}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 294 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_declaration Found!\n");
										struct string_list_node * current = (yyvsp[0].function).identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = (yyvsp[0].function).identifiers;
										struct integer_list_node * current_count = (yyvsp[0].function).param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										int params_size = 0, param_count = 0;
										struct string_and_type_list_node * current_param = (yyvsp[0].function).params;
										while(current_param != NULL){
											param_count++;
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										int * param_types = (int *) malloc(param_count * sizeof(int));
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = (yyvsp[0].function).params;
										int i = 0;
										while(current_param != NULL){
											param_types[i++] = current_param->type;
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										int size = strlen("void") + functionId_size + params_size + 4;
										(yyval.string) = (char *) malloc(size * sizeof(char));
										sprintf((yyval.string), "void %s(%s)", functionId, params);
										if(get_function(functionId) != NULL){
											yyerror("Semantic Error: Function is already declared!");
											exit(1);
										}
										add_function(functionId, param_types, param_count, TYPE_VOID);
										free(params);
									}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 355 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_declaration Found!\n");
										struct string_list_node * current = (yyvsp[-1].function).identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										functionId_size += strlen((yyvsp[0].string)) + 2;
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = (yyvsp[-1].function).identifiers;
										struct integer_list_node * current_count = (yyvsp[-1].function).param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										temp = (char *) malloc((strlen((yyvsp[0].string)) + 2) * sizeof(char));
										sprintf(temp, "%s%d", (yyvsp[0].string), (current_count != NULL) ? current_count->data : 0);
										strcat(functionId, temp);
										free(temp);
										int params_size = 0, param_count = 0;
										struct string_and_type_list_node * current_param = (yyvsp[-1].function).params;
										while(current_param != NULL){
											param_count++;
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										int * param_types = (int *) malloc(param_count * sizeof(int));
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = (yyvsp[-1].function).params;
										int i = 0;
										while(current_param != NULL){
											param_types[i++] = current_param->type;
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										int size = strlen("void") + functionId_size + params_size + 4;
										(yyval.string) = (char *) malloc(size * sizeof(char));
										sprintf((yyval.string), "void %s(%s)", functionId, params);
										if(get_function(functionId) != NULL){
											yyerror("Semantic Error: Function is already declared!");
											exit(1);
										}
										add_function(functionId, param_types, param_count, TYPE_VOID);
										free(params);
									}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 424 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: var_type Found!\n");
										(yyval.data_and_type).data = "char*";
										(yyval.data_and_type).type = TYPE_STRING;
									}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 430 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: var_type Found!\n");
										(yyval.data_and_type).data = "double";
										(yyval.data_and_type).type = TYPE_NUMBER;
									}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 436 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: var_type Found!\n");
										(yyval.data_and_type).data = "int";
										(yyval.data_and_type).type = TYPE_NUMBER;
									}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 445 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function Found!\n");
										struct string_list_node * current = (yyvsp[-2].function).identifiers;
										while(current->next != NULL){
											current = current->next;
										}
										current->next = (struct string_list_node*) malloc(sizeof(struct string_list_node));
										current->next->data = (yyvsp[-1].string);
										current->next->next = NULL;

										struct string_and_type_list_node* current_param = (yyvsp[-2].function).params;
										while(current_param->next != NULL){
											current_param = current_param->next;
										}
										current_param->next = (yyvsp[0].function_params).params;
										struct integer_list_node* current_count = (yyvsp[-2].function).param_count;
										while(current_count->next != NULL){
											current_count = current_count->next;
										}
										current_count->next = (struct integer_list_node*) malloc(sizeof(struct integer_list_node));
										current_count->next->data = (yyvsp[0].function_params).size;
										current_count->next->next = NULL;
										(yyval.function) = (yyvsp[-2].function);
 									}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 470 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function Found!\n");

										(yyval.function).identifiers = (struct string_list_node*) malloc(sizeof(struct string_list_node));
										(yyval.function).identifiers->data = (yyvsp[-1].string);
										(yyval.function).identifiers->next = NULL;
										(yyval.function).params = (yyvsp[0].function_params).params;
										(yyval.function).param_count = (struct integer_list_node*) malloc(sizeof(struct integer_list_node));
										(yyval.function).param_count->data = (yyvsp[0].function_params).size;
										(yyval.function).param_count->next = NULL;
									}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 484 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: params Found!\n");
										(yyval.function_params) = (yyvsp[-1].function_params);
									}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 489 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: params Found!\n");
										(yyval.function_params).params = NULL;
										(yyval.function_params).size = 0;
									}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 497 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: param_list Found!\n");
										struct string_and_type_list_node * current = (yyvsp[-3].function_params).params;
										while(current->next != NULL){
											current = current->next;
										}
										current->next = (struct string_and_type_list_node*) malloc(sizeof(struct string_and_type_list_node));
										current->next->next = NULL;
										int size = strlen((yyvsp[-1].data_and_type).data) + strlen((yyvsp[0].string)) + 2;
										current->next->data = (char*) malloc(size * sizeof(char));
										sprintf(current->next->data, "%s %s", (yyvsp[-1].data_and_type).data, (yyvsp[0].string));
										current->next->type = (yyvsp[-1].data_and_type).type;
										free((yyvsp[0].string));
										(yyvsp[-3].function_params).size++;
										(yyval.function_params) = (yyvsp[-3].function_params);
									}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 514 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: param_list Found!\n");
										(yyval.function_params).params = (struct string_and_type_list_node *) malloc(sizeof(struct string_and_type_list_node));
										(yyval.function_params).params->next = NULL;
										int size = strlen((yyvsp[-1].data_and_type).data) + strlen((yyvsp[0].string)) + 2;
										(yyval.function_params).params->data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.function_params).params->data, "%s %s", (yyvsp[-1].data_and_type).data, (yyvsp[0].string));
										free((yyvsp[0].string));
										(yyval.function_params).params->type = (yyvsp[-1].data_and_type).type;
										(yyval.function_params).size = 1;
									}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 530 "parser.y" /* yacc.c:1646  */
    {
												printf("SEMANTIC ANALYSER: setting scope level to 1\n");
												current_level = 1;
											}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 534 "parser.y" /* yacc.c:1646  */
    {
												printf("PARSER: function_definition_block Found!\n");
												int size = strlen((yyvsp[-4].string)) + strlen((yyvsp[-1].string)) + 7;
												(yyval.string) = (char *) malloc(size * sizeof(char));
												sprintf((yyval.string), "%s\n{\n%s\n}\n", (yyvsp[-4].string), (yyvsp[-1].string));
												free((yyvsp[-4].string));
												free((yyvsp[-1].string));
												printf("SEMANTIC ANALYSER: deleting local symbols and decreasing scope level...\n");
												delete_symbols(current_level--);
											}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 545 "parser.y" /* yacc.c:1646  */
    {
												printf("PARSER: function_definition_block Found!\n");
												int size = strlen((yyvsp[-2].string)) + 6;
												(yyval.string) = (char *) malloc(size * sizeof(char));
												sprintf((yyval.string), "%s\n{\n}\n", (yyvsp[-2].string));
												free((yyvsp[-2].string));
											}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 558 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_definition Found!\n");
										struct string_list_node * current = (yyvsp[0].function).identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = (yyvsp[0].function).identifiers;
										struct integer_list_node * current_count = (yyvsp[0].function).param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										int params_size = 0;
										struct string_and_type_list_node * current_param = (yyvsp[0].function).params;
										while(current_param != NULL){
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										struct function_node * function = get_function(functionId);
										if(function == NULL || function -> is_defined == 1){
											yyerror("Semantic Error: Function not found or it's already defined!");
											exit(1);
										}
										if(function->return_type != (yyvsp[-1].data_and_type).type){
											yyerror("Semantic Error: Function return type does not match it's declaration!");
											exit(1);
										}
										int index = 0;
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = (yyvsp[0].function).params;
										while(current_param != NULL){
											if(index == function->param_count || function->param_types[index++] != current_param->type){
												yyerror("Semantic Error: Function parameter types does not match it's declaration!");
												exit(1);
											}
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											char * oldParamName = strchr(current_param->data, ' ') + 1;
											char * newParamName = (char *) malloc((strlen(oldParamName) + 1) * sizeof(char));
											strcpy(newParamName, oldParamName);
											add_symbol(newParamName, current_param->type, current_level + 1);
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										function->is_defined = 1;
										int size = strlen((yyvsp[-1].data_and_type).data) + functionId_size + params_size + 4;
										(yyval.string) = (char *) malloc(size * sizeof(char));
										sprintf((yyval.string), "%s %s(%s)", (yyvsp[-1].data_and_type).data, functionId, params);
										free(functionId);
										free(params);
									}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 630 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_definition Found!\n");
										struct string_list_node * current = (yyvsp[-1].function).identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										functionId_size += strlen((yyvsp[0].string)) + 2;
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = (yyvsp[-1].function).identifiers;
										struct integer_list_node * current_count = (yyvsp[-1].function).param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										temp = (char *) malloc((strlen((yyvsp[0].string)) + 2) * sizeof(char));
										sprintf(temp, "%s%d", (yyvsp[0].string), (current_count != NULL) ? current_count->data : 0);
										strcat(functionId, temp);
										free(temp);
										
										int params_size = 0;
										struct string_and_type_list_node * current_param = (yyvsp[-1].function).params;
										while(current_param != NULL){
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										struct function_node * function = get_function(functionId);
										if(function == NULL || function -> is_defined == 1){
											yyerror("Semantic Error: Function not found or it's already defined!");
											exit(1);
										}
										if(function->return_type != (yyvsp[-2].data_and_type).type){
											yyerror("Semantic Error: Function return type does not match it's declaration!");
											exit(1);
										}
										int index = 0;
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = (yyvsp[-1].function).params;
										while(current_param != NULL){
											if(index == function->param_count || function->param_types[index++] != current_param->type){
												yyerror("Semantic Error: Function parameter types does not match it's declaration!");
												exit(1);
											}
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											char * oldParamName = strchr(current_param->data, ' ') + 1;
											char * newParamName = (char *) malloc((strlen(oldParamName) + 1) * sizeof(char));
											strcpy(newParamName, oldParamName);
											add_symbol(newParamName, current_param->type, current_level + 1);
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										function->is_defined = 1;
										int size = strlen((yyvsp[-2].data_and_type).data) + functionId_size + params_size + 4;
										(yyval.string) = (char *) malloc(size * sizeof(char));
										sprintf((yyval.string), "%s %s(%s)", (yyvsp[-2].data_and_type).data, functionId, params);
										free(functionId);
										free(params);
									}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 708 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_definition Found!\n");
										struct string_list_node * current = (yyvsp[0].function).identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = (yyvsp[0].function).identifiers;
										struct integer_list_node * current_count = (yyvsp[0].function).param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										int params_size = 0;
										struct string_and_type_list_node * current_param = (yyvsp[0].function).params;
										while(current_param != NULL){
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										struct function_node * function = get_function(functionId);
										if(function == NULL || function -> is_defined == 1){
											yyerror("Semantic Error: Function not found or it's already defined!");
											exit(1);
										}
										if(function->return_type != TYPE_VOID){
											yyerror("Semantic Error: Function return type does not match it's declaration!");
											exit(1);
										}
										int index = 0;
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = (yyvsp[0].function).params;
										while(current_param != NULL){
											if(index == function->param_count || function->param_types[index++] != current_param->type){
												yyerror("Semantic Error: Function parameter types does not match it's declaration!");
												exit(1);
											}
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											char * oldParamName = strchr(current_param->data, ' ') + 1;
											char * newParamName = (char *) malloc((strlen(oldParamName) + 1) * sizeof(char));
											strcpy(newParamName, oldParamName);
											add_symbol(newParamName, current_param->type, current_level + 1);
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										function->is_defined = 1;
										int size = strlen("void") + functionId_size + params_size + 4;
										(yyval.string) = (char *) malloc(size * sizeof(char));
										sprintf((yyval.string), "void %s(%s)", functionId, params);
										free(functionId);
										free(params);
									}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 780 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_definition Found!\n");
										struct string_list_node * current = (yyvsp[-1].function).identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										functionId_size += strlen((yyvsp[0].string)) + 2;
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = (yyvsp[-1].function).identifiers;
										struct integer_list_node * current_count = (yyvsp[-1].function).param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										temp = (char *) malloc((strlen((yyvsp[0].string)) + 2) * sizeof(char));
										sprintf(temp, "%s%d", (yyvsp[0].string), (current_count != NULL) ? current_count->data : 0);
										strcat(functionId, temp);
										free(temp);
										
										int params_size = 0;
										struct string_and_type_list_node * current_param = (yyvsp[-1].function).params;
										while(current_param != NULL){
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										struct function_node * function = get_function(functionId);
										if(function == NULL || function -> is_defined == 1){
											yyerror("Semantic Error: Function not found or it's already defined!");
											exit(1);
										}
										if(function->return_type != TYPE_VOID){
											yyerror("Semantic Error: Function return type does not match it's declaration!");
											exit(1);
										}
										int index = 0;
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = (yyvsp[-1].function).params;
										while(current_param != NULL){
											if(index == function->param_count || function->param_types[index++] != current_param->type){
												yyerror("Semantic Error: Function parameter types does not match it's declaration!");
												exit(1);
											}
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											char * oldParamName = strchr(current_param->data, ' ') + 1;
											char * newParamName = (char *) malloc((strlen(oldParamName) + 1) * sizeof(char));
											strcpy(newParamName, oldParamName);
											add_symbol(newParamName, current_param->type, current_level + 1);
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										function->is_defined = 1;
										int size = strlen("void") + functionId_size + params_size + 4;
										(yyval.string) = (char *) malloc(size * sizeof(char));
										sprintf((yyval.string), "void %s(%s)", functionId, params);
										free(functionId);
										free(params);
									}
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 862 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statements Found!\n");
										int size = strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 1;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										(yyval.string)[0] = '\0';
										strcpy((yyval.string), (yyvsp[-1].string));
										strcat((yyval.string), (yyvsp[0].string));
										free((yyvsp[-1].string));
										free((yyvsp[0].string));
 									}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 873 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statements Found!\n");
 										(yyval.string) = (yyvsp[0].string);
									}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 884 "parser.y" /* yacc.c:1646  */
    {
										printf("SEMANTIC ANALYSER: setting scope level to %d\n", ++current_level);
									}
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 887 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										int size = strlen((yyvsp[-1].string)) + 5;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										sprintf((yyval.string), "{\n%s}\n", (yyvsp[-1].string));
										free((yyvsp[-1].string));
										printf("SEMANTIC ANALYSER: deleting local symbols and decreasing scope level...\n");
										delete_symbols(current_level--);
									}
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 898 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										int type = get_symbol_type((yyvsp[-1].string));
										if(type != NOT_FOUND){
											yyerror("Semantic Error: Identifier is already defined!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[-1].string)) + 4;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										sprintf((yyval.string), "%s %s;\n", (yyvsp[-2].data_and_type).data, (yyvsp[-1].string));
										add_symbol((yyvsp[-1].string), (yyvsp[-2].data_and_type).type, current_level);
									}
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 911 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										int type = get_symbol_type((yyvsp[-4].string));
										if(type != NOT_FOUND){
											yyerror("Semantic Error: Identifier is already defined!");
											exit(1);
										}
										int size = strlen((yyvsp[-5].data_and_type).data) + strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].string)) + 20;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										sprintf((yyval.string), "%s %s[(unsigned int)%s];\n", (yyvsp[-5].data_and_type).data, (yyvsp[-4].string), (yyvsp[-2].string));
										free((yyvsp[-2].string));
										add_symbol((yyvsp[-4].string), (yyvsp[-5].data_and_type).type + ARRAY, current_level);
									}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 927 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										if((yyvsp[-2].data_and_type).type != TYPE_BOOLEAN){
											yyerror("Semantic Error: Expression type is not Boolean!");
											exit(1);
										}
										if((yyvsp[0].string)[0] != '{'){
											yyerror("Syntax Error: while statements must be wrapped in \'{\' and \'}\' !");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].string)) + 9;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										sprintf((yyval.string), "while(%s)\n%s", (yyvsp[-2].data_and_type).data, (yyvsp[0].string));
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].string));
									}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 944 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										if((yyvsp[-2].data_and_type).type != TYPE_BOOLEAN){
											yyerror("Semantic Error: Expression type is not Boolean!");
											exit(1);
										}
										if((yyvsp[0].string)[0] != '{'){
											yyerror("Syntax Error: if statements must be wrapped in \'{\' and \'}\' !");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].string)) + 6;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										sprintf((yyval.string), "if(%s)\n%s", (yyvsp[-2].data_and_type).data, (yyvsp[0].string));
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].string));
									}
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 961 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										if((yyvsp[-4].data_and_type).type != TYPE_BOOLEAN){
											yyerror("Semantic Error: Expression type is not Boolean!");
											exit(1);
										}
										if((yyvsp[-2].string)[0] != '{' || (yyvsp[0].string)[0] != '{'){
											yyerror("Syntax Error: if and else statements must be wrapped in \'{\' and \'}\' !");
											exit(1);
										}
										int size = strlen((yyvsp[-4].data_and_type).data) + strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 12;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										sprintf((yyval.string), "if(%s)\n%s\nelse\n%s", (yyvsp[-4].data_and_type).data, (yyvsp[-2].string), (yyvsp[0].string));
										free((yyvsp[-4].data_and_type).data);
										free((yyvsp[-2].string));
										free((yyvsp[0].string));
									}
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 979 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										int type = get_symbol_type((yyvsp[-3].string));
										if(type != (yyvsp[-1].data_and_type).type){
											yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].data_and_type).data) + 6;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										sprintf((yyval.string), "%s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].data_and_type).data);
										free((yyvsp[-3].string));
										free((yyvsp[-1].data_and_type).data);
 									}
#line 2511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 993 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										int size = strlen((yyvsp[-1].data_and_type).data) + 17;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										if((yyvsp[-1].data_and_type).type == TYPE_NUMBER){											
											sprintf((yyval.string), "printf(\"%%g\", %s);\n", (yyvsp[-1].data_and_type).data);
										}
										if((yyvsp[-1].data_and_type).type == TYPE_BOOLEAN){
											sprintf((yyval.string), "printf(\"%%d\", %s);\n", (yyvsp[-1].data_and_type).data);
										}
										if((yyvsp[-1].data_and_type).type == TYPE_STRING){
											sprintf((yyval.string), "printf(\"%%s\", %s);\n", (yyvsp[-1].data_and_type).data);
										}
										free((yyvsp[-1].data_and_type).data);
 									}
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1009 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
				 						int type = get_symbol_type((yyvsp[-1].string));
										if(type != TYPE_NUMBER && type != TYPE_STRING){
											yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
											exit(1);
										}
										if(type == TYPE_NUMBER){
											int size = strlen((yyvsp[-1].string)) + 18;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "scanf(\"%%lf\", &%s);\n", (yyvsp[-1].string));
										} else {
											int size = strlen((yyvsp[-1].string)) + 16;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "scanf(\"%%s\", %s);\n", (yyvsp[-1].string));
										}
										free((yyvsp[-1].string));
 									}
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1028 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										int type = get_symbol_type((yyvsp[-2].string));
										if(type != TYPE_NUMBER){
											yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].string)) + 5;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										sprintf((yyval.string), "%s++;\n", (yyvsp[-2].string));
										free((yyvsp[-2].string));
 									}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1041 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										int type = get_symbol_type((yyvsp[-2].string));
										if(type != TYPE_NUMBER){
											yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
												exit(1);
										}
										int size = strlen((yyvsp[-2].string)) + 5;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										sprintf((yyval.string), "%s--;\n", (yyvsp[-2].string));
										free((yyvsp[-2].string));
 									}
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1054 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										int size = 10;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										sprintf((yyval.string), "exit(0);\n");
 									}
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1061 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										int size = 10;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										sprintf((yyval.string), "exit(1);\n");
 									}
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1068 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: statement Found!\n");
										int size = strlen((yyvsp[-1].name_and_data).data) + 3;
										(yyval.string) = (char*) malloc(size * sizeof(char));
										sprintf((yyval.string), "%s;\n", (yyvsp[-1].name_and_data).data);
										free((yyvsp[-1].name_and_data).data);
									}
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1081 "parser.y" /* yacc.c:1646  */
    {
											printf("SEMANTIC ANALYSER: setting scope level to %d\n", ++current_level);
										}
#line 2630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1084 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int size = strlen((yyvsp[-1].string)) + 6;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "{\n%s}\n", (yyvsp[-1].string));
											free((yyvsp[-1].string));
											printf("SEMANTIC ANALYSER: deleting local symbols and decreasing scope level...\n");
											delete_symbols(current_level--);
										}
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1095 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int type = get_symbol_type((yyvsp[-1].string));
											if(type != NOT_FOUND){
												yyerror("Semantic Error: Identifier is already defined!");
												exit(1);
											}
											int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[-1].string)) + 4;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "%s %s;\n", (yyvsp[-2].data_and_type).data, (yyvsp[-1].string));
											add_symbol((yyvsp[-1].string), (yyvsp[-2].data_and_type).type, current_level);
										}
#line 2661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1108 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int type = get_symbol_type((yyvsp[-4].string));
											if(type != NOT_FOUND){
												yyerror("Semantic Error: Identifier is already defined!");
												exit(1);
											}
											int size = strlen((yyvsp[-5].data_and_type).data) + strlen((yyvsp[-4].string)) + strlen((yyvsp[-2].string)) + 20;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "%s %s[(unsigned int)%s];\n", (yyvsp[-5].data_and_type).data, (yyvsp[-4].string), (yyvsp[-2].string));
											free((yyvsp[-2].string));
											add_symbol((yyvsp[-4].string), (yyvsp[-5].data_and_type).type + ARRAY, current_level);
										}
#line 2679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1124 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											if((yyvsp[-2].data_and_type).type != TYPE_BOOLEAN){
												yyerror("Semantic Error: Expression type is not Boolean!");
												exit(1);
											}
											if((yyvsp[0].string)[0] != '{'){
												yyerror("Syntax Error: while statements must be wrapped in \'{\' and \'}\' !");
												exit(1);
											}
											int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].string)) + 9;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "while(%s)\n%s", (yyvsp[-2].data_and_type).data, (yyvsp[0].string));
											free((yyvsp[-2].data_and_type).data);
											free((yyvsp[0].string));
										}
#line 2700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1141 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											if((yyvsp[-2].data_and_type).type != TYPE_BOOLEAN){
												yyerror("Semantic Error: Expression type is not Boolean!");
												exit(1);
											}
											if((yyvsp[0].string)[0] != '{'){
												yyerror("Syntax Error: if statements must be wrapped in \'{\' and \'}\' !");
												exit(1);
											}
											int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].string)) + 6;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "if(%s)\n%s", (yyvsp[-2].data_and_type).data, (yyvsp[0].string));
											free((yyvsp[-2].data_and_type).data);
											free((yyvsp[0].string));
										}
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1158 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											if((yyvsp[-4].data_and_type).type != TYPE_BOOLEAN){
												yyerror("Semantic Error: Expression type is not Boolean!");
												exit(1);
											}
											if((yyvsp[-2].string)[0] != '{' || (yyvsp[0].string)[0] != '}'){
												yyerror("Syntax Error: if and else statements must be wrapped in \'{\' and \'}\' !");
												exit(1);
											}
											int size = strlen((yyvsp[-4].data_and_type).data) + strlen((yyvsp[-2].string)) + strlen((yyvsp[0].string)) + 12;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "if(%s)\n%s\nelse\n%s", (yyvsp[-4].data_and_type).data, (yyvsp[-2].string), (yyvsp[0].string));
											free((yyvsp[-4].data_and_type).data);
											free((yyvsp[-2].string));
											free((yyvsp[0].string));
										}
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1177 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int type = get_symbol_type((yyvsp[-3].string));
											if(type != (yyvsp[-1].data_and_type).type){
												yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
												exit(1);
											}
											int size = strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].data_and_type).data) + 6;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "%s = %s;\n", (yyvsp[-3].string), (yyvsp[-1].data_and_type).data);
											free((yyvsp[-3].string));
											free((yyvsp[-1].data_and_type).data);
 										}
#line 2761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1192 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int size = strlen((yyvsp[-1].data_and_type).data) + 17;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											if((yyvsp[-1].data_and_type).type == TYPE_NUMBER){											
												sprintf((yyval.string), "printf(\"%%g\", %s);\n", (yyvsp[-1].data_and_type).data);
											}
											if((yyvsp[-1].data_and_type).type == TYPE_BOOLEAN){
												sprintf((yyval.string), "printf(\"%%d\", %s);\n", (yyvsp[-1].data_and_type).data);
											}
											if((yyvsp[-1].data_and_type).type == TYPE_STRING){
												sprintf((yyval.string), "printf(\"%%s\", %s);\n", (yyvsp[-1].data_and_type).data);
											}
											free((yyvsp[-1].data_and_type).data);
 										}
#line 2781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1208 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int type = get_symbol_type((yyvsp[-1].string));
											if(type != TYPE_NUMBER && type != TYPE_STRING){
												yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
												exit(1);
											}
											if(type == TYPE_NUMBER){
												int size = strlen((yyvsp[-1].string)) + 18;
												(yyval.string) = (char*) malloc(size * sizeof(char));
												sprintf((yyval.string), "scanf(\"%%lf\", &%s);\n", (yyvsp[-1].string));
											} else {
												int size = strlen((yyvsp[-1].string)) + 16;
												(yyval.string) = (char*) malloc(size * sizeof(char));
												sprintf((yyval.string), "scanf(\"%%s\", %s);\n", (yyvsp[-1].string));
											}
											free((yyvsp[-1].string));
 										}
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1227 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int type = get_symbol_type((yyvsp[-2].string));
											if(type != TYPE_NUMBER){
												yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
												exit(1);
											}
											int size = strlen((yyvsp[-2].string)) + 5;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "%s++;\n", (yyvsp[-2].string));
											free((yyvsp[-2].string));
 										}
#line 2821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1240 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int type = get_symbol_type((yyvsp[-2].string));
											if(type != TYPE_NUMBER){
												yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
												exit(1);
											}
											int size = strlen((yyvsp[-2].string)) + 5;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "%s--;\n", (yyvsp[-2].string));
											free((yyvsp[-2].string));
 										}
#line 2838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1253 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int size = 8;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "break;\n");
 										}
#line 2849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1260 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int size = 11;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "continue;\n");
 										}
#line 2860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1267 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int size = 10;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "exit(0);\n");
 										}
#line 2871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1274 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int size = 10;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "exit(1);\n");
 										}
#line 2882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1281 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statement Found!\n");
											int size = strlen((yyvsp[-1].name_and_data).data) + 3;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											sprintf((yyval.string), "%s;\n", (yyvsp[-1].name_and_data).data);
											free((yyvsp[-1].name_and_data).data);
										}
#line 2894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1294 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statements Found!\n");
											int size = strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 1;
											(yyval.string) = (char*) malloc(size * sizeof(char));
											(yyval.string)[0] = '\0';
											strcpy((yyval.string), (yyvsp[-1].string));
											strcat((yyval.string), (yyvsp[0].string));
 										}
#line 2907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1303 "parser.y" /* yacc.c:1646  */
    {
											printf("PARSER: while_statements Found!\n");
											(yyval.string) = (yyvsp[0].string);
										}
#line 2916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1311 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!((yyvsp[-2].data_and_type).type == TYPE_NUMBER && (yyvsp[0].data_and_type).type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 4;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s + %s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_NUMBER;
									}
#line 2934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1325 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!((yyvsp[-2].data_and_type).type == TYPE_NUMBER && (yyvsp[0].data_and_type).type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 4;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s - %s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_NUMBER;
									}
#line 2952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1339 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!((yyvsp[-2].data_and_type).type == TYPE_NUMBER && (yyvsp[0].data_and_type).type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 4;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s * %s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_NUMBER;
									}
#line 2970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1353 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!((yyvsp[-2].data_and_type).type == TYPE_NUMBER && (yyvsp[0].data_and_type).type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 4;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s / %s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_NUMBER;
									}
#line 2988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1367 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!((yyvsp[-2].data_and_type).type == TYPE_NUMBER && (yyvsp[0].data_and_type).type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 14;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "(int)%s %% (int)%s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_NUMBER;
									}
#line 3006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1381 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										int type = get_symbol_type((yyvsp[-1].string));
										if(type != TYPE_NUMBER){
											yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-1].string)) + 3;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s++", (yyvsp[-1].string));
										free((yyvsp[-1].string));
										(yyval.data_and_type).type = TYPE_NUMBER;
 									}
#line 3024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1395 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										int type = get_symbol_type((yyvsp[-1].string));
										if(type != TYPE_NUMBER){
											yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-1].string)) + 3;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s--", (yyvsp[-1].string));
										free((yyvsp[-1].string));
										(yyval.data_and_type).type = TYPE_NUMBER;
 									}
#line 3042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1409 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!((yyvsp[-2].data_and_type).type == TYPE_NUMBER && (yyvsp[0].data_and_type).type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 4;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s > %s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_BOOLEAN;
									}
#line 3060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1423 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!((yyvsp[-2].data_and_type).type == TYPE_NUMBER && (yyvsp[0].data_and_type).type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 4;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s < %s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_BOOLEAN;
									}
#line 3078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1437 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!((yyvsp[-2].data_and_type).type == TYPE_BOOLEAN && (yyvsp[0].data_and_type).type == TYPE_BOOLEAN)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 5;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s && %s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_BOOLEAN;
									}
#line 3096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1451 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!((yyvsp[-2].data_and_type).type == TYPE_BOOLEAN && (yyvsp[0].data_and_type).type == TYPE_BOOLEAN)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 5;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s || %s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_BOOLEAN;
									}
#line 3114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1465 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!(((yyvsp[-2].data_and_type).type == TYPE_NUMBER && (yyvsp[0].data_and_type).type == TYPE_NUMBER)||((yyvsp[-2].data_and_type).type == TYPE_BOOLEAN && (yyvsp[0].data_and_type).type == TYPE_BOOLEAN))){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 5;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s == %s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_BOOLEAN;
									}
#line 3132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1479 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!((yyvsp[-2].data_and_type).type == TYPE_NUMBER && (yyvsp[0].data_and_type).type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 5;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s >= %s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_BOOLEAN;
									}
#line 3150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1493 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!((yyvsp[-2].data_and_type).type == TYPE_NUMBER && (yyvsp[0].data_and_type).type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 5;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s <= %s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_BOOLEAN;
									}
#line 3168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1507 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if(!(((yyvsp[-2].data_and_type).type == TYPE_NUMBER && (yyvsp[0].data_and_type).type == TYPE_NUMBER)||((yyvsp[-2].data_and_type).type == TYPE_BOOLEAN && (yyvsp[0].data_and_type).type == TYPE_BOOLEAN))){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen((yyvsp[-2].data_and_type).data) + strlen((yyvsp[0].data_and_type).data) + 5;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s != %s", (yyvsp[-2].data_and_type).data, (yyvsp[0].data_and_type).data);
										free((yyvsp[-2].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = TYPE_BOOLEAN;
									}
#line 3186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1521 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										if((yyvsp[0].data_and_type).type != TYPE_NUMBER){
											yyerror("Semantic Error: Expression type is not number!");
											exit(1);
										}
										int size = strlen((yyvsp[0].data_and_type).data) + 2;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "-%s", (yyvsp[0].data_and_type).data);
										free((yyvsp[0].data_and_type).data);
										(yyval.data_and_type).type = (yyvsp[0].data_and_type).type;
									}
#line 3203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1534 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										int type = get_symbol_type((yyvsp[-3].string));
										if(type != TYPE_STRING_ARRAY && type != TYPE_NUMBER_ARRAY && type != TYPE_BOOLEAN_ARRAY){
											yyerror("Semantic Error: Identifier is not an array!");
											exit(1);
										}
										if((yyvsp[-1].data_and_type).type != TYPE_NUMBER){
											yyerror("Semantic Error: Expression type is not number!");
											exit(1);
										}
										
										(yyval.data_and_type).type = type - ARRAY;
										int size = strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].data_and_type).data) + 19;
										(yyval.data_and_type).data = (char*) malloc(size * sizeof(char));
										sprintf((yyval.data_and_type).data, "%s[(unsigned int)(%s)]", (yyvsp[-3].string), (yyvsp[-1].data_and_type).data);
										free((yyvsp[-3].string));
										free((yyvsp[-1].data_and_type).data);
									}
#line 3227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1554 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										int type = get_symbol_type((yyvsp[0].string));
										if(type == NOT_FOUND){
											yyerror("Semantic Error: Identifier is undefined!");
											exit(1);
										}
										(yyval.data_and_type).type = type;
										(yyval.data_and_type).data = (yyvsp[0].string);
									}
#line 3242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1565 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										(yyval.data_and_type).data = (yyvsp[0].string);
										(yyval.data_and_type).type = TYPE_NUMBER;
									}
#line 3252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1571 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										(yyval.data_and_type).data = (yyvsp[0].string);
										(yyval.data_and_type).type = TYPE_STRING;
									}
#line 3262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1577 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										(yyval.data_and_type).data = (yyvsp[0].string);
										(yyval.data_and_type).type = TYPE_BOOLEAN;
									}
#line 3272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1583 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										(yyval.data_and_type).data = (yyvsp[0].string);
										(yyval.data_and_type).type = TYPE_BOOLEAN;
									}
#line 3282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1589 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: expression Found!\n");
										int type = get_function_return_type((yyvsp[0].name_and_data).name);
										if(type == TYPE_VOID || type == NOT_FOUND){
											yyerror("Semantic Error: Function not found or it's type is void!");
											exit(1);
										}
										(yyval.data_and_type).type = type;
										(yyval.data_and_type).data = (yyvsp[0].name_and_data).data;
									}
#line 3297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1606 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_call_statement Found!\n");
										struct string_list_node * current = (yyvsp[0].function).identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = (yyvsp[0].function).identifiers;
										struct integer_list_node * current_count = (yyvsp[0].function).param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										int params_size = 0;
										struct string_and_type_list_node * current_param = (yyvsp[0].function).params;
										while(current_param != NULL){
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										struct function_node * function = get_function(functionId);
										if(function == NULL){
											yyerror("Semantic Error: Function is not declared!");
											exit(1);
										}
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = (yyvsp[0].function).params;
										int index = 0;
										while(current_param != NULL){
											if(index == function->param_count || function->param_types[index++] != current_param->type){
												yyerror("Semantic Error: Function arguments does not match it's declared parameter types!");
												exit(1);
											}
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										int size = functionId_size + params_size + 4;
										(yyval.name_and_data).data = (char *) malloc(size * sizeof(char));
										sprintf((yyval.name_and_data).data, "%s(%s)", functionId, params);
										(yyval.name_and_data).name = functionId;
										free(params);
									}
#line 3363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1668 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_call_statement Found!\n");
										struct string_list_node * current = (yyvsp[-1].function).identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										functionId_size += strlen((yyvsp[0].string)) + 2;
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp = NULL;
										current = (yyvsp[-1].function).identifiers;
										struct integer_list_node * current_count = (yyvsp[-1].function).param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										temp = (char *) malloc((strlen((yyvsp[0].string)) + 2) * sizeof(char));
										sprintf(temp, "%s%d", (yyvsp[0].string), (current_count != NULL) ? current_count->data : 0);
										strcat(functionId, temp);
										free(temp);
										int params_size = 0;
										struct string_and_type_list_node * current_param = (yyvsp[-1].function).params;
										while(current_param != NULL){
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										struct function_node * function = get_function(functionId);
										if(function == NULL){
											yyerror("Semantic Error: Function is not declared!");
											exit(1);
										}
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = (yyvsp[-1].function).params;
										int index = 0;
										while(current_param != NULL){
											if(index == function->param_count || function->param_types[index++] != current_param->type){
												yyerror("Semantic Error: Function arguments does not match it's declared parameter types!");
												exit(1);
											}
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										int size = functionId_size + params_size + 3;
										(yyval.name_and_data).data = (char *) malloc(size * sizeof(char));
										sprintf((yyval.name_and_data).data, "%s(%s)", functionId, params);
										(yyval.name_and_data).name = functionId;
										free(params);
									}
#line 3434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1737 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_call Found!\n");										
										struct string_list_node * current = (yyvsp[-2].function).identifiers;
										while(current->next != NULL){
											current = current->next;
										}
										current->next = (struct string_list_node*) malloc(sizeof(struct string_list_node));
										current->next->data = (yyvsp[-1].string);
										current->next->next = NULL;

										struct string_and_type_list_node * current_param = (yyvsp[-2].function).params;
										while(current_param->next != NULL){
											current_param = current_param->next;
										}
										current_param->next = (yyvsp[0].function_params).params;
										struct integer_list_node* current_count = (yyvsp[-2].function).param_count;
										while(current_count->next != NULL){
											current_count = current_count->next;
										}
										current_count->next = (struct integer_list_node*) malloc(sizeof(struct integer_list_node));
										current_count->next->data = (yyvsp[0].function_params).size;
										current_count->next->next = NULL;
 									}
#line 3462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1761 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: function_call Found!\n");
										(yyval.function).identifiers = (struct string_list_node*) malloc(sizeof(struct string_list_node));
										(yyval.function).identifiers->data = (yyvsp[-1].string);
										(yyval.function).identifiers->next = NULL;
										(yyval.function).params = (yyvsp[0].function_params).params;
										(yyval.function).param_count = (struct integer_list_node*) malloc(sizeof(struct integer_list_node));
										(yyval.function).param_count->data = (yyvsp[0].function_params).size;
										(yyval.function).param_count->next = NULL;
									}
#line 3477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1774 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: args Found!\n");
										(yyval.function_params) = (yyvsp[-1].function_params);
									}
#line 3486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1779 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: args Found!\n");
										(yyval.function_params).params = NULL;
										(yyval.function_params).size = 0;
									}
#line 3496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1787 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: arg_list Found!\n");
										struct string_and_type_list_node * current = (yyvsp[-2].function_params).params;
										while(current->next != NULL){
											current = current->next;
										}
										current->next = (struct string_and_type_list_node *) malloc(sizeof(struct string_and_type_list_node));
										current->next->next = NULL;
										current->next->data = (yyvsp[0].data_and_type).data;
										current->next->type = (yyvsp[0].data_and_type).type;
										(yyvsp[-2].function_params).size++;
										(yyval.function_params) = (yyvsp[-2].function_params);
									}
#line 3514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1801 "parser.y" /* yacc.c:1646  */
    {
										printf("PARSER: arg_list Found!\n");
										(yyval.function_params).params = (struct string_and_type_list_node *) malloc(sizeof(struct string_and_type_list_node));
										(yyval.function_params).params->next = NULL;
										(yyval.function_params).params->data = (yyvsp[0].data_and_type).data;
										(yyval.function_params).params->type = (yyvsp[0].data_and_type).type;
										(yyval.function_params).size = 1;
									}
#line 3527 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3531 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1813 "parser.y" /* yacc.c:1906  */


void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

void add_symbol(char * name, int type, int level){
	struct symbol_node * temp = (struct symbol_node *) malloc(sizeof(struct symbol_node));
	temp->name = name;
	temp->type = type;
	temp->scope_level = level;
	temp->next = symbol_list;
	symbol_list = temp;
}

void delete_symbols(int level){
	struct symbol_node * temp;
	while(symbol_list != NULL && symbol_list->scope_level == level){
		temp = symbol_list->next;
		free(symbol_list->name);
		free(symbol_list);
		symbol_list = temp;
	}
}

int get_symbol_type(char * name){
	struct symbol_node * list = symbol_list;
	while(list != NULL){
		if(strcmp(list->name, name) == 0){
			return list->type;
		}
		list = list->next;
	}
	return NOT_FOUND;
}

void add_function(char * name, int * param_types, int param_count, int return_type){
	struct function_node * temp = (struct function_node *) malloc(sizeof(struct function_node));
	temp->name = name;
	temp->param_types = param_types;
	temp->param_count = param_count;
	temp->return_type = return_type;
	temp->is_defined = 0;
	temp->next = function_list;
	function_list = temp;
}

int get_function_return_type(char * name){
	struct function_node * list = function_list;
	while(list != NULL){
		if(strcmp(list->name, name) == 0){
			return list->return_type;
		}
		list = list->next;
	}
	return NOT_FOUND;
}


struct function_node * get_function(char * name){
	struct function_node * list = function_list;
	while(list != NULL){
		if(strcmp(list->name, name) == 0){
			return list;
		}
		list = list->next;
	}
	return NULL;
}


int main(int argc, char **argv) {
	if(argc != 3){
		printf("Error: bad arguments!\nThis compiler compiles an input file to C language!\nUSAGE: compiler [input_file_name] [output_file_name]\n");
		return 1;
	}
	yyin = fopen(argv[1], "r");
	if(yyin == NULL){
		printf("Error:\tCan't open input file!\n");
		return 1;
	}
	output = fopen(argv[2], "w");
	if(yyin == NULL){
		printf("Error:\tCan't open output file!\n");
		return 1;
	}
	yyparse();
	return 0;
}
