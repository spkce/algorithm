/*
面试题 02.05. 链表求和
给定两个用链表表示的整数，每个节点包含一个数位。

这些数位是反向存放的，也就是个位排在链表首部。

编写函数对这两个整数求和，并用链表形式返回结果。

 

示例：

输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
输出：2 -> 1 -> 9，即912
进阶：思考一下，假设这些数位是正向存放的，又该如何解决呢?

示例：

输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
输出：9 -> 1 -> 2，即912

*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);//创建新的头节点，来保存两个链表相加之后的结果
        ListNode* cur = head;
        int carry = 0;//进位命令
        while(l1 != nullptr || l2 != nullptr || carry){//只要此时l1或者l2或者进位标志carry都不为空或者大于
                                                       //0，那么就可以进行如下操作，也就是说，即便l1和l2为
                                                       //空，假如此时依然有上个循环的进位的话，本循环依然可
                                                       //以执行。
            int sum = 0;//每个循环我们都要来看一看此时的两个链表对应节点值相加的结果
            if(l1 != nullptr)
			{//取l1此时节点对应值
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != nullptr){//取l2此时节点对应值
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            sum += carry;//sum加上上一个循环的进位值，假如上个循环的结果大于10，那么肯定会对本循环进行进位
            ListNode* tmp = new ListNode(sum % 10);//创建一个新的节点，该节点的值为去掉进位值后剩下的值，
                                                   //比如14进位后只剩下4
            carry = sum / 10;//更新carry，为下一个循环做准备，因为下一个循环肯定要看看当前循环有没有进位
            cur -> next = tmp;//把新节点接入
            cur = cur -> next;//cur往后面挪一个位置，准备下一个循环接受新的节点
        }
        return head -> next;//完事儿
    }
};
