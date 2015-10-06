#include <stdlib.h>
#include "tarray.h"

#define t_alloc(a,t,sz)       realloc(a, sz * sizeof(t))
#define _t_alloc_array()      malloc(sizeof (TArr))
#define _t_realloc_vector(a, sz)  t_alloc(a, tpointer, sz)

#define TYPE(t)   ((void *) (t))

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
    t_array_append(des,  TYPE(t_array_index(src, i)));
  }                                                       
}

//void t_bubble_sort (TArr * array, TCompDataFunc cmp_func){
void t_bubble_sort (TArr * array, TArr * cmp_funcs){
  int c, d;
  TCompFunc cmp_func_1;
  TCompFunc cmp_func_2;

  cmp_func_1 = (TCompFunc) t_array_index(cmp_funcs, 0);
  cmp_func_2 = (TCompFunc) t_array_index(cmp_funcs, 1);

  for (c = 0 ; c < ( 1000 - 1 ); c++)
  {
    for (d = 0 ; d < 1000 - c - 1; d++)
    {
      if ( cmp_func_1( array->vector[c] ,array->vector[d]) < 0) {
        t_swap (array->vector[c], array->vector[d]);
      } else {
        if ( cmp_func_2( array->vector[c] ,array->vector[d]) < 0) {
          t_swap (array->vector[c], array->vector[d]);
        }
      }
    }
  }
}
