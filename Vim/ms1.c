//#include <stdio.h>
//#include <limits.h>
//#include <math.h>
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int i, b, e, iy;
//	int rx, ry;
//	double x, y, r, ty, temp, ep = 1e-6;
//	double dis, ret = INT_MIN;
//	scanf("%lf%lf%lf", &x, &y, &r);
//	temp = x - r;
//	if (fabs(temp - round(temp)) <= ep) {
//		b = round(temp);
//	}
//	else {
//		b = ceil(temp);
//	}
//
//	temp = x + r;
//	if (fabs(temp - round(temp)) <= ep) {
//		e = round(temp);
//	}
//	else {
//		e =floor(temp);
//	}
//
//	for (i = b; i <= e; i++) {
//		temp = r * r - (x - i) * (x - i);
//		if (fabs(temp - round(temp)) <= ep) {
//			temp = round(temp);
//		}
//		ty = sqrt(temp);
//
//		temp = y - ty;
//		if (fabs(temp - round(temp)) <= ep) {
//			iy = round(temp);
//		}
//		else {
//			iy = ceil(temp);
//		}
//
//		dis = (i - x) * (i - x) + (iy - y) * (iy - y);
//		if (dis > ret || fabs(dis - ret) <= ep) {
//			ret = dis;
//			rx = i;
//			ry = iy;
//		}
//
//		temp = y + ty;
//		if (fabs(temp - round(temp)) <= ep) {
//			iy = round(temp);
//		}
//		else {
//			iy = floor(temp);
//		}
//
//		dis = (i - x) * (i - x) + (iy - y) * (iy - y);
//		if (dis > ret || fabs(dis - ret) <= ep) {
//			ret = dis;
//			rx = i;
//			ry = iy;
//		}
//
//	}
//
//	printf("%d %d\n", rx, ry);
//	return 0;
//}