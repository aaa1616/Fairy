//#include <stdio.h>
//
//#define N 50001
//#define lson(x) (x << 1)
//#define rson(x) ((x << 1) | 1)
//
//typedef struct _ST {
//	int left, right;
//	int same;
//	int add;
//	int delta, inc;
//}ST;
//
//ST st[N << 2];
//char str[N];
//int f[N];
//int sp = 0;
//int n;
//
//void build(int cur, int left, int right)
//{
//	int mid;
//	st[cur].left = left;
//	st[cur].right = right;
//	if (left == right) {
//		st[cur].same = str[left] - 'A';
//		return;
//	}
//
//	st[cur].same = -1;
//	mid = (left + right) >> 1;
//	build(lson(cur), left, mid);
//	build(rson(cur), mid + 1, right);
//}
//
//void cmd(int cur, int left, int right, int key, int type)
//{
//	if (type == 1) {
//		st[cur].same = key;
//		st[cur].delta = st[cur].inc = 0;
//		st[cur].add = 0;
//	}
//	if (type == 2) {
//		st[cur].add += key;
//	}
//	if (type == 4) {
//		st[cur].delta += (n + st[cur].left - key) % n + 1;
//		st[cur].inc++;
//	}
//}
//
//void update(int cur, int left, int right, int key, int type)
//{
//	int stl, str, m;
//	stl = st[cur].left;
//	str = st[cur].right;
//	m = (stl + str) >> 1;
//
//	if (left == stl && str == right) {
//		cmd(cur, left, right, key, type);
//		return;
//	}
//
//	if (st[cur].same == -1) {
//		st[lson(cur)].delta += st[cur].delta;
//		st[rson(cur)].delta += st[cur].delta + (m - stl + 1) * st[cur].inc;
//		st[lson(cur)].inc += st[cur].inc;
//		st[rson(cur)].inc += st[cur].inc;
//		st[lson(cur)].add += st[cur].add;
//		st[rson(cur)].add += st[cur].add;
//	}
//	else {
//		st[lson(cur)].same = st[rson(cur)].same = st[cur].same;
//		st[lson(cur)].delta = st[cur].delta;
//		st[rson(cur)].delta = st[cur].delta + (m - stl + 1) * st[cur].inc;
//		st[lson(cur)].inc = st[rson(cur)].inc = st[cur].inc;
//		st[lson(cur)].add = st[rson(cur)].add = st[cur].add;
//	}
//
//	st[cur].same = -1;
//	st[cur].add = st[cur].delta = st[cur].inc = 0;
//
//	if (right <= m) {
//		update(lson(cur), left, right, key, type);
//	}
//	else if (left <= m && right >= m) {
//		update(lson(cur), left, m, key, type);
//		update(rson(cur), m + 1, right, key, type);
//	}
//	else {
//		update(rson(cur), left, right, key, type);
//	}
//}
//
//void getResult(int cur)
//{
//	if (st[cur].same == -1) {
//		int m = (st[cur].left + st[cur].right) >> 1;
//		st[lson(cur)].delta += st[cur].delta;
//		st[rson(cur)].delta += st[cur].delta + (m - st[cur].left + 1) * st[cur].inc;
//		st[lson(cur)].inc += st[cur].inc;
//		st[rson(cur)].inc += st[cur].inc;
//		st[lson(cur)].add += st[cur].add;
//		st[rson(cur)].add += st[cur].add;
//
//		getResult(lson(cur));
//		getResult(rson(cur));
//	}
//	else {
//		int i;
//		int delta = st[cur].delta;
//		for (i = st[cur].left; i <= st[cur].right; i++) {
//			f[i] = st[cur].same + st[cur].add + delta;
//			delta += st[cur].inc;
//		}
//		return;
//	}
//}
//
//void typeAnds()
//{
//	int i;
//	for (i = 0; i < n; i++) {
//		printf("%c", (char)(f[(sp + i) % n] % 26 + 'A'));
//	}
//	printf("\n");
//}
//
//void commonUpdate(int cur, int left, int right, int key, int type)
//{
//	if (left + sp < n && right + sp >= n) {
//		update(cur, left + sp, n - 1, key, type);
//		update(cur, 0, right + sp - n, key, type);
//		return;
//	}
//
//	update(cur, (left + sp) % n, (right + sp) % n, key, type);
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int t, c, i, j, k;
//	char x[2];
//	char cmd[10];
//	scanf("%d%d", &n, &t);
//	scanf("%s", str);
//	build(1, 0, n - 1);
//	while (t--) {
//		scanf("%s%d", cmd, &c);
//		switch (c)
//		{
//		case 1:
//			scanf("%d%d%s", &i, &j, x);
//			commonUpdate(1, i - 1, j - 1, x[0] - 'A', 1);
//			break;
//		case 2:
//			scanf("%d%d%d", &i, &j, &k);
//			commonUpdate(1, i - 1, j - 1, k, 2);
//			break;
//		case 3:
//			scanf("%d", &k);
//			sp = (sp + k) % n;
//			break;
//		case 4:
//			scanf("%d%d", &i, &j);
//			commonUpdate(1, i - 1, j - 1, (i - 1 + sp) % n, 4);
//			break;
//		default:
//			break;
//		}
//	}
//	getResult(1);
//	typeAnds();
//	return 0;
//}