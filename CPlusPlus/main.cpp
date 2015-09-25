#include <stdio.h>
#include <iostream>
#include <vector>

#include "Source.h"

typedef int (*func)(int *, int);

int f2(int*,  int)
{
	return 0;
}

func f1 = &f2;

void userBigger(const string &, const string &, bool(const string &, const string &))
{

}

int main()
{
	int a;
	vector<Sales_item> bad(10);
	for (vector<Sales_item>::iterator iter = bad.begin; iter != bad.end(); iter++) {
		cout << iter->units_sold << endl;
	}

	return 0;
}