#pragma once
#include <iostream>
#include "LinkList.h"
#include "通讯录.h"
#include "Stack.h"
#include "表达式求解.h"
#include "Array.h"
#include "Binarytree.h"
#include "Graph.h"
#include "图的遍历.h"

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
				L = createList(L, num);
			}
			break;
		case 2:
			printf("--------插入元素-------\n");
			{
				int i , data;
				i = data = 0;
				printf("请输入要插入的位置和插入的数据\n");
				scanf_s("%d%d", &i, &data);
				insertNode(L, i, data);
			}
			break;
		case 3:
			printf("--------删除元素-------\n");
			{
				int i, data;
				i = data = 0;
				printf("请输入要删除结点的位置\n");
				scanf_s("%d", &i);
				deleteNode(L, i, data);
				printf("你删除的结点的数据值为%d\n", data);
			}
			break;
		case 4:
			printf("--------查找元素-------\n");
			{
				int i, data;
				i = data = 0;
				printf("请输入要查找的结点的位置\n");
				scanf_s("%d", &i);
				selectNode(L, i, data);
				printf("你查找的结点的数据值为%d\n", data);
			}
			break;
		case 5:
			printf("--------显示链表-------\n"); 
			printListNode(L);
			printf("--------显示完毕-------\n");
			break;
		case 6:
			printf("--------通讯录---------\n");
			showTellBook();
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
	//栈相关变量
	STACK s;
	initStack(&s);
	int elem;
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
			printf("--------进栈-------\n");
			{
				printf("请输入要进栈的元素值\n");
				scanf_s("%d", &elem);
				push(&s, elem);
			}
			break;
		case 2:
			printf("--------出栈-------\n");
			{
				pop(&s, elem);
				printf("出栈的值为%d\n", elem);
			}
			break;
		case 3:
			printf("--------取栈顶元素-------\n");
			{
				getTop(&s, elem);
				printf("栈顶元素的值为%d\n", elem);
			}
			break;
		case 4:
			printf("--------表达式求值-------\n");
			{
				solution();
			}
			break;
		case 5:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 5);
}

//数组矩阵菜单
void Array(){
	int n;
	//矩阵相关变量
	TSMATRIX matrix;
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
			printf("---------创建-------\n"); 
			createTSMATRIX(matrix);
			break;
		case 2:
			printf("---------显示-------\n"); 
			printTSMatrix(matrix);
			break;
		case 3:
			printf("---------矩阵乘法-------\n");
			{
				printf("计算矩阵A乘以矩阵B得矩阵C\n");
				TSMATRIX matrixA, matrixB, matrixC;
				printf("请输入矩阵A\n");
				createTSMATRIX(matrixA);
				printTSMatrix(matrixA);
				printf("请输入矩阵B\n");
				createTSMATRIX(matrixB);
				printTSMatrix(matrixB);
				multiplyTSMatrix(matrixA, matrixB, matrixC);
				printf("计算出结果矩阵C为\n");
				printTSMatrix(matrixC);
			}
			break;
		case 4:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 4);
}

//二叉树菜单
void BiTree(){
	int n;
	//二叉树相关变量
	PBITREE T;
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
			printf("---------创建二叉树--------\n");
			{
				printf("先根创建二叉树\n");
				createBiTree(T);
			}
			break;
		case 2:
			printf("---------遍历二叉树-------\n");
			{
				printf("先序遍历二叉树\n");
				preOrderTraverse(T);
				printf("中序遍历二叉树\n");
				inOrderTraverse(T);
				printf("后序遍历二叉树\n");
				postOrderTraverse(T);
			}
			break;
		case 3:
			printf("---------计算树的深度------\n"); 
			printf("该二叉树的深度为%d", depth(T));
			break;
		case 4:
			printf("---------计算叶子结点个数-------");
			printf("该二叉树的叶子节点个数为%d", countLeaf(T));
			break;
		case 5:
			printf("---------查找双亲-------");
			{
				printf("请输入要查找双亲的结点的值\n");
				char data;
				scanf_s("%c", &data);
				findParent(T, data);
			}
			break;
		case 6:
			printf("---------查找兄弟-------");
			{
				printf("请输入要查找兄弟的结点的值");
				char data;
				scanf_s("%c", &data);
				findLSibling(T, data);
				findRSibling(T, data);
			}
			break;
		case 7:
			printf("---------Huffman编码-------");
			printf("功能未实现");
			break;
		case 8:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 8);
}

//图菜单
void Graph(){
	int n;
	//图相关变量
	MGRAPH mGraph;
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
			printf("---------创建无向图-------\n");
			{
				
				createUDG(mGraph);
				printf("打印无向图\n");
				printGraph(mGraph);
			}
			break;
		case 2:
			printf("---------创建无向网-------\n");
			{
				MGRAPH mGraph;
				createUDN(mGraph);
				printf("打印无向网\n");
				printGraph(mGraph);
			}
			break;
		case 3:
			printf("---------创建有向图-------\n");
			{
				MGRAPH mGraph;
				createDG(mGraph);
				printf("打印有向图\n");
				printGraph(mGraph);
			}
			break;
		case 4:
			printf("---------创建有向网-------\n");
			{
				MGRAPH mGraph;
				createDN(mGraph);
				printf("打印有向网\n");
				printGraph(mGraph);
			}
			break;
		case 5:
			printf("---------遍历-------\n");
			{
				DFSTraverse(mGraph);
			}
			break;
		case 6:
			printf("---------拓扑排序-------\n"); break;
		case 7:
			printf("---------最小生成树-------\n"); break;
		case 8:
			printf("---------最短路径-------\n"); break;
		case 9:
			printf("---------关键路径-------\n"); break;
		case 10:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 10);
}

