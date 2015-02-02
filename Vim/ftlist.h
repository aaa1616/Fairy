#ifndef  _FTLIST_H
#define _FTLIST_H

#include "ftdef.h"

#define LIST_POISON1 ((void *) 0x00100100)
#define LIST_POISON2 ((void *) 0x00200200)

typedef struct _LISTHEAD {
	struct _LISTHEAD *next, *prev;
}LISTHEAD;
typedef struct _HLISTHEAD {
	struct _HLISTHEAD *first;
}HLISTHEAD;
typedef struct _HLISTNODE {
	struct _HLISTNODE *next, **pprev;
}HLISTNODE;

#define ftListInit(name) {&(name), &(name)}
#define ftListHead(name) LISTHEAD name = ftListInit(name)
static __inline void __init_list_head(LISTHEAD *list)
{
	list->next = list;
	list->prev = list;
}
/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static __inline void __list_add(LISTHEAD *node, LISTHEAD *prev, LISTHEAD *next)
{
	prev->next = node;
	node->prev = prev;
	next->prev = node;
	node->next = next;
}
/*
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static __inline void __list_del(LISTHEAD *prev, LISTHEAD *next)
{
	next->prev = prev;
	prev->next = next;
}
static __inline void __list_del_entry(LISTHEAD *node)
{
	__list_del(node->prev, node->next);
	node->prev = (LISTHEAD *)LIST_POISON1;
	node->next = (LISTHEAD *)LIST_POISON2;
}
/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
static __inline void ftListAdd(LISTHEAD *node, LISTHEAD *head)
{
	__list_add(node, head, head->next);
}
/**
 * list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
static __inline void ftListAddTail(LISTHEAD *node, LISTHEAD *head)
{
	__list_add(node, head->prev, head);
}
static __inline void ftListDelInit(LISTHEAD *node)
{
	__list_del_entry(node);
	__init_list_head(node);
}
/**
 * list_replace - replace old entry by new one
 * @old : the element to be replaced
 * @new : the new element to insert
 *
 * If @old was empty, it will be overwritten.
 */
static __inline void __list_replace(LISTHEAD *oldnode, LISTHEAD *newnode)
{
	newnode->prev = oldnode->prev;
	newnode->prev->next = newnode;
	newnode->next = oldnode->next;
	newnode->next->prev = newnode;
}
static __inline void ftListReplaceInit(LISTHEAD *oldnode, LISTHEAD *newnode)
{
	__list_replace(oldnode, newnode);
	__init_list_head(oldnode);
}
static __inline void ftListMove(LISTHEAD *node, LISTHEAD *head)
{
	__list_del_entry(node);
	ftListAdd(node, head);
}
static __inline void ftListMoveTail(LISTHEAD *node, LISTHEAD *head)
{
	__list_del_entry(node);
	ftListAddTail(node, head);
}
/**
 * list_is_last - tests whether @list is the last entry in list @head
 * @list: the entry to test
 * @head: the head of the list
 */
static __inline int ftListIsLast(const LISTHEAD *list, const LISTHEAD *head)
{
	return list->next == head;
}
/**
 * list_empty - tests whether a list is empty
 * @head: the list to test.
 */
static __inline int ftListEmpty(const LISTHEAD *head)
{
	return head->next == head;
}
/**
 * list_is_singular - tests whether a list has just one entry.
 * @head: the list to test.
 */
static __inline int ftListIsSingular(const LISTHEAD *head)
{
	return !ftListEmpty(head) && (head->next == head->prev);
}
/**
 * list_entry - get the struct for this entry
 * @ptr:        the &struct list_head pointer.
 * @type:       the type of the struct this is embedded in.
 * @member:     the name of the list_struct within the struct.
 */
#define ftListEntry(ptr, type, member) ftContainerOf(ptr, type, member)
/**
 * list_first_entry - get the first element from a list
 * @ptr:        the list head to take the element from.
 * @type:       the type of the struct this is embedded in.
 * @member:     the name of the list_struct within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define ftListFirstEntry(ptr, type, member) ftListEntry((ptr)->next, type, member)
/**
 * list_last_entry - get the last element from a list
 * @ptr:        the list head to take the element from.
 * @type:       the type of the struct this is embedded in.
 * @member:     the name of the list_struct within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define ftListLastEntry(ptr, type, member) ftListEntry((ptr)->prev, type, member)
/**
 * list_first_entry_or_null - get the first element from a list
 * @ptr:        the list head to take the element from.
 * @type:       the type of the struct this is embedded in.
 * @member:     the name of the list_struct within the struct.
 *
 * Note that if the list is empty, it returns NULL.
 */
#define ftListFirstEntryOrNull(ptr, type, memeber) \
	(!ftListEmpty(ptr) ? ftListFirstEntry(ptr, type, member) : NULL)
/**
 * list_next_entry - get the next element in list
 * @pos:        the type * to cursor
 * @member:     the name of the list_struct within the struct.
 */
#define ftListNextEntry(pos, type, member) \
	ftListEntry((pos)->member.next, type, member)
/**
 * list_prev_entry - get the prev element in list
 * @pos:        the type * to cursor
 * @member:     the name of the list_struct within the struct.
 */
#define ftListPrevEntry(pos, type, member) \
	ftListEntry((pos)->member.prev, type, member)
/**
 * list_for_each        -       iterate over a list
 * @pos:        the &struct list_head to use as a loop cursor.
 * @head:       the head for your list.
 */
#define ftListForEach(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)
/**
 * list_for_each_prev   -       iterate over a list
 * @pos:        the &struct list_head to use as a loop cursor.
 * @head:       the head for your list.
 */
