#ifndef _AIDL_H
#define _AIDL_H

#include "ftinclib.h"
#include "uthash.h"

struct my_struct {
	char key[100];
	int id;
	UT_hash_handle hh;
};
extern struct my_struct *fnHash;

void getAidlFilename(FILE *file, char filelist[][100]);
int parseAidl(FILE *file, char *filename, int id, char ***aidl_table);

#endif