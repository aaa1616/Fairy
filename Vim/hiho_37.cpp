//#include <stdio.h>
//
//#define N 1000000
//
//int a[N];
//
//void swap(int i, int j)
//{
//	if (a[i] != a[j]) {
//		a[i] ^= a[j];
//		a[j] ^= a[i];
//		a[i] ^= a[j];
//	}
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int n, k, i, l, r, mid, pos, result;
//	scanf("%d%d", &n, &k);
//	for (i = 0; i < n; i++) {
//		scanf("%d", a + i);
//	}
//	l = 0, r = n - 1;
//	while (l <= r) {
//		mid = (l + r) >> 1;
//		swap(mid, r);
//		pos = l;
//		for (i = l; i < r; i++) {
//			if (a[i] < a[r]) {
//				swap(i, pos);
//				pos++;
//			}
//		}
//		swap(r, pos);
//		if (k == (pos - l) +1) {
//			result = a[pos];
//			break;
//		}
//		else if (k < (pos - l) + 1) {
//			r = pos - 1;
//		}
//		else {
//			k = k - (pos - l) - 1;
//			l = pos + 1;
//		}
//
//	}
//	printf("%d\n", result);
//	
//	return 0;
//}