#include "stdio.h"
#include <iostream>
#include <vector>

//合并两个有序数组，并移除相同的数字

int main(int argc, char const *argv[])
{
	int a[5] = {1,3,4,5,6};
	int b[5] = {2,4,5,8,9};
	
	std::vector<int> result;


	int i = 0, j =0;
	while (i < 5 && j < 5)
	{
			if (a[i] < b[j])
			{
				result.push_back(a[i]);
				i++;
			}
			else if (a[i] == b[j])
			{
				i++;j++;
			}
			else
			{
				result.push_back(b[j]);
				j++;
			}
	}

	
	
	while (i < 5)
	{
		result.push_back(a[i]);
		i++;
	}
	while (j < 5)
	{
		result.push_back(b[j]);
		j++;
	}
	
	for (int i = 0; i < result.size(); i++)
	{
		printf(" %d \n", result[i]);
	}
	
}