#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"
int main()
{
	DL* plist = DoubleListInit();

	DoubleListPushFront(plist,1);
	DoubleListPushFront(plist,2);
	DoubleListPushFront(plist,3);
	DoubleListPushFront(plist,4);
	DoubleListPushFront(plist,5);
	//DoubleListPrint(plist);
	//DL* pos = DoubleListFind(plist, 3);
	//if (pos)
	//{
	//	(pos->Data) *= 10;
	//}


	/*DoubleListPopBack(plist);
	DoubleListPopBack(plist);
	DoubleListPopBack(plist);
	DoubleListPopBack(plist);
	DoubleListPopBack(plist);*/

	//DoubleListPopFront(plist);
	//DoubleListPopFront(plist);
	//DoubleListPopFront(plist);
	//DoubleListPopFront(plist);

	DoubleListPrint(plist);
	return 0;
}