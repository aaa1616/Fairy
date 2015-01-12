#include "ftinclib.h"

int main()
{
	ftCreate2DArray(int, a);
	ftInit2DArray(&a, 3, 4, sizeof(int));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = i * 3 + j;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			Trace("a[%d][%d] = %d\n", i, j, a[i][j]);
		}
	}

	return 0;
}