#pragma once
#include <iostream>
using namespace std;

//定义通讯录中联系人的结构体
typedef struct TELLPEOPLE
{
	string userName;//姓名
	string tellNumber;//电话号码
}TELLPEOPLE;

//定义通讯录单链表结构体
typedef struct LISTTELLPEOPLE
{
	TELLPEOPLE data;
	struct LISTTELLPEOPLE *next;
}LISTTELLPEOPLE, *PLISTTELLPEOPLE;

//创建一个空的通讯录
PLISTTELLPEOPLE createTellBook(PLISTTELLPEOPLE T)
{
	T = (LISTTELLPEOPLE*)malloc(sizeof(LISTTELLPEOPLE));
	if (!T)
		printf("通讯录创建失败\a\n");
	else{
		TELLPEOPLE title = { "姓名", "电话" };
		T->data = title;
		T->next = NULL;
	}
	return T;
}

//打印联系人的信息函数
void printTellPeopleInfo(TELLPEOPLE tellPeople)
{
	printf("%s  %s\n", tellPeople.userName, tellPeople.tellNumber);
}

//添加新的联系人
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
		printf("插入成功！\a\n", i);
	}
}

//根据查找联系人，可根据姓名，电话号码两种种方式查询
void selectTellPeopleByName(PLISTTELLPEOPLE L, string userName)
{
	PLISTTELLPEOPLE p = L->next;//查找时跳过链表的头结点
	while (p && p->data.userName != userName)
		p = p->next;
	if (!p)
		printf("没有姓名为%s的联系人，查找失败！\a\n", userName);
	else{
		//打印出查找到的联系人的信息
		printTellPeopleInfo(p->data);
	}
}
void selectTellPeopleByTelNumber(PLISTTELLPEOPLE L, string tellNumber)
{
	PLISTTELLPEOPLE p = L->next;//查找时跳过链表的头结点
	while (p && p->data.tellNumber != tellNumber)
		p = p->next;
	if (!p)
		printf("没有电话号码为%s的联系人，查找失败！\a\n", tellNumber);
	else{
		//打印出查找到的联系人的信息
		printTellPeopleInfo(p->data);
	}
}

//删除已有的联系人，可根据姓名，电话号码两种方式删除
void deleteTellPeopleByName(PLISTTELLPEOPLE L, string userName)
{
	PLISTTELLPEOPLE p = L;
	//p指针移动到插入位置的前一个结点
	while (p->next && p->data.userName != userName)
	{
		p = p->next;
	}
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
void deleteTellPeopleByTelNumber(PLISTTELLPEOPLE L, string tellNumber)
{
	PLISTTELLPEOPLE p = L;
	//p指针移动到插入位置的前一个结点
	while (p->next && p->data.tellNumber != tellNumber)
	{
		p = p->next;
	}
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
void changeTellPeopleByName(PLISTTELLPEOPLE L, string userName)
{
	PLISTTELLPEOPLE p = L->next;//查找时跳过链表的头结点
	int j = 1;
	while (p && p->data.userName != userName)
	{
		p = p->next;
		j++;
	}
	if (!p)
		printf("没有姓名为%s的联系人，修改失败！\a\n", userName);
	else{
		//根据联系人姓名修改电话号码
		printf("请输入修改后的电话号码\n");
		scanf_s("%s", &p->data.tellNumber);
		//打印修改后的联系人的信息
		printTellPeopleInfo(p->data);
	}
}
void changeTellPeopleByTelNumber(PLISTTELLPEOPLE L, string tellNumber)
{
	PLISTTELLPEOPLE p = L->next;//查找时跳过链表的头结点
	int j = 1;
	while (p && p->data.tellNumber != tellNumber)
	{
		p = p->next;
		j++;
	}
	if (!p)
		printf("没有电话号码为%s的联系人，修改失败！\a\n", tellNumber);
	else{
		//根据联系人姓名修改电话号码
		printf("请输入修改后的联系人的姓名\n");
		scanf_s("%s", &p->data.userName);
		//打印修改后的联系人的信息
		printTellPeopleInfo(p->data);
	}
}


void printTellBook(PLISTTELLPEOPLE L)
{
	PLISTTELLPEOPLE p = L;
	while (!p)
	{
		printTellPeopleInfo(p->data);
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
			printf("--------添加新的联系人-------");
			{
				TELLPEOPLE tellPeople;
				printf("请输入新联系人的姓名\n");
				scanf_s("%s", &tellPeople.userName);
				printf("请输入新联系人的电话号码\n");
				scanf_s("%s", &tellPeople.tellNumber);
				printf("请输入要插入的位置\n");
				int i = 0;
				scanf_s("%d", &i);
				addTellPeople(T, i, tellPeople);
			}
			break;
		case 2:
			printf("--------根据姓名来查找联系人-------");
			{
				printf("请输入要查询的联系人的姓名\n");
				string userName = NULL;
				scanf_s("%s", &userName);
				selectTellPeopleByName(T, userName);
			}
			break;
		case 3:
			printf("--------根据电话号码来查找联系人-------");
			{
				printf("请输入要查询的联系人的电话号码\n");
				string tellNumber = NULL;
				scanf_s("%s", &tellNumber);
				selectTellPeopleByTelNumber(T, tellNumber);
			}
			break;
		case 4:
			printf("--------根据姓名修改来联系人-------");
			{
				printf("请输入要修改的联系人的姓名\n");
				string userName = NULL;
				scanf_s("%s", &userName);
				changeTellPeopleByName(T, userName);
			}
			break;
		case 5:
			printf("--------根据电话号码来修改联系人-------");
			{
				printf("请输入要修改的联系人的电话号码\n");
				string tellNumber = NULL;
				scanf_s("%s", &tellNumber);
				changeTellPeopleByTelNumber(T, tellNumber);
			}
			break;
		case 6:
			printf("--------根据姓名删除联系人-------");
			{
				printf("请输入要删除的联系人的姓名\n");
				string userName = NULL;
				scanf_s("%s", &userName);
				deleteTellPeopleByName(T, userName);
			}
			break;
		case 7:
			printf("--------根据电话号码删除联系人-------");
			{
				printf("请输入要修改的联系人的电话号码\n");
				string tellNumber = NULL;
				scanf_s("%s", &tellNumber);
				deleteTellPeopleByTelNumber(T, tellNumber);
			}
			break;
		case 8:
			printf("--------查看整个电话本的联系人-------");
			printTellBook(T);
			break;
		case 9:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 9);
}