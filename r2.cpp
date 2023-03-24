#include <iostream>

void stars(int n) {
    if (n == 0) {
        std::cout << '\n';
        return;
    }

    std::cout << '*';
    stars(n-1);
    return;
}