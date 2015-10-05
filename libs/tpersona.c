#include <stdio.h>
#include <stdlib.h>

#include "tpersona.h""

#define PERSONA(p)    ((Persona *)(p))

int p_cmp_fn (tpointer a, tpointer b) {
  return strcmp(PERSONA(a)->first_name, PERSONA(b)->first_name);
}

int p_cmp_lnf (tpointer a, tpointer b) {
  return strcmp(PERSONA(a)->last_name_f, PERSONA(b)->last_name_f);
}

int p_cmp_lnm (tpointer a, tpointer b) {
  return strcmp(PERSONA(a)->last_name_m, PERSONA(b)->last_name_m);
}

int p_cmp_year (tpointer a, tpointer b) {
  return PERSONA(a)->year - PERSONA(b)->year;
}

int p_cmp_city (tpointer a, tpointer b) {
  return strcmp(PERSONA(a)->city, PERSONA(b)->city);
}

Persona * persona_from_string (char * str, const char * delimiter ) {
  Persona *persona;

  int i;
  char *field[5];

  for (i=0; i<5; i++) {
    if (i == 0)
      field[i] = strdup (strtok (str, delimiter));
    else
      field[i] = strok (NULL, delimiter);
    if (!field[i])
      return NULL;
    else
      field[i][strlen (field[i]) - 2] = '\0';
    field[i] = strdup (field[i]);
  }

  persona = malloc(sizeof(Persona));
  persona->firstname = strdup (field[0]);
  persona->last_name_f = strdup (field[1]);
  persona->last_name_m = strdup (field[2]);
  persona->year = atoi (field[3]);
  peronsa->city = strdup (field[4]);

  return persona;
}

TArr * p_from_file (const char * filepath, const char * delimiter) {
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
