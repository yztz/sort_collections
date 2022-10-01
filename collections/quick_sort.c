//
// Created by 16009 on 2022/10/1.
//
#include "global.h"

int partition(int nums[], int left, int right) {
    int mid = (left + right - 1) / 2;
    int pivot = nums[mid];
    swap(nums, left, mid);
    int i = left, j = right - 1;

    while (i < j) {
        while (nums[j] >= pivot && i < j) j--;
        nums[i] = nums[j];
        while (nums[i] <= pivot && i < j) i++;
        nums[j] = nums[i];
    }

    nums[i] = pivot;
    return i;
}

void __quick_sort(int nums[], int left, int right) {
    if (left >= right) return;

    int pivot = partition(nums, left, right);

    __quick_sort(nums, left, pivot);
    __quick_sort(nums, pivot + 1, right);
}

void quick_sort(int nums[], int size) {
    __quick_sort(nums, 0, size);
}

ADD_SORT("Quick Sort", quick_sort, "O(nlogn)");