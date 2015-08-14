//#include <stdio.h>
//#include <map>
//
//#define N 20001
//#define M 100001
//#define MIN(a, b) ((a) < (b) ? (a) : (b))
//
//using namespace std;
//
//typedef struct _NODE {
//	int next;
//}NODE;
//
//typedef struct _EDGE {
//	int to, next;
//	int id;
//}EDGE;
//
//typedef struct _GROUP {
//	int p, min;
//	int mark;
//}GROUP;
//
//NODE nodes[N];
//EDGE edges[2 * M];
//int low[N];
//int dfn[N];
//int vis[N];
//int parent[N];
//GROUP group[M];
//int edgestack[2 * M];
//
//int gIndex = 0;
//int groupcount = 1;
//int top = 0;
//
////map<int, int> nodemap;
////map<int, map<int, int>> edgemap;
//
//void build(int u, int v, int edgeIndex)
//{
//	gIndex++;
//	edges[gIndex].to = v;
//	edges[gIndex].next = nodes[u].next;
//	edges[gIndex].id = edgeIndex;
//	nodes[u].next = gIndex;
//}
//
//void buildGroup(int u, int v, int id)
//{
//	int nowedge;
//	do {
//		top--;
//		nowedge = edgestack[top];
//		group[nowedge].p = id;
//		group[nowedge].mark = 1;
//		group[id].min = nowedge < group[id].min ? nowedge : group[id].min;
//	} while (id != nowedge);
//}
//
//void dfs(int u)
//{
//	int i, v, id, child = 0;
//	low[u] = dfn[u] = ++gIndex;
//	vis[u] = 1;
//	for (i = nodes[u].next; i; i = edges[i].next) {
//		v = edges[i].to;
//		id = edges[i].id;
//		if (group[id].mark == 1) {
//			continue;
//		}
//		if (vis[v] == 0) {
//			edgestack[top++] = id;
//			parent[v] = u;
//			child++;
//			dfs(v);
//			low[u] = MIN(low[u], low[v]);
//
//			if (parent[u] == 0 && child > 1) {
//				groupcount++;
//				buildGroup(u, v, id);
//			}
//
//			if (parent[u] != 0 && low[v] >= dfn[u]) {
//				groupcount++;
//				buildGroup(u, v, id);
//			}
//
//		}
//		else if (parent[u] != v) {
//			edgestack[top++] = id;
//			low[u] = MIN(low[u], dfn[v]);
//		}
//	}
//}
//
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//	int i, n, m, u, v, nowedge, id;
//	fscanf(file, "%d%d", &n, &m);
//	for (i = 0; i < m; i++) {
//		fscanf(file, "%d%d", &u, &v);
//		build(u, v, i + 1);
//		build(v, u, i + 1);
//		group[i + 1].min = group[i + 1].p = i + 1;
//	}
//	gIndex = 0;
//	dfs(1);
//	id = edgestack[0];
//	while (top > 0) {
//		top--;
//		nowedge = edgestack[top];
//		group[nowedge].p = id;
//		group[id].min = nowedge < group[id].min ? nowedge : group[id].min;
//	}
//	printf("%d\n", groupcount);
//	for (i = 1; i < m; i++) {
//		printf("%d ",group[group[i].p].min);
//	}
//	printf("%d\n", group[group[i].p].min);
//	return 0;
//}