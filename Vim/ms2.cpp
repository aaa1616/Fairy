//#include <stdio.h>
//#include <string.h>
//#include <unordered_map>
//
//#define N 100001
//
//using namespace std;
//
//typedef struct _NODE {
//	int next;
//	int d;
//}NODE;
//
//typedef struct _EDGE {
//	int to;
//	int next;
//	int dis;
//}EDGE;
//
//int vis[N];
//NODE nodes[N];
//EDGE edges[2 * N];
//int dis[N];
//unordered_map<int, unordered_map<int, int>> um;
//	
//int gIndex = 0;
//
//void build(int a, int b, int dis)
//{
//	gIndex++;
//	edges[gIndex].to = b;
//	edges[gIndex].next = nodes[a].next;
//	edges[gIndex].dis = dis;
//	nodes[a].next = gIndex;
//	nodes[a].d++;
//}
//
//void dfs(int u)
//{
//	int i, v;
//	vis[u] = 1;
//	for (i = nodes[u].next; i; i = edges[i].next) {
//		v = edges[i].to;
//		if (!vis[v]) {
//			dis[gIndex] = edges[i].dis;
//			um[u][v] = gIndex;
//			um[v][u] = gIndex;
//			gIndex++;
//			dfs(v);
//		}
//	}
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	char str[10];
//	long long i;
//	int n, m, u, v, d;
//	int temp;
//	long long sum = 0;
//	scanf("%d%d", &n, &m);
//	temp = n;
//	temp--;
//	while (temp--) {
//		scanf("%d%d%d", &u, &v, &d);
//		build(u, v, d);
//		build(v, u, d);
//	}
//	for (i = 1; i <= n; i++) {
//		if (nodes[i].d == 1) {
//			u = i;
//			break;
//		}
//	}
//	gIndex = 0;
//	dfs(u);
//
//	for (i = 0; i < gIndex; i++) {
//		sum += (i * (n - i - 1) + n - i - 1) * dis[i];
//	}
//
//	while (m--) {
//		scanf("%s", str);
//		if (strcmp(str, "EDIT") == 0) {
//			scanf("%d%d%d", &u, &v, &d);
//			i = um[u][v];
//			sum += (i * (n - i - 1) + n - i - 1) * (d - dis[i]);
//			dis[i] = d;
//		}
//		else {
//			printf("%lld\n", sum);
//		}
//	}
//
//	return 0;
//}