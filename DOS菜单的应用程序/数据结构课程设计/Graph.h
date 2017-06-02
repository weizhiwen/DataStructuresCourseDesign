#pragma once

#include <iostream>
#define MAX_VERTEX_NUM 20
typedef enum { DG, DN, UDG, UDN }GraphKind; //有向图， 有向网， 无向图， 无向网

//弧结构体
typedef struct ARCCELL
{
	int adj; //顶点之间的相互关系，对于无权图，用1或0表示是否相邻，对于带权图，则为权值类型
	char *info; //该弧相关的信息指针
}ARCCELL, ADJMATRIX[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

//图矩阵结构体
typedef struct MGRAPH
{
	char vers[MAX_VERTEX_NUM]; //顶点数组
	ADJMATRIX arcs; //邻接矩阵
	int vexnum, arcnum; //图当前顶点个数和弧个数
	GraphKind kind; //图的类型
}MGRAPH;

//查找顶点在顶点数组中的序号
int locateVertex(MGRAPH mGraph, char vertex)
{
	int vexnum = mGraph.vexnum;
	for (int i = 0; i < vexnum; i++)
	{
		if (mGraph.vers[i] == vertex)
			return i;
	}
	return -1; //表示不存在该顶点
}

//创建无向图
void createUDG(MGRAPH &mGraph)
{
	mGraph.kind = UDG;
	printf("请输入无向图的定点数和弧数\n");
	scanf_s("%d%d", &mGraph.vexnum, &mGraph.arcnum);
	//输入顶点数组
	printf("请输入无向图的各个顶点\n");
	fflush(stdin); //清空缓存区，不影响后续的输入
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		scanf_s("%c", &mGraph.vers[i]);
	}
	//构建邻接矩阵
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		for (int j = 0; j < mGraph.vexnum; j++)
		{
			mGraph.arcs[i][j].adj = 0; //用0来表示顶点之间没有有向边
			mGraph.arcs[i][j].info = NULL;
		}
	}
	//构建顶点之间的边关系
	for (int k = 0; k < mGraph.arcnum; k++)
	{
		char v1, v2;
		int w = 0;
		printf("请输入有向图的两个顶点<V1，V2>\n");
		fflush(stdin);
		printf("起点");
		scanf_s("%c", &v1);
		getchar();
		printf("终点");
		scanf_s("%c", &v2);
		int i = locateVertex(mGraph, v1);
		int j = locateVertex(mGraph, v2);
		//赋予无向边的关系
		mGraph.arcs[i][j].adj = 1; 
		mGraph.arcs[j][i].adj = 1;
	}
}

//创建无向网
void createUDN(MGRAPH &mGraph)
{
	mGraph.kind = UDN;
	printf("请输入无向网的定点数和弧数\n");
	scanf_s("%d%d", &mGraph.vexnum, &mGraph.arcnum);
	//输入顶点数组
	printf("请输入无向网的各个顶点\n");
	fflush(stdin); //清空缓存区，不影响后续的输入
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		scanf_s("%c", &mGraph.vers[i]);
	}
	//构建邻接矩阵
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		for (int j = 0; j < mGraph.vexnum; j++)
		{
			mGraph.arcs[i][j].adj = -1; //用-1来代表不可达
			mGraph.arcs[i][j].info = NULL;
		}
	}
	//构建顶点之间的弧和权值
	for (int k = 0; k < mGraph.arcnum; k++)
	{
		char v1, v2;
		int w = 0;
		printf("请输入有向网的两个顶点之间的权值<V1，V2，W>\n");
		fflush(stdin);
		//scanf_s("%c%c%d", &v1, &v2, &w); //程序的输出会有问题，和程序本身的逻辑代码无关
		printf("源顶点");
		scanf_s("%c", &v1);
		getchar();
		printf("目的顶点");
		scanf_s("%c", &v2);
		getchar();
		printf("权值");
		scanf_s("%d", &w);
		int i = locateVertex(mGraph, v1);
		int j = locateVertex(mGraph, v2);
		mGraph.arcs[i][j].adj = w; //赋予权值
		mGraph.arcs[i][j] = mGraph.arcs[j][i]; //无向网两顶点互通
	}
}


//创建有向图
void createDG(MGRAPH &mGraph)
{
	mGraph.kind = DG;
	printf("请输入有向图的定点数和弧数\n");
	scanf_s("%d%d", &mGraph.vexnum, &mGraph.arcnum);
	//输入顶点数组
	printf("请输入有向图的各个顶点\n");
	fflush(stdin); //清空缓存区，不影响后续的输入
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		scanf_s("%c", &mGraph.vers[i]);
	}
	//构建邻接矩阵
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		for (int j = 0; j < mGraph.vexnum; j++)
		{
			mGraph.arcs[i][j].adj = 0; //用0来表示顶点之间没有有向边
			mGraph.arcs[i][j].info = NULL;
		}
	}
	//构建顶点之间的边关系
	for (int k = 0; k < mGraph.arcnum; k++)
	{
		char v1, v2;
		int w = 0;
		printf("请输入有向图的两个顶点<V1，V2>\n");
		fflush(stdin);
		printf("起点");
		scanf_s("%c", &v1);
		getchar();
		printf("终点");
		scanf_s("%c", &v2);
		int i = locateVertex(mGraph, v1);
		int j = locateVertex(mGraph, v2);
		mGraph.arcs[i][j].adj = 1; //赋予有向边的关系
	}
}

//创建有向网
void createDN(MGRAPH &mGraph)
{
	mGraph.kind = DN;
	printf("请输入有向网的定点数和弧数\n");
	scanf_s("%d%d", &mGraph.vexnum, &mGraph.arcnum);
	//输入顶点数组
	printf("请输入有向网的各个顶点\n");
	fflush(stdin); //清空缓存区，不影响后续的输入，和getchar()函数效果一样，都是去除enter键的影响
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		scanf_s("%c", &mGraph.vers[i]);
	}
	//构建邻接矩阵
	for (int i = 0; i < mGraph.vexnum; i++)
	{
		for (int j = 0; j < mGraph.vexnum; j++)
		{
			mGraph.arcs[i][j].adj = -1; //用-1来代表不可达
			mGraph.arcs[i][j].info = NULL;
		}
	}
	//构建顶点之间的弧和权值
	for (int k = 0; k < mGraph.arcnum; k++)
	{
		char v1, v2;
		int w = 0;
		printf("请输入有向网的两个顶点之间的权值<V1，V2，W>\n");
		fflush(stdin);
		//scanf_s("%c%c%d", &v1, &v2, &w);
		printf("起点");
		scanf_s("%c", &v1);
		getchar();
		printf("终点");
		scanf_s("%c", &v2);
		getchar();
		printf("权值");
		scanf_s("%d", &w);
		int i = locateVertex(mGraph, v1);
		int j = locateVertex(mGraph, v2);
		mGraph.arcs[i][j].adj = w; //赋予权值
		//mGraph.arcs[i][j] = mGraph.arcs[j][i]; //无向网两顶点单通
	}
}

//打印图的相关信息
void printGraph(MGRAPH mGraph)
{
	printf("图中各顶点为：\n");
	for (int i = 0; i < mGraph.vexnum; i++)
		printf("%c", mGraph.vers[i]);
	printf("\n邻接矩阵为：\n");
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

//图的遍历