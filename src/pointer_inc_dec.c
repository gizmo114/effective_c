#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char cba[] = "cba";
  char *p = cba;
  // prints c because pointer to arrays is pointer to first item
  printf("%c\n", *p);
  // *p is furst resolved to produce character c, then ++ is applied making the
  // result d
  printf("%c\n", ++*p);

  char xyz[] = "xyz";
  char *q = xyz;
  // prints x because pointer to arrays is pointer to first item
  printf("%c\n", *q);
  // *q is first printed priducing x then ++ is applied
  printf("%c\n", *q++);
  // if we print it again we see value y
  printf("%c\n", *q);
  return EXIT_SUCCESS;
}
