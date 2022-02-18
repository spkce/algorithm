#include <stdio.h>
#include <vector>
//#include <unistd.h>
//#include <string>
//#include <stdlib.h>
//#include <string.h>
//#include <iostream>

/*用以太网线缆将?n?台计算机连接成一个网络，计算机的编号从?0?到?n-1。线缆用?connections?表示，其中?connections[i] = [a, b]?连接了计算机?a?和?b。

网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。

给你这个计算机网络的初始布线?connections，你可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。请你计算并返回使所有计算机都连通所需的最少操作次数。如果不可能，则返回?-1 。?
*/
class CDisjointSet
{

public:
	CDisjointSet(int n)
		: m_vParent(std::vector<int>(n)), m_vRank(std::vector<int>(n)), m_count(n), m_rest(0)
	{
		for (int i = 0; i < n; i++)
		{
			m_vParent[i] = i;
		}
	}

	int find(int x)
	{
		// 压缩方式：直接指向根节点
		if (x != m_vParent[x])
		{
			m_vParent[x] = find(m_vParent[x]);
		}
		return m_vParent[x];
	}

	bool merge(int x, int y)
	{
		int rootx = find(x);
		int rooty = find(y);

		if (rootx == rooty)
		{
			m_rest++; 
			return false;
		}

		// 按秩合并
		if (m_vRank[rootx] < m_vRank[rooty])
		{
			std::swap(rootx, rooty);
		}
		
		m_vParent[rooty] = rootx;

		m_vRank[x] += m_vRank[y];
		--m_count;
		return true;
	}
	bool isConnected(int x, int y)
	{
		x = find(x);
		y = find(y);
		return x == y;
	}

public:
	std::vector<int> m_vParent;
	std::vector<int> m_vRank; // 记录根节点的深度（用于优化）
	int m_count;	//// 记录连通分量的个数
	int m_rest;		//// 多余的连接
};


class Solution {
public:
	int makeConnected(int n, std::vector<std::vector<int>> &connections)
	{
		if (connections.size() < n - 1)
		{
			return -1;
		}

		CDisjointSet djset(n);
		for (const auto &conn : connections)
		{
			djset.merge(conn[0], conn[1]);
		}

		return djset.m_count - 1;
	}
};

int main(int argc, char const *argv[])
{
	int n = 4;
	std::vector<std::vector<int> > connections(3, std::vector<int>(2, 0));
	connections[0][0] = 0;
	connections[0][1] = 1;
	connections[1][0] = 0;
	connections[1][1] = 2;
	connections[2][0] = 1;
	connections[2][1] = 2;

	Solution s;
	int ret = s.makeConnected(n, connections);

	printf("ret = %d\n", ret);

	return 0;
}
