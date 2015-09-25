//#include <stdio.h>
//
//#define LEN 10
//#define ENOUGH 1000000
//
//char out[LEN];
//char buf[LEN];
//
//int gIndex = 0;
//int gFlag = 1;
//int gPos = 0;
//int gLen;
//
//int recv(char *buf, int len);
//
//char *read_line()
//{
//	int i;
//	while (true) {
//		if (gFlag) {
//			gLen = recv(buf, LEN);
//		}
//		for (i = gPos; i < gLen; i++) {
//			if (buf[i] != '\n') {
//				out[gIndex++] = buf[i];
//			}
//			else {
//				break;
//			}
//		}
//		if (buf[i] == '\n') {
//			out[gIndex] = 0;
//			gPos = i + 1;
//			gIndex = 0;
//			if (i != gLen- 1) {
//				gFlag = 0;
//			}
//			else {
//				gPos = 0;
//				gFlag = 1;
//			}
//			return out;
//		}
//		else {
//			gPos = 0;
//			gFlag = 1;
//		}
//	}
//}