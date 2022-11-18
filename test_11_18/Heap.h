#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HpDataType;

typedef struct Heap
{
	HpDataType* a;
	int size;
	int capacity;
}Heap;


//堆初始化
void HeapInit(Heap* ph);
//堆销毁
void HeapDestroy(Heap* ph);
//堆插入 O(logN)
void HeapPush(Heap* ph, HpDataType x);
//取Top元素
HpDataType HeapTop(Heap* ph);
//交换函数
void Swap(HpDataType* p1, HpDataType* p2);
//向上调整
void AdjustUp(HpDataType* a, int child);
//向下调整
void AdjustDown(HpDataType* a, int size,int parent);
//删除堆顶的数据，并且保持他继续是一个堆 O(logN)
void HeapPop(Heap* ph);
//判空
bool HeapEmpty(Heap* ph);
//返回size
int HeapSize(Heap* ph);
//打印
void HeapPrint(Heap* ph);