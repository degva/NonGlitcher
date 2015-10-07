#ifndef TARRAY
#define TARRAY
#include "ttypes.h"

struct _TArr {
  tpointer *vector;
  int len;
};

typedef struct _TArr TArr;

TArr * t_array_new ();
void t_array_append (TArr * array, tpointer data);
tpointer t_array_index (TArr * array, int index);
int t_array_length (TArr * array);
void t_array_remove_last (TArr * array);
// creates full copy 
void t_array_full_copy(TArr * src, TArr * des);

//sorting algorithms
void t_bubble_sort (TArr * array, TArr * cmp_funcs);
int execute_partition(TArr *array , int izq , int der ,TArr * cmp_funcs, tpointer * pivote);
tpointer * choose_pivote(TArr * array, int izq);
void qs(TArr * array,int izq , int der ,TArr * cmp_funcs );
void t_quick_sort(TArr * array, TArr *cmp_funcs);
void t_shaker_sort(TArr * array , TArr * cmp_funcs);

#endif
