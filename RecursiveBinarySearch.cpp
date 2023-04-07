#include "RecursiveBinarySearch.h"

#include <cmath>

int RecursiveBinarySearch::rbSearch(std::vector<int> list, int value, int start, int end) {
    if (list[end] == value) {
        return end;
    } else if (list[end] > value && list[start] < value)

    rbSearch(list, value, start, std::floor(end / 2));
    rbSearch(list, value, std::ceil(end / 2), end);
}

bool RecursiveBinarySearch::search(std::vector<int> list, int value) {
    int result = rbSearch(list, value, 0, list.size() - 1);

    return result ? true : false;
}