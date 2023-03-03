#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human : public Player {
    private:
        Human();
        Human(name);

        std::string name;

    public:
        char makeMove();
        std::string getName();
}

#endif