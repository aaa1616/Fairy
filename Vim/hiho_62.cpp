//#include <stdio.h>
//#include <string>
//#include <map>
//
//using namespace std; 
//
//#define N 20000
//
//char str[40];
//string page[N];
//map<string, int> lastvisit;
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int i, n, m, b = 0, w = 0;
//	map<string, int>::iterator iter;
//	scanf("%d%d", &n, &m);
//	for (i = 0; i < n; i++) {
//		scanf("%s", str);
//		string s = str;
//		page[i] = s;
//		iter = lastvisit.find(s);
//		if (iter != lastvisit.end() && iter->second != -1) {
//			printf("Cache\n");
//			lastvisit[s] = i;
//		}
//		else {
//			printf("Internet\n");
//			w++;
//			if (w <= m) {
//				lastvisit[s] = i;
//			}
//			else {
//				lastvisit[page[b]] = -1;
//				b++;
//			}
//		}
//		while (true) {
//			if (lastvisit[page[b]] == b) {
//				lastvisit[s] = i;
//				break;
//			}
//			b++;
//		}
//	}
//
//	return 0;
//}