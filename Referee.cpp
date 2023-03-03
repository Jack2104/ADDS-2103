#include "Referee.h"

Referee::Referee() {};

Player* Referee::refGame (Player* player1, Player* player2) {
    char p1_move = player1->getMove();
    char p2_move = player2->getMove();

    if (p1_move == p2_move) {
        return nullptr;
    } else if (
        (p1_move == 'R' && p2_move == 'S') ||
        (p1_move == 'S' && p2_move == 'P') ||
        (p1_move == 'P' && p2_move == 'R')
    ) {
        return player1;
    }

    return player2;
}