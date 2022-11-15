#define _CRT_SECURE_NO_WARNINGS 1
typedef int DataType;

typedef struct stack
{
	DataType* a;
	int top;
	int capacity;
}Stack;

//topָ��ջ���һ�����ݵ���һ��λ��

// ��ʼ��ջ 
void StackInit(Stack* ps);
// ����ջ 
void StackDestroy(Stack* ps);
// ��ջ 
void StackPush(Stack* ps, DataType x);
// ��ջ 
void StackPop(Stack* ps);
// ��ȡջ��Ԫ��
DataType StackTop(Stack* ps);
// ���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps);
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = (DataType*)malloc(sizeof(DataType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc file\n");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = 4;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a == NULL;
	ps->capacity = ps->top = 0;
}


// ��ջ 
void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity * 2;
		DataType* tmp = (DataType*)realloc(ps->a, newcapacity * sizeof(DataType));
		if (tmp == NULL)
		{
			perror("realloc file\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	//assert(!StackEmpty(ps));
	ps->top--;
}

// ��ȡջ��Ԫ��
DataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	//assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

// ���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

��������C����ģ��ʵ��ջ

ͬ����ջʵ�ֶ���

˼·��һ��ջ��Ϊ������ջ����һ��ջ��Ϊ������ջ
     ��������ջ����������ջʱ����ʱ������ջ��Ԫ����Ϊ�����С�����Ԫ��
	 ������ʱ����������ջû��������Ҫ�ȵ�����

typedef struct {
	Stack Pushs1;
	Stack Pops2;
} MyQueue;
int myQueuePeek(MyQueue* obj);

����һ�����У����Ҷ����ʼ��
MyQueue* myQueueCreate() {
	MyQueue* new = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&new->Pushs1);
	StackInit(&new->Pops2);
	return new;
}

��Ԫ�� x �Ƶ����е�ĩβ
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->Pushs1, x);
}

�Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
int myQueuePop(MyQueue* obj) {
	int tmp = myQueuePeek(obj);
	StackPop(&obj->Pops2);
	return tmp;
}

���ض��п�ͷ��Ԫ��
int myQueuePeek(MyQueue* obj) {
	if (!StackEmpty(&obj->Pops2))
	{
		return StackTop(&obj->Pops2);
	}
	else
	{
		int size = StackSize(&obj->Pushs1);
		while (size--)
		{
			StackPush(&obj->Pops2, StackTop(&obj->Pushs1));
			StackPop(&obj->Pushs1);
		}
		int tmp = StackTop(&obj->Pops2);
		return tmp;
	}
}

�������Ϊ�գ����� true �����򣬷��� false
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->Pushs1) && StackEmpty(&obj->Pops2);
}

���ٶ���
void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->Pushs1);
	StackDestroy(&obj->Pops2);
	free(obj);
	obj = NULL;
}