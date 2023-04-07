#include "QuickSort.h"

#include <iostream>

void QuickSort::qsort(std::vector<int> &list, int start, int end) {
    if (start >= end) {
        return;
    }

    // Select a pivot
    int pivot_location = end - start >= 2 ? start + 2 : end;
    int pivot = list[pivot_location];

    int pivot_index = 0;
    int temp;

    for (int i = 0; i < pivot_location; i++) {
        if (list[i] < pivot) {
            temp = list[i];
            list[i] = list[pivot_index];
            list[pivot_index] = temp;

            pivot_index++;
        }
    }

    temp = list[pivot_index];
    list[pivot_index] = pivot;
    list[pivot_location] = temp;

    qsort(list, start, pivot_index - 1);
    qsort(list, pivot_index + 1, end);
}

std::vector<int> QuickSort::sort(std::vector<int> list) {
    qsort(list, 0, list.size() - 1);
    return list;
}
