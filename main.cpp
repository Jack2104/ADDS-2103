#include <iostream>
#include <vector>
#include <sstream>

#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

using namespace std;

int main() {
    // QuickSort qSort;

    // vector<int> q_test = {1, 3, 2, 3, 5, 2};
    // vector<int> sorted_q_test = qSort.sort(q_test);

    // for (int i : sorted_q_test) {
    //     cout << i << " ";
    // }

    vector<int> list;
    string num_str;

    string line;
    getline(cin, line);
    istringstream iss(line);

    while (iss >> num_str) {    
        list.push_back(stoi(num_str));
    }

    QuickSort qSort;
    vector<int> sorted_list = qSort.sort(list);

    RecursiveBinarySearch rbs;
    bool containsOne = rbs.search(sorted_list, 1);
    string bool_str = containsOne ? "true" : "false";

    cout << bool_str << " ";

    for (int i : sorted_list) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}