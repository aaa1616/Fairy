//#include <stdio.h>
//
//#define N 1001
//
//int matrix[N][N];
//int d[N][N];
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int m, n, i, j, left, bot, other;
//	scanf("%d%d", &m, &n);
//	for (i = 0; i < m; i++) {
//		for (j = 0; j < n; j++) {
//			scanf("%d", &matrix[i][j]);
//		}
//	}
//	d[m - 1][0] = matrix[m - 1][0] == 1 ? 1 : 0;
//	for (i = m - 2; i >= 0; i--) {
//		if (d[i + 1][0] == 0 || matrix[i][0] == 0) {
//			d[i][0] = 0;
//		}
//		else {
//			d[i][0] = 1;
//		}
//	}
//	for (i = 1; i < n; i++) {
//		if (d[m - 1][i - 1] == 0 || matrix[m  -1][i] == 0) {
//			d[m - 1][i] = 0;
//		}
//		else {
//			d[m - 1][i] = 1;
//		}
//	}
//
//
//	for (i = m - 2; i >= 0; i--) {
//		for (j = 1; j < n; j++) {
//			if (matrix[i][j] == 1) {
//				left = matrix[i][j - 1] == 1 ? d[i][j - 1] : 0;
//				bot = matrix[i + 1][j] == 1 ? d[i + 1][j] : 0;
//				other = matrix[i + 1][j - 1] == 1 ? d[i + 1][j - 1] : 0;
//				d[i][j] = left + bot + other;
//			}
//		}
//	}
//	printf("%d\n", d[0][n - 1]);
//	return 0;
//}