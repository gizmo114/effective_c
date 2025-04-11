#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
  int id;
  char name[50];
  char phone[50];
} example_user, *example_user_p;

int main() {
  example_user.id = 0;
  strcpy(example_user.name, "Tomas Mihok");
  strcpy(example_user.phone, "+421 908 393 328");

  printf("%d\t%s\t%s\n", example_user.id, example_user.name,
         example_user.phone);

  example_user_p = &example_user;

  example_user_p->id = 1;
  strcpy(example_user_p->name, "Kinga Imreczeova");
  strcpy(example_user_p->phone, "+421 908 056 081");

  printf("%d\t%s\t%s\n", example_user_p->id, example_user_p->name,
         example_user_p->phone);

  return EXIT_SUCCESS;
}
