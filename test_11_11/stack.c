#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

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
		DataType* tmp = (DataType*)realloc(ps->a, newcapacity*sizeof(DataType));
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