#define ftListForEachPrev(pos, head) \
	for (pos = (head)->prev; pos != (head); pos = pos->prev)
/**
 * list_for_each_safe - iterate over a list safe against removal of list entry
 * @pos:        the &struct list_head to use as a loop cursor.
 * @n:          another &struct list_head to use as temporary storage
 * @head:       the head for your list.
 */
#define ftListForEachSafe(pos, n, head) \
	for (pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)
/**
 * list_for_each_prev_safe - iterate over a list backwards safe against removal of list entry
 * @pos:        the &struct list_head to use as a loop cursor.
 * @n:          another &struct list_head to use as temporary storage
 * @head:       the head for your list.
 */
#define ftListForEachPrevSafe(pos, n, head) \
	for (pos = (head)->prev, n = pos->prev; pos != (head); pos = n, n = pos->prev)
/**
 * list_for_each_entry  -       iterate over list of given type
 * @pos:        the type * to use as a loop cursor.
 * @head:       the head for your list.
 * @member:     the name of the list_struct within the struct.
 */
#define ftListForEachEntry(pos, type, head, member) \
	for (pos = ftListFirstEntry(head, type, member); &pos->member != (head); pos = ftListNextEntry(pos, type, member))
/**
 * list_for_each_entry_reverse - iterate backwards over list of given type.
 * @pos:        the type * to use as a loop cursor.
 * @head:       the head for your list.
 * @member:     the name of the list_struct within the struct.
 */
#define ftListForEachEntryReverse(pos, type, head, member) \
	for (pos = ftListLastEntry(head, type, member); &pos->member != (head); pos = ftListLastEntry(pos, type, member))
/**
 * list_for_each_entry_safe - iterate over list of given type safe against removal of list entry
 * @pos:        the type * to use as a loop cursor.
 * @n:          another type * to use as temporary storage
 * @head:       the head for your list.
 * @member:     the name of the list_struct within the struct.
 */
#define ftListForEachEntrySafe(pos, type, head, member) \
	for (pos = ftListFirstEntry(head, type, member), n = ftListNextEntry(pos, type, member); &pos->member != (head); pos = n, n = ftListNextEntry(pos, type, member))
/**
 * list_for_each_entry_safe_reverse - iterate backwards over list safe against removal
 * @pos:        the type * to use as a loop cursor.
 * @n:          another type * to use as temporary storage
 * @head:       the head for your list.
 * @member:     the name of the list_struct within the struct.
 *
 * Iterate backwards over list of given type, safe against removal
 * of list entry.
 */
#define ftListForEachEntryReverseSafe(pos, type, head, member) \
	for (pos = ftListLastEntry(head, type, member), n = ftListPrevEntry(pos, type, member); &pos->member != (head); pos = n, n = ftListLastEntry(pos, type, member))

/*
 * Double linked lists with a single pointer list head.
 * Mostly useful for hash tables where the two pointer list head is
 * too wasteful.
 * You lose the ability to access the tail in O(1).
 */
#define ftHListInit	{ .first = NULL}
#define ftHListHead(name) HLISTHEAD name = ftHListInit
#define ftHListInitHead(ptr) ((ptr)->first = NULL)
static __inline void __init_hlist_node(HLISTNODE *node)
{
	node->next = NULL;
	node->pprev = NULL;
}
static __inline int ftHListUnHashed(HLISTNODE *node)
{
	return !node->pprev;
}
static __inline int ftHListEmpty(HLISTHEAD *head)
{
	return !head->first;
}
static __inline void __hlist_del(HLISTNODE *node)
{
	*(node->pprev) = node->next;
	if (node->next) {
		node->next->pprev = node->pprev;
	}
}
static __inline void __hlist_del_entry(HLISTNODE *node)
{
	__hlist_del(node);
	node->next = LIST_POISON1;
	node->pprev = LIST_POISON2;
}
static _inline void ftHListDelInit(HLISTNODE *node)
{
	if (!ftHListUnHashed(node)) {
		__hlist_del_entry(node);
		__init_hlist_node(node);
	}
}
static __inline void ftHListAddHead(HLISTHEAD *head, HLISTNODE *node)
{
	HLISTNODE *first = head->first;
	node->next = first;
	if (first) {
		first->pprev = &node->next;
	}
	head->first = node;
	node->pprev = &head->first;
}
/* next must be != NULL */
static __inline void ftHListAddBefore(HLISTNODE *node, HLISTNODE *next)
{
	node->pprev = next->pprev;
	node->next = next;
	*node->pprev = node;
	next->pprev = &node->next;
}
static __inline void ftHListAddBehind(HLISTNODE *node, HLISTNODE *prev)
{
	node->next = prev->next;
	prev->next = node;
	node->pprev = &prev->next;
	if (node->next) {
		node->next->pprev = &node->next;
	}
}
#define ftHListEntry(ptr, type, member) ftListEntry(ptr, type, member)
#define ftHListEntrySafe(ptr, type, member) \
	(ptr ? ftHListEntry(ptr, type, member) : NULL)
#define ftHListForEach(pos, head) \
	for (pos = (head)->first ; pos ; pos = pos->next)
#define ftHListForEachSafe(pos, n, head) \
	for (pos = (head)->first ; pos && ({n = pos->next; 1;}) ; pos = n)
#define ftHListForEachEntry(pos, type, head, member) \
	for (pos = ftHListEntrySafe((head)->first, type, member) ; pos ; pos = ftHListEntrySafe(pos->member.next, type, member))
#define ftHListForEachEntrySafe(pos, n, type, head, member) \
	for (pos = ftHListEntrySafe((head)->first, type, member) ; \
		pos && ({n = pos->member.next ; 1;}) ; \
		pos = ftHListEntrySafe(n, type, member))
#endif