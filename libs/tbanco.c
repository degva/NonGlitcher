#include "tbanco.h"
#include "tpersona.h"
#include "tarray.h"

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

void start (TArr *data, TArr *personas) {
  printf("Determinando el credito para las personas con el banco A\n");
  for (i=0; i<personas->len; i++)
    calc_credit_a(data, t_array_index(personas, i));
  
  printf("Determinando el credito para las personas con el banco B\n");
  for (i=0; i<personas->len; i++)
    calc_credit_b(data, t_array_index(personas, i));
  
  printf("Determinando el credito para las personas con el banco C\n");
  for (i=0; i<personas->len; i++)
    calc_credit_c(data, t_array_index(personas, i));
}
