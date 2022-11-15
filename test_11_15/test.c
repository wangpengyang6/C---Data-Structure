#define _CRT_SECURE_NO_WARNINGS 1
typedef int DataType;

typedef struct stack
{
	DataType* a;
	int top;
	int capacity;
}Stack;

//top指向栈最后一个数据的下一个位置

// 初始化栈 
void StackInit(Stack* ps);
// 销毁栈 
void StackDestroy(Stack* ps);
// 入栈 
void StackPush(Stack* ps, DataType x);
// 出栈 
void StackPop(Stack* ps);
// 获取栈顶元素
DataType StackTop(Stack* ps);
// 检测栈是否为空
bool StackEmpty(Stack* ps);
// 获取栈中有效元素个数 
int StackSize(Stack* ps);

// 初始化栈 
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

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a == NULL;
	ps->capacity = ps->top = 0;
}


// 入栈 
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

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	//assert(!StackEmpty(ps));
	ps->top--;
}

// 获取栈顶元素
DataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	//assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

// 检测栈是否为空
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

以上是用C语言模拟实现栈

同两个栈实现队列

思路：一个栈作为入数据栈，另一个栈作为出数据栈
     当入数据栈倒到出数据栈时，此时出数据栈顶元素则为“队列”队首元素
	 出数据时，若出数据栈没数据则需要先倒数据

typedef struct {
	Stack Pushs1;
	Stack Pops2;
} MyQueue;
int myQueuePeek(MyQueue* obj);

创建一个队列，并且对其初始化
MyQueue* myQueueCreate() {
	MyQueue* new = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&new->Pushs1);
	StackInit(&new->Pops2);
	return new;
}

将元素 x 推到队列的末尾
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->Pushs1, x);
}

从队列的开头移除并返回元素
int myQueuePop(MyQueue* obj) {
	int tmp = myQueuePeek(obj);
	StackPop(&obj->Pops2);
	return tmp;
}

返回队列开头的元素
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

如果队列为空，返回 true ；否则，返回 false
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->Pushs1) && StackEmpty(&obj->Pops2);
}

销毁队列
void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->Pushs1);
	StackDestroy(&obj->Pops2);
	free(obj);
	obj = NULL;
}