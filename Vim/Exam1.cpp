//#include <stdio.h>
//#include <algorithm>
//#include <time.h>
//
//using namespace std;
//
//#define N 502
//
//int a[N][N];
//int d[N], u[N], c[N];
//
//int main()
//{
//	int i, j, n, m, k, ret = -1, last = 0;
//	int one, flag;
//	//FILE *file = fopen("input.txt", "w");
//	//srand(time(NULL));
//	//n = rand() % 9;
//	//m = rand() % 9;
//	//fprintf(file, "%d %d\n", n, m);
//	//for (i = 1; i <= n; i++) {
//	//	for (j = 1; j <= m; j++) {
//	//		int temp = rand() % 16 - 6;
//	//		fprintf(file, "%d\t", temp < 0 ? -1 : temp);
//	//	}
//	//	fprintf(file, "\n");
//	//}
//	//fclose(file);
//	
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d", &n, &m);
//	for (i = 1; i <= n; i++) {
//		for (j = 1; j <= m; j++) {
//			scanf("%d", &a[i][j]);
//		}
//	}
//	for (j = 1; j <= m; j++) {
//		flag = false;
//		last = i = 1;
//		one = false;
//		while (1) {
//			if (!one && a[i][j] == -1) {
//				d[i] = -1;
//			}
//			else {
//				if (!one) {
//					if ((i == 1 || d[i - 1] == -1) && c[i] == -1) {
//						d[i] = -1;
//					}
//					else {
//						if (c[i] != -1) {
//							last = i;
//						}
//						d[i] = max(d[i - 1], c[i]) + a[i][j];
//					}
//				}
//				else {
//					if (i == last) {
//						break;
//					}
//					if (a[i][j] != -1 && d[i - 1] != -1) {
//						d[i] = max(d[i], d[i - 1] + a[i][j]);
//					}
//				}
//			}
//			//printf("%d ", d[i]);
//			i = (i + 1) % (n + 1);
//			if (i == 0 && !one) {
//				d[i++] = d[n] == -1 ? -1 : 0;
//				one = 1;
//			}
//			else if (i == 0 && one) {
//				break;
//			}
//		}
//		//printf("\n");
//		last = i = n;
//		one = false;
//		while (1) {
//			if (!one && a[i][j] == -1) {
//				u[i] = -1;
//			}
//			else {
//				if (!one) {
//					if ((i == n || u[i + 1] == -1) && c[i] == -1) {
//						u[i] = -1;
//					}
//					else {
//						if (c[i] != -1) {
//							last = i;
//						}
//						u[i] = max(u[i + 1], c[i]) + a[i][j];
//					}
//				}
//				else {
//					if (i == last) {
//						break;
//					}
//					if (a[i][j] != -1 && u[i + 1] != -1) {
//						u[i] = max(u[i], u[i + 1] + a[i][j]);
//					}
//				}
//			}
//			//printf("%d ", u[i]);
//			i = (i - 1) % (n + 1);
//			if (i == 0 && !one) {
//				u[n + 1] = u[1] == -1 ? -1 : 0;
//				i = n;
//				one = 1;
//			}
//			else if (i == 0 && one) {
//				break;
//			}
//		}
//		//printf("\n");
//		//printf("Col%d : ", j);
//		for (i = 1; i <= n; i++) {
//			c[i] = max(d[i], u[i]);
//			//printf("%d ", c[i]);
//			if (c[i] != -1) {
//				flag = true;
//			}
//		}
//		//printf("\n");
//		if (!flag) {
//			printf("-1\n");
//			return 0;
//		}
//	}
//	for (i = 1; i <= n; i++) {
//		ret = max(ret, c[i]);
//	}
//	printf("%d\n", ret);
//	return 0;
//}