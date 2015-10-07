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


int execute_partition(TArr *array , int izq , int der ,TArr * cmp_funcs){
 TCompFunc cmp_func_1;
 TCompFunc cmp_func_2;

  cmp_func_1 = (TCompFunc) t_array_index(cmp_funcs, 0);
  cmp_func_2 = (TCompFunc) t_array_index(cmp_funcs, 1);
  int i , j ; 
  int izqT=izq;
  j = izq +1;
  for (i = izq +1 ;i<= der ;i++){
    if (cmp_func_1(array-> vector[i],array->vector[izqT])>0){
      t_swap(array->vector[i],array->vector[izqT]);
    } else if (cmp_func_1(array->vector[i],array->vector[izqT])==0){
      if (cmp_func_2(array->vector[i],array->vector[izqT])>0){
        t_swap(array->vector[i],array->vector[izqT]);
      }
    }
  }
  t_swap(&array[izq],&array[j-1]);
  return j-1;
}

void qs(TArr * array,int izq , int der ,TArr * cmp_funcs ){
    if (izq < der ){
        int pos_pivote = execute_partition(array ,izq ,der,cmp_funcs);
        qs(array,izq,pos_pivote -1,cmp_funcs);
        qs(array,pos_pivote +1,der,cmp_funcs);
    }
}

void t_quick_sort(TArr * array, TArr *cmp_funcs){

     qs ( array , 0 , 1000 , cmp_funcs ) ;
 }

void t_shaker_sort(TArr * array , TArr * cmp_funcs){
  int i , j;
  TCompFunc cmp_func_1;
  TCompFunc cmp_func_2;

  cmp_func_1 = (TCompFunc) t_array_index(cmp_funcs, 0);
  cmp_func_2 = (TCompFunc) t_array_index(cmp_funcs, 1);

  for (  i = 0;i<500;i++){
    TBoolean swapped = FALSE ;
    for( j = i ; j < 1000-i-1;j++){
      if (cmp_func_1(array-> vector[j],array->vector[j+1])>0){
      t_swap(array->vector[j],array->vector[j+1]);
      swapped =TRUE;
    } else if (cmp_func_1)(array->vector[j],array->vector[j+1]==0){
      if (cmp_func_2(array->vector[j],array->vector[j+1])>0){
        t_swap(array->vector[j],array->vector[j+1]);
        swapped = TRUE;
      }
    }

    }
  }
  for(j = 500 -2 -i; j > i ;j-- ){
    if (cmp_func_1(array-> vector[j],array->vector[j+1])>0){
      t_swap(array->vector[j],array->vector[j+1]);
        swapped =TRUE;
    } else if ((cmp_func_1)(array->vector[j],array->vector[j+1])==0){
      if (cmp_func_2(array->vector[j],array->vector[j+1])>0){
        t_swap(array->vector[j],array->vector[j+1]);
        swapped = TRUE;
      }
    }
    if (!swapped) break;
  }
}
