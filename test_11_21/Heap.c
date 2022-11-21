#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"


//��������
void Swap(HpDataType* x1, HpDataType* x2)
{
	HpDataType tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}

//�ѵĳ�ʼ��
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}

//���
void HeapPush(Heap* ph, HpDataType x)
{
	assert(ph);
	if (ph->capacity == ph->size)
	{
		int newcapacity = ph->capacity == 0 ? 4 : ph->capacity * 2;
		HpDataType* tmp = (HpDataType*)realloc(ph->a, sizeof(HpDataType) * newcapacity);
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
	HeapAdjustUp(ph->a, ph->size - 1);
}

////���õĶѵĹ���  ʱ�临�Ӷ�:O(n*logn)
//void CreateHeap(Heap* hp, HpDataType* a, int n)
//{
//	assert(hp);
//	HeapInit(hp);
//	for (int i = 0; i < n; i++)
//	{
//		HeapPush(hp, a[i]);
//	}
//	hp->size = hp->capacity = n;
//}

//�ѵĹ���  ʱ�临�Ӷ�:O(n)
void CreateHeap(Heap* hp, HpDataType* a, int n)
{
	assert(hp);
	hp->a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	if (hp->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	memcpy(hp->a,a,sizeof(HpDataType)*n);
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		HeapAdjustDown(hp->a, n, i);
	}
	hp->size = hp->capacity = n;
}

//���ϵ���
void HeapAdjustUp(HpDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while(child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HeapAdjustDown(HpDataType* a, int size, int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child]) //����������� ����������������ѡһ�����ģ��ٸ�˫�׽���
			                                             //������Ž���,����������������ѡһ����С�ģ��ٸ�˫�׽���
		{
			child++;
		}
		if (a[child] < a[parent])
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

void HeapSort(HpDataType* a, int size)
{
	//����
	for (int i = (size - 2) / 2; i >= 0 ;i--)
	{
		HeapAdjustDown(a, size, i);
	}
	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		HeapAdjustDown(a, end, 0);
		end--;
	}

}