#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;
  int x = 5;

  if ((fp = fopen("write.txt", "w")) == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  fputs("Hello, file!\n", fp);
  fprintf(fp, "x = %d\n", x);

  fclose(fp);

  return EXIT_SUCCESS;
}
