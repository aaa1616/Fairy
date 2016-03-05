#include <string.h>
#include <unordered_map>
#include <unordered_set>

#include "dalvikflow.h"

using namespace std;

#define N 1000

typedef struct _FUNC {
	char classname[100];
	char funcname[100];
}FUNC;

typedef struct _FLOW {
	FUNC source[2], sink[2];
	FUNC func[1000];
}FLOW;

typedef struct _DALNODE {
	int next, parent, last;
	int pathIndex, funcIndex;
}NODE;

typedef struct _DALEDGE {
	int to, next;
}EDGE;

static int gIndex = 0;
static int gnIndex = 0;
NODE nodes[N];
EDGE edges[N];
unordered_map<string, int> mapping;
unordered_set<string> filter;

FLOW flow[100];

void build(int a, int b)
{
	gIndex++;
	edges[gIndex].to = b;
	if (nodes[a].last == 0) {
		nodes[a].next = nodes[a].last = gIndex;
	}
	else {
		edges[nodes[a].last].next = gIndex;
	}
	nodes[b].parent = a;
}

void dfsdalvik(int u, int dep)
{
	int i, v;
	int pathIndex = nodes[u].pathIndex, funcIndex = nodes[u].funcIndex;
	printf("(%d)%s.%s\n", dep, flow[pathIndex].func[funcIndex].classname, flow[pathIndex].func[funcIndex].funcname);
	for (i = nodes[u].next;  i; i = edges[i].next) {
		v = edges[i].to;
		dfsdalvik(v, dep + 1);
	}
}

void filterInit()
{
	filter.insert("<init>");
	filter.insert("dummyMainMethod");
	filter.insert("access$0");
	filter.insert("access$1");
}

void dalvikflow()
{
	freopen("path.txt", "r", stdin);
	char line[100];
	int flag = 1, index = 0, pathIndex = -1, sourceIndex, sinkIndex, funcIndex;
	filterInit();
	while (gets(line)) {
		if (strcmp(line, "Sink and Source") == 0) {
			pathIndex++;
			gIndex = gnIndex = sourceIndex = sinkIndex = funcIndex = flag = 0;
			memset(nodes, 0, sizeof(nodes));
			memset(edges, 0, sizeof(edges));
			mapping.clear();
			continue;
		}
		else if (strcmp(line, "END") == 0) {
			dfsdalvik(0, 0);
		}
		else if (strcmp(line, "on Path") == 0) {
			continue;
		}
		if (flag < 4) {
			if ((flag & 0x01) == 0) {
				strcpy(flow[pathIndex].sink[sinkIndex].classname, line);
			}
			else {
				strcpy(flow[pathIndex].sink[sinkIndex].funcname, line);
				sinkIndex++;
			}
		}
		else if (flag < 8) {
			if ((flag & 0x01) == 0) {
				strcpy(flow[pathIndex].source[sourceIndex].classname, line);
			}
			else {
				strcpy(flow[pathIndex].source[sourceIndex].funcname, line);
				sourceIndex++;
			}
		}
		else {
			if ((flag & 0x01) == 0) {
				strcpy(flow[pathIndex].func[funcIndex].classname, line);
			}
			else {
				strcpy(flow[pathIndex].func[funcIndex].funcname, line);
				if (funcIndex != 0) {
					if (memcmp(&flow[pathIndex].func[funcIndex], &flow[pathIndex].func[funcIndex - 1], sizeof(FUNC)) == 0 || filter.find(flow[pathIndex].func[funcIndex].funcname) != filter.end()) {
						memset(&flow[pathIndex].func[funcIndex], 0, sizeof(FUNC));
						funcIndex--;
					}
					else {
						string classname = flow[pathIndex].func[funcIndex].classname;
						string funcname = flow[pathIndex].func[funcIndex].funcname;
						string fullname = classname + "." + funcname;
						string classname1 = flow[pathIndex].func[funcIndex - 1].classname;
						string funcname1 = flow[pathIndex].func[funcIndex - 1].funcname;
						string fullname1 = classname1 + "." + funcname1;
						if (mapping.find(fullname) != mapping.end()) {
							if (nodes[mapping[fullname1]].parent != mapping[fullname]) {
								build(mapping[fullname1], mapping[fullname]);
							}
						}
						else {
							mapping[fullname] = gnIndex;
							nodes[gnIndex].pathIndex = pathIndex;
							nodes[gnIndex].funcIndex = funcIndex;
							gnIndex++;
							build(mapping[fullname1], mapping[fullname]);
						}
					}
				}
				else {
					string classname = flow[pathIndex].func[funcIndex].classname;
					string funcname = flow[pathIndex].func[funcIndex].funcname;
					mapping[classname + "." + funcname] = gnIndex;
					nodes[gnIndex].pathIndex = pathIndex;
					nodes[gnIndex].funcIndex = funcIndex;
					gnIndex++;
				}
				funcIndex++;
			}
		}
		flag++;
	}
}