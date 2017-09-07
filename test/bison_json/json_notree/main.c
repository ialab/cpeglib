#include <stdio.h>
#include <time.h>

extern int yyparse(void);
extern FILE *yyin;
extern int yydebug; /* デバッグ用 */

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
  clock_t s, e;
  yyin = fp;
  s = clock();
  if (yyparse())
    printf("json parse error!\n");
  e = clock();
  printf("%f\n", (double)(e-s)/CLOCKS_PER_SEC);
  return 0;
}
