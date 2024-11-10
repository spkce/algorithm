
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
### 1926. 迷宫中离入口最近的出口 - 力扣（LeetCode）
给你一个 m x n 的迷宫矩阵 maze （下标从 0 开始），矩阵中有空格子（用 '.' 表示）和墙（用 '+' 表示）。同时给你迷宫的入口 entrance ，用 entrance = [entrancerow, entrancecol] 表示你一开始所在格子的行和列。

每一步操作，你可以往 上，下，左 或者 右 移动一个格子。你不能进入墙所在的格子，你也不能离开迷宫。你的目标是找到离 entrance 最近 的出口。出口 的含义是 maze 边界 上的 空格子。entrance 格子 不算 出口。

请你返回从 entrance 到最近出口的最短路径的 步数 ，如果不存在这样的路径，请你返回 -1 。

示例 1：
```
输入：maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
输出：1
解释：总共有 3 个出口，分别位于 (1,0)，(0,2) 和 (2,3) 。
一开始，你在入口格子 (1,2) 处。
- 你可以往左移动 2 步到达 (1,0) 。
- 你可以往上移动 1 步到达 (0,2) 。
从入口处没法到达 (2,3) 。
所以，最近的出口是 (0,2) ，距离为 1 步。
```
示例 2：
```
输入：maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
输出：2
解释：迷宫中只有 1 个出口，在 (1,2) 处。
(1,0) 不算出口，因为它是入口格子。
初始时，你在入口与格子 (1,0) 处。
- 你可以往右移动 2 步到达 (1,2) 处。
所以，最近的出口为 (1,2) ，距离为 2 步。
```
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

## 多源BFS最短路问题


### 542. 01 矩阵 - 力扣（LeetCode）
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。
示例 1：

```
输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
输出：[[0,0,0],[0,1,0],[0,0,0]]
```
示例 2：
```
输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
输出：[[0,0,0],[0,1,0],[1,2,1]]
```
这是一个经典的多源 BFS 问题
但如果将1当作起点，0 当作终点的话，很难判定它的距离，于是我们正难则反，将0当作起点（将所有的 0 入队），1 当作终点进行一个多源 BFS 即可

```c++
class Solution
{
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
	{
		int m = mat.size(), n = mat[0].size();
		// dist[i][j] == -1 表⽰：没有搜索过
		// dist[i][j] != -1 表⽰：最短距离
		vector<vector<int>> dist(m, vector<int>(n, -1));
		queue<pair<int, int>> q;
		// 1. 把所有的源点加⼊到队列中
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (mat[i][j] == 0)
				{
					q.push({ i, j });
					dist[i][j] = 0;
				}
		// 2. ⼀层⼀层的往外扩
		while (q.size())
		{
			auto [a, b] = q.front(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int x = a + dx[i], y = b + dy[i];
				if (x >= 0 && x < m && y >= 0 && y < n && dist[x][y] == -1)
				{
					dist[x][y] = dist[a][b] + 1;
					q.push({ x, y });
				}
			}
		}
		return dist;
	}
};
```

## 最短路问题
### AcWing 1102. 移动骑士
给定一个 n∗n 的棋盘，以及一个开始位置和终点位置。

棋盘的横纵坐标范围都是 0∼n−1。

将一个国际象棋中的骑士放置在开始位置上，请问将它移动至终点位置至少需要走多少步。

