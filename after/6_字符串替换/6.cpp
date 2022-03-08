#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;

//src中的subSrc换成subDst
char* replace(char* src, const char* subSrc, const char* subDst, char* dst, int size)
{
	char * pos = src;
	char * temp = NULL;
	int len = 0;
	int cplen = 0;

	while (1)
	{
		temp = strstr(pos, subSrc);
		if (temp == NULL)
		{
			cplen = strlen(pos) + len > size ? size - len : strlen(pos);
			memcpy(dst + len, pos, cplen);
			break;
		}
		cplen = temp - pos + len > size ? size - len : temp - pos;
		memcpy(dst + len, pos, cplen);
		len += cplen;
		pos += cplen;
		if(len >= size)
		{
			break;
		}
		cplen = strlen(subDst) + len > size ? size - len : strlen(subDst);
		memcpy(dst + len, subDst, cplen);
		len += cplen;
		pos += strlen(subSrc);
	}
	return dst;
}

//src中的subSrc换成subDst （strlen(subSrc) >= strlen(subDst)）
char* replace(char* src, const char* subSrc, const char* subDst, int size)
{
	char * pos = src;
	char * temp = NULL;
	char * dst = NULL;
	int len = 0;
	int cplen = 0;

	if (strlen(subSrc) < strlen(subDst))
	{
		return src;
	}

	dst = (char*)malloc(size);
	if (dst == NULL)
	{
		return src;
	}

	while (1)
	{
		temp = strstr(pos, subSrc);
		if (temp == NULL)
		{
			cplen = strlen(pos) + len > size ? size - len : strlen(pos);
			memcpy(dst + len, pos, cplen);
			break;
		}
		cplen = temp - pos + len > size ? size - len : temp - pos;
		memcpy(dst + len, pos, cplen);
		len += cplen;
		pos += cplen;
		if(len >= size)
		{
			break;
		}
		cplen = strlen(subDst) + len > size ? size - len : strlen(subDst);
		memcpy(dst + len, subDst, cplen);
		len += cplen;
		pos += strlen(subSrc);
	}

	strncpy(src, dst, size);
	free(dst);
	return src;
}