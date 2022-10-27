#define _CRT_SECURE_NO_WARNINGS 1
#include"Sequence.h"

int main()
{
	SL sl;
	SeqlistInit(&sl);
	SeqlistPushBack(&sl, 1);
	SeqlistPushBack(&sl, 2);
	SeqlistPushBack(&sl, 3);
	SeqlistPushBack(&sl, 4);
	SeqlistPushBack(&sl, 5);

	//SeqlistPushFront(&sl, 10);
	//SeqlistPopFront(&sl);

	//SeqlistFind(&sl, 10);

	//SeqlistInsert(&sl, 0, 0);

	//SeqlistErase(&sl, 1);
	SeqlistPrint(&sl);

	SeqlistDestroy(&sl);
	return 0;
}