
# Breadth First Search 宽度优先搜索算法

1. 先将根节点放入队列中
2. 从队列中出队一个节点，并将该节点的所有孩子节点（如果有）依次放入队列中
3. 继续取出节点，指导队列为空
4. 当队列为空时，遍历完成


## 树的BFS
练习1：N叉树的层序遍历
题目链接：

### 429. N 叉树的层序遍历 - 力扣（LeetCode）

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
## 迷宫问题
### 1926. 迷宫中离入口最近的出口
给你一个 m x n 的迷宫矩阵 maze （下标从 0 开始），矩阵中有空格子（用 '.' 表示）和墙（用 '+' 表示）。同时给你迷宫的入口 entrance ，用 entrance = [entrancerow, entrancecol] 表示你一开始所在格子的行和列。

每一步操作，你可以往 上，下，左 或者 右 移动一个格子。你不能进入墙所在的格子，你也不能离开迷宫。你的目标是找到离 entrance 最近 的出口。出口 的含义是 maze 边界 上的 空格子。entrance 格子 不算 出口。

请你返回从 entrance 到最近出口的最短路径的 步数 ，如果不存在这样的路径，请你返回 -1 。

示例 1：
输入：maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
输出：1
解释：总共有 3 个出口，分别位于 (1,0)，(0,2) 和 (2,3) 。
一开始，你在入口格子 (1,2) 处。
- 你可以往左移动 2 步到达 (1,0) 。
- 你可以往上移动 1 步到达 (0,2) 。
从入口处没法到达 (2,3) 。
所以，最近的出口是 (0,2) ，距离为 1 步。

示例 2：
输入：maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
输出：2
解释：迷宫中只有 1 个出口，在 (1,2) 处。
(1,0) 不算出口，因为它是入口格子。
初始时，你在入口与格子 (1,0) 处。
- 你可以往右移动 2 步到达 (1,2) 处。
所以，最近的出口为 (1,2) ，距离为 2 步。

```c++
class Solution {
public:
	int bfs(std::vector<std::vector<char>>& maze, int x, int y)
	{
		int mx = maze.size();
		int my = maze[0].size();
		int dx[4] = {1,-1,0,0};
		int dy[4] = {0,0,1,-1};

		maze[x][y] = 0;
		std::queue<std::tuple<int,int,int>> que;

		que.push(std::make_tuple(x,y,0));

		while (!que.empty())
		{
			std::tuple<int,int,int> coor = que.front();
			que.pop();
			int x = std::get<0>(coor);
			int y = std::get<1>(coor);
			int s = std::get<2>(coor);

			for (int i = 0; i < 4; i++)
			{
				int tx = x + dx[i];
				int ty = y + dy[i];

				if (!isOut(mx, my, tx, ty) && maze[tx][ty] == '.')
				{
					//到达边界
					if (tx == 0 || tx == mx - 1 || ty == 0 || ty == my - 1)
					{
						return s+1;
					}

					maze[tx][ty] = 0;
					que.emplace(tx, ty, s+1);
				}
			}
		}

		return -1;
	}

	bool isOut(int mx, int my, int x, int y)
	{
		return x < 0 || y < 0 || x >= mx || y >= my;
	}
	int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance) {
		int x = entrance[0];
		int y = entrance[1];
		return bfs( maze, x, y);
	}
};
```