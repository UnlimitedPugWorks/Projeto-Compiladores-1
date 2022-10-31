%{
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


%}

%union {
	int i;			/* integer value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* node pointer */
}


/*
  Tokens vindos do LEX
*/
%token <i> INTEGER CHAR
%token <s> VARNAME STR
%token FUNCTION MODULE START VOID CONST NUMBER 
%token ARRAY STRING PUBLIC FORWARD IF FI THEN FOR ELSE ELIF PROGRAM END 
%token UNTIL STEP DO DONE REPEAT STOP RETURN GE LE EQ NE

/*
  Tokens no Node
*/
%token ADD OR EQ SUBT MOD ADDR LS GR POW ID AND MINUS DIV NOT IDPOINTER MUL
%token ARG
%token PROGRAM PROGRAMDEC MODULE MODULEDEC
%token ELIFT RETURNEXPR RETURNVOID BODYVARLIST BODYINST BODYVAR 
%token QUALIIFIER QUALTYPE
%token INSTRUCTLIST
%token IFTHEN IFTHENELSE
%token DECLIST DECLTYPE ARGLIST
%token INT VAR
%token PRINTEXPR
%token LEFTVALUE
%token EMPTY LISTEND SETEND
%token VARDEC FUNCDEC BODY
%token LITYPE LITERALSET LITERALIST
%token TYPE FUNCTYPE
%token FICHEIRO 
%token TYPE
%token VARPOINTER VARLIST VARPOINTERDEC
%token SET LIST INDEX
%token FUNCBODY FUNC PROGBODY FUNCALL
%token READ
%token EXPR
%token CHARACTER
%token INITER INITIALIZERS


/*Associatividade*/
%right '^' IEQ
%left GE LE EQ NE '>' '<' '=' 
%left '+' '-' '*' '/' '%' 
%left '&' '|'
%nonassoc '(' ')' '~' '?' '[' ']'

/*Precs*/
%nonassoc ADDRESS UMINUS

/*Node types*/
%type <n> ficheiro
%type <n> programa modulo
%type <n> funcao functype args argsopt elifopt funcdone
%type <n> variavel
%type <n> expressao corpo corpovar returns
%type <n> qualificador tipo
%type <n> declaracoes declaracao decltype
%type <n> literal literaltype literalist
%type <n> instrucoes instructopt instrucao
%type <n> leftvalue expresionlist varopt
%type <n> cadeias iniciadores iniciador
%type <i> inteiro


%% 

file     : ficheiro {printNode($1, 0, yynames);}

ficheiro : programa {$$ = uniNode(FICHEIRO, $1);} /*ok*/  
		 | modulo   {$$ = uniNode(FICHEIRO, $1);} /*ok*/  
		 ;
		

programa : PROGRAM START {IDpush();} corpo END /*ok*/ {$$ = uniNode(PROGBODY, $4); returnevaluator(MAINTYPE, $4); IDpop();}
		 | PROGRAM declaracoes START {IDpush();} corpo END {$$ = binNode(PROGRAMDEC, $2,$5); returnevaluator(MAINTYPE, $5); IDpop();} /*ok*/
		 ;


modulo : MODULE END              {$$ = nilNode(MODULE);}
	   | MODULE declaracoes END  {$$ = uniNode(MODULEDEC, $2);}
	   ;

declaracoes : declaracao                   {$$ = binNode(DECLIST, nilNode(LISTEND), $1);}
			| declaracoes ';' declaracao   {$$ = binNode(DECLIST, $1, $3);}
		   	;

declaracao : funcao                                             {$$ = uniNode(FUNCDEC, $1);}
		   | decltype tipo VARNAME  literaltype                 {$$ = triNode(VARDEC, $1,$2,$4); voiderror($2->info); forwardecltest($1->info, $4->info); IDnew(($2->info|$1->info),$3,NULL); /*if(($2->info & TYPEMASK) == ARRAYTYPE){yyerror("Os arrays tem de ter dimensão");}*/}
	  	   | decltype tipo VARNAME '[' INTEGER ']' literaltype  {$$ = quadNode(VARPOINTERDEC,$1,$2,intNode(INDEX, $5),$7); declerror($2->info,$7->info);arrayIndexError($2->info); voiderror($2->info);forwardecltest($1->info, $7->info); if($5 == 0){yyerror("Nao existem arrays com dimensao zero");} if(($2->info & TYPEMASK) != ARRAYTYPE){yyerror("Só os arrays é que tem dimensão");} IDnew(($2->info | $1->info),$3,NULL);}
		   ;

