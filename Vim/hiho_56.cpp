//#include <stdio.h>
//#include <math.h>
//
//#define N 501
//#define M 1000
//
//double matrix[M][N];
//int value[N];
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
//int ge(int m, int n)
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
//			for (k = n - 1; k >= i; k--) {
//				matrix[j][k] -= matrix[i][k] * (matrix[j][i] / matrix[i][i]);
//			}
//		}
//	}
//
//	for (i = 0; i < m; i++) {
//		flag = 0;
//		for (j = 0; j < n - 1; j++) {
//			if (matrix[i][j] != 0) {
//				flag = 1;
//			}
//		}
//		if (flag == 0 && matrix[i][j] != 0) {
//			return 2;
//		}
//	}
//	if (mflag == 1) {
//		return 1;
//	}
//
//	for (i = n - 2; i >= 0; i--) {
//		for (j = i + 1; j < n - 1; j++) {
//			matrix[i][n - 1] -= matrix[i][j] * value[j];
//		}
//		value[i] = (int)round(matrix[i][n - 1] / matrix[i][i]);
//	}
//	return 0;
//}
//
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//	int m, n, i, j, result;
//	fscanf(file, "%d%d", &n, &m);
//	for (i = 0; i < m; i++) {
//		for (j = 0; j < n + 1; j++) {
//			fscanf(file, "%lf", &matrix[i][j]);
//		}
//	}
//	result = ge(m, n + 1);
//	switch (result)
//	{
//	case 0:
//		for (i = 0; i < n; i++) {
//			printf("%d\n", value[i]);
//		}
//		break;
//	case 1:
//		printf("Many solutions\n");
//		break;
//	case 2:
//		printf("No solutions\n");
//		break;
//	default:
//		break;
//	}
//	return 0;
//}