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
int *countSort(int *num, int n, int k)
{
	int *c = malloc(k * sizeof(int));
	int *ret = malloc(n * sizeof(int));
	memset(c, 0, k * sizeof(int));
	memset(ret, 0, n * sizeof(int));
	int i;
	for (i = 0; i < n; i++) {
		c[num[i]]++;
	}
	for (int i = 1; i < k; i++) {
		c[i] += c[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		ret[c[num[i]] - 1] = num[i];
		c[num[i]]--;
	}
	free(c);
	return ret;
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
int **ret;
int *data;
void interPermute(int numbers[], int index, int n, int *numRows) {
	if (index == n) {
		(*numRows)++;
		return;
	}
	for (int i = index; i < n; i++) {
		swap(&numbers[index], &numbers[i]);
		int last = *numRows;
		ret[*numRows][index] = numbers[index];
		interPermute(numbers, index + 1, n, numRows);
		if (i != n - 1) {
			memcpy(ret[*numRows], ret[last], n * sizeof(int));
		}
		swap(&numbers[index], &numbers[i]);
	}
}
int **permute(int numbers[], int n, int *numRows) {
	int total = n;
	*numRows = 0;
	for (int i = n - 1; i >= 1; i--) {
		total *= i;
	}
	ret = malloc(total * sizeof(int *));
	data = malloc(total * n * sizeof(int));
	for (int i = 0; i < total; i++) {
		ret[i] = data + i * n;
	}
	interPermute(numbers, 0, n, numRows);
	return ret;
}
int selectKth(int *num, int b, int e, int k)
{
	if (b >= e) {
		return num[b];
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
	i = m - b + 1;
	if (i == k) {
		return num[m];
	}
	else if(k < i) {
		selectKth(num, b, m, k);
	}
	else {
		selectKth(num, m + 1, e, k - i);
	}
}
int **generateMatrix(int n) {
	int i, max = n * n, x = 0, y = 0, direct = 0;
	int leftRow = n, leftCol = n, step = 0;
	int xdirect[] = { 1, 0, -1, 0 };
	int ydirect[] = { 0, 1, 0, -1 };

	int **ret = malloc(n * sizeof(int *));
	int *data = malloc(n * n * sizeof(int));
	for (i = 0; i < n; i++) {
		ret[i] = data + n * i;
	}
	i = 1;
	while (i <= max) {
		ret[x][y] = i;
		i++;
		step++;
		if (step == leftRow && ydirect[direct] == 0) {
			step = 0;
			leftCol--;
			direct++;
			direct %= 4;
		}
		if (step == leftCol && xdirect[direct] == 0) {
			step = 0;
			leftRow--;
			direct++;
			direct %= 4;
		}
		y += xdirect[direct];
		x += ydirect[direct];
	}
	return ret;
	
}
struct ListNode *rotateRight(struct ListNode *head, int k) {
	struct ListNode emptyHead;
	struct ListNode *one, *two, *newHead;

	if (head == NULL || head->next == NULL || k == 0) {
		return head;
	}

	int count = 0;
	one = emptyHead.next = head;
	two = &emptyHead;

	while (one != NULL) {
		count++;
		one = one->next;
	}
	one = emptyHead.next;
	count = 0;
	k %= count;
	while (one != NULL) {
		if (count >= k) {
			two = two->next;
		}
		if (one->next == NULL) {
			one->next = head;
			head = two->next;
			two->next = NULL;

			break;
		}
		one = one->next;
		count++;
	}
	return head;
}
char *simplifyPath(char *path) {
	int i, stackpos = 0, index = 1, pos = 1, count = 0;
	int len = strlen(path);
	int *stack = malloc(len * sizeof(int));
	stack[stackpos++] = 0;
	for (i = 1; i < len; i++) {
		if (path[i] == '/') {
			if (count == 0) {
				pos++;
				continue;
			}
			if (strncmp(path + pos, ".", count) == 0) {
				index = stack[stackpos - 1] + 1;
			}
			else if (strncmp(path + pos, "..", count) == 0) {
				stackpos--;
				if (stackpos > 0) {
					index = stack[stackpos - 1] + 1;
				}
				else {
					stackpos = 1;
					index = 1;
				}
			}
			else {
				stack[stackpos++] = index;
				path[index++] = path[i];
			}
			pos = i + 1;
			count = 0;
		}
		else {
			path[index++] = path[i];
			count++;
		}
	}

	if (count == 0) {
		if (index > 1 && path[index - 1] == '/') {
			path[index - 1] = 0;
		}
		else {
			path[index] = 0;
		}
		free(stack);
		return path;
	}

	if (strncmp(path + pos, ".", count) == 0) {
		index = stack[stackpos - 1] + 1;
		path[index] = 0;
	}
	else if (strncmp(path + pos, "..", count) == 0) {
		stackpos--;
		if (stackpos > 0) {
			index = stack[stackpos - 1] + 1;
		}
		else {
			stackpos = 1;
			index = 1;
		}
		path[index] = 0;
	}
	else if (index > 1 && path[index - 1] == '/') {
		path[index - 1] = 0;
	}
	else {
		path[index] = 0;
	}
	free(stack);

	return path;
}
char *genLine(int b, int e, int len, int L, char **words)
{
	int i, spaces = L - len, wordlen, pos = 0;
	int as, rs;
	char *ret = malloc((L + 1) * sizeof(char));
	memset(ret, ' ', L * sizeof(char));
	if (b == e) {
		memcpy(ret, words[b], strlen(words[b]) * sizeof(char));
		ret[L] = 0;
		return ret;
	}
	as = spaces / (e - b);
	rs = spaces % (e - b);
	for (i = b; i <= e; i++) {
		wordlen = strlen(words[i]);
		memcpy(ret + pos, words[i], wordlen * sizeof(char));
		pos += wordlen + as + 1 + rs;
		rs = rs > 0 ? --rs : 0;
	}
	ret[L] = 0;
	return ret;
}
char *genLastLine(int b, int e, int len, int L, char **words)
{
	int i, pos = 0, wordlen;
	char *ret = malloc((L + 1) * sizeof(char));
	memset(ret, ' ', L * sizeof(char));

	for (i = b; i <= e; i++) {
		wordlen = strlen(words[i]);
		memcpy(ret + pos, words[i], wordlen * sizeof(char));
		pos += wordlen + 1;
	}
	ret[L] = 0;
	return ret;
}

char **fullJustify(char **words, int n, int L, int *outputSize) {
	int i, wordlen, index = 0, b = 0, len = 0;
	char **ret;
	if (n == 0) {
		*outputSize = 0;
		return NULL;
	}
	ret = malloc(n * sizeof(char *));
	for (i = 0; i < n; i++) {
		wordlen = strlen(words[i]);
		if (len + wordlen >= L) {
			if (len + wordlen == L) {
				ret[index++] = genLine(b, i, len + wordlen, L, words);
				b = i + 1;
				len = 0;
			}
			else {
				ret[index++] = genLine(b, i - 1, len, L, words);
				b = i;
				len = wordlen + 1;
			}
		}
		else {
			len += wordlen + 1;
		}
	}
	if (b != n) {
		ret[index++] = genLastLine(b, n - 1, len, L, words);
	}
	*outputSize = index;
	return ret;
}
int uniquePaths(int m, int n) {
	int ret[100];
	int i, j;
	if (m == 0 || n == 0) {
		return 0;
	}
	memset(ret, 0, 100 * sizeof(int));
	ret[0] = 1;
	for (i = 0; i < m; i++) {
		for (j = 1; j < n; j++) {
			ret[j] += ret[j - 1];
		}
	}
	return ret[n - 1];
}
void comb(int n, int k, int b, int resultPos, int *retPos, int **ret, int *result) {
	if (resultPos == k) {
		ret[*retPos] = malloc(k * sizeof(int));
		memcpy(ret[*retPos], result, k * sizeof(int));
		(*retPos)++;
		return;
	}
	for (int i = b; i <= n; i++) {
		result[resultPos] = i;
		comb(n, k, i + 1, resultPos + 1, retPos, ret, result);
	}
}

int **combine(int n, int k, int **columnSizes, int *returnSize) {
	int i;
	int **ret, *tempResult, *columnS;
	if (k <= 0) {
		*returnSize = 0;
		return NULL;
	}

	*returnSize = uniquePaths(k + 1, n - k + 1);
	ret = malloc(*returnSize * sizeof(int *));
	columnS = malloc(*returnSize * sizeof(int));
	for (i = 0; i < *returnSize; i++) {
		columnS[i] = k;
	}
	*columnSizes = columnS;

	*returnSize = 0;
	tempResult = malloc(k * sizeof(int));
	comb(n, k, 1, 0, returnSize, ret, tempResult);

	free(tempResult);

	return ret;
}
struct ListNode *partition(struct ListNode *head, int x) {
	int isFound = 0;
	struct ListNode newHead;
	struct ListNode *insertPos, *insertPosPrev, *cur, *prev;
	newHead.next = head;
	prev = insertPosPrev = &newHead;
	insertPos = cur = head;
	while (cur != NULL) {
		 if (cur->val >= x && isFound == 0) {
		     insertPos = cur;
		     isFound = 1;
		     insertPosPrev = prev;
		 }
		if (cur->val < x) {
			insertPosPrev->next = cur;
			prev->next = cur->next;
			cur->next = insertPos;
			insertPosPrev = cur;
			cur = prev;
		}
		prev = cur;
		cur = cur->next;
	}
	return newHead.next;
}
int isScramble(char* s1, char* s2) {
	int ret;
	int i, j, k, m;
	int len, len1 = strlen(s1), len2 = strlen(s2);
	char ***scrambled, **temp2d, *temp3d;
	if (len1 != len2 || len1 == 0) {
		return 0;
	}
	len = len1;
	scrambled = malloc(len * sizeof(char **));
	temp2d = malloc(len * len * sizeof(char *));
	temp3d = malloc(len * len * len * sizeof(char));
	memset(temp3d, 0, len * len * len * sizeof(char));
	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			temp2d[j] = temp3d + i * len * len + j * len;
		}
		scrambled[i] = temp2d + i * len;
	}
	for (i = 0; i < len; i++) {
		for (j = 0; j < len - i; j++) {
			for (k = 0; k < len - i; k++) {
				if (i == 0) {
					scrambled[0][k][j] = s1[j] == s2[k] ? 1 : 0;
					continue;
				}
				for (m = 0; m < i; m++) {
					if (scrambled[m][j][k] && scrambled[i - m - 1][j + m + 1][k + m + 1] ||
						scrambled[m][j][k + i - m] && scrambled[i - m - 1][j + m + 1][k]
						) {
						scrambled[i][j][k] = 1;
						break;
					}
				}
			}
		}
	}
	ret = scrambled[len - 1][0][0];
	free(temp3d);
	free(temp2d);
	free(scrambled);
	return ret;
}