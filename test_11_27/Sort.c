#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

// 直接插入排序
void InsertSort(int* arr, int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}

		arr[end + 1] = tmp;
	}
}

//选择排序
void SelectSort(int* arr, int sz)
{
	int begin = 0, end = sz - 1;
	while (begin < end)
	{
		int min_i = begin, max_i = begin;
		for (int i = begin+1; i <= end; i++)
		{
			if (arr[i] < arr[min_i])
			{
				min_i = i;
			}
			if (arr[i] > arr[max_i])
			{
				max_i = i;
			}
		}
		Swap(&arr[min_i], &arr[begin]);
		if (max_i == begin)
			max_i = min_i;
		Swap(&arr[max_i], &arr[end]);

		begin++;
		end--;
	}
}



// 打印
void PrintArr(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
}

void Swap(int* a, int* y)
{
	int tmp = *a;
	*a = *y;
	*y = tmp;
}