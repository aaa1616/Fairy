#ifndef  _FTLIST_H
#define _FTLIST_H

#define LIST_POISON1 ((void *) 0x00100100)
#define LIST_POISON2 ((void *) 0x00200200)


typedef struct _LISTHEAD {
	struct _LISTHEAD *next, *prev;
}LISTHEAD;

#define ftListInit(name) {&(name), &(name)}
#define ftListHead(name) LISTHEAD name = ftListInit(name)
static inline void __init_list_head(LISTHEAD *list)
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
static inline void __list_add(LISTHEAD *node, LISTHEAD *prev, LISTHEAD *next)
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
static inline void __list_del(LISTHEAD *prev, LISTHEAD *next)
{
	next->prev = prev;
	prev->next = next;
}
static inline void __list_del_entry(LISTHEAD *node)
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
static inline void ftListAdd(LISTHEAD *node, LISTHEAD *head)
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
static inline void ftListAddTail(LISTHEAD *node, LISTHEAD *head)
{
	__list_add(node, head->prev, head);
}
static inline void ftListDelInit(LISTHEAD *node)
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
static inline void __list_replace(LISTHEAD *oldnode, LISTHEAD *newnode)
{
	newnode->prev = oldnode->prev;
	newnode->prev->next = newnode;
	newnode->next = oldnode->next;
	newnode->next->prev = newnode;
}
static inline void ftListReplaceInit(LISTHEAD *oldnode, LISTHEAD *newnode)
{
	__list_replace(oldnode, newnode);
	__init_list_head(oldnode);
}
static inline void ftListMove(LISTHEAD *node, LISTHEAD *head)
{
	__list_del_entry(node);
	ftListAdd(node, head);
}
static inline void ftListMoveTail(LISTHEAD *node, LISTHEAD *head)
{
	__list_del_entry(node);
	ftListAddTail(node, head);
}
/**
 * list_is_last - tests whether @list is the last entry in list @head
 * @list: the entry to test
 * @head: the head of the list
 */
static inline int ftListIsLast(const LISTHEAD *list, const LISTHEAD *head)
{
	return list->next == head;
}
/**
 * list_is_singular - tests whether a list has just one entry.
 * @head: the list to test.
 */
static inline int ftListIsSingular(const LISTHEAD *head)
{
	return !ftListEmpty(head) && (head->next == head->prev);
}
/**
 * list_empty - tests whether a list is empty
 * @head: the list to test.
 */
static inline int ftListEmpty(const LISTHEAD *head)
{
	return head->next == head;
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
#define ftListLastEntry(ptr, type, member) list_entry((ptr)->prev, type, member)
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
#define ftListNextEntry(pos, member) \
	ftListEntry((pos)->member.next, __typeof(*(pos), member)
/**
 * list_prev_entry - get the prev element in list
 * @pos:        the type * to cursor
 * @member:     the name of the list_struct within the struct.
 */
#define ftListPrevEntry(pos, member) \
	ftListEntry((pos)->member.prev, __typeof(*(pos)), member)
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
#define ftListForEachEntry(pos, head, member) \
	for (pos = ftListFristEntry(head, __typeof(*pos), member); &pos->member != (head); pos = ftListNextEntry(pos, member))
/**
 * list_for_each_entry_reverse - iterate backwards over list of given type.
 * @pos:        the type * to use as a loop cursor.
 * @head:       the head for your list.
 * @member:     the name of the list_struct within the struct.
 */
#define ftListForEachEntryReverse(pos, head, member) \
	for (pos = ftListLastEntry(head, __typeof(*pos), member); &pos->member != (head); pos = ftListLastEntry(pos, member))
/**
 * list_for_each_entry_safe - iterate over list of given type safe against removal of list entry
 * @pos:        the type * to use as a loop cursor.
 * @n:          another type * to use as temporary storage
 * @head:       the head for your list.
 * @member:     the name of the list_struct within the struct.
 */
#define ftListForEachEntrySafe(pos, head, member) \
	for (pos = ftListFristEntry(head, __typeof(*pos), member), n = ftListNextEntry(pos, member); &pos->member != (head); pos = n, n = ftListNextEntry(pos, member))
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
#define ftListForEachEntryReverseSafe(pos, head, member) \
	for (pos = ftListLastEntry(head, __typeof(*pos), member), n = ftListPrevEntry(pos, member); &pos->member != (head); pos = n, n = ftListLastEntry(pos, member))


#endif