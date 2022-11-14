#define _CRT_SECURE_NO_WARNINGS 1


˼·������һ�����д����ݣ�һ������Ϊ��
      ����ջ����������ݶ��У�����ջ���������ݵĶ�����ǰsize - 1����ݵ��ն��У����������ݵĶ������һ��

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

typedef struct {
	Queue p1;
	Queue p2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* new = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&new->p1);
	QueueInit(&new->p2);

	return new;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->p1))
	{
		QueuePush(&obj->p1, x);
	}
	else
	{
		QueuePush(&obj->p2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* empty = &obj->p1;
	Queue* unempty = &obj->p2;
	if (!QueueEmpty(empty))
	{
		empty = &obj->p2;
		unempty = &obj->p1;
	}
	int count = QueueSize(unempty) - 1;
	while (count--)
	{
		QueuePush(empty, QueueFront(unempty));
		QueuePop(unempty);
	}

	int tmp = QueueFront(unempty);
	QueuePop(unempty);
	return tmp;
}

int myStackTop(MyStack* obj) {
	Queue empty = obj->p1;
	Queue unempty = obj->p2;
	if (!QueueEmpty(&empty))
	{
		empty = obj->p2;
		unempty = obj->p1;
	}
	return QueueBack(&unempty);
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->p1) && QueueEmpty(&obj->p2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->p1);
	QueueDestroy(&obj->p2);
	free(obj);
	obj = NULL;
}