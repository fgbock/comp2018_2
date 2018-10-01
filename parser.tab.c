/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

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


#include "arvore.h"

int yylex(void);
void yyerror (char const *s);

extern void *arvore;

#define BINARY_EXP(X) $$ = make_node(X); $$->child[0] = $1; $$->child[1] = $3; \


#line 79 "parser.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
    TK_PR_INT = 258,
    TK_PR_FLOAT = 259,
    TK_PR_BOOL = 260,
    TK_PR_CHAR = 261,
    TK_PR_STRING = 262,
    TK_PR_IF = 263,
    TK_PR_THEN = 264,
    TK_PR_ELSE = 265,
    TK_PR_WHILE = 266,
    TK_PR_DO = 267,
    TK_PR_INPUT = 268,
    TK_PR_OUTPUT = 269,
    TK_PR_RETURN = 270,
    TK_PR_CONST = 271,
    TK_PR_STATIC = 272,
    TK_PR_FOREACH = 273,
    TK_PR_FOR = 274,
    TK_PR_SWITCH = 275,
    TK_PR_CASE = 276,
    TK_PR_BREAK = 277,
    TK_PR_CONTINUE = 278,
    TK_PR_CLASS = 279,
    TK_PR_PRIVATE = 280,
    TK_PR_PUBLIC = 281,
    TK_PR_PROTECTED = 282,
    TK_OC_LE = 283,
    TK_OC_GE = 284,
    TK_OC_EQ = 285,
    TK_OC_NE = 286,
    TK_OC_AND = 287,
    TK_OC_OR = 288,
    TK_OC_SL = 289,
    TK_OC_SR = 290,
    TK_OC_FORWARD_PIPE = 291,
    TK_OC_BASH_PIPE = 292,
    TK_LIT_INT = 293,
    TK_LIT_FLOAT = 294,
    TK_LIT_FALSE = 295,
    TK_LIT_TRUE = 296,
    TK_LIT_CHAR = 297,
    TK_LIT_STRING = 298,
    TK_IDENTIFICADOR = 299,
    TOKEN_ERRO = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "parser.y" /* yacc.c:355  */

   ast_node* node;
   int valor_lexico_int;
   int valor_lexico_bool;
   float valor_lexico_float;
   char valor_lexico_char;
   char* valor_lexico_string;

#line 174 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 191 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   924

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  322

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    57,    67,    50,    54,     2,
      58,    59,    48,    46,    66,    47,    70,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    65,
      51,    62,    52,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    55,    69,     2,     2,     2,     2,
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
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    88,    89,    90,    91,    92,    95,    96,
      97,    98,    99,   100,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   114,   115,   116,   117,   118,   119,   120,
     121,   127,   128,   129,   130,   131,   132,   133,   136,   137,
     138,   139,   140,   141,   142,   143,   146,   147,   148,   149,
     150,   151,   152,   153,   156,   157,   158,   159,   160,   163,
     164,   165,   166,   167,   168,   169,   170,   178,   179,   182,
     183,   184,   185,   186,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     221,   224,   225,   227,   228,   229,   230,   231,   233,   234,
     235,   237,   238,   239,   241,   242,   244,   245,   246,   247,
     249,   250,   251,   252,   253,   254,   255,   259,   260,   261,
     262,   265,   266,   267,   268,   269,   270,   274,   275,   276,
     277,   280,   281,   282,   283,   286,   287,   288,   289,   290,
     291,   292,   293,   296,   297,   298,   299,   300
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_STRING", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE",
  "TK_PR_WHILE", "TK_PR_DO", "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN",
  "TK_PR_CONST", "TK_PR_STATIC", "TK_PR_FOREACH", "TK_PR_FOR",
  "TK_PR_SWITCH", "TK_PR_CASE", "TK_PR_BREAK", "TK_PR_CONTINUE",
  "TK_PR_CLASS", "TK_PR_PRIVATE", "TK_PR_PUBLIC", "TK_PR_PROTECTED",
  "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR",
  "TK_OC_SL", "TK_OC_SR", "TK_OC_FORWARD_PIPE", "TK_OC_BASH_PIPE",
  "TK_LIT_INT", "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE",
  "TK_LIT_CHAR", "TK_LIT_STRING", "TK_IDENTIFICADOR", "TOKEN_ERRO", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", "'!'", "'&'", "'|'", "'^'",
  "'#'", "'('", "')'", "':'", "'?'", "'='", "'['", "']'", "';'", "','",
  "'$'", "'{'", "'}'", "'.'", "$accept", "programa", "programa_aux",
  "literal", "opcional_acesso_vetor", "opcional_declaracao_valor",
  "opcional_acesso_propriedade", "acesso_propriedade", "acesso_variavel",
  "tipo_variavel_primitiva", "tipo_variavel_usuario", "tipo_variavel",
  "expressao", "declaracao_novo_tipo", "declaracao_novo_tipo_propriedades",
  "declaracao_novo_tipo_propriedade", "opcional_encapsulamento",
  "declaracao_tamanho", "identificador",
  "declaracao_funcao_usertype_e_var_global", "declaracao_variavel_global",
  "declaracao_funcao", "primeiro_param_funcao", "param_funcao",
  "declaracao_parametro_unico_funcao", "um_comando", "comando_simples",
  "bloco_comandos", "atribuicao",
  "declaracao_variavel_local_ou_atribuicao_ou_shift",
  "declaracao_variavel_local_const", "declaracao_variavel_local_static",
  "declaracao_variavel_local_ou_atribuicao_ou_shift_id",
  "declaracao_variavel_local_ou_atribuicao_id_parametro",
  "declaracao_variavel_local", "input", "output", "lista_expressoes",
  "chamada_funcao", "argumento", "argumento_aux", "comando_return",
  "comando_break", "comando_continue", "comando_case", "comando_if",
  "comando_else_opcional", "comando_switch", "comandos_dentro_for",
  "comandos_dentro_for_aux", "comando_foreach", "comando_for",
  "comando_while", "comando_do_while", "pipe", "optional_pipe_command",
  "comando_pipe", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    43,    45,    42,    47,
      37,    60,    62,    33,    38,   124,    94,    35,    40,    41,
      58,    63,    61,    91,    93,    59,    44,    36,   123,   125,
      46
};
# endif

