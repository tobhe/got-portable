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

#include <sys/types.h>
#include <sys/queue.h>

#include <netdb.h>

#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "got_compat.h"

#include "got_error.h"
#include "gotconfig.h"

static struct file {
	FILE			*stream;
	const char		*name;
	size_t	 		 ungetpos;
	size_t			 ungetsize;
	u_char			*ungetbuf;
	int			 eof_reached;
	int			 lineno;
} *file;
static const struct got_error*	newfile(struct file**, const char *, int *);
static void	closefile(struct file *);
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
static int	 parseport(char *, long long *);

TAILQ_HEAD(symhead, sym)	 symhead = TAILQ_HEAD_INITIALIZER(symhead);
struct sym {
	TAILQ_ENTRY(sym)	 entry;
	int			 used;
	int			 persist;
	char			*nam;
	char			*val;
};

int	 symset(const char *, const char *, int);
int	 cmdline_symset(char *);
char	*symget(const char *);

static int	 atoul(char *, u_long *);

static const struct got_error* gerror;
static struct gotconfig_remote_repo *remote;
static struct gotconfig gotconfig;
static const struct got_error* new_remote(struct gotconfig_remote_repo **);
static const struct got_error* new_fetch_config(struct fetch_config **);
static const struct got_error* new_send_config(struct send_config **);

typedef struct {
	union {
		long long	 number;
		char		*string;
		struct node_branch *branch;
		struct node_ref *ref;
	} v;
	int lineno;
} YYSTYPE;

#if defined(__APPLE__) && !defined(YYSTYPE)
#warning "Setting YYSTYPE - is GNU Bison installed?"
#define YYSTYPE YYSTYPE
#endif

