#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *str = "Here comes the sun!";
  size_t str_len = strlen(str) + 1;

  char *str_cpy = malloc(str_len);

  if (str_cpy) {
    strcpy(str_cpy, str);
  }

  printf("%s\n", str_cpy);
}
