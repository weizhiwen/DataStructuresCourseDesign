#pragma once

#include <iostream>
#define QUEUE_MAXSIZE 20

typedef struct Queue
{
	char data[QUEUE_MAXSIZE]; //循环队列数据
	int front; //队列头指针
	int rear; //队列尾指针，若队列不为空则指向队尾元素的下一个位置
}Queue;

//初始化一个空队列
void initQueue(Queue *q)
{
	q->front = 0;
	q->rear = 0;
}

//求循环队列的当前长度，即队列的元素个数
int queueLength(Queue *q)
{
	return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}

//进队列
int enQueue(Queue *q, char e)
{
	//判断队列是否未满
	if ((q->rear + 1) % MAXSIZE == q->front)
		return 0;
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
	return 1;
}

//出队列
int deQueue(Queue *q, char &e)
{
	if (q->rear == q->front)
	{
		printf("队列为空！\a\n");
		return 0;
	}
	e = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return 1;
}

//队列是否为空
bool isQueueEmpty(Queue *q)
{
	if (q->rear == q->front)
		return true;
	else
		return false;
}
