//#include <stdio.h>
//
//#define N 13
//
//int edges[1 << N];
//int p[1 << N];
//int unused;
//int gCount;
//
//void dfs(int u)
//{
//	int rest, i;
//	unused ^= 1 << (u - 1);
//	if (!unused) {
//		gCount += edges[u] & 1;
//	}
//	else {
//		rest = unused & edges[u];
//		while (rest) {
//			i = rest & -rest;
//			dfs(p[i]);
//			rest ^= i;
//		}
//	}
//	unused ^= 1 << (u - 1);
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int i, n, m, u, v;
//	scanf("%d%d", &n, &m);
//	unused = (1 << n) - 1;
//	for (i = 0; i < n; i++) {
//		p[1 << i] = i + 1;
//	}
//	while (m--) {
//		scanf("%d%d", &u, &v);
//		edges[u] |= 1 << (v - 1);
//	}
//	dfs(1);
//	printf("%d\n", gCount);
//	return 0;
//}