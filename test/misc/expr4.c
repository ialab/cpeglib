#define CPEG_VALUE_TYPE int
/* #define CPEG_DO_MEMOIZE (0) */
#include "cpeglib.h"
#include <stdio.h>

/*
  START <- E
  E <- P '+' E ';'? / P
  P <- '0' / '1' / ... / '9'
*/

DECLARE_RULES(E, P);
cpeg_charset_t digits;

BEGIN_RULE(START)
     {
       cs_range(digits, '0', '9');
       E();
     }
END_RULE

BEGIN_RULE(E)
     {
       int v1, v2;
       ALT(SEQ(P(), v1=val, CHAR('+'), E(), v2 = val, OPTION(CHAR(';')), val = v1 + v2),
	   P());
     }
END_RULE

long counter;
BEGIN_RULE(P)
     {
       counter++;
       SEQ(CHARSET(digits), (val = val - '0'));
     }
END_RULE

int main(int argc, char *argv[]) {
  cpeg_main(argc, argv);
  printf("counter = %ld\n", counter);
  return 0;
}