#define YYPACT_NINF -267

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-267)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     123,  -267,  -267,  -267,  -267,  -267,   155,   -29,  -267,    25,
    -267,   -29,   123,     6,   123,   123,   123,  -267,  -267,   -29,
    -267,   -28,  -267,   -20,  -267,   155,    19,     7,    75,    -5,
    -267,  -267,  -267,    38,    96,   131,    18,    50,  -267,   155,
      53,   131,  -267,   131,  -267,  -267,  -267,    35,   216,   155,
     -29,    66,    65,  -267,  -267,    67,  -267,    74,    80,    96,
      77,   -29,   -29,  -267,    81,   131,  -267,  -267,    81,    81,
      35,    85,  -267,  -267,   324,  -267,    65,  -267,  -267,  -267,
    -267,    84,    93,    81,   863,   863,   863,   182,   150,   111,
     113,   115,   141,  -267,  -267,   126,   -29,    -8,   125,   122,
     127,  -267,  -267,  -267,  -267,  -267,  -267,  -267,   324,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,   863,   863,   184,  -267,
    -267,  -267,  -267,  -267,  -267,   863,   863,   863,   863,   863,
     863,   863,   863,  -267,  -267,   780,   129,  -267,   347,   780,
     -29,   -29,   -29,   -29,   -29,   -29,  -267,  -267,   182,  -267,
    -267,   -29,   -27,   863,   133,   838,   170,   863,   863,   863,
     863,   153,    31,  -267,  -267,   324,  -267,   324,  -267,   542,
     576,   143,   814,   814,   242,   142,   142,   142,   610,  -267,
     863,   863,   863,   863,   863,   863,   863,   863,   863,   863,
     863,   863,   863,   863,   863,   863,   863,   161,   152,   863,
    -267,   170,   170,   170,   170,   170,  -267,  -267,   168,   191,
     174,  -267,  -267,   179,   644,  -267,   185,   392,   189,   169,
    -267,   780,   780,   780,   431,  -267,   863,   863,   863,   863,
    -267,  -267,  -267,   243,   246,   863,  -267,    30,    30,    30,
      30,   109,   109,   814,   814,   242,   242,   242,    30,    30,
     142,   142,   142,   678,  -267,   863,  -267,   347,  -267,  -267,
    -267,  -267,  -267,   863,  -267,   863,   -27,   194,    81,   838,
    -267,  -267,   -16,  -267,  -267,   193,   780,   780,   780,   468,
      81,    81,   712,   863,   505,  -267,   347,   780,   179,   863,
    -267,  -267,  -267,  -267,   219,  -267,  -267,   863,   198,   252,
    -267,  -267,  -267,  -267,   205,  -267,   746,   126,  -267,   780,
     863,    81,  -267,    81,   -27,   780,  -267,  -267,   179,   206,
      81,  -267
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,    23,    24,    26,    25,    27,     0,     0,    68,     0,
       2,     0,     7,     0,     7,     7,     7,    30,    29,     0,
      28,     0,     1,     0,     5,     0,     0,     0,     0,     0,
       3,     4,     6,     0,    63,    77,     0,     0,    73,     0,
       0,    77,    69,    77,    64,    65,    66,    61,     0,     0,
       0,     0,    79,    70,    67,     0,    71,     0,     0,    63,
       0,     0,     0,    82,     0,     0,    78,    72,     0,     0,
      61,     0,    62,    81,    96,    76,    79,    74,    75,    60,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   139,    68,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    89,    96,    91,
      92,    93,    94,    95,    90,    80,     0,     0,     0,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    55,   127,    19,    56,   129,   137,
       0,     0,     0,     0,     0,   120,   105,   108,     0,   106,
     110,     0,     0,     0,     0,   132,    16,     0,     0,     0,
       0,     0,     0,   103,   104,    96,   100,    96,    99,     0,
       0,     0,    31,    32,    35,    33,    34,    36,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
     128,    16,    16,    16,    16,    16,   126,   109,     0,    68,
       0,   146,   145,   147,     0,   140,   135,   135,     0,     0,
     107,   111,   112,   115,     0,    21,     0,     0,     0,     0,
     113,    97,    98,     0,     0,     0,    57,    48,    49,    50,
      51,    52,    53,    38,    39,    40,    41,    42,    46,    47,
      44,    43,    45,     0,    20,     0,    22,   129,   121,   122,
     123,   124,   125,     0,   102,     0,     0,     0,     0,   132,
     134,   133,   155,    18,    17,     0,   118,   119,   117,     0,
       0,     0,     0,     0,     0,   130,   129,   101,   147,     0,
     144,   136,   153,   154,     0,   131,   156,     0,     0,   142,
     151,   152,    58,    15,     0,   148,     0,     0,   157,   114,
       0,     0,   141,     0,     0,   116,   143,   149,   147,     0,
       0,   150
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -267,  -267,   162,    47,  -267,    37,  -267,  -267,  -146,    16,
    -267,    12,   -83,  -267,   199,   217,  -267,  -267,   218,  -267,
    -267,  -267,    46,   201,   213,  -267,   -94,   -64,  -267,  -267,
    -267,  -267,  -267,  -267,   -81,  -267,  -267,  -218,   -50,    13,
      64,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -258,  -266,
    -267,  -267,  -267,  -267,  -267,  -267,  -267
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,   133,   256,   220,   198,   162,   134,    17,
      18,    50,   217,    12,    60,    47,    48,    28,   136,    14,
      15,    16,    51,    66,    52,    98,    99,   100,   212,   101,
     146,   149,   164,   230,   147,   102,   103,   200,   137,   218,
     270,   105,   106,   107,   108,   109,   312,   110,   213,   267,
     111,   112,   113,   114,   294,   295,   296
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      75,   135,   138,   139,    77,    78,   210,   150,   288,     1,
       2,     3,     4,     5,   168,     8,    11,   209,    19,   118,
     292,   293,   305,    25,   104,    22,   157,   158,    11,    27,
      11,    11,    11,   169,   170,    34,     8,    36,    35,   285,
      40,    74,   172,   173,   174,   175,   176,   177,   178,   179,
       8,    55,   319,    41,   159,   160,   318,    37,   104,   161,
      42,    62,   184,   185,    61,   226,   227,   207,   304,    26,
     214,   231,    38,   232,   221,   222,   223,   224,     1,     2,
       3,     4,     5,    53,   193,   194,   195,    57,   211,    58,
      96,   196,    39,   228,   229,    59,    43,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    54,   104,   257,   104,    56,     8,
     210,    44,    45,    46,    96,    64,     1,     2,     3,     4,
       5,    65,    67,    68,     1,     2,     3,     4,     5,    69,
       6,    71,   116,   276,   277,   278,   279,     7,    49,    74,
      80,   117,   282,   140,   141,   142,   143,   144,     1,     2,
       3,     4,     5,   193,   194,   195,   148,     8,   210,   151,
     196,   152,   284,   153,    24,     8,    30,    31,    32,   154,
     286,    96,   287,    96,   155,   140,   141,   142,   143,   144,
     165,   166,   167,   215,     8,   171,   197,   225,   219,     8,
     302,   235,   211,   196,   290,   254,   306,   119,   120,   121,
     122,   123,   124,     8,   309,   255,   299,   300,    13,     1,
       2,     3,     4,     5,    20,    21,     8,   315,   263,    23,
      13,    29,    13,    13,    13,   264,   265,    33,   258,   259,
     260,   261,   262,    20,   308,   266,    20,   316,   272,   317,
     211,   269,   280,    20,   289,   297,   321,    20,   281,    20,
     310,    20,   311,   307,   313,   320,   273,    20,    63,    79,
     180,   181,   182,   183,   184,   185,    70,   115,    76,    72,
      73,   271,   291,    20,     0,     0,     0,     0,     0,     0,
       0,     0,    97,   191,   192,     0,   193,   194,   195,     0,
       0,     0,     0,   196,     0,   145,   145,     0,     0,     0,
       0,     0,     0,     0,   156,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,     1,     2,     3,
       4,     5,    81,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   202,
     203,   204,   205,   206,     0,     0,   145,     0,    95,   208,
       0,     0,     0,     0,     0,   180,   181,   182,   183,   184,
     185,     0,     0,    97,     0,    97,     0,     0,     0,     0,
       0,     0,    74,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,     0,     0,     0,   196,     0,
       0,     0,     0,   199,     0,     0,     0,     0,     0,     0,
     180,   181,   182,   183,   184,   185,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   274,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
       0,     0,     0,   196,     0,     0,     0,     0,   269,   180,
     181,   182,   183,   184,   185,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,     0,
       0,     0,   196,     0,     0,   275,   180,   181,   182,   183,
     184,   185,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,     0,     0,     0,   196,
       0,     0,   298,   180,   181,   182,   183,   184,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,     0,     0,     0,   196,     0,     0,   303,
     180,   181,   182,   183,   184,   185,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
       0,   233,     0,   196,   180,   181,   182,   183,   184,   185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,     0,   234,     0,   196,   180,   181,
     182,   183,   184,   185,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,     0,   236,
       0,   196,   180,   181,   182,   183,   184,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,     0,   268,     0,   196,   180,   181,   182,   183,
     184,   185,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,     0,     0,   283,   196,
     180,   181,   182,   183,   184,   185,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
       0,   301,     0,   196,   180,   181,   182,   183,   184,   185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,     0,     0,   314,   196,   180,   181,
     182,   183,   184,   185,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,     0,     0,
       0,   196,   180,   181,   182,   183,   184,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,     0,     0,     0,   196,   119,   120,   121,   122,
     123,   124,    95,     0,   125,   126,   127,     0,     0,     0,
       0,   128,   129,     0,     0,   130,   131,     0,     0,   132,
       0,   119,   120,   121,   122,   123,   124,    95,   216,   125,
     126,   127,     0,     0,     0,     0,   128,   129,     0,     0,
     130,   131,     0,     0,   132
};

