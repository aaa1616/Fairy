#include "ftinclib.h"
#include <time.h>
#include "aidl.h"

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
	FILE *file = fopen("INetworkManagementService.aidl", "r");
	if (file != NULL) {
		parseAidl(file);
	}
	system("pause");
}