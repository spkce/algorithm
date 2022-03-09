
/*
leetcode 147. 对链表进行插入排序
给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。

插入排序 算法的步骤:

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。

*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
	ListNode *insertionSortList(ListNode *head)
	{
		if (head == nullptr)
		{
			return head;
		}
		ListNode *dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode *lastSorted = head;
		ListNode *curr = head->next;
		while (curr != nullptr)
		{
			if (lastSorted->val <= curr->val)
			{
				lastSorted = lastSorted->next;
			}
			else
			{
				ListNode *prev = dummyHead;
				while (prev->next->val <= curr->val)
				{
					prev = prev->next;
				}
				lastSorted->next = curr->next;
				curr->next = prev->next;
				prev->next = curr;
			}
			curr = lastSorted->next;
		}
		return dummyHead->next;
	}
};
