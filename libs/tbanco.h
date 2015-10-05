#ifndef TBANCO
#define TBANCO

// Funcion que devuelve el credito usando la formula del
// banco B
float calc_credit_a (TArr * data, TPersona persona);
float calc_credit_b (TArr * data, TPersona persona);
float calc_credit_c (TArr * data, TPersona persona);

// imprime datos de la persona con su credito
void print_person (TPersona * persona, float credit);

// Lee el archivo persona y para cada persona
// calcula el credito - tambien inicia el tiempo de ejecucion.
void start (TArr *data, const char * filepath, const char * delimiter);

#endif