static const yytype_int16 yycheck[] =
{
      64,    84,    85,    86,    68,    69,   152,    88,   266,     3,
       4,     5,     6,     7,   108,    44,     0,    44,     6,    83,
      36,    37,   288,    17,    74,     0,    34,    35,    12,    13,
      14,    15,    16,   116,   117,    63,    44,    25,    58,   257,
      28,    68,   125,   126,   127,   128,   129,   130,   131,   132,
      44,    39,   318,    58,    62,    63,   314,    38,   108,    67,
      65,    49,    32,    33,    48,    34,    35,   148,   286,    63,
     153,   165,    65,   167,   157,   158,   159,   160,     3,     4,
       5,     6,     7,    65,    54,    55,    56,    41,   152,    43,
      74,    61,    17,    62,    63,    60,    58,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    64,   165,   199,   167,    65,    44,
     266,    25,    26,    27,   108,    59,     3,     4,     5,     6,
       7,    66,    65,    59,     3,     4,     5,     6,     7,    59,
      17,    64,    58,   226,   227,   228,   229,    24,    17,    68,
      65,    58,   235,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,    54,    55,    56,    16,    44,   314,    58,
      61,    58,   255,    58,    12,    44,    14,    15,    16,    38,
     263,   165,   265,   167,    58,     3,     4,     5,     6,     7,
      65,    69,    65,    60,    44,    11,    67,    44,    28,    44,
     283,    58,   266,    61,   268,    44,   289,    38,    39,    40,
      41,    42,    43,    44,   297,    63,   280,   281,     0,     3,
       4,     5,     6,     7,     6,     7,    44,   310,    60,    11,
      12,    13,    14,    15,    16,    44,    62,    19,   201,   202,
     203,   204,   205,    25,   294,    66,    28,   311,    59,   313,
     314,    66,     9,    35,    60,    62,   320,    39,    12,    41,
      62,    43,    10,    44,    59,    59,   219,    49,    50,    70,
      28,    29,    30,    31,    32,    33,    59,    76,    65,    61,
      62,   217,   269,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    51,    52,    -1,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,    -1,    -1,   148,    -1,    44,   151,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,   165,    -1,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    64,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    64,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    -1,
      -1,    59,    -1,    61,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    -1,    -1,    59,    -1,    61,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    -1,    -1,    59,
      -1,    61,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    -1,    -1,    59,    -1,    61,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    56,    -1,    -1,    -1,    60,    61,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    -1,
      -1,    59,    -1,    61,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    56,    -1,    -1,    -1,    60,    61,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    54,    -1,    -1,    57,    58,    -1,    -1,    61,
      -1,    38,    39,    40,    41,    42,    43,    44,    70,    46,
      47,    48,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,
      57,    58,    -1,    -1,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    17,    24,    44,    72,
      73,    80,    84,    89,    90,    91,    92,    80,    81,    82,
      89,    89,     0,    89,    73,    17,    63,    80,    88,    89,
      73,    73,    73,    89,    63,    58,    82,    38,    65,    17,
      82,    58,    65,    58,    25,    26,    27,    86,    87,    17,
      82,    93,    95,    65,    64,    82,    65,    93,    93,    60,
      85,    80,    82,    89,    59,    66,    94,    65,    59,    59,
      86,    64,    89,    89,    68,    98,    95,    98,    98,    85,
      65,     8,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    44,    80,    89,    96,    97,
      98,   100,   106,   107,   109,   112,   113,   114,   115,   116,
     118,   121,   122,   123,   124,    94,    58,    58,    98,    38,
      39,    40,    41,    42,    43,    46,    47,    48,    53,    54,
      57,    58,    61,    74,    79,    83,    89,   109,    83,    83,
       3,     4,     5,     6,     7,    89,   101,   105,    16,   102,
     105,    58,    58,    58,    38,    58,    89,    34,    35,    62,
      63,    67,    78,    89,   103,    65,    69,    65,    97,    83,
      83,    11,    83,    83,    83,    83,    83,    83,    83,    83,
      28,    29,    30,    31,    32,    33,    46,    47,    48,    49,
      50,    51,    52,    54,    55,    56,    61,    67,    77,    66,
     108,    89,    89,    89,    89,    89,    89,   105,    89,    44,
      79,    98,    99,   119,    83,    60,    70,    83,   110,    28,
      76,    83,    83,    83,    83,    44,    34,    35,    62,    63,
     104,    97,    97,    59,    59,    58,    59,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    44,    63,    75,    83,    76,    76,
      76,    76,    76,    60,    44,    62,    66,   120,    59,    66,
     111,   111,    59,    74,    89,    64,    83,    83,    83,    83,
       9,    12,    83,    60,    83,   108,    83,    83,   119,    60,
      98,   110,    36,    37,   125,   126,   127,    62,    64,    98,
      98,    59,    83,    64,   108,   120,    83,    44,   109,    83,
      62,    10,   117,    59,    60,    83,    98,    98,   119,   120,
      59,    98
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    73,    73,    73,    74,    74,
      74,    74,    74,    74,    75,    75,    76,    76,    76,    77,
      77,    78,    79,    80,    80,    80,    80,    80,    81,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    84,
      85,    85,    86,    87,    87,    87,    87,    88,    89,    90,
      91,    91,    91,    91,    90,    92,    92,    93,    93,    94,
      94,    95,    95,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    97,    97,    97,
      98,    99,    99,   100,   100,   100,   100,   100,   101,   102,
     102,   103,   103,   103,   103,   103,   104,   104,   104,   104,
     105,   105,   105,   105,   105,   105,   105,   106,   107,   108,
     108,   109,   110,   110,   110,   111,   111,   112,   113,   114,
     115,   116,   117,   117,   118,   119,   119,   120,   120,   121,
     122,   123,   124,   125,   125,   126,   126,   127
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     0,     1,     1,
       1,     1,     1,     1,     0,     3,     0,     2,     2,     0,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     3,     5,     7,
       3,     0,     3,     0,     1,     1,     1,     3,     1,     3,
       4,     4,     5,     3,     6,     7,     6,     0,     2,     0,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     3,     2,
       3,     3,     2,     2,     2,     2,     2,     3,     1,     2,
       1,     2,     2,     2,     5,     2,     5,     2,     2,     2,
       1,     3,     3,     3,     3,     3,     2,     2,     3,     0,
       3,     5,     0,     2,     2,     0,     2,     2,     1,     1,
       3,     7,     0,     2,     5,     1,     1,     0,     3,     8,
      11,     6,     6,     1,     1,     0,     1,     2
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
#line 85 "parser.y" /* yacc.c:1646  */
    { arvore = make_node(NODE_PROGRAM); ((ast_node*)arvore)->child[0] = (yyvsp[0].node); }
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_PROGRAM); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_PROGRAM); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 90 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_PROGRAM); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 91 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_PROGRAM); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 92 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 95 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_INT_LITERAL);    (yyval.node)->int_literal = yylval.valor_lexico_int; }
#line 1671 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 96 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_FLOAT_LITERAL);  (yyval.node)->float_literal = yylval.valor_lexico_float; }
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 97 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_BOOL_LITERAL);   (yyval.node)->bool_literal = 0; }
#line 1683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 98 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_BOOL_LITERAL);   (yyval.node)->bool_literal = 1; }
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_CHAR_LITERAL);   (yyval.node)->char_literal = yylval.valor_lexico_char; }
#line 1695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 100 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_STRING_LITERAL); (yyval.node)->string_literal = strdup(yylval.valor_lexico_string); }
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 103 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EMPTY); }
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 104 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_VECTOR_ACCESS); (yyval.node)->child[0] = (yyvsp[-1].node); }
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 105 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EMPTY); }
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 106 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EMPTY); }
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_PROPERTY_ACCESS); (yyval.node)->string_literal = strdup(yylval.valor_lexico_string); }
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_PROPERTY_ACCESS); (yyval.node)->string_literal = strdup(yylval.valor_lexico_string); }
#line 1749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_VAR_ACCESS); (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[-1].node); (yyval.node)->child[2] = (yyvsp[0].node); }
#line 1755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_INT_TYPE);    }
#line 1761 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_FLOAT_TYPE);  }
#line 1767 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_CHAR_TYPE);   }
#line 1773 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_BOOL_TYPE);   }
#line 1779 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_STRING_TYPE); }
#line 1785 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1791 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1797 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1803 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_POSITIVE);      (yyval.node)->child[0] = (yyvsp[0].node); }
#line 1809 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_MINUS);         (yyval.node)->child[0] = (yyvsp[0].node); }
#line 1815 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_NOT);           (yyval.node)->child[0] = (yyvsp[0].node); }
#line 1821 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_DEREF_POINTER); (yyval.node)->child[0] = (yyvsp[0].node); }
#line 1827 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_DEREF_VALUE);   (yyval.node)->child[0] = (yyvsp[0].node); }
#line 1833 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ACCESS);        (yyval.node)->child[0] = (yyvsp[0].node); }
#line 1839 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_BOOL_EVAL);     (yyval.node)->child[0] = (yyvsp[0].node); }
#line 1845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ADD);         (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_SUB);         (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_MUL);         (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1863 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_DIV);         (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_MOD);         (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_BITWISE_OR);  (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_BITWISE_AND); (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EXP);         (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_LESS);       (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1899 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_GREATER);    (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_LE);         (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_GE);         (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1917 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EQ);         (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1923 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_NE);         (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_AND);        (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1935 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_OR);         (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 1941 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1947 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1953 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1965 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_TERNARY); (yyval.node)->child[0] = (yyvsp[-4].node); (yyval.node)->child[1] = (yyvsp[-2].node); (yyval.node)->child[2] = (yyvsp[0].node); }
#line 1971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 163 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_NEW_TYPE); (yyval.node)->child[0] = make_node(NODE_CLASS); (yyval.node)->child[1] = (yyvsp[-5].node); (yyval.node)->child[2] = (yyvsp[-3].node); (yyval.node)->child[3] = (yyvsp[-2].node);}
#line 1977 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_NEW_TYPE_PROPERTY_LIST); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = (yyvsp[0].node);}
#line 1983 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_EMPTY);}
#line 1989 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_NEW_TYPE_PROPERTY); (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[-1].node); (yyval.node)->child[2] = (yyvsp[0].node);}
#line 1995 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_EMPTY);}
#line 2001 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_PRIVATE);}
#line 2007 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 169 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_PUBLIC);}
#line 2013 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 170 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_PROTECTED);}
#line 2019 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_SIZE);       (yyval.node)->int_literal = yylval.valor_lexico_int; }
#line 2025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_IDENTIFIER); (yyval.node)->string_literal = strdup(yylval.valor_lexico_string); }
#line 2031 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_VAR_GLOBAL); (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[-1].node);                                                                               }
#line 2037 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_VAR_GLOBAL); (yyval.node)->child[0] = (yyvsp[-3].node); (yyval.node)->child[1] = make_node(NODE_STATIC); (yyval.node)->child[2] = (yyvsp[-1].node);                                        }
#line 2043 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_VAR_GLOBAL); (yyval.node)->child[0] = (yyvsp[-3].node); (yyval.node)->child[1] = (yyvsp[-2].node);                     (yyval.node)->child[2] = (yyvsp[-1].node);                                        }
#line 2049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_VAR_GLOBAL); (yyval.node)->child[0] = (yyvsp[-4].node); (yyval.node)->child[1] = (yyvsp[-3].node);                     (yyval.node)->child[2] = make_node(NODE_STATIC); (yyval.node)->child[3] = (yyvsp[-1].node); }
#line 2055 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_VAR_GLOBAL); (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[-1].node);                                                                               }
#line 2061 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_FUNCTION_DEFINITION); (yyval.node)->child[0] = make_node(NODE_EMPTY);  (yyval.node)->child[1] = (yyvsp[-5].node); (yyval.node)->child[2] = (yyvsp[-4].node); (yyval.node)->child[3] = (yyvsp[-2].node); (yyval.node)->child[4] = (yyvsp[0].node); }
#line 2067 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_FUNCTION_DEFINITION); (yyval.node)->child[0] = make_node(NODE_STATIC); (yyval.node)->child[1] = (yyvsp[-5].node); (yyval.node)->child[2] = (yyvsp[-4].node); (yyval.node)->child[3] = (yyvsp[-2].node); (yyval.node)->child[4] = (yyvsp[0].node); }
#line 2073 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_FUNCTION_DEFINITION); (yyval.node)->child[0] = make_node(NODE_EMPTY);  (yyval.node)->child[1] = (yyvsp[-5].node); (yyval.node)->child[2] = (yyvsp[-4].node); (yyval.node)->child[3] = (yyvsp[-2].node); (yyval.node)->child[4] = (yyvsp[0].node); }
#line 2079 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ARGUMENT_LIST); }
#line 2085 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ARGUMENT_LIST); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 2091 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EMPTY); }
#line 2097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ARGUMENT_LIST); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 2103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ARGUMENT); (yyval.node)->child[0] = make_node(NODE_STATIC); (yyval.node)->child[1] = (yyvsp[-1].node); (yyval.node)->child[2] = (yyvsp[0].node); }
#line 2109 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ARGUMENT); (yyval.node)->child[0] = make_node(NODE_EMPTY);  (yyval.node)->child[1] = (yyvsp[-1].node); (yyval.node)->child[2] = (yyvsp[0].node); }
#line 2115 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2121 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2127 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2133 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2139 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2145 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2151 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2157 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2163 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2169 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2175 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2181 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2187 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2193 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EMPTY); }
#line 2199 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_COMMAND_LIST); (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 2205 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_COMMAND_LIST); (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 2211 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); (yyval.node)->child[0] = (yyvsp[0].node); }
#line 2217 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_COMMAND_BLOCK); (yyval.node)->child[0] = (yyvsp[-1].node);  }
#line 2223 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ASSIGNMENT_2); (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 2229 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EMPTY); }
#line 2235 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 227 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_LOCAL_VAR); (yyval.node)->child[1] = (yyvsp[0].node); (yyval.node)->child[0] = (yyvsp[-1].node);}
#line 2241 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); (yyval.node)->child[1] = (yyvsp[-1].node); }
#line 2247 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); (yyval.node)->child[2] = make_node(NODE_CONST);  }
#line 2253 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); (yyval.node)->child[3] = make_node(NODE_STATIC); }
#line 2259 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_LOCAL_VAR); (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[-1].node); (yyval.node)->child[4] = (yyvsp[0].node); }
#line 2265 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2271 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); (yyval.node)->child[2] = make_node(NODE_CONST);  }
#line 2277 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2283 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_SHIFT_LEFT); (yyval.node)->child[3] = (yyvsp[0].node); }
#line 2289 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 238 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_SHIFT_LEFT); (yyval.node)->child[3] = (yyvsp[0].node); }
#line 2295 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); (yyval.node)->child[1] = (yyvsp[-1].node); }
#line 2301 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 241 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ASSIGNMENT); (yyval.node)->child[2] = make_node(NODE_VECTOR_ACCESS); (yyval.node)->child[2]->child[0] = (yyvsp[-3].node); (yyval.node)->child[3] = (yyvsp[0].node); }
#line 2307 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ASSIGNMENT);                                                                            (yyval.node)->child[3] = (yyvsp[0].node); }
#line 2313 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ASSIGNMENT); (yyval.node)->child[2] = make_node(NODE_VECTOR_ACCESS); (yyval.node)->child[2]->child[0] = (yyvsp[-3].node); (yyval.node)->child[3] = (yyvsp[0].node); }
#line 2319 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ASSIGNMENT);                                                                            (yyval.node)->child[3] = (yyvsp[0].node); }
#line 2325 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_SHIFT_LEFT); (yyval.node)->child[3] = (yyvsp[0].node); }
#line 2331 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_SHIFT_RIGHT); (yyval.node)->child[3] = (yyvsp[0].node); }
#line 2337 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_LOCAL_VAR); (yyval.node)->child[0] = (yyvsp[0].node); }
#line 2343 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_LOCAL_VAR); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = make_node(NODE_INT_TYPE);    (yyval.node)->child[4] = (yyvsp[0].node); }
#line 2349 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_LOCAL_VAR); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = make_node(NODE_FLOAT_TYPE);  (yyval.node)->child[4] = (yyvsp[0].node); }
#line 2355 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 252 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_LOCAL_VAR); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = make_node(NODE_BOOL_TYPE);   (yyval.node)->child[4] = (yyvsp[0].node); }
#line 2361 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 253 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_LOCAL_VAR); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = make_node(NODE_CHAR_TYPE);   (yyval.node)->child[4] = (yyvsp[0].node); }
#line 2367 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_LOCAL_VAR); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = make_node(NODE_STRING_TYPE); (yyval.node)->child[4] = (yyvsp[0].node); }
#line 2373 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_LOCAL_VAR); (yyval.node)->child[0] = (yyvsp[0].node); (yyval.node)->child[1] = (yyvsp[-1].node); }
#line 2379 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_INPUT);  (yyval.node)->child[0] = (yyvsp[0].node);                    }
#line 2385 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_OUTPUT); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 2391 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EMPTY);                                        }
#line 2397 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EXPRESSION_LIST); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 2403 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_FUNCTION_CALL);         (yyval.node)->child[0] = make_node(NODE_IDENTIFIER); (yyval.node)->child[1] = (yyvsp[-2].node); (yyval.node)->child[2] = (yyvsp[0].node); }
#line 2409 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EMPTY);}
#line 2415 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 267 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ARGUMENT);         (yyval.node)->child[0] = (yyvsp[-1].node);                                   (yyval.node)->child[1] = (yyvsp[0].node);}
#line 2421 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ARGUMENT);         (yyval.node)->child[0] = make_node(NODE_ARGUMENT_PLACEHOLDER); (yyval.node)->child[0] = (yyvsp[0].node);}
#line 2427 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EMPTY);}
#line 2433 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);}
#line 2439 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_RETURN); (yyval.node)->child[0] = (yyvsp[0].node); }
#line 2445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_BREAK); }
#line 2451 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_CONTINUE); }
#line 2457 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 277 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_CASE); (yyval.node)->int_literal = yylval.valor_lexico_int; }
#line 2463 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 280 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_IF); (yyval.node)->child[0] = (yyvsp[-4].node); (yyval.node)->child[1] = (yyvsp[-1].node); (yyval.node)->child[2] = (yyvsp[0].node); }
#line 2469 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 281 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EMPTY); }
#line 2475 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 282 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_ELSE); (yyval.node)->child[0] = (yyvsp[0].node); }
#line 2481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_SWITCH); (yyval.node)->child[0] = (yyvsp[-2].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 2487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_EMPTY); }
#line 2505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_COMMAND_LIST); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 2511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 290 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_FOREACH); (yyval.node)->child[0] = (yyvsp[-5].node); (yyval.node)->child[1] = (yyvsp[-3].node); (yyval.node)->child[2] = (yyvsp[-2].node); (yyval.node)->child[3] = (yyvsp[0].node);  }
#line 2517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 291 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_FOR); (yyval.node)->child[0] = (yyvsp[-8].node); (yyval.node)->child[1] = (yyvsp[-7].node); (yyval.node)->child[2] = (yyvsp[-5].node); (yyval.node)->child[3] = (yyvsp[-3].node); (yyval.node)->child[4] = (yyvsp[-2].node); (yyval.node)->child[5] = (yyvsp[0].node); }
#line 2523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 292 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_WHILE); (yyval.node)->child[0] = (yyvsp[-3].node); (yyval.node)->child[1] = (yyvsp[0].node); }
#line 2529 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 293 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = make_node(NODE_DO_WHILE);   (yyval.node)->child[0] = (yyvsp[-4].node); (yyval.node)->child[1] = (yyvsp[-1].node); }
#line 2535 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_FORWARD_PIPE); }
#line 2541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 297 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_BASH_PIPE); }
#line 2547 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_EMPTY);}
#line 2553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 299 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2559 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 300 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = make_node(NODE_PIPE_COMMAND); (yyval.node)->child[0] = (yyvsp[-1].node); (yyval.node)->child[1] = (yyvsp[0].node);}
#line 2565 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2569 "parser.tab.c" /* yacc.c:1646  */
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
#line 302 "parser.y" /* yacc.c:1906  */

