#pragma once
#include <iostream>
#include <string>
using namespace std;

//定义通讯录中联系人的结构体
typedef struct TELLPEOPLE
{
	char userName[20];//姓名
	char tellNumber[15];//电话号码
}TELLPEOPLE;

//定义通讯录单链表结构体
typedef struct LISTTELLPEOPLE
{
	TELLPEOPLE data; //联系人的信息
	struct LISTTELLPEOPLE *next;
}LISTTELLPEOPLE, *PLISTTELLPEOPLE;

//创建一个空的通讯录
PLISTTELLPEOPLE createTellBook(PLISTTELLPEOPLE T)
{
	T = (LISTTELLPEOPLE*)malloc(sizeof(LISTTELLPEOPLE));
	if (!T)
		printf("通讯录创建失败\a\n");
	else{
		T->data.userName[0] = '\0';
		T->data.tellNumber[0] = '\0';
		T->next = NULL;
		//printf("请输入初始化链表的%d个节点的值\n", num);
		//PLISTTELLPEOPLE p = T;
		//PLISTTELLPEOPLE q = NULL;//中间结点
		//for (int i = 0; i < num; i++)
		//{
		//	q = (LISTTELLPEOPLE*)malloc(sizeof(LISTTELLPEOPLE));
		//	printf("请输入该联系人的姓名和电话信息\n");
		//	scanf_s("%s%s", &q->data.userName, &q->data.tellNumber);
		//	//正向插入
		//	p->next = q;//中间结点挂到链表上
		//	p = q;//p的位置移动到最后一个节点上
		//	p->next = NULL;
		//}
	}
	return T;
}

//打印联系人的信息函数
void printTellPeopleInfo(TELLPEOPLE tellPeople)
{
	printf("%s  %s\n", tellPeople.userName, tellPeople.tellNumber);
}

//添加新的联系人,任意插入法
void addTellPeople(PLISTTELLPEOPLE L, int i, TELLPEOPLE data)
{
	PLISTTELLPEOPLE p = L;
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
		PLISTTELLPEOPLE s = (LISTTELLPEOPLE *)malloc(sizeof(LISTTELLPEOPLE));
		s->data = data;//赋值
		s->next = p->next;//插入
		p->next = s;//挂上
		printf("插入成功！\n");
	}
}
//添加联系人，尾插法
void addTellPeople(PLISTTELLPEOPLE L, TELLPEOPLE data)
{
	PLISTTELLPEOPLE p = L;
	while (p->next)
		p = p->next; //遍历找到尾结点
	PLISTTELLPEOPLE s = (LISTTELLPEOPLE *)malloc(sizeof(LISTTELLPEOPLE));
	s->data = data;//赋值
	s->next = NULL;
	p->next = s;//挂上
	printf("插入成功！\n");
}

//根据查找联系人，可根据姓名，电话号码两种种方式查询
void selectTellPeopleByName(PLISTTELLPEOPLE L)
{
	char userName[20];
	printf("请输入你要查找的联系人的姓名：");
	scanf_s("%s", userName, 20);
	PLISTTELLPEOPLE p = L->next;//查找时跳过链表的头结点
	while (p && strcmp(p->data.userName, userName) != 0)//注意比较两个字符数组的用法
		p = p->next;
	if (!p)
		printf("没有姓名为%s的联系人，查找失败！\a\n", userName);
	else{
		//打印出查找到的联系人的信息
		printTellPeopleInfo(p->data);
	}
}
void selectTellPeopleByTelNumber(PLISTTELLPEOPLE L)
{
	char tellNumber[15];
	printf("请输入你要查找的联系人的电话：");
	scanf_s("%s", tellNumber, 15);
	PLISTTELLPEOPLE p = L->next;//查找时跳过链表的头结点
	while (p && strcmp(p->data.tellNumber, tellNumber) != 0)
		p = p->next;
	if (!p)
		printf("没有电话号码为%s的联系人，查找失败！\a\n", tellNumber);
	else{
		//打印出查找到的联系人的信息
		printTellPeopleInfo(p->data);
	}
}

//删除已有的联系人，可根据姓名，电话号码两种方式删除
void deleteTellPeopleByName(PLISTTELLPEOPLE L)
{
	char userName[20];
	printf("请输入你要删除的联系人的姓名：");
	scanf_s("%s", userName, 20);
	PLISTTELLPEOPLE p = L;
	//p指针移动到插入位置的前一个结点
	while (p->next && strcmp(p->next->data.userName, userName) != 0)//注意此处比较的是该结点的下一结点的内容
		p = p->next;
	if (!(p->next))
		printf("没有姓名为%s的联系人，删除失败！\a\n", userName);
	else{
		PLISTTELLPEOPLE q;
		q = p->next;
		p->next = q->next;
		//打印一下删除的联系人的信息
		printTellPeopleInfo(q->data);
		free(q);//释放q指向及结点的内存
		printf("该联系人删除成功！");
	}
}
void deleteTellPeopleByTelNumber(PLISTTELLPEOPLE L)
{
	char tellNumber[15];
	printf("请输入你要删除的联系人的电话：");
	scanf_s("%s", tellNumber, 15);
	PLISTTELLPEOPLE p = L;
	//p指针移动到插入位置的前一个结点
	while (p && strcmp(p->next->data.tellNumber, tellNumber) != 0)
		p = p->next;
	if (!(p->next))
		printf("没有电话号码为%s的联系人，删除失败！\a\n", tellNumber);
	else{
		PLISTTELLPEOPLE q;
		q = p->next;
		p->next = q->next;
		//打印一下删除的联系人的信息
		printTellPeopleInfo(q->data);
		free(q);//释放q指向及结点的内存
		printf("该联系人删除成功！");
	}
}

