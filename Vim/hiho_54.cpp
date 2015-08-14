#include <stdio.h>
#include <map>

using namespace std;

#define N 20001
#define M 100001
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct _NODE {
	int next;
	int group;
	int deg;
	int sum;
}NODE;

typedef struct _EDGE {
	int to, next;
}EDGE;

NODE nodes[N];
EDGE edges[M];
NODE tonodes[N];
EDGE toedges[M];

int low[N];
int dfn[N];
int vis[N];
int stk[N];
int w[N];

int gIndex = 0;
int top = 0;
int groupCount = 0;

map<int, map<int, int>> newedges;

void tobuild(int a, int b)
{
	gIndex++;
	toedges[gIndex].to = b;
	toedges[gIndex].next = tonodes[a].next;
	tonodes[a].next = gIndex;
	tonodes[b].deg++;
}

void build(int u, int v)
{
	gIndex++;
	edges[gIndex].to = v;
	edges[gIndex].next = nodes[u].next;
	nodes[u].next = gIndex;
}

void dfs(int u)
{
	int i, v;
	low[u] = dfn[u] = ++gIndex;
	vis[u] = 1;
	stk[++top] = u;
	vis[u] = 2;
	for (i = nodes[u].next; i; i = edges[i].next) {
		v = edges[i].to;
		if (vis[v] == 0) {
			dfs(v);
			low[u] = MIN(low[u], low[v]);
		}
		else if (vis[v] == 2) {
			low[u] = MIN(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		while (stk[top] != u) {
			nodes[stk[top]].group = u;
			w[u] += w[stk[top]];
			vis[stk[top]] = 1;
			top--;
		}
		vis[stk[top]] = 1;
		nodes[stk[top--]].group = u;
	}
}

int main()
{
	FILE *file = fopen("input.txt", "r");
	int i, j, n, m, u, v, max = 0;
	map<int, int>::iterator itnode;
	map<int, map<int, int>>::iterator itedge;
	fscanf(file, "%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		fscanf(file, "%d", w + i);
	}
	while (m--) {
		fscanf(file, "%d%d", &u, &v);
		build(u, v);
	}
	gIndex = 0;
	dfs(1);
	gIndex = 0;

	for (u = 1; u <= n; u++) {
		if (vis[u] != 0) {
			tonodes[nodes[u].group].sum = w[nodes[u].group];
			for (i = nodes[u].next; i; i = edges[i].next) {
				v = nodes[edges[i].to].group;
				if (v != nodes[u].group) {
					tonodes[v].sum = w[v];
					newedges[nodes[u].group][v] = 1;
					printf("%d %d\n", nodes[u].group, v);
				}
			}
		}
	}

	for (itedge = newedges.begin(); itedge != newedges.end(); itedge++) {
		for (itnode = itedge->second.begin(); itnode != itedge->second.end(); itnode++) {
			tobuild(itedge->first, itnode->first);
			nodes[itedge->first].group = -1;
		}
	}

	gIndex = 0;
	for (i = 1; i <= n; i++) {
		if (tonodes[i].deg == 0 && nodes[i].group == -1) {
			stk[gIndex++] = i;
		}
	}
	i = 0;
	max = tonodes[1].sum;
	while (i < gIndex) {
		u = stk[i++];
		for (j = tonodes[u].next; j != 0; j = toedges[j].next) {
			v = toedges[j].to;
			if (tonodes[v].deg != 0) {
				tonodes[v].sum = w[v] + tonodes[u].sum > tonodes[v].sum ? w[v] + tonodes[u].sum : tonodes[v].sum;
				max = tonodes[v].sum > max ? tonodes[v].sum : max;
				tonodes[v].deg--;
				if (tonodes[v].deg == 0) {
					stk[gIndex++] = v;
				}
			}
		}
	}

	printf("%d\n", max);

	return 0;
}