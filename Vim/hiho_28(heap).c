//#include <stdio.h>
//
//#define N 100001
//#define lson(x) (x << 1)
//#define rson(x) ((x << 1) | 1)
//#define par(x) (x >> 1)
//
//int nodes[N];
//int a = 2;
//
//void siftDown(int cur, int e)
//{
//	int tempmax, temp = nodes[cur];
//	while (lson(cur) <= e) {
//		tempmax = nodes[lson(cur)] > nodes[rson(cur)] ? lson(cur) : rson(cur);
//		if (temp >= nodes[tempmax]) {
//			break;
//		}
//		else {
//			nodes[cur] = nodes[tempmax];
//			cur = tempmax;
//		}
//	}
//	nodes[cur] = temp;
//}
//
//void siftUp(int cur)
//{
//	int p = par(cur), temp = nodes[cur];
//	while (cur > 1) {
//		if (nodes[p] >= temp) {
//			break;
//		}
//		else {
//			nodes[cur] = nodes[p];
//			cur = p;
//			p = par(p);
//		}
//	}
//	nodes[cur] = temp;
//}
//
//int main()
//{
//	FILE *file = fopen("input.txt", "r");
//	int n, w, size = 0;
//	char c;
//	fscanf(file, "%d%*c", &n);
//	while (n--) {
//		fscanf(file, "%c%*c", &c);
//		if (c == 'A') {
//			fscanf(file, "%d%*c", &w);
//			nodes[++size] = w;
//			siftUp(size);
//		}
//		else {
//			printf("%d\n", nodes[1]);
//			nodes[1] = nodes[size];
//			size--;
//			siftDown(1, size);
//		}
//	}
//	return 0;
//}