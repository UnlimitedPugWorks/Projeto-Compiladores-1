/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "minor.y"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "tabid.h"
#include "node.h"


#define VOIDTYPE 0
#define INTTYPE 1
#define ARRAYTYPE 2
#define STRINGTYPE 3
#define FUNCMASK 4
#define PUBLICMASK 8
#define FORWARDMASK 16
#define CONSTMASK 32
#define HASARGSMASK 64
#define UNKNOWN 128
#define TYPEMASK 3
#define MAINTYPE -1


extern int yylex();
void typerror(int, int);
void funcerror(char*, Node*);
void iterateTreeNode(Node*, Node*);
void consterror(int);
void voiderror(int);
void functyperror(int, int);
void heaperror(int, int);
void leftvaluefuncerror(char*, int);
void returntester(int, Node*);
void returnevaluator(int, Node*);
void intypescheck(int, int);
void intstrerror(int, int);
int adderror(int,int);
void addresserror(int);
int suberror(int,int);
void intypecheck(int);
void funcheck(int);
void isPointer(int);
void forwardtest(char*, int);
void looperror(int);
void argslistiterator(Node*, Node*);

int loopend = 0;


#line 52 "minor.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;			/* integer value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* node pointer */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 83 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INTEGER 257
#define CHAR 258
#define VARNAME 259
#define STR 260
#define FUNCTION 261
#define MODULE 262
#define START 263
#define VOID 264
#define CONST 265
#define NUMBER 266
#define ARRAY 267
#define STRING 268
#define PUBLIC 269
#define FORWARD 270
#define IF 271
#define FI 272
#define THEN 273
#define FOR 274
#define ELSE 275
#define ELIF 276
#define PROGRAM 277
#define END 278
#define UNTIL 279
#define STEP 280
#define DO 281
#define DONE 282
#define REPEAT 283
#define STOP 284
#define RETURN 285
#define GE 286
#define LE 287
#define EQ 288
#define NE 289
#define ADD 290
#define OR 291
#define SUBT 292
#define MOD 293
#define ADDR 294
#define LS 295
#define GR 296
#define POW 297
#define ID 298
#define AND 299
#define MINUS 300
#define DIV 301
#define NOT 302
#define IDPOINTER 303
#define MUL 304
#define ARG 305
#define PROGRAMDEC 306
#define MODULEDEC 307
#define ELIFT 308
#define RETURNEXPR 309
#define RETURNVOID 310
#define BODYVARLIST 311
#define BODYINST 312
#define BODYVAR 313
#define QUALIIFIER 314
#define QUALTYPE 315
#define INSTRUCTLIST 316
#define IFTHEN 317
#define IFTHENELSE 318
#define DECLIST 319
#define DECLTYPE 320
#define ARGLIST 321
#define INT 322
#define VAR 323
#define PRINTEXPR 324
#define LEFTVALUE 325
#define EMPTY 326
#define LISTEND 327
#define SETEND 328
#define VARDEC 329
#define FUNCDEC 330
#define BODY 331
#define LITYPE 332
#define LITERALSET 333
#define LITERALIST 334
#define TYPE 335
#define FUNCTYPE 336
#define FICHEIRO 337
#define VARPOINTER 338
#define VARLIST 339
#define VARPOINTERDEC 340
#define SET 341
#define LIST 342
#define INDEX 343
#define FUNCBODY 344
#define FUNC 345
#define PROGBODY 346
#define FUNCALL 347
#define READ 348
#define EXPR 349
#define CHARACTER 350
#define INITER 351
#define INITIALIZERS 352
#define IEQ 353
#define ADDRESS 354
#define UMINUS 355
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,   33,    2,   34,    2,    3,    3,   17,
   17,   18,   18,   18,   19,   19,   19,   19,   21,   21,
   21,   21,   22,   22,   35,   36,    4,    9,    9,    5,
    5,   16,   16,   16,   16,   29,   29,   31,   31,   31,
   32,   32,   30,   30,   15,   15,    7,    7,    6,    6,
   10,   10,   12,   14,   14,   14,   13,   13,   28,   28,
   20,   20,   25,   25,   37,   38,   25,   25,   25,   39,
   25,   40,   25,   25,   24,   24,    8,    8,   23,   23,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   27,   27,   26,   26,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    0,    5,    0,    6,    2,    3,    1,
    3,    1,    4,    7,    2,    1,    1,    0,    2,    4,
    2,    0,    1,    3,    0,    0,    7,    1,    2,    2,
    1,    1,    1,    1,    1,    2,    1,    1,    1,    1,
    1,    2,    1,    2,    1,    1,    0,    1,    1,    3,
    5,    2,    2,    1,    2,    0,    2,    3,    0,    1,
    1,    1,    6,    8,    0,    0,   11,    2,    2,    0,
    2,    0,    2,    4,    1,    2,    0,    4,    1,    2,
    1,    4,    1,    1,    1,    1,    4,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    2,    2,    1,    3,    1,    4,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    3,    0,   17,   45,   46,
    8,   12,    0,    0,   10,    0,    4,    0,   35,   32,
   33,   34,    0,    0,   31,   15,    9,    0,    0,    0,
    6,   25,   30,   11,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   13,   57,    5,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   85,    0,   75,    0,   53,   79,    0,   84,    0,    0,
    0,    0,    0,   26,   49,    0,    0,    0,   19,   21,
    0,    0,   58,    0,    0,    0,    0,    0,    0,    0,
  106,    0,  104,    0,  105,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   68,
   69,   76,   80,    0,    0,   38,   39,   40,    0,   43,
   71,   73,    7,    0,    0,   42,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  103,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   89,   88,
    0,    0,   44,   50,    0,   28,   27,   41,    0,   23,
   14,   51,   87,    0,    0,    0,    0,    0,   74,   29,
    0,    0,    0,    0,    0,  110,   24,    0,   63,    0,
    0,    0,    0,   65,   78,   64,    0,   66,    0,   67,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,    6,   12,   23,   73,   74,  174,  157,   36,
   62,   37,   38,   63,   13,   39,   14,   15,   16,   79,
   45,  159,   64,   65,   66,   88,  131,   40,   68,  119,
   69,   81,   30,   41,   42,  125,  187,  189,   70,   71,
};
static const YYINT yysindex[] = {                      -238,
 -180, -144,    0,    0,    0,    0,   -9,    0,    0,    0,
    0,    0, -223,  -40,    0,  -58,    0,  -41,    0,    0,
    0,    0, -207,  -58,    0,    0,    0,  -72, -193,  -58,
    0,    0,    0,    0,  -88,   41, -177,  -58, -154, 1375,
  -58,  -58,   54, -151,    0,    0,    0,   51,   20,    0,
    0,  -23,    0,   11,   11,   11,   11, -135,   11,   11,
    0,  735,    0, 1375,    0,    0,  -34,    0, -102, -161,
 -155, -142,   82,    0,    0,    0,    0, -115,    0,    0,
   99,   60,    0,  -96,   11,   11,  788, -181,  988, 1258,
    0,   83,    0, 1025,    0,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,    0,
    0,    0,    0,   11,   11,    0,    0,    0, -102,    0,
    0,    0,    0,  -58, -224,    0,  -13, -175,   80, 1258,
   -7, 1046, 1375,   11,   11,    0,   33,   33,   33, 1258,
   33,   33,   33,  -22,  -22,  -22,  -22,  -22,    0,    0,
 1258, 1083,    0,    0,  -58,    0,    0,    0,  139,    0,
    0,    0,    0,   11,    0,  -97, 1175, 1186,    0,    0,
  -13, 1258,   11, -152,   11,    0,    0, 1221,    0, 1375,
 1247, 1375,  -81,    0,    0,    0, 1375,    0,  -90,    0,
};
static const YYINT yyrindex[] = {                         0,
   36,   36,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   69,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   36,    0, 1353,
    0,    0,    0,    0,  -44,    0,    0, 1315,    0,   10,
 1353, -209,    0,    0,    0,    0,    0,    0,  -53,   71,
  107,  -33,  143,    0,    0,  135,    0,    0,    0,    0,
    0,    0,    0,   23,    0,    0,    0,    0,    0,    0,
    0,    0, -194,    0,    0,  -37,  -46,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  174,
    0,  280,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  398,    0,
    0,    0,    0,    0,    0,    0,    0,  -44,    0,  119,
    0,    0, -137,    0,    0,    0,  642,  667,  725, 1211,
  875,  900,  922,  434,  470,  535,  565,  605,    0,    0,
 1280,    0,    0,    0, 1345,    0,    0,    0,  -28,    0,
    0,    0,    0,    0,    3,  -76,    0,    0,    0,    0,
    0,  172,    0,    0,    0,    0,    0,    0,    0, -229,
    0, -113,    0,    0,    0,    0, -190,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -17,
 1585,  -21,    0,  151,  200,   79,  216,  196,    0,    0,
   97,    0,    0, -103,  163,   -5,    0,    0,  208,    0,
  -36, -104,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1760
static const YYINT yytable[] = {                         81,
  115,  109,   44,   81,   81,   52,   41,   81,   81,   81,
   81,   81,   62,   81,   22,  108,   85,   28,   28,   72,
   48,   61,  160,    1,   75,   81,   81,   81,   81,  166,
   20,   78,  120,  163,   67,   82,  164,  110,    2,   82,
   82,   26,   56,   82,   82,   82,   82,   82,   58,   82,
   59,   32,   93,   70,   72,   57,  155,  156,   67,   81,
   81,   82,   82,   82,   82,   35,  177,   86,   56,  107,
  108,   47,   47,   61,  105,  103,  183,  104,  185,  106,
    7,   56,  153,  188,    8,   25,   48,   48,    9,   10,
   81,   56,   70,   72,   29,   82,   82,   11,   78,   46,
   47,  109,   33,   83,   49,   82,  154,   83,   83,   83,
   84,   83,   83,   83,   83,   83,    7,   83,   17,  179,
    8,  121,  180,   92,    9,   10,   82,   67,  122,   83,
   83,   83,   83,  170,   56,  123,   60,   56,   56,   86,
  124,  126,  127,   86,   86,   70,   72,   86,   86,   86,
   86,   86,  128,   86,  116,  117,  109,  118,   56,  107,
  129,   56,  107,   83,   83,   86,   86,   86,   86,   70,
   72,  114,  162,  135,   67,   37,   67,   43,  173,   37,
   37,   67,  171,   37,   37,   37,   37,   37,    7,   37,
  186,  190,    8,   54,   83,   77,    9,   10,   77,   86,
   86,   37,   37,   37,   37,   19,   24,   20,   21,   22,
   39,   39,  108,   39,  112,  108,   62,   18,   22,   38,
   38,   31,   38,   34,  161,   61,  113,   52,   52,   81,
   86,   62,   55,   22,   20,   37,   37,   27,   81,   81,
   61,   81,   81,  158,   81,   81,   81,   81,   81,   20,
   80,    0,   81,   81,   19,   81,   20,   21,   22,    9,
   10,    0,    0,    0,   43,   82,   37,   50,   51,   52,
   53,    0,   56,    0,   82,   82,    0,   82,   82,    0,
   82,   82,   82,   82,   82,   56,    0,   56,   82,   82,
    0,   82,   70,   72,   56,    0,    0,   56,   56,   18,
   56,   18,   18,   18,   56,   70,   72,    0,    0,    0,
   76,   77,  109,   53,    0,    0,  109,  109,  114,  109,
  109,  109,  109,  109,  109,    0,  109,   38,   38,    0,
   38,    0,   16,   83,   16,   16,   16,    0,  109,  109,
  109,  109,   83,   83,    0,   83,   83,    0,   83,   83,
   83,   83,   83,    0,    0,  110,   83,   83,    0,   83,
    0,    0,    0,   39,   39,    0,   39,    0,    0,   86,
    0,    0,  109,  109,    0,    0,    0,    0,   86,   86,
    0,   86,   86,    0,   86,   86,   86,   86,   86,    0,
    0,    0,   86,   86,    0,   86,    0,   54,    0,   40,
   40,    0,   40,  109,    0,   37,   54,    0,    0,   54,
   54,    0,   54,    0,   37,   37,   54,   37,   37,    0,
   37,   37,   37,   37,   37,    0,    0,    0,   37,   37,
   36,   37,    0,    0,   36,   36,   55,    0,   36,   36,
   36,   36,   36,    0,   36,   55,    0,    0,   55,   55,
    0,   55,    0,    0,    0,   55,   36,   36,   36,   36,
    0,    0,    0,    0,    0,    0,   91,    0,    0,    0,
   91,    0,    0,    0,   91,   91,   91,   91,   91,    0,
   91,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   36,   36,   91,   91,   91,   91,    0,    0,    0,    0,
    0,    0,   92,    0,    0,    0,   92,    0,    0,    0,
   92,   92,   92,   92,   92,    0,   92,    0,    0,    0,
    0,   36,    0,    0,    0,    0,   91,   91,   92,   92,
   92,   92,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  109,    0,    0,    0,    0,    0,    0,    0,
    0,  109,  109,    0,  109,  109,    0,  109,  109,  109,
  109,  109,   92,   92,    0,  109,  109,  101,  109,    0,
    0,  101,    0,    0,    0,  101,  101,  101,  101,  101,
    0,  101,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  101,  101,  101,  101,   94,    0,    0,
    0,   94,    0,    0,    0,   94,   94,   94,   94,   94,
    0,   94,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   94,   94,   94,   94,  101,  101,    0,
    0,    0,    0,    0,    0,    0,    0,   93,    0,    0,
    0,   93,    0,    0,    0,   93,   93,   93,   93,   93,
    0,   93,    0,    0,    0,    0,    0,   94,   94,    0,
   36,    0,    0,   93,   93,   93,   93,    0,    0,   36,
   36,    0,   36,   36,   95,   36,   36,   36,   36,   36,
    0,    0,   95,   36,   36,   95,   36,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   91,   93,   93,   97,
   95,   95,   95,   95,    0,   91,   91,   97,   91,   91,
   97,   91,   91,   91,   91,   91,    0,    0,    0,   91,
   91,    0,   91,    0,    0,   97,   97,   97,   97,    0,
    0,    0,   92,    0,   95,   95,    0,    0,    0,    0,
    0,   92,   92,    0,   92,   92,    0,   92,   92,   92,
   92,   92,    0,    0,    0,   92,   92,   99,   92,   97,
   97,    0,    0,    0,    0,   99,    0,  111,   99,    0,
    0,  107,  108,    0,    0,    0,  105,  103,    0,  104,
    0,  106,    0,   99,   99,   99,   99,    0,    0,    0,
    0,    0,    0,  110,  101,  102,  100,  101,    0,    0,
    0,    0,    0,    0,    0,    0,  101,  101,    0,  101,
  101,    0,  101,  101,  101,  101,  101,   99,   99,    0,
  101,  101,    0,  101,  107,  108,    0,   94,   99,  105,
  103,    0,  104,    0,  106,    0,   94,   94,    0,   94,
   94,    0,   94,   94,   94,   94,   94,  101,  102,  100,
   94,   94,    0,   94,    0,    0,    0,    0,  109,    0,
    0,    0,    0,    0,    0,    0,    0,   93,    0,    0,
    0,    0,    0,    0,    0,    0,   93,   93,    0,   93,
   93,   99,   93,   93,   93,   93,   93,    0,    0,    0,
   93,   93,    0,   93,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   95,    0,    0,   96,    0,    0,
    0,  109,    0,   95,   95,   96,   95,   95,   96,   95,
   95,   95,   95,   95,    0,    0,    0,   95,   95,   97,
   95,    0,   98,   96,   96,   96,   96,    0,   97,   97,
   98,   97,   97,   98,   97,   97,   97,   97,   97,    0,
    0,    0,   97,   97,   90,   97,    0,    0,   98,   98,
   98,   98,   90,    0,    0,   90,    0,   96,   96,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   90,   90,   90,   90,    0,    0,    0,   99,    0,    0,
    0,    0,   98,   98,    0,    0,   99,   99,    0,   99,
   99,    0,   99,   99,   99,   99,   99,    0,    0,    0,
   99,   99,    0,   99,   90,   90,    0,    0,    0,    0,
   96,   97,    0,   98,  107,  108,    0,    0,    0,  105,
  103,    0,  104,    0,  106,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  101,  102,  100,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  133,  107,  108,    0,    0,  136,  105,  103,    0,  104,
    0,  106,    0,   96,   97,    0,   98,    0,    0,    0,
    0,   99,  107,  108,  101,  102,  100,  105,  103,    0,
  104,    0,  106,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  101,  102,  100,    0,    0,
    0,  109,    0,    0,    0,    0,    0,    0,   99,  107,
  108,    0,    0,    0,  105,  103,    0,  104,    0,  106,
    0,    0,    0,    0,    0,    0,    0,   96,  165,   99,
    0,  169,  101,  102,  100,    0,   96,   96,  109,   96,
   96,    0,   96,   96,   96,   96,   96,    0,    0,    0,
   96,   96,   98,   96,    0,    0,    0,    0,    0,  109,
    0,   98,   98,    0,   98,   98,   99,   98,   98,   98,
   98,   98,    0,    0,   90,   98,   98,    0,   98,    0,
    0,    0,    0,   90,   90,    0,   90,   90,    0,   90,
   90,   90,   90,   90,    0,    0,  109,   90,   90,    0,
   90,  107,  108,    0,    0,    0,  105,  103,    0,  104,
    0,  106,  107,  108,    0,    0,    0,  105,  103,    0,
  104,    0,  106,    0,  101,  102,  100,    0,    0,    0,
    0,    0,    0,  100,    0,  101,  102,  100,    0,    0,
    0,  100,    0,    0,  100,    0,    0,  107,  108,    0,
    0,    0,  105,  103,    0,  104,  134,  106,   99,  100,
    0,    0,    0,   96,   97,    0,   98,    0,  176,   99,
  101,  102,  100,  107,  108,    0,    0,    0,  105,  103,
    0,  104,    0,  106,  107,  108,    0,    0,  109,  105,
  103,    0,  104,  100,  106,    0,  101,  102,  100,  109,
   96,   97,  102,   98,   99,    0,    0,  101,  102,  100,
  102,    0,    0,  102,    0,    0,    0,    0,    0,    0,
    0,   96,   97,    0,   98,    0,    0,    0,  102,    0,
   99,    0,    0,    0,  109,    0,    0,    0,    0,    0,
    0,   99,   60,    0,   60,    0,    0,    0,    0,   60,
    0,    0,    0,    0,    0,    0,    0,    0,   96,   97,
  109,   98,  102,   60,    0,    0,    0,   60,    0,    0,
    0,  109,   59,    0,   59,    0,    0,    0,    0,   59,
   59,    0,   59,    0,    0,    0,    0,   59,    0,    0,
    0,    0,    0,   59,    0,    0,    0,   59,    0,    0,
    0,    0,   58,    0,   59,   59,    0,    0,    0,   57,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   61,    0,    0,
   60,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  175,    0,    0,    0,    0,    0,
   96,   97,    0,   98,    0,    0,    0,    0,    0,    0,
   59,   96,   97,  100,   98,    0,    0,    0,   59,    0,
    0,    0,  100,  100,    0,  100,  100,    0,  100,  100,
  100,  100,  100,  182,    0,    0,    0,    0,    0,    0,
   60,    0,    0,    0,    0,    0,   96,   97,    0,   98,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  184,    0,    0,
    0,    0,   96,   97,    0,   98,    0,    0,    0,    0,
    0,    0,  102,   96,   97,    0,   98,    0,    0,    0,
    0,  102,  102,    0,  102,  102,    0,  102,  102,  102,
  102,  102,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   60,   60,   60,   60,    0,    0,   60,    0,    0,
    0,    0,    0,    0,    0,   60,    0,    0,   60,    0,
    0,    0,   60,    0,    0,    0,    0,   60,   60,   60,
    0,   59,   59,   59,   59,    0,    0,   59,    0,   59,
   59,   59,   59,    0,    0,   59,    0,    0,   59,    0,
    0,    0,   59,   59,    0,    0,   59,   59,   59,   59,
   59,   50,   51,   52,   53,   59,   59,   59,   87,   89,
   90,   91,    0,   94,   95,   54,    0,    0,   55,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   56,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  130,
  132,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  137,  138,  139,  140,  141,  142,  143,  144,  145,  146,
  147,  148,  149,  150,    0,    0,    0,    0,  151,  152,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  167,  168,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  172,    0,
    0,    0,    0,    0,    0,    0,    0,  178,    0,  181,
};
static const YYINT yycheck[] = {                         33,
   35,   35,   91,   37,   38,   59,   44,   41,   42,   43,
   44,   45,   59,   47,   59,   38,   40,   59,   59,   41,
   38,   59,  127,  262,   42,   59,   60,   61,   62,  133,
   59,   45,   69,   41,   40,   33,   44,   35,  277,   37,
   38,  265,  272,   41,   42,   43,   44,   45,   38,   47,
   40,  259,   58,  283,  284,   45,  281,  282,   64,   93,
   94,   59,   60,   61,   62,  259,  171,   91,   59,   37,
   38,  281,  282,   63,   42,   43,  180,   45,  182,   47,
  261,   59,  119,  187,  265,    7,  281,  282,  269,  270,
  124,  282,  283,  284,   16,   93,   94,  278,   45,   59,
  278,  124,   24,   33,  259,  257,  124,   37,   38,   59,
   91,   41,   42,   43,   44,   45,  261,   47,  263,  272,
  265,  283,  275,  259,  269,  270,  124,  133,  284,   59,
   60,   61,   62,  155,  272,  278,  126,  275,  276,   33,
   59,  257,   44,   37,   38,  283,  284,   41,   42,   43,
   44,   45,   93,   47,  257,  258,  124,  260,  272,   41,
  257,  275,   44,   93,   94,   59,   60,   61,   62,  283,
  284,  353,   93,   91,  180,   33,  182,  353,  276,   37,
   38,  187,   44,   41,   42,   43,   44,   45,  261,   47,
  272,  282,  265,   59,  124,  272,  269,  270,  275,   93,
   94,   59,   60,   61,   62,  264,    7,  266,  267,  268,
  257,  258,   41,  260,   64,   44,  263,    2,  263,  257,
  258,  263,  260,   28,  128,  263,   64,  281,  282,  263,
  124,  278,   59,  278,  263,   93,   94,  278,  272,  273,
  278,  275,  276,  257,  278,  279,  280,  281,  282,  278,
   43,   -1,  286,  287,  264,  289,  266,  267,  268,  269,
  270,   -1,   -1,   -1,  353,  263,  124,  257,  258,  259,
  260,   -1,  263,   -1,  272,  273,   -1,  275,  276,   -1,
  278,  279,  280,  281,  282,  263,   -1,  278,  286,  287,
   -1,  289,  283,  284,  272,   -1,   -1,  275,  276,  264,
  278,  266,  267,  268,  282,  283,  284,   -1,   -1,   -1,
  257,  258,   33,  260,   -1,   -1,   37,   38,  353,  353,
   41,   42,   43,   44,   45,   -1,   47,  257,  258,   -1,
  260,   -1,  264,  263,  266,  267,  268,   -1,   59,   60,
   61,   62,  272,  273,   -1,  275,  276,   -1,  278,  279,
  280,  281,  282,   -1,   -1,  353,  286,  287,   -1,  289,
   -1,   -1,   -1,  257,  258,   -1,  260,   -1,   -1,  263,
   -1,   -1,   93,   94,   -1,   -1,   -1,   -1,  272,  273,
   -1,  275,  276,   -1,  278,  279,  280,  281,  282,   -1,
   -1,   -1,  286,  287,   -1,  289,   -1,  263,   -1,  257,
  258,   -1,  260,  124,   -1,  263,  272,   -1,   -1,  275,
  276,   -1,  278,   -1,  272,  273,  282,  275,  276,   -1,
  278,  279,  280,  281,  282,   -1,   -1,   -1,  286,  287,
   33,  289,   -1,   -1,   37,   38,  263,   -1,   41,   42,
   43,   44,   45,   -1,   47,  272,   -1,   -1,  275,  276,
   -1,  278,   -1,   -1,   -1,  282,   59,   60,   61,   62,
   -1,   -1,   -1,   -1,   -1,   -1,   33,   -1,   -1,   -1,
   37,   -1,   -1,   -1,   41,   42,   43,   44,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   93,   94,   59,   60,   61,   62,   -1,   -1,   -1,   -1,
   -1,   -1,   33,   -1,   -1,   -1,   37,   -1,   -1,   -1,
   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   93,   94,   59,   60,
   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  272,  273,   -1,  275,  276,   -1,  278,  279,  280,
  281,  282,   93,   94,   -1,  286,  287,   33,  289,   -1,
   -1,   37,   -1,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   60,   61,   62,   33,   -1,   -1,
   -1,   37,   -1,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   60,   61,   62,   93,   94,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   33,   -1,   -1,
   -1,   37,   -1,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   93,   94,   -1,
  263,   -1,   -1,   59,   60,   61,   62,   -1,   -1,  272,
  273,   -1,  275,  276,   33,  278,  279,  280,  281,  282,
   -1,   -1,   41,  286,  287,   44,  289,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  263,   93,   94,   33,
   59,   60,   61,   62,   -1,  272,  273,   41,  275,  276,
   44,  278,  279,  280,  281,  282,   -1,   -1,   -1,  286,
  287,   -1,  289,   -1,   -1,   59,   60,   61,   62,   -1,
   -1,   -1,  263,   -1,   93,   94,   -1,   -1,   -1,   -1,
   -1,  272,  273,   -1,  275,  276,   -1,  278,  279,  280,
  281,  282,   -1,   -1,   -1,  286,  287,   33,  289,   93,
   94,   -1,   -1,   -1,   -1,   41,   -1,   33,   44,   -1,
   -1,   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   59,   60,   61,   62,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   60,   61,   62,  263,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,   -1,  275,
  276,   -1,  278,  279,  280,  281,  282,   93,   94,   -1,
  286,  287,   -1,  289,   37,   38,   -1,  263,   94,   42,
   43,   -1,   45,   -1,   47,   -1,  272,  273,   -1,  275,
  276,   -1,  278,  279,  280,  281,  282,   60,   61,   62,
  286,  287,   -1,  289,   -1,   -1,   -1,   -1,  124,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,   -1,  275,
  276,   94,  278,  279,  280,  281,  282,   -1,   -1,   -1,
  286,  287,   -1,  289,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  263,   -1,   -1,   33,   -1,   -1,
   -1,  124,   -1,  272,  273,   41,  275,  276,   44,  278,
  279,  280,  281,  282,   -1,   -1,   -1,  286,  287,  263,
  289,   -1,   33,   59,   60,   61,   62,   -1,  272,  273,
   41,  275,  276,   44,  278,  279,  280,  281,  282,   -1,
   -1,   -1,  286,  287,   33,  289,   -1,   -1,   59,   60,
   61,   62,   41,   -1,   -1,   44,   -1,   93,   94,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   60,   61,   62,   -1,   -1,   -1,  263,   -1,   -1,
   -1,   -1,   93,   94,   -1,   -1,  272,  273,   -1,  275,
  276,   -1,  278,  279,  280,  281,  282,   -1,   -1,   -1,
  286,  287,   -1,  289,   93,   94,   -1,   -1,   -1,   -1,
  286,  287,   -1,  289,   37,   38,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   61,   62,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  273,   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,
   -1,   47,   -1,  286,  287,   -1,  289,   -1,   -1,   -1,
   -1,   94,   37,   38,   60,   61,   62,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   60,   61,   62,   -1,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,   94,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,   93,   94,
   -1,   59,   60,   61,   62,   -1,  272,  273,  124,  275,
  276,   -1,  278,  279,  280,  281,  282,   -1,   -1,   -1,
  286,  287,  263,  289,   -1,   -1,   -1,   -1,   -1,  124,
   -1,  272,  273,   -1,  275,  276,   94,  278,  279,  280,
  281,  282,   -1,   -1,  263,  286,  287,   -1,  289,   -1,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,   -1,  278,
  279,  280,  281,  282,   -1,   -1,  124,  286,  287,   -1,
  289,   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,
   -1,   47,   37,   38,   -1,   -1,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,   60,   61,   62,   -1,   -1,   -1,
   -1,   -1,   -1,   33,   -1,   60,   61,   62,   -1,   -1,
   -1,   41,   -1,   -1,   44,   -1,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,  279,   47,   94,   59,
   -1,   -1,   -1,  286,  287,   -1,  289,   -1,   93,   94,
   60,   61,   62,   37,   38,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,   37,   38,   -1,   -1,  124,   42,
   43,   -1,   45,   93,   47,   -1,   60,   61,   62,  124,
  286,  287,   33,  289,   94,   -1,   -1,   60,   61,   62,
   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  286,  287,   -1,  289,   -1,   -1,   -1,   59,   -1,
   94,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   94,   38,   -1,   40,   -1,   -1,   -1,   -1,   45,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,
  124,  289,   93,   59,   -1,   -1,   -1,   63,   -1,   -1,
   -1,  124,   38,   -1,   40,   -1,   -1,   -1,   -1,   45,
   38,   -1,   40,   -1,   -1,   -1,   -1,   45,   -1,   -1,
   -1,   -1,   -1,   59,   -1,   -1,   -1,   63,   -1,   -1,
   -1,   -1,   38,   -1,   40,   63,   -1,   -1,   -1,   45,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   63,   -1,   -1,
  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  280,   -1,   -1,   -1,   -1,   -1,
  286,  287,   -1,  289,   -1,   -1,   -1,   -1,   -1,   -1,
  126,  286,  287,  263,  289,   -1,   -1,   -1,  126,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,   -1,  278,  279,
  280,  281,  282,  273,   -1,   -1,   -1,   -1,   -1,   -1,
  126,   -1,   -1,   -1,   -1,   -1,  286,  287,   -1,  289,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,   -1,   -1,
   -1,   -1,  286,  287,   -1,  289,   -1,   -1,   -1,   -1,
   -1,   -1,  263,  286,  287,   -1,  289,   -1,   -1,   -1,
   -1,  272,  273,   -1,  275,  276,   -1,  278,  279,  280,
  281,  282,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  257,  258,  259,  260,   -1,   -1,  263,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  271,   -1,   -1,  274,   -1,
   -1,   -1,  278,   -1,   -1,   -1,   -1,  283,  284,  285,
   -1,  257,  258,  259,  260,   -1,   -1,  263,   -1,  257,
  258,  259,  260,   -1,   -1,  271,   -1,   -1,  274,   -1,
   -1,   -1,  278,  271,   -1,   -1,  274,  283,  284,  285,
  278,  257,  258,  259,  260,  283,  284,  285,   54,   55,
   56,   57,   -1,   59,   60,  271,   -1,   -1,  274,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  285,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   85,
   86,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   96,   97,   98,   99,  100,  101,  102,  103,  104,  105,
  106,  107,  108,  109,   -1,   -1,   -1,   -1,  114,  115,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  134,  135,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  164,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  173,   -1,  175,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 355
#define YYUNDFTOKEN 398
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'|'",0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTEGER","CHAR","VARNAME",
"STR","FUNCTION","MODULE","START","VOID","CONST","NUMBER","ARRAY","STRING",
"PUBLIC","FORWARD","IF","FI","THEN","FOR","ELSE","ELIF","PROGRAM","END","UNTIL",
"STEP","DO","DONE","REPEAT","STOP","RETURN","GE","LE","EQ","NE","ADD","OR",
"SUBT","MOD","ADDR","LS","GR","POW","ID","AND","MINUS","DIV","NOT","IDPOINTER",
"MUL","ARG","PROGRAMDEC","MODULEDEC","ELIFT","RETURNEXPR","RETURNVOID",
"BODYVARLIST","BODYINST","BODYVAR","QUALIIFIER","QUALTYPE","INSTRUCTLIST",
"IFTHEN","IFTHENELSE","DECLIST","DECLTYPE","ARGLIST","INT","VAR","PRINTEXPR",
"LEFTVALUE","EMPTY","LISTEND","SETEND","VARDEC","FUNCDEC","BODY","LITYPE",
"LITERALSET","LITERALIST","TYPE","FUNCTYPE","FICHEIRO","VARPOINTER","VARLIST",
"VARPOINTERDEC","SET","LIST","INDEX","FUNCBODY","FUNC","PROGBODY","FUNCALL",
"READ","EXPR","CHARACTER","INITER","INITIALIZERS","IEQ","ADDRESS","UMINUS",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : ficheiro",
"ficheiro : programa",
"ficheiro : modulo",
"$$1 :",
"programa : PROGRAM START $$1 corpo END",
"$$2 :",
"programa : PROGRAM declaracoes START $$2 corpo END",
"modulo : MODULE END",
"modulo : MODULE declaracoes END",
"declaracoes : declaracao",
"declaracoes : declaracoes ';' declaracao",
"declaracao : funcao",
"declaracao : decltype tipo VARNAME literaltype",
"declaracao : decltype tipo VARNAME '[' INTEGER ']' literaltype",
"decltype : qualificador CONST",
"decltype : qualificador",
"decltype : CONST",
"decltype :",
"literaltype : IEQ literal",
"literaltype : IEQ inteiro ',' literalist",
"literaltype : IEQ cadeias",
"literaltype :",
"literalist : inteiro",
"literalist : literalist ',' inteiro",
"$$3 :",
"$$4 :",
"funcao : FUNCTION functype VARNAME $$3 argsopt $$4 funcdone",
"funcdone : DONE",
"funcdone : DO corpo",
"functype : qualificador tipo",
"functype : tipo",
"tipo : NUMBER",
"tipo : ARRAY",
"tipo : STRING",
"tipo : VOID",
"cadeias : iniciador iniciadores",
"cadeias : STR",
"iniciador : INTEGER",
"iniciador : CHAR",
"iniciador : STR",
"inteiro : INTEGER",
"inteiro : '-' INTEGER",
"iniciadores : iniciador",
"iniciadores : iniciadores iniciador",
"qualificador : PUBLIC",
"qualificador : FORWARD",
"argsopt :",
"argsopt : args",
"args : variavel",
"args : args ';' variavel",
"variavel : tipo VARNAME '[' INTEGER ']'",
"variavel : tipo VARNAME",
"corpo : varopt instructopt",
"returns : RETURN",
"returns : RETURN expressao",
"returns :",
"corpovar : variavel ';'",
"corpovar : corpovar variavel ';'",
"varopt :",
"varopt : corpovar",
"literal : INTEGER",
"literal : CHAR",
"instrucao : IF expressao THEN instructopt elifopt FI",
"instrucao : IF expressao THEN instructopt elifopt ELSE instructopt FI",
"$$5 :",
"$$6 :",
"instrucao : FOR expressao UNTIL expressao STEP expressao DO $$5 instructopt $$6 DONE",
"instrucao : expressao ';'",
"instrucao : expressao '!'",
"$$7 :",
"instrucao : $$7 REPEAT",
"$$8 :",
"instrucao : $$8 STOP",
"instrucao : leftvalue '#' expressao ';'",
"instructopt : returns",
"instructopt : instrucoes returns",
"elifopt :",
"elifopt : ELIF expressao THEN instructopt",
"instrucoes : instrucao",
"instrucoes : instrucoes instrucao",
"expressao : VARNAME",
"expressao : VARNAME '[' expressao ']'",
"expressao : INTEGER",
"expressao : cadeias",
"expressao : '?'",
"expressao : CHAR",
"expressao : VARNAME '(' expresionlist ')'",
"expressao : expressao '|' expressao",
"expressao : expressao '&' expressao",
"expressao : expressao '=' expressao",
"expressao : expressao '+' expressao",
"expressao : expressao '-' expressao",
"expressao : expressao '%' expressao",
"expressao : expressao '/' expressao",
"expressao : expressao GE expressao",
"expressao : expressao '>' expressao",
"expressao : expressao LE expressao",
"expressao : expressao '<' expressao",
"expressao : expressao NE expressao",
"expressao : expressao '^' expressao",
"expressao : expressao '*' expressao",
"expressao : leftvalue IEQ expressao",
"expressao : '(' expressao ')'",
"expressao : '&' leftvalue",
"expressao : '~' expressao",
"expressao : '-' expressao",
"expresionlist : expressao",
"expresionlist : expresionlist ',' expressao",
"leftvalue : VARNAME",
"leftvalue : VARNAME '[' expressao ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 302 "minor.y"
int yyerror(const char*); /* declaration may depend on yacc's version/flavor */
char **yynames =
#if YYDEBUG > 0
     (char**)yyname;
#else
     0;
#endif

void forwardtest(char* funcname, int type2){
	int type = 0;
	void** atribute;
	if((type = IDfind(funcname, (void*) IDtest)) == -1){
		IDnew(type2, funcname, NULL);
		return;
	}
	typerror(type,type2);
	if(type & FORWARDMASK){
		IDfind(funcname, atribute);
		IDreplace(type, funcname, atribute[0]);
		return;
	}
	else{
		yyerror("A função já se encontra declarada");
	}
}

void printerror(int type){
	type = type & TYPEMASK;
	if(type == 0){
		yyerror("Não se pode imprimir voids");
		exit(1);
	}
}

void looperror(int type){
	if(loopend == 0){
		if(type == 1){
			yyerror("O REPEAT não pode estar fora de um loop");
		}
		else{
			yyerror("O STOP não pode estar fora de um loop");
		}
		exit(1); 
	}
}

void declerror(int type1, int type2){
	if(type2 & UNKNOWN){
		return;
	}
	type1 = type1 & TYPEMASK;
	type2 = type2 & TYPEMASK;
	/*printf("%d\n", type1);
	printf("%d\n", type2);*/
	if(type1 == ARRAYTYPE && type2 == INTTYPE){
		/*printf("Entro aqui\n");*/
		return;
	}
	else{
		/*printf("Mas chego aqui?\n");*/
		typerror(type1, type2);
	}
}

void forwardargstest(char* name, Node* newargs){
	void** atribute;
	int type = IDfind(name, atribute);
	/*printf("%d\n", type);
	printf("A funcao que tou a testar é %s\n", name);
	printf("O ponteiro a que o atributo tá ligado é %p\n", atribute);*/
	Node* funcargslist = (Node*) atribute[0];
	/*printf("O ponteiro a que o atributo tá ligado é %p\n", funcargslist);*/
	if(funcargslist == NULL){
		IDreplace(IDfind(name, NULL)|newargs->info, name, (void*)newargs);
		/*printf("%d\n", IDfind(name, NULL) & HASARGSMASK);*/
		return;
	}
	if(newargs->attrib == EMPTY && funcargslist->attrib == EMPTY){
		return;
	}
	argslistiterator(funcargslist->CHILD(0), newargs->CHILD(0));
}


void argslistiterator(Node* oldargs, Node* newargs){
	if(oldargs->attrib == LISTEND && newargs->attrib == LISTEND){
		return;
	}
	if(oldargs->attrib == LISTEND && newargs->attrib != LISTEND){
		yyerror("A declaração forward da funcao tem um numero diferente de argumentos do que a atual");
	}
	if(oldargs->attrib != LISTEND && newargs->attrib == LISTEND){
		yyerror("A declaração forward da funcao tem um numero diferente de argumentos do que a atual");
	}
	int i = 0;
	if(oldargs->attrib == VAR && oldargs->attrib == VAR){
		typerror(oldargs->info, newargs->info);
		return;
	}
	if(oldargs->attrib == VARPOINTER && oldargs->attrib == VARPOINTER){
		typerror(oldargs->info, newargs->info);
		return;
	}
	for(i = 0; i < newargs->value.sub.num && i<oldargs->value.sub.num; i++){
		argslistiterator(oldargs->CHILD(i), newargs->CHILD(i));
	}

}

void forwardecltest(int type1, int type2){
	if(((type1 & FORWARDMASK) && !(type2 & FORWARDMASK))){
		yyerror("Não se pode declarar uma funcao ou variavel foward logo a seguir");
	}
}

void forwardecltest2(int type1, int type2){
	if(((type1 & FORWARDMASK) && !(type2 & FORWARDMASK)) || (!(type1 & FORWARDMASK) && (type2 & FORWARDMASK)) ){
		yyerror("Não se pode declarar uma funcao ou variavel foward logo a seguir");
	}
}

void addresserror(int type1){
	if ((type1 & TYPEMASK) != ARRAYTYPE && ((type1 & TYPEMASK) != INTTYPE)){
		yyerror("Só se pode usar o & com arrays");
		exit(1);
	}

}

void indexError(int type1){
	if((type1 & TYPEMASK) != INTTYPE){
		yyerror("Uma expressao que é um indice tem de ter como resultado um inteiro");
		exit(1);
	}
}


void arrayIndexError(int type1){
	if((type1 & TYPEMASK) != ARRAYTYPE){
		yyerror("Não se pode declarar variaveis que nao são arrays com tamanhos");
		exit(1);
	}
}

void returnevaluator(int type, Node* node){
	Node* body = node;
	/*printNode(body,0, yynames);*/
	if (type != MAINTYPE){
		if(body->value.sub.num == 0){
			return;
		}
		body = body->CHILD(0);
	}
	/*printf("Bom dia\n");*/
	/*printNode(body, 0, yynames);*/
	Node* instructionlist = body->CHILD(1);
	/*printNode(instructionlist, 0, yynames);*/
	if(instructionlist->value.sub.num == 0){
		return;
	}
	/*printf("Buenos dias\n");
	printf("O tipo que quero testar é %d\n", type);
	printf("%d\n", instructionlist->value.sub.num);*/
	Node* returns;
	/*No caso de estarmos num ramo só como returns*/
	if(instructionlist->attrib == EMPTY || instructionlist->attrib == RETURNEXPR || instructionlist->attrib == RETURNVOID){
		returns = instructionlist;
	}
	/*No caso de estarmos num ramo com instructionopt e returns*/
	else{
		returns = instructionlist->CHILD(instructionlist->value.sub.num-1);
	}
	/*printNode(returns, 0, yynames);*/
	if(type == MAINTYPE && returns->attrib != EMPTY){
		yyerror("A funcão start não deve ter return nenhum");
		exit(1);
	}
	else if(!(type & TYPEMASK) && (returns->attrib != RETURNVOID) && (returns->attrib != EMPTY)){
		yyerror("A funcão tem tipo de retorno void mas tem return de um tipo");
		exit(1);
	}
	else if(returns->attrib == RETURNEXPR){
		/*printf("Entro aqui\n");*/
		returntester(type, returns);
	}
}

void returntester(int type1, Node* returns){
	int type2 = returns->CHILD(0)->info;
	type1 = (type1 & TYPEMASK);
	type2 = (type2 & TYPEMASK);
	/*printf("type1 é %d type2 é %d\n",type1,type2);*/
	if(type1 != type2){
		yyerror("A funcão tem um return diferente do seu tipo");
		exit(1);
	}
}

void funcheck(int type1){
	if(type1 & FUNCMASK){
		yyerror("Um leftvalue nao pode ser uma função sem argumentos");
		exit(1);
	}
}

void isPointer(int type1){
	type1 = (type1 & TYPEMASK);
	if(type1 != ARRAYTYPE && type1 != STRINGTYPE){
		yyerror("Não se pode indexar algo que não é um ponteiro(string ou vetor)");
		exit(1);
	}
}





int adderror(int type1, int type2){
	type1 = type1 & TYPEMASK;
	type2 = type2 & TYPEMASK;
	if(!((type1 == INTTYPE && type2 == INTTYPE) || (type1 == ARRAYTYPE && type2 == INTTYPE) || (type1 == INTTYPE && type2 == ARRAYTYPE))){
		yyerror("A operação de adição só funciona com dois inteiros ou um inteiros e um vetor");
		exit(1);
	}  
	if(type1 == type2){
		return INTTYPE;
	}
	else{
		return ARRAYTYPE;
	}
}

int suberror(int type1, int type2){
	type1 = type1 & TYPEMASK;
	type2 = type2 & TYPEMASK;
	if(!((type1 == INTTYPE || type1 == ARRAYTYPE) && (type2 == INTTYPE || type2 == ARRAYTYPE))){
		yyerror("A operação de subtração só funciona com dois inteiros, dois vetores ou um inteiros e um vetor");
		exit(1);
	}
	if(type1 == type2){
		return INTTYPE;
	}
	else{
		return ARRAYTYPE;
	}
}

void intstrerror(int type1, int type2){
	type1 = type1 & TYPEMASK;
	type2 = type2 & TYPEMASK;
	/*printf("%d\n", type1);
	printf("%d\n", type2);*/
	if(!((type1 == INTTYPE && type2 == INTTYPE) || (type1 == STRINGTYPE && type2 == STRINGTYPE))){
		yyerror("A operação só funciona com dois inteiros ou duas cadeias");
		exit(1);
	}
}

void typerror(int type1, int type2){
	if(type2 & UNKNOWN){
		return;
	}
	type1 = type1 & TYPEMASK;
	type2 = type2 & TYPEMASK;
	/*printf("type1 é %d type2 é %d\n",type1,type2);*/
	if(type1 != type2){
		yyerror("Type error");
		exit(1);
	}
}

void intypescheck(int type1, int type2){
	type1 = type1 & TYPEMASK;
	type2 = type2 & TYPEMASK;
	if(!(type1 == INTTYPE && type2 == INTTYPE)){
		yyerror("A operação só é valida com inteiros");
		exit(1);
	}
}

void intypecheck(int type1){
	type1 = type1 & TYPEMASK;
	if(!(type1 == INTTYPE)){
		yyerror("A operação só é valida com inteiros");
		exit(1);
	}
}


void funcerror(char* funcname, Node* args){
		if((IDfind(funcname, NULL) & FUNCMASK) == 0){
			yyerror("Só as funcões é que podem ter argumentos");
			exit(1);
		}
		/*printNode(args, 0, yynames);*/
		/*printf("%d\n", IDfind(funcname, NULL) & HASARGSMASK);*/
		if(((IDfind(funcname, NULL) & HASARGSMASK) == 0)){
			yyerror("A funcão não tem argumentos");
			exit(1);
		}
		/*printf("%s\n", funcname);*/
		void** atribute;
		IDfind(funcname, atribute);
		Node* funcargslist = (Node*) atribute[0];
		/*printf("O atributo em node tem %p\n", funcargslist);*/
		Node* funcargs = funcargslist->CHILD(0);
		/*printf("Vou imprimir as arvores\n");*/
		iterateTreeNode(funcargs, args);
}




void iterateTreeNode(Node* funcargs, Node* args){
	int i;
	Node* current1 = funcargs;
	Node* current2 = args;
	if(current1 == NULL || current2 == NULL){
		return;
	}
	if((current1->attrib == LISTEND && current2->attrib != LISTEND) || (current1->attrib != LISTEND && current2->attrib == LISTEND)){
		yyerror("O numero de argumentos é diferente do definido");
		exit(1);
	}
	if(current1->attrib == LISTEND && current2->attrib == LISTEND){
		return;
	}
	if(current2->attrib == FUNCALL){ /* Se é uma função não vale a pena entrar lá dentro e faz-se apenas o teste*/
		typerror(current1->info, current2->info);
		return;
	}
	if(current2->attrib == IDPOINTER || current2->attrib == ID){ /*Se chegou ao nome de uma varival ou funcao pode testar e parar*/
		typerror(current1->info, current2->info);
		return;
	}
	typerror(current1->info, current2->info);
	for(i = 0; i < current1->value.sub.num; i++){
		iterateTreeNode(current1->CHILD(i), current2->CHILD(i));
	}
}

void consterror(int type){
	if(type & CONSTMASK){
		yyerror("Não se pode fazer uma atribuição a um variavel constante");
		exit(1);
	}
}

void voiderror(int type){
	if(!(type & TYPEMASK) && !(type & FUNCMASK)){
		yyerror("Não existem variaveis do tipo void");
		exit(1);
	}
}

void voidexpressionerror(int type){
	if(!(type & TYPEMASK)){
		yyerror("Uma expressao não pode ser do tipo void");
		exit(1);
	}
}


void forwarderror(int type1, int type2){
	if(type1 & FORWARDMASK || type2 & FORWARDMASK){
		yyerror("Não pode declarar imediatamente uma funcão que é forward");
	}
}

void heaperror(int type1, int type2){
	type2 = type2 & TYPEMASK;
	/*printf("type 2 = %d\n", type2);*/
	if(type2 != INTTYPE){
		yyerror("Na operação # o lado direito não é uma unidade");
		exit(1);
	}
	type1 = (type1 & TYPEMASK);
	/*printf("type 1 = %d\n", type1);*/
	if(type1 != ARRAYTYPE && type1 != STRINGTYPE){
		yyerror("Na operação # o lado esquerdo não é um ponteiro");
		exit(1);
	}
}


/*instructopt:returns            {$$ = $1;}
		  | instrucoes returns {$$ = binNode(INSTRUCTLIST, $1, $2); printf("Dá erro exatamente aqui\n"); typerror($1->info,$2->info);$$->info = $2->info;}
		  ;*/

/*returns : RETURN              {$$ = nilNode(RETURNVOID); $$->info = VOIDTYPE;}
		| RETURN expressao    {$$ = uniNode(RETURNEXPR, $2); $$->info = $2->info;}
		|                     {$$ = nilNode(EMPTY); $$->info = VOIDTYPE; printf("Passa aqui\n");}
		;*/


#line 1252 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 124 "minor.y"
	{printNode(yystack.l_mark[0].n, 0, yynames);}
break;
case 2:
#line 126 "minor.y"
	{yyval.n = uniNode(FICHEIRO, yystack.l_mark[0].n);}
break;
case 3:
#line 127 "minor.y"
	{yyval.n = uniNode(FICHEIRO, yystack.l_mark[0].n);}
break;
case 4:
#line 131 "minor.y"
	{IDpush();}
break;
case 5:
#line 131 "minor.y"
	{yyval.n = uniNode(PROGBODY, yystack.l_mark[-1].n); returnevaluator(MAINTYPE, yystack.l_mark[-1].n); IDpop();}
break;
case 6:
#line 132 "minor.y"
	{IDpush();}
break;
case 7:
#line 132 "minor.y"
	{yyval.n = binNode(PROGRAMDEC, yystack.l_mark[-4].n,yystack.l_mark[-1].n); returnevaluator(MAINTYPE, yystack.l_mark[-1].n); IDpop();}
break;
case 8:
#line 136 "minor.y"
	{yyval.n = nilNode(MODULE);}
break;
case 9:
#line 137 "minor.y"
	{yyval.n = uniNode(MODULEDEC, yystack.l_mark[-1].n);}
break;
case 10:
#line 140 "minor.y"
	{yyval.n = binNode(DECLIST, nilNode(LISTEND), yystack.l_mark[0].n);}
break;
case 11:
#line 141 "minor.y"
	{yyval.n = binNode(DECLIST, yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 12:
#line 144 "minor.y"
	{yyval.n = uniNode(FUNCDEC, yystack.l_mark[0].n);}
break;
case 13:
#line 145 "minor.y"
	{yyval.n = triNode(VARDEC, yystack.l_mark[-3].n,yystack.l_mark[-2].n,yystack.l_mark[0].n); voiderror(yystack.l_mark[-2].n->info); forwardecltest(yystack.l_mark[-3].n->info, yystack.l_mark[0].n->info); IDnew((yystack.l_mark[-2].n->info|yystack.l_mark[-3].n->info),yystack.l_mark[-1].s,NULL); /*if(($2->info & TYPEMASK) == ARRAYTYPE){yyerror("Os arrays tem de ter dimensão");}*/}
break;
case 14:
#line 146 "minor.y"
	{yyval.n = quadNode(VARPOINTERDEC,yystack.l_mark[-6].n,yystack.l_mark[-5].n,intNode(INDEX, yystack.l_mark[-2].i),yystack.l_mark[0].n); declerror(yystack.l_mark[-5].n->info,yystack.l_mark[0].n->info);arrayIndexError(yystack.l_mark[-5].n->info); voiderror(yystack.l_mark[-5].n->info);forwardecltest(yystack.l_mark[-6].n->info, yystack.l_mark[0].n->info); if(yystack.l_mark[-2].i == 0){yyerror("Nao existem arrays com dimensao zero");} if((yystack.l_mark[-5].n->info & TYPEMASK) != ARRAYTYPE){yyerror("Só os arrays é que tem dimensão");} IDnew((yystack.l_mark[-5].n->info | yystack.l_mark[-6].n->info),yystack.l_mark[-4].s,NULL);}
break;
case 15:
#line 149 "minor.y"
	{yyval.n = binNode(DECLTYPE,yystack.l_mark[-1].n,nilNode(CONST)); yyval.n->info = (yystack.l_mark[-1].n->info | CONSTMASK);}
break;
case 16:
#line 150 "minor.y"
	{yyval.n = uniNode(QUALTYPE,yystack.l_mark[0].n); yyval.n->info = (yystack.l_mark[0].n->info);}
break;
case 17:
#line 151 "minor.y"
	{yyval.n = nilNode(CONST); yyval.n->info = CONSTMASK;}
break;
case 18:
#line 152 "minor.y"
	{yyval.n = nilNode(EMPTY); yyval.n->info = 0;}
break;
case 19:
#line 155 "minor.y"
	{yyval.n = uniNode(LITYPE, yystack.l_mark[0].n); yyval.n->info = INTTYPE;}
break;
case 20:
#line 156 "minor.y"
	{yyval.n = binNode(LITERALIST, intNode(INT,yystack.l_mark[-2].i),yystack.l_mark[0].n); yyval.n->info = ARRAYTYPE;}
break;
case 21:
#line 157 "minor.y"
	{yyval.n = uniNode(LITERALSET, yystack.l_mark[0].n); yyval.n->info = STRINGTYPE;}
break;
case 22:
#line 158 "minor.y"
	{yyval.n = nilNode(EMPTY); yyval.n->info = FORWARDMASK|UNKNOWN;}
break;
case 23:
#line 162 "minor.y"
	{yyval.n = binNode(LIST,nilNode(LISTEND),intNode(INT,yystack.l_mark[0].i));}
break;
case 24:
#line 163 "minor.y"
	{yyval.n = binNode(LIST,yystack.l_mark[-2].n, intNode(INT,yystack.l_mark[0].i));}
break;
case 25:
#line 167 "minor.y"
	{forwardtest(yystack.l_mark[0].s, FUNCMASK|yystack.l_mark[-1].n->info); /*printf("A funcão é %s = %d\n", $3, IDfind($3,NULL));*/ /*IDprint(0,2);*/ IDpush();}
break;
case 26:
#line 167 "minor.y"
	{IDreplace(IDfind(yystack.l_mark[-2].s, NULL)|yystack.l_mark[0].n->info, yystack.l_mark[-2].s, (void*)yystack.l_mark[0].n);}
break;
case 27:
#line 167 "minor.y"
	{/*IDprint(0,2);*/ IDpop(); /*IDprint(0,2);*/ yyval.n = triNode(FUNC, yystack.l_mark[-5].n, yystack.l_mark[-2].n, yystack.l_mark[0].n); returnevaluator(yystack.l_mark[-5].n->info,yystack.l_mark[0].n); forwardecltest2(yystack.l_mark[-5].n->info, yystack.l_mark[0].n->info);}
break;
case 28:
#line 170 "minor.y"
	{yyval.n = nilNode(DONE); yyval.n->info = FORWARDMASK;}
break;
case 29:
#line 171 "minor.y"
	{yyval.n = uniNode(DO, yystack.l_mark[0].n) ;yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 30:
#line 175 "minor.y"
	{yyval.n = binNode(FUNCTYPE, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = (yystack.l_mark[0].n->info | yystack.l_mark[-1].n->info);}
break;
case 31:
#line 176 "minor.y"
	{yyval.n = uniNode(FUNCTYPE,yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 32:
#line 179 "minor.y"
	{yyval.n = nilNode(TYPE); yyval.n->info = INTTYPE;}
break;
case 33:
#line 180 "minor.y"
	{yyval.n = nilNode(TYPE); yyval.n->info = ARRAYTYPE;}
break;
case 34:
#line 181 "minor.y"
	{yyval.n = nilNode(TYPE); yyval.n->info = STRINGTYPE;}
break;
case 35:
#line 182 "minor.y"
	{yyval.n = nilNode(TYPE); yyval.n->info = VOIDTYPE;}
break;
case 36:
#line 185 "minor.y"
	{yyval.n = binNode(INITIALIZERS, uniNode(INITER, yystack.l_mark[-1].n), yystack.l_mark[0].n);}
break;
case 37:
#line 186 "minor.y"
	{yyval.n = strNode(STR, yystack.l_mark[0].s);}
break;
case 38:
#line 189 "minor.y"
	{yyval.n = intNode(INT,yystack.l_mark[0].i);}
break;
case 39:
#line 190 "minor.y"
	{yyval.n = intNode(CHAR,yystack.l_mark[0].i);}
break;
case 40:
#line 191 "minor.y"
	{yyval.n = strNode(STR,yystack.l_mark[0].s);}
break;
case 41:
#line 194 "minor.y"
	{yyval.i = yystack.l_mark[0].i;}
break;
case 42:
#line 195 "minor.y"
	{yyval.i = -yystack.l_mark[0].i;}
break;
case 43:
#line 198 "minor.y"
	{yyval.n = binNode(LIST, nilNode(LISTEND),uniNode(INITER,yystack.l_mark[0].n));}
break;
case 44:
#line 199 "minor.y"
	{yyval.n = binNode(LIST, yystack.l_mark[-1].n, uniNode(INITER,yystack.l_mark[0].n));}
break;
case 45:
#line 203 "minor.y"
	{yyval.n = nilNode(QUALIIFIER); yyval.n->info = PUBLICMASK;}
break;
case 46:
#line 204 "minor.y"
	{yyval.n = nilNode(QUALIIFIER); yyval.n->info = FORWARDMASK;}
break;
case 47:
#line 207 "minor.y"
	{yyval.n = nilNode(EMPTY); yyval.n->info = 0;}
break;
case 48:
#line 208 "minor.y"
	{yyval.n = uniNode(ARG, yystack.l_mark[0].n); yyval.n->info = HASARGSMASK;}
break;
case 49:
#line 212 "minor.y"
	{yyval.n = binNode(ARGLIST, nilNode(LISTEND), yystack.l_mark[0].n);yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 50:
#line 213 "minor.y"
	{yyval.n = binNode(ARGLIST, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 51:
#line 217 "minor.y"
	{ IDnew(yystack.l_mark[-4].n->info,yystack.l_mark[-3].s,NULL); yyval.n = binNode(VARPOINTER, yystack.l_mark[-4].n,intNode(INDEX, yystack.l_mark[-1].i)); arrayIndexError(yystack.l_mark[-4].n->info); if(yystack.l_mark[-1].i == 0){yyerror("Nao existem arrays com dimensao zero");exit(1);} yyval.n->info = yystack.l_mark[-4].n->info;}
break;
case 52:
#line 218 "minor.y"
	{ IDnew(yystack.l_mark[-1].n->info,yystack.l_mark[0].s,NULL); yyval.n = uniNode(VAR, yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-1].n->info;}
break;
case 53:
#line 221 "minor.y"
	{yyval.n = binNode(BODY,yystack.l_mark[-1].n,yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 54:
#line 224 "minor.y"
	{yyval.n = nilNode(RETURNVOID); yyval.n->info = VOIDTYPE;}
break;
case 55:
#line 225 "minor.y"
	{yyval.n = uniNode(RETURNEXPR, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 56:
#line 226 "minor.y"
	{yyval.n = nilNode(EMPTY); yyval.n->info = UNKNOWN;}
break;
case 57:
#line 230 "minor.y"
	{yyval.n = binNode(BODYVARLIST, nilNode(LISTEND), yystack.l_mark[-1].n);}
break;
case 58:
#line 231 "minor.y"
	{yyval.n = binNode(BODYVARLIST, yystack.l_mark[-2].n, yystack.l_mark[-1].n);}
break;
case 59:
#line 234 "minor.y"
	{yyval.n = nilNode(EMPTY);}
break;
case 60:
#line 235 "minor.y"
	{yyval.n = uniNode(VARLIST, yystack.l_mark[0].n);}
break;
case 61:
#line 238 "minor.y"
	{yyval.n = intNode(INT,yystack.l_mark[0].i);}
break;
case 62:
#line 239 "minor.y"
	{yyval.n = intNode(CHAR, yystack.l_mark[0].i);}
break;
case 63:
#line 242 "minor.y"
	{yyval.n = triNode(IFTHEN,yystack.l_mark[-4].n,yystack.l_mark[-2].n,yystack.l_mark[-1].n); voidexpressionerror(yystack.l_mark[-4].n->info); yyval.n->info = yystack.l_mark[-2].n->info;}
break;
case 64:
#line 243 "minor.y"
	{yyval.n = quadNode(IFTHENELSE,yystack.l_mark[-6].n,yystack.l_mark[-4].n,yystack.l_mark[-3].n,yystack.l_mark[-1].n); voidexpressionerror(yystack.l_mark[-6].n->info); yyval.n->info = yystack.l_mark[-4].n->info;}
break;
case 65:
#line 244 "minor.y"
	{loopend++;}
break;
case 66:
#line 244 "minor.y"
	{loopend--;}
break;
case 67:
#line 244 "minor.y"
	{yyval.n = quadNode(FOR,yystack.l_mark[-9].n,yystack.l_mark[-7].n,yystack.l_mark[-5].n,yystack.l_mark[-2].n); voidexpressionerror(yystack.l_mark[-9].n->info); voidexpressionerror(yystack.l_mark[-7].n->info); voidexpressionerror(yystack.l_mark[-5].n->info); yyval.n->info = yystack.l_mark[-2].n->info;}
break;
case 68:
#line 245 "minor.y"
	{yyval.n = uniNode(EXPR, yystack.l_mark[-1].n); yyval.n->info = UNKNOWN;}
break;
case 69:
#line 246 "minor.y"
	{yyval.n = uniNode(PRINTEXPR, yystack.l_mark[-1].n); printerror(yystack.l_mark[-1].n->info); yyval.n->info = UNKNOWN;}
break;
case 70:
#line 247 "minor.y"
	{looperror(1);}
break;
case 71:
#line 247 "minor.y"
	{yyval.n = nilNode(REPEAT); yyval.n->info = UNKNOWN;}
break;
case 72:
#line 248 "minor.y"
	{looperror(0);}
break;
case 73:
#line 248 "minor.y"
	{yyval.n = nilNode(STOP); yyval.n->info = UNKNOWN;}
break;
case 74:
#line 249 "minor.y"
	{yyval.n = binNode(LEFTVALUE,yystack.l_mark[-3].n,yystack.l_mark[-1].n); yyval.n->info = UNKNOWN; heaperror(yystack.l_mark[-3].n->info, yystack.l_mark[-1].n->info);}
break;
case 75:
#line 252 "minor.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 76:
#line 253 "minor.y"
	{yyval.n = binNode(INSTRUCTLIST, yystack.l_mark[-1].n, yystack.l_mark[0].n);yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 77:
#line 256 "minor.y"
	{yyval.n = nilNode(EMPTY); yyval.n->info = UNKNOWN;}
break;
case 78:
#line 257 "minor.y"
	{yyval.n = binNode(ELIFT, yystack.l_mark[-2].n,yystack.l_mark[0].n); voidexpressionerror(yystack.l_mark[-2].n->info); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 79:
#line 260 "minor.y"
	{yyval.n = binNode(LIST, nilNode(LISTEND), yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 80:
#line 261 "minor.y"
	{yyval.n = binNode(LIST,yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 81:
#line 264 "minor.y"
	{yyval.n = strNode(ID, yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s, NULL);}
break;
case 82:
#line 265 "minor.y"
	{yyval.n = binNode(IDPOINTER,strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n); indexError(yystack.l_mark[-1].n->info); isPointer(IDfind(yystack.l_mark[-3].s,NULL)); yyval.n->info = INTTYPE;}
break;
case 83:
#line 266 "minor.y"
	{yyval.n = intNode(INTEGER, yystack.l_mark[0].i); if(yystack.l_mark[0].i != 0)yyval.n->info = INTTYPE; else yyval.n->info = UNKNOWN|INTTYPE;}
break;
case 84:
#line 267 "minor.y"
	{yyval.n = uniNode(STR, yystack.l_mark[0].n); yyval.n->info = STRINGTYPE;}
break;
case 85:
#line 268 "minor.y"
	{yyval.n = nilNode(READ); yyval.n->info = INTTYPE;}
break;
case 86:
#line 269 "minor.y"
	{yyval.n = intNode(CHARACTER,yystack.l_mark[0].i); yyval.n->info = INTTYPE;}
break;
case 87:
#line 270 "minor.y"
	{yyval.n = uniNode(FUNCALL, yystack.l_mark[-1].n); yyval.n->info = IDfind(yystack.l_mark[-3].s,NULL); funcerror(yystack.l_mark[-3].s, yystack.l_mark[-1].n);}
break;
case 88:
#line 271 "minor.y"
	{yyval.n = binNode(OR, yystack.l_mark[-2].n, yystack.l_mark[0].n); intypescheck(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 89:
#line 272 "minor.y"
	{yyval.n = binNode(AND, yystack.l_mark[-2].n, yystack.l_mark[0].n); intypescheck(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 90:
#line 273 "minor.y"
	{yyval.n = binNode(EQ, yystack.l_mark[-2].n, yystack.l_mark[0].n); intstrerror(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 91:
#line 274 "minor.y"
	{yyval.n = binNode(ADD, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = adderror(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info);}
break;
case 92:
#line 275 "minor.y"
	{yyval.n = binNode(SUBT, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = suberror(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info);}
break;
case 93:
#line 276 "minor.y"
	{yyval.n = binNode(MOD, yystack.l_mark[-2].n, yystack.l_mark[0].n); intypescheck(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 94:
#line 277 "minor.y"
	{yyval.n = binNode(DIV, yystack.l_mark[-2].n, yystack.l_mark[0].n); intypescheck(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 95:
#line 278 "minor.y"
	{yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); intstrerror(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 96:
#line 279 "minor.y"
	{yyval.n = binNode(GR, yystack.l_mark[-2].n, yystack.l_mark[0].n); intstrerror(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 97:
#line 280 "minor.y"
	{yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); intstrerror(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 98:
#line 281 "minor.y"
	{yyval.n = binNode(LS, yystack.l_mark[-2].n, yystack.l_mark[0].n); intstrerror(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 99:
#line 282 "minor.y"
	{yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); intstrerror(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 100:
#line 283 "minor.y"
	{yyval.n = binNode(POW, yystack.l_mark[-2].n, yystack.l_mark[0].n); intypescheck(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); typerror(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 101:
#line 284 "minor.y"
	{yyval.n = binNode(MUL, yystack.l_mark[-2].n, yystack.l_mark[0].n); intypescheck(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 102:
#line 285 "minor.y"
	{yyval.n = binNode(IEQ, yystack.l_mark[-2].n, yystack.l_mark[0].n);typerror(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); consterror(yystack.l_mark[-2].n->info); yyval.n->info = yystack.l_mark[-2].n->info;}
break;
case 103:
#line 286 "minor.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 104:
#line 287 "minor.y"
	{yyval.n = uniNode(ADDR, yystack.l_mark[0].n); addresserror(yystack.l_mark[0].n->info); yyval.n->info = INTTYPE;}
break;
case 105:
#line 288 "minor.y"
	{yyval.n = uniNode(NOT, yystack.l_mark[0].n); intypecheck(yystack.l_mark[0].n->info); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 106:
#line 289 "minor.y"
	{yyval.n = uniNode(MINUS, yystack.l_mark[0].n); intypecheck(yystack.l_mark[0].n->info); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 107:
#line 292 "minor.y"
	{yyval.n = binNode(LIST, nilNode(LISTEND), yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 108:
#line 293 "minor.y"
	{yyval.n = binNode(LIST,yystack.l_mark[-2].n, yystack.l_mark[0].n);yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 109:
#line 297 "minor.y"
	{yyval.n = strNode(ID, yystack.l_mark[0].s); /*printf("%s\n", $1);*/ funcheck(IDfind(yystack.l_mark[0].s,NULL)); yyval.n->info = IDfind(yystack.l_mark[0].s, NULL);}
break;
case 110:
#line 298 "minor.y"
	{yyval.n = binNode(IDPOINTER,strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n); indexError(yystack.l_mark[-1].n->info); isPointer(IDfind(yystack.l_mark[-3].s,NULL)); funcheck(IDfind(yystack.l_mark[-3].s,NULL)); yyval.n->info = INTTYPE;}
break;
#line 1894 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
