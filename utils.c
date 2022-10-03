//
// Created by yztz on 2022/10/1.
//
#include "global.h"

void show(char *string, crossline_color_e color) {
    crossline_color_set(color);
    printf(string);
    crossline_color_set(CROSSLINE_COLOR_DEFAULT);
}

void error(char *string) {
    show(string, CROSSLINE_FGCOLOR_RED);
    exit(-1);
}


void swap(int nums[], int i, int j) {
    int tmp = nums[j];
    nums[j] = nums[i];
    nums[i] = tmp;
}

void print_array(int array[], int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        if (i == 0)
            printf("%d", array[i]);
        else
            printf(", %d", array[i]);
    }
    printf("]");
}

