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

    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <iostream>
    #include <vector>
    #include <sstream>
    #include "type.h"
    using namespace std;
    extern int yylineno;
    int yyerror (const char *error);
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
    vector<std::string*> vec;


#line 93 "parser.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 54 "parser.y" /* yacc.c:355  */

  type_t t;
  type_t lt[1000];
  char *str;
  int n;
  float f;

#line 162 "parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 177 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    66,    67,    68,    69,    70,    71,    79,
      87,    99,   100,   104,   112,   123,   140,   148,   179,   187,
     216,   248,   257,   270,   283,   297,   311,   325,   342,   365,
     390,   401,   405,   406,   410,   411,   412,   416,   421,   434,
     436,   438,   452,   453,   457,   461,   462,   463,   464,   465,
     469,   470,   471,   475,   476,   480,   481,   485,   486,   494,
     495,   499,   500,   501,   505,   510,   519,   520,   524,   525,
     529
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
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    40,    41,    91,    93,    44,    45,    33,    42,    43,
      60,    62,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      44,   -65,   -65,   -65,   -65,     9,    10,   -65,   -65,    -8,
      31,    -4,    -3,   -65,   -65,    59,   -65,     9,   -65,    32,
      87,   -65,    45,    49,   -65,     9,    72,   -65,    54,   -65,
     -65,    57,    64,    22,    66,    47,   196,   200,   200,   -65,
     -65,   -65,   -65,    43,   220,   -65,    60,   -65,     9,   -65,
     -65,   162,   112,   -65,   -65,   -65,   -65,   -65,    49,   -65,
      44,   -65,   -65,   189,   196,   200,   196,   196,   -65,    65,
     181,    86,    88,     7,   -65,   -65,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   -65,    49,   -65,   137,   -65,
     -65,   -65,   -65,   101,   -65,    85,   -65,    89,    90,   -65,
     181,    97,   -65,   196,   -65,    50,    50,    50,    50,    43,
      43,    50,    50,   -65,   -65,   196,    92,    47,    47,   196,
     196,    95,   -65,   200,   109,   -65,   106,   113,   -65,   -65,
      47,    47,   103,   -65,   -65,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    35,    36,    34,    69,     0,     0,    66,    68,    37,
       0,     0,    32,     1,    67,     0,    38,     0,    31,     0,
       0,    70,     0,    33,    41,     0,     0,    42,     2,     3,
       4,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      50,    13,    16,    18,    21,    30,     0,    53,     0,    55,
      45,     0,     0,    46,    47,    48,    49,    39,    44,    40,
       0,     8,     9,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     2,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    32,    54,     0,    51,
      56,    43,     6,     0,    11,     0,    28,     0,     0,    65,
       0,     0,     5,     0,    17,    24,    25,    26,    27,    20,
      19,    22,    23,    52,     7,     0,    10,     0,     0,     0,
       0,     0,    12,     0,    59,    61,     0,     0,    10,    29,
       0,     0,     0,    60,    62,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   -65,   -34,   -62,   155,   -64,   -31,   -11,   -65,
     -13,    -9,   -65,    74,   -35,   125,   -65,    93,   -59,   -65,
     -65,   -65,   -65,   142,   -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    41,    93,    42,    43,    44,    45,    46,     4,    11,
       5,    12,    26,    27,    49,    50,    51,    52,    53,    54,
      55,    56,     6,     7,     8
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      71,    96,    69,    74,    75,    72,    25,    48,    23,    47,
      13,   100,     9,    61,    62,    15,    58,    90,    19,   109,
     110,    17,     1,     2,     3,    28,    29,    30,    63,    18,
     103,    20,    94,    95,    16,    97,    98,    10,    48,    86,
      87,   119,   104,    36,     1,     2,     3,    25,    37,    38,
      28,    29,    30,    90,    24,    68,     1,     2,     3,   129,
      61,    62,    31,    22,    32,    33,    34,    35,    36,    57,
      19,    76,   121,    37,    38,    63,    81,    64,    66,    82,
      39,    20,   124,   125,   122,    67,    65,    70,   126,   127,
      28,    29,    30,    85,    59,   133,   134,    60,    99,     1,
       2,     3,    31,   101,    32,    33,    34,    35,    36,   116,
     102,   117,   118,    37,    38,    28,    29,    30,   120,   128,
      39,    20,    40,   114,   123,   130,   115,    31,   131,    32,
      33,    34,    35,    36,    91,   132,   135,    21,    37,    38,
      28,    29,    30,     0,    88,    39,    20,    89,    14,     0,
       0,     0,    31,     0,    32,    33,    34,    35,    36,     0,
       0,     0,     0,    37,    38,    28,    29,    30,     0,     0,
      39,    20,   113,     0,     1,     2,     3,    31,     0,    32,
      33,    34,    35,    36,    28,    29,    30,     0,    37,    38,
       0,     0,    28,    29,    30,    39,    20,     0,     0,    28,
      29,    30,    36,    73,    29,    30,     0,    37,    38,     0,
      36,    92,     0,     0,    39,    37,    38,    36,     0,     0,
       0,    36,    37,    38,     0,     0,    37,    38,    77,    78,
      79,    80,   105,   106,   107,   108,     0,     0,   111,   112,
       0,     0,     0,     0,     0,     0,    81,     0,     0,    82,
      83,    84
};

