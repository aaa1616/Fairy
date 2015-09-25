#include <stdio.h>
#include <algorithm>

using namespace std;

#define L 100002

//#define MIN(a, b) (nodes[(a)].h < nodes[(b)].h ? (a) : (b))

typedef struct _Node {
	int next;
	int h;
	int p, arraypos;
}NODE;

typedef struct _EDGE{
	int to, next;
}EDGE;

int gIndex = 0;

NODE nodes[L];
EDGE edges[2 * L];

void build(int u, int v)
{
	gIndex++;
	edges[gIndex].to = v;
	edges[gIndex].next = nodes[u].next;
	nodes[u].next = gIndex;
	nodes[u].h = INT_MAX;
}
void dfs(int u, int h, int p)
{
	int i, v;
	nodes[u].p = p;
	for (i = nodes[u].next; i ; i = edges[i].next) {
		v = edges[i].to;
		if (v != p) {
			dfs(v, h + 1, u);
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	int n, m, u, v, q, ret;
	scanf("%d%d", &n, &m);
	n--;
	while (n--) {
		scanf("%d%d", &u, &v);
		build(u, v);
		build(v, u);
	}

	gIndex = 0;
	dfs(1, 0, 0);
	nodes[1].h = 0;

	while (m--) {
		scanf("%d%d", &q, &v);
		if (q == 1) {
			u = v;
			nodes[v].h = 0;
			while (v != 0) {
				if (nodes[nodes[v].p].h > nodes[v].h + 1)  {
					nodes[nodes[v].p].h = nodes[v].h + 1;
					v = nodes[v].p;
				}
				else {
					break;
				}
			}
		}
		else {
			int height = 0;
			ret = INT_MAX;
			while (v != 0) {
				if (nodes[v].h != INT_MAX) {
					ret = min(ret, nodes[v].h + height);
				}
				v = nodes[v].p;
				height++;
				if (ret <= height) {
					break;
				}
			}
			printf("%d\n", ret);
		}
		
	}
	return 0;
}