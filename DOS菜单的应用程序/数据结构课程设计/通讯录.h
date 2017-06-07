#pragma once
#include <iostream>
#include <string>
using namespace std;

//����ͨѶ¼����ϵ�˵Ľṹ��
typedef struct TELLPEOPLE
{
	char userName[20];//����
	char tellNumber[15];//�绰����
}TELLPEOPLE;

//����ͨѶ¼������ṹ��
typedef struct LISTTELLPEOPLE
{
	TELLPEOPLE data; //��ϵ�˵���Ϣ
	struct LISTTELLPEOPLE *next;
}LISTTELLPEOPLE, *PLISTTELLPEOPLE;

//����һ���յ�ͨѶ¼
PLISTTELLPEOPLE createTellBook(PLISTTELLPEOPLE T)
{
	T = (LISTTELLPEOPLE*)malloc(sizeof(LISTTELLPEOPLE));
	if (!T)
		printf("ͨѶ¼����ʧ��\a\n");
	else{
		T->data.userName[0] = '\0';
		T->data.tellNumber[0] = '\0';
		T->next = NULL;
		//printf("�������ʼ�������%d���ڵ��ֵ\n", num);
		//PLISTTELLPEOPLE p = T;
		//PLISTTELLPEOPLE q = NULL;//�м���
		//for (int i = 0; i < num; i++)
		//{
		//	q = (LISTTELLPEOPLE*)malloc(sizeof(LISTTELLPEOPLE));
		//	printf("���������ϵ�˵������͵绰��Ϣ\n");
		//	scanf_s("%s%s", &q->data.userName, &q->data.tellNumber);
		//	//�������
		//	p->next = q;//�м���ҵ�������
		//	p = q;//p��λ���ƶ������һ���ڵ���
		//	p->next = NULL;
		//}
	}
	return T;
}

//��ӡ��ϵ�˵���Ϣ����
void printTellPeopleInfo(TELLPEOPLE tellPeople)
{
	printf("%s  %s\n", tellPeople.userName, tellPeople.tellNumber);
}

//����µ���ϵ��,������뷨
void addTellPeople(PLISTTELLPEOPLE L, int i, TELLPEOPLE data)
{
	PLISTTELLPEOPLE p = L;
	int j = 0;
	//pָ���ƶ�������λ�õ�ǰһ�����
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		printf("���ܲ��뵽%dλ�ã�����ʧ�ܣ�\a\n", i);
	else{
		PLISTTELLPEOPLE s = (LISTTELLPEOPLE *)malloc(sizeof(LISTTELLPEOPLE));
		s->data = data;//��ֵ
		s->next = p->next;//����
		p->next = s;//����
		printf("����ɹ���\n");
	}
}
//�����ϵ�ˣ�β�巨
void addTellPeople(PLISTTELLPEOPLE L, TELLPEOPLE data)
{
	PLISTTELLPEOPLE p = L;
	while (p->next)
		p = p->next; //�����ҵ�β���
	PLISTTELLPEOPLE s = (LISTTELLPEOPLE *)malloc(sizeof(LISTTELLPEOPLE));
	s->data = data;//��ֵ
	s->next = NULL;
	p->next = s;//����
	printf("����ɹ���\n");
}

