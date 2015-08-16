//#include <stdio.h>
//
//int main()
//{
//	FILE *file = fopen("codejam input/A-large-practice.in", "r");
//	FILE *out = fopen("outputL.txt", "w");
//	int i, t, w, b;
//	fscanf(file, "%d", &t);
//
//	for (i = 1; i <= t; i++) {
//		fscanf(file, "%d%d", &w, &b);
//		if ((b & 0x01) == 0) {
//			fprintf(out, "Case #%d: WHITE\n", i);
//		}
//		else {
//			fprintf(out, "Case #%d: BLACK\n", i);
//		}
//	}
//	fclose(out);
//
//	return 0;
//}