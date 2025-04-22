#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TestStruct {
  union {
    struct {
      unsigned char a;
      unsigned char b;
    };
    unsigned short *ab;
  };
} src, *src_p, *dst_p;

int main(void) {
  src_p = &src;
  src_p->a = 0x12;
  src_p->b = 0x34;

  dst_p = malloc(sizeof(struct TestStruct));
  memcpy(dst_p, src_p, sizeof(struct TestStruct));

  printf("%X\t%X\n", dst_p->a, dst_p->b);

  return EXIT_SUCCESS;
}
