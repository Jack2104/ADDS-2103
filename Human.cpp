#include "Human.h"
#include "Move.h"

#include <vector>

Human::Human() {
    this->name = "Human";
}

Human::Human(std::string name){
    this->name = name;
};

Move* Human::makeMove() {
    std::string move;

    std::cout << "Enter Move: ";
    std::cin >> move;

    if (move == "Rock")
        return new Move("Rock", {"Paper"});
    else if (move == "Paper")
        return new Move("Paper", {"Scissors"});
    else if (move == "Scissors")
        return new Move("Scissors", {"Rock"});
    else if (move == "Ninja")
        return new Move("Ninja", {"Monkey", "Robot"});
    else if (move == "Monkey")
        return new Move("Monkey", {"Zombie", "Pirate"});
    else if (move == "Robot")
        return new Move("Robot", {"Pirate", "Monkey"});
    else if (move == "Pirate")
        return new Move("Pirate", {"Zombie", "Ninja"});
    else if (move == "Zombie")
        return new Move("Zombie", {"Robot", "Ninja"});
    
    return nullptr;
}

std::string Human::getName() {
    return this->name;
}

