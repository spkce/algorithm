/*
活动选择问题

假设需要使用某一资源的n个活动组成的集合Sn={a1,a2,...,an},资源一次只能被一个资源占用，每一个活动ai有开始时间和结束时间si和fi,且0<=si<=fi<oo
一旦ai被选择，占据[si,fi)时间区间。若ai和aj时间段不重叠，则称ai和aj是兼容的。活动选择问题就是选出一个互相兼容活动组成的最大子集

输入：s[] = {1,3,0,5,3,5,6,8,8,2,12}
输入：f[] = {4,5,6,7,8,9,10,11,12,13,14}

假设结束时间已经排序了
*/


int OptimalSubset[100];
//递归
int RecursiveActivitySelector(int* s, int* f, int index, int n)
{
	int m = index + 1;
	static int activity_number = 0;
	while (m <= n && s[m] <= f[index]) //寻找晚于index结束的活动
	{
		m++;
	}

	if (m <= n)
	{
		//找到了m
		OptimalSubset[activity_number++] = m;
		RecursiveActivitySelector(s,f,m,n); //以m为基准继续找
	}

	return activity_number;
}

//迭代
int GreedyActivitySelecor(int* s, int* f, int n)
{
	int index = 0;
	int activity_number = 0;
	for (int m = 1; m <=n; m++)
	{
		if (s[m] >= f[index])
		{
			OptimalSubset[activity_number++] = m;
			index = m;
		}
	}
	return activity_number;
}

int main(int argc, char const *argv[])
{
	//强制加个s0=0 f0=0
	int s[] = {0,1,3,0,5,3,5,6,8,8,2,12};
	int f[] = {0,4,5,6,7,8,9,10,11,12,13,14};

	//int nset = RecursiveActivitySelector(s, f, 0, 12);
	int nset = GreedyActivitySelecor(s, f, 12);
	for (int i = 0; i < nset; i++)
	{
		printf("\033[0;35m""set:%d""\033[0m\n", OptimalSubset[i]);
	}
	
	return 0;
}