

/*
面试题 02.07. 链表相交
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
函数返回结果后，链表必须 保持其原始结构 。
*/

/*
解题思路：
设「第一个公共节点」为 node ，「链表 headA」的节点数量为 aa ，「链表 headB」的节点数量为 bb ，「两链表的公共尾部」的节点数量为 cc ，则有：

头节点 headA 到 node 前，共有 a - ca?c 个节点；
头节点 headB 到 node 前，共有 b - cb?c 个节点；


考虑构建两个节点指针 A? , B 分别指向两链表头节点 headA , headB ，做如下操作：

指针 A 先遍历完链表 headA ，再开始遍历链表 headB ，当走到 node 时，共走步数为：
a + (b - c)
a+(b?c)

指针 B 先遍历完链表 headB ，再开始遍历链表 headA ，当走到 node 时，共走步数为：
b + (a - c)
b+(a?c)

如下式所示，此时指针 A , B 重合，并有两种情况：

a + (b - c) = b + (a - c)
a+(b?c)=b+(a?c)

若两链表 有 公共尾部 (即 c > 0c>0 ) ：指针 A , B 同时指向「第一个公共节点」node 。
若两链表 无 公共尾部 (即 c = 0c=0 ) ：指针 A , B 同时指向 nullnull 。

*/

#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include "stdlib.h"

using namespace std;


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while (A != B) {
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }
};

