#include "tbanco.h"
#include "tpersona.h"
#include "tarray.h"


//lee el archivo del DB_SUNAT
TArr *sunat;
people= p_from_file ("DB_SUNAT.txt","DB_RENIEC.txt","DB_INFOCORP",",");





float calc_credit_a (TArr * data, TPersona persona) {
  return 0;
}

float calc_credit_b (TArr * data, TPersona persona) {
  return 0;
}

float calc_credit_c (TArr * data, TPersona persona) {
  return 0;
}

void print_person (TPersona * persona, float credit) {

}

void start (int crit1, int crit2) {

  // Lee bases de datos y los pone en un arreglo de punteros
  TArr * baseDatos;
  // Usaremos copias externas de dicha base de datos
  TArr * copiaBancoA;
  TArr * copiaBancoB;
  TArr * copiaBancoC;

  // iniciamos las bases
  baseDatos = t_array_new();
  copiaBancoA = t_array_new();
  copiaBancoB = t_array_new();
  copiaBancoC = t_array_new();

  // leemos las bases de datos
  leer_bases(baseDatos);

  // Hacemos copias enteras de las bases de datos
  t_array_full_copy(baseDatos, copiaBancoA);
  t_array_full_copy(baseDatos, copiaBancoB);
  t_array_full_copy(baseDatos, copiaBancoC);

  // Hace una copia para banco a y hace el sort respectivo a la copia de la DB
  // -- inicia tiempo para banco Ai
  printf("Banco A: \n");
  printf("\tCriterio 1: %s\n", buscaCriterio(crit1));
  printf("\tCriterio 2: %s\n", buscaCriterio(crit2));
  printf("\tQuick Sort\n");
  t_quick_sort(copiaBancoA, crit1, crit2);
  printf("Determinando el credito para las personas con el banco A\n");
  for (i=0; i<personas->len; i++)
    calc_credit_a(copiaBancoA, t_array_index(personas, i));
  printf("Listo :v\n");
  
  printf("Banco B: \n");
  printf("\tCriterio 1: %s\n", buscaCriterio(crit1));
  printf("\tCriterio 2: %s\n", buscaCriterio(crit2));
  printf("\tBubble Sort\n");
  t_bubble_sort(copiaBancoA, crit1, crit2);
  printf("Haciendo el sort a la base de datos usando criterio\n");
  printf("Determinando el credito para las personas con el banco B\n");
  for (i=0; i<personas->len; i++)
    calc_credit_b(copiaBancoB, t_array_index(personas, i));
  printf("gg :v\n");
  
  printf("Banco C: \n");
  printf("\tCriterio 1: %s\n", buscaCriterio(crit1));
  printf("\tCriterio 2: %s\n", buscaCriterio(crit2));
  printf("\tShake Sort\n");
  t_shake_sort(copiaBancoA, crit1, crit2);
  printf("Determinando el credito para las personas con el banco C\n");
  for (i=0; i<personas->len; i++)
    calc_credit_c(copiaBancoC, t_array_index(personas, i));
  printf("wp :v\n");
}
