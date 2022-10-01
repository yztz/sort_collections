//
// Created by yztz on 2022/9/30.
//

#include "global.h"

void bubble(int nums[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) swap(nums, j, j + 1);
        }
    }
}

ADD_SORT("Bubble", bubble)