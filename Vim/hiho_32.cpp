//#include <stdio.h>
//#include <string.h>
//
//using namespace std;
//
//#define N 11
//
//typedef struct _UDEFINE {
//	int i, j;
//	int mine;
//}UDEFINE;
//
//int matrix[N][N];
//UDEFINE ud[N];
//
//int gN, gM, gK;
//int gIndex = 0;
//
//void check()
//{
//	int i, j, x, y;
//	int mine;
//	for (i = 1; i <= gN; i++) {
//		for (j = 1; j <= gM; j++) {
//			if (matrix[i][j] >= 0) {
//				mine = 0;
//				for (x = -1; x <= 1; x++) {
//					for (y = -1; y <= 1; y++) {
//						if (matrix[i + x][j + y] == -1) {
//							mine++;
//						}
//					}
//				}
//				if (matrix[i][j] != mine) {
//					return;
//				}
//			}
//		}
//	}
//
//	gIndex++;
//	for (i = 0; i < gK; i++) {
//		if (matrix[ud[i].i][ud[i].j] == -1) {
//			ud[i].mine++;
//		}
//	}
//}
//
//void solve(int k)
//{
//	if (k == gK) {
//		check();
//		return ;
//	}
//
//	matrix[ud[k].i][ud[k].j] = -1;
//	solve(k + 1);
//	matrix[ud[k].i][ud[k].j] = -2;
//	solve(k + 1);
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int t, i, j, yes, no;
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%d%d", &gN, &gM);
//		memset(matrix, 0, sizeof(matrix));
//		gK = yes = no = gIndex = 0;
//		for (i = 1; i <= gN; i++) {
//			for (j = 1; j <= gM; j++) {
//				scanf("%d", &matrix[i][j]);
//				if (matrix[i][j] == -1) {
//					ud[gK].i = i;
//					ud[gK].j = j;
//					ud[gK].mine = 0;
//					gK++;
//				}
//			}
//		}
//		solve(0);
//		for (i = 0; i < gK; i++) {
//			if (ud[i].mine == 0) {
//				no++;
//			}
//			if (ud[i].mine == gIndex) {
//				yes++;
//			}
//		}
//		printf("%d %d\n", yes, no);
//	}
//
//	return 0;
//}