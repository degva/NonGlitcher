#include "tbanco.h"
#include "tpersona.h"

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
