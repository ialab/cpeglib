#include "mouse_parser.h"

int main(int argc, char *argv[]) {
  return cpeg_main2(argc, argv, &print_mouse_ast);
}
