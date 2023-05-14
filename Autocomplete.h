#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>

class Autocomplete {
    public:
        std::vector<std::string> getSuggestions(std::string partialWord);
        void insert(std::string word);
    
    private:
        struct Node {
            std::vector<Node*> children;
            bool endOfWord;
        };

        std::vector<Node*> children;
};

#endif