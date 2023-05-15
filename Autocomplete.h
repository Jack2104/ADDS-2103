#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>

class Autocomplete {
    public:
        Autocomplete();
        std::vector<std::string> getSuggestions(std::string partialWord);
        void insert(std::string word);
    
    private:
        struct Node {
            std::vector<Node*> children;
            bool endOfWord = false;
        };

        Node* root;

        char getLetterFromPos(int n);
        void dfs(Node* startNode, std::string prefix, std::vector<std::string>& words);
};

#endif