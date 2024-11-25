/*
0-1背包问题

有n个物品，第i个物品的价值为vi，重量为wi，背包容量为W（vi，wi，W均为非负数）。
求装入背包中价值最大物品
解法：
1. 刻画0-1背包问题的最优解结构
	背包问题可以看成一系列的最优决策过程
	若第n个物品选择，则包含前n-1个物品在容量 W - w（n）时的最优解
	若第n个物品不选择，则包含前n-1个物品在容量 W 时的最优解
2. 递归定义最优解值
	设 c[i,w] 为背包容量为 w时 i个物品最优解的总价值
			 | 0								,i=0 或 w = 0
	c[i,w] = | c[i-1,w]							, wi > w
			 | max{c[i-1,w-wi] + vi, c[i-1,w]} , i > 0 且 wi <= w
3. 计算最优解值
	int** KnapsackDP(int n, int w, int* vV, int* vW)
	时间复杂度O(nw)
4. 根据计算结果构造问题最优解
	c[i,w] 和 c[i-1,w]值是否相等，相等则说明xi=0，没有选择，否则xi=1 选择
	void OutputKnapsackDP(int n, int w, int* v, int* vW, int** c)
	时间复杂度O(n)
	最优解（0, 0, 0, 1, 1）
*/

#include <stdio.h>

int** KnapsackDP(int n, int w, int* vV, int* vW)
{
	int** c = new int*[n+1];
	for (int i = 0 ; i <= n; i++)
	{
		c[i] = new int[w+1];
	}

	for (int j = 0; j <= w; j++)
	{
		c[0][j] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		c[i][0] = 0;
		for (int j = 1; j <= w; j++)
		{
			if (vW[i - 1] <= j)
			{
				if (vV[i-1] + c[i-1][j-vW[i-1]] > c[i-1][j])
				{
					//选择放入
					c[i][j] = vV[i-1] + c[i-1][j-vW[i-1]];
				}
				else
				{
					//选择不放入
					c[i][j] = c[i-1][j];
				}
			}
			else
			{
				c[i][j] = c[i-1][j];
			}
		}
	}
	return c;
}

void OutputKnapsackDP(int n, int w, int* v, int* vW, int** c)
{
	int x[n] = {};

	for (int i = n; i > 1; i--)
	{
		if (c[i][w] == c[i-1][w])
		{
			x[i-1] = 0;
		}
		else
		{
			x[i-1] = 1;
			w = w - vW[i-1];
		}
	}

	if(c[1][w]==0)
	{
		x[0] = 0;
	}
	else
	{
		x[0] = 1;
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("%d ", x[i]);
	}

	printf("\n");
}

int main(int argc, char const *argv[])
{
	//假设n=5，W=17
	int v[] = {4,5,10,11,13};
	int w[] = {3,4,7,8,9};

	int ** p = KnapsackDP(5, 17, v, w);

	OutputKnapsackDP(5, 17, v, w, p);
	return 0;
}
