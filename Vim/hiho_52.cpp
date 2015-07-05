#include <stdio.h>
#include <map>

#define N 20001
#define M 100001
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef struct _NODE {
	int next;
}NODE;

typedef struct _EDGE {
	int to, next;
}EDGE;

NODE nodes[N];
EDGE edges[2 * M];
int low[N];
int dfn[N];
int vis[N];
int parent[N];

int gIndex = 0;

map<int, int> nodemap;
map<int, map<int, int>> edgemap;

void build(int u, int v)
{
	gIndex++;
	edges[gIndex].to = v;
	edges[gIndex].next = nodes[u].next;
	nodes[u].next = gIndex;
}

void dfs(int u)
{
	int i, v, child = 0;
	low[u] = dfn[u] = ++gIndex;
	vis[u] = 1;
	for (i = nodes[u].next; i; i = edges[i].next) {
		v = edges[i].to;
		if (vis[v] == 0) {
			parent[v] = u;
			child++;
			dfs(v);
			low[u] = MIN(low[u], low[v]);

			if (parent[u] == 0 && child > 1) {
				nodemap[u] = 1;
			}

			if (parent[u] != 0 && low[v] >= dfn[u]) {
				nodemap[u] = 1;
			}

			if (low[v] > dfn[u]) {
				if (u > v) {
					edgemap[v][u] = 1;
				}
				else {
					edgemap[u][v] = 1;
				}
			}
		}
		else if (parent[u] != v) {
			low[u] = MIN(low[u], dfn[v]);
		}
	}
}

int main()
{
	FILE * file = fopen("input.txt", "r");
	int n, m, u, v;
	map<int, int>::iterator itnode;
	map<int, map<int, int>>::iterator itedge;
	fscanf(file, "%d%d", &n, &m);
	while (m--) {
		fscanf(file, "%d%d", &u, &v);
		build(u, v);
		build(v, u);
	}
	gIndex = 0;
	dfs(1);
	if (nodemap.empty()) {
		printf("Null");
	}
	for (itnode = nodemap.begin(); itnode != nodemap.end(); itnode++) {
		printf("%d ", itnode->first);
	}
	printf("\n");
	for (itedge = edgemap.begin(); itedge != edgemap.end(); itedge++) {
		for (itnode = itedge->second.begin(); itnode != itedge->second.end(); itnode++) {
			printf("%d %d\n", itedge->first, itnode->first);
		}
	}
	return 0;
}