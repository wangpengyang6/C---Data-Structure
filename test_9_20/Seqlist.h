#pragma once
#define N 100
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;


//动态开辟顺序表
typedef struct Seqlist
{
	SLDataType*a;
	int size ;
	int capacity;
}SL;


//初始化顺序表
void SeqlistInit(SL* ps);
//尾插法
void SeqlistPushBack(SL* ps, SLDataType x);
//尾删
void SeqlistPopBack(SL* ps);
//打印顺序表
void SeqlistPrint(SL* ps);
//释放
void SeqlistDestory(SL* ps);
//头插法
void SeqlistPushFront(SL* ps, SLDataType x);
//头删
void SeqlistPopFront(SL* ps);