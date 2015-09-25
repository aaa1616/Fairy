//#include <stdio.h>
//#define _USE_MATH_DEFINES
//#include <math.h>
//
//#define ONLINE_JUDGE
//
//int main()
//{
//#ifdef ONLINE_JUDGE
//	FILE *file = fopen("codejam input/A-small-1-attempt0.in", "r");
//	FILE *out = fopen("output.txt", "w");
//#else
//	FILE *file = fopen("input.txt", "r");
//#endif
//	int i, t;
//	double value, result, v, d, ep = 1e-6;
//	fscanf(file, "%d", &t);
//	for (i = 1; i <= t; i++) {
//		fscanf(file, "%lf%lf", &v, &d);
//		value = d * 9.8 / v / v;
//		if (abs(value - round(value)) <= ep) {
//			value = round(value);
//		}
//		result = asin(value) * 90 / M_PI;
//#ifdef ONLINE_JUDGE
//		fprintf(out, "Case #%d: %.7f\n", i, result);
//#else
//		printf("Case #%d: %.7f\n", i, result);
//#endif
//	}
//
//#ifdef ONLINE_JUDGE
//	fclose(out);
//#endif
//
//	return 0;
//}