#include <stdio.h>
#include "tmsg.h"
#include "tarray.h"
#include "menu.h"

int main(int argc, char *argv[])
{
  TArr *test = t_array_new();
  char msg[] = "This is a list of things. Select one of them";
  TMsg *opt;
 
  t_array_append(test, t_msg_new("This is it..."));
  t_array_append(test, t_msg_new("This is another option"));
  t_array_append(test, t_msg_new("Opt 3"));

  opt = retrieve_opt(test, msg);
  printf("You've selected \"%s\"\n", opt->msg);

  return 0;
}

