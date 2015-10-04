#include <stdio.h>
#include "tlib.h"

int main(int argc, char *argv[])
{
  // Array con los criterios disponibles
  TArray order_ways;
  t_array_append(order_ways, INT_TO_POINTER(23));
  t_array_append(order_ways, INT_TO_POINTER(43));
  t_array_append(order_ways, INT_TO_POINTER(21));
  t_array_append(order_ways, INT_TO_POINTER(55));

  t_array_foreach(order_ways, printf, NULL);
  
	// setf;
  return 0;
}

