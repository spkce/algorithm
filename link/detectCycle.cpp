#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>


/*
leetcode 560. 和为K的子数组
题目描述

给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。

*/

using namespace std;

//前缀和
int subarraySum(vector<int>& nums, int k)
{
	vector<int> presum(nums.size() + 1, 0);

	for (int i = 0; i < nums.size(); i++)
	{
		presum[i + 1] = presum[i] + nums[i];
	}

	int count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i; j < nums.size(); j++)
		{
			//注意偏移，因为我们的nums[2]到nums[4]等于presum[5]-presum[2]
			//所以这样就可以得到nums[i,j]区间内的和
			if (presum[j + 1] - presum[i] == k)
			{
				count++;
			}
		}
	}

	return count;
}


struct singleNode_t
{
	singleNode_t* next;
	int data;
};

singleNode_t *detectCycle(singleNode_t *head) 
{
	singleNode_t* fast = head;
	singleNode_t* slow = head;

	while(fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			fast = head;
			//当发现 slow 与 fast 相遇时，降fast回到head，和 slow 每次向后移动一个位置。最终，它们会在入环点相遇
			while (slow != fast) 
			{
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}

	return nullptr;
}

int main(int argc, char const *argv[])
{

	singleNode_t* pHead = new singleNode_t;
	pHead->data = 0;
	pHead->next = NULL;
	singleNode_t *p = pHead;

	singleNode_t* p1 = NULL;

	for (int i = 1; i < 10; i++)
	{
		p->next = new singleNode_t;
		if (i == 5)
		{
			p1 = p->next;
		}

		p = p->next;
		p->data = i;
		p->next = NULL;
		if (i == 9)
		{
			p->next = p1;
		}
	}
	printf("p1 = %p detect = %p\n", p1, detectCycle(pHead));
	return 0;
}


