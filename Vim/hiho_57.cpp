//#include <stdio.h>
//#include <math.h>
//
//#define N 30
//#define C 6
//#define R 5
//
//int matrix[N][N + 1];
//char board[N + 1];
//int value[N];
//
//int gCount = 0;
//
//void swaprow(int a, int b, int n)
//{
//	int i;
//	double temp;
//	if (a != b) {
//		for (i = 0; i < n; i++) {
//			if (matrix[a][i] != matrix[b][i]) {
//				temp = matrix[b][i];
//				matrix[b][i] = matrix[a][i];
//				matrix[a][i] = temp;
//			}
//		}
//	}
//}
//
//void ge(int m, int n)
//{
//	int i, j, k, flag, mflag = 0;
//	for (i = 0; i < n - 1; i++) {
//		flag = 0;
//		for (j = i; j < m; j++) {
//			if (matrix[j][i] != 0) {
//				swaprow(j, i, n);
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0) {
//			mflag = 1;
//			continue;
//		}
//		for (j = i + 1; j < m; j++) {
//			if (matrix[j][i] != 0) {
//				for (k = n - 1; k >= i; k--) {
//					matrix[j][k] ^= matrix[i][k];
//				}
//			}
//		}
//	}
//
//	for (i = n - 2; i >= 0; i--) {
//		for (j = i + 1; j < n - 1; j++) {
//			matrix[i][n - 1] ^= matrix[i][j] * value[j];
//		}
//		value[i] = matrix[i][n - 1];
//		if (value[i] == 1) {
//			gCount++;
//		}
//	}
//}
//
//
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//	int i, j;
//	for (i = 0; i < R; i++) {
//		fscanf(file, "%s", board + C * i);
//	}
//	for (i = 0; i < N; i++) {
//		int irow = i / C;
//		int icol = i % C;
//		for (j = 0; j < N; j++) {
//			int row = j / C;
//			int col = j % C;
//			if (j == i || (row == irow && abs(col - icol) == 1) || (col == icol && abs(row - irow) == 1)) {
//				matrix[i][j] = 1;
//			}
//		}
//		matrix[i][j] = 1 ^ (board[i] - '0');
//	}
//	ge(N, N + 1);
//	printf("%d\n", gCount);
//	for (i = 0; i < N; i++) {
//		if (value[i] == 1) {
//			printf("%d %d\n", i / C + 1, i % C + 1);
//		}
//	}
//	return 0;
//}