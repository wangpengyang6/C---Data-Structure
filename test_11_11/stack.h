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