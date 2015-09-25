//#include <stdio.h>
//#include <string.h>
//#include <queue>
//
//using namespace std;
//
//#define N 100001
//#define M 1000001
//
//typedef struct _NODE {
//	int dis;
//	int next;
//}NODE;
//
//typedef struct _EDGE {
//	int to, next;
//	int w;
//}EDGE;
//
//NODE nodes[N];
//EDGE edges[M << 1];
//queue<int> q;
//int gIndex = 0;
//
//void build(int u, int v, int w)
//{
//	gIndex++;
//	edges[gIndex].to = v;
//	edges[gIndex].w = w;
//	edges[gIndex].next = nodes[u].next;
//	nodes[u].next = gIndex;
//	nodes[u].dis = 2000000000;
//}
//
//int main()
//{
//	// 	freopen("input.txt", "r", stdin);
//	int n, m, s, t;
//	int u, v, len;
//	int i, j;
//	int vis[N];
//	scanf("%d%d%d%d", &n, &m, &s, &t);
//	memset(vis, 0, sizeof(vis));
//	for (i = 0; i < m; i++) {
//		scanf("%d%d%d", &u, &v, &len);
//		build(u, v, len);
//		build(v, u, len);
//	}
//	nodes[s].dis = 0;
//	q.push(s);
//	vis[s] = 1;
//	while (!q.empty()) {
//		int i;
//		int u = q.front();
//		q.pop();
//		vis[u] = 0;
//		for (i = nodes[u].next; i; i = edges[i].next) {
//			v = edges[i].to;
//			int nextdis = nodes[u].dis + edges[i].w;
//			if (nodes[v].dis > nextdis) {
//				nodes[v].dis = nextdis;
//				if (vis[v] == 0) {
//					q.push(v);
//					vis[v] = 1;
//				}
//			}
//		}
//	}
//
//	printf("%d\n", nodes[t].dis);
//	return 0;
//}