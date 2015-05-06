//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <math.h>
//
//#define MAXNUM 10005
//
//#define myscanf(file, fmt, ...) fscanf(file, fmt, ##__VA_ARGS__)
//
//typedef struct _LINKLIST {
//	int data;
//	struct _LINKLIST *next;
//}LINKLIST;
//
//typedef struct _QUEUE {
//	LINKLIST *front, *rear;
//}QUEUE;
//
//static QUEUE *initQueue()
//{
//	QUEUE *q = malloc(sizeof(QUEUE));
//	memset(q, 0, sizeof(QUEUE));
//	return q;
//}
//static void delQueue(QUEUE *q)
//{
//	LINKLIST *next, *front = q->front;
//	while (front != NULL) {
//		next = front->next;
//		free(front);
//		front = next;
//	}
//	free(q);
//}
//static int isQueueEmpty(QUEUE *q)
//{
//	return q->front == NULL ? 1 : 0;
//}
//static void enqueue(QUEUE *q, int data)
//{
//	if (q->front != NULL) {
//		LINKLIST *newnode = malloc(sizeof(LINKLIST));
//		newnode->data = data;
//		newnode->next = NULL;
//		q->rear->next = newnode;
//		q->rear = newnode;
//	}
//	else {
//		q->front = q->rear = malloc(sizeof(LINKLIST));
//		q->front->data = data;
//		q->front->next = NULL;
//	}
//}
//static int dequeue(QUEUE *q)
//{
//	LINKLIST *node = q->front;
//	int data = node->data;
//	q->front = q->front->next;
//	free(node);
//	return data;
//}
//
//
//typedef struct _MODULE {
//	int k[3];
//	int kNum;
//	int count;
//}MODULE;
//
//int main(void)
//{
//	int n, i = 0;
//	int modulesNum, signalNum;
//	LINKLIST *hash[MAXNUM];
//	//int *signal;
//	MODULE *modules;
//	QUEUE *q = initQueue();
//
//	FILE *file = fopen("input.txt", "r");
//	//read test case
//	myscanf(file, "%d", &n);
//	//scanf("%d", &n);
//	while (n--) {
//		memset(hash, 0, MAXNUM * sizeof(LINKLIST *));
//
//		myscanf(file, "%d%d", &modulesNum, &signalNum);
//		//scanf("%d%d", &modulesNum, &signalNum);
//		//read init sign
//		//signal = malloc(signalNum * sizeof(int));
//		for (i = 0; i < signalNum; i++) {
//			int st;
//			myscanf(file, "%d", &st);
//			//scanf("%d", &st);
//			enqueue(q, st);
//		}
//		//read module info
//		modules = malloc(modulesNum * sizeof(MODULE));
//		memset(modules, -1, modulesNum * sizeof(MODULE));
//		for (i = 0; i < modulesNum; i++) {
//			int s, k;
//			myscanf(file, "%d%d", &s, &k);
//			//scanf("%d%d", &s, &k);
//			for (int j = 0; j < k; j++) {
//				int thisMs;
//				myscanf(file, "%d", &thisMs);
//				//scanf("%d", &thisMs);
//				modules[i].k[j] = thisMs;
//			}
//			modules[i].kNum = k;
//			modules[i].count= 0;
//			if (hash[s] == NULL) {
//				hash[s] = malloc(sizeof(LINKLIST));
//				hash[s]->data = i;
//				hash[s]->next = NULL;
//			}
//			else {
//				LINKLIST *p = malloc(sizeof(LINKLIST));
//				p->data = i;
//				p->next = hash[s]->next;
//				hash[s]->next = p;
//			}
//		}
//		while (!isQueueEmpty(q)) {
//			int st = dequeue(q);
//			LINKLIST *p = hash[st];
//			while (p != NULL) {
//				int md = p->data;
//				int knum = modules[md].kNum;
//				(modules[md].count)++;
//				for (i = 0; i < knum; i++) {
//					enqueue(q, modules[md].k[i]);
//				}
//				p = p->next;
//			}
//		}
//		for (int i = 0; i < MAXNUM; i++) {
//			LINKLIST *next, *p = hash[i];
//			while (p != NULL) {
//				next = p->next;
//				free(p);
//				p = next;
//			}
//		}
//		for (i = 0; i < modulesNum; i++) {
//			printf("%d ", modules[i].count % 142857);
//		}
//		printf("\n");
//		free(modules);
//	}
//
//	free(q);
//
//	return 0;
//}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LONGLONG long long
#define MOD 12357

int k;
LONGLONG **c, *cdata;
LONGLONG *codata;

void mulm(LONGLONG **a, LONGLONG **b, LONGLONG **ret, int powk)
{
	int i, j, k;
	memset(cdata, 0, powk * powk * sizeof(LONGLONG));
	for (i = 0; i < powk; i++) {
		for (j = 0; j < powk; j++) {
			for (k = 0; k < powk; k++) {
				c[i][j] += a[i][k] * a[k][j];
			}
			c[i][j] %= MOD;
		}
	}
	memcpy(ret[0], cdata, powk * powk * sizeof(LONGLONG));
}

void mula(LONGLONG *a, LONGLONG **m, LONGLONG *ret, int powk)
{
	int i, j;
	memset(codata, 0, powk * sizeof(LONGLONG));
	for (i = 0; i < powk; i++) {
		for (j = 0; j < powk; j++) {
			codata[i] += a[j] * m[j][i];
		}
		codata[i] %= MOD;
	}
	memcpy(ret, codata, powk * sizeof(LONGLONG));
}


static void dfs(int x, int y, int col, LONGLONG **d)
{
	if (col == k) {
		d[y][x] = 1;
		return;
	}
	dfs(x << 1, (y << 1) + 1, col + 1, d);
	dfs((x << 1) + 1, y << 1, col + 1, d);
	if (col + 2 <= k) {
		dfs((x << 2) + 3, (y << 2) + 3, col + 2, d);
	}
}
int main()
{
	FILE *file = fopen("input.txt", "r");
	int n, i, powk;
	LONGLONG **m, *mdata;
	LONGLONG *a;
	fscanf(file, "%d%d", &k, &n);
	powk = 1 << k;

	a = malloc(powk * sizeof(LONGLONG));
	codata = malloc(powk * sizeof(LONGLONG));

	m = malloc(powk * sizeof(LONGLONG *));
	c = malloc(powk * sizeof(LONGLONG *));

	mdata = malloc(powk * powk * sizeof(LONGLONG));
	cdata = malloc(powk * powk * sizeof(LONGLONG));

	for (i = 0; i < powk; i++) {
		m[i] = mdata + i * powk;
		c[i] = cdata + i * powk;
	}

	memset(mdata, 0, powk * powk * sizeof(LONGLONG));
	memset(cdata, 0, powk * powk * sizeof(LONGLONG));

	memset(a, 0, powk * sizeof(LONGLONG));
	memset(codata, 0, powk * sizeof(LONGLONG));

	a[powk - 1] = 1;
	dfs(0, 0, 0, m);

	for (; n > 0; n >>= 1, mulm(m, m, m, powk)) {
		if (n & 1) {
			mula(a, m, a, powk);
		}
	}
	printf("%d\n", a[powk - 1]);

	free(m);
	free(c);

	free(mdata);
	free(cdata);

	free(a);
	free(codata);

	return 0;
}