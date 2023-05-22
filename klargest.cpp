// #include <iostream>
#include <queue>
#include <vector>

int kth_largest(std::vector<int> values, int k) {
    std::priority_queue<int> pq;

    for (auto i : values) {
        pq.push(i);
    }

    int largest;

    for (int i = 0; i < k; i++) {
        largest = pq.top();
        pq.pop();
    }

    return largest;
}


// int main() {
//     std::vector<int> v = {1, 2, 3, 7, 5, 6, 10, 9, 8};
//     std::cout << kth_largest(v, 3) << std::endl;
//     return 0;
// }