//���ݲ�����ϵ�ˣ��ɸ����������绰���������ַ�ʽ��ѯ
void selectTellPeopleByName(PLISTTELLPEOPLE L)
{
	char userName[20];
	printf("��������Ҫ���ҵ���ϵ�˵�������");
	scanf_s("%s", userName, 20);
	PLISTTELLPEOPLE p = L->next;//����ʱ���������ͷ���
	while (p && strcmp(p->data.userName, userName) != 0)//ע��Ƚ������ַ�������÷�
		p = p->next;
	if (!p)
		printf("û������Ϊ%s����ϵ�ˣ�����ʧ�ܣ�\a\n", userName);
	else{
		//��ӡ�����ҵ�����ϵ�˵���Ϣ
		printTellPeopleInfo(p->data);
	}
}
void selectTellPeopleByTelNumber(PLISTTELLPEOPLE L)
{
	char tellNumber[15];
	printf("��������Ҫ���ҵ���ϵ�˵ĵ绰��");
	scanf_s("%s", tellNumber, 15);
	PLISTTELLPEOPLE p = L->next;//����ʱ���������ͷ���
	while (p && strcmp(p->data.tellNumber, tellNumber) != 0)
		p = p->next;
	if (!p)
		printf("û�е绰����Ϊ%s����ϵ�ˣ�����ʧ�ܣ�\a\n", tellNumber);
	else{
		//��ӡ�����ҵ�����ϵ�˵���Ϣ
		printTellPeopleInfo(p->data);
	}
}

//ɾ�����е���ϵ�ˣ��ɸ����������绰�������ַ�ʽɾ��
void deleteTellPeopleByName(PLISTTELLPEOPLE L)
{
	char userName[20];
	printf("��������Ҫɾ������ϵ�˵�������");
	scanf_s("%s", userName, 20);
	PLISTTELLPEOPLE p = L;
	//pָ���ƶ�������λ�õ�ǰһ�����
	while (p->next && strcmp(p->next->data.userName, userName) != 0)//ע��˴��Ƚϵ��Ǹý�����һ��������
		p = p->next;
	if (!(p->next))
		printf("û������Ϊ%s����ϵ�ˣ�ɾ��ʧ�ܣ�\a\n", userName);
	else{
		PLISTTELLPEOPLE q;
		q = p->next;
		p->next = q->next;
		//��ӡһ��ɾ������ϵ�˵���Ϣ
		printTellPeopleInfo(q->data);
		free(q);//�ͷ�qָ�򼰽����ڴ�
		printf("����ϵ��ɾ���ɹ���");
	}
}
void deleteTellPeopleByTelNumber(PLISTTELLPEOPLE L)
{
	char tellNumber[15];
	printf("��������Ҫɾ������ϵ�˵ĵ绰��");
	scanf_s("%s", tellNumber, 15);
	PLISTTELLPEOPLE p = L;
	//pָ���ƶ�������λ�õ�ǰһ�����
	while (p && strcmp(p->next->data.tellNumber, tellNumber) != 0)
		p = p->next;
	if (!(p->next))
		printf("û�е绰����Ϊ%s����ϵ�ˣ�ɾ��ʧ�ܣ�\a\n", tellNumber);
	else{
		PLISTTELLPEOPLE q;
		q = p->next;
		p->next = q->next;
		//��ӡһ��ɾ������ϵ�˵���Ϣ
		printTellPeopleInfo(q->data);
		free(q);//�ͷ�qָ�򼰽����ڴ�
		printf("����ϵ��ɾ���ɹ���");
	}
}

//�޸����е���ϵ����Ϣ���ɸ����������绰�������ַ�ʽ�޸�
void changeTellPeopleByName(PLISTTELLPEOPLE L)
{
	char userName[20];
	printf("��������Ҫ�޸ĵ���ϵ�˵�������");
	scanf_s("%s", userName, 20);
	PLISTTELLPEOPLE p = L->next;//����ʱ���������ͷ���
	while (p &&  strcmp(p->data.userName, userName) != 0)
	{
		p = p->next;
	}
	if (!p)
		printf("û������Ϊ%s����ϵ�ˣ��޸�ʧ�ܣ�\a\n", userName);
	else{
		//������ϵ�������޸ĵ绰����
		printf("�������޸ĺ�ĵ绰����\n");
		scanf_s("%s", &p->data.tellNumber, 15);
		//��ӡ�޸ĺ����ϵ�˵���Ϣ
		printTellPeopleInfo(p->data);
	}
}
void changeTellPeopleByTelNumber(PLISTTELLPEOPLE L)
{
	char tellNumber[15];
	printf("��������Ҫ�޸ĵ���ϵ�˵ĵ绰��");
	scanf_s("%s", tellNumber, 15);
	PLISTTELLPEOPLE p = L->next;//����ʱ���������ͷ���
	while (p &&  strcmp(p->data.tellNumber, tellNumber) != 0)
	{
		p = p->next;
	}
	if (!p)
		printf("û�е绰����Ϊ%s����ϵ�ˣ��޸�ʧ�ܣ�\a\n", tellNumber);
	else{
		//������ϵ�������޸ĵ绰����
		printf("�������޸ĺ����ϵ�˵�����\n");
		scanf_s("%s", &p->data.userName, 20);
		//��ӡ�޸ĺ����ϵ�˵���Ϣ
		printTellPeopleInfo(p->data);
	}
}

