#include <iostream>
#include <string>

void stars(int n) {
    if (n == 0) {
        return "\n";
    }

    return "*" + stars(n-1);
}