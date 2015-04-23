#define HIHO_42
#ifdef HIHO_42
#include <stdio.h>
#include <string.h>

#define MOD 12357
#define MAXSIZE 8
#define LONGLONG long long

void mulm(LONGLONG a[][MAXSIZE], LONGLONG b[][MAXSIZE], LONGLONG ret[][MAXSIZE])
{
	int i, j, k;
	LONGLONG c[MAXSIZE][MAXSIZE];
	memset(c, 0, MAXSIZE * MAXSIZE * sizeof(LONGLONG));
	for (i = 0; i < MAXSIZE; i++) {
		for (j = 0; j < MAXSIZE; j++) {
			for (k = 0; k < MAXSIZE; k++) {
				c[i][j] += a[i][k] * a[k][j];
			}
			c[i][j] %= MOD;
		}
	}
	memcpy(ret, c, MAXSIZE * MAXSIZE * sizeof(LONGLONG));
}

void mula(LONGLONG a[], LONGLONG m[][MAXSIZE], LONGLONG ret[])
{
	int i, j;
	LONGLONG c[MAXSIZE];
	memset(c, 0, MAXSIZE * sizeof(LONGLONG));
	for (i = 0; i < MAXSIZE; i++) {
		for (j = 0; j < MAXSIZE; j++) {
			c[i] += a[j] * m[j][i];
		}
		c[i] %= MOD;
	}
	memcpy(ret, c, MAXSIZE* sizeof(LONGLONG));
}

int main()
{
	int n;
	LONGLONG m[][MAXSIZE] = { { 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 1 },
	{ 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 1, 0 },
	};
	LONGLONG a[MAXSIZE] = { 0, 0, 0, 0, 0, 0, 0, 1 };
	scanf("%d", &n);
	for (; n > 0; n >>= 1, mulm(m, m, m)) {
		if (n & 1) {
			mula(a, m, a);
		}
	}
	printf("%d\n", a[MAXSIZE - 1]);

	return 0;
}
#endif