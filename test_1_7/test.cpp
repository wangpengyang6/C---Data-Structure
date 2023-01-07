#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;

void InsertSort(int* p, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = p[end + 1];
		while (end >= 0)
		{
			if (p[end] > tmp)
			{
				p[end + 1] = p[end];
				end--;
			}
			else
				break;
		}
		p[end + 1] = tmp;
	}
}

//第一层优化 三数取中

int GetMinIndex(int p[], int begin, int end)
{
	int mid = (begin + end) / 2;
	if (p[begin] < p[mid])
	{
		if (p[begin] > p[end])
			return begin;
		else if (p[end] > p[mid])
			return mid;
		else
			return end;
	}
	else
	{
		if (p[mid] > p[end])
			return mid;
		else if (p[end] > p[begin])
			return begin;
		else
			return end;
	}
}

//1 .Hoare法
void Quick_sort_Hoare(int p[], int begin, int end)
{
	if (begin > end)
		return;

	//第二层优化 快排分割到小区间时候，用直接插入排序 减少递归调用次数
	if ((end - begin + 1) < 15)
	{
		InsertSort(p + begin, end - begin + 1);
	}
	else
	{
		//第一层优化 三数取中
		int midi = GetMinIndex(p, begin, end);
		swap(p[begin], p[midi]);
		int left = begin, right = end;
		int keyi = left;

		while (left < right)
		{
			//让右边先走
			while (left < right && p[right] >= p[keyi])
			{
				right--;
			}
			while (left < right && p[left] <= p[keyi])
			{
				left++;
			}

			swap(p[left], p[right]);
		}
		swap(p[left], p[keyi]);
		keyi = left;
		Quick_sort_Hoare(p, begin, keyi - 1);
		Quick_sort_Hoare(p, keyi + 1, end);
	}

}



//2 挖坑法
void Quick_sort_Hole(int p[], int begin, int end)
{
	if (begin > end)
		return;

	//第二层优化 快排分割到小区间时候，用直接插入排序 减少递归调用次数
	if ((end - begin + 1) < 15)
	{
		InsertSort(p + begin, end - begin + 1);
	}
	else
	{
		//第一层优化 三数取中
		int midi = GetMinIndex(p, begin, end);
		swap(p[begin], p[midi]);
		int left = begin, right = end;
		int key = p[left];
		int hole = left;
		while (left < right)
		{
			//让右边先走
			while (left < right && p[right] >= key)
			{
				right--;
			}
			p[hole] = p[right];
			hole = right;
			while (left < right && p[left] <= key)
			{
				left++;
			}
			p[hole] = p[left];
			hole = left;
		}
		p[hole] = key;
		Quick_sort_Hole(p, begin, hole - 1);
		Quick_sort_Hole(p, hole + 1, end);
	}

}

//3 双指针法 最简单实现快排
void Quick_sort_Pointer(int p[], int begin, int end)
{
	if (begin > end)
		return;
	//第二层优化 快排分割到小区间时候，用直接插入排序 减少递归调用次数
	if ((end - begin + 1) < 10)
	{
		InsertSort(p + begin, end - begin + 1);
	}
	else
	{
		//第一层优化 三数取中
		int midi = GetMinIndex(p, begin, end);
		swap(p[begin], p[midi]);

		int key = begin;
		int prev = begin, cur = begin + 1;
		while (cur <= end)
		{
			if (p[cur] < p[key] && ++prev != cur)
			{
				swap(p[prev], p[cur]);
			}
			cur++;
		}
		swap(p[prev], p[key]);
		Quick_sort_Pointer(p, begin, prev - 1);
		Quick_sort_Pointer(p, prev + 1, end);
	}

}
int main()
{
	int p[15] = { 1,1,2,3,5,4,7,2,5,8,3,6,9,10,14 };
	Quick_sort_Pointer(p, 0, 14);
	//Quick_sort_Hole(p,0,14);
	//InsertSort_Hoare(p,10);
	for (auto e : p)
	{
		cout << e << ' ';
	}
	return 0;
}