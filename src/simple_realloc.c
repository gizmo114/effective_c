#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 5

void print_array(int *array_p, size_t size);

int main(void) {
  int *array = malloc(ARRAY_SIZE * sizeof(int));
  // the array now has space for 5 integers
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = 5;
  }
  print_array(array, ARRAY_SIZE);

  int *handler = realloc(array, 7 * sizeof(int));
  if (handler == NULL) {
    printf("Memory allocation issue!");
    return EXIT_FAILURE;
  }
  array = handler;

  for (int i = 0; i < 7; i++) {
    array[i] = 7;
  }

  print_array(array, 7);
  free(array);
  return EXIT_SUCCESS;
}

void print_array(int *array_p, size_t size) {
  for (int i = 0; i < size; i++) {
    printf("%d%s", array_p[i], (i == (size - 1)) ? "\n" : "\t");
  }
}
