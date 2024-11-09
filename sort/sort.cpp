稳定排序

/*
************************************************************
排序算法
从小到大排列
************************************************************
*/
#include "stdafx.h"

void IntAreaOut(int* a, int len);
void swap(int* a, int* b);

void QucikSort(int * a, int Left, int Right);
void BubbleSort(int *a, int len);
void SelectSort(int *a, int len);
void InsertSort(int* a, int len);
void ShellSort(int *a, int len);

int main()
{
	int a[] = { 4,2,1,3,5,9,7,6,8,0 };

	int num = sizeof(a) / sizeof(a[0]);

	//QucikSort(a, 0, num - 1);
	//BubbleSort(a, num);
	//SelectSort(a, num);
	//InsertSort(a, num);
	ShellSort(a, num);

	IntAreaOut(a, num);
	while (1);
	return 0;
}
void IntAreaOut(int* a, int len)
{
	printf("out:");

	for (int i = 0; i < len; i++)
	{
		printf("%d", a[i]);
	}

	printf("\n");
}
void swap(int* a, int* b)
{	
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
//快速排序
void QucikSort(int * a, int Left, int Right)
{
	int i = Left;		//i从左起
	int key = a[Left];	//选最左边为基准
	int j = Right;		//j从右起

	if (Left>Right) return;

	while (i < j)
	{
		while (i < j && key <= a[j])
		{
			j--;
		}
		while (i < j && key >= a[i])
		{
			i++;
		}
		if (i < j)
		{
			swap(&a[i], &a[j]);
		}
	}

	//将基准放在中间
	a[Left] = a[i];
	a[i] = key;

	QucikSort(a, Left, i - 1);
	QucikSort(a, j + 1, Right);
}
//冒泡排序
void BubbleSort(int *a, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = 1;
				swap(a + j, a + j + 1);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
//简单选择排序
void SelectSort(int *a, int len)
{
	for (int i = 0; i < len; i++)
	{
		int  min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(a + min, a + i);
		}
	}
}
//直接插入排序
void InsertSort(int* a, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a + j, a + j - 1);
			}
		}
	}
}
//希尔排序
void ShellSort(int *a, int len)
{
	for (int grep = len / 2; grep > 0; grep = grep / 2)
	{
		for (int i = grep; i < len; i++)  //i代表每组最右的位置
		{
			for (int j = i - grep; j >= 0 && a[j] > a[j + grep]; j -= grep) //从右向左交换
			{
				swap(a + j, a + j + grep);
			}
		}
	}
}
