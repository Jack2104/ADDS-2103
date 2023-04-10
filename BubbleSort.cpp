#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list) {
    for (int i = list.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j + 1];
                list[j + 1] = list [j];
                list[j] = temp;
            }
        }
    }

    return list;
}
