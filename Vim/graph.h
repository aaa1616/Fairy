#ifndef _GRAPH_H
#define _GRAPH_H
#include "ftinclib.h"
typedef struct _EDGE {
	//int dest;
	char dest;
	struct _EDGE *link;
}EDGE;

typedef struct _VERTEX{
	//int data;
	char data;
	int color;
	EDGE *adj;
}VERTEX;

typedef struct _GRAPH {
	VERTEX *adj;
	int vetNum;
	int edgeNum;
}GRAPH;

void delGraph(GRAPH *g);
void dfs(GRAPH *g);
GRAPH *createGraph();
#endif // !_GRAPH_H

