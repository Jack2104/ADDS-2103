#ifndef RECURSIVE_BINARY_SEARCH_H
#define RECURSIVE_BINARY_SEARCH_H

class RecursiveBinarySearch {
    public:
        bool search(std::vector<int> list, int value);
    
    private:
        int rbSearch(std::vector<int> list, int value, int start, int end)
};

#endif