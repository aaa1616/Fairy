//#include <stdio.h>
//
//#define N 10
//
//typedef struct _EDGE {
//	int to;
//	int next;
//	int vis;
//}EDGE;
//typedef struct _NODE {
//	int next;
//}NODE;
//
//EDGE edges[(1 << N) + 1];
//NODE nodes[1 << N];
//int path[(1 << N) + 1];
//int gIndex = 0;
//char binary[(1 << N) + 1];
//
//void build(int u, int v)
//{
//	gIndex++;
//	edges[gIndex].to = v;
//	edges[gIndex].next = nodes[u].next;
//	edges[gIndex].vis = 0;
//	nodes[u].next = gIndex;
//}
//
//static void dfs(int u)
//{
//	int i, v;
//	for (i = nodes[u].next; i; i = edges[i].next) {
//		v = edges[i].to;
//		if (edges[i].vis != 1) {
//			edges[i].vis = 1;
//			dfs(v);
//		}
//	}
//	path[gIndex++] = u;
//}
//
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//	int n, i, j, m, mask, ret = 0;
//	fscanf(file, "%d", &n);
//	m = 1 << n - 1;
//	mask = (1 << (n - 1)) - 1;
//	for (i = 0; i < m; i++) {
//		build(i, (i << 1) & mask);
//		build(i, (i << 1) & mask | 0x1);
//	}
//	gIndex = 0;
//	dfs(0);
//	for (i = 0; i < n; i++) {
//		binary[i] = '0';
//	}
//	for (i = gIndex - 2, j = 0; i >= 0; i--, j++) {
//		binary[n + j] = (path[i] & 0x1) + '0';
//	}
//	binary[m << 1] = 0;
//	printf("%s\n", binary);
//	return 0;
//}