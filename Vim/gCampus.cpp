//#include <stdio.h>
//#include <string.h>
//#include <map>
//#include <vector>
//#include <algorithm>
//
//#define L 101
//#define M 10011
//
//using namespace std;
//
//map<int, map<int, int>> road;
//int gIndex = 0;
//int output[M];
//
//#define ONLINE_JUDGE
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//#else
//	freopen("codejam input/A-small-1-attempt0.in", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
//
//	int t, ii, i, j, k, n, m, u, v, len, temp;
//	int dis[L][L];
//	int orig[L][L];
//	scanf("%d", &t);
//	for (ii = 1; ii <= t; ii++) {
//		scanf("%d%d", &n, &m);
//		memset(dis, 0x3f, sizeof(dis));
//		memset(orig, 0x3f, sizeof(dis));
//		road.clear();
//		gIndex = 0;
//		for (i = 0; i < m; i++) {
//			scanf("%d%d%d", &u, &v, &len);
//			orig[u][v] = len;
//			dis[v][u] = dis[u][v] = dis[u][v] > len ? len : dis[u][v];
//			road[u][v] = gIndex++;
//		}
//		printf("Case #%d:\n", ii);
//		for (k = 0; k <= n - 1; k++) {
//			for (i = 0; i <= n - 1; i++) {
//				dis[i][i] = 0;
//				for (j = i + 1; j <= n - 1; j++) {
//					if (i != k && j != k) {
//						temp = dis[i][k] + dis[k][j];
//						dis[j][i] = dis[i][j] = dis[i][j] > temp ? temp : dis[i][j];
//					}
//				}
//			}
//		}
//		gIndex = 0;
//		map<int, map<int, int>>::iterator it1;
//		map<int, int>::iterator it2;
//		for (it1 = road.begin(); it1 != road.end(); it1++) {
//			for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
//				u = it1->first;
//				v = it2->first;
//				if (orig[u][v] > dis[u][v]) {
//					output[gIndex++] = it2->second;
//				}
//			}
//		}
//		sort(output, output + gIndex);
//		for (i = 0; i < gIndex; i++) {
//			printf("%d\n", output[i]);
//		}
//	}
//	return 0;
//}