//
// Created by 16009 on 2022/10/1.
//
#include "global.h"

int partition(int nums[], int left, int right) {
    int mid = (left + right) / 2;
    int pivot = nums[mid];
    swap(nums, 0, mid);
    int i = left, j = right;
    while (i < j) {
        while (nums[j] >= pivot && i < j) j--;
        nums[i] = nums[j];
        while (nums[i] <= pivot && i < j) i++;
        nums[j] = nums[i];
    }

    nums[i] = pivot;

    return i;
}

void quick_sort(int nums[], int size) {
    if(size <= 1) return;

    int pivot = partition(nums, 0, size - 1);

    quick_sort(nums, pivot);
    quick_sort(nums + pivot + 1, size - pivot - 1);
}

ADD_SORT("Quick Sort O(nlogn)", quick_sort);