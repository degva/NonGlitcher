#include <stdio.h>
#include "tarray.h"
#include "menu.h"
#include "tpersona.h"
#include "tbanco.h"

int main(int argc, char *argv[])
{

  int crit1, crit2;
  enum PersonaCriteria options;
  TArr *opts = t_array_new();

  put_data(opts, options);

  crit1 = retrieve_opt(opts, "Ingrese criteria 1 de sort:");
  t_array_remove_item(test, crit1);
  crit2 = retrieve_opt(test, "Ingrese criteria 2 de sort:");

  // inicia todo el proceso desde banco.c
  start(crit1, crit2);

  return 0;
}

