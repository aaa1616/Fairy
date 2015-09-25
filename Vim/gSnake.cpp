//#include <stdio.h>
//#include <string.h>
//#include <map>
//#include <set>
//#include <queue>
//#include <algorithm>
//
//
//using namespace std;
//
//#define N 10000
//
//typedef struct _SNAKE {
//	int i, j;
//}SNAKE;
//
//typedef pair <int, int> PII;
//queue <PII> q;
//map <PII, bool> eated;
//set <PII> body;
//
//SNAKE snake[N];
//
//#define M 102
//#define FOOD 1
//#define HEAD 2
//#define BODY 3
//#define TAIL 4
//
//int a[M][M];
//int r, c;
//int gIndex;
//int direct = 0;
//
//int hx = 1, hy = 1;
//int tx = 1, ty = 1;
//int flag = 0;
//
//int gHead = 0;
//int gTail = 0;
//
//int xd[] = { 0, 1, 0, -1 };
//int yd[] = { 1, 0, -1, 0 };
//
//#define ONLINE_JUDGE
//
//void init()
//{
//	memset(a, 0, sizeof(a));
//	a[1][1] = HEAD;
//	int i, j;
//	for (i = 1; i <= r; i++) {
//		for (j = 1; j <= c; j++) {
//			if ((i + j) % 2 == 1) {
//				a[i][j] = FOOD;
//			}
//		}
//	}
//	flag = 0;
//	direct = 0;
//	hx = hy = tx = ty = 1;
//	gHead = gTail = 0;
//	gIndex = 0;
//	snake[0].j = snake[0].i = 1;
//}
//
//void countnext(int cellx, int celly, int *nr, int *nc)
//{
//	if (cellx + xd[direct] > r) {
//		*nr = 1;
//		*nc = celly;
//		return;
//	}
//	if (cellx + xd[direct] < 1) {
//		*nr = r;
//		*nc = celly;
//		return;
//	}
//	if (celly + yd[direct] > c) {
//		*nr = cellx;
//		*nc = 1;
//		return;
//	}
//	if (celly + yd[direct] < 1) {
//		*nr = cellx;
//		*nc = c;
//		return;
//	}
//
//	*nr = cellx + xd[direct];
//	*nc = celly + yd[direct];
//
//	return;
//}
//
//int action(char *p)
//{
//	int nr, nc;
//	if (p != NULL) {
//		if (strcmp(p, "R") == 0) {
//			direct = (direct + 1) % 4;
//		}
//		else {
//			direct = (direct - 1 + 4) % 4;
//		}
//	}
//	countnext(hx, hy, &nr, &nc);
//	//printf("head %d : %d %d pos: %d\n", gIndex, hx, hy, a[nr][nc]);
//	if (a[nr][nc] == BODY) {
//		return 0;
//	}
//
//	gHead = (gHead + 1) % N;
//	if (a[nr][nc] == FOOD) {
//		a[hx][hy] = BODY;
//		a[nr][nc] = HEAD;
//		snake[gHead].i = nr;
//		snake[gHead].j = nc;
//		hx = nr;
//		hy = nc;
//	}
//	else {
//		a[hx][hy] = BODY;
//		a[tx][ty] = 0;
//		hx = nr, hy = nc;
//		snake[gHead].i = nr;
//		snake[gHead].j = nc;
//		gTail = (gTail + 1) % N;
//		tx = snake[gTail].i;
//		ty = snake[gTail].j;
//		a[tx][ty] = TAIL;
//		a[hx][hy] = HEAD;
//	}
//
//	return 1;
//}
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//#else
//	freopen("codejam input/D-small-practice.in", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
//
//	int t, i, s, x;
//	char str[3];
//	scanf("%d", &t);
//	for (i = 1; i <= t; i++) {
//		scanf("%d%d%d", &s, &r, &c);
//		init();
//		while (s--) {
//			scanf("%d%s", &x, str);
//			while (x > gIndex) {
//				if (!action(NULL)) {
//					flag = 1;
//					break;
//				}
//				gIndex++;
//			}
//			if (flag) {
//				break;
//			}
//			if (!action(str)) {
//				break;
//			}
//			gIndex++;
//		}
//
//		gIndex = 0;
//		if (s < 0) {
//			while (gIndex != M) {
//				gIndex++;
//				if (!action(NULL)) {
//					break;
//				}
//			}
//		}
//		else {
//			while (s--) {
//				scanf("%d%s", &x, str);
//			}
//		}
//
//		printf("Case #%d: %d\n", i, (gHead - gTail + 1 + N) % N);
//	}
//	return 0;
//}