    
#include "stdio.h"
#include <iostream>
#include <map>
#include <string>

//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
int lengthOfLongestSubstring(std::string s, std::string & rs)
{
	std::map<int, int> mMap;
	int result = 0;
	int length = 0;
	int start = 0;
	int maxS = 0;
	for (int end = 0; end < s.size(); end++)
	{
		if (mMap.find(s[end]) != mMap.end() && mMap[s[end]] >= start)
		{
			start = mMap[s[end]] + 1;
			length = end - start;
		}
		else
		{
			length++;
			mMap[s[end]] = end;

			if (result < length)
			{
				result = length;
				maxS = start;
			}
		}
	}

	rs = s.substr(maxS, result);
	return result;
}


int main(int argc, char const *argv[])
{
	std::string s = "abcabcbb";
	std::string res;
	int ret = lengthOfLongestSubstring(s, res);
	printf("%d %s\n", ret, res.c_str());
}