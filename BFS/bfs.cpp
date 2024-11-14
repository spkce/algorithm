/*
************************************************************
Breadth First Search
宽度优先搜索算法
************************************************************
*/

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

class CPosition
{
public:
	CPosition():x(0),y(0) {}
	CPosition(int x, int y):this.x(x),this.y(y){}
	void operator =(const CPosition& point)
	{
		x = point.x;
		y = point.y;
	}
	CPosition operator +(const CPosition& point)
	{
		CPosition pos;
		pos.x = this.x + point.x;
		pos.y = this.y + point.y;
		return pos;
	}
	virtual ~CPosition(){}
	int x;
	int y;
};

class Node
{
public:
	Node():pre(NULL){}
	Node(int x, int y):pos(x,y),pre(NULL)(x,y){}
	CPosition pos;
	Node* pre;
};

const int maxRaw = 5;
const int maxCol = 5;

//迷宫地形
int maze[maxRaw][maxCol] = {
	{ 0, 1, 0, 0, 0 }, 
	{ 0, 1, 0, 1, 0 }, 
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0 },
	{ 0, 0, 0, 1, 0 }
};
//记录是否被遍历
int book[maxRaw][maxCol] = {0};
void bfs()
{
	//定义出四个方向
	CPosition dct[4];
	dct[0] = left(-1, 0);
	dct[1] = right(1, 0);
	dct[2] = up(0, -1);
	dct[3] = down(0, 1);
	//队列
	queue<Node*> Q;

	//开始节点(0,0)
	Node* pFristNode = new Node(0,0);
	Q.push(pFristNode);

	while (!Q.empty())
	{
		Node* node = Q.front();
		CPosition temp;

		for (int i = 0; i < 4; i++)
		{
			temp = node.pos + dct[i];
		
			if (temp.x > 0 && temp.x < maxCol && temp.y > 0 && temp.y < maxRaw)
			{
				if (maze[temp.x][temp.y] == 0 && book[temp.x][temp.y] == 0)
				{
					Node* pNode = new Node(temp.x, temp.y);
					pNode.pre = node;
					book[temp.x][temp.y] = 1;
					Q.push(pNode);
					Q.pop();

					//到达终点
					if (temp.x == 4 && temp.x == 4)
					{
						
					}
				}
			}

		}
	}
}
