#define _CRT_SECURE_NO_WARNINGS 1
#include"Slistnode.h"

//创建单链表结点
Node* BuySlistNode(DataType x)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//创建双链表结点
DoubleNode* BuyDoubleSlistNode(DataType x)
{
	DoubleNode* newnode = (DoubleNode*)malloc(sizeof(DoubleNode));
	if (newnode == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	
	newnode->data = x;
	newnode->Left = NULL;
	newnode->Right = NULL;

	return newnode;
}

//单链表后插
void SlistNodePushBack(Node** pphead, DataType x)
{

	Node* newnode = BuySlistNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{

		Node* tail = *pphead;
		while (tail->next )
		{
			tail = tail->next;
		}

		tail->next = newnode;

	}
}

//双链表后插
void DoubleSlistNodePushBack(DoubleNode** pphead, DataType x)
{
	DoubleNode* cur = *pphead;
	DoubleNode* newnode = BuyDoubleSlistNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		DoubleNode* tail = *pphead;
		while (tail->Right)
		{
			tail = tail->Right;
		}
		tail->Right = newnode;
		newnode->Left = tail;
	}
}

//单链表前插
void SlistNodePushFront(Node** pphead, DataType x)
{
	Node* newnode = BuySlistNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}


//双链表前插
void DoubleSlistNodePushFront(DoubleNode** pphead, DataType x)
{
	DoubleNode* cur = *pphead;
	DoubleNode* newnode = BuyDoubleSlistNode(x);
	if (*pphead == NULL)
	{
		;
	}
	else
	{
		cur->Left = newnode;
	}

	newnode->Right = *pphead;
	*pphead = newnode;

}



//单链表打印
void SlistNodePrint(Node* phead)
{

	Node* cur = phead;
	while (cur)
	{
		printf("%d->",cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//双链表正向打印
void DoubleSlistNodePrintLtoR(DoubleNode* phead)
{
	DoubleNode* cur = phead;
	while (cur)
	{
		printf("%d->",cur->data);
		cur = cur->Right;
	}
	printf("NULL\n");
}





//算法1——求结点个数
int SlistNodeSum(Node* phead)
{
	Node* cur = phead;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

//算法2——在值为y的前面插入x值
void SlistNodeInsertBefore(Node** pphead, DataType y, DataType x)
{
	Node* cur = *pphead;
	Node* prev = NULL;
	if ((*pphead)->data == y)
	{
		SlistNodePushFront(pphead, x);
	}
	else
	{
		while (cur)
		{
			if (cur->data == y)
			{
				Node* pos = cur;
				break;
			}
			prev = cur;
			cur = cur->next;
		}
		if (cur == NULL)
		{
			printf("不存在为y值的结点\n");
			return;
		}

		Node* newnode = BuySlistNode(x);
		prev->next = newnode;
		newnode->next = cur;
	}
}

////算法3——判断结点值是否有序
void SlistNodeJudgeSequence(Node* phead)
{
	assert(phead);
	assert(phead->next);
	Node* cur = phead;
	Node* Aft = phead->next;

	//判断是否升序
	if (cur->data <= Aft->data)
	{
		while (Aft->next)
		{
			cur = cur->next;
			Aft = Aft->next;
			if (cur->data > Aft->data)
			{
				printf("程序非有序的\n");
				return;
			}
		}
		printf("程序有序\n");
	}
	//判断是否降序
	else if (cur->data >= Aft->data)
	{
		while (Aft->next)
		{
			cur = cur->next;

			Aft = Aft->next;
			if (cur->data < Aft->data)
			{
				printf("程序非有序的\n");
				return;
			}
		}
		printf("程序有序\n");
	}
}

//算法4——转置链表
void SlistNodeReverse(Node** pphead)
{
	assert(*pphead);
	Node* n1 = NULL;
	Node* n2 = *pphead;
	Node* n3 = (*pphead)->next;
	while (n2)
	{
		n2 -> next= n1;
		n1 = n2;
		n2 = n3;
		if (n3)
		{
			n3 = n3->next;
		}
	}

	*pphead = n1;
}

//算法5——双向链表在值为y的前面插入值
void DoubleSlistNodeInsertBefore(DoubleNode** pphead, DataType y, DataType x)
{
	DoubleNode* cur = *pphead;

	if ((*pphead)->data == y)
	{
		DoubleSlistNodePushFront(pphead,x);
	}
	else
	{
		DoubleNode* prev = NULL;
		while (cur)
		{

			if (cur->data == y)
			{
				prev = cur->Left;
				break;
			}
			cur = cur->Right;
		}
		if (cur == NULL)
		{
			printf("值为y的结点不存在\n");
			return;
		}

		DoubleNode* newnode = BuyDoubleSlistNode(x);

		newnode->Right = cur;
		newnode->Left = prev;
		prev->Right = newnode;
		cur->Left = newnode;
	}

}


//算法6——双向链表从右向左打印各个结点值
void DoubleSlistNodePrint(DoubleNode* phead)
{
	DoubleNode* tail = phead;
	while (tail->Right)
	{
		tail = tail->Right;
	}

	while (tail)
	{
		printf("%d->", tail->data);
		tail = tail->Left;
	}
	printf("NULL\n");
}