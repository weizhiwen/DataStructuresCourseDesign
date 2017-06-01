#pragma once
#include <iostream>
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 5

//定义栈结构体
typedef struct STACK
{
	int *base;
	int *top;
	int stackSize;
}STACK;

//初始化栈
void initStack(STACK *s)
{
	s->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!(s->base))
		printf("初始化栈失败\a\n");
	else{
		s->top = s->base;
		s->stackSize = STACK_INIT_SIZE;
	}
}

//进栈
void push(STACK *s, int elem)
{
	//栈的空间不够用时自动扩展
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (int*)realloc(s->base, (s->stackSize + STACK_INCREMENT) * sizeof(int));
		if (!(s->base))
			printf("栈扩充失败！\a\n");
		else{
			s->top = s->base + s->stackSize;
			s->stackSize += STACK_INCREMENT;
		}
	}
	*(s->top++) = elem;//压栈
}

//出栈
void pop(STACK *s, int &elem)
{
	if (s->base == s->top)
		printf("栈为空，无元素可以出栈！\a\n");
	elem = *(--s->top);
}

//得到栈顶元素
void getTop(STACK *s, int &elem)
{
	if (s->top == s->base)
		printf("栈为空，无元素可以出栈！\a\n");
	elem = *(s->top - 1);//不改变栈的数据结构
}

