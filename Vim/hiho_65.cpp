//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//
//using namespace std;
//
//#define N 1000
//
//typedef struct _POS {
//	int x, y, v;
//	int index;
//}POS;
//
//POS pos[N];
//
//double t[N];
//int p[N];
//double ret[N];
//
//int cmp(const POS &p1, const POS &p2)
//{
//	return p1.x > p2.x;
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int i, j, n, now;
//	double cur;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		scanf("%d%d%d", &pos[i].x, &pos[i].y, &pos[i].v);
//		pos[i].index = i;
//		p[i] = pos[i].y;
//	}
//	sort(pos, pos + n, cmp);
//	sort(p, p + n);
//
//	for (i = 0; i < n; i++) {
//		cur = 0;
//		now = pos[i].x;
//		for (j = 0; i < n; j++) {
//			if (p[j] > pos[i].x) {
//				cur += (p[j] - now) * 1.0 / pos[i].v;
//				cur = t[j] = fmax(t[j], cur);
//				now = p[j];
//				if (p[j] == pos[i].y){
//					ret[pos[i].index] = cur;
//					break;
//				}
//			}
//		}
//	}
//	for (i = 0; i < n; i++) {
//		printf("%.2f\n", ret[i]);
//	}
//	return 0;
//}