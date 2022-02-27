
#include <stdio.h>
#include <map>

int input(int *a, int an, int b)
{
	printf(" %d %d\n", an, b);
	int start = 0;
	int len = 0;
	int maxlen = 0;
	int maxStart = 0;
	for (int end = 0; end < an; end++)
	{
		if (a[end] >= b)
		{
			len++;
			if (maxlen < len)
			{
				maxlen = len;
				maxStart = start;
			}
		}
		else
		{
			start = end + 1;
			len = end - start + 1;
		}
		
	}
	printf("maxstart:%d\n", maxStart);
	return maxlen;
}

int main(int argc, char const *argv[])
{
	int a[] = {0,1,2,3,4,5,7,8,9};
	//printf("%lu\n", sizeof(a)); // 36 ? 奇怪 ？ubuntu环境
	printf("%d\n", input(a, 9, 5));
	return 0;
}
