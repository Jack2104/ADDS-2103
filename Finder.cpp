#include "Finder.h"

#include <iostream>

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;

    for(size_t i = 1; i <= s2.size(); i++) {
        size_t found = s1.find(s2.substr(0, i));

        if (found != string::npos) {
            result.push_back(found);
        } else {
            result.insert(result.end(), s2.size() - i + 1, -1);
            return result;
        }
    }

    return result;
}