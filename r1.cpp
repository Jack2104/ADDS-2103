#include <iostream>

int sumSquares(int n) {
    if (n == 1) {
        return 1;
    }

    return n*n + sumSquares(n-1);
}

int main() {
    std::cout << sumSquares(3) << std::endl;

    return 0;
}