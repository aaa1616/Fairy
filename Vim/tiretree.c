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
