#include "ftinclib.h"

int main(void)
{
	void *memblock = ftMalloc(100);
	ftFree(memblock);
	ftReportMem();
	system("pause");
}