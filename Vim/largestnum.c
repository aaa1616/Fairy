#include "largetnum.h"

#define NUM_SIZE 64

static void swap(int *a, int *b)
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
void quicksort(int *num, int b, int e)
{
	if (b >= e - 1) {
		return;
	}
	int cmpIndex = b + rand() % (e - b);
	swap(&num[cmpIndex], &num[e - 1]);
	int i, m = b - 1;
	for (i = b; i < e - 1; i++) {
		if (num[i] < num[e - 1]) {
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
char *longestCommonPrefix(char *strs[], int n) {
	if (n == 0) {
		return NULL;
	}
	int len = strlen(strs[0]);
	if (len == 0) {
		return "";
	}
	int i;
	for (i = 0; i < len; i++) {
		char c = strs[0][i];
		for (int j = 1; j < n; j++) {
			if (strs[j][i] == c) {
				continue;
			}
			else {
				char *ret = malloc((i + 1) * sizeof(char));
				memcpy(ret, strs[0], i);
				ret[i] = 0;
				return ret;
			}
		}
	}
	return strs[0];
}

int **threeSum(int num[], int n, int *returnSize) {
	if (n < 2) {
		*returnSize = 0;
		return NULL;
	}
	int *ret = malloc(n * sizeof(int));
	quicksort(num, 0, n);
	int retIndex = 0, triNum = 0;
	for (int i = 0; i < n - 2; i++) {
		if (i > 0 && num[i] == num[i - 1]) {
			continue;
		}
		int sum = 0;
		int j = i + 1, k = n - 1;
		while (j < k) {
			if ((j > i + 1) && (num[j] == num[j - 1])) {
				j++;
				continue;
			}
			if ((k < n - 1) && num[k] == num[k + 1]) {
				k--;
				continue;
			}

			sum = num[i] + num[j] + num[k];
			if (sum > 0) {
				k--;
			}
			else if (sum < 0) {
				j++;
			}
			else {
				triNum++;
				ret[retIndex++] = num[i];
				ret[retIndex++] = num[j];
				ret[retIndex++] = num[k];
				j++;
				k--;
			}
		}
	}
	int **triple = malloc(triNum * sizeof(int *));
	for (int i = 0; i < triNum; i++) {
		triple[i] = ret + 3 * i;
	}
	*returnSize = triNum;
	return triple;
}
int threeSumClosest(int *num, int n, int target) {
	if (n < 2) {
		return 0;
	}
	quicksort(num, 0, n);
	int ret = INT_MAX, lastgap = INT_MAX;
	for (int i = 0; i < n - 2; i++) {
		if (i > 0 && num[i] == num[i - 1]) {
			continue;
		}
		int sum = 0;
		int j = i + 1, k = n - 1;
		while (j < k) {
			if ((j > i + 1) && (num[j] == num[j - 1])) {
				j++;
				continue;
			}
			if ((k < n - 1) && num[k] == num[k + 1]) {
				k--;
				continue;
			}

			sum = num[i] + num[j] + num[k];
			if (sum > target) {
				k--;
			}
			else if (sum < target) {
				j++;
			}
			else {
				return sum;
			}
			if (abs(sum - target) < lastgap) {
				ret = sum;
			}
			lastgap = abs(sum - target);
		}
	}
	return ret;
}
char *toAlpha(char c)
{
	switch (c)
	{
	case '1':
		return "";
		break;
	case '2':
		return "abc";
		break;
	case '3':
		return "def";
		break;
	case '4':
		return "ghi";
		break;
	case '5':
		return "jkl";
		break;
	case '6':
		return "mno";
		break;
	case '7':
		return "pqrs";
		break;
	case '8':
		return "tuv";
		break;
	case '9':
		return "wxyz";
		break;
	case '0':
		return "";
		break;
	default:
		return "";
		break;
	}
}
static void dfs(int dep, int maxdep, char *s, char *ret)
{
	if (dep == maxdep) {
		return;
	}
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		ret[dep] = toAlpha(s[dep])[i];
		ret[dep+ 1] = 0;
		dfs(dep + 1, maxdep, s, ret);
	}
}
char **letterCombinations(char *digits, int *returnSize) {
	int n = strlen(digits);
	int size = (int)pow(4, n);
	char **final = malloc(size * sizeof (char *));
	char *finalmem = malloc(size * (n + 1) * sizeof(char));
	char *ret = malloc((n + 1) * sizeof(char));
	dfs(0, strlen(digits), digits, ret);
	return final;
}
int* subLongest(char *s, int begin, int end) {
	int b = 0, e = 0;
	int index = -1, max = -1;
	int tempb = INT_MAX, tempe, tempMax = -1, flag = 1;
	int *stack = malloc((end - begin) * sizeof(int));
	for (int i = begin; i < end; i++) {
		if (s[i] == '(') {
			if (flag) {
				tempMax = -1;
				tempb = INT_MAX;
				flag = 0;
			}
			stack[++index] = i;
		}
		else {
			if (index != -1) {
				if (stack[index] < tempb) {
					tempb = stack[index];
				}
				index--;
				if (i - tempb > tempMax) {
					tempMax = i - tempb;
					tempe = i;
				}
			}
			else {
				flag = 1;
				if (tempMax > max) {
					max = tempMax;
					b = tempb;
					e = tempe;
				}
			}
		}
	}
	if (tempMax > max) {
		max = tempMax;
		b = tempb;
		e = tempe;
	}
	free(stack);
	int *ret = malloc(3 * sizeof(int));
	ret[0] = b;
	ret[1] = e;
	ret[2] = max + 1;
	return ret;
}
int longestValidParentheses(char *s) {
	int b = 0, e = 0, max = -1;
	int n = strlen(s);
	int *stack = malloc(n * sizeof(int));
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			stack[++index] = i;
		}
		else {
			if (index != -1) {
				index--;
			}
		}
	}
	e = n;
	for (int i = index; i >= 0; i--) {
		int *ret = subLongest(s, stack[i] + 1, e);
		e = stack[i];
		if (ret[2] > max) {
			max = ret[2];
			b = ret[0];
			e = ret[1];
		}
		free(ret);
	}
	int *ret = subLongest(s, 0, e);
	if (ret[2] > max) {
		max = ret[2];
		b = ret[0];
		e = ret[1];
	}
	free(ret);
	free(stack);
	return max;
}
int divide(int dividend, int divisor) {
	if (dividend == INT_MIN && divisor == -1) {
		return INT_MAX;
	}
	int res = 0;
	if (dividend == INT_MIN) {
		dividend -= abs(divisor);
		res++;
	}
	if (divisor == INT_MIN) {
		return res;
	}
	if (divisor == 0) {
		return INT_MAX;
	}

	int a = abs(dividend);
	int b = abs(divisor);
	while (a >= b)
	{
		int c = b;
		for (int i = 0; a >= c && c > 0; i++, c <<= 1)
		{
			a -= c;
			res += 1 << i;
		}
	}
	return ((dividend ^ divisor) >> 31) ? (-res) : (res);

}