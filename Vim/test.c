#include "ftinclib.h"
#include <time.h>
#include <io.h>
#include "largetnum.h"

struct Test {
	int a;
};

int main(void)
{
	//int i = 10000000;
	//clock_t a, b;
	//a = clock();
	//size_t con =23;
	//size_t n = con, val;
	//while (i--) {
	//	n *= con;
	//	val = i;
	//	//n <<= 30;
	//}
	//b = clock();
	//ftTrace("val : %u, time : %lf\n", n, (double)(b - a) / CLOCKS_PER_SEC);
	//char * dir = "E:\\aidl\\*.*";
	//long handle;
	//struct _finddata_t fileinfo;
	//handle = _findfirst(dir, &fileinfo);
	//int total = 0;
	//if (handle != -1) {
	//	while (!_findnext(handle, &fileinfo)) {
	//		char filePath[256] = "E:\\aidl\\";
	//		strcat(filePath, fileinfo.name);
	//		FILE *file = fopen(filePath, "r");
	//		if (file != NULL) {
	//			if (parseAidl(file) != 0) {
	//				total++;
	//				printf("%s\n", filePath);
	//			}
	//		}
	//	}
	//}
	//printf("Total:%d\n", total);
	//_findclose(handle);
	char str[] = "a";
	char *s = longestPalindrome(str);
	system("pause");
}