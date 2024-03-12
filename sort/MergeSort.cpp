#include "stdio.h"

void merge(int *input, int l, int m, int r, int *temp)
{
	int i = l;	   // 初始化i, 左边有序序列的头部初始索引
	int j = m + 1; // 初始化j, 右边有序序列的头部初始索引
	int t = 0;	   // 指向中转数组 temp 的当前索引

	// 1. 先把左右（有序）序列的数据按照规则填充到中转数组 temp
	//直到左右俩边的有序序列有一边处理完毕为止
	while (i <= m && j <= r)
	{
		// 左边有序序列头部元素 <= 右边有序序列头部元素
		if (input[i] <= input[j])
		{
			// 将 input[i] 即小的数据 填充到 中转数组 temp, 并将 i 和 t 后移
			temp[t++] = input[i++];
		}
		else
		{
			// 反之 将 右边有序序列头部元素 拷贝到 中转数组 temp, 并将 j 和 t 后移
			temp[t++] = input[j++];
		}
	}

	// 2. 把有剩余数据的一边的剩余数据依次全部填充到 temp
	// 2.1 说明左边有序序列还有剩余元素， 将剩余元素全部填充到 temp
	while (i <= m)
	{
		temp[t++] = input[i++];
	}

	// 2.2 说明右边有序序列还有剩余元素， 将剩余元素全部填充到 temp
	while (j <= r)
	{
		temp[t++] = input[j++];
	}

	// 3. 把中转数组 temp 元素 拷贝到 原始数组 input
	for (t = 0; l <= r; t++, l++)
	{
		input[l] = temp[t];
	}
}

void mergeSort(int *input, int l, int r, int *temp)
{
	if (l < r)
	{
		int m = (l + r) / 2; // 中间索引
		mergeSort(input, l, m, temp);
		mergeSort(input, m + 1, r, temp);
		merge(input, l, m, r, temp);
	}
}

void MergeSort(int *input, int len)
{
	int temp[len] = {0};
	mergeSort(input, 0, len - 1, temp);
}

int main(int argc, char const *argv[])
{
	int input[] = {9, 8, 7, 6, 5, 1, 2};

	int len = sizeof(input) / sizeof(input[0]);

	// int temp[len] = {};

	// mergeSort(input,0, len - 1,temp);
	MergeSort(input, len);

	printf("out:");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", input[i]);
	}
	printf("\n");
	/* code */
	return 0;
}
