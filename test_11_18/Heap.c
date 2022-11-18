#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//堆初始化
void HeapInit(Heap* ph)
{
	assert(ph);
	ph->a = NULL;
	ph->capacity = ph->size = 0;
}
//堆销毁
void HeapDestroy(Heap* ph)
{
	assert(ph);
	free(ph->a);
	ph->capacity = ph->size = 0;
}
//堆插入
void HeapPush(Heap* ph, HpDataType x)
{
	assert(ph);
	if (ph->capacity == ph->size)
	{
		int newcapacity = ph->capacity == 0 ? 4 : ph->capacity * 2;
		HpDataType*tmp = (HpDataType*)realloc(ph->a, sizeof(HpDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ph->a = tmp;
		ph->capacity = newcapacity;
	}
	ph->a[ph->size] = x;
	ph->size++;
	AdjustUp(ph->a,ph->size-1);
}

//交换函数
void Swap(HpDataType* p1, HpDataType* p2)
{
	HpDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//向上调整
void AdjustUp(HpDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])  //如果是大堆则是 > ，小堆为 < 
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//取Top元素,再将剩下的元素再次大堆排序
HpDataType HeapTop(Heap* ph)
{
	assert(ph);
	assert(ph->size > 0);
	return ph->a[0];
}

//删除堆顶的数据，并且保持他继续是一个堆 O(logN)
void HeapPop(Heap* ph)
{
	assert(ph);
	assert(ph->size > 0);

	Swap(&ph->a[0], &ph->a[ph->size - 1]);
	ph->size--;

	AdjustDown(ph->a, ph->size, 0);
}

//向下调整
void AdjustDown(HpDataType* a, int size,int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			child++;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//判空
bool HeapEmpty(Heap* ph)
{
	assert(ph);
	return ph->size == 0;
}
//返回size
int HeapSize(Heap* ph)
{
	assert(ph);
	return ph->size;
}
//打印
void HeapPrint(Heap* ph)
{
	assert(ph);
	for (int i = 0; i < ph->size; i++)
	{
		printf("%d ",ph->a[i]);
	}
	printf("\n");
}