//修改已有的联系人信息，可根据姓名，电话号码两种方式修改
void changeTellPeopleByName(PLISTTELLPEOPLE L)
{
	char userName[20];
	printf("请输入你要修改的联系人的姓名：");
	scanf_s("%s", userName, 20);
	PLISTTELLPEOPLE p = L->next;//查找时跳过链表的头结点
	while (p &&  strcmp(p->data.userName, userName) != 0)
	{
		p = p->next;
	}
	if (!p)
		printf("没有姓名为%s的联系人，修改失败！\a\n", userName);
	else{
		//根据联系人姓名修改电话号码
		printf("请输入修改后的电话号码\n");
		scanf_s("%s", &p->data.tellNumber, 15);
		//打印修改后的联系人的信息
		printTellPeopleInfo(p->data);
	}
}
void changeTellPeopleByTelNumber(PLISTTELLPEOPLE L)
{
	char tellNumber[15];
	printf("请输入你要修改的联系人的电话：");
	scanf_s("%s", tellNumber, 15);
	PLISTTELLPEOPLE p = L->next;//查找时跳过链表的头结点
	while (p &&  strcmp(p->data.tellNumber, tellNumber) != 0)
	{
		p = p->next;
	}
	if (!p)
		printf("没有电话号码为%s的联系人，修改失败！\a\n", tellNumber);
	else{
		//根据联系人姓名修改电话号码
		printf("请输入修改后的联系人的姓名\n");
		scanf_s("%s", &p->data.userName, 20);
		//打印修改后的联系人的信息
		printTellPeopleInfo(p->data);
	}
}

//打印整个电话本的联系人信息
void printTellBook(PLISTTELLPEOPLE L)
{
	PLISTTELLPEOPLE p = L->next;
	printf("联系人姓名  电话\n");
	while (p)
	{
		printTellPeopleInfo(p->data);
		p = p->next;
	}
}

void showTellBook()
{
	//创建一个空的电话本
	PLISTTELLPEOPLE T = NULL;
	T = createTellBook(T);
	int n;
	do{
		printf("\n");
		printf("****************通讯录*****************\n");
		printf("* 1  添加新的联系人                   *\n");
		printf("* 2  根据姓名来查找联系人             *\n");
		printf("* 3  根据电话号码来查找联系人         *\n");
		printf("* 4  根据姓名修改来联系人             *\n");
		printf("* 5  根据电话号码来修改联系人         *\n");
		printf("* 6  根据姓名删除联系人               *\n");
		printf("* 7  根据电话号码删除联系人           *\n");
		printf("* 8  查看整个电话本的联系人           *\n");
		printf("* 9  退出                             *\n");
		printf("***************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n){
		case 1:
			printf("--------添加新的联系人-------\n");
			{
				TELLPEOPLE tellPeople;
				printf("请输入新联系人的姓名\n");
				scanf_s("%s", &tellPeople.userName, 20);
				printf("请输入新联系人的电话号码\n");
				scanf_s("%s", &tellPeople.tellNumber, 15);
				printf("请选择添加方式\n1，任意位置添加\n2，电话本尾部添加\n");
				int flag = 0;
				scanf_s("%d", &flag);
				int i = 0;
				switch (flag)
				{
				case 1:
					printf("请选择插入位置：");
					scanf_s("%d", &i);
					addTellPeople(T, i, tellPeople);
					break;
				case 2:
					addTellPeople(T, tellPeople);
					break;
				default:
					printf("不合理的输入\a\n");
					break;
				}
			}
			break;
		case 2:
			printf("--------根据姓名来查找联系人-------\n");
			{
				selectTellPeopleByName(T);
			}
			break;
		case 3:
			printf("--------根据电话号码来查找联系人-------\n");
			{
				selectTellPeopleByTelNumber(T);
			}
			break;
		case 4:
			printf("--------根据姓名修改来联系人-------\n");
			{
				changeTellPeopleByName(T);
			}
			break;
		case 5:
			printf("--------根据电话号码来修改联系人-------\n");
			{
				changeTellPeopleByTelNumber(T);
			}
			break;
		case 6:
			printf("--------根据姓名删除联系人-------\n");
			{
				deleteTellPeopleByName(T);
			}
			break;
		case 7:
			printf("--------根据电话号码删除联系人-------\n");
			{
				deleteTellPeopleByTelNumber(T);
			}
			break;
		case 8:
			printf("--------查看整个电话本的联系人-------\n");
			printTellBook(T);
			break;
		case 9:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 9);
}