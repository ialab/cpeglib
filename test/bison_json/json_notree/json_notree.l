%{
#include <stdio.h>
#include "y.tab.h"

int yywrap(void){ return 1;}

%}

DIGIT     [0-9]
DIGIT1to9 [1-9]
HEXDIG    {DIGIT}|[A-F]
FOUR_HEX  {HEXDIG}{HEXDIG}{HEXDIG}{HEXDIG}
DIGITS    {DIGIT}+
INT       {DIGIT}|{DIGIT1to9}{DIGITS}|[-]{DIGIT}|[-]{DIGIT1to9}{DIGITS}
NUMB      {INT}|{INT}{FRAC}|{INT}{EXP}|{INT}{FRAC}{EXP}
FRAC      [.]{DIGITS}
EXP       {E}{DIGITS}
E         [eE][+-]?

CHAR      {UNESCAPED}|{ESCAPE}
CHARS     {CHAR}*
UNESCAPED [^\"\\]
ESCAPE    {ESC}([\"]|[\\]|[b]|[f]|[n]|[r]|[t]|([u]{FOUR_HEX}))
DBL_Q     [\"]
ESC       [\\]

%%
{DBL_Q}{CHARS}{DBL_Q} {
    yylval.cval = strdup(yytext);
    return STRING;
};

{NUMB} {
    yylval.cval = strdup(yytext);
    return NUMBER;
};

true {
    return true;
}

false {
    return false;
}

null {
    return null;
}

\}       return R_CUR;
\{       return L_CUR;
\]       return R_SQU;
\[       return L_SQU;
,        return COMMA;
:        return COLON;
[ \t\n]+             ;

. {
    printf("Unexpected: %s\nExiting...\n", yytext);
    exit(0);
}

%%
