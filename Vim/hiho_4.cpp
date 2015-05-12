//#define _HIHO_4
#ifdef _HIHO_4
#include <cstdio>
#include <queue>

using namespace std;

#define L 100

#define DEBUG

#ifdef DEBUG
#define myscanf(file, fmt, ...) fscanf(file, fmt, ##__VA_ARGS__)
#else
#define myscanf(file, fmt, ...) scanf(fmt, ##__VA_ARGS__)
#endif // DEBUG

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
			if (nodes[trie[index]].flag == true) {
				nodes[index].flag = true;
			}
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
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

//#define L 1000005
//
//char buff[L];
//
//struct trie_node {
//	char ch;
//	char is_end;
//	struct trie_node *child;
//	struct trie_node *sibling;
//	struct trie_node *next;
//};
//
//struct trie_node *dict;
//
//struct trie_node *new_node(char ch)
//{
//	struct trie_node *node = (struct trie_node *) malloc(sizeof(struct trie_node));
//	node->ch = ch;
//	node->is_end = 0;
//	node->child = NULL;
//	node->sibling = NULL;
//	return node;
//}
//
//struct trie_node *find_sub(struct trie_node *root, char ch)
//{
//	struct trie_node *m;
//	for (m = root->child; m != NULL && m->ch != ch; m = m->sibling)
//		;
//	return m;
//}
//
//struct trie_node *insert_ch(char ch, struct trie_node *root)
//{
//	struct trie_node *m;
//	m = find_sub(root, ch);
//	if (m == NULL) {
//		m = new_node(ch);
//		m->sibling = root->child;
//		root->child = m;
//	}
//	return m;
//}
//
//void freeall(struct trie_node *root)
//{
//	struct trie_node *p, *q;
//	for (p = root->child; p; p = q) {
//		q = p->sibling;
//		free(p);
//	}
//	free(root);
//}
//
//void add_word(char *s)
//{
//	struct trie_node *m, *cur, *matched;
//
//	if (*s == '\0') return;
//
//	/* Add the first charactor. */
//	cur = insert_ch(*s++, dict);
//	cur->next = dict;
//	/* Then match itself. */
//	matched = dict;
//	while (*s != '\0') {
//		cur = insert_ch(*s++, cur);
//
//		m = NULL;
//		while (matched != dict && m == NULL) {
//			m = find_sub(matched, cur->ch);
//			if (m == NULL)
//				matched = matched->next;
//		}
//		if (m == NULL)
//			m = find_sub(matched, cur->ch);
//		if (m != NULL && m->ch == cur->ch)
//			matched = m;
//		cur->next = matched;
//	}
//	cur->is_end = 1;
//}
//
//void search(char *s)
//{
//	struct trie_node *matched, *m;
//	char ch;
//	matched = dict;
//	while ((ch = *s++) != '\0') {
//		m = NULL;
//		while (matched != dict && m == NULL) {
//			m = find_sub(matched, ch);
//			if (m == NULL)
//				matched = matched->next;
//		}
//		if (m == NULL)
//			m = find_sub(matched, ch);
//		if (m != NULL && m->ch == ch) {
//			matched = m;
//			if (m->is_end) {
//				printf("YES\n");
//				return;
//			}
//		}
//	}
//	printf("NO\n");
//}

//int main()
//{
//	int n, len;
//	char *s;
//#ifdef DEBUG
//	FILE *file = fopen("input.txt", "r");
//#endif
//	dict = new_node(0);
//	myscanf(file, "%d", &n);
//	s = buff;
//	while (n-- > 0) {
//		myscanf(file, "%s", s);
//		add_word(s);
//		s += strlen(s);
//	}
//	myscanf(file, "%s", buff);
//	search(buff);
//	freeall(dict);
//#ifdef DEBUG
//	fclose(file);
//	system("pause");
//#endif
//	return 0;
//}


int main()
{
	int a[10][10];
	a[0][0] = 123;
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