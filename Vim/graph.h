#ifndef _GRAPH_H
#define _GRAPH_H

#include "ftinclib.h"

typedef struct _EDGE {
	int dest;
	struct _EDGE *link;
}EDGE;

typedef struct _VERTEX{
	int data;
	int color;
	EDGE *adj;
}VERTEX;

typedef struct _GRAPH {
	VERTEX *adj;
	int vetNum;
	int edgeNum;
}GRAPH;

typedef struct _LINKLIST {
	int data;
	struct _LINKLIST *next;
}LINKLIST;

typedef struct _QUEUE {
	LINKLIST *front, *rear;
}QUEUE;

typedef struct _BINTREENODE{
	int data;
	struct _BINTREENODE *left, *right;
}BINTREENODE;

typedef struct _BINTREE{
	BINTREENODE *root;
}BINTREE;

typedef struct _STACK {
	int num[100];
	int top;
}STACK;

void stackPush(STACK *stack, int data);
int stackPop(STACK *stack, int *data);
int stackGet(STACK *stack, int *data);

void preOrder(BINTREENODE *root);
BINTREE *createBinTree();
BINTREE *createBinTreeLR();
void delBinTree(BINTREENODE *root);

void delGraph(GRAPH *g);
void dfs(GRAPH *g);
void bfs(GRAPH *g, int data);
GRAPH *createGraph();

QUEUE *initQueue();
void delQueue(QUEUE *q);
void enqueue(QUEUE *q, int data);
int dequeue(QUEUE *q);
int isQueueEmpty(QUEUE *q);

#endif // !_GRAPH_H

