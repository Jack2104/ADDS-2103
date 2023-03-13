#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

#include "Move.h"

class Player {
    public:
        virtual Move* makeMove() = 0;
        virtual std::string getName() = 0;
};

#endif