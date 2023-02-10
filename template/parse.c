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
#line 24 "parse.y"


#include <sys/queue.h>

#include <ctype.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include "got_compat.h"

#ifndef nitems
#define nitems(_a) (sizeof((_a)) / sizeof((_a)[0]))
#endif

TAILQ_HEAD(files, file)		 files = TAILQ_HEAD_INITIALIZER(files);
static struct file {
	TAILQ_ENTRY(file)	 entry;
	FILE			*stream;
	char			*name;
	size_t			 ungetpos;
	size_t			 ungetsize;
	unsigned char		*ungetbuf;
	int			 eof_reached;
	int			 lineno;
	int			 errors;
} *file, *topfile;
int		 parse(FILE *, const char *);
struct file	*pushfile(const char *, int);
int		 popfile(void);
int		 yyparse(void);
int		 yylex(void);
int		 yyerror(const char *, ...)
    __attribute__((__format__ (printf, 1, 2)))
    __attribute__((__nonnull__ (1)));
int		 kw_cmp(const void *, const void *);
int		 lookup(char *);
int		 igetc(void);
int		 lgetc(int);
void		 lungetc(int);
int		 findeol(void);

void		 dbg(void);
void		 printq(const char *);

extern int	 nodebug;

static FILE	*fp;

static int	 block;
static int	 in_define;
static int	 errors;
static int	 lastline = -1;

typedef struct {
	union {
		char		*string;
	} v;
	int lineno;
} YYSTYPE;


