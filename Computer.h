#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <iostream>

#include "Player.h"
#include "Move.h"

class Computer : public Player {
    public:
        Move* makeMove();
        std::string getName();
};

#endif