#pragma once
#include <iostream>
/*
1.可以改进的地方，数据类型是char的，创建链表时把int类型的数据转为char类型的
*/


//定义带头节点的单链表结构体
typedef struct LISTNODE
{
	int data; //结点的数据值
	struct LISTNODE *next; //结点的尾指针
}LISTNODE, *PLIST;

//创建单链表
PLIST createList(PLIST L, int num)
{
	L = (LISTNODE*)malloc(sizeof(LISTNODE));
	if (!L)
		printf("单链表头节点初始化失败\a\n");
	else{
		L->data = num;//头节点用来记录单链表的长度
		L->next = NULL;
		printf("请输入初始化链表的%d个节点的值\n", num);
		PLIST p = L;
		PLIST q = NULL;//中间结点
		for (int i = 0; i < num; i++)
		{
			q = (LISTNODE*)malloc(sizeof(LISTNODE));
			scanf_s("%d", &q->data);
			//正向插入
			p->next = q;//中间结点挂到链表上
			p = q;//p的位置移动到最后一个节点上
			p->next = NULL;
		}
	}
	return L;
}

//单链表任意合法位置插入结点
void insertNode(PLIST L, int i, int data)
{
	PLIST p = L;
	int j = 0;
	//p指针移动到插入位置的前一个结点
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		printf("不能插入到%d位置，插入失败！\a\n", i);
	else{
		PLIST s = (LISTNODE *)malloc(sizeof(LISTNODE));
		s->data = data;//赋值
		s->next = p->next;//插入
		p->next = s;//挂上
		printf("插入成功！\n");
	}
}

//插入的重载函数，在原链表的尾部插入
void insertNode(PLIST L, int data)
{
	PLIST p = L;
	while (p->next)
		p = p->next;//遍历找到尾结点
	PLIST s = (LISTNODE *)malloc(sizeof(LISTNODE));
	s->data = data;//赋值
	s->next = NULL;
	p->next = s; //挂上
	printf("插入成功！\n");
}

//单链表任意合法位置删除结点，将结点的数据值返回给data变量
void deleteNode(PLIST L, int i, int &data)
{
	PLIST p = L;
	int j = 0;
	//p指针移动到插入位置的前一个结点
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)
		printf("没有%d位置的元素，删除失败！\a\n", i);
	else{
		PLIST q;
		q = p->next;
		p->next = q->next;
		data = q->data;
		free(q);//释放q指向及结点的内存
		printf("删除成功！");
	}
}

//单链表根据位置查找结点的数据值，返回给data变量
void selectNode(PLIST L, int i, int &data)
{
	PLIST p = L->next;//查找时跳过链表的头结点
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		printf("没有%d位置的元素，查找失败！\a\n", i);
	else
		data = p->data;//赋值
}

//打印单链表的结点
void printListNode(PLIST L)
{
	PLIST p = L->next;
	int i = 1;//计数变量
	while (p)
	{
		printf("%d : %d\n", i, p->data);
		p = p->next;
		i++;
	}
}