#include "buystock.h"

void crossmid(int prices[], int left, int right, int ret[])
{
	int leftSum = -INT_MAX, rightSum = -INT_MAX;
	int sum = 0;
	int mid = (left + right) / 2;
	for (int i = mid; i >= left; i--) {
		sum += prices[i];
		if (sum > leftSum) {
			leftSum = sum;
			ret[0] = i;
		}
	}
	sum = leftSum;
	for (int i = mid + 1; i <= right; i++) {
		sum += prices[i];
		if (sum > rightSum) {
			rightSum = sum;
			ret[1] = i;
		}
	}
	ret[2] = rightSum;
}

void subMaxProfit(int prices[], int left, int right, int ret[])
{
	if (left == right) {
		ret[0] = ret[1] = left;
		ret[2] = prices[left];
		return;
	}

	int mid = (left + right) / 2;
	int leftret[3] = { 0 };
	int rightret[3] = { 0 };
	int crossret[3] = { 0 };

	subMaxProfit(prices, left, mid, leftret);
	subMaxProfit(prices, mid + 1, right, rightret);
	crossmid(prices, left, right, crossret);

	if (leftret[2] >= rightret[2] && leftret[2] >= crossret[2]) {
		memcpy(ret, leftret, sizeof(leftret));
		return;
	}
	if (rightret[2] >= leftret[2] && rightret[2] >= crossret[2]) {
		memcpy(ret, rightret, sizeof(rightret));
		return;
	}
	if (crossret[2] >= leftret[2] && crossret[2] >= rightret[2]) {
		memcpy(ret, crossret, sizeof(crossret));
		return;
	}
}

int maxProfit(int prices[], int n)
{
	int left = 0, right = n - 1;
	int ret[3] = { 0 };
	subMaxProfit(prices, left, right, ret);
	ftTrace("left:%d, right:%d, sum=%d\n", ret[0], ret[1], ret[2]);
}