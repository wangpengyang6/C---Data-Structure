#define  _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"

int main()
{
	SL sl;
	SeqlistInit(&sl);
	
	SeqlistPushBack(&sl,1);
	SeqlistPushBack(&sl,2);
	SeqlistPushBack(&sl,3);
	SeqlistPushBack(&sl,4);
	SeqlistPushBack(&sl,5);

	SeqlistPrint(&sl);
	printf("\n");
	
	//SeqlistPopBack(&sl);
	//SeqlistPopBack(&sl);

	SeqlistPushFront(&sl, 10);
	SeqlistPushFront(&sl, 20);

	SeqlistPrint(&sl);
	printf("\n");

	SeqlistPopFront(&sl);
	SeqlistPopFront(&sl);


	SeqlistPrint(&sl);

	SeqlistDestory(&sl);
	return 0;
}