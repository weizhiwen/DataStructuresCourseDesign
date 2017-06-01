#pragma once
#include <iostream>

//�������Ľ��ṹ��
typedef struct BITREENODE
{
	char data;
	struct BITREENODE *lChild, *rChild;
}BITREENODE, *PBITREE;

//�ȸ�����������
void createBiTree(PBITREE &T)
{
	char data;
	data = getchar();
	if (data == ' ')
		T = NULL;
	else{
		if (!(T = (BITREENODE*)malloc(sizeof(BITREENODE))))
			printf("�ڴ����ʧ��!\a\n");
		else{
			T->data = data;
			createBiTree(T->lChild);
			createBiTree(T->rChild);
		}
	}
}

//�������������
void preOrderTraverse(PBITREE &T)
{
	if (T)
	{
		printf("%c", T->data); //�����ֵ
		preOrderTraverse(T->lChild); //�����ýڵ�������
		preOrderTraverse(T->rChild); //�����ýڵ�������
	}
}

//�������������
void inOrderTraverse(PBITREE &T)
{
	if (T)
	{
		inOrderTraverse(T->lChild); //�����ýڵ�������
		printf("%c", T->data); //�����ֵ
		inOrderTraverse(T->rChild); //�����ýڵ�������
	}
}

//�������������
void postOrderTraverse(PBITREE &T)
{
	if (T)
	{
		postOrderTraverse(T->lChild);
		postOrderTraverse(T->rChild);
		printf("%c", T->data);
	}
}

//�����������
int max(int a, int b)
{
	return a > b ? a : b;
}

int depth(PBITREE &T)
{
	if (!T)
		return 0;
	else
		return 1 + max(depth(T->lChild), depth(T->rChild));
}

//����Ҷ�ӽڵ����
int countLeaf(PBITREE &T)
{
	int static count = 0;
	if (T)
	{
		//�ж�һ������ǲ���Ҷ�ӽڵ㣬�Ϳ��Ƿ�ýڵ���������������
		if (T->lChild == NULL && T->rChild == NULL)
			count++;
		countLeaf(T->lChild);
		countLeaf(T->rChild);
	}
	return count;
}

//����˫��
void findParent(PBITREE &T, char data)
{
	if (T != NULL)
	{
		if (T->data == data)
			printf("�ýڵ�Ϊ�����\n");
		if ((T->lChild != NULL && T->lChild->data == data) || (T->rChild != NULL && T->rChild->data == data))
			printf("˫�׽ڵ�Ϊ%c\n", T->data);
		else{
			findParent(T->lChild, data);
			findParent(T->rChild, data);
		}
	}
}

//�����ֵܣ��������ֵܺ����ֵ�
void findLSibling(PBITREE &T, char data)
{
	if (T != NULL)
	{
		if (T->data == data)
			printf("�ýڵ�Ϊ����㣬�����ֵ�\n");
		else if (T->lChild != NULL && T->lChild->data == data)
			printf("�ýڵ�Ϊ��ڵ㣬�����ֵ�\n");
		else if (T->rChild != NULL && T->rChild->data == data)
			printf("�ýڵ�����ֵ�Ϊ%c\n", T->lChild->data);
		else{
			findLSibling(T->lChild, data);
			findLSibling(T->rChild, data);
		}
	}
}

void findRSibling(PBITREE &T, char data)
{
	if (T != NULL)
	{
		if (T->data == data)
			printf("�ýڵ�Ϊ����㣬�����ֵ�\n");
		else if (T->rChild != NULL && T->rChild->data == data)
			printf("�ýڵ�Ϊ�ҽڵ㣬�����ֵ�\n");
		else if (T->lChild != NULL && T->lChild->data == data)
			printf("�ýڵ�����ֵ�Ϊ%c\n", T->lChild->data);
		else{
			findRSibling(T->lChild, data);
			findRSibling(T->rChild, data);
		}
	}
}