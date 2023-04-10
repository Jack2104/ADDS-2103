#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "Sort.h"

class QuickSort : public Sort {
    public:
        std::vector<int> sort(std::vector<int> list);
    
    private:
        void qsort(std::vector<int> &list, int start, int end);
        // int partition(std::vector<int> &list, int start, int end);
};

#endif