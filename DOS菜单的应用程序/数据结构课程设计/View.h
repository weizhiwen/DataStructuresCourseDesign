#pragma once
#include <iostream>
#include "LinkList.h"

//主程序界面函数

//主菜单
void ShowMainMenu(){
	printf("\n");
	printf("*******************算法与数据结构******************\n");
	printf("* 1  单链表的基本操作及应用                       *\n");
	printf("* 2  栈的基本操作及应用                           *\n");
	printf("* 3  数组的基本操作及应用                         *\n");
	printf("* 4  树的基本操作及应用                           *\n");
	printf("* 5  图的基本操作及应用                           *\n");
	printf("* 6  退出                                         *\n");
	printf("***************************************************\n");
}

//链表菜单
void LinkList(){
	int n;
	//链表相关变量
	PLIST L = NULL;
	int num = 0;

	do{
		printf("\n");
		printf("**************单链表的基本操作及应用***************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  插入                                         *\n");
		printf("* 3  删除                                         *\n");
		printf("* 4  查找                                         *\n");
		printf("* 5  显示                                         *\n");
		printf("* 6  通讯录（应用）                               *\n");
		printf("* 7  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n){
		case 1:
			printf("--------创建单链表---------\n");
			{
				printf("请输入初始化单链表的结点个数\n");
				scanf_s("%d", &num);
				createList(L, num);
			}
			break;
		case 2:
			printf("--------插入元素-------\n");
			{
				int i , data;
				i = data = 0;
				printf("请输入要插入的位置和插入的数据");
				scanf_s("%d%d", &i, &data);
				insertNode(L, i, data);
			}
			break;
		case 3:
			printf("--------删除元素-------\n");
			{
				int i, data;
				i = data = 0;
				printf("请输入要删除结点的位置");
				scanf_s("%d", &i);
				deleteNode(L, i, data);
				printf("你删除的结点的数据值为%d", data);
			}
			break;
		case 4:
			printf("--------查找元素-------\n");
			{
				int i, data;
				i = data = 0;
				printf("请输入要查找的结点的位置");
				scanf_s("%d", &i);
				selectNode(L, i, data);
				printf("你查找的结点的数据值为%d", data);
			}
			break;
		case 5:
			printf("--------显示链表-------\n"); 
			printListNode(L);
			break;
		case 6:
			printf("--------通讯录---------\n");
			printf("功能暂时没有写");
			break;
		case 7: break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 7);
}

//栈菜单
void Stack(){
	int n;
	do{
		printf("\n");
		printf("****************栈的基本操作及应用*****************\n");
		printf("* 1  进栈                                         *\n");
		printf("* 2  出栈                                         *\n");
		printf("* 3  取栈顶元素                                   *\n");
		printf("* 4  表达式求解（应用）                           *\n");
		printf("* 5  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n){
		case 1:
			printf("--------进栈-------"); break;
		case 2:
			printf("--------出栈-------"); break;
		case 3:
			printf("--------取栈顶元素-------"); break;
		case 4:
			printf("--------表达式求值-------"); break;
		case 5:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 5);
}

//数组矩阵菜单
void Array(){
	int n;
	do{
		printf("\n");
		printf("*************稀疏矩阵的压缩存储及应用**************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  显示                                         *\n");
		printf("* 3  矩阵乘法（应用）                             *\n");
		printf("* 4  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n){
		case 1:
			printf("---------创建-------"); break;
		case 2:
			printf("---------显示-------"); break;
		case 3:
			printf("---------矩阵乘法-------"); break;
		case 4:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 4);
}

//二叉树菜单
void BiTree(){
	int n;
	do{
		printf("\n");
		printf("**************二叉树的基本操作及应用***************\n");
		printf("* 1  创建二叉树                                   *\n");
		printf("* 2  遍历二叉树（先/中/后）                       *\n");
		printf("* 3  计算树的深度                                 *\n");
		printf("* 4  计算叶子结点个数                             *\n");
		printf("* 5  查找双亲                                     *\n");
		printf("* 6  查找兄弟                                     *\n");
		printf("* 7  Huffman编码（应用）                          *\n");
		printf("* 8  退出\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n){
		case 1:
			printf("---------创建二叉树--------"); break;
		case 2:
			printf("---------*遍历二叉树-------"); break;
		case 3:
			printf("---------计算树的深度------"); break;
		case 4:
			printf("---------计算叶子结点个数-------"); break;
		case 5:
			printf("---------查找双亲-------"); break;
		case 6:
			printf("---------查找兄弟-------"); break;
		case 7:
			printf("---------Huffman编码-------"); break;
		case 8:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 8);
}

//图菜单
void Graph(){
	int n;
	do{
		printf("\n");
		printf("****************图的基本操作及应用*****************\n");
		printf("* 1  创建无向图                                    *\n");
		printf("* 2  创建无向网                                    *\n");
		printf("* 3  创建有向图                                    *\n");
		printf("* 4  创建有向网                                    *\n");
		printf("* 5  遍历                                          *\n");
		printf("* 6  拓扑排序                                      *\n");
		printf("* 7  最小生成树（应用）                            *\n");
		printf("* 8  最短路径（应用）                              *\n");
		printf("* 9  关键路径（应用）                              *\n");
		printf("* 10 退出                                          *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n){
		case 1:
			printf("---------创建无向图-------"); break;
		case 2:
			printf("---------创建无向网-------"); break;
		case 3:
			printf("---------创建有向图-------"); break;
		case 4:
			printf("---------创建有向网-------"); break;
		case 5:
			printf("---------遍历-------"); break;
		case 6:
			printf("---------拓扑排序-------"); break;
		case 7:
			printf("---------最小生成树-------"); break;
		case 8:
			printf("---------最短路径-------"); break;
		case 9:
			printf("---------关键路径-------"); break;
		case 10:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 10);
}

