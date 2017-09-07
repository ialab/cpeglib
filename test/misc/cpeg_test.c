#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define CPEG_VALUE_TYPE int
#include "cpeglib.h"


/* 3. 文法定義部分 */

/*
START -> A E1 A ;
E1  -> A T1 A + A E1 A / A E1 A
T1  -> A P1 A + A T1 A / A P1 A
P1  -> A D N A / A ( A E1 A ) A 
N   -> D N / e
D   -> 0~9
A   -> A B / e
B   -> ' ' / '\n'
*/

void START(void);
void E(void);
void T(void);
void P(void);
/*
void NUM(void);
void Number(int);
void Digit(void);
*/
void N(int);
void D(void);
void A(void);
void B(void);

cpeg_charset_t digit, alpha, alnum;

BEGIN_RULE(START) {
  int v1;
  SEQ(A(), E(), v1=val, A(), CHAR(';'), val=v1, pos = pos-1);
} END_RULE

BEGIN_RULE(E) {
  int v1, v2;
  ALT(SEQ(SEQ(A(), T(), v1=val, A(), CHAR('+')),
	  SEQ(A(), E(), v2=val, A(), val = v1 + v2)),
      SEQ(A(), T(), v1=val, A(), val=v1));
} END_RULE

BEGIN_RULE(T) {
  int v1, v2;
  ALT(SEQ(SEQ(A(), P(), v1=val, A(), CHAR('*')),
	  SEQ(A(), T(), v2=val, A(), val = v1 * v2)),
      SEQ(A(), P(), v1=val, A(), val=v1));
} END_RULE

BEGIN_RULE(P) {
  int v1, v2;
  ALT(SEQ(A(),
          /*NUM(),*/
          D(), v1=val, N(v1), 
          v2=val, A(), val = v2),
      SEQ(SEQ(A(), CHAR('('), A(), E(), v1=val),
          SEQ(A(), CHAR(')'), A(), val=v1)));
} END_RULE

// D(), v1=val, N(v1) をNUM()でまとめられる？
/*
void NUM(void) {
  NUMBER();
}
*/

#ifdef CPEG_DO_TRACE
long cpeg_N_called, cpeg_N_missed;
#endif
void N(int v) {
  PROLOGUE(N);
  int v1;
  ALT(SEQ(D(), v1=val, N(v * 10 + v1)),
      SEQ(val = v, EMPTY()));
  EPILOGUE();
}

BEGIN_RULE(D) {
  SEQ(CHARSET(digit),
      val = val - '0' );
} END_RULE

/*
ALT(ALT(CHAR('0'),CHAR('1'),CHAR('2'),CHAR('3'),CHAR('4')),
    ALT(CHAR('5'),CHAR('6'),CHAR('7'),CHAR('8'),CHAR('9')))
*/

BEGIN_RULE(A) {
  ALT(SEQ(B(), A()),
      EMPTY());
} END_RULE

BEGIN_RULE(B) {
  ALT(CHAR(' '), CHAR('\n'));
} END_RULE

/* 2. 固定プログラム部分 */

void START();
#define P_NUM (10000)

static char* get_file(char *filepath){
  int fd;
  long psize, size;
  char *mp;
  fd = open(filepath, O_RDONLY);
  if(fd < 0){
    printf("Error: open() %s: %s\n", strerror(errno), filepath);
    exit(-1);
  }
  psize = sysconf(_SC_PAGESIZE);
  size = (P_NUM + psize - 1) / psize * psize;
  mp = (char*)mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
  close(fd);
  return(mp); 
}

int main(int argc, char *argv[]) {

  cs_range(digit, '0', '9');
  cs_range(alpha, 'A', 'Z');
  cs_range(alpha, 'a', 'z');
  cs_union(alnum, digit);
  cs_union(alnum, alpha);
  
  return cpeg_main(argc, argv);
}
