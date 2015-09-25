//#include <stdio.h>
//#include <set>
//
//using namespace std;
//
//set<__int64> spe;
//
////#define ONLINE_JUDGE
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//#else
//	freopen("codejam input/A-small-1-attempt0.in", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
//	int i, t, count;
//	__int64 k;
//	__int64 a = 1;
//	set<__int64>::iterator iter, gIter;
//	spe.insert(1);
//	for (i = 1; i <= 60; i++) {
//		a <<= 1;
//		spe.insert(a);
//	}
//
//	scanf("%d", &t);
//	for (i = 1; i <= t; i++) {
//		gIter = spe.end();
//		gIter--;
//		count = 0;
//		scanf("%I64d", &k);
//		while ((iter = spe.find(k)) == spe.end()) {
//			count++;
//			while (true) {
//				if (k < *gIter) {
//					gIter--;
//				}
//				else {
//					k = *gIter - (k - *gIter);
//					break;
//				}
//			}
//		}
//
//		printf("Case #%d: %d\n", i, count % 2);
//	}
//
//	return 0;
//
//}