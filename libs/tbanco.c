#include <stdio.h>
#include "tarray.h"
#include "tpersona.h"
#include "tbanco.h"

float calculaCredito (int monto, float carga, float riesgo) {
  return (4*(monto)/14)*(carga/3)*riesgo;
}

float calc_credit_a (TArr * data, TPersona * persona, TArr * cmp_funcs) {	
  float riesgo, carga;
  TPersona * per_bus;
  float creditoA;
  per_bus = buscaPersona(data, persona, cmp_funcs);
  
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

float calc_credit_b (TArr * data, TPersona * persona, TArr * cmp_funcs) {
  float riesgo, carga;
  float creditoB;
  TPersona * per_bus;
  per_bus = buscaPersona(data, persona, cmp_funcs);
  
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
  print_person(per_bus, creditoB);
  return creditoB;
}

float calc_credit_c (TArr * data, TPersona * persona, TArr * cmp_funcs) {
  float riesgo, carga;
  float creditoC;
  TPersona * per_bus;
  per_bus = buscaPersona(data, persona, cmp_funcs);
  
  //Establecemos el valor de la carga 
  if (per_bus->carga){
    carga = 2;
  } else{
    carga = 3;
  }

  //Establecemos el valor del riesgo	
  if (per_bus->riesgo == 1) {
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
  printf("+ %.10s \t+ %.10s \t+ %d \t+ %.2f \t\t+\n", persona->first_name, persona->last_name_f, persona->dni, credit);
}

void start (int crit1, int crit2) {
  int i;
  TArr * cmp_funcs;
  cmp_funcs = t_array_new();
  switch (crit1) {
    case PERSONA_FIRST_NAME:
      t_array_append(cmp_funcs, p_cmp_fn);
      break;
    case PERSONA_LAST_NAME_F:
      t_array_append(cmp_funcs, p_cmp_lnf);
      break;
    case PERSONA_LAST_NAME_M:
      t_array_append(cmp_funcs, p_cmp_lnm);
      break;
    case PERSONA_DNI:
      t_array_append(cmp_funcs, p_cmp_dni);
      break;
  }

  switch (crit2) {
    case PERSONA_FIRST_NAME:
      t_array_append(cmp_funcs, p_cmp_fn);
      break;
    case PERSONA_LAST_NAME_F:
      t_array_append(cmp_funcs, p_cmp_lnf);
      break;
    case PERSONA_LAST_NAME_M:
      t_array_append(cmp_funcs, p_cmp_lnm);
      break;
    case PERSONA_DNI:
      t_array_append(cmp_funcs, p_cmp_dni);
      break;
  }

  // Lee bases de datos y los pone en un arreglo de punteros
  TArr * baseDatos;
  // Usaremos copias externas de dicha base de datos
  TArr * copiaBancoA;
  TArr * copiaBancoB;
  TArr * copiaBancoC;

  // iniciamos las bases
  copiaBancoA = t_array_new();
  copiaBancoB = t_array_new();
  copiaBancoC = t_array_new();

  // leemos las bases de datos
  baseDatos = p_from_file ("data/DB_SUNAT.txt","data/DB_RENIEC.txt","data/DB_INFOCORP.txt",",");

  // Hacemos copias enteras de las bases de datos
  t_array_full_copy(baseDatos, copiaBancoA);
  t_array_full_copy(baseDatos, copiaBancoB);
  t_array_full_copy(baseDatos, copiaBancoC);
  
  // leemos el archivo de personas
  TArr * personas;
  personas = p_from_file_2 ("data/Personas.txt",",");

  // Hace una copia para banco a y hace el sort respectivo a la copia de la DB
  // -- inicia tiempo para banco Ai
  /*
  printf("Banco A: \n");
  printf("\tCriterio 1: %s\n", buscaCriterio(crit1));
  printf("\tCriterio 2: %s\n", buscaCriterio(crit2));
  printf("\tQuick Sort\n");
  t_quick_sort(copiaBancoA, crit1, crit2);
  printf("Determinando el credito para las personas con el banco A\n");
  for (i=0; i<personas->len; i++)
    calc_credit_a(copiaBancoA, t_array_index(personas, i));
  printf("Listo :v\n");
  */
  printf("Banco B: \n");
  /*
  printf("\tCriterio 1: %s\n", buscaCriterio(crit1));
  printf("\tCriterio 2: %s\n", buscaCriterio(crit2));
  */
  printf("\tCriterio 1: %d\n", crit1);
  printf("\tCriterio 2: %d\n", crit2);
  printf("\tBubble Sort\n");
  //t_bubble_sort(copiaBancoA, cmp_funcs);
  t_bubble_sort(baseDatos, cmp_funcs);
  printf("Haciendo el sort a la base de datos usando criterio\n");
  printf("Determinando el credito para las personas con el banco B\n");
  printf("+ Nombre \t+ Apellido \t+ DNI \t\t+ Credito \t+\n");
  for (i=0; i<personas->len; i++) {
    //calc_credit_b(copiaBancoB, t_array_index(personas, i));
    calc_credit_b(baseDatos, t_array_index(personas, i), cmp_funcs);
  }
  printf("gg :v\n");
  /*
  printf("Banco C: \n");
  printf("\tCriterio 1: %s\n", buscaCriterio(crit1));
  printf("\tCriterio 2: %s\n", buscaCriterio(crit2));
  printf("\tShake Sort\n");
  t_shake_sort(copiaBancoA, crit1, crit2);
  printf("Determinando el credito para las personas con el banco C\n");
  for (i=0; i<personas->len; i++)
    calc_credit_c(copiaBancoC, t_array_index(personas, i));
  printf("wp :v\n");
  */
}
