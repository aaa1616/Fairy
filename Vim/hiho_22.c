//#include <stdio.h>
//
//#define N 11
//#define MIN(a, b) (a) < (b) ? (a) : (b)
//#define MAXW 10000
//#define lson(x) (x << 1)
//#define rson(x) ((x << 1) | 1)
//
//typedef struct _ST {
//	int left, right;
//	int tagset, tagadd;
//	int sum;
//}ST;
//ST st[4 * N];
//int w[N];
//
//void build(int l, int r, int cur)
//{
//	int m;
//	st[cur].left = l;
//	st[cur].right = r;
//	if (l == r) {
//		st[cur].sum = w[l];
//		return;
//	}
//
//	m = (l + r) / 2;
//	build(l, m, lson(cur));
//	build(m + 1, r, rson(cur));
//	st[cur].sum = st[lson(cur)].sum + st[rson(cur)].sum;
//}
//
//void update(int l, int r, int price, int cur, int flag)
//{
//	int stl = st[cur].left, str = st[cur].right;
//	int m = (stl + str) / 2;
//
//	if (l == stl && r == str) {
//		if (flag == 0) {
//			st[cur].tagadd = price;
//			st[cur].sum += (r - l + 1) * price;
//		}
//		else {
//			st[cur].tagset = price;
//			st[cur].tagadd = 0;
//			st[cur].sum = (r - l + 1) * price;
//		}
//		return;
//	}
//	if (st[cur].tagset != 0) {
//		st[rson(cur)].tagset = st[lson(cur)].tagset = st[cur].tagset;
//		st[lson(cur)].tagadd = st[rson(cur)].tagadd = 0;
//
//		st[lson(cur)].sum = (st[lson(cur)].right - st[lson(cur)].left + 1) * st[cur].tagset;
//		st[rson(cur)].sum = (st[rson(cur)].right - st[rson(cur)].left + 1) * st[cur].tagset;
//		st[cur].tagset = 0;
//	}
//	if (st[cur].tagadd != 0) {
//		st[lson(cur)].tagadd += st[cur].tagadd;
//		st[rson(cur)].tagadd += st[cur].tagadd;
//
//		st[lson(cur)].sum += (st[lson(cur)].right - st[lson(cur)].left + 1) * st[cur].tagadd;
//		st[rson(cur)].sum += (st[rson(cur)].right - st[rson(cur)].left + 1) * st[cur].tagadd;
//		st[cur].tagadd = 0;
//	}
//
//	if (r <= m) {
//		update(l, r, price, lson(cur), flag);
//	}
//	else if (l <= m && r >= m) {
//		update(l, m, price, lson(cur), flag);
//		update(m + 1, r, price, rson(cur), flag);
//	}
//	else {
//		update(l, r, price, rson(cur), flag);
//	}
//
//	st[cur].sum = st[lson(cur)].sum + st[rson(cur)].sum;
//}
//
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//	int i, n, q, op, wi, l, r, ret;
//	fscanf(file, "%d%d", &n, &q);
//	for (i = 0; i <= n; i++) {
//		fscanf(file, "%d", w + i);
//	}
//	build(0, n, 1);
//	while (q--) {
//		fscanf(file, "%d%d%d%d", &op, &l, &r, &wi);
//		update(l, r, wi, 1, op);
//		printf("%d\n", st[1].sum);
//	}
//	return 0;
//}