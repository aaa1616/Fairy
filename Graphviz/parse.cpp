#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <gvc.h>

#include "dalvikflow.h"

#pragma comment(lib, "gvc.lib")
#pragma comment(lib, "cdt.lib")
#pragma comment(lib, "cgraph.lib")
#pragma comment(lib, "gvplugin_core.lib")
#pragma comment(lib, "gvplugin_dot_layout.lib")
#pragma comment(lib, "gvplugin_neato_layout.lib")
#pragma comment(lib, "gvplugin_gd.lib")
#pragma comment(lib, "gvplugin_pango.lib")

using namespace std;

#define N 10000

typedef struct _NODE {
	int pid, uid;
	int cid;
	string func;
	string param;

	int parent;
	int next;
	int child;
	int scheduleFunc;
	int matchid;
	int finishFunc;

	int app;
	int visit;
}NODE;

typedef struct _EDGE {
	int to;
	int next;
}EDGE;

NODE nodes[N];

EDGE edges[N];

map<int, map<int, int>> umap;

map<string, int> packageSI;
map<int, string> packageIS;

vector<int> Q;

int gnIndex, geIndex;

char cparam[10000];

char ctemp[10000];

void packageList()
{
	ifstream file;
	string buf;
	char pname[100];
	int uid;
	file.open("packages.list", ios::in);
	while (getline(file, buf, '\n')) {
		sscanf(buf.c_str(), "%s %d", pname, &uid);
		string name(pname);
		packageIS[uid] = name;
		packageSI[name] = uid;
	}
	file.close();
}

void build(int a, int b, int uid, int pid, int cid)
{
	geIndex++;
	edges[geIndex].to = b;
	edges[geIndex].next = nodes[a].next;
	nodes[a].next = geIndex;
	nodes[a].child++;
	nodes[b].parent = a;

	if (uid != 0 && cid == 0) {
		umap[uid][pid] = b;
	}
	if (cid != 0) {
		umap[uid][cid] = b;
	}
}

void dfs(Agraph_t *g, int u)
{
	int i, v;
	Agnode_t *nodeu, *nodev;
	if (nodes[u].visit == 1) {
		return;
	}
	nodes[u].visit = 1;
	for (i = nodes[u].next; i; i = edges[i].next) {
		v = edges[i].to;
		dfs(g, v);
			if (nodes[v].func != "clone" || nodes[v].child != 0) {
				string context1 = nodes[u].func + "\n" + nodes[u].param;
				char temp[10];
				itoa(u, temp, 10);
				strcpy(cparam, temp);
				strcat(cparam, "\n");
				strcat(cparam, context1.c_str());

				nodeu = agnode(g, cparam, 1);
				agsafeset(nodeu, "shape", "rect", "");

				string context2 = nodes[v].func + "\n" + nodes[v].param;
				itoa(v, temp, 10);
				strcpy(cparam, temp);
				strcat(cparam, "\n");
				strcat(cparam, context2.c_str());

				nodev = agnode(g, cparam, 1);
				agsafeset(nodev, "shape", "rect", "");
				
				agedge(g, nodeu, nodev, 0, 1);
			}
			else {
				nodes[v].child--;
			}
	}
}

void match(int total)
{
	int i;
	int flag = 0;
	int cnode, pnode;
	int last = 0;

	for (i = 1; i < total; i++) {
		if (nodes[i].scheduleFunc == 1) {
			Q.push_back(i);
		}
		else {
			if (nodes[i].finishFunc == 1) {
				vector<int>::iterator iter;
				for (iter = Q.begin(); iter != Q.end(); iter++) {
					if (nodes[*iter].func == "scheduleReceiver") {
						if (nodes[i].uid == nodes[*iter].matchid) {
							flag = 1;
							break;
						}
					}
					else {
						if (nodes[i].pid == nodes[*iter].matchid) {
							flag = 1;
							break;
						}
					}
				}
				if (flag == 1) {
					cnode = pnode = i;

					do {
						cnode = pnode;
						pnode = nodes[pnode].parent;
					} while (nodes[pnode].pid == nodes[i].pid && nodes[pnode].app != 1 && pnode > last && pnode > *iter);
					
					build(*iter, cnode, 0, 0, 0);
					build(*iter, i, 0, 0, 0);
					last = i;
					Q.erase(iter);
					flag = 0;
					break;
				}
			}
		}
	}
}