//��ӡ�����绰������ϵ����Ϣ
void printTellBook(PLISTTELLPEOPLE L)
{
	PLISTTELLPEOPLE p = L->next;
	printf("��ϵ������  �绰\n");
	while (p)
	{
		printTellPeopleInfo(p->data);
		p = p->next;
	}
}

void showTellBook()
{
	//����һ���յĵ绰��
	PLISTTELLPEOPLE T = NULL;
	T = createTellBook(T);
	int n;
	do{
		printf("\n");
		printf("****************ͨѶ¼*****************\n");
		printf("* 1  ����µ���ϵ��                   *\n");
		printf("* 2  ����������������ϵ��             *\n");
		printf("* 3  ���ݵ绰������������ϵ��         *\n");
		printf("* 4  ���������޸�����ϵ��             *\n");
		printf("* 5  ���ݵ绰�������޸���ϵ��         *\n");
		printf("* 6  ��������ɾ����ϵ��               *\n");
		printf("* 7  ���ݵ绰����ɾ����ϵ��           *\n");
		printf("* 8  �鿴�����绰������ϵ��           *\n");
		printf("* 9  �˳�                             *\n");
		printf("***************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n){
		case 1:
			printf("--------����µ���ϵ��-------\n");
			{
				TELLPEOPLE tellPeople;
				printf("����������ϵ�˵�����\n");
				scanf_s("%s", &tellPeople.userName, 20);
				printf("����������ϵ�˵ĵ绰����\n");
				scanf_s("%s", &tellPeople.tellNumber, 15);
				printf("��ѡ����ӷ�ʽ\n1������λ�����\n2���绰��β�����\n");
				int flag = 0;
				scanf_s("%d", &flag);
				int i = 0;
				switch (flag)
				{
				case 1:
					printf("��ѡ�����λ�ã�");
					scanf_s("%d", &i);
					addTellPeople(T, i, tellPeople);
					break;
				case 2:
					addTellPeople(T, tellPeople);
					break;
				default:
					printf("�����������\a\n");
					break;
				}
			}
			break;
		case 2:
			printf("--------����������������ϵ��-------\n");
			{
				selectTellPeopleByName(T);
			}
			break;
		case 3:
			printf("--------���ݵ绰������������ϵ��-------\n");
			{
				selectTellPeopleByTelNumber(T);
			}
			break;
		case 4:
			printf("--------���������޸�����ϵ��-------\n");
			{
				changeTellPeopleByName(T);
			}
			break;
		case 5:
			printf("--------���ݵ绰�������޸���ϵ��-------\n");
			{
				changeTellPeopleByTelNumber(T);
			}
			break;
		case 6:
			printf("--------��������ɾ����ϵ��-------\n");
			{
				deleteTellPeopleByName(T);
			}
			break;
		case 7:
			printf("--------���ݵ绰����ɾ����ϵ��-------\n");
			{
				deleteTellPeopleByTelNumber(T);
			}
			break;
		case 8:
			printf("--------�鿴�����绰������ϵ��-------\n");
			printTellBook(T);
			break;
		case 9:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 9);
}