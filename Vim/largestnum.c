#include "largetnum.h"

#define NUM_SIZE 64

void swap(int *a, int *b)
{
	if (*a != *b) {
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}
int compare(char *aStr, char *bStr)
{
	char abStr[NUM_SIZE * 2] = { 0 }, baStr[NUM_SIZE * 2] = { 0 };
	strcat(abStr, aStr);
	strcat(abStr, bStr);
	strcat(baStr, bStr);
	strcat(baStr, aStr);
	if (strcmp(abStr, baStr) > 0) {
		return 1;
	}
	else {
		return 0;
	}


}
void quicksort(char **num, int b, int e)
{
	if (b >= e - 1) {
		return;
	}
	int cmpIndex = b + rand() % (e - b);
	swap(&num[cmpIndex], &num[e - 1]);
	int i, m = b - 1;
	for (i = b; i < e - 1; i++) {
		if (compare(num[i], num[e - 1])) {
			m++;
			swap(&num[i], &num[m]);
		}
	}
	m++;
	swap(&num[m], &num[e - 1]);

	quicksort(num, b, m);
	quicksort(num, m + 1, e);
}
void quicksortdiff(int **num, int b, int e)
{
	if (b >= e - 1) {
		return;
	}
	int cmpIndex = b + rand() % (e - b);
	swap(&num[cmpIndex], &num[e - 1]);
	int i, m = b - 1;
	for (i = b; i < e - 1; i++) {
		if (*num[i] < *num[e - 1]) {
			m++;
			swap(&num[i], &num[m]);
		}
	}
	m++;
	swap(&num[m], &num[e - 1]);

	quicksortdiff(num, b, m);
	quicksortdiff(num, m + 1, e);
}
char *largestNumber(int *num, int n)
{
	char *numStr = malloc(n * NUM_SIZE);
	char *res = malloc(n * NUM_SIZE);
	char **numStrArray = malloc(n * sizeof(char *));
	memset(numStr, 0, n * NUM_SIZE);
	memset(res, 0, n * NUM_SIZE);
	for (int i = 0; i < n; i++) {
		sprintf(numStr + NUM_SIZE * i, "%d\0", num[i]);
		numStrArray[i] = numStr + NUM_SIZE * i;
	}
	quicksortdiff(numStrArray, 0, n);
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(numStrArray[i], "0") != 0) {
			strcat(res, numStrArray[i]);
			flag = 1;
		}
		else if(flag) {
			strcat(res, "0");
		}
	}
	if (!flag) {
		strcat(res, "0");
	}
	return res;
}
int *twoSum(int numbers[], int n, int target) {
	int **numArray = malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		numArray[i] = (char *)numbers + sizeof(int)* i;
	}
	quicksortdiff(numArray, 0, n);
	int b = 0, e = n - 1;
	int res[2] = { 0 };
	while (b < e) {
		int sum = *numArray[b] + *numArray[e];
		if (sum > target) {
			e--;
		}
		else if (sum < target) {
			b++;
		}
		else {
			res[0] = ((char *)numArray[b] - numbers) / sizeof(int)+1;
			res[1] = ((char *)numArray[e] - numbers) / sizeof(int)+1;
			break;
		}
	}
	return res;
}
int lengthOfLongestSubstring(char *s) {
	int b = 0, e = -1, longest = -1, i = 0;
	int tempb = 0, tempe;
	int str[128] = { -1 };
	memset(str, -1, 128);
	while (s[i] != 0) {
		if (str[s[i]] >= tempb) {
			tempb = str[s[i]] + 1;
		}
		if (i - tempb > longest) {
			longest = i - tempb;
			b = tempb;
			e = i;
		}
		str[s[i]] = i;
		i++;
	}
	return longest + 1;
}
int findEle(int a[], int m, int b[], int n, int k) {
	if (m > n) {
		return findEle(b, n, a, m, k);
	}
	if (m == 0) {
		return b[k - 1];
	}
	if (k == 1) {
		return a[0] < b[0] ? a[0] : b[0];
	}
	int ap = k / 2 < m ? k / 2 : m;
	int bp = k - ap;
	if (a[ap - 1] < b[bp - 1]) {
		return findEle(a + ap, m - ap, b, n, bp);
	}
	else if (a[ap - 1] > b[bp - 1]) {
		return findEle(a, m, b + bp, n - bp, ap);
	}
	else {
		return a[ap];
	}
}
double findMedianSortedArrays(int A[], int m, int B[], int n) {
	int total = n + m;
	if (total & 0x01) {
		return findEle(A, m, B, n, total / 2 + 1);
	}
	else {
		return (findEle(A, m, B, n, total / 2) + findEle(A, m, B, n, total / 2 + 1)) / 2.0;
	}
}
char * preprocess(char *s) {
	int n = strlen(s);
	if (n == 0) {
		return "^$";
	}
	char *newStr = malloc((n * 2 + 10) * sizeof(char));
	int i;
	newStr[0] = '^';
	for (i = 1; i <= n; i++) {
		newStr[2 * i] = s[i - 1];
		newStr[2 * i - 1] = '#';
	}
	newStr[2 * i - 1] = '#';
	newStr[2 * i] = '$';
	newStr[2 * i + 1] = 0;
	return newStr;
}
char *longestPalindrome(char *s) {
	char *T = preprocess(s);
	int n = strlen(T);
	int *P = malloc(n * sizeof(int));
	memset(P, 0, n * sizeof(int));
	int C = 0, R = 0;

	for (int i = 1; i < n - 1; i++) {
		int i_mirror = 2 * C - i; // equals to i' = C - (i-C)

		P[i] = (R > i) ? (R - i < P[i_mirror] ? R - i : P[i_mirror]) : 0;

		// Attempt to expand palindrome centered at i
		while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
			P[i]++;

		// If palindrome centered at i expand past R,
		// adjust center based on expanded palindrome.
		if (i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
	}

	// Find the maximum element in P.
	int maxLen = 0;
	int centerIndex = 0;
	for (int i = 1; i < n - 1; i++) {
		if (P[i] > maxLen) {
			maxLen = P[i];
			centerIndex = i;
		}
	}
	char *pld = malloc((maxLen + 1) * sizeof(char));
	for (int i = 0; i < maxLen; i++) {
		pld[i] = T[centerIndex - maxLen + 2 * i + 1] + 'a';
		//pld[i] = 'a' + i + P[i];
	}
	pld[maxLen] = 0;
	free(T);
	free(P);
	return pld;

}