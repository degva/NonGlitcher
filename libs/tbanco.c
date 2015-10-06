#include "tbanco.h"
#include "tpersona.h"
#include "tarray.h"

float calc_credit_a (TArr * data, TPersona persona) {	
  float riesgo, carga;
  TPersona * per_bus;
  float creditoA;
  per_bus = buscarPersona(data, persona);
  
  //Establecemos el valor de la carga 
  if (per_bus->carga){
    carga = 1;
  } else{
    carga = 3;
  }

  //Establecemos el valor del riesgo	
  if ((per_bus->riesgo >= 1) && (per_bus->riesgo <= 2)){
    riesgo = 1;
  } else if ((per_bus->riesgo >= 3) && (per_bus->riesgo <= 5)){
    riesgo = 0.6;
  } else if ((per_bus->riesgo >= 6) && (per_bus->riesgo <= 7)){
    riesgo = 0.2;
  } else if (per_bus->riesgo >= 8){
    riesgo = 0;
  }
  
  creditoA = calculaCredito(per_bus->monto, carga, riesgo);
  return creditoA;
}

float calc_credit_b (TArr * data, TPersona persona) {
  TPersona * per_bus;
  per_bus = buscarPersona(data, persona);
  
  //Establecemos el valor de la carga 
  if (per_bus->carga){
    carga = 1;
  } else{
    carga = 4;
  }

  //Establecemos el valor del riesgo	
  if ((per_bus->riesgo >= 1) && (per_bus->riesgo <= 2)){
    riesgo = 1;
  } else if (per_bus->riesgo >= 3){
    riesgo = 0;
  }  
  creditoB = calculaCredito(per_bus->monto, carga, riesgo);
  return creditoB;
}

float calc_credit_c (TArr * data, TPersona persona) {
  TPersona * per_bus;
  per_bus = buscarPersona(data, persona);
  
  //Establecemos el valor de la carga 
  if (per_bus->carga){
    carga = 2;
  } else{
    carga = 3;
  }

  //Establecemos el valor del riesgo	
  if (per_bus->riesgo = 1){
    riesgo = 1;
  } else if ((per_bus->riesgo >= 2) && (per_bus->riesgo <= 4)){
    riesgo = 0.4;
  } else if (per_bus->riesgo >= 5){
    riesgo = 0;
  }

  creditoC = calculaCredito(per_bus->monto, carga, riesgo);
  return creditoC;
}

void print_person (TPersona * persona, float credit) {

}

void start (int crit1, int crit2) {

  TArr * cmp_funcs;
  cmp_funcs = t_array_new();
  switch (crit1) {
    case PERSONA_FIRST_NAME:
      t_array_append(cmp_funcs, p_cmp_fn);
    case PERSONA_LAST_NAME_F:
      t_array_append(cmp_funcs, p_cmp_lnf);
    case PERSONA_LAST_NAME_M:
      t_array_append(cmp_funcs, p_cmp_lnm);
    case PERSONA_DNI:
      t_array_append(cmp_funcs, p_cmp_dni);
  }

  switch (crit2) {
    case PERSONA_FIRST_NAME:
      t_array_append(cmp_funcs, p_cmp_fn);
    case PERSONA_LAST_NAME_F:
      t_array_append(cmp_funcs, p_cmp_lnf);
    case PERSONA_LAST_NAME_M:
      t_array_append(cmp_funcs, p_cmp_lnm);
    case PERSONA_DNI:
      t_array_append(cmp_funcs, p_cmp_dni);
  }

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
  TArr *persona;
  persona= p_from_file ("DB_SUNAT.txt","DB_RENIEC.txt","DB_INFOCORP",",")

  // Hacemos copias enteras de las bases de datos
  t_array_full_copy(persona, copiaBancoA);
  t_array_full_copy(persona, copiaBancoB);
  t_array_full_copy(persona, copiaBancoC);

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
