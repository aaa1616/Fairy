#include "nqueen.h"

int isValid(int *num, int row, int col)
{
	for (int i = 0; i < row; i++) {
		if (num[i] == col) {
			return 0;
		}
		if (abs(i - row) == abs(num[i] - col)) {
			return 0;
		}
	}
	return 1;
}

static void findPos(int *num, int row, int n, int *solution)
{
	if (row == n) {
		(*solution)++;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (num[j] == k) {
					printf("Q ");
				}
				else {
					printf("* ");
				}
			}
			printf("\n");
		}
		printf("\n");
		return ;
	}

	for (int i = 0; i < n; i++) {
		num[row] = i;
		if (isValid(num, row, i)) {
			findPos(num, row + 1, n, solution);
		}
	}
}

void nqueen(int n)
{
	int *num = malloc(n * sizeof(int));
	int solution = 0;
	findPos(num, 0, n, &solution);
	if (solution != 0) {
		printf("%d Queen Solution Count : %d\n", n, solution);
	}
	else {
		printf("No solution for %d\n", n);
	}
	free(num);
}

