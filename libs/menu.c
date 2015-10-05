#include <stdio.h>
#include <string.h>
#include "tmsg.h"
#include "tarray.h"
#include "menu.h"


void _show_message (char msg[]) {
  printf("%s", msg);
  printf("\n");
}

void _print_list (TArr *items) {
  int i;
  TMsg *message;
  for (i=0; i < items->len; i++) {
    message = t_array_index(items, i);
    printf("%d - %s\n", i, message->msg);
  }
}

tpointer retrieve_opt (TArr *items, char msg[]) {
  int opt;
  if (strcmp(msg, "") == 0)
    _show_message("Select any of the options below:");
  else
    _show_message(msg);

  _print_list(items);
  printf("Select > ");
  scanf("%d", &opt);
  return t_array_index(items, opt);
}
