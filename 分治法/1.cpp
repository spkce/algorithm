/*
最大子段和问题
给定由n个整数（可能有负数）组成的序列a1,a2,a3,.....,an,求该序列的子段和的最大值。

1. 分解。如果将序列分为长度相等的两段：A[1,...,n/2],A[n/2+1,...,n]分别求出两段最大子段和则有3中情形：
	1.1 A[1,...,n]和A[1,...,n/2]最大子段和相同
	1.2 A[1,...,n]和A[n/2+1,...,n]最大子段和相同
	1.3 A[1,...,n]和A[i,...,j](1<=i<=n/2, n/2+1<=j<=n)最大子段和相同
2. 解决。1.1和1.2两种情形可以递归求得，对于1.3，A[n/2+1]与A[n/2+1]在最优序列中，
	s1 = A[1,...,n/2]，s2 = A[n/2+1,...,n]，s1 + s2便是1.3情况的最优值
3. 合并。比较3中情况下最大子段的和，最大的为最大子段和
*/
#include <algorithm>
int findMaxCrossingSubarray(int * nums, int l, int m, int r)
{
	int s1 = 0;
	for (int sum = 0, i = m; i >= l; i--)
	{
		sum += nums[i];
		s1 = std::max(s1, sum);
	}

	int s2 = 0;
	for (int sum = 0, i = m + 1; i <= r; i++)
	{
		sum += nums[i];
		s2 = std::max(s2, sum);
	}
	return (s1 + s2);
}

int maxSubArrayHelper(int * nums, int l, int r)
{
	if (l == r)
	{
		return nums[l];
	}
	int m = (l + r) / 2;
	int leftSum = maxSubArrayHelper(nums, l, m);
	int rightSum = maxSubArrayHelper(nums, m + 1, r);
	int midSum = findMaxCrossingSubarray(nums, l, m, r);

	return std::max(std::max(leftSum, rightSum), midSum);
}

int maxSubArray(int * nums, int len)
{
	return maxSubArrayHelper(nums, 0, len - 1);;
}


int main(int argc, char const *argv[])
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	int len = sizeof(a) / sizeof(a[0]);
	int r = maxSubArray(a, len);
	printf("\033[0;35m""r = %d""\033[0m\n", r);
	return 0;
}