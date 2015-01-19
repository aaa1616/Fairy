#include "ftmem.h"

typedef struct _MEMINFO {
	void *address;
	size_t size;
	char *file;
	size_t line;
}MEMINFO;

typedef struct _MEMLEAK {
	MEMINFO meminfo;
	struct _MEMLEAK *next;
}MEMLEAK;

void *xmalloc(size_t size, const char *file, size_t line)
{
	void *ptr = malloc(size);
	if (ptr != NULL) {

	}
	return ptr;
}
void *xcalloc(size_t num, size_t size, const char *file, size_t line)
{
	void *ptr = calloc(num, size);
	if (ptr != NULL) {

	}
	return ptr;
}
char *xstrdup(const char *strSource, const char * file, size_t line)
{
	char *desSource = strdup(strSource);
	if (desSource != NULL) {

	}
	return desSource;
}
void xfree(void *memblock)
{
	free(memblock);
}
