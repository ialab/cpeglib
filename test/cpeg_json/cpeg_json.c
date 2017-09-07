#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CPEG_VALUE_TYPE int
#include "../../src/cpeglib.h"
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <regex.h>
#include <time.h>

/* 3. 文法定義部分 */
// メモ: RFC4627を参照すること．

/*
START   -> value
value   -> object / array / number / string / true / false / null
object  -> '{' member (',' member)* '}'
member  -> string ':' value
array   -> '[' value (',' value)* ']'
string  -> ...
number  -> ...
int     -> ...
*/

DECLARE_RULES(START, V, O, M, A, S, ESC ,N, INT, TRU, FAL, NUL);

cpeg_charset_t str;
cpeg_charset_t digit;
cpeg_charset_t digit19;
cpeg_charset_t hex_digit_set;
cpeg_charset_t space;

#define TOKEN(e) SEQ(REPEAT0(CHARSET(space)), e)
#define T_CHAR(c) TOKEN(CHAR(c))
#define T_STR(s) TOKEN(STR(s))

BEGIN_RULE(START) {
    V();
} END_RULE

BEGIN_RULE(V) {
    ALT(O(), A(), N(), S(), TRU(), FAL(), NUL());
} END_RULE

BEGIN_RULE(TRU) {
    T_STR("true");
} END_RULE

BEGIN_RULE(FAL) {
    T_STR("false");
} END_RULE

BEGIN_RULE(NUL) {
    T_STR("null");
} END_RULE

BEGIN_RULE(O) {
    SEQ(T_CHAR('{'), M(), REPEAT0(SEQ(T_CHAR(','), M())),T_CHAR('}'));
} END_RULE

BEGIN_RULE(M) {
    SEQ(S(), T_CHAR(':'), V());
  } END_RULE

BEGIN_RULE(A) {
    SEQ(T_CHAR('['), V(), REPEAT0(SEQ(T_CHAR(','), V())),T_CHAR(']'));
} END_RULE

BEGIN_RULE(S) {
    SEQ(T_CHAR('"'),
        REPEAT0(ALT(CHARSET(str),
  		    SEQ(CHAR('\\'),ALT(SEQ(CHAR('u'),
                           CHARSET(hex_digit_set),
                           CHARSET(hex_digit_set),
                           CHARSET(hex_digit_set),
                           CHARSET(hex_digit_set)),
                       CHAR('n'),
                       CHAR('r'),
                       CHAR('t'),
                       SEQ(NOTPRE(CHAR('u')), ANY())
                       )))),
        CHAR('"'));
} END_RULE

BEGIN_RULE(ESC) {
} END_RULE

BEGIN_RULE(N) {
    TOKEN(SEQ(OPTION(CHAR('-')),
            INT(),
            OPTION(SEQ(CHAR('.'),REPEAT1(CHARSET(digit)))),
            OPTION(SEQ(ALT(CHAR('E'), CHAR('e')),
                       OPTION(ALT(CHAR('-'), CHAR('+'))),
                       REPEAT1(CHARSET(digit)))))
        );
} END_RULE

BEGIN_RULE(INT) {
    TOKEN(ALT(CHAR('0'),
            SEQ(CHARSET(digit19), REPEAT0(CHARSET(digit)))));
} END_RULE

#define PRINT_STAT(name) \
  printf(#name " miss/called = %ld/%ld\n", cpeg_ ## name ## _missed, cpeg_ ## name ## _called)

static void print_stats(void) {
#if CPEG_DO_COUNT
  PRINT_STAT(START);
  PRINT_STAT(V);
  PRINT_STAT(O);
  PRINT_STAT(M);
  PRINT_STAT(A);
  PRINT_STAT(S);
  PRINT_STAT(N);
  PRINT_STAT(INT);
  PRINT_STAT(TRU);
  PRINT_STAT(FAL);
  PRINT_STAT(NUL);
#endif
}

int main(int argc, char *argv[]) {

  cs_range(digit, '0', '9');

  cs_range(digit19, '1', '9');

  cs_range(hex_digit_set, '0', '9');
  cs_range(hex_digit_set, 'a', 'f');
  cs_range(hex_digit_set, 'A', 'F');

  cs_simple(str, '"');
  cs_simple(str, '\\');
  cs_complement(str);

  cs_simple(space, ' ');
  cs_simple(space, '\t');
  cs_simple(space, '\n');
  cs_simple(space, '\r');
  cs_simple(space, '\f');

  clock_t s, e;   //時間計測用(msec)
  s = clock();
  cpeg_main(argc, argv);
  e = clock();
  //printf("%d\n", CLOCKS_PER_SEC);
  printf("%f\n", (double)(e-s)/CLOCKS_PER_SEC*1000);

  print_stats();
  return 0;
}
