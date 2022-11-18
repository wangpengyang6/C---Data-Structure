#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
int main()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	Heap hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
	{
		HeapPush(&hp, array[i]);
	}
	//HeapInit(&hp);
	//HeapPush(&hp, 25);
	//HeapPush(&hp, 36);
	//HeapPush(&hp, 14);
	//HeapPush(&hp, 87);
	//HeapPush(&hp, 45);
	//HeapPush(&hp, 59);
	//HeapPush(&hp, 100);
	//HeapPush(&hp, 65);
	//HeapPush(&hp, 9);
	//HeapPrint(&hp);
	while (!HeapEmpty(&hp))
	{
		printf("%d\n", HeapTop(&hp));
		HeapPop(&hp);
	}
	//HpDataType tmp =  HeapTop(&hp);
	//HeapPrint(&hp);

	HeapDestroy(&hp);
	return 0;
}