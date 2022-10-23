#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

//单链表
typedef struct SlistNode
{
	DataType data;
	struct SlistNode* next;
}Node;

//双向链表
typedef struct DoubleSlistNode
{
	DataType data;
	struct DoubleSlistNode* Left;
	struct DoubleSlistNode* Right;
}DoubleNode;

//创建单链表结点
Node* BuySlistNode(DataType x);
//创建双链表结点
DoubleNode* BuyDoubleSlistNode(DataType x);
//单链表前插
void SlistNodePushFront(Node** pphead, DataType x);
//双链表前插
void DoubleSlistNodePushFront(DoubleNode** pphead, DataType x);
//单链表后插
void SlistNodePushBack(Node** pphead,DataType x);
//双链表后插
void DoubleSlistNodePushBack(DoubleNode** pphead, DataType x);

//单链表打印
void SlistNodePrint(Node* phead);
//双链表正向打印
void DoubleSlistNodePrintLtoR(DoubleNode* phead);


//算法1——求结点个数
int SlistNodeSum(Node* phead);
//算法2——在值为y的前面插入值
void SlistNodeInsertBefore(Node** pphead, DataType y, DataType x);
//算法3——判断结点值是否有序
void SlistNodeJudgeSequence(Node* phead);
//算法4——转置链表
void SlistNodeReverse(Node** pphead);
//算法5——双向链表在值为y的前面插入值
void DoubleSlistNodeInsertBefore(DoubleNode** pphead, DataType y, DataType x);
//算法6——双向链表从右向左打印各个结点值
void DoubleSlistNodePrint(DoubleNode* phead);
