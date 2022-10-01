//
// Created by yztz on 2022/9/30.
//

#include "global.h"
#include "crossline.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>


int nums[ARRAY_SIZE];

#define SHOW(s, c) { \
crossline_color_set(c); \
        printf(s);   \
crossline_color_set(CROSSLINE_COLOR_DEFAULT);}

sort_case_t collections[__MAX_CASES];
static int collection_size = 0;

void __add_sort(char *name, sorter_t sorter) {
    collections[collection_size++] = (sort_case_t){name, sorter};
}

void run_one(sort_case_t *sort_case) {
    int nums_copy[ARRAY_SIZE];
    memcpy(nums_copy, nums, sizeof nums);
    sort_case->sorter(nums_copy, ARRAY_SIZE);
    int v = verify(nums_copy, ARRAY_SIZE);

    if(v) {
        SHOW(sort_case->name, CROSSLINE_BGCOLOR_GREEN|CROSSLINE_FGCOLOR_BRIGHT|CROSSLINE_FGCOLOR_WHITE)
    } else {
        SHOW(sort_case->name, CROSSLINE_BGCOLOR_RED|CROSSLINE_FGCOLOR_BRIGHT|CROSSLINE_FGCOLOR_WHITE)
    }
    printf(" >> ", sort_case->name);
    print_array(nums_copy, ARRAY_SIZE);
    printf("\n");
}

void print_origin() {
    printf("Origin ");
    print_array(nums, ARRAY_SIZE);
}

void run_all() {
    print_origin();
    printf("\n\n");
    printf("[Run All]\n");
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


