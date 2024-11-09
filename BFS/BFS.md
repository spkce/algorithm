
## Breadth First Search 宽度优先搜索算法

1. 先将根节点放入队列中
2. 从队列中出队一个节点，并将该节点的所有孩子节点（如果有）依次放入队列中
3. 继续取出节点，指导队列为空
4. 当队列为空时，遍历完成


### 树的BFS
练习1：N叉树的层序遍历
题目链接：

1.   N 叉树的层序遍历 - 力扣（LeetCode）

题目描述：

给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。

树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
```
    1
  /  \  \
  3   2  4
 / \
 5 6 
```

输入：`root = [1,null,3,2,4,null,5,6]`
输出：`[[1],[3,2,4],[5,6]]`
```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
     {
        if (!root) {
            return {};
        }

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int cnt = q.size();
            vector<int> level;
            for (int i = 0; i < cnt; ++i) {
                Node* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for (Node* child: cur->children) {
                    q.push(child);
                }
            }
            ans.push_back(move(level));
        }

        return ans;
    }
};
```