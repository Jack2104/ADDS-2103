#include "Finder.h"

#include <iostream>

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;

    for(size_t i = 1; i <= s2.size(); i++) {
        // The index that the previous prefix was found at
        int prev_found = i > 1 ? result[i - 2] : 0;
        // cout << "i: " << i << ", prev_found: " << prev_found << endl;
        // cout << result.size() << endl;

        // Start the search at prev_found, as current prefix won't
        // be found before the index of the previous prefix
        size_t found = s1.find(s2.substr(0, i), prev_found);

        if (found != string::npos) {
            // cout << "result: " << found << endl;
            result.push_back(found);
        } else {
            result.insert(result.end(), s2.size() - i + 1, -1);
            return result;
        }
    }

    return result;
}