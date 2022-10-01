//
// Created by yztz on 2022/10/1.
//
#include "global.h"

void swap(int nums[], int i, int j) {
    int tmp = nums[j];
    nums[j] = nums[i];
    nums[i] = tmp;
}

void print_array(int array[], int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        if (i == 0)
            printf("%d", array[i]);
        else
            printf(", %d", array[i]);
    }
    printf("]");
}

int natural_comparator(int a, int b) {
    return a - b;
}

int __verify(int nums[], int size, comparator_t comparator) {
    for (int i = 0; i < size - 1; ++i) {
        if(comparator(nums[i + 1], nums[i]) < 0) return 0;
    }
    return 1;
}

int verify(int nums[], int size) {
    return __verify(nums, size, natural_comparator);
}