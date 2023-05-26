#include "Trie.h"

Trie::Trie() {
    root = new Node();
    (root->children).assign(26, nullptr);
}

int Trie::getDocID(std::string word) {
    Node* currentNode = this->root;
    std::string constructedWord = "";

    for (int i = 0; i < word.length(); i++) {
        int pos = (word[i] & 31) - 1; // Gets the position of c in the alphabet (https://www.geeksforgeeks.org/find-letters-position-in-alphabet-using-bit-operation/)
        
        if (currentNode->children[pos] == nullptr) {
            return 0;
        }

        currentNode = currentNode->children[pos];
        constructedWord = constructedWord + currentNode->letter;
    }

    // If it reaches here, doc_id is not 0, and the word matches, then word is present
    return (currentNode->doc_id != 0 && word == constructedWord) ? currentNode->doc_id : 0;
}

void Trie::insert(std::string word, int doc_id) {
    Node* currentNode = this->root;

    for (int i = 0; i < word.length(); i++) {
        int pos = (word[i] & 31) - 1; // Gets the position of c in the alphabet (https://www.geeksforgeeks.org/find-letters-position-in-alphabet-using-bit-operation/)
        
        if (currentNode->children[pos] == nullptr) {
            Node* newNode = new Node();
            (newNode->children).assign(26, nullptr);
            newNode->letter = word[i];

            currentNode->children[pos] = newNode;
        }

        currentNode = currentNode->children[pos];
    }

    currentNode->doc_id = doc_id;
}

void Trie::print() {
    Node* currentNode = this->root;
    bool finished = false;

    while (!finished) {
        finished = true;

        for (int i = 0; i < 26; i++) {
            if (currentNode->children[i] != nullptr) {
                currentNode = currentNode->children[i];
                finished = false;
                std::cout << currentNode->letter << ", " << currentNode->doc_id << std::endl;
            }
        }
    }
}
