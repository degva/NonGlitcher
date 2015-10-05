#ifndef TMSG
#define TMSG

struct _TMsg {
  char msg[100];
};

typedef struct _TMsg TMsg;

TMsg * t_msg_new ();

#endif
