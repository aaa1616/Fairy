#ifdef MICROSOFT
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXNUM 10005

#define DEBUG

#ifndef INT_MAX
#define INT_MAX 2000000000
#endif
#ifndef INT_MIN
#define INT_MIN -2000000000
#endif

#ifdef DEBUG
#define myscanf(file, fmt, ...) fscanf(file, fmt, ##__VA_ARGS__)
#else
#define myscanf(file, fmt, ...) scanf(fmt, ##__VA_ARGS__)
#endif // DEBUG

typedef struct _CORD {
	int x;
	int y;
	int num;
}CORD;

typedef struct _EDGE {
	int dest;
	int weight;
	struct _EDGE *link;
}EDGE;

typedef struct _VERTEX{
	int data;
	int color;
	EDGE *next;
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
static QUEUE *initQueue()
{
	QUEUE *q = malloc(sizeof(QUEUE));
	memset(q, 0, sizeof(QUEUE));
	return q;
}
static void delQueue(QUEUE *q)
{
	LINKLIST *next, *front = q->front;
	while (front != NULL) {
		next = front->next;
		free(front);
		front = next;
	}
	free(q);
}
static int isQueueEmpty(QUEUE *q)
{
	return q->front == NULL ? 1 : 0;
}
static void enqueue(QUEUE *q, int data)
{
	if (q->front != NULL) {
		LINKLIST *newnode = malloc(sizeof(LINKLIST));
		newnode->data = data;
		newnode->next = NULL;
		q->rear->next = newnode;
		q->rear = newnode;
	}
	else {
		q->front = q->rear = malloc(sizeof(LINKLIST));
		q->front->data = data;
		q->front->next = NULL;
	}
}
static int dequeue(QUEUE *q)
{
	LINKLIST *node = q->front;
	int data = node->data;
	q->front = q->front->next;
	free(node);
	return data;
}

int cmpx(void const *a, void const *b)
{
	return ((CORD *)a)->x - ((CORD *)b)->x;
}
int cmpy(void const *a, void const *b)
{
	return ((CORD *)a)->y - ((CORD *)b)->y;
}

int distance(int i, int j, CORD *cord)
{
	int ret, x, y;
	x = abs(cord[i].x - cord[j].x);
	y = abs(cord[i].y - cord[j].y);
	return x < y ? x : y;
}

static void createGraph(int n, VERTEX *adj,  CORD *cord)
{
	int i;
	for (i = 0; i < n - 1; i++) {
		int a = cord[i].num, b = cord[i + 1].num;
		EDGE *p = malloc(sizeof(EDGE));
		p->dest = b;
		p->link = adj[a].next;
		p->weight = distance(i, i + 1, cord);
		adj[a].next = p;

		p = malloc(sizeof(EDGE));
		p->dest = a;
		p->link = adj[b].next;
		p->weight = distance(i, i + 1, cord);
		adj[b].next = p;
	}
}

int main(void)
{
	int i, n;
	int isInqueue[MAXNUM];
	CORD cord[MAXNUM];
	int dist[MAXNUM];
	QUEUE *q = initQueue();
#ifdef DEBUG
	FILE *file = fopen("input.txt", "r");
#endif
	memset(isInqueue, 0, MAXNUM * sizeof(int));
	//read test case
	myscanf(file, "%d", &n);
	for (i = 0; i < n; i++) {
		myscanf(file, "%d%d", &cord[i].x, &cord[i].y);
		dist[i] = INT_MAX;
		cord[i].num = i;
	}
	dist[0] = 0;

	//create the edge
	VERTEX *adj = malloc(n * sizeof(VERTEX));
	for (i = 0; i < n; i++) {
		adj[i].data = i;
		adj[i].next = NULL;
	}
	qsort(cord, n, sizeof(CORD), cmpx);
	createGraph(n, adj, cord);
	qsort(cord, n, sizeof(CORD), cmpy);
	createGraph(n, adj, cord);

	//relax edge
	enqueue(q, 0);
	isInqueue[0] = 1;
	while (!isQueueEmpty(q)) {
		int u = dequeue(q);
		isInqueue[u] = 0;
		EDGE *p = adj[u].next;
		while (p != NULL) {
			int dis = dist[u] + p->weight;
			if (dist[p->dest] > dis) {
				dist[p->dest] = dis;
				if (isInqueue[p->dest] == 0) {
					enqueue(q, p->dest);
					isInqueue[p->dest] = 1;
				}
			}
			p = p->link;
		}
	}
	
	//free malloc memory
	for (i = 0; i < n; i++) {
		EDGE *next, *p = adj[i].next;
		while (p != NULL) {
			next = p->link;
			free(p);
			p = next;
		}
	}
	free(adj);
	delQueue(q);

	printf("%d\n", dist[n - 1]);

#ifdef DEBUG
	fclose(file);
	system("pause");
#endif
	return 0;
}
#endif