#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string convertToBase(int num, int k)
{
	string ret;
	bool negative = num < 0;
	num = abs(num);
	if (num == 0)
	{
		return "0";
	}
	while (num > 0)
	{
		ret.push_back(num%k + '0');
		num = num/k;
	}
	if (negative) 
	{
		ret.push_back('-');
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
