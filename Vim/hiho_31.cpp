//#include <stdio.h>
//#include <string.h>
//#include <set>
//
//using namespace std;
//
//#define N 210
//
//int matrix[N][N];
//
//set<int> yes, no;
//
//int gN, gM;
//
//int inside(int col, int row)
//{
//	if (col < 2 || col > gN + 1 || row < 2 || row > gM + 1) {
//		return 0;
//	}
//
//	return 1;
//}
//
//void check_single(int col, int row)
//{
//	int i, j, temp_col, temp_row;
//	if (matrix[col][row] == 0) {
//		for (i = -1; i <= 1; i++) {
//			for (j = -1; j <= 1; j++) {
//				temp_col = col + i;
//				temp_row = row + j;
//				if (matrix[temp_col][temp_row] == -1) {
//					no.insert((temp_col - 2) * gM + temp_row - 1);
//				}
//			}
//		}
//	}
//	else {
//		int cover = 0;
//		int coverArray[10];
//		for (i = -1; i <= 1; i++) {
//			for (j = -1 ; j <= 1; j++) {
//				temp_col = col + i;
//				temp_row = row + j;
//				if (matrix[temp_col][temp_row] == -1) {
//					coverArray[cover++] = (temp_col - 2) * gM + temp_row - 1;
//				}
//			}
//		}
//		if (cover <= matrix[col][row]) {
//			for (i = 0; i < cover; i++) {
//				yes.insert(coverArray[i]);
//			}
//		}
//		else {
//			int maxcol, maxrow, mincol, minrow;
//			for (i = -2; i <= 2; i++) {
//				for (j = -2; j <= 2; j++) {
//					temp_col = col + i;
//					temp_row = row + j;
//					maxcol = col;
//					maxrow = row;
//					mincol = temp_col;
//					minrow = temp_row;
//					if (inside(temp_col, temp_row) && matrix[temp_col][temp_row] != -1 && matrix[col][row] != matrix[temp_col][temp_row]) {
//						if (matrix[temp_col][temp_row] > matrix[col][row]) {
//							mincol = col;
//							minrow = row;
//							maxcol = temp_col;
//							maxrow = temp_row;
//						}
//						int ii, jj, flag = 0;
//						set<int> case3;
//						for (ii = -1; ii <= 1; ii++) {
//							for (jj = -1; jj <= 1; jj++) {
//								int t_col = maxcol + ii;
//								int t_row = maxrow + jj;
//								if (matrix[t_col][t_row] == -1) {
//									case3.insert((t_col - 2) * gM + t_row - 1);
//								}
//							}
//						}
//						for (ii = -1; ii <= 1; ii++) {
//							for (jj = -1; jj <= 1; jj++) {
//								int t_col = mincol + ii;
//								int t_row = minrow + jj;
//								if (matrix[t_col][t_row] == -1) {
//									if (case3.erase((t_col - 2) * gM + t_row - 1) == 0) {
//										flag = 1;
//										break;
//									}
//								}
//							}
//							if (flag) {
//								break;
//							}
//						}
//						if (!flag && (matrix[maxcol][maxrow] - matrix[mincol][minrow] == case3.size())) {
//							set<int>::iterator iter;
//							for (iter = case3.begin(); iter != case3.end(); iter++) {
//								yes.insert(*iter);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//void solve()
//{
//	int i, j;
//	for (i = 2; i <= gN + 1; i++) {
//		for (j = 2; j <= gM + 1; j++) {
//			if (matrix[i][j] != -1) {
//				check_single(i, j);
//			}
//		}
//	}
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int t, i, j;
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%d%d", &gN, &gM);
//		memset(matrix, 0, sizeof(matrix));
//		yes.clear();
//		no.clear();
//		for (i = 2; i <= gN + 1; i++) {
//			for (j = 2; j <= gM + 1; j++) {
//				scanf("%d", &matrix[i][j]);
//			}
//		}
//		solve();
//		//for (set<int>::iterator iter = yes.begin(); iter != yes.end(); iter++) {
//		//	printf("%d ", *iter);
//		//}
//		//printf("\n");
//		printf("%d %d\n", yes.size(), no.size());
//	}
//}