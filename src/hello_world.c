#include <stdio.h>
#include <stdlib.h>

int main() {
  puts("Hello world!");

  if (puts("Secure hello world!") == EOF) {
    return EXIT_FAILURE;
  }

  int num = printf("%s\n", "Hello world! but with printf");
  printf("Printf printed %d characters!\n", num);

  return EXIT_SUCCESS;
}
