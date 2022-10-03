//
// Created by yztz on 2022/10/3.
//
#include "global.h"


#define LEFT(i) (i * 2 + 1)
#define RIGHT(i) (i * 2 + 2)

void heap_adjust(int heap[], int size, int k) {
//    int decision = -1;
//    // left
//    if (LEFT(k) < size && heap[LEFT(k)] < heap[k]) {
//        decision = LEFT(k);
//    }
//    // right
//    if (RIGHT(k) < size && heap[RIGHT(k)] < heap[k]) {
//        decision = decision == -1 ? RIGHT(k) :
//                   (heap[decision] < heap[RIGHT(k)] ? decision : RIGHT(k));
//    }
//
//    if (decision != -1) {
//        swap(heap, k, decision);
//        heap_adjust(heap, size, decision);
//    }
    int num = heap[k];
    for (int i = 2 * k + 1; i < size; i = i * 2 + 1) {
        if (i + 1 < size && heap[i] > heap[i + 1]) {
            i = i + 1;
        }
        if (num > heap[i]) {
            heap[k] = heap[i];
            k = i;
        } else {
            break;
        }
    }
    heap[k] = num;

}

int *build_heap(int nums[], int size) {
    int *heap = (int *) malloc(size * sizeof(int));
    if (!heap) error("Heap Alloc Fail");
    memcpy(heap, nums, size * sizeof(int));
    for (int i = size / 2; i >= 0; i--) {
        heap_adjust(heap, size, i);
    }
    return heap;
}

int heap_poll(int heap[], int size) {
    int res = heap[0];
    swap(heap, 0, size - 1);
    heap_adjust(heap, size - 1, 0);
    return res;
}

#include <math.h>

void print_heap(int heap[], int size) {
    int indent = size / 2;
    for (int i = 0; i < size; ++i) {
        if ((i & (i + 1)) == 0) {
            if (i != 0) printf("\n");
            printf("%*s", indent--, "");
        }
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void heap_sort(int nums[], int size) {
    int *heap = build_heap(nums, size);
    for (int i = 0; i < size; ++i) {
//        printf("========%d========\n", i);
//        print_heap(heap, size - i);

        nums[i] = heap_poll(heap, size - i);
    }
    free(heap);
}


ADD_SORT("Heap Sort", heap_sort, "O(nlogn)")