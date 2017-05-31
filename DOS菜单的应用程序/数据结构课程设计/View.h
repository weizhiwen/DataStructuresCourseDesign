#pragma once
#include <iostream>
#include "LinkList.h"

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
				createList(L, num);
			}
			break;
		case 2:
			printf("--------����Ԫ��-------\n");
			{
				int i , data;
				i = data = 0;
				printf("������Ҫ�����λ�úͲ��������");
				scanf_s("%d%d", &i, &data);
				insertNode(L, i, data);
			}
			break;
		case 3:
			printf("--------ɾ��Ԫ��-------\n");
			{
				int i, data;
				i = data = 0;
				printf("������Ҫɾ������λ��");
				scanf_s("%d", &i);
				deleteNode(L, i, data);
				printf("��ɾ���Ľ�������ֵΪ%d", data);
			}
			break;
		case 4:
			printf("--------����Ԫ��-------\n");
			{
				int i, data;
				i = data = 0;
				printf("������Ҫ���ҵĽ���λ��");
				scanf_s("%d", &i);
				selectNode(L, i, data);
				printf("����ҵĽ�������ֵΪ%d", data);
			}
			break;
		case 5:
			printf("--------��ʾ����-------\n"); 
			printListNode(L);
			break;
		case 6:
			printf("--------ͨѶ¼---------\n");
			printf("������ʱû��д");
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
			printf("--------��ջ-------"); break;
		case 2:
			printf("--------��ջ-------"); break;
		case 3:
			printf("--------ȡջ��Ԫ��-------"); break;
		case 4:
			printf("--------���ʽ��ֵ-------"); break;
		case 5:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 5);
}

//�������˵�
void Array(){
	int n;
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
			printf("---------����-------"); break;
		case 2:
			printf("---------��ʾ-------"); break;
		case 3:
			printf("---------����˷�-------"); break;
		case 4:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 4);
}

//�������˵�
void BiTree(){
	int n;
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
			printf("---------����������--------"); break;
		case 2:
			printf("---------*����������-------"); break;
		case 3:
			printf("---------�����������------"); break;
		case 4:
			printf("---------����Ҷ�ӽ�����-------"); break;
		case 5:
			printf("---------����˫��-------"); break;
		case 6:
			printf("---------�����ֵ�-------"); break;
		case 7:
			printf("---------Huffman����-------"); break;
		case 8:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 8);
}

//ͼ�˵�
void Graph(){
	int n;
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
			printf("---------��������ͼ-------"); break;
		case 2:
			printf("---------����������-------"); break;
		case 3:
			printf("---------��������ͼ-------"); break;
		case 4:
			printf("---------����������-------"); break;
		case 5:
			printf("---------����-------"); break;
		case 6:
			printf("---------��������-------"); break;
		case 7:
			printf("---------��С������-------"); break;
		case 8:
			printf("---------���·��-------"); break;
		case 9:
			printf("---------�ؼ�·��-------"); break;
		case 10:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 10);
}

