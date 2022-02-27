
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

//十进制
string input(string a, string b)
{
	int i = a.size() - 1;
	int j = b.size() - 1;
	bool isCarry = false;
	string result;
	while (i >= 0 || j >=0)
	{
		
		char tempA = i >=0 ? a[i] : '0';
		char tempB = j >=0 ? b[j] : '0';

		int temp = tempA + tempB - 2 * '0';
		if (isCarry)
		{
			temp++;
			isCarry = false;
		}

		if (temp > 9)
		{
			isCarry = true;
			temp = temp % 10;
		}

		result += temp + '0';

		printf("%c+%c=%c\n", tempA, tempB, temp + '0');
		i--;
		j--;
	}
	reverse(result.begin(), result.end());
	return result;
}


int main(int argc, char const *argv[])
{
	string a = "123456";
	string b = "111";

	printf("%s\n", input(a, b).c_str());
	return 0;
}
