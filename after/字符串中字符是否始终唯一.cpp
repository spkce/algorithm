
#include <stdio.h>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

/*
面试题 01.01. 判定字符是否唯一
实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

作者：from_zero-2
链接：https://leetcode-cn.com/problems/is-unique-lcci/solution/sethash_setpai-xu-wei-yun-suan-c-fu-zhu-jua55/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
class Solution {
public:
    bool isUnique(string astr) {
        set<char> st;
        for(auto c:astr){
            st.insert(c);
        }
        return st.size()==astr.size();
    }
};

