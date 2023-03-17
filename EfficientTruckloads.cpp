#include "EfficientTruckloads.h"

#include <cmath>
#include <map>

using namespace std;

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    // Base case
    if (numCrates <= loadSize) {
        return 1;
    }

    int cratesFloor = floor(numCrates / 2.0f);
    int createCeil = ceil(numCrates / 2.0f);

    static map<int, int> storedValues;

    if (storedValues.find(numCrates) == storedValues.end()) {
        storedValues[numCrates] = numTrucks(cratesFloor, loadSize) + numTrucks(createCeil, loadSize);
    }

    return storedValues[numCrates];
}