#include <iostream>
#include<limits>

#include "LinkedList.h"

LinkedList::LinkedList() {
    this->head = nullptr;
}

LinkedList::LinkedList(int* array, int len) {
    this->head = nullptr;

    for (int i = 0; i < len; i++) {
        insertPosition(i + 1, array[i]);

    }
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->link;
        delete temp;
    }
}

Node* LinkedList::traverse(int pos) {
    if (pos < 1)
        return nullptr;

    int currentPos = 1; // This LL is 1-indexed
    Node* currentNode = head;

    while (currentPos < pos && currentNode != nullptr) {
        currentNode = currentNode->link;
        currentPos++;
    }

    return currentNode;
}

void LinkedList::insertPosition(int pos, int newNum) {
    if (pos <= 1) {
        head = new Node(newNum, head);
        return;
    }

    Node* previousNode = traverse(pos - 1);

    // If pos > length, insert newNum at the end of the linked list
    int n = 2;

    while (previousNode == nullptr) {
        std::cout << "test 1" << std::endl;
        previousNode = traverse(pos - n);
        n++;
    }

    Node* newNode = new Node(newNum, previousNode->link);
    previousNode->link = newNode;
    return;
}

bool LinkedList::deletePosition(int pos) {
    Node* node = traverse(pos);
    Node* previousNode = traverse(pos - 1);
    Node* nextNode = traverse(pos + 1);

    // Out of bounds
    if (node == nullptr)
        return false;
    
    // pos = 1 (i.e. trying to delete head)
    if (previousNode == nullptr) {
        head = nextNode;
        delete node;
        return true;
    }

    previousNode->link = nextNode;
    delete node;
    return true;
}

int LinkedList::get(int pos) {
    Node* node = traverse(pos);

    if (node == nullptr) {
        return std::numeric_limits<int>::max();
    }

    return node->data;
}

int LinkedList::search(int target) {
    int currentPos = 1;
    Node* currentNode = head;

    while (currentNode != nullptr) {
        if (currentNode->data == target)
            return currentPos;

        currentPos++;
        currentNode = currentNode->link;
    }

    return -1;
}

void LinkedList::printList() {
    // Empty list
    if (head == nullptr)
        return;
    
    std::string listStr = "[ ";

    Node* currentNode = head;

    while (currentNode != nullptr) {
        listStr += std::to_string(currentNode->data) + " ";
        currentNode = currentNode->link;
    }

    listStr += "]";
    std::cout << listStr << std::endl;
}
