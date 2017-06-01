#pragma once
#include <iostream>
using namespace std;

//����ͨѶ¼����ϵ�˵Ľṹ��
typedef struct TELLPEOPLE
{
	string userName;//����
	string tellNumber;//�绰����
}TELLPEOPLE;

//����ͨѶ¼������ṹ��
typedef struct LISTTELLPEOPLE
{
	TELLPEOPLE data;
	struct LISTTELLPEOPLE *next;
}LISTTELLPEOPLE, *PLISTTELLPEOPLE;

//����һ���յ�ͨѶ¼
PLISTTELLPEOPLE createTellBook(PLISTTELLPEOPLE T)
{
	T = (LISTTELLPEOPLE*)malloc(sizeof(LISTTELLPEOPLE));
	if (!T)
		printf("ͨѶ¼����ʧ��\a\n");
	else{
		TELLPEOPLE title = { "����", "�绰" };
		T->data = title;
		T->next = NULL;
	}
	return T;
}

//��ӡ��ϵ�˵���Ϣ����
void printTellPeopleInfo(TELLPEOPLE tellPeople)
{
	printf("%s  %s\n", tellPeople.userName, tellPeople.tellNumber);
}

//����µ���ϵ��
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
		printf("����ɹ���\a\n", i);
	}
}

//���ݲ�����ϵ�ˣ��ɸ����������绰���������ַ�ʽ��ѯ
void selectTellPeopleByName(PLISTTELLPEOPLE L, string userName)
{
	PLISTTELLPEOPLE p = L->next;//����ʱ���������ͷ���
	while (p && p->data.userName != userName)
		p = p->next;
	if (!p)
		printf("û������Ϊ%s����ϵ�ˣ�����ʧ�ܣ�\a\n", userName);
	else{
		//��ӡ�����ҵ�����ϵ�˵���Ϣ
		printTellPeopleInfo(p->data);
	}
}
void selectTellPeopleByTelNumber(PLISTTELLPEOPLE L, string tellNumber)
{
	PLISTTELLPEOPLE p = L->next;//����ʱ���������ͷ���
	while (p && p->data.tellNumber != tellNumber)
		p = p->next;
	if (!p)
		printf("û�е绰����Ϊ%s����ϵ�ˣ�����ʧ�ܣ�\a\n", tellNumber);
	else{
		//��ӡ�����ҵ�����ϵ�˵���Ϣ
		printTellPeopleInfo(p->data);
	}
}

//ɾ�����е���ϵ�ˣ��ɸ����������绰�������ַ�ʽɾ��
void deleteTellPeopleByName(PLISTTELLPEOPLE L, string userName)
{
	PLISTTELLPEOPLE p = L;
	//pָ���ƶ�������λ�õ�ǰһ�����
	while (p->next && p->data.userName != userName)
	{
		p = p->next;
	}
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
void deleteTellPeopleByTelNumber(PLISTTELLPEOPLE L, string tellNumber)
{
	PLISTTELLPEOPLE p = L;
	//pָ���ƶ�������λ�õ�ǰһ�����
	while (p->next && p->data.tellNumber != tellNumber)
	{
		p = p->next;
	}
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
void changeTellPeopleByName(PLISTTELLPEOPLE L, string userName)
{
	PLISTTELLPEOPLE p = L->next;//����ʱ���������ͷ���
	int j = 1;
	while (p && p->data.userName != userName)
	{
		p = p->next;
		j++;
	}
	if (!p)
		printf("û������Ϊ%s����ϵ�ˣ��޸�ʧ�ܣ�\a\n", userName);
	else{
		//������ϵ�������޸ĵ绰����
		printf("�������޸ĺ�ĵ绰����\n");
		scanf_s("%s", &p->data.tellNumber);
		//��ӡ�޸ĺ����ϵ�˵���Ϣ
		printTellPeopleInfo(p->data);
	}
}
void changeTellPeopleByTelNumber(PLISTTELLPEOPLE L, string tellNumber)
{
	PLISTTELLPEOPLE p = L->next;//����ʱ���������ͷ���
	int j = 1;
	while (p && p->data.tellNumber != tellNumber)
	{
		p = p->next;
		j++;
	}
	if (!p)
		printf("û�е绰����Ϊ%s����ϵ�ˣ��޸�ʧ�ܣ�\a\n", tellNumber);
	else{
		//������ϵ�������޸ĵ绰����
		printf("�������޸ĺ����ϵ�˵�����\n");
		scanf_s("%s", &p->data.userName);
		//��ӡ�޸ĺ����ϵ�˵���Ϣ
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
			printf("--------����µ���ϵ��-------");
			{
				TELLPEOPLE tellPeople;
				printf("����������ϵ�˵�����\n");
				scanf_s("%s", &tellPeople.userName);
				printf("����������ϵ�˵ĵ绰����\n");
				scanf_s("%s", &tellPeople.tellNumber);
				printf("������Ҫ�����λ��\n");
				int i = 0;
				scanf_s("%d", &i);
				addTellPeople(T, i, tellPeople);
			}
			break;
		case 2:
			printf("--------����������������ϵ��-------");
			{
				printf("������Ҫ��ѯ����ϵ�˵�����\n");
				string userName = NULL;
				scanf_s("%s", &userName);
				selectTellPeopleByName(T, userName);
			}
			break;
		case 3:
			printf("--------���ݵ绰������������ϵ��-------");
			{
				printf("������Ҫ��ѯ����ϵ�˵ĵ绰����\n");
				string tellNumber = NULL;
				scanf_s("%s", &tellNumber);
				selectTellPeopleByTelNumber(T, tellNumber);
			}
			break;
		case 4:
			printf("--------���������޸�����ϵ��-------");
			{
				printf("������Ҫ�޸ĵ���ϵ�˵�����\n");
				string userName = NULL;
				scanf_s("%s", &userName);
				changeTellPeopleByName(T, userName);
			}
			break;
		case 5:
			printf("--------���ݵ绰�������޸���ϵ��-------");
			{
				printf("������Ҫ�޸ĵ���ϵ�˵ĵ绰����\n");
				string tellNumber = NULL;
				scanf_s("%s", &tellNumber);
				changeTellPeopleByTelNumber(T, tellNumber);
			}
			break;
		case 6:
			printf("--------��������ɾ����ϵ��-------");
			{
				printf("������Ҫɾ������ϵ�˵�����\n");
				string userName = NULL;
				scanf_s("%s", &userName);
				deleteTellPeopleByName(T, userName);
			}
			break;
		case 7:
			printf("--------���ݵ绰����ɾ����ϵ��-------");
			{
				printf("������Ҫ�޸ĵ���ϵ�˵ĵ绰����\n");
				string tellNumber = NULL;
				scanf_s("%s", &tellNumber);
				deleteTellPeopleByTelNumber(T, tellNumber);
			}
			break;
		case 8:
			printf("--------�鿴�����绰������ϵ��-------");
			printTellBook(T);
			break;
		case 9:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 9);
}