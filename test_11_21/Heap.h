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
//�ѵĳ�ʼ��
void HeapInit(Heap* hp);
//�ѵĹ���
void CreateHeap(Heap* hp, HpDataType* a,int n);
//������
void HeapSort(HpDataType* a, int size);
//���
void HeapPush(Heap* ph, HpDataType x);
//���ϵ���
void HeapAdjustUp(HpDataType* a, int child);
//���µ���
void HeapAdjustDown(HpDataType*a,int size, int parent);
//��������
void Swap(HpDataType* x1, HpDataType* x2);

