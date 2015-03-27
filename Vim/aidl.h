#ifndef _AIDL_H
#define _AIDL_H

#include "ftinclib.h"
#include "uthash.h"

struct my_struct {
	char key[100];
	int id;
	UT_hash_handle hh;
};
struct my_struct *fnHash;
int parseAidl(FILE *file, char *filename, int id, char ***aidl_table);

#endif