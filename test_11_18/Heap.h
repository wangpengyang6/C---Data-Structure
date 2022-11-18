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


//�ѳ�ʼ��
void HeapInit(Heap* ph);
//������
void HeapDestroy(Heap* ph);
//�Ѳ��� O(logN)
void HeapPush(Heap* ph, HpDataType x);
//ȡTopԪ��
HpDataType HeapTop(Heap* ph);
//��������
void Swap(HpDataType* p1, HpDataType* p2);
//���ϵ���
void AdjustUp(HpDataType* a, int child);
//���µ���
void AdjustDown(HpDataType* a, int size,int parent);
//ɾ���Ѷ������ݣ����ұ�����������һ���� O(logN)
void HeapPop(Heap* ph);
//�п�
bool HeapEmpty(Heap* ph);
//����size
int HeapSize(Heap* ph);
//��ӡ
void HeapPrint(Heap* ph);