/*
面试题 04.01. 节点间通路
节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。

示例1:

 输入：n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
 输出：true
示例2:

 输入：n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
 输出 true
提示：

节点数量n在[0, 1e5]范围内。
节点编号大于等于 0 小于 n。
图中可能存在自环和平行边。
*/


#include <stdio.h>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
方法一：BFS（迭代）
1.创建邻接表map
2.定义数组visited(记录访问过的节点)
3.利用queue实现BFS （一旦出现一个满足start=target就说明找到了）

作者：xuheding
链接：https://leetcode-cn.com/problems/route-between-nodes-lcci/solution/mian-shi-ti-0401-jie-dian-jian-tong-lu-c-6j3q/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target)
	 {
        if(start==target) return true;
        unordered_map<int,vector<int>> map;
        for(vector<int>& vec:graph){
            map[vec[0]].push_back(vec[1]);
        }
        vector<bool> visited(n,false);
        queue<int> queue;
        queue.push(start);
        while(!queue.empty()){
            int cur=queue.front();
            queue.pop();
            visited[cur]=true;
            for(int point:map[cur]){
                if(point==target) return true;
                else if(visited[point]==false) queue.push(point);
            }
        }
        return false;
    }
};

/*
方法二：DFS（迭代）
与方法一没区别，只不过使用了stack,来实现DFS
*/

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        if(start==target) return true;
        unordered_map<int,vector<int>> map;
        for(vector<int>& vec:graph){
            map[vec[0]].push_back(vec[1]);
        }
        stack<int> st;
        st.push(start);
        vector<bool> visited(n,false);
        while(!st.empty()){
            int cur=st.top();
            st.pop();
            visited[cur]=true;
            for(int point:map[cur]){
                if(point==target) return true;
                else if(visited[point]==false){
                    st.push(point);
                }
            }
        }
        return false;
    }
};

/*
方法三：DFS（递归）
采用递归的方法
1.创建邻接表map和方法一、二 是一样的。
2.由于找到一个结果就立刻返回,利用if(dfs(point,target)) return true;来实现

*/


class Solution {
private:
    vector<bool> visited;
    unordered_map<int,vector<int>> map;
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        if(start==target) return true;
        for(vector<int>& vec:graph){
            map[vec[0]].push_back(vec[1]);
        }
        visited=vector<bool>(n,false);
        return dfs(start,target);
    }
    bool dfs(int start,int target){
        if(start==target) return true;
        if(visited[start]) return false;
        visited[start]=true;
        for(int point:map[start]){
            if(dfs(point,target)) return true;
        }
        return false;
    }
};
