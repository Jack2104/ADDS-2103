#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::rbSearch(std::vector<int> list, int value, int start, int end) {
    if (start > end) {
        return false;
    }

    int midpoint = (start + end) / 2;

    if (list[midpoint] == value)
        return true;
    else if (list[midpoint] > value)
        return rbSearch(list, value, start, midpoint - 1);
    else if (list[midpoint] < value)
        return rbSearch(list, value, midpoint + 1, end);
    
    return false;
}

bool RecursiveBinarySearch::search(std::vector<int> list, int value) {
    return rbSearch(list, value, 0, list.size() - 1);
}