#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//传数组建堆
void test1()
{
	Heap hp;
	int arr[10] = { 1,4,7,8,2,5,3,6,9,10 };
	int size = sizeof(arr) / sizeof(int);
	CreateHeap(&hp, arr, size);
}

//堆排序
void test2()
{
	int arr[10] = { 1,4,7,8,2,5,3,6,9,10 };
	int size = sizeof(arr) / sizeof(int);
	HeapSort(arr, size);//                   排升序建大堆，每次将堆顶元素与堆最后一个元素互换，再从上往下进行大堆建立
	                    //                   排升序建降堆，每次将堆顶元素与堆最后一个元素互换，再从上往下进行小堆建立     
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

//TOP-k 数据足够大时，不能在计算机内存上储存，需要保存到硬盘中再读取

//在文件中写入数据，在取TOP-k 
//时间复杂度  O(N*logk)  空间复杂度O(k)
//如果取得TOP是最大的五个数，则需要建小堆，将每个数据跟堆顶元素进行比较，大于堆顶元素就换堆顶，在向下调整
//如果取得TOP是最小的五个数，则需要建大堆，将每个数据跟堆顶元素进行比较，小于堆顶元素就换堆顶，在向下调整
void test3(int k)
{
	HpDataType* MinHeap = (HpDataType*)malloc(sizeof(HpDataType) * k);
	FILE* fout = fopen("Data.txt","r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout,"%d",&MinHeap[i]);
	}
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(MinHeap, k, i);
	}
	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > MinHeap[0])
		{
			MinHeap[0] = val;
			HeapAdjustDown(MinHeap, k, 0);
		}
	}
	HeapSort(MinHeap,k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ",MinHeap[i]);
	}
	fclose(fout);
}
int main()
{

	//test1();
	//test2();
	//test3(5);
	return 0;
}