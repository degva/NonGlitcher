#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "tpersona.h"

#define PERSONA(p)    ((TPersona *)(p))

int p_cmp_fn (tpointer a, tpointer b) {
  return strcmp(PERSONA(a)->first_name, PERSONA(b)->first_name);
}

int p_cmp_lnf (tpointer a, tpointer b) {
  return strcmp(PERSONA(a)->last_name_f, PERSONA(b)->last_name_f);
}

int p_cmp_lnm (tpointer a, tpointer b) {
  return strcmp(PERSONA(a)->last_name_m, PERSONA(b)->last_name_m);
}

TPersona *buscaPersona (TArr *data, TPersona * persona){
  int max, min, mid;
  max = data->len;
  min = 0;
  while (min < max) {
    mid = min + (max-min)/2;
    if (PERSONA(data->vector[min])->dni == persona->dni){
      return data->vector[min];
    }
    else if (PERSONA(data->vector[min])->dni < persona->dni){
      min = mid + 1;
    }
    else {
      max = mid - 1;
    }
  }
  return NULL;
}


DB_Sunat * persona_from_string_su(char * str, const char * delimiter ) {
  DB_Sunat *sunat;

  int i;
  char *field[8];

  for (i=0; i<8; i++) {
    if (i == 0)
      field[i] = strdup (strtok (str, delimiter));
    else
      field[i] = strtok (NULL, delimiter);
    if (!field[i])
      return NULL;
    else
      field[i][strlen (field[i]) - 2] = '\0';
    field[i] = strdup (field[i]);
  }

  sunat = malloc(sizeof(DB_Sunat));
  sunat->ruc = atoi (field[0]);
  sunat->dni = atoi (field[1]);
  sunat->first_name = strdup (field[2]);
  sunat->last_name_f = strdup (field[3]);
  sunat->last_name_m = strdup (field[4]);
  sunat->fecha = strdup (field[5]);
  sunat->estado = strdup (field[6]);
  sunat->monto = atoi  (field[7]);

  return sunat;
}
DB_Reniec * persona_from_string_re(char * str, const char * delimiter ) {
  DB_Reniec *reniec;

  int i;
  char *field[6];

  for (i=0; i<6; i++) {
    if (i == 0)
      field[i] = strdup (strtok (str, delimiter));
    else
      field[i] = strtok (NULL, delimiter);
    if (!field[i])
      return NULL;
    else
      field[i][strlen (field[i]) - 2] = '\0';
    field[i] = strdup (field[i]);
  }

  reniec = malloc(sizeof(DB_Sunat));
  reniec->dni = atoi (field[0]);
  reniec->first_name = strdup (field[1]);
  reniec->last_name_f = strdup (field[2]);
  reniec->last_name_m = strdup (field[3]);
  reniec->genero= strdup(field[4]);
  if (strcmp(strdup(field[5]), "Si") == 0) 
    reniec->carga = TRUE;
  else
    reniec->carga = FALSE;

  return reniec;
}
DB_Infocorp * persona_from_string_in(char * str, const char * delimiter ) {
  DB_Infocorp *infocorp;

  int i;
  char *field[5];

  for (i=0; i<5; i++) {
    if (i == 0)
      field[i] = strdup (strtok (str, delimiter));
    else
      field[i] = strtok (NULL, delimiter);
    if (!field[i])
      return NULL;
    else
      field[i][strlen (field[i]) - 2] = '\0';
    field[i] = strdup (field[i]);
  }

  infocorp = malloc(sizeof(DB_Sunat));
  infocorp -> dni = atoi (field[0]);
  infocorp -> first_name = strdup (field[1]);
  infocorp->last_name_f = strdup (field[2]);
  infocorp->last_name_m = strdup (field[3]);
  infocorp->riesgo = atoi (field[4]);

  return infocorp;
}

TPersona * include_persona(const DB_Reniec * reniec, const DB_Sunat * sunat , const DB_Infocorp * infocorp){

  TPersona *people ;
  people -> first_name = reniec ->first_name;
  people -> last_name_f = reniec -> last_name_f;
  people -> last_name_m = reniec -> last_name_m;
  people -> dni = reniec -> dni;
  people -> ruc = sunat -> ruc;
  people -> fecha = sunat -> fecha;
  people -> estado = sunat -> estado;
  people -> monto = sunat -> monto;
  people -> genero = reniec -> genero;
  people -> carga= reniec -> carga;
  people ->riesgo =infocorp -> riesgo;
  return people;

}

TArr * p_from_file (const char * filepath_sunat,const char * filepath_reniec,const char * filepath_infocorp, const char * delimiter) {
  TArr *personas;
  FILE *f;
  FILE *f1;
  FILE *f2;
  char line[1000];
  char line1[1000];
  char line2[1000];

  personas = t_array_new();

  f = fopen(filepath_sunat, "r");
  f1 = fopen(filepath_infocorp, "r");
  f2 = fopen(filepath_reniec, "r");

  if (!f)
    goto handle_error;

  while (fgets (line, 1000, f) && fgets(line1,1000,f1) && fgets(line2,1000,f2)) {
    TPersona *people;
    DB_Sunat *sunat;
    DB_Reniec *reniec;
    DB_Infocorp *infocorp ;
    
    reniec = persona_from_string_re(line1,delimiter);
    sunat = persona_from_string_su(line, delimiter);
    infocorp= persona_from_string_in(line2,delimiter);
    people = include_persona(reniec,sunat,infocorp);

    if (!people)
      goto handle_error;
    t_array_append(personas, people);
  }
  fclose(f);

  if (personas->len == 0)
    goto handle_error;

  return personas;
handle_error:
  free(personas);
  return NULL;
}

