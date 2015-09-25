//#include <stdio.h>
//#include <map>
//#include <queue>
//#include <set>
//
//using namespace std;
//
//const int maxn = 100005;
//typedef pair <int, int> PII;
//queue <PII> Q;
//map <PII, bool> eated;
//set <PII> body;
//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//int r, c, t[maxn];
//char op[maxn];
//int dir;
//PII now;
//bool fail;
//
//inline PII pos(PII x) {
//	if (x.first > r) x.first = 1;
//	if (x.first < 1) x.first = r;
//	if (x.second > c) x.second = 1;
//	if (x.second < 1) x.second = c;
//	return x;
//}
//
//void Go() {
//	now = pos(make_pair(now.first + dx[dir], now.second + dy[dir]));
//	if (((now.first + now.second) & 1) && !eated[now]) {
//		eated[now] = 1;
//		Q.push(now);
//		body.insert(now);
//	}
//	else {
//		PII a = Q.front();
//		Q.pop();
//		body.erase(a);
//		if (body.find(now) != body.end()) {
//			fail = 1;
//			return;
//		}
//		Q.push(now);
//		body.insert(now);
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	//freopen("D-large.in", "r", stdin);
//	//freopen("D-large.ou", "w", stdout);
//	int T, s, cases = 0;
//	char cmd[10];
//	scanf("%d", &T);
//	while (T--) {
//		dir = 1; //right
//		now = make_pair(1, 1);
//		fail = 0;
//		while (!Q.empty()) Q.pop();
//		eated.clear();
//		body.clear();
//		Q.push(now);
//		body.insert(now);
//		scanf("%d%d%d", &s, &r, &c);
//		for (int i = 0; i < s; i++) {
//			scanf("%d%s", &t[i], cmd);
//			op[i] = cmd[0];
//		}
//		int p = 0;
//		for (int i = 1; i <= t[s - 1] + max(r, c) + 1; i++) {
//			Go();
//			if (p < s && t[p] == i) {
//				if (op[p] == 'R') {
//					dir = (dir + 1) % 4;
//				}
//				else {
//					dir = (dir - 1 + 4) % 4;
//				}
//				p++;
//			}
//			//printf("t = %d\n", i);
//			//for(set <PII> :: iterator it = body.begin(); it != body.end(); it++) printf("(%d, %d)  ", it -> first, it -> second); 
//			//printf("\n");
//			if (fail) break;
//		}
//		printf("Case #%d: %d\n", ++cases, Q.size() + fail);
//	}
//	return 0;
//}
