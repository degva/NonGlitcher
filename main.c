#include <stdio.h>
#include "tarray.h"
#include "menu.h"
#include "tpersona.h"
#include "tbanco.h"

int main()
{

  printf("\e[1;1H\e[2J");
  printf(" -+----------------------+-\n");
  printf(" -|  TRABAJO  _  PARCIAL |-\n");
  printf(" -|  A L G O R I T M I A |-\n");
  printf(" -+----------------------+-\n");

  printf("Notas:\n");
  printf("1 Los bancos A, B y C tienen algoritmos\n");
  printf("  distintos: Quick Sort, Bubble Sort y\n");
  printf("  Shaker Sort respectivamente.\n");
  printf("2 La seleccion de criterios influye mucho.\n");
  printf("  Se hace notar las siguiente combinaciones que\n");
  printf("  podrían mostrar un error y el por qué.\n");
  printf("  Ap. Paterno <+> Ap. Materno\n");
  printf("    Muchas personas comparten los mismos apellidos\n");
  printf("3 El Shaker Sort no funciona gg wp\n\n\n");


  printf(" -+----------------------+-\n\n\n");

  int crit1, crit2;

  TArr *opts = t_array_new();
  t_array_append(opts, "Nombres");
  t_array_append(opts, "Apellido Paterno");
  t_array_append(opts, "Apellido Materno");
  t_array_append(opts, "DNI");

  crit1 = retrieve_opt(opts, "Ingrese la criteria #1:");
  crit2 = crit1;

  if (crit1 != 3) {
    while (crit2 == crit1) {
      crit2 = retrieve_opt(opts, "Ingrese la criteria #2:");
      if (crit2 == crit1)
        printf("\nElija otro criterio distinto al primero\n");
    }
  }

  // inicia todo el proceso desde banco.c
  start(crit1, crit2);

  return 0;
}

