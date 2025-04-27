#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp);

int main(void) {
  FILE *fp = fopen("foo.txt", "r");
  char *line;

  while ((line = readline(fp)) != NULL) {
    printf("%s\n", line);
    free(line);
  }

  fclose(fp);
  return EXIT_SUCCESS;
}

char *readline(FILE *fp) {
  int buffer_size = 4;
  char *buffer = malloc(buffer_size);
  int offset = 0;
  int c;

  // read character, check if we have enough space, if not reallocate to double
  // the buffer size, if yes read the character and move the offset
  while (c = getc(fp), c != '\n' && c != EOF) {
    if (offset == buffer_size - 1) {
      buffer_size *= 2;
      char *new_buffer = realloc(buffer, buffer_size);

      if (new_buffer == NULL) {
        free(buffer);
        return NULL;
      }
      buffer = new_buffer;
    }
    buffer[offset++] = c;
  }

  if (c == EOF && offset == 0) {
    free(buffer);
    return NULL;
  }

  // shrink the buffer if we're over offset + 1 when we're done readline
  if (offset < buffer_size - 1) {
    buffer_size = offset + 1;
    char *new_buffer = realloc(buffer, buffer_size);

    if (new_buffer != NULL) {
      buffer = new_buffer;
    }
  }
  buffer[offset] = '\0';
  return buffer;
}
