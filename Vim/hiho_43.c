//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define LONGLONG long long
//#define MOD 12357
//#define L (1 << 7)
//
//int k;
//
//LONGLONG m[L][L], c[L][L];
//LONGLONG a[L], codata[L];
//
//void mulm(LONGLONG a[][L], LONGLONG b[][L], LONGLONG ret[][L], int powk)
//{
//	int i, j, k;
//	memset(c, 0, L * L * sizeof(LONGLONG));
//	for (i = 0; i < powk; i++) {
//		for (j = 0; j < powk; j++) {
//			if (a[i][j] == 0) {
//				continue;
//			}
//			for (k = 0; k < powk; k++) {
//				c[i][k] += a[i][j] * b[j][k];
//			}
//			c[i][j] %= MOD;
//		}
//	}
//	memcpy(ret, c, L * L * sizeof(LONGLONG));
//}
//
//void mula(LONGLONG *a, LONGLONG m[][L], LONGLONG *ret, int powk)
//{
//	int i, j;
//	memset(codata, 0, powk * sizeof(LONGLONG));
//	for (i = 0; i < powk; i++) {
//		for (j = 0; j < powk; j++) {
//			codata[i] += a[j] * m[j][i];
//		}
//		codata[i] %= MOD;
//	}
//	memcpy(ret, codata, powk * sizeof(LONGLONG));
//}
//
//
//static void dfs(int x, int y, int col, LONGLONG d[][L])
//{
//	if (col == k) {
//		d[y][x] = 1;
//		return;
//	}
//	dfs(x << 1, (y << 1) + 1, col + 1, d);
//	dfs((x << 1) + 1, y << 1, col + 1, d);
//	if (col + 2 <= k) {
//		dfs((x << 2) + 3, (y << 2) + 3, col + 2, d);
//	}
//}
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//	int n, i, powk;
//	fscanf(file, "%d%d", &k, &n);
//	//scanf("%d%d", &k, &n);
//	powk = 1 << k;
//
//	a[powk - 1] = 1;
//	dfs(0, 0, 0, m);
//
//	for (; n > 0; n >>= 1, mulm(m, m, m, powk)) {
//		if (n & 1) {
//			mula(a, m, a, powk);
//		}
//	}
//	printf("%d\n", a[powk - 1]);
//
//	return 0;
//}