#include <stdio.h>
#include "header2.h"

int name_test;

void func2()
{
	printf("%d\n", gExt);
}

HasPtr & HasPtr::operator=(const HasPtr & rhs)
{
	rhs.ptr->use++;
	if (--ptr->use == 0) {
		delete ptr;
	}
	ptr = rhs.ptr;
	val = rhs.val;
	return *this;
}

HasPtr::~HasPtr()
{
	if (--ptr->use == 0) {
		delete ptr;
	}
}

void func_test()
{
	printf("func_test\n");
}

void normal_func()
{
	global_v++;
	printf("%d\n", global_v);
}

