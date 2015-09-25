//#include <stdio.h>
//#include <string.h>
//
//#define L 101
//
//int main()
//{
//	int i, j, k, n, m, u, v, len, temp;
//	int dis[L][L];
//	memset(dis, 0x3f, sizeof(dis));
//	scanf("%d%d", &n, &m);
//	for (i = 0; i < m; i++) {
//		scanf("%d%d%d", &u, &v, &len);
//		dis[v][u] = dis[u][v] = dis[u][v] > len ? len : dis[u][v];
//	}
//	for (k = 1; k <= n; k++) {
//		for (i = 1; i <= n; i++) {
//			dis[i][i] = 0;
//			for (j = i + 1; j <= n; j++) {
//				if (i != k && j != k) {
//					temp = dis[i][k] + dis[k][j];
//					dis[j][i] = dis[i][j] = dis[i][j] > temp ? temp : dis[i][j];
//				}
//			}
//		}
//	}
//	for (i = 1; i <= n; i++) {
//		for (j = 1; j < n; j++) {
//			printf("%d ", dis[i][j]);
//		}
//		printf("%d\n", dis[i][j]);
//	}
//	return 0;
//}