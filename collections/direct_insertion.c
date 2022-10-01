//
// Created by yztz on 2022/10/1.
//
#include "global.h"

void direct_insertion(int nums[], int size) {
    for (int i = 1; i < size; ++i) {
        if (nums[i] < nums[i - 1]) {
            int j = i;
            int num = nums[i];
            for (; j >= 1; j--) {
                nums[j] = nums[j - 1];
                if(nums[j - 1] < num) break;
            }
            nums[j] = num;
        }
    }
}

ADD_SORT("Direct Insert O(n2)", direct_insertion)