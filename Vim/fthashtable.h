#ifndef _FTHASHTABLE_H
#define _FTHASHTABLE_H

#include <math.h>
#include <ddkernel.h>

#include "ftdef.h"
#include "ftlist.h"
#include "ftmath.h"

#define ftHashTableDefine(name, bits) HLISTHEAD name[1 << (bits)] = {0}
#define ftHashTableDeclare(name, bits) HLISTHEAD name[1 << (bits)]
#define ftHashSize(name) (ftArraySize(name))
#define ftHashBits(name) ((size_t)log2(ftHashSize(name)))
#define ftHashMin(val, bits) ftHash32(val, bits)

static __inline void __hash_init(HLISTHEAD *ht, size_t size)
{
	int i;
	for (i = 0; i < size; i++) {
		ftHListInitHead(&ht[i]);
	}
}
/**
 * hash_init - initialize a hash table
 * @hashtable: hashtable to be initialized
 *
 * Calculates the size of the hashtable from the given parameter, otherwise
 * same as hash_init_size.
 *
 * This has to be a macro since HASH_BITS() will not work on pointers since
 * it calculates the size during preprocessing.
 */
#define ftHashInit(hashtable) __hash_init(hashtable, ftHashSize(hashtable))
#define ftHashAdd(hashtable, node, key) \
	ftHListAddHead(&hashtable[ftHashMin(key, ftHashBits(hashtable))], node)
#define ftHashDel(node) ftHListDelInit(node)
/**
 * hash_hashed - check whether an object is in any hashtable
 * @node: the &struct hlist_node of the object to be checked
 */
static __inline int ftHashHashed(HLISTNODE *node)
{
	return !ftHListUnHashed(node);
}
static __inline int __hash_empty(HLISTHEAD *ht, size_t size)
{
	int i;
	for (i = 0; i < size; i++) {
		if (!ftHListEmpty(ht)) {
			return false;
		}
	}

	return true;
}
/**
 * hash_empty - check whether a hashtable is empty
 * @hashtable: hashtable to check
 *
 * This has to be a macro since HASH_BITS() will not work on pointers since
 * it calculates the size during preprocessing.
 */
#define ftHashEmpty(hashtable) __hash_empty(hashtable, ftHashSize(hashtable))
/**
 * hash_for_each - iterate over a hashtable
 * @name: hashtable to iterate
 * @bkt: integer to use as bucket loop cursor
 * @obj: the type * to use as a loop cursor for each entry
 * @member: the name of the hlist_node within the struct
 */
#define ftHashForEach(bkt, pos, type, name, member) \
	for ((bkt) = 0, pos = NULL; pos == NULL && (bkt) < ftHashSize(name); (bkt)++) \
		ftHListForEachEntry(pos, type, name, member)
/**
 * hash_for_each_safe - iterate over a hashtable safe against removal of
 * hash entry
 * @name: hashtable to iterate
 * @bkt: integer to use as bucket loop cursor
 * @tmp: a &struct used for temporary storage
 * @obj: the type * to use as a loop cursor for each entry
 * @member: the name of the hlist_node within the struct
 */
#define ftHashForEachSafe(bkt, pos, n, type, name, member) \
	for ((bkt) = 0, pos = NULL; pos == NULL && (bkt) < ftHashSize(name); (bkt)++) \
		ftHListForEachEntrySafe(pos, n, type, name, member)
/**
 * hash_for_each_possible - iterate over all possible objects hashing to the
 * same bucket
 * @name: hashtable to iterate
 * @obj: the type * to use as a loop cursor for each entry
 * @member: the name of the hlist_node within the struct
 * @key: the key of the objects to iterate over
 */
#define ftHashForEachPossible(pos, type, name, member, key) \
	ftHListForEachEntry(pos, type, &name[ftHashMin(key, ftHashBits(name))], member)	
/**
 * hash_for_each_possible_safe - iterate over all possible objects hashing to the
 * same bucket safe against removals
 * @name: hashtable to iterate
 * @obj: the type * to use as a loop cursor for each entry
 * @tmp: a &struct used for temporary storage
 * @member: the name of the hlist_node within the struct
 * @key: the key of the objects to iterate over
 */
#define ftHashForEachPossibleSafe(pos, n, type, name, member, key) \
	ftHListForEachEntry(pos, n, type, &name[ftHashMin(key, ftHashBits(name))], member)	

#endif