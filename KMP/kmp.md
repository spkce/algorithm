
# BF算法
BF算法，又称简单匹配算法，
```c++
int BF(string s, string t)
{
	int i = 0, j = 0;
	while (i < s.size() && j < t.size())
	{
		//比较当前字符是否相等
		if (s[i] == t[i])
		{
			//相等时，i,j后移一位，接着比较下一位字符
			i++;
			j++;
		}
		else
		{
			//不等时，i回溯，j重置为0，重新开始遍历
			i = i - j + 1;
			j = 0;
		}
	}
	//判断模式串是否遍历完
	if (j >= t.size())
		//遍历完则返回t在s中的位置
		return (i - t.size());
	else
		//否则返回-1
		return (-1);
}
```
# KMP算法
Knuth-Morris-Pratt字符串查找算法，简称为“KMP算法”，常用于在一个文本串S内查找一个模式串P的出现位置，KMP算法由D.E.Knuth、J.H.Morris和V.R.Pratt共同提出的。KMP算法与BF算法相比有较大的改进，主要是消除了目标串指针的回溯，从而使算法的效率在某种程度上提高了。

基本思路:
KMP算法是通过增加空间复杂度来减小时间复杂度。
当目标串s与模式串t进行匹配时，遇到字符不相匹配时，保持目标串s的指针i不变，将模式串t根据一个特殊的数组next[]进行回溯。

数组next[ ]是用来记录模式串t的指针j在某一位置时其之前遍历过的字符区段中最长相等的前后缀

示例：以模式串t = "abcabaa"为例

|	j	|0|1|2|3|4|5|6|
|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
|t[j]之前的字符串|无|a|ab|abc|abca|abcab|abcaba|
|next[j]|-1|0|0|0|1|2|1|

数组next[ ]的作用 
目标串s = "abcaabbabcabaab" , 模式串t = "abcabaa" .
当匹配到i = 4时，目标串s的字符与模式串t的字符已经无法匹配， 此时模式串t的指针回溯 j = 1
由next数组可知，next[4] = 1,故可知当目标串s字符与模式串t字符不匹配时，模式串t的指针进行回溯，即 j = next[ j ]。

```c++
//求取nextval[ ]
int GetNext(string t, int nextval[])
{
	int j = 0, k = -1;
	//规定：第一个字符前无字符串，故给值-1；
	nextval[0] = -1;
	//因为数组的最大下标为t.size()-1,但字符串的前缀与后缀不能与本身相等
	//所以遍历时只能取到t.size()-2;
	while (j < t.size() - 1)
	{
		if (k == -1 || t[j] == t[k])
		{
			//当字符匹配时，目标串s和模式串t的指针同时后移一位
			j++;
			k++;
			//判断指针回溯前字符是否相等
			if (t[j] != t[k])
				//不相等时，回溯到该位置
				nextval[j] = k;
			else
				//相等时，跳过当前回溯
				nextval[j] = nextval[k];
		}
		else
		{
			//当字符不匹配时，模式串t的指针进行回溯
			k = nextval[k];
		}
	}
}
 
//KMP
int KMPPIndex(string s, string t)
{
	int nextval[MaxSize], i = 0, j = 0;
	//获取模式串t的next数组
	GetNext(t, nextval);
	while (i < s.size() && j < t.size())
	{
		//判断指针是否指向第一个字符或比较当前字符是否相等
		if (j == -1 || s[i] == s[j])
		{
			//指针不在第一个字符时，i,j后移一位再进行比较
			//相等时，i,j后移一位，接着比较下一位字符
			i++;
			j++;
		}
		else
		{
			//字符不匹配时，回溯模式串t的指针j
			j = nextval[j];
		}
		//判断模式串是否遍历完
		if (j >= t.size())
			//遍历完则返回t在s中的位置
			return (i - t.size());
		else
			//否则返回-1
			return (-1);
	}
}
```