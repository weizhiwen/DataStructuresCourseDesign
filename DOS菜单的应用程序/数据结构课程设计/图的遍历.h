#pragma once
#include <iostream>
using namespace std;
#define MAXVEX 100 //��󶨵���
#include "Graph.h"
#include "Queue.h"

//������ʱ�־����
bool visited[MAXVEX];

//�ڽӾ�����ȱ������ȵݹ��㷨������ͼ
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

//�ڽӾ���Ĺ�ȱ����㷨
void BFSTraverse(MGRAPH mGraph)
{
	int i, j;
	Queue q;
	for (i = 0; i < mGraph.vexnum; i++)
	{
		visited[i] = false;
	}
	initQueue(&q);
	for (i = 0; i < mGraph.vexnum; i++)//��ÿ��������ѭ��
	{
		if (!visited[i])               //����δ���ʹ�
		{
			visited[i] = true;
			printf("%c ", mGraph.vers[i]); //��ӡ��㣬Ҳ������������
			enQueue(&q, i);           //���˽�������
			while (!isQueueEmpty(&q))     //������Ԫ�س����У���ֵ��
			{
				char m;
				deQueue(&q, m);
				for (j = 0; j < mGraph.vexnum; j++)
				{
					//�ж������������뵱ǰ������ڱ���δ���ʹ�
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
