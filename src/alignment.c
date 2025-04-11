#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argx, [[maybe_unused]] char *argv[]) {
  int a = 42;
  printf("Address in the memory: %p\n", (void *)&a);
  printf("Address in the memory as integer: %lu\n", (uintptr_t)&a);
  printf("%s\n", ((uintptr_t)&a % 4 == 0) ? "Aligned" : "Not aligned!");
  return EXIT_SUCCESS;
}
