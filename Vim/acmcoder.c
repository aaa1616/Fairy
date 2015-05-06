//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <math.h>
//
////#define DEBUG
//
//#ifdef DEBUG
//#define myscanf(file, fmt, ...) fscanf(file, fmt, ##__VA_ARGS__)
//#else
//#define myscanf(file, fmt, ...) scanf(fmt, ##__VA_ARGS__)
//#endif // DEBUG
//
//int main(void)
//{
//	char str[10] = "1234567891";
//	printf("%s\n", str);
//	//FILE *file = fopen("input.txt", "r");
//	int n, sum, i;
//	while (myscanf(file, "%d", &n) != EOF) {
//		sum = 0;
//		for (i = 1; i <= n; i++) {
//			sum += i;
//		}
//		printf("%d\n", sum);
//		printf("\n");
//	}
//	//fclose(file);
//	return 0;
//}