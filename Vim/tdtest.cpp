////#include <stdio.h>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//struct POS {
//	int x, y;
//	int b;
//};
//
//int cmp(const POS& p1, const POS& p2)
//{
//	if (p1.x < p2.x) {
//		return 1;
//	}
//	else if (p1.x == p2.x) {
//		return p1.b > p2.b;
//	}
//	else {
//		return 0;
//	}
//}
//
//POS p[10000];
//
//class Solution {
//public:
//	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
//		int i, k, len = buildings.size();
//		vector<pair<int, int>> vec;
//		if (len == 0) {
//			return vec;
//		}
//
//		priority_queue<int> q;
//		map<int, int> needtopop;
//		map<int, int>::iterator it;
//		// POS *p = new POS[len * 2];
//		for (i = 0; i < len; i++) {
//			p[i * 2].x = buildings[i][0];
//			p[i * 2].y = buildings[i][2];
//			p[i * 2].b = 1;
//
//			p[i * 2 + 1].x = buildings[i][1];
//			p[i * 2 + 1].y = buildings[i][2];
//			p[i * 2 + 1].b = 0;
//		}
//		sort(p, p + 2 * len, cmp);
//		len *= 2;
//		q.push(p[0].y);
//		vec.push_back(make_pair(p[0].x, p[0].y));
//		for (i = 1; i < len; i++) {
//			if (p[i].b == 1) {
//				if (p[i].y > q.top()) {
//					vec.push_back(make_pair(p[i].x, p[i].y));
//				}
//				q.push(p[i].y);
//			}
//			else {
//				needtopop[p[i].y]++;
//				while (!q.empty() && (it = needtopop.find(q.top())) != needtopop.end()) {
//					q.pop();
//					if (--it->second == 0) {
//						needtopop.erase(it);
//					}
//				}
//				if (q.empty()) {
//					vec.push_back(make_pair(p[i].x, 0));
//				}
//				else if (p[i].y > q.top()){
//					vec.push_back(make_pair(p[i].x, q.top()));
//				}
//			}
//		}
//
//		return vec;
//	}
//};
//
//int main()
//{
//	vector<vector<int>> b = { { 0, 2, 3 }, { 2, 5, 3 } };
//	Solution sl;
//	sl.getSkyline(b);
//}
////
////int main()
////{
////	long long sec = 1444038735;
////	time_t timet = sec;
////	tm* tt;
////	tt = localtime(&timet);
////	printf("%04d-%02d-%02d %02d:%02d:%02d\n", tt->tm_year + 1900, tt->tm_mon + 1, tt->tm_mday, tt->tm_hour, tt->tm_min, tt->tm_sec);
////	return 0;
////}