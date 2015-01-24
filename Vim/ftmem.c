#include "ftmem.h"

#define FILE_NAME_LENGTH 256

#if defined(WIN32)

#include <windows.h>
typedef CRITICAL_SECTION mutex_handle_t;
#define MUTEX_CREATE(handle) 	InitializeCriticalSection(&handle)
#define MUTEX_LOCK(handle) 		EnterCriticalSection(&handle)
#define MUTEX_UNLOCK(handle) 	LeaveCriticalSection(&handle)
#define MUTEX_DESTROY(handle)	DeleteCriticalSection(&handle)

#else 

#include <pthread.h>
typedef pthread_mutex_t mutex_handle_t;
#define MUTEX_CREATE(handle) pthread_mutex_init(&(handle), NULL)
#define MUTEX_LOCK(handle) pthread_mutex_lock(&(handle))
#define MUTEX_UNLOCK(handle) pthread_mutex_unlock(&(handle))
#define MUTEX_DESTROY(handle) pthread_mutex_destroy(&(handle))

#endif

typedef struct _MEMINFO {
	void *address;
	size_t size;
	char file[FILE_NAME_LENGTH];
	size_t line;
}MEMINFO;

typedef struct _MEMLEAK {
	MEMINFO meminfo;
	LISTHEAD node
}MEMLEAK;

typedef struct _MEMLEAK_CTX{
	size_t num;
	size_t onceMax;
	size_t total;
	size_t usedMax;
	mutex_handle_t gCs;
	int isFirst;
}MEMLEAK_CTX;

static ftListHead(leakHead);
static MEMLEAK_CTX leakCtx = { 0 };

static void __add(MEMINFO allocInfo);
static void __add_mem_info(void *memblock, size_t size, const char *file, size_t line);

static void __add(MEMINFO allocInfo) {
	MEMLEAK *memleak;
	memleak = (MEMLEAK *)malloc(sizeof(MEMLEAK));
	memcpy(&memleak->meminfo, &allocInfo, sizeof(MEMINFO));
	ftListAdd(&memleak->node, &leakHead);
	leakCtx.total += allocInfo.size;
	if (leakCtx.total > leakCtx.usedMax) {
		leakCtx.usedMax = leakCtx.total;
	}
	if (leakCtx.onceMax < allocInfo.size) {
		leakCtx.onceMax = allocInfo.size;
	}
	leakCtx.num++;
}
static void __add_mem_info(void *memblock, size_t size, const char *file, size_t line){
	if (leakCtx.isFirst == 0) {
		MUTEX_CREATE(leakCtx.gCs);
		leakCtx.isFirst++;
		assert(leakCtx.isFirst == 1);
	}
	MEMINFO allocInfo;
	memset(&allocInfo, 0, sizeof(MEMINFO));
	allocInfo.address = memblock;
	allocInfo.size = size;
	allocInfo.line = line;
	strncpy(&allocInfo.file, file, FILE_NAME_LENGTH);
	MUTEX_LOCK(leakCtx.gCs);
	__add(allocInfo);
	MUTEX_UNLOCK(leakCtx.gCs);
}

void *xmalloc(size_t size, const char *file, size_t line)
{
	void *ptr = malloc(size);
	if (ptr != NULL) {
		__add_mem_info(ptr, size, file, line);
	}
	return ptr;
}
void *xcalloc(size_t num, size_t size, const char *file, size_t line)
{
	void *ptr = calloc(num, size);
	if (ptr != NULL) {
		__add_mem_info(ptr, num * size, file, line);
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
