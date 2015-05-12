#include <stdio.h>

#define L 100000

typedef struct TreeNode {
	int data;
	int first, next;
}TREENODE;

TREENODE nodes[L];
int max = 0;

void build(int ai, int bi)
{
	int i;
	if (nodes[ai].first == 0) {
		nodes[ai].first = bi;
	}
	else {
		nodes[bi].next = nodes[nodes[ai].first].next;
		nodes[nodes[ai].first].next = bi;
	}
}

int post(int node)
{
	int i, first = -1, second = -1, tmax;
	for (i = nodes[node].first; i != 0; i = nodes[i].next) {
		int ret = post(i);
		if (ret >= first) {
			second = first;
			first = ret;
		}
		else if (ret > second) {
			second = ret;
		}
	}
	first++;
	second++;
	tmax = first + second;
	max = tmax > max ? tmax : max;
	return first;
}

int main()
{
	FILE *file = fopen("input.txt", "r");
	int i, n, ai, bi;
	fscanf(file, "%d", &n);
	for (i = 0; i < n - 1; i++) {
		fscanf(file, "%d%d", &ai, &bi);
		build(ai, bi);
	}
	post(1);
	printf("%d\n", max);
	system("pause");
	return 0;
}
