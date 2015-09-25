//#include <stdio.h>
//#include <string.h>
//
//#define MAXM 100000
//#define MAXN 100000
//#define MAXWEIGHT 1000000
//
//struct edge {
//	int to;
//	int weight;
//	int next;
//} edges[MAXM * 2 + 1];
//
//int head[MAXN + 1], edge_end = 1, k, t, l = MAXWEIGHT + 1, r = 0, mid, visited[MAXN + 1], visited_magic = 0;
//
//void add_edge(int from, int to, int weight) {
//	edges[edge_end].to = to;
//	edges[edge_end].weight = weight;
//	edges[edge_end].next = head[from];
//	head[from] = edge_end++;
//}
//
//int tryed[MAXN + 1];  /*the tryed length on each vertex*/
//int DFS(const int x, const int length) {
//	int edge;
//	if (x == t)
//		return true;
//	if (length == k)
//		return false;
//	visited[x] = visited_magic;
//	for (edge = head[x]; edge; edge = edges[edge].next)
//		if (edges[edge].weight <= mid
//			&& (visited[edges[edge].to] != visited_magic || length + 1 < tryed[edges[edge].to])) {
//			tryed[edges[edge].to] = length + 1;
//			if (DFS(edges[edge].to, length + 1))
//				return true;
//		}
//	return false;
//}
//
//struct state {
//	int l;
//	int vertex;
//} q[MAXN];
//int queue_begin, queue_end;
//int BFS(const int x) {
//	int edge;
//	if (x == t)
//		return true;
//	queue_begin = 0;
//	queue_end = 0;
//	q[queue_end].vertex = x;
//	q[queue_end].l = 0;
//	++queue_end;
//	visited[x] = visited_magic;
//	while (queue_begin < queue_end && q[queue_begin].l < k) {
//		for (edge = head[q[queue_begin].vertex]; edge; edge = edges[edge].next)
//			if (edges[edge].weight <= mid && visited[edges[edge].to] != visited_magic) {
//				if (edges[edge].to == t)
//					return true;
//				else {
//					q[queue_end].vertex = edges[edge].to;
//					q[queue_end].l = q[queue_begin].l + 1;
//					++queue_end;
//					visited[edges[edge].to] = visited_magic;
//				}
//			}
//		++queue_begin;
//	}
//	return false;
//}
//
//int main(void) {
//	freopen("input.txt", "r", stdin);
//	int n, m, u, v, w;
//	scanf("%d%d%d%d", &n, &m, &k, &t);
//	memset(visited + 1, 0, n * sizeof(int));
//	memset(head + 1, 0, n * sizeof(int));
//	while (m--) {
//		scanf("%d%d%d", &u, &v, &w);
//		add_edge(u, v, w);
//		add_edge(v, u, w);
//		if (w < l)
//			l = w;
//		else if (w > r)
//			r = w;
//	}
//	if (!r) {  /*only one edge*/
//		printf("%d\n", l);
//		return 0;
//	}
//	while (l < r) {
//		mid = (l + r) / 2;
//		++visited_magic;
//		if (BFS(1))  /*DFS(1, 0)*/
//			r = mid;
//		else
//			l = mid + 1;
//	}
//	printf("%d\n", l);
//	return 0;
//}
//
