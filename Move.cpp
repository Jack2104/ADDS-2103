#include <string>
#include <vector>
#include <algorithm>

#include "Move.h"

Move::Move(std::string name, std::vector<std::string> losesTo) : moveName(name), losesTo(losesTo) {};

std::string Move::getName() {
    return this->moveName;
}

bool Move::isBeatenBy(std::string move) {
    if(std::find(this->losesTo.begin(), this->losesTo.end(), move) != this->losesTo.end()) {
        return true;
    }

    return false;
}