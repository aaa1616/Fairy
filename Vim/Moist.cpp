//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//
//int gIndex = 0;
//
//#define ONLINE_JUDGE
//
//int main()
//{
//#ifdef ONLINE_JUDGE
//	FILE *file = fopen("codejam input/A-small-1-attempt0.in", "r");
//#else
//	FILE *file = fopen("input.txt", "r");
//#endif
//
//	FILE *out = fopen("output.txt", "w");
//	int i, t, n, result;
//	char n1[256];
//	string s1, last;
//
//	fscanf(file, "%d", &t);
//	for (i = 1; i <= t; i++) {
//		fscanf(file, "%d\n", &n);
//		gIndex = 0;
//		last = " ";
//		result = 0;
//		while (n--) {
//			fgets(n1, 100, file);
//			n1[strlen(n1) - 1] = 0;
//			s1 = n1;
//
//			if (s1 < last) {
//				result++;
//			}
//			else {
//				last = s1;
//			}
//
//		}
//#ifdef ONLINE_JUDGE
//		fprintf(out, "Case #%d: %d\n", i ,result);
//#else
//		printf("Case #%d: %d\n", i, result);
//#endif
//	}
//	fclose(out);
//
//	return 0;
//}
