#include "Heap.tpp"
#include "klargest.cpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3, 7, 5, 6, 10, 9, 8};
    Heap<int>* h = new Heap<int>(v);

    h->insert(0);
    h->remove(3);

    std::cout << kth_largest(v, 1) << std::endl;
    return 0;
}