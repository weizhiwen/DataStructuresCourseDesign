#pragma once
#include <iostream>
#define MAX_WEIGHT 10000 //�����ַ������Ȩֵ����������
#define MAXSIZE_LEAF 20 //��������������λ������Ҷ�������
#define MAXSIZE_NODE MAXSIZE_LEAF * 2 -1 //�����������������
#define MAXSIZE_BIT  100 //λ�������λ��

//������������Ľṹ��
typedef struct HUFFMANTREE
{
	int weight; //����Ԫ����ռ��Ȩֵ
	int lChild, rChild, parent;
}HUFFMANTREE;

//�������������Ľṹ��
typedef struct HUFFMANCODE
{
	char bits[MAXSIZE_BIT]; //λ��
	int start; //������λ���е���ʼλ��
}HUFFMANCODE;

//������������
void createHuffmanTree(HUFFMANTREE tree[MAXSIZE_NODE], int leafNum)
{
	int nodeNum = 2 * leafNum - 1;
	//�ȳ�ʼ��ÿ�����������Ľ��
	for (int i = 0; i < nodeNum; i++)
	{
		tree[i].weight = 0;
		tree[i].parent = -1;
		tree[i].lChild = tree[i].rChild = -1; //-1��ʾ���������Һ���
	}
	//printf("���ζ���%d���ַ���ֵ��Ȩֵ", leafNum);
	for (int i = 0; i < leafNum; i++)
	{
		printf("�������%d���ַ���Ȩֵ��", i + 1);
		scanf_s("%d", &tree[i].weight);
	}
	//�ҳ���ǰ����Ȩֵ��С���ַ����кϲ���ѭ��������������
	int smallWeight1, smallWeight2; //��¼������С�ַ���Ȩֵ
	int smallIndex1, smallIndex2; //�����ַ�Ȩֵ��С�Ľ����±�
	for (int i = 0; i < leafNum - 1; i++)
	{
		smallWeight1 = smallWeight2 = MAX_WEIGHT; //����СȨֵ��Ϊ�趨�����Ȩֵ��
		smallIndex1 = smallIndex2 = 0; //ÿ��ѭ�������������
		//ѡ������Ȩֵ��С���ַ����
		for (int j = 0; j < leafNum + i; j++)
		{
			//��δ������ַ�����������СȨ�Ĳ���
			if (tree[j].weight < smallWeight1 && tree[j].parent == -1)
			{
				smallWeight2 = smallWeight1;
				smallIndex2 = smallIndex1;//�ı���СȨֵ�ַ���λ��
				smallWeight1 = tree[j].weight; //���������СȨֵ��ֵ��smallWeight1
				smallIndex1 = j;
			}
			//��СȨ�Ĳ���
			else if (tree[j].weight < smallWeight2 && tree[j].parent == -1)
			{
				smallWeight2 = tree[j].weight;
				smallIndex2 = j;
			}
		}
		tree[smallIndex1].parent = leafNum + i;
		tree[smallIndex2].parent = leafNum + i;
		tree[leafNum + i].weight = tree[smallIndex1].weight + tree[smallIndex2].weight;
		tree[leafNum + i].lChild = smallIndex1; //��СȨ�ĸ�������½�������
		tree[leafNum + i].rChild = smallIndex2; //��СȨ�ĸ�������½����Һ���
		//printf("%d�� %d, %d\n", i + 1, tree[smallIndex1].weight, tree[smallIndex2].weight);
	}
}

//����������
void huffmanCode()
{
	HUFFMANTREE tree[MAXSIZE_NODE]; //�������������
	HUFFMANCODE code[MAXSIZE_LEAF], cd; //����ṹ�����飬cd������ű���ʱ����Ϣ
	printf("���������ĸ�����");
	int n = 0;
	scanf_s("%d", &n);
	createHuffmanTree(tree, n);
	int c, p, i, j;
	for (i = 0; i < n; i++)
	{
		cd.start = n - 1;
		c = i;
		p = tree[c].parent;
		//��������
		while (p != -1)
		{
			if (tree[p].lChild == c)
				cd.bits[cd.start] = 0;
			else
				cd.bits[cd.start] = 1;
			cd.start--; //�����ĵ�һλ
			c = p;
			p = tree[c].parent;
		}
		for (j = cd.start + 1; j < n; j++)
		{
			code[i].bits[j] = cd.bits[j];
		}
		code[i].start = cd.start;
	}
	//����ѱ���õ����д��ڵı���Ĺ���������
	for (i = 0; i < n; i++)
	{
		printf("��%d���ַ��Ĺ���������Ϊ��", i+1);
		for (int j = code[i].start + 1; j < n; j++)
		{
			printf("%d", code[i].bits[j]);
		}
		printf("\n");
	}
}
