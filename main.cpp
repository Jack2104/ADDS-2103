#include "Heap.tpp"
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 7, 5, 6, 10, 9, 8};
    Heap<int>* h = new Heap<int>(v);

    h->insert(0);
    h->remove(3);
    return 0;
}