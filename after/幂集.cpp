/*
面试题 08.04. 幂集
幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。

说明：解集不能包含重复的子集。

示例:

 输入： nums = [1,2,3]
 输出：
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
/*
解题思路
从空集正推到所有集合：
根据 [1，2，3，...，n] 的所有子集推出 [1，2，3，...，n，x] 的所有子集；就是在 [1，2，3，...，n] 的所有子集中加上一个新元素 [x] ,并且保留原来的子集；

例如 nums = [1,2,3]
从 nums = [] 开始考虑， 答案 ans = [[]]

接着 就是 nums = [1] ,在之前 ans = [[]] 中的元素不变，并且将ans中的每个元素后面加上一个[1]就得到答案 ans = [[]，[1]]

然后 就是 nums = [1，2]
ans = [[]，[1]] ==> [[]，[1]，[2]] ==> [[]，[1]，[2], [1,2]]

最后 nums = [1，2]
ans = [[]，[1]，[2]，[1,2]] ==> [[]，[1]，[2]，[1,2], [3]] ==> [[]，[1]，[2]，[1,2], [3], [1,3]] ==> [[]，[1]，[2]，[1,2], [3], [1,3], [2,3]] ==> [[]，[1]，[2]，[1,2], [3], [1,3], [2,3], [1,2,3]] 就得到了答案

作者：sakura_pc
链接：https://leetcode-cn.com/problems/power-set-lcci/solution/cong-kong-ji-zheng-tui-dao-suo-you-ji-he-o1g1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0, j = 0, k = 0;
        //vector<int> black;
        vector<int> tmp;
        ans.push_back(tmp);
        for(i = 0; i < nums.size(); i++){
            k = ans.size();
            for(j = 0; j < k; j++){
                tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
