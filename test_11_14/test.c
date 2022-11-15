#define _CRT_SECURE_NO_WARNINGS 1


思路：保持一个队列存数据，一个队列为空
      “入栈”进入存数据队列，“出栈”将有数据的队列中前size - 1项导数据到空队列，最后出有数据的队列最后一项

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


// 初始化队列 
void QueueInit(Queue* pq);
// 销毁队列 
void QueueDestroy(Queue* pq);
// 队尾入队列 
void QueuePush(Queue* pq, QDataType x);
// 队头出队列
void QueuePop(Queue* pq);
// 检测队列是否为空
bool QueueEmpty(Queue* pq);
// 获取队列头部元素 
QDataType QueueFront(Queue* pq);
// 获取队列队尾元素 
QDataType QueueBack(Queue* pq);
// 获取队列中有效元素个数 
int QueueSize(Queue* pq);


// 初始化队列 
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

// 销毁队列 
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

// 队尾入队列 
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

// 队头出队列
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

// 检测队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL && pq->tail == NULL;
}

// 获取队列头部元素 
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* pq)
{
	return pq->size;
}

以上是用C语言实现队列

typedef struct {
	Queue p1;
	Queue p2;
} MyStack;       

创建栈
MyStack* myStackCreate() {
	MyStack* new = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&new->p1);
	QueueInit(&new->p2);

	return new;
}

进栈
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

移除并返回栈顶元素
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

返回栈顶元素
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

判断栈是否为空，为空为true
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->p1) && QueueEmpty(&obj->p2);
}

销毁栈
void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->p1);
	QueueDestroy(&obj->p2);
	free(obj);
	obj = NULL;
}