```
输入格式：
第一行包含整数 T，表示共有 T 组测试数据。
每组测试数据第一行包含整数 n，表示棋盘大小。
第二行包含两个整数 x,y 用来表示骑士的开始位置坐标 (x,y)。
第三行包含两个整数 x,y 用来表示骑士的终点位置坐标 (x,y)。
数据范围：
4≤n≤300
0≤x,y≤n−1
```
输入：
```
3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
```
输出：
```
5
28
0
```
```c++
#include<iostream>
#include<cstring>
#include<queue>
 
using namespace std;
int t,n;
int sx,sy,fx,fy;//(sx,sy)起点,(fx,fy)终点
struct node{//点结构体
	int x;
	int y;
	int dep;//步数
}Node;
int dx[]={1,1,2,2,-1,-1,-2,-2};//方向数组
int dy[]={2,-2,1,-1,2,-2,1,-1};
bool vis[305][305];//标记数组
int sum=0x3f3f3f;//最小步数
queue<node> q;
 
void bfs(){
	while(!q.empty()){
		auto tmp=q.front();
		q.pop();
		if(tmp.x==fx&&tmp.y==fy){//目标状态更新最小步数
			sum=min(sum,tmp.dep);
			return;
		}
		for(int i=0;i<8;i++){//八个方向遍历
			Node.x=tmp.x+dx[i];
			Node.y=tmp.y+dy[i];
			if(Node.x<0||Node.y<0||Node.x>=n||Node.y>=n){//下标越界
				continue;
			}
			if(vis[Node.x][Node.y]==1){//已经被访问过
				continue;
			}
			Node.dep=tmp.dep+1;//步数更新
			vis[Node.x][Node.y]=1;//先标记
			q.push(Node);//再入队
		}
	}
}
 
int main(){
	cin>>t;
	while(t--){
		memset(vis,false,sizeof(vis));//多组输入置0
		sum=0x3f3f3f;//初始最大值
		cin>>n>>sx>>sy>>fx>>fy;
		vis[sx][sy]=1;//先标记起点
		while(!q.empty()){//清空队列
			q.pop();
		}
		q.push(node{sx,sy,0});//起点步数为0
		bfs();
		cout<<sum<<endl;
	}
	return 0;
}
```

### 洛谷 P1379 八数码难题

在 3×3 的棋盘上，摆有八个棋子，每个棋子上标有 1 至 8 的某一数字。棋盘中留有一个空格，空格用 0 来表示。空格周围的棋子可以移到空格中。要求解的问题是：给出一种初始布局（初始状态）和目标布局（为了使题目简单,设目标状态为 123804765），找到一种最少步骤的移动方法，实现从初始布局到目标布局的转变。

```
输入格式：
输入初始状态，一行九个数字，空格用 0 表示。

输出格式：
只有一行，该行只有一个数字，表示从初始状态到目标状态需要的最少移动次数。保证测试数据中无特殊无法到达目标状态数据。

输入 
283104765

输出 
4
```
```
283    203    023     123    123
104 -> 184 -> 184  -> 084 -> 804
765    765    765     765    765
```
思路：
每一个字符串就是一个状态，我们发现每一次都是‘0’字符（空格）与四个方向的数字进行交换，属于空格的BFS
```
283             203             023             123             123
104       ->    184       ->    184       ->    084       ->    804
765             765             765             765             765

283104765 | -> 203184765 |    230184765 | -> 123084765 | -> 123804765 
          |    283140765 | -> 023184765 |              |    123784065
          |    283164705 |              |              |
          |    283014765 |              |              |
```
```c++
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<unordered_map>
 
using namespace std;
 
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};//方向数组
unordered_map<string,int> d;//考虑map键值对映射,状态映射步数
queue<string> q;//棋盘状态布局
 
int bfs(string strat){
	string end="123804765";//目标状态
	q.push(strat);//初始状态
	d[strat]=0;
	while(q.size()){
		auto s=q.front();
		q.pop();
		if(s==end){//目标状态
			return d[s];
		}
		int k=s.find('0');//下标位置转化
		int x=k/3;
		int y=k%3;
		for(int i=0;i<4;i++){//四个方向搜索
			int a=x+dx[i];
			int b=y+dy[i];
			if(a<0||a>=3||b<0||b>=3){//下标越界
				continue;
			}
			int distance=d[s];//记录步数
			swap(s[k],s[3*a+b]);//交换
			if(!d.count(s)){//新的布局
				d[s]=distance+1;
				q.push(s);
			}
			swap(s[k],s[3*a+b]);//还原
		}
	}
	return -1;//无法到达
}
 
int main(){
	string strat;
	for(int i=0;i<9;i++){
		char ch;
		cin>>ch;
		strat+=ch;
	}
	cout<<bfs(strat)<<endl;
	return 0;
}
```