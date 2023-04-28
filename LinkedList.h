#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

class LinkedList {
    private:
        Node* head;
        Node* traverse(int pos);

    public:
        LinkedList();
        LinkedList(int* array, int len);
        ~LinkedList();

        void insertPosition(int pos, int newNum);
        bool deletePosition(int pos);
        int get(int pos);
        int search(int target);
        void printList();
};

#endif