#define  _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"

void SeqlistInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqlistCheakCapatify(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc error\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqlistPushBack(SL* ps, SLDataType x)
{
	SeqlistCheakCapatify(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqlistPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ",ps->a[i]);
	}
}

void SeqlistDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqlistPopBack(SL* ps)
{
	if (ps->size > 0)
	{
		ps->size--;
	}
}


void SeqlistPushFront(SL* ps, SLDataType x)
{
	SeqlistCheakCapatify(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqlistPopFront(SL* ps)
{
	assert(ps->size > 0);
	int begin = 0;
	while (begin < ps->size - 1)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
}