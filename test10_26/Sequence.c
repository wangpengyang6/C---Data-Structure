#define _CRT_SECURE_NO_WARNINGS 1
#include"Sequence.h"


//检查顺序表容量
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

//顺序表初始化
void SeqlistInit(SL* phead)
{
	assert(phead);
	phead->a = NULL;
	phead->capacity = phead->size = 0;
}

//销毁顺序表
void SeqlistDestroy(SL* phead)
{
	assert(phead);
	free(phead->a);
	phead->a = NULL;
	phead->capacity = phead->size = 0;
}

//打印顺序表
void SeqlistPrint(SL* phead)
{
	assert(phead);
	//assert(phead->size);

	if (phead->size == 0)
	{
		printf("顺序表为空");
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

//尾插
void SeqlistPushBack(SL* phead, Datatype x)
{
	assert(phead);

	CheckCapacity(phead);
	phead->a[phead->size] = x;
	(phead->size)++;
}

//头插
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

//头删
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

//尾删
void SeqlistPopBack(SL* phead)
{
	assert(phead);

	assert(phead->size);
	phead->size--;
}

//顺序表查找
void SeqlistFind(SL* phead, Datatype x)
{
	assert(phead);
	for (int i = 0; i < phead->size; i++)
	{
		if (phead->a[i] == x)
		{
			printf("找到了，是顺序表的第%d个元素\n",i+1);
			return;
		}
	}
	printf("没找到，无此数字\n");
}

//顺序表在pos位置插入x
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

//顺序表删除pos位置的值
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

//改变顺序表pos位置的值
void SeqlistModify(SL* phead, size_t pos, Datatype x)
{
	assert(phead);
	assert(pos < phead->size);
	phead->a[pos] = x;
}
