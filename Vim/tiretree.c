#include "tiretree.h"

struct TireNode *createTireTree()
{
	struct TireNode *root;
	root = malloc(sizeof(struct TireNode));
	memset(root, 0, sizeof(struct TireNode));
	return root;
}
void addTireTreeNode(struct TireNode *root, char *s)
{
	struct TireNode *p = root;
	int i, n = strlen(s);
	for (i = 0; i < n; i++) {
		if (p->next[s[i] - 'a'] == NULL) {
			struct TireNode *t = malloc(sizeof(struct TireNode));
			memset(t, 0, sizeof(struct TireNode));
			p->next[s[i] - 'a'] = t;
			p = t;
			p->word++;
		}
		else {
			p = p->next[s[i] - 'a'];
			p->word++;
		}
	}
}
int delTireTreeNode(struct TireNode *cur, char *s)
{
	struct TireNode *p = cur;
	int i, n = strlen(s);

	if (cur != NULL) {
		if (n == 1) {
			cur->word--;
		}
		else if (delTireTreeNode(cur->next[*(s + 1) - 'a'], s + 1) == 0) {
			cur->word--;
		}
		else {
			return -1;
		}

		if (cur->word == 0) {
			free(cur);
		}

		return 0;
	}
	return -1;
}
void delTireTree(struct TireNode *root)
{
	if (root != NULL) {
		int i;
		for (i = 0; i < TIRE_NODE_MAX; i++) {
			delTireTree(root->next[i]);
		}
		free(root);
	}
}

TREENODE *createTree()
{
	TREENODE *root = malloc(sizeof(TREENODE));
	memset(root, 0, sizeof(TREENODE));
	return root;
}
void addTreeNode(TREENODE *root, char *s)
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
int countTreeNode(TREENODE *root, char *s)
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
void delTree(TREENODE *root)
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
