//
// Created by yztz on 2022/9/30.
//

#ifndef SORT_COLLECTIONS_GLOBAL_H
#define SORT_COLLECTIONS_GLOBAL_H

#include "config.h"
#include "crossline.h"

#define INFINITE MAX_NUM

#define __MAX_CASES 100

typedef void (*sorter_t)(int[], int);
typedef struct {
    char *name;
    sorter_t sorter;
    char *desc;
} sort_case_t;

typedef int (*comparator_t)(int, int);

#define ADD_SORT(name, func, desc) \
    extern void __add_sort(char *, sorter_t, char *); \
    static void __attribute__((constructor)) add_sort_##__LINE__() { \
        __add_sort(name, func, desc); \
    }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

extern void run_all();
extern void print_array(int array[], int size);
extern int verify(int nums[], int size);

void show(char *string, crossline_color_e color);
void error(char *string);
extern void swap(int nums[], int i, int j);

#endif //SORT_COLLECTIONS_GLOBAL_H
