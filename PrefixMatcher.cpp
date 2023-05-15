#include "PrefixMatcher.h"

#include <iostream>

PrefixMatcher::PrefixMatcher() {
    root = new Node();
    (root->children).assign(2, nullptr);
}

int PrefixMatcher::selectRouter(std::string networkAddress) {
    Node* currentNode = this->root;
    std::vector<std::string> matches;

    // Find the first match using depth first search
    dfs(currentNode, "", matches, networkAddress);

    std::string longestMatch = matches[0];

    for (auto t : matches) {
        if (t.length() > longestMatch.length())
            longestMatch = t;
    }

    return routers[longestMatch];
}

void PrefixMatcher::dfs(Node* startNode, std::string addr, std::vector<std::string> &matches, std::string networkAddress) {
    if (startNode->routerNum != -1)
        matches.push_back(addr);

    for (int i = 0; i < 2; i++) {
        if (startNode->children[i] != nullptr && getNumberFromPos(i) == networkAddress[0]) {
            dfs(startNode->children[i], addr + getNumberFromPos(i), matches, networkAddress.substr(1, networkAddress.size() - 1));
        }
    }
}

void PrefixMatcher::insert(std::string address, int routerNumber) {
    Node* currentNode = this->root;

    for (int i = 0; i < address.length(); i++) {
        int pos = address[i] == '0' ? 0 : 1;
        
        if (currentNode->children[pos] == nullptr) {
            Node* newNode = new Node();
            (newNode->children).assign(2, nullptr);

            currentNode->children[pos] = newNode;
        }

        currentNode = currentNode->children[pos];
    }

    currentNode->routerNum = routerNumber;

    routers[address] = routerNumber;
}

char PrefixMatcher::getNumberFromPos(int n) {
    return "01"[n];
}
