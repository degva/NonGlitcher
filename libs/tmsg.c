#include  <stdlib.h>
#include <string.h>
#include "tmsg.h"

TMsg * t_msg_new(char mgg[]) {
  TMsg *i;
  i = malloc(sizeof (TMsg));
  strcpy(i->msg, mgg);
  return i;
}
