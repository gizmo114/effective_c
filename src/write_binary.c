#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;
  int binary_data[5] = {1, 2, 3, 4, 5};

  if ((fp = fopen("data.bin", "wb")) == NULL) {
    perror("Error opening file");
  }

  fwrite(binary_data, sizeof(int), 5, fp);

  fclose(fp);
  return EXIT_SUCCESS;
}
