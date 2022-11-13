#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

// ��ʼ������ 
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

// ���ٶ��� 
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* del = cur;
		cur = cur->next;
		free(del);
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

// ��β����� 
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc fild");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}

	pq->size++;
}

// ��ͷ������
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;

	}
	else
	{
		QueueNode* del = pq->head;
		pq->head = pq->head->next;
		free(del);
	}

	pq->size--;

}

// �������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL && pq->tail == NULL;
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* pq)
{
	return pq->size;
}