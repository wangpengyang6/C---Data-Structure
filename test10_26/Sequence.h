#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int Datatype;

typedef struct Seqlist
{
	Datatype* a;
	int size;
	int capacity;
}SL;

//检查顺序表容量
void CheckCapacity(SL* phead);
//顺序表初始化
void SeqlistInit(SL* phead);
//销毁顺序表
void SeqlistDestroy(SL* phead);
//打印顺序表
void SeqlistPrint(SL* phead);
//尾插
void SeqlistPushBack(SL* phead,Datatype x);
//头插
void SeqlistPushFront(SL* phead, Datatype x);
//头删
void SeqlistPopFront(SL* phead);
//尾删
void SeqlistPopBack(SL* phead);
//顺序表查找
void SeqlistFind(SL* phead, Datatype x);
//顺序表在pos位置插入x
void SeqlistInsert(SL* phead, size_t pos, Datatype x);
//顺序表删除pos位置的值
void SeqlistErase(SL* phead, size_t pos);
//改变顺序表pos位置的值
void SeqlistModify(SL* phead, size_t pos, Datatype x);