#line 138 "parse.c"

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
    DEFINE = 258,                  /* DEFINE  */
    ELSE = 259,                    /* ELSE  */
    END = 260,                     /* END  */
    ERROR = 261,                   /* ERROR  */
    FINALLY = 262,                 /* FINALLY  */
    FOR = 263,                     /* FOR  */
    IF = 264,                      /* IF  */
    INCLUDE = 265,                 /* INCLUDE  */
    PRINTF = 266,                  /* PRINTF  */
    RENDER = 267,                  /* RENDER  */
    TQFOREACH = 268,               /* TQFOREACH  */
    UNSAFE = 269,                  /* UNSAFE  */
    URLESCAPE = 270,               /* URLESCAPE  */
    WHILE = 271,                   /* WHILE  */
    STRING = 272                   /* STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DEFINE 258
#define ELSE 259
#define END 260
#define ERROR 261
#define FINALLY 262
#define FOR 263
#define IF 264
#define INCLUDE 265
#define PRINTF 266
#define RENDER 267
#define TQFOREACH 268
#define UNSAFE 269
#define URLESCAPE 270
#define WHILE 271
#define STRING 272

/* Value type.  */


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEFINE = 3,                     /* DEFINE  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_END = 5,                        /* END  */
  YYSYMBOL_ERROR = 6,                      /* ERROR  */
  YYSYMBOL_FINALLY = 7,                    /* FINALLY  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_INCLUDE = 10,                   /* INCLUDE  */
  YYSYMBOL_PRINTF = 11,                    /* PRINTF  */
  YYSYMBOL_RENDER = 12,                    /* RENDER  */
  YYSYMBOL_TQFOREACH = 13,                 /* TQFOREACH  */
  YYSYMBOL_UNSAFE = 14,                    /* UNSAFE  */
  YYSYMBOL_URLESCAPE = 15,                 /* URLESCAPE  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_STRING = 17,                    /* STRING  */
  YYSYMBOL_18_ = 18,                       /* '!'  */
  YYSYMBOL_19_ = 19,                       /* '{'  */
  YYSYMBOL_20_ = 20,                       /* '}'  */
  YYSYMBOL_21_ = 21,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 22,                  /* $accept  */
  YYSYMBOL_grammar = 23,                   /* grammar  */
  YYSYMBOL_include = 24,                   /* include  */
  YYSYMBOL_verbatim = 25,                  /* verbatim  */
  YYSYMBOL_verbatim1 = 26,                 /* verbatim1  */
  YYSYMBOL_verbatims = 27,                 /* verbatims  */
  YYSYMBOL_raw = 28,                       /* raw  */
  YYSYMBOL_block = 29,                     /* block  */
  YYSYMBOL_define = 30,                    /* define  */
  YYSYMBOL_body = 31,                      /* body  */
  YYSYMBOL_special = 32,                   /* special  */
  YYSYMBOL_printf = 33,                    /* printf  */
  YYSYMBOL_34_1 = 34,                      /* $@1  */
  YYSYMBOL_printfargs = 35,                /* printfargs  */
  YYSYMBOL_if = 36,                        /* if  */
  YYSYMBOL_endif = 37,                     /* endif  */
  YYSYMBOL_elsif = 38,                     /* elsif  */
  YYSYMBOL_else = 39,                      /* else  */
  YYSYMBOL_loop = 40,                      /* loop  */
  YYSYMBOL_41_2 = 41,                      /* $@2  */
  YYSYMBOL_42_3 = 42,                      /* $@3  */
  YYSYMBOL_43_4 = 43,                      /* $@4  */
  YYSYMBOL_end = 44,                       /* end  */
  YYSYMBOL_finally = 45,                   /* finally  */
  YYSYMBOL_46_5 = 46,                      /* $@5  */
  YYSYMBOL_string = 47,                    /* string  */
  YYSYMBOL_stringy = 48                    /* stringy  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   95

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  22
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  98

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   272


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
       2,     2,     2,    18,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    19,    21,    20,     2,     2,     2,     2,
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
      15,    16,    17
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    99,    99,   100,   101,   102,   103,   106,   121,   128,
     129,   138,   139,   142,   152,   158,   165,   176,   177,   178,
     179,   182,   188,   189,   190,   191,   199,   207,   217,   217,
     231,   232,   238,   245,   246,   247,   250,   257,   263,   263,
     269,   269,   278,   278,   286,   289,   289,   295,   301,   304,
     305,   311
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
  "\"end of file\"", "error", "\"invalid token\"", "DEFINE", "ELSE",
  "END", "ERROR", "FINALLY", "FOR", "IF", "INCLUDE", "PRINTF", "RENDER",
  "TQFOREACH", "UNSAFE", "URLESCAPE", "WHILE", "STRING", "'!'", "'{'",
  "'}'", "'|'", "$accept", "grammar", "include", "verbatim", "verbatim1",
  "verbatims", "raw", "block", "define", "body", "special", "printf",
  "$@1", "printfargs", "if", "endif", "elsif", "else", "loop", "$@2",
  "$@3", "$@4", "end", "finally", "$@5", "string", "stringy", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -31,     9,   -31,   -31,   -12,   -31,    15,   -31,   -31,   -31,
     -31,   -31,    12,     4,    -6,   -31,   -31,     4,    17,   -31,
      49,   -31,   -31,   -31,   -31,   -31,   -31,   -31,    34,   -31,
     -31,    43,    44,     3,     3,   -31,     4,     6,     3,    21,
      28,    65,   -31,   -31,   -31,     3,     3,    51,    52,   -31,
      58,    56,    59,   -31,    53,    27,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,     5,   -31,    69,   -31,    67,
      70,    -3,    28,    31,    73,   -31,   -31,   -31,    74,   -31,
     -31,   -31,     3,   -31,   -31,    72,   -31,   -31,    31,   -31,
      31,    75,   -31,   -31,   -31,   -31,    31,   -31
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     6,     0,     9,     0,     3,     4,     5,
      17,     7,     0,     0,     0,    10,     8,    48,     0,    13,
       0,    18,    19,    20,    22,    17,    24,    14,     0,    47,
      16,     0,     0,     0,     0,    28,     0,     0,     0,     0,
       0,     0,    15,    44,    45,    49,     0,     0,     0,    30,
       0,     0,     0,    27,     0,     0,    23,    17,    17,    33,
      11,    50,    51,    38,    32,     0,    21,     0,    42,     0,
       0,     0,     0,     0,    46,    17,    31,    29,     0,    17,
      25,    26,     0,    37,    35,     0,    34,    12,     0,    40,
       0,     0,    39,    17,    43,    36,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,   -31,     1,   -31,   -31,   -31,   -31,   -31,   -24,
     -31,   -31,   -31,   -31,   -31,    20,   -31,   -31,   -31,   -31,
     -31,   -31,   -14,   -31,   -31,   -10,   -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     7,    21,    12,    74,    22,     9,    10,    14,
      23,    24,    49,    65,    25,    56,    57,    58,    26,    75,
      93,    79,    59,    28,    60,    39,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    40,     8,    18,    48,    11,    82,    29,    52,     2,
       3,    19,     5,    20,    42,    61,    62,    83,    13,     4,
      45,    17,    76,    51,    46,    77,    50,     5,     6,    15,
      16,    71,    31,    72,    73,    33,    34,    30,    35,    36,
      37,    53,    54,    38,    17,    19,     5,    55,    19,     5,
      85,    88,    91,    41,    31,    90,    32,    33,    34,    86,
      35,    36,    37,    43,    44,    38,    17,    69,    70,    96,
      31,    63,    64,    67,    92,    87,    94,    31,    66,    68,
      33,    34,    97,    35,    36,    37,    78,    80,    38,    17,
      81,     5,    84,     0,    89,    95
};

static const yytype_int8 yycheck[] =
{
      14,    25,     1,    13,    34,    17,     9,    17,    38,     0,
       1,    17,    18,    19,    28,    45,    46,    20,     3,    10,
      17,    17,    17,    17,    21,    20,    36,    18,    19,    17,
      18,     4,     5,    57,    58,     8,     9,    20,    11,    12,
      13,    20,    21,    16,    17,    17,    18,    19,    17,    18,
      19,    75,    82,    19,     5,    79,     7,     8,     9,    73,
      11,    12,    13,    20,    20,    16,    17,    14,    15,    93,
       5,    20,    20,    17,    88,    74,    90,     5,    20,    20,
       8,     9,    96,    11,    12,    13,    17,    20,    16,    17,
      20,    18,    72,    -1,    20,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,     0,     1,    10,    18,    19,    24,    25,    29,
      30,    17,    26,     3,    31,    17,    18,    17,    47,    17,
      19,    25,    28,    32,    33,    36,    40,    44,    45,    47,
      20,     5,     7,     8,     9,    11,    12,    13,    16,    47,
      31,    19,    44,    20,    20,    17,    21,    48,    48,    34,
      47,    17,    48,    20,    21,    19,    37,    38,    39,    44,
      46,    48,    48,    20,    20,    35,    20,    17,    20,    14,
      15,     4,    31,    31,    27,    41,    17,    20,    17,    43,
      20,    20,     9,    20,    37,    19,    44,    25,    31,    20,
      31,    48,    44,    42,    44,    20,    31,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    22,    23,    23,    23,    23,    23,    24,    25,    26,
      26,    27,    27,    28,    29,    29,    30,    31,    31,    31,
      31,    32,    32,    32,    32,    32,    32,    32,    34,    33,
      35,    35,    36,    37,    37,    37,    38,    39,    41,    40,
      42,    40,    43,    40,    44,    46,    45,    47,    47,    48,
      48,    48
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     3,     0,
       2,     0,     2,     1,     3,     4,     4,     0,     2,     2,
       2,     4,     1,     3,     1,     5,     5,     3,     0,     5,
       0,     2,     4,     1,     3,     3,     5,     3,     0,     7,
       0,     9,     0,     7,     3,     0,     5,     2,     1,     1,
       2,     2
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
  case 6: /* grammar: grammar error  */
