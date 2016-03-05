//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//#define N 1001
//
//struct row {
//	int childId;
//	int expandLength;
//	row() :childId(-1), expandLength(0) {};
//	row(int id) : childId(id), expandLength(0) {};
//};
//
//struct section {
//	vector<row> rows;
//	int length;
//	int expandLength;
//	int d;
//	section() : length(0), expandLength(0), d(0) {};
//};
//struct panel {
//	vector<section> sections;
//	vector<int> rowIds;
//};
//
//panel panels[N];
//
//int cmpRow(const row &x, const row &y)
//{
//	return x.expandLength > y.expandLength;
//}
//
//int cmpSection(const section &x, const section &y)
//{
//	return x.d > y.d;
//}
//
//int getLength(panel &p)
//{
//	int i, j, temp, now = 0, ret = 0, len = p.sections.size();
//
//	for (i = 0; i < len; i++) {
//		int jlen = p.sections[i].rows.size();
//		for (j = 0; j < jlen; j++) {
//			p.sections[i].rows[j].expandLength = getLength(panels[p.sections[i].rows[j].childId]);
//		}
//		sort(p.sections[i].rows.begin(), p.sections[i].rows.end(), cmpRow);
//		p.sections[i].length = jlen;
//		p.sections[i].expandLength = jlen;
//		for (j = 0; j < jlen; j++) {
//			temp = j + p.sections[i].rows[j].expandLength;
//			if (p.sections[i].expandLength < temp) {
//				p.sections[i].expandLength = temp;
//			}
//		}
//		p.sections[i].d = p.sections[i].expandLength - p.sections[i].length;
//	}
//	sort(p.sections.begin(), p.sections.end(), cmpSection);
//
//	for (i = 0; i < len; i++) {
//		temp = now + p.sections[i].expandLength;
//		if (ret < temp) {
//			ret = temp;
//		}
//		now += p.sections[i].length;
//	}
//
//	return ret;
//}
//
//void dealPanel(panel &p)
//{
//	int i, len = p.rowIds.size(), sectionId = -1;
//
//	for (i = 0; i < len; i++) {
//		if (p.rowIds[i] == 0) {
//			p.sections.push_back(section());
//			sectionId++;
//		}
//		else {
//			p.sections[sectionId].rows.push_back(row(p.rowIds[i]));
//		}
//	}
//}
//
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int i, n, num, id;
//	scanf("%d", &n);
//	for (i = 0; i <= n; i++) {
//		scanf("%d", &num);
//		panels[i].rowIds.push_back(0);
//		while (num--) {
//			scanf("%d", &id);
//			if (id == 0) {
//				num++;
//			}
//			panels[i].rowIds.push_back(id);
//		}
//		dealPanel(panels[i]);
//	}
//	printf("%d\n", getLength(panels[0]));
//	return 0;
//}