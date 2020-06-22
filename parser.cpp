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
#line 4 "sintactico.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <scanner.h>
#include <typeinfo>
#include <MKDISK.h>
#include <RMDISK.h>
#include <FDISK.h>
#include <REP.h>
#include <MOUNT.h>
#include <UNMOUNT.h>
#include <MKFS.h>
#include <LOGIN.h>
#include <LOGOUT.h>
#include <MKGRP.h>
#include <RMGRP.h>
#include <QList>
#include <structs.h>



using namespace std;

extern int yylex(void);
extern char *yytext;
extern  int SourceLine;
extern FILE *yyin;
extern QList<MOUNT_>* mounted = new QList<MOUNT_>();
extern bool loged = false;
Sesion sesion;

MKDISK_* mkdisk_ = new MKDISK_();
RMDISK_* rmdisk_ = new RMDISK_();
FDISK_* fdisk_ = new FDISK_();
REP_* rep_ = new REP_();
MOUNT_* mount_ = new MOUNT_();
UNMOUNT_* unmount_ = new UNMOUNT_();
MKFS_* mkfs_ = new MKFS_();
LOGIN_* login_ = new LOGIN_();
LOGOUT_* logout_ = new LOGOUT_();
MKGRP_* mkgrp_ = new MKGRP_();
RMGRP_* rmgrp_ = new RMGRP_();
void yyerror(const char *s);

string delimiter="------------------------------------------------------------------------------------------------------------------------------------------------------";


#line 117 "parser.cpp" /* yacc.c:339  */

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
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    numero = 258,
    numero_negativo = 259,
    full = 260,
    fast = 261,
    size = 262,
    fit = 263,
    unit = 264,
    path = 265,
    type = 266,
    name = 267,
    delete_o = 268,
    add = 269,
    mkdisk = 270,
    rmdisk = 271,
    fdisk = 272,
    mount = 273,
    unmount = 274,
    exec = 275,
    rep = 276,
    k = 277,
    m = 278,
    bf = 279,
    ff = 280,
    wf = 281,
    b = 282,
    p = 283,
    e = 284,
    l = 285,
    igual = 286,
    cadena_esp = 287,
    id = 288,
    disk = 289,
    ruta = 290,
    guion = 291,
    mbr = 292,
    mkfs = 293,
    login = 294,
    usr = 295,
    pwd = 296,
    logout = 297,
    fname = 298,
    mkgrp = 299,
    rmgrp = 300,
    mkusr = 301,
    grp = 302,
    rmusr = 303,
    chmod = 304,
    mkfile = 305,
    cont = 306,
    cat = 307,
    inode = 308,
    journaling = 309,
    block = 310,
    bm_inode = 311,
    bm_block = 312,
    tree = 313,
    file = 314,
    rem = 315,
    edit = 316,
    ren = 317,
    mkdir = 318,
    cp = 319,
    dest = 320,
    mv = 321,
    find = 322,
    chown_ = 323,
    r = 324,
    chgrp = 325,
    pause_ = 326,
    route = 327,
    sb = 328,
    ls = 329,
    pass = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 170 "sintactico.y" /* yacc.c:355  */

char* STRING;
char* NUM;

#line 238 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 269 "parser.cpp" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   178,   178,   180,   181,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   200,
     203,   204,   207,   208,   209,   210,   211,   212,   213,   214,
     217,   218,   221,   224,   225,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   247,   250,   251,   254,   255,   256,   257,
     260,   261,   264,   265,   268,   271,   272,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   295,   298,   299,   302,   303,
     304,   305,   309,   312,   315,   316,   319,   320,   321,   322,
     323,   324,   325,   326,   329,   332,   333,   336,   337
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "numero", "numero_negativo", "full",
  "fast", "size", "fit", "unit", "path", "type", "name", "delete_o", "add",
  "mkdisk", "rmdisk", "fdisk", "mount", "unmount", "exec", "rep", "k", "m",
  "bf", "ff", "wf", "b", "p", "e", "l", "igual", "cadena_esp", "id",
  "disk", "ruta", "guion", "mbr", "mkfs", "login", "usr", "pwd", "logout",
  "fname", "mkgrp", "rmgrp", "mkusr", "grp", "rmusr", "chmod", "mkfile",
  "cont", "cat", "inode", "journaling", "block", "bm_inode", "bm_block",
  "tree", "file", "rem", "edit", "ren", "mkdir", "cp", "dest", "mv",
  "find", "chown_", "r", "chgrp", "pause_", "route", "sb", "ls", "pass",
  "$accept", "INICIO", "INSTRUCCIONES", "INSTRUCCION", "MKDISK",
  "MKDISKPS", "MKDISKP", "RMDISK", "FDISK", "FDISKPS", "FDISKP", "MOUNT",
  "MOUNTPS", "MOUNTP", "UNMOUNT", "EXEC", "REP", "REPPS", "REPP", "MKFS",
  "MKFSPS", "MKFSP", "PAUSE", "LOGIN", "LOGINPS", "LOGINP", "LOGOUT",
  "MKGRP", "RMGRP", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330
};
# endif

