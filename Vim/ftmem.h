#ifndef _FTMEM_H
#define _FTMEM_H

#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void *xmalloc(size_t size, const char *file, size_t line);
void *xcalloc(size_t num, size_t size, const char *file, size_t line);
char *xstrdup (const char *strSource, const char *file, size_t line);
void xfree(void *memblock);

#define ftMalloc(size) xmalloc(size, __FILE__, __LINE__)
#define ftCalloc(num, size) xcalloc(num, size, __FILE__, __LINE__)
#define ftStrdup(strSource) xstrdup(strSource, __FILE__, __LINE__)
#define ftFree(memblock) xfree(memblock)

#endif