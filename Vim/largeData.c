#include "largeData.h"

#define MAXNUM 10000
#define RANDOM(a, b) ((a) + (int)((double)rand() * ((b) - (a)) / (RAND_MAX + 1)))

typedef struct _MODULE {
	int k[3];
	int kNum;
	int count;
	int signal;
}MODULE;

static void swap(int *a, int *b)
{
	if (*a != *b) {
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}

void genData()
{
	srand((unsigned)time(NULL));
	int *initS = malloc(MAXNUM * sizeof(int));
	MODULE *all = malloc(MAXNUM * sizeof(MODULE));

	//int initS[MAXNUM];
	for (int i = 0; i < MAXNUM; i++) {
		initS[i] = i;
	}
	for (int i = 0; i < MAXNUM; i++) {
		swap(&initS[i], &initS[RANDOM(0, MAXNUM)]);
	}

	//MODULE all[MAXNUM];
	all[0].kNum = 0;
	all[0].signal = 0;

	for (int i = 1; i < MAXNUM; i++) {
		int kNum = RANDOM(0, 4);
		all[i].kNum = kNum;
		all[i].signal = i;
		for (int j = 0; j < kNum; j++) {
			all[i].k[j] = all[RANDOM(0, i)].signal;
		}
	}

	FILE *file = fopen("input.txt", "w");
	fprintf(file, "1\n");
	fprintf(file, "%d %d\n", MAXNUM, MAXNUM);
	for (int i = 0; i < MAXNUM; i++) {
		fprintf(file, "%d ", initS[i]);
	}
	fprintf(file, "\n");
	for (int i = 0; i < MAXNUM; i++) {
		fprintf(file, "%d %d ", all[i].signal, all[i].kNum);
		for (int j = 0; j < all[i].kNum; j++) {
			fprintf(file, "%d ", all[i].k[j]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
	return 0;
}
