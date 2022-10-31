%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"
int hexchar(char*);
int hex(char*);
int octal(char*);
int bin(char*);
int atoioverflow(char*);
const char* printint(int);
extern void yyerror(const char *msg);
char *dupstr(const char *s);
int yywrap(void);
int active = 0;
%}
%x STRINGS ACTIVE ENDED COM COM2
%%

program[ \t\n\r] BEGIN ACTIVE; return PROGRAM; 
module[ \t\n\r]  BEGIN ACTIVE; return MODULE;


<ACTIVE>">=" return GE; 
<ACTIVE>"<=" return LE;  
<ACTIVE>":=" return IEQ;
<ACTIVE>"~=" return NE;
<ACTIVE>"start" return START;
<ACTIVE>"end" BEGIN ENDED;return END;
<ACTIVE>"void" return VOID;
<ACTIVE>"const" return CONST;
<ACTIVE>"number" return NUMBER;
<ACTIVE>"array" return ARRAY;
<ACTIVE>"string" return STRING;
<ACTIVE>"function" return FUNCTION;
<ACTIVE>"public" return PUBLIC;
<ACTIVE>"forward" return FORWARD;
<ACTIVE>"if" return IF;
<ACTIVE>"then" return THEN;
<ACTIVE>"else" return ELSE;
<ACTIVE>"elif" return ELIF;
<ACTIVE>"fi" return FI;
<ACTIVE>"for" return FOR;
<ACTIVE>"until" return UNTIL;
<ACTIVE>"step" return STEP;
<ACTIVE>"do" return DO;
<ACTIVE>"done" return DONE;
<ACTIVE>"repeat" return REPEAT;
<ACTIVE>"stop" return STOP;
<ACTIVE>"return" return RETURN;

<ACTIVE>\"([^*"]|\*.)*\"  yylval.s = malloc(yyleng); *yylval.s = 0; REJECT;
<ACTIVE>\" BEGIN STRINGS;
<ACTIVE>'\\(0[A-Fa-f0-9]*)' yylval.i = hexchar(yytext); return CHAR;
<ACTIVE>'\\([A-Fa-f0-9]+)' yylval.i = hexchar(yytext); return CHAR;
<ACTIVE>'(\\n|\\r|\\t|\"|\\'|\\\\)' yylval.i = *(yytext+1); return CHAR;
<ACTIVE>'[^\\]' yylval.i = yytext[1]; return CHAR;
<ACTIVE>0[0-7]+ yylval.i = octal(yytext); return INTEGER;
<ACTIVE>0x[A-Fa-f0-9]+ yylval.i = hex(yytext); return INTEGER;
<ACTIVE>0b[0-1]+ yylval.i = bin(yytext); return INTEGER;
<ACTIVE>0|([1-9][0-9]*) yylval.i = atoioverflow(yytext); return INTEGER;
<ACTIVE>[A-Za-z][A-Za-z0-9_]* yylval.s = dupstr(yytext); return VARNAME;

<ACTIVE>\$\$ BEGIN COM; /*Comentarios*/
<ACTIVE>\$ BEGIN COM2;     /*Comentarios*/
<ACTIVE>[ \t\n\r]+ ;
<ACTIVE>\-|\+|\*|\/|\%|\^|\>|\<|\=|\||\&|\~|\? return *yytext;
<ACTIVE>\[|\]|\;|\(|\)|\#|\:|\!|\, return *yytext;
<ACTIVE>.       ECHO; yyerror("Unkown character");

<COM>\n BEGIN ACTIVE;
<COM>. ;

<COM2>\$ BEGIN ACTIVE;
<COM2>.|\n ;


<STRINGS>\" BEGIN ACTIVE; return STR;
<STRINGS>\\n|\\r|\\t|\\|\\\" strcat(yylval.s, yytext+1);
<STRINGS>[^\"]* strcat(yylval.s, yytext);

<ENDED>.|\n ;
.|\n ;

%%



const char* printint(int i){
    char* result = (char *) malloc(sizeof(char) * 25);
    sprintf(result, "%d", i);
    return result;
}

int atoioverflow(char *s){
  int i = atoi(s);
  if(i < 0){
    yyerror("Decimal overflow");
  }
  return i;
}

int octal(char *s){
  int i, a = 0, b = 0;
  for (i = 0; i < strlen(s); i++) {
    if (s[i] < '0' || s[i] > '7') break;
    b = b * 8 + s[i] - '0';
    if (b < a) {
      yyerror("octal overflow");
      break;
    }
    a = b;
  }
  return a;
}

int hexchar(char *s){
  int i, a = 0, b = 0;
  for (i = 2; i < strlen (s); i++){
    if (s[i] >= '0' && s[i] <= '9'){
        b = b * 16 + s[i] - '0';
    }
    if (s[i] >= 'A' && s[i] <= 'F'){
      b = b * 16 + s[i] - 'A' + 10;
    }
    if (s[i] >= 'a' && s[i] <= 'a'){
      b = b * 16 + s[i] - 'a' + 10;
    }
    if ((b < a) || (b > 255)){
      yyerror("hex overflow");
      break;
    }
  }
  a = b;
  return a;
}

int bin(char *s){
  int i, a = 0, b = 0;
  for (i = 2; i < strlen (s); i++){
    if (s[i] < '0' || s[i] > '1')
           break;
    b = b * 2 + s[i] - '0';
    if (b < a){
    yyerror("bin overflow");
    break;
    }
  }
  a = b;
  return a;
}

int hex(char *s){
  int i, a = 0, b = 0;
  for (i = 2; i < strlen (s); i++){
    if (s[i] >= '0' && s[i] <= '9'){
        b = b * 16 + s[i] - '0';
    }
    if (s[i] >= 'A' && s[i] <= 'F'){
      b = b * 16 + s[i] - 'A' + 10;
    }
    if (s[i] >= 'a' && s[i] <= 'a'){
      b = b * 16 + s[i] - 'a' + 10;
    }
    if (b < a){
      yyerror("hex overflow");
      break;
    }
  }
  a = b;
  return a;
}

int yywrap(void) {
 if (YYSTATE == STRINGS) yyerror("unterminated string");
 if ((YYSTATE == COM) || (YYSTATE == COM2)) yyerror("unterminated comment");
  return 1; } 
char *getyytext() { return yytext; }

