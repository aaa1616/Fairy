#ifndef _FTMACRO_H
#define _FTMACRO_H

#define DEBUG_TRACE

#ifdef DEBUG_TRACE
#define ftTrace(fmt, ...)	fprintf(stdout, fmt, ##__VA_ARGS__)
#else
#define	Trace(fmt, ...)
#endif

#define myscanf(file, fmt, ...) fscanf(file, fmt, ##__VA_ARGS__)

#define SUCCESS_STATUS 0
#define FAILUTRE_STATUS -1
#define OUTOFMEM_STATUS 1

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:        the pointer to the member.
 * @type:       the type of the container struct this is embedded in.
 * @member:     the name of the member within the struct.
 *
 */
#define ftContainerOf(ptr, type, member) \
	((type *)((char *)ptr - ftOffsetOf(type, member)))
#define ftOffsetOf(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define ftArraySize(arr) (sizeof(arr) / sizeof((arr)[0]))

#endif