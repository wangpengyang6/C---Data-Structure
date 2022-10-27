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

//���˳�������
void CheckCapacity(SL* phead);
//˳����ʼ��
void SeqlistInit(SL* phead);
//����˳���
void SeqlistDestroy(SL* phead);
//��ӡ˳���
void SeqlistPrint(SL* phead);
//β��
void SeqlistPushBack(SL* phead,Datatype x);
//ͷ��
void SeqlistPushFront(SL* phead, Datatype x);
//ͷɾ
void SeqlistPopFront(SL* phead);
//βɾ
void SeqlistPopBack(SL* phead);
//˳������
void SeqlistFind(SL* phead, Datatype x);
//˳�����posλ�ò���x
void SeqlistInsert(SL* phead, size_t pos, Datatype x);
//˳���ɾ��posλ�õ�ֵ
void SeqlistErase(SL* phead, size_t pos);
//�ı�˳���posλ�õ�ֵ
void SeqlistModify(SL* phead, size_t pos, Datatype x);