#define  _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"

//创建一个新的结点
SL* BuyListNode(DataType x)
{
	SL* newnode = (SL*)malloc(sizeof(SL));
	if (newnode == NULL)
	{
		printf("malloc errno\n");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode; 
}

//打印
void SlPrint(SL* ps)
{
	SL* cur = ps;
	//while (cur)
	while (cur != NULL)
	{
		printf("%d->",cur->data);
		cur = cur->next;
	}

	printf("NULL\n");
}

//尾插
void SlPushBack(SL** pphead, DataType x)
{

	SL* newnode = BuyListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾
		SL* tail = *pphead;

		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

//头插
void SlPushFront(SL** pphead, DataType x)
{


	SL* newnode = BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//尾删
void SlPopBack(SL** pphead)
{
	assert(*pphead);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SL* end = *pphead;
		SL* prve = NULL;
		while (end->next)
		{
			prve = end;
			end = end->next;
		}

		free(end);
		end = NULL;

		prve->next = NULL;
	}

}

//头删
void SlPopFront(SL** pphead)
{
	assert(*pphead != NULL);
	assert(pphead);

	SL* next = (*pphead)->next;
	free(*pphead);
	
	*pphead = next;

}

//找到x值的地址
SL* SlFind(SL* phead, DataType x)
{
	assert(phead);

	while (phead)
	{
		if (phead->data == x)
		{
			return phead;
		}
		else
		{
			phead = phead->next;
		}
	}
	return NULL;
}

//在pos后面插入一个数
void SlInsertAfter(SL* pos, DataType x)
{
	SL* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//在pos前面插入一个数
void SlInsertBefore(SL** pphead, SL* pos, DataType x)
{
	assert(*pphead);
	assert(pos);

	if (*pphead == pos)
	{
		SlPushFront(pphead,x);
	}
	else
	{
		SL* prev = *pphead;
		while (prev->next != pos)
		{
			prev = (*pphead)->next;
		}

		SL* newnode = BuyListNode(x);
		newnode->next = pos;
		prev->next = newnode;
	}
}

//删除某个位置
void SlErase(SL** pphead, SL* pos)
{
	assert(*pphead);
	assert(pos);
	if(*pphead == pos)
	{
		SlPopFront(pphead);
	}
	else
	{
		SL* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SListEraseAfter(SL* pos)
{
	assert(pos);
	assert(pos->next);

	SL* next = pos->next;
	pos->next = next->next;

	free(next);
	next = NULL;
}

//销毁链表
void SlDestory(SL** pphead)
{
	assert(pphead);

	SL* cur = *pphead;
	while (cur)
	{
		SL* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}