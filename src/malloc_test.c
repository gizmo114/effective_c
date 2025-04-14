#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
  int id;
  char name[50];
};

int main(void) {
  struct User *user = malloc(sizeof(struct User));
  if (user == NULL) {
    fprintf(stderr, "Memory allocation failed!\n");
    exit(EXIT_FAILURE);
  }
  user->id = 0;
  strcpy(user->name, "John Smith");
  printf("ID: %d, Name: %s\n", user->id, user->name);
  char *string = malloc(10);
  strcpy(string, "abcdefghi");
  string[9] = '\0';
  printf("%s\n", string);
  free(user);
  free(string);
  return EXIT_SUCCESS;
}
