#include "tbanco.h"
#include "tpersona.h"


float calc_credit_a (TArr * data, TPersona persona) {	
  float riesgo, carga;
  TPersona * per_bus;
  float creditoA;
  per_bus = buscarPersona(data, persona);
  
  //Establecemos el valor de la carga 
  if (per_bus->carga){
	carga = 1;
  }
  else{
	carga = 3;
  }

  //Establecemos el valor del riesgo	
  if ((per_bus->riesgo >= 1) && (per_bus->riesgo <= 2)){
	riesgo = 1;
  }
  else if ((per_bus->riesgo >= 3) && (per_bus->riesgo <= 5)){
	riesgo = 0.6;
  }
  else if ((per_bus->riesgo >= 6) && (per_bus->riesgo <= 7)){
	riesgo = 0.2;
  }
  else if (per_bus->riesgo >= 8){
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
  }
  else{
	carga = 4;
  }

  //Establecemos el valor del riesgo	
  if ((per_bus->riesgo >= 1) && (per_bus->riesgo <= 2)){
	riesgo = 1;
  }
  else if (per_bus->riesgo >= 3){
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
  }
  else{
	carga = 3;
  }

  //Establecemos el valor del riesgo	
  if (per_bus->riesgo = 1){
	riesgo = 1;
  }
  else if ((per_bus->riesgo >= 2) && (per_bus->riesgo <= 4)){
	riesgo = 0.4;
  }
  else if (per_bus->riesgo >= 5){
	riesgo = 0;
  }

  creditoC = calculaCredito(per_bus->monto, carga, riesgo);
  return creditoC;
}

void print_person (TPersona * persona, float credit) {

}

void start (TArr  *data, const char * filepath, const char * delimiter) {
  printf("Leyendo archivo de entrada...");
  
  TArr *people;
  FILE *f;
  char line[1000];

  people = t_array_new();

  f = fopen(filepath, 'r');

  if (!f)
    goto handle_error;

  while (fgets (line, 1000, f)) {
    Persona *persona;
    persona = persona_from_string(line, delimiter);
    if (!persona)
      goto handle_error;
    t_array_append(people, persona);
  }
  fclose(f);

  if (people->len == 0)
    goto handle_error;

  return people;
handle_error:
  free(people);
  return NULL;
}
