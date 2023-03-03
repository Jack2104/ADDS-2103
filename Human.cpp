#include "Human.h"

Human::Human() {
    this->name = "Human";
}

Human::Human(std::string name){
    this->name = name;
};

char Human::makeMove() {
    char move;

    std::cout << "Enter Move: ";
    std::cin >> move;

    return move;
}

std::string Human::getName() {
    std::cout << this->name << std::endl;
}

