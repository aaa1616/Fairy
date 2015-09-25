//#include <stdio.h>
//
//using namespace std;
//
//#define N 100001
//
//typedef struct _NODE {
//	int visit;
//	int next;
//	int len;
//}NODE;
//
//typedef struct _EDGE {
//	int w;
//	int next;
//	int to;
//}EDGE;
//
//NODE nodes[2 * N];
//EDGE edges[2 * N];
//
//int gIndex = 0;
//int gT;
//
//void build(int a, int b, int w)
//{
//	gIndex++;
//	edges[gIndex].w = w;
//	edges[gIndex].to = b;
//	edges[gIndex].next = nodes[a].next;
//	nodes[a].next = gIndex;
//}
//
//int f(int u, int w, int k)
//{
//	int i, v;
//	if (u == gT && k >= 0) {
//		return 1;
//	}
//
//	if (k == 0 && u != gT) {
//		return 0;
//	}
//
//	if (nodes[u].visit == gIndex && nodes[u].len > k) {
//		return 0;
//	}
//	nodes[u].len = k;
//	nodes[u].visit = gIndex;
//	for (i = nodes[u].next; i; i = edges[i].next) {
//		if (edges[i].w <= w) {
//			v = edges[i].to;
//			if (f(v, w, k - 1)) {
//				return 1;
//			}
//		}
//	}
//
//	return 0;
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	//freopen("output38_1.txt", "w", stdout);
//	int n, m, k, min = 1000000, max = 0, u, v, w, l, r, mid;
//	scanf("%d%d%d%d", &n, &m, &k, &gT);
//	while (m--) {
//		scanf("%d%d%d", &u, &v, &w);
//		build(u, v, w);
//		build(v, u, w);
//		if (w < min) {
//			min = w;
//		}
//		if (w > max) {
//			max = w;
//		}
//	}
//	l = min;
//	r = max;
//	while (l < r) {
//		mid = (l + r) >> 1;
//		gIndex++;
//		if (f(1, mid, k)) {
//			r = mid;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//
//	printf("%d\n", l);
//	return 0;
//}