//
// Created by yztz on 2022/10/1.
//
#include "global.h"


void half_insertion(int nums[], int size) {
    for (int i = 1; i < size; i++) {
        if (nums[i] < nums[i - 1]) {
            int num = nums[i];
            int left = 0;
            int right = i - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if(nums[mid] > num) right = mid - 1;
                else if(nums[mid] <= num) left = mid + 1;
            }
            for (int j = i - 1; j >= left; j--) {
                nums[j + 1] = nums[j];
            }
            nums[left] = num;
        }
    }
}

ADD_SORT("Half Insert O(n2)", half_insertion);