void streamline(Agraph_t *g, int u, map<string, int> &keywords, int &inside)
{
	int i, v;
	Agnode_t *nodeu, *nodev;
	int flag = 0;
	if (nodes[u].finishFunc != 1 && nodes[nodes[u].parent].scheduleFunc == 1 && nodes[u].scheduleFunc != 1) {
		flag = 1;
	}

	if (nodes[u].finishFunc == 1) {
		keywords.clear();
	}
	for (i = nodes[u].next; i; i = edges[i].next) {
		v = edges[i].to;
		if (nodes[v].finishFunc == 1) {
			continue;
		}
		if (flag == 1) {
			inside = 1;
			streamline(g, v, keywords, inside);
		}
		else {
			streamline(g, v, keywords, inside);
			if (nodes[v].func == "open"
				|| nodes[v].func == "read"
				|| nodes[v].func == "write"
				|| nodes[v].func == "close") {
				string keyword = "FILE_ACCESS";
				keywords[keyword] = 1;
			}

			if (nodes[v].func == "recvfrom"
				|| nodes[v].func == "sendto") {
				string keyword = "NETWORK_ACCESS";
				keywords[keyword] = 1;
			}

			if (nodes[v].func == "android.app.IActivityManager.checkPermission") {
				keywords[nodes[v].param] = 1;
			}

			if (inside == 0) {
				string context1 = nodes[u].func + "\n" + nodes[u].param;
				char temp[10];
				itoa(u, temp, 10);
				strcpy(cparam, temp);
				strcat(cparam, "\n");
				strcat(cparam, context1.c_str());

				nodeu = agnode(g, cparam, 1);
				agsafeset(nodeu, "shape", "rect", "");

				string context2 = nodes[v].func + "\n" + nodes[v].param;
				itoa(v, temp, 10);
				strcpy(cparam, temp);
				strcat(cparam, "\n");
				strcat(cparam, context2.c_str());

				nodev = agnode(g, cparam, 1);
				agsafeset(nodev, "shape", "rect", "");

				agedge(g, nodeu, nodev, 0, 1);
			}
		}
	}
	if (flag == 1) {
		string context1 = "";

		map<string, int>::iterator iter;
		for (iter = keywords.begin(); iter != keywords.end(); iter++) {
			context1 += "\n" + iter->first;
		}
		nodes[u].func = context1;
		nodes[u].param = "";

		keywords.clear();
		
		inside = 0;
	}
}

