#include <stdio.h>
#include <stdlib.h>

void merge_sort(int array[static + 1], size_t len);
void print_array(int array[static + 1], size_t len);

int main() {
  int A[5] = {
      [0] = 4, [1] = 2, [2] = 1, [3] = 3, [4] = 0,
  };
  // size of array by dividing size of array (in bytes) byt size of one element
  size_t len = sizeof(A) / sizeof(A[0]);
  print_array(A, len);
  merge_sort(A, len);
  print_array(A, len);

  return EXIT_SUCCESS;
}

void merge_sort(int array[static + 1], size_t len) {
  // arrays of size 0, 1 are automatically sorted
  if (len < 2) {
    return;
  }
  // find the center to know where to split the array
  size_t mid = len / 2;

  // two helper arrays to store the halves
  // left is a pointer to an integer, malloc allocates memory for an array on
  // address of left
  int *left = malloc(mid * sizeof(int));
  int *right = malloc((len - mid) * sizeof(int));

  // copy the data into the two halves
  for (size_t i = 0; i < mid; i++) {
    left[i] = array[i];
  }

  for (size_t i = mid; i < len; i++) {
    right[i - mid] = array[i];
  }

  // recursively call merge_sort on both left and right
  merge_sort(left, mid);
  merge_sort(right, len - mid);

  // at this point the array should be split into arrays the size of one and we
  // can start merging
  size_t i = 0, j = 0, k = 0;
  while (i < mid && j < (len - mid)) {
    if (left[i] <= right[j]) {
      array[k++] = left[i++];
    } else {
      array[k++] = right[j++];
    }
  }
  // print the remainder of whichever array has something left in it
  while (i < mid) {
    array[k++] = left[i++];
  }

  while (j < (len - mid)) {
    array[k++] = right[j++];
  }

  // free the allocated memory
  free(left);
  free(right);
}
// print the array, duh
void print_array(int array[static + 1], size_t len) {
  for (size_t i = 0; i < len; i++) {
    if (i == (len - 1)) {
      printf("%d\n", array[i]);
    } else {
      printf("%d\t", array[i]);
    }
  }
}
