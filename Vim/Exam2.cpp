//#include <stdio.h>
//#include <cmath>
//
//using namespace std;
//
//#define L 100002
//#define Q 19
//
//#define MIN(a, b) (nodes[(a)].h < nodes[(b)].h ? (a) : (b))
//
//typedef struct _Node {
//	int next;
//	int h, arraypos;
//}NODE;
//
//typedef struct _EDGE{
//	int to, next;
//}EDGE;
//
//int gIndex = 0;
//
//NODE nodes[L];
//EDGE edges[2 * L];
//int mb[Q];
//int pre[Q][2 * L];
//
//void process(int n, int q)
//{
//	int i, j, l;
//	mb[0] = 1;
//	for (i = 1; i < Q; i++) {
//		mb[i] = mb[i - 1] << 1;
//	}
//	for (i = 1; i <= q; i++) {
//		l = n - mb[i];
//		for (j = 0; j <= l; j++) {
//			pre[i][j] = MIN(pre[i - 1][j], pre[i - 1][j + mb[i - 1]]);
//
//		}
//	}
//}
//
//void build(int u, int v)
//{
//	gIndex++;
//	edges[gIndex].to = v;
//	edges[gIndex].next = nodes[u].next;
//	nodes[u].next = gIndex;
//}
//void dfs(int u, int h, int p)
//{
//	int i, v;
//	pre[0][gIndex] = u;
//	nodes[u].h = h;
//	nodes[u].arraypos = gIndex++;
//	for (i = nodes[u].next; i ; i = edges[i].next) {
//		v = edges[i].to;
//		if (v != p) {
//			dfs(v, h + 1, u);
//			pre[0][gIndex] = u;
//			nodes[u].arraypos = gIndex++;
//		}
//	}
//}
//
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int n, m, u, v, q, l, r, t, ret;
//	scanf("%d%d", &n, &m);
//	n--;
//	while (n--) {
//		scanf("%d%d", &u, &v);
//		build(u, v);
//		build(v, u);
//	}
//
//	gIndex = 0;
//	dfs(1, 0, 0);
//	n = gIndex;
//	q = log(n) / log(2);
//	process(n, q);
//	u = 1;
//
//	while (m--) {
//		scanf("%d%d", &q, &v);
//		if (q == 1) {
//			u = v;
//		}
//		else {
//			l = nodes[u].arraypos + 1;
//			r = nodes[v].arraypos + 1;
//			if (l > r) {
//				l ^= r;
//				r ^= l;
//				l ^= r;
//			}
//
//			t = log(r - l + 1) / log(2);
//			ret = MIN(pre[t][l - 1], pre[t][r - mb[t]]);
//			printf("%d\n", nodes[u].h + nodes[v].h - 2 * nodes[ret].h);
//		}
//		
//	}
//	return 0;
//}