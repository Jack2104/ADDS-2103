#include "Autocomplete.h"
#include "PrefixMatcher.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    Autocomplete ac;
    ac.insert("test");
    ac.insert("testers");
    ac.insert("telling");
    vector<string> res = ac.getSuggestions("te");

    // for (auto w : res) {
    //     cout << w << endl;
    // }

    PrefixMatcher pm;
    pm.insert("1100110111", 1);
    pm.insert("110011011", 2);
    pm.insert("11001101", 3);
    pm.insert("110011010", 4);
    pm.insert("10001101001", 5);
    pm.insert("01001101001", 6);
    cout << pm.selectRouter("11001101110") << endl;

    pm.insert("001", 1);
    pm.insert("0011", 2);
    pm.insert("10011", 3);
    cout << pm.selectRouter("00110") << endl;

    return 0;
}