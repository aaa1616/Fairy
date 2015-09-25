//#include <stdio.h>
//#include <string.h>
//#include <queue>
//
//using namespace std;
//
//#define N 10001
//#define M 40001
//
//typedef struct _NODE {
//	int color;
//	int next;
//}NODE;
//
//typedef struct _EDGE {
//	int to, next;
//}EDGE;
//
//NODE nodes[N];
//EDGE edges[2 * M];
//
//queue<int> q;
//
//int gIndex = 0;
//
//void build(int u, int v)
//{
//	gIndex++;
//	edges[gIndex].to = v;
//	edges[gIndex].next = nodes[u].next;
//	nodes[u].next = gIndex;
//	nodes[u].color = -1;
//}
//
//int dfs(int u, int color)
//{
//	int i, v;
//	if (nodes[u].color == -1) {
//		nodes[u].color = color;
//	}
//	else {
//		if (nodes[u].color == color) {
//			return 1;
//		}
//		else {
//			return 0;
//		}
//	}
//	for (i = nodes[u].next; i; i = edges[i].next) {
//		v = edges[i].to;
//		if (!dfs(v, !color)) {
//			return 0;
//		}
//	}
//
//	return 1;
//}
//
//int bfs(int s, int color)
//{
//	int u, v, i;
//	q.push(s);
//	nodes[s].color = color;
//	while (!q.empty()) {
//		u = q.front();
//		q.pop();
//		color = nodes[u].color;
//		for (i = nodes[u].next; i; i = edges[i].next) {
//			v = edges[i].to;
//			if (nodes[v].color == -1) {
//				nodes[v].color = !color;
//					q.push(v);
//			}
//			else if (nodes[v].color == color) {
//				while (!q.empty()) {
//					q.pop();
//				}
//				return 0;
//			}
//		}
//	}
//
//	return 1;
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int t, i, u, v, n, m, result;
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%d%d", &n, &m);
//		gIndex = 0;
//		memset(nodes, 0, sizeof(nodes));
//		memset(edges, 0, sizeof(edges));
//		while (m--) {
//			scanf("%d%d", &u, &v);
//			build(u, v);
//			build(v, u);
//		}
//		for (i = 1; i <= n; i++) {
//			if (nodes[i].color == -1) {
//				result = bfs(i, 0);// dfs(i, 0);
//				if (!result) {
//					break;
//				}
//			}
//		}
//
//		if (result) {
//			printf("Correct\n");
//		}
//		else {
//			printf("Wrong\n");
//		}
//	}
//
//	return 0;
//}