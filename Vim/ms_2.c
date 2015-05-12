//#define _MS_2
#ifdef _MS_2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define L 503

#define DEBUG

#ifdef DEBUG
#define myscanf(file, fmt, ...) fscanf(file, fmt, ##__VA_ARGS__)
#else
#define myscanf(file, fmt, ...) scanf(fmt, ##__VA_ARGS__)
#endif // DEBUG

#define LONGLONG long long

#ifndef INT_MAX
#define INT_MAX 2000000000
#endif
#ifndef INT_MIN
#define INT_MIN -2000000000
#endif

int judge(int a, int b)
{
	if (a * b != 0) {
		if ((a - 1) / 3 <= (b - 1) / 3 && (a - 1) % 3 <= (b - 1) % 3)
			return 1;
		else
			return 0;
	}
	else {
		if (a == b && b == 0) {
			return 1;
		}
		if (b == 0 && (a % 3 != 0))
			return 1;
		else
			return 0;
	}

	return 0;
}

int main()
{
	int t, len, i, j;
	int flag;
	char dig = 0;
	char temp[L], num[L];
#ifdef DEBUG
	FILE *file = fopen("input.txt", "r");
#endif
	myscanf(file, "%d", &t);
	//t = 1000;
	while (t--) {
		myscanf(file, "%s", num);
		//sprintf(temp, "%lld", t);
		//len = strlen(temp);
		//i = 0;
		//while (temp[i] == '0' && temp[i + 1] != 0) {
		//	i++;
		//}
		//memcpy(num, temp + i, len - i + 1);
		len = strlen(num);
		//if (len == 1) {
		//	printf("%s\n", num);
		//	continue;
		//}
		flag = 0;
		for (i = 0; i < len - 1; i++) {
			if (judge(num[i] - '0', num[i + 1] - '0') == 0) {
				dig = 0;
				for (j = num[i + 1] - '0' - 1; j >= 0; j--) {
					if (judge(num[i] - '0', j) == 1) {
						num[i + 1] = j + '0';
						dig = '9';
						break;
					}
				}
				
				if (dig == 0) {
					num[i] = num[i] - 1;
					num[i + 1] = '9';
					dig = '9';
					if (i == 0) {
						break;
					}
					i -= 2;
					flag = 1;
					continue;
				}
				else {
					break;
				}
			} else {
				if (flag == 1) {
					break;
				}
			}
		}
		if (num[i + 1] == '0') {
			dig = '0';
		}
		for (i = i + 2; i < len; i++) {
			num[i] = dig;
		}
		//ret = strtoll(num, num + len, 10);
		printf("%s\n", num);
	}

#ifdef DEBUG
	fclose(file);
	system("pause");
#endif
	return 0;
}

#endif // _MS_2

