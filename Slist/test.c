#define  _CRT_SECURE_NO_WARNINGS 1

#include"Slist.h"


int main()
{
	SL* plist = NULL;

	SlPushBack(&plist, 1);
	SlPushBack(&plist, 2);
	SlPushBack(&plist, 3);
	SlPushBack(&plist, 4);

	SlPrint(plist);

	//SlPushFront(&plist, 5);
	//SlPushFront(&plist, 6);

	//SlInsertBefore(&plist, plist->next->next, 9);
	SlErase(&plist, plist->next);
	//SListEraseAfter(plist);
	SlPrint(plist);


	SlPopBack(&plist);
	//SlPopBack(&plist);
	//SlPopBack(&plist);
	//SlPopBack(&plist);
	//SlPopBack(&plist);
	                           

	SlPopFront(&plist);

	SlPrint(plist);


	SlDestory(&plist);


	return 0;
}