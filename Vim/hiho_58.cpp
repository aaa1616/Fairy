#include <stdio.h>

#define N 11000000

char str[N];
char ch[N];
int num[N];

char * checkstr(char str[], int n)
{
	int i, lastIndex;
	char lastch;
	if (n < 3) {
		return "NO";
	}
	lastIndex = 0;
	lastch = ch[0] = str[0];
	num[0] = 1;
	for (i = 1; i < n; i++) {
		if (str[i] == lastch) {
			num[lastIndex]++;
		}
		else {
			lastIndex++;
			lastch = ch[lastIndex] = str[i];
			num[lastIndex] = 1;
		}
	}
	for (i = 0; i <= lastIndex - 2; i++) {
		if ((ch[i] + 1 == ch[i + 1] && ch[i + 1] + 1 == ch[i + 2]) &&
			(num[i] >= num[i + 1] && num[i + 1] <= num[i + 2])) {
			return "YES";
		}
	}

	return "NO";
}

int main()
{
	FILE *file = fopen("input.txt", "r");
	int t, n;
	fscanf(file, "%d", &t);
	while (t--) {
		fscanf(file, "%d", &n);
		fscanf(file, "%s", str);
		printf("%s\n", checkstr(str, n));
	}
	return 0;
}