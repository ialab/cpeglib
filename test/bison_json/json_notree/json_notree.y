/* Infix notation calculator.  */
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void yyerror(const char *s);
%}

%union{
    char *cval;
 }
%token <cval> NUMBER
%token <cval> STRING
%token <cval> true false null
%left  <cval> R_CUR L_CUR R_SQU L_SQU
%left  <cval> COMMA
%left  <cval> COLON
%type <cval> OBJECT MEMBERS ARRAY ELEMENTS VALUE START

%start START

%%

START
: VALUE {
}
;

OBJECT:
L_CUR R_CUR {
}
| L_CUR MEMBERS R_CUR {
}
;

MEMBERS:
STRING COLON VALUE {
}
| MEMBERS COMMA STRING COLON VALUE {
}
;

ARRAY
: L_SQU R_SQU {
}
| L_SQU ELEMENTS R_SQU {
}
;

ELEMENTS
: VALUE {
}
| ELEMENTS COMMA VALUE {
}
;

VALUE
: STRING {$$ = yylval.cval;}
| NUMBER {$$ = yylval.cval;}
| ARRAY {$$ = $1;}
| OBJECT {$$ = $1;}
| true {$$ = "true";}
| false {$$ = "false";}
| null {$$ = "null";}
;

%%
  //ファイル入力
int main(int argc, char **argv) {
    FILE *fp;
    extern FILE *yyin;
    if (argc >= 2) {
        if (!(fp = fopen(argv[1], "r"))) {
            fprintf(stderr, "File [%s] is not found!\n", argv[1]);
            return 1;
        }
    }
    clock_t s, e; //msec
    yyin = fp;
    s = clock();
    if (yyparse())
        printf("json parse error!\n");
    e = clock();
    printf("%f\n", (double)(e-s)/CLOCKS_PER_SEC*1000);
    return 0;
}

void yyerror (char const *s) {
  fprintf (stderr, "error : %s\n", s);
}