decltype : qualificador CONST              {$$ = binNode(DECLTYPE,$1,nilNode(CONST)); $$->info = ($1->info | CONSTMASK);}
		 | qualificador		  			   {$$ = uniNode(QUALTYPE,$1); $$->info = ($1->info);}
		 | CONST                           {$$ = nilNode(CONST); $$->info = CONSTMASK;}
		 |                                 {$$ = nilNode(EMPTY); $$->info = 0;}
		 ;

literaltype : IEQ literal     {$$ = uniNode(LITYPE, $2); $$->info = INTTYPE;}
			| IEQ inteiro ',' literalist {$$ = binNode(LITERALIST, intNode(INT,$2),$4); $$->info = ARRAYTYPE;}
			| IEQ cadeias     {$$ = uniNode(LITERALSET, $2); $$->info = STRINGTYPE;}
 			|              	  {$$ = nilNode(EMPTY); $$->info = FORWARDMASK|UNKNOWN;}
			;


literalist : inteiro                {$$ = binNode(LIST,nilNode(LISTEND),intNode(INT,$1));}
           | literalist ',' inteiro {$$ = binNode(LIST,$1, intNode(INT,$3));}
           ;


funcao : FUNCTION functype VARNAME {forwardtest($3, FUNCMASK|$2->info); /*printf("A funcão é %s = %d\n", $3, IDfind($3,NULL));*/ /*IDprint(0,2);*/ IDpush();} argsopt {IDreplace(IDfind($3, NULL)|$5->info, $3, (void*)$5);} funcdone {/*IDprint(0,2);*/ IDpop(); /*IDprint(0,2);*/ $$ = triNode(FUNC, $2, $5, $7); returnevaluator($2->info,$7); forwardecltest2($2->info, $7->info);}
   	   ;

funcdone : DONE           {$$ = nilNode(DONE); $$->info = FORWARDMASK;}
		 | DO corpo       {$$ = uniNode(DO, $2) ;$$->info = $2->info;}
		 ;


functype : qualificador tipo {$$ = binNode(FUNCTYPE, $1, $2); $$->info = ($2->info | $1->info);}
		 | tipo 			 {$$ = uniNode(FUNCTYPE,$1); $$->info = $1->info;}
		 ;

tipo : NUMBER {$$ = nilNode(TYPE); $$->info = INTTYPE;}
	 | ARRAY  {$$ = nilNode(TYPE); $$->info = ARRAYTYPE;}
	 | STRING {$$ = nilNode(TYPE); $$->info = STRINGTYPE;}
	 | VOID   {$$ = nilNode(TYPE); $$->info = VOIDTYPE;}
	 ;

cadeias : iniciador iniciadores  {$$ = binNode(INITIALIZERS, uniNode(INITER, $1), $2);}
		| STR                    {$$ = strNode(STR, $1);}
		;

iniciador : INTEGER  {$$ = intNode(INT,$1);}  
		  | CHAR     {$$ = intNode(CHAR,$1);}
		  | STR      {$$ = strNode(STR,$1);}
		  ;

inteiro   : INTEGER     {$$ = $1;}
		  | '-' INTEGER {$$ = -$2;}
		  ;

iniciadores : iniciador {$$ = binNode(LIST, nilNode(LISTEND),uniNode(INITER,$1));}
            | iniciadores iniciador {$$ = binNode(LIST, $1, uniNode(INITER,$2));}
            ;
			

qualificador : PUBLIC   {$$ = nilNode(QUALIIFIER); $$->info = PUBLICMASK;}
			 | FORWARD  {$$ = nilNode(QUALIIFIER); $$->info = FORWARDMASK;}
			 ;

argsopt :                   {$$ = nilNode(EMPTY); $$->info = 0;}
		| args              {$$ = uniNode(ARG, $1); $$->info = HASARGSMASK;}    
		;


