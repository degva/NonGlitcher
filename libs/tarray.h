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


#endif
