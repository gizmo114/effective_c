#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char buffer[1024];
  FILE *fp;
  int line_count = 0;

  if ((fp = fopen("quote.txt", "r")) == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  };

  while (fgets(buffer, sizeof buffer, fp) != NULL) {
    printf("%d:\t%s", ++line_count, buffer);
  }
  fclose(fp);
  return EXIT_SUCCESS;
}
