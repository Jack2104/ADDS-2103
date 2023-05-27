#include "DocumentManager.h"
#include "Trie.h"

#include <iostream>

int main() {
    // Trie t;

    // t.insert("Test", 1);
    // t.insert("tesu", 2);
    // t.print();
    // std::cout << t.getDocID("Test") << std::endl;

    DocumentManager dm;
    dm.addDocument("Test test", 1, 2);
    dm.addPatron(1);

    std::cout << dm.search("Test test") << std::endl;
    
    std::cout << dm.borrowDocument(1, 1) << std::endl;
    std::cout << dm.borrowDocument(1, 1) << std::endl;
    std::cout << dm.borrowDocument(1, 1) << std::endl;

    dm.returnDocument(1, 1);

    std::cout << dm.borrowDocument(1, 1) << std::endl;
    
    return 0;
}