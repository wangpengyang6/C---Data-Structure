#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

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