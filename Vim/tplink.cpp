//#include <stdio.h>
//#include <string.h>
//
//#define N 1001
//
//typedef struct _NODE {
//	int next;
//}NODE;
//	
//typedef struct _EDGE {
//	int to;
//	int next;
//}EDGE;
//
//int vis[N];
//NODE nodes[N];
//EDGE edges[N * (N - 1)];
//	
//	
//int gIndex = 0;
//int ret = 0;
//
//void build(int a, int b)
//{
//	gIndex++;
//	edges[gIndex].to = b;
//	edges[gIndex].next = nodes[a].next;
//	nodes[a].next = gIndex;
//}
//
//void dfs(int u)
//{
//	int i, v;
//	vis[u] = 1;
//	for (i = nodes[u].next; i; i = edges[i].next) {
//		v = edges[i].to;
//		if (!vis[v]) {
//			ret++;
//			dfs(v);
//		}
//	}
//}
//
//int main()
//{
//
//	freopen("input.txt", "r", stdin);
//	int n, m, u, v;
//	while (1) {
//		scanf("%d%d", &n, &m);
//		if (n == 0 && m == 0) {
//			break;
//		}
//		else {
//			ret = 0;
//			memset(vis, 0, sizeof(vis));
//			memset(nodes, 0, sizeof(nodes));
//			memset(edges, 0, sizeof(edges));
//			while (m--) {
//				scanf("%d%d", &u, &v);
//				build(u, v);
//				build(v, u);
//			}
//			dfs(1);
//			printf("%d\n", ret);
//		}
//	}
//	return 0;
//}