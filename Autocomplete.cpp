#include "Autocomplete.h"

Autocomplete::Autocomplete() {
    root = new Node();
    (root->children).assign(26, nullptr);
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    std::vector<std::string> results;
    Node* currentNode = this->root;

    for (int i = 0; i < partialWord.length(); i++) {
        int pos = (partialWord[i] & 31) - 1; // Gets the position of c in the alphabet (https://www.geeksforgeeks.org/find-letters-position-in-alphabet-using-bit-operation/)
        
        if (currentNode->children[pos] == nullptr) {
            return {};
        }

        currentNode = currentNode->children[pos];
    }

    // Find all possible words branching from currentNode using depth first search
    dfs(currentNode, partialWord, results);
    return results;
}

void Autocomplete::dfs(Node* startNode, std::string prefix, std::vector<std::string>& words) {
    if (startNode->endOfWord) {
        words.push_back(prefix);
    }

    for (int i = 0; i < 26; i++) {
        if (startNode->children[i] != nullptr) {
            dfs(startNode->children[i], prefix + getLetterFromPos(i), words);
        }
    }
}

void Autocomplete::insert(std::string word) {
    Node* currentNode = this->root;

    for (int i = 0; i < word.length(); i++) {
        int pos = (word[i] & 31) - 1; // Gets the position of c in the alphabet (https://www.geeksforgeeks.org/find-letters-position-in-alphabet-using-bit-operation/)
        
        if (currentNode->children[pos] == nullptr) {
            Node* newNode = new Node();
            (newNode->children).assign(26, nullptr);

            currentNode->children[pos] = newNode;
        }

        currentNode = currentNode->children[pos];
    }

    currentNode->endOfWord = true;
}

char Autocomplete::getLetterFromPos(int n) {
    return "abcdefghijklmnopqrstuvwxyz"[n];
}
