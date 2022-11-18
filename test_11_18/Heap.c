#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//�ѳ�ʼ��
void HeapInit(Heap* ph)
{
	assert(ph);
	ph->a = NULL;
	ph->capacity = ph->size = 0;
}
//������
void HeapDestroy(Heap* ph)
{
	assert(ph);
	free(ph->a);
	ph->capacity = ph->size = 0;
}
//�Ѳ���
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

//��������
void Swap(HpDataType* p1, HpDataType* p2)
{
	HpDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//���ϵ���
void AdjustUp(HpDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])  //����Ǵ������ > ��С��Ϊ < 
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

//ȡTopԪ��,�ٽ�ʣ�µ�Ԫ���ٴδ������
HpDataType HeapTop(Heap* ph)
{
	assert(ph);
	assert(ph->size > 0);
	return ph->a[0];
}

//ɾ���Ѷ������ݣ����ұ�����������һ���� O(logN)
void HeapPop(Heap* ph)
{
	assert(ph);
	assert(ph->size > 0);

	Swap(&ph->a[0], &ph->a[ph->size - 1]);
	ph->size--;

	AdjustDown(ph->a, ph->size, 0);
}

//���µ���
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

//�п�
bool HeapEmpty(Heap* ph)
{
	assert(ph);
	return ph->size == 0;
}
//����size
int HeapSize(Heap* ph)
{
	assert(ph);
	return ph->size;
}
//��ӡ
void HeapPrint(Heap* ph)
{
	assert(ph);
	for (int i = 0; i < ph->size; i++)
	{
		printf("%d ",ph->a[i]);
	}
	printf("\n");
}