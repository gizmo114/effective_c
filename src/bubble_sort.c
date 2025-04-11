#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int array[], size_t len);
void print_array(int array[], size_t len);

int main() {
  int A[5] = {
      [0] = 4, [1] = 2, [2] = 1, [3] = 3, [4] = 0,
  };
  // size of array by dividing size of array (in bytes) byt size of one element
  size_t len = sizeof(A) / sizeof(A[0]);
  print_array(A, len);
  bubble_sort(A, len);
  print_array(A, len);

  return EXIT_SUCCESS;
}

void bubble_sort(int array[], size_t len) {
  bool shifted = false;

  for (size_t j = 0; j < (len - 1); j++) {
    shifted = false;
    for (size_t i = 0; i < (len - 1 - j); i++) {
      if (array[i + 1] < array[i]) {
        int tmp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tmp;
        shifted = true;
      }
    }
    if (!shifted) {
      break;
    }
  }
}
void print_array(int array[], size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("%d%s", array[i], (i == (len - 1)) ? "\n" : "\t");
  }
}
