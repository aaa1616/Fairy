#include "graph.h"

GRAPH *createGraph()
{
	GRAPH *g = malloc(sizeof(GRAPH));
	int i, vet, edge, b, e;
	char strb[10], stre[10];
	scanf("%d%d", &vet, &edge);
	VERTEX *adj = malloc(vet * sizeof(VERTEX));
	g->adj = adj;
	g->vetNum = vet;
	g->edgeNum = edge;
	for (i = 0; i < vet; i++) {
		adj[i].data = i;
		adj[i].adj = NULL;

	}
	for (i = 0; i < edge; i++) {
		scanf("%s %s", strb, stre);
		b = strb[0] - 'A';
		e = stre[0] - 'A';
		EDGE *p = malloc(sizeof(EDGE));
		p->dest = e;
		p->link =adj[b].adj;
		adj[b].adj = p;

		p = malloc(sizeof(EDGE));
		p->dest = b;
		p->link =adj[e].adj;
		adj[e].adj = p;
	}
	return g;
}
static void dfsVisit(GRAPH *g, int v)
{
	printf("%c ", v + 'A');
	g->adj[v].color = 1;
	EDGE *p = g->adj[v].adj;
	while (p != NULL) {
		int next = p->dest;
		if (g->adj[next].color == 0) {
			dfsVisit(g, next);
		}
		p = p->link;
	}
	g->adj[v].color = 2;
}
void dfs(GRAPH *g)
{
	VERTEX *adj = g->adj;
	int i, vet = g->vetNum;
	for (i = 0; i < vet; i++) {
		adj[i].color = 0;
	}
	for (i = 0; i < vet; i++) {
		if (adj[i].color == 0) {
			dfsVisit(g, i);
		}
	}
	printf("\n");
}
void delGraph(GRAPH *g)
{
	VERTEX *adj = g->adj;
	int i, vet = g->vetNum;
	for (i = 0; i < vet; i++) {
		EDGE *next, *p = adj[i].adj;
		while (p != NULL) {
			next = p->link;
			free(p);
			p = next;
		}
	}
	free(adj);
	free(g);
}