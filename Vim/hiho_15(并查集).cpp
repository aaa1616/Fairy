//#include <cstdio>
//#include <map>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//#define L 100001
//#define S 100
//
//typedef struct TreeNode {
//	int first, next;
//	int rank, p;
//	int anc;
//	int color;
//	string name;
//}TREENODE;
//
//typedef struct PairNode {
//	int next;
//	int value;
//	int quespos;
//}PAIRNODE;
//
//int gIndex = 0;
//map<string, int> names;
//
//TREENODE nodes[L];
//PAIRNODE pnodes[2 * L];
//int posit[L];
//int ret[L];
//
//void makeset(int x)
//{
//	nodes[x].p = x;
//	nodes[x].rank = 0;
//}
//int findset(int x)
//{
//	if (nodes[x].p != x) {
//		nodes[x].p = findset(nodes[x].p);
//	}
//	return nodes[x].p;
//}
//void unionset(int x, int y)
//{
//	x = findset(x);
//	y = findset(y);
//	if (nodes[x].rank > nodes[y].rank) {
//		nodes[y].p = x;
//	}
//	else {
//		nodes[x].p = y;
//		if (nodes[x].rank == nodes[y].rank) {
//			nodes[y].rank++;
//		}
//	}
//}
//
//void build(int ai, string n1, int bi, string n2)
//{
//	int i;
//	nodes[bi].name = n2;
//	if (nodes[ai].first == 0) {
//		nodes[ai].first = bi;
//		nodes[ai].name = n1;
//	}
//	else {
//		nodes[bi].next = nodes[nodes[ai].first].next;
//		nodes[nodes[ai].first].next = bi;
//	}
//}
//void buildpair(int ai, int bi, int i)
//{
//	gIndex++;
//	pnodes[gIndex].value = bi;
//	pnodes[gIndex].quespos = i;
//	pnodes[gIndex].next = posit[ai];
//	posit[ai] = gIndex;
//}
//
//void lca(int u)
//{
//	int i, v;
//	makeset(u);
//	nodes[u].anc = u;
//	for (i = nodes[u].first; i != 0; i = nodes[i].next) {
//		lca(i);
//		unionset(i, u);
//		nodes[findset(u)].anc = u;
//	}
//	nodes[u].color = 1;
//	for (i = posit[u]; i != 0; i = pnodes[i].next) {
//		v = pnodes[i].value;
//		if (nodes[v].color == 1) {
//			ret[pnodes[i].quespos] = nodes[findset(v)].anc;
//		}
//	}
//}
//
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//	int i, n, ai, bi;
//	char name1[S], name2[S];
//	fscanf(file, "%d", &n);
//	while (n--) {
//		fscanf(file, "%s %s", name1, name2);
//		string n1(name1), n2(name2);
//		map<string, int>::iterator it1, it2;
//		it1 = names.find(n1);
//		it2 = names.find(n2);
//		if (it1 != names.end()) {
//			ai = it1->second;
//		}
//		else {
//			ai = gIndex;
//			names[n1] = gIndex++;
//		}
//		if (it2 != names.end()) {
//			bi = it2->second;
//		}
//		else {
//			bi = gIndex;
//			names[n2] = gIndex++;
//		}
//		build(ai, n1, bi, n2);
//	}
//	gIndex = 0;
//	fscanf(file, "%d", &n);
//	for (i = 0; i < n; i++) {
//		fscanf(file, "%s %s", name1, name2);
//		string n1(name1), n2(name2);
//		buildpair(names[n1], names[n2], i);
//		buildpair(names[n2], names[n1], i);
//	}
//	lca(0);
//	for (i = 0; i < n; i++) {
//		printf("%s\n", nodes[ret[i]].name.c_str());
//	}
//	return 0;
//}