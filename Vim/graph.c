#include "graph.h"

GRAPH *createGraph()
{
	GRAPH *g = malloc(sizeof(GRAPH));
	int i, vet, edge, b, e;
	char strb[10], stre[10];
	FILE *file = fopen("input.txt", "r");
	//scanf("%d%d", &vet, &edge);
	fscanf(file, "%d%d", &vet, &edge);
	VERTEX *adj = malloc(vet * sizeof(VERTEX));
	g->adj = adj;
	g->vetNum = vet;
	g->edgeNum = edge;
	for (i = 0; i < vet; i++) {
		adj[i].data = i;
		adj[i].adj = NULL;

	}
	for (i = 0; i < edge; i++) {
		//scanf("%s %s", strb, stre);
		fscanf(file, "%s%s", strb, stre);
		b = strb[0] - 'A';
		e = stre[0] - 'A';
		EDGE *p = malloc(sizeof(EDGE));
		p->dest = e;
		p->link =adj[b].adj;
		adj[b].adj = p;

		p = malloc(sizeof(EDGE));
		p->dest = b;
		p->link =adj[e].adj;
		adj[e].adj = p;
	}
	fclose(file);
	return g;
}
static void dfsVisit(GRAPH *g, int v)
{
	printf("%c ", v + 'A');
	g->adj[v].color = 1;
	EDGE *p = g->adj[v].adj;
	while (p != NULL) {
		int next = p->dest;
		if (g->adj[next].color == 0) {
			dfsVisit(g, next);
		}
		p = p->link;
	}
	g->adj[v].color = 2;
}
void dfs(GRAPH *g)
{
	VERTEX *adj = g->adj;
	int i, vet = g->vetNum;
	for (i = 0; i < vet; i++) {
		adj[i].color = 0;
	}
	for (i = 0; i < vet; i++) {
		if (adj[i].color == 0) {
			dfsVisit(g, i);
		}
	}
	printf("\n");
}
void bfs(GRAPH *g, int data)
{
	int i, vet = g->vetNum;
	g->adj[data].color = 1;
	for (i = 0; i < vet; i++) {
		if (i != data) {
			g->adj[i].color = 0;
		}
	}
	QUEUE *q = initQueue();
	enqueue(q, data);
	while (!isQueueEmpty(q)) {
		int u = dequeue(q);
		printf("%c ", u + 'A');
		EDGE *p = g->adj[u].adj;
		while (p != NULL) {
			int next = p->dest;
			if (g->adj[next].color == 0) {
				g->adj[next].color = 1;
				enqueue(q, next);
			}
			p = p->link;
		}
		g->adj[u].color = 2;
	}
	printf("\n");
}
void delGraph(GRAPH *g)
{
	VERTEX *adj = g->adj;
	int i, vet = g->vetNum;
	for (i = 0; i < vet; i++) {
		EDGE *next, *p = adj[i].adj;
		while (p != NULL) {
			next = p->link;
			free(p);
			p = next;
		}
	}
	free(adj);
	free(g);
}

QUEUE *initQueue()
{
	QUEUE *q = malloc(sizeof(QUEUE));
	memset(q, 0, sizeof(QUEUE));
	return q;
}
void delQueue(QUEUE *q)
{
	LINKLIST *next, *front = q->front;
	while (front != NULL) {
		next = front->next;
		free(front);
		front = next;
	}
	free(q);
}
int isQueueEmpty(QUEUE *q)
{
	return q->front == NULL ? 1 : 0;
}
void enqueue(QUEUE *q, int data)
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
int dequeue(QUEUE *q)
{
	LINKLIST *node = q->front;
	int data = node->data;
	q->front = q->front->next;
	free(node);
	return data;
}

void stackPush(STACK *stack, int data)
{
	stack->num[++(stack->top)] = data;
}
int stackPop(STACK *stack, int *data)
{
	if (stack->top != 0) {
		*data = stack->num[(stack->top)--];
		return 1;
	}
	return 0;
}
int stackGet(STACK *stack, int *data)
{
	if (stack->top != 0) {
		*data = stack->num[stack->top];
		return 1;
	}
	return 0;
}

BINTREE *createBinTree()
{
	int k;
	FILE *file = fopen("input.txt", "r");
	BINTREENODE *p, *t;
	BINTREE *bt;
	bt = malloc(sizeof(BINTREE));
	memset(bt, 0, sizeof(BINTREE));
	STACK stack;
	stack.top = 0;
	char c;
	c = getc(file);
	while (c != '#') {
		switch (c)
		{
		case '(':
			stackPush(&stack, (int)p);
			k = 1;
			break;
		case ')':
			stackPop(&stack, (int *)&t);
			break;
		case ',':
			k = 2;
			break;
		default:
			p = malloc(sizeof(BINTREENODE));
			memset(p, 0, sizeof(BINTREENODE));
			p->data = c;
			if (bt->root == NULL) {
				bt->root = p;
			}
			else {
				if (k == 1) {
					stackGet(&stack, (int *)&t);
					t->left = p;
				}
				else {
					stackGet(&stack, (int *)&t);
					t->right= p;
				}
			}
			break;
		}
		c = getc(file);
	}
	fclose(file);
	return bt;
}
static BINTREENODE * subCreate(char *lstr, char *rstr, int n)
{
	if (n == 0) {
		return NULL;
	}
	int i = 0;
	while (lstr[0] != rstr[i]) {
		i++;
	}
	BINTREENODE *root = malloc(sizeof(BINTREENODE));
	root->data = lstr[0];
	root->left = subCreate(lstr + 1, rstr, i);
	root->right= subCreate(lstr + i + 1, rstr + i + 1, n - i - 1);
	return root;
}
BINTREE *createBinTreeLR()
{
	char lstr[20];
	char rstr[20];

	FILE *file = fopen("input.txt", "r");
	myscanf(file, "%s%s", lstr, rstr);

	int n = strlen(lstr);
	BINTREENODE *root = subCreate(lstr, rstr, n);

	BINTREE *bt;
	bt = malloc(sizeof(BINTREE));
	memset(bt, 0, sizeof(BINTREE));
	bt->root = root;

	return bt;
}
void preOrder(BINTREENODE *root)
{
	if (root != NULL) {
		printf("%c ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void delBinTree(BINTREENODE *root)
{
	if (root != NULL) {
		delBinTree(root->left);
		delBinTree(root->right);
		free(root);
	}
}