static const yytype_int16 yycheck[] =
{
      35,    65,    33,    37,    38,    36,    19,    20,    17,    20,
       0,    70,     3,     6,     7,    23,    25,    52,    21,    81,
      82,    25,    12,    13,    14,     3,     4,     5,    21,    33,
      23,    34,    63,    64,     3,    66,    67,    28,    51,    48,
      51,   100,    76,    21,    12,    13,    14,    60,    26,    27,
       3,     4,     5,    88,    22,    33,    12,    13,    14,   123,
       6,     7,    15,     4,    17,    18,    19,    20,    21,    24,
      21,    28,   103,    26,    27,    21,    26,    23,    21,    29,
      33,    34,   117,   118,   115,    21,    32,    21,   119,   120,
       3,     4,     5,    33,    22,   130,   131,    25,    33,    12,
      13,    14,    15,    17,    17,    18,    19,    20,    21,    24,
      22,    22,    22,    26,    27,     3,     4,     5,    21,    24,
      33,    34,    35,    22,    32,    16,    25,    15,    22,    17,
      18,    19,    20,    21,    60,    22,    33,    12,    26,    27,
       3,     4,     5,    -1,    51,    33,    34,    35,     6,    -1,
      -1,    -1,    15,    -1,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,     3,     4,     5,    -1,    -1,
      33,    34,    35,    -1,    12,    13,    14,    15,    -1,    17,
      18,    19,    20,    21,     3,     4,     5,    -1,    26,    27,
      -1,    -1,     3,     4,     5,    33,    34,    -1,    -1,     3,
       4,     5,    21,     3,     4,     5,    -1,    26,    27,    -1,
      21,    22,    -1,    -1,    33,    26,    27,    21,    -1,    -1,
      -1,    21,    26,    27,    -1,    -1,    26,    27,     8,     9,
      10,    11,    77,    78,    79,    80,    -1,    -1,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,
      30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    14,    44,    46,    58,    59,    60,     3,
      28,    45,    47,     0,    59,    23,     3,    25,    33,    21,
      34,    51,     4,    47,    22,    46,    48,    49,     3,     4,
       5,    15,    17,    18,    19,    20,    21,    26,    27,    33,
      35,    37,    39,    40,    41,    42,    43,    44,    46,    50,
      51,    52,    53,    54,    55,    56,    57,    24,    47,    22,
      25,     6,     7,    21,    23,    32,    21,    21,    33,    43,
      21,    50,    43,     3,    39,    39,    28,     8,     9,    10,
      11,    26,    29,    30,    31,    33,    47,    44,    53,    35,
      50,    49,    22,    38,    43,    43,    42,    43,    43,    33,
      54,    17,    22,    23,    39,    41,    41,    41,    41,    40,
      40,    41,    41,    35,    22,    25,    24,    22,    22,    54,
      21,    43,    43,    32,    50,    50,    43,    43,    24,    42,
      16,    22,    22,    50,    50,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    38,    38,    39,    39,    39,    40,    40,    41,    41,
      41,    42,    42,    42,    42,    42,    42,    42,    43,    43,
      43,    44,    45,    45,    46,    46,    46,    47,    47,    47,
      47,    47,    48,    48,    49,    50,    50,    50,    50,    50,
      51,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    56,    57,    57,    58,    58,    59,    59,
      60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     4,     2,     2,
       4,     1,     3,     1,     2,     2,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     6,
       1,     3,     1,     3,     1,     1,     1,     1,     2,     4,
       4,     3,     1,     3,     2,     1,     1,     1,     1,     1,
       2,     3,     4,     1,     2,     1,     2,     1,     2,     5,
       7,     5,     7,     7,     2,     3,     1,     2,     1,     1,
       3
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
#line 65 "parser.y" /* yacc.c:1646  */
    {(yyval.t).code = new std::string("pushq %%rbp\n");vec.push_back((yyval.t).code); (yyval.t).addre = (yyvsp[0].t).addre;}
#line 1372 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 66 "parser.y" /* yacc.c:1646  */
    {std::stringstream s; s << "pushq $" << (yyvsp[0].n) << "\n";(yyval.t).code = new std::string(s.str());vec.push_back((yyval.t).code);}
#line 1378 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 67 "parser.y" /* yacc.c:1646  */
    {std::stringstream s; s << "pushq $" << (yyvsp[0].f) << "\n";(yyval.t).code = new std::string(s.str());vec.push_back((yyval.t).code);}
#line 1384 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 68 "parser.y" /* yacc.c:1646  */
    {(yyval.t).element_type = (yyvsp[-1].t).element_type;}
#line 1390 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 69 "parser.y" /* yacc.c:1646  */
    {(yyval.t).element_type = (yyvsp[-2].t).element_type; (yyval.t).addre = (yyvsp[-2].t).addre;}
#line 1396 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 70 "parser.y" /* yacc.c:1646  */
    {(yyval.t).element_type = (yyvsp[-3].t).element_type; (yyval.t).addre = (yyvsp[-3].t).addre;}
#line 1402 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 71 "parser.y" /* yacc.c:1646  */
    {
 (yyval.t).element_type = (yyvsp[-1].t).element_type;
 std::stringstream s;
 s << "addq $1 " << -(yyvsp[-1].t).addre << "(%%rbp)\npushq " << -(yyvsp[-1].t).addre << "(%%rbp)\n";
 (yyval.t).code = new std::string(s.str());
 vec.push_back((yyval.t).code);
 (yyval.t).addre = (yyvsp[-1].t).addre;
 }
#line 1415 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 79 "parser.y" /* yacc.c:1646  */
    {
 (yyval.t).element_type = (yyvsp[-1].t).element_type;
 std::stringstream s;
 s << "subq $1 " << -(yyvsp[-1].t).addre << "(%%rbp)\npushq " << -(yyvsp[-1].t).addre << "(%%rbp)\n";
 (yyval.t).code = new std::string(s.str());
 vec.push_back((yyval.t).code);
 (yyval.t).addre = (yyvsp[-1].t).addre;
}
#line 1428 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 87 "parser.y" /* yacc.c:1646  */
    {
(yyval.t).element_type = (yyvsp[-3].t).element_type; 
if((yyvsp[-3].t).element_type == INT_T) {
std::stringstream s;
s << "popq %%rax\nmovq " << -(yyvsp[-3].t).addre << "(%%rbp, %%rax, 8), %%rax\npushq %%rax\n";
(yyval.t).code = new std::string(s.str());
vec.push_back((yyval.t).code);
}
}
#line 1442 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 104 "parser.y" /* yacc.c:1646  */
    {if ((yyvsp[0].t).element_type == INT_T)
     (yyval.t).element_type = INT_T;
     //$$.no =  $1.no;
     else if ((yyvsp[0].t).element_type == FLOAT_T)
       (yyval.t).element_type = FLOAT_T;
       //$$.fo = $1.fo;
   (yyval.t).addre = (yyvsp[0].t).addre;
 }
#line 1455 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 112 "parser.y" /* yacc.c:1646  */
    {if ((yyvsp[0].t).element_type == INT_T)
      { (yyval.t).element_type = INT_T;
		(yyval.t).code = new std::string("popq %%rax\nneg %%rax\npushq %%rax\n");
		vec.push_back((yyval.t).code);
      }
      //$$.no = - $2.no;
     else if ((yyvsp[0].t).element_type == FLOAT_T)
       (yyval.t).element_type = FLOAT_T;
       //$$.fo = - $2.fo;
   (yyval.t).addre = (yyvsp[0].t).addre;
  }
#line 1471 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 123 "parser.y" /* yacc.c:1646  */
    {if ((yyvsp[0].t).element_type == INT_T)
		{   
		  (yyval.t).element_type = INT_T;
		  std::stringstream s;
		  s << "popq %%rax\ncmpq $0, %%rax\njne L" << nlabel << "\npushq $1\njmp L" << (nlabel+1) << "\n.L" << nlabel << ":\npushq $0\n.L"<<(nlabel+1)<<":\n";
		  (yyval.t).code = new std::string(s.str());
		  vec.push_back((yyval.t).code); 
		  nlabel += 2;
		 }
     else if ((yyvsp[0].t).element_type == FLOAT_T)
       (yyval.t).element_type = FLOAT_T;
       //$$.fo = (! $2.fo);
   (yyval.t).addre = (yyvsp[0].t).addre;
  }
#line 1490 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 140 "parser.y" /* yacc.c:1646  */
    {if ((yyvsp[0].t).element_type == INT_T)
     (yyval.t).element_type = INT_T;
     //$$.no =  $1.no;
     else if ((yyvsp[0].t).element_type == FLOAT_T)
       (yyval.t).element_type = FLOAT_T;
       //$$.fo = $1.fo;
   (yyval.t).addre = (yyvsp[0].t).addre;
 }
#line 1503 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 148 "parser.y" /* yacc.c:1646  */
    {if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == INT_T)) 
      {
	  (yyval.t).element_type = INT_T;
	  (yyval.t).code = new std::string("popq %%rax\npopq %%rbx\nimul %%rbx, %%rax\npushq %%rax\n");
	  vec.push_back((yyval.t).code);
      }
      // $$.no = $1.no + $3.no;
   else if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     {
     (yyval.t).element_type = FLOAT_T;
     (yyval.t).code = new std::string("popq %%rax\npopq %%rbx\nfmul %%rbx, %%rax\npushq %%rax\n");
	 vec.push_back((yyval.t).code);  // On doit convertir le int en float avant
     }
       // $$.fo = $1.no + $3.fo;
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == INT_T))
     {
     (yyval.t).element_type = FLOAT_T;
     (yyval.t).code = new std::string("popq %%rax\npopq %%rbx\nfmul %%rbx, %%rax\npushq %%rax\n");
	 vec.push_back((yyval.t).code);   // On doit convertir le int en float avant
     }
     // $$.fo = $1.fo + $3.no;
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     {
     (yyval.t).element_type = FLOAT_T;
     (yyval.t).code = new std::string("popq %%rax\npopq %%rbx\nfmul %%rbx, %%rax\npushq %%rax\n");
	 vec.push_back((yyval.t).code);   // On doit convertir le int en float avant
     }
}
#line 1536 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 179 "parser.y" /* yacc.c:1646  */
    {if ((yyvsp[0].t).element_type == INT_T)
     (yyval.t).element_type = INT_T;
     //$$.no =  $1.no;
     else if ((yyvsp[0].t).element_type == FLOAT_T)
       (yyval.t).element_type = FLOAT_T;
       //$$.fo = $1.fo;
   (yyval.t).addre = (yyvsp[0].t).addre;
       }
