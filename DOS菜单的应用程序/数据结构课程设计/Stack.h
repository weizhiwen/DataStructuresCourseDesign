#pragma once
#include <iostream>
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 5

//����ջ�ṹ��
typedef struct STACK
{
	int *base;
	int *top;
	int stackSize;
}STACK;

//��ʼ��ջ
void initStack(STACK *s)
{
	s->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!(s->base))
		printf("��ʼ��ջʧ��\a\n");
	else{
		s->top = s->base;
		s->stackSize = STACK_INIT_SIZE;
	}
}

//��ջ
void push(STACK *s, int elem)
{
	//ջ�Ŀռ䲻����ʱ�Զ���չ
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (int*)realloc(s->base, (s->stackSize + STACK_INCREMENT) * sizeof(int));
		if (!(s->base))
			printf("ջ����ʧ�ܣ�\a\n");
		else{
			s->top = s->base + s->stackSize;
			s->stackSize += STACK_INCREMENT;
		}
	}
	*(s->top++) = elem;//ѹջ
}

//��ջ
void pop(STACK *s, int &elem)
{
	if (s->base == s->top)
		printf("ջΪ�գ���Ԫ�ؿ��Գ�ջ��\a\n");
	elem = *(--s->top);
}

//�õ�ջ��Ԫ��
void getTop(STACK *s, int &elem)
{
	if (s->top == s->base)
		printf("ջΪ�գ���Ԫ�ؿ��Գ�ջ��\a\n");
	elem = *(s->top - 1);//���ı�ջ�����ݽṹ
}

