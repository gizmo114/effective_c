#include <stdio.h>
#include <stdlib.h>

// char is 1 byte, int is 4 so there should be 3 bytes of padding in between
struct PaddedStruct {
  char a;
  int b;
};

int main(void) {
  struct PaddedStruct ps = {'A', 1};
  unsigned char *ps_p = (unsigned char *)&ps;

  for (int i = 0; i < sizeof(struct PaddedStruct); i++) {
    printf("%d%s", ps_p[i],
           (i == (sizeof(struct PaddedStruct) - 1) ? "\n" : "\t"));
  }
  return EXIT_SUCCESS;
}
