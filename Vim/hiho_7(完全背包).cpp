//#include <stdio.h>
//#include <string.h>
//
//#define LN 500
//#define LM 100000
//
//int main()
//{
//	int n, m, i, j, max;
//	int *need, *value, *best;
//	scanf("%d%d", &n, &m);
//	need = malloc(n * sizeof(int));
//	value = malloc(n * sizeof(int));
//	best = malloc(m * sizeof(int));
//	memset(best, 0, m * sizeof(int));
//
//	for (i = 0; i < n; i++) {
//		scanf("%d%d", need + i, value + i);
//	}
//
//	for (i = 0; i < n; i++) {
//		for (j = need[i]; j <= m; j++) {
//			int val = best[j - need[i]] + value[i];
//			best[j] = val > best[j] ? val : best[j];
//		}
//	}
//	max = best[m];
//	free(need);
//	free(value);
//	free(best);
//	printf("%d\n", max);
//	return 0;
//}