int main()
{
	int pid, uid, len, i, cIndex;
	char cfunc[100];

	char config[10][256];
	ifstream file;
	string buf;

	char newConfig[10];
	int reConfig = 1;

	dalvikflow();
	return 0;


	printf("=================================================================\n");
	printf("=\t\t\tGraph Generating Tool\t\t\t=\n");
	printf("=================================================================\n");
	printf("\n");
	printf("-----------------------------------------------------------------\n");
	while (reConfig) {
		printf("Generate new config file ? (N) : ");
		gets(newConfig);
		if (strcmp(newConfig, "Y") == 0) {
			FILE *file = fopen("config.ini", "w");
			printf("Log file path : ");
			gets(config[0]);
			fprintf(file, "%s\n", config[0]);

			printf("Single application reconstruction ? (Y) : ");
			gets(config[1]);
			if (strlen(config[1]) == 0) {
				strcpy(config[1], "Y");
			}
			fprintf(file, "%s\n", config[1]);

			printf("Sensitive data source ? (NONE) : ");
			gets(config[2]);
			if (strlen(config[2]) == 0) {
				strcpy(config[2], "NONE");
			}
			fprintf(file, "%s\n", config[2]);

			printf("Behavior graph algorithm and layours ? (dot) : ");
			gets(config[3]);
			if (strlen(config[3]) == 0) {
				strcpy(config[3], "dot");
			}
			fprintf(file, "%s\n", config[3]);

			printf("Behavior graph format ? (png) : ");
			gets(config[4]);
			if (strlen(config[4]) == 0) {
				strcpy(config[4], "png");
			}
			fprintf(file, "%s\n", config[4]);

			printf("Behavior graph file name ? (out1.png) : ");
			gets(config[5]);
			if (strlen(config[5]) == 0) {
				strcpy(config[5], "out1.png");
			}
			fprintf(file, "%s\n", config[5]);

			printf("Abstract graph algorithm and layours ? (dot) : ");
			gets(config[6]);
			if (strlen(config[6]) == 0) {
				strcpy(config[6], "dot");
			}
			fprintf(file, "%s\n", config[6]);

			printf("Abstract graph format ? (png) : ");
			gets(config[7]);
			if (strlen(config[7]) == 0) {
				strcpy(config[7], "png");
			}
			fprintf(file, "%s\n", config[7]);

			printf("Abstract graph file name ? (out2.png) : ");
			gets(config[8]);
			if (strlen(config[8]) == 0) {
				strcpy(config[8], "out2.png");
			}
			fprintf(file, "%s\n", config[8]);
			reConfig = 0;
			fclose(file);
		}
		else {
			FILE *file = fopen("config.ini", "r");
			int i;
			for (i = 0; i < 9; i++) {
				fgets(config[i], 256, file);
				config[i][strlen(config[i]) - 1] = 0;
				if (strlen(config[i]) == 0) {
					if (i < 8) {
						printf("Config file format is error, please regenerate config file!\n");
						break;
					}
				}
			}
			fclose(file);
			if (i == 9) {
				reConfig = 0;
			}
		}
	}
	printf("-----------------------------------------------------------------\n");

	printf("=================================================================\n");
	printf("Start generating graph ? (Y) : ");
	gets(newConfig);
	if (strlen(newConfig) != 0) {
		return 0;
	}

	printf("Generating graph, please wait......\n");

	packageList();

	file.open(config[0], ios::in);
	gnIndex = 1;
	geIndex = 0;
	map<int, map<int, int>>::iterator uit;
	map<int, int>::iterator pit;

	Agraph_t *g;
	GVC_t *gvc;
	gvc = gvContext();
	g = agopen("g", Agdirected, 0);
	getline(file, buf, '\n');

	while (getline(file, buf, '\n')) {
		sscanf(buf.c_str(), "[Rootkit](%d)(%d)%[^(](%[^\n])", &pid, &uid, cfunc, cparam);
		len = strlen(cparam);
		if (len > 0) {
			cparam[len - 1] = 0;
		}
		string func(cfunc);
		cIndex = 0;
		string param;
		if (func != "scheduleRegisteredReceiver" && func != "scheduleReceiver") {
			for (i = 0; i < len; i++) {
				if ((i + 1) % 60 != 0) {
					ctemp[cIndex++] = cparam[i];
				}
				else {
					ctemp[cIndex++] = '\\';
					ctemp[cIndex++] = 'n';
				}
			}
			param = ctemp;
		}
		else {
			param = cparam;
		}
		
		nodes[gnIndex].pid = pid;
		nodes[gnIndex].uid = uid;
		if (func == "clone") {
			nodes[gnIndex].cid = atoi(param.c_str());
		}
		nodes[gnIndex].func = func;
		nodes[gnIndex].param = param;

		if (strcmp(config[1], "N") == 0) {

			if (func == "scheduleRegisteredReceiver") {
				string broadcast = param.substr(0, param.find_first_of(','));
				if (strcmp(broadcast.c_str(), config[2]) == 0) {
					nodes[gnIndex].scheduleFunc = 1;
					nodes[gnIndex].matchid = atoi(param.substr(param.find_last_of(',') + 1).c_str());
				}
			}

			if (func == "scheduleReceiver") {
				string broadcast = param.substr(0, param.find_first_of(','));
				if (strcmp(broadcast.c_str(), config[2]) == 0) {
					nodes[gnIndex].scheduleFunc = 1;
					string temp = param.substr(param.find_last_of(',') + 2);
					map<string, int>::iterator iter = packageSI.find(param.substr(param.find_last_of(',') + 2));
					if (iter != packageSI.end()) {
						nodes[gnIndex].matchid = iter->second;
					}
					else {
						nodes[gnIndex].matchid = 0;
					}
				}
			}
		}

		if (func == "finishReceiver") {
			nodes[gnIndex].finishFunc = 1;
		}

		uit = umap.find(uid);
		if (uit != umap.end()) {
			pit = uit->second.find(pid);
			if (pit != uit->second.end()) {
				if (func != "clone") {
					build(pit->second, gnIndex, uid, pid, 0);
				}
				else {
					build(pit->second, gnIndex, uid, pid, nodes[gnIndex].cid);
				}
			}
			else {
				uit->second[pid] = gnIndex;
			}
		}
		else {
			map<int, int> pmap;
			pmap[pid] = gnIndex;
			umap[uid] = pmap;

			if (uid != 1000) {
				gnIndex++;
				map<int, string>::iterator iter = packageIS.find(uid);
				if (iter != packageIS.end()) {
					nodes[gnIndex].func = iter->second;
					nodes[gnIndex].param = "";
					nodes[gnIndex].app = 1;
					build(0, gnIndex, 0, 0, 0);
				}
				build(gnIndex, umap[uid][pid], 0, 0, 0);
			}
			else {
				build(0, gnIndex, 0, 0, 0);
			}

		}
		gnIndex++;
	}
	file.close();
	//match(gnIndex);
	dfs(g, 0);

	gvLayout(gvc, g, config[3]);
	gvRenderFilename(gvc, g, config[4], config[5]);
	/* Free layout data */
	gvFreeLayout(gvc, g);
	/* Free graph structures */
	agclose(g);
	/* close output file, free context, and return number of errors */
	gvFreeContext(gvc);

	//streamline
	gvc = gvContext();
	g = agopen("g", Agdirected, 0);
	map<string, int> keywords;
	int inside = 0;
	streamline(g, 0, keywords, inside);

	gvLayout(gvc, g, config[6]);
	gvRenderFilename(gvc, g, config[7], config[8]);
	/* Free layout data */
	gvFreeLayout(gvc, g);
	/* Free graph structures */
	agclose(g);
	/* close output file, free context, and return number of errors */
	gvFreeContext(gvc);

	printf("Graph generation complete, please check!\n");
	printf("=================================================================\n");

	return 0;

}