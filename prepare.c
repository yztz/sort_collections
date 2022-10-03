//
// Created by yztz on 2022/9/30.
//

#include "global.h"
#include "timer.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

int *nums;
int *nums_order;


sort_case_t collections[__MAX_CASES];
static int collection_size = 0;

static int *get_case() {
    int *copy = (int *)malloc(sizeof(int) * ARRAY_SIZE);
    if(!copy) error("Fetch Case Fail");
    memmove(copy, nums, sizeof(int) * ARRAY_SIZE);
    return copy;
}

void __add_sort(char *name, sorter_t sorter, char *desc) {
    collections[collection_size++] = (sort_case_t) {name, sorter, desc};
}

void run_one(sort_case_t *sort_case) {
    int *nums_copy = get_case();

    tick_t t1 = timer_system();
    sort_case->sorter(nums_copy, ARRAY_SIZE);
    tick_t dt = timer_system() - t1;

    int v = verify(nums_copy, ARRAY_SIZE);

    if (v) {
        show(sort_case->name, CROSSLINE_FGCOLOR_GREEN | CROSSLINE_FGCOLOR_BRIGHT | CROSSLINE_UNDERLINE);
        printf(" %llums ", dt);
        show(sort_case->desc, CROSSLINE_FGCOLOR_MAGENTA);
//#if ARRAY_SIZE <= 20
//        printf(">> ", sort_case->name);
//        print_array(nums_copy, ARRAY_SIZE);
//#endif
        printf("\n");
    } else {
        show(sort_case->name, CROSSLINE_FGCOLOR_RED | CROSSLINE_FGCOLOR_BRIGHT | CROSSLINE_UNDERLINE);
        printf(" Bad Answer\n");
    }

    free(nums_copy);
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
    show("[Run All]\n", CROSSLINE_FGCOLOR_CYAN);
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

    nums = (int *)malloc(sizeof(int) * ARRAY_SIZE);
    nums_order = (int *)malloc(sizeof(int) * ARRAY_SIZE);

    if(!nums || !nums_order)
        error("Array Init Fail");

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        nums_order[i] = nums[i] = rand() % MAX_NUM;
    }
    qsort(nums_order, ARRAY_SIZE, sizeof(int), natural_comparator);
}


void __free_array() {
    free(nums);
    free(nums_order);
}

void __init_timer() {
    timer_lib_initialize();
}

void __disable_timer() {
    timer_lib_shutdown();
}

void __attribute__((constructor)) prepare() {
    __init_array();
    __init_timer();
}

void __attribute__ ((destructor)) clean() {
    __free_array();
    __disable_timer();
}


