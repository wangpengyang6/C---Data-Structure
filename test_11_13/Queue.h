#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct Queue* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	int size;
}Queue;


// ��ʼ������ 
void QueueInit(Queue* pq);
// ���ٶ��� 
void QueueDestroy(Queue* pq);
// ��β����� 
void QueuePush(Queue* pq, QDataType x);
// ��ͷ������
void QueuePop(Queue* pq);
// �������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* pq);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* pq);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* pq);