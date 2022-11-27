#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"


void TestInsertSort()
{
	int arr[10] = { 1,4,7,8,5,2,3,6,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr,sz);
	PrintArr(arr,sz);
}
void TestSelectSort()
{
	int arr[10] = { 1,4,7,8,5,2,3,6,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, sz);
	PrintArr(arr, sz);
}
int main()
{
	//TestInsertSort();
	TestSelectSort();
	return 0;
}
