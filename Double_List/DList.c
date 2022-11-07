#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"


// 创建返回带头双向循环链表的头结点.
DL* DoubleListInit()
{
	DL*plist = Buynewnode(-1);

	plist->next = plist;
	plist->prev = plist;

	return plist;
}

// 创建一个新的带头双向循环链表的结点
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


// 带头双向循环链表尾插
void DoubleListPushBack(DL* plist, Datetype x)
{
	assert(plist);
	DL* newnode = Buynewnode(x);

	DL* tail = plist->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = plist;
	plist->prev = newnode;

	//DoubleListInsert(plist, x);       DoubleListInsert函数的尾插复用
} 

// 带头双向循环链表尾删
void DoubleListPopBack(DL* plist)
{
	assert(plist);
	assert(plist->next != plist);//判空，如果链表中只有一个哨兵位，free(tail) 会把哨兵位释放掉
	DL* tail = plist->prev;

	tail->prev->next = plist;
	plist->prev = tail->prev;
	

	free(tail);

	//DoubleListErase(plist->prev);  DoubleListErase函数的尾删复用
}

// 带头双向循环链表头插
void DoubleListPushFront(DL* plist, Datetype x)
{
	assert(plist);
	DL* newnode = Buynewnode(x);
	
	newnode->prev = plist;
	newnode->next = plist->next;
	plist->next->prev = newnode;
	plist->next = newnode;


	//DoubleListInsert(plist->next, x);    DoubleListInsert函数的头插复用
}

// 带头双向循环链表头删
void DoubleListPopFront(DL* plist)
{
	assert(plist);
	assert(plist->next);
	DL* p = plist->next;
	plist->next = p->next;
	p->next->prev = plist;

	free(p);

	//DoubleListErase(plist->next);  DoubleListErase函数的头删
}


// 带头双向循环链表打印
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

// 带头双向循环链表查找
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

// 带头双向循环链表在pos的前面进行插入
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

//注：传pos不能为头 C++中能更好的解决
// 
// 带头双向循环链表删除pos位置的节点
void DoubleListErase(DL* pos)
{
	assert(pos);
	DL* prev = pos->prev;
	DL* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}

//判空
bool DoubleListEmpty(DL* plist)
{
	assert(plist);
	//if (plist->next == plist)
	//	return true;
	//else
	//	return false;

	return plist->next == plist;
}

// 判断带头双向循环链表的size
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
// 带头双向循环链表销毁
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