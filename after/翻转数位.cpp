/*
面试题 05.03. 翻转数位
给定一个32位整数 num，你可以将一个数位从0变为1。请编写一个程序，找出你能够获得的最长的一串1的长度。

示例 1：

输入: num = 1775(110111011112)
输出: 8
示例 2：

输入: num = 7(01112)
输出: 4
*/

#include <stdio.h>
#include <string>
#include <bitset>
#include <algorithm>
#include <vector>
#include "stdlib.h"

using namespace std;

class Solution {
public:
    int reverseBits(int num) {
        bitset<32> bst(num);
        int cnt1 = 0, cnt2 = 0; //cnt1表示前一段1，cnt2表示后一段1
        bool flag = false;  //flag表示后一段1是否可以和前一段1相连
        int ans = 1;  //记录答案
        int i = 0;  //记录遍历情况
        while(i < 32){
            cnt2 = 0;
            while(i < 32 && bst[i]){
                ++i;
                ++cnt2;  //记录后一段1的长度
            }
            ans = max(ans, flag ? (cnt1 + cnt2 + 1) : (cnt2 + 1)); //更新答案
            cnt1 = cnt2;  //后一段1变成前一段1，向后遍历
            cnt2 = 0;
            while(i < 32 && !bst[i]){ //记录0的长度
                ++i;
                ++cnt2;
            }
            flag = cnt2 == 1; //如果0的长度为1，则可以连接
        }
        return min(ans, 32);
    }
};