#line 1549 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 187 "parser.y" /* yacc.c:1646  */
    {if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == INT_T))
      {
		(yyval.t).element_type = INT_T;
		(yyval.t).code = new std::string("popq %%rax\npopq %%rbx\naddq %%rbx, %%rax\npushq %%rax\n");
		vec.push_back((yyval.t).code);
      }
      // $$.no = $1.no + $3.no;
   else if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     {
       (yyval.t).element_type = FLOAT_T;
       (yyval.t).code = new std::string("popq %%rax\npopq %%rbx\naddss %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back((yyval.t).code); // On doit convertir le int en float avant
     }
       // $$.fo = $1.no + $3.fo;
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == INT_T))
     {
	   (yyval.t).element_type = FLOAT_T;
       (yyval.t).code = new std::string("popq %%rax\npopq %%rbx\naddq %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back((yyval.t).code); // ici aussi
     }
     // $$.fo = $1.fo + $3.no;
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     {
       (yyval.t).element_type = FLOAT_T;
       (yyval.t).code = new std::string("popq %%rax\npopq %%rbx\naddss %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back((yyval.t).code);
     }
     //$$.fo = $1.fo + $3.fo;
}
#line 1583 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 216 "parser.y" /* yacc.c:1646  */
    {if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == INT_T))
      {
       (yyval.t).element_type = INT_T;
       (yyval.t).code = new std::string("popq %%rax\npopq %%rbx\nsubq %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back((yyval.t).code);
      }
      // $$.no = $1.no - $3.no;
   else if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     {
       (yyval.t).element_type = FLOAT_T;
       (yyval.t).code = new std::string("popq %%rax\npopq %%rbx\nsubq %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back((yyval.t).code); // On doit convertir le int en float avant
       //$$.fo = $1.no - $3.fo;
     }
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == INT_T))
     {
       (yyval.t).element_type = FLOAT_T;
       (yyval.t).code = new std::string("popq %%rax\npopq %%rbx\nsubq %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back((yyval.t).code);  // On doit convertir le int en float avant
       //$$.fo = $1.fo - $3.no;
     }
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     {
       (yyval.t).element_type = FLOAT_T;
       (yyval.t).code = new std::string("popq %%rax\npopq %%rbx\nsubss %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back((yyval.t).code);
     }
     //$$.fo = $1.fo - $3.fo;
}
#line 1617 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 248 "parser.y" /* yacc.c:1646  */
    {if ((yyvsp[0].t).element_type == INT_T)
      {(yyval.t).element_type = INT_T;
      }
     //$$.no =  $1.no;
     else if ((yyvsp[0].t).element_type == FLOAT_T)
       (yyval.t).element_type = FLOAT_T;
       //$$.fo = $1.fo;
   (yyval.t).addre = (yyvsp[0].t).addre;
       }
#line 1631 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 257 "parser.y" /* yacc.c:1646  */
    {if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == INT_T))
      (yyval.t).element_type = INT_T;
      //$$.no = ($1.no < $3.no);
   else if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.fo = ($1.no < $3.fo);
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == INT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.fo = ($1.fo < $3.no);
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.fo = ($1.fo < $3.fo);
}
#line 1649 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 270 "parser.y" /* yacc.c:1646  */
    {if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == INT_T))
      (yyval.t).element_type = INT_T;
      //$$.no = ($1.no > $3.no);
   else if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.fo = ($1.no > $3.fo);
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == INT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.fo = ($1.fo > $3.no);
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.fo = ($1.fo > $3.fo);
}
#line 1667 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 284 "parser.y" /* yacc.c:1646  */
    {if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == INT_T))
    (yyval.t).element_type = INT_T;
    //$$.n = ($1.n >= $3.n);
   else if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.f = ($1.n >= $3.f);
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == INT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.f = ($1.f >= $3.n);
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.f = ($1.f >= $3.f);
}
#line 1685 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 298 "parser.y" /* yacc.c:1646  */
    {if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == INT_T))
    (yyval.t).element_type = INT_T;
    //$$.n = ($1.n <= $3.n);
   else if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.f = ($1.n <= $3.f);
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == INT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.f = ($1.f <= $3.n);
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     // $$.f = ($1.f <= $3.f);
}
#line 1703 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 312 "parser.y" /* yacc.c:1646  */
    {if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == INT_T))
    (yyval.t).element_type = INT_T;
    //$$.n = ($1.n == $3.n);
   else if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.f = ($1.n == $3.f);
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == INT_T))
     (yyval.t).element_type = FLOAT_T;
     // $$.f = ($1.f == $3.n);
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.f = ($1.f == $3.f);
}
#line 1721 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 326 "parser.y" /* yacc.c:1646  */
    {if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == INT_T))
    (yyval.t).element_type = INT_T;
  //$$.n = ($1.n != $3.n);
  else if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
    (yyval.t).element_type = FLOAT_T;
    //$$.f = ($1.n != $3.f);
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == INT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.f = ($1.f != $3.n);
   else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
     (yyval.t).element_type = FLOAT_T;
     //$$.f = ($1.f != $3.f);
}
#line 1739 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 342 "parser.y" /* yacc.c:1646  */
    {if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == INT_T)){
     (yyval.t).element_type = INT_T;
     //($1.n = $3.n);
     std::stringstream s;
	 s << "popq %%rax\nmovl %%rax " << -(yyvsp[-2].t).addre << "(%%rbp)\npushq %%rax\n";
	 (yyval.t).code = new std::string(s.str());
	 vec.push_back((yyval.t).code);
   }
 else if (((yyvsp[-2].t).element_type == INT_T)&&((yyvsp[0].t).element_type == FLOAT_T))
   perror("int = float not allowed");
 else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == INT_T))
   (yyval.t).element_type = FLOAT_T;
   //($1.f = $3.n);
 else if (((yyvsp[-2].t).element_type == FLOAT_T)&&((yyvsp[0].t).element_type == FLOAT_T)){
   (yyval.t).element_type = FLOAT_T;
   //($1.f = $3.f);
   std::stringstream s;
   s << "popq %%rax\nmovl %%rax " << -(yyvsp[-2].t).addre << "(%%rbp)\npushq %%rax\n";
   (yyval.t).code = new std::string(s.str());
   vec.push_back((yyval.t).code);
 }
   (yyval.t).addre = (yyvsp[-2].t).addre;
}
#line 1767 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 366 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-3].t).element_type == INT_T){
    if (((yyvsp[-5].t).element_type == INT_T)&&((yyvsp[-3].t).element_type == INT_T)){
      (yyval.t).element_type = INT_T;
      //($1[$3.n].n = $6.n);
	  std::stringstream s;
	  s << "popq %%rax\npopq %%rbx\nmovq %%rax, " << -(yyvsp[-5].t).addre << "(%%rbp, %%rbx, 8)\npushq %%rax\n";
	  (yyval.t).code = new std::string(s.str());
	  vec.push_back((yyval.t).code);
    }
    else if (((yyvsp[-5].t).element_type == INT_T)&&((yyvsp[-3].t).element_type == FLOAT_T))
      {perror("int[int] = float not allowed"); exit(0);}
    else if (((yyvsp[-5].t).element_type == FLOAT_T)&&((yyvsp[-3].t).element_type == INT_T))
      (yyval.t).element_type = FLOAT_T;
      //($1[$3.n].f = $6.n);
    else if (((yyvsp[-5].t).element_type == FLOAT_T)&&((yyvsp[-3].t).element_type == FLOAT_T))
      (yyval.t).element_type = FLOAT_T;
      //($1[$3.n].f = $6.f);
  }
  else
    {
      perror("expression not an int"); exit(0);
    }
  (yyval.t).addre = (yyvsp[-5].t).addre;
}
#line 1796 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 390 "parser.y" /* yacc.c:1646  */
    {if ((yyvsp[0].t).element_type == INT_T)
      (yyval.t).element_type = INT_T;
      //$$.n =  $1.n;
     else if ((yyvsp[0].t).element_type == FLOAT_T)
       (yyval.t).element_type = FLOAT_T;
       //$$.f = $1.f;
   (yyval.t).addre = (yyvsp[0].t).addre;
}
#line 1809 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 405 "parser.y" /* yacc.c:1646  */
    {(yyval.lt)[0].element_type = (yyvsp[0].t).element_type ; dliste =1;}
