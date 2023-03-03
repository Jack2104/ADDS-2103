#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <iostream>

#include "Player.h"

class Computer : public Player {
    public:
        char makeMove();
        std::string getName();
};

#endif