#include <stdio.h>

void func() {

	static int b;

	printf("%d", b);

}

int reachTask[100];
void inorder(int *sq, int n, int task) {
	for (int i = 0; i < n; i++) {
		int oldtask = task;
		reachTask[sq[i]] = i;
		while (reachTask[task] != -1) {
			printf("%d", sq[reachTask[task]]);
			task++;
		}
		if (oldtask != task) {
			printf("\n");
		}
	}
}

int main() {

	int sq[] = { 1, 2, 5, 6, 10, 4, 3, 8, 9, 7 };
	memset(reachTask, -1, 100 * sizeof(int));
	inorder(sq, 10, 1);
	return 0;

}