#line 1815 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 406 "parser.y" /* yacc.c:1646  */
    {(yyval.lt)[dliste++].element_type = (yyvsp[0].t).element_type;}
#line 1821 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 410 "parser.y" /* yacc.c:1646  */
    {bt = VOID_T;}
#line 1827 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 411 "parser.y" /* yacc.c:1646  */
    {bt = INT_T;}
#line 1833 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 412 "parser.y" /* yacc.c:1646  */
    {bt = FLOAT_T;}
#line 1839 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 416 "parser.y" /* yacc.c:1646  */
    { 
  if (bt != VOID_T){ 
      addr += 8; (yyvsp[0].t).addre += addr;
  }
  (yyval.t).element_type = bt; (yyval.t).kind = -1 ;}
#line 1849 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 421 "parser.y" /* yacc.c:1646  */
    { 
  if(bt == VOID_T)
 {
     perror("void* not allowed"); exit(0);
 } 
  else
    {
      addr += 8;
      (yyvsp[0].t).addre += addr;
      (yyval.t).element_type = (type)(bt+1); 
      (yyval.t).kind = -1;
    }
}
#line 1867 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 434 "parser.y" /* yacc.c:1646  */
    {(yyval.t).element_type = bt; (yyval.t).kind = 0;
   (yyval.t).element_size = (yyvsp[-1].n); addr += 8*(yyvsp[-1].n) ; (yyval.t).addre = addr;}
