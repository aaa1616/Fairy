#ifndef _FTMATH_H
#define _FTINCLIB_H

/* 2^31 + 2^29 - 2^25 + 2^22 - 2^19 - 2^16 + 1 */
#define GOLDEN_RATIO_PRIME_32 0x9e370001UL

#define ftMax(a,b) ((a) > (b) ? (a) : (b))
#define ftAlign(a, b) (((a) + (b - 1)) & ~(b - 1))


static __inline size_t ftHash32(size_t val, size_t bits)
{
	size_t hash = val * GOLDEN_RATIO_PRIME_32;
	return hash >> (32 - bits);
}

#endif