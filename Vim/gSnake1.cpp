//#include <stdio.h>
//#include <string.h>
//#include <map>
//#include <set>
//#include <queue>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//#define M 100001
//
//typedef pair <int, int> PII;
//queue <PII> q;
//map <PII, int> eated;
//set <PII> body;
//PII now;
//
//int direct = 0;
//int gIndex = 0;
//int flag = 0;
//int r, c;
//
//int xd[] = { 0, 1, 0, -1 };
//int yd[] = { 1, 0, -1, 0 };
//
//#define ONLINE_JUDGE
//
//void init()
//{
//	vector<int> test;
//	test.
//	body.clear();
//	eated.clear();
//	while (!q.empty()) {
//		q.pop();
//	}
//	now.first = 1;
//	now.second = 1;
//	body.insert(now);
//	q.push(now);
//	gIndex = direct = flag = 0;
//}
//
//void countnext(PII *now)
//{
//	if (now->first + xd[direct] > r) {
//		now->first = 1;
//		return;
//	}
//	if (now->first + xd[direct] < 1) {
//		now->first = r;
//		return;
//	}
//	if (now->second + yd[direct] > c) {
//		now->second = 1;
//		return;
//	}
//	if (now->second + yd[direct] < 1) {
//		now->second = c;
//		return;
//	}
//
//	now->first += xd[direct];
//	now->second += yd[direct];
//}
//
//int action(char *p)
//{
//	int nr, nc;
//	if (p != NULL) {
//		if (strcmp(p, "R") == 0) {
//			direct = (direct + 1) % 4;
//		}
//		else {
//			direct = (direct - 1 + 4) % 4;
//		}
//	}
//	countnext(&now);
//	//printf("head %d : %d %d\n", gIndex, now.first, now.second);
//	if (((now.first + now.second) & 0x01) && !eated[now]) {
//		eated[now] = 1;
//		body.insert(now);
//		q.push(now);
//		return 1;
//	}
//	else {
//		PII tail = q.front();
//		body.erase(tail);
//		if (body.find(now) != body.end()) {
//			return 0;
//		}
//		q.pop();
//		q.push(now);
//		body.insert(now);
//	}
//
//	return 1;
//}
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//#else
//	freopen("codejam input/D-small-practice.in", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
//
//	int t, i, s, x;
//	char str[3];
//	scanf("%d", &t);
//	for (i = 1; i <= t; i++) {
//		scanf("%d%d%d", &s, &r, &c);
//		init();
//		while (s--) {
//			scanf("%d%s", &x, str);
//			while (x > gIndex) {
//				if (!action(NULL)) {
//					flag = 1;
//					break;
//				}
//				gIndex++;
//			}
//			if (flag) {
//				break;
//			}
//			if (!action(str)) {
//				break;
//			}
//			gIndex++;
//		}
//
//		gIndex = 0;
//		if (s < 0) {
//			while (gIndex != M) {
//				gIndex++;
//				if (!action(NULL)) {
//					break;
//				}
//			}
//		}
//		else {
//			while (s--) {
//				scanf("%d%s", &x, str);
//			}
//		}
//
//		printf("Case #%d: %d\n", i, q.size());
//	}
//	return 0;
//}