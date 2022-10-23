#define _CRT_SECURE_NO_WARNINGS 1
#include"Slistnode.h"

int main()
{
	Node* plist = NULL;
	DoubleNode* Dplist = NULL;
	SlistNodeReverse(&plist);
	//SlistNodePushBack(&plist,1);
	//SlistNodePushBack(&plist,2);
	//SlistNodePushBack(&plist,3);
	//SlistNodePushBack(&plist,4);
	//SlistNodePushBack(&plist,5);

	//printf("目前链表结点个数是:%d\n", SlistNodeSum(plist));
	// 
	//printf("插入前:");
	//SlistNodePrint(plist);

	//SlistNodeInsertBefore(&plist, 50, 10);

	//printf("插入后:");
	//SlistNodePrint(plist);

	//SlistNodeJudgeSequence(plist);
	//SlistNodePrint(plist);

	//printf("转置前:");
	//SlistNodePrint(plist);

	//printf("转置后:");
	//SlistNodeReverse(&plist);
	//SlistNodePrint(plist);



	//DoubleSlistNodePushFront(&Dplist, 1);
	//DoubleSlistNodePushFront(&Dplist, 2);
	//DoubleSlistNodePushFront(&Dplist, 3);
	//DoubleSlistNodePushFront(&Dplist, 4);
	//DoubleSlistNodePushFront(&Dplist, 5);
	//DoubleSlistNodePushFront(&Dplist, 6);



	//printf("插入前:");
	//DoubleSlistNodePrintLtoR(Dplist);
	//DoubleSlistNodeInsertBefore(&Dplist, 100, 9);

	//printf("插入后:");
	//DoubleSlistNodePrintLtoR(Dplist);

	/*SlistNodeInsertBefore(&plist,2, 6);*/

	//printf("从左向右打印为：");
	//DoubleSlistNodePrintLtoR(Dplist);
	//printf("从右向左打印为：");
	//DoubleSlistNodePrint(Dplist);

	/*SlistNodeJudgeSequence(plist);*/
	//SlistNodePrint(plist);

	//SlistNodeReverse(&plist);

	//SlistNodePrint(plist);

	return 0;
}