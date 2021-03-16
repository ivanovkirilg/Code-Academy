#ifndef KILIST_GUARD
#define KILIST_GUARD

typedef struct tagList * list;

list lcreate(void);
int ldestroy(list l);

int ladd(list l, int data);
int lappend(list l, int data);
int linsindex(list l, int data, unsigned ind);
int linsafter(list l, int data, int after);
int linsbefore(list l, int data, int before);

int lremvalue(list l, int data);
int lremindex(list l, unsigned ind);

int lgetlen(list l);
int lfindindex(list l, int data);
int lreadindex(list l, unsigned index);
int lreadlast(list l);
int lprint(list l);

#endif