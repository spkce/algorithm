#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include "stdlib.h"

using namespace std;

/*
剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

示例：

输入：nums =?[1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。


解题思路：
考虑定义双指针 ii , jj 分列数组左右两端，循环执行：

指针 ii 从左向右寻找偶数；
指针 jj 从右向左寻找奇数；
将 偶数 nums[i]nums[i] 和 奇数 nums[j]nums[j] 交换

作者：jyd
链接：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/solution/mian-shi-ti-21-diao-zheng-shu-zu-shun-xu-shi-qi-4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
vector<int> exchange(vector<int>& nums)
{
	int i = 0, j = nums.size() - 1;
	while (i < j)
	{
		while(i < j && (nums[i] & 1) == 1) i++;
		while(i < j && (nums[j] & 1) == 0) j--;
		swap(nums[i], nums[j]);
	}
	return nums;
}

