#pragma once
#include <iostream>
#include "LinkList.h"
#include "ͨѶ¼.h"
#include "Stack.h"
#include "���ʽ���.h"
#include "Array.h"
#include "Binarytree.h"
#include "Graph.h"
#include "ͼ�ı���.h"

//��������溯��

//���˵�
void ShowMainMenu(){
	printf("\n");
	printf("*******************�㷨�����ݽṹ******************\n");
	printf("* 1  ������Ļ���������Ӧ��                       *\n");
	printf("* 2  ջ�Ļ���������Ӧ��                           *\n");
	printf("* 3  ����Ļ���������Ӧ��                         *\n");
	printf("* 4  ���Ļ���������Ӧ��                           *\n");
	printf("* 5  ͼ�Ļ���������Ӧ��                           *\n");
	printf("* 6  �˳�                                         *\n");
	printf("***************************************************\n");
}

//����˵�
void LinkList(){
	int n;
	//������ر���
	PLIST L = NULL;
	int num = 0;
	do{
		printf("\n");
		printf("**************������Ļ���������Ӧ��***************\n");
		printf("* 1  ����                                         *\n");
		printf("* 2  ����                                         *\n");
		printf("* 3  ɾ��                                         *\n");
		printf("* 4  ����                                         *\n");
		printf("* 5  ��ʾ                                         *\n");
		printf("* 6  ͨѶ¼��Ӧ�ã�                               *\n");
		printf("* 7  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n){
		case 1:
			printf("--------����������---------\n");
			{
				printf("�������ʼ��������Ľ�����\n");
				scanf_s("%d", &num);
				L = createList(L, num);
			}
			break;
		case 2:
			printf("--------����Ԫ��-------\n");
			{
				int i , data;
				i = data = 0;
				printf("������Ҫ�����λ�úͲ��������\n");
				scanf_s("%d%d", &i, &data);
				insertNode(L, i, data);
			}
			break;
		case 3:
			printf("--------ɾ��Ԫ��-------\n");
			{
				int i, data;
				i = data = 0;
				printf("������Ҫɾ������λ��\n");
				scanf_s("%d", &i);
				deleteNode(L, i, data);
				printf("��ɾ���Ľ�������ֵΪ%d\n", data);
			}
			break;
		case 4:
			printf("--------����Ԫ��-------\n");
			{
				int i, data;
				i = data = 0;
				printf("������Ҫ���ҵĽ���λ��\n");
				scanf_s("%d", &i);
				selectNode(L, i, data);
				printf("����ҵĽ�������ֵΪ%d\n", data);
			}
			break;
		case 5:
			printf("--------��ʾ����-------\n"); 
			printListNode(L);
			printf("--------��ʾ���-------\n");
			break;
		case 6:
			printf("--------ͨѶ¼---------\n");
			showTellBook();
			break;
		case 7: break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 7);
}

//ջ�˵�
void Stack(){
	int n;
	//ջ��ر���
	STACK s;
	initStack(&s);
	int elem;
	do{
		printf("\n");
		printf("****************ջ�Ļ���������Ӧ��*****************\n");
		printf("* 1  ��ջ                                         *\n");
		printf("* 2  ��ջ                                         *\n");
		printf("* 3  ȡջ��Ԫ��                                   *\n");
		printf("* 4  ���ʽ��⣨Ӧ�ã�                           *\n");
		printf("* 5  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n){
		case 1:
			printf("--------��ջ-------\n");
			{
				printf("������Ҫ��ջ��Ԫ��ֵ\n");
				scanf_s("%d", &elem);
				push(&s, elem);
			}
			break;
		case 2:
			printf("--------��ջ-------\n");
			{
				pop(&s, elem);
				printf("��ջ��ֵΪ%d\n", elem);
			}
			break;
		case 3:
			printf("--------ȡջ��Ԫ��-------\n");
			{
				getTop(&s, elem);
				printf("ջ��Ԫ�ص�ֵΪ%d\n", elem);
			}
			break;
		case 4:
			printf("--------���ʽ��ֵ-------\n");
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

//�������˵�
void Array(){
	int n;
	//������ر���
	TSMATRIX matrix;
	do{
		printf("\n");
		printf("*************ϡ������ѹ���洢��Ӧ��**************\n");
		printf("* 1  ����                                         *\n");
		printf("* 2  ��ʾ                                         *\n");
		printf("* 3  ����˷���Ӧ�ã�                             *\n");
		printf("* 4  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n){
		case 1:
			printf("---------����-------\n"); 
			createTSMATRIX(matrix);
			break;
		case 2:
			printf("---------��ʾ-------\n"); 
			printTSMatrix(matrix);
			break;
		case 3:
			printf("---------����˷�-------\n");
			{
				printf("�������A���Ծ���B�þ���C\n");
				TSMATRIX matrixA, matrixB, matrixC;
				printf("���������A\n");
				createTSMATRIX(matrixA);
				printTSMatrix(matrixA);
				printf("���������B\n");
				createTSMATRIX(matrixB);
				printTSMatrix(matrixB);
				multiplyTSMatrix(matrixA, matrixB, matrixC);
				printf("������������CΪ\n");
				printTSMatrix(matrixC);
			}
			break;
		case 4:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 4);
}

//�������˵�
void BiTree(){
	int n;
	//��������ر���
	PBITREE T;
	do{
		printf("\n");
		printf("**************�������Ļ���������Ӧ��***************\n");
		printf("* 1  ����������                                   *\n");
		printf("* 2  ��������������/��/��                       *\n");
		printf("* 3  �����������                                 *\n");
		printf("* 4  ����Ҷ�ӽ�����                             *\n");
		printf("* 5  ����˫��                                     *\n");
		printf("* 6  �����ֵ�                                     *\n");
		printf("* 7  Huffman���루Ӧ�ã�                          *\n");
		printf("* 8  �˳�\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n){
		case 1:
			printf("---------����������--------\n");
			{
				printf("�ȸ�����������\n");
				createBiTree(T);
			}
			break;
		case 2:
			printf("---------����������-------\n");
			{
				printf("�������������\n");
				preOrderTraverse(T);
				printf("�������������\n");
				inOrderTraverse(T);
				printf("�������������\n");
				postOrderTraverse(T);
			}
			break;
		case 3:
			printf("---------�����������------\n"); 
			printf("�ö����������Ϊ%d", depth(T));
			break;
		case 4:
			printf("---------����Ҷ�ӽ�����-------");
			printf("�ö�������Ҷ�ӽڵ����Ϊ%d", countLeaf(T));
			break;
		case 5:
			printf("---------����˫��-------");
			{
				printf("������Ҫ����˫�׵Ľ���ֵ\n");
				char data;
				scanf_s("%c", &data);
				findParent(T, data);
			}
			break;
		case 6:
			printf("---------�����ֵ�-------");
			{
				printf("������Ҫ�����ֵܵĽ���ֵ");
				char data;
				scanf_s("%c", &data);
				findLSibling(T, data);
				findRSibling(T, data);
			}
			break;
		case 7:
			printf("---------Huffman����-------");
			printf("����δʵ��");
			break;
		case 8:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 8);
}

//ͼ�˵�
void Graph(){
	int n;
	//ͼ��ر���
	MGRAPH mGraph;
	do{
		printf("\n");
		printf("****************ͼ�Ļ���������Ӧ��*****************\n");
		printf("* 1  ��������ͼ                                    *\n");
		printf("* 2  ����������                                    *\n");
		printf("* 3  ��������ͼ                                    *\n");
		printf("* 4  ����������                                    *\n");
		printf("* 5  ����                                          *\n");
		printf("* 6  ��������                                      *\n");
		printf("* 7  ��С��������Ӧ�ã�                            *\n");
		printf("* 8  ���·����Ӧ�ã�                              *\n");
		printf("* 9  �ؼ�·����Ӧ�ã�                              *\n");
		printf("* 10 �˳�                                          *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n){
		case 1:
			printf("---------��������ͼ-------\n");
			{
				
				createUDG(mGraph);
				printf("��ӡ����ͼ\n");
				printGraph(mGraph);
			}
			break;
		case 2:
			printf("---------����������-------\n");
			{
				MGRAPH mGraph;
				createUDN(mGraph);
				printf("��ӡ������\n");
				printGraph(mGraph);
			}
			break;
		case 3:
			printf("---------��������ͼ-------\n");
			{
				MGRAPH mGraph;
				createDG(mGraph);
				printf("��ӡ����ͼ\n");
				printGraph(mGraph);
			}
			break;
		case 4:
			printf("---------����������-------\n");
			{
				MGRAPH mGraph;
				createDN(mGraph);
				printf("��ӡ������\n");
				printGraph(mGraph);
			}
			break;
		case 5:
			printf("---------����-------\n");
			{
				DFSTraverse(mGraph);
			}
			break;
		case 6:
			printf("---------��������-------\n"); break;
		case 7:
			printf("---------��С������-------\n"); break;
		case 8:
			printf("---------���·��-------\n"); break;
		case 9:
			printf("---------�ؼ�·��-------\n"); break;
		case 10:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 10);
}

