#pragma once

#include <iostream>
#define QUEUE_MAXSIZE 20

typedef struct Queue
{
	char data[QUEUE_MAXSIZE]; //ѭ����������
	int front; //����ͷָ��
	int rear; //����βָ�룬�����в�Ϊ����ָ���βԪ�ص���һ��λ��
}Queue;

//��ʼ��һ���ն���
void initQueue(Queue *q)
{
	q->front = 0;
	q->rear = 0;
}

//��ѭ�����еĵ�ǰ���ȣ������е�Ԫ�ظ���
int queueLength(Queue *q)
{
	return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}

//������
int enQueue(Queue *q, char e)
{
	//�ж϶����Ƿ�δ��
	if ((q->rear + 1) % MAXSIZE == q->front)
		return 0;
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
	return 1;
}

//������
int deQueue(Queue *q, char &e)
{
	if (q->rear == q->front)
	{
		printf("����Ϊ�գ�\a\n");
		return 0;
	}
	e = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return 1;
}

//�����Ƿ�Ϊ��
bool isQueueEmpty(Queue *q)
{
	if (q->rear == q->front)
		return true;
	else
		return false;
}
