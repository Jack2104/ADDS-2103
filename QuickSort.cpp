#include "QuickSort.h"

#include <iostream>

void QuickSort::qsort(std::vector<int> &list, int start, int end) {
    if (start >= end) {
        return;
    }

    // Select a pivot
    // int pivot_location = end - start >= 2 ? start + 2 : end;
    int pivot_location = end;
    int pivot = list[pivot_location];

    // std::cout << "BEFORE: ";

    // for (int i = start; i < end + 1; i++) {
    //     std::cout << list[i] << " ";
    // }

    // std::cout << std::endl;

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

    temp = list[pivot_index];
    list[pivot_index] = pivot;
    list[pivot_location] = temp;

    // std::cout << ", AFTER: ";

    // for (int i = start; i < end + 1; i++) {
    //     std::cout << list[i] << " ";
    // }

    // std::cout << std::endl;

    qsort(list, start, pivot_index - 1);
    qsort(list, pivot_index + 1, end);
}

std::vector<int> QuickSort::sort(std::vector<int> list) {
    qsort(list, 0, list.size() - 1);
    return list;
}

// int QuickSort::partition(std::vector<int> &list, int start, int end) {
//     int pivot_location = end - start >= 2 ? start + 2 : end;
//     int pivot = list[pivot_location];

//     // Sorting left and right parts of the pivot element
//     int i = start, j = end;
 
//     while (i < pivot_location && j > pivot_location) {
 
//         while (list[i] <= pivot) {
//             i++;
//         }
 
//         while (list[j] > pivot) {
//             j--;
//         }
 
//         if (i < pivot_location && j > pivot_location) {
//             std::swap(list[i++], list[j--]);
//         }
//     }
 
//     return pivot_location;
// }
