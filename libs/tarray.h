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
void t_quick_sort(TArr * src, int crit1, int crit2);
void t_bubble_sort(TArr * src, int crit1, int crit2);
void t_shake_sort(TArr * src, int crit1, int crit2);


#endif
