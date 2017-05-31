// 数据结构课程设计.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "View.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int userChoice;
	do{
		ShowMainMenu();
		printf("请选择：");
		scanf_s("%d", &userChoice);
		switch (userChoice){
		case 1:LinkList(); break;
		case 2:Stack(); break;
		case 3:Array(); break;
		case 4:BiTree(); break;
		case 5:Graph(); break;
		case 6:break;
		default:printf("ERROR!"); break;
		}
	} while (userChoice != 6);
	system("pause");
	return 0;
}

