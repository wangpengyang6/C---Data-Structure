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


// ����һ���µĴ�ͷ˫��ѭ������Ľ��
DL* Buynewnode(Datetype x);
// �������������ͷ���.
DL* DoubleListInit();
// ��ͷ˫��ѭ������β��
void DoubleListPushBack(DL* plist, Datetype x);
// ��ͷ˫��ѭ������βɾ
void DoubleListPopBack(DL* plist);
// ��ͷ˫��ѭ������ͷ��
void DoubleListPushFront(DL* plist, Datetype x);
// ��ͷ˫��ѭ������ͷɾ
void DoubleListPopFront(DL* plist);
// ��ͷ˫��ѭ�������ӡ
void DoubleListPrint(DL* plist);
// ��ͷ˫��ѭ���������
DL* DoubleListFind(DL* plist,Datetype x);
// ��ͷ˫��ѭ��������pos��ǰ����в���
void DoubleListInsert(DL* pos, Datetype x);
// ��ͷ˫��ѭ������ɾ��posλ�õĽڵ�
void DoubleListErase(DL* pos);
// �п�
bool DoubleListEmpty(DL* plist);
// �жϴ�ͷ˫��ѭ�������size
size_t DoubleListSize(DL* plist);
// ��ͷ˫��ѭ����������
void DoubleListDestroy(DL* plist);