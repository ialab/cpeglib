#define CPEG_VALUE_TYPE int
/* #define CPEG_DO_MEMOIZE (0) */
#define CPEG_DO_COUNT (1)	/* 呼び出し回数・ミス回数をカウントする */
#include "cpeglib.h"
#include <stdio.h>

/*
  START <- E
  E <- P '+' E ';' / P '+' E / P
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
       ALT(SEQ(P(), v1=val, CHAR('+'), E(), v2 = val + v1, CHAR(';'), val = v2),
	   SEQ(P(), v1=val, CHAR('+'), E(), val = val + v1),
	   P());
     }
END_RULE

/* 以下はメモ化しない 
#undef CPEG_DO_MEMOIZE
#define CPEG_DO_MEMOIZE 0
*/

/* 以下は，メモ化表サイズを4096にする
#undef CPEG_MEMO_SIZE
#define CPEG_MEMO_SIZE 4096
 */

BEGIN_RULE(P)
     {
       SEQ(CHARSET(digits), (val = val - '0'));
     }
END_RULE

int main(int argc, char *argv[]) {
  printf("CPEG_DO_MEMOIZE = %d, CPEG_MEMO_SIZE = %d\n", CPEG_DO_MEMOIZE, CPEG_MEMO_SIZE);
  cpeg_main(argc, argv);

#if CPEG_DO_COUNT
  printf("E missed/called = %ld/%ld, P missed/called = %ld/%ld\n",
	 cpeg_E_missed, cpeg_E_called,
	 cpeg_P_missed, cpeg_P_called);
#endif
  
  return 0;
}
