#include "ftinclib.h"
#include <time.h>
#include <io.h>
#include "aidl.h"
#include "graph.h"
#include "largetnum.h"
#include "nqueen.h"
#include "largeData.h"

#define FILE_ITEM 200
#define FUNC_ITEM 100
#define BUFF_SIZE 200

//char aidl_table[200][100][200];
void *mymemcpy(void *dest, const void *src, size_t count)
{
         char *tmp = dest;
         const char *s = src;

         while (count--)
 * tmp++ = *s++;
         return dest;
}
static int uniquePaths(int m, int n)
{
	int i, j;
	double sum = 1;
	m = m - 1 + n - 1;
	n--;
	for (i = m, j = n; j >= 1; j--, i--) {
		sum = sum / j * i;
	}
	return round(sum);
}

int main(void)
{
	//char ***aidl_table = malloc(FILE_ITEM * sizeof (char *));
	//char **aidl_table_2d = malloc(FUNC_ITEM * FILE_ITEM * sizeof(char *));
	//char *aidl_table_3d = malloc(FUNC_ITEM * FILE_ITEM * BUFF_SIZE * sizeof(char *));
	//memset(aidl_table_3d, 0, FUNC_ITEM * FILE_ITEM * BUFF_SIZE);
	//for (int i = 0; i < FILE_ITEM; i++) {
	//	aidl_table[i] = aidl_table_2d + i * FUNC_ITEM;
	//}
	//for (int i = 0; i < FUNC_ITEM * FILE_ITEM; i++) {
	//	aidl_table_2d[i] = aidl_table_3d + i * BUFF_SIZE;
	//}
	//char * dir = "E:\\aidl\\*.*";
	//long handle;
	//struct _finddata_t fileinfo;
	//handle = _findfirst(dir, &fileinfo);
	//int total = 0;
	//int func = 0;
	//fnHash = NULL;
	//if (handle != -1) {
	//	while (!_findnext(handle, &fileinfo)) {
	//		char filePath[256] = "E:\\aidl\\";
	//		strcat(filePath, fileinfo.name);
	//		FILE *file = fopen(filePath, "r");
	//		if (file != NULL) {
	//			if ((func = parseAidl(file, fileinfo.name, total, aidl_table)) > 1) {
	//				total++;
	//				//for (int i = 1; i < func; i++) {
	//				//	printf("%s\n",aidl_table[total - 1][i]);
	//				//}
	//				//printf("%s\n", filePath);
	//			}
	//		}
	//	}
	//}
	//char des[100];
	//scanf("%s", des);
	//struct my_struct *s;
	//HASH_FIND_STR(fnHash, des, s);
	//FILE *file =fopen("E:\\aidl\\filelist", "r");
	//char filelist[500][100];
	//int i = sizeof(filelist);
	//memset(filelist, 0, 500 * 100 * sizeof(char));
	//if (file != NULL) {
	//	getAidlFilename(file, filelist);
	//}

	////printf("%s\n", aidl_table[s->id][1]);
	//divide(INT_MAX, 1);
	//GRAPH *g = createGraph();
	//dfs(g);
	//bfs(g, 0);
	//delGraph(g);
	//FILE *file = fopen("input.txt", "r");
	//int n;
	//myscanf(file, "%d", &n);
	//nqueen(n);

	//int num[10];
	//for (int i = 0; i < n; i++) {
	//	myscanf(file, "%d", num + i);
	//}
	//fclose(file);
	//printf("%d\n", selectKth(num, 0, n, 8));
	//int *ret = countSort(num, n, 6);
	//for (int i = 0; i < n; i++) {
	//	printf("%d ", ret[i]);
	//}
	//printf("\n");
	//free(ret);

	//BINTREE *bt = createBinTreeLR();
	//preOrder(bt->root);
	//printf("\n");
	//delBinTree(bt->root);
	//free(bt);
	//struct ListNode one, two;
	//one.next = &two;
	//two.next = NULL;
	//one.val = 1;
	//two.val = 2;
	//rotateRight(&one, 2);
	//uniquePaths(50, 50);
	//int i;
	//char *a[] = { "When", "I", "was", "just", "a", "little", "girl", "I", "asked", "my", "mother", "what", "will", "I", "be", "Will", "I", "be", "pretty", "Will", "I", "be", "rich", "Here's", "what", "she", "said", "to", "me", "Que", "sera", "sera", "Whatever", "will", "be", "will", "be", "The", "future's", "not", "ours", "to", "see", "Que", "sera", "sera", "When", "I", "was", "just", "a", "child", "in", "school", "I", "asked", "my", "teacher", "what", "should", "I", "try", "Should", "I", "paint", "pictures", "Should", "I", "sing", "songs", "This", "was", "her", "wise", "reply", "Que", "sera", "sera", "Whatever", "will", "be", "will", "be", "The", "future's", "not", "ours", "to", "see", "Que", "sera", "sera", "When", "I", "grew", "up", "and", "fell", "in", "love", "I", "asked", "my", "sweetheart", "what", "lies", "ahead", "Will", "there", "be", "rainbows", "day", "after", "day", "Here's", "what", "my", "sweetheart", "said", "Que", "sera", "sera", "Whatever", "will", "be", "will", "be", "The", "future's", "not", "ours", "to", "see", "Que", "sera", "sera", "What", "will", "be,", "will", "be", "Que", "sera", "sera..." };
	//int output = 0;
	//char **ret = fullJustify(a, ftArraySize(a), 61, &output);
	//for (i = 0; i < output; i++) {
	//	printf("%s\n", ret[i]);
	//	free(ret[i]);
	//}
	//free(ret);
	//int returnSize, *columnSize, **ret, i, j;
	//ret = combine(2, 2, &columnSize, &returnSize);
	//for (i = 0; i < returnSize; i++) {
	//	for (j = 0; j < columnSize[i]; j++) {
	//		printf("%d ", ret[i][j]);
	//	}
	//	printf("\n");
	//}
	//char test[] = "123456";
	//mymemcpy(test + 1, test, 4);
	//printf("%s-%s\n", test, test + 1);
	//uniquePaths(5, 5);
//int test[] = {1, 1};
//	struct ListNode head, *prev, *node;
//	prev = &head;
//	for (int i = 0; i < ftArraySize(test); i++) {
//		node = malloc(sizeof(struct ListNode));
//		node->next = NULL;
//		node->val = test[i];
//		prev->next = node;
//		prev = node;
//	}
//	node = partition(head.next, 0);
//
//	for (int i = 0; i < ftArraySize(test); i++) {
//		printf("%d ", node->val);
//		prev = node;
//		node = node->next;
//		free(prev);
//	}
//	printf("\n");
char *s1 = "aa", *s2 = "aa";
int ret = isScramble(s1, s2);

	

	system("pause");
}