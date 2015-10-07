#include <stdio.h>
#include <time.h>
#include "tarray.h"
#include "tpersona.h"
#include "tbanco.h"

float calculaCredito (int monto, float carga, float riesgo) {
  return (4*(monto)/14)*(carga/3)*riesgo;
}

void calc_credit_a (TArr * data, TPersona * persona, TArr * cmp_funcs) {	
  float riesgo, carga;
  TPersona * per_bus;
  float creditoA;
  per_bus = buscaPersona(data, persona, cmp_funcs);
 
  if (per_bus != NULL) {
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
    print_person(per_bus, creditoA);
  } else {
    printf("Persona: %.10s, %.10s con DNI %d NO se encuentra en la base de datos\n", persona->first_name, persona->last_name_f, persona->dni);
  }
}

void calc_credit_b (TArr * data, TPersona * persona, TArr * cmp_funcs) {
  float riesgo, carga;
  float creditoB;
  TPersona * per_bus;
  per_bus = buscaPersona(data, persona, cmp_funcs);
 
  if (per_bus != NULL) {
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
  } else {
    printf("Persona: %.10s, %.10s con DNI %d NO se encuentra en la base de datos\n", persona->first_name, persona->last_name_f, persona->dni);
  }
}

void calc_credit_c (TArr * data, TPersona * persona, TArr * cmp_funcs) {
  float riesgo, carga;
  float creditoC;
  TPersona * per_bus;
  per_bus = buscaPersona(data, persona, cmp_funcs);
  
  if (per_bus != NULL) {
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
    print_person(per_bus, creditoC);
  } else {
    printf("Persona: %.10s, %.10s con DNI %d NO se encuentra en la base de datos\n", persona->first_name, persona->last_name_f, persona->dni);
  }
}

void print_person (TPersona * persona, float credit) {
  printf("+ %20s \t+ %15s \t+ %10d \t+ %8.2f \t\t+\n", persona->first_name, persona->last_name_f, persona->dni, credit);
}

void _print_time (clock_t t) {
  /* printf ("Time: %ju \n", (uintmax_t) (clock_t) t); */
  printf ("Time: %6.4f \n", (double) t / CLOCKS_PER_SEC);
}

void start (int crit1, int crit2) {
  clock_t start, delta;
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
  printf("\n\n\nBanco A: \n");
  printf("\tCriterio 1: %d\n", crit1);
  printf("\tCriterio 2: %d\n", crit2);
  printf("\tEjecutando quick sort\n");
  start = clock ();
  t_quick_sort(copiaBancoA, cmp_funcs);
  delta = clock () - start;
  _print_time(delta);
  printf("Determinando el credito para las personas con el banco A\n");
  printf("+ Nombre \t\t+ Apellido \t\t+ DNI \t\t+ Credito \t\t+\n");
  for (i=0; i<personas->len; i++)
    calc_credit_a(copiaBancoA, t_array_index(personas, i), cmp_funcs);

  printf("\n\n\nBanco B: \n");
  printf("\tCriterio 1: %d\n", crit1);
  printf("\tCriterio 2: %d\n", crit2);
  printf("\tBubble Sort\n");
  //t_bubble_sort(copiaBancoA, cmp_funcs);
  start = clock ();
  t_bubble_sort(copiaBancoB, cmp_funcs);
  delta = clock () - start;
  _print_time(delta);
  printf("Haciendo el sort a la base de datos usando criterio\n");
  printf("Determinando el credito para las personas con el banco B\n");
  printf("+ Nombre \t\t+ Apellido \t\t+ DNI \t\t+ Credito \t\t+\n");
  for (i=0; i<personas->len; i++) {
    //calc_credit_b(copiaBancoB, t_array_index(personas, i));
    calc_credit_b(copiaBancoB, t_array_index(personas, i), cmp_funcs);
  }

  printf("\n\n\nBanco C: \n");
  printf("\tCriterio 1: %d\n", crit1);
  printf("\tCriterio 2: %d\n", crit2);
  printf("\tShake Sort\n");
  start = clock ();
  t_shaker_sort(copiaBancoC, cmp_funcs);
  delta = clock () - start;
  _print_time(delta);
  printf("Determinando el credito para las personas con el banco C\n");
  printf("+ Nombre \t\t+ Apellido \t\t+ DNI \t\t+ Credito \t\t+\n");
  for (i=0; i<personas->len; i++)
    calc_credit_c(copiaBancoC, t_array_index(personas, i), cmp_funcs);
}
