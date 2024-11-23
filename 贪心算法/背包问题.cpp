/*
背包问题
背包问题与01背包问题相似，但是每个物品可以部分放入背包
n = 5 W = 100
重量 W = {30，10， 20，50， 40}
体积 V = {65，20， 30，60， 40}
单位体积重量
	{2.1，2，1.5，1.2，1}

	假设已经对单位体积重量排序
*/

int GreedyKnapsack(int n, int W, int* vW, int* vV)
{
	float value[n] = {};

	for (int i = 0; i < n; i++)
	{
		value[i] = (float)((float)vV[i] / (float)vW[i]);
	}

	int total = 0;
	for (int i = 0; i < n; i++)
	{
		if (W >= vW[i])
		{
			total += vV[i];
			W -= vW[i];
		}
		else if (W < vW[i] && W > 0)
		{
			total += (int)(value[i] * W);
			W = 0;
			break;
		}
		else
		{
			break;
		}
	}
	return total;
}

int main(int argc, char const *argv[])
{
	int n = 5;
	int CW = 100;
	int W[] = {30, 10, 20, 50, 40};
	int V[] = {65, 20, 30, 60, 40};

	int total = GreedyKnapsack(n, 100, W, V);
	printf("\033[0;35m""total:%d""\033[0m\n", total);
	return 0;
}

