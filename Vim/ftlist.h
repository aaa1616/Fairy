#ifndef  _FTLIST_H
#define _FTLIST_H

typedef struct _LISTHEAD {
	struct _LIST_ENTRY *next, *prev;
}LISTHEAD;

#define ftListInit(name) {&(name), &(name)}
#define ftListHead(name) LISTHEAD name = ftListInit(name)

#endif