#line 103 "parse.y"
                                        { file->errors++; }
#line 1296 "parse.c"
    break;

  case 7: /* include: INCLUDE STRING  */
#line 106 "parse.y"
                                 {
			struct file	*nfile;

			if ((nfile = pushfile((yyvsp[0].v.string), 0)) == NULL) {
				yyerror("failed to include file %s", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));

			file = nfile;
			lungetc('\n');
		}
#line 1314 "parse.c"
    break;

  case 8: /* verbatim: '!' verbatim1 '!'  */
#line 121 "parse.y"
                                    {
			if (in_define) {
				/* TODO: check template status and exit in case */
			}
		}
#line 1324 "parse.c"
    break;

  case 10: /* verbatim1: verbatim1 STRING  */
#line 129 "parse.y"
                                   {
			if (*(yyvsp[0].v.string) != '\0') {
				dbg();
				fprintf(fp, "%s\n", (yyvsp[0].v.string));
			}
			free((yyvsp[0].v.string));
		}
#line 1336 "parse.c"
    break;

  case 13: /* raw: STRING  */
#line 142 "parse.y"
                         {
			dbg();
			fprintf(fp, "if ((tp_ret = tp->tp_puts(tp, ");
			printq((yyvsp[0].v.string));
			fputs(")) == -1) goto err;\n", fp);

			free((yyvsp[0].v.string));
		}
