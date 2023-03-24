#include <iostream>

int sum_of_squares(int n) {
    if (n == 1) {
        return 1;
    }

    return n*n + sum_of_squares(n-1);
}

int main() {
    std::cout << sum_of_squares(2) << std::endl;

    return 0;
}