#include "ftinclib.h"
#include <time.h>
#include <io.h>
#include "aidl.h"

struct Test {
	int a;
};
#define FILE_ITEM 200
#define FUNC_ITEM 100
#define BUFF_SIZE 200

//char aidl_table[200][100][200];
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
	FILE *file =fopen("E:\\aidl\\filelist", "r");
	char filelist[500][100];
	int i = sizeof(filelist);
	memset(filelist, 0, 500 * 100 * sizeof(char));
	if (file != NULL) {
		getAidlFilename(file, filelist);
	}

	//printf("%s\n", aidl_table[s->id][1]);
	divide(INT_MAX, 1);

	system("pause");
}