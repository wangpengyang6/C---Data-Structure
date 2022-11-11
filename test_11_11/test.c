#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
int main()
{
	Stack sk;
	StackInit(&sk);
	StackPush(&sk,1);
	StackPush(&sk,2);
	StackPush(&sk,3);
	StackPush(&sk,4);
	StackPush(&sk,5);
	printf("%d ", StackTop(&sk));
	StackPop(&sk);
	printf("%d ", StackTop(&sk));
	StackPop(&sk);
	printf("%d ", StackTop(&sk));
	StackPop(&sk);
	printf("%d ", StackTop(&sk));
	StackPop(&sk);
	printf("%d ", StackTop(&sk));
	StackPop(&sk);

	StackDestroy(&sk);
	return 0;
}