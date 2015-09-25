//#include <stdio.h>
//#include <string>
//#include <math.h>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//#define MAX(a, b) ((a) > (b) ? (a) : (b))
//#define MIN(a, b) ((a) < (b) ? (a) : (b))
//#define INT_MAX 2000000000
//
//void swap(int *a, int *b)
//{
//	if (*a != *b) {
//		*a ^= *b;
//		*b ^= *a;
//		*a ^= *b;
//	}
//}
//int findKthLargest(int* nums, int numsSize, int k) {
//	int i, b, e, mid;
//	b = 0, e = numsSize - 1;
//	while (b <= e) {
//		mid = b;
//		for (i = b; i < e; i++) {
//			if (nums[i] < nums[e]) {
//				swap(&nums[i], &nums[mid]);
//				mid++;
//			}
//		}
//		swap(nums[mid], nums[e]);
//		if (mid + 1 == k) {
//			return nums[mid];
//		}
//		else if (mid + 1 < k){
//			b = mid + 1;
//		}
//		else {
//			e = mid - 1;
//		}
//	}
//
//	return 0;
//}
//
//struct Test{
//	short a;
//	short b;
//};
//
//class A {
//public:
//	A() { printf("A\n"); }
//};
//class B : public A {
//public:
//	B() { printf("B\n"); }
//};
//class C : public A{
//public:
//	C(B v) : b(v) { printf("C\n"); }
//private:
//	A a;
//	B b;
//};
//
//int main()
//{
//	set<int> h;
//	h.
//	printf("%d\n");
//	return 0;
//}