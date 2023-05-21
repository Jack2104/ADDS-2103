#include "Heap.tpp"
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3};
    Heap<int>* h = new Heap<int>(v);

    h->insert(0);
    return 0;
}