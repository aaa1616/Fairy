//#define _MS_1
#ifdef _MS_1

#include <iostream>
#include <string>
#include <map>
#include <string.h>
using namespace std;

#define L 102

#define DEBUG

#ifdef DEBUG
#define myscanf(file, fmt, ...) fscanf(file, fmt, ##__VA_ARGS__)
#else
#define myscanf(file, fmt, ...) scanf(fmt, ##__VA_ARGS__)
#endif // DEBUG

#ifndef INT_MAX
#define INT_MAX 2000000000
#endif
#ifndef INT_MIN
#define INT_MIN -2000000000
#endif

int cmp(void const *a, void const *b)
{
	return (*(char *)a) - (*(char *)b);
}

int main(void)
{
	char hashmap[256];
	int len, i, count, fa = 0, fb = 1, j;
	char lastchar, sclastchar = 0;
	char str[L], ret[L];
	map<string, int> retmap;
	retmap.clear();
#ifdef DEBUG
	FILE *file = fopen("input.txt", "r");
#endif
	myscanf(file, "%s", str);
	len = strlen(str);
	//qsort(str, len, sizeof(char), cmp);
	for (i = 0; i < len; i++) {
		//lastchar = str[i];
		count = 0;
		fa = fb = 1;
		memset(hashmap, 0, sizeof(hashmap));
		for (j = i; j < len; j++) {
			if (hashmap[str[j]] == 0) {
				//lastchar = str[j];
				count++;
				hashmap[str[j]] = 1;
			}
			if (count == fb) {
				memcpy(ret, str + i, (j - i + 1) * sizeof(char));
				ret[j - i + 1] = 0;
				string s(ret);
				retmap.insert(map<string, int>::value_type(s, 1));
			}
			else {
				int temp = fa + fb;
				if (count == temp) {
					memcpy(ret, str + i, (j - i + 1) * sizeof(char));
					ret[j - i + 1] = 0;
					string s(ret);
					retmap.insert(map<string, int>::value_type(s, 1));
					fa = fb;
					fb = temp;
				}
			}
		}
	}
	map<string, int>::iterator it;
	for (it = retmap.begin(); it != retmap.end(); it++) {
		cout << it->first << endl;
	}


#ifdef DEBUG
	fclose(file);
	system("pause");
#endif
	return 0;
}

#endif // _MS_1

