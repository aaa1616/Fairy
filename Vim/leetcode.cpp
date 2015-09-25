//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//};
//
//int maxSum = 0;
//int maxToRoot(struct TreeNode * root)
//{
//	isalnum
//	if (root == NULL) {
//		return 0;
//	}
//
//	int left, right, cur, fromLeft, fromRight;
//	left = maxToRoot(root->left);
//	right = maxToRoot(root->right);
//
//	cur = left + right + root->val;
//	fromLeft = left + root->val;
//	fromRight = right + root->val;
//
//	maxSum = cur > maxSum ? cur : maxSum;
//
//	return fromLeft > fromRight ? fromLeft : fromRight;
//
//}
//int maxPathSum(struct TreeNode* root) {
//	maxToRoot(root);
//	return maxSum;
//}
//
//int main()
//{
//	struct TreeNode node1;
//	node1.left = node1.right = NULL;
//	node1.val = -3;
//	maxPathSum(&node1);
//	return 0;
//}