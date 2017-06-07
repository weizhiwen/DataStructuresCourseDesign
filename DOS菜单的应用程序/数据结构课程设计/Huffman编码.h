#pragma once
#include <iostream>
#define MAX_WEIGHT 10000 //定义字符的最大权值不超过该数
#define MAXSIZE_LEAF 20 //哈夫曼编码的最大位数，即叶子最大数
#define MAXSIZE_NODE MAXSIZE_LEAF * 2 -1 //哈夫曼数的最大结点数
#define MAXSIZE_BIT  100 //位串的最大位数

//定义哈夫曼树的结构体
typedef struct HUFFMANTREE
{
	int weight; //编码元素所占的权值
	int lChild, rChild, parent;
}HUFFMANTREE;

//定义哈夫曼编码的结构体
typedef struct HUFFMANCODE
{
	char bits[MAXSIZE_BIT]; //位串
	int start; //编码在位串中的起始位置
}HUFFMANCODE;

//建立哈夫曼树
void createHuffmanTree(HUFFMANTREE tree[MAXSIZE_NODE], int leafNum)
{
	int nodeNum = 2 * leafNum - 1;
	//先初始化每个哈夫曼树的结点
	for (int i = 0; i < nodeNum; i++)
	{
		tree[i].weight = 0;
		tree[i].parent = -1;
		tree[i].lChild = tree[i].rChild = -1; //-1表示不存在左右孩子
	}
	//printf("依次读入%d个字符的值和权值", leafNum);
	for (int i = 0; i < leafNum; i++)
	{
		printf("请输入第%d个字符的权值：", i + 1);
		scanf_s("%d", &tree[i].weight);
	}
	//找出当前两个权值最小的字符进行合并，循环构建哈夫曼树
	int smallWeight1, smallWeight2; //记录两个最小字符的权值
	int smallIndex1, smallIndex2; //两个字符权值最小的结点的下标
	for (int i = 0; i < leafNum - 1; i++)
	{
		smallWeight1 = smallWeight2 = MAX_WEIGHT; //将最小权值设为设定的最大权值数
		smallIndex1 = smallIndex2 = 0; //每次循环都先置零操作
		//选出两个权值最小的字符结点
		for (int j = 0; j < leafNum + i; j++)
		{
			//对未编码的字符做编码做最小权的操作
			if (tree[j].weight < smallWeight1 && tree[j].parent == -1)
			{
				smallWeight2 = smallWeight1;
				smallIndex2 = smallIndex1;//改变最小权值字符的位置
				smallWeight1 = tree[j].weight; //将编码的最小权值赋值给smallWeight1
				smallIndex1 = j;
			}
			//次小权的操作
			else if (tree[j].weight < smallWeight2 && tree[j].parent == -1)
			{
				smallWeight2 = tree[j].weight;
				smallIndex2 = j;
			}
		}
		tree[smallIndex1].parent = leafNum + i;
		tree[smallIndex2].parent = leafNum + i;
		tree[leafNum + i].weight = tree[smallIndex1].weight + tree[smallIndex2].weight;
		tree[leafNum + i].lChild = smallIndex1; //最小权的根结点是新结点的左孩子
		tree[leafNum + i].rChild = smallIndex2; //次小权的根结点是新结点的右孩子
		//printf("%d： %d, %d\n", i + 1, tree[smallIndex1].weight, tree[smallIndex2].weight);
	}
}

//哈夫曼编码
void huffmanCode()
{
	HUFFMANTREE tree[MAXSIZE_NODE]; //二叉树结点数组
	HUFFMANCODE code[MAXSIZE_LEAF], cd; //编码结构体数组，cd用来存放编码时的信息
	printf("请输入编码的个数：");
	int n = 0;
	scanf_s("%d", &n);
	createHuffmanTree(tree, n);
	int c, p, i, j;
	for (i = 0; i < n; i++)
	{
		cd.start = n - 1;
		c = i;
		p = tree[c].parent;
		//父结点存在
		while (p != -1)
		{
			if (tree[p].lChild == c)
				cd.bits[cd.start] = 0;
			else
				cd.bits[cd.start] = 1;
			cd.start--; //求编码的低一位
			c = p;
			p = tree[c].parent;
		}
		for (j = cd.start + 1; j < n; j++)
		{
			code[i].bits[j] = cd.bits[j];
		}
		code[i].start = cd.start;
	}
	//输出已保存好的所有存在的编码的哈夫曼编码
	for (i = 0; i < n; i++)
	{
		printf("第%d个字符的哈夫曼编码为：", i+1);
		for (int j = code[i].start + 1; j < n; j++)
		{
			printf("%d", code[i].bits[j]);
		}
		printf("\n");
	}
}
