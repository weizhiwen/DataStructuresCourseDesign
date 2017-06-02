#pragma once
#include <iostream>
using namespace std;
#define MAXVEX 100 //��󶨵���
#include "Graph.h"

//������ʱ�־����
bool visited[MAXVEX];

//�ڽӾ�����ȱ������ȵݹ��㷨������ͼ
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

//�ڽӾ������ȱ�������
void DFSTraverse(MGRAPH mGraph)
{
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		visited[i] = false; //��ʼ�����ʱ�־����
	}
	for (int j = 0; j < mGraph.vexnum; j++)
	{
		if (!visited[j])
		{
			DFS(mGraph, j); //��δ���ʵĶ������DFS��������ͨͼ���ִ��һ��
		}
	}
}
