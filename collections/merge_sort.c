//
// Created by yztz on 2022/10/3.
//
#include "global.h"

void merge(int nums[], int low, int mid, int high) {
    // A: low...mid , B: mid + 1...high
//    printf("A: ");
//    print_array(nums, mid - low + 1);
//    printf("\nB: ");
//    print_array(nums + mid + 1, high - mid);
//    printf("\n");
    int *tmp = (int *) malloc(sizeof(int) * (mid - low + 1));
    if (!tmp) error("Merge TMP Alloc Fail");
    memcpy(tmp, nums + low, sizeof(int) * (mid - low + 1));
//    printf("TMP: ");
//    print_array(tmp, mid - low + 1);
//    printf("\n");
    int i = 0, j = mid + 1, k = low;
    while (i <= mid - low && j <= high) {
        if (tmp[i] < nums[j]) {
            nums[k++] = tmp[i++];
        } else {
            nums[k++] = nums[j++];
        }
    }
    while (i <= mid - low) {
        nums[k++] = tmp[i++];
    }

//    printf("After Merge: ");
//    print_array(nums, high - low + 1);
//    printf("\n");
//    while (j <= high) {
//        nums[]
//    }
    free(tmp);
}

void __merge_sort(int nums[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    __merge_sort(nums, low, mid);
    __merge_sort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

void merge_sort(int nums[], int size) {
    __merge_sort(nums, 0, size - 1);
}

ADD_SORT("Merge Sort", merge_sort, "O(nlogn)")