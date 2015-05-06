#ifndef _TIRE_TREE_H
#define _TIRE_TREE_H
#include "ftinclib.h"

#define TIRE_NODE_MAX 26

struct TireNode {
	int word;
	struct TireNode *next[TIRE_NODE_MAX];
};

typedef struct TreeNode {
	char data;
	int count;
	struct TreeNode *firstChild, *nextSibling;
}TREENODE;

struct TireNode *createTireTree();
void addTireTreeNode(struct TireNode *root, char *s);
void delTireTree(struct TireNode *root, char *s);

TREENODE *createTree();
void addTreeNode(TREENODE *root, char *s);
void delTree(TREENODE *root);

int countTreeNode(TREENODE *root, char *s);

#endif // !_TIRE_TREE_H
