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

// Ҫ�ı䴫������ָ���һ���ڵ��ָ��ʹ�����
// ���ı䴫������ָ���һ���ڵ��ָ��ʹ�һ��



//����һ�������½��
SL* BuyListNode(DataType x);
//��ӡ
void SlPrint(SL* phead);
//β��
void SlPushBack(SL** pphead, DataType x);
//ͷ��
void SlPushFront(SL** pphead, DataType x);
//βɾ
void SlPopBack(SL** pphead);
//ͷɾ
void SlPopFront(SL** pphead);
//�ҵ�xֵ�ĵ�ַ
SL* SlFind(SL* phead, DataType x);
//��pos�������һ����
void SlInsertAfter(SL* pos, DataType x);
//��posǰ�����һ����
void SlInsertBefore(SL** pphead, SL* pos, DataType x);
//ɾ��ĳ��λ��
void SlErase(SL** pphead, SL* pos);
//ɾ��ĳ��λ�õĺ�һ��λ��
void SListEraseAfter(SL* pos);
//��������
void SlDestory(SL** pphead);