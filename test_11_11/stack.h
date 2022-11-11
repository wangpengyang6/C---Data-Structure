#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h.>
#include<stdbool.h>

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