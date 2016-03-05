//#include <stdio.h>
//#include <string.h>
//
//#define N 101
//
//char str[N];
//char ret[N];
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int i, n, len, index;
//	scanf("%d", &n);
//	while (n--) {
//		index = 0;
//		scanf("%s", str);
//		len = strlen(str);
//		for (i = 0; i < len; i++) {
//			if (str[i] == '#') {
//				index--;
//				index = index < 0 ? 0 : index;
//			}
//			else if (str[i] == '@') {
//				index = 0;
//			}
//			else {
//				ret[index++] = str[i];
//			}
//		}
//		ret[index] = 0;
//		printf("%s\n", ret);
//	}
//}