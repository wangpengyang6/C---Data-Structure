#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct Slist
{
	DataType data;
	struct Slist* next;
}SL;

// 要改变传过来的指向第一个节点的指针就传二级
// 不改变传过来的指向第一个节点的指针就传一级



//创建一个链表新结点
SL* BuyListNode(DataType x);
//打印
void SlPrint(SL* phead);
//尾插
void SlPushBack(SL** pphead, DataType x);
//头插
void SlPushFront(SL** pphead, DataType x);
//尾删
void SlPopBack(SL** pphead);
//头删
void SlPopFront(SL** pphead);
//找到x值的地址
SL* SlFind(SL* phead, DataType x);
//在pos后面插入一个数
void SlInsertAfter(SL* pos, DataType x);
//在pos前面插入一个数
void SlInsertBefore(SL** pphead, SL* pos, DataType x);
//删除某个位置
void SlErase(SL** pphead, SL* pos);
//删除某个位置的后一个位置
void SListEraseAfter(SL* pos);
//销毁链表
void SlDestory(SL** pphead);
