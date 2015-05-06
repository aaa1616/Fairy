//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <math.h>
//
//#define MAXLEN 20004
//#define DEBUG
//
//#ifdef DEBUG
//#define myscanf(file, fmt, ...) fscanf(file, fmt, ##__VA_ARGS__)
//#else
////#define myscanf(file, fmt, ...) scanf(fmt, ##__VA_ARGS__)
//#endif // DEBUG
//
//void conv(char *str, char *ret)
//{
//	int len = strlen(str), i, pos = 0;
//	for (i = 0; i < len; i++) {
//		if (str[i] - 'a' < 0) {
//			ret[pos++] = str[i] - 'A' + 'a';
//			ret[pos++] = str[i] - 'A' + 'a';
//		}
//		else {
//			ret[pos++] = str[i];
//		}
//	}
//}
//long long calWeight(char *str)
//{
//	int len = strlen(str), i;
//	long long count = 1;
//	long long sum = 0;
//	char lastchar = str[0];
//	for (i = 1; i < len; i++) {
//		if (str[i] == lastchar) {
//			count++;
//		}
//		else {
//			sum += count * count * (long long)(lastchar - 'a' + 1);
//			count = 1;
//			lastchar = str[i];
//		}
//	}
//	sum += count * count * (long long)(lastchar - 'a' + 1);
//	return sum;
//}
//
//int main(void)
//{
//	FILE *file = fopen("input.txt", "r");
//	int i, n;
//	char str[MAXLEN], ret[MAXLEN];
//	myscanf(file, "%d", &n);
//	//scanf("%d", &n);
//	for (i = 0; i < n; i++) {
//		memset(ret, 0, MAXLEN * sizeof(char));
//		myscanf(file, "%s", str);
//		//scanf("%s", str);
//		conv(str, ret);
//		printf("%lld\n", calWeight(ret));
//	}
//	fclose(file);
//	system("pause");
//	return 0;
//}