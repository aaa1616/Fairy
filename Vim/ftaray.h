#ifndef _FTARRAY_H
#define _FTARRAY_H

#include "ftinclib.h"

#define ftCreate2DArray(type, name) type **name = NULL

int ftInit2DArray(void ***parray, int row, int col, int size);
int ftFree2DArray(void ***parray);

#endif