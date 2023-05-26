#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <iostream>

class Trie {
    public:
        Trie();
        int getDocID(std::string word);
        void insert(std::string word, int doc_id);
        void print();
    
    private:
        struct Node {
            std::vector<Node*> children;
            int doc_id = 0;
            char letter;
        };

        Node* root;
};

#endif