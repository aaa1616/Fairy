//#include <stdio.h>
//#include <queue>
//
//using namespace std;
//
//#define N 1001
//#define M 5001
//
//typedef struct _NODE {
//	int color;
//	int match;
//	int next;
//	int vis;
//}NODE;
//
//typedef struct _EDGE {
//	int to, next;
//	int type;
//}EDGE;
//
//NODE nodes[N];
//EDGE edges[2 * M];
//
//int gIndex = 0;
//int gCount = 0;
//
//queue<int> q;
//
//void build(int u, int v)
//{
//	gIndex++;
//	edges[gIndex].to = v;
//	edges[gIndex].type = 0;
//	edges[gIndex].next = nodes[u].next;
//	nodes[u].next = gIndex;
//	nodes[u].color = -1;
//}
//
//void bfs(int u, int color)
//{
//	int i, v;
//	nodes[u].color = color;
//	q.push(u);
//	while (!q.empty()) {
//		u = q.front();
//		q.pop();
//		color = nodes[u].color;
//		for (i = nodes[u].next; i; i = edges[i].next) {
//			v = edges[i].to;
//			if (nodes[v].color == -1) {
//				nodes[v].color = !color;
//				q.push(v);
//			}
//		}
//	}
//}
//
//int dfs(int u)
//{
//	int i, v;
//	if (nodes[u].vis == gIndex) {
//		return 0;
//	}
//	nodes[u].vis = gIndex;
//	for (i = nodes[u].next; i; i = edges[i].next) {
//		v = edges[i].to;
//		if (nodes[v].match == 0 || dfs(nodes[v].match)) {
//			nodes[v].match = u;
//			return 1;
//		}
//	}
//
//	return 0;
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int n, m, i, u, v;
//	scanf("%d%d", &n, &m);
//	while (m--) {
//		scanf("%d%d", &u, &v);
//		build(u, v);
//		build(v, u);
//	}
//	for (i = 1; i <= n; i++) {
//		if (nodes[i].color == -1) {
//			bfs(i, 0);
//		}
//	}
//	gIndex = 0;
//	for (i = 1; i <= n; i++) {
//		if (nodes[i].color == 0 && nodes[i].match == 0) {
//			gIndex++;
//			gCount += dfs(i);
//		}
//	}
//	printf("%d\n", gCount);
//	return 0;
//}