#include <stdio.h>
#include <string.h>
#include "cpeglib.h"

int cpeg_main2(int argc, char *argv[], result_processor print) {
  int i = 1;
  size_t size;

  if (strcmp(argv[i], "-f") == 0) {
    input = cpeg_get_file_mmap(argv[++i]);
    size = cpeg_get_file_size(argv[i]);
  } else {
    input = argv[i];
    size = strlen(input);
  }
  failed = false;
  pos = 0;
  START();
  print(val, input, pos, size);
  return 0;
}

void default_printer(cpeg_value_t result, char *input, cpeg_pos_t pos, size_t size) {
  printf("result: %d (pos %d/%zu) - [%s]\n", (int)result, pos, size,
	 (pos == size) ? "success" : "failed");
}

int cpeg_main(int argc, char *argv[]) {
  return cpeg_main2(argc, argv, default_printer);
}