#line 1349 "parse.c"
    break;

  case 14: /* block: define body end  */
#line 152 "parse.y"
                                  {
			fputs("err:\n", fp);
			fputs("return tp_ret;\n", fp);
			fputs("}\n", fp);
			in_define = 0;
		}
#line 1360 "parse.c"
    break;

  case 15: /* block: define body finally end  */
#line 158 "parse.y"
                                          {
			fputs("return tp_ret;\n", fp);
			fputs("}\n", fp);
			in_define = 0;
		}
#line 1370 "parse.c"
    break;

  case 16: /* define: '{' DEFINE string '}'  */
#line 165 "parse.y"
                                        {
			in_define = 1;

			dbg();
			fprintf(fp, "int\n%s\n{\n", (yyvsp[-1].v.string));
			fputs("int tp_ret = 0;\n", fp);

			free((yyvsp[-1].v.string));
		}
#line 1384 "parse.c"
    break;

  case 21: /* special: '{' RENDER string '}'  */
#line 182 "parse.y"
                                        {
			dbg();
			fprintf(fp, "if ((tp_ret = %s) == -1) goto err;\n",
			    (yyvsp[-1].v.string));
			free((yyvsp[-1].v.string));
		}
#line 1395 "parse.c"
    break;

  case 23: /* special: if body endif  */
#line 189 "parse.y"
                                                { fputs("}\n", fp); }
#line 1401 "parse.c"
    break;

  case 25: /* special: '{' string '|' UNSAFE '}'  */
#line 191 "parse.y"
                                            {
			dbg();
			fprintf(fp,
			    "if ((tp_ret = tp->tp_puts(tp, %s)) == -1)\n",
			    (yyvsp[-3].v.string));
			fputs("goto err;\n", fp);
			free((yyvsp[-3].v.string));
		}
#line 1414 "parse.c"
    break;

  case 26: /* special: '{' string '|' URLESCAPE '}'  */
#line 199 "parse.y"
                                               {
			dbg();
			fprintf(fp,
			    "if ((tp_ret = tp_urlescape(tp, %s)) == -1)\n",
			    (yyvsp[-3].v.string));
			fputs("goto err;\n", fp);
			free((yyvsp[-3].v.string));
		}
#line 1427 "parse.c"
    break;

  case 27: /* special: '{' string '}'  */
#line 207 "parse.y"
                                 {
			dbg();
			fprintf(fp,
			    "if ((tp_ret = tp->tp_escape(tp, %s)) == -1)\n",
			    (yyvsp[-1].v.string));
			fputs("goto err;\n", fp);
			free((yyvsp[-1].v.string));
		}
#line 1440 "parse.c"
    break;

  case 28: /* $@1: %empty  */
#line 217 "parse.y"
                             {
			dbg();
			fprintf(fp, "if (asprintf(&tp->tp_tmp, ");
		}
#line 1449 "parse.c"
    break;

  case 29: /* printf: '{' PRINTF $@1 printfargs '}'  */
#line 220 "parse.y"
                                 {
			fputs(") == -1)\n", fp);
			fputs("goto err;\n", fp);
			fputs("if ((tp_ret = tp->tp_escape(tp, tp->tp_tmp)) "
			    "== -1)\n", fp);
			fputs("goto err;\n", fp);
			fputs("free(tp->tp_tmp);\n", fp);
			fputs("tp->tp_tmp = NULL;\n", fp);
		}
#line 1463 "parse.c"
    break;

  case 31: /* printfargs: printfargs STRING  */
#line 232 "parse.y"
                                    {
			fprintf(fp, " %s", (yyvsp[0].v.string));
			free((yyvsp[0].v.string));
		}
#line 1472 "parse.c"
    break;

  case 32: /* if: '{' IF stringy '}'  */
