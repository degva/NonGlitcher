#ifndef TYPES
#define TYPES

#define TRUE 1
#define FALSE !TRUE

typedef int TBoolean;
typedef void * tpointer;

typedef int  (*TCompFunc)       (tpointer a,
                                 tpointer b);
typedef int  (*TCompDataFunc)   (tpointer a,
                                 tpointer b,
#endif
