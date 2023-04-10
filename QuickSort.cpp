#include "QuickSort.h"

void QuickSort::qsort(std::vector<int> &list, int start, int end) {
    if (start >= end) {
        return;
    }

    // Select a pivot
    int pivot_location = end - start >= 2 ? start + 2 : end;
    int pivot = list[pivot_location];

    // Sort the LHS of the array
    int pivot_index = start;
    int temp;

    for (int i = start; i < pivot_location; i++) {
        if (list[i] < pivot) {
            temp = list[i];
            list[i] = list[pivot_index];
            list[pivot_index] = temp;

            pivot_index++;
        }
    }

    // Swap the element at pivot_index and the pivot
    temp = list[pivot_index];
    list[pivot_index] = pivot;
    list[pivot_location] = temp;

    // Sort the RHS of the array - must be done if the pivot isn't at the end of the array
    if (pivot_location < end) {
        pivot_location = pivot_index; // The pivot will always move to be at pivot_index
        pivot = list[pivot_location]; // Note: the pivot itself won't actually change

        pivot_index = end;

        // Loop down from the end of the array to the pivot
        for (int i = end; i > pivot_location; i--) {
            // We only want elements *larger* than the pivot on the RHS
            if (list[i] > pivot) {
                temp = list[i];
                list[i] = list[pivot_index];
                list[pivot_index] = temp;

                pivot_index--;
            }
        }

        // Swap the element at pivot_index and the pivot
        temp = list[pivot_index];
        list[pivot_index] = pivot;
        list[pivot_location] = temp;
    }

    qsort(list, start, pivot_index - 1);
    qsort(list, pivot_index + 1, end);
}

std::vector<int> QuickSort::sort(std::vector<int> list) {
    qsort(list, 0, list.size() - 1);
    return list;
}
