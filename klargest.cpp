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