#include "Referee.h"
#include "Move.h"

Referee::Referee() {};

Player* Referee::refGame (Player* player1, Player* player2) {
    Move* p1_move = player1->makeMove();
    Move* p2_move = player2->makeMove();

    if (p1_move->getName() == p2_move->getName()) {
        return nullptr; // Tie
    } else if (p2_move->isBeatenBy(p1_move->getName())) {
        return player1;
    }

    return player2;
}