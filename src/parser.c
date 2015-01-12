/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <iostream>
    #include <vector>
    #include <sstream>
    #include<map>
    #include "type.h"
    using namespace std;
    extern int yylineno;
    int yyerror (const char *error);
    void printCode (std::string* code);
    int  yylex ();
    type bt;
    int nliste = 0;
    int dliste = 0;
    int sliste = 0;
    int pliste = 0;
    int level = 0;
    int yylex ();
    int yyerror ();
    int addr = 0;
    int nlabel = 0;
    int nfunc = 0;
    string current_function;
    vector<std::string*> vec;
    map<std::string, type_t> VariableStack;

/* Line 371 of yacc.c  */
#line 98 "parser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     ICONSTANT = 259,
     FCONSTANT = 260,
     INC_OP = 261,
     DEC_OP = 262,
     LE_OP = 263,
     GE_OP = 264,
     EQ_OP = 265,
     NE_OP = 266,
     INT = 267,
     FLOAT = 268,
     VOID = 269,
     IF = 270,
     ELSE = 271,
     WHILE = 272,
     RETURN = 273,
     FOR = 274,
     DO = 275
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 57 "parser.y"

  type_t t;
  type_t lt[1000];
  char *str;
  int n;
  float f;


/* Line 387 of yacc.c  */
#line 170 "parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 198 "parser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,     2,     2,     2,     2,     2,
      21,    22,    28,    29,    25,    26,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      30,    32,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,    24,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    17,    22,    25,
      28,    33,    35,    39,    41,    44,    47,    49,    53,    55,
      59,    63,    65,    69,    73,    77,    81,    85,    89,    93,
     100,   102,   106,   108,   112,   114,   116,   118,   120,   123,
     128,   133,   139,   143,   148,   150,   154,   157,   159,   161,
     163,   165,   167,   170,   174,   179,   181,   184,   186,   189,
     191,   194,   200,   208,   214,   222,   230,   233,   237,   239,
     242,   244,   246
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    21,
      43,    22,    -1,     3,    21,    22,    -1,     3,    21,    38,
      22,    -1,     3,     6,    -1,     3,     7,    -1,     3,    23,
      43,    24,    -1,    43,    -1,    38,    25,    43,    -1,    37,
      -1,    26,    39,    -1,    27,    39,    -1,    39,    -1,    40,
      28,    39,    -1,    40,    -1,    41,    29,    40,    -1,    41,
      26,    40,    -1,    41,    -1,    41,    30,    41,    -1,    41,
      31,    41,    -1,    41,     8,    41,    -1,    41,     9,    41,
      -1,    41,    10,    41,    -1,    41,    11,    41,    -1,     3,
      32,    42,    -1,     3,    23,    43,    24,    32,    42,    -1,
      42,    -1,    46,    45,    33,    -1,    47,    -1,    45,    25,
      47,    -1,    14,    -1,    12,    -1,    13,    -1,     3,    -1,
      28,     3,    -1,     3,    23,     4,    24,    -1,     3,    21,
      48,    22,    -1,    28,     3,    21,    48,    22,    -1,     3,
      21,    22,    -1,    28,     3,    21,    22,    -1,    49,    -1,
      48,    25,    49,    -1,    46,    47,    -1,    51,    -1,    54,
      -1,    55,    -1,    56,    -1,    57,    -1,    34,    35,    -1,
      34,    53,    35,    -1,    34,    52,    53,    35,    -1,    44,
      -1,    52,    44,    -1,    50,    -1,    53,    50,    -1,    33,
      -1,    43,    33,    -1,    15,    21,    43,    22,    50,    -1,
      15,    21,    43,    22,    50,    16,    50,    -1,    17,    21,
      43,    22,    50,    -1,    19,    21,    54,    54,    43,    22,
      50,    -1,    20,    50,    17,    21,    43,    22,    33,    -1,
      18,    33,    -1,    18,    43,    33,    -1,    59,    -1,    58,
      59,    -1,    60,    -1,    44,    -1,    46,    47,    51,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    74,    82,    90,    93,    97,   101,   113,
     125,   141,   142,   146,   149,   163,   187,   190,   224,   227,
     258,   292,   295,   321,   347,   372,   401,   426,   454,   480,
     510,   516,   520,   521,   525,   526,   527,   531,   539,   553,
     555,   557,   559,   571,   586,   587,   591,   595,   596,   597,
     598,   599,   603,   606,   609,   613,   614,   618,   619,   630,
     631,   641,   654,   658,   659,   660,   664,   668,   677,   678,
     682,   683,   687
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "ICONSTANT", "FCONSTANT",
  "INC_OP", "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "INT", "FLOAT",
  "VOID", "IF", "ELSE", "WHILE", "RETURN", "FOR", "DO", "'('", "')'",
  "'['", "']'", "','", "'-'", "'!'", "'*'", "'+'", "'<'", "'>'", "'='",
  "';'", "'{'", "'}'", "$accept", "primary_expression",
  "argument_expression_list", "unary_expression",
  "multiplicative_expression", "additive_expression",
  "comparison_expression", "expression", "declaration", "declarator_list",
  "type_name", "declarator", "parameter_list", "parameter_declaration",
  "statement", "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "program", "external_declaration",
  "function_definition", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    40,    41,    91,    93,    44,    45,    33,    42,    43,
      60,    62,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    38,    38,    39,    39,    39,    40,    40,    41,    41,
      41,    42,    42,    42,    42,    42,    42,    42,    43,    43,
      43,    44,    45,    45,    46,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    48,    48,    49,    50,    50,    50,
      50,    50,    51,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    56,    57,    57,    58,    58,
      59,    59,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     4,     2,     2,
       4,     1,     3,     1,     2,     2,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     6,
       1,     3,     1,     3,     1,     1,     1,     1,     2,     4,
       4,     5,     3,     4,     1,     3,     2,     1,     1,     1,
       1,     1,     2,     3,     4,     1,     2,     1,     2,     1,
       2,     5,     7,     5,     7,     7,     2,     3,     1,     2,
       1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    35,    36,    34,    71,     0,     0,    68,    70,    37,
       0,     0,    32,     1,    69,     0,     0,    38,     0,    31,
       0,    72,    42,     0,     0,    44,     0,     0,    33,     2,
       3,     4,     0,     0,     0,     0,     0,     0,     0,     0,
      59,    52,    13,    16,    18,    21,    30,     0,    55,     0,
      57,    47,     0,     0,    48,    49,    50,    51,    46,    40,
       0,    39,    43,     0,     8,     9,     0,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     2,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    32,
      56,     0,    53,    58,    45,    41,     6,     0,    11,     0,
      28,     0,     0,    67,     0,     0,     5,     0,    17,    24,
      25,    26,    27,    20,    19,    22,    23,    54,     7,     0,
      10,     0,     0,     0,     0,     0,    12,     0,    61,    63,
       0,     0,    10,    29,     0,     0,     0,    62,    64,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    42,    97,    43,    44,    45,    46,    47,     4,    11,
      23,    12,    24,    25,    50,    51,    52,    53,    54,    55,
      56,    57,     6,     7,     8
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const yytype_int16 yypact[] =
{
      40,   -68,   -68,   -68,   -68,     3,   126,   -68,   -68,     9,
      10,   -22,   -16,   -68,   -68,   165,    16,    28,     3,   -68,
      90,   -68,   -68,     3,   -10,   -68,    37,   189,   -68,    56,
     -68,   -68,    48,    49,   159,    50,    63,   178,   193,   193,
     -68,   -68,   -68,   -68,    44,   207,   -68,    -8,   -68,     3,
     -68,   -68,   140,    24,   -68,   -68,   -68,   -68,   -68,   -68,
      40,   -68,   -68,    -3,   -68,   -68,   186,   178,   193,   178,
     178,   -68,    41,   167,    59,    51,   106,   -68,   -68,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   -68,   -68,
     -68,   115,   -68,   -68,   -68,   -68,   -68,     1,   -68,    76,
     -68,    79,    84,   -68,   167,    93,   -68,   178,   -68,     7,
       7,     7,     7,    44,    44,     7,     7,   -68,   -68,   178,
      83,    63,    63,   178,   178,    97,   -68,   193,   112,   -68,
     100,   109,   -68,   -68,    63,    63,   104,   -68,   -68,   -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   -31,   -20,   141,   -67,   -32,    -6,   -68,
       4,    -2,   119,    87,   -36,   139,   -68,   113,   -64,   -68,
     -68,   -68,   -68,   150,   -68
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      74,   100,    72,    18,     5,    75,     9,    77,    78,   104,
       5,    19,    59,    17,    48,    60,    28,    93,    20,    95,
      26,    58,    60,   118,    49,    88,   119,    29,    30,    31,
      15,    10,    16,    84,    98,    99,    85,   101,   102,    32,
     123,    33,    34,    35,    36,    37,    90,    89,   108,    27,
      38,    39,     1,     2,     3,    93,    49,    40,    20,    92,
     133,    61,    64,    65,   113,   114,    29,    30,    31,    69,
      70,    73,    79,   106,   103,   125,   105,    66,    32,    67,
      33,    34,    35,    36,    37,   128,   129,   126,    68,    38,
      39,   130,   131,    29,    30,    31,    40,    20,   137,   138,
     120,   121,     1,     2,     3,    32,   122,    33,    34,    35,
      36,    37,    64,    65,   124,   127,    38,    39,    29,    30,
      31,   132,   135,    40,    20,    41,    13,    66,   134,   107,
      32,   136,    33,    34,    35,    36,    37,   139,     1,     2,
       3,    38,    39,    29,    30,    31,    63,    94,    40,    20,
     117,    21,     1,     2,     3,    32,    14,    33,    34,    35,
      36,    37,    29,    30,    31,    91,    38,    39,     0,     0,
      29,    30,    31,    40,    20,     0,     0,     1,     2,     3,
      37,    29,    30,    31,     0,    38,    39,    22,    37,    29,
      30,    31,    71,    38,    39,     0,    76,    30,    31,    37,
      40,     1,     2,     3,    38,    39,     0,    37,    96,     0,
       0,    62,    38,    39,    37,    80,    81,    82,    83,    38,
      39,   109,   110,   111,   112,     0,     0,   115,   116,     0,
       0,     0,     0,    84,     0,     0,    85,    86,    87
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      36,    68,    34,    25,     0,    37,     3,    38,    39,    73,
       6,    33,    22,     3,    20,    25,    18,    53,    34,    22,
       4,    23,    25,    22,    20,    33,    25,     3,     4,     5,
      21,    28,    23,    26,    66,    67,    29,    69,    70,    15,
     104,    17,    18,    19,    20,    21,    52,    49,    79,    21,
      26,    27,    12,    13,    14,    91,    52,    33,    34,    35,
     127,    24,     6,     7,    84,    85,     3,     4,     5,    21,
      21,    21,    28,    22,    33,   107,    17,    21,    15,    23,
      17,    18,    19,    20,    21,   121,   122,   119,    32,    26,
      27,   123,   124,     3,     4,     5,    33,    34,   134,   135,
      24,    22,    12,    13,    14,    15,    22,    17,    18,    19,
      20,    21,     6,     7,    21,    32,    26,    27,     3,     4,
       5,    24,    22,    33,    34,    35,     0,    21,    16,    23,
      15,    22,    17,    18,    19,    20,    21,    33,    12,    13,
      14,    26,    27,     3,     4,     5,    27,    60,    33,    34,
      35,    12,    12,    13,    14,    15,     6,    17,    18,    19,
      20,    21,     3,     4,     5,    52,    26,    27,    -1,    -1,
       3,     4,     5,    33,    34,    -1,    -1,    12,    13,    14,
      21,     3,     4,     5,    -1,    26,    27,    22,    21,     3,
       4,     5,    33,    26,    27,    -1,     3,     4,     5,    21,
      33,    12,    13,    14,    26,    27,    -1,    21,    22,    -1,
      -1,    22,    26,    27,    21,     8,     9,    10,    11,    26,
      27,    80,    81,    82,    83,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    14,    44,    46,    58,    59,    60,     3,
      28,    45,    47,     0,    59,    21,    23,     3,    25,    33,
      34,    51,    22,    46,    48,    49,     4,    21,    47,     3,
       4,     5,    15,    17,    18,    19,    20,    21,    26,    27,
      33,    35,    37,    39,    40,    41,    42,    43,    44,    46,
      50,    51,    52,    53,    54,    55,    56,    57,    47,    22,
      25,    24,    22,    48,     6,     7,    21,    23,    32,    21,
      21,    33,    43,    21,    50,    43,     3,    39,    39,    28,
       8,     9,    10,    11,    26,    29,    30,    31,    33,    47,
      44,    53,    35,    50,    49,    22,    22,    38,    43,    43,
      42,    43,    43,    33,    54,    17,    22,    23,    39,    41,
      41,    41,    41,    40,    40,    41,    41,    35,    22,    25,
      24,    22,    22,    54,    21,    43,    43,    32,    50,    50,
      43,    43,    24,    42,    16,    22,    22,    50,    50,    33
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 68 "parser.y"
    {
	type_t local_identifier = VariableStack[current_function + " "+(yyvsp[(1) - (1)].str)];
	(yyval.t) = local_identifier;
	(yyval.t).code = new std::string("pushq %rbp\n");
	vec.push_back((yyval.t).code);
	}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 74 "parser.y"
    {
 std::stringstream s;
 s << "pushq $" << (yyvsp[(1) - (1)].n) << "\n";
 (yyval.t).code = new std::string(s.str());
 (yyval.t).element_type = INT_T;
 (yyval.t).kind = -1;
 vec.push_back((yyval.t).code);
 }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 82 "parser.y"
    {
 std::stringstream s;
 s << "pushq $" << (yyvsp[(1) - (1)].f) << "\n";
 (yyval.t).code = new std::string(s.str());
 (yyval.t).element_type = FLOAT_T;
 (yyval.t).kind = -1;
 vec.push_back((yyval.t).code);
 }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 90 "parser.y"
    {
(yyval.t) = (yyvsp[(2) - (3)].t);
}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 93 "parser.y"
    {
	type_t local_identifier = VariableStack[current_function + " "+(yyvsp[(1) - (3)].str)];
	(yyval.t) = local_identifier;
	}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 97 "parser.y"
    {
	type_t local_identifier = VariableStack[current_function + " "+(yyvsp[(1) - (4)].str)];
	(yyval.t) = local_identifier;
	}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 101 "parser.y"
    {
	type_t local_identifier = VariableStack[current_function + " "+(yyvsp[(1) - (2)].str)];
	(yyval.t) = local_identifier;
	std::stringstream s;
	s << "addq $1 ";
	s << -local_identifier.addre;
	s << "(%rbp)\npushq ";
	s << -local_identifier.addre;
	s << "(%rbp)\n";
	(yyval.t).code = new std::string(s.str());
	vec.push_back((yyval.t).code);
 }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 113 "parser.y"
    {
	type_t local_identifier = VariableStack[current_function + " "+(yyvsp[(1) - (2)].str)];
	(yyval.t) = local_identifier;
	std::stringstream s;
	s << "subq $1 " ;
	s << -local_identifier.addre;
	s << "(%rbp)\npushq ";
	s << -local_identifier.addre;
	s << "(%rbp)\n";
	(yyval.t).code = new std::string(s.str());
	vec.push_back((yyval.t).code);
}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 125 "parser.y"
    {
	type_t local_identifier = VariableStack[current_function + " "+(yyvsp[(1) - (4)].str)];
	(yyval.t) = local_identifier; 
	if(local_identifier.element_type == INT_T) {
	std::stringstream s;
	s << *(yyvsp[(3) - (4)].t).code;
	s << "popq %rax\nmovq ";
	s << -local_identifier.addre;
	s << "(%rbp, %rax, 8), %rax\npushq %rax\n";
	(yyval.t).code = new std::string(s.str());
	vec.push_back((yyval.t).code);
	}
}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 141 "parser.y"
    {}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 142 "parser.y"
    {}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 146 "parser.y"
    {
	(yyval.t) = (yyvsp[(1) - (1)].t);
 }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 149 "parser.y"
    {
	(yyval.t) = (yyvsp[(2) - (2)].t);	
	if ((yyvsp[(2) - (2)].t).element_type == INT_T)
      { 
		std::stringstream s;
		s << *(yyvsp[(2) - (2)].t).code;
		s << "popq %rax\n";
		s << "neg %rax\npushq %rax\n";
		(yyval.t).code = new std::string(s.str());
		vec.push_back((yyval.t).code);
      }
     else if ((yyvsp[(2) - (2)].t).element_type == FLOAT_T){}
       //meme chose avec des floats
  }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 163 "parser.y"
    {
	(yyval.t) = (yyvsp[(2) - (2)].t);
	if ((yyvsp[(2) - (2)].t).element_type == INT_T)
		{   
		  std::stringstream s;
		  s << *(yyvsp[(2) - (2)].t).code;
		  s << "popq %rax\n";
		  s << "cmpq $0, %rax\n";
		  s << "jne L" << nlabel << "\n";
		  s << "pushq $1\n";
		  s << "jmp L" << (nlabel+1) << "\n";
		  s << ".L" << nlabel << ":\n";
		  s << "pushq $0\n";
		  s << ".L"<< (nlabel+1) <<":\n";
		  (yyval.t).code = new std::string(s.str());
		  vec.push_back((yyval.t).code); 
		  nlabel += 2;
		 }
     else if ((yyvsp[(2) - (2)].t).element_type == FLOAT_T){}
       //idem en float
  }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 187 "parser.y"
    {
	(yyval.t) = (yyvsp[(1) - (1)].t);
 }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    {
	(yyval.t) = (yyvsp[(1) - (3)].t);
	if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T)) 
      {
		(yyval.t).element_type = INT_T;
	  	std::stringstream s;
		s << *(yyvsp[(1) - (3)].t).code;
		s << *(yyvsp[(3) - (3)].t).code;
		s << "popq %rax\n";
		s << "popq %rbx\n";
		s << "imul %rbx, %rax\n";
		s << "pushq %rax\n";
		(yyval.t).code = new std::string(s.str());
		vec.push_back((yyval.t).code);
      }
   else if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T))
     {
     (yyval.t).element_type = FLOAT_T;
     //idem en float
     }
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T))
     {
     (yyval.t).element_type = FLOAT_T;
     //idem en float
     }
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T))
     {
     (yyval.t).element_type = FLOAT_T;
     //idem en float
     }
}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 224 "parser.y"
    {
	(yyval.t) = (yyvsp[(1) - (1)].t);
       }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 227 "parser.y"
    {
	(yyval.t) = (yyvsp[(1) - (3)].t);
	if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T))
		{
		(yyval.t).element_type = INT_T;
		std::stringstream s;
		s << *(yyvsp[(1) - (3)].t).code;
		s << *(yyvsp[(3) - (3)].t).code;
		s << "popq %rax\n";
		s << "popq %rbx\n";
		s << "addq %rbx, %rax\n";
		s << "pushq %rax\n";
		(yyval.t).code = new std::string(s.str());
		vec.push_back((yyval.t).code);
		}
	else if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T))
		{
		(yyval.t).element_type = FLOAT_T;
		//idem en float
		}
	else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T))
		{
		(yyval.t).element_type = FLOAT_T;
		//idem en float
		}
	else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T))
		{
		(yyval.t).element_type = FLOAT_T;
		//idem en float
		}
}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 258 "parser.y"
    {
	(yyval.t) = (yyvsp[(1) - (3)].t);
	if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T))
		{
		(yyval.t).element_type = INT_T;
		std::stringstream s;
		s << *(yyvsp[(1) - (3)].t).code;
		s << *(yyvsp[(3) - (3)].t).code;
		s << "popq %rax\n";
		s << "popq %rbx\n";
		s << "subq %rbx, %rax\n";
		s << "pushq %rax\n";
		(yyval.t).code = new std::string(s.str());
		vec.push_back((yyval.t).code);
		}
	else if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T))
		{
		(yyval.t).element_type = FLOAT_T;
		//idem en float
		}
	else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T))
		{
		(yyval.t).element_type = FLOAT_T;
		//idem en float
		}
	else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T))
		{
		(yyval.t).element_type = FLOAT_T;
		//idem en float
		}
}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 292 "parser.y"
    {
	(yyval.t)=(yyvsp[(1) - (1)].t);
       }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 295 "parser.y"
    {
	(yyval.t)=(yyvsp[(1) - (3)].t);
	if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T))
      {
      (yyval.t).element_type = INT_T;
      std::stringstream s;
      s << *(yyvsp[(1) - (3)].t).code;
      s << *(yyvsp[(3) - (3)].t).code;
	  s << "popq %rax\n";
	  s << "popq %rbx\n";
	  s << "cmp %rax, %rbx\n";
	  s << "jl .L" << nlabel << "\n";
	  s << "movq $1 %rbp\n";
	  s << ".L" << nlabel << ":\n";
	  s << "movq $0 %rbp\n";
	  (yyval.t).code = new std::string(s.str());
	  vec.push_back((yyval.t).code);
	  nlabel++;
      }
   else if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T)){
     (yyval.t).element_type = FLOAT_T;}
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T)){
     (yyval.t).element_type = FLOAT_T;}
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T)){
     (yyval.t).element_type = FLOAT_T;}
}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 321 "parser.y"
    {
	(yyval.t)=(yyvsp[(1) - (3)].t);
	if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T))
      {
      (yyval.t).element_type = INT_T;
      std::stringstream s;
      s << *(yyvsp[(1) - (3)].t).code;
      s << *(yyvsp[(3) - (3)].t).code;
	  s << "popq %rax\n";
	  s << "popq %rbx\n";
	  s << "cmp %rax, %rbx\n";
	  s << "jg .L" << nlabel << "\n";
	  s << "movq $1 %rbp\n";
	  s << ".L" << nlabel << ":\n";
	  s << "movq $0 %rbp\n";
	  (yyval.t).code = new std::string(s.str());
	  vec.push_back((yyval.t).code);
	  nlabel++;
      }
   else if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T)){
     (yyval.t).element_type = FLOAT_T;}
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T)){
     (yyval.t).element_type = FLOAT_T;}
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T)){
     (yyval.t).element_type = FLOAT_T;}
}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 348 "parser.y"
    {	(yyval.t) = (yyvsp[(1) - (3)].t);	
if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T))
    { (yyval.t).element_type = INT_T;
      std::stringstream s;
      s << *(yyvsp[(1) - (3)].t).code;
      s << *(yyvsp[(3) - (3)].t).code;
	  s << "popq %rax\n";
	  s << "popq %rbx\n";
	  s << "cmp %rax, %rbx\n";
	  s << "jle .L" << nlabel << "\n";
	  s << "movq $1 %rbp\n";
	  s << ".L" << nlabel << ":\n";
	  s << "movq $0 %rbp\n";
	  (yyval.t).code = new std::string(s.str());
	  vec.push_back((yyval.t).code);
	  nlabel++;
      }
   else if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T)){
     (yyval.t).element_type = FLOAT_T;}
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T)){
     (yyval.t).element_type = FLOAT_T;}
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T)){
     (yyval.t).element_type = FLOAT_T;}
}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 373 "parser.y"
    {	(yyval.t)=(yyvsp[(1) - (3)].t);
	if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T))
    { (yyval.t).element_type = INT_T;
      std::stringstream s;
      s << *(yyvsp[(1) - (3)].t).code;
      s << *(yyvsp[(3) - (3)].t).code;
	  s << "popq %rax\n";
	  s << "popq %rbx\n";
	  s << "cmp %rax, %rbx\n";
	  s << "jge .L" << nlabel << "\n";
	  s << "movq $1 %rbp\n";
	  s << ".L" << nlabel << ":\n";
	  s << "movq $0 %rbp\n";
	  (yyval.t).code = new std::string(s.str());
	  vec.push_back((yyval.t).code);
	  nlabel++;
      }
    //$$.n = ($1.n <= $3.n);
   else if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.f = ($1.n <= $3.f);
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.f = ($1.f <= $3.n);
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     // $$.f = ($1.f <= $3.f);
}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 402 "parser.y"
    {	(yyval.t)=(yyvsp[(1) - (3)].t);
	if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T))
    { (yyval.t).element_type = INT_T;
      std::stringstream s;
	  s << *(yyvsp[(1) - (3)].t).code;
	  s << *(yyvsp[(3) - (3)].t).code;
	  s << "popq %rax\n";
	  s << "popq %rbx\n";
	  s << "cmp %rax, %rbx\n";
	  s << "je .L" << nlabel << "\n";
	  s << "movq $1 %rbp\n";
	  s << ".L" << nlabel << ":\n";
	  s << "movq $0 %rbp\n";
	  (yyval.t).code = new std::string(s.str());
	  vec.push_back((yyval.t).code);
	  nlabel++;
      }
   else if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T)){
     (yyval.t).element_type = FLOAT_T;}
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T)){
     (yyval.t).element_type = FLOAT_T;}
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T)){
     (yyval.t).element_type = FLOAT_T;}
}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 427 "parser.y"
    {	(yyval.t)=(yyvsp[(1) - (3)].t);
	if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T))
    { (yyval.t).element_type = INT_T;
      std::stringstream s;
	  s << *(yyvsp[(1) - (3)].t).code;
	  s << *(yyvsp[(3) - (3)].t).code;
	  s << "popq %rax\n";
	  s << "popq %rbx\n";
	  s << "cmp %rax, %rbx\n";
	  s << "jne .L" << nlabel << "\n";
	  s << "movq $1 %rbp\n";
	  s << ".L" << nlabel << ":\n";
	  s << "movq $0 %rbp\n";
	  (yyval.t).code = new std::string(s.str());
	  vec.push_back((yyval.t).code);
	  nlabel++;
      }
  else if (((yyvsp[(1) - (3)].t).element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T)){
    (yyval.t).element_type = FLOAT_T;}
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T)){
     (yyval.t).element_type = FLOAT_T;}
   else if (((yyvsp[(1) - (3)].t).element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T)){
     (yyval.t).element_type = FLOAT_T;}
}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 454 "parser.y"
    {
	type_t local_identifier = VariableStack[current_function + " "+(yyvsp[(1) - (3)].str)];
	(yyval.t) = local_identifier;
	if ((local_identifier.element_type == INT_T)&&(local_identifier.element_type == INT_T)){
     (yyval.t).element_type = INT_T;
     std::stringstream s;
     s << *(yyvsp[(3) - (3)].t).code;
	 s << "popq %rax\n";
	 s << "movl %rax " << -local_identifier.addre << "(%rbp)\n";
	 s << "pushq %rax\n";
	 (yyval.t).code = new std::string(s.str());
	 vec.push_back((yyval.t).code);
   }
 else if ((local_identifier.element_type == INT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T)){
   perror("int = float not allowed");}
 else if ((local_identifier.element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == INT_T)){
   (yyval.t).element_type = FLOAT_T;} // idem pour float
 else if ((local_identifier.element_type == FLOAT_T)&&((yyvsp[(3) - (3)].t).element_type == FLOAT_T)){ //idem pour float
   (yyval.t).element_type = FLOAT_T;
   std::stringstream s;
   s << "popq %rax\nmovl %rax " << -local_identifier.addre << "(%rbp)\npushq %rax\n";
   (yyval.t).code = new std::string(s.str());
   vec.push_back((yyval.t).code);
 }
   (yyval.t).addre = local_identifier.addre;
}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 481 "parser.y"
    {	
	type_t local_identifier = VariableStack[current_function + " "+(yyvsp[(1) - (6)].str)];
	(yyval.t) = local_identifier;
	if((yyvsp[(3) - (6)].t).element_type == INT_T){
    if ((local_identifier.element_type == INT_T)&&((yyvsp[(3) - (6)].t).element_type == INT_T)){
      (yyval.t).element_type = INT_T;
	  std::stringstream s;
	  s << *(yyvsp[(3) - (6)].t).code;
	  s << *(yyvsp[(6) - (6)].t).code;
	  s << "popq %rax\n";
	  s << "popq %rbx\n";
	  s << "movq %rax, " << -local_identifier.addre << "(%rbp, %rbx, 8)\n";
	  s << "pushq %rax\n";
	  (yyval.t).code = new std::string(s.str());
	  vec.push_back((yyval.t).code);
    }
    else if ((local_identifier.element_type == INT_T)&&((yyvsp[(3) - (6)].t).element_type == FLOAT_T))
      {perror("int[int] = float not allowed"); exit(0);}
    else if ((local_identifier.element_type == FLOAT_T)&&((yyvsp[(3) - (6)].t).element_type == INT_T))
      (yyval.t).element_type = FLOAT_T;
    else if ((local_identifier.element_type == FLOAT_T)&&((yyvsp[(3) - (6)].t).element_type == FLOAT_T))
      (yyval.t).element_type = FLOAT_T;
  }
  else
    {
      perror("expression not an int"); exit(0);
    }
  (yyval.t).addre = local_identifier.addre;
}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 510 "parser.y"
    {
	(yyval.t) = (yyvsp[(1) - (1)].t);
}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 520 "parser.y"
    {(yyval.lt)[0].element_type = (yyvsp[(1) - (1)].t).element_type ; dliste =1;}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 521 "parser.y"
    {(yyval.lt)[dliste++].element_type = (yyvsp[(3) - (3)].t).element_type;}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 525 "parser.y"
    {bt = VOID_T;}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 526 "parser.y"
    {bt = INT_T;}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 527 "parser.y"
    {bt = FLOAT_T;}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 531 "parser.y"
    { 
  if (bt != VOID_T){ 
      addr += 8; (yyval.t).addre = addr;
  }
  (yyval.t).element_type = bt;
  (yyval.t).kind = -1 ;
  VariableStack.insert ( std::pair<std::string, type_t>(current_function +" "+(yyvsp[(1) - (1)].str),(yyval.t)) );
  }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 539 "parser.y"
    { 
  if(bt == VOID_T)
 {
     perror("void* not allowed"); exit(0);
 } 
  else
    {
      addr += 8;
      (yyval.t).addre = addr;
      (yyval.t).element_type = (type)(bt+1); 
      (yyval.t).kind = -1;
      VariableStack.insert ( std::pair<std::string, type_t>((yyvsp[(2) - (2)].str),(yyval.t)) );
    }
}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 553 "parser.y"
    {(yyval.t).element_type = bt; (yyval.t).kind = 0;
   (yyval.t).element_size = (yyvsp[(3) - (4)].n); addr += 8*(yyvsp[(3) - (4)].n) ; (yyval.t).addre = addr; VariableStack.insert( std::pair<std::string, type_t>(current_function +" "+(yyvsp[(1) - (4)].str),(yyval.t)) );}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 555 "parser.y"
    {addr = 0;(yyval.t).element_type = bt; (yyval.t).kind = 1; 
(yyval.t).element_size = nliste; (yyval.t).function_parameters = (yyvsp[(3) - (4)].lt); VariableStack.insert(std::pair<std::string, type_t>((yyvsp[(1) - (4)].str), (yyval.t))); current_function = (yyvsp[(1) - (4)].str);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 557 "parser.y"
    {addr = 0;(yyval.t).element_type = bt; (yyval.t).kind = 1; 
(yyval.t).element_size = nliste; (yyval.t).function_parameters = (yyvsp[(4) - (5)].lt);VariableStack.insert(std::pair<std::string, type_t>((yyvsp[(2) - (5)].str),(yyval.t))); current_function = (yyvsp[(2) - (5)].str);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 559 "parser.y"
    {
	addr = 0;
	(yyval.t).element_type = bt;
	(yyval.t).kind = 1;
	(yyval.t).element_size = 0;	
	std::stringstream s;
	s << (yyvsp[(1) - (3)].str) <<":\n.LFB" << nfunc << ":\n.cfi_startproc\npushq	%rbp\n";
	s << ".cfi_def_cfa_offset 16\n.cfi_offset 6, -16\nmovq	%rsp, %rbp\n.cfi_def_cfa_register 6\n";
	(yyval.t).code = new std::string(s.str());
	vec.push_back((yyval.t).code);
	VariableStack.insert(std::pair<std::string, type_t>((yyvsp[(1) - (3)].str),(yyval.t))); current_function = (yyvsp[(1) - (3)].str);
 }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 571 "parser.y"
    {
	addr = 0;
	(yyval.t).element_type = bt;
	(yyval.t).kind = 1;
	(yyval.t).element_size = 0;	
	std::stringstream s;
	s << (yyvsp[(2) - (4)].str) << ":\n.LFB" << nfunc << ":\n.cfi_startproc\npushq	%rbp\n";
	s << ".cfi_def_cfa_offset 16\n.cfi_offset 6, -16\nmovq	%rsp, %rbp\n.cfi_def_cfa_register 6\n";
	(yyval.t).code = new std::string(s.str());
	vec.push_back((yyval.t).code);
	VariableStack.insert(std::pair<std::string, type_t>((yyvsp[(2) - (4)].str),(yyval.t))); current_function = (yyvsp[(2) - (4)].str);
 }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 586 "parser.y"
    {(yyval.lt)[0] = (yyvsp[(1) - (1)].t); nliste=1;}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 587 "parser.y"
    {(yyval.lt)[nliste++] = (yyvsp[(3) - (3)].t);}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 591 "parser.y"
    {(yyval.t) = (yyvsp[(2) - (2)].t);}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 595 "parser.y"
    {(yyval.t) = (yyvsp[(1) - (1)].t);}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 596 "parser.y"
    {(yyval.t) = (yyvsp[(1) - (1)].t);}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 597 "parser.y"
    {(yyval.t) = (yyvsp[(1) - (1)].t);}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 598 "parser.y"
    {(yyval.t) = (yyvsp[(1) - (1)].t);}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 599 "parser.y"
    {(yyval.t) = (yyvsp[(1) - (1)].t);}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 603 "parser.y"
    {
	(yyval.t).code = new std::string("");
	}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 606 "parser.y"
    {
	(yyval.t) = (yyvsp[(2) - (3)].t);
	}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 609 "parser.y"
    { (yyval.t) = (yyvsp[(3) - (4)].t);}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 613 "parser.y"
    {(yyval.lt)[0] = (yyvsp[(1) - (1)].t); pliste = 1;}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 614 "parser.y"
    {(yyval.lt)[pliste++] = (yyvsp[(2) - (2)].t);}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 618 "parser.y"
    {(yyval.t) = (yyvsp[(1) - (1)].t);}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 619 "parser.y"
    {
	(yyval.t) = (yyvsp[(2) - (2)].t);
	std::stringstream s;
    s << *(yyvsp[(1) - (2)].t).code;
    s << *(yyvsp[(2) - (2)].t).code;
    (yyval.t).code = new std::string(s.str());
	vec.push_back((yyval.t).code);
    }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 631 "parser.y"
    {
 (yyval.t) = (yyvsp[(1) - (2)].t);
 std::stringstream s;
 s << *(yyvsp[(1) - (2)].t).code;
 s << "popq %rax\n";
 (yyval.t).code = new std::string(s.str());
 vec.push_back((yyval.t).code);
 }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 642 "parser.y"
    {	
	std::stringstream s;
    s << *(yyvsp[(3) - (5)].t).code;
	s << "popq %rax\n";
	s << "cmp %rax, $0\n";
	s << "je .L" << nlabel << "\n";
	s << *(yyvsp[(5) - (5)].t).code;
	s << ".L" << nlabel << ":\n";
	(yyval.t).code = new std::string(s.str());
	vec.push_back((yyval.t).code);
	nlabel++;
}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 664 "parser.y"
    {
 (yyval.t).code = new std::string("movl $1, -8(%rbp)\n");
 vec.push_back((yyval.t).code);
}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 668 "parser.y"
    {
 std::stringstream s;
 s << "popq %rax\nmovl %rax, " << -(yyvsp[(2) - (3)].t).addre << "(%rbp)\n";
 (yyval.t).code = new std::string(s.str());
 vec.push_back((yyval.t).code);
}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 687 "parser.y"
    {
 std::stringstream s;
 s << *(yyvsp[(3) - (3)].t).code;
 s << ".cfi_def_cfa 7, 8\nret\n.cfi_endproc\n.LFE" << nfunc << ":\n";
 (yyval.t).code = new std::string(s.str());
 vec.push_back((yyval.t).code);
 printCode((yyval.t).code);
 nfunc++;
 }
    break;


/* Line 1792 of yacc.c  */
#line 2379 "parser.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 698 "parser.y"

#include <cstdio>
#include <string>

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

char *file_name = NULL;

int yyerror (const char *s) {
    fflush (stdout);
    fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
    return 0;
}

void printCode (std::string* code) {
	std::cout << *code;
	for (std::string* i : vec)
	{
		delete(i);
	}
	vec.clear();
}


int main (int argc, char *argv[]) {
    FILE *input = NULL;
    if (argc==2) {
    printf(".file	\"%s\"\n.text\n",argv[1]);
	input = fopen (argv[1], "r");
	file_name = strdup (argv[1]);
	if (input) {
	    yyin = input;
	    yyparse();
	}
	else {
	  fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
	    return 1;
	}
	free(file_name);
    }
    else {
	fprintf (stderr, "%s: error: no input file\n", *argv);
	return 1;
    }
    return 0;
}
