#define _CRT_SECURE_NO_WARNINGS 1
#include"Sequence.h"


//���˳�������
void CheckCapacity(SL* phead)
{
	if (phead->size == phead->capacity)
	{
		int newcapacity = phead->capacity == 0 ? 4 : 2 * phead->capacity;
		Datatype* tmp = (Datatype*)realloc(phead->a, newcapacity * sizeof(Datatype));
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			exit(-1);
		}
		phead->a = tmp;
		phead->capacity = newcapacity;
	}
}

//˳����ʼ��
void SeqlistInit(SL* phead)
{
	assert(phead);
	phead->a = NULL;
	phead->capacity = phead->size = 0;
}

//����˳���
void SeqlistDestroy(SL* phead)
{
	assert(phead);
	free(phead->a);
	phead->a = NULL;
	phead->capacity = phead->size = 0;
}

//��ӡ˳���
void SeqlistPrint(SL* phead)
{
	assert(phead);
	//assert(phead->size);

	if (phead->size == 0)
	{
		printf("˳���Ϊ��");
	}
	else
	{
		for (int i = 0; i < phead->size; i++)
		{
			printf("%d ",phead->a[i]);
		}
		printf("\n");
	}
}

//β��
void SeqlistPushBack(SL* phead, Datatype x)
{
	assert(phead);

	CheckCapacity(phead);
	phead->a[phead->size] = x;
	(phead->size)++;
}

//ͷ��
void SeqlistPushFront(SL* phead, Datatype x)
{
	assert(phead);

	CheckCapacity(phead);
	for (int i = phead->size; i > 0; i--)
	{
		phead->a[i] = phead->a[i - 1];
	}
	phead->a[0] = x;
	phead->size++;
}

//ͷɾ
void SeqlistPopFront(SL* phead)
{
	assert(phead);

	assert(phead->size);
	for (int i = 1; i < phead->size; i++)
	{
		phead->a[i - 1] = phead->a[i];
	}
	phead->size--;
}

//βɾ
void SeqlistPopBack(SL* phead)
{
	assert(phead);

	assert(phead->size);
	phead->size--;
}

//˳������
void SeqlistFind(SL* phead, Datatype x)
{
	assert(phead);
	for (int i = 0; i < phead->size; i++)
	{
		if (phead->a[i] == x)
		{
			printf("�ҵ��ˣ���˳���ĵ�%d��Ԫ��\n",i+1);
			return;
		}
	}
	printf("û�ҵ����޴�����\n");
}

//˳�����posλ�ò���x
void SeqlistInsert(SL* phead, size_t pos, Datatype x)
{
	assert(phead);
	assert(pos <= phead->size);
	CheckCapacity(phead);

	size_t end = phead->size;
	while (end > pos)
	{
		phead->a[end] = phead->a[end - 1];
		end--;
	}
	phead->a[pos] = x;
	phead->size++;
}

//˳���ɾ��posλ�õ�ֵ
void SeqlistErase(SL* phead, size_t pos)
{
	assert(phead);
	assert(pos < phead->size);
	for (int i = pos; i < phead->size-1; i++)
	{
		phead->a[i] = phead->a[i + 1];
	}
	phead->size--;
}

//�ı�˳���posλ�õ�ֵ
void SeqlistModify(SL* phead, size_t pos, Datatype x)
{
	assert(phead);
	assert(pos < phead->size);
	phead->a[pos] = x;
}