#line 238 "parse.y"
                                     {
			dbg();
			fprintf(fp, "if (%s) {\n", (yyvsp[-1].v.string));
			free((yyvsp[-1].v.string));
		}
#line 1482 "parse.c"
    break;

  case 36: /* elsif: '{' ELSE IF stringy '}'  */
#line 250 "parse.y"
                                          {
			dbg();
			fprintf(fp, "} else if (%s) {\n", (yyvsp[-1].v.string));
			free((yyvsp[-1].v.string));
		}
#line 1492 "parse.c"
    break;

  case 37: /* else: '{' ELSE '}'  */
#line 257 "parse.y"
                               {
			dbg();
			fputs("} else {\n", fp);
		}
#line 1501 "parse.c"
    break;

  case 38: /* $@2: %empty  */
#line 263 "parse.y"
                                      {
			fprintf(fp, "for (%s) {\n", (yyvsp[-1].v.string));
			free((yyvsp[-1].v.string));
		}
#line 1510 "parse.c"
    break;

  case 39: /* loop: '{' FOR stringy '}' $@2 body end  */
#line 266 "parse.y"
                           {
			fputs("}\n", fp);
		}
#line 1518 "parse.c"
    break;

  case 40: /* $@3: %empty  */
#line 269 "parse.y"
                                                         {
			fprintf(fp, "TAILQ_FOREACH(%s, %s, %s) {\n",
			    (yyvsp[-3].v.string), (yyvsp[-2].v.string), (yyvsp[-1].v.string));
			free((yyvsp[-3].v.string));
			free((yyvsp[-2].v.string));
			free((yyvsp[-1].v.string));
		}
#line 1530 "parse.c"
    break;

  case 41: /* loop: '{' TQFOREACH STRING STRING STRING '}' $@3 body end  */
#line 275 "parse.y"
                           {
			fputs("}\n", fp);
		}
#line 1538 "parse.c"
    break;

  case 42: /* $@4: %empty  */
#line 278 "parse.y"
                                        {
			fprintf(fp, "while (%s) {\n", (yyvsp[-1].v.string));
			free((yyvsp[-1].v.string));
		}
#line 1547 "parse.c"
    break;

  case 43: /* loop: '{' WHILE stringy '}' $@4 body end  */
#line 281 "parse.y"
                           {
			fputs("}\n", fp);
		}
#line 1555 "parse.c"
    break;

  case 45: /* $@5: %empty  */
#line 289 "parse.y"
                                  {
			dbg();
			fputs("err:\n", fp);
		}
#line 1564 "parse.c"
    break;

  case 47: /* string: STRING string  */
