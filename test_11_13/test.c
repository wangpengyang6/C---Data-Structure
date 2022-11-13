#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
int main()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	printf("%d", QueueEmpty(&q)); 
	QueuePop(&q);

	QueuePush(&q, 2);
	printf("%d", QueueFront(&q));
	QueuePop(&q);

	QueuePush(&q, 3);
	printf("%d", QueueFront(&q));

	//QueuePush(&q, 4);
	//QueuePush(&q, 5);


	//QueuePop(&q);
	//QueuePop(&q);
	//QueuePop(&q);


	QueueDestroy(&q);

	return 0;
}