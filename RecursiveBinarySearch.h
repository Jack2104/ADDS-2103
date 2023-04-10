#ifndef RECURSIVE_BINARY_SEARCH_H
#define RECURSIVE_BINARY_SEARCH_H

#include <vector>

class RecursiveBinarySearch {
    public:
        bool search(std::vector<int> list, int value);
    
    private:
        bool rbSearch(std::vector<int> list, int value, int start, int end);
};

#endif