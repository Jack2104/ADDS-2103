#include "PrefixMatcher.h"

#include <iostream>

PrefixMatcher::PrefixMatcher() {
    root = new Node();
    (root->children).assign(2, nullptr);
}

int PrefixMatcher::selectRouter(std::string networkAddress) {
    Node* currentNode = this->root;

    for (int i = 0; i < networkAddress.length(); i++) {
        int pos = networkAddress[i] == '0' ? 0 : 1; // Gets the position of c in the alphabet (https://www.geeksforgeeks.org/find-letters-position-in-alphabet-using-bit-operation/)
        
        if (currentNode->children[pos] == nullptr) {
            return -1;
        }

        currentNode = currentNode->children[pos];
    }

    // Find the first match using depth first search
    return dfs(currentNode, currentNode->routerNum);
}

int PrefixMatcher::dfs(Node* startNode, int routerNum) {
    if (startNode->routerNum != -1)
        return startNode->routerNum;

    int num = -1;

    for (int i = 0; i < 2; i++) {
        if (startNode->children[i] != nullptr) {
            num = dfs(startNode->children[i], startNode->children[i]->routerNum);

            if (num != -1)
                return num;
        }
    }

    return -1;
}

void PrefixMatcher::insert(std::string address, int routerNumber) {
    Node* currentNode = this->root;

    for (int i = 0; i < address.length(); i++) {
        int pos = address[i] == '0' ? 0 : 1; // Gets the position of c in the alphabet (https://www.geeksforgeeks.org/find-letters-position-in-alphabet-using-bit-operation/)
        
        if (currentNode->children[pos] == nullptr) {
            Node* newNode = new Node();
            (newNode->children).assign(2, nullptr);

            currentNode->children[pos] = newNode;
        }

        currentNode = currentNode->children[pos];
    }

    currentNode->routerNum = routerNumber;
}

char PrefixMatcher::getNumberFromPos(int n) {
    return "01"[n];
}
