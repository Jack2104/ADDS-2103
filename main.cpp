#include <iostream>
#include <vector>

#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

using namespace std;

int main() {
    BubbleSort bSort;

    vector<int> b_test = {1, 3, 5, 2, 0};
    vector<int> sorted_b_test = bSort.sort(b_test);

    cout << "Bubble Sort: ";

    for (int i : sorted_b_test) {
        cout << i << " ";
    }

    cout << endl << "Quick Sort: ";

    QuickSort qSort;

    vector<int> q_test = {1, 3, 5, 2, 0};
    vector<int> sorted_q_test = qSort.sort(q_test);

    for (int i : sorted_q_test) {
        cout << i << " ";
    }

    cout << endl << "Recursive Binary Search: ";

    RecursiveBinarySearch rbSearch;

    vector<int> rbs_test = {1, 3, 5, 2, 0};
    int rbs_result = rbSearch.search(rbs_test, 5);

    for (int i : sorted_q_test) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}