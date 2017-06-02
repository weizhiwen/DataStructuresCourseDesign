#pragma once

#include <iostream>
#define MAX_VERTEX_NUM 20
typedef enum { DG, DN, UDG, UDN }GraphKind; //����ͼ�� �������� ����ͼ�� ������

//���ṹ��
typedef struct ARCCELL
{
	int adj; //����֮����໥��ϵ��������Ȩͼ����1��0��ʾ�Ƿ����ڣ����ڴ�Ȩͼ����ΪȨֵ����
	char *info; //�û���ص���Ϣָ��
}ARCCELL, ADJMATRIX[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

//ͼ����ṹ��
typedef struct MGRAPH
{
	char vers[MAX_VERTEX_NUM]; //��������
	ADJMATRIX arcs; //�ڽӾ���
	int vexnum, arcnum; //ͼ��ǰ��������ͻ�����
	GraphKind kind; //ͼ������
}MGRAPH;

//���Ҷ����ڶ��������е����
int locateVertex(MGRAPH mGraph, char vertex)
{
	int vexnum = mGraph.vexnum;
	for (int i = 0; i < vexnum; i++)
	{
		if (mGraph.vers[i] == vertex)
			return i;
	}
	return -1; //��ʾ�����ڸö���
}

//��������ͼ
void createUDG(MGRAPH &mGraph)
{
	mGraph.kind = UDG;
	printf("����������ͼ�Ķ������ͻ���\n");
	scanf_s("%d%d", &mGraph.vexnum, &mGraph.arcnum);
	//���붥������
	printf("����������ͼ�ĸ�������\n");
	fflush(stdin); //��ջ���������Ӱ�����������
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		scanf_s("%c", &mGraph.vers[i]);
	}
	//�����ڽӾ���
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		for (int j = 0; j < mGraph.vexnum; j++)
		{
			mGraph.arcs[i][j].adj = 0; //��0����ʾ����֮��û�������
			mGraph.arcs[i][j].info = NULL;
		}
	}
	//��������֮��ı߹�ϵ
	for (int k = 0; k < mGraph.arcnum; k++)
	{
		char v1, v2;
		int w = 0;
		printf("����������ͼ����������<V1��V2>\n");
		fflush(stdin);
		printf("���");
		scanf_s("%c", &v1);
		getchar();
		printf("�յ�");
		scanf_s("%c", &v2);
		int i = locateVertex(mGraph, v1);
		int j = locateVertex(mGraph, v2);
		//��������ߵĹ�ϵ
		mGraph.arcs[i][j].adj = 1; 
		mGraph.arcs[j][i].adj = 1;
	}
}

//����������
void createUDN(MGRAPH &mGraph)
{
	mGraph.kind = UDN;
	printf("�������������Ķ������ͻ���\n");
	scanf_s("%d%d", &mGraph.vexnum, &mGraph.arcnum);
	//���붥������
	printf("�������������ĸ�������\n");
	fflush(stdin); //��ջ���������Ӱ�����������
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		scanf_s("%c", &mGraph.vers[i]);
	}
	//�����ڽӾ���
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		for (int j = 0; j < mGraph.vexnum; j++)
		{
			mGraph.arcs[i][j].adj = -1; //��-1�������ɴ�
			mGraph.arcs[i][j].info = NULL;
		}
	}
	//��������֮��Ļ���Ȩֵ
	for (int k = 0; k < mGraph.arcnum; k++)
	{
		char v1, v2;
		int w = 0;
		printf("����������������������֮���Ȩֵ<V1��V2��W>\n");
		fflush(stdin);
		//scanf_s("%c%c%d", &v1, &v2, &w); //���������������⣬�ͳ�������߼������޹�
		printf("Դ����");
		scanf_s("%c", &v1);
		getchar();
		printf("Ŀ�Ķ���");
		scanf_s("%c", &v2);
		getchar();
		printf("Ȩֵ");
		scanf_s("%d", &w);
		int i = locateVertex(mGraph, v1);
		int j = locateVertex(mGraph, v2);
		mGraph.arcs[i][j].adj = w; //����Ȩֵ
		mGraph.arcs[i][j] = mGraph.arcs[j][i]; //�����������㻥ͨ
	}
}


//��������ͼ
void createDG(MGRAPH &mGraph)
{
	mGraph.kind = DG;
	printf("����������ͼ�Ķ������ͻ���\n");
	scanf_s("%d%d", &mGraph.vexnum, &mGraph.arcnum);
	//���붥������
	printf("����������ͼ�ĸ�������\n");
	fflush(stdin); //��ջ���������Ӱ�����������
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		scanf_s("%c", &mGraph.vers[i]);
	}
	//�����ڽӾ���
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		for (int j = 0; j < mGraph.vexnum; j++)
		{
			mGraph.arcs[i][j].adj = 0; //��0����ʾ����֮��û�������
			mGraph.arcs[i][j].info = NULL;
		}
	}
	//��������֮��ı߹�ϵ
	for (int k = 0; k < mGraph.arcnum; k++)
	{
		char v1, v2;
		int w = 0;
		printf("����������ͼ����������<V1��V2>\n");
		fflush(stdin);
		printf("���");
		scanf_s("%c", &v1);
		getchar();
		printf("�յ�");
		scanf_s("%c", &v2);
		int i = locateVertex(mGraph, v1);
		int j = locateVertex(mGraph, v2);
		mGraph.arcs[i][j].adj = 1; //��������ߵĹ�ϵ
	}
}

//����������
void createDN(MGRAPH &mGraph)
{
	mGraph.kind = DN;
	printf("�������������Ķ������ͻ���\n");
	scanf_s("%d%d", &mGraph.vexnum, &mGraph.arcnum);
	//���붥������
	printf("�������������ĸ�������\n");
	fflush(stdin); //��ջ���������Ӱ����������룬��getchar()����Ч��һ��������ȥ��enter����Ӱ��
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		scanf_s("%c", &mGraph.vers[i]);
	}
	//�����ڽӾ���
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		for (int j = 0; j < mGraph.vexnum; j++)
		{
			mGraph.arcs[i][j].adj = -1; //��-1�������ɴ�
			mGraph.arcs[i][j].info = NULL;
		}
	}
	//��������֮��Ļ���Ȩֵ
	for (int k = 0; k < mGraph.arcnum; k++)
	{
		char v1, v2;
		int w = 0;
		printf("����������������������֮���Ȩֵ<V1��V2��W>\n");
		fflush(stdin);
		//scanf_s("%c%c%d", &v1, &v2, &w);
		printf("���");
		scanf_s("%c", &v1);
		getchar();
		printf("�յ�");
		scanf_s("%c", &v2);
		getchar();
		printf("Ȩֵ");
		scanf_s("%d", &w);
		int i = locateVertex(mGraph, v1);
		int j = locateVertex(mGraph, v2);
		mGraph.arcs[i][j].adj = w; //����Ȩֵ
		//mGraph.arcs[i][j] = mGraph.arcs[j][i]; //�����������㵥ͨ
	}
}

//��ӡͼ�������Ϣ
void printGraph(MGRAPH mGraph)
{
	printf("ͼ�и�����Ϊ��\n");
	for (int i = 0; i < mGraph.vexnum; i++)
		printf("%c", mGraph.vers[i]);
	printf("\n�ڽӾ���Ϊ��\n");
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		for (int j = 0; j < mGraph.vexnum; j++)
		{
			if (mGraph.arcs[i][j].adj == -1)
				printf("*");
			else{
				printf("%d\t", mGraph.arcs[i][j].adj);
			}
		}
		printf("\n");
	}
}

//ͼ�ı���