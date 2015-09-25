//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//
//using namespace std;
//
//#define N 1010
//
//#define ONLINE_JUDGE
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//#else
//	freopen("codejam input/A-small-1-attempt0.in", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
//	int t, j, i, k,  n, m, l, r;
//	double v = 0;
//	int a[N];
//	scanf("%d", &t);
//	for (i = 1; i <= t; i++) {
//		scanf("%d%d", &n, &m);
//		memset(a, 0, sizeof(a));
//		for (j = 0; j < n; j++) {
//			scanf("%d", a + j);
//		}
//		printf("Case #%d:\n", i);
//		while (m--) {
//			scanf("%d%d", &l, &r);
//			v = 1;
//			for (k = l; k <= r; k++) {
//				double dm = a[k] + 0.0;
//				double sq = 1.0 / (r - l + 1);
//				v *= pow(dm, sq);
//			}
//			printf("%.7f\n", v);
//		}
//	}
//
//	return 0;
//}