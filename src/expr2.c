#define CPEG_VALUE_TYPE int

#include "cpeglib.h"

/* 3. 文法定義部分 */

/*
  START <- E
  E <- T '+' E / T
  T <- P '*' T / P
  P <- '0' / '1' / ... / '9' / '(' E ')'
*/

DECLARE_RULES(E, P, T, SP);
cpeg_charset_t digits;

RULE(SP,
     {
       ALT(SEQ(ALT(CHAR(' '), CHAR('\n'), CHAR('\t')), SP()),
	   {});
     })

#define TOKEN(e) SEQ(SP(), e)

RULE(START,
     {
       cs_range(digits, '0', '9');
       E();
     })

RULE(E,
     {
       int v1;
       ALT(SEQ(T(), v1=val, TOKEN(CHAR('+')), E(), val = val + v1),
	   T());
     })

RULE(T,
     {
       int v1;
       ALT(SEQ(P(), v1=val, TOKEN(CHAR('*')), T(), val = val * v1),
	   P());
     })

RULE(P,
     {
       int v1;
       ALT(SEQ(TOKEN(CHARSET(digits)),
	       (val = val - '0')),
	   SEQ(TOKEN(CHAR('(')), E(), v1 = val, TOKEN(CHAR(')')), val = v1));
     })
