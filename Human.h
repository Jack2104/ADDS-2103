#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include <iostream>

#include "Player.h"

class Human : public Player {
    public:
        Human();
        Human(std::string name);

        std::string name;

        char makeMove();
        std::string getName();
};

#endif