#line 153 "parse.c"

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
    ERROR = 258,                   /* ERROR  */
    REMOTE = 259,                  /* REMOTE  */
    REPOSITORY = 260,              /* REPOSITORY  */
    SERVER = 261,                  /* SERVER  */
    PORT = 262,                    /* PORT  */
    PROTOCOL = 263,                /* PROTOCOL  */
    MIRROR_REFERENCES = 264,       /* MIRROR_REFERENCES  */
    BRANCH = 265,                  /* BRANCH  */
    AUTHOR = 266,                  /* AUTHOR  */
    ALLOWED_SIGNERS = 267,         /* ALLOWED_SIGNERS  */
    REVOKED_SIGNERS = 268,         /* REVOKED_SIGNERS  */
    SIGNER_ID = 269,               /* SIGNER_ID  */
    FETCH_ALL_BRANCHES = 270,      /* FETCH_ALL_BRANCHES  */
    REFERENCE = 271,               /* REFERENCE  */
    FETCH = 272,                   /* FETCH  */
    SEND = 273,                    /* SEND  */
    STRING = 274,                  /* STRING  */
    NUMBER = 275                   /* NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ERROR 258
#define REMOTE 259
#define REPOSITORY 260
#define SERVER 261
#define PORT 262
#define PROTOCOL 263
#define MIRROR_REFERENCES 264
#define BRANCH 265
#define AUTHOR 266
#define ALLOWED_SIGNERS 267
#define REVOKED_SIGNERS 268
#define SIGNER_ID 269
#define FETCH_ALL_BRANCHES 270
#define REFERENCE 271
#define FETCH 272
#define SEND 273
#define STRING 274
#define NUMBER 275

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
  YYSYMBOL_ERROR = 3,                      /* ERROR  */
  YYSYMBOL_REMOTE = 4,                     /* REMOTE  */
  YYSYMBOL_REPOSITORY = 5,                 /* REPOSITORY  */
  YYSYMBOL_SERVER = 6,                     /* SERVER  */
  YYSYMBOL_PORT = 7,                       /* PORT  */
  YYSYMBOL_PROTOCOL = 8,                   /* PROTOCOL  */
  YYSYMBOL_MIRROR_REFERENCES = 9,          /* MIRROR_REFERENCES  */
  YYSYMBOL_BRANCH = 10,                    /* BRANCH  */
  YYSYMBOL_AUTHOR = 11,                    /* AUTHOR  */
  YYSYMBOL_ALLOWED_SIGNERS = 12,           /* ALLOWED_SIGNERS  */
  YYSYMBOL_REVOKED_SIGNERS = 13,           /* REVOKED_SIGNERS  */
  YYSYMBOL_SIGNER_ID = 14,                 /* SIGNER_ID  */
  YYSYMBOL_FETCH_ALL_BRANCHES = 15,        /* FETCH_ALL_BRANCHES  */
  YYSYMBOL_REFERENCE = 16,                 /* REFERENCE  */
  YYSYMBOL_FETCH = 17,                     /* FETCH  */
  YYSYMBOL_SEND = 18,                      /* SEND  */
  YYSYMBOL_STRING = 19,                    /* STRING  */
  YYSYMBOL_NUMBER = 20,                    /* NUMBER  */
  YYSYMBOL_21_n_ = 21,                     /* '\n'  */
  YYSYMBOL_22_ = 22,                       /* '{'  */
  YYSYMBOL_23_ = 23,                       /* '}'  */
  YYSYMBOL_24_ = 24,                       /* ','  */
  YYSYMBOL_YYACCEPT = 25,                  /* $accept  */
  YYSYMBOL_grammar = 26,                   /* grammar  */
  YYSYMBOL_boolean = 27,                   /* boolean  */
  YYSYMBOL_numberstring = 28,              /* numberstring  */
  YYSYMBOL_portplain = 29,                 /* portplain  */
  YYSYMBOL_branch = 30,                    /* branch  */
  YYSYMBOL_xbranch = 31,                   /* xbranch  */
  YYSYMBOL_branch_list = 32,               /* branch_list  */
  YYSYMBOL_ref = 33,                       /* ref  */
  YYSYMBOL_xref = 34,                      /* xref  */
  YYSYMBOL_ref_list = 35,                  /* ref_list  */
  YYSYMBOL_remoteopts2 = 36,               /* remoteopts2  */
  YYSYMBOL_remoteopts1 = 37,               /* remoteopts1  */
  YYSYMBOL_38_1 = 38,                      /* $@1  */
  YYSYMBOL_39_2 = 39,                      /* $@2  */
  YYSYMBOL_fetchempty = 40,                /* fetchempty  */
  YYSYMBOL_fetchopts2 = 41,                /* fetchopts2  */
  YYSYMBOL_fetchopts1 = 42,                /* fetchopts1  */
  YYSYMBOL_sendempty = 43,                 /* sendempty  */
  YYSYMBOL_sendopts2 = 44,                 /* sendopts2  */
  YYSYMBOL_sendopts1 = 45,                 /* sendopts1  */
  YYSYMBOL_remote = 46,                    /* remote  */
  YYSYMBOL_47_3 = 47,                      /* $@3  */
  YYSYMBOL_author = 48,                    /* author  */
  YYSYMBOL_allowed_signers = 49,           /* allowed_signers  */
  YYSYMBOL_revoked_signers = 50,           /* revoked_signers  */
  YYSYMBOL_signer_id = 51,                 /* signer_id  */
  YYSYMBOL_optnl = 52,                     /* optnl  */
  YYSYMBOL_nl = 53,                        /* nl  */
  YYSYMBOL_comma = 54                      /* comma  */
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
#define YYLAST   105

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   275


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
      21,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    24,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    23,     2,     2,     2,     2,
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
static const yytype_int16 yyrline[] =
{
       0,   119,   119,   120,   121,   122,   123,   124,   125,   127,
     142,   150,   152,   160,   161,   162,   164,   174,   175,   181,
     182,   183,   185,   195,   196,   202,   203,   205,   208,   211,
     214,   217,   220,   223,   226,   229,   229,   242,   242,   256,
     257,   259,   260,   262,   265,   268,   271,   274,   278,   279,
     281,   282,   284,   287,   290,   293,   296,   300,   300,   315,
     319,   323,   327,   331,   332,   334,   336,   337
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
  "\"end of file\"", "error", "\"invalid token\"", "ERROR", "REMOTE",
  "REPOSITORY", "SERVER", "PORT", "PROTOCOL", "MIRROR_REFERENCES",
  "BRANCH", "AUTHOR", "ALLOWED_SIGNERS", "REVOKED_SIGNERS", "SIGNER_ID",
  "FETCH_ALL_BRANCHES", "REFERENCE", "FETCH", "SEND", "STRING", "NUMBER",
  "'\\n'", "'{'", "'}'", "','", "$accept", "grammar", "boolean",
  "numberstring", "portplain", "branch", "xbranch", "branch_list", "ref",
  "xref", "ref_list", "remoteopts2", "remoteopts1", "$@1", "$@2",
  "fetchempty", "fetchopts2", "fetchopts1", "sendempty", "sendopts2",
  "sendopts1", "remote", "$@3", "author", "allowed_signers",
  "revoked_signers", "signer_id", "optnl", "nl", "comma", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-102)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -102,     5,  -102,   -18,   -11,     4,    10,    16,  -102,    18,
      22,    24,    35,    36,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,    25,    41,    41,    62,  -102,    44,
      45,     8,    57,    66,    -9,    66,     2,  -102,  -102,    43,
      41,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,    41,  -102,  -102,  -102,  -102,    41,  -102,  -102,    65,
      67,  -102,    69,  -102,    72,    73,    41,    41,    41,  -102,
      41,    14,    41,    31,    26,    76,  -102,  -102,  -102,  -102,
      72,  -102,  -102,    73,    74,    75,     8,    77,    -9,    78,
      26,    41,    79,    80,     8,    81,    -9,    82,    76,    41,
      41,    41,  -102,  -102,  -102,  -102,  -102,  -102,    69,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,    69,  -102,  -102,  -102,
    -102,  -102
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     0,     0,    57,    59,    60,    61,    62,     5,
       4,     6,     7,     8,     0,    64,    64,     0,    63,     0,
       0,     0,     0,     0,    13,     0,    19,    35,    37,     0,
      64,    27,    28,    11,    10,    12,    32,    29,     9,    30,
      16,    64,    33,    14,    31,    22,    64,    34,    20,     0,
       0,    58,     0,    26,     0,     0,    64,    64,    64,    25,
      64,    67,    64,    67,    39,    48,    65,    17,    15,    66,
       0,    23,    21,     0,     0,     0,     0,     0,    13,     0,
      40,    64,     0,     0,     0,     0,    13,     0,    49,    64,
      64,    64,    43,    44,    46,    45,    47,    36,     0,    42,
      52,    53,    55,    54,    56,    38,     0,    51,    18,    24,
      41,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -102,  -102,    53,  -102,   -83,   -84,   -58,  -102,  -102,   -63,
    -102,  -102,    56,  -102,  -102,  -102,  -102,     7,  -102,  -102,
       6,  -102,  -102,  -102,  -102,  -102,  -102,   -26,  -101,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    49,    45,    46,    52,    53,    71,    57,    58,
      73,    39,    40,    59,    60,    89,    90,    91,    97,    98,
      99,     9,    24,    10,    11,    12,    13,    27,    69,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,    14,    72,   104,   106,     2,    70,   120,    15,     3,
      50,   112,   114,    51,    63,   121,     4,     5,     6,     7,
     101,    55,   100,    16,    56,    64,     8,    43,    44,    17,
      65,    84,    85,    86,    87,    18,    88,    78,    79,    19,
      74,    75,    76,    20,    77,    21,    81,    25,    29,    30,
      31,    32,    33,    34,    82,    79,    22,    23,    35,    36,
      37,    38,    26,    41,    42,   109,    61,    29,    30,    31,
      32,    33,    34,   117,   118,   119,    47,    35,    36,    37,
      38,    92,    93,    94,    95,    48,    96,    66,    54,    67,
      68,    50,    55,   102,   103,    62,   105,   108,   110,   111,
     113,   107,    83,     0,   116,   115
};

