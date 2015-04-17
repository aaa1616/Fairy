#ifndef _LARGEST_NUM
#define _LARGEST_NUM
#include "ftinclib.h"

struct ListNode {
	int val;
	struct ListNode *next;
};

int *twoSum(int numbers[], int n, int target);
char *largestNumber(char **num, int n);
int lengthOfLongestSubstring(char *s);
double findMedianSortedArrays(int A[], int m, int B[], int n);
char *longestPalindrome(char *s);
char *longestCommonPrefix(char *strs[], int n);
int **threeSum(int num[], int n, int *returnSize);
int threeSumClosest(int *num, int n, int target);
char **letterCombinations(char *digits, int *returnSize);
int longestValidParentheses(char *s);
int divide(int dividend, int divisor);
int **permute(int numbers[], int n, int *numRows);
int *countSort(int *num, int n, int k);
int selectKth(int *num, int b, int e, int k);
int **generateMatrix(int n);
struct ListNode *rotateRight(struct ListNode *head, int k);
int uniquePaths(int m, int n);
char *simplifyPath(char *path);
char **fullJustify(char **words, int n, int L, int *outputSize);
int **combine(int n, int k, int **columnSizes, int *returnSize);
struct ListNode *partition(struct ListNode *head, int x);
int isScramble(char* s1, char* s2);


#endif // !_LARGEST_NUM
