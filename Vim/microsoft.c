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