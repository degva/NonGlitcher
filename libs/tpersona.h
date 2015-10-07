#ifndef TPERSONA
#define TPERSONA

#include "tarray.h"
#include "ttypes.h"

struct _TPersona {
  const char *first_name;
  const char *last_name_f;
  const char *last_name_m;
  int dni;
  int ruc;
  const char *fecha;
  const char *estado;
  int monto;
  const char *genero;
  TBoolean carga;
  int riesgo;  
};

typedef struct _TPersona TPersona;

struct _DB_Sunat {
  const char *first_name;
  const char *last_name_f;
  const char *last_name_m;
  int dni;
  int ruc;  
  const char *fecha;
  const char *estado;
  int monto;
}; 

typedef struct _DB_Sunat DB_Sunat;

struct _DB_Reniec {
  const char *first_name;
  const char *last_name_f;
  const char *last_name_m;
  int dni;
  const char *genero;
  TBoolean carga ;
}; 

typedef struct _DB_Reniec DB_Reniec;

struct _DB_Infocorp {
  const char *first_name;
  const char *last_name_f;
  const char *last_name_m;
  int dni;
  int riesgo;
  
}; 

typedef struct _DB_Infocorp DB_Infocorp;

typedef enum {
  PERSONA_FIRST_NAME,
  PERSONA_LAST_NAME_F,
  PERSONA_LAST_NAME_M,
  PERSONA_DNI
} PersonaCriteria;

// Creates a new person
TPersona * include_persona(const DB_Reniec * reniec, const DB_Sunat * sunat , const DB_Infocorp * infocorp);
// Compare 2 persons by first name
int p_cmp_fn (tpointer a, tpointer b);
// Compare 2 persons by last name f
int p_cmp_lnf (tpointer a, tpointer b);
// Compare 2 persons by last name m
int p_cmp_lnm (tpointer a, tpointer b);
int p_cmp_dni (tpointer a, tpointer b);
TPersona * buscaPersona (TArr * data, TPersona * persona, TArr * cmp_funcs);
// Create a person from a string
TPersona * persona_from_string(char * str, const char * delimiter);
// read data from databases Reniec, Infocorp and Sunat
TArr * p_from_file (const char * filepath_sunat,const char * filepath_reniec,const char * filepath_infocorp, const char * delimiter);
// read data from the personas
TArr * p_from_file_2 (const char  * filepath, const char * delimiter);
#endif
