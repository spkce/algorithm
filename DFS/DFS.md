# DFS思路

深度优先搜索类似于树的先序遍历，具体过程如下：

```
准备工作：创建一个visited数组，用于记录所有被访问过的顶点。
1.从图中v0出发，访问v0。
2.找出v0的第一个未被访问的邻接点，访问该顶点。以该顶点为新顶点，重复此步骤，直至刚访问过的顶点没有未被访问的邻接点为止。
3.返回前一个访问过的仍有未被访问邻接点的顶点，继续访问该顶点的下一个未被访问领接点。
4.重复2,3步骤，直至所有顶点均被访问，搜索结束。
```
### 例题：79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
```
｜A｜B｜C｜E｜
｜S｜F｜C｜S｜
｜A｜D｜E｜E｜

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
```


### 例题：463. 岛屿的周长
```
给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。

网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
输出：16
```

```c++
//递归实现dfs
class Solution
{
public:
    int res;
    void dfs(std::vector<std::vector<int>>& grid, 
            int mx, int my,
            int x, int y)
    {
        grid[x][y] = 2; //标记上已经访问过的位置
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!isInGrid(nx, ny, mx, my))
            {
                res++; //与边境相邻的边界
                continue;
            }

            if (grid[nx][ny] == 0)
            {
                res++; //与海相邻的边界
            }
            else if (grid[nx][ny] == 1)
            {
                dfs(grid, mx, my, nx, ny);
            }
        }
    }

    bool isInGrid(int x, int y, int mx, int my)
    {
        return x >= 0 && x < mx && y >= 0 && y < my;
    }

    int islandPerimeter(std::vector<std::vector<int>>& grid) 
    {
        res = 0;
        int mx = grid.size();
        int my = grid[0].size();

        for (int x = 0; x < mx; x++)
        {
            for (int y = 0; y < my; y++)
            {
                if (grid[x][y] == 1)
                {
                    dfs(grid, mx, my, x, y);
                    return res;
                }
            }
        }

        return res;
    }
};
```

