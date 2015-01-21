#pragma once

#ifndef _FTINCLIB_H
#define _FTINCLIB_H

#include <stdio.h>

#include "ftmem.h"
#include "ftmath.h"
#include "ftaray.h"

#define DEBUG_TRACE

#ifdef DEBUG_TRACE
#define Trace(fmt, ...)	fprintf(stdout, fmt, ##__VA_ARGS__)
#else
#define	Trace(fmt, ...)
#endif

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
#define ftContainerOf(ptr, type, member) ({ \
	const __typeof(((type *)0)->member) *__mptr = (ptr);	\
	(type *)((char *)__mptr - ftOffsetOf(type, member)); \
})
#define ftOffsetOf(TYPE, MEMBER) ((size_t) &((TYPE *)0->MEMBER))

#endif