static const yytype_int8 yycheck[] =
{
      26,    19,    65,    86,    88,     0,    64,   108,    19,     4,
      19,    94,    96,    22,    40,   116,    11,    12,    13,    14,
      83,    19,    80,    19,    22,    51,    21,    19,    20,    19,
      56,     5,     6,     7,     8,    19,    10,    23,    24,    21,
      66,    67,    68,    21,    70,    21,    72,    22,     5,     6,
       7,     8,     9,    10,    23,    24,    21,    21,    15,    16,
      17,    18,    21,    19,    19,    91,    23,     5,     6,     7,
       8,     9,    10,    99,   100,   101,    19,    15,    16,    17,
      18,     5,     6,     7,     8,    19,    10,    22,    35,    22,
      21,    19,    19,    19,    19,    39,    19,    90,    19,    19,
      19,    23,    73,    -1,    98,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,     0,     4,    11,    12,    13,    14,    21,    46,
      48,    49,    50,    51,    19,    19,    19,    19,    19,    21,
      21,    21,    21,    21,    47,    22,    21,    52,    52,     5,
       6,     7,     8,     9,    10,    15,    16,    17,    18,    36,
      37,    19,    19,    19,    20,    28,    29,    19,    19,    27,
      19,    22,    30,    31,    27,    19,    22,    33,    34,    38,
      39,    23,    37,    52,    52,    52,    22,    22,    21,    53,
      31,    32,    34,    35,    52,    52,    52,    52,    23,    24,
      54,    52,    23,    54,     5,     6,     7,     8,    10,    40,
      41,    42,     5,     6,     7,     8,    10,    43,    44,    45,
      31,    34,    19,    19,    29,    19,    30,    23,    42,    52,
      19,    19,    29,    19,    30,    23,    45,    52,    52,    52,
      53,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    25,    26,    26,    26,    26,    26,    26,    26,    27,
      28,    28,    29,    30,    30,    30,    31,    32,    32,    33,
      33,    33,    34,    35,    35,    36,    36,    37,    37,    37,
      37,    37,    37,    37,    37,    38,    37,    39,    37,    40,
      40,    41,    41,    42,    42,    42,    42,    42,    43,    43,
      44,    44,    45,    45,    45,    45,    45,    47,    46,    48,
      49,    50,    51,    52,    52,    53,    54,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     0,     1,     4,     1,     2,     4,     0,
       1,     4,     1,     2,     4,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     0,     6,     0,     6,     0,
       1,     3,     2,     2,     2,     2,     2,     2,     0,     1,
       3,     2,     2,     2,     2,     2,     2,     0,     7,     2,
       2,     2,     2,     2,     0,     2,     1,     0
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
  case 9: /* boolean: STRING  */
#line 127 "parse.y"
                         {
			if (strcasecmp((yyvsp[0].v.string), "true") == 0 ||
			    strcasecmp((yyvsp[0].v.string), "yes") == 0)
				(yyval.v.number) = 1;
			else if (strcasecmp((yyvsp[0].v.string), "false") == 0 ||
			    strcasecmp((yyvsp[0].v.string), "no") == 0)
				(yyval.v.number) = 0;
			else {
				yyerror("invalid boolean value '%s'", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 1353 "parse.c"
    break;

  case 10: /* numberstring: NUMBER  */
#line 142 "parse.y"
                                                        {
			char	*s;
			if (asprintf(&s, "%lld", (yyvsp[0].v.number)) == -1) {
				yyerror("string: asprintf");
				YYERROR;
			}
			(yyval.v.string) = s;
		}
#line 1366 "parse.c"
    break;

  case 12: /* portplain: numberstring  */
#line 152 "parse.y"
                                {
			if (parseport((yyvsp[0].v.string), &(yyval.v.number)) == -1) {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 1378 "parse.c"
    break;

  case 13: /* branch: %empty  */
#line 160 "parse.y"
                                                        { (yyval.v.branch) = NULL; }
#line 1384 "parse.c"
    break;

  case 14: /* branch: xbranch  */
#line 161 "parse.y"
                                                { (yyval.v.branch) = (yyvsp[0].v.branch); }
#line 1390 "parse.c"
    break;

  case 15: /* branch: '{' optnl branch_list '}'  */
#line 162 "parse.y"
                                                { (yyval.v.branch) = (yyvsp[-1].v.branch); }
#line 1396 "parse.c"
    break;

  case 16: /* xbranch: STRING  */
#line 164 "parse.y"
                         {
			(yyval.v.branch) = calloc(1, sizeof(struct node_branch));
			if ((yyval.v.branch) == NULL) {
				yyerror("calloc");
				YYERROR;
			}
			(yyval.v.branch)->branch_name = (yyvsp[0].v.string);
			(yyval.v.branch)->tail = (yyval.v.branch);
		}
#line 1410 "parse.c"
    break;

  case 17: /* branch_list: xbranch optnl  */
#line 174 "parse.y"
                                                { (yyval.v.branch) = (yyvsp[-1].v.branch); }
#line 1416 "parse.c"
    break;

  case 18: /* branch_list: branch_list comma xbranch optnl  */
#line 175 "parse.y"
                                                  {
			(yyvsp[-3].v.branch)->tail->next = (yyvsp[-1].v.branch);
			(yyvsp[-3].v.branch)->tail = (yyvsp[-1].v.branch);
			(yyval.v.branch) = (yyvsp[-3].v.branch);
		}
#line 1426 "parse.c"
    break;

  case 19: /* ref: %empty  */
#line 181 "parse.y"
                                        { (yyval.v.ref) = NULL; }
#line 1432 "parse.c"
    break;

  case 20: /* ref: xref  */
#line 182 "parse.y"
                                        { (yyval.v.ref) = (yyvsp[0].v.ref); }
#line 1438 "parse.c"
    break;

  case 21: /* ref: '{' optnl ref_list '}'  */
#line 183 "parse.y"
                                                { (yyval.v.ref) = (yyvsp[-1].v.ref); }
#line 1444 "parse.c"
    break;

  case 22: /* xref: STRING  */
#line 185 "parse.y"
                         {
			(yyval.v.ref) = calloc(1, sizeof(struct node_ref));
			if ((yyval.v.ref) == NULL) {
				yyerror("calloc");
				YYERROR;
			}
			(yyval.v.ref)->ref_name = (yyvsp[0].v.string);
			(yyval.v.ref)->tail = (yyval.v.ref);
		}
#line 1458 "parse.c"
    break;

  case 23: /* ref_list: xref optnl  */
#line 195 "parse.y"
                                                { (yyval.v.ref) = (yyvsp[-1].v.ref); }
#line 1464 "parse.c"
    break;

  case 24: /* ref_list: ref_list comma xref optnl  */
#line 196 "parse.y"
                                            {
			(yyvsp[-3].v.ref)->tail->next = (yyvsp[-1].v.ref);
			(yyvsp[-3].v.ref)->tail = (yyvsp[-1].v.ref);
			(yyval.v.ref) = (yyvsp[-3].v.ref);
		}
#line 1474 "parse.c"
    break;

  case 27: /* remoteopts1: REPOSITORY STRING  */
#line 205 "parse.y"
                                    {
			remote->repository = (yyvsp[0].v.string);
		}
#line 1482 "parse.c"
    break;

  case 28: /* remoteopts1: SERVER STRING  */
#line 208 "parse.y"
                                {
			remote->server = (yyvsp[0].v.string);
		}
#line 1490 "parse.c"
    break;

  case 29: /* remoteopts1: PROTOCOL STRING  */
#line 211 "parse.y"
                                  {
			remote->protocol = (yyvsp[0].v.string);
		}
#line 1498 "parse.c"
    break;

  case 30: /* remoteopts1: MIRROR_REFERENCES boolean  */
#line 214 "parse.y"
                                            {
			remote->mirror_references = (yyvsp[0].v.number);
		}
#line 1506 "parse.c"
    break;

  case 31: /* remoteopts1: FETCH_ALL_BRANCHES boolean  */
#line 217 "parse.y"
                                             {
			remote->fetch_all_branches = (yyvsp[0].v.number);
		}
#line 1514 "parse.c"
    break;

  case 32: /* remoteopts1: PORT portplain  */
#line 220 "parse.y"
                                 {
			remote->port = (yyvsp[0].v.number);
		}
#line 1522 "parse.c"
    break;

  case 33: /* remoteopts1: BRANCH branch  */
#line 223 "parse.y"
                                {
			remote->branch = (yyvsp[0].v.branch);
		}
#line 1530 "parse.c"
    break;

  case 34: /* remoteopts1: REFERENCE ref  */
#line 226 "parse.y"
                                {
			remote->fetch_ref = (yyvsp[0].v.ref);
		}
#line 1538 "parse.c"
    break;

  case 35: /* $@1: %empty  */
#line 229 "parse.y"
                        {
			static const struct got_error* error;

			if (remote->fetch_config != NULL) {
				yyerror("fetch block already exists");
				YYERROR;
			}
			error = new_fetch_config(&remote->fetch_config);
			if (error) {
				yyerror("%s", error->msg);
				YYERROR;
			}
		}
#line 1556 "parse.c"
    break;

  case 37: /* $@2: %empty  */
#line 242 "parse.y"
                       {
			static const struct got_error* error;

			if (remote->send_config != NULL) {
				yyerror("send block already exists");
				YYERROR;
			}
			error = new_send_config(&remote->send_config);
			if (error) {
				yyerror("%s", error->msg);
				YYERROR;
			}
		}
#line 1574 "parse.c"
    break;

  case 43: /* fetchopts1: REPOSITORY STRING  */
#line 262 "parse.y"
                                    {
			remote->fetch_config->repository = (yyvsp[0].v.string);
		}
#line 1582 "parse.c"
    break;

  case 44: /* fetchopts1: SERVER STRING  */
#line 265 "parse.y"
                                {
			remote->fetch_config->server = (yyvsp[0].v.string);
		}
#line 1590 "parse.c"
    break;

  case 45: /* fetchopts1: PROTOCOL STRING  */
#line 268 "parse.y"
                                  {
			remote->fetch_config->protocol = (yyvsp[0].v.string);
		}
#line 1598 "parse.c"
    break;

  case 46: /* fetchopts1: PORT portplain  */
#line 271 "parse.y"
                                 {
			remote->fetch_config->port = (yyvsp[0].v.number);
		}
#line 1606 "parse.c"
    break;

  case 47: /* fetchopts1: BRANCH branch  */
#line 274 "parse.y"
                                {
			remote->fetch_config->branch = (yyvsp[0].v.branch);
		}
#line 1614 "parse.c"
    break;

  case 52: /* sendopts1: REPOSITORY STRING  */
#line 284 "parse.y"
                                    {
			remote->send_config->repository = (yyvsp[0].v.string);
		}
#line 1622 "parse.c"
    break;

  case 53: /* sendopts1: SERVER STRING  */
#line 287 "parse.y"
                                {
			remote->send_config->server = (yyvsp[0].v.string);
		}
#line 1630 "parse.c"
    break;

  case 54: /* sendopts1: PROTOCOL STRING  */
#line 290 "parse.y"
                                  {
			remote->send_config->protocol = (yyvsp[0].v.string);
		}
#line 1638 "parse.c"
    break;

  case 55: /* sendopts1: PORT portplain  */
#line 293 "parse.y"
                                 {
			remote->send_config->port = (yyvsp[0].v.number);
		}
#line 1646 "parse.c"
    break;

  case 56: /* sendopts1: BRANCH branch  */
#line 296 "parse.y"
                                {
			remote->send_config->branch = (yyvsp[0].v.branch);
		}
#line 1654 "parse.c"
    break;

  case 57: /* $@3: %empty  */
#line 300 "parse.y"
                                {
			static const struct got_error* error;

			error = new_remote(&remote);
			if (error) {
				free((yyvsp[0].v.string));
				yyerror("%s", error->msg);
				YYERROR;
			}
			remote->name = (yyvsp[0].v.string);
		}
#line 1670 "parse.c"
    break;

  case 58: /* remote: REMOTE STRING $@3 '{' optnl remoteopts2 '}'  */
#line 310 "parse.y"
                                            {
			TAILQ_INSERT_TAIL(&gotconfig.remotes, remote, entry);
			gotconfig.nremotes++;
		}
#line 1679 "parse.c"
    break;

  case 59: /* author: AUTHOR STRING  */
#line 315 "parse.y"
                                {
			gotconfig.author = (yyvsp[0].v.string);
		}
#line 1687 "parse.c"
    break;

  case 60: /* allowed_signers: ALLOWED_SIGNERS STRING  */
#line 319 "parse.y"
                                         {
			gotconfig.allowed_signers_file = (yyvsp[0].v.string);
		}
#line 1695 "parse.c"
    break;

  case 61: /* revoked_signers: REVOKED_SIGNERS STRING  */
#line 323 "parse.y"
                                         {
			gotconfig.revoked_signers_file = (yyvsp[0].v.string);
		}
#line 1703 "parse.c"
    break;

  case 62: /* signer_id: SIGNER_ID STRING  */
#line 327 "parse.y"
                                   {
			gotconfig.signer_id = (yyvsp[0].v.string);
		}
#line 1711 "parse.c"
    break;


#line 1715 "parse.c"

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

#line 339 "parse.y"


struct keywords {
	const char	*k_name;
	int		 k_val;
};

int
yyerror(const char *fmt, ...)
{
	va_list		 ap;
	char		*msg;
	char		*err = NULL;

	va_start(ap, fmt);
	if (vasprintf(&msg, fmt, ap) == -1) {
		gerror =  got_error_from_errno("vasprintf");
		return 0;
	}
	va_end(ap);
	if (asprintf(&err, "%s: line %d: %s", file->name, yylval.lineno,
	    msg) == -1) {
		gerror = got_error_from_errno("asprintf");
		return(0);
	}
	gerror = got_error_msg(GOT_ERR_PARSE_CONFIG, err);
	free(msg);
	return(0);
}
int
kw_cmp(const void *k, const void *e)
{
	return (strcmp(k, ((const struct keywords *)e)->k_name));
}

int
lookup(char *s)
{
	/* This has to be sorted always. */
	static const struct keywords keywords[] = {
		{"allowed_signers",	ALLOWED_SIGNERS},
		{"author",		AUTHOR},
		{"branch",		BRANCH},
		{"fetch",		FETCH},
		{"fetch-all-branches",	FETCH_ALL_BRANCHES}, /* deprecated */
		{"fetch_all_branches",	FETCH_ALL_BRANCHES},
		{"mirror-references",	MIRROR_REFERENCES}, /* deprecated */
		{"mirror_references",	MIRROR_REFERENCES},
		{"port",		PORT},
		{"protocol",		PROTOCOL},
		{"reference",		REFERENCE},
		{"remote",		REMOTE},
		{"repository",		REPOSITORY},
		{"revoked_signers",	REVOKED_SIGNERS},
		{"send",		SEND},
		{"server",		SERVER},
		{"signer_id",		SIGNER_ID},
	};
	const struct keywords	*p;

	p = bsearch(s, keywords, sizeof(keywords)/sizeof(keywords[0]),
	    sizeof(keywords[0]), kw_cmp);

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
	int		c, next;

	if (quotec) {
		c = igetc();
		if (c == EOF) {
			yyerror("reached end of file while parsing "
			    "quoted string");
		}
		return (c);
	}

	c = igetc();
	while (c == '\\') {
		next = igetc();
		if (next != '\n') {
			c = next;
			break;
		}
		yylval.lineno = file->lineno;
		file->lineno++;
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
			err(1, "%s", __func__);
		file->ungetbuf = p;
		file->ungetsize *= 2;
	}
	file->ungetbuf[file->ungetpos++] = c;
}

int
findeol(void)
{
	int	c;

	/* Skip to either EOF or the first real EOL. */
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

static long long
getservice(char *n)
{
	struct servent	*s;
	u_long		 ulval;

	if (atoul(n, &ulval) == 0) {
		if (ulval == 0 || ulval > 65535) {
			yyerror("illegal port value %lu", ulval);
			return (-1);
		}
		return ulval;
	} else {
		s = getservbyname(n, "tcp");
		if (s == NULL)
			s = getservbyname(n, "udp");
		if (s == NULL) {
			yyerror("unknown port %s", n);
			return (-1);
		}
		return (s->s_port);
	}
}

static int
parseport(char *port, long long *pn)
{
	if ((*pn = getservice(port)) == -1) {
		*pn = 0LL;
		return (-1);
	}
	return (0);
}


int
yylex(void)
{
	char	 buf[8096];
	char	*p, *val;
	int	 quotec, next, c;
	int	 token;

top:
	p = buf;
	c = lgetc(0);
	while (c == ' ' || c == '\t')
		c = lgetc(0); /* nothing */

	yylval.lineno = file->lineno;
	if (c == '#') {
		c = lgetc(0);
		while (c != '\n' && c != EOF)
			c = lgetc(0); /* nothing */
	}
	if (c == '$' && !expanding) {
		while (1) {
			c = lgetc(0);
			if (c == EOF)
				return (0);

			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
			}
			if (isalnum(c) || c == '_') {
				*p++ = c;
				continue;
			}
			*p = '\0';
			lungetc(c);
			break;
		}
		val = symget(buf);
		if (val == NULL) {
			yyerror("macro '%s' not defined", buf);
			return (findeol());
		}
		p = val + strlen(val) - 1;
		lungetc(DONE_EXPAND);
		while (p >= val) {
			lungetc((unsigned char)*p);
			p--;
		}
		lungetc(START_EXPAND);
		goto top;
	}

	switch (c) {
	case '\'':
	case '"':
		quotec = c;
		while (1) {
			c = lgetc(quotec);
			if (c == EOF)
				return (0);
			if (c == '\n') {
				file->lineno++;
				continue;
			} else if (c == '\\') {
				next = lgetc(quotec);
				if (next == EOF)
					return (0);
				if (next == quotec || c == ' ' || c == '\t')
					c = next;
				else if (next == '\n') {
					file->lineno++;
					continue;
				} else
					lungetc(next);
			} else if (c == quotec) {
				*p = '\0';
				break;
			} else if (c == '\0') {
				yyerror("syntax error");
				return (findeol());
			}
			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
			}
			*p++ = c;
		}
		yylval.v.string = strdup(buf);
		if (yylval.v.string == NULL)
			err(1, "%s", __func__);
		return (STRING);
	}

#define allowed_to_end_number(x) \
	(isspace(x) || x == ')' || x ==',' || x == '/' || x == '}' || x == '=')

	if (c == '-' || isdigit(c)) {
		do {
			*p++ = c;
			if ((size_t)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
			c = lgetc(0);
		} while (c != EOF && isdigit(c));
		lungetc(c);
		if (p == buf + 1 && buf[0] == '-')
			goto nodigits;
		if (c == EOF || allowed_to_end_number(c)) {
			const char *errstr = NULL;

			*p = '\0';
			yylval.v.number = strtonum(buf, LLONG_MIN,
			    LLONG_MAX, &errstr);
			if (errstr) {
				yyerror("\"%s\" invalid number: %s",
				    buf, errstr);
				return (findeol());
			}
			return (NUMBER);
		} else {
nodigits:
			while (p > buf + 1)
				lungetc((unsigned char)*--p);
			c = (unsigned char)*--p;
			if (c == '-')
				return (c);
		}
	}

#define allowed_in_string(x) \
	(isalnum(x) || (ispunct(x) && x != '(' && x != ')' && \
	x != '{' && x != '}' && \
	x != '!' && x != '=' && x != '#' && \
	x != ','))

	if (isalnum(c) || c == ':' || c == '_') {
		do {
			*p++ = c;
			if ((size_t)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
			c = lgetc(0);
		} while (c != EOF && (allowed_in_string(c)));
		lungetc(c);
		*p = '\0';
		token = lookup(buf);
		if (token == STRING) {
			yylval.v.string = strdup(buf);
			if (yylval.v.string == NULL)
				err(1, "%s", __func__);
		}
		return (token);
	}
	if (c == '\n') {
		yylval.lineno = file->lineno;
		file->lineno++;
	}
	if (c == EOF)
		return (0);
	return (c);
}

static const struct got_error*
newfile(struct file **nfile, const char *filename, int *fd)
{
	const struct got_error* error = NULL;

	(*nfile) = calloc(1, sizeof(struct file));
	if ((*nfile) == NULL)
		return got_error_from_errno("calloc");
	(*nfile)->stream = fdopen(*fd, "r");
	if ((*nfile)->stream == NULL) {
		error = got_error_from_errno("fdopen");
		free((*nfile));
		return error;
	}
	*fd = -1; /* Stream owns the file descriptor now. */
	(*nfile)->name = filename;
	(*nfile)->lineno = 1;
	(*nfile)->ungetsize = 16;
	(*nfile)->ungetbuf = malloc((*nfile)->ungetsize);
	if ((*nfile)->ungetbuf == NULL) {
		error = got_error_from_errno("malloc");
		fclose((*nfile)->stream);
		free((*nfile));
		return error;
	}
	return NULL;
}

static const struct got_error*
new_remote(struct gotconfig_remote_repo **remote)
{
	const struct got_error *error = NULL;

	*remote = calloc(1, sizeof(**remote));
	if (*remote == NULL)
		error = got_error_from_errno("calloc");
	return error;
}

static const struct got_error*
new_fetch_config(struct fetch_config **fetch_config)
{
	const struct got_error *error = NULL;

	*fetch_config = calloc(1, sizeof(**fetch_config));
	if (*fetch_config == NULL)
		error = got_error_from_errno("calloc");
	return error;
}

static const struct got_error*
new_send_config(struct send_config **send_config)
{
	const struct got_error *error = NULL;

	*send_config = calloc(1, sizeof(**send_config));
	if (*send_config == NULL)
		error = got_error_from_errno("calloc");
	return error;
}

static void
closefile(struct file *file)
{
	fclose(file->stream);
	free(file->ungetbuf);
	free(file);
}

const struct got_error *
gotconfig_parse(struct gotconfig **conf, const char *filename, int *fd)
{
	const struct got_error *err = NULL;
	struct sym	*sym, *next;

	*conf = NULL;

	err = newfile(&file, filename, fd);
	if (err)
		return err;

	TAILQ_INIT(&gotconfig.remotes);

	yyparse();
	closefile(file);

	/* Free macros and check which have not been used. */
	TAILQ_FOREACH_SAFE(sym, &symhead, entry, next) {
		if (!sym->persist) {
			free(sym->nam);
			free(sym->val);
			TAILQ_REMOVE(&symhead, sym, entry);
			free(sym);
		}
	}

	if (gerror == NULL)
		*conf = &gotconfig;
	return gerror;
}

static void
free_fetch_config(struct fetch_config *fetch_config)
{
	free(remote->fetch_config->repository);
	free(remote->fetch_config->server);
	free(remote->fetch_config->protocol);
	free(remote->fetch_config);
}

static void
free_send_config(struct send_config *send_config)
{
	free(remote->send_config->repository);
	free(remote->send_config->server);
	free(remote->send_config->protocol);
	free(remote->send_config);
}

void
gotconfig_free(struct gotconfig *conf)
{
	struct gotconfig_remote_repo *remote;

	free(conf->author);
	free(conf->allowed_signers_file);
	free(conf->revoked_signers_file);
	free(conf->signer_id);
	while (!TAILQ_EMPTY(&conf->remotes)) {
		remote = TAILQ_FIRST(&conf->remotes);
		TAILQ_REMOVE(&conf->remotes, remote, entry);
		if (remote->fetch_config != NULL)
			free_fetch_config(remote->fetch_config);
		if (remote->send_config != NULL)
			free_send_config(remote->send_config);
		free(remote->name);
		free(remote->repository);
		free(remote->server);
		free(remote->protocol);
		free(remote);
	}
}

int
symset(const char *nam, const char *val, int persist)
{
	struct sym	*sym;

	TAILQ_FOREACH(sym, &symhead, entry) {
		if (strcmp(nam, sym->nam) == 0)
			break;
	}

	if (sym != NULL) {
		if (sym->persist == 1)
			return (0);
		else {
			free(sym->nam);
			free(sym->val);
			TAILQ_REMOVE(&symhead, sym, entry);
			free(sym);
		}
	}
	sym = calloc(1, sizeof(*sym));
	if (sym == NULL)
		return (-1);

	sym->nam = strdup(nam);
	if (sym->nam == NULL) {
		free(sym);
		return (-1);
	}
	sym->val = strdup(val);
	if (sym->val == NULL) {
		free(sym->nam);
		free(sym);
		return (-1);
	}
	sym->used = 0;
	sym->persist = persist;
	TAILQ_INSERT_TAIL(&symhead, sym, entry);
	return (0);
}

int
cmdline_symset(char *s)
{
	char	*sym, *val;
	int	ret;
	size_t	len;

	val = strrchr(s, '=');
	if (val == NULL)
		return (-1);

	len = strlen(s) - strlen(val) + 1;
	sym = malloc(len);
	if (sym == NULL)
		errx(1, "cmdline_symset: malloc");

	strlcpy(sym, s, len);

	ret = symset(sym, val + 1, 1);
	free(sym);

	return (ret);
}

char *
symget(const char *nam)
{
	struct sym	*sym;

	TAILQ_FOREACH(sym, &symhead, entry) {
		if (strcmp(nam, sym->nam) == 0) {
			sym->used = 1;
			return (sym->val);
		}
	}
	return (NULL);
}

static int
atoul(char *s, u_long *ulvalp)
{
	u_long	 ulval;
	char	*ep;

	errno = 0;
	ulval = strtoul(s, &ep, 0);
	if (s[0] == '\0' || *ep != '\0')
		return (-1);
	if (errno == ERANGE && ulval == ULONG_MAX)
		return (-1);
	*ulvalp = ulval;
	return (0);
}
