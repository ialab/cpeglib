#include <stdio.h>  /* for perror*/
#include <stdlib.h> /* for malloc */

void *allocate(size_t size) {
  void *value = malloc(size);
  if (value == NULL) {
    perror("malloc");
    exit(1);
  }
  return value;
}
