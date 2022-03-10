/*
面试题 05.02. 二进制数转字符串
二进制数转字符串。给定一个介于0和1之间的实数（如0.72），类型为double，打印它的二进制表达式。如果该数字无法精确地用32位以内的二进制表示，则打印“ERROR”。

示例1:

 输入：0.625
 输出："0.101"
示例2:

 输入：0.1
 输出："ERROR"
 提示：0.1无法被二进制准确表示
提示：

32位包括输出中的"0."这两位。
*/

#include <stdio.h>
#include <string>
#include <algorithm>
#include "stdlib.h"


using namespace std;
//十进制的小数转换为二进制小数，主要是利用小数部分乘2后，取整数部分，直至小数点后为0
class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        while (num != 0) {
            num *= 2;
            if (num >= 1) { //乘2后num>=1,说明此时整数部分为1，取完该整数部分1后，num接着利用的还是其小数部分，所以要减掉整数部分（即1）
                ans += "1";
                num -= 1;
            } else { //小于1说明整数部分为0，取该整数部分0
                ans += "0";
            }
            if (ans.size() > 32) return "ERROR";
        }
        return ans;
    }
};
