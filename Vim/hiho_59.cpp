//#include <stdio.h>
//#include <string.h>
//#include <time.h>
//#include <stack>
//#include <map>
//
//using namespace std;
//
//#define N 256
//#define L 20001
//
//typedef struct _NODE {
//	char func[N];
//	char times[N];
//	char action[N];
//}NODE;
//
//NODE nodes[L];
//int result[L];
//
//map<string, int> funcmap;
//stack<int> stk;
//
//int gIndex = 0;
//int nodeIndex = 0;
//
//tm st, et;
//time_t starttime, endtime;
//
//int mydiff(int a, int b)
//{
//	int diff, hour, min, sec;
//
//	sscanf(nodes[a].times, "%d:%d:%d", &st.tm_hour, &st.tm_min, &st.tm_sec);
//	sscanf(nodes[b].times, "%d:%d:%d", &et.tm_hour, &et.tm_min, &et.tm_sec);
//
//	starttime = mktime(&st);
//	endtime = mktime(&et);
//
//	return difftime(endtime, starttime);
//}
//
//int settime(int a, int b)
//{
//	int diff, hour, min, sec;
//	diff = mydiff(a, b);
//
//	if (diff < 0) {
//		return -1;
//	}
//
//	hour = diff / 3600;
//	min = (diff - hour * 3600) / 60;
//	sec = diff - hour * 3600 - min * 60;
//	sprintf(nodes[a].times, "%02d:%02d:%02d", hour, min, sec);
//
//	return 0;
//}
//
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//	int i, t;
//	char func[N], times[N], action[N];
//	tm *ttm;
//	starttime = time(NULL);
//	ttm = localtime(&starttime);
//	memcpy(&st, ttm, sizeof(tm));
//	memcpy(&et, ttm, sizeof(tm));
//	fscanf(file, "%d", &t);
//	while (t--) {
//		fscanf(file, "%s%s%s", nodes[nodeIndex].func, nodes[nodeIndex].times, nodes[nodeIndex].action);
//		if (nodeIndex != 0) {
//			if (mydiff(nodeIndex - 1, nodeIndex) < 0) {
//				printf("Incorrect performance log\n");
//				return 0;
//			}
//		}
//
//		if (strcmp(nodes[nodeIndex].action, "START") == 0) {
//			map<string, int>::iterator iter = funcmap.find(nodes[nodeIndex].func);
//			if (iter != funcmap.end()) {
//				printf("Incorrect performance log\n");
//				return 0;
//			}
//			funcmap[nodes[nodeIndex].func] = 1;
//			stk.push(nodeIndex);
//			result[gIndex++] = nodeIndex;
//		}
//		else {
//			if (!stk.empty()) {
//				int topnode = stk.top();
//				stk.pop();
//				if (strcmp(nodes[topnode].func, nodes[nodeIndex].func) == 0) {
//					if (settime(topnode, nodeIndex) == -1) {
//						printf("Incorrect performance log\n");
//						return 0;
//					}
//				}
//				else {
//					printf("Incorrect performance log\n");
//					return 0;
//				}
//			}
//			else {
//				printf("Incorrect performance log\n");
//				return 0;
//			}
//		}
//		nodeIndex++;
//	}
//
//	if (!stk.empty()) {
//		printf("Incorrect performance log\n");
//		return 0;
//	}
//
//	for (i = 0; i < gIndex; i++) {
//		nodeIndex = result[i];
//		printf("%s %s\n", nodes[nodeIndex].func, nodes[nodeIndex].times);
//	}
//
//	return 0;
//}