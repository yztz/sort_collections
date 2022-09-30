//
// Created by yztz on 2022/9/30.
//

#include "global.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

int nums[ARRAY_SIZE];

sort_case_t collections[__MAX_CASES];

static int collection_size = 0;
void __add_sort(char *name, sorter_t sorter) {
    collections[collection_size++] = (sort_case_t){name, sorter};
}

void print_array(int array[], int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        if(i == 0)
            printf("%d", array[i]);
        else
            printf(", %d", array[i]);
    }
    printf("]");
}

void run_one(sort_case_t *sort_case) {
    int nums_copy[ARRAY_SIZE];
    memcpy(nums_copy, nums, sizeof nums);
    printf("-%s ", sort_case->name);
    sort_case->sorter(nums_copy, ARRAY_SIZE);
    printf("res ");
    print_array(nums_copy, ARRAY_SIZE);
    printf("\n");
}

void run_all() {
    printf("[Run All]\nOrigin ");
    print_array(nums, ARRAY_SIZE);
    printf("\n\n");
    for (int i = 0; i < collection_size; ++i) {
        run_one(collections + i);
    }
}

void __init_array() {
    srand((unsigned ) time(NULL));
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        nums[i] = rand() % MAX_NUM;
    }
}

void __attribute__((constructor)) prepare() {
    __init_array();
}


