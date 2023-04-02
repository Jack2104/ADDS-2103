#include <iostream>
#include <string>
#include <vector>

#include "Finder.h"

using namespace std;

int main() {
    Finder finder;
    vector<int> indices = finder.findSubstrings("hatabtcabctgabcdef", "abcdef");

    for (int i = 0; i < indices.size(); i++) {
        cout << indices[i] << ", ";
    }

    return 0;
}