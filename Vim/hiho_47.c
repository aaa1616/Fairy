//#include <stdio.h>
//
//#define N 3
//#define M 4
//
//typedef struct _NODE {
//	int color;
//	int next;
//}NODE;
//
//typedef struct _EDGE {
//	int to;
//	int next;
//}EDGE;
//NODE nodes[N];
//EDGE edges[M];
//
//int gIndex = 0;
//
//void build(int a, int b)
//{
//	gIndex++;
//	edges[gIndex].to = b;
//	edges[gIndex].next = nodes[a].next;
//	nodes[a].next = gIndex;
//}
//int dfsvisit(int u)
//{
//	int i;
//	nodes[u].color = 1;
//	for (i = nodes[u].next; i != 0; i = edges[i].next) {
//		if (nodes[edges[i].to].color == 1) {
//			return 1;
//		}
//		if (nodes[edges[i].to].color == 0) {
//			if (dfsvisit(edges[i].to) == 1) {
//				return 1;
//			}
//		}
//	}
//	nodes[u].color = 2;
//	return 0;
//}
//
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//	int flag, i, t, n, m, a, b;
//	fscanf(file, "%d", &t);
//	while (t--) {
//		flag = 0;
//		fscanf(file, "%d%d", &n, &m);
//		memset(nodes, 0, sizeof(nodes));
//		memset(edges, 0, sizeof(edges));
//		while (m--) {
//			fscanf(file, "%d%d", &a, &b);
//			build(a, b);
//		}
//		for (i = 1; i <= n; i++) {
//			if (nodes[i].color == 0) {
//				if (dfsvisit(i) == 1) {
//					flag = 1;
//					break;
//				}
//			}
//		}
//		if (flag == 0) {
//			printf("Correct\n");
//		}
//		else {
//			printf("Wrong\n");
//		}
//	}
//	return 0;
//}