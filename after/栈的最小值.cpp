/*
面试题 03.02. 栈的最小值
请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)

示例：

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include "stdlib.h"

using namespace std;


//方法一：单栈
//1.用pair压栈两个数，一个是正常元素，另一个是目前最小值
class MinStack {
public:
    stack<pair<int, int>> stk;
    MinStack() {

    }
    void push(int x) {
        if(stk.empty()) stk.push(make_pair(x, x)); //为空插入(x,x)
        else stk.push(make_pair(x, min(x, stk.top().second)));
    }
    void pop() {
        stk.pop();
    }
    int top() {
        return stk.top().first;
    }
    int getMin() {
        return stk.top().second;
    }
};


//方法二：双栈
//1.一个栈正常压栈元素
//2.另一个栈将最小值压栈

class MinStack {
public:
    stack<int> stk, stkhelp;
    MinStack() {
        
    }
    void push(int x) {
        stk.push(x);
        if(stkhelp.empty())
		{
			stkhelp.push(x); //为空压入x
		}
        else
		{
			stkhelp.push(min(stkhelp.top(), x));
		}
    }
    void pop() {
        stk.pop();
        stkhelp.pop();
    }
    int top() {
        return stk.top();   
    }
    int getMin() {
        return stkhelp.top();   
    }
};
