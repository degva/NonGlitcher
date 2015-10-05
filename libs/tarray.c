#include <stdlib.h>
#include "tarray.h"

#define t_alloc(a,t,sz)       realloc(a, sz * sizeof(t))
#define _t_alloc_array()      malloc(sizeof (TArr))
#define _t_realloc_vector(a, sz)  t_alloc(a, tpointer, sz)

TArr * t_array_new () {
  TArr *array;
  array = _t_alloc_array();
  array->len = 0;
  array->vector = NULL;

  return array;
}

void t_array_append (TArr * array, tpointer data) {
  array->len++;
  array->vector = realloc(array->vector, sizeof(tpointer) * array->len);
  array->vector[array->len - 1] = data;
}

tpointer t_array_index (TArr * array, int index){
  return array->vector[index];
}

int t_array_length (TArr * array) {
  return array->len;
}

void t_array_remove_last (TArr * array) {
  array->len--;
  array->vector = realloc(array, sizeof(tpointer) * array->len);
}

void t_array_full_copy(TArr * src, TArr * des) {
  int i;
  des->len = src->len;
  for (i=0; i<src->len; i++) {
    t_array_append( 
  }
  memcpy(des->vector, src->vector);
}
