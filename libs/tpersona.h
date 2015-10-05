#ifndef TPERSONA
#define TPERSONA

#include "tarray.h"

struct _TPersona {
  int dni;
  const char *first_name;
  const char *last_name_f;
  const char *last_name_m;
  int year;
  const char * city;
};

typedef _TPersona TPersona;

typedef enum {
  PERSONA_FIRST_NAME,
  PERSONA_LAST_NAME_F,
  PERSONA_LAST_NAME_M,
  PERSONA_YEAR,
  PERSONA_CITY
} PersonaCriteria;

// Compare 2 persons by first name
int p_cmp_fn (tpointer a, tpointer b);
// Compare 2 persons by last name f
int p_cmp_lnf (tpointer a, tpointer b);
// Compare 2 persons by last name m
int p_cmp_lnm (tpointer a, tpointer b);
// copare by year
int p_cmp_year (tpointer a, tpointer b);
// copare by city
int p_cmp_city (tpointer a, tpointer b);
// Create a persona from a string
Persona * persona_from_string(char * str, const char * delimiter);
// read data from persona
TArr * p_from_file (const char * filepath, const char * delimiter);

#endif
