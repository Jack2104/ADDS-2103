#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "Player.h"

class Human : public Player {
    public:
        Human();
        Human(name);

        std::string name;

        char makeMove();
        std::string getName();
}

#endif