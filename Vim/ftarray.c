#include "ftaray.h"

int ftInit2DArray(void ***array, int row, int col, int size)
{
	void ** prow = NULL;
	char * parray = NULL;
	if ((prow = ftMalloc(row * size)) == NULL) {
		return OUTOFMEM_STATUS;
	}

	if ((parray = ftMalloc(row * col * size)) == NULL) {
		ftFree(prow);
		return OUTOFMEM_STATUS;
	}
	
	memset(parray, 0, row * col * size);
	for (int i = 0; i < row; i++) {
		prow[i] = (parray + i * col * size);
	}

	*array = prow;

	return SUCCESS_STATUS;
}
int ftFree2DArray(void ***parray)
{
	ftFree((*parray)[0]);
	ftFree(*parray);
	return SUCCESS_STATUS;
}