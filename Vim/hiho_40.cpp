//#include <stdio.h>
//#include <math.h>
//
//#define MIN(a, b) ((a) < (b) ? (a) : (b))
//#define MAX(a, b) ((a) < (b) ? (b) : (a))
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int a, b, c, x, y;
//	double left, right, lm, rm, t1, t2;
//	double dlm, drm, d;
//	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
//	left = -b / 2 / a;
//	t1 = (-b + sqrt(b * b - 4 * a * (c - y) + 0.0)) / 2 / a;
//	t2 = (-b - sqrt(b * b - 4 * a * (c - y) + 0.0)) / 2 / a;
//	if (x < left) {
//		right = MIN(t1, t2);
//	}
//	else {
//		right = MAX(t1, t2);
//	}
//
//	while (abs(left - right) > 1e-6) {
//		lm = left + (right - left) / 3;
//		rm = lm + (right - left) / 3;
//
//		dlm = pow(lm - x, 2) + pow(a * lm * lm + b * lm + c - y, 2);
//		drm = pow(rm - x, 2) + pow(a * rm * rm + b * rm + c - y, 2);
//
//		if (dlm > drm) {
//			left = lm;
//		}
//		else {
//			right = rm;
//		}
//	}
//
//	dlm = pow(lm - x, 2) + pow(a * lm * lm + b * lm + c - y, 2);
//	d = sqrt(dlm);
//	printf("%.3f\n", d);
//}