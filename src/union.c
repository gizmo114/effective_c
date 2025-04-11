#include <stdio.h>

union {
  struct {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int rest : 6;
  } bits;
  unsigned char byte;
} bytefield, *bytefield_p;

int main() {
  bytefield.byte = 0b11001100;
  printf("bit0: %u\n", bytefield.bits.bit0);
  bytefield_p = &bytefield;

  bytefield_p->bits.bit0 = 1;
  printf("bit0: %u\n", bytefield.bits.bit0);
}
