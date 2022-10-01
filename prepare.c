//
// Created by yztz on 2022/9/30.
//

#include "global.h"
#include "crossline.h"
#include "timer.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>


int nums[ARRAY_SIZE];
int nums_order[ARRAY_SIZE];

#define SHOW(s, c) { \
crossline_color_set(c); \
        printf(s);   \
crossline_color_set(CROSSLINE_COLOR_DEFAULT);}

sort_case_t collections[__MAX_CASES];
static int collection_size = 0;

void __add_sort(char *name, sorter_t sorter) {
    collections[collection_size++] = (sort_case_t) {name, sorter};
}

void run_one(sort_case_t *sort_case) {
    int nums_copy[ARRAY_SIZE];
    memcpy(nums_copy, nums, sizeof nums);

    tick_t t1 = timer_system();
    sort_case->sorter(nums_copy, ARRAY_SIZE);
    tick_t dt = timer_system() - t1;

    int v = verify(nums_copy, ARRAY_SIZE);

    if (v) {
        SHOW(sort_case->name, CROSSLINE_FGCOLOR_GREEN | CROSSLINE_FGCOLOR_BRIGHT | CROSSLINE_UNDERLINE)
        printf(" %llu ms ", dt);
//#if ARRAY_SIZE <= 20
//        printf(">> ", sort_case->name);
//        print_array(nums_copy, ARRAY_SIZE);
//#endif
        printf("\n");
    } else {
        SHOW(sort_case->name, CROSSLINE_FGCOLOR_RED | CROSSLINE_FGCOLOR_BRIGHT | CROSSLINE_UNDERLINE)
        printf(" Bad Answer\n");
    }

}

void print_origin() {
    printf("Origin ");
    print_array(nums, ARRAY_SIZE);
    printf("\nOrigin with order ");
    print_array(nums_order, ARRAY_SIZE);
}

void run_all() {
#if ARRAY_SIZE <= 20
    print_origin();
    printf("\n\n");
#endif

    printf("[Run All]\n");
    for (int i = 0; i < collection_size; ++i) {
        run_one(collections + i);
    }
}

int verify(int nums[], int size) {
    for (int i = 0; i < size; ++i) {
        if(nums[i] != nums_order[i]) return 0;
    }
    return 1;
}

int natural_comparator(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void __init_array() {
    srand((unsigned) time(NULL));
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        nums_order[i] = nums[i] = rand() % MAX_NUM;
    }
    qsort(nums_order, ARRAY_SIZE, sizeof(int), natural_comparator);
}

void __init_timer() {
    timer_lib_initialize();
}

void __attribute__((constructor)) prepare() {
    __init_array();
}


