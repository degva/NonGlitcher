#include <stdio.h>
#include "tarray.h"
#include "menu.h"
#include "tpersona.h"
#include "tbanco.h"

int main()
{

  int crit1, crit2;

  TArr *opts = t_array_new();
  t_array_append(opts, "PERSONA_FIRST_NAME");
  t_array_append(opts, "PERSONA_LAST_NAME_F");
  t_array_append(opts, "PERSONA_LAST_NAME_M");
  t_array_append(opts, "PERSONA_DNI");

  crit1 = retrieve_opt(opts, "Ingrese criteria 1 de sort:");
  crit2 = crit1;
  if (crit1 != 3) {
    while (crit2 == crit1) {
      crit2 = retrieve_opt(opts, "Ingrese criteria 2 de sort:");
      if (crit2 == crit1)
        printf("\nElija otro criterio\n");
    }
  }

  // inicia todo el proceso desde banco.c
  start(crit1, crit2);

  return 0;
}

