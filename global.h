//
// Created by yztz on 2022/9/30.
//

#ifndef SORT_COLLECTIONS_GLOBAL_H
#define SORT_COLLECTIONS_GLOBAL_H

#define ARRAY_SIZE 10
#define MAX_NUM 0x7fff
#define INFINITE MAX_NUM

#define __MAX_CASES 100

typedef void (*sorter_t)(int[], int size);
typedef struct {
    char *name;
    sorter_t sorter;
} sort_case_t;

#define ADD_SORT(name, func) \
    extern void __add_sort(char *, sorter_t); \
    static void __attribute__((constructor)) add_sort_##__LINE__() { \
        __add_sort(name, func); \
    }

#include <stdio.h>

extern void run_all();
extern void print_array(int array[], int size);

#endif //SORT_COLLECTIONS_GLOBAL_H
