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
	LISTHEAD node;
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
static void __del_mem_info(void *memblock);

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
static void __del_mem_info(void *memblock)
{
	MUTEX_LOCK(leakCtx.gCs);
	MEMLEAK *pos;
	ftListForEachEntry(pos, MEMLEAK, &leakHead, node) {
		if (memblock == pos->meminfo.address) {
			ftListDelInit(&pos->node);
			free(pos);
			break;
		}
	}
	leakCtx.num--;
	assert(leakCtx.num >= 0);
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
		__add_mem_info(desSource, strlen(desSource) + 1, file, line);
	}
	return desSource;
}
void xfree(void *memblock)
{
	__del_mem_info(memblock);
	free(memblock);
}
int ld_hex_printout(char *out_buf,const char *buf, size_t len,int wide)
{
	int i, j;
	int ret     = 0;
	int nLines  = 0;
	const char hex_char[] = "0123456789ABCDEF";
	const unsigned char *ptr = buf;
	char *dst  = out_buf;
	nLines = (len + 0x0f) >> 4;
	for (i = 0; i < nLines; i++)
	{
		int nbytes = ((int)len < wide) ? len : wide;
		*dst++ = ' ';
		*dst++ = ' ';
		*dst++ = ' ';
		*dst++ = ' ';
		for (j = 0; j < nbytes; j++)
		{
			unsigned char ival = *ptr++;
			*dst++ = hex_char[(ival >> 4) & 0x0F];
			*dst++ = hex_char[ival & 0x0F];
			*dst++ = ' ';
		}
		for (j = 0; j < wide - nbytes + 1; j++)
		{
			*dst++ = ' ';
			*dst++ = ' ';
			*dst++ = ' ';
		}
		ptr -= nbytes;
		for (j = 0; j < nbytes; j++)
		{
			if ((*ptr >= 0x20) && (*ptr <= 0x7e))
			{
				*dst = *ptr;
			}
			else
			{
				*dst = '.';
			}
			ptr++;
			dst++;
		}
		*dst++ = '\n';
		len -= nbytes;
	}
	*dst++ = 0;
	return ret;
}
void ftReportMem(void)
{
	fprintf(stdout, "Memory Leak Summary\n");
	fprintf(stdout, "==============================================================================\n");
	fprintf(stdout, "Leak total : %d bytes, max used : %d bytes, once max : %d bytes\n", leakCtx.total, leakCtx.usedMax, leakCtx.onceMax);
	fprintf(stdout, "------------------------------------------------------------------------------\n");
	MEMLEAK *pos;
	char info[1024];
	size_t printSize;
	ftListForEachEntry(pos, MEMLEAK, &leakHead, node) {
		fprintf(stdout, "Address : 0x%08x, size : %d bytes\n", pos->meminfo.address, pos->meminfo.size);
		fprintf(stdout, "File : %s, line : %d\n", pos->meminfo.file, pos->meminfo.line);
		printSize = pos->meminfo.size > 64 ? 64 : pos->meminfo.size;
		//ld_hex_printout(info, pos->meminfo.address, printSize, 16);
		//fprintf(stdout, "%s\n", info);
		fprintf(stdout, "------------------------------------------------------------------------------\n");
	}
	fprintf(stdout, "==============================================================================\n");
	MUTEX_DESTROY(leakCtx.gCs);
}
