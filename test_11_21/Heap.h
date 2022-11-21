#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>

typedef int HpDataType;

typedef struct Heap
{
	HpDataType* a;
	int size;
	int capacity;
}Heap;
//堆的初始化
void HeapInit(Heap* hp);
//堆的构建
void CreateHeap(Heap* hp, HpDataType* a,int n);
//堆排序
void HeapSort(HpDataType* a, int size);
//后插
void HeapPush(Heap* ph, HpDataType x);
//向上调整
void HeapAdjustUp(HpDataType* a, int child);
//向下调整
void HeapAdjustDown(HpDataType*a,int size, int parent);
//交换函数
void Swap(HpDataType* x1, HpDataType* x2);

