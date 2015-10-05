#ifndef TPERSONA
#define TPERSONA

#include "tarray.h"
#include "ttypes.h"

struct _TPersona {
  const char *first_name;
  const char *last_name_f;
  const char *last_name_m;
  long dni;
  long ruc;
  const char *fecha;
  const char *estado;
  int monto;
  const char *genero;
  TBoolean char carga ;
  int riesgo;
  
};
typedef _TPersona TPersona;

struct _DB_Sunat {
  const char *first_name;
  const char *last_name_f;
  const char *last_name_m;
  long dni;
  long ruc;  
  const char *fecha;
  const char *estado;
  int monto;
}; typedef _DB_Sunat DB_Sunat;

struct _DB_Reniec {
  const char *first_name;
  const char *last_name_f;
  const char *last_name_m;
  long dni;
  const char *genero;
  TBoolean char carga ;
}; typedef _DB_Reniec DB_Reniec;

struct _DB_Infocorp {
  const char *first_name;
  const char *last_name_f;
  const char *last_name_m;
  long dni;
  int riesgo;
  
}; typedef _DB_Infocorp DB_Infocorp;



typedef enum {
  PERSONA_FIRST_NAME,
  PERSONA_LAST_NAME_F,
  PERSONA_LAST_NAME_M,
  PERSONA_DNI,
  PERSONA_RUC,
  PERSONA_FECHA,
  PERSONA_ESTADO,
  PERSONA_MONTO,
  PERSONA_GENERO,
  PERSONA_CARGA,
  PERSONA_RIESGO

} PersonaCriteria;
// crea el nuevo persona
include_persona(DB_Reniec,DB_Sunat,DB_Infocorp); 
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
