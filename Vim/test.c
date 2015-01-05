#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
	//int a[4][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
	int *a = malloc(sizeof(int)* 4 * 3);
	
	for (int i = 0; i < 3; i++) {
		fprintf(stdout, "a[%d] : %x, %x", i, a + i, *(a + i));
		for (int j = 0; j < 4; j++) {
			a[i][j] = i * 4 + j + 1;
		}
	}
	return 0;
}