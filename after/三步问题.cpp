/*
面试题 08.01. 三步问题
三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模1000000007。

示例1:

 输入：n = 3 
 输出：4
 说明: 有四种走法
示例2:

 输入：n = 5
 输出：13
提示:

n范围在[1, 1000000]之间
*/



/*
解题思路
dp[i]含义：走到i阶台阶一共有dp[i]种方式

dp数组初始化：

dp[0]：0层台阶？没有意义，不用多管，直接赋值为null
dp[1]：1层台阶，只有1种方式
dp[2]：2层台阶，有1+1、2一共2种方式，故dp[2]=2
dp[3]：3层台阶，有1+1+1、1+2、2+1、3一共4种方式，故dp[3]=4
所以dp = [null, 1, 2, 4]
递推公式：第i层台阶可以由i-1、i-2、i-3层台阶相加而来，取模，故dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000007

作者：lzxjack
链接：https://leetcode-cn.com/problems/three-steps-problem-lcci/solution/jing-dian-dong-tai-gui-hua-javascript-by-fqtl/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


class Solution {
public:
    int waysToStep(int n) {

        //迭代存储前三个量
        if(n==1) return 1;
        if(n==2) return 2;
        int w1=1,w2=2,w3=4;
        int ans=4;
        for(int i=4;i<=n;i++){
            
            ans=(w1+w2)% 1000000007+w3;
            ans%= 1000000007;
            w1=w2; //dp[i - 3]
            w2=w3; //dp[i - 2]
            w3=ans; //dp[i - 1]
        }
        return ans;
    }
};


        /*
        AC:传统方法，开辟数组存储
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int>w(n+1,0);
        w[1]=1;
        w[2]=2;
        w[3]=4;

        for(int i=4;i<=n;i++){
            w[i]=(w[i-1]+w[i-2])% 1000000007+w[i-3];// % 1000000007;
            w[i] %= 1000000007;
        }
        return w[n];
        */