#define YYPACT_NINF -36

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-36)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      36,   -36,   -35,     7,    41,    46,    93,    95,    96,    97,
      98,   -36,    99,   101,   -36,     8,     2,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,    51,   -35,   -36,    18,    83,    41,   -36,    14,    46,
     -36,   -19,   118,    -6,    96,   -36,    -2,    97,   -36,    -8,
     -36,    98,    22,   124,   -36,   -36,   107,   108,   109,   110,
     -36,   112,   113,   114,   115,   116,   117,   119,   120,   121,
     -36,   122,   123,   -36,   125,   126,   127,   128,   129,   130,
     -36,   131,   132,   -36,   133,   134,   135,   -36,   136,   137,
     139,    24,    40,   -22,     3,   146,    45,   -11,     4,    70,
      69,   100,   105,    10,    78,    80,    33,    44,    30,    82,
     -28,   111,    86,    88,    90,    -3,    92,    94,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,     0,     0,    92,     0,     0,     3,     5,     6,
       7,     8,     9,    11,    10,    12,    13,    14,    15,    16,
      17,     0,    19,    21,     0,     0,    32,    33,     0,    53,
      54,     0,     0,     0,    64,    65,     0,    85,    86,     0,
      93,    95,     0,     0,     1,     4,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,    55,     0,     0,     0,     0,     0,     0,
      66,     0,     0,    87,     0,     0,     0,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,    29,    28,    31,    30,    35,    44,
      45,    46,    37,    38,    36,    40,    39,    41,    42,    43,
      50,    49,    48,    47,    51,    52,    57,    56,    59,    58,
      61,    60,    63,    62,    68,    67,    76,    74,    75,    77,
      78,    79,    80,    81,    82,    83,    84,    73,    72,    71,
      69,    70,    90,    91,    89,    88,   103,   102,    97,    96,
      99,   101,   100,    98,   106,   105,   108,   107
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -36,   -36,   -36,   153,   -36,   -36,   138,   -36,   -36,   -36,
     140,   -36,   -36,    91,   -36,   -36,   -36,   -36,   141,   -36,
     -36,   142,   -36,   -36,   104,   -36,   -36,   -36,   -36
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    32,    33,    19,    20,    36,
      37,    21,    39,    40,    22,    23,    24,    44,    45,    25,
      47,    48,    26,    27,    50,    51,    28,    29,    30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     180,    31,    -2,     1,    76,   169,    77,   170,    54,    81,
     124,   132,   133,   125,    74,   171,   134,     2,     3,     4,
       5,     6,     7,     8,    71,    84,    72,    78,    61,   181,
     182,    82,    85,    86,    88,   126,   135,     1,   127,   136,
       9,    10,   146,    34,    11,   147,    12,    13,   119,   120,
     121,     2,     3,     4,     5,     6,     7,     8,    56,    57,
      58,    59,   122,   123,   156,   152,    79,   157,   153,   129,
     130,   131,   183,    14,     9,    10,   154,    35,    11,   155,
      12,    13,    38,   158,   159,   160,   161,   162,   163,   164,
      62,    63,    64,    65,    66,    67,    68,    69,   137,   138,
     139,   140,   141,   165,   166,   142,   143,    14,   144,   145,
     148,   149,   150,   151,   167,   168,   172,   173,   174,   175,
     176,   177,   178,   179,   184,   185,   186,   187,    75,    41,
      73,    42,    43,    46,    49,    52,    89,    53,    90,    91,
      92,    93,   118,    94,    95,    96,    97,    98,    99,   128,
     100,   101,   102,   103,   104,    87,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    55,
      60,     0,     0,     0,     0,     0,    70,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,    83
};

