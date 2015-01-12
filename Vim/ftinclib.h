#pragma once

#ifndef _FTINCLIB_H
#define _FTINCLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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

#endif