#include "Bag.h"
#include <iostream>

int main() {
    Bag<int> bag;
    bag.addItem(10);

    std::cout << bag.removeItem() << std::endl;

    return 0;
}