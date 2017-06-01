#pragma once
#include <iostream>

//二叉树的结点结构体
typedef struct BITREENODE
{
	char data;
	struct BITREENODE *lChild, *rChild;
}BITREENODE, *PBITREE;

//先根创建二叉树
void createBiTree(PBITREE &T)
{
	char data;
	data = getchar();
	if (data == ' ')
		T = NULL;
	else{
		if (!(T = (BITREENODE*)malloc(sizeof(BITREENODE))))
			printf("内存分配失败!\a\n");
		else{
			T->data = data;
			createBiTree(T->lChild);
			createBiTree(T->rChild);
		}
	}
}

//先序遍历二叉树
void preOrderTraverse(PBITREE &T)
{
	if (T)
	{
		printf("%c", T->data); //根结点值
		preOrderTraverse(T->lChild); //遍历该节点左子树
		preOrderTraverse(T->rChild); //遍历该节点右子树
	}
}

//中序遍历二叉树
void inOrderTraverse(PBITREE &T)
{
	if (T)
	{
		inOrderTraverse(T->lChild); //遍历该节点左子树
		printf("%c", T->data); //根结点值
		inOrderTraverse(T->rChild); //遍历该节点右子树
	}
}

//后序遍历二叉树
void postOrderTraverse(PBITREE &T)
{
	if (T)
	{
		postOrderTraverse(T->lChild);
		postOrderTraverse(T->rChild);
		printf("%c", T->data);
	}
}

//计算树的深度
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

//计算叶子节点个数
int countLeaf(PBITREE &T)
{
	int static count = 0;
	if (T)
	{
		//判断一个结点是不是叶子节点，就看是否该节点左子树和右子树
		if (T->lChild == NULL && T->rChild == NULL)
			count++;
		countLeaf(T->lChild);
		countLeaf(T->rChild);
	}
	return count;
}

//查找双亲
void findParent(PBITREE &T, char data)
{
	if (T != NULL)
	{
		if (T->data == data)
			printf("该节点为根结点\n");
		if ((T->lChild != NULL && T->lChild->data == data) || (T->rChild != NULL && T->rChild->data == data))
			printf("双亲节点为%c\n", T->data);
		else{
			findParent(T->lChild, data);
			findParent(T->rChild, data);
		}
	}
}

//查找兄弟，包括左兄弟和右兄弟
void findLSibling(PBITREE &T, char data)
{
	if (T != NULL)
	{
		if (T->data == data)
			printf("该节点为根结点，无左兄弟\n");
		else if (T->lChild != NULL && T->lChild->data == data)
			printf("该节点为左节点，无左兄弟\n");
		else if (T->rChild != NULL && T->rChild->data == data)
			printf("该节点的左兄弟为%c\n", T->lChild->data);
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
			printf("该节点为根结点，无右兄弟\n");
		else if (T->rChild != NULL && T->rChild->data == data)
			printf("该节点为右节点，无右兄弟\n");
		else if (T->lChild != NULL && T->lChild->data == data)
			printf("该节点的右兄弟为%c\n", T->lChild->data);
		else{
			findRSibling(T->lChild, data);
			findRSibling(T->rChild, data);
		}
	}
}