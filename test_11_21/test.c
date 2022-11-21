#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//�����齨��
void test1()
{
	Heap hp;
	int arr[10] = { 1,4,7,8,2,5,3,6,9,10 };
	int size = sizeof(arr) / sizeof(int);
	CreateHeap(&hp, arr, size);
}

//������
void test2()
{
	int arr[10] = { 1,4,7,8,2,5,3,6,9,10 };
	int size = sizeof(arr) / sizeof(int);
	HeapSort(arr, size);//                   �����򽨴�ѣ�ÿ�ν��Ѷ�Ԫ��������һ��Ԫ�ػ������ٴ������½��д�ѽ���
	                    //                   �����򽨽��ѣ�ÿ�ν��Ѷ�Ԫ��������һ��Ԫ�ػ������ٴ������½���С�ѽ���     
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

//TOP-k �����㹻��ʱ�������ڼ�����ڴ��ϴ��棬��Ҫ���浽Ӳ�����ٶ�ȡ

//���ļ���д�����ݣ���ȡTOP-k 
//ʱ�临�Ӷ�  O(N*logk)  �ռ临�Ӷ�O(k)
//���ȡ��TOP�����������������Ҫ��С�ѣ���ÿ�����ݸ��Ѷ�Ԫ�ؽ��бȽϣ����ڶѶ�Ԫ�ؾͻ��Ѷ��������µ���
//���ȡ��TOP����С�������������Ҫ����ѣ���ÿ�����ݸ��Ѷ�Ԫ�ؽ��бȽϣ�С�ڶѶ�Ԫ�ؾͻ��Ѷ��������µ���
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