#line 295 "parse.y"
                                {
			if (asprintf(&(yyval.v.string), "%s %s", (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1)
				err(1, "asprintf");
			free((yyvsp[-1].v.string));
			free((yyvsp[0].v.string));
		}
#line 1575 "parse.c"
    break;

  case 50: /* stringy: STRING stringy  */
#line 305 "parse.y"
                                 {
			if (asprintf(&(yyval.v.string), "%s %s", (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1)
				err(1, "asprintf");
			free((yyvsp[-1].v.string));
			free((yyvsp[0].v.string));
		}
#line 1586 "parse.c"
    break;

  case 51: /* stringy: '|' stringy  */
#line 311 "parse.y"
                              {
			if (asprintf(&(yyval.v.string), "|%s", (yyvsp[0].v.string)) == -1)
				err(1, "asprintf");
			free((yyvsp[0].v.string));
		}
#line 1596 "parse.c"
    break;


#line 1600 "parse.c"

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

#line 318 "parse.y"


struct keywords {
	const char	*k_name;
	int		 k_val;
};

int
yyerror(const char *fmt, ...)
{
	va_list	 ap;
	char	*msg;

	file->errors++;
	va_start(ap, fmt);
	if (vasprintf(&msg, fmt, ap) == -1)
		err(1, "yyerror vasprintf");
	va_end(ap);
	fprintf(stderr, "%s:%d: %s\n", file->name, yylval.lineno, msg);
	free(msg);
	return (0);
}

int
kw_cmp(const void *k, const void *e)
{
	return (strcmp(k, ((const struct keywords *)e)->k_name));
}

int
lookup(char *s)
{
	/* this has to be sorted always */
	static const struct keywords keywords[] = {
		{ "define",		DEFINE },
		{ "else",		ELSE },
		{ "end",		END },
		{ "finally",		FINALLY },
		{ "for",		FOR },
		{ "if",			IF },
		{ "include",		INCLUDE },
		{ "printf",		PRINTF },
		{ "render",		RENDER },
		{ "tailq-foreach",	TQFOREACH },
		{ "unsafe",		UNSAFE },
		{ "urlescape",		URLESCAPE },
		{ "while",		WHILE },
	};
	const struct keywords	*p;

	p = bsearch(s, keywords, nitems(keywords), sizeof(keywords[0]),
	    kw_cmp);

	if (p)
		return (p->k_val);
	else
		return (STRING);
}

#define START_EXPAND	1
#define DONE_EXPAND	2

static int	expanding;

int
igetc(void)
{
	int	c;

	while (1) {
		if (file->ungetpos > 0)
			c = file->ungetbuf[--file->ungetpos];
		else
			c = getc(file->stream);

		if (c == START_EXPAND)
			expanding = 1;
		else if (c == DONE_EXPAND)
			expanding = 0;
		else
			break;
	}
	return (c);
}

int
lgetc(int quotec)
{
	int		c;

	if (quotec) {
		if ((c = igetc()) == EOF) {
			yyerror("reached end of filewhile parsing "
			    "quoted string");
			if (file == topfile || popfile() == EOF)
				return (EOF);
			return (quotec);
		}
		return (c);
	}

	c = igetc();
	if (c == '\t' || c == ' ') {
		/* Compress blanks to a sigle space. */
		do {
			c = getc(file->stream);
		} while (c == '\t'  || c == ' ');
		ungetc(c, file->stream);
		c = ' ';
	}

	if (c == EOF) {
		/*
		 * Fake EOL when hit EOF for the first time. This gets line
		 * count rigchtif last line included file is syntactically
		 * invalid and has no newline.
		 */
		if (file->eof_reached == 0) {
			file->eof_reached = 1;
			return ('\n');
		}
		while (c == EOF) {
			if (file == topfile || popfile() == EOF)
				return (EOF);
			c = igetc();
		}
	}
	return (c);
}

void
lungetc(int c)
{
	if (c == EOF)
		return;

	if (file->ungetpos >= file->ungetsize) {
		void *p = reallocarray(file->ungetbuf, file->ungetsize, 2);
		if (p == NULL)
			err(1, "reallocarray");
		file->ungetbuf = p;
		file->ungetsize *= 2;
	}
	file->ungetbuf[file->ungetpos++] = c;
}

int
findeol(void)
{
	int	c;

	/* skip to either EOF or the first real EOL */
	while (1) {
		c = lgetc(0);
		if (c == '\n') {
			file->lineno++;
			break;
		}
		if (c == EOF)
			break;
	}
	return (ERROR);
}

int
yylex(void)
{
	char		 buf[8096];
	char		*p = buf;
	int		 c;
	int		 token;
	int		 starting = 0;
	int		 ending = 0;
	int		 quote = 0;

	if (!in_define && block == 0) {
		while ((c = lgetc(0)) != '{' && c != EOF) {
			if (c == '\n')
				file->lineno++;
		}

		if (c == EOF)
			return (0);

newblock:
		c = lgetc(0);
		if (c == '{' || c == '!') {
			if (c == '{')
				block = '}';
			else
				block = c;
			return (c);
		}
		if (c == '\n')
			file->lineno++;
	}

	while ((c = lgetc(0)) == ' ' || c == '\t' || c == '\n') {
		if (c == '\n')
			file->lineno++;
	}

	if (c == EOF) {
		yyerror("unterminated block");
		return (0);
	}

	yylval.lineno = file->lineno;

	if (block != 0 && c == block) {
		if ((c = lgetc(0)) == '}') {
			if (block == '!') {
				block = 0;
				return ('!');
			}
			block = 0;
			return ('}');
		}
		lungetc(c);
		c = block;
	}

	if (in_define && block == 0) {
		if (c == '{')
			goto newblock;

		do {
			if (starting) {
				if (c == '!' || c == '{') {
					lungetc(c);
					lungetc('{');
					break;
				}
				starting = 0;
				lungetc(c);
				c = '{';
			} else if (c == '{') {
				starting = 1;
				continue;
			}

			*p++ = c;
			if ((size_t)(p - buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && c != '\n');
		*p = '\0';
		if (c == EOF) {
			yyerror("unterminated block");
			return (0);
		}
		if (c == '\n')
			file->lineno++;
		if ((yylval.v.string = strdup(buf)) == NULL)
			err(1, "strdup");
		return (STRING);
	}

	if (block == '!') {
		do {
			if (ending) {
				if (c == '}') {
					lungetc(c);
					lungetc(block);
					break;
				}
				ending = 0;
				lungetc(c);
				c = block;
			} else if (c == '!') {
				ending = 1;
				continue;
			}

			*p++ = c;
			if ((size_t)(p - buf) >= sizeof(buf)) {
				yyerror("line too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && c != '\n');
		*p = '\0';

		if (c == EOF) {
			yyerror("unterminated block");
			return (0);
		}
		if (c == '\n')
			file->lineno++;

		if ((yylval.v.string = strdup(buf)) == NULL)
			err(1, "strdup");
		return (STRING);
	}

	if (c == '|')
		return (c);

	do {
		if (!quote && isspace((unsigned char)c))
			break;

		if (c == '"')
			quote = !quote;

		if (!quote && c == '|') {
			lungetc(c);
			break;
		}

		if (ending) {
			if (c == '}') {
				lungetc(c);
				lungetc('}');
				break;
			}
			ending = 0;
			lungetc(c);
			c = block;
		} else if (!quote && c == '}') {
			ending = 1;
			continue;
		}

		*p++ = c;
		if ((size_t)(p - buf) >= sizeof(buf)) {
			yyerror("string too long");
			return (findeol());
		}
	} while ((c = lgetc(0)) != EOF);
	*p = '\0';

	if (c == EOF) {
		yyerror(quote ? "unterminated quote" : "unterminated block");
		return (0);
	}
	if (c ==  '\n')
		file->lineno++;
	if ((token = lookup(buf)) == STRING)
		if ((yylval.v.string = strdup(buf)) == NULL)
			err(1, "strdup");
	return (token);
}

struct file *
pushfile(const char *name, int secret)
{
	struct file	*nfile;

	if ((nfile = calloc(1, sizeof(*nfile))) == NULL)
		err(1, "calloc");
	if ((nfile->name = strdup(name)) == NULL)
		err(1, "strdup");
	if ((nfile->stream = fopen(nfile->name, "r")) == NULL) {
		warn("can't open %s", nfile->name);
		free(nfile->name);
		free(nfile);
		return (NULL);
	}
	nfile->lineno = TAILQ_EMPTY(&files) ? 1 : 0;
	nfile->ungetsize = 16;
	nfile->ungetbuf = malloc(nfile->ungetsize);
	if (nfile->ungetbuf == NULL)
		err(1, "malloc");
	TAILQ_INSERT_TAIL(&files, nfile, entry);
	return (nfile);
}

int
popfile(void)
{
	struct file	*prev;

	if ((prev = TAILQ_PREV(file, files, entry)) != NULL)
		prev->errors += file->errors;

	TAILQ_REMOVE(&files, file, entry);
	fclose(file->stream);
	free(file->name);
	free(file->ungetbuf);
	free(file);
	file = prev;
	return (file ? 0 : EOF);
}

int
parse(FILE *outfile, const char *filename)
{
	fp = outfile;

	if ((file = pushfile(filename, 0)) == 0)
		return (-1);
	topfile = file;

	yyparse();
	errors = file->errors;
	popfile();

	return (errors ? -1 : 0);
}

void
dbg(void)
{
	if (nodebug)
		return;

	if (yylval.lineno == lastline + 1) {
		lastline = yylval.lineno;
		return;
	}
	lastline = yylval.lineno;

	fprintf(fp, "#line %d ", yylval.lineno);
	printq(file->name);
	putc('\n', fp);
}

void
printq(const char *str)
{
	putc('"', fp);
	for (; *str; ++str) {
		if (*str == '"')
			putc('\\', fp);
		putc(*str, fp);
	}
	putc('"', fp);
}
