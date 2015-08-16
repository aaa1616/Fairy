//#include <stdio.h>
//#include <map>
//
//using namespace std;
//
//#define M 210
//#define L 256
//
//typedef struct _NODE {
//	char n1[L];
//	char n2[L];
//	int visit;
//}NODE;
//
//NODE nodes[M];
//int gIndex = 0;
//
//map<string, int> g1map;
//
//
//#define ONLINE_JUDGE
//
//int main()
//{
//#ifdef ONLINE_JUDGE
//	FILE *file = fopen("codejam input/A-small-1-attempt1.in", "r");
//#else
//	FILE *file = fopen("input.txt", "r");
//#endif
//
//	FILE *out = fopen("output.txt", "w");
//	int i, j, n, t, u, v, result, flag;
//	map<string, int>::iterator g1iter;
//	fscanf(file, "%d", &t);
//	for (i = 1; i <= t; i++) {
//		fscanf(file, "%d", &n);
//		flag = 1;
//		result = 0;
//		gIndex = 0;
//		g1map.clear();
//		while (n--) {
//			fscanf(file, "%s%s", nodes[gIndex].n1, nodes[gIndex].n2);
//			nodes[gIndex].visit = 0;
//			gIndex++;
//		}
//
//		g1map[nodes[0].n1] = 1;
//		g1map[nodes[0].n2] = 0;
//
//		while (flag) {
//			int allvisit = 1;
//			for (j = 1; j < gIndex; j++) {
//				string n1 = nodes[j].n1;
//				string n2 = nodes[j].n2;
//				//if (nodes[j].visit == 0)  {
//				//	g1map[n1] = -1;
//				//	g1map[n2] = 0;
//				//	nodes[j].visit = 1;
//				//	allvisit = 0;
//				//	continue;
//				//}
//				if (nodes[j].visit == 0) {
//					allvisit = 0;
//
//					g1iter = g1map.find(n1);
//					if (g1iter != g1map.end()) {
//						g1iter = g1map.find(n2);
//						if (g1iter != g1map.end()) {
//							if (g1map[n1] == g1map[n2]) {
//								flag = 0;
//								result = -1;
//								break;
//							}
//							else {
//								nodes[j].visit = 1;
//							}
//
//						}
//						else {
//							g1map[n2] = !g1map[n1];
//							nodes[j].visit = 1;
//						}
//					}
//					else {
//						g1iter = g1map.find(n2);
//						if (g1iter != g1map.end()) {
//							g1map[n1] = !g1map[n2];
//							nodes[j].visit = 1;
//						}
//					}
//				}
//			}
//
//			if (allvisit) {
//				flag = 0;
//			}
//		}
//
//		if (result == -1) {
//#ifdef ONLINE_JUDGE
//			fprintf(out, "Case #%d: No\n", i);
//#else
//			printf("Case #%d: No\n", i);
//#endif
//		}
//		else {
//#ifdef ONLINE_JUDGE
//			fprintf(out, "Case #%d: Yes\n", i);
//#else
//			printf("Case #%d: Yes\n", i);
//#endif
//
//		}
//	}
//	fclose(out);
//
//	return 0;
//}
