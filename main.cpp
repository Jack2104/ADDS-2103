#include "DocumentManager.h"
#include <iostream>

int main() {
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