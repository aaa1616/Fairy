//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <math.h>
//
//#include "tiretree.h"
//
////double calculate(int a, int b, char op)
////{
////	switch (op)
////	{
////	case '+' :
////		return a + b;
////		break;
////	case '-' :
////		return a - b;
////		break;
////	case '*' :
////		return a * b;
////		break;
////	case '/' :
////		return a * 1.0 / b;
////		break;
////	default:
////		break;
////	}
////	return 0;
////}
////int reorder(char *s, char *output)
////{
////	int i, index = 0, n = strlen(s);
////	int flag = 1;
////	char count[36];
////	memset(count, 0, 36 * sizeof(char));
////	for (i = 0; i < n; i++) {
////		if (isdigit(s[i])) {
////			count[s[i] - '0']++;
////		}
////		else if (isalpha(s[i])) {
////			count[s[i] - 'a' + 10]++;
////		}
////		else {
////			return 0;
////		}
////	}
////
////	while (index < n) {
////		for (i = 0; i < 36; i++) {
////			if (count[i] != 0) {
////				output[index++] = i < 10 ? i + '0' : i - 10 + 'a';
////				count[i]--;
////			}
////		}
////	}
////	output[index] = 0;
////	
////	return 1;
////}
//
////int kochSnowflake(int i, int n) {
////	i = i % (int)pow(4, n);
////	if (i == 0) {
////		return 0;
////	}
////	int count = 0;
////	while (i != 1) {
////		if (i % 4 == 2 || i % 4 == 3) {
////			return n;
////		}
////		i = ceil (i * 1.0 / 4);
////		n--;
////	}
////	return 0;
////	
////}
//void search(struct TireNode *root, int *ret)
//{
//	int i;
//	struct TireNode *p = root;
//	for (i = 0; i < TIRE_NODE_MAX; i++) {
//		if (p->next[i] != NULL) {
//			if (p->next[i]->word <= 5) {
//				(*ret)++;
//				continue;
//			}
//			else {
//				search(p->next[i], ret);
//			}
//		}
//	}
//}
//int main()
//{
//	//int i, n;
//	//int a, b, min, index;
//	//char op;
//	//min = INT_MAX;
//	//index = 0;
//	//scanf("%d", &n);
//	//for (i = 0; i < n; i++) {
//	//	double gap;
//	//	scanf("%d %c %d", &a, &op, &b);
//	//	gap = abs(calculate(a, b, op) - 9);
//	//	if (gap < min) {
//	//		min = gap;
//	//		index = i + 1;
//	//	}
//	//}
//	//printf("%d\n", index);
//	//char str[500];
//	//char output[500];
//	//while (scanf("%s", str) != EOF) {
//	//	if (reorder(str, output) != 0) {
//	//		printf("%s\n", output);
//	//	}
//	//	else {
//	//		printf("<invalid input string>\n");
//	//	}
//	//}
//	//int m, i, n, ret = 0;
//	//char str[500];
//	//scanf("%d", &m);
//	//struct TireNode *root = createTireTree();
//	//while (m--) {
//	//	scanf("%s", str);
//	//	addTireTreeNode(root, str);
//	////	scanf("%d%d", &i, &n);
//	////	printf("%d\n", kochSnowflake(i, n));
//	//}
//	//search(root, &ret);
//	//printf("%d\n", ret);
//
//	//system("pause");
//	char *p[10];
//	char (*p1)[10];
//	printf("%d %d\n", sizeof(p), sizeof(p1));
//	return 0;
//}