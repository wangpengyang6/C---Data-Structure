#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"


// �������ش�ͷ˫��ѭ�������ͷ���.
DL* DoubleListInit()
{
	DL*plist = Buynewnode(-1);

	plist->next = plist;
	plist->prev = plist;

	return plist;
}

// ����һ���µĴ�ͷ˫��ѭ������Ľ��
DL* Buynewnode(Datetype x)
{
	DL* newnode = (DL*)malloc(sizeof(DL));
	if (newnode == NULL)
	{
		perror("malloc file\n");
		exit(-1);
	}

	newnode->Data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}


// ��ͷ˫��ѭ������β��
void DoubleListPushBack(DL* plist, Datetype x)
{
	assert(plist);
	DL* newnode = Buynewnode(x);

	DL* tail = plist->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = plist;
	plist->prev = newnode;

	//DoubleListInsert(plist, x);       DoubleListInsert������β�帴��
} 

// ��ͷ˫��ѭ������βɾ
void DoubleListPopBack(DL* plist)
{
	assert(plist);
	assert(plist->next != plist);//�пգ����������ֻ��һ���ڱ�λ��free(tail) ����ڱ�λ�ͷŵ�
	DL* tail = plist->prev;

	tail->prev->next = plist;
	plist->prev = tail->prev;
	

	free(tail);

	//DoubleListErase(plist->prev);  DoubleListErase������βɾ����
}

// ��ͷ˫��ѭ������ͷ��
void DoubleListPushFront(DL* plist, Datetype x)
{
	assert(plist);
	DL* newnode = Buynewnode(x);
	
	newnode->prev = plist;
	newnode->next = plist->next;
	plist->next->prev = newnode;
	plist->next = newnode;


	//DoubleListInsert(plist->next, x);    DoubleListInsert������ͷ�帴��
}

// ��ͷ˫��ѭ������ͷɾ
void DoubleListPopFront(DL* plist)
{
	assert(plist);
	assert(plist->next);
	DL* p = plist->next;
	plist->next = p->next;
	p->next->prev = plist;

	free(p);

	//DoubleListErase(plist->next);  DoubleListErase������ͷɾ
}


// ��ͷ˫��ѭ�������ӡ
void DoubleListPrint(DL* plist)
{
	assert(plist);
	DL* cur = plist->next;
	while (cur != plist)
	{
		printf("%d ",cur->Data);
		cur = cur->next;
	}
	printf("\n");
}

// ��ͷ˫��ѭ���������
DL* DoubleListFind(DL* plist,Datetype x)
{
	assert(plist);
	DL* cur = plist->next;
	while (cur != plist)
	{
		if (cur->Data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ��ͷ˫��ѭ��������pos��ǰ����в���
void DoubleListInsert(DL* pos, Datetype x)
{
	assert(pos);
	DL* prev = pos->prev;
	DL* newnode = Buynewnode(x);
	newnode->prev = prev;
	newnode->next = pos;
	prev->next = newnode;
	pos->prev = newnode;

}

//ע����pos����Ϊͷ C++���ܸ��õĽ��
// 
// ��ͷ˫��ѭ������ɾ��posλ�õĽڵ�
void DoubleListErase(DL* pos)
{
	assert(pos);
	DL* prev = pos->prev;
	DL* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}

//�п�
bool DoubleListEmpty(DL* plist)
{
	assert(plist);
	//if (plist->next == plist)
	//	return true;
	//else
	//	return false;

	return plist->next == plist;
}

// �жϴ�ͷ˫��ѭ�������size
size_t DoubleListSize(DL* plist)
{
	assert(plist);

	DL* cur = plist->next;
	size_t size = 0;
	while (cur != plist)
	{
		size++;
		cur = cur->next;
	}

	return size;
}
// ��ͷ˫��ѭ����������
void DoubleListDestroy(DL* plist)
{
	assert(plist);
	DL* cur = plist->next;
	while (cur != plist)
	{
		DL* next = cur->next;
		free(cur);
		cur = next;
	}
	free(plist);
}