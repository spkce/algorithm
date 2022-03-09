/*
面试题 16.16. 部分排序
给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。

示例：

输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
输出： [3,9]
提示：

0 <= len(array) <= 1000000
*/
/*

解题思路
双指针

这里没有说升序还是降序，这里假设为升序，思路转换为：

找到左右两边需要被移动的l和r，那么它们需要满足什么呢？
对于l， 是需要找到它的右侧有元素比它小，那么按照升序排列，这里就需要把最小值排序；就是从右向左遍历，记录当前最小值，和当前点比较，一旦大于，则说明需要移动
对于r，类似的道理，就是要找到左侧比它大的元素，则需要把大的元素移动过来；这里采用从左往右的遍历方式，记录最大值，和当前点比较，一旦小于，则说明需要移动
总结一下：

通过两次遍历分别求得l和r
对于边缘情况，比如都是有序的 那么这种情况下，l和r就是默认值为-1

作者：ffreturn
链接：https://leetcode-cn.com/problems/sub-sort-lcci/solution/cji-hu-shuang-bai-de-shuang-zhi-zhen-by-3sbv0/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int> res {-1, -1};
        int n = array.size();
        if (n > 0)
        {
            // 从后往前遍历，得到l
            int currMin = INT_MAX;
            for (int i = n-1; i >= 0; --i)
            {
                if (array[i] > currMin)
                {
                    res[0] = i;
                }
                else
                {
                    currMin = min(currMin, array[i]);
                }
            }

            // 从前往后遍历，得到r
            int currMax = INT_MIN;
            for (int i = 0; i < n; ++i)
            {
                // cout << array[i] << " vs " << currMax << endl;
                if (array[i] < currMax)
                {
                    res[1] = i;
                }
                else
                {
                    currMax = max(currMax, array[i]);
                }
            }
        }

        return res;
    }
};

