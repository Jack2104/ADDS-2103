#include "Human.h"

Human::Human() {
    this->name = "Human";
}

Human::Human(name) : name(name) {};

char Human::makeMove() {
    char move;

    std::cout << "Enter Move: ";
    std::cin >> move;

    return move;
}

std::string Human::getName() {
    std::cout << this->name << std::endl;
}

