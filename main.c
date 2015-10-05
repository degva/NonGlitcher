#include <stdio.h>
#include "tmsg.h"
#include "tarray.h"
#include "menu.h"

int main(int argc, char *argv[])
{

  int crit1, crit2;
  enum PersonaCriteria options;
  TArr *opts = t_array_new();

  //char msg[] = "This is a list of things. Select one of them";
  //TMsg *opt;

  put_data(opts, options);

  crit1 = retrieve_opt(opts, "Ingrese criteria 1 de sort:");
  t_array_remove_item(test, crit1);
  crit2 = retrieve_opt(test, "Ingrese criteria 2 de sort:");
  

  return 0;
}