args     : variavel          {$$ = binNode(ARGLIST, nilNode(LISTEND), $1);$$->info = $1->info;}
		 | args ';' variavel {$$ = binNode(ARGLIST, $1, $3); $$->info = $3->info;}
		 ;


variavel : tipo VARNAME '[' INTEGER ']' { IDnew($1->info,$2,NULL); $$ = binNode(VARPOINTER, $1,intNode(INDEX, $4)); arrayIndexError($1->info); if($4 == 0){yyerror("Nao existem arrays com dimensao zero");exit(1);} $$->info = $1->info;}
		 | tipo VARNAME					{ IDnew($1->info,$2,NULL); $$ = uniNode(VAR, $1); $$->info = $1->info;}
		 ;

corpo : varopt instructopt {$$ = binNode(BODY,$1,$2); $$->info = $2->info;}
	  ;

returns : RETURN              {$$ = nilNode(RETURNVOID); $$->info = VOIDTYPE;}
		| RETURN expressao    {$$ = uniNode(RETURNEXPR, $2); $$->info = $2->info;}
		|                     {$$ = nilNode(EMPTY); $$->info = UNKNOWN;}
		;


corpovar : variavel ';'          {$$ = binNode(BODYVARLIST, nilNode(LISTEND), $1);}
		 | corpovar variavel ';' {$$ = binNode(BODYVARLIST, $1, $2);}
		 ;

varopt   :						{$$ = nilNode(EMPTY);}
		 | corpovar             {$$ = uniNode(VARLIST, $1);}
		 ;  

literal :  INTEGER {$$ = intNode(INT,$1);}
		|  CHAR    {$$ = intNode(CHAR, $1);}
		;

instrucao : IF expressao THEN instructopt elifopt FI                           {$$ = triNode(IFTHEN,$2,$4,$5); voidexpressionerror($2->info); $$->info = $4->info;}
		  | IF expressao THEN instructopt elifopt ELSE instructopt FI          {$$ = quadNode(IFTHENELSE,$2,$4,$5,$7); voidexpressionerror($2->info); $$->info = $4->info;}
		  | FOR expressao UNTIL expressao STEP expressao DO {loopend++;} instructopt {loopend--;} DONE   {$$ = quadNode(FOR,$2,$4,$6,$9); voidexpressionerror($2->info); voidexpressionerror($4->info); voidexpressionerror($6->info); $$->info = $9->info;}
		  | expressao ';' 	                                                   {$$ = uniNode(EXPR, $1); $$->info = UNKNOWN;}
		  | expressao '!' 	                                                   {$$ = uniNode(PRINTEXPR, $1); printerror($1->info); $$->info = UNKNOWN;}
		  | {looperror(1);} REPEAT                                             {$$ = nilNode(REPEAT); $$->info = UNKNOWN;}
	  	  | {looperror(0);} STOP                                               {$$ = nilNode(STOP); $$->info = UNKNOWN;}
  	  	  | leftvalue '#' expressao ';'                                        {$$ = binNode(LEFTVALUE,$1,$3); $$->info = UNKNOWN; heaperror($1->info, $3->info);}
  	  	  ;

instructopt:returns            {$$ = $1;}
		  | instrucoes returns {$$ = binNode(INSTRUCTLIST, $1, $2);$$->info = $2->info;}
		  ;

elifopt : 						   		 {$$ = nilNode(EMPTY); $$->info = UNKNOWN;}
		| ELIF expressao THEN instructopt {$$ = binNode(ELIFT, $2,$4); voidexpressionerror($2->info); $$->info = $4->info;}
		;

instrucoes : instrucao             {$$ = binNode(LIST, nilNode(LISTEND), $1); $$->info = $1->info;}
		   | instrucoes instrucao  {$$ = binNode(LIST,$1, $2); $$->info = $2->info; }
		   ;

