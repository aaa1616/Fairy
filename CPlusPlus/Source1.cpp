#include <stdio.h>

void func1() {
#ifndef _CPRIMER_H
	printf("%d, %s\n", __LINE__, __FILE__);
#endif
}

