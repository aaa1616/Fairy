//#include <stdio.h>
//#include <algorithm>
//#include <stdlib.h>
//
//using namespace std;
//
//struct pair_t {
//	int a, b;
//};
//
//struct node_t {
//	int a, b;
//	node_t *left, *right;
//};
//
//int cmp(const pair_t &p1, const pair_t &p2)
//{
//	if (p1.b < p2.b) {
//		return 1;
//	}
//	return 0;
//}
//
//node_t *dfs(pair_t *pair, int pos)
//{
//	int i;
//	node_t * root = (node_t *)malloc(sizeof(node_t));
//	root->a = pair[pos].a;
//	root->b = pair[pos].b;
//	root->left = NULL;
//	root->right = NULL;
//	if (pos > 0) {
//		for (i = pos - 1; i >= 0; i--) {
//			if (pair[i].a > root->a && pair[i].b < root->b) {
//				root->right = dfs(pair, i);
//				break;
//			}
//		}
//		for (i = pos - 1; i >= 0; i--) {
//			if (pair[i].a < root->a && pair[i].b < root->b) {
//				root->left = dfs(pair, i);
//				break;
//			}
//		}
//		return root;
//	}
//
//	return NULL;
//
//}
//
//node_t * build(pair_t *pair, int n)
//{
//	sort(pair, pair + n, cmp);
//	return dfs(pair, n);
//}
//
//int main()
//{
//	int size = 0;
//	pair_t pair[] = { {5, 8}, {2, 10}, {4, 3}, {1,5}, {0, 2}, {9, 1} };
//	size = sizeof(pair) / sizeof (pair_t);
//	sort(pair, pair + size, cmp);
//	return 0;
//}