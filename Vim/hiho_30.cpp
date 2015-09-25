//#include <stdio.h>
//#include <string.h>
//
//#define N 100001
//
//int mine[N];
//int tempans[N];
//int ans[N];
//int gMineWidth;
//
//int yes[N];
//int no[N];
//
//int gAnsNum;
//int ycount = 0, ncount = 0;
//
//void check_ans()
//{
//	int i;
//	for (i = 1; i <= gMineWidth; i++) {
//		ans[i] += tempans[i];
//	}
//}
//
////int calNextPos(int pos)
////{
////	tempans[pos + 1] = mine[pos] - tempans[pos - 1] - tempans[pos];
////	return tempans[pos + 1] >= 0 && tempans[pos + 1] < 2 ? 1 : 0;
////}
////
////void dfs(int pos)
////{
////	if (pos == gMineWidth) {
////		if (tempans[pos] + tempans[pos - 1] == mine[pos]) {
////			gAnsNum++;
////			check_ans();
////		}
////		return;
////	}
////
////	if (calNextPos(pos)) {
////		dfs(pos + 1);
////	}
////}
//
//void solve()
//{
//	int i, flag = 1;
//	for (i = 1; i < gMineWidth; i++) {
//		tempans[i + 1] = mine[i] - tempans[i - 1] - tempans[i];
//		if (tempans[i + 1] < 0 || tempans[i + 1] >= 2) {
//			flag = 0;
//			break;
//		}
//	}
//	if (flag && tempans[i] + tempans[i - 1] == mine[i]) {
//		gAnsNum++;
//		check_ans();
//	}
//}
//
//void print_ans()
//{
//	int i, yescount = 0, nocount = 0;
//	for (i = 1; i <= gMineWidth; i++) {
//		if (ans[i] == 0) {
//			no[nocount++] = i;
//		}
//		else if (ans[i] == gAnsNum) {
//			yes[yescount++] = i;
//		}
//	}
//	printf("%d", yescount);
//	for (i = 0; i < yescount; i++) {
//		printf(" %d", yes[i]);
//	}
//	printf("\n");
//	printf("%d", nocount);
//	for (i = 0; i < nocount; i++) {
//		printf(" %d", no[i]);
//	}
//	printf("\n");
//
//}
//
//int main()
//{
//	int t, i;
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%d", &gMineWidth);
//		for (i = 1; i <= gMineWidth; i++) {
//			scanf("%d", mine + i);
//			ans[i] = 0;
//		}
//		gAnsNum = 0;
//		tempans[1] = 0;
//		//dfs(1);
//		solve();
//		tempans[1] = 1;
//		solve();
//		//dfs(1);
//
//		print_ans();
//	}
//	return 0;
//}