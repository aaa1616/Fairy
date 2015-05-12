//#define _MS_3
#ifdef _MS_3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define L 10

#define DEBUG

#ifdef DEBUG
#define myscanf(file, fmt, ...) fscanf(file, fmt, ##__VA_ARGS__)
#else
#define myscanf(file, fmt, ...) scanf(fmt, ##__VA_ARGS__)
#endif // DEBUG

#ifndef INT_MAX
#define INT_MAX 2000000000
#endif
#ifndef INT_MIN
#define INT_MIN -2000000000
#endif

typedef struct TreeNode {
	char data;
	int count;
	struct TreeNode *firstChild, *nextSibling;
}TREENODE;
static TREENODE *createTree()
{
	TREENODE *root = malloc(sizeof(TREENODE));
	memset(root, 0, sizeof(TREENODE));
	return root;
}
static void addTreeNode(TREENODE *root, char *s)
{
	int i, n = strlen(s);
	int type = 0;
	TREENODE *p, *prev;
	p = root->firstChild;
	prev = root;
	for (i = 0; i < n; i++) {
		while (p != NULL) {
			if (p->data == s[i]) {
				break;
			}
			prev = p;
			p = p->nextSibling;
			type = 1;
		}
		if (p == NULL) {
			p = malloc(sizeof(TREENODE));
			memset(p, 0, sizeof(TREENODE));
			p->data = s[i];
			p->count = 1;
			if (type == 0) {
				prev->firstChild = p;
			}
			else {
				prev->nextSibling = p;
			}
		}
		else if (p->data == s[i]) {
			p->count++;
		}

		prev = p;
		p = p->firstChild;
		type = 0;
	}
}
static int countTreeNode(TREENODE *root, char *s)
{
	int i, n = strlen(s), ret;
	TREENODE *p;
	p = root->firstChild;
	for (i = 0; i < n; i++) {
		while (p != NULL) {
			if (p->data == s[i]) {
				break;
			}
			p = p->nextSibling;
		}
		if (p == NULL) {
			return 0;
		}
		if (p->data == s[i]) {
			ret = p->count;
			p = p->firstChild;
			continue;
		}
	}
	return ret;
}
static void delTree(TREENODE *root)
{
	TREENODE *p, *temp;
	if (root != NULL) {
		p = root->firstChild;
		while (p != NULL) {
			temp = p->nextSibling;
			delTree(p);
			p = temp;
		}
		free(root);
	}
}


int main()
{
	int *p;
	int a[100];
	int n;
	char s[L];
#ifdef DEBUG
	FILE *file = fopen("input.txt", "r");
#endif
	myscanf(file, "%d", &n);
	TREENODE *root = createTree();
	while (n--) {
		myscanf(file, "%s", s);
		addTreeNode(root, s);
	}
	myscanf(file, "%d", &n);
	while (n--) {
		myscanf(file, "%s", s);
		printf("%d\n", countTreeNode(root, s));
	}
	delTree(root);

#ifdef DEBUG
	fclose(file);
	system("pause");
#endif
	return 0;
}

#endif // _MS_3