static const yytype_int8 yycheck[] =
{
       3,    36,     0,     1,    10,    33,    12,    35,     0,    11,
      32,    22,    23,    35,    33,    43,    27,    15,    16,    17,
      18,    19,    20,    21,    10,    33,    12,    33,    10,    32,
      33,    33,    40,    41,    12,    32,    32,     1,    35,    35,
      38,    39,    32,    36,    42,    35,    44,    45,    24,    25,
      26,    15,    16,    17,    18,    19,    20,    21,     7,     8,
       9,    10,    22,    23,    34,    32,    72,    37,    35,    24,
      25,    26,    75,    71,    38,    39,    32,    36,    42,    35,
      44,    45,    36,    53,    54,    55,    56,    57,    58,    59,
       7,     8,     9,    10,    11,    12,    13,    14,    28,    29,
      30,    32,    33,    73,    74,     5,     6,    71,     3,     4,
      32,    33,    32,    33,    32,    33,     5,     6,    32,    33,
      32,    33,    32,    33,    32,    33,    32,    33,    10,    36,
      39,    36,    36,    36,    36,    36,    12,    36,    31,    31,
      31,    31,     3,    31,    31,    31,    31,    31,    31,     3,
      31,    31,    31,    31,    31,    51,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    16,
      32,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    15,    16,    17,    18,    19,    20,    21,    38,
      39,    42,    44,    45,    71,    77,    78,    79,    80,    83,
      84,    87,    90,    91,    92,    95,    98,    99,   102,   103,
     104,    36,    81,    82,    36,    36,    85,    86,    36,    88,
      89,    36,    36,    36,    93,    94,    36,    96,    97,    36,
     100,   101,    36,    36,     0,    79,     7,     8,     9,    10,
      82,    10,     7,     8,     9,    10,    11,    12,    13,    14,
      86,    10,    12,    89,    33,    10,    10,    12,    33,    72,
      94,    11,    33,    97,    33,    40,    41,   100,    12,    12,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,     3,    24,
      25,    26,    22,    23,    32,    35,    32,    35,     3,    24,
      25,    26,    22,    23,    27,    32,    35,    28,    29,    30,
      32,    33,     5,     6,     3,     4,    32,    35,    32,    33,
      32,    33,    32,    35,    32,    35,    34,    37,    53,    54,
      55,    56,    57,    58,    59,    73,    74,    32,    33,    33,
      35,    43,     5,     6,    32,    33,    32,    33,    32,    33,
       3,    32,    33,    75,    32,    33,    32,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    84,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    88,    88,    89,    89,    89,    89,
      90,    90,    91,    91,    92,    93,    93,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    96,    96,    97,    97,
      97,    97,    98,    99,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   102,   103,   103,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     5,     2,     1,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     2,     1,     2,     4,     4,     4,     4,
       5,     5,     5,     5,     2,     1,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     1,     2,     4,     4,
       4,     4,     1,     2,     2,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     1,     5,     5,     5,     5
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 18:
#line 197 "sintactico.y" /* yacc.c:1646  */
    {}
#line 1580 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 200 "sintactico.y" /* yacc.c:1646  */
    {mkdisk_->printMk();std::cout << delimiter << std::endl;;mkdisk_ = new MKDISK_();}
#line 1586 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 207 "sintactico.y" /* yacc.c:1646  */
    {mkdisk_->setSize((yyvsp[0].NUM));}
#line 1592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 208 "sintactico.y" /* yacc.c:1646  */
    {mkdisk_->setFit((yyvsp[0].STRING));}
#line 1598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 209 "sintactico.y" /* yacc.c:1646  */
    {mkdisk_->setFit((yyvsp[0].STRING));}
#line 1604 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 210 "sintactico.y" /* yacc.c:1646  */
    {mkdisk_->setFit((yyvsp[0].STRING));}
#line 1610 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 211 "sintactico.y" /* yacc.c:1646  */
    {mkdisk_->setUnit((yyvsp[0].STRING));}
#line 1616 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 212 "sintactico.y" /* yacc.c:1646  */
    {mkdisk_->setUnit((yyvsp[0].STRING));}
#line 1622 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 213 "sintactico.y" /* yacc.c:1646  */
    {mkdisk_->setPath((yyvsp[0].STRING));}
#line 1628 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 214 "sintactico.y" /* yacc.c:1646  */
    {mkdisk_->setPath((yyvsp[0].STRING));}
#line 1634 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 217 "sintactico.y" /* yacc.c:1646  */
    {rmdisk_->setPath((yyvsp[0].STRING));rmdisk_->borrarDisco();std::cout << delimiter << std::endl; rmdisk_ = new RMDISK_();}
#line 1640 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 218 "sintactico.y" /* yacc.c:1646  */
    {rmdisk_->setPath((yyvsp[0].STRING));rmdisk_->borrarDisco();std::cout << delimiter << std::endl; rmdisk_ = new RMDISK_();}
#line 1646 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 221 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->run();std::cout << delimiter << std::endl;fdisk_ = new FDISK_();}
#line 1652 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 227 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setSize((yyvsp[0].NUM));}
#line 1658 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 228 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setUnit((yyvsp[0].STRING));}
#line 1664 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 229 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setUnit((yyvsp[0].STRING));}
#line 1670 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 230 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setUnit((yyvsp[0].STRING));}
#line 1676 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 231 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setPath((yyvsp[0].STRING));}
#line 1682 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 232 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setPath((yyvsp[0].STRING));}
#line 1688 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 233 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setType((yyvsp[0].STRING));}
#line 1694 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 234 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setType((yyvsp[0].STRING));}
#line 1700 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 235 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setType((yyvsp[0].STRING));}
#line 1706 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 236 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setFit((yyvsp[0].STRING));}
#line 1712 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 237 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setFit((yyvsp[0].STRING));}
#line 1718 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 238 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setFit((yyvsp[0].STRING));}
#line 1724 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 239 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setDelete((yyvsp[0].STRING));}
#line 1730 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 240 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setDelete((yyvsp[0].STRING));}
#line 1736 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 241 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setName((yyvsp[0].STRING));}
#line 1742 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 242 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setName((yyvsp[0].STRING));}
#line 1748 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 243 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setAdd((yyvsp[0].NUM));}
#line 1754 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 244 "sintactico.y" /* yacc.c:1646  */
    {fdisk_->setAdd((yyvsp[0].NUM));}
#line 1760 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 247 "sintactico.y" /* yacc.c:1646  */
    {mount_->run();std::cout << delimiter << std::endl;mount_= new MOUNT_();}
#line 1766 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 254 "sintactico.y" /* yacc.c:1646  */
    {mount_->setPath((yyvsp[0].STRING));}
#line 1772 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 255 "sintactico.y" /* yacc.c:1646  */
    {mount_->setPath((yyvsp[0].STRING));}
#line 1778 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 256 "sintactico.y" /* yacc.c:1646  */
    {mount_->setName((yyvsp[0].STRING));}
#line 1784 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 257 "sintactico.y" /* yacc.c:1646  */
    {mount_->setName((yyvsp[0].STRING));}
#line 1790 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 260 "sintactico.y" /* yacc.c:1646  */
    {unmount_->setId((yyvsp[0].STRING));unmount_->run();std::cout << delimiter << std::endl;unmount_= new UNMOUNT_();}
#line 1796 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 261 "sintactico.y" /* yacc.c:1646  */
    {unmount_->setId((yyvsp[0].STRING));unmount_->run();std::cout << delimiter << std::endl;unmount_= new UNMOUNT_();}
#line 1802 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 268 "sintactico.y" /* yacc.c:1646  */
    {rep_->run();std::cout << delimiter << std::endl;rep_ = new REP_();}
#line 1808 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 275 "sintactico.y" /* yacc.c:1646  */
    {rep_->setPath((yyvsp[0].STRING));}
#line 1814 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 276 "sintactico.y" /* yacc.c:1646  */
    {rep_->setPath((yyvsp[0].STRING));}
#line 1820 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 277 "sintactico.y" /* yacc.c:1646  */
    {rep_->setCont((yyvsp[0].STRING));}
#line 1826 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 278 "sintactico.y" /* yacc.c:1646  */
    {rep_->setCont((yyvsp[0].STRING));}
#line 1832 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 279 "sintactico.y" /* yacc.c:1646  */
    {rep_->setCont((yyvsp[0].STRING));}
#line 1838 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 280 "sintactico.y" /* yacc.c:1646  */
    {rep_->setId((yyvsp[0].STRING));}
#line 1844 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 281 "sintactico.y" /* yacc.c:1646  */
    {rep_->setId((yyvsp[0].STRING));}
#line 1850 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 282 "sintactico.y" /* yacc.c:1646  */
    {rep_->setName((yyvsp[0].STRING));}
#line 1856 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 283 "sintactico.y" /* yacc.c:1646  */
    {rep_->setName((yyvsp[0].STRING));}
#line 1862 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 284 "sintactico.y" /* yacc.c:1646  */
    {rep_->setName((yyvsp[0].STRING));}
#line 1868 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 285 "sintactico.y" /* yacc.c:1646  */
    {rep_->setName((yyvsp[0].STRING));}
#line 1874 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 286 "sintactico.y" /* yacc.c:1646  */
    {rep_->setName((yyvsp[0].STRING));}
#line 1880 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 287 "sintactico.y" /* yacc.c:1646  */
    {rep_->setName((yyvsp[0].STRING));}
#line 1886 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 288 "sintactico.y" /* yacc.c:1646  */
    {rep_->setName((yyvsp[0].STRING));}
#line 1892 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 289 "sintactico.y" /* yacc.c:1646  */
    {rep_->setName((yyvsp[0].STRING));}
#line 1898 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 290 "sintactico.y" /* yacc.c:1646  */
    {rep_->setName((yyvsp[0].STRING));}
#line 1904 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 291 "sintactico.y" /* yacc.c:1646  */
    {rep_->setName((yyvsp[0].STRING));}
#line 1910 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 292 "sintactico.y" /* yacc.c:1646  */
    {rep_->setName((yyvsp[0].STRING));}
#line 1916 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 295 "sintactico.y" /* yacc.c:1646  */
    {mkfs_->run();std::cout << delimiter << std::endl; mkfs_ = new MKFS_();}
#line 1922 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 302 "sintactico.y" /* yacc.c:1646  */
    {mkfs_->id=(yyvsp[0].STRING);}
#line 1928 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 303 "sintactico.y" /* yacc.c:1646  */
    {mkfs_->id=(yyvsp[0].STRING);}
#line 1934 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 304 "sintactico.y" /* yacc.c:1646  */
    {mkfs_->type=(yyvsp[0].STRING);}
#line 1940 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 305 "sintactico.y" /* yacc.c:1646  */
    {mkfs_->type=(yyvsp[0].STRING);}
#line 1946 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 309 "sintactico.y" /* yacc.c:1646  */
    {std::string Entrada; std::cout<<"Modo Pausa..."<<std::endl;std::cin>>Entrada;}
#line 1952 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 312 "sintactico.y" /* yacc.c:1646  */
    {login_->run();std::cout << delimiter << std::endl;login_ = new LOGIN_();}
#line 1958 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 319 "sintactico.y" /* yacc.c:1646  */
    {login_->setUsr((yyvsp[0].STRING));}
#line 1964 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 320 "sintactico.y" /* yacc.c:1646  */
    {login_->setUsr((yyvsp[0].STRING));}
#line 1970 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 321 "sintactico.y" /* yacc.c:1646  */
    {login_->setPass((yyvsp[0].STRING));}
#line 1976 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 322 "sintactico.y" /* yacc.c:1646  */
    {login_->setPass((yyvsp[0].NUM));}
#line 1982 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 323 "sintactico.y" /* yacc.c:1646  */
    {login_->setPass((yyvsp[0].STRING));}
#line 1988 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 324 "sintactico.y" /* yacc.c:1646  */
    {login_->setPass((yyvsp[0].STRING));}
#line 1994 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 325 "sintactico.y" /* yacc.c:1646  */
    {login_->setId((yyvsp[0].STRING));}
#line 2000 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 326 "sintactico.y" /* yacc.c:1646  */
    {login_->setId((yyvsp[0].STRING));}
#line 2006 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 329 "sintactico.y" /* yacc.c:1646  */
    {logout_->run();std::cout << delimiter << std::endl;}
#line 2012 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 332 "sintactico.y" /* yacc.c:1646  */
    {mkgrp_->setName((yyvsp[0].STRING));mkgrp_->run();std::cout << delimiter << std::endl;mkgrp_ = new MKGRP_();}
#line 2018 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 333 "sintactico.y" /* yacc.c:1646  */
    {mkgrp_->setName((yyvsp[0].STRING));mkgrp_->run();std::cout << delimiter << std::endl;mkgrp_ = new MKGRP_();}
#line 2024 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 336 "sintactico.y" /* yacc.c:1646  */
    {rmgrp_->setName((yyvsp[0].STRING)); rmgrp_->run(); std::cout << delimiter << std::endl; rmgrp_ = new RMGRP_();}
#line 2030 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 337 "sintactico.y" /* yacc.c:1646  */
    {rmgrp_->setName((yyvsp[0].STRING)); rmgrp_->run(); std::cout << delimiter << std::endl; rmgrp_ = new RMGRP_();}
#line 2036 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2040 "parser.cpp" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 339 "sintactico.y" /* yacc.c:1906  */


void yyerror(const char *s)
{
    printf("Error sintactico en la linea %i: %s\n", SourceLine, s);
    std::cout << delimiter << std::endl;
}
