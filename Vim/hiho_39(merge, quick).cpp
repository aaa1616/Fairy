//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//
//using namespace std;
//
//#define N 100001
//
//int a[N];
//int l[N], r[N];
//long long result = 0;
//
//void merge(int b, int m, int e)
//{
//	int i, lsize, rsize, li = 0, ri = 0;
//	lsize = m - b + 1;
//	rsize = e - m;
//	memcpy(l, a + b, lsize * sizeof(int));
//	memcpy(r, a + m + 1, rsize * sizeof(int));
//	for (i = b; i <= e; i++) {
//		if (ri >= rsize || (li < lsize && l[li] <= r[ri])) {
//			a[i] = l[li];
//			result += ri;
//			li++;
//			continue;
//		}
//		
//		if (li >= lsize || (ri < rsize && l[li] > r[ri])){
//			a[i] = r[ri];
//			ri++;
//			continue;
//		}
//	}
//}
//
//void mergeSort(int b, int e)
//{
//	if (b < e) {
//		int m = (b + e) >> 1;
//		mergeSort(b, m);
//		mergeSort(m + 1, e);
//		merge(b, m, e);
//	}
//}
//
//int partition(int b, int e)
//{
//	int i, pos = b;
//	for (i = b; i < e; i++) {
//		if (a[i] < a[e]) {
//			swap(a[i], a[pos]);
//			pos++;
//		}
//	}
//	swap(a[pos], a[e]);
//	return pos;
//}
//
//void quickSort(int b, int e)
//{
//	if (b < e) {
//		int m = partition(b, e);
//		quickSort(b, m - 1);
//		quickSort(m + 1, e);
//	}
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int i, n;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		scanf("%d", a + i);
//	}
//	mergeSort(0, n - 1);
//	printf("%lld\n", result);
//	return 0;
//}