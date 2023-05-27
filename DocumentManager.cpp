#include "DocumentManager.h"

using namespace std;

void DocumentManager::addDocument(string name, int id, int license_limit) {
    vector<int> v = {0, license_limit};
    docs.insert({id, v});

    // Insert into the trie so it can be searched for by name
    documentNames.insert(name, id);
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert({patronID, multiset<int>()});
}

int DocumentManager::search(string name) {
    // if (docs.find(name) == docs.end()) {
    //     return 0;
    // }

    // return doc = docs[name][0];
    return documentNames.getDocID(name);
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (patrons.find(patronID) == patrons.end() || docs.find(docid) == docs.end() || docs[docid][0] >= docs[docid][1]) {
        return false;
    }

    docs[docid][0] = docs[docid][0] + 1;
    patrons[patronID].insert(docid);

    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    if (docs.find(docid) != docs.end() && patrons.find(patronID) != patrons.end() && docs[docid][0] >= 0)
        docs[docid][0] = docs[docid][0] - 1;
    
    patrons[patronID].erase(docid);
}