#pragma once
#include <iostream>
using namespace std;
#define MAXVEX 100 //最大定点数
#include "Graph.h"
#include "Queue.h"

//定义访问标志数组
bool visited[MAXVEX];

//邻接矩阵深度遍历优先递归算法，无向图
void DFS(MGRAPH mGraph, int i)
{
	visited[i] = true;
	printf("%c ", mGraph.vers[i]);
	//cout << mGraph.vers[i];
	for (int j = 0; j < mGraph.vexnum; j++)
	{
		if (mGraph.arcs[i][j].adj == 1 && !visited[j])
			DFS(mGraph, j);
	}
}

//邻接矩阵的深度遍历操作
void DFSTraverse(MGRAPH mGraph)
{
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		visited[i] = false; //初始化访问标志数组
	}
	for (int j = 0; j < mGraph.vexnum; j++)
	{
		if (!visited[j])
		{
			DFS(mGraph, j); //对未访问的顶点调用DFS，若是连通图则会执行一次
		}
	}
}

//邻接矩阵的广度遍历算法
void BFSTraverse(MGRAPH mGraph)
{
	int i, j;
	Queue q;
	for (i = 0; i < mGraph.vexnum; i++)
	{
		visited[i] = false;
	}
	initQueue(&q);
	for (i = 0; i < mGraph.vexnum; i++)//对每个顶点做循环
	{
		if (!visited[i])               //若是未访问过
		{
			visited[i] = true;
			printf("%c ", mGraph.vers[i]); //打印结点，也可以其他操作
			enQueue(&q, i);           //将此结点入队列
			while (!isQueueEmpty(&q))     //将队中元素出队列，赋值给
			{
				char m;
				deQueue(&q, m);
				for (j = 0; j < mGraph.vexnum; j++)
				{
					//判断其他顶点若与当前顶点存在边且未访问过
					if (mGraph.arcs[m][j].adj == 1 && !visited[j])
					{
						visited[j] = true;
						printf("%c ", mGraph.vers[j]);
						enQueue(&q, j);
					}
				}
			}
		}
	}
}
