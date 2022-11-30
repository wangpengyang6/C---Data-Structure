#define _CRT_SECURE_NO_WARNINGS 1

//œ£∂˚≈≈–Ú  ±º‰∏¥‘”∂»O(n^1.3)~O(n^2)
void ShellSort(int* arr, int sz)
{
	int gap = sz;//  gap > 1 ‘§≈≈–Ú
	while (gap > 1)    //  gap == 1 ÷±Ω”≤Â»Î≈≈–Ú
	{
		gap /= 2;
		// gap /= 3 + 1;
		for (int i = 0; i < sz - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

//√∞≈›≈≈–Ú
void BubbleSort(int* arr, int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(&arr[j], &arr[j + 1]);
		}
	}
}