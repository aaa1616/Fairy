//#include <stdio.h>
//#include <string.h>
//
//#define N 2102
//#define __max(a,b)  (((a) > (b)) ? (a) : (b))
//#define __max3(a, b, c) ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))
//
//int d[N][N][2];
//int f[N][N];
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int n, m, i, j;
//	char a[N], b[N];
//	a[0] = '0';
//	b[0] = '0';
//	scanf("%s%s", a + 1, b + 1);
//	n = strlen(a) - 1;
//	m = strlen(b) - 1;
//
//	for (i = 1; i <= n; i++) {
//		for (j = 1; j <= m; j++) {
//			if (a[i] == b[j]) {
//				f[i][j] = f[i - 1][j - 1] + 1;
//			}
//			else {
//				f[i][j] = 0;
//			}
//		}
//	}
//
//	int fv = 0;
//	for (i = 1; i <= n; i++) {
//		for (j = 1; j <= m; j++) {
//			fv = f[i][j];
//			if (fv >= 3){
//				d[i][j][1] = d[i - 3][j - 3][0] + 3;
//				if (fv > 3) {
//					d[i][j][1] = __max(d[i - 1][j - 1][1] + 1, d[i][j][1]);
//				}
//			}
//			d[i][j][0] = __max3(d[i - 1][j][0], d[i][j - 1][0], d[i][j][1]);
//		}
//	}
//
//	printf("%d\n", d[n][m][0]);
//	return 0;
//}