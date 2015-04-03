#ifndef _TIRE_TREE_H
#define _TIRE_TREE_H
#include "ftinclib.h"

#define TIRE_NODE_MAX 26

struct TireNode {
	int word;
	struct TireNode *next[TIRE_NODE_MAX];
};

struct TireNode *createTireTree();
void addTireTreeNode(struct TireNode *root, char *s);
void delTireTree(struct TireNode *root, char *s);

#endif // !_TIRE_TREE_H
