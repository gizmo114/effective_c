#include <stdio.h>
#include <stdlib.h>

void swap_by_value(int a, int b);
void swap_by_reference(int *pa, int *pb);

int main() {
  int a = 15;
  int b = 27;
  swap_by_value(a, b);
  printf("[main] a = %d, b = %d\n", a, b);
  swap_by_reference(&a, &b);
  printf("[main] a = %d, b = %d\n", a, b);
  return EXIT_SUCCESS;
}
// this won't really swap since C is pass-by-value and arguments are just mere
// copies
void swap_by_value(int a, int b) {
  int t = a;
  a = b;
  b = t;
  printf("[swap_by_value] a = %d, b = %d\n", a, b);
}
// this now works
void swap_by_reference(int *pa, int *pb) {
  int t = *pa;
  *pa = *pb;
  *pb = t;
  printf("[swap_by_reference] a = %d, b = %d\n", *pa, *pb);
}
