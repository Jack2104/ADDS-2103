#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

#include "Trie.h"

class DocumentManager {
    private:
        std::unordered_map<int, std::vector<int>> docs;
        std::unordered_map<std::string, int> docNames;
        std::unordered_map<int, std::multiset<int>> patrons;

    public:
        void addDocument(std::string name, int id, int license_limit);

        void addPatron(int patronID);

        int search(std::string name); // returns docid if name is in the document collection or 0 if the name is not in the collection

        bool borrowDocument(int docid, int patronID);  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)

        void returnDocument(int docid, int patronID);
};

#endif