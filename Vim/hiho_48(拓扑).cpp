//#include <stdio.h>
//
//#define N 100001
//#define M 500001
//#define MOD 142857
//
//typedef struct _NODE {
//	int next;
//	int deg;
//	int sum;
//}NODE;
//
//typedef struct _EDGE {
//	int to;
//	int next;
//}EDGE;
//NODE nodes[N];
//EDGE edges[M];
//
//int queue[N];
//
//int gIndex = 0;
//
//void build(int a, int b)
//{
//	gIndex++;
//	edges[gIndex].to = b;
//	edges[gIndex].next = nodes[a].next;
//	nodes[a].next = gIndex;
//	nodes[b].deg++;
//}
//
//int main()
//{
//	int n, m, k, a, b, i, j, u, v, ret = 0;
//	scanf("%d%d%d", &n, &m, &k);
//	while (k--) {
//		scanf("%d", &a);
//		nodes[a].sum = 1;
//	}
//	while (m--) {
//		scanf("%d%d", &a, &b);
//		build(a, b);
//	}
//	gIndex = 0;
//	for (i = 1; i <= n; i++) {
//		if (nodes[i].deg == 0) {
//			queue[gIndex++] = i;
//		}
//	}
//	i = 0;
//	while (i < gIndex) {
//		u = queue[i++];
//		for (j = nodes[u].next; j != 0; j = edges[j].next) {
//			v = edges[j].to;
//			if (nodes[v].deg != 0) {
//				nodes[v].sum = (nodes[v].sum + nodes[u].sum) % MOD;
//				nodes[v].deg--;
//				if (nodes[v].deg == 0) {
//					queue[gIndex++] = v;
//				}
//			}
//		}
//	}
//	for (i = 1; i <= n; i++) {
//		ret = (ret + nodes[i].sum) % MOD;
//	}
//	printf("%d\n", ret);
//	return 0;
//}