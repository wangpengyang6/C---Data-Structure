#define _CRT_SECURE_NO_WARNINGS 1
#include"Slistnode.h"

//������������
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

//����˫������
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

//��������
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

//˫������
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

//������ǰ��
void SlistNodePushFront(Node** pphead, DataType x)
{
	Node* newnode = BuySlistNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}


//˫����ǰ��
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



//�������ӡ
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

//˫���������ӡ
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





//�㷨1�����������
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

//�㷨2������ֵΪy��ǰ�����xֵ
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
			printf("������Ϊyֵ�Ľ��\n");
			return;
		}

		Node* newnode = BuySlistNode(x);
		prev->next = newnode;
		newnode->next = cur;
	}
}

////�㷨3�����жϽ��ֵ�Ƿ�����
void SlistNodeJudgeSequence(Node* phead)
{
	assert(phead);
	assert(phead->next);
	Node* cur = phead;
	Node* Aft = phead->next;

	//�ж��Ƿ�����
	if (cur->data <= Aft->data)
	{
		while (Aft->next)
		{
			cur = cur->next;
			Aft = Aft->next;
			if (cur->data > Aft->data)
			{
				printf("����������\n");
				return;
			}
		}
		printf("��������\n");
	}
	//�ж��Ƿ���
	else if (cur->data >= Aft->data)
	{
		while (Aft->next)
		{
			cur = cur->next;

			Aft = Aft->next;
			if (cur->data < Aft->data)
			{
				printf("����������\n");
				return;
			}
		}
		printf("��������\n");
	}
}

//�㷨4����ת������
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

//�㷨5����˫��������ֵΪy��ǰ�����ֵ
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
			printf("ֵΪy�Ľ�㲻����\n");
			return;
		}

		DoubleNode* newnode = BuyDoubleSlistNode(x);

		newnode->Right = cur;
		newnode->Left = prev;
		prev->Right = newnode;
		cur->Left = newnode;
	}

}


//�㷨6����˫��������������ӡ�������ֵ
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