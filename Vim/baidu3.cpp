//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//#define MAX(a, b, c) ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))
//
//#define N 5000
//
//int a[N];
//int result[N];
//int d[N][N];
//
//int gIndex = 0;
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int i, j, n, m, k, sum;
//	int temp, temp1, temp2;
//	scanf("%d%d%d", &n, &m, &k);
//	for (i = 0; i < n; i++) {
//		scanf("%d", a + i);
//	}
//
//	for (i = 0; i < n - m; i++) {
//		sum = 0;
//		for (j = 0; j < m; j++) {
//			sum += a[i + j];
//		}
//		result[i + j - 1] = sum;
//	}
//	for (j = 1; j <= k; j++) {
//		for (i = 0 + m - 1; i < n; i++) {
//			temp = i - m >= 0 ? d[i - m][j - 1] : 0;
//			temp1 = i - 2 >= 0 ? d[i - 2][j] : 0;
//			temp2 = i - 1 >= 0 ? d[i - 1][j] : 0;
//			d[i][j] = MAX(temp + result[i], temp1, temp2);
//		}
//	}
//	printf("%d\n", d[i - 1][k]);
//	return 0;
//}