#line 1874 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 436 "parser.y" /* yacc.c:1646  */
    {addr = 0;(yyval.t).element_type = bt; (yyval.t).kind = 1; 
(yyval.t).element_size = nliste; (yyval.t).function_parameters = (yyvsp[-1].lt);}
#line 1881 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 438 "parser.y" /* yacc.c:1646  */
    {
	addr = 0;
	(yyval.t).element_type = bt;
	(yyval.t).kind = 1;
	(yyval.t).element_size = 0;	
	std::stringstream s;
	s << "main:\n.LFB" << nfunc << ":\n.cfi_startproc\npushq	%%rbp\n";
	s << ".cfi_def_cfa_offset 16\n.cfi_offset 6, -16\nmovq	%%rsp, %%rbp\n.cfi_def_cfa_register 6\n";
	(yyval.t).code = new std::string(s.str());
	vec.push_back((yyval.t).code);
 }
#line 1897 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 452 "parser.y" /* yacc.c:1646  */
    {(yyval.lt)[0] = (yyvsp[0].t); nliste=1;}
#line 1903 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 453 "parser.y" /* yacc.c:1646  */
    {(yyval.lt)[nliste++] = (yyvsp[0].t);}
#line 1909 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 457 "parser.y" /* yacc.c:1646  */
    {(yyval.t) = (yyvsp[0].t);}
