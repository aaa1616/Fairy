#include "ftaray.h"

int ftInit2DArray(void ***parray, int row, int col, int size)
{
	void * tdarray = NULL;
	if ((tdarray = ftMalloc(row * col * size)) == NULL) {
		return OUTOFMEM_STATUS;
	}

	return SUCCESS_STATUS;
}
int ftFree2DArray(void ***parray)
{
	return SUCCESS_STATUS;
}