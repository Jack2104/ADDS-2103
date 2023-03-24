#ifndef BAG_H
#define BAG_H

#include <vector>
#include <cstdlib>

template<class T>
class Bag {
    private:
        std::vector<T> items;

    public:
        void addItem(T item);
        T removeItem();
};

template<class T>
void Bag<T>::addItem(T item) {
    this->items.push_back(item);
}

template<class T>
T Bag<T>::removeItem() {
    int item_count = this->items.size();
    int rand_index = rand() % item_count; // Random number between 0 and item_count - 1;
    return this->items[rand_index];
}

#endif