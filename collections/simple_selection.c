//
// Created by yztz on 2022/10/3.
//
#include "global.h"

void simple_selection_sort(int nums[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int pos = i;
        for (int j = i + 1; j < size; ++j) {
            if(nums[j] < nums[pos]) pos = j;
        }
        swap(nums, i, pos);
    }
}

ADD_SORT("Simple Selection", simple_selection_sort, "O(n2)")