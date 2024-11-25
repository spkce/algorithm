/*
最长公共子序列（LCS）
子序列就是从给定序列中去掉若干元素（不一定是连续的）后形成的序列，例如X=ABCBDAB Y=BCDB Y是X的子序列

给定两个序列X=x1x2...xm, Y=y1y2...yn。求X和Y的最长公共子序列 Z=z1z2...zk


设l[i,j]是序列Xi，Yj的最长公共子序列，若i=0，j=0则 l = 0，状态转移方程
			 | 0							i=或j=0
	l[i,j] = | l[i-1, l-1] + 1				i,j>0 且 xi = yi
			 | max(l[i-1, l], l[i, l-1]),	i,j>0 且 xi != yi

	同时使用b[i][j]记录选择过程
*/


int** dp(int n, int m, char* vX, char* vY)
{
	int** l = new int*[n+1];
	int** b = new int*[n+1];
	for (int i = 0; i <= n; i++)
	{
		l[i] = new int[m+1];
		b[i] = new int[m+1];
	}

	for (int i = 1; i <= m; i++)
	{
		l[0][i] = 0;
		b[0][i] = 0;
	}

	for (int x = 1; x <= n; x++)
	{
		l[x][0] = 0;
		b[x][0] = 0;
		for (int y = 1; y <= m; y++)
		{
			if (vX[x-1] != vY[y-1])
			{
				if (l[x-1][y] >= l[x][y-1])
				{
					l[x][y] = l[x-1][y];
					b[x][y] = 1; // 沿y轴方向变化
				}
				else
				{
					l[x][y] = l[x][y-1];
					b[x][y] = 2; // 沿x轴方向变化
				}
			}
			else
			{
				l[x][y] = l[x-1][y-1] + 1;
				b[x][y] = 0;
			}
		}
	}

	return b;
}



void output(int lx, int ly, char* vX, char* vY, int**b)
{
	if (lx == 0 || ly == 0)
	{
		return;
	}

	if (b[lx][ly] == 0)
	{
		output(lx-1, ly-1,vX,vY,b);
		printf("%c\n", vX[lx-1]);
	}
	else if (b[lx][ly] == 1)
	{
		output(lx-1, ly,vX,vY,b);
	}
	else
	{
		output(lx, ly-1,vX,vY,b); 
	}
}

int main(int argc, char const *argv[])
{
	char X[] = {'A','B','C','B','D','A','B'};
	char Y[] = {'B','D','C','A','A','B','A'};

	int** p = dp(7,7,X,Y);

	output(7,7,X,Y,p);
	return 0;
}
