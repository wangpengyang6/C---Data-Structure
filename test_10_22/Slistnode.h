#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

//������
typedef struct SlistNode
{
	DataType data;
	struct SlistNode* next;
}Node;

//˫������
typedef struct DoubleSlistNode
{
	DataType data;
	struct DoubleSlistNode* Left;
	struct DoubleSlistNode* Right;
}DoubleNode;

//������������
Node* BuySlistNode(DataType x);
//����˫������
DoubleNode* BuyDoubleSlistNode(DataType x);
//������ǰ��
void SlistNodePushFront(Node** pphead, DataType x);
//˫����ǰ��
void DoubleSlistNodePushFront(DoubleNode** pphead, DataType x);
//��������
void SlistNodePushBack(Node** pphead,DataType x);
//˫������
void DoubleSlistNodePushBack(DoubleNode** pphead, DataType x);

//�������ӡ
void SlistNodePrint(Node* phead);
//˫���������ӡ
void DoubleSlistNodePrintLtoR(DoubleNode* phead);


//�㷨1�����������
int SlistNodeSum(Node* phead);
//�㷨2������ֵΪy��ǰ�����ֵ
void SlistNodeInsertBefore(Node** pphead, DataType y, DataType x);
//�㷨3�����жϽ��ֵ�Ƿ�����
void SlistNodeJudgeSequence(Node* phead);
//�㷨4����ת������
void SlistNodeReverse(Node** pphead);
//�㷨5����˫��������ֵΪy��ǰ�����ֵ
void DoubleSlistNodeInsertBefore(DoubleNode** pphead, DataType y, DataType x);
//�㷨6����˫��������������ӡ�������ֵ
void DoubleSlistNodePrint(DoubleNode* phead);
