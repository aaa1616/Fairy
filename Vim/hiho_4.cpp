//#define _HIHO_4
#ifdef _HIHO_4
#include <cstdio>
#include <queue>

using namespace std;

#define DEBUG
#ifdef DEBUG
#define myscanf(file, fmt, ...) fscanf(file, fmt, ##__VA_ARGS__)
#else
#define myscanf(file, fmt, ...) scanf(fmt, ##__VA_ARGS__)
#endif // DEBUG

#define L 1000000

typedef struct TrieNode{
	char data;
	int next[26];
	int parent;
	bool flag;
}TRIENODE;

TRIENODE nodes[L];
int trie[L], next[L][26];
int nextnode = 0;
char word[L];

void insert()
{
	int i = 0, index = 0;
	int pos;

	while (word[i] != 0) {
		pos = word[i] - 'a';
		if (nodes[index].next[pos] == 0) {
			nextnode++;
			nodes[index].next[pos] = nextnode;
			nodes[nextnode].data = pos;
			nodes[nextnode].parent = index;
		}
		index = nodes[index].next[pos];
		i++;
	}
	nodes[index].flag = true;
}
void createGraph()
{
	int i, index;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		index = q.front();
		q.pop();
		if (index == 0 || nodes[index].parent == 0) {
			trie[index] = 0;
		}
		else {
			trie[index] = nodes[trie[nodes[index].parent]].next[nodes[index].data];
		}
		for (i = 0; i < 26; i++) {
			int nextindex = nodes[index].next[i];
			if (nextindex != 0) {
				q.push(nextindex);
			}
			else {
				nodes[index].next[i] = nodes[trie[index]].next[i];
			}
		}
	}
}
char *search()
{
	int i = 0, index = 0;
	int pos;

	while (word[i] != 0) {
		pos = word[i] - 'a';
		if (nodes[index].flag == true) {
			return "YES";
		}
		index = nodes[index].next[pos];
		i++;
	}
	if (nodes[index].flag == true) {
		return "YES";
	}
	return "NO";
}

int main()
{
	int n;
#ifdef DEBUG
	FILE *file = fopen("input.txt", "r");
#endif

	myscanf(file, "%d", &n);
	while (n--) {
		myscanf(file, "%s", word);
		insert();
	}
	createGraph();
	myscanf(file, "%s", word);
	printf("%s\n", search());

#ifdef DEBUG
	fclose(file);
	system("pause");
#endif
	return 0;
}
#endif