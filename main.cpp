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

    for (auto w : res) {
        cout << w << endl;
    }

    PrefixMatcher pm;
    pm.insert("110011011101", 1);
    pm.insert("110011011", 2);
    pm.insert("11001101", 3);
    cout << pm.selectRouter("11001101110") << endl;

    return 0;
}