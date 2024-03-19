/*
0-1 背包问题

	给定n个货物、每个货物重量为Wi，一艘船的载货总重量为W。问如何选择货物装载使得船尽可能多的装载货物而不翻船？ 输入：货物数量n，每个货物的重量 输出：选择的货物i、最大的货物装载量

*/

#include <iostream>
using namespace std;
int cw = 0;	   //表示当前船上装的货物重量
int bestw = 0; //能装载的最大货物重量

void Backtrack(int t, int *w, int W, int n)
{ // t表示层级，w表示货物的重量，W表示船最大载重，n输入的货物数
	if (t > n - 1)
	{ //已经搜索到末尾
		if (cw > bestw && cw <= W)
			bestw = cw; //最大的重量记录
		return;
	}
	else
	{
		if (cw < W)
		{					//还能装下货物
			cw = cw + w[t]; //装、左子树
			Backtrack(t + 1, w, W, n);
			cw = cw - w[t]; //不装、右子树 cw之前添加了w，必须减回去
			Backtrack(t + 1, w, W, n);
		}
		if (cw == W)
		{
			bestw = cw;
		} // cw>W直接回溯
		return;
	}
}

int main()
{
	int n, W;
	cout << "请输入n件货物及船的最大载重量W:";
	cin >> n >> W;
	int w[n];
	cout << "请输入" << n << "件物品的重量:";
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	Backtrack(0, w, W, n);
	cout << "最大能装载货量为：" << bestw;

	return 0;
}