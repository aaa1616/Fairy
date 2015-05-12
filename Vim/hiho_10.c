//#include <stdio.h>
//#include <string.h>
//
//#define L 26
//
//typedef struct TreeNode{
//	char data;
//	int left, right;
//}TREENODE;
//TREENODE treenode[L];
//char ret[L];
//
//int index = 0;
//
//int build(char *pre, char *in, int len)
//{
//	int i = 0, temp;
//	char d = pre[0];
//	if (len == 0) {
//		return -1;
//	}
//	while (d != in[i]) {
//		i++;
//	}
//	temp = index;
//	index++;
//	treenode[temp].data = d;
//	treenode[temp].left = build(pre + 1, in, i);
//	treenode[temp].right = build(pre + i + 1, in + i + 1, len - i - 1);
//	return temp;
//}
//
//void post(int root)
//{
//	if (root != -1) {
//		post(treenode[root].left);
//		post(treenode[root].right);
//		ret[index] = treenode[root].data;
//		index++;
//	}
//}
//
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//	char pre[L];
//	char in[L];
//	fscanf(file, "%s%s", pre, in);
//	build(pre, in, strlen(pre));
//	index = 0;
//	post(0);
//	printf("%s\n", ret);
//	return 0;
//}