#define _CRT_SECURE_NO_WARNINGS 1


LC27 顺序表移除元素
int removeElement(int* nums, int numsSize, int val) {
    int left = 0;
    int right = numsSize;
    while (left < right)
    {
        if (nums[left] == val)
        {
            nums[left] = nums[right - 1];
            right--;
        }
        else
        {
            left++;
        }
    }
    return left;
}


LC26删除排序数组中的重复项

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[j])
            {
                nums[++j] = nums[i];
            }
        }
        return j + 1;
    }
};


LC88 合并两个有序数组

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int index = nums1.size() - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[index--] = nums1[i--];
            }
            else
                nums1[index--] = nums2[j--];
        }
        while (j >= 0)
            nums1[index--] = nums2[j--];
    }
};