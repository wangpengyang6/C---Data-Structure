#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int Datetype;

typedef struct DoubleList
{
	Datetype Data;
	struct DoubleList* prev;
	struct DoubleList* next;
}DL;


// 创建一个新的带头双向循环链表的结点
DL* Buynewnode(Datetype x);
// 创建返回链表的头结点.
DL* DoubleListInit();
// 带头双向循环链表尾插
void DoubleListPushBack(DL* plist, Datetype x);
// 带头双向循环链表尾删
void DoubleListPopBack(DL* plist);
// 带头双向循环链表头插
void DoubleListPushFront(DL* plist, Datetype x);
// 带头双向循环链表头删
void DoubleListPopFront(DL* plist);
// 带头双向循环链表打印
void DoubleListPrint(DL* plist);
// 带头双向循环链表查找
DL* DoubleListFind(DL* plist,Datetype x);
// 带头双向循环链表在pos的前面进行插入
void DoubleListInsert(DL* pos, Datetype x);
// 带头双向循环链表删除pos位置的节点
void DoubleListErase(DL* pos);
// 判空
bool DoubleListEmpty(DL* plist);
// 判断带头双向循环链表的size
size_t DoubleListSize(DL* plist);
// 带头双向循环链表销毁
void DoubleListDestroy(DL* plist);