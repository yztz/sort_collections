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

