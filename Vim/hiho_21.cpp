//#include <stdio.h>
//#include <map>
//using namespace std;
//
//#define N 5
//#define lson(x) (x << 1)
//#define rson(x) ((x << 1) | 1)
//
//typedef struct _ST {
//	int left, right;
//	int tag;
//}ST;
//ST st[8 * N];
//
//map<int, int> m;
//map<int, int> ret;
//int a[N], b[N];
//
//void build(int l, int r, int cur)
//{
//	int m;
//	st[cur].left = l;
//	st[cur].right = r;
//	if (l == r - 1) {
//		//st[cur].sum = w[l];
//		return;
//	}
//
//	m = (l + r) / 2;
//	build(l, m, lson(cur));
//	build(m, r, rson(cur));
//	//st[cur].sum = st[lson(cur)].sum + st[rson(cur)].sum;
//}
//
//void update(int l, int r, int price, int cur)
//{
//	int stl = st[cur].left, str = st[cur].right;
//	int m = (stl + str) / 2;
//
//	if (l == stl && r == str) {
//		st[cur].tag = price;
//		return;
//	}
//	if (st[cur].tag != 0) {
//		st[lson(cur)].tag = st[cur].tag;
//		st[rson(cur)].tag = st[cur].tag;
//		st[cur].tag = 0;
//	}
//
//	if (r <= m) {
//		update(l, r, price, lson(cur));
//	}
//	else if (l < m && r >= m) {
//		update(l, m, price, lson(cur));
//		update(m, r, price, rson(cur));
//	}
//	else {
//		update(l, r, price, rson(cur));
//	}
//}
//void scan(int cur)
//{
//	if (st[cur].tag != 0) {
//		ret[st[cur].tag] = 1;
//	}
//	else if (st[cur].left == st[cur].right - 1) {
//		return;
//	}else {
//		scan(lson(cur));
//		scan(rson(cur));
//	}
//}
//
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//	int n, l, i;
//	map<int, int>::iterator it;
//	fscanf(file, "%d%d", &n, &l);
//	for (i = 0; i < n; i++) {
//		fscanf(file, "%d%d", a + i, b + i);
//		m[a[i]] = 1;
//		m[b[i]] = 1;
//	}
//	i = 0;
//	for (it = m.begin(); it != m.end(); it++) {
//		it->second = ++i;
//	}
//	build(1, i, 1);
//	for (i = 0; i < n; i++) {
//		update(m[a[i]], m[b[i]], i + 1, 1);
//	}
//	scan(1);
//	printf("%d\n", ret.size());
//	return 0;
//}