expressao : VARNAME  	{$$ = strNode(ID, $1); $$->info = IDfind($1, NULL);}
		  | VARNAME '[' expressao ']' {$$ = binNode(IDPOINTER,strNode(ID, $1), $3); indexError($3->info); isPointer(IDfind($1,NULL)); $$->info = INTTYPE;}
		  | INTEGER  	{$$ = intNode(INTEGER, $1); if($1 != 0)$$->info = INTTYPE; else $$->info = UNKNOWN|INTTYPE;} 
		  | cadeias        {$$ = uniNode(STR, $1); $$->info = STRINGTYPE;}
		  | '?'         {$$ = nilNode(READ); $$->info = INTTYPE;}
		  | CHAR        {$$ = intNode(CHARACTER,$1); $$->info = INTTYPE;}
		  | VARNAME '(' expresionlist ')' {$$ = uniNode(FUNCALL, $3); $$->info = IDfind($1,NULL); funcerror($1, $3);}
		  | expressao '|' expressao {$$ = binNode(OR, $1, $3); intypescheck($1->info, $3->info); $$->info = INTTYPE;}
		  | expressao '&' expressao {$$ = binNode(AND, $1, $3); intypescheck($1->info, $3->info); $$->info = INTTYPE;}
		  | expressao '=' expressao {$$ = binNode(EQ, $1, $3); intstrerror($1->info, $3->info); $$->info = INTTYPE;}
		  | expressao '+' expressao {$$ = binNode(ADD, $1, $3); $$->info = adderror($1->info, $3->info);}
		  | expressao '-' expressao {$$ = binNode(SUBT, $1, $3); $$->info = suberror($1->info, $3->info);}
		  | expressao '%' expressao {$$ = binNode(MOD, $1, $3); intypescheck($1->info, $3->info); $$->info = INTTYPE;}
		  | expressao '/' expressao {$$ = binNode(DIV, $1, $3); intypescheck($1->info, $3->info); $$->info = INTTYPE;}
		  | expressao GE expressao  {$$ = binNode(GE, $1, $3); intstrerror($1->info, $3->info); $$->info = INTTYPE;}
		  | expressao '>' expressao {$$ = binNode(GR, $1, $3); intstrerror($1->info, $3->info); $$->info = INTTYPE;}
		  | expressao LE expressao  {$$ = binNode(LE, $1, $3); intstrerror($1->info, $3->info); $$->info = INTTYPE;}
		  | expressao '<' expressao {$$ = binNode(LS, $1, $3); intstrerror($1->info, $3->info); $$->info = INTTYPE;}
		  | expressao NE expressao  {$$ = binNode(NE, $1, $3); intstrerror($1->info, $3->info); $$->info = INTTYPE;}
		  | expressao '^' expressao {$$ = binNode(POW, $1, $3); intypescheck($1->info, $3->info); typerror($1->info, $3->info); $$->info = INTTYPE;}
		  | expressao '*' expressao {$$ = binNode(MUL, $1, $3); intypescheck($1->info, $3->info); $$->info = INTTYPE;}
		  | leftvalue IEQ expressao {$$ = binNode(IEQ, $1, $3);typerror($1->info, $3->info); consterror($1->info); $$->info = $1->info;}
		  | '(' expressao ')'       {$$ = $2;}
		  | '&' leftvalue %prec ADDRESS {$$ = uniNode(ADDR, $2); addresserror($2->info); $$->info = INTTYPE;}
		  | '~' expressao {$$ = uniNode(NOT, $2); intypecheck($2->info); $$->info = $2->info;}
		  | '-' expressao %prec UMINUS  {$$ = uniNode(MINUS, $2); intypecheck($2->info); $$->info = $2->info;}
		  ;

expresionlist : expressao                    {$$ = binNode(LIST, nilNode(LISTEND), $1); $$->info = $1->info;}
			  | expresionlist ',' expressao  {$$ = binNode(LIST,$1, $3);$$->info = $3->info;}
			  ;


leftvalue: VARNAME                   {$$ = strNode(ID, $1); /*printf("%s\n", $1);*/ funcheck(IDfind($1,NULL)); $$->info = IDfind($1, NULL);}
		 | VARNAME '[' expressao ']' {$$ = binNode(IDPOINTER,strNode(ID, $1), $3); indexError($3->info); isPointer(IDfind($1,NULL)); funcheck(IDfind($1,NULL)); $$->info = INTTYPE;}
		 ;

%%
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


