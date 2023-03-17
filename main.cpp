#include <iostream>
#include <string>

#include "Truckloads.h"
#include "Reverser.h"

int main() {
    Truckloads truckloads;
    std::cout << truckloads.numTrucks(14, 3) << std::endl;

    Reverser r;
    std::cout << r.reverseString("abc") << std::endl;
    std::cout << r.reverseDigit(123) << std::endl;

    return 0;
}