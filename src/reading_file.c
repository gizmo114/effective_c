#include <err.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  int c;

  if ((fp = fopen("hello.txt", "r")) == NULL) {
    err(1, "Failed to open a file!");
  }

  while ((c = fgetc(fp)) != EOF)
    printf("%c", c);

  return EXIT_SUCCESS;
}
