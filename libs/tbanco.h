#ifndef TBANCO
#define TBANCO
#include "tarray.h"
#include "tpersona.h"

float calculaCredito (int monto, float carga, float riesgo);
// Funcion que devuelve el credito usando la formula del
void calc_credit_a (TArr * data, TPersona * persona, TArr * cmp_funcs);
void calc_credit_b (TArr * data, TPersona * persona, TArr * cmp_funcs);
void calc_credit_c (TArr * data, TPersona * persona, TArr * cmp_funcs);

// imprime datos de la persona con su credito
void print_person (TPersona * persona, float credit);

// Lee el archivo persona y para cada persona
// calcula el credito - tambien inicia el tiempo de ejecucion.
void start (int crit1, int crit2);

#endif
