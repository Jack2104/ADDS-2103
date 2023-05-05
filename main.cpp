#include "LinkedList.h"
#include <iostream>

int main() {
    LinkedList ll;
    ll.insertFront(1);
    ll.insertFront(2);
    ll.insertFront(3);
    ll.insertFront(0);


    // std::cout << ll.find_and_delete(3) << std::endl;
    std::cout << ll.swap(1, 2) << std::endl;

    // ll.printList();

    return 0;
}