#line 1915 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 475 "parser.y" /* yacc.c:1646  */
    {(yyval.lt)[0] = (yyvsp[0].t); pliste = 1;}
#line 1921 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 476 "parser.y" /* yacc.c:1646  */
    {(yyval.lt)[pliste++] = (yyvsp[0].t);}
#line 1927 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 480 "parser.y" /* yacc.c:1646  */
    {(yyval.lt)[0] = (yyvsp[0].t); sliste = 1;}
#line 1933 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 481 "parser.y" /* yacc.c:1646  */
    {(yyval.lt)[pliste++] = (yyvsp[0].t);}
#line 1939 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 486 "parser.y" /* yacc.c:1646  */
    {
 (yyval.t).element_type = (yyvsp[-1].t).element_type;
 (yyval.t).code = new std::string("popq %%rax\n");
 vec.push_back((yyval.t).code);
 }
#line 1949 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 494 "parser.y" /* yacc.c:1646  */
    {}
#line 1955 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 505 "parser.y" /* yacc.c:1646  */
    {
 std::string s("movl $1, -8(%%rbp)\n");
 (yyval.t).code = new std::string(s);
 vec.push_back((yyval.t).code);
}
#line 1965 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 510 "parser.y" /* yacc.c:1646  */
    {
 std::stringstream s;
 s << "popq %%rax\nmovl %%rax, " << -(yyvsp[-1].t).addre << "(%%rbp)\n";
 (yyval.t).code = new std::string(s.str());
 vec.push_back((yyval.t).code);
}
#line 1976 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 529 "parser.y" /* yacc.c:1646  */
    {
 std::stringstream s;
 s << ".cfi_def_cfa 7, 8\nret\n.cfi_endproc\n.LFE" << nfunc << ":\n";
 (yyval.t).code = new std::string(s.str());
 vec.push_back((yyval.t).code);
 nfunc++;
 }
#line 1988 "parser.c" /* yacc.c:1646  */
    break;


#line 1992 "parser.c" /* yacc.c:1646  */
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
#line 538 "parser.y" /* yacc.c:1906  */

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
