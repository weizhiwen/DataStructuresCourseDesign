#pragma once
#include <iostream>
using namespace std;
#define MAXVEX 100 //最大定点数
#include "Graph.h"

//定义访问标志数组
bool visited[MAXVEX];

//邻接矩阵深度遍历优先递归算法，无向图
void DFS(MGRAPH mGraph, int i)
{
	visited[i] = true;
	//printf("%c", mGraph.vers[i]);
	cout << mGraph.vers[i];
	for (int j = 0; j < mGraph.vexnum; j++)
	{
		if (mGraph.arcs[i][j].adj == 1 && visited[j])
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
