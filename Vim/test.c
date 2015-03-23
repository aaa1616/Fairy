#include "ftinclib.h"
#include <time.h>
#include "buystock.h"

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
	int prices[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	maxProfit(prices, ftArraySize(prices));
	system("pause");
}