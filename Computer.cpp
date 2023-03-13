#include "Computer.h"
#include "Move.h"

Move* Computer::makeMove() { return new Move("Rock", {"Paper"}); };

std::string Computer::getName() { return "Computer"; };