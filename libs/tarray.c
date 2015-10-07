#include <stdlib.h>
#include "tarray.h"

#define t_alloc(a,t,sz)       realloc(a, sz * sizeof(t))
#define _t_alloc_array()      malloc(sizeof (TArr))
#define _t_realloc_vector(a, sz)  t_alloc(a, tpointer, sz)
#define t_swap(a, b)    do { typeof(a) t; t = a; a = b; b = t; } while(0)

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
    for (d = 0 ; d < ( 1000 - c - 1); d++)
    {
      if ( cmp_func_1( array->vector[d], array->vector[d+1]) > 0) {
        t_swap (array->vector[d], array->vector[d+1]);
      } else if ( cmp_func_1( array->vector[d] ,array->vector[d+1]) == 0) { 
        if ( cmp_func_2( array->vector[d] ,array->vector[d+1]) > 0) {
          t_swap (array->vector[d], array->vector[d+1]);
        }
      }
    }
  }
}


int execute_partition(TArr *array , int izq , int der ,TArr * cmp_funcs, tpointer * pivote){
  TCompFunc cmp_func_1;
  TCompFunc cmp_func_2;

  cmp_func_1 = (TCompFunc) t_array_index(cmp_funcs, 0);
  cmp_func_2 = (TCompFunc) t_array_index(cmp_funcs, 1);
  int i , j ; 
  j = izq +1;
  for (i = izq +1 ;i<= der ;i++){
    if (cmp_func_1(array-> vector[i],pivote) < 0){
      t_swap(array->vector[i],array->vector[j]);
      j++;
    } else if (cmp_func_1(array->vector[i],pivote)==0){
      if (cmp_func_2(array->vector[i],pivote) < 0){
        t_swap(array->vector[i],array->vector[j]);
        j++;
      }
    }
  }
  t_swap(array->vector[izq],array->vector[j-1]);
  return j-1;
}

tpointer * choose_pivote(TArr * array, int izq) {
  return t_array_index(array, izq);
}

void qs(TArr * array,int izq , int der ,TArr * cmp_funcs ){
    if (izq < der ){
        tpointer * pivote = choose_pivote(array, izq);
        int pos_pivote = execute_partition(array ,izq ,der,cmp_funcs, pivote);
        qs(array,izq,pos_pivote -1,cmp_funcs);
        qs(array,pos_pivote +1,der,cmp_funcs);
    }
}

void t_quick_sort(TArr * array, TArr *cmp_funcs){
  qs ( array, 0, 999, cmp_funcs);
}

/*
void t_shaker_sort(TArr * array, TArr * cmp_funcs)
{
  int len = array->len;
  int i;
  int t = 0;
  TCompFunc cmp_func_1;
  TCompFunc cmp_func_2;

  cmp_func_1 = (TCompFunc) t_array_index(cmp_funcs, 0);
  cmp_func_2 = (TCompFunc) t_array_index(cmp_funcs, 1);
  while (!t) {
    for (i = 1, t = 1; i < len; i++) {
      if (cmp_func_1(array-> vector[i],array->vector[i-1]) > 0) {
        t_swap(array->vector[i],array->vector[i-1]);
        t = 0;
      } else if (cmp_func_1(array->vector[i],array->vector[i-1]) == 0) {
        if (cmp_func_2(array->vector[i],array->vector[i-1]) > 0){
          t_swap(array->vector[i],array->vector[i-1]);
          t=0;
        }
      }
    }
    if (t) break;
    for (i = len - 1, t = 1; i; i--) {
      if (cmp_func_1(array-> vector[i],array->vector[i-1]) > 0) {
        t_swap(array->vector[i],array->vector[i-1]);
        t = 0;
      } else if (cmp_func_1(array->vector[i],array->vector[i-1]) == 0) {
        if (cmp_func_2(array->vector[i],array->vector[i-1]) > 0){
          t_swap(array->vector[i],array->vector[i-1]);
          t=0;
        }
      }
    }
  }
}
*/

void t_shaker_sort(TArr * array , TArr * cmp_funcs){
  int i , j;
  TCompFunc cmp_func_1;
  TCompFunc cmp_func_2;

  cmp_func_1 = (TCompFunc) t_array_index(cmp_funcs, 0);
  cmp_func_2 = (TCompFunc) t_array_index(cmp_funcs, 1);

  for (i = 1; i <= 1000/2; i++) {
    for( j = i-1 ; j < 1000 -i ;j++) {
      if (cmp_func_1(array-> vector[j],array->vector[j+1]) > 0){
        t_swap(array->vector[j],array->vector[j+1]);
      } else if (cmp_func_1(array->vector[j],array->vector[j+1]) == 0){
        if (cmp_func_2(array->vector[j],array->vector[j+1]) > 0){
          t_swap(array->vector[j],array->vector[j+1]);
        }
      }
    }
    for (j = 1000 -1 -i; j >= i ;j-- ){
      if (cmp_func_1(array-> vector[j],array->vector[j-1]) > 0){
        t_swap(array->vector[j],array->vector[j-1]);
      } else if ((cmp_func_1)(array->vector[j],array->vector[j-1]) == 0){
        if (cmp_func_2(array->vector[j],array->vector[j-1]) > 0){
          t_swap(array->vector[j],array->vector[j-1